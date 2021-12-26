// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_SFMOUT/EL_SFMOUT.h"

AEL_SFMOUT::AEL_SFMOUT()
{
	Room1TimerDelay = 4;
	Room2TimerDelay = 4;
	Room3TimerDelay = 5;
	Room4TimerDelay = 5.25;
	Room5TimerDelay = 4;
	Room6TimerDelay = 5;
	Room7TimerDelay = 5;
	Room8TimerDelay = 4;
	Room9TimerDelay = 7;
	preTimerPause = 0.5;
	keepMovingIdleTime = 30;
	aarReportDelay = 0.5;
	AmmoFadeTime = 2;
	FlashTimerDelay = 6;
	TargetFlipModifier = 0.35;
	GameSounds = {
		FGameSound({ nullptr,"None",0}),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_c0_Que.m_c0_Cue'"),NULL, LOAD_None, NULL),"m_c0",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_c2_Que.m_c2_Cue'"),NULL, LOAD_None, NULL),"m_c2",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls0_Que.m_ls0_Cue'"),NULL, LOAD_None, NULL),"m_ls0",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls1_Que.m_ls1_Cue'"),NULL, LOAD_None, NULL),"m_ls1",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls2_Que.m_ls2_Cue'"),NULL, LOAD_None, NULL),"m_ls2",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls3_Que.m_ls3_Cue'"),NULL, LOAD_None, NULL),"m_ls3",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls5_Que.m_ls5_Cue'"),NULL, LOAD_None, NULL),"m_ls5",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls6_Que.m_ls6_Cue'"),NULL, LOAD_None, NULL),"m_ls6",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_p0_Que.m_p0_Cue'"),NULL, LOAD_None, NULL),"m_p0",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ws1_Que.m_ws1_Cue'"),NULL, LOAD_None, NULL),"m_ws1",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_beep_Que.m_beep_Cue'"),NULL, LOAD_None, NULL),"m_beep",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_clank_Que.m_clank_Cue'"),NULL, LOAD_None, NULL),"m_clank",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_error_Que.m_error_Cue'"),NULL, LOAD_None, NULL),"m_error",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_horn_Que.m_horn_Cue'"),NULL, LOAD_None, NULL),"m_horn",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_hydraulic_Que.m_hydraulic_Cue'"),NULL, LOAD_None, NULL),"m_hydraulic",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_klaxon_Que.m_klaxon_Cue'"),NULL, LOAD_None, NULL),"m_klaxon",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Foley/machines/Switch_Que.Switch_Cue'"),NULL, LOAD_None, NULL),"m_switch",0 })
	};

	LSAnims = {
		FLSAnim({ "m_aar0",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar0_Que.m_aar0_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar1_Que.m_aar1_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/m_aar2_Que.m_aar2_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar3_Que.m_aar3_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar4_Que.m_aar4_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar5_Que.m_aar5_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar6",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar6_Que.m_aar6_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar7",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar7_Que.m_aar7_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar8",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar8_Que.m_aar8_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar9",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar9_Que.m_aar9_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar10_Que.m_aar10_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar11",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar11_Que.m_aar11_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar12",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar12_Que.m_aar12_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar13_Que.m_aar13_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar14",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar14_Que.m_aar14_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_ws0",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ws0_Que.m_ws0_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_c1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_c1_Que.m_c1_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar15",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar15_Que.m_aar15_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar16",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar16_Que.m_aar16_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar17",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar17_Que.m_aar17_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar18",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar18_Que.m_aar18_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar19",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar19_Que.m_aar19_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar20",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar20_Que.m_aar20_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar21",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar21_Que.m_aar21_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "m_aar22",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_aar22_Que.m_aar22_Cue'"),NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} ,{0,0,0,0,0,0,0,0,0,0} })
	};

}

/*
State Briefing
{
	Function BeginState()
	{
		PlayGameSound("m_c0",Player);
		PlayerLock(true,false);
	}
	Function EndIntroVO()
	{
		if (! bIntroed)
		{
			PlayTip("Welcome to the MOUT Training Exercise.","See MAJ Amerine for your mission briefing.",5);
		}
		bIntroed=true;
		SetCustomTimer(40,false,"CheckPlayerMove");
		PlayerLock(false,false);
		skipVOTrigger.HUDText="";
		skipVOTrigger.bDisabled=true;
		cadreAAR.LoopAnim("DrillIdle");
		cadreFrago.LoopAnim("DrillIdle");
		cadreHistory.LoopAnim("DrillIdle");
	}
	Function bool skipVOTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Player.StopSound(GetGameSound("m_c0"));
		EndIntroVO();
		return true;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "m_c0")
		{
			EndIntroVO();
			return true;
		}
	}
}
*/

/*
State DoorBreacher
{
	Function BeginState()
	{
		breacherSpeech=true;
		if (! breacherSpeech)
		{
			PlayGameSound("m_ls1",room0Sound);
			PlayTip("Select and Employ the Door Breacher","to Gain Entry to the Shoot House",5);
			breacherSpeech=true;
		}
	}
}
*/

/*
State Room1_Red
{
	Function bool doorTrigger1_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool breacherTrigger_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		bNoSecurityViolation=false;
		return true;
	}
	Function bool room1Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger1.Close();
			doorTrigger1.bIsLocked=true;
			room1Target7=MarksmanTarget(CaptureEvent("room1Target7"));
			room1Target8=MarksmanTarget(CaptureEvent("room1Target8"));
			StartTimer("Target7",0.1);
			StartTimer("Target8",0.05);
			StartTimer("interrupt",2);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room1Timer1.SetValue("room1Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room1_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom1Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room1TimerDelay);
			}
			bFlashed=false;
			bRoom1Flipped=true;
			PlayGameSound("m_horn",room1Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room1Target1);
			room1Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room1Target2);
			room1Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room1Target3);
			room1Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room1Target4);
			room1Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room1Target5);
			room1Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room1Target6);
			room1Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room1Target7);
			room1Target7.TriggerSelf();
			return true;
			case "Target8":
			PlayGameSound("m_hydraulic",room1Target8);
			room1Target8.TriggerSelf();
			return true;
			case "interrupt":
			if (room1Target7.bTriggered)
			{
				PlayGameSound("m_hydraulic",room1Target7);
				room1Target7.ResetTarget(true);
				UnCaptureEvent(room1Target7);
			}
			if (room1Target8.bTriggered)
			{
				PlayGameSound("m_hydraulic",room1Target8);
				room1Target8.ResetTarget(true);
				UnCaptureEvent(room1Target8);
			}
			return true;
			case "CountDown":
			ChangeState("Room1_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		StopCustomTimer("CheckPlayerMove");
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room1Target1=MarksmanTarget(CaptureEvent("room1Target1"));
		room1Target2=MarksmanTarget(CaptureEvent("room1Target2"));
		room1Target3=MarksmanTarget(CaptureEvent("room1Target3"));
		room1Target4=MarksmanTarget(CaptureEvent("room1Target4"));
		room1Target5=MarksmanTarget(CaptureEvent("room1Target5"));
		room1Target6=MarksmanTarget(CaptureEvent("room1Target6"));
		opforRunningCount=0;
		if (! bFlashed)
		{
			StartClock(0);
		}
		StartTimer("Pause",preTimerPause);
		bCanRunOutOfAmmo=true;
		TimeRemaining=Room1TimerDelay;
		SetCustomTimer((5 * float(60)),false,"OutOfTime");
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room1Target1.ResetTarget(true);
		UnCaptureEvent(room1Target1);
		room1Target2.ResetTarget(true);
		UnCaptureEvent(room1Target2);
		room1Target3.ResetTarget(true);
		UnCaptureEvent(room1Target3);
		room1Target4.ResetTarget(true);
		UnCaptureEvent(room1Target4);
		room1Target5.ResetTarget(true);
		UnCaptureEvent(room1Target5);
		room1Target6.ResetTarget(true);
		UnCaptureEvent(room1Target6);
	}
}
*/

/*
State Room1_Green extends Room1_Red
{
	Function bool room1Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger1_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_ls5",room1Sound,,,0.99);
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			return true;
			case "WhiteLight":
			room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "m_beep")
		{
			PlayGameSound("m_ls5",room1Sound,,,1);
			PlayTip("Room is cleared!","Move on to the Next Door!",5);
			return true;
		}
		else
		{
			if (Name == "m_ls5")
			{
				PlayGameSound("m_klaxon",room1Sound,,,0.75);
				return true;
			}
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room1Sound);
		room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room2_Red
{
	Function bool room1Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room1Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room1Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger2_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger2.Close();
			doorTrigger2.bIsLocked=true;
			room2Target6=MarksmanTarget(CaptureEvent("room2Target6"));
			room2Target7=MarksmanTarget(CaptureEvent("room2Target7"));
			StartTimer("Target6",0.1);
			StartTimer("Target7",0.05);
			StartTimer("interrupt",2.5);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room2Timer1.SetValue("room2Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room2_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom2Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room2TimerDelay);
			}
			bFlashed=false;
			bRoom2Flipped=true;
			PlayGameSound("m_horn",room2Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room2Target1);
			room2Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room2Target2);
			room2Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room2Target3);
			room2Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room2Target4);
			room2Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room2Target5);
			room2Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room2Target6);
			room2Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room2Target7);
			room2Target7.TriggerSelf();
			return true;
			case "interrupt":
			if (! room2Target6.bTriggered)
			{
				PlayGameSound("m_hydraulic",room2Target6);
				room2Target6.ResetTarget(true);
				UnCaptureEvent(room2Target6);
			}
			if (! room2Target7.bTriggered)
			{
				PlayGameSound("m_hydraulic",room2Target7);
				room2Target7.ResetTarget(true);
				UnCaptureEvent(room2Target7);
			}
			return true;
			case "CountDown":
			ChangeState("Room2_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room2Target1=MarksmanTarget(CaptureEvent("room2Target1"));
		room2Target2=MarksmanTarget(CaptureEvent("room2Target2"));
		room2Target3=MarksmanTarget(CaptureEvent("room2Target3"));
		room2Target4=MarksmanTarget(CaptureEvent("room2Target4"));
		room2Target5=MarksmanTarget(CaptureEvent("room2Target5"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room2TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room2Target1.ResetTarget(true);
		UnCaptureEvent(room2Target1);
		room2Target2.ResetTarget(true);
		UnCaptureEvent(room2Target2);
		room2Target3.ResetTarget(true);
		UnCaptureEvent(room2Target3);
		room2Target4.ResetTarget(true);
		UnCaptureEvent(room2Target4);
		room2Target5.ResetTarget(true);
		UnCaptureEvent(room2Target5);
	}
}
*/

