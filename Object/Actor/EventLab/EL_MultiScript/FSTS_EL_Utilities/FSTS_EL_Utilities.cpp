// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_DirectionMarker/FSTS_DirectionMarker.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_HelpMarker.h"
#include "AA29/Object/Actor/Projector/FSTS_LocationMarker/FSTS_LocationMarker.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/PlayerBlockingVolume/TriggeredPlayerBlockingVolume/TriggeredPlayerBlockingVolume.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"

AFSTS_EL_Utilities::AFSTS_EL_Utilities()
{
	bCreateLocationMarker = true;
	bCreateHelpMarker = true;
	NumStationsRequired = 1;
}

void AFSTS_EL_Utilities::PostInit()
{
	Super::PostInit();
	CreateMarkers();
	if (bMasterScript)
	{
		InitBlockingVolumesArray();
	}
}

void AFSTS_EL_Utilities::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == StationObjectiveTag)
		{
			StationObjective = Cast<AAGP_Objective>(SearchActor);
		}
	}
	*/
}

void AFSTS_EL_Utilities::Destroyed()
{
	DrillSergeant = nullptr;
	AltDrillSergeant = nullptr;
	ProximityDestination = nullptr;
	StationObjective = nullptr;
	if (LocationMarker != nullptr)
	{
		LocationMarker->Destroy();
	}
	if (DirectionMarker != nullptr)
	{
		DirectionMarker->Destroy();
	}
	if (HelpMarker != nullptr)
	{
		HelpMarker->Destroy();
	}
	Super::Destroyed();
}

void AFSTS_EL_Utilities::Reset()
{
	bStationComplete = false;
	bPassedTraining = false;
	if (DrillSergeant != nullptr)
	{
		DrillSergeant->StopLIPSincAnim();
	}
	if (AltDrillSergeant != nullptr)
	{
		AltDrillSergeant->StopLIPSincAnim();
	}
	Super::Reset();
}

void AFSTS_EL_Utilities::EventLabTick(float DeltaTime)
{
	Super::EventLabTick(DeltaTime);
	if (bDormant)
	{
		return;
	}
	if (bDetectActorProximity)
	{
		CheckActorProximity();
	}
}

void AFSTS_EL_Utilities::StartHelpTimer(int32 HelpIndex, bool bRepeat)
{
	/*
	if ((HelpIndex < 0) || (HelpIndex >= HelpInfoList.Num()))
	{
		Log("Unable to run StartHelpTimer for HelpIndex=" + FString::FromInt(HelpIndex) + ", index is out of range.", "FSTS_EL_Utilities");
		return;
	}
	SetTimerEvent(HelpInfoList[HelpIndex].HelpName, HelpInfoList[HelpIndex].HelpTimer, 0, bRepeat);
	*/
}

bool AFSTS_EL_Utilities::SetHelpLSActor(AActor* nActor, bool bNoSetAll, int32 Index)
{
	int32 i = 0;
	if (bNoSetAll)
	{
		if ((Index >= 0) && (Index < HelpInfoList.Num()))
		{
			HelpInfoList[Index].LSActor = nActor;
			return true;
		}
	}
	else
	{
		for (i = 0; i < HelpInfoList.Num(); i++)
		{
			HelpInfoList[i].LSActor = nActor;
		}
		return true;
	}
	return false;
}

void AFSTS_EL_Utilities::LogStationEnd(AFSTS_EL_Utilities* CompletedStation, bool bStationPassed)
{
	int32 StationNum = 0;
	FString CompleteMsg = "";
	/*
	if (bMasterScript)
	{
		StationNum = CompletedStation.GetLevelScriptsListIndex();
		if ((StationNum >= 0) && (StationNum < LevelScriptsList.Num()))
		{
			CompleteMsg = "Station " + FString::FromInt(StationNum) + " - " + Cast<AFSTS_EL_Utilities>(LevelScriptsList[StationNum]).StationName;
			if (bStationPassed)
			{
				(CompleteMsg += " - GO");
				FSTS_EL_Utilities(LevelScriptsList[StationNum]).StationObjective.AccomplishObjective(Level.GetLocalPlayerController().Pawn);
				FSTS_EL_Utilities(LevelScriptsList[StationNum]).StationObjective.SendPercentage(Level.GetLocalPlayerController().Pawn);
			}
			else
			{
				(CompleteMsg += " - NO GO");
			}
		}
		else
		{
			Log("WARNING! Bad StationNum for station" @ FString::FromInt(CompletedStation) + ", StationNum=" + FString::FromInt(StationNum) + ".", "FSTS_EL_Utilities");
		}
	}
	else
	{
		FSTS_EL_Utilities(MasterScript).LogStationEnd(CompletedStation, bStationPassed);
	}
	*/
}

