// All the original content belonged to the US Army

#include "AA29/Object/BrushBuilder/MapDox/MapDox.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/PSSet/PSSet.h"

UMapDox::UMapDox()
{
	TourInfo.SetNum(32);
	bGenOverview = true;
	bGenImageBox = true;
	bGenViewpoints = true;
	bGenBriefings = true;
	bGenLoadouts = true;
	bGenObjectives = true;
	bGenCommVolumes = true;
	bGenOtherVolumes = true;
	bGenSpawns = true;
	FileFormat = EFormat::FORMAT_WIKI;
	BitmapFilename = "MapDox";
	ToolTip = "Generate and save documentation on this map.";
}

FString UMapDox::SettingString()
{
	switch (Setting)
	{
	case ESetting::SETTING_None:
		return "N/A";
	case ESetting::SETTING_Urban:
		return "Urban";
	case ESetting::SETTING_Industrial:
		return "Industrial";
	case ESetting::SETTING_Rural:
		return "Rural";
	case ESetting::SETTING_Arctic:
		return "Arctic";
	case ESetting::SETTING_Desert:
		return "Desert";
	case ESetting::SETTING_Village:
		return "Village";
	case ESetting::SETTING_Campground:
		return "Campground";
	default:
		break;
	}
	return "N/A";
}

FString UMapDox::TimeString()
{
	switch (Time)
	{
	case ETimeSetting::TIME_None:
		return "N/A";
	case ETimeSetting::TIME_Dawn:
		return "Dawn";
	case ETimeSetting::TIME_Day:
		return "Day";
	case ETimeSetting::TIME_Dusk:
		return "Dusk";
	case ETimeSetting::TIME_Night:
		return "Night";
	default:
		break;
	}
	return "N/A";
}

FString UMapDox::WeatherString()
{
	switch (Weather)
	{
	case EWeatherSetting::WEATHER_None:
		return "N/A";
	case EWeatherSetting::WEATHER_Snowing:
		return "Snowing";
	case EWeatherSetting::WEATHER_Stormy:
		return "Stormy";
	case EWeatherSetting::WEATHER_Overcast:
		return "Overcast";
	case EWeatherSetting::WEATHER_Raining:
		return "Raining";
	case EWeatherSetting::WEATHER_Sunny:
		return "Sunny";
	default:
		break;
	}
	return "N/A";
}

ALevelInfo* UMapDox::GetLevel()
{
	ALevelInfo* LevelInfoIterator = nullptr;
	if (myLevel == nullptr)
	{
		/*
		ForEach AllObjects(ALevelInfo::StaticClass(), LevelInfoIterator)
		{
			myLevel = LevelInfoIterator;
			return myLevel;
		}
		*/
	}
	return myLevel;
}

void UMapDox::FlushBuffer(FString& Buffer)
{
	/*
	FWrite(Buffer);
	Buffer = "";
	*/
}

FString UMapDox::LineBreak()
{
	switch (FileFormat)
	{
		case EFormat::FORMAT_HTM:
			return "<br>";
		case EFormat::FORMAT_WIKI:
			//return Chr(13) + Chr(10) + Chr(13) + Chr(10);
		case EFormat::FORMAT_TXT:
			//return Chr(13) + Chr(10);
		default:
			break;
	}
	return "<br>";
}

FString UMapDox::WikiEndLine()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "";
	case EFormat::FORMAT_WIKI:
		//return Chr(13) + Chr(10);
	case EFormat::FORMAT_TXT:
		return "";
	default:
		break;
	}
	return "";
}

FString UMapDox::Bold(FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<b>" + Text + "</b>";
	case EFormat::FORMAT_WIKI:
		return "'''" + Text + "'''";
	case EFormat::FORMAT_TXT:
		return "*" + Text + "*";
	default:
		break;
	}
	return "<b>" + Text + "</b>";
}

FString UMapDox::Italic(FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<i>" + Text + "</i>";
	case EFormat::FORMAT_WIKI:
		return "''" + Text + "''";
	case EFormat::FORMAT_TXT:
		return "/" + Text + "/";
	default:
		break;
	}
	return "<i>" + Text + "</i>";
}

FString UMapDox::Underline(FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<u>" + Text + "</u>";
	case EFormat::FORMAT_WIKI:
		return "<u>" + Text + "</u>";
	case EFormat::FORMAT_TXT:
		return "_" + Text + "_";
	default:
		break;
	}
	return "<u>" + Text + "</u>";
}

FString UMapDox::ALink(FString link_url, FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<a href=\"" + link_url + "\">" + Text + "</a>";
	case EFormat::FORMAT_WIKI:
		return "[" + link_url + Text + "]";
	case EFormat::FORMAT_TXT:
		return "[LINK: " + Text + "]";
	default:
		break;
	}
	return "<a href=\"" + link_url + "\">" + Text + "</a>";
}

FString UMapDox::Image(FString image_url, FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<img src=\"" + image_url + "\" alt=\"" + Text + "\">";
	case EFormat::FORMAT_WIKI:
		return "[[Image:" + image_url + "|" + Text + "]]";
	case EFormat::FORMAT_TXT:
		return "[IMAGE: " + Text + "]";
	default:
		break;
	}
	return "<img src=\"" + image_url + "\" alt=\"" + Text + "\">";
}