/*
State Room2_Green extends Room2_Red
{
	Function bool room1Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room1Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room1Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger2_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room2Sound);
			return true;
			case "WhiteLight":
			room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room2Sound);
		room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room3_Red
{
	Function bool room2Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger3_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger3.Close();
			doorTrigger3.bIsLocked=true;
			room3Target9=MarksmanTarget(CaptureEvent("room3Target9"));
			room3Target10=MarksmanTarget(CaptureEvent("room3Target10"));
			StartTimer("Target9",0.1);
			StartTimer("Target10",0.05);
			StartTimer("interrupt",1.75);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room3Timer1.SetValue("room3Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room3_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom3Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room3TimerDelay);
			}
			bFlashed=false;
			bRoom3Flipped=true;
			PlayGameSound("m_horn",room3Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
			StartTimer("Target7",(FRand() * TargetFlipModifier));
			StartTimer("Target8",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room3Target1);
			room3Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room3Target2);
			room3Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room3Target3);
			room3Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room3Target4);
			room3Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room3Target5);
			room3Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room3Target6);
			room3Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room3Target7);
			room3Target7.TriggerSelf();
			return true;
			case "Target8":
			PlayGameSound("m_hydraulic",room3Target8);
			room3Target8.TriggerSelf();
			return true;
			case "Target9":
			PlayGameSound("m_hydraulic",room3Target9);
			room3Target9.TriggerSelf();
			return true;
			case "Target10":
			PlayGameSound("m_hydraulic",room3Target10);
			room3Target10.TriggerSelf();
			return true;
			case "interrupt":
			if (! room3Target9.bTriggered)
			{
				PlayGameSound("m_hydraulic",room3Target9);
				room3Target9.ResetTarget(true);
				UnCaptureEvent(room3Target9);
			}
			if (! room3Target10.bTriggered)
			{
				PlayGameSound("m_hydraulic",room3Target10);
				room3Target10.ResetTarget(true);
				UnCaptureEvent(room3Target10);
			}
			return true;
			case "CountDown":
			ChangeState("Room3_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room3Target1=MarksmanTarget(CaptureEvent("room3Target1"));
		room3Target2=MarksmanTarget(CaptureEvent("room3Target2"));
		room3Target3=MarksmanTarget(CaptureEvent("room3Target3"));
		room3Target4=MarksmanTarget(CaptureEvent("room3Target4"));
		room3Target5=MarksmanTarget(CaptureEvent("room3Target5"));
		room3Target6=MarksmanTarget(CaptureEvent("room3Target6"));
		room3Target7=MarksmanTarget(CaptureEvent("room3Target7"));
		room3Target8=MarksmanTarget(CaptureEvent("room3Target8"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room3TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room3Target1.ResetTarget(true);
		UnCaptureEvent(room3Target1);
		room3Target2.ResetTarget(true);
		UnCaptureEvent(room3Target2);
		room3Target3.ResetTarget(true);
		UnCaptureEvent(room3Target3);
		room3Target4.ResetTarget(true);
		UnCaptureEvent(room3Target4);
		room3Target5.ResetTarget(true);
		UnCaptureEvent(room3Target5);
		room3Target6.ResetTarget(true);
		UnCaptureEvent(room3Target6);
		room3Target7.ResetTarget(true);
		UnCaptureEvent(room3Target7);
		room3Target8.ResetTarget(true);
		UnCaptureEvent(room3Target8);
	}
}
*/

/*
State Room3_Green extends Room3_Red
{
	Function bool room2Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room2Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger3_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room3Sound);
			return true;
			case "WhiteLight":
			room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room3Sound);
		room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room4_Red
{
	Function bool room3Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger4_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger4.Close();
			doorTrigger4.bIsLocked=true;
			room4Target7=MarksmanTarget(CaptureEvent("room4Target7"));
			room4Target8=MarksmanTarget(CaptureEvent("room4Target8"));
			StartTimer("Target7",0.1);
			StartTimer("Target8",0.05);
			StartTimer("interrupt",2);
			interrupt=true;
		}
		return true;
	}
	Function bool room4Trigger4_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt2)
		{
			room4Target9=MarksmanTarget(CaptureEvent("room4Target9"));
			StartTimer("Target9",0.1);
			StartTimer("interrupt",1.5);
			interrupt2=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room4Timer1.SetValue("room4Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room4_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom4Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room4TimerDelay);
			}
			bFlashed=false;
			bRoom4Flipped=true;
			PlayGameSound("m_horn",room4Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room4Target1);
			room4Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room4Target2);
			room4Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room4Target3);
			room4Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room4Target4);
			room4Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room4Target5);
			room4Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room4Target6);
			room4Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room4Target7);
			room4Target7.TriggerSelf();
			return true;
			case "Target8":
			PlayGameSound("m_hydraulic",room4Target8);
			room4Target8.TriggerSelf();
			return true;
			case "Target9":
			PlayGameSound("m_hydraulic",room4Target9);
			room4Target9.TriggerSelf();
			return true;
			case "interrupt":
			if (! room4Target7.bTriggered)
			{
				PlayGameSound("m_hydraulic",room4Target7);
				room4Target7.ResetTarget(true);
				UnCaptureEvent(room4Target7);
			}
			if (! room4Target8.bTriggered)
			{
				PlayGameSound("m_hydraulic",room4Target8);
				room4Target8.ResetTarget(true);
				UnCaptureEvent(room4Target8);
			}
			if (! room4Target9.bTriggered)
			{
				PlayGameSound("m_hydraulic",room4Target9);
				room4Target9.ResetTarget(true);
				UnCaptureEvent(room4Target9);
			}
			return true;
			case "CountDown":
			ChangeState("Room4_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room4Target1=MarksmanTarget(CaptureEvent("room4Target1"));
		room4Target2=MarksmanTarget(CaptureEvent("room4Target2"));
		room4Target3=MarksmanTarget(CaptureEvent("room4Target3"));
		room4Target4=MarksmanTarget(CaptureEvent("room4Target4"));
		room4Target5=MarksmanTarget(CaptureEvent("room4Target5"));
		room4Target6=MarksmanTarget(CaptureEvent("room4Target6"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room4TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room4Target1.ResetTarget(true);
		UnCaptureEvent(room4Target1);
		room4Target2.ResetTarget(true);
		UnCaptureEvent(room4Target2);
		room4Target3.ResetTarget(true);
		UnCaptureEvent(room4Target3);
		room4Target4.ResetTarget(true);
		UnCaptureEvent(room4Target4);
		room4Target5.ResetTarget(true);
		UnCaptureEvent(room4Target5);
		room4Target6.ResetTarget(true);
		UnCaptureEvent(room4Target6);
	}
}
*/

/*
State Room4_Green extends Room4_Red
{
	Function bool room3Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room3Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger4_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room3Sound);
			return true;
			case "WhiteLight":
			room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room3Sound);
		room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room5_Red
{
	Function bool room4Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger5_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger5.Close();
			doorTrigger5.bIsLocked=true;
			room5Target6=MarksmanTarget(CaptureEvent("room5Target6"));
			StartTimer("Target6",0.1);
			StartTimer("interrupt",2);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room5Timer1.SetValue("room5Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room5_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom5Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room5TimerDelay);
			}
			bFlashed=false;
			bRoom5Flipped=true;
			PlayGameSound("m_horn",room5Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room5Target1);
			room5Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room5Target2);
			room5Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room5Target3);
			room5Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room5Target4);
			room5Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room5Target5);
			room5Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room5Target6);
			room5Target6.TriggerSelf();
			return true;
			case "interrupt":
			if (! room5Target6.bTriggered)
			{
				PlayGameSound("m_hydraulic",room5Target6);
				room5Target6.ResetTarget(true);
				UnCaptureEvent(room5Target6);
			}
			return true;
			case "CountDown":
			ChangeState("Room5_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room5Target1=MarksmanTarget(CaptureEvent("room5Target1"));
		room5Target2=MarksmanTarget(CaptureEvent("room5Target2"));
		room5Target3=MarksmanTarget(CaptureEvent("room5Target3"));
		room5Target4=MarksmanTarget(CaptureEvent("room5Target4"));
		room5Target5=MarksmanTarget(CaptureEvent("room5Target5"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room5TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room5Target1.ResetTarget(true);
		UnCaptureEvent(room5Target1);
		room5Target2.ResetTarget(true);
		UnCaptureEvent(room5Target2);
		room5Target3.ResetTarget(true);
		UnCaptureEvent(room5Target3);
		room5Target4.ResetTarget(true);
		UnCaptureEvent(room5Target4);
		room5Target5.ResetTarget(true);
		UnCaptureEvent(room5Target5);
	}
}
*/

/*
State Room5_Green extends Room5_Red
{
	Function bool room4Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room4Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger5_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room5Sound);
			return true;
			case "WhiteLight":
			room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room5Sound);
		room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room6_Red
{
	Function bool room5Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger6_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room6Timer1.SetValue("room6Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room6_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom6Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room6TimerDelay);
			}
			bFlashed=false;
			bRoom6Flipped=true;
			PlayGameSound("m_horn",room6Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
			StartTimer("Target7",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room6Target1);
			room6Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room6Target2);
			room6Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room6Target3);
			room6Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room6Target4);
			room6Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room6Target5);
			room6Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room6Target6);
			room6Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room6Target7);
			room6Target7.TriggerSelf();
			return true;
			case "CountDown":
			ChangeState("Room6_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room6Target1=MarksmanTarget(CaptureEvent("room6Target1"));
		room6Target2=MarksmanTarget(CaptureEvent("room6Target2"));
		room6Target3=MarksmanTarget(CaptureEvent("room6Target3"));
		room6Target4=MarksmanTarget(CaptureEvent("room6Target4"));
		room6Target5=MarksmanTarget(CaptureEvent("room6Target5"));
		room6Target6=MarksmanTarget(CaptureEvent("room6Target6"));
		room6Target7=MarksmanTarget(CaptureEvent("room6Target7"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room6TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room6Target1.ResetTarget(true);
		UnCaptureEvent(room6Target1);
		room6Target2.ResetTarget(true);
		UnCaptureEvent(room6Target2);
		room6Target3.ResetTarget(true);
		UnCaptureEvent(room6Target3);
		room6Target4.ResetTarget(true);
		UnCaptureEvent(room6Target4);
		room6Target5.ResetTarget(true);
		UnCaptureEvent(room6Target5);
		room6Target6.ResetTarget(true);
		UnCaptureEvent(room6Target6);
		room6Target7.ResetTarget(true);
		UnCaptureEvent(room6Target7);
	}
}
*/

