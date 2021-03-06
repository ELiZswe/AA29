// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/EL_MultiScript.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_Ambush/FA_EL_Ambush.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_BleedingControl/FA_EL_BleedingControl.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_CasualtyEvaluation/FA_EL_CasualtyEvaluation.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_HeatExhaustion/FA_EL_HeatExhaustion.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_LowCrawlUnderFire/FA_EL_LowCrawlUnderFire.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_SplintFracture/FA_EL_SplintFracture.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Acosta.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Johnson.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Kelly.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Koch.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Mateo.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Moore.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/TriggerVolume/StationTriggerVolume/StationTriggerVolume.h"

AFA_EL_MasterScript::AFA_EL_MasterScript()
{
	TeleportStationID = -1;
	bCreateLocationMarker = false;
	HelpMarkerSmallOffset = FVector(0, 0, 15);
	HelpMarkerLargeOffset = FVector(0, 0, 70);
	NumStationsRequired = 4;
	TrainingName = "First Aid Training";
	bMasterScript = true;
	LevelScriptsClasses = {
		//AFA_EL_CasualtyEvaluation::StaticClass(),
		//AFA_EL_LowCrawlUnderFire::StaticClass(),
		//AFA_EL_BleedingControl::StaticClass(),
		//AFA_EL_SplintFracture::StaticClass(),
		//AFA_EL_Ambush::StaticClass(),
		//AFA_EL_HeatExhaustion::StaticClass()
	};
	bUseLevelBeginFadeIn = true;
	LevelBeginFadeInTime = 3.5;
}

/*
simulated State LevelBegin extends MasterActiveExecute
{
	simulated Function BeginState()
	{
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station6_EndBlock"));
		PlayerLock(true,true);
		SetPlayerWeapon(false,true);
		SetTimerEvent("InitialPlayerOrientation",0.5,0,false);
		PlayTip("Harvey Range - Basic First Aid Field Training","",7);
	}
	simulated Function FFDrillSergeantScold()
	{
		DS_Koch->StopLIPSincAnim();
		StopTimerByType(ETimerType::TT_LSAnim);
		StopTimerByType(ETimerType::TT_Timer);
		PlayLSAnim("fa_StagingArea_5",DS_Koch);
		PlayTip("Watch your aim soldier!","",4);
		ForceLevelReset();
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_StagingArea_1":
			PlayLSAnim("fa_StagingArea_2",DS_Koch,,,,2);
			return true;
			case "fa_StagingArea_2":
			SetHelpMarker(DirectionMarker,GetActorByTag("ToStation1")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
			SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation1").Rotation);
			DetectProximityToActor(GetActorByTag("ToStation1"),Player,400);
			PlayerLock(false,false);
			return true;
			case "fa_StagingArea_3":
			return true;
			case "fa_StagingArea_4":
			break;
			default:
		}
		return false;
	}
	simulated Function bool Timer_Timer(FName EventName)
	{
		switch(EventName)
		{
			case "LevelBeginFadeInComplete":
			PlayLSAnim("fa_StagingArea_1",DS_Koch);
			PlayerLock(true,false);
			break;
			case "InitialPlayerOrientation":
			FacePlayerTo(DS_Koch,"Neck","CameraBone");
			break;
			default:
		}
		return true;
	}
	simulated Function Timer()
	{
	}
}
*/

/*
simulated State ForcePlayerMove extends MasterActiveExecute
{
	simulated Function BeginState()
	{
		PlayerLock(true,true);
		FadeOutBlack(3);
		StartTimer("FadeOutBlack",3);
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		FString tempString = "";
		FName NewStationName = "";
		switch(TimerName)
		{
			case "FadeOutBlack":
			tempString="Station" + FString::FromInt(TeleportStationID) + "_Start";
			NewStationName=string(tempString);
			TeleportStationID=Default.TeleportStationID;
			Log("NewStationName test is " + FString::FromInt(NewStationName));
			Player.SetLocation(GetActorByTag(NewStationName).Location);
			Controller.SetRotation(GetActorByTag(NewStationName).Rotation);
			FadeInBlack(3);
			StartTimer("FadeInBlack",3);
			PlayerLock(false,false);
			break;
			case "FadeInBlack":
			ChangeState("MasterActiveExecute");
			break;
			default:
		}
		return true;
	}
	simulated Function EndState()
	{
	}
}
*/

