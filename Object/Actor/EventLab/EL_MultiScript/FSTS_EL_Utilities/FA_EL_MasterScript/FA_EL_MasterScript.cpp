// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"

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
		//class'FSTS.FA_EL_CasualtyEvaluation'
		//class'FSTS.FA_EL_LowCrawlUnderFire'
		//class'FSTS.FA_EL_BleedingControl'
		//class'FSTS.FA_EL_SplintFracture'
		//class'FSTS.FA_EL_Ambush'
		//class'FSTS.FA_EL_HeatExhaustion'
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
		DS_Koch.StopLIPSincAnim();
		StopTimerByType(3);
		StopTimerByType(0);
		PlayLSAnim("fa_StagingArea_5",DS_Koch);
		PlayTip("Watch your aim soldier!","",4);
		ForceLevelReset();
	}
	simulated Function ActorProximityAlert(Actor ProximityActor, FName AlertTag)
	{
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(Self) $ " Timer_LSAnim called for " $ string(LSName));
		switch(LSName)
		{
			case "fa_StagingArea_1":
			PlayLSAnim("fa_StagingArea_2",DS_Koch,,,,2);
			return true;
			case "fa_StagingArea_2":
			SetHelpMarker(DirectionMarker,GetActorByTag("ToStation1").Location,HelpMarkerLargeOffset,true,true);
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
			tempString="Station" $ string(TeleportStationID) $ "_Start";
			NewStationName=string(tempString);
			TeleportStationID=Default.TeleportStationID;
			Log("NewStationName test is " $ string(NewStationName));
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
	/*
	Super::PostInit();
	if (bMasterScript)
	{
		DoReferenceLinking();
		LinkDrillSergeants();
	}
	*/
}

void AFA_EL_MasterScript::PostPostInit()
{
	/*
	Super::PostPostInit();
	if (bMasterScript)
	{
		Player.SetEventLab(Self);
		ChangeState("LevelBegin");
	}
	else
	{
		ChangeState("Dormant");
	}
	*/
}

FString AFA_EL_MasterScript::GetTrainingMapName()
{
	return "First_Aid.aao";
}

void AFA_EL_MasterScript::SetMasterScript()
{
	/*
	Super::SetMasterScript();
	if (bMasterScript)
	{
		FAMasterScript = Self;
	}
	else
	{
		if (FA_EL_MasterScript(MasterScript) != nullptr)
		{
			FAMasterScript = FA_EL_MasterScript(MasterScript);
		}
		else
		{
			Log("ERROR - " $ string(Self) $ " - FAMasterScript could not be set!");
		}
	}
	*/
}

void AFA_EL_MasterScript::CreateCustomLevelScriptsLinks()
{
	/*
	Station1 = FA_EL_CasualtyEvaluation(LevelScriptsList[1]);
	Station2 = FA_EL_LowCrawlUnderFire(LevelScriptsList[2]);
	Station3 = FA_EL_BleedingControl(LevelScriptsList[3]);
	Station4 = FA_EL_SplintFracture(LevelScriptsList[4]);
	Station5 = FA_EL_Ambush(LevelScriptsList[5]);
	Station6 = FA_EL_HeatExhaustion(LevelScriptsList[6]);
	*/
}

void AFA_EL_MasterScript::Reset()
{
	/*
	if (bMasterScript)
	{
		bFriendlyFireFailure = false;
		TeleportStationID = Default.TeleportStationID;
		Station1.bDormant = true;
		Station2.bDormant = true;
		Station3.bDormant = true;
		Station4.bDormant = true;
		Station5.bDormant = true;
		Station6.bDormant = true;
		Station1.bStationComplete = false;
		Station2.bStationComplete = false;
		Station3.bStationComplete = false;
		Station4.bStationComplete = false;
		Station5.bStationComplete = false;
		Station6.bStationComplete = false;
		if (!Station1.IsInState("Dormant"))
		{
			Station1.GotoState("Dormant");
		}
		if (!Station2.IsInState("Dormant"))
		{
			Station2.GotoState("Dormant");
		}
		if (!Station3.IsInState("Dormant"))
		{
			Station3.GotoState("Dormant");
		}
		if (!Station4.IsInState("Dormant"))
		{
			Station4.GotoState("Dormant");
		}
		if (!Station5.IsInState("Dormant"))
		{
			Station5.GotoState("Dormant");
		}
		if (!Station6.IsInState("Dormant"))
		{
			Station6.GotoState("Dormant");
		}
	}
	Super::Reset();
	*/
}