/*
State Room6_Green extends Room6_Red
{
	Function bool room5Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room5Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger6_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room6Sound);
			return true;
			case "WhiteLight":
			room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room6Sound);
		room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room7_Red
{
	Function bool room6Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger7_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		doorTrigger7.Close();
		doorTrigger7.bIsLocked=true;
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room7Timer1.SetValue("room7Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room7_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom7Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room7TimerDelay);
			}
			bFlashed=false;
			bRoom7Flipped=true;
			PlayGameSound("m_horn",room7Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
			StartTimer("Target7",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room7Target1);
			room7Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room7Target2);
			room7Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room7Target3);
			room7Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room7Target4);
			room7Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room7Target5);
			room7Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room7Target6);
			room7Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room7Target7);
			room7Target7.TriggerSelf();
			return true;
			case "CountDown":
			ChangeState("Room7_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room7Target1=MarksmanTarget(CaptureEvent("room7Target1"));
		room7Target2=MarksmanTarget(CaptureEvent("room7Target2"));
		room7Target3=MarksmanTarget(CaptureEvent("room7Target3"));
		room7Target4=MarksmanTarget(CaptureEvent("room7Target4"));
		room7Target5=MarksmanTarget(CaptureEvent("room7Target5"));
		room7Target6=MarksmanTarget(CaptureEvent("room7Target6"));
		room7Target7=MarksmanTarget(CaptureEvent("room7Target7"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room7TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room7Target1.ResetTarget(true);
		UnCaptureEvent(room7Target1);
		room7Target2.ResetTarget(true);
		UnCaptureEvent(room7Target2);
		room7Target3.ResetTarget(true);
		UnCaptureEvent(room7Target3);
		room7Target4.ResetTarget(true);
		UnCaptureEvent(room7Target4);
		room7Target5.ResetTarget(true);
		UnCaptureEvent(room7Target5);
		room7Target6.ResetTarget(true);
		UnCaptureEvent(room7Target6);
		room7Target7.ResetTarget(true);
		UnCaptureEvent(room7Target7);
	}
}
*/

/*
State Room7_Green extends Room7_Red
{
	Function bool room6Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room6Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger7_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room7Sound);
			return true;
			case "WhiteLight":
			room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room7Sound);
		room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room8_Red
{
	Function bool room7Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger8_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			doorTrigger8.Close();
			doorTrigger8.bIsLocked=true;
			room8Target7=MarksmanTarget(CaptureEvent("room8Target7"));
			room8Target8=MarksmanTarget(CaptureEvent("room8Target8"));
			StartTimer("Target7",0.1);
			StartTimer("Target8",0.05);
			StartTimer("interrupt",3);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room8Timer1.SetValue("room8Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room8_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom8Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room8TimerDelay);
			}
			bFlashed=false;
			bRoom8Flipped=true;
			PlayGameSound("m_horn",room8Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room8Target1);
			room8Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room8Target2);
			room8Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room8Target3);
			room8Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room8Target4);
			room8Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room8Target5);
			room8Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room8Target6);
			room8Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room8Target7);
			room8Target7.TriggerSelf();
			return true;
			case "Target8":
			PlayGameSound("m_hydraulic",room8Target8);
			room8Target8.TriggerSelf();
			return true;
			case "interrupt":
			if (! room8Target7.bTriggered)
			{
				PlayGameSound("m_hydraulic",room8Target7);
				room8Target7.ResetTarget(true);
				UnCaptureEvent(room8Target7);
			}
			if (! room8Target8.bTriggered)
			{
				PlayGameSound("m_hydraulic",room8Target8);
				room8Target8.ResetTarget(true);
				UnCaptureEvent(room8Target8);
			}
			return true;
			case "CountDown":
			ChangeState("Room8_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room8Target1=MarksmanTarget(CaptureEvent("room8Target1"));
		room8Target2=MarksmanTarget(CaptureEvent("room8Target2"));
		room8Target3=MarksmanTarget(CaptureEvent("room8Target3"));
		room8Target4=MarksmanTarget(CaptureEvent("room8Target4"));
		room8Target5=MarksmanTarget(CaptureEvent("room8Target5"));
		room8Target6=MarksmanTarget(CaptureEvent("room8Target6"));
		room8Target7=MarksmanTarget(CaptureEvent("room8Target7"));
		room8Target8=MarksmanTarget(CaptureEvent("room8Target8"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room8TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room8Target1.ResetTarget(true);
		UnCaptureEvent(room8Target1);
		room8Target2.ResetTarget(true);
		UnCaptureEvent(room8Target2);
		room8Target3.ResetTarget(true);
		UnCaptureEvent(room8Target3);
		room8Target4.ResetTarget(true);
		UnCaptureEvent(room8Target4);
		room8Target5.ResetTarget(true);
		UnCaptureEvent(room8Target5);
		room8Target6.ResetTarget(true);
		UnCaptureEvent(room8Target6);
	}
}
*/

/*
State Room8_Green extends Room8_Red
{
	Function bool room7Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room7Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool doorTrigger8_UsedBy(AGP_Gameplay.DoorTrigger Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room8Sound);
			return true;
			case "WhiteLight":
			room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound("m_beep",room8Sound);
		room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
}
*/

/*
State Room9_Red
{
	Function bool room8Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room9Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt)
		{
			PlayGameSound("m_switch",Player);
			room9Target9=MarksmanTarget(CaptureEvent("room9Target9"));
			room9Target10=MarksmanTarget(CaptureEvent("room9Target10"));
			StartTimer("Target9",0.1);
			StartTimer("Target10",0.05);
			StartTimer("interrupt",1.75);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer("CountDown"),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer("CountDown") != 0)
		{
			TimeRemaining=QueryTimer("CountDown");
		}
		room9Timer1.SetValue("room9Digits",newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 6)
		{
			PlayGameSound("m_p0",Player);
			StopTimer("CountDown",0);
			(timeKeeper += TimeRemaining);
			ChangeState("Room9_Green");
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom9Flipped)
		{
			if (! bFlashed)
			{
				StartTimer("CountDown",Room9TimerDelay);
			}
			bFlashed=false;
			bRoom9Flipped=true;
			PlayGameSound("m_horn",room9Sound);
			StartTimer("Target1",(FRand() * TargetFlipModifier));
			StartTimer("target2",(FRand() * TargetFlipModifier));
			StartTimer("Target3",(FRand() * TargetFlipModifier));
			StartTimer("Target4",(FRand() * TargetFlipModifier));
			StartTimer("Target5",(FRand() * TargetFlipModifier));
			StartTimer("Target6",(FRand() * TargetFlipModifier));
			StartTimer("Target7",(FRand() * TargetFlipModifier));
			StartTimer("Target8",(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Target1":
			PlayGameSound("m_hydraulic",room9Target1);
			room9Target1.TriggerSelf();
			return true;
			case "target2":
			PlayGameSound("m_hydraulic",room9Target2);
			room9Target2.TriggerSelf();
			return true;
			case "Target3":
			PlayGameSound("m_hydraulic",room9Target3);
			room9Target3.TriggerSelf();
			return true;
			case "Target4":
			PlayGameSound("m_hydraulic",room9Target4);
			room9Target4.TriggerSelf();
			return true;
			case "Target5":
			PlayGameSound("m_hydraulic",room9Target5);
			room9Target5.TriggerSelf();
			return true;
			case "Target6":
			PlayGameSound("m_hydraulic",room9Target6);
			room9Target6.TriggerSelf();
			return true;
			case "Target7":
			PlayGameSound("m_hydraulic",room9Target7);
			room9Target7.TriggerSelf();
			return true;
			case "Target8":
			PlayGameSound("m_hydraulic",room9Target8);
			room9Target8.TriggerSelf();
			return true;
			case "Target9":
			PlayGameSound("m_hydraulic",room9Target9);
			room9Target9.TriggerSelf();
			return true;
			case "Target10":
			PlayGameSound("m_hydraulic",room9Target10);
			room9Target10.TriggerSelf();
			return true;
			case "interrupt":
			if (! room9Target9.bTriggered)
			{
				PlayGameSound("m_hydraulic",room9Target9);
				room9Target9.ResetTarget(true);
				UnCaptureEvent(room9Target9);
			}
			if (! room9Target10.bTriggered)
			{
				PlayGameSound("m_hydraulic",room9Target10);
				room9Target10.ResetTarget(true);
				UnCaptureEvent(room9Target10);
			}
			aarScoreboard();
			return true;
			case "CountDown":
			ChangeState("Room9_Green");
			return true;
			case "Pause":
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"PlayKeepMoving");
		room9Target1=MarksmanTarget(CaptureEvent("room9Target1"));
		room9Target2=MarksmanTarget(CaptureEvent("room9Target2"));
		room9Target3=MarksmanTarget(CaptureEvent("room9Target3"));
		room9Target4=MarksmanTarget(CaptureEvent("room9Target4"));
		room9Target5=MarksmanTarget(CaptureEvent("room9Target5"));
		room9Target6=MarksmanTarget(CaptureEvent("room9Target6"));
		room9Target7=MarksmanTarget(CaptureEvent("room9Target7"));
		room9Target8=MarksmanTarget(CaptureEvent("room9Target8"));
		opforRunningCount=0;
		StartTimer("Pause",preTimerPause);
		TimeRemaining=Room9TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer("Pause",0);
		room9Target1.ResetTarget(true);
		UnCaptureEvent(room9Target1);
		room9Target2.ResetTarget(true);
		UnCaptureEvent(room9Target2);
		room9Target3.ResetTarget(true);
		UnCaptureEvent(room9Target3);
		room9Target4.ResetTarget(true);
		UnCaptureEvent(room9Target4);
		room9Target5.ResetTarget(true);
		UnCaptureEvent(room9Target5);
		room9Target6.ResetTarget(true);
		UnCaptureEvent(room9Target6);
		room9Target7.ResetTarget(true);
		UnCaptureEvent(room9Target7);
		room9Target8.ResetTarget(true);
		UnCaptureEvent(room9Target8);
		SetCustomTimer((keepMovingIdleTime * 2),false,"JumpToAAR");
		StopCustomTimer("OutOfTime");
		PlayGameSound("m_beep",room9Sound);
		room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer("WhiteLight",0.5);
	}
	Function Ammoish()
	{
		bCanRunOutOfAmmo=false;
	}
	Function bool WeaponClearTrigger_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! bDonels6)
		{
			Ammoish();
			bDonels6=true;
			DoWeapClearVO();
			ChangeState("EndSH");
			bNoSecurityViolation=false;
		}
		return true;
	}
}
*/

