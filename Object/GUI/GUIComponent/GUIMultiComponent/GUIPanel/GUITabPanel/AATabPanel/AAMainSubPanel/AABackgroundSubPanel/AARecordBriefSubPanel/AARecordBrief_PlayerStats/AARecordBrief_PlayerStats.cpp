// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBrief_PlayerStats/AARecordBrief_PlayerStats.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AATeamList.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"

UAARecordBrief_PlayerStats::UAARecordBrief_PlayerStats()
{
	
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.06625;
	MyPanel->WinHeight=0.8825;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	
	guicbPanel = MyPanel;
	DefaultRecordBriefText = "<text><content>Please log in to view your record brief.</content></text>";
	TemplateFile = "DynamicContent/NML/x_rbrief_stats.nml";
	DefaultPanelText = "Player Statistics";
	LoggedInPanelText = "Player Stats for ";
	PanelCaption = "Player Statistics";
}

void UAARecordBrief_PlayerStats::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
	}
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UAARecordBrief_PlayerStats::Opened(UGUIComponent* Sender)
{
	UpdateHeaderWithUserName();
	if (!Cast<UAAGUIController>(Controller)->bLoggedIn)
	{
		guicbPanel->RemoveAllComponents();
		MyNML->ParseNMLFromString(DefaultRecordBriefText, guicbPanel);
	}
}

bool UAARecordBrief_PlayerStats::ButtonClick(UGUIComponent* Sender)
{
	if ((Cast<UGUILabelButton>(Sender) != nullptr) || (Cast<UGUIImageButton>(Sender) != nullptr))
	{
		selected = Sender;
	}
	if (selected == nullptr)
	{
		return false;
	}
	if (Cast<UGUILabelButton>(Sender) != nullptr)
	{
		Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUILabelButton>(selected)->Caption, Cast<UGUILabelButton>(selected)->link);
	}
	else
	{
		if (Cast<UGUIImageButton>(Sender) != nullptr)
		{
			Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUIImageButton>(selected)->Caption, Cast<UGUIImageButton>(selected)->link);
		}
	}
	return true;
}

void UAARecordBrief_PlayerStats::ProcessRecordBriefData()
{
	/*
	FString RBNML = "";
	if (ResultCode != 1)
	{
		AddNMLTextBlock("Error receiving record brief...please try again later.", RBNML);
		if (MyNML != nullptr)
		{
			MyNML.ParseNMLFromString(RBNML, guicbPanel);
		}
	}
	else
	{
		MyNML.__dPreParser__Delegate = InsertDataIntoNML;
		MyNML.ParseNMLFromServer("/x_rbrief_stats.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

FString UAARecordBrief_PlayerStats::RankImageFromHonor()
{
	/*
	switch (true)
	{
	case (RecordBrief.Honor < 20):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e2";
	case (RecordBrief.Honor < 30):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e3";
	case (RecordBrief.Honor < 50):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e4";
	case (RecordBrief.Honor < 60):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e5";
	case (RecordBrief.Honor < 70):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e6";
	case (RecordBrief.Honor < 80):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e7";
	case (RecordBrief.Honor < 90):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e8";
	case (RecordBrief.Honor <= 100):
		return "t_aao_ui.uniform.t_ui_uniform_patch_e9";
	default:
		return "t_aao_ui.uniform.t_ui_uniform_patch_e2";
	}
	*/
	return "FAKE";     //FAKE   /ELiZ
}