FString UMapDox::Center(FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<center>" + Text + "</center>";
	case EFormat::FORMAT_WIKI:
		return "<center>" + Text + "</center>";
	case EFormat::FORMAT_TXT:
		return Text;
	default:
		break;
	}
	return "<center>" + Text + "</center>";
}

FString UMapDox::Header(int32 header_num, FString Text)
{
	int32 i = 0;
	FString Result = "";
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<h" + FString::FromInt(header_num) + ">" + Text + "</h" + FString::FromInt(header_num) + ">";
	case EFormat::FORMAT_WIKI:
		Result = "";
		i = 0;
		if (i <= header_num)
		{
			Result += "=";
			i++;
			break;
		}
		Result += " " + Text + " ";
		for (i = 0; i <= header_num; i++)
		{
			Result += "=";
		}
		return Result;
	case EFormat::FORMAT_TXT:
		Result = "/";
		i = 0;
		if (i <= (header_num * 2))
		{
			Result += "-";
			i++;
		}
		Result += " " + Text + " ";
		for (i = Result.Len(); i <= 78; i++)
		{
			Result += "-";
		}
		Result += LineBreak();
		return Result;
	default:
		break;
	}
	return "<h" + FString::FromInt(header_num) + ">" + Text + "</h" + FString::FromInt(header_num) + ">";
}

FString UMapDox::StartList()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<ul>";
	case EFormat::FORMAT_WIKI:
		return LineBreak();
	case EFormat::FORMAT_TXT:
		return LineBreak();
	default:
		break;
	}
	return "<ul>";
}

FString UMapDox::StartNumList()
{
	ListItemCount = 0;
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<ol>";
	case EFormat::FORMAT_WIKI:
		return LineBreak();
	case EFormat::FORMAT_TXT:
		return LineBreak();
	default:
		break;
	}
	return "<ol>";
}

FString UMapDox::NumListItem(FString Text)
{
	ListItemCount++;
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<li>" + Text;
	case EFormat::FORMAT_WIKI:
		return "#" + Text + LineBreak();
	case EFormat::FORMAT_TXT:
		return " " + FString::FromInt(ListItemCount) + ". " + Text + LineBreak();
	default:
		break;
	}
	return "<li>" + Text;
}

FString UMapDox::listitem(FString Text)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<li>" + Text;
	case EFormat::FORMAT_WIKI:
		return "*" + Text + LineBreak();
	case EFormat::FORMAT_TXT:
		return " *" + Text + LineBreak();
	default:
		break;
	}
	return "<li>" + Text;
}

FString UMapDox::EndNumList()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "</ol>";
	case EFormat::FORMAT_WIKI:
		return LineBreak();
	case EFormat::FORMAT_TXT:
		return LineBreak();
	default:
		break;
	}
	return "</ol>";
}

FString UMapDox::EndList()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "</ul>";
	case EFormat::FORMAT_WIKI:
		return LineBreak();
	case EFormat::FORMAT_TXT:
		return LineBreak();
	default:
		break;
	}
	return "</ul>";
}

FString UMapDox::HorizontalRule()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<hr>";
	case EFormat::FORMAT_WIKI:
	case EFormat::FORMAT_TXT:
		return "-------------------------------------------------------------------------------" + LineBreak();
	default:
		break;
	}
	return "<hr>";
}

FString UMapDox::WikiArrow()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "";
	case EFormat::FORMAT_WIKI:
		return "&rarr; ";
	case EFormat::FORMAT_TXT:
		return "";
	default:
		break;
	}
	return "FAKE";    //FAKE   /EliZ
}

void UMapDox::GenFileHeader()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		//FWrite("<html><head><title>" + GetLevel().Title + "</title></head><body>");
		break;
	case EFormat::FORMAT_WIKI:
		break;
	case EFormat::FORMAT_TXT:
		break;
	default:
		break;
	}
}

void UMapDox::GenFileFooter()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		//FWrite(Center(Italic("<font size = -1>Map documentation auto-generated by MapDox.</font>")) + "</body></html>");
		break;
	case EFormat::FORMAT_WIKI:
		//FWrite(LineBreak() + LineBreak() + "Map documentation auto-generated by MapDox." + LineBreak());
		break;
	case EFormat::FORMAT_TXT:
		//FWrite(LineBreak() + LineBreak() + "Map documentation auto-generated by MapDox." + LineBreak());
		break;
	default:
		break;
	}
}