int32 AFSTS_EL_Utilities::GetHelpInfoListIndex(FName HelpName)
{
	int32 i = 0;
	/*
	for (i = 0; i < HelpInfoList.Num(); i++)
	{
		if (HelpName == HelpInfoList[i].HelpName)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool AFSTS_EL_Utilities::HandleHelpTimerEvent(FName EventName)
{
	/*
	int32 HelpInfoIndex = 0;
	HelpInfoIndex = GetHelpInfoListIndex(EventName);
	if (HelpInfoIndex == -1)
	{
		return false;
	}
	if (HelpInfoIndex >= 0)
	{
		DoHelpMessage(HelpInfoIndex);
		return true;
	}
	*/
	return false;
}

void AFSTS_EL_Utilities::DoHelpMessage(int32 Index)
{
	/*
	PlayTip(HelpInfoList[Index].Line1HelpText, HelpInfoList[Index].Line2HelpText, (HelpInfoList[Index].HelpTimer / 2));
	if ((HelpInfoList[Index].LSActor != nullptr) && (HelpInfoList[Index].LSHelpAnimation != "None"))
	{
		PlayLSAnim(HelpInfoList[Index].LSHelpAnimation, HelpInfoList[Index].LSActor);
	}
	*/
}

void AFSTS_EL_Utilities::StopHelpTimer(int32 HelpIndex)
{
	int32 i = 0;
	/*
	if ((HelpIndex < 0) || (HelpIndex >= HelpInfoList.Num()))
	{
		Log("Unable to run StopHelpTimer for HelpIndex=" + FString::FromInt(HelpIndex) + ", index is out of range.", "FSTS_EL_Utilities");
		return;
	}
	if (HelpIndex != 0)
	{
		if (StopTimer(HelpInfoList[HelpIndex].HelpName, 0))
		{
			return;
		}
	}
	for (i = 0; i < HelpInfoList.Num(); i++)
	{
		if (HasTimerEventName(HelpInfoList[i].HelpName))
		{
			StopTimer(HelpInfoList[i].HelpName, 0);
		}
	}
	*/
}

bool AFSTS_EL_Utilities::CheckLocationProximity(FVector DestinationLocation, FVector VariableLocation, float Radius)
{
	float dist = 0;
	/*
	dist = VSize((DestinationLocation - VariableLocation));
	return (dist <= Radius);
	*/
	return false;     //FAKE   /EliZ
}

bool AFSTS_EL_Utilities::CheckActorProximity()
{
	/*
	if (CheckLocationProximity(ProximityDestination->GetActorLocation(), ProximityMoveActor->GetActorLocation(), ProximityRadius))
	{
		bDetectActorProximity = false;
		ActorProximityAlert(ProximityDestination, ProximityAlertTag);
		return true;
	}
	*/
	return false;
}

void AFSTS_EL_Utilities::DetectProximityToActor(AActor* Destination, AActor* ActorToMove, float ProxyRadius, FName AlertTag)
{
	/*
	bDetectActorProximity = true;
	if (ActorToMove == nullptr)
	{
		ActorToMove = Player;
	}
	ProximityDestination = Destination;
	ProximityMoveActor = ActorToMove;
	ProximityRadius = ProxyRadius;
	ProximityAlertTag = AlertTag;
	*/
}

void AFSTS_EL_Utilities::CreateMarkers()
{
	/*
	if (bCreateLocationMarker && (LocationMarker == nullptr))
	{
		LocationMarker = Spawn(AFSTS_LocationMarker::StaticClass(), this, , , AFSTS_LocationMarker::StaticClass().Default.Rotation);
		LocationMarker.DeactivateMarker();
	}
	if (bCreateHelpMarker && (HelpMarker == nullptr))
	{
		HelpMarker = Spawn(AFSTS_HelpMarker::StaticClass(), this);
		HelpMarker.DeactivateMarker();
	}
	if (bCreateDirectionMarker && (DirectionMarker == nullptr))
	{
		DirectionMarker = Spawn(AFSTS_DirectionMarker::StaticClass(), this);
		DirectionMarker.DeactivateMarker();
	}
	*/
}