/*
State Room9_Green extends Room9_Red
{
	Function bool room8Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room9Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function EventLabTick(float DeltaTime)
	{
	}
	Function bool exitRedState(int32 opforNum)
	{
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "AllClear":
			PlayGameSound("m_klaxon",room9Sound);
			return true;
			case "WhiteLight":
			room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer("RedLight",0.75);
			return true;
			case "RedLight":
			room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer("WhiteLight",0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case "m_beep":
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer("AllClear",3);
			return true;
			case "m_ls6":
			PlayerLock(false,false);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		SetCustomTimer(1,false,"Ammoish");
	}
}
*/

/*
State OutOfAmmo
{
	Function BeginState()
	{
		StopCustomTimer("PlayKeepMoving");
		Player.SetLocation(aarLocation.Location);
		Player.Controller.SetRotation(aarLocation.Rotation);
		FadeInBlack(float(AmmoFadeTime));
		holsterweapon();
		RemoveWeapons();
		PlayTip("Soldier, You've expended your ammo prior to completing your training","You've failed to meet the minimum standard.",5);
		PlayerLock(true,true);
		PlayLSAnim("m_aar15",cadreAAR,1,512,,aarReportDelay);
		cadreUseTrigger3.bActive=false;
		cadreUseTrigger3.HUDText="";
	}
	Function PlayNoGo()
	{
		PlayLSAnim("m_aar14",cadreAAR,1,512,,aarReportDelay);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "m_aar15":
			case "m_aar14":
			uploadStats();
			return true;
			default:
		}
	}
}
*/

/*
State EndSH
{
	Function bool room8Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room8Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room9Trigger1_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room9Trigger2_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool room9Trigger3_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
	}
	Function bool cadreUseTrigger3_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState("AAR");
		return true;
	}
	Function bool sbUseTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		uploadStats();
		return true;
	}
	Function BeginState()
	{
		aarScoreboard();
	}
}
*/

/*
State AAR
{
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "aar0":
			aarOpforHit();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "m_aar0":
			case "m_aar1":
			case "m_aar2":
			case "m_aar17":
			case "m_aar18":
			aarFriendlyHit();
			return true;
			case "m_aar3":
			case "m_aar4":
			case "m_aar5":
			case "m_aar19":
			aarAmmo();
			return true;
			case "m_aar6":
			case "m_aar7":
			case "m_aar8":
			case "m_aar20":
			aarTime();
			return true;
			case "m_aar9":
			case "m_aar10":
			case "m_aar11":
			case "m_aar21":
			aarTotalScore();
			return true;
			case "m_aar12":
			case "m_aar13":
			case "m_aar14":
			case "m_aar22":
			EndOfAAR();
			return true;
			default:
		}
	}
	Function bool aarOpforHit()
	{
		if (opforHit >= 46)
		{
			aarAnimName="m_aar17";
		}
		else
		{
			if (opforHit >= 40)
			{
				aarAnimName="m_aar0";
			}
			else
			{
				if (opforHit >= 30)
				{
					aarAnimName="m_aar1";
				}
				else
				{
					if (opforHit >= 20)
					{
						aarAnimName="m_aar2";
					}
					else
					{
						aarAnimName="m_aar18";
					}
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarOpforHit:" $ string(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total OPFOR Targets Hit:" @ string(opforHit),"OPFOR Hit Score:" @ string(opforHitScore),7);
		return true;
	}
	Function bool aarFriendlyHit()
	{
		FString FriendlyHitName = "";
		if (friendlyHit >= 5)
		{
			aarAnimName="m_aar19";
		}
		else
		{
			if (friendlyHit >= 3)
			{
				aarAnimName="m_aar3";
			}
			else
			{
				if (friendlyHit >= 1)
				{
					aarAnimName="m_aar4";
				}
				else
				{
					aarAnimName="m_aar5";
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarFriendlyHit:" $ string(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		if (friendlyHit > 0)
		{
			FriendlyHitName="Friendly Casualty Penalties:";
		}
		else
		{
			FriendlyHitName="IFF Bonus:";
		}
		PlayTip("Total Friendly Targets Hit:" @ string(friendlyHit),FriendlyHitName @ string(friendlyHitScore),7);
		return true;
	}
	Function bool aarAmmo()
	{
		if (Accuracy == 1)
		{
			aarAnimName="m_aar20";
		}
		else
		{
			if (Accuracy >= 0.85)
			{
				aarAnimName="m_aar6";
			}
			else
			{
				if (Accuracy >= 0.6)
				{
					aarAnimName="m_aar7";
				}
				else
				{
					aarAnimName="m_aar8";
				}
			}
		}
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Overall Weapon Accuracy:" @ string(int((Accuracy * float(100)))) $ "%","Weapon Accuracy Bonus:" @ string(accuracyScore),7);
		return true;
	}
	Function bool aarTime()
	{
		int32 totalHouseTime = 0;
		totalHouseTime=GetClockSeconds();
		if (totalHouseTime > 135)
		{
			aarAnimName="m_aar21";
		}
		else
		{
			if (totalHouseTime > 115)
			{
				aarAnimName="m_aar9";
			}
			else
			{
				if (totalHouseTime > 95)
				{
					aarAnimName="m_aar10";
				}
				else
				{
					aarAnimName="m_aar11";
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarTime:" $ string(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total Time to Complete Training:" @ timeOverall,"Speed Bonus Score:" @ string(timeOverallScore),7);
		return true;
	}
	Function bool aarTotalScore()
	{
		if (TotalScore >= 18000)
		{
			aarAnimName="m_aar12";
		}
		else
		{
			if (TotalScore >= 15000)
			{
				aarAnimName="m_aar22";
			}
			else
			{
				if (TotalScore >= 10000)
				{
					aarAnimName="m_aar13";
				}
				else
				{
					aarAnimName="m_aar14";
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarTotalScore:" $ string(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		if (finalGo == "X")
		{
			PlayTip("Total Overall Score:" @ string(TotalScore),"You are a GO at this training",7);
		}
		else
		{
			PlayTip("Total Overall Score:" @ string(TotalScore),"You are a NO-GO at this training",7);
		}
		return true;
	}
	Function bool cadreUseTrigger3_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState("EndSH");
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR.StopLIPSincAnim();
		}
		aarAnimName="m_aar16";
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		return true;
	}
	Function EndOfAAR()
	{
		ChangeState("EndSH");
	}
	Function BeginState()
	{
		StopCustomTimer("PlayKeepMoving");
		cadreUseTrigger3.HUDText="Skip AAR";
		Controller.LockPlayer(true,true);
		doorTrigger9.Close();
		doorTrigger9.bIsLocked=true;
		StartTimer("aar0",1);
	}
	Function EndState()
	{
		PlayTip("Examine Scoreboard and review your","results to complete this training.",3);
		Controller.LockPlayer(false,false);
		cadreUseTrigger3.HUDText=cadreUseTipAAR;
	}
}
*/

bool AEL_SFMOUT::DecoMesh_Damaged(ADecoMesh* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_SFMOUT::Pawn_Custom(APawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_SFMOUT::AGP_Pawn_Custom(AAGP_Pawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_SFMOUT::AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_SFMOUT::AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_SFMOUT::Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	local AGP_Weapon weap;
	local Pickup pick;
	FVector weapLocation = FVector(0, 0, 0);
	FRotator weapRotation = FRotator(0, 0, 0);
	SetCustomTimer(0.1, false, "doCantDrop");
	if (NotifyActor.IsA("PickupW_M9_Pistol") || NotifyActor.IsA("PickupW_M4A1_Rifle_Mod"))
	{
		if (Instigator.IsA("Pawn"))
		{
			weap = AGP_Weapon(Pawn(Instigator).FindInventoryType(Class'AGP_Inventory.Weapon_M9_Pistol'));
			if (weap != None)
			{
				weap.PickupClass = Class'AGP_Inventory.PickupW_M9_Pistol';
				weapLocation = w_m9.Location;
				weapRotation = w_m9.Rotation;
				pick = weap.DropFrom(weapLocation);
				pick.SetEventLab(Self);
				pick.SetRotation(weapRotation);
				if (weap.PickupClass == nullptr)
				{
				}
				weap = AGP_Weapon(Pawn(Instigator).FindInventoryType(Class'AGP_Inventory.Weapon_M9_Pistol'));
			}
			weap = AGP_Weapon(Pawn(Instigator).FindInventoryType(Class'AGP_Inventory.Weapon_M4A1_Rifle_Mod'));
			if (weap != None)
			{
				weap.PickupClass = Class'AGP_Inventory.PickupW_M4A1_Rifle_Mod';
				weapLocation = w_m4a1.Location;
				weapRotation = w_m4a1.Rotation;
				pick = weap.DropFrom(weapLocation);
				pick.SetEventLab(Self);
				pick.SetRotation(weapRotation);
				if (weap.PickupClass == nullptr)
				{
				}
				weap = AGP_Weapon(Pawn(Instigator).FindInventoryType(Class'AGP_Inventory.Weapon_M4A1_Rifle_Mod'));
			}
		}
	}
	*/
	return true;
}

void AEL_SFMOUT::doCantDrop()
{
	/*
	local AGP_Weapon weap;
	weap = AGP_Weapon(Player.FindInventoryType(Class'AGP_Inventory.Weapon_M9_Pistol'));
	weap.PickupClass = nullptr;
	weap = AGP_Weapon(Player.FindInventoryType(Class'AGP_Inventory.Weapon_M4A1_Rifle_Mod'));
	weap.PickupClass = nullptr;
	*/
}

bool AEL_SFMOUT::Pickup_AbortPickup(APickup* NotifyPickup, APawn* User)
{
	/*
	if (NotifyPickup.Tag == "CantTouchThis")
	{
		switch (NotifyPickup.Class)
		{
		case Class'AGP_Inventory.PickupW_M4A1_Rifle_Mod':
			PlayTip("Excellent short-range weapon.", "use in semi-auto mode while in Shoot House", 4);
			break;
		case Class'AGP_Inventory.PickupW_M9_Pistol':
			PlayTip("Low recoil, high reliability firearm.", "check magazine capacity often in Shoot House", 4);
			break;
		case Class'AGP_Inventory.PickupT_M84_Stun':
			PlayTip("Throw into hostile rooms before entering.", "Will halt timer for " $ string(FlashTimerDelay) $ " seconds", 4);
			break;
		case Class'AGP_Inventory.Pickup_Nightvision':
			PlayTip("Use Night Vision Goggles (NVG) in blacked out", "rooms to help discern enemies from friendlies.", 4);
			break;
		default:
		}
	}
	*/
	return true;
}

bool AEL_SFMOUT::ThrowWeaponPickup_GrenadeEffects(AThrowWeaponPickup* Grenade)
{
	/*
	if (Grenade.Zone.Name == "ZoneInfo1")
	{
		SecurityViolation();
	}
	*/
	return true;
}

bool AEL_SFMOUT::AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator)
{
	/*
	FadeOut(0.5, true);
	SetCustomTimer(0.6, false, "RestartLevel");
	*/
	return true;
}

bool AEL_SFMOUT::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	/*
	if ((Player.Zone.Name == "ZoneInfo0") && bCanRunOutOfAmmo)
	{
		return true;
	}
	FadeOut(0.5, true);
	SetCustomTimer(0.5, false, "Leavenworth");
	*/
	return true;
}