bool AFA_EL_MasterScript::AllowScriptStart(AEL_MultiScript* StationToStart)
{
	/*
	local FA_EL_MasterScript nStationToStart;
	nStationToStart = FA_EL_MasterScript(StationToStart);
	if ((!bMasterScript) || (nStationToStart == None))
	{
		return false;
	}
	switch (nStationToStart)
	{
	case FAMasterScript:
		return true;
		break;
	case Station1:
		return (!Station1.bStationComplete);
		break;
	case Station2:
		return ((!Station2.bStationComplete) && Station1.bStationComplete);
		break;
	case Station3:
		return (((!Station3.bStationComplete) && Station2.bStationComplete) && Station2.bStationComplete);
		break;
	case Station4:
		return ((((!Station4.bStationComplete) && Station1.bStationComplete) && Station2.bStationComplete) && Station3.bStationComplete);
		break;
	case Station5:
		return (((((!Station5.bStationComplete) && Station1.bStationComplete) && Station2.bStationComplete) && Station3.bStationComplete) && Station4.bStationComplete);
		break;
	case Station6:
		return ((((((!Station6.bStationComplete) && Station1.bStationComplete) && Station2.bStationComplete) && Station3.bStationComplete) && Station4.bStationComplete) && Station5.bStationComplete);
		break;
	default:
	}
	*/
	return false;
}

void AFA_EL_MasterScript::CheatSkipToStation(int32 StationNum)
{
	/*
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
			Station1.bStationComplete = false;
			Station1.Reset();
			break;
		case 2:
			Station1.bStationComplete = true;
			Station2.bStationComplete = false;
			Station2.Reset();
			break;
		case 3:
			Station1.bStationComplete = true;
			Station2.bStationComplete = true;
			Station3.bStationComplete = false;
			Station3.Reset();
			break;
		case 4:
			Station1.bStationComplete = true;
			Station2.bStationComplete = true;
			Station3.bStationComplete = true;
			Station4.bStationComplete = false;
			Station4.Reset();
			break;
		case 5:
			Station1.bStationComplete = true;
			Station2.bStationComplete = true;
			Station3.bStationComplete = true;
			Station4.bStationComplete = true;
			Station5.bStationComplete = false;
			Station5.Reset();
			break;
		case 6:
			MoveDSKochToStation6();
			Station1.bStationComplete = true;
			Station2.bStationComplete = true;
			Station3.bStationComplete = true;
			Station4.bStationComplete = true;
			Station5.bStationComplete = true;
			Station6.bStationComplete = false;
			Station6.Reset();
			break;
		default:
		}
	}
	*/
}

AFA_EL_MasterScript* AFA_EL_MasterScript::GetFAActiveScript()
{
	AEL_MultiScript* ActiveScript = nullptr;
	AFA_EL_MasterScript* FA_ActiveScript = nullptr;
	//ActiveScript = GetActiveScript();
	//FA_ActiveScript = FA_EL_MasterScript(ActiveScript);
	return FA_ActiveScript;
}

void AFA_EL_MasterScript::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
}