void AFSTS_EL_Utilities::SetLocationMarker(AFSTS_LocationMarker* MarkerToSet, FVector NewLocation, FVector AdditionalOffset, bool bActivateNow)
{
	if (MarkerToSet == nullptr)
	{
		//Log("SetLocationMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//LocationMarker.SetMarkingLocation(NewLocation, AdditionalOffset);
	if (bActivateNow)
	{
		ActivateLocationMarker(MarkerToSet);
	}
}

void AFSTS_EL_Utilities::ActivateLocationMarker(AFSTS_LocationMarker* MarkerToSet)
{
	if (MarkerToSet == nullptr)
	{
		//Log("ActivateLocationMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//MarkerToSet.ActivateMarker();
}

void AFSTS_EL_Utilities::DeactivateLocationMarker(AFSTS_LocationMarker* MarkerToSet)
{
	if (MarkerToSet == nullptr)
	{
		//Log("DeactivateLocationMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//MarkerToSet.DeactivateMarker();
}

void AFSTS_EL_Utilities::SetHelpMarker(AFSTS_HelpMarker* MarkerToSet, FVector NewLocation, FVector AdditionalOffset, bool bActivateNow, bool bUseAltStaticMesh)
{
	/*
	if (MarkerToSet == nullptr)
	{
		Log("SetHelpMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	MarkerToSet.SetMarkingLocation(NewLocation, AdditionalOffset);
	MarkerToSet.SetDisplayMesh((!bUseAltStaticMesh));
	if (bActivateNow)
	{
		ActivateHelpMarker(MarkerToSet);
	}
	*/
}

void AFSTS_EL_Utilities::SetHelpMarkerRotation(AFSTS_HelpMarker* MarkerToSet, FRotator NewRotation)
{
	if (MarkerToSet == nullptr)
	{
		//Log("SetHelpMarkerRotation() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//MarkerToSet->SetRotation(NewRotation);
}

void AFSTS_EL_Utilities::ActivateHelpMarker(AFSTS_HelpMarker* MarkerToSet)
{
	if (MarkerToSet == nullptr)
	{
		//Log("ActivateHelpMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//MarkerToSet->ActivateMarker();
}

void AFSTS_EL_Utilities::DeactivateHelpMarker(AFSTS_HelpMarker* MarkerToSet)
{
	if (MarkerToSet == nullptr)
	{
		//Log("DeactivateHelpMarker() - MarkerToSet is None.", "FSTS_EL_Utilities");
		return;
	}
	//MarkerToSet->DeactivateMarker();
}

void AFSTS_EL_Utilities::ForcePlayerCrouch(bool bCrouch)
{
	/*
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	bOldLockMovement = Controller.GetLockMovement();
	bOldLockRotation = Controller.GetLockRotation();
	PlayerLock(false, false);
	if (bCrouch)
	{
		if (!Player.bIsCrouched)
		{
			Controller.Crouching();
		}
	}
	else
	{
		if ((!Player.bIsCrouched) && (!Player.bIsProne))
		{
		}
		if (Player.bIsCrouched)
		{
			Controller.Crouching();
		}
		else
		{
			if (Player.bIsProne)
			{
				Controller.Crawling();
			}
		}
	}
	PlayerLock(bOldLockMovement, bOldLockRotation);
	*/
}

void AFSTS_EL_Utilities::ForcePlayerProne(bool bProne)
{
	/*
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	bOldLockMovement = Controller.GetLockMovement();
	bOldLockRotation = Controller.GetLockRotation();
	PlayerLock(false, false);
	if (bProne)
	{
		if (!Player.bIsProne)
		{
			Controller.Crawling();
		}
	}
	else
	{
		if ((!Player.bIsCrouched) && (!Player.bIsProne))
		{
		}
		if (Player.bIsCrouched)
		{
			Controller.Crouching();
		}
		else
		{
			if (Player.bIsProne)
			{
				Controller.Crawling();
			}
		}
	}
	PlayerLock(bOldLockMovement, bOldLockRotation);
	*/
}

float AFSTS_EL_Utilities::GetPlayerProximityTo(AActor* DistanceActor)
{
	/*
	if (DistanceActor == nullptr)
	{
		return 0;
	}
	return VSize((Player.Location - DistanceActor.Location));
	*/
	return 0;     //FAKE   /EliZ
}

void AFSTS_EL_Utilities::FacePlayerTo(AActor* ActorToFace, FName TargetBone, FName PlayerBone)
{
	FVector TargetLoc = FVector(0, 0, 0);
	FVector PlayerLoc = FVector(0, 0, 0);
	/*
	if (ActorToFace == nullptr)
	{
		return;
	}
	if (((PlayerBone != "None") && (PlayerBone != "None")) && Player.HasBone(PlayerBone))
	{
		PlayerLoc = Player.GetBoneCoords(PlayerBone).Origin;
	}
	else
	{
		PlayerLoc = Player.Location;
	}
	if (((TargetBone != "None") && (TargetBone != "None")) && ActorToFace.HasBone(TargetBone))
	{
		TargetLoc = ActorToFace.GetBoneCoords(TargetBone).Origin;
		TargetLoc = (TargetLoc - PlayerLoc);
	}
	else
	{
		TargetLoc = (ActorToFace.Location - PlayerLoc);
	}
	Controller.SetRotation(rotator(TargetLoc));
	*/
}

void AFSTS_EL_Utilities::LinkDrillSergeants()
{
	AActor* SearchActor = nullptr;
	int32 i = 0;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		for (i = 0; i < LevelScriptsList.Num(); i++)
		{
			if ((Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).DrillSergeant == nullptr) && (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).DrillSergeantTag == SearchActor.Tag))
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).DrillSergeant = FSTS_NPC_DrillSergeant(SearchActor);
				FSTS_EL_Utilities(LevelScriptsList[i]).SetHelpLSActor(SearchActor);
				FSTS_EL_Utilities(LevelScriptsList[i]).DrillSergeant.SetEventLab(LevelScriptsList[i]);
			}
			if ((Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).AltDrillSergeant == nullptr) && (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).AltDrillSergeantTag == SearchActor.Tag))
			{
				FSTS_EL_Utilities(LevelScriptsList[i]).AltDrillSergeant = FSTS_NPC_DrillSergeant(SearchActor);
				FSTS_EL_Utilities(LevelScriptsList[i]).AltDrillSergeant.SetEventLab(LevelScriptsList[i]);
			}
		}
	}
	*/
}

