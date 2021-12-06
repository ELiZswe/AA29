// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_SFMOUT/EL_SFMOUT.h"

AEL_SFMOUT::AEL_SFMOUT()
{

}

/*
State Briefing
{
	Function BeginState()
	{
		PlayGameSound('m_c0',Player);
		PlayerLock(true,false);
	}
	Function EndIntroVO()
	{
		if (! bIntroed)
		{
			PlayTip("Welcome to the MOUT Training Exercise.","See MAJ Amerine for your mission briefing.",5);
		}
		bIntroed=true;
		SetCustomTimer(40,false,'CheckPlayerMove');
		PlayerLock(false,false);
		skipVOTrigger.HUDText="";
		skipVOTrigger.bDisabled=true;
		cadreAAR.LoopAnim('DrillIdle');
		cadreFrago.LoopAnim('DrillIdle');
		cadreHistory.LoopAnim('DrillIdle');
	}
	Function bool skipVOTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Player.StopSound(GetGameSound('m_c0'));
		EndIntroVO();
		return true;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == 'm_c0')
		{
			EndIntroVO();
			return true;
		}
	}
}
State DoorBreacher
{
	Function BeginState()
	{
		breacherSpeech=true;
		if (! breacherSpeech)
		{
			PlayGameSound('m_ls1',room0Sound);
			PlayTip("Select and Employ the Door Breacher","to Gain Entry to the Shoot House",5);
			breacherSpeech=true;
		}
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger1.Close();
			doorTrigger1.bIsLocked=true;
			room1Target7=MarksmanTarget(CaptureEvent('room1Target7'));
			room1Target8=MarksmanTarget(CaptureEvent('room1Target8'));
			StartTimer('Target7',0.1);
			StartTimer('Target8',0.05);
			StartTimer('interrupt',2);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room1Timer1.SetValue('room1Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room1_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom1Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room1TimerDelay);
			}
			bFlashed=false;
			bRoom1Flipped=true;
			PlayGameSound('m_horn',room1Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room1Target1);
			room1Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room1Target2);
			room1Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room1Target3);
			room1Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room1Target4);
			room1Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room1Target5);
			room1Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room1Target6);
			room1Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room1Target7);
			room1Target7.TriggerSelf();
			return true;
			case 'Target8':
			PlayGameSound('m_hydraulic',room1Target8);
			room1Target8.TriggerSelf();
			return true;
			case 'interrupt':
			if (room1Target7.bTriggered)
			{
				PlayGameSound('m_hydraulic',room1Target7);
				room1Target7.ResetTarget(true);
				UnCaptureEvent(room1Target7);
			}
			if (room1Target8.bTriggered)
			{
				PlayGameSound('m_hydraulic',room1Target8);
				room1Target8.ResetTarget(true);
				UnCaptureEvent(room1Target8);
			}
			return true;
			case 'CountDown':
			ChangeState('Room1_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		StopCustomTimer('CheckPlayerMove');
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room1Target1=MarksmanTarget(CaptureEvent('room1Target1'));
		room1Target2=MarksmanTarget(CaptureEvent('room1Target2'));
		room1Target3=MarksmanTarget(CaptureEvent('room1Target3'));
		room1Target4=MarksmanTarget(CaptureEvent('room1Target4'));
		room1Target5=MarksmanTarget(CaptureEvent('room1Target5'));
		room1Target6=MarksmanTarget(CaptureEvent('room1Target6'));
		opforRunningCount=0;
		if (! bFlashed)
		{
			StartClock(0);
		}
		StartTimer('Pause',preTimerPause);
		bCanRunOutOfAmmo=true;
		TimeRemaining=Room1TimerDelay;
		SetCustomTimer((5 * float(60)),false,'OutOfTime');
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_ls5',room1Sound,,,0.99);
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			return true;
			case 'WhiteLight':
			room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == 'm_beep')
		{
			PlayGameSound('m_ls5',room1Sound,,,1);
			PlayTip("Room is cleared!","Move on to the Next Door!",5);
			return true;
		}
		else
		{
			if (Name == 'm_ls5')
			{
				PlayGameSound('m_klaxon',room1Sound,,,0.75);
				return true;
			}
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room1Sound);
		room1Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger2.Close();
			doorTrigger2.bIsLocked=true;
			room2Target6=MarksmanTarget(CaptureEvent('room2Target6'));
			room2Target7=MarksmanTarget(CaptureEvent('room2Target7'));
			StartTimer('Target6',0.1);
			StartTimer('Target7',0.05);
			StartTimer('interrupt',2.5);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room2Timer1.SetValue('room2Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room2_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom2Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room2TimerDelay);
			}
			bFlashed=false;
			bRoom2Flipped=true;
			PlayGameSound('m_horn',room2Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room2Target1);
			room2Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room2Target2);
			room2Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room2Target3);
			room2Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room2Target4);
			room2Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room2Target5);
			room2Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room2Target6);
			room2Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room2Target7);
			room2Target7.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room2Target6.bTriggered)
			{
				PlayGameSound('m_hydraulic',room2Target6);
				room2Target6.ResetTarget(true);
				UnCaptureEvent(room2Target6);
			}
			if (! room2Target7.bTriggered)
			{
				PlayGameSound('m_hydraulic',room2Target7);
				room2Target7.ResetTarget(true);
				UnCaptureEvent(room2Target7);
			}
			return true;
			case 'CountDown':
			ChangeState('Room2_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room2Target1=MarksmanTarget(CaptureEvent('room2Target1'));
		room2Target2=MarksmanTarget(CaptureEvent('room2Target2'));
		room2Target3=MarksmanTarget(CaptureEvent('room2Target3'));
		room2Target4=MarksmanTarget(CaptureEvent('room2Target4'));
		room2Target5=MarksmanTarget(CaptureEvent('room2Target5'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room2TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room2Sound);
			return true;
			case 'WhiteLight':
			room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room2Sound);
		room2Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger3.Close();
			doorTrigger3.bIsLocked=true;
			room3Target9=MarksmanTarget(CaptureEvent('room3Target9'));
			room3Target10=MarksmanTarget(CaptureEvent('room3Target10'));
			StartTimer('Target9',0.1);
			StartTimer('Target10',0.05);
			StartTimer('interrupt',1.75);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room3Timer1.SetValue('room3Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room3_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom3Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room3TimerDelay);
			}
			bFlashed=false;
			bRoom3Flipped=true;
			PlayGameSound('m_horn',room3Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
			StartTimer('Target7',(FRand() * TargetFlipModifier));
			StartTimer('Target8',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room3Target1);
			room3Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room3Target2);
			room3Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room3Target3);
			room3Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room3Target4);
			room3Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room3Target5);
			room3Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room3Target6);
			room3Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room3Target7);
			room3Target7.TriggerSelf();
			return true;
			case 'Target8':
			PlayGameSound('m_hydraulic',room3Target8);
			room3Target8.TriggerSelf();
			return true;
			case 'Target9':
			PlayGameSound('m_hydraulic',room3Target9);
			room3Target9.TriggerSelf();
			return true;
			case 'Target10':
			PlayGameSound('m_hydraulic',room3Target10);
			room3Target10.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room3Target9.bTriggered)
			{
				PlayGameSound('m_hydraulic',room3Target9);
				room3Target9.ResetTarget(true);
				UnCaptureEvent(room3Target9);
			}
			if (! room3Target10.bTriggered)
			{
				PlayGameSound('m_hydraulic',room3Target10);
				room3Target10.ResetTarget(true);
				UnCaptureEvent(room3Target10);
			}
			return true;
			case 'CountDown':
			ChangeState('Room3_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room3Target1=MarksmanTarget(CaptureEvent('room3Target1'));
		room3Target2=MarksmanTarget(CaptureEvent('room3Target2'));
		room3Target3=MarksmanTarget(CaptureEvent('room3Target3'));
		room3Target4=MarksmanTarget(CaptureEvent('room3Target4'));
		room3Target5=MarksmanTarget(CaptureEvent('room3Target5'));
		room3Target6=MarksmanTarget(CaptureEvent('room3Target6'));
		room3Target7=MarksmanTarget(CaptureEvent('room3Target7'));
		room3Target8=MarksmanTarget(CaptureEvent('room3Target8'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room3TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room3Sound);
			return true;
			case 'WhiteLight':
			room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room3Sound);
		room3Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger4.Close();
			doorTrigger4.bIsLocked=true;
			room4Target7=MarksmanTarget(CaptureEvent('room4Target7'));
			room4Target8=MarksmanTarget(CaptureEvent('room4Target8'));
			StartTimer('Target7',0.1);
			StartTimer('Target8',0.05);
			StartTimer('interrupt',2);
			interrupt=true;
		}
		return true;
	}
	Function bool room4Trigger4_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! interrupt2)
		{
			room4Target9=MarksmanTarget(CaptureEvent('room4Target9'));
			StartTimer('Target9',0.1);
			StartTimer('interrupt',1.5);
			interrupt2=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room4Timer1.SetValue('room4Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room4_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom4Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room4TimerDelay);
			}
			bFlashed=false;
			bRoom4Flipped=true;
			PlayGameSound('m_horn',room4Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room4Target1);
			room4Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room4Target2);
			room4Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room4Target3);
			room4Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room4Target4);
			room4Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room4Target5);
			room4Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room4Target6);
			room4Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room4Target7);
			room4Target7.TriggerSelf();
			return true;
			case 'Target8':
			PlayGameSound('m_hydraulic',room4Target8);
			room4Target8.TriggerSelf();
			return true;
			case 'Target9':
			PlayGameSound('m_hydraulic',room4Target9);
			room4Target9.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room4Target7.bTriggered)
			{
				PlayGameSound('m_hydraulic',room4Target7);
				room4Target7.ResetTarget(true);
				UnCaptureEvent(room4Target7);
			}
			if (! room4Target8.bTriggered)
			{
				PlayGameSound('m_hydraulic',room4Target8);
				room4Target8.ResetTarget(true);
				UnCaptureEvent(room4Target8);
			}
			if (! room4Target9.bTriggered)
			{
				PlayGameSound('m_hydraulic',room4Target9);
				room4Target9.ResetTarget(true);
				UnCaptureEvent(room4Target9);
			}
			return true;
			case 'CountDown':
			ChangeState('Room4_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room4Target1=MarksmanTarget(CaptureEvent('room4Target1'));
		room4Target2=MarksmanTarget(CaptureEvent('room4Target2'));
		room4Target3=MarksmanTarget(CaptureEvent('room4Target3'));
		room4Target4=MarksmanTarget(CaptureEvent('room4Target4'));
		room4Target5=MarksmanTarget(CaptureEvent('room4Target5'));
		room4Target6=MarksmanTarget(CaptureEvent('room4Target6'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room4TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room3Sound);
			return true;
			case 'WhiteLight':
			room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room3Sound);
		room4Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger5.Close();
			doorTrigger5.bIsLocked=true;
			room5Target6=MarksmanTarget(CaptureEvent('room5Target6'));
			StartTimer('Target6',0.1);
			StartTimer('interrupt',2);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room5Timer1.SetValue('room5Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room5_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom5Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room5TimerDelay);
			}
			bFlashed=false;
			bRoom5Flipped=true;
			PlayGameSound('m_horn',room5Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room5Target1);
			room5Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room5Target2);
			room5Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room5Target3);
			room5Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room5Target4);
			room5Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room5Target5);
			room5Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room5Target6);
			room5Target6.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room5Target6.bTriggered)
			{
				PlayGameSound('m_hydraulic',room5Target6);
				room5Target6.ResetTarget(true);
				UnCaptureEvent(room5Target6);
			}
			return true;
			case 'CountDown':
			ChangeState('Room5_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room5Target1=MarksmanTarget(CaptureEvent('room5Target1'));
		room5Target2=MarksmanTarget(CaptureEvent('room5Target2'));
		room5Target3=MarksmanTarget(CaptureEvent('room5Target3'));
		room5Target4=MarksmanTarget(CaptureEvent('room5Target4'));
		room5Target5=MarksmanTarget(CaptureEvent('room5Target5'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room5TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room5Sound);
			return true;
			case 'WhiteLight':
			room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room5Sound);
		room5Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room6Timer1.SetValue('room6Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room6_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom6Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room6TimerDelay);
			}
			bFlashed=false;
			bRoom6Flipped=true;
			PlayGameSound('m_horn',room6Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
			StartTimer('Target7',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room6Target1);
			room6Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room6Target2);
			room6Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room6Target3);
			room6Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room6Target4);
			room6Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room6Target5);
			room6Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room6Target6);
			room6Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room6Target7);
			room6Target7.TriggerSelf();
			return true;
			case 'CountDown':
			ChangeState('Room6_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room6Target1=MarksmanTarget(CaptureEvent('room6Target1'));
		room6Target2=MarksmanTarget(CaptureEvent('room6Target2'));
		room6Target3=MarksmanTarget(CaptureEvent('room6Target3'));
		room6Target4=MarksmanTarget(CaptureEvent('room6Target4'));
		room6Target5=MarksmanTarget(CaptureEvent('room6Target5'));
		room6Target6=MarksmanTarget(CaptureEvent('room6Target6'));
		room6Target7=MarksmanTarget(CaptureEvent('room6Target7'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room6TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room6Sound);
			return true;
			case 'WhiteLight':
			room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room6Sound);
		room6Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room7Timer1.SetValue('room7Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 4)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room7_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom7Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room7TimerDelay);
			}
			bFlashed=false;
			bRoom7Flipped=true;
			PlayGameSound('m_horn',room7Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
			StartTimer('Target7',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room7Target1);
			room7Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room7Target2);
			room7Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room7Target3);
			room7Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room7Target4);
			room7Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room7Target5);
			room7Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room7Target6);
			room7Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room7Target7);
			room7Target7.TriggerSelf();
			return true;
			case 'CountDown':
			ChangeState('Room7_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room7Target1=MarksmanTarget(CaptureEvent('room7Target1'));
		room7Target2=MarksmanTarget(CaptureEvent('room7Target2'));
		room7Target3=MarksmanTarget(CaptureEvent('room7Target3'));
		room7Target4=MarksmanTarget(CaptureEvent('room7Target4'));
		room7Target5=MarksmanTarget(CaptureEvent('room7Target5'));
		room7Target6=MarksmanTarget(CaptureEvent('room7Target6'));
		room7Target7=MarksmanTarget(CaptureEvent('room7Target7'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room7TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room7Sound);
			return true;
			case 'WhiteLight':
			room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room7Sound);
		room7Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			doorTrigger8.Close();
			doorTrigger8.bIsLocked=true;
			room8Target7=MarksmanTarget(CaptureEvent('room8Target7'));
			room8Target8=MarksmanTarget(CaptureEvent('room8Target8'));
			StartTimer('Target7',0.1);
			StartTimer('Target8',0.05);
			StartTimer('interrupt',3);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room8Timer1.SetValue('room8Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 5)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room8_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom8Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room8TimerDelay);
			}
			bFlashed=false;
			bRoom8Flipped=true;
			PlayGameSound('m_horn',room8Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room8Target1);
			room8Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room8Target2);
			room8Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room8Target3);
			room8Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room8Target4);
			room8Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room8Target5);
			room8Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room8Target6);
			room8Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room8Target7);
			room8Target7.TriggerSelf();
			return true;
			case 'Target8':
			PlayGameSound('m_hydraulic',room8Target8);
			room8Target8.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room8Target7.bTriggered)
			{
				PlayGameSound('m_hydraulic',room8Target7);
				room8Target7.ResetTarget(true);
				UnCaptureEvent(room8Target7);
			}
			if (! room8Target8.bTriggered)
			{
				PlayGameSound('m_hydraulic',room8Target8);
				room8Target8.ResetTarget(true);
				UnCaptureEvent(room8Target8);
			}
			return true;
			case 'CountDown':
			ChangeState('Room8_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room8Target1=MarksmanTarget(CaptureEvent('room8Target1'));
		room8Target2=MarksmanTarget(CaptureEvent('room8Target2'));
		room8Target3=MarksmanTarget(CaptureEvent('room8Target3'));
		room8Target4=MarksmanTarget(CaptureEvent('room8Target4'));
		room8Target5=MarksmanTarget(CaptureEvent('room8Target5'));
		room8Target6=MarksmanTarget(CaptureEvent('room8Target6'));
		room8Target7=MarksmanTarget(CaptureEvent('room8Target7'));
		room8Target8=MarksmanTarget(CaptureEvent('room8Target8'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room8TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room8Sound);
			return true;
			case 'WhiteLight':
			room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		PlayGameSound('m_beep',room8Sound);
		room8Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
	}
}
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
			PlayGameSound('m_switch',Player);
			room9Target9=MarksmanTarget(CaptureEvent('room9Target9'));
			room9Target10=MarksmanTarget(CaptureEvent('room9Target10'));
			StartTimer('Target9',0.1);
			StartTimer('Target10',0.05);
			StartTimer('interrupt',1.75);
			interrupt=true;
		}
		return true;
	}
	Function EventLabTick(float DeltaTime)
	{
		newTimer=FormatTime(QueryTimer('CountDown'),true,true);
		newTimer=Right(newTimer,(Len(newTimer) - 1));
		if (QueryTimer('CountDown') != 0)
		{
			TimeRemaining=QueryTimer('CountDown');
		}
		room9Timer1.SetValue('room9Digits',newTimer);
	}
	Function bool exitRedState(int32 opforNum)
	{
		if (opforNum >= 6)
		{
			PlayGameSound('m_p0',Player);
			StopTimer('CountDown',0);
			(timeKeeper += TimeRemaining);
			ChangeState('Room9_Green');
		}
		return true;
	}
	Function flipTargets()
	{
		if (! bRoom9Flipped)
		{
			if (! bFlashed)
			{
				StartTimer('CountDown',Room9TimerDelay);
			}
			bFlashed=false;
			bRoom9Flipped=true;
			PlayGameSound('m_horn',room9Sound);
			StartTimer('Target1',(FRand() * TargetFlipModifier));
			StartTimer('target2',(FRand() * TargetFlipModifier));
			StartTimer('Target3',(FRand() * TargetFlipModifier));
			StartTimer('Target4',(FRand() * TargetFlipModifier));
			StartTimer('Target5',(FRand() * TargetFlipModifier));
			StartTimer('Target6',(FRand() * TargetFlipModifier));
			StartTimer('Target7',(FRand() * TargetFlipModifier));
			StartTimer('Target8',(FRand() * TargetFlipModifier));
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Target1':
			PlayGameSound('m_hydraulic',room9Target1);
			room9Target1.TriggerSelf();
			return true;
			case 'target2':
			PlayGameSound('m_hydraulic',room9Target2);
			room9Target2.TriggerSelf();
			return true;
			case 'Target3':
			PlayGameSound('m_hydraulic',room9Target3);
			room9Target3.TriggerSelf();
			return true;
			case 'Target4':
			PlayGameSound('m_hydraulic',room9Target4);
			room9Target4.TriggerSelf();
			return true;
			case 'Target5':
			PlayGameSound('m_hydraulic',room9Target5);
			room9Target5.TriggerSelf();
			return true;
			case 'Target6':
			PlayGameSound('m_hydraulic',room9Target6);
			room9Target6.TriggerSelf();
			return true;
			case 'Target7':
			PlayGameSound('m_hydraulic',room9Target7);
			room9Target7.TriggerSelf();
			return true;
			case 'Target8':
			PlayGameSound('m_hydraulic',room9Target8);
			room9Target8.TriggerSelf();
			return true;
			case 'Target9':
			PlayGameSound('m_hydraulic',room9Target9);
			room9Target9.TriggerSelf();
			return true;
			case 'Target10':
			PlayGameSound('m_hydraulic',room9Target10);
			room9Target10.TriggerSelf();
			return true;
			case 'interrupt':
			if (! room9Target9.bTriggered)
			{
				PlayGameSound('m_hydraulic',room9Target9);
				room9Target9.ResetTarget(true);
				UnCaptureEvent(room9Target9);
			}
			if (! room9Target10.bTriggered)
			{
				PlayGameSound('m_hydraulic',room9Target10);
				room9Target10.ResetTarget(true);
				UnCaptureEvent(room9Target10);
			}
			aarScoreboard();
			return true;
			case 'CountDown':
			ChangeState('Room9_Green');
			return true;
			case 'Pause':
			flipTargets();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'PlayKeepMoving');
		room9Target1=MarksmanTarget(CaptureEvent('room9Target1'));
		room9Target2=MarksmanTarget(CaptureEvent('room9Target2'));
		room9Target3=MarksmanTarget(CaptureEvent('room9Target3'));
		room9Target4=MarksmanTarget(CaptureEvent('room9Target4'));
		room9Target5=MarksmanTarget(CaptureEvent('room9Target5'));
		room9Target6=MarksmanTarget(CaptureEvent('room9Target6'));
		room9Target7=MarksmanTarget(CaptureEvent('room9Target7'));
		room9Target8=MarksmanTarget(CaptureEvent('room9Target8'));
		opforRunningCount=0;
		StartTimer('Pause',preTimerPause);
		TimeRemaining=Room9TimerDelay;
		interrupt=false;
	}
	Event EndState()
	{
		StopTimer('Pause',0);
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
		SetCustomTimer((keepMovingIdleTime * 2),false,'JumpToAAR');
		StopCustomTimer('OutOfTime');
		PlayGameSound('m_beep',room9Sound);
		room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
		StartTimer('WhiteLight',0.5);
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
			ChangeState('EndSH');
			bNoSecurityViolation=false;
		}
		return true;
	}
}
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
			case 'AllClear':
			PlayGameSound('m_klaxon',room9Sound);
			return true;
			case 'WhiteLight':
			room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx2_cor_05';
			StartTimer('RedLight',0.75);
			return true;
			case 'RedLight':
			room9Light1.Skins[0]=Texture'T_AA2_FX.Corona.fx_cor_red';
			StartTimer('WhiteLight',0.5);
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_Sound(FName Name)
	{
		switch(Name)
		{
			case 'm_beep':
			PlayTip("Room is cleared!","Move on to the Next Door!",3);
			StartTimer('AllClear',3);
			return true;
			case 'm_ls6':
			PlayerLock(false,false);
			return true;
			default:
		}
	}
	Function BeginState()
	{
		SetCustomTimer(1,false,'Ammoish');
	}
}
State OutOfAmmo
{
	Function BeginState()
	{
		StopCustomTimer('PlayKeepMoving');
		Player.SetLocation(aarLocation.Location);
		Player.Controller.SetRotation(aarLocation.Rotation);
		FadeInBlack(float(AmmoFadeTime));
		holsterweapon();
		RemoveWeapons();
		PlayTip("Soldier, You've expended your ammo prior to completing your training","You've failed to meet the minimum standard.",5);
		PlayerLock(true,true);
		PlayLSAnim('m_aar15',cadreAAR,1,512,,aarReportDelay);
		cadreUseTrigger3.bActive=false;
		cadreUseTrigger3.HUDText="";
	}
	Function PlayNoGo()
	{
		PlayLSAnim('m_aar14',cadreAAR,1,512,,aarReportDelay);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'm_aar15':
			case 'm_aar14':
			uploadStats();
			return true;
			default:
		}
	}
}
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
		ChangeState('AAR');
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
State AAR
{
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'aar0':
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
			case 'm_aar0':
			case 'm_aar1':
			case 'm_aar2':
			case 'm_aar17':
			case 'm_aar18':
			aarFriendlyHit();
			return true;
			case 'm_aar3':
			case 'm_aar4':
			case 'm_aar5':
			case 'm_aar19':
			aarAmmo();
			return true;
			case 'm_aar6':
			case 'm_aar7':
			case 'm_aar8':
			case 'm_aar20':
			aarTime();
			return true;
			case 'm_aar9':
			case 'm_aar10':
			case 'm_aar11':
			case 'm_aar21':
			aarTotalScore();
			return true;
			case 'm_aar12':
			case 'm_aar13':
			case 'm_aar14':
			case 'm_aar22':
			EndOfAAR();
			return true;
			default:
		}
	}
	Function bool aarOpforHit()
	{
		if (opforHit >= 46)
		{
			aarAnimName='m_aar17';
		}
		else
		{
			if (opforHit >= 40)
			{
				aarAnimName='m_aar0';
			}
			else
			{
				if (opforHit >= 30)
				{
					aarAnimName='m_aar1';
				}
				else
				{
					if (opforHit >= 20)
					{
						aarAnimName='m_aar2';
					}
					else
					{
						aarAnimName='m_aar18';
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
			aarAnimName='m_aar19';
		}
		else
		{
			if (friendlyHit >= 3)
			{
				aarAnimName='m_aar3';
			}
			else
			{
				if (friendlyHit >= 1)
				{
					aarAnimName='m_aar4';
				}
				else
				{
					aarAnimName='m_aar5';
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
			aarAnimName='m_aar20';
		}
		else
		{
			if (Accuracy >= 0.85)
			{
				aarAnimName='m_aar6';
			}
			else
			{
				if (Accuracy >= 0.6)
				{
					aarAnimName='m_aar7';
				}
				else
				{
					aarAnimName='m_aar8';
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
			aarAnimName='m_aar21';
		}
		else
		{
			if (totalHouseTime > 115)
			{
				aarAnimName='m_aar9';
			}
			else
			{
				if (totalHouseTime > 95)
				{
					aarAnimName='m_aar10';
				}
				else
				{
					aarAnimName='m_aar11';
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
			aarAnimName='m_aar12';
		}
		else
		{
			if (TotalScore >= 15000)
			{
				aarAnimName='m_aar22';
			}
			else
			{
				if (TotalScore >= 10000)
				{
					aarAnimName='m_aar13';
				}
				else
				{
					aarAnimName='m_aar14';
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
		ChangeState('EndSH');
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR.StopLIPSincAnim();
		}
		aarAnimName='m_aar16';
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		return true;
	}
	Function EndOfAAR()
	{
		ChangeState('EndSH');
	}
	Function BeginState()
	{
		StopCustomTimer('PlayKeepMoving');
		cadreUseTrigger3.HUDText="Skip AAR";
		Controller.LockPlayer(true,true);
		doorTrigger9.Close();
		doorTrigger9.bIsLocked=true;
		StartTimer('aar0',1);
	}
	Function EndState()
	{
		PlayTip("Examine Scoreboard and review your","results to complete this training.",3);
		Controller.LockPlayer(false,false);
		cadreUseTrigger3.HUDText=cadreUseTipAAR;
	}
}
*/