void AEL_SFMOUT::Leavenworth()
{
	//ConsoleCommand("open leavenworth");
}

void AEL_SFMOUT::PreInit()
{
	/*
	aarLocation = AGP_DumbEndPoint(CaptureEvent("NoAmmoFadeTarget"));
	damageDetector1 = DamageDetector(CaptureEvent("damageDetector1"));
	damageDetector2 = DamageDetector(CaptureEvent("damageDetector2"));
	damageDetector3 = DamageDetector(CaptureEvent("damageDetector3"));
	damageDetector4 = DamageDetector(CaptureEvent("damageDetector4"));
	damageDetector5 = DamageDetector(CaptureEvent("damageDetector5"));
	damageDetector6 = DamageDetector(CaptureEvent("damageDetector6"));
	damageDetector7 = DamageDetector(CaptureEvent("damageDetector7"));
	damageDetector8 = DamageDetector(CaptureEvent("damageDetector8"));
	w_m4a1 = Pickup(CaptureEvent("w_m4a1"));
	w_m9 = Pickup(CaptureEvent("w_m9"));
	door1 = Mover(CaptureEvent("door1"));
	door2 = Mover(CaptureEvent("door2"));
	door3 = Mover(CaptureEvent("door3"));
	door4 = Mover(CaptureEvent("door4"));
	door5 = Mover(CaptureEvent("door5"));
	door6 = Mover(CaptureEvent("door6"));
	door7 = Mover(CaptureEvent("door7"));
	door8 = Mover(CaptureEvent("door8"));
	door9 = Mover(CaptureEvent("door9"));
	cadreUseTrigger1 = AGP_UseTrigger(CaptureEvent("cadreUseTrigger1"));
	cadreUseTrigger2 = AGP_UseTrigger(CaptureEvent("cadreUseTrigger2"));
	cadreUseTrigger3 = AGP_UseTrigger(CaptureEvent("cadreUseTrigger3"));
	skipVOTrigger = AGP_UseTrigger(CaptureEvent("skipVOTrigger"));
	sbUseTrigger = AGP_UseTrigger(CaptureEvent("sbUseTrigger"));
	inspectUseTrigger = AGP_UseTrigger(CaptureEvent("inspectUseTrigger"));
	cadreUseTip1 = cadreUseTrigger1.HUDText;
	cadreUseTip2 = cadreUseTrigger2.HUDText;
	cadreUseTipAAR = cadreUseTrigger3.HUDText;
	inspectUseTip = inspectUseTrigger.HUDText;
	cadreTrigger1 = TriggerVolume(CaptureEvent("cadreTrigger1"));
	cadreTrigger2 = TriggerVolume(CaptureEvent("cadreTrigger2"));
	cadreTrigger3 = TriggerVolume(CaptureEvent("cadreTrigger3"));
	doorTrigger1 = DoorTrigger(CaptureEvent("doorTrigger1"));
	doorTrigger2 = DoorTrigger(CaptureEvent("doorTrigger2"));
	doorTrigger3 = DoorTrigger(CaptureEvent("doorTrigger3"));
	doorTrigger4 = DoorTrigger(CaptureEvent("doorTrigger4"));
	doorTrigger5 = DoorTrigger(CaptureEvent("doorTrigger5"));
	doorTrigger6 = DoorTrigger(CaptureEvent("doorTrigger6"));
	doorTrigger7 = DoorTrigger(CaptureEvent("doorTrigger7"));
	doorTrigger8 = DoorTrigger(CaptureEvent("doorTrigger8"));
	doorTrigger9 = DoorTrigger(CaptureEvent("doorTrigger9"));
	room1Trigger1 = TriggerVolume(CaptureEvent("room1Trigger1"));
	room1Trigger2 = TriggerVolume(CaptureEvent("room1Trigger2"));
	room1Trigger3 = TriggerVolume(CaptureEvent("room1Trigger3"));
	room2Trigger1 = TriggerVolume(CaptureEvent("room2Trigger1"));
	room2Trigger2 = TriggerVolume(CaptureEvent("room2Trigger2"));
	room2Trigger3 = TriggerVolume(CaptureEvent("room2Trigger3"));
	room3Trigger1 = TriggerVolume(CaptureEvent("room3Trigger1"));
	room3Trigger2 = TriggerVolume(CaptureEvent("room3Trigger2"));
	room3Trigger3 = TriggerVolume(CaptureEvent("room3Trigger3"));
	room4Trigger1 = TriggerVolume(CaptureEvent("room4Trigger1"));
	room4Trigger2 = TriggerVolume(CaptureEvent("room4Trigger2"));
	room4Trigger3 = TriggerVolume(CaptureEvent("room4Trigger3"));
	room4Trigger4 = TriggerVolume(CaptureEvent("room4Trigger4"));
	room5Trigger1 = TriggerVolume(CaptureEvent("room5Trigger1"));
	room5Trigger2 = TriggerVolume(CaptureEvent("room5Trigger2"));
	room5Trigger3 = TriggerVolume(CaptureEvent("room5Trigger3"));
	room6Trigger1 = TriggerVolume(CaptureEvent("room6Trigger1"));
	room6Trigger2 = TriggerVolume(CaptureEvent("room6Trigger2"));
	room7Trigger1 = TriggerVolume(CaptureEvent("room7Trigger1"));
	room7Trigger2 = TriggerVolume(CaptureEvent("room7Trigger2"));
	room7Trigger3 = TriggerVolume(CaptureEvent("room7Trigger3"));
	room8Trigger1 = TriggerVolume(CaptureEvent("room8Trigger1"));
	room8Trigger2 = TriggerVolume(CaptureEvent("room8Trigger2"));
	room8Trigger3 = TriggerVolume(CaptureEvent("room8Trigger3"));
	room9Trigger1 = TriggerVolume(CaptureEvent("room9Trigger1"));
	room9Trigger2 = TriggerVolume(CaptureEvent("room9Trigger2"));
	room9Trigger3 = TriggerVolume(CaptureEvent("room9Trigger3"));
	authTrigger = TriggerVolume(CaptureEvent("authTrigger"));
	holsterTrigger = TriggerVolume(CaptureEvent("TriggerVolume"));
	WeaponClearVolumeTrigger = TriggerVolume(CaptureEvent("WeaponClearVolume"));
	breacherTrigger = TriggerVolume(CaptureEvent("breacherTrigger"));
	TextDisplay = TextDisplay(GetActor("TextDisplay"));
	aarDisplay = TextDisplay(GetActor("aarDisplay"));
	room1Timer1 = TextDisplay(GetActor("room1Timer1"));
	room2Timer1 = TextDisplay(GetActor("room2Timer1"));
	room3Timer1 = TextDisplay(GetActor("room3Timer1"));
	room4Timer1 = TextDisplay(GetActor("room4Timer1"));
	room5Timer1 = TextDisplay(GetActor("room5Timer1"));
	room6Timer1 = TextDisplay(GetActor("room6Timer1"));
	room7Timer1 = TextDisplay(GetActor("room7Timer1"));
	room8Timer1 = TextDisplay(GetActor("room8Timer1"));
	room9Timer1 = TextDisplay(GetActor("room9Timer1"));
	room1Light1 = Light(GetActor("room1Light1"));
	room2Light1 = Light(GetActor("room2Light1"));
	room3Light1 = Light(GetActor("room3Light1"));
	room4Light1 = Light(GetActor("room4Light1"));
	room5Light1 = Light(GetActor("room5Light1"));
	room6Light1 = Light(GetActor("room6Light1"));
	room7Light1 = Light(GetActor("room7Light1"));
	room8Light1 = Light(GetActor("room8Light1"));
	room9Light1 = Light(GetActor("room9Light1"));
	terrainSound1 = AGP_Sound(GetActor("terrainSound1"));
	ambientSound1 = AGP_Sound(GetActor("AmbientSound"));
	room0Sound = AGP_Sound(GetActor("room0Sound"));
	room1Sound = AGP_Sound(GetActor("room1Sound"));
	room2Sound = AGP_Sound(GetActor("room2Sound"));
	room3Sound = AGP_Sound(GetActor("room3Sound"));
	room4Sound = AGP_Sound(GetActor("room4Sound"));
	room5Sound = AGP_Sound(GetActor("room5Sound"));
	room6Sound = AGP_Sound(GetActor("room6Sound"));
	room7Sound = AGP_Sound(GetActor("room7Sound"));
	room8Sound = AGP_Sound(GetActor("room8Sound"));
	room9Sound = AGP_Sound(GetActor("room9Sound"));
	doCantTouch();
	*/
}