FString UMapDox::StartLoadoutTable()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "<table width=800 cellpadding=5 cellspacing=1 style=\"border: 1px solid #cccccc; margin-top: 5px; background-color: #cccccc\">";
	case EFormat::FORMAT_WIKI:
		return "{| width=\"800\" cellpadding=\"5\" cellspacing=\"1\" style=\"border: 1px solid #cccccc; margin-top: 5px; background-color: #cccccc\" |" + WikiEndLine();
	case EFormat::FORMAT_TXT:
		return " --- StartTable --- " + LineBreak();
	default:
		break;
	}
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::LoadoutHeaderEntry()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		//return "<tr>" + "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" + Bold("Team") + "</td>" + "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" + Bold("Role / ID") + "</td>" + "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" + Bold("Weapons / Ammo") + "</td>" + "</tr>";
	case EFormat::FORMAT_WIKI:
		return "|-" + WikiEndLine() + "| align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\" |" + WikiEndLine() + Bold("Team") + WikiEndLine() + "| align=\"center\" valign=\"top\" width=\"225\" style=\"background-color: #aaaaaa\" |" + WikiEndLine() + Bold("Role / ID") + WikiEndLine() + "| align=\"center\" valign=\"top\" width=\"525\" style=\"background-color: #aaaaaa\" |" + WikiEndLine() + Bold("Weapons / Ammo") + WikiEndLine();
	case EFormat::FORMAT_TXT:
		return "[Team] [Role/ID] [Weapons/Ammo]" + LineBreak();
	default:
		break;
	}
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::LoadoutTableEntry(FString Team, FString Role, FString WeaponClass, FString SpawnClass, FString SpawnPS, FString BaseLoadout, FString Added, FString Removed)
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		//return "<tr>" + "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" + Team + "</td>" + "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" + Bold(Role) + ": " + WeaponClass + LineBreak() + SpawnPS + "</td>" + "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" + listitem(Bold("Base Loadout: ") + BaseLoadout) + listitem(Bold("Added: ") + Added) + listitem(Bold("Removed: ") + Removed) + "</td>" + "</tr>";
	case EFormat::FORMAT_WIKI:
		return "|-" + WikiEndLine() + "| width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\" |" + WikiEndLine() + Team + WikiEndLine() + "| width=\"225\" valign=\"top\" style=\"background-color: #f3f3f3\" |" + WikiEndLine() + Bold(Role) + ": " + WeaponClass + LineBreak() + "([[" + SpawnClass + "|" + SpawnPS + "]])" + WikiEndLine() + "| width=\"520\" valign=\"top\" style=\"background-color: #f3f3f3\" |" + WikiEndLine() + "* " + Bold("Base Loadout: ") + BaseLoadout + LineBreak() + "* " + Bold("Added: ") + Added + LineBreak() + "* " + Bold("Removed: ") + Removed + WikiEndLine();
	case EFormat::FORMAT_TXT:
		return "[Team: " + Team + "] [Role: " + Role + " Class: " + SpawnPS + "] [Base: " + BaseLoadout + " / Added: " + Added + " / Removed: " + Removed + "]" + LineBreak();
	default:
		break;
	}
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::EndLoadoutTable()
{
	switch (FileFormat)
	{
	case EFormat::FORMAT_HTM:
		return "</table>";
	case EFormat::FORMAT_WIKI:
		return "|}" + LineBreak();
	case EFormat::FORMAT_TXT:
		return " --- EndTable --- " + LineBreak();
	default:
		return "";
	}
	return "</table>";
}

void UMapDox::GenOverview()
{
	FString ResultString = "";
	FString ObjectiveTypes = "";
	FString ObjectiveTypeName = "";
	FString MissionType = "";
	int32 PlayerCount0 = 0;
	int32 PlayerCount1 = 0;
	int32 SpawnCount = 0;
	int32 ViewpointCount = 0;
	AAGP_Viewpoint* ViewpointIterator = nullptr;
	AAGP_PlayerStart* PSIterator = nullptr;
	AAGP_Objective* ObjectiveIterator = nullptr;
	ResultString = "";
	ViewpointCount = 0;
	/*
	ForEach myLevel.AllActors(AAGP_Viewpoint::StaticClass(), ViewpointIterator)
	{
		ViewpointCount++;
	}
	PlayerCount0 = 0;
	PlayerCount1 = 0;
	SpawnCount = 0;
	ForEach myLevel.AllActors(AAGP_PlayerStart::StaticClass(), PSIterator)
	{
		SpawnCount++;
		if (PSIterator.TeamNumber == 0)
		{
			PlayerCount0++;
		}
		else
		{
			PlayerCount1++;
		}
	}
	ObjectiveTypes = "";
	ForEach myLevel.AllActors(AAGP_Objective::StaticClass(), ObjectiveIterator)
	{
		ObjectiveTypeName = GetItemName(string(ObjectiveIterator));
		(ObjectiveTypes += Left(ObjectiveTypeName, (Len(ObjectiveTypeName) - 1)) + ", ");
	}
	if (Len(ObjectiveTypes) > 0)
	{
		ObjectiveTypes = Left(ObjectiveTypes, (Len(ObjectiveTypes) - 2));
	}
	switch (GetLevel().GamePlayMode)
	{
	case 0:
		MissionType = "Live Fire";
		break;
	case 1:
		MissionType = "MILES";
		break;
	case 2:
		MissionType = "Simunition";
		break;
	default:
	}
	(ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Overview") + LineBreak());
	(ResultString += Bold("Description:") @ "N/A" + LineBreak() + LineBreak());
	(ResultString += Bold("Setting:") @ SettingString() + LineBreak());
	(ResultString += Bold("Time:") @ TimeString() + LineBreak());
	(ResultString += Bold("Weather:") @ WeatherString() + LineBreak());
	(ResultString += Bold("Spawn Points:") @ FString::FromInt(SpawnCount) + LineBreak());
	(ResultString += Bold("Players (Team 0):") @ FString::FromInt(PlayerCount0) + LineBreak());
	(ResultString += Bold("Players (Team 1):") @ FString::FromInt(PlayerCount1) + LineBreak());
	FlushBuffer(ResultString);
	(ResultString += Bold("Objective Types:") @ ObjectiveTypes + LineBreak());
	(ResultString += Bold("Viewpoints:") @ FString::FromInt(ViewpointCount) + LineBreak());
	(ResultString += Bold("Mission Type:") @ MissionType + LineBreak());
	(ResultString += Bold("Version Deployment:") @ VersionDeployment + LineBreak());
	(ResultString += LineBreak() + Image("yellow_star.gif", "Yellow Star") @ Bold("Filename:") @ FileNameNoExtension + ".aao" + LineBreak());
	(ResultString += HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenImageBox()
{
	/*
	FString ResultString = "";
	FString IMGName = "";
	if (Len(ImageName) > 0)
	{
		IMGName = ImageName;
	}
	else
	{
		IMGName = "map_" + FileNameNoExtension + ".jpg";
	}
	ResultString = "";
	if (FileFormat == 1)
	{
		(ResultString += "__NOTOC__" + WikiEndLine() + Image(IMGName + "|right|frame", "Overhead View of the Map") + WikiEndLine());
	}
	else
	{
		(ResultString += Image(IMGName, "Overhead View of the Map"));
	}
	FlushBuffer(ResultString);
	*/
}