void AFSTS_EL_Utilities::DrillSergeantUsed(AFSTS_NPC_DrillSergeant* Sarge)
{
	AFSTS_EL_Utilities* TempActiveScript = nullptr;
	AFSTS_EL_Utilities* ScriptToActivate = nullptr;
	int32 i = 0;
	AActor* PlayerMovePoint=nullptr;
	/*
	if (!bMasterScript)
	{
		Log("WARNING! DrillSergeantUsed called on non-MasterScript, script was " + FString::FromInt(this) + ".", "FSTS_EL_Utilities");
		return;
	}
	TempActiveScript = Cast<AFSTS_EL_Utilities>(GetActiveScript());
	for (i = 0; i < LevelScriptsList.Num(); i++)
	{
		if ((Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).DrillSergeant == Sarge) || (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).AltDrillSergeant == Sarge))
		{
			ScriptToActivate = Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]);
			if (ScriptToActivate.bAcceptDrillSergeantUse)
			{
				if ((((ScriptToActivate != TempActiveScript) && ScriptToActivate.bDormant) && (!ScriptToActivate.bStationComplete)) && ScriptToActivate.bStartFromDrillSergeantUse)
				{
					ScriptToActivate.NotifyDrillSergeantUsed();
					SetActiveScript(ScriptToActivate);
				}
				if (ScriptToActivate.bFadeMoveFromDrillSergeantUse)
				{
					PlayerMovePoint = GetActorByTag(ScriptToActivate.StationBeginPointTag);
					FadeMoveStart(PlayerMovePoint, ScriptToActivate);
				}
			}
		}
	}
	*/
}