/*
simulated State FriendlyFireFailureState extends MasterActiveExecute
{
	simulated Function BeginState()
	{
		PlayerLock(true,false);
		FadeOutBlack(3);
		StartTimer("FadeOutBlack",5);
	}
	simulated Function ForceLevelReset()
	{
		RunConsoleCommand("Reconnect");
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		ForceLevelReset();
		return true;
	}
}
*/

void AFA_EL_MasterScript::EventLabTick(float DeltaTime)
{
	Super::EventLabTick(DeltaTime);
	if (bDormant)
	{
		return;
	}
}

void AFA_EL_MasterScript::PostInit()
{
	Super::PostInit();
	if (bMasterScript)
	{
		DoReferenceLinking();
		LinkDrillSergeants();
	}
}

void AFA_EL_MasterScript::PostPostInit()
{
	Super::PostPostInit();
	if (bMasterScript)
	{
		//Player->SetEventLab(this);
		ChangeState("LevelBegin","");
	}
	else
	{
		ChangeState("Dormant","");
	}
}

FString AFA_EL_MasterScript::GetTrainingMapName()
{
	return "First_Aid.aao";
}

void AFA_EL_MasterScript::SetMasterScript()
{
	Super::SetMasterScript();
	if (bMasterScript)
	{
		FAMasterScript = this;
	}
	else
	{
		if (Cast<AFA_EL_MasterScript>(MasterScript) != nullptr)
		{
			FAMasterScript = Cast<AFA_EL_MasterScript>(MasterScript);
		}
		else
		{
			//Log("ERROR - " + FString::FromInt(this) + " - FAMasterScript could not be set!");
		}
	}
}

void AFA_EL_MasterScript::CreateCustomLevelScriptsLinks()
{
	Station1 = Cast<AFA_EL_CasualtyEvaluation>(LevelScriptsList[1]);
	Station2 = Cast<AFA_EL_LowCrawlUnderFire>(LevelScriptsList[2]);
	Station3 = Cast<AFA_EL_BleedingControl>(LevelScriptsList[3]);
	Station4 = Cast<AFA_EL_SplintFracture>(LevelScriptsList[4]);
	Station5 = Cast<AFA_EL_Ambush>(LevelScriptsList[5]);
	Station6 = Cast<AFA_EL_HeatExhaustion>(LevelScriptsList[6]);
}

void AFA_EL_MasterScript::Reset()
{
	if (bMasterScript)
	{
		bFriendlyFireFailure = false;
		TeleportStationID = GetDefault<AFA_EL_MasterScript>()->TeleportStationID;
		Station1->bDormant = true;
		Station2->bDormant = true;
		Station3->bDormant = true;
		Station4->bDormant = true;
		Station5->bDormant = true;
		Station6->bDormant = true;
		Station1->bStationComplete = false;
		Station2->bStationComplete = false;
		Station3->bStationComplete = false;
		Station4->bStationComplete = false;
		Station5->bStationComplete = false;
		Station6->bStationComplete = false;
		/*
		if (!Station1->IsInState("Dormant"))
		{
			Station1->GotoState("Dormant");
		}
		if (!Station2->IsInState("Dormant"))
		{
			Station2->GotoState("Dormant");
		}
		if (!Station3->IsInState("Dormant"))
		{
			Station3->GotoState("Dormant");
		}
		if (!Station4->IsInState("Dormant"))
		{
			Station4->GotoState("Dormant");
		}
		if (!Station5->IsInState("Dormant"))
		{
			Station5->GotoState("Dormant");
		}
		if (!Station6->IsInState("Dormant"))
		{
			Station6->GotoState("Dormant");
		}
		*/
	}
	Super::Reset();
}