void AEL_SFMOUT::doCantTouch()
{
	/*
	local Pickup CantTouch;
	ForEach AllActors(Class'Pickup', CantTouch)
	{
		if (CantTouch.Tag == "CantTouchThis")
		{
			CantTouch.SetEventLab(Self);
			CantTouch.InventoryType = nullptr;
		}
		else
		{
			if (CantTouch.Tag == "PickupT_M84_Stun")
			{
				CantTouch.SetEventLab(Self);
			}
		}
	}
	*/
}

void AEL_SFMOUT::PostPostInit()
{
	/*
	cadreFrago = AGP_Character_NPC(CaptureEvent("cadreFrago", Class'AGP_Characters.AGP_Character_NPC'));
	cadreHistory = AGP_Character_NPC(CaptureEvent("cadreHistory", Class'AGP_Characters.AGP_Character_NPC'));
	cadreAAR = AGP_Character_NPC(CaptureEvent("cadreAAR", Class'AGP_Characters.AGP_Character_NPC'));
	cadreObserver = AGP_Character_NPC(CaptureEvent("cadreObserver4", Class'AGP_Characters.AGP_Character_NPC'));
	cadreFrago.SetCollisionSize(cadreFrago.CollisionRadius, 41);
	cadreAAR.SetCollisionSize(cadreFrago.CollisionRadius, 41);
	CapturePlayer();
	FadeIn(6, true);
	cadreFrago.LoopAnim("JmasterIdle");
	cadreFrago.Controller.Focus = Controller.Pawn;
	cadreHistory.LoopAnim("podiumidle");
	cadreHistory.Controller.Focus = Controller.Pawn;
	cadreAAR.LoopAnim("podiumidle");
	PlayerLock(false, false);
	UserName = Controller.UserName;
	doorTrigger1.SetLocked(true);
	dateToday = string(Level.Year) $ "/";
	if (Level.Month < 10)
	{
		(dateToday $ = "0");
	}
	(dateToday $ = string(Level.Month) $ "/");
	if (Level.Day < 10)
	{
		(dateToday $ = "0");
	}
	(dateToday $ = string(Level.Day));
	opforHit = 0;
	opforHitScore = 0;
	friendlyHit = 0;
	friendlyHitScore = 0;
	roundsFired = 0;
	Accuracy = 0;
	accuracyScore = 0;
	timeOverall = "00:00";
	timeOverallScore = 0;
	TotalScore = 0;
	finalNoGo = "";
	finalGo = "";
	TextDisplay.SetValue("sTotalScore", string(TotalScore));
	TextDisplay.SetValue("sUserName", UserName);
	TextDisplay.SetValue("sDateToday", dateToday);
	TextDisplay.SetValue("sOpforHit", string(opforHit));
	TextDisplay.SetValue("sFriendlyHit", string(friendlyHit));
	TextDisplay.SetValue("sOpforHitScore", string(opforHitScore));
	TextDisplay.SetValue("sFriendlyHitScore", string(friendlyHitScore));
	TextDisplay.SetValue("sRoundsFired", string(int((Accuracy * float(100)))) $ "%");
	TextDisplay.SetValue("sRoundsFiredScore", string(accuracyScore));
	TextDisplay.SetValue("sTimeOverall", timeOverall);
	TextDisplay.SetValue("sTimeOverallScore", string(timeOverallScore));
	TextDisplay.SetValue("sFinalGo", finalGo);
	TextDisplay.SetValue("sFinalNoGo", finalNoGo);
	Controller.MPCheat_NVG();
	ChangeState("Briefing");
	*/
}

bool AEL_SFMOUT::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "cadreTrigger1":
		return cadreTrigger1_Enter(Trigger, Instigator);
	case "cadreTrigger2":
		return cadreTrigger2_Enter(Trigger, Instigator);
	case "cadreTrigger3":
		return cadreTrigger3_Enter(Trigger, Instigator);
	case "room1Trigger1":
		return room1Trigger1_Enter(Trigger, Instigator);
	case "room1Trigger2":
		return room1Trigger2_Enter(Trigger, Instigator);
	case "room1Trigger3":
		return room1Trigger3_Enter(Trigger, Instigator);
	case "room2Trigger1":
		return room2Trigger1_Enter(Trigger, Instigator);
	case "room2Trigger2":
		return room2Trigger2_Enter(Trigger, Instigator);
	case "room2Trigger3":
		return room2Trigger3_Enter(Trigger, Instigator);
	case "room3Trigger1":
		return room3Trigger1_Enter(Trigger, Instigator);
	case "room3Trigger2":
		return room3Trigger2_Enter(Trigger, Instigator);
	case "room3Trigger3":
		return room3Trigger3_Enter(Trigger, Instigator);
	case "room4Trigger1":
		return room4Trigger1_Enter(Trigger, Instigator);
	case "room4Trigger2":
		return room4Trigger2_Enter(Trigger, Instigator);
	case "room4Trigger3":
		return room4Trigger3_Enter(Trigger, Instigator);
	case "room4Trigger4":
		return room4Trigger4_Enter(Trigger, Instigator);
	case "room5Trigger1":
		return room5Trigger1_Enter(Trigger, Instigator);
	case "room5Trigger2":
		return room5Trigger2_Enter(Trigger, Instigator);
	case "room5Trigger3":
		return room5Trigger3_Enter(Trigger, Instigator);
	case "room6Trigger1":
		return room6Trigger1_Enter(Trigger, Instigator);
	case "room6Trigger2":
		return room6Trigger2_Enter(Trigger, Instigator);
	case "room6Trigger3":
		return room6Trigger3_Enter(Trigger, Instigator);
	case "room7Trigger1":
		return room7Trigger1_Enter(Trigger, Instigator);
	case "room7Trigger2":
		return room7Trigger2_Enter(Trigger, Instigator);
	case "room7Trigger3":
		return room7Trigger3_Enter(Trigger, Instigator);
	case "room8Trigger1":
		return room8Trigger1_Enter(Trigger, Instigator);
	case "room8Trigger2":
		return room8Trigger2_Enter(Trigger, Instigator);
	case "room8Trigger3":
		return room8Trigger3_Enter(Trigger, Instigator);
	case "room9Trigger1":
		return room9Trigger1_Enter(Trigger, Instigator);
	case "room9Trigger2":
		return room9Trigger2_Enter(Trigger, Instigator);
	case "room9Trigger3":
		return room9Trigger3_Enter(Trigger, Instigator);
	case "authTrigger":
		return authTrigger_Enter(Trigger, Instigator);
	case "TriggerVolume":
		return holsterTrigger_Enter(Trigger, Instigator);
	case "WeaponClearVolume":
		return WeaponClearTrigger_Enter(Trigger, Instigator);
	case "breacherTrigger":
		return breacherTrigger_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_SFMOUT::holsterTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	holsterweapon();
	RemoveWeapons();
	StopCustomTimer("PlayKeepMoving");
	StopCustomTimer("JumpToAAR");
	doorTrigger9.SetLocked(true);
	doorTrigger9.Close();
	*/
	return true;
}

bool AEL_SFMOUT::WeaponClearTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

void AEL_SFMOUT::RemoveWeapons()
{
	/*
	if (AGP_Pawn(Controller.Pawn).FindInventoryType(Class'AGP_Inventory.Weapon_M4A1_Rifle_Mod') != None)
	{
		sWeaponAtCompletion = "M4A1";
	}
	else
	{
		if (AGP_Pawn(Controller.Pawn).FindInventoryType(Class'AGP_Inventory.Weapon_M9_Pistol') != None)
		{
			sWeaponAtCompletion = "M9";
		}
		else
		{
			sWeaponAtCompletion = "Unknown";
		}
	}
	AGP_Pawn(Controller.Pawn).EmptyInventory();
	*/
}

void AEL_SFMOUT::holsterweapon()
{
	//Weapon(Player.getHandsInventory()).PutDown();
}

bool AEL_SFMOUT::cadreTrigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("Pick up M4A1 Rifle or M9 Pistol, and Flashbangs", "Talk to Cadre for additional instructions", 2);
	return true;
}

bool AEL_SFMOUT::cadreTrigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("Talk to SGT Zedwick for a safety briefing on", "the equipment you'll use in the Shoot House.", 2);
	return true;
}

bool AEL_SFMOUT::cadreTrigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room1Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//bNoSecurityViolation = true;
	return true;
}

bool AEL_SFMOUT::room1Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room1Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room2Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room2Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room2Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room3Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room3Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room3Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room4Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room4Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room4Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room4Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room5Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room5Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room5Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room6Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room6Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room6Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room7Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room7Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room7Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room8Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room8Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room8Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::room9Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//ChangeState("Room9_Red");
	return true;
}

bool AEL_SFMOUT::room9Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//ChangeState("Room9_Green");
	return true;
}

bool AEL_SFMOUT::room9Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::authTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//ChangeState("DataBase");
	return true;
}

bool AEL_SFMOUT::PlayerHasWeapon(APawn* aPlayer)
{
	/*
	if (aPlayer.FindInventoryType(Class'AGP.TraceWeapon') != None)
	{
		return true;
	}
	*/
	return false;
}

bool AEL_SFMOUT::breacherTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if ((Pawn(Instigator) != None) && PlayerHasWeapon(Pawn(Instigator)))
	{
		doorTrigger1.SetLocked(false);
		if (!bPlayedEntranceVO)
		{
			PlayGameSound("m_ls1", Player);
		}
		bPlayedEntranceVO = true;
	}
	else
	{
		doorTrigger1.SetLocked(true);
		PlayTip("You must select a weapon from the Range table ", " before attempting to enter the Shoot House.", 3);
		bPlayedNoWeapVO = true;
	}
	bNoSecurityViolation = false;
	*/
	return true;
}