FString UMapDox::EndGameToString(EEndGameViewpoint EndGame)
{
	/*
	switch (EndGame)
	{
	case 0:
		return "None";
	case 1:
		return "Always";
	case 2:
		return "Team 0 Won";
	case 3:
		return "Team 1 Won";
	case 4:
		return "No Team Won";
	default:
		return ""; 
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

void UMapDox::GenViewpoints()
{
	FString ResultString = "";
	AAGP_Viewpoint* ViewpointIterator = nullptr;
	ResultString = "";
	/*
	(ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Viewpoints") + LineBreak());
	ForEach myLevel.AllActors(AAGP_Viewpoint::StaticClass(), ViewpointIterator)
	{
		(ResultString += GetItemName(string(ViewpointIterator)) + ":");
		(ResultString += StartList());
		(ResultString += listitem("Description:" @ ViewpointIterator.Description));
		(ResultString += listitem("Location: X = " + FString::FromInt(ViewpointIterator.Location.X) + ", Y = " + FString::FromInt(ViewpointIterator.Location.Y) + ", Z = " + FString::FromInt(ViewpointIterator.Location.Z)));
		(ResultString += listitem("Rotation: Pitch = " + FString::FromInt(ViewpointIterator.Rotation.Pitch) + ", Yaw = " + FString::FromInt(ViewpointIterator.Rotation.Yaw) + ", Roll = " + FString::FromInt(ViewpointIterator.Rotation.Roll)));
		(ResultString += listitem("Sequence:" @ FString::FromInt(ViewpointIterator.iSequence)));
		(ResultString += listitem("Spectator Viewpoint:" @ FString::FromInt(ViewpointIterator.bSpectatorViewpoint)));
		(ResultString += listitem("End Game Viewpoint:" @ EndGameToString(ViewpointIterator.EndGameViewpoint)));
		(ResultString += EndList());
		FlushBuffer(ResultString);
	}
	(ResultString += HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::LoadTours()
{
	/*
	int32 iNumTours = 0;
	int32 iCurNumMissions = 0;
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	bool bFoundTourAndMission = false;
	FString sTemp = "";
	FString sFile = "";
	FString sLine = "";
	bFoundTourAndMission = false;
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Tour = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "Dependency(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Dependency = GetPrivateProfileInt(sFile, "Tours", sLine);
		sLine = "Image(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].Image = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourText(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].TourText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourTextTitle(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].TourTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryText(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].HistoryText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryTextTitle(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].HistoryTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "IsSequential(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].IsSequential = bool(GetPrivateProfileString(sFile, "Tours", sLine));
		sLine = "IsTraining(" + FString::FromInt(iCurTour) + ")";
		TourInfo[iCurTour].IsTraining = bool(GetPrivateProfileString(sFile, "Tours", sLine));
		iCurNumMissions = GetPrivateProfileInt(sFile, TourInfo[iCurTour].Tour, "NumMissions");
		if (iCurNumMissions < 0)
		{
			iCurNumMissions = 0;
		}
		if (iCurNumMissions > 32)
		{
			iCurNumMissions = 32;
		}
		TourInfo[iCurTour].iNumMissions = iCurNumMissions;
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sLine = "MissionTitle(" + FString::FromInt(iCurMission) + ")";
			TourInfo[iCurTour].Mission[iCurMission].Title = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImage(" + FString::FromInt(iCurMission) + ")";
			TourInfo[iCurTour].Mission[iCurMission].Image = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImageDisabled(" + FString::FromInt(iCurMission) + ")";
			TourInfo[iCurTour].Mission[iCurMission].ImageDisabled = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionMapFilename(" + FString::FromInt(iCurMission) + ")";
			TourInfo[iCurTour].Mission[iCurMission].MapFilename = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			if (FileNameNoExtension ~= TourInfo[iCurTour].Mission[iCurMission].MapFilename)
			{
				iMyTour = iCurTour;
				iMyMission = iCurMission;
				bFoundTourAndMission = true;
			}
		}
	}
	sTemp = GetBaseDir() + "\\..\\Briefings\\";
	HistoryBriefing.RemoveAt(0, HistoryBriefing.Num());
	sFile = sTemp + TourInfo[iMyTour].HistoryText + ".txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			HistoryBriefing[HistoryBriefing.Num()] = sLine;
		}
		FClose();
	}
	Briefing.RemoveAt(0, Briefing.Num());
	sFile = sTemp + TourInfo[iMyTour].Mission[iMyMission].MapFilename + ".txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Briefing[Briefing.Num()] = sLine;
		}
		FClose();
	}
	Team0Briefing.RemoveAt(0, Team0Briefing.Num());
	sFile = sTemp + TourInfo[iMyTour].Mission[iMyMission].MapFilename + "_team0.txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Team0Briefing[Team0Briefing.Num()] = sLine;
		}
		FClose();
	}
	Team1Briefing.RemoveAt(0, Team1Briefing.Num());
	sFile = sTemp + TourInfo[iMyTour].Mission[iMyMission].MapFilename + "_team1.txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Team1Briefing[Team1Briefing.Num()] = sLine;
		}
		FClose();
	}
	*/
}