bool AFA_EL_MasterScript::AllowScriptStart(AEL_MultiScript* StationToStart)
{
	AFA_EL_MasterScript* nStationToStart = nullptr;
	nStationToStart = Cast<AFA_EL_MasterScript>(StationToStart);
	if ((!bMasterScript) || (nStationToStart == nullptr))
	{
		return false;
	}

	if (nStationToStart == FAMasterScript)
	{
		return true;
	}
	if (nStationToStart == Station1)
	{
		return (!Station1->bStationComplete);
	}
	if (nStationToStart == Station2)
	{
		return ((!Station2->bStationComplete) && Station1->bStationComplete);
	}
	if (nStationToStart == Station3)
	{
		return (((!Station3->bStationComplete) && Station2->bStationComplete) && Station2->bStationComplete);
	}
	if (nStationToStart == Station4)
	{
		return ((((!Station4->bStationComplete) && Station1->bStationComplete) && Station2->bStationComplete) && Station3->bStationComplete);
	}
	if (nStationToStart == Station5)
	{
		return (((((!Station5->bStationComplete) && Station1->bStationComplete) && Station2->bStationComplete) && Station3->bStationComplete) && Station4->bStationComplete);
	}
	if (nStationToStart == Station6)
	{
		return ((((((!Station6->bStationComplete) && Station1->bStationComplete) && Station2->bStationComplete) && Station3->bStationComplete) && Station4->bStationComplete) && Station5->bStationComplete);
	}
	return false;
}

void AFA_EL_MasterScript::CheatSkipToStation(int32 StationNum)
{
	if (!bMasterScript)
	{
		return;
	}
	SetPlayerWeapon(true, false);
	if ((StationNum >= 1) && (StationNum < 7))
	{
		PlayerLock(false, false);
		switch (StationNum)
		{
		case 1:
			Station1->bStationComplete = false;
			Station1->Reset();
			break;
		case 2:
			Station1->bStationComplete = true;
			Station2->bStationComplete = false;
			Station2->Reset();
			break;
		case 3:
			Station1->bStationComplete = true;
			Station2->bStationComplete = true;
			Station3->bStationComplete = false;
			Station3->Reset();
			break;
		case 4:
			Station1->bStationComplete = true;
			Station2->bStationComplete = true;
			Station3->bStationComplete = true;
			Station4->bStationComplete = false;
			Station4->Reset();
			break;
		case 5:
			Station1->bStationComplete = true;
			Station2->bStationComplete = true;
			Station3->bStationComplete = true;
			Station4->bStationComplete = true;
			Station5->bStationComplete = false;
			Station5->Reset();
			break;
		case 6:
			MoveDSKochToStation6();
			Station1->bStationComplete = true;
			Station2->bStationComplete = true;
			Station3->bStationComplete = true;
			Station4->bStationComplete = true;
			Station5->bStationComplete = true;
			Station6->bStationComplete = false;
			Station6->Reset();
			break;
		default:
			break;
		}
	}
}

AFA_EL_MasterScript* AFA_EL_MasterScript::GetFAActiveScript()
{
	AEL_MultiScript* ActiveScript = nullptr;
	AFA_EL_MasterScript* FA_ActiveScript = nullptr;
	ActiveScript = GetActiveScript();
	FA_ActiveScript = Cast<AFA_EL_MasterScript>(ActiveScript);
	return FA_ActiveScript;
}

void AFA_EL_MasterScript::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
}