void AFSTS_EL_Utilities::SetDrillSergeantParams(bool bAcceptDSUse, bool bStartFromDSUse, bool bFadeMoveOnDSUse)
{
	/*
	DrillSergeant.bUseActionIcon = bAcceptDSUse;
	bAcceptDrillSergeantUse = bAcceptDSUse;
	bStartFromDrillSergeantUse = bStartFromDSUse;
	bFadeMoveFromDrillSergeantUse = bFadeMoveOnDSUse;
	*/
}

void AFSTS_EL_Utilities::FadeMoveStart(AActor* PlayerMovePoint, AFSTS_EL_Utilities* CallBackScript)
{
	/*
	if (!bMasterScript)
	{
		FSTS_EL_Utilities(MasterScript).FadeMoveStart(PlayerMovePoint, CallBackScript);
		return;
	}
	if (bFadeMoveActive)
	{
		Log("Trying to do a Fade-Move while one is in progress, breaking out...", "FSTS_EL_Utilities");
		return;
	}
	bFadeMoveActive = true;
	FadeMoveInfo.PlayerMovePoint = PlayerMovePoint;
	FadeMoveInfo.CallBackScript = CallBackScript;
	PlayerLock(true, true);
	FadeMoveInfo.CallBackScript.NotifyFadeMoveStart(FadeMoveInfo.PlayerMovePoint.Tag);
	SetCustomTimer(1, false, "FadeMoveMiddle");
	FadeOutBlack(1);
	*/
}

void AFSTS_EL_Utilities::FadeMoveMiddle()
{
	/*
	if (!bMasterScript)
	{
		Log("WARNING! Trying to do FadeMoveMiddle in non-MasterScript, script was " + FString::FromInt(this) + ".", "FSTS_EL_Utilities");
		return;
	}
	if (FadeMoveInfo.PlayerMovePoint != nullptr)
	{
		Controller.SetRotation(FadeMoveInfo.PlayerMovePoint.Rotation);
		Player.SetLocation(FadeMoveInfo.PlayerMovePoint.Location);
	}
	else
	{
		Log("WARNING! Trying to move player to a non-existant point.", "FSTS_EL_Utilities");
	}
	FadeMoveInfo.CallBackScript.NotifyFadeMoveMiddle(FadeMoveInfo.PlayerMovePoint.Tag);
	SetCustomTimer(1, false, "FadeMoveEnd");
	FadeInBlack(1);
	*/
}

void AFSTS_EL_Utilities::FadeMoveEnd()
{
	/*
	if (!bMasterScript)
	{
		Log("WARNING! Trying to do FadeMoveEnd in non-MasterScript.", "FSTS_EL_Utilities");
		return;
	}
	PlayerLock(false, false);
	FadeMoveInfo.CallBackScript.NotifyFadeMoveEnd(FadeMoveInfo.PlayerMovePoint.Tag);
	bFadeMoveActive = false;
	*/
}

void AFSTS_EL_Utilities::NotifyDrillSergeantUsed()
{
}

void AFSTS_EL_Utilities::NotifyFadeMoveStart(FName PlayerMoveName)
{
}

void AFSTS_EL_Utilities::NotifyFadeMoveMiddle(FName PlayerMoveName)
{
}

void AFSTS_EL_Utilities::NotifyFadeMoveEnd(FName PlayerMoveName)
{
}

bool AFSTS_EL_Utilities::Pawn_Damaged(APawn* DamagedPawn, AController* InstigatorController)
{
	/*
	Cast<AHumanController>(Player.Controller).DisplayMissionFailure("", "You performed an illegal action.", "Level restarted.", 128, 128, 6, "None");
	FadeOut(0.5, true);
	Reset();
	*/
	return true;
}

bool AFSTS_EL_Utilities::Pawn_Damaged_Miles(APawn* DamagedPawn, AController* InstigatorController)
{
	/*
	Cast<AHumanController>(Player.Controller).DisplayMissionFailure("", "You performed an illegal action.", "Level restarted.", 128, 128, 6, "None");
	FadeOut(0.5, true);
	Reset();
	*/
	return true;
}

