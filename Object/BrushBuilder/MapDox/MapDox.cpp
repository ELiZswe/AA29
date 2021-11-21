// All the original content belonged to the US Army


#include "AA29/Object/BrushBuilder/MapDox/MapDox.h"

UMapDox::UMapDox()
{
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
	/*

	switch (Setting)
	{
	case ESetting::SETTING_None:
		return "N/A";
	case 1:
		return "Urban";
	case 2:
		return "Industrial";
	case 3:
		return "Rural";
	case 4:
		return "Arctic";
	case 5:
		return "Desert";
	case 6:
		return "Village";
	case 7:
		return "Campground";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::TimeString()
{
	/*
	switch (Time)
	{
	case 0:
		return "N/A";
	case 1:
		return "Dawn";
	case 2:
		return "Day";
	case 3:
		return "Dusk";
	case 4:
		return "Night";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ

}

FString UMapDox::WeatherString()
{
	/*
	switch (Weather)
	{
	case 0:
		return "N/A";
	case 1:
		return "Snowing";
	case 2:
		return "Stormy";
	case 3:
		return "Overcast";
	case 4:
		return "Raining";
	case 5:
		return "Sunny";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ

}
/*
ALevelInfo* UMapDox::GetLevel()
{
	local LevelInfo LevelInfoIterator;
	if (myLevel == None)
	{
		ForEach AllObjects(Class'LevelInfo', LevelInfoIterator)
		{
			myLevel = LevelInfoIterator;
			return myLevel;
		}
	}
	return myLevel;
}
*/

void UMapDox::FlushBuffer(FString& Buffer)
{
	/*
	FWrite(Buffer);
	Buffer = "";
	*/
}

FString UMapDox::LineBreak()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<br>";
	case 1:
		return Chr(13) $ Chr(10) $ Chr(13) $ Chr(10);
	case 2:
		return Chr(13) $ Chr(10);
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ

}