bool AFA_EL_MasterScript::Volume_Enter(AVolume* NotifyActor, AActor* aInstigator)
{
	AStationTriggerVolume* STV = Cast<AStationTriggerVolume>(NotifyActor);

	if (!bMasterScript)
	{
		return false;
	}
	if (Cast<AStationTriggerVolume>(NotifyActor) != nullptr)
	{
		if (STV->ActorHasTag("First_Weapon_BringUp"))
		{
			SetPlayerWeapon(true, false);
			//break;
		}
		if (STV->ActorHasTag("Station1_Entry"))
		{
			PlayTip("Press <Action> on a Drill Sergeant to begin each station's instruction.", "", 8);
			//break;
		}
		if (STV->ActorHasTag("Station1_Exit"))
		{
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript,nullptr,"","",false);
			}
			else
			{
				Station1->DrillSergeantMoveOn(DS_Moore);
			}
		}
		if (STV->ActorHasTag("Station1_Teleport"))
		{
			if ((GetActiveScript() == MasterScript) && Station1->bStationComplete)
			{
				PlayLSAnim("fa_station1_14", Station1->DrillSergeant,0,0,0,0);
			}
		}
		if (STV->ActorHasTag("Station2_Entry"))
		{
			SetActiveScript(Station2,nullptr,"","",false);
			if (!Station2->bStationComplete)
			{
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
					ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
			}
		}
		if (STV->ActorHasTag("Station2_Exit"))
		{
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript,nullptr,"","",false);
			}
			else
			{
				Station2->DrillSergeantMoveOn(DS_Acosta);
			}
		}
		if (STV->ActorHasTag("Station2_Teleport"))
		{
			if ((GetActiveScript() == MasterScript) && Station2->bStationComplete)
			{
				PlayLSAnim("fa_station2_11", Station2->DrillSergeant,0,0,0,0);
			}
		}
		if (STV->ActorHasTag("Station3_Entry"))
		{
			Station3->SetDrillSergeantParams(true, true, true);
		}
		if (STV->ActorHasTag("Station3_Exit"))
		{
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript,nullptr,"","",false);
			}
			else
			{
				Station3->DrillSergeantMoveOn(DS_Mateo);
			}
		}
		if (STV->ActorHasTag("Station3_Teleport"))
		{
			if ((GetActiveScript() == MasterScript) && Station3->bStationComplete)
			{
				PlayLSAnim("fa_station5_18", Station3->DrillSergeant,0,0,0,0);
			}
		}
		if (STV->ActorHasTag("Station4_Entry"))
		{
			Station4->SetDrillSergeantParams(true, true, true);
		}
		if (STV->ActorHasTag("Station4_Exit"))
		{
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript,nullptr,"","",false);
			}
			else
			{
				Station4->DrillSergeantMoveOn(DS_Johnson);
			}
		}
		if (STV->ActorHasTag("Station4_Teleport"))
		{
			if ((GetActiveScript() == MasterScript) && Station4->bStationComplete)
			{
				PlayLSAnim("fa_station3_12", Station4->DrillSergeant,0,0,0,0);
			}
		}
		if (STV->ActorHasTag("Station5_Entry"))
		{
			SetActiveScript(Station5,nullptr,"","",false);
			if (!Station5->bStationComplete)
			{
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_StartBlock"));
					ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
			}
		}
		if (STV->ActorHasTag("Station5_Exit"))
		{
			Station6->PrepareStation();
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript,nullptr,"","",false);
			}
			else
			{
				Station5->DrillSergeantMoveOn(DS_Kelly);
			}
		}
		if (STV->ActorHasTag("Station5_Teleport"))
		{
			if ((GetActiveScript() == MasterScript) && Station5->bStationComplete)
			{
				PlayLSAnim("fa_station4_8", Station5->DrillSergeant,0,0,0,0);
			}
		}
		//Log("Unable to process stationtag " + FString::FromInt(Cast<AStationTriggerVolume>(NotifyActor).StationTag));
		return false;
	}
	else
	{
		//Log("Unable to process Volume_Enter with NotifyActor" @ FString::FromInt(NotifyActor) @ "with tag" @ FString::FromInt(NotifyActor.Tag));
		return false;
	}
	//Log("Volume_Enter - NotifyActor is " + FString::FromInt(NotifyActor) + " with stationtag " + FString::FromInt(Cast<AStationTriggerVolume>(NotifyActor).StationTag));
	return true;
}

