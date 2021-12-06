// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_EscapeAndEvade/EL_EscapeAndEvade.h"

AEL_EscapeAndEvade::AEL_EscapeAndEvade()
{

}

/*
State PreInsertion
{
Begin:
	if (LastLocationTag == StartLocationTag)
	{
		ChangeState('Insertion');
	}
	else
	{
		Player.SetLocation(GetActorLocation(LastLocationTag));
		switch(LastLocationTag)
		{
			case 'CheckpointA':
			PlayTip("You have been reset to Objective A","",5);
			StartClock();
			break;
			case 'CheckpointB':
			PlayTip("You have been reset to Objective B","",5);
			StartClock();
			break;
			default:
		}
		ChangeState('PreEvade');
	}
}
State Insertion
{
	Function BeginState()
	{
		blackhawk.ResetAnims();
		ClearClock();
		DisableGuards();
		DisableAmbient();
		DisableHUD();
		PlayerLock(false,false);
		Controller.Crouch();
		PlayerLock(true,true);
		HidePlayer();
		GiveBinocs(Player,0);
		blackhawk.SetLocation(GetActorLocation('IP_Insertion'));
		blackhawk.SetRotation(GetActorRotation('IP_Insertion'));
		blackhawk.SetChopperSound('Interior');
		blackhawk.TurnOffLandingLights();
		CheckpointA.SetDisabled(false);
		CheckpointB.SetDisabled(true);
		CheckpointC.SetDisabled(true);
	}
	Function EventLabTick(float DeltaTime)
	{
		blackhawk.ViewMarker.SetRotation((blackhawk.PlayerView.Rotation + Player.GetViewRotation()));
	}
	Function bool Timer_Timer(FName Name)
	{
		return Global.Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		return true;
	}
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		blackhawk.LoopAnim('Idle');
	}
Begin:
	if (bSkipIntro && (! bStartAtEnd))
	{
		FadeIn(1,true);
		SetFOV(85);
		EnableHUD();
		PlayerLock(false,false);
		ChangeState('Dustoff');
		JL'End'
;
	}
	if (bStartAtEnd)
	{
		Player.SetLocation(GetActorLocation('LocExtraction'));
		Player.SetRotation(GetActorRotation('LocExtraction'));
		CheckpointC.SetDisabled(false);
		FadeIn(1,true);
		ChangeState('PreEvade');
		JL'End'
;
	}
	if (ViewedCinematicCount > 1)
	{
		FadeOut(2,true);
		StartClock();
		Player.SetLocation(GetActorLocation('L_PostInsertion'));
		Controller.SetRotation(GetActorRotation('L_PostInsertion'));
		ChangeState('PreEvade');
		JL'End'
;
	}
	ViewedCinematicCount ++;
	FadeOut(0,true);
	Sleep(1);
	StartScene('Insertion');
	blackhawk.SetChopperSound('exterior');
	FadeIn(5,true);
	DisableHUD();
	Cam01.SetActive(true);
	Log("EVENTLAB CUEING CAM01");
	CueCamera(Cam01);
	SetFOV(25);
	Sleep(9);
	Cam01.SetActive(false);
	Controller.SetRotation(blackhawk.Rotation);
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound('Interior');
	SetFOV(85);
	PlayerLock(true,false);
	blackhawk.Crew[2].PlayLIPSincAnim('01_ThirtySeconds',1,128,1);
	Sleep(4);
	blackhawk.Crew[2].PlayLIPSincAnim('02_SlowAndLow_Short',1,128,1);
	Sleep(8);
	CueCamera(blackhawk.ChaseCamB);
	blackhawk.SetChopperSound('Exterior2');
	SetFOV(45);
	DisableHUD();
	Sleep(2.5);
	Cam02.SetActive(true);
	CueCamera(Cam02);
	blackhawk.SetChopperSound('exterior');
	SetFOV(45);
	DisableHUD();
	Sleep(6);
	Cam02.SetActive(false);
	Controller.SetRotation(blackhawk.Rotation);
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound('Interior');
	SetFOV(85);
	blackhawk.Crew[2].PlayLIPSincAnim('03_CrouchOrCrawl',1,128,1);
	Sleep(9);
	Cam03.SetActive(true);
	CueCamera(Cam03);
	blackhawk.SetChopperSound('exterior');
	SetFOV(45);
	DisableHUD();
	Sleep(1);
	blackhawk.TurnOnLandingLights();
	Sleep(4);
	Cam03.SetActive(false);
	Controller.SetRotation((blackhawk.Rotation + MakeRot(0,-16384,0)));
	CueCamera(blackhawk.ViewMarker);
	blackhawk.SetChopperSound('Interior');
	SetFOV(85);
	blackhawk.Crew[2].PlayLIPSincAnim('04_ThreeObjectives',1,128,1);
	Sleep(14);
	blackhawk.Crew[2].PlayLIPSincAnim('05_MoveOut',1,128,1);
	Sleep(2);
	ChangeState('Dustoff');
}
State Dustoff
{
	Function BeginState()
	{
		StartClock();
		Player.SetLocation(GetActorLocation('L_PostInsertion'));
		Controller.SetRotation(GetActorRotation('L_PostInsertion'));
		PlayerLock(false,false);
		Controller.Crouch();
		ShowPlayer();
		GiveBinocs(Player,2);
		CuePlayer();
		EnableHUD();
		SetFOV(85);
		blackhawk.SetChopperSound('Exterior2');
		StartTimer('DoDustOff',0.5);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'DoDustOff')
		{
			StartScene('Dustoff');
			return true;
		}
		return false;
	}
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		blackhawk.TurnOffLandingLights();
	}
	Function bool SceneManager_SceneEnd(SceneManager NotifyActor, Actor Instigator, FString Parms)
	{
		if (NotifyActor.Tag == 'Dustoff')
		{
			ChangeState('PreEvade');
			return true;
		}
	}
}
State PreEvade
{
	Function BeginState()
	{
		ResetGuards();
		ResetScript();
		EnableAmbient();
		ShowPlayer();
		CuePlayer();
		EnableHUD();
		RestoreFOV();
		PlayerLock(false,false);
		GiveBinocs(Player,2);
		blackhawk.SetChopperSound('None');
		FadeIn(2,true);
	}
Begin:
	ChangeState('Evade');
}
State Evade
{
	Function BeginState()
	{
		StartTimer('PlayAmbient',0.2,true);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'PlayAmbient')
		{
			if (! bDisableAmbient)
			{
				PlayAmbientSounds();
			}
		}
		return Global.Timer_Timer(Name);
	}
	Function bool NoiseTrigger_Trigger(AGP_Gameplay.NoiseTrigger NotifyActor, Actor Instigator, FString Parms)
	{
		ParseParms(Parms);
		if (ParmList[0] == "EXTNOISE")
		{
			SendNoise(NotifyActor,float(ParmList[1]));
			return true;
		}
	}
	Function bool RiskVolume_Enter(AGP_Gameplay.RiskVolume NotifyActor, Actor Instigator, FString Parms)
	{
		ParseParms(Parms);
		if (ParmList[0] == "RISK")
		{
			VolumeRisk=float(ParmList[1]);
			return true;
		}
	}
	Function bool RiskVolume_Exit(AGP_Gameplay.RiskVolume NotifyActor, Actor Instigator, FString Parms)
	{
		return RiskVolume_Enter(NotifyActor,Instigator,Parms);
	}
	Function bool AGP_Character_Custom(AGP_Characters.AGP_Character NotifyActor, Actor Instigator, FString Parms)
	{
		if (! NotifyActor.Controller.IsA('HumanController'))
		{
			return false;
		}
		ParseParms(Parms);
		if (ParmList[0] == "SLOWMODE")
		{
			GOTO JL00D0;
		}
		if (ParmList[0] == "SPRINTMODE")
		{
			GOTO JL00D0;
		}
		if (ParmList[0] == "CROUCHMODE")
		{
			if (bool(ParmList[1]))
			{
				PlayerPosture=1;
			}
			else
			{
				PlayerPosture=2;
			}
		}
		else
		{
			if (ParmList[0] == "PRONEMODE")
			{
				if (bool(ParmList[1]))
				{
					PlayerPosture=0;
				}
				else
				{
					PlayerPosture=2;
JL00D0:
				}
			}
		}
		return true;
	}
	Function SendNoise(Actor Instigator, float Loudness)
	{
		int32 i = 0;
		for (i=0; i<Guards.Length; i++)
		{
			if (Guards[i] == None)
			{
			}
			if (VSize((Instigator.Location - Guards[i].Location)) < float(4096))
			{
				if (bDebug)
				{
					Log("EL_EscapeAndEvade::SendNoise(): Noise Sent at loudness: " $ string(Loudness));
				}
				Guards[i].ExtMakeNoise(Instigator,Loudness);
			}
		}
	}
	Function PlayAmbientSounds()
	{
		float RandNum = 0;
		RandNum=FRand();
		if (RandNum >= 0.9)
		{
			if (PlayerStealth > 0.6)
			{
				GetRandomMarker().PlaySound(GetCommonSound(),,(0.05 * PlayerStealth),false,128);
			}
		}
		if (RandNum >= 0.9)
		{
			if (PlayerStealth < 0.4)
			{
				GetRandomMarker().PlaySound(GetDogSound(),,(0.25 * (1 - PlayerStealth)),false,1024);
			}
		}
		if (RandNum >= 0.98)
		{
			if (PlayerStealth > 0.4)
			{
				GetRandomMarker().PlaySound(GetRareSound(),,0.1,false,256);
			}
		}
	}
	Function bool NPC_EEGuard_Custom(AGP_Characters.NPC_EEGuard NotifyActor, Actor Instigator, FString Parms)
	{
		if (bDisableGuardScript)
		{
			return true;
		}
		ParseParms(Parms);
		switch(ParmList[0])
		{
			case "PLAYERSPOTTED":
			if (bDebug)
			{
				Log("PLAYER SPOTTED");
			}
			PlayerSpotted(NotifyActor);
			return true;
			case "HEARSOMETHING":
			if (bDebug)
			{
				Log("HEAR SOMETHING");
			}
			HearSomething(NotifyActor);
			return true;
			case "SEESOMETHING":
			if (bDebug)
			{
				Log("SEE SOMETHING");
			}
			SeeSomething(NotifyActor);
			return true;
			case "FALSEALARM":
			if (bDebug)
			{
				Log("FALSE ALARM");
			}
			FalseAlarm(NotifyActor);
			return true;
			default:
			return false;
		}
	}
	Function int32 GetReqVisBones()
	{
		return 2;
	}
	Function bool CanSeePlayer(Actor Camera)
	{
		int32 i = 0;
		int32 NumVisible = 0;
		int32 ReqVisible = 0;
		bool bVisible = false;
		FVector BonePos = FVector(0,0,0);
		ReqVisible=GetReqVisBones();
		for (i=0; i<PlayerBones.Length; i++)
		{
			BonePos=Player.GetBoneCoords(PlayerBones[i].BoneName).Origin;
			bVisible=FastTrace(BonePos,Camera.Location);
			if (bVisible)
			{
				NumVisible ++;
			}
			if (NumVisible >= ReqVisible)
			{
			}
		}
		return (NumVisible >= ReqVisible);
	}
	Function PlayerSpotted(AGP_Characters.NPC_EEGuard Guard)
	{
		Player.PutAwayHandItem();
		PlayTip("You've been spotted!","Resetting to last completed objective...",5);
		PlayerLock(true,true);
		if ((bUseDeathCameras && (Guard.DeathCamera != None)) && CanSeePlayer(Guard.DeathCamera))
		{
			CameraPoint(Guard.DeathCamera).SetActive(true);
			CueCamera(Guard.DeathCamera);
			DisableHUD();
			StartFOV=110;
			EndFOV=15;
			FOVTweenTime=1.2;
			SetFOV(StartFOV);
			StartTimer('StartZoom',3);
		}
		Guard.PlaySound(BustedSounds[Rand(2)],0,1,,512);
		ChangeState('STATE_PlayerSpotted');
	}
	Function HearSomething(AGP_Characters.NPC_EEGuard Guard)
	{
		Guard.PlaySound(HearSounds[Rand(2)],0,1,,512);
	}
	Function SeeSomething(AGP_Characters.NPC_EEGuard Guard)
	{
		Guard.PlaySound(SeeSounds[Rand(2)],0,1,,512);
	}
	Function FalseAlarm(AGP_Characters.NPC_EEGuard Guard)
	{
		Guard.PlaySound(FalseSounds[Rand(2)],0,10,,2048);
	}
	Function bool AGP_Objective_Trigger(AGP_Objective NotifyActor, Actor Instigator)
	{
		if (NotifyActor.Tag == 'CheckpointA')
		{
			CheckpointA.SetDisabled(true);
			CheckpointB.SetDisabled(false);
			LastLocationTag=CheckpointA.Tag;
			PlayTip("You have reached Objective A","",5);
			return true;
		}
		if (NotifyActor.Tag == 'CheckpointB')
		{
			CheckpointB.SetDisabled(true);
			CheckpointC.SetDisabled(false);
			LastLocationTag=CheckpointB.Tag;
			PlayTip("You have reached Objective B","",5);
			return true;
		}
		if (NotifyActor.Tag == 'CheckpointC')
		{
			CheckpointC.SetDisabled(true);
			PlayTip("You have reached Objective C","",5);
			ChangeState('Signal');
			return true;
		}
	}
Begin:
	if (LastLocationTag == StartLocationTag)
	{
		PlayTip("Head for Objective A","Stay low and move slow to avoid being detected",5);
		Sleep(7);
	}
	PlayTip("Use your <FastMove> key","to control your movement speed",5);
	Sleep(7);
	PlayTip("If you think you might have been detected,","use your <crawling> key to go prone, and stay still for several seconds",8);
}
State STATE_PlayerSpotted
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'StartZoom')
		{
			StartZoom();
		}
		return Global.Timer_Timer(Name);
	}
	Function StartZoom()
	{
		ZoomFOV(StartFOV,EndFOV,FOVTweenTime);
	}
Begin:
	DisableGuards();
	Sleep(5);
	ChangeState('PreInsertion');
}
State Signal
{
	Function bool AGP_UseTrigger_UsedBy(AGP_UseTrigger NotifyActor, Actor Instigator)
	{
		MissionTime=GetClockTime();
		ClearClock();
		ChangeState('Extraction');
		return Global.agpdoCurrentTarget(NotifyActor,Instigator);
	}
Begin:
	Sleep(7);
	PlayTip("Use the truck to signal for extraction","",5);
}
State Extraction
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
	}
	Function UpdateCompletionFields()
	{
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local TArray<FString> asMD5ForMap;
		local TArray<FString> asMD5ForScript;
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != None)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != None)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/eande.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
				sMD5ForMap=asMD5ForMap[0];
				sMD5ForScript=asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
	}
Begin:
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	Cam04.SetActive(true);
	CueCamera(Cam04);
	SetFOV(65);
	DisableHUD();
	PlayerLock(true,true);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	TriggerEvent('Headlights',Self,Player);
	Sleep(1);
	Cam04.SetActive(false);
	Cam05.SetActive(true);
	CueCamera(Cam05);
	SetFOV(20);
	DisableHUD();
	blackhawk.SetChopperSound('exterior');
	Scout.LoopAnim('StdBinocsUp',1,0.5);
	StartScene('Extraction');
	Sleep(1);
	Scout.LoopAnim('StdBinocsDn',1,0.5);
	Sleep(1.5);
	blackhawk.TurnOnLandingLights();
	Sleep(3);
	Cam05.SetActive(false);
	PlayerLock(false,false);
	EnableHUD();
	CuePlayer();
	SetFOV(85);
	Sleep(7);
	StudentController(Controller).ResetAuthExtraMissionData();
	StudentController(Controller).AddAuthExtraMissionData(GetClockTime());
	UpdateCompletionFields();
	if (StudentController(Controller).IsCheating())
	{
		StudentController(Controller).SetAuthMissionPassFlag(false);
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Cheats Detected!","Your time is: " $ MissionTime,128,128,7,'None');
	}
	else
	{
		StudentController(Controller).SetAuthMissionPassFlag(true);
		DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_SF","Congratulations! ","Your time is: " $ MissionTime,128,128,7,'None');
	}
}
*/