FString UAARecordBrief_PlayerStats::RankDescriptionFromHonor()
{
	/*
	switch (true)
	{
	case (RecordBrief.Honor < 20):
		return "Private|(E-2)";
	case (RecordBrief.Honor < 30):
		return "Private First Class|(E-3)";
	case (RecordBrief.Honor < 50):
		return "Specialist|(E-4)";
	case (RecordBrief.Honor < 60):
		return "Sergeant|(E-5)";
	case (RecordBrief.Honor < 70):
		return "Staff Sergeant|(E-6)";
	case (RecordBrief.Honor < 80):
		return "Sergeant First Class|(E-7)";
	case (RecordBrief.Honor < 90):
		return "Master Sergeant|(E-8)";
	case (RecordBrief.Honor <= 100):
		return "Sergeant Major|(E-9)";
	default:
		return "";
	}
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void UAARecordBrief_PlayerStats::InsertDataIntoNML(FString& NML)
{
	/*
	AHumanController* HC = nullptr;
	FString WorkingString = "";
	int32 Grade = 0;
	HC = Cast<AHumanController>(PlayerOwner());
	ReplaceText(NML, "%UserName%", Caps(RecordBrief.UserName));
	ReplaceText(NML, "%LastLoginDate%", FixDate(RecordBrief.LastLoginDate));
	ReplaceText(NML, "%MemberSince%", FixDate(RecordBrief.CreationDate));
	ReplaceText(NML, "%GroupName%", GetGroup(RecordBrief.GroupID));
	if (Cast<AHumanController>(PlayerOwner())->iCompleted[1] != 15)
	{
		if (HC.PlayerReplicationInfo.GetExperience() >= 15000)
		{
			ReplaceText(NML, "%XPHonor%", "15000 / 20 (BCT Training Not Complete)");
		}
		else
		{
			ReplaceText(NML, "%XPHonor%", FString::FromInt(RecordBrief.Experience) + " / " + FString::FromInt(RecordBrief.Honor) + " (BCT Training Not Complete)");
		}
	}
	else
	{
		ReplaceText(NML, "%XPHonor%", FString::FromInt(RecordBrief.Experience) + " / " + FString::FromInt(RecordBrief.Honor));
	}
	ReplaceText(NML, "%RankImage%", RankImageFromHonor());
	ReplaceText(NML, "%RankDescription%", RankDescriptionFromHonor());
	ReplaceText(NML, "%HoursPlayed%", FString::FromInt(RecordBrief.HoursPlayed));
	ReplaceText(NML, "%MatchesCompleted%", FString::FromInt(RecordBrief.MatchesCompleted));
	ReplaceText(NML, "%RoundsWonLost%", FString::FromInt(RecordBrief.RoundsWon) + " / " + FString::FromInt(RecordBrief.RoundsLost));
	ReplaceText(NML, "%ObjectivesCompleted%", FString::FromInt(RecordBrief.ObjectivesCompleted));
	ReplaceText(NML, "%DeathsWhileCompletingObjectives%", FString::FromInt(RecordBrief.ObjectiveDeaths));
	ReplaceText(NML, "%AvgMissionScore%", FString::FromInt(RecordBrief.AverageScore));
	ReplaceText(NML, "%NumTimesHealed%", FString::FromInt(RecordBrief.TimesHealed));
	ReplaceText(NML, "%MedPacksApplied%", FString::FromInt(RecordBrief.MedpaksApplied));
	ReplaceText(NML, "%TimeInSquadLeaderRole%", RecordBrief.SquadLeaderSeconds);
	ReplaceText(NML, "%TimeInFTLeader%", RecordBrief.FireteamLeaderSeconds);
	ReplaceText(NML, "%TimeInNonLeader%", RecordBrief.SoldierSeconds);
	ReplaceText(NML, "%TimeLinkedToSquadLeader%", RecordBrief.SquadLeaderLinkedSeconds);
	ReplaceText(NML, "%TimeLinkedToFTLeader%", RecordBrief.FireteamLeaderLinkedSeconds);
	ReplaceText(NML, "%TimeLinkedToOtherSoldiers%", RecordBrief.SoldierLinkedSeconds);
	ReplaceText(NML, "%MedicTrained%", FixQualificationDate(RecordBrief.MedicTourCompletionDate));
	ReplaceText(NML, "%AirborneTrained%", FixQualificationDate(RecordBrief.AirborneTourCompletionDate));
	ReplaceText(NML, "%AdvMarksmanTrained%", FixQualificationDate(RecordBrief.AdvancedMarksmanshipTourCompletionDate));
	ReplaceText(NML, "%SFTrained%", FixQualificationDate(RecordBrief.SpecialForcesTrainingTourCompletionDate));
	ReplaceText(NML, "%ROETotal%", FString::FromInt(RecordBrief.ROE));
	ReplaceText(NML, "%FavoriteMap%", RecordBrief.FavoriteMap);
	ReplaceText(NML, "%FavoriteMapImage%", GetImageFrom28Mapname(RecordBrief.FavoriteMap));
	ReplaceText(NML, "%PistolShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[1].ShotsFired));
	ReplaceText(NML, "%PistolHits%", FString::FromInt(RecordBrief.WeaponUseRecords[1].ShotsHit));
	ReplaceText(NML, "%PistolKills%", FString::FromInt(RecordBrief.WeaponUseRecords[1].Kills));
	ReplaceText(NML, "%PistolUsagePercent%", FString::FromInt(GetWeaponShotPercentage(1)) + "%");
	if (RecordBrief.WeaponUseRecords[1].ShotsFired != 0)
	{
		ReplaceText(NML, "%PistolAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[1].ShotsHit) / float(RecordBrief.WeaponUseRecords[1].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%PistolAccuracy%", FString::FromInt(0));
	}
	ReplaceText(NML, "%RifleShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[0].ShotsFired));
	ReplaceText(NML, "%RifleHits%", FString::FromInt(RecordBrief.WeaponUseRecords[0].ShotsHit));
	ReplaceText(NML, "%RifleKills%", FString::FromInt(RecordBrief.WeaponUseRecords[0].Kills));
	ReplaceText(NML, "%RifleUsagePercent%", FString::FromInt(GetWeaponShotPercentage(0)) + "%");
	if (RecordBrief.WeaponUseRecords[0].ShotsFired != 0)
	{
		ReplaceText(NML, "%RifleAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[0].ShotsHit) / float(RecordBrief.WeaponUseRecords[0].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%RifleAccuracy%", FString::FromInt(0));
	}
	ReplaceText(NML, "%MGShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[2].ShotsFired));
	ReplaceText(NML, "%MGHits%", FString::FromInt(RecordBrief.WeaponUseRecords[2].ShotsHit));
	ReplaceText(NML, "%MGKills%", FString::FromInt(RecordBrief.WeaponUseRecords[2].Kills));
	ReplaceText(NML, "%MGUsagePercent%", FString::FromInt(GetWeaponShotPercentage(2)) + "%");
	if (RecordBrief.WeaponUseRecords[2].ShotsFired != 0)
	{
		ReplaceText(NML, "%MGAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[2].ShotsHit) / float(RecordBrief.WeaponUseRecords[2].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%MGAccuracy%", FString::FromInt(0));
	}
	ReplaceText(NML, "%SniperShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[3].ShotsFired));
	ReplaceText(NML, "%SniperHits%", FString::FromInt(RecordBrief.WeaponUseRecords[3].ShotsHit));
	ReplaceText(NML, "%SniperKills%", FString::FromInt(RecordBrief.WeaponUseRecords[3].Kills));
	ReplaceText(NML, "%SniperUsagePercent%", FString::FromInt(GetWeaponShotPercentage(3)) + "%");
	if (RecordBrief.WeaponUseRecords[3].ShotsFired != 0)
	{
		ReplaceText(NML, "%SniperAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[3].ShotsHit) / float(RecordBrief.WeaponUseRecords[3].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%SniperAccuracy%", FString::FromInt(0));
	}
	ReplaceText(NML, "%RocketShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[4].ShotsFired));
	ReplaceText(NML, "%RocketHits%", FString::FromInt(RecordBrief.WeaponUseRecords[4].ShotsHit));
	ReplaceText(NML, "%RocketKills%", FString::FromInt(RecordBrief.WeaponUseRecords[4].Kills));
	ReplaceText(NML, "%RocketUsagePercent%", FString::FromInt(GetWeaponShotPercentage(4)) + "%");
	if (RecordBrief.WeaponUseRecords[4].ShotsFired != 0)
	{
		ReplaceText(NML, "%RocketAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[4].ShotsHit) / float(RecordBrief.WeaponUseRecords[4].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%RocketAccuracy%", FString::FromInt(0));
	}
	ReplaceText(NML, "%GrenadeShotsFired%", FString::FromInt(RecordBrief.WeaponUseRecords[5].ShotsFired));
	ReplaceText(NML, "%GrenadeHits%", FString::FromInt(RecordBrief.WeaponUseRecords[5].ShotsHit));
	ReplaceText(NML, "%GrenadeKills%", FString::FromInt(RecordBrief.WeaponUseRecords[5].Kills));
	ReplaceText(NML, "%GrenadeUsagePercent%", FString::FromInt(GetWeaponShotPercentage(5)) + "%");
	if (RecordBrief.WeaponUseRecords[5].ShotsFired != 0)
	{
		ReplaceText(NML, "%GrenadeAccuracy%", FString::FromInt(((float(RecordBrief.WeaponUseRecords[5].ShotsHit) / float(RecordBrief.WeaponUseRecords[5].ShotsFired)) * 100)));
	}
	else
	{
		ReplaceText(NML, "%GrenadeAccuracy%", FString::FromInt(0));
	}
	Grade = RecordBrief.QualificationRecords[0].Grade;
	if ((Grade >= 24) && (Grade <= 28))
	{
		WorkingString = "Marksman Qualified on ";
	}
	else
	{
		if ((Grade >= 29) && (Grade <= 35))
		{
			WorkingString = "Sharpshooter Qualified on ";
		}
		else
		{
			if ((Grade >= 36) && (Grade <= 40))
			{
				WorkingString = "Expert Qualified on ";
			}
		}
	}
	(WorkingString += FixDate(RecordBrief.QualificationRecords[0].Date));
	if (Grade < 24)
	{
		WorkingString = "Not Qualified";
	}
	ReplaceText(NML, "%RifleMarksmanshipQual%", WorkingString);
	if (RecordBrief.QualificationRecords[2].Grade > 0)
	{
		WorkingString = "CROWS HMMWV Driver Qualified on " + FixDate(RecordBrief.QualificationRecords[2].Date);
	}
	else
	{
		WorkingString = "Not Qualified";
	}
	ReplaceText(NML, "%DriverQual%", WorkingString);
	if ((Cast<AHumanController>(PlayerOwner())->iCompleted[1] != 15) && (HC.PlayerReplicationInfo.GetExperience() >= 15000))
	{
		ReplaceText(NML, "%XPPrompt%", "Complete BCT training to apply " + FString::FromInt((HC.PlayerReplicationInfo.GetExperience() - 15000)) + " points to your next honor level.");
		ReplaceText(NML, "%XPReqd%", "");
	}
	else
	{
		ReplaceText(NML, "%XPPrompt%", "XP Required for next HONOR:");
		ReplaceText(NML, "%XPReqd%", FString::FromInt(CalculateExperienceNeeded(HC.PlayerReplicationInfo.GetExperience(), HC.PlayerReplicationInfo.GetHonor())));
	}
	*/
}