void UMapDox::GenBriefingText(TArray<FString> Brief)
{
	/*
	FString ResultString = "";
	int32 i = 0;
	ResultString = "";
	if (FileFormat == 0)
	{
		ResultString += "<ul>";
	}
	for (i = 0; i < Brief.Num(); i++)
	{
		if (FileFormat == 1)
		{
			ResultString @ = Brief[i] + WikiEndLine();
		}
		else
		{
			ResultString @ = Brief[i] + LineBreak();
		}
		FlushBuffer(ResultString);
	}
	if (FileFormat == 0)
	{
		ResultString += "</ul>";
		FlushBuffer(ResultString);
	}
	*/
}

void UMapDox::GenBriefings()
{
	/*
	FString ResultString = "";
	FString FileHistory = "";
	FString FileBase = "";
	FString FileTeam[2] = "";
	ResultString = "";
	FileBase = TourInfo[iMyTour].Mission[iMyMission].MapFilename + ".txt";
	FileTeam[0] = TourInfo[iMyTour].Mission[iMyMission].MapFilename + "_team0.txt";
	FileTeam[1] = TourInfo[iMyTour].Mission[iMyMission].MapFilename + "_team1.txt";
	FileHistory = TourInfo[iMyTour].HistoryText + ".txt";
	(ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Briefings") + LineBreak());
	(ResultString += Header(3, WikiArrow() @ "Deployment UI Briefing") + LineBreak());
	(ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ Bold("Filename: ") + FileBase @ "(" + TourInfo[iMyTour].Mission[iMyMission].Title + ")") + LineBreak());
	FlushBuffer(ResultString);
	(ResultString += Header(3, Bold("History Briefing: ") + FileHistory @ "(" + TourInfo[iMyTour].HistoryTextTitle + ")") + LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(HistoryBriefing);
	(ResultString += Header(3, Bold("Mission Briefing: ") + FileBase) + LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Briefing);
	(ResultString += Header(3, Bold("Team 0 Briefing: ") + FileTeam[0]) + LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Team0Briefing);
	(ResultString += Header(3, Bold("Team 1 Briefing: ") + FileTeam[1]) + LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Team1Briefing);
	(ResultString += HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

FString UMapDox::FTToString(EFireTeam FireTeam)
{
	/*
	switch (FireTeam)
	{
	case 0:
		return "";
	case 1:
		return "A";
	case 2:
		return "B";
	case 3:
		return "C";
	case 4:
		return "D";
	default:
		return "";
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::PSToRole(AAGP_PlayerStart* PS)
{
	/*
	if (PS.bSquadLeader)
	{
		return "Squad Leader";
	}
	else
	{
		if (PS.bFTLeader)
		{
			return "Fire Team Leader";
		}
		else
		{
			return "Team Member";
		}
	}
	*/
	return "FAKE";    //FAKE  /ELiZ
}

FString UMapDox::GenerateDefaultItems(AAGP_PlayerStart* PS)
{
	int32 i = 0;
	FString ResultString = "";
	ResultString = "";
	/*
	for (i = 0; i < 32; i++)
	{
		if (Len(PS.SpawnClass.Default.ClassEquipment[i]) > 0)
		{
			ResultString += class<Inventory>(DynamicLoadObject(PS.SpawnClass.Default.ClassEquipment[i], Class'Class')).Default.ItemName + ", ";
		}
	}
	if (Len(ResultString) > 0)
	{
		ResultString = Left(ResultString, (Len(ResultString) - 2));
	}
	*/
	return ResultString;
}