void AFSTS_EL_Utilities::CheatMissionComplete()
{
	int32 i = 0;
	if (!bMasterScript)
	{
		return;
	}
	/*
	for (i = 1; i < LevelScriptsList.Num(); i++)
	{
		if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]) != nullptr)
		{
			FSTS_EL_Utilities(LevelScriptsList[i]).bStationComplete = true;
		}
	}
	MissionComplete();
	*/
}

int32 AFSTS_EL_Utilities::GetNumStationsPassed()
{
	int32 i = 0;
	int32 numpassed = 0;
	numpassed = 0;
	/*
	for (i = 1; i < LevelScriptsList.Num(); i++)
	{
		if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).bStationComplete)
		{
			if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).StationObjective.GetPercentComplete() >= 1)
			{
				numpassed++;
			}
		}
	}
	*/
	return numpassed;
}

bool AFSTS_EL_Utilities::AllStationsComplete()
{
	int32 i = 0;
	int32 numpassed = 0;
	numpassed = 0;
	/*
	for (i = 1; i < LevelScriptsList.Num(); i++)
	{
		if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).bStationComplete)
		{
			if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).StationObjective.GetPercentComplete() >= 1)
			{
				numpassed++;
			}
			else
			{
				Log("Station" @ FString::FromInt(Cast<AFSTS_EL_Utilities>(LevelScriptsList[i])) @ "objective was set to failure", "FSTS_EL_Utilities");
			}
		}
		else
		{
			else
			{
			Log("Station" @ FString::FromInt(Cast<AFSTS_EL_Utilities>(LevelScriptsList[i])) @ "was not set to station complete", "FSTS_EL_Utilities");
			}
		}
	}
	NumStationsPassed = numpassed;
	if (numpassed >= NumStationsRequired)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;     //FAKE   /EliZ
}

FString AFSTS_EL_Utilities::GenerateDebugMissionSummaryString()
{
	FString MissionSummary = "";
	FString StationCompleteStatus = "";
	int32 i = 0;
	MissionSummary = "";
	StationCompleteStatus = "";
	/*
	for (i = 1; i < LevelScriptsList.Num(); i++)
	{
		if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).StationObjective != nullptr)
		{
			if (Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).StationObjective.GetPercentComplete() >= 1)
			{
				StationCompleteStatus = "Passed";
			}
			else
			{
				StationCompleteStatus = "Failed";
			}
			MissionSummary += Cast<AFSTS_EL_Utilities>(LevelScriptsList[i]).StationName + ":" + StationCompleteStatus + "   ";
		}
	}
	*/
	return MissionSummary;
}

void AFSTS_EL_Utilities::MissionComplete()
{
	FString LevelSpecificLine1 = "";
	FString LevelSpecificLine2 = "";
	/*
	if (bMasterScript)
	{
		if (Cast<AFSTS_PlayerController>(Controller).IsUsingCheats())
		{
			DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Cheats detected: Mission Failed!", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageEx");
			return;
		}
		if (AllStationsComplete())
		{
			bPassedTraining = true;
			HandlePassResults();
		}
		else
		{
			bPassedTraining = false;
			if (GenerateLevelSpecificFailureStrings(LevelSpecificLine1, LevelSpecificLine2))
			{
				DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", LevelSpecificLine1, LevelSpecificLine2, 0, 0, 0, "None");
			}
			else
			{
				DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Mission Failed.", "You passed" @ FString::FromInt(GetNumStationsPassed()) @ "out of a required" @ FString::FromInt(NumStationsRequired) @ "stations.", 0, 0, 0, "None");
			}
		}
	}
	else
	{
		MasterScript.MissionComplete();
	}
	*/
}

bool AFSTS_EL_Utilities::HandlePassResults()
{
	FString LevelSpecificLine1 = "";
	FString LevelSpecificLine2 = "";
	/*
	if ((!bMasterScript) || (!bPassedTraining))
	{
		return false;
	}
	DebugLog(DEBUG_EventLab, "uploadStats:");
	Controller.SetAuthMissionPassFlag(true);
	Controller.ResetAuthExtraMissionData();
	GenerateAuthNumStationsPassed(NumStationsPassed);
	if (GenerateLevelSpecificSuccessStrings(LevelSpecificLine1, LevelSpecificLine2))
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", LevelSpecificLine1, LevelSpecificLine2, 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageEx");
	}
	else
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_sf", "Mission Complete!", "You passed" @ FString::FromInt(GetNumStationsPassed()) @ "out of a required" @ FString::FromInt(NumStationsRequired) @ "stations.", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageEx");
	}
	*/
	return true;
}