bool AFA_EL_MasterScript::Volume_Exit(AVolume* NotifyActor, AActor* aInstigator)
{
	/*
	if (Cast<AStationTriggerVolume>(NotifyActor) != nullptr)
	{
		switch (Cast<AStationTriggerVolume>(NotifyActor).StationTag)
		{
		case "Station1_Entry":
		case "Station1_Exit":
		case "Station1_Teleport":
		case "Station2_Entry":
		case "Station2_Exit":
		case "Station2_Teleport":
		case "Station3_Entry":
		case "Station3_Exit":
		case "Station3_Teleport":
		case "Station4_Entry":
		case "Station4_Exit":
		case "Station4_Teleport":
		case "Station5_Entry":
		case "Station5_Exit":
		case "Station5_Teleport":
		case "Station6_Entry":
			return true;
		default:
		}
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AFA_EL_MasterScript::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	AGrenadeHelper* GH = nullptr;
	/*
	if (bMasterScript)
	{
		GH = Level.GetGrenadeHelper();
		GH.EventLab = this;
		ForEach AllActors(Class'Actor', SearchActor)
		{
			if (SearchActor.Tag == "StationTriggerVolume")
			{
				SearchActor.EventLab = this;
			}
			if (SearchActor.Tag == "NPC_Ambient")
			{
				SearchActor.EventLab = this;
			}
			if (Cast<AFA_NPC_DS_Koch>(SearchActor) != nullptr)
			{
				DS_Koch = FA_NPC_DS_Koch(SearchActor);
				Log("DS_Koch linked");
			}
			if (Cast<AFA_NPC_DS_Moore>(SearchActor) != nullptr)
			{
				DS_Moore = Cast<AFA_NPC_DS_Moore>(SearchActor);
				DS_Moore.bUseActionIcon = true;
				Log("DS_Moore linked");
			}
			if (Cast<AFA_NPC_DS_Acosta>(SearchActor) != nullptr)
			{
				DS_Acosta = FA_NPC_DS_Acosta(SearchActor);
				Log("DS_Acosta linked");
			}
			if (Cast<AFA_NPC_DS_Mateo>(SearchActor) != nullptr)
			{
				DS_Mateo = FA_NPC_DS_Mateo(SearchActor);
				Log("DS_Mateo linked");
			}
			if (Cast<AFA_NPC_DS_Johnson>(SearchActor) != nullptr)
			{
				DS_Johnson = FA_NPC_DS_Johnson(SearchActor);
				Log("DS_Johnson linked");
			}
			if (Cast<AFA_NPC_DS_Kelly>(SearchActor) != nullptr)
			{
				DS_Kelly = FA_NPC_DS_Kelly(SearchActor);
				Log("DS_Kelly linked");
			}
		}
		Station1->AssignDrillSergeants(DS_Moore);
		Station2->AssignDrillSergeants(DS_Acosta);
		Station3->AssignDrillSergeants(DS_Kelly);
		Station4->AssignDrillSergeants(DS_Mateo);
		Station5->AssignDrillSergeants(DS_Johnson);
		Station6->AssignDrillSergeants(DS_Koch);
	}
	Super::DoReferenceLinking();
	*/
}

void AFA_EL_MasterScript::GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms)
{
	AFA_EL_MasterScript* ActiveScript = nullptr;
	if (bMasterScript)
	{
		ActiveScript = Cast<AFA_EL_MasterScript>(GetActiveScript());
		if ((ActiveScript == nullptr) || (ActiveScript == this))
		{
			//Log("Breaking from masterscript GrenadeExploded().  ActiveScript is " + FString::FromInt(ActiveScript));
			return;
		}
		else
		{
			if (ActiveScript != nullptr)
			{
				ActiveScript->GrenadeExploded(Grenade, Event, GetInstigator(), Parms);
			}
		}
	}
}