FString UMapDox::GenerateAddedItems(AAGP_PlayerStart* PS)
{
	int32 i = 0;
	FString ResultString = "";
	ResultString = "";
	/*
	for (i = 0; i < 16; i++)
	{
		if (PS.AddedInventory[i] != nullptr)
		{
			ResultString += PS.AddedInventory[i].Default.ItemName + ", ";
		}
	}
	if (Len(ResultString) > 0)
	{
		ResultString = Left(ResultString, (Len(ResultString) - 2));
	}
	*/
	return ResultString;
}

FString UMapDox::GenerateRemovedItems(AAGP_PlayerStart* PS)
{
	int32 i = 0;
	FString ResultString = "";
	ResultString = "";
	/*
	for (i = 0; i < 16; i++)
	{
		if (PS.RemoveClassInventory[i] != nullptr)
		{
			ResultString += PS.RemoveClassInventory[i].Default.ItemName + ", ";
		}
	}
	if (Len(ResultString) > 0)
	{
		ResultString = Left(ResultString, (Len(ResultString) - 2));
	}
	*/
	return ResultString;
}

bool UMapDox::Compare(AAGP_PlayerStart* PS1, AAGP_PlayerStart* PS2)
{
	EWeaponType Weapon1 = EWeaponType::WEAPON_None;
	EWeaponType Weapon2 = EWeaponType::WEAPON_None;
	/*
	if (PS1.bSquadLeader)
	{
		return true;
	}
	else
	{
		if (PS2.bSquadLeader)
		{
			return false;
		}
	}
	if (PS1.bGuerrilla != PS2.bGuerrilla)
	{
		return (!PS1.bGuerrilla);
	}
	if (PS1.getFT() != PS2.getFT())
	{
		return (PS1.getFT() < PS2.getFT());
	}
	else
	{
		if (PS1.bFTLeader)
		{
			return true;
		}
		else
		{
			if (PS2.bFTLeader)
			{
				return false;
			}
		}
		Weapon1 = PS1.GetSpawnClass().Default.nativeWeapon;
		Weapon2 = PS2.GetSpawnClass().Default.nativeWeapon;
		if (Weapon1 != Weapon2)
		{
			return (CompareScore(Weapon1) <= CompareScore(Weapon2));
		}
		else
		{
			return (PS1.fBaseScore < PS2.fBaseScore);
		}
	}
	*/
	return false;    //FAKE   /ELiZ

}

int32 UMapDox::CompareScore(EWeaponType W)
{
	/*
	switch (W)
	{
	case 2:
		return 10;
	case 6:
		return 20;
	case 3:
		return 30;
	case 4:
		return 40;
	default:
		return 99;
	}
	*/
	return 0;   //FAKE    /ELiZ
}

void UMapDox::Swap(AAGP_PlayerStart*& PS1, AAGP_PlayerStart*& PS2)
{
	AAGP_PlayerStart* Temp = nullptr;
	Temp = PS1;
	PS1 = PS2;
	PS2 = Temp;
}

void UMapDox::SortFT(TArray<AAGP_PlayerStart*>& FireTeam)
{
	int32 i = 0;
	int32 j = 0;
	for (i = 0; i < FireTeam.Num(); i++)
	{
		for (j = (i + 1); j < FireTeam.Num(); j++)
		{
			if (Compare(FireTeam[j], FireTeam[i]))
			{
				Swap(FireTeam[j], FireTeam[i]);
			}
		}
	}
}