bool AFA_EL_MasterScript::Volume_Enter(AVolume* NotifyActor, AActor* aInstigator)
{
	/*
	if (!bMasterScript)
	{
		return false;
	}
	if (StationTriggerVolume(NotifyActor) != nullptr)
	{
		switch (StationTriggerVolume(NotifyActor).StationTag)
		{
		case "First_Weapon_BringUp":
			SetPlayerWeapon(true, false);
			break;
		case "Station1_Entry":
			PlayTip("Press <Action> on a Drill Sergeant to begin each station's instruction.", "", 8);
			break;
		case "Station1_Exit":
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript);
			}
			else
			{
				Station1.DrillSergeantMoveOn(DS_Moore);
			}
		case "Station1_Teleport":
			if ((GetActiveScript() == MasterScript) && Station1.bStationComplete)
			{
				PlayLSAnim("fa_station1_14", Station1.DrillSergeant);
			}
		case "Station2_Entry":
			SetActiveScript(Station2);
			if (!Station2.bStationComplete)
			{
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_StartBlock"));
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station2_EndBlock"));
			}
		case "Station2_Exit":
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript);
			}
			else
			{
				Station2.DrillSergeantMoveOn(DS_Acosta);
			}
		case "Station2_Teleport":
			if ((GetActiveScript() == MasterScript) && Station2.bStationComplete)
			{
				PlayLSAnim("fa_station2_11", Station2.DrillSergeant);
			}
		case "Station3_Entry":
			Station3.SetDrillSergeantParams(true, true, true);
		case "Station3_Exit":
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript);
			}
			else
			{
				Station3.DrillSergeantMoveOn(DS_Mateo);
			}
		case "Station3_Teleport":
			if ((GetActiveScript() == MasterScript) && Station3.bStationComplete)
			{
				PlayLSAnim("fa_station5_18", Station3.DrillSergeant);
			}
		case "Station4_Entry":
			Station4.SetDrillSergeantParams(true, true, true);
		case "Station4_Exit":
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript);
			}
			else
			{
				Station4.DrillSergeantMoveOn(DS_Johnson);
			}
		case "Station4_Teleport":
			if ((GetActiveScript() == MasterScript) && Station4.bStationComplete)
			{
				PlayLSAnim("fa_station3_12", Station4.DrillSergeant);
			}
		case "Station5_Entry":
			SetActiveScript(Station5);
			if (!Station5.bStationComplete)
			{
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_StartBlock"));
				ActivatePlayerBlocking(GetPlayerBlockingVolume("Station5_EndBlock"));
			}
		case "Station5_Exit":
			Station6.PrepareStation();
			if (GetActiveScript() != MasterScript)
			{
				SetActiveScript(MasterScript);
			}
			else
			{
				Station5.DrillSergeantMoveOn(DS_Kelly);
			}
		case "Station5_Teleport":
			if ((GetActiveScript() == MasterScript) && Station5.bStationComplete)
			{
				PlayLSAnim("fa_station4_8", Station5.DrillSergeant);
			}
		default:
			Log("Unable to process stationtag " $ string(StationTriggerVolume(NotifyActor).StationTag));
			return false;
		}
	}
	else
	{
		Log("Unable to process Volume_Enter with NotifyActor" @ string(NotifyActor) @ "with tag" @ string(NotifyActor.Tag));
		return false;
	}
	Log("Volume_Enter - NotifyActor is " $ string(NotifyActor) $ " with stationtag " $ string(StationTriggerVolume(NotifyActor).StationTag));
	*/
	return true;
}