bool AEL_SFMOUT::Timer_Timer(FName Name)
{
	//return Super::Timer_Timer(Name);
	return false;    //FAKE   /ELiZ
}

bool AEL_SFMOUT::Timer_Sound(FName Name)
{
	return true;
}

bool AEL_SFMOUT::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	Trigger.bIsLocked = true;
	switch (Trigger.Tag)
	{
	case "doorTrigger1":
		return doorTrigger1_UsedBy(Trigger, Instigator);
	case "doorTrigger2":
		return doorTrigger2_UsedBy(Trigger, Instigator);
	case "doorTrigger3":
		return doorTrigger3_UsedBy(Trigger, Instigator);
	case "doorTrigger4":
		return doorTrigger4_UsedBy(Trigger, Instigator);
	case "doorTrigger5":
		return doorTrigger5_UsedBy(Trigger, Instigator);
	case "doorTrigger6":
		return doorTrigger6_UsedBy(Trigger, Instigator);
	case "doorTrigger7":
		return doorTrigger7_UsedBy(Trigger, Instigator);
	case "doorTrigger8":
		return doorTrigger8_UsedBy(Trigger, Instigator);
	case "doorTrigger9":
		return doorTrigger9_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE  /EliZ
}

bool AEL_SFMOUT::doorTrigger1_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	local Sound EnterVO;
	local Pickup CantTouch;
	EnterVO = GetGameSound("m_ls1");
	if (EnterVO != None)
	{
		Player.StopSound(EnterVO);
	}
	ChangeState("Room1_Red");
	ForEach AllActors(Class'Pickup', CantTouch)
	{
		if ((CantTouch.Tag == "w_m4a1") || (CantTouch.Tag == "w_m9"))
		{
			CantTouch.InventoryType = nullptr;
		}
	}
	bDisallowPickup = true;
	*/
	return true;
}

bool AEL_SFMOUT::doorTrigger2_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room2_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger3_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room3_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger4_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room4_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger5_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room5_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger6_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room6_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger7_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room7_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger8_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Room8_Red");
	return true;
}

bool AEL_SFMOUT::doorTrigger9_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (roundsFired == 0)
	{
		Accuracy = 0;
		PlayTip("Soldier, you have failed to meet the minimun standards for this training exercise by not firing your weapon.", "You are a NO-GO.", 4);
		FadeOut(8, true);
		SetCustomTimer(8, false, "RestartLevel");
		return true;
	}
	PlayTip("You've completed the MOUT training", "See SFC Wolford for your After Action Report", 5);
	*/
	return true;
}

bool AEL_SFMOUT::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	DebugLog(DEBUG_EventLab, "AGP Trigger: " $ string(Trigger));
	switch (Trigger.Tag)
	{
	case "cadreUseTrigger1":
		return cadreUseTrigger1_UsedBy(Trigger, Instigator);
	case "cadreUseTrigger2":
		return cadreUseTrigger2_UsedBy(Trigger, Instigator);
	case "cadreUseTrigger3":
		return cadreUseTrigger3_UsedBy(Trigger, Instigator);
	case "inspectUseTrigger":
		return inspectUseTrigger_UsedBy(Trigger, Instigator);
	case "skipVOTrigger":
		return skipVOTrigger_UsedBy(Trigger, Instigator);
	case "sbUseTrigger":
		return sbUseTrigger_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_SFMOUT::cadreUseTrigger1_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (cadreFrago.IsPlayingLIPSincAnim())
	{
		cadreFrago.StopLIPSincAnim();
	}
	if (cadreHistory.IsPlayingLIPSincAnim())
	{
		cadreHistory.StopLIPSincAnim();
		FinishCadreVO();
	}
	else
	{
		DoIntroLSVO(cadreHistory, "m_c1");
	}
	*/
	return true;
}

bool AEL_SFMOUT::inspectUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//PlayTip("Study these enemy targets carefully.", "They're the only valid targets in the Shoot House!", 4);
	return true;
}

bool AEL_SFMOUT::cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (cadreHistory.IsPlayingLIPSincAnim())
	{
		cadreHistory.StopLIPSincAnim();
	}
	if (cadreFrago.IsPlayingLIPSincAnim())
	{
		cadreFrago.StopLIPSincAnim();
		FinishCadreVO();
	}
	else
	{
		DoIntroLSVO(cadreFrago, "m_ws0");
	}
	*/
	return true;
}

bool AEL_SFMOUT::cadreUseTrigger3_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

void AEL_SFMOUT::StopVO()
{
	/*
	local Sound VO;
	if (cadreHistory.IsPlayingLIPSincAnim())
	{
		cadreHistory.StopLIPSincAnim();
		FinishCadreVO();
	}
	if (cadreFrago.IsPlayingLIPSincAnim())
	{
		cadreFrago.StopLIPSincAnim();
		FinishCadreVO();
	}
	VO = GetGameSound("m_ls1");
	if (VO != None)
	{
		Player.StopSound(VO);
	}
	VO = GetGameSound("m_ls5");
	if (VO != None)
	{
		room1Sound.StopSound(VO);
	}
	VO = GetGameSound("m_ls6");
	if ((VO != None) && bDonels6)
	{
		room9Sound.StopSound(VO);
		bRestartls6 = true;
	}
	*/
}

void AEL_SFMOUT::DoIntroLSVO(APawn* Target, FName LSAnim)
{
	/*
	StopCustomTimer("CheckPlayerMove");
	PlayLSAnim(LSAnim, Target, 1, 512);
	PlayerLock(true, true);
	cadreUseTrigger1.bDisabled = false;
	cadreUseTrigger2.bDisabled = false;
	cadreUseTrigger1.HUDText = "Skip Dialog";
	cadreUseTrigger2.HUDText = "Skip Dialog";
	*/
}

bool AEL_SFMOUT::sbUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_SFMOUT::skipVOTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

void AEL_SFMOUT::FinishCadreVO()
{
	/*
	SetCustomTimer(20, false, "CheckPlayerMove");
	cadreUseTrigger1.bDisabled = false;
	cadreUseTrigger2.bDisabled = false;
	cadreUseTrigger1.HUDText = cadreUseTip1;
	cadreUseTrigger2.HUDText = cadreUseTip2;
	PlayerLock(false, false);
	*/
}

bool AEL_SFMOUT::Timer_LSAnim(FName Name)
{
	/*
	switch (Name)
	{
	case "m_ws0":
	case "m_c1":
		FinishCadreVO();
		return true;
	default:
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AEL_SFMOUT::EventLabTick(float DeltaTime)
{
}

void AEL_SFMOUT::flipTargets()
{
}

bool AEL_SFMOUT::AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (Parms == "FIRE")
	{
		if (NotifyActor.IsA("TraceWeapon"))
		{
			roundsFired++;
			DebugLog(DEBUG_EventLab, "+++++++++++++++++ Rounds Fired:" @ string(roundsFired));
		}
		if (!bNoSecurityViolation)
		{
			SecurityViolation();
		}
	}
	else
	{
		if (((Parms == "FIREEMPTY") && (!NotifyActor.HasAmmo())) && bCanRunOutOfAmmo)
		{
			bCanRunOutOfAmmo = false;
			FadeOutBlack(float(AmmoFadeTime));
			SetCustomTimer(float(AmmoFadeTime), false, "OutOfAmmoFadeIn");
		}
	}
	*/
	return true;
}

bool AEL_SFMOUT::AGP_Weapon_Trace_Hit(AAGP_Weapon* NotifyActor, AActor* HitActor, FString Parms)
{
	/*
	switch (HitActor.Tag)
	{
	case "CantShootThat1":
	case "CantShootThat2":
	case "CantShootThat3":
	case "CantShootThat4":
	case "WeaponClearVolume":
	case "breacherTrigger":
		SecurityViolation();
		return true;
	default:
		return true;
		return true;
	}
	*/
	return false;     //FAKE   /ELiZ
}

void AEL_SFMOUT::SecurityViolation()
{
	/*
	float Time = 0;
	if (bWarnedPlay)
	{
		return;
	}
	StopVO();
	if (!bWarned)
	{
		PlayTip("Do not engage your weapons outside of the ShootHouse.", "This is your first and only warning", 4);
		Time = PlayGameSound("m_ls0", Player);
		SetCustomTimer(Time, false, "SecurityViolationPart2");
		if (bRestartls6)
		{
			SetCustomTimer(Time, false, "DoWeapClearVO");
		}
		bWarned = true;
	}
	else
	{
		if (bLastViolation)
		{
			PlayerLock(true, false);
			PlayTip("Soldier, you have violated the rules of engagement for this exercise.", "You are a NO-GO and will have to restart this mission", 4);
			SetCustomTimer(PlayGameSound("m_ls3", Player), false, "SecurityViolationPart2");
			Disable("SecurityViolation");
		}
	}
	bWarnedPlay = true;
	*/
}

void AEL_SFMOUT::SecurityViolationPart2()
{
	/*
	if (bLastViolation)
	{
		FadeOut(0.5, true);
		SetCustomTimer(0.5, false, "RestartLevel");
	}
	bWarnedPlay = false;
	bLastViolation = true;
	*/
}

void AEL_SFMOUT::JumpToAAR()
{
	/*
	PlayerLock(true, false);
	FadeOutBlack(float(AmmoFadeTime));
	SetCustomTimer(float(AmmoFadeTime), false, "JumpToAARFadeIn");
	*/
}

void AEL_SFMOUT::JumpToAARFadeIn()
{
	/*
	FadeInBlack(float(AmmoFadeTime));
	ChangeState("AAR");
	Player.SetLocation(aarLocation.Location);
	Player.Controller.SetRotation(aarLocation.Rotation);
	holsterweapon();
	RemoveWeapons();
	*/
}

void AEL_SFMOUT::OutOfAmmoFadeIn()
{
	//ChangeState("OutOfAmmo");
}

void AEL_SFMOUT::OutOfTime()
{
	/*
	if (bCanRunOutOfAmmo)
	{
		PlayerLock(true, false);
		PlayTip("Soldier, you have failed to meet the minimun standards for this training exercise.", "You are a NO-GO.", 4);
		FadeOut(5, true);
		SetCustomTimer(5, false, "RestartLevel");
	}
	*/
}