void UMapDox::GenLoadouts()
{
	int32 Team = 0;
	int32 FireTeam = 0;
	int32 i = 0;
	FString ResultString = "";
	AAGP_PlayerStart* PSIterator = nullptr;
	TArray<AAGP_PlayerStart*> PSList = {};
	TArray<AAGP_PlayerStart*> FireTeamList = {};
	ResultString = "";
	/*
	ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Loadouts") + LineBreak();
	ForEach GetLevel().AllActors(AAGP_PlayerStart::StaticClass(), PSIterator)
	{
		PSList[PSList.Num()] = PSIterator;
	}
	for (Team = 0; Team < 2; Team++)
	{
		ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ "Team" @ FString::FromInt(Team) @ "(" + GetLevel().TeamName[Team] + ")") + LineBreak();
		for (FireTeam = 0; FireTeam < 5; FireTeam++)
		{
			FireTeamList.RemoveAt(0, FireTeamList.Num());
			for (i = 0; i < PSList.Num(); i++)
			{
				if ((PSList[i].TeamNumber == Team) && (PSList[i].FireTeam == FireTeam))
				{
					FireTeamList[FireTeamList.Num()] = PSList[i];
				}
			}
			if (FireTeamList.Num() <= 0)
			{
			}
			if (FireTeam == 0)
			{
				ResultString += StartLoadoutTable() + LoadoutHeaderEntry();
			}
			else
			{
				ResultString += StartLoadoutTable();
			}
			FlushBuffer(ResultString);
			SortFT(FireTeamList);
			for (i = 0; i < FireTeamList.Num(); i++)
			{
				ResultString += LoadoutTableEntry(FTToString(FireTeamList[i].FireTeam), PSToRole(FireTeamList[i]), FireTeamList[i].SpawnClass.Default._ShortName, GetItemName(string(FireTeamList[i].SpawnClass)), FString::FromInt(FireTeamList[i].Name), GenerateDefaultItems(FireTeamList[i]), GenerateAddedItems(FireTeamList[i]), GenerateRemovedItems(FireTeamList[i]));
				FlushBuffer(ResultString);
			}
			ResultString += EndLoadoutTable();
			FlushBuffer(ResultString);
		}
	}
	ResultString += HorizontalRule();
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenObjectives()
{
	int32 i = 0;
	FString ResultString = "";
	TArray<AAGP_Objective*> ObjectivesList = {};
	AAGP_Objective* ObjectiveIterator = nullptr;
	ResultString = "";
	/*
	ForEach myLevel.AllActors(AAGP_Objective::StaticClass(), ObjectiveIterator)
	{
		ObjectivesList[ObjectivesList.Num()] = ObjectiveIterator;
	}
	ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Objectives") + LineBreak();
	ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ "Level Scoring") + LineBreak();
	ResultString += StartList();
	ResultString += listitem("Team 0 FT Leader Bonus Per Survivor: " + FString::FromInt(GetLevel().Score_Team0_FTLeaderBonusPerSurvivor));
	ResultString += listitem("Team 0 Squad Leader Bonus Per Survivor: " + FString::FromInt(GetLevel().Score_Team0_SquadLeaderBonusPerSurvivor));
	ResultString += listitem("Team 0 Survival Win: " + FString::FromInt(GetLevel().Score_Team0_SurviveWin));
	ResultString += listitem("Team 0 Win: " + FString::FromInt(GetLevel().Score_Team0_Win));
	ResultString += listitem("Team 1 FT Leader Bonus Per Survivor: " + FString::FromInt(GetLevel().Score_Team1_FTLeaderBonusPerSurvivor));
	ResultString += listitem("Team 1 Squad Leader Bonus Per Survivor: " + FString::FromInt(GetLevel().Score_Team1_SquadLeaderBonusPerSurvivor));
	ResultString += listitem("Team 1 Survival Win: " + FString::FromInt(GetLevel().Score_Team1_SurviveWin));
	ResultString += listitem("Team 1 Win: " + FString::FromInt(GetLevel().Score_Team1_Win));
	ResultString += EndList();
	FlushBuffer(ResultString);
	for (i = 0; i < ObjectivesList.Num(); i++)
	{
		ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(ObjectivesList[i]))) + LineBreak();
		ResultString += Bold(WikiArrow() @ "Specifics:") + LineBreak();
		ResultString += StartList();
		ResultString += listitem("Location: X = " + FString::FromInt(ObjectivesList[i].Location.X) + ", Y = " + FString::FromInt(ObjectivesList[i].Location.Y) + ", Z = " + FString::FromInt(ObjectivesList[i].Location.Z));
		ResultString += listitem("Attack Description: " + ObjectivesList[i].AttackDescription);
		ResultString += listitem("Defense Description: " + ObjectivesList[i].DefenseDescription);
		ResultString += listitem("Accomplish Message: " + ObjectivesList[i].AccomplishMessage);
		ResultString += listitem("Failed Defense Message: " + ObjectivesList[i].FailedDefenseMessage);
		FlushBuffer(ResultString);
		ResultString += listitem("Required to win: " + FString::FromInt(ObjectivesList[i].bRequiredToWin));
		ResultString += listitem("Instant win: " + FString::FromInt(ObjectivesList[i].bInstantWin));
		ResultString += listitem("Attacking Team: " + FString::FromInt(ObjectivesList[i].AttackTeam));
		ResultString += listitem("Recapturable (Take Turns): " + FString::FromInt(ObjectivesList[i].bTakeTurns));
		ResultString += listitem("Kick Instigator on Damaged: " + FString::FromInt(ObjectivesList[i].bKickInstigator_Damage));
		ResultString += listitem("Kick Instigator on Killed: " + FString::FromInt(ObjectivesList[i].bKickInstigator_Kill));
		ResultString += listitem("Linked NPC: " + FString::FromInt(ObjectivesList[i].LinkedNPC));
		ResultString += EndList();
		FlushBuffer(ResultString);
		ResultString += StartList();
		ResultString += Bold(WikiArrow() @ "Scoring:") + LineBreak();
		ResultString += listitem("Assault Player: " + FString::FromInt(ObjectivesList[i].Score_AssaultPlayer));
		ResultString += listitem("Assault Helper: " + FString::FromInt(ObjectivesList[i].Score_AssaultHelper));
		ResultString += listitem("Assault Team: " + FString::FromInt(ObjectivesList[i].Score_AssaultTeam));
		ResultString += listitem("Assault Survivor: " + FString::FromInt(ObjectivesList[i].Score_AssaultSurvivor));
		ResultString += listitem("Assault Defender Kill: " + FString::FromInt(ObjectivesList[i].Score_DefenderKill));
		ResultString += listitem("Killed ROE Penalty: " + FString::FromInt(ObjectivesList[i].Kill_ROE_Penalty));
		ResultString += listitem("ROE Multiplier: " + FString::FromInt(ObjectivesList[i].fROE_Damage_Multiplier));
		ResultString += EndList();
		FlushBuffer(ResultString);
	}
	*/
}