void AFA_EL_MasterScript::SetPlayerWeapon(bool bWeaponUp, bool bSetLockWeaponPosition)
{
	/*
	if (bMasterScript)
	{
		if (bWeaponUp)
		{
			if (Player.Weapon == nullptr)
			{
				bLockWeaponPosition = false;
				Controller.SwapHands();
			}
		}
		else
		{
			if (Player.Weapon != nullptr)
			{
				bLockWeaponPosition = false;
				Controller.SwapHands();
			}
		}
		bLockWeaponPosition = bSetLockWeaponPosition;
		return;
	}
	else
	{
		FAMasterScript.SetPlayerWeapon(bWeaponUp, bSetLockWeaponPosition);
	}
	*/
}

void AFA_EL_MasterScript::MoveDSKochToStation6()
{
	AActor* MoveToPoint = nullptr;
	/*
	MoveToPoint = GetActorByTag("DS_Koch_New_Location");
	DS_Koch->SetLocation(MoveToPoint->GetActorLocation());
	DS_Koch->SetRotation(MoveToPoint->GetActorRotationr)Rotation();
	DS_Koch->DesiredRotation = MoveToPoint->GetActorRotationo)rRotation();
	DS_Koch->Default.DesiredRotation = MoveToPoint->GetActorRotation();
	DS_Koch->bRotateToDesired = false;
	*/
}

void AFA_EL_MasterScript::MovePlayerToStation(int32 StationID)
{
	TeleportStationID = StationID;
	//ChangeState("ForcePlayerMove");
}

void AFA_EL_MasterScript::Destroyed()
{
	int32 i = 0;
	/*
	for (i = 0; i < BlockingVolumes.Num(); i++)
	{
		BlockingVolumes[i] = nullptr;
	}
	BlockingVolumes.RemoveAt(0, BlockingVolumes.Num());
	FAMasterScript = nullptr;
	Station1 = nullptr;
	Station2 = nullptr;
	Station3 = nullptr;
	Station4 = nullptr;
	Station5 = nullptr;
	Station6 = nullptr;
	DS_Koch = nullptr;
	DS_Moore = nullptr;
	DS_Acosta = nullptr;
	DS_Mateo = nullptr;
	DS_Johnson = nullptr;
	DS_Kelly = nullptr;
	Super::Destroyed();
	*/
}

bool AFA_EL_MasterScript::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	//FriendlyFire(NotifyActor);
	return true;
}

bool AFA_EL_MasterScript::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	//FriendlyFire(NotifyActor);
	return true;
}

void AFA_EL_MasterScript::FriendlyFire(APawn* HitActor)
{

	if (bFriendlyFireFailure)
	{
		return;
	}
	bFriendlyFireFailure = true;
	StopHelpTimer(0);
	PlayerNoGoAwarded();
	FFDrillSergeantScold();
}

bool AFA_EL_MasterScript::AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (GetActiveScript() == this)
	{
		return false;
	}
	return GetActiveScript().AGP_Weapon_Empty(NotifyActor, Instigator, Parms);
	*/
	return false;     //FAKE   /ELiZ
}

void AFA_EL_MasterScript::ForceLevelReset()
{
	/*
	if (!bMasterScript)
	{
		FAMasterScript.SetActiveScript(FAMasterScript, , "FriendlyFireFailureState", , true);
		return;
	}
	else
	{
		if (!IsInState("FriendlyFireFailureState"))
		{
			ChangeState("FriendlyFireFailureState");
		}
	}
	*/
}

void AFA_EL_MasterScript::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
}

void AFA_EL_MasterScript::MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
{
}

void AFA_EL_MasterScript::HandleMedPickup(AActor* HitActor)
{
}

bool AFA_EL_MasterScript::LockWeaponPosition()
{
	return bLockWeaponPosition;
}

void AFA_EL_MasterScript::FFDrillSergeantScold()
{
}

void AFA_EL_MasterScript::PlayerNoGoAwarded()
{
}