bool AFA_EL_MasterScript::Volume_Exit(AVolume* NotifyActor, AActor* aInstigator)
{
	/*
	if (StationTriggerVolume(NotifyActor) != nullptr)
	{
		switch (StationTriggerVolume(NotifyActor).StationTag)
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
	/*
	local Actor SearchActor;
	local GrenadeHelper GH;
	if (bMasterScript)
	{
		GH = Level.GetGrenadeHelper();
		GH.EventLab = Self;
		ForEach AllActors(Class'Actor', SearchActor)
		{
			if (SearchActor.Tag == "StationTriggerVolume")
			{
				SearchActor.EventLab = Self;
			}
			if (SearchActor.Tag == "NPC_Ambient")
			{
				SearchActor.EventLab = Self;
			}
			if (FA_NPC_DS_Koch(SearchActor) != nullptr)
			{
				DS_Koch = FA_NPC_DS_Koch(SearchActor);
				Log("DS_Koch linked");
			}
			if (FA_NPC_DS_Moore(SearchActor) != nullptr)
			{
				DS_Moore = FA_NPC_DS_Moore(SearchActor);
				DS_Moore.bUseActionIcon = true;
				Log("DS_Moore linked");
			}
			if (FA_NPC_DS_Acosta(SearchActor) != nullptr)
			{
				DS_Acosta = FA_NPC_DS_Acosta(SearchActor);
				Log("DS_Acosta linked");
			}
			if (FA_NPC_DS_Mateo(SearchActor) != nullptr)
			{
				DS_Mateo = FA_NPC_DS_Mateo(SearchActor);
				Log("DS_Mateo linked");
			}
			if (FA_NPC_DS_Johnson(SearchActor) != nullptr)
			{
				DS_Johnson = FA_NPC_DS_Johnson(SearchActor);
				Log("DS_Johnson linked");
			}
			if (FA_NPC_DS_Kelly(SearchActor) != nullptr)
			{
				DS_Kelly = FA_NPC_DS_Kelly(SearchActor);
				Log("DS_Kelly linked");
			}
		}
		Station1.AssignDrillSergeants(DS_Moore);
		Station2.AssignDrillSergeants(DS_Acosta);
		Station3.AssignDrillSergeants(DS_Kelly);
		Station4.AssignDrillSergeants(DS_Mateo);
		Station5.AssignDrillSergeants(DS_Johnson);
		Station6.AssignDrillSergeants(DS_Koch);
	}
	Super::DoReferenceLinking();
	*/
}

void AFA_EL_MasterScript::GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	local FA_EL_MasterScript ActiveScript;
	if (bMasterScript)
	{
		ActiveScript = FA_EL_MasterScript(GetActiveScript());
		if ((ActiveScript == None) || (ActiveScript == Self))
		{
			Log("Breaking from masterscript GrenadeExploded().  ActiveScript is " $ string(ActiveScript));
			return;
		}
		else
		{
			if (ActiveScript != nullptr)
			{
				ActiveScript.GrenadeExploded(Grenade, Event, Instigator, Parms);
			}
		}
	}
	*/
}

void AFA_EL_MasterScript::SetPlayerWeapon(bool bWeaponUp, bool bSetLockWeaponPosition)
{
	/*
	if (bMasterScript)
	{
		if (bWeaponUp)
		{
			if (Player.Weapon == None)
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
	/*
	local Actor MoveToPoint;
	MoveToPoint = GetActorByTag("DS_Koch_New_Location");
	DS_Koch.SetLocation(MoveToPoint.Location);
	DS_Koch.SetRotation(MoveToPoint.Rotation);
	DS_Koch.DesiredRotation = MoveToPoint.Rotation;
	DS_Koch.Default.DesiredRotation = MoveToPoint.Rotation;
	DS_Koch.bRotateToDesired = false;
	*/
}

void AFA_EL_MasterScript::MovePlayerToStation(int32 StationID)
{
	TeleportStationID = StationID;
	//ChangeState("ForcePlayerMove");
}

void AFA_EL_MasterScript::Destroyed()
{
	/*
	int32 i = 0;
	for (i = 0; i < BlockingVolumes.Length; i++)
	{
		BlockingVolumes[i] = None;
	}
	BlockingVolumes.remove(0, BlockingVolumes.Length);
	FAMasterScript = None;
	Station1 = None;
	Station2 = None;
	Station3 = None;
	Station4 = None;
	Station5 = None;
	Station6 = None;
	DS_Koch = None;
	DS_Moore = None;
	DS_Acosta = None;
	DS_Mateo = None;
	DS_Johnson = None;
	DS_Kelly = None;
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
	if (GetActiveScript() == Self)
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