void UMapDox::GenCommVolumes()
{
	FString ResultString = "";
	FBox BBox = FBox({});
	AVolume* VolumeIterator = nullptr;
	ResultString = "";
	/*
	(ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Comm Volumes") + LineBreak());
	ForEach GetLevel().AllActors(Class'Volume', VolumeIterator)
	{
		if (VolumeIterator.bIsCommVolume)
		{
			BBox = VolumeIterator.GetBoundingBox();
			(ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(VolumeIterator))) + LineBreak());
			(ResultString += StartList());
			(ResultString += listitem("Location Name: " + VolumeIterator.LocationName));
			(ResultString += listitem("Bounding Box: {[" + FString::FromInt(BBox.Min.X) + ", " + FString::FromInt(BBox.Min.Y) + "], Max: [" + FString::FromInt(BBox.Max.X) + ", " + FString::FromInt(BBox.Max.Y) + "]}"));
			(ResultString += EndList());
			FlushBuffer(ResultString);
		}
	}
	(ResultString += HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenOtherVolumes()
{
	FString ResultString = "";
	FBox BBox = FBox({});
	AVolume* VolumeIterator = nullptr;
	ResultString = "";
	/*
	(ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Other Volumes") + LineBreak());
	ForEach GetLevel().AllActors(Class'Volume', VolumeIterator)
	{
		if (!VolumeIterator.bIsCommVolume)
		{
			BBox = VolumeIterator.GetBoundingBox();
			(ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(VolumeIterator))) + LineBreak());
			(ResultString += StartList());
			(ResultString += listitem("Location Name: " + VolumeIterator.LocationName));
			(ResultString += listitem("Bounding Box: {[" + FString::FromInt(BBox.Min.X) + ", " + FString::FromInt(BBox.Min.Y) + "], Max: [" + FString::FromInt(BBox.Max.X) + ", " + FString::FromInt(BBox.Max.Y) + "]}"));
			(ResultString += EndList());
			FlushBuffer(ResultString);
		}
	}
	(ResultString += HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenSpawns()
{
	int32 i = 0;
	FString ResultString = "";
	APSSet* PSSetIterator = nullptr;
	ResultString = "";
	/*
	ResultString += Header(2, Image("aa_star.gif", "AAStar") @ "Player Spawns") + LineBreak();
	for (i = 0; i < 2; i++)
	{
		ResultString += Header(3, Image("yellow_star.gif", "Yellow Star") @ "Team" @ FString::FromInt(i) @ "(" + GetLevel().TeamName[i] + ")") + LineBreak();
		ForEach GetLevel().AllActors(APSSet::StaticClass(), PSSetIterator)
		{
			if (PSSetIterator.Team == i)
			{
				ResultString += StartList();
				ResultString += listitem("Name: " + GetItemName(string(PSSetIterator)));
				ResultString += listitem("Set Tag: " + FString::FromInt(PSSetIterator.SetTag));
				ResultString += listitem("Location: X = " + FString::FromInt(PSSetIterator.Location.X) + ", Y = " + FString::FromInt(PSSetIterator.Location.Y) + ", Z = " + FString::FromInt(PSSetIterator.Location.Z));
				ResultString += listitem("Team: " + FString::FromInt(PSSetIterator.Team));
				ResultString += EndList();
				FlushBuffer(ResultString);
			}
		}
	}
	ResultString += HorizontalRule();
	FlushBuffer(ResultString);
	*/
}

bool UMapDox::Build()
{
	/*
	FString TempFileName = "";
	myLevel = nullptr;
	if (GetLevel() == nullptr)
	{
		return false;
	}
	Log(myLevel.Title);
	Log(GetLevel().Title);
	if (Len(FileNameNoExtension) <= 0)
	{
		FileNameNoExtension = "Untitled";
	}
	switch (FileFormat)
	{
	case 0:
		FileExtension = ".htm";
		break;
	case 1:
		FileExtension = ".wiki";
		break;
	case 2:
	default:
		FileExtension = ".txt";
		break;
	}
	TempFileName = GetBaseDir() + "\\..\\MapDox\\";
	CreateDir(TempFileName);
	TempFileName = TempFileName + FileNameNoExtension + FileExtension;
	LoadTours();
	FOpenWrite(TempFileName);
	GenFileHeader();
	if (FileFormat == 1)
	{
		if (bGenImageBox)
		{
			GenImageBox();
		}
		if (bGenOverview)
		{
			GenOverview();
		}
	}
	else
	{
		if (bGenOverview)
		{
			GenOverview();
		}
		if (bGenImageBox)
		{
			GenImageBox();
		}
	}
	if (bGenViewpoints)
	{
		GenViewpoints();
	}
	if (bGenBriefings)
	{
		GenBriefings();
	}
	if (bGenLoadouts)
	{
		GenLoadouts();
	}
	if (bGenObjectives)
	{
		GenObjectives();
	}
	if (bGenCommVolumes)
	{
		GenCommVolumes();
	}
	if (bGenOtherVolumes)
	{
		GenOtherVolumes();
	}
	if (bGenSpawns)
	{
		GenSpawns();
	}
	GenFileFooter();
	FClose();
	*/
	return true;
}