bool AFSTS_EL_Utilities::GenerateLevelSpecificSuccessStrings(FString& Line1, FString& Line2)
{
	return false;     //FAKE   /EliZ
}

bool AFSTS_EL_Utilities::GenerateLevelSpecificFailureStrings(FString& Line1, FString& Line2)
{
	return false;     //FAKE   /EliZ
}

void AFSTS_EL_Utilities::GenerateAuthNumStationsPassed(int32 StationsPassed)
{
	SetAuthNumStationsPassed(StationsPassed);
}

void AFSTS_EL_Utilities::SetAuthNumStationsPassed(int32 NewVal)
{
	AuthNumStationsPassed = NewVal;
}

FString AFSTS_EL_Utilities::GetTrainingMapName()
{
	return "FAKE";     //FAKE   /EliZ
}

void AFSTS_EL_Utilities::InitBlockingVolumesArray()
{
	ATriggeredPlayerBlockingVolume* SearchActor = nullptr;
	int32 i = 0;
	if (bMasterScript)
	{
		/*
		ForEach AllActors(ATriggeredPlayerBlockingVolume::StaticClass(), SearchActor)
		{
			if (SearchActor != nullptr)
			{
				i = BlockingVolumes.Num();
				BlockingVolumes.insert(i, 1);
				SearchActor.EventLab = this;
				BlockingVolumes[i] = SearchActor;
			}
		}
		*/
	}
}

ATriggeredPlayerBlockingVolume* AFSTS_EL_Utilities::GetPlayerBlockingVolume(FName SearchTag)
{
	int32 i = 0;
	if (bMasterScript)
	{
		for (i = 0; i < BlockingVolumes.Num(); i++)
		{
			/*
			if ((BlockingVolumes[i] != nullptr) && (BlockingVolumes[i].Tag == SearchTag))
			{
				return BlockingVolumes[i];
			}
			*/
		}
	}
	else
	{
		return Cast<AFSTS_EL_Utilities>(MasterScript)->GetPlayerBlockingVolume(SearchTag);
	}
	return nullptr;
}

void AFSTS_EL_Utilities::ActivatePlayerBlocking(ATriggeredPlayerBlockingVolume* VolumeToActivate)
{
	if (VolumeToActivate != nullptr)
	{
		//VolumeToActivate.ActivatePlayerBlocking();
	}
	else
	{
		//Log("ActivatePlayerBlocking() - VolumeToActivate is none", "FSTS_EL_Utilities");
	}
}

void AFSTS_EL_Utilities::DeactivatePlayerBlocking(ATriggeredPlayerBlockingVolume* VolumeToDeactivate)
{
	if (VolumeToDeactivate != nullptr)
	{
		//VolumeToDeactivate.DeactivatePlayerBlocking();
	}
	else
	{
		//Log("DeactivatePlayerBlocking() - VolumeToDeactivate is none", "FSTS_EL_Utilities");
	}
}

void AFSTS_EL_Utilities::ForceDrawPlayerCrosshair(bool bForceActive)
{
	if (Player != nullptr)
	{
		//Player->bForceDrawCrosshair = bForceActive;
	}
}

void AFSTS_EL_Utilities::CrouchEvent()
{
	//Log("CrouchEvent", "FSTS_EL_Utilities");
}

void AFSTS_EL_Utilities::CrawlEvent()
{
	//Log("CrawlEvent", "FSTS_EL_Utilities");
}

void AFSTS_EL_Utilities::LMouseClickEvent()
{
	//Log("MouseClickEvent", "FSTS_EL_Utilities");
}

void AFSTS_EL_Utilities::ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
{
}

void AFSTS_EL_Utilities::CheatSkipToStation(int32 StationNum)
{
}

void AFSTS_EL_Utilities::ReloadEvent(AWeapon* ReloadedWeapon)
{
}

void AFSTS_EL_Utilities::StationComplete()
{
}

void AFSTS_EL_Utilities::LeavingStation()
{
}