FString UMapDox::WikiEndLine()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "";
	case 1:
		return Chr(13) $ Chr(10);
	case 2:
		return "";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Bold(FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<b>" $ Text $ "</b>";
	case 1:
		return "'''" $ Text $ "'''";
	case 2:
		return "*" $ Text $ "*";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Italic(FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<i>" $ Text $ "</i>";
	case 1:
		return "''" $ Text $ "''";
	case 2:
		return "/" $ Text $ "/";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Underline(FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
	case 1:
		return "<u>" $ Text $ "</u>";
	case 2:
		return "_" $ Text $ "_";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::ALink(FString link_url, FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<a href=\"" $ link_url $ "\">" $ Text $ "</a>";
	case 1:
		return "[" $ link_url @ Text $ "]";
	case 2:
		return "[LINK: " $ Text $ "]";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Image(FString image_url, FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<img src=\"" $ image_url $ "\" alt=\"" $ Text $ "\">";
	case 1:
		return "[[Image:" $ image_url $ "|" $ Text $ "]]";
	case 2:
		return "[IMAGE: " $ Text $ "]";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Center(FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
	case 1:
		return "<center>" $ Text $ "</center>";
	case 2:
		return Text;
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::Header(int32 header_num, FString Text)
{
	/*
	int32 i = 0;
	FString Result = "";
	switch (FileFormat)
	{
	case 0:
		return "<h" $ string(header_num) $ ">" $ Text $ "</h" $ string(header_num) $ ">";
	case 1:
		Result = "";
		i = 0;
		if (i <= header_num)
		{
			Result $ = "=";
			i++;
			break;
		}
		Result $ = " " $ Text $ " ";
		for (i = 0; i <= header_num; i++)
		{
			Result $ = "=";
		}
		return Result;
	case 2:
		Result = "/";
		i = 0;
		if (i <= (header_num * 2))
		{
			Result $ = "-";
			i++;
		}
		Result $ = " " $ Text $ " ";
		for (i = Len(Result); i <= 78; i++)
		{
			Result $ = "-";
		}
		Result $ = LineBreak();
		return Result;
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::StartList()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<ul>";
	case 1:
		return LineBreak();
	case 2:
		return LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::StartNumList()
{
	/*
	ListItemCount = 0;
	switch (FileFormat)
	{
	case 0:
		return "<ol>";
	case 1:
		return LineBreak();
	case 2:
		return LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::NumListItem(FString Text)
{
	/*
	ListItemCount++;
	switch (FileFormat)
	{
	case 0:
		return "<li>" $ Text;
	case 1:
		return "#" @ Text $ LineBreak();
	case 2:
		return " " $ string(ListItemCount) $ ". " @ Text $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::listitem(FString Text)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<li>" $ Text;
	case 1:
		return "*" @ Text $ LineBreak();
	case 2:
		return " *" @ Text $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::EndNumList()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "</ol>";
	case 1:
		return LineBreak();
	case 2:
		return LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::EndList()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "</ul>";
	case 1:
		return LineBreak();
	case 2:
		return LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::HorizontalRule()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<hr>";
	case 1:
	case 2:
		return "-------------------------------------------------------------------------------" $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::WikiArrow()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "";
	case 1:
		return "&rarr; ";
	case 2:
		return "";
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

void UMapDox::GenFileHeader()
{
	/*
	switch (FileFormat)
	{
	case 0:
		FWrite("<html><head><title>" $ GetLevel().Title $ "</title></head><body>");
		break;
	case 1:
		break;
	case 2:
		break;
	default:
	}
	*/
}

void UMapDox::GenFileFooter()
{
	/*
	switch (FileFormat)
	{
	case 0:
		FWrite(Center(Italic("<font size = -1>Map documentation auto-generated by MapDox.</font>")) $ "</body></html>");
		break;
	case 1:
		FWrite(LineBreak() $ LineBreak() $ "Map documentation auto-generated by MapDox." $ LineBreak());
		break;
	case 2:
		FWrite(LineBreak() $ LineBreak() $ "Map documentation auto-generated by MapDox." $ LineBreak());
		break;
	default:
	}
	*/
}

FString UMapDox::StartLoadoutTable()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<table width=800 cellpadding=5 cellspacing=1 style=\"border: 1px solid #cccccc; margin-top: 5px; background-color: #cccccc\">";
	case 1:
		return "{| width=\"800\" cellpadding=\"5\" cellspacing=\"1\" style=\"border: 1px solid #cccccc; margin-top: 5px; background-color: #cccccc\" |" $ WikiEndLine();
	case 2:
		return " --- StartTable --- " $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::LoadoutHeaderEntry()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<tr>" $ "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" $ Bold("Team") $ "</td>" $ "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" $ Bold("Role / ID") $ "</td>" $ "<td align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\">" $ Bold("Weapons / Ammo") $ "</td>" $ "</tr>";
	case 1:
		return "|-" $ WikiEndLine() $ "| align=\"center\" valign=\"top\" width=\"50\" style=\"background-color: #aaaaaa\" |" $ WikiEndLine() $ Bold("Team") $ WikiEndLine() $ "| align=\"center\" valign=\"top\" width=\"225\" style=\"background-color: #aaaaaa\" |" $ WikiEndLine() $ Bold("Role / ID") $ WikiEndLine() $ "| align=\"center\" valign=\"top\" width=\"525\" style=\"background-color: #aaaaaa\" |" $ WikiEndLine() $ Bold("Weapons / Ammo") $ WikiEndLine();
	case 2:
		return "[Team] [Role/ID] [Weapons/Ammo]" $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::LoadoutTableEntry(FString Team, FString Role, FString WeaponClass, FString SpawnClass, FString SpawnPS, FString BaseLoadout, FString Added, FString Removed)
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "<tr>" $ "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" $ Team $ "</td>" $ "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" $ Bold(Role) $ ": " $ WeaponClass $ LineBreak() $ SpawnPS $ "</td>" $ "<td width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\">" $ listitem(Bold("Base Loadout: ") $ BaseLoadout) $ listitem(Bold("Added: ") $ Added) $ listitem(Bold("Removed: ") $ Removed) $ "</td>" $ "</tr>";
	case 1:
		return "|-" $ WikiEndLine() $ "| width=\"50\" align=\"center\" valign=\"middle\" style=\"background-color: #f3f3f3\" |" $ WikiEndLine() $ Team $ WikiEndLine() $ "| width=\"225\" valign=\"top\" style=\"background-color: #f3f3f3\" |" $ WikiEndLine() $ Bold(Role) $ ": " $ WeaponClass $ LineBreak() $ "([[" $ SpawnClass $ "|" $ SpawnPS $ "]])" $ WikiEndLine() $ "| width=\"520\" valign=\"top\" style=\"background-color: #f3f3f3\" |" $ WikiEndLine() $ "* " $ Bold("Base Loadout: ") $ BaseLoadout $ LineBreak() $ "* " $ Bold("Added: ") $ Added $ LineBreak() $ "* " $ Bold("Removed: ") $ Removed $ WikiEndLine();
	case 2:
		return "[Team: " $ Team $ "] [Role: " $ Role $ " Class: " $ SpawnPS $ "] [Base: " $ BaseLoadout $ " / Added: " $ Added $ " / Removed: " $ Removed $ "]" $ LineBreak();
	default:
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

FString UMapDox::EndLoadoutTable()
{
	/*
	switch (FileFormat)
	{
	case 0:
		return "</table>";
	case 1:
		return "|}" $ LineBreak();
	case 2:
		return " --- EndTable --- " $ LineBreak();
	default:
		return "";
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

void UMapDox::GenOverview()
{
	/*
	FString ResultString = "";
	FString ObjectiveTypes = "";
	FString ObjectiveTypeName = "";
	FString MissionType = "";
	int32 PlayerCount0 = 0;
	int32 PlayerCount1 = 0;
	int32 SpawnCount = 0;
	int32 ViewpointCount = 0;
	local AGP_Viewpoint ViewpointIterator;
	local AGP_PlayerStart PSIterator;
	local AGP_Objective ObjectiveIterator;
	ResultString = "";
	ViewpointCount = 0;
	ForEach myLevel.AllActors(Class'AGP_Viewpoint', ViewpointIterator)
	{
		ViewpointCount++;
	}
	PlayerCount0 = 0;
	PlayerCount1 = 0;
	SpawnCount = 0;
	ForEach myLevel.AllActors(Class'AGP.AGP_PlayerStart', PSIterator)
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
	ForEach myLevel.AllActors(Class'AGP.AGP_Objective', ObjectiveIterator)
	{
		ObjectiveTypeName = GetItemName(string(ObjectiveIterator));
		(ObjectiveTypes $ = Left(ObjectiveTypeName, (Len(ObjectiveTypeName) - 1)) $ ", ");
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
	(ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Overview") $ LineBreak());
	(ResultString $ = Bold("Description:") @ "N/A" $ LineBreak() $ LineBreak());
	(ResultString $ = Bold("Setting:") @ SettingString() $ LineBreak());
	(ResultString $ = Bold("Time:") @ TimeString() $ LineBreak());
	(ResultString $ = Bold("Weather:") @ WeatherString() $ LineBreak());
	(ResultString $ = Bold("Spawn Points:") @ string(SpawnCount) $ LineBreak());
	(ResultString $ = Bold("Players (Team 0):") @ string(PlayerCount0) $ LineBreak());
	(ResultString $ = Bold("Players (Team 1):") @ string(PlayerCount1) $ LineBreak());
	FlushBuffer(ResultString);
	(ResultString $ = Bold("Objective Types:") @ ObjectiveTypes $ LineBreak());
	(ResultString $ = Bold("Viewpoints:") @ string(ViewpointCount) $ LineBreak());
	(ResultString $ = Bold("Mission Type:") @ MissionType $ LineBreak());
	(ResultString $ = Bold("Version Deployment:") @ VersionDeployment $ LineBreak());
	(ResultString $ = LineBreak() $ Image("yellow_star.gif", "Yellow Star") @ Bold("Filename:") @ FileNameNoExtension $ ".aao" $ LineBreak());
	(ResultString $ = HorizontalRule());
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
		IMGName = "map_" $ FileNameNoExtension $ ".jpg";
	}
	ResultString = "";
	if (FileFormat == 1)
	{
		(ResultString $ = "__NOTOC__" $ WikiEndLine() $ Image(IMGName $ "|right|frame", "Overhead View of the Map") $ WikiEndLine());
	}
	else
	{
		(ResultString $ = Image(IMGName, "Overhead View of the Map"));
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
	/*
	FString ResultString = "";
	local AGP_Viewpoint ViewpointIterator;
	ResultString = "";
	(ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Viewpoints") $ LineBreak());
	ForEach myLevel.AllActors(Class'AGP_Viewpoint', ViewpointIterator)
	{
		(ResultString $ = GetItemName(string(ViewpointIterator)) $ ":");
		(ResultString $ = StartList());
		(ResultString $ = listitem("Description:" @ ViewpointIterator.Description));
		(ResultString $ = listitem("Location: X = " $ string(ViewpointIterator.Location.X) $ ", Y = " $ string(ViewpointIterator.Location.Y) $ ", Z = " $ string(ViewpointIterator.Location.Z)));
		(ResultString $ = listitem("Rotation: Pitch = " $ string(ViewpointIterator.Rotation.Pitch) $ ", Yaw = " $ string(ViewpointIterator.Rotation.Yaw) $ ", Roll = " $ string(ViewpointIterator.Rotation.Roll)));
		(ResultString $ = listitem("Sequence:" @ string(ViewpointIterator.iSequence)));
		(ResultString $ = listitem("Spectator Viewpoint:" @ string(ViewpointIterator.bSpectatorViewpoint)));
		(ResultString $ = listitem("End Game Viewpoint:" @ EndGameToString(ViewpointIterator.EndGameViewpoint)));
		(ResultString $ = EndList());
		FlushBuffer(ResultString);
	}
	(ResultString $ = HorizontalRule());
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
	sFile = sTemp $ "tours.ini";
	iNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iNumTours; iCurTour++)
	{
		sLine = "Tour(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].Tour = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "Dependency(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].Dependency = GetPrivateProfileInt(sFile, "Tours", sLine);
		sLine = "Image(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].Image = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourText(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].TourText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "TourTextTitle(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].TourTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryText(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].HistoryText = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "HistoryTextTitle(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].HistoryTextTitle = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = "IsSequential(" $ string(iCurTour) $ ")";
		TourInfo[iCurTour].IsSequential = bool(GetPrivateProfileString(sFile, "Tours", sLine));
		sLine = "IsTraining(" $ string(iCurTour) $ ")";
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
			sLine = "MissionTitle(" $ string(iCurMission) $ ")";
			TourInfo[iCurTour].Mission[iCurMission].Title = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImage(" $ string(iCurMission) $ ")";
			TourInfo[iCurTour].Mission[iCurMission].Image = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionImageDisabled(" $ string(iCurMission) $ ")";
			TourInfo[iCurTour].Mission[iCurMission].ImageDisabled = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			sLine = "MissionMapFilename(" $ string(iCurMission) $ ")";
			TourInfo[iCurTour].Mission[iCurMission].MapFilename = GetPrivateProfileString(sFile, TourInfo[iCurTour].Tour, sLine);
			if (FileNameNoExtension ~= TourInfo[iCurTour].Mission[iCurMission].MapFilename)
			{
				iMyTour = iCurTour;
				iMyMission = iCurMission;
				bFoundTourAndMission = true;
			}
		}
	}
	sTemp = GetBaseDir() $ "\\..\\Briefings\\";
	HistoryBriefing.remove(0, HistoryBriefing.Length);
	sFile = sTemp $ TourInfo[iMyTour].HistoryText $ ".txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			HistoryBriefing[HistoryBriefing.Length] = sLine;
		}
		FClose();
	}
	Briefing.remove(0, Briefing.Length);
	sFile = sTemp $ TourInfo[iMyTour].Mission[iMyMission].MapFilename $ ".txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Briefing[Briefing.Length] = sLine;
		}
		FClose();
	}
	Team0Briefing.remove(0, Team0Briefing.Length);
	sFile = sTemp $ TourInfo[iMyTour].Mission[iMyMission].MapFilename $ "_team0.txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Team0Briefing[Team0Briefing.Length] = sLine;
		}
		FClose();
	}
	Team1Briefing.remove(0, Team1Briefing.Length);
	sFile = sTemp $ TourInfo[iMyTour].Mission[iMyMission].MapFilename $ "_team1.txt";
	if (FOpen(sFile))
	{
		if (FReadLine(sLine))
		{
			Team1Briefing[Team1Briefing.Length] = sLine;
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
		ResultString $ = "<ul>";
	}
	for (i = 0; i < Brief.Length; i++)
	{
		if (FileFormat == 1)
		{
			ResultString @ = Brief[i] $ WikiEndLine();
		}
		else
		{
			ResultString @ = Brief[i] $ LineBreak();
		}
		FlushBuffer(ResultString);
	}
	if (FileFormat == 0)
	{
		ResultString $ = "</ul>";
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
	FileBase = TourInfo[iMyTour].Mission[iMyMission].MapFilename $ ".txt";
	FileTeam[0] = TourInfo[iMyTour].Mission[iMyMission].MapFilename $ "_team0.txt";
	FileTeam[1] = TourInfo[iMyTour].Mission[iMyMission].MapFilename $ "_team1.txt";
	FileHistory = TourInfo[iMyTour].HistoryText $ ".txt";
	(ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Briefings") $ LineBreak());
	(ResultString $ = Header(3, WikiArrow() @ "Deployment UI Briefing") $ LineBreak());
	(ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ Bold("Filename: ") $ FileBase @ "(" $ TourInfo[iMyTour].Mission[iMyMission].Title $ ")") $ LineBreak());
	FlushBuffer(ResultString);
	(ResultString $ = Header(3, Bold("History Briefing: ") $ FileHistory @ "(" $ TourInfo[iMyTour].HistoryTextTitle $ ")") $ LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(HistoryBriefing);
	(ResultString $ = Header(3, Bold("Mission Briefing: ") $ FileBase) $ LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Briefing);
	(ResultString $ = Header(3, Bold("Team 0 Briefing: ") $ FileTeam[0]) $ LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Team0Briefing);
	(ResultString $ = Header(3, Bold("Team 1 Briefing: ") $ FileTeam[1]) $ LineBreak());
	FlushBuffer(ResultString);
	GenBriefingText(Team1Briefing);
	(ResultString $ = HorizontalRule());
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
			ResultString $ = class<Inventory>(DynamicLoadObject(PS.SpawnClass.Default.ClassEquipment[i], Class'Class')).Default.ItemName $ ", ";
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
		if (PS.AddedInventory[i] != None)
		{
			ResultString $ = PS.AddedInventory[i].Default.ItemName $ ", ";
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
		if (PS.RemoveClassInventory[i] != None)
		{
			ResultString $ = PS.RemoveClassInventory[i].Default.ItemName $ ", ";
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
	/*
	local EWeaponType Weapon1;
	local EWeaponType Weapon2;
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
	/*
	local AGP_PlayerStart Temp;
	Temp = PS1;
	PS1 = PS2;
	PS2 = Temp;
	*/
}

void UMapDox::SortFT(TArray<AAGP_PlayerStart*>& FireTeam)
{
	/*
	int32 i = 0;
	int32 j = 0;
	for (i = 0; i < FireTeam.Length; i++)
	{
		for (j = (i + 1); j < FireTeam.Length; j++)
		{
			if (Compare(FireTeam[j], FireTeam[i]))
			{
				Swap(FireTeam[j], FireTeam[i]);
			}
		}
	}
	*/
}

void UMapDox::GenLoadouts()
{
	/*
	int32 Team = 0;
	int32 FireTeam = 0;
	int32 i = 0;
	FString ResultString = "";
	local AGP_PlayerStart PSIterator;
	local TArray<AGP_PlayerStart> PSList;
	local TArray<AGP_PlayerStart> FireTeamList;
	ResultString = "";
	ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Loadouts") $ LineBreak();
	ForEach GetLevel().AllActors(Class'AGP.AGP_PlayerStart', PSIterator)
	{
		PSList[PSList.Length] = PSIterator;
	}
	for (Team = 0; Team < 2; Team++)
	{
		ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ "Team" @ string(Team) @ "(" $ GetLevel().TeamName[Team] $ ")") $ LineBreak();
		for (FireTeam = 0; FireTeam < 5; FireTeam++)
		{
			FireTeamList.remove(0, FireTeamList.Length);
			for (i = 0; i < PSList.Length; i++)
			{
				if ((PSList[i].TeamNumber == Team) && (PSList[i].FireTeam == FireTeam))
				{
					FireTeamList[FireTeamList.Length] = PSList[i];
				}
			}
			if (FireTeamList.Length <= 0)
			{
			}
			if (FireTeam == 0)
			{
				ResultString $ = StartLoadoutTable() $ LoadoutHeaderEntry();
			}
			else
			{
				ResultString $ = StartLoadoutTable();
			}
			FlushBuffer(ResultString);
			SortFT(FireTeamList);
			for (i = 0; i < FireTeamList.Length; i++)
			{
				ResultString $ = LoadoutTableEntry(FTToString(FireTeamList[i].FireTeam), PSToRole(FireTeamList[i]), FireTeamList[i].SpawnClass.Default._ShortName, GetItemName(string(FireTeamList[i].SpawnClass)), string(FireTeamList[i].Name), GenerateDefaultItems(FireTeamList[i]), GenerateAddedItems(FireTeamList[i]), GenerateRemovedItems(FireTeamList[i]));
				FlushBuffer(ResultString);
			}
			ResultString $ = EndLoadoutTable();
			FlushBuffer(ResultString);
		}
	}
	ResultString $ = HorizontalRule();
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenObjectives()
{
	/*
	int32 i = 0;
	FString ResultString = "";
	local TArray<AGP_Objective> ObjectivesList;
	local AGP_Objective ObjectiveIterator;
	ResultString = "";
	ForEach myLevel.AllActors(Class'AGP.AGP_Objective', ObjectiveIterator)
	{
		ObjectivesList[ObjectivesList.Length] = ObjectiveIterator;
	}
	ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Objectives") $ LineBreak();
	ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ "Level Scoring") $ LineBreak();
	ResultString $ = StartList();
	ResultString $ = listitem("Team 0 FT Leader Bonus Per Survivor: " $ string(GetLevel().Score_Team0_FTLeaderBonusPerSurvivor));
	ResultString $ = listitem("Team 0 Squad Leader Bonus Per Survivor: " $ string(GetLevel().Score_Team0_SquadLeaderBonusPerSurvivor));
	ResultString $ = listitem("Team 0 Survival Win: " $ string(GetLevel().Score_Team0_SurviveWin));
	ResultString $ = listitem("Team 0 Win: " $ string(GetLevel().Score_Team0_Win));
	ResultString $ = listitem("Team 1 FT Leader Bonus Per Survivor: " $ string(GetLevel().Score_Team1_FTLeaderBonusPerSurvivor));
	ResultString $ = listitem("Team 1 Squad Leader Bonus Per Survivor: " $ string(GetLevel().Score_Team1_SquadLeaderBonusPerSurvivor));
	ResultString $ = listitem("Team 1 Survival Win: " $ string(GetLevel().Score_Team1_SurviveWin));
	ResultString $ = listitem("Team 1 Win: " $ string(GetLevel().Score_Team1_Win));
	ResultString $ = EndList();
	FlushBuffer(ResultString);
	for (i = 0; i < ObjectivesList.Length; i++)
	{
		ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(ObjectivesList[i]))) $ LineBreak();
		ResultString $ = Bold(WikiArrow() @ "Specifics:") $ LineBreak();
		ResultString $ = StartList();
		ResultString $ = listitem("Location: X = " $ string(ObjectivesList[i].Location.X) $ ", Y = " $ string(ObjectivesList[i].Location.Y) $ ", Z = " $ string(ObjectivesList[i].Location.Z));
		ResultString $ = listitem("Attack Description: " $ ObjectivesList[i].AttackDescription);
		ResultString $ = listitem("Defense Description: " $ ObjectivesList[i].DefenseDescription);
		ResultString $ = listitem("Accomplish Message: " $ ObjectivesList[i].AccomplishMessage);
		ResultString $ = listitem("Failed Defense Message: " $ ObjectivesList[i].FailedDefenseMessage);
		FlushBuffer(ResultString);
		ResultString $ = listitem("Required to win: " $ string(ObjectivesList[i].bRequiredToWin));
		ResultString $ = listitem("Instant win: " $ string(ObjectivesList[i].bInstantWin));
		ResultString $ = listitem("Attacking Team: " $ string(ObjectivesList[i].AttackTeam));
		ResultString $ = listitem("Recapturable (Take Turns): " $ string(ObjectivesList[i].bTakeTurns));
		ResultString $ = listitem("Kick Instigator on Damaged: " $ string(ObjectivesList[i].bKickInstigator_Damage));
		ResultString $ = listitem("Kick Instigator on Killed: " $ string(ObjectivesList[i].bKickInstigator_Kill));
		ResultString $ = listitem("Linked NPC: " $ string(ObjectivesList[i].LinkedNPC));
		ResultString $ = EndList();
		FlushBuffer(ResultString);
		ResultString $ = StartList();
		ResultString $ = Bold(WikiArrow() @ "Scoring:") $ LineBreak();
		ResultString $ = listitem("Assault Player: " $ string(ObjectivesList[i].Score_AssaultPlayer));
		ResultString $ = listitem("Assault Helper: " $ string(ObjectivesList[i].Score_AssaultHelper));
		ResultString $ = listitem("Assault Team: " $ string(ObjectivesList[i].Score_AssaultTeam));
		ResultString $ = listitem("Assault Survivor: " $ string(ObjectivesList[i].Score_AssaultSurvivor));
		ResultString $ = listitem("Assault Defender Kill: " $ string(ObjectivesList[i].Score_DefenderKill));
		ResultString $ = listitem("Killed ROE Penalty: " $ string(ObjectivesList[i].Kill_ROE_Penalty));
		ResultString $ = listitem("ROE Multiplier: " $ string(ObjectivesList[i].fROE_Damage_Multiplier));
		ResultString $ = EndList();
		FlushBuffer(ResultString);
	}
	*/
}

void UMapDox::GenCommVolumes()
{
	/*
	FString ResultString = "";
	local Box BBox;
	local Volume VolumeIterator;
	ResultString = "";
	(ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Comm Volumes") $ LineBreak());
	ForEach GetLevel().AllActors(Class'Volume', VolumeIterator)
	{
		if (VolumeIterator.bIsCommVolume)
		{
			BBox = VolumeIterator.GetBoundingBox();
			(ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(VolumeIterator))) $ LineBreak());
			(ResultString $ = StartList());
			(ResultString $ = listitem("Location Name: " $ VolumeIterator.LocationName));
			(ResultString $ = listitem("Bounding Box: {[" $ string(BBox.Min.X) $ ", " $ string(BBox.Min.Y) $ "], Max: [" $ string(BBox.Max.X) $ ", " $ string(BBox.Max.Y) $ "]}"));
			(ResultString $ = EndList());
			FlushBuffer(ResultString);
		}
	}
	(ResultString $ = HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenOtherVolumes()
{
	/*
	FString ResultString = "";
	local Box BBox;
	local Volume VolumeIterator;
	ResultString = "";
	(ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Other Volumes") $ LineBreak());
	ForEach GetLevel().AllActors(Class'Volume', VolumeIterator)
	{
		if (!VolumeIterator.bIsCommVolume)
		{
			BBox = VolumeIterator.GetBoundingBox();
			(ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ GetItemName(string(VolumeIterator))) $ LineBreak());
			(ResultString $ = StartList());
			(ResultString $ = listitem("Location Name: " $ VolumeIterator.LocationName));
			(ResultString $ = listitem("Bounding Box: {[" $ string(BBox.Min.X) $ ", " $ string(BBox.Min.Y) $ "], Max: [" $ string(BBox.Max.X) $ ", " $ string(BBox.Max.Y) $ "]}"));
			(ResultString $ = EndList());
			FlushBuffer(ResultString);
		}
	}
	(ResultString $ = HorizontalRule());
	FlushBuffer(ResultString);
	*/
}

void UMapDox::GenSpawns()
{
	/*
	int32 i = 0;
	FString ResultString = "";
	local PSSet PSSetIterator;
	ResultString = "";
	ResultString $ = Header(2, Image("aa_star.gif", "AAStar") @ "Player Spawns") $ LineBreak();
	for (i = 0; i < 2; i++)
	{
		ResultString $ = Header(3, Image("yellow_star.gif", "Yellow Star") @ "Team" @ string(i) @ "(" $ GetLevel().TeamName[i] $ ")") $ LineBreak();
		ForEach GetLevel().AllActors(Class'PSSet', PSSetIterator)
		{
			if (PSSetIterator.Team == i)
			{
				ResultString $ = StartList();
				ResultString $ = listitem("Name: " $ GetItemName(string(PSSetIterator)));
				ResultString $ = listitem("Set Tag: " $ string(PSSetIterator.SetTag));
				ResultString $ = listitem("Location: X = " $ string(PSSetIterator.Location.X) $ ", Y = " $ string(PSSetIterator.Location.Y) $ ", Z = " $ string(PSSetIterator.Location.Z));
				ResultString $ = listitem("Team: " $ string(PSSetIterator.Team));
				ResultString $ = EndList();
				FlushBuffer(ResultString);
			}
		}
	}
	ResultString $ = HorizontalRule();
	FlushBuffer(ResultString);
	*/
}

bool UMapDox::Build()
{
	/*
	FString TempFileName = "";
	myLevel = None;
	if (GetLevel() == None)
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
	TempFileName = GetBaseDir() $ "\\..\\MapDox\\";
	CreateDir(TempFileName);
	TempFileName = TempFileName $ FileNameNoExtension $ FileExtension;
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