void AEL_SFMOUT::PlayKeepMoving()
{
	//PlayGameSound("m_ls2", Player);
}

void AEL_SFMOUT::CheckPlayerMove()
{
	/*
	if ((Player.Location == PlayerLocation) && (Player.Rotation == PlayerRotation))
	{
		if (bHaveNotMoved)
		{
			ConsoleCommand("disconnect");
		}
		else
		{
			bHaveNotMoved = true;
			PlayKeepMoving();
		}
	}
	else
	{
		PlayerLocation = Player.Location;
		PlayerRotation = Player.Rotation;
		bHaveNotMoved = false;
	}
	SetCustomTimer(20, false, "CheckPlayerMove");
	*/
}

void AEL_SFMOUT::RestartLevel()
{
	//ConsoleCommand("Reconnect");
}

void AEL_SFMOUT::StartCountDown()
{
	//StartClock(0);
	//StartTimer("Pause", preTimerPause);
}

bool AEL_SFMOUT::DamageDetector_Damaged(ADamageDetector* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	ParseParms(Parms);
	switch (NotifyActor)
	{
	case damageDetector2:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector3:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector4:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector5:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector6:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector7:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	case damageDetector8:
		if (ParmList[2] == "AGP_Inventory.PickupT_M84_Stun")
		{
			RoomFlashed(NotifyActor);
		}
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

void AEL_SFMOUT::RoomFlashed(ADamageDetector* NotifyActor)
{
	/*
	PauseTimer("CountDown", 0);
	SetCustomTimer(FlashTimerDelay, false, "FlashedTime");
	*/
}

void AEL_SFMOUT::FlashedTime()
{
	//RestartTimer("CountDown", 0);
}

void AEL_SFMOUT::StartRoom()
{

}

bool AEL_SFMOUT::MarksmanTarget_Damaged(AMarksmanTarget* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	int32 targetVal = 0;
	ParseParms(Parms);
	if (NotifyActor.TargetType == 1)
	{
		if ((ParmList[1] == "A") && NotifyActor.bTriggered)
		{
			opforHit++;
			(opforHitScore += 400);
			targetA++;
			opforRunningCount++;
			NotifyActor.ResetTarget(true);
			UnCaptureEvent(NotifyActor);
		}
		else
		{
			if ((ParmList[1] == "B") && NotifyActor.bTriggered)
			{
				opforHit++;
				(opforHitScore += 300);
				targetB++;
				opforRunningCount++;
				NotifyActor.ResetTarget(true);
				UnCaptureEvent(NotifyActor);
			}
			else
			{
				if ((ParmList[1] == "C") && NotifyActor.bTriggered)
				{
					opforHit++;
					(opforHitScore += 200);
					targetC++;
					opforRunningCount++;
					NotifyActor.ResetTarget(true);
					UnCaptureEvent(NotifyActor);
				}
			}
		}
	}
	else
	{
		if (NotifyActor.bTriggered)
		{
			friendlyHit++;
			(friendlyHitScore -= 400);
			PlayGameSound("m_error", NotifyActor);
			NotifyActor.ResetTarget(true);
			UnCaptureEvent(NotifyActor);
		}
	}
	exitRedState(opforRunningCount);
	DebugLog(DEBUG_EventLab, "<<<<< ");
	DebugLog(DEBUG_EventLab, ">>>>> Target:" @ string(NotifyActor) @ "| Type:" @ string(NotifyActor.TargetType) @ "| Target Part:" @ ParmList[1]);
	DebugLog(DEBUG_EventLab, ">>>>> Value for this hit:" @ string(targetVal));
	DebugLog(DEBUG_EventLab, ">>>>> Total Target A:" @ string(targetA) @ "| Target B:" @ string(targetB) @ "| Target C:" @ string(targetC));
	DebugLog(DEBUG_EventLab, ">>>>> Enemy Hit:" @ string(opforHit) @ "| Friendly Hit:" @ string(friendlyHit));
	DebugLog(DEBUG_EventLab, ">>>>> Total Enemy Score:" @ string(opforHitScore) @ "| Friendly Score:" @ string(friendlyHitScore));
	DebugLog(DEBUG_EventLab, ">>>>> Enemy Running Count: " @ string(opforRunningCount));
	DebugLog(DEBUG_EventLab, ">>>>> Time Remaining Total: " @ string(timeKeeper));
	DebugLog(DEBUG_EventLab, "<<<<< ");
	*/
	return true;
}

bool AEL_SFMOUT::exitRedState(int32 opforNum)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_SFMOUT::aarScoreboard()
{
	/*
	int32 totalHouseTime = 0;
	timeOverall = GetClockTime();
	StopClock();
	roundsRemaining = (90 - roundsFired);
	Accuracy = (float(opforHit) / float(roundsFired));
	if ((Accuracy > 0.5) && (Accuracy <= 0.6))
	{
		accuracyScore = 200;
	}
	else
	{
		if ((Accuracy > 0.6) && (Accuracy <= 0.7))
		{
			accuracyScore = 400;
		}
		else
		{
			if ((Accuracy > 0.7) && (Accuracy <= 0.8))
			{
				accuracyScore = 600;
			}
			else
			{
				if ((Accuracy > 0.8) && (Accuracy <= 0.9))
				{
					accuracyScore = 800;
				}
				else
				{
					if ((Accuracy > 0.9) && (Accuracy < 1))
					{
						accuracyScore = 1000;
					}
					else
					{
						if (Accuracy == 1)
						{
							accuracyScore = 1500;
						}
						else
						{
							accuracyScore = 0;
						}
					}
				}
			}
		}
	}
	if (timeKeeper >= 7)
	{
		timeOverallScore = 1000;
	}
	else
	{
		if (timeKeeper >= 5)
		{
			timeOverallScore = 800;
		}
		else
		{
			if (timeKeeper >= 3.5)
			{
				timeOverallScore = 600;
			}
			else
			{
				if (timeKeeper >= 2)
				{
					timeOverallScore = 400;
				}
				else
				{
					if (timeKeeper >= 0.5)
					{
						timeOverallScore = 200;
					}
					else
					{
						timeOverallScore = 0;
					}
				}
			}
		}
	}
	totalHouseTime = GetClockSeconds();
	if (totalHouseTime <= 60)
	{
		(timeOverallScore *= 1.59);
	}
	else
	{
		if (totalHouseTime <= 75)
		{
			(timeOverallScore *= 1.48);
		}
		else
		{
			if (totalHouseTime <= 90)
			{
				(timeOverallScore *= 1.37);
			}
			else
			{
				if (totalHouseTime <= 105)
				{
					(timeOverallScore *= 1.26);
				}
				else
				{
					if (totalHouseTime <= 120)
					{
						(timeOverallScore *= 1.15);
					}
				}
			}
		}
	}
	if (friendlyHit == 0)
	{
		friendlyHitScore = 1000;
	}
	TotalScore = (((opforHitScore + friendlyHitScore) + accuracyScore) + timeOverallScore);
	if (TotalScore >= 10000)
	{
		finalGo = "X";
		finalNoGo = "";
	}
	else
	{
		finalNoGo = "X";
		finalGo = "";
	}
	aarDisplay.SetValue("aTotalScore", string(TotalScore));
	aarDisplay.SetValue("aUserName", UserName);
	aarDisplay.SetValue("aDateToday", dateToday);
	aarDisplay.SetValue("aOpforHit", string(opforHit));
	aarDisplay.SetValue("aFriendlyHit", string(friendlyHit));
	aarDisplay.SetValue("aOpforHitScore", string(opforHitScore));
	aarDisplay.SetValue("aFriendlyHitScore", string(friendlyHitScore));
	aarDisplay.SetValue("aRoundsFired", string(int((Accuracy * float(100)))) $ "%");
	aarDisplay.SetValue("aRoundsFiredScore", string(accuracyScore));
	aarDisplay.SetValue("aTimeOverall", timeOverall);
	aarDisplay.SetValue("aTimeOverallScore", string(timeOverallScore));
	aarDisplay.SetValue("aFinalGo", finalGo);
	aarDisplay.SetValue("aFinalNoGo", finalNoGo);
	*/
	return true;
}

bool AEL_SFMOUT::uploadStats()
{
	/*
	local Security secLocalSecurity;
	local class<Security>  scLocalSecurityClass;
	local TArray<FString> asMD5ForMap;
	local TArray<FString> asMD5ForScript;
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (StudentController(Controller).bUsedCheats)
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF", "Shoot House Complete", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageSFMOUT");
		return false;
	}
	Controller.ResetAuthExtraMissionData();
	Controller.AddAuthExtraMissionData(sWeaponAtCompletion);
	Controller.AddAuthExtraMissionData("" $ string(TotalScore));
	Controller.AddAuthExtraMissionData("" $ string(opforHit));
	Controller.AddAuthExtraMissionData("" $ string(friendlyHit));
	Controller.AddAuthExtraMissionData("" $ string(opforHitScore));
	Controller.AddAuthExtraMissionData("" $ string(friendlyHitScore));
	Controller.AddAuthExtraMissionData("" $ string(roundsFired));
	Controller.AddAuthExtraMissionData("" $ string(accuracyScore));
	Controller.AddAuthExtraMissionData("" $ timeOverall);
	Controller.AddAuthExtraMissionData("" $ string(timeOverallScore));
	if (finalGo == "X")
	{
		Controller.AddAuthExtraMissionData("1");
	}
	else
	{
		Controller.AddAuthExtraMissionData("0");
	}
	StudentController(Controller).SetAuthMissionPassFlag(true);
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != None)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != None)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/Shoothouse.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/AGP_Script.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData(sMD5ForMap);
	Controller.AddAuthExtraMissionData(sMD5ForScript);
	DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF", "Shoot House Complete", "Would you like to save your results to your Personnel Jacket?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageSFMOUT");
	*/
	return true;
}

void AEL_SFMOUT::DoWeapClearVO()
{
	/*
	SetCustomTimer(PlayGameSound("m_ls6", room9Sound), false, "UnlockPlayer");
	PlayerLock(true, false);
	*/
}

void AEL_SFMOUT::UnlockPlayer()
{
	//PlayerLock(false, false);
}