FString UAARecordBrief_PlayerStats::ToHHMMSS(float Time)
{
	FString strTime = "";
	int32 NumSeconds = 0;
	/*
	strTime = FString::FromInt(int(Time)) @ "hrs";
	NumSeconds = int((float(3600) * (Time - float(int(Time)))));
	(strTime @ = FString::FromInt((NumSeconds / 60)) @ "min");
	(strTime @ = FString::FromInt(int((float(NumSeconds) % float(60)))) @ "sec");
	*/
	return strTime;
}

FString UAARecordBrief_PlayerStats::FixDate(FString Date)
{
	TArray<FString> DateChunks = {};
	/*
	if (Date == "")
	{
		return "";
	}
	Split(Date, "-", DateChunks);
	return "20" + DateChunks[2] + "-" + DateChunks[1] + "-" + DateChunks[0];
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString UAARecordBrief_PlayerStats::FixQualificationDate(FString Date)
{
	TArray<FString> DateChunks = {};
	/*
	Split(Date, ":", DateChunks);
	if (0 == Len(Date))
	{
		return "Unknown";
	}
	if (3 != DateChunks.Num())
	{
		Log("Failed to parse qualification date '" @ Date @ "'");
		return "<unknown>";
	}
	switch (DateChunks[1])
	{
	case "01":
		DateChunks[1] = "JAN";
		break;
	case "02":
		DateChunks[1] = "FEB";
		break;
	case "03":
		DateChunks[1] = "MAR";
		break;
	case "04":
		DateChunks[1] = "APR";
		break;
	case "05":
		DateChunks[1] = "MAY";
		break;
	case "06":
		DateChunks[1] = "JUN";
		break;
	case "07":
		DateChunks[1] = "JUL";
		break;
	case "08":
		DateChunks[1] = "AUG";
		break;
	case "09":
		DateChunks[1] = "SEP";
		break;
	case "10":
		DateChunks[1] = "OCT";
		break;
	case "11":
		DateChunks[1] = "NOV";
		break;
	case "12":
		DateChunks[1] = "DEC";
		break;
	default:
	}
	return "20" + DateChunks[0] + "-" + DateChunks[1] + "-" + DateChunks[2];
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString UAARecordBrief_PlayerStats::GetGroup(int32 Id)
{
	/*
	if (UAATeamList::StaticClass().Default.GroupDescriptions[Id] != "")
	{
		return UAATeamList::StaticClass().Default.GroupDescriptions[Id];
	}
	else
	{
		if (Id == 1440)
		{
			return "AA Community Manager";
		}
		else
		{
			if (Id == 1441)
			{
				return "AA Volunteer";
			}
			else
			{
				if (Id == 1460)
				{
					return "U.S. Coast Guard";
				}
				else
				{
					return "Normal User";
				}
			}
		}
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void UAARecordBrief_PlayerStats::ProcessRecordBriefError()
{
	//FString RBNML = "";
	//AddNMLTextBlock("There was an error retrieving your Record Brief.  Please try again later.", RBNML);
}

void UAARecordBrief_PlayerStats::AddNMLTextBlock(FString TextToAdd, FString& NML)
{
	//(NML += "<text><content>" + TextToAdd + "</content></text>");
}

float UAARecordBrief_PlayerStats::GetWeaponShotPercentage(int32 WeaponClass)
{
	/*
	int32 i = 0;
	int32 TotalShotsFired = 0;
	TotalShotsFired = 0;
	for (i = 0; i < 6; i++)
	{
		TotalShotsFired += RecordBrief.WeaponUseRecords[i].ShotsFired;
	}
	if (float(TotalShotsFired) > 0)
	{
		return ((float(RecordBrief.WeaponUseRecords[WeaponClass].ShotsFired) / float(TotalShotsFired)) * 100);
	}
	else
	{
		return 0;
	}
	*/
	return 0;    //FAKE   /ELiZ
}

FString UAARecordBrief_PlayerStats::GetImageFrom28Mapname(FString MapName)
{
	int32 TourID = 0;
	int32 MissionID = 0;
	ALevelInfo* myLevel = nullptr;
	/*
	myLevel = PlayerOwner().Level;
	if (myLevel != nullptr)
	{
		PlayerOwner().Level.GetMBSTitleTourAndMissionPrivate(MapName, TourID, MissionID);
		return PlayerOwner().Level.GetTourMissionImage(TourID, MissionID);
	}
	*/
	return "";
}

