// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_ES2McKenna/EL_ES2McKenna.h"

AEL_ES2McKenna::AEL_ES2McKenna()
{

}

/*
State Briefing
{
	Function BeginState()
	{
		if (! bIntroed)
		{
			PlayGameSound('VoiceGuy_IntroMessage01',Player);
			PlayerLock(true,false);
		}
	}
	Function bool StartGateVO_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if ((! courseEntered) && PlayerHasWeapon(Pawn(Instigator)))
		{
			PlayGameSound('VoiceGuy_StartGate',Player);
			StartGateVO.DisableTrigger();
		}
		return true;
	}
	Function EndIntroVO()
	{
		if (! bIntroed)
		{
			PlayTip("Welcome to the ES2 Training Exercise.","See your Instructor for your mission briefing.",5);
		}
		bIntroed=true;
		SetCustomTimer(40,false,'CheckPlayerMove');
		PlayerLock(false,false);
		skipVOTrigger.HUDText="";
		skipVOTrigger.bDisabled=true;
		cadreAAR.LoopAnim('DrillIdle');
		cadreInstructor.LoopAnim('DrillIdle');
	}
	Function FinishCadreVO()
	{
		SetCustomTimer(20,false,'CheckPlayerMove');
		cadreUseTrigger1.bDisabled=false;
		cadreUseTrigger2.bDisabled=false;
		cadreUseTrigger1.HUDText=cadreUseTip1;
		cadreUseTrigger2.HUDText=cadreUseTip2;
		PlayerLock(false,false);
	}
	Function DoIntroLSVO(Pawn Target, FName LSAnim)
	{
		StopCustomTimer('CheckPlayerMove');
		PlayLSAnim(LSAnim,Target,1,512);
		PlayerLock(true,true);
		cadreUseTrigger1.bDisabled=false;
		cadreUseTrigger2.bDisabled=false;
		cadreUseTrigger1.HUDText="Skip Dialog";
		cadreUseTrigger2.HUDText="Skip Dialog";
	}
	Function bool cadreUseTrigger1_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR.StopLIPSincAnim();
		}
		ChangeState('Instructions');
		return true;
	}
	Function bool cadreUseTrigger2_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (cadreInstructor.IsPlayingLIPSincAnim())
		{
			cadreInstructor.StopLIPSincAnim();
		}
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR.StopLIPSincAnim();
			FinishCadreVO();
		}
		else
		{
			DoIntroLSVO(cadreAAR,'AARGuy_NotCompleted');
		}
		return true;
	}
	Function bool skipVOTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Player.StopSound(GetGameSound('VoiceGuy_IntroMessage01'));
		EndIntroVO();
		return true;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == 'VoiceGuy_IntroMessage01')
		{
			EndIntroVO();
			return true;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'AARGuy_NotCompleted':
			FinishCadreVO();
			return true;
			default:
		}
	}
}
State Instructions
{
	Function bool cadreUseTrigger1_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (cadreInstructor.IsPlayingLIPSincAnim())
		{
			cadreInstructor.StopLIPSincAnim();
		}
		cadreUseTrigger1.HUDText=cadreUseTip1;
		ChangeState('Briefing');
		return true;
	}
	Function BeginState()
	{
		Log("I'm in Instructions BeginState()");
		cadreUseTrigger1.HUDText="Skip Dialog";
		Controller.LockPlayer(true,true);
		InstructorAnimNum=2;
		StopCustomTimer('CheckPlayerMove');
		PlayLSAnim('Instruction_02',cadreInstructor,1,512,,0.5);
	}
	Function NextInstructionVO()
	{
		FName instructionName = "";
		switch(InstructorAnimNum)
		{
			case 2:
			instructionName='Instruction_03';
			break;
			case 3:
			instructionName='Instruction_04';
			StartTimer('ShowReportDialog',6);
			StartTimer('ShowUseDialog',20);
			break;
			case 4:
			instructionName='Instruction_05';
			break;
			case 5:
			instructionName='Instruction_06';
			break;
			default:
		}
		PlayLSAnim(instructionName,cadreInstructor,1,512);
		InstructorAnimNum ++;
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'ShowReportDialog':
			PlayTip("To report an object: ","Press the (<ESSObjectiveReport>) Key",5);
			return true;
			case 'ShowUseDialog':
			PlayTip("To use an object: ","Press the (<Action>) Key",5);
			return true;
			default:
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'Instruction_01':
			case 'Instruction_02':
			case 'Instruction_03':
			case 'Instruction_04':
			case 'Instruction_05':
			NextInstructionVO();
			return true;
			case 'Instruction_06':
			ChangeState('Briefing');
			cadreUseTrigger1.HUDText=cadreUseTip1;
			return true;
			default:
		}
	}
	Function EndState()
	{
		SetCustomTimer(20,false,'CheckPlayerMove');
		Controller.LockPlayer(false,false);
	}
}
State AAR
{
	Function BeginState()
	{
		Log("Do AAR Stuff now plz.");
	}
	Function bool cadreUseTrigger2_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState('AARBriefing');
		return true;
	}
	Function bool sbUseTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		Log("TODO: Get uploadStats stuff");
		uploadStats();
		return true;
	}
}
State AARBriefing
{
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'aarStart':
			aarES2ObjectsFound();
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'AARGuy_ES2Bad':
			case 'AARGuy_ES2Good':
			case 'AARGuy_ES2Okay':
			aarOpforHit();
			return true;
			case 'AARGuy_SkillSummeryBad':
			case 'AARGuy_SkillSummeryGood':
			case 'AARGuy_SkillSummeryGreat':
			case 'AARGuy_SkillSummeryOkay':
			aarFriendlyHit();
			return true;
			case 'AARGuy_FFSummaryBad':
			case 'AARGuy_FFSummaryGood':
			case 'AARGuy_FFSummaryOkay':
			aarAmmo();
			return true;
			case 'AARGuy_AccuracyBad':
			case 'AARGuy_AccuracyGood':
			case 'AARGuy_AccuracyGreat':
			case 'AARGuy_AccuracyOkay':
			aarTime();
			return true;
			case 'AARGuy_SpeedBad':
			case 'AARGuy_SpeedGood':
			case 'AARGuy_SpeedGreat':
			case 'AARGuy_SpeedOkay':
			aarTotalScore();
			return true;
			case 'AARGuy_GoGo':
			case 'AARGuy_GoNoGoScore':
			case 'AARGuy_GoSoftGo':
			EndOfAAR();
			return true;
			default:
		}
	}
	Function bool aarES2ObjectsFound()
	{
		if (ES2objectsFound > 11)
		{
			aarAnimName='AARGuy_ES2Good';
		}
		else
		{
			if (ES2objectsFound >= 3)
			{
				aarAnimName='AARGuy_ES2Okay';
			}
			else
			{
				aarAnimName='AARGuy_ES2Bad';
			}
		}
		DebugLog(DEBUG_EventLab,"aarOpforHit:" $ string(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total ES2 Objects Found:" @ string(ES2objectsFound),"ES2 Found Score:" @ string(ES2Score),7);
		return true;
	}
	Function bool aarOpforHit()
	{
		if (opforHit >= 40)
		{
			aarAnimName='AARGuy_SkillSummeryGreat';
		}
		else
		{
			if (opforHit >= 25)
			{
				aarAnimName='AARGuy_SkillSummeryGood';
			}
			else
			{
				if (opforHit >= 10)
				{
					aarAnimName='AARGuy_SkillSummeryOkay';
				}
				else
				{
					aarAnimName='AARGuy_SkillSummeryBad';
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
		if (friendlyHit >= 3)
		{
			aarAnimName='AARGuy_FFSummaryBad';
		}
		else
		{
			if (friendlyHit >= 1)
			{
				aarAnimName='AARGuy_FFSummaryOkay';
			}
			else
			{
				aarAnimName='AARGuy_FFSummaryGood';
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
			aarAnimName='AARGuy_AccuracyGreat';
		}
		else
		{
			if (Accuracy >= 0.85)
			{
				aarAnimName='AARGuy_AccuracyGood';
			}
			else
			{
				if (Accuracy >= 0.6)
				{
					aarAnimName='AARGuy_AccuracyOkay';
				}
				else
				{
					aarAnimName='AARGuy_AccuracyBad';
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
		totalHouseTime=(600 - GetClockSeconds());
		if (totalHouseTime > 420)
		{
			aarAnimName='AARGuy_SpeedBad';
		}
		else
		{
			if (totalHouseTime > 300)
			{
				aarAnimName='AARGuy_SpeedOkay';
			}
			else
			{
				if (totalHouseTime > 150)
				{
					aarAnimName='AARGuy_SpeedGood';
				}
				else
				{
					aarAnimName='AARGuy_SpeedGreat';
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarTime:" $ string(aarAnimName));
		Log("aarTime: " @ string(totalHouseTime));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total Time to Complete Training:" @ timeOverall,"Speed Bonus Score:" @ string(timeOverallScore),7);
		return true;
	}
	Function bool aarTotalScore()
	{
		if (TotalScore >= 15000)
		{
			aarAnimName='AARGuy_GoGo';
		}
		else
		{
			if (TotalScore >= 10000)
			{
				aarAnimName='AARGuy_GoSoftGo';
			}
			else
			{
				aarAnimName='AARGuy_GoNoGoScore';
			}
		}
		if (finalGo == "X")
		{
			PlayTip("Total Overall Score:" @ string(TotalScore),"You are a GO at this training",7);
		}
		else
		{
			PlayTip("Total Overall Score:" @ string(TotalScore),"You are a NO-GO at this training",7);
		}
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		return true;
	}
	Function bool cadreUseTrigger2_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		ChangeState('AAR');
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR.StopLIPSincAnim();
		}
		return true;
	}
	Function EndOfAAR()
	{
		ChangeState('AAR');
	}
	Function BeginState()
	{
		StopCustomTimer('CheckPlayerMove');
		cadreUseTrigger2.HUDText="Skip AAR";
		Controller.LockPlayer(true,true);
		StartTimer('aarStart',1);
	}
	Function EndState()
	{
		PlayTip("Examine Scoreboard and review your","results to complete this training.",3);
		Controller.LockPlayer(false,false);
		cadreUseTrigger2.HUDText=cadreUseTipAAR;
	}
}
State OutOfAmmo
{
	Function BeginState()
	{
		StopCustomTimer('CheckPlayerMove');
		Player.SetLocation(aarLocation.Location);
		Player.Controller.SetRotation(aarLocation.Rotation);
		FadeInBlack(float(AmmoFadeTime));
		holsterweapon();
		RemoveWeapons();
		PlayTip("Soldier, You've expended your ammo prior to completing your training","You've failed to meet the minimum standard.",5);
		PlayerLock(true,true);
		PlayLSAnim('AARGuy_GoNoGoAmmo',cadreAAR,1,512,,aarReportDelay);
		cadreUseTrigger2.bActive=false;
		cadreUseTrigger2.HUDText="";
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'AARGuy_GoNoGoAmmo':
			uploadStats();
			return true;
			default:
		}
	}
}
State building1Active
{
	Function bool Building1MT_Trigger02AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building1M06Target1=MarksmanTarget(CaptureEvent('Building1Marker06Target01'));
		building1M06Target2=MarksmanTarget(CaptureEvent('Building1Marker06Target02'));
		building1M07Target1=MarksmanTarget(CaptureEvent('Building1Marker07Target01'));
		building1M07Target2=MarksmanTarget(CaptureEvent('Building1Marker07Target02'));
		building1M07Target3=MarksmanTarget(CaptureEvent('Building1Marker07Target03'));
		building1M07Target4=MarksmanTarget(CaptureEvent('Building1Marker07Target04'));
		building1M07Target5=MarksmanTarget(CaptureEvent('Building1Marker07Target05'));
		building1M07Target6=MarksmanTarget(CaptureEvent('Building1Marker07Target06'));
		StartTimer('room1Target1',(FRand() * TargetFlipModifier));
		StartTimer('room1Target2',(FRand() * TargetFlipModifier));
		StartTimer('room1Target3',(FRand() * TargetFlipModifier));
		StartTimer('room1Target4',(FRand() * TargetFlipModifier));
		StartTimer('room1Target5',(FRand() * TargetFlipModifier));
		StartTimer('room1Target6',(FRand() * TargetFlipModifier));
		StartTimer('room1Target7',(FRand() * TargetFlipModifier));
		StartTimer('room1Target8',(FRand() * TargetFlipModifier));
		StartTimer('room1Reset',4);
		building1MTTrigger01.DisableTrigger();
		UnCaptureEvent(building1MTTrigger01);
		return true;
	}
	Function bool Building1MT_Trigger06AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('room2Target1',(FRand() * TargetFlipModifier));
		StartTimer('room2Target2',(FRand() * TargetFlipModifier));
		StartTimer('room2Target3',(FRand() * TargetFlipModifier));
		StartTimer('room2Target4',(FRand() * TargetFlipModifier));
		StartTimer('room2Target5',(FRand() * TargetFlipModifier));
		StartTimer('room2Target6',(FRand() * TargetFlipModifier));
		StartTimer('room2Reset',4);
		building1MTTrigger03.DisableTrigger();
		UnCaptureEvent(building1MTTrigger03);
		return true;
	}
	Function bool Building1MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		flipDoor1Targets();
		return true;
	}
	Function flipDoor1Targets()
	{
		if (! bbuilding1Door1Flipped)
		{
			bbuilding1Door1Flipped=true;
			StartTimer('Door1Target1',(FRand() * TargetFlipModifier));
			StartTimer('Door1Target2',(FRand() * TargetFlipModifier));
			StartTimer('Door1Target3',(FRand() * TargetFlipModifier));
			StartTimer('Door1Target4',(FRand() * TargetFlipModifier));
			StartTimer('Door1Target5',(FRand() * TargetFlipModifier));
			StartTimer('Door1Target6',(FRand() * TargetFlipModifier));
			StartTimer('door1Reset',4);
		}
	}
	Function flipDoor2Targets()
	{
		if (! bbuilding1Door2Flipped)
		{
			bbuilding1Door2Flipped=true;
			StartTimer('Door2Target1',(FRand() * TargetFlipModifier));
			StartTimer('Door2Target2',(FRand() * TargetFlipModifier));
			StartTimer('Door2Target3',(FRand() * TargetFlipModifier));
			StartTimer('Door2Target4',(FRand() * TargetFlipModifier));
			StartTimer('Door2Target5',(FRand() * TargetFlipModifier));
			StartTimer('door2Reset',4);
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Door1Target1':
			PlayGameSound('m_hydraulic',building1M01Target1);
			building1M01Target1.TriggerSelf();
			return true;
			case 'Door1Target2':
			PlayGameSound('m_hydraulic',building1M01Target2);
			building1M01Target2.TriggerSelf();
			return true;
			case 'Door1Target3':
			PlayGameSound('m_hydraulic',building1M01Target3);
			building1M01Target3.TriggerSelf();
			return true;
			case 'Door1Target4':
			PlayGameSound('m_hydraulic',building1M02Target1);
			building1M02Target1.TriggerSelf();
			return true;
			case 'Door1Target5':
			PlayGameSound('m_hydraulic',building1M02Target2);
			building1M02Target2.TriggerSelf();
			return true;
			case 'Door1Target6':
			PlayGameSound('m_hydraulic',building1M03Target1);
			building1M03Target1.TriggerSelf();
			return true;
			case 'Door2Target1':
			PlayGameSound('m_hydraulic',building1M01Target1);
			building1M01Target1.TriggerSelf();
			return true;
			case 'Door2Target2':
			PlayGameSound('m_hydraulic',building1M04Target2);
			building1M04Target2.TriggerSelf();
			return true;
			case 'Door2Target3':
			PlayGameSound('m_hydraulic',building1M04Target3);
			building1M04Target3.TriggerSelf();
			return true;
			case 'Door2Target4':
			PlayGameSound('m_hydraulic',building1M05Target1);
			building1M05Target1.TriggerSelf();
			return true;
			case 'Door2Target5':
			PlayGameSound('m_hydraulic',building1M05Target2);
			building1M05Target2.TriggerSelf();
			return true;
			case 'room1Target1':
			PlayGameSound('m_hydraulic',building1M06Target1);
			building1M06Target1.TriggerSelf();
			return true;
			case 'room1Target2':
			PlayGameSound('m_hydraulic',building1M06Target2);
			building1M06Target2.TriggerSelf();
			return true;
			case 'room1Target3':
			PlayGameSound('m_hydraulic',building1M07Target1);
			building1M07Target1.TriggerSelf();
			return true;
			case 'room1Target4':
			PlayGameSound('m_hydraulic',building1M07Target2);
			building1M07Target2.TriggerSelf();
			return true;
			case 'room1Target5':
			PlayGameSound('m_hydraulic',building1M07Target3);
			building1M07Target3.TriggerSelf();
			case 'room1Target6':
			PlayGameSound('m_hydraulic',building1M07Target4);
			building1M07Target4.TriggerSelf();
			return true;
			case 'room1Target7':
			PlayGameSound('m_hydraulic',building1M07Target5);
			building1M07Target5.TriggerSelf();
			return true;
			case 'room1Target8':
			PlayGameSound('m_hydraulic',building1M07Target6);
			building1M07Target6.TriggerSelf();
			return true;
			case 'room2Target1':
			PlayGameSound('m_hydraulic',building1M08Target1);
			building1M08Target1.TriggerSelf();
			return true;
			case 'room2Target2':
			PlayGameSound('m_hydraulic',building1M08Target2);
			building1M08Target2.TriggerSelf();
			return true;
			case 'room2Target3':
			PlayGameSound('m_hydraulic',building1M08Target3);
			building1M08Target3.TriggerSelf();
			return true;
			case 'room2Target4':
			PlayGameSound('m_hydraulic',building1M08Target4);
			building1M08Target4.TriggerSelf();
			return true;
			case 'room2Target5':
			PlayGameSound('m_hydraulic',building1M08Target5);
			building1M08Target5.TriggerSelf();
			case 'room2Target6':
			PlayGameSound('m_hydraulic',building1M08Target6);
			building1M08Target6.TriggerSelf();
			return true;
			case 'door1Pause':
			flipDoor1Targets();
			return true;
			case 'door2Pause':
			flipDoor2Targets();
			return true;
			case 'door1Reset':
			building1M01Target1.ResetTarget(true);
			building1M01Target2.ResetTarget(true);
			building1M01Target3.ResetTarget(true);
			building1M02Target1.ResetTarget(true);
			building1M02Target2.ResetTarget(true);
			building1M03Target1.ResetTarget(true);
			return true;
			case 'door2Reset':
			building1M04Target1.ResetTarget(true);
			building1M04Target2.ResetTarget(true);
			building1M04Target3.ResetTarget(true);
			building1M05Target1.ResetTarget(true);
			building1M05Target2.ResetTarget(true);
			return true;
			case 'room1Reset':
			building1M06Target1.ResetTarget(true);
			building1M06Target2.ResetTarget(true);
			building1M07Target1.ResetTarget(true);
			building1M07Target2.ResetTarget(true);
			building1M07Target3.ResetTarget(true);
			building1M07Target4.ResetTarget(true);
			building1M07Target5.ResetTarget(true);
			building1M07Target6.ResetTarget(true);
			return true;
			case 'room2Reset':
			building1M08Target1.ResetTarget(true);
			building1M08Target2.ResetTarget(true);
			building1M08Target3.ResetTarget(true);
			building1M08Target4.ResetTarget(true);
			building1M08Target5.ResetTarget(true);
			building1M08Target6.ResetTarget(true);
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,'CheckPlayerMove');
		building1M01Target1=MarksmanTarget(CaptureEvent('Building1Marker01Target01'));
		building1M01Target2=MarksmanTarget(CaptureEvent('Building1Marker01Target02'));
		building1M01Target3=MarksmanTarget(CaptureEvent('Building1Marker01Target03'));
		building1M02Target1=MarksmanTarget(CaptureEvent('Building1Marker02Target01'));
		building1M02Target2=MarksmanTarget(CaptureEvent('Building1Marker02Target02'));
		building1M03Target1=MarksmanTarget(CaptureEvent('Building1Marker03Target01'));
		building1M04Target1=MarksmanTarget(CaptureEvent('Building1Marker04Target01'));
		building1M04Target2=MarksmanTarget(CaptureEvent('Building1Marker04Target02'));
		building1M04Target3=MarksmanTarget(CaptureEvent('Building1Marker04Target03'));
		building1M05Target1=MarksmanTarget(CaptureEvent('Building1Marker05Target01'));
		building1M05Target2=MarksmanTarget(CaptureEvent('Building1Marker05Target02'));
		building1M08Target1=MarksmanTarget(CaptureEvent('Building1Marker08Target01'));
		building1M08Target2=MarksmanTarget(CaptureEvent('Building1Marker08Target02'));
		building1M08Target3=MarksmanTarget(CaptureEvent('Building1Marker08Target03'));
		building1M08Target4=MarksmanTarget(CaptureEvent('Building1Marker08Target04'));
		building1M08Target5=MarksmanTarget(CaptureEvent('Building1Marker08Target05'));
		building1M08Target6=MarksmanTarget(CaptureEvent('Building1Marker08Target06'));
		if (! building1MTTriggerCaptured)
		{
			building1MTTrigger01=TriggerVolume(CaptureEvent('Building1MT_Trigger02AB'));
			building1MTTrigger02=TriggerVolume(CaptureEvent('Building1MT_Trigger02B'));
			building1MTTrigger03=TriggerVolume(CaptureEvent('Building1MT_Trigger06AB'));
			building1MTTriggerCaptured=true;
		}
		opforRunningCount=0;
		if (door1Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer('door1Pause',preTimerPause);
			building1M04Target1.bHidden=true;
			building1M04Target2.bHidden=true;
			building1M04Target3.bHidden=true;
			building1M05Target1.bHidden=true;
			building1M05Target2.bHidden=true;
		}
		if (door2Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer('door2Pause',preTimerPause);
			building1M04Target1.bHidden=false;
			building1M04Target2.bHidden=false;
			building1M04Target3.bHidden=false;
			building1M05Target1.bHidden=false;
			building1M05Target2.bHidden=false;
		}
	}
	Event EndState()
	{
		building1M01Target1.ResetTarget(true);
		UnCaptureEvent(building1M01Target1);
		building1M01Target2.ResetTarget(true);
		UnCaptureEvent(building1M01Target2);
		building1M01Target3.ResetTarget(true);
		UnCaptureEvent(building1M01Target3);
		building1M02Target1.ResetTarget(true);
		UnCaptureEvent(building1M02Target1);
		building1M02Target2.ResetTarget(true);
		UnCaptureEvent(building1M02Target2);
		building1M03Target1.ResetTarget(true);
		UnCaptureEvent(building1M03Target1);
		building1M04Target1.ResetTarget(true);
		UnCaptureEvent(building1M04Target1);
		building1M04Target2.ResetTarget(true);
		UnCaptureEvent(building1M04Target2);
		building1M04Target3.ResetTarget(true);
		UnCaptureEvent(building1M04Target3);
		building1M05Target1.ResetTarget(true);
		UnCaptureEvent(building1M05Target1);
		building1M05Target2.ResetTarget(true);
		UnCaptureEvent(building1M05Target2);
		building1M06Target1.ResetTarget(true);
		UnCaptureEvent(building1M06Target1);
		building1M06Target2.ResetTarget(true);
		UnCaptureEvent(building1M06Target2);
		building1M07Target1.ResetTarget(true);
		UnCaptureEvent(building1M07Target1);
		building1M07Target2.ResetTarget(true);
		UnCaptureEvent(building1M07Target2);
		building1M07Target3.ResetTarget(true);
		UnCaptureEvent(building1M07Target3);
		building1M07Target4.ResetTarget(true);
		UnCaptureEvent(building1M07Target4);
		building1M07Target5.ResetTarget(true);
		UnCaptureEvent(building1M07Target5);
		building1M07Target6.ResetTarget(true);
		UnCaptureEvent(building1M07Target6);
		building1M08Target1.ResetTarget(true);
		UnCaptureEvent(building1M08Target1);
		building1M08Target2.ResetTarget(true);
		UnCaptureEvent(building1M08Target2);
		building1M08Target3.ResetTarget(true);
		UnCaptureEvent(building1M08Target3);
		building1M08Target4.ResetTarget(true);
		UnCaptureEvent(building1M08Target4);
		building1M08Target5.ResetTarget(true);
		UnCaptureEvent(building1M08Target5);
		building1M08Target6.ResetTarget(true);
		UnCaptureEvent(building1M08Target6);
	}
}
State Building1InActive extends building1Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		ChangeState('NoBuildingActive');
	}
}
State Building2Active
{
	Function bool Building2MT_Trigger07B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger07B',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger05);
		}
		return true;
	}
	Function Trigger07BFlip()
	{
		if (building2MTTrigger05.bActive)
		{
			building2M11Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M11Target1);
			building2M11Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M11Target2);
			building2M11Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M11Target3);
			building2M11Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M11Target4);
			building2M11Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M11Target5);
			building2MTTrigger05.DisableTrigger();
			StartTimer('Trigger07BReset',4);
		}
	}
	Function Trigger07BReset()
	{
		building2M11Target1.ResetTarget(true);
		building2M11Target2.ResetTarget(true);
		building2M11Target3.ResetTarget(true);
		building2M11Target4.ResetTarget(true);
		building2M11Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger08A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger08A',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger06);
		}
		return true;
	}
	Function Trigger08AFlip()
	{
		if (building2MTTrigger06.bActive)
		{
			building2M12Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M12Target1);
			building2M12Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M12Target2);
			building2M12Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M12Target3);
			building2MTTrigger06.DisableTrigger();
			StartTimer('Trigger08AReset',4);
		}
	}
	Function Trigger08AReset()
	{
		building2M12Target1.ResetTarget(true);
		building2M12Target2.ResetTarget(true);
		building2M12Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger09A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger09A',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger07);
		}
		return true;
	}
	Function Trigger09AFlip()
	{
		if (building2MTTrigger07.bActive)
		{
			building2M13Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M13Target1);
			building2M13Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M13Target2);
			building2M13Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M13Target3);
			building2MTTrigger07.DisableTrigger();
			StartTimer('Trigger09AReset',4);
		}
	}
	Function Trigger09AReset()
	{
		building2M13Target1.ResetTarget(true);
		building2M13Target2.ResetTarget(true);
		building2M13Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger10A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger10A',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger08);
		}
		return true;
	}
	Function Trigger10AFlip()
	{
		if (building2MTTrigger08.bActive)
		{
			building2M14Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target1);
			building2M14Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target2);
			building2M14Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target3);
			building2M14Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target4);
			building2M14Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target5);
			building2MTTrigger08.DisableTrigger();
			StartTimer('Trigger10AReset',4);
		}
	}
	Function Trigger10AReset()
	{
		building2M14Target1.ResetTarget(true);
		building2M14Target2.ResetTarget(true);
		building2M14Target3.ResetTarget(true);
		building2M14Target4.ResetTarget(true);
		building2M14Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger11A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger11A',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger09);
		}
		return true;
	}
	Function Trigger11AFlip()
	{
		if (building2MTTrigger09.bActive)
		{
			building2M15Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M14Target1);
			building2MTTrigger09.DisableTrigger();
			StartTimer('Trigger11AReset',4);
		}
	}
	Function Trigger11AReset()
	{
		building2M15Target1.ResetTarget(true);
	}
	Function bool Building2MT_Trigger12A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Trigger12A',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger10);
		}
		return true;
	}
	Function Trigger12AFlip()
	{
		if (building2MTTrigger10.bActive)
		{
			building2M16Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M16Target1);
			building2M16Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M16Target2);
			building2M16Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M16Target3);
			building2M17Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M17Target1);
			building2M17Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M17Target2);
			building2M18Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M18Target1);
			building2M18Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M18Target2);
			building2M18Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M18Target3);
			building2MTTrigger10.DisableTrigger();
			StartTimer('Trigger12AReset',4);
		}
	}
	Function Trigger12AReset()
	{
		building2M16Target1.ResetTarget(true);
		building2M16Target2.ResetTarget(true);
		building2M16Target3.ResetTarget(true);
		building2M17Target1.ResetTarget(true);
		building2M17Target2.ResetTarget(true);
		building2M18Target1.ResetTarget(true);
		building2M18Target2.ResetTarget(true);
		building2M18Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger05B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Trigger05B',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger04);
		}
		return true;
	}
	Function Trigger05BFlip()
	{
		if (building2MTTrigger04.bActive)
		{
			building2M09Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M09Target1);
			building2M09Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M09Target2);
			building2M09Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M09Target3);
			building2M09Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M09Target4);
			building2MTTrigger04.DisableTrigger();
			StartTimer('Trigger05BReset',4);
		}
	}
	Function Trigger05BReset()
	{
		building2M09Target1.ResetTarget(true);
		building2M09Target2.ResetTarget(true);
		building2M09Target3.ResetTarget(true);
		building2M09Target4.ResetTarget(true);
	}
	Function bool Building2MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Trigger04B',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger03);
		}
		return true;
	}
	Function Trigger04BFlip()
	{
		if (building2MTTrigger03.bActive)
		{
			building2M05Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M05Target1);
			building2M05Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M05Target2);
			building2M05Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M05Target3);
			building2M06Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M06Target1);
			building2M06Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M06Target2);
			building2M06Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M06Target3);
			building2M07Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M07Target1);
			building2M07Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M07Target2);
			building2M07Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M07Target3);
			building2M08Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M08Target1);
			building2M08Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M08Target2);
			building2MTTrigger03.DisableTrigger();
			StartTimer('Trigger04BReset',4);
		}
	}
	Function Trigger04BReset()
	{
		building2M05Target1.ResetTarget(true);
		building2M05Target2.ResetTarget(true);
		building2M05Target3.ResetTarget(true);
		building2M06Target1.ResetTarget(true);
		building2M06Target2.ResetTarget(true);
		building2M06Target3.ResetTarget(true);
		building2M07Target1.ResetTarget(true);
		building2M07Target2.ResetTarget(true);
		building2M07Target3.ResetTarget(true);
		building2M08Target1.ResetTarget(true);
		building2M08Target2.ResetTarget(true);
	}
	Function bool Building2MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Trigger03B',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger02);
		}
		return true;
	}
	Function Trigger03BFlip()
	{
		if (building2MTTrigger02.bActive)
		{
			building2M04Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M03Target1);
			building2M04Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M04Target2);
			building2M04Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M04Target3);
			building2M04Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M04Target4);
			building2M04Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M04Target5);
			building2MTTrigger02.DisableTrigger();
			StartTimer('Trigger03bReset',4);
		}
	}
	Function Trigger03bReset()
	{
		building2M04Target1.ResetTarget(true);
		building2M04Target2.ResetTarget(true);
		building2M04Target3.ResetTarget(true);
		building2M04Target4.ResetTarget(true);
		building2M04Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Trigger02B',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger01);
		}
		return true;
	}
	Function Trigger02BFlip()
	{
		if (building2MTTrigger01.bActive)
		{
			building2M03Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M03Target1);
			building2M03Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M03Target2);
			building2M03Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M03Target3);
			building2MTTrigger01.DisableTrigger();
			StartTimer('Trigger02BReset',4);
		}
	}
	Function Trigger02BReset()
	{
		building2M03Target1.ResetTarget(true);
		building2M03Target2.ResetTarget(true);
		building2M03Target3.ResetTarget(true);
	}
	Function flipDoor1Targets()
	{
		if (! bbuilding2Door1Flipped)
		{
			building2M10Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target1);
			building2M10Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target2);
			building2M10Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target3);
			building2M10Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target4);
			building2M10Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target5);
			building2M10Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M10Target6);
			bbuilding2Door1Flipped=true;
			StartTimer('door1Reset',4);
		}
	}
	Function ResetDoor1Targets()
	{
		building2M10Target1.ResetTarget(true);
		building2M10Target2.ResetTarget(true);
		building2M10Target3.ResetTarget(true);
		building2M10Target4.ResetTarget(true);
		building2M10Target5.ResetTarget(true);
		building2M10Target6.ResetTarget(true);
	}
	Function flipDoor2Targets()
	{
		if (! bbuilding2Door2Flipped)
		{
			building2M01Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M01Target1);
			building2M02Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M02Target1);
			building2M02Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building2M02Target2);
			bbuilding2Door2Flipped=true;
			StartTimer('door2Reset',4);
		}
	}
	Function ResetDoor2Targets()
	{
		building2M01Target1.ResetTarget(true);
		building2M02Target1.ResetTarget(true);
		building2M02Target2.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'door1Pause':
			flipDoor1Targets();
			return true;
			case 'door2Pause':
			flipDoor2Targets();
			return true;
			case 'door1Reset':
			ResetDoor1Targets();
			return true;
			case 'door2Reset':
			ResetDoor2Targets();
			return true;
			case 'Trigger07B':
			Trigger07BFlip();
			return true;
			case 'Trigger08A':
			Trigger08AFlip();
			return true;
			case 'Trigger09A':
			Trigger09AFlip();
			return true;
			case 'Trigger10A':
			Trigger10AFlip();
			return true;
			case 'Trigge11A':
			Trigger11AFlip();
			return true;
			case 'Trigger12A':
			Trigger12AFlip();
			return true;
			case 'Trigger05B':
			Trigger05BFlip();
			return true;
			case 'Trigger04B':
			Trigger04BFlip();
			return true;
			case 'Trigger03B':
			Trigger03BFlip();
			return true;
			case 'Trigger02B':
			Trigger02BFlip();
			return true;
			case 'Trigger07BReset':
			Trigger07BReset();
			return true;
			case 'Trigger08AReset':
			Trigger08AReset();
			return true;
			case 'Trigger09AReset':
			Trigger09AReset();
			return true;
			case 'Trigger10AReset':
			Trigger10AReset();
			return true;
			case 'Trigge11AReset':
			Trigger11AReset();
			return true;
			case 'Trigger12AReset':
			Trigger12AReset();
			return true;
			case 'Trigger05BReset':
			Trigger05BReset();
			return true;
			case 'Trigger04BReset':
			Trigger04BReset();
			return true;
			case 'Trigger03bReset':
			Trigger03bReset();
			return true;
			case 'Trigger02BReset':
			Trigger02BReset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building2M01Target1=MarksmanTarget(CaptureEvent('Building2Marker01Target01'));
		building2M02Target1=MarksmanTarget(CaptureEvent('Building2Marker02Target01'));
		building2M02Target2=MarksmanTarget(CaptureEvent('Building2Marker02Target02'));
		building2M03Target1=MarksmanTarget(CaptureEvent('Building2Marker03Target01'));
		building2M03Target2=MarksmanTarget(CaptureEvent('Building2Marker03Target02'));
		building2M03Target3=MarksmanTarget(CaptureEvent('Building2Marker03Target03'));
		building2M04Target1=MarksmanTarget(CaptureEvent('Building2Marker04Target01'));
		building2M04Target2=MarksmanTarget(CaptureEvent('Building2Marker04Target02'));
		building2M04Target3=MarksmanTarget(CaptureEvent('Building2Marker04Target03'));
		building2M04Target4=MarksmanTarget(CaptureEvent('Building2Marker04Target04'));
		building2M04Target5=MarksmanTarget(CaptureEvent('Building2Marker04Target05'));
		building2M05Target1=MarksmanTarget(CaptureEvent('Building2Marker05Target01'));
		building2M05Target2=MarksmanTarget(CaptureEvent('Building2Marker05Target02'));
		building2M05Target3=MarksmanTarget(CaptureEvent('Building2Marker05Target03'));
		building2M06Target1=MarksmanTarget(CaptureEvent('Building2Marker06Target01'));
		building2M06Target2=MarksmanTarget(CaptureEvent('Building2Marker06Target02'));
		building2M06Target3=MarksmanTarget(CaptureEvent('Building2Marker06Target03'));
		building2M07Target1=MarksmanTarget(CaptureEvent('Building2Marker07Target01'));
		building2M07Target2=MarksmanTarget(CaptureEvent('Building2Marker07Target02'));
		building2M07Target3=MarksmanTarget(CaptureEvent('Building2Marker07Target03'));
		building2M08Target1=MarksmanTarget(CaptureEvent('Building2Marker08Target01'));
		building2M08Target2=MarksmanTarget(CaptureEvent('Building2Marker08Target02'));
		building2M09Target1=MarksmanTarget(CaptureEvent('Building2Marker09Target01'));
		building2M09Target2=MarksmanTarget(CaptureEvent('Building2Marker09Target02'));
		building2M09Target3=MarksmanTarget(CaptureEvent('Building2Marker09Target03'));
		building2M09Target4=MarksmanTarget(CaptureEvent('Building2Marker09Target04'));
		building2M10Target1=MarksmanTarget(CaptureEvent('Building2Marker10Target01'));
		building2M10Target2=MarksmanTarget(CaptureEvent('Building2Marker10Target02'));
		building2M10Target3=MarksmanTarget(CaptureEvent('Building2Marker10Target03'));
		building2M10Target4=MarksmanTarget(CaptureEvent('Building2Marker10Target04'));
		building2M10Target5=MarksmanTarget(CaptureEvent('Building2Marker10Target05'));
		building2M10Target6=MarksmanTarget(CaptureEvent('Building2Marker10Target06'));
		building2M11Target1=MarksmanTarget(CaptureEvent('Building2Marker11Target01'));
		building2M11Target2=MarksmanTarget(CaptureEvent('Building2Marker11Target02'));
		building2M11Target3=MarksmanTarget(CaptureEvent('Building2Marker11Target03'));
		building2M11Target4=MarksmanTarget(CaptureEvent('Building2Marker11Target04'));
		building2M11Target5=MarksmanTarget(CaptureEvent('Building2Marker11Target05'));
		building2M12Target1=MarksmanTarget(CaptureEvent('Building2Marker12Target01'));
		building2M12Target2=MarksmanTarget(CaptureEvent('Building2Marker12Target02'));
		building2M12Target3=MarksmanTarget(CaptureEvent('Building2Marker12Target03'));
		building2M13Target1=MarksmanTarget(CaptureEvent('Building2Marker13Target01'));
		building2M13Target2=MarksmanTarget(CaptureEvent('Building2Marker13Target02'));
		building2M13Target3=MarksmanTarget(CaptureEvent('Building2Marker13Target03'));
		building2M14Target1=MarksmanTarget(CaptureEvent('Building2Marker14Target01'));
		building2M14Target2=MarksmanTarget(CaptureEvent('Building2Marker14Target02'));
		building2M14Target3=MarksmanTarget(CaptureEvent('Building2Marker14Target03'));
		building2M14Target4=MarksmanTarget(CaptureEvent('Building2Marker14Target04'));
		building2M14Target5=MarksmanTarget(CaptureEvent('Building2Marker14Target05'));
		building2M15Target1=MarksmanTarget(CaptureEvent('Building2Marker15Target01'));
		building2M16Target1=MarksmanTarget(CaptureEvent('Building2Marker16Target01'));
		building2M16Target2=MarksmanTarget(CaptureEvent('Building2Marker16Target02'));
		building2M16Target3=MarksmanTarget(CaptureEvent('Building2Marker16Target03'));
		building2M17Target1=MarksmanTarget(CaptureEvent('Building2Marker17Target01'));
		building2M17Target2=MarksmanTarget(CaptureEvent('Building2Marker17Target02'));
		building2M18Target1=MarksmanTarget(CaptureEvent('Building2Marker18Target01'));
		building2M18Target2=MarksmanTarget(CaptureEvent('Building2Marker18Target02'));
		building2M18Target3=MarksmanTarget(CaptureEvent('Building2Marker18Target03'));
		if (door1Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer('door1Pause',preTimerPause);
			building2M01Target1.bHidden=true;
			building2M02Target1.bHidden=true;
			building2M02Target2.bHidden=true;
			building2M03Target1.bHidden=true;
			building2M03Target2.bHidden=true;
			building2M03Target3.bHidden=true;
			building2M04Target1.bHidden=true;
			building2M04Target2.bHidden=true;
			building2M04Target3.bHidden=true;
			building2M04Target4.bHidden=true;
			building2M04Target5.bHidden=true;
			building2M05Target1.bHidden=true;
			building2M05Target2.bHidden=true;
			building2M05Target3.bHidden=true;
			building2M06Target1.bHidden=true;
			building2M06Target2.bHidden=true;
			building2M06Target3.bHidden=true;
			building2M07Target1.bHidden=true;
			building2M07Target2.bHidden=true;
			building2M07Target3.bHidden=true;
			building2M08Target1.bHidden=true;
			building2M08Target2.bHidden=true;
			building2M09Target1.bHidden=true;
			building2M09Target2.bHidden=true;
			building2M09Target3.bHidden=true;
			building2M09Target4.bHidden=true;
			building2M10Target1.bHidden=false;
			building2M10Target2.bHidden=false;
			building2M10Target3.bHidden=false;
			building2M10Target4.bHidden=false;
			building2M10Target5.bHidden=false;
			building2M10Target6.bHidden=false;
			building2M11Target1.bHidden=false;
			building2M11Target2.bHidden=false;
			building2M11Target3.bHidden=false;
			building2M11Target4.bHidden=false;
			building2M11Target5.bHidden=false;
			building2M12Target1.bHidden=false;
			building2M12Target2.bHidden=false;
			building2M12Target3.bHidden=false;
			building2M13Target1.bHidden=false;
			building2M13Target2.bHidden=false;
			building2M13Target3.bHidden=false;
			building2M14Target1.bHidden=false;
			building2M14Target2.bHidden=false;
			building2M14Target3.bHidden=false;
			building2M14Target4.bHidden=false;
			building2M14Target5.bHidden=false;
			building2M15Target1.bHidden=false;
			building2M16Target1.bHidden=false;
			building2M16Target2.bHidden=false;
			building2M16Target3.bHidden=false;
			building2M17Target1.bHidden=false;
			building2M17Target2.bHidden=false;
			building2M18Target1.bHidden=false;
			building2M18Target2.bHidden=false;
			building2M18Target3.bHidden=false;
		}
		if (door2Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer('door2Pause',preTimerPause);
			building2M10Target1.bHidden=true;
			building2M10Target2.bHidden=true;
			building2M10Target3.bHidden=true;
			building2M10Target4.bHidden=true;
			building2M10Target5.bHidden=true;
			building2M10Target6.bHidden=true;
			building2M11Target1.bHidden=true;
			building2M11Target2.bHidden=true;
			building2M11Target3.bHidden=true;
			building2M11Target4.bHidden=true;
			building2M11Target5.bHidden=true;
			building2M12Target1.bHidden=true;
			building2M12Target2.bHidden=true;
			building2M12Target3.bHidden=true;
			building2M13Target1.bHidden=true;
			building2M13Target2.bHidden=true;
			building2M13Target3.bHidden=true;
			building2M14Target1.bHidden=true;
			building2M14Target2.bHidden=true;
			building2M14Target3.bHidden=true;
			building2M14Target4.bHidden=true;
			building2M14Target5.bHidden=true;
			building2M15Target1.bHidden=true;
			building2M16Target1.bHidden=true;
			building2M16Target2.bHidden=true;
			building2M16Target3.bHidden=true;
			building2M17Target1.bHidden=true;
			building2M17Target2.bHidden=true;
			building2M18Target1.bHidden=true;
			building2M18Target2.bHidden=true;
			building2M18Target3.bHidden=true;
			building2M01Target1.bHidden=false;
			building2M02Target1.bHidden=false;
			building2M02Target2.bHidden=false;
			building2M03Target1.bHidden=false;
			building2M03Target2.bHidden=false;
			building2M03Target3.bHidden=false;
			building2M04Target1.bHidden=false;
			building2M04Target2.bHidden=false;
			building2M04Target3.bHidden=false;
			building2M04Target4.bHidden=false;
			building2M04Target5.bHidden=false;
			building2M05Target1.bHidden=false;
			building2M05Target2.bHidden=false;
			building2M05Target3.bHidden=false;
			building2M06Target1.bHidden=false;
			building2M06Target2.bHidden=false;
			building2M06Target3.bHidden=false;
			building2M07Target1.bHidden=false;
			building2M07Target2.bHidden=false;
			building2M07Target3.bHidden=false;
			building2M08Target1.bHidden=false;
			building2M08Target2.bHidden=false;
			building2M09Target1.bHidden=false;
			building2M09Target2.bHidden=false;
			building2M09Target3.bHidden=false;
			building2M09Target4.bHidden=false;
		}
		if (! building2MTTriggerCaptured)
		{
			building2MTTrigger01=TriggerVolume(CaptureEvent('Building2MT_Trigger02B'));
			building2MTTrigger02=TriggerVolume(CaptureEvent('Building2MT_Trigger03B'));
			building2MTTrigger03=TriggerVolume(CaptureEvent('Building2MT_Trigger04B'));
			building2MTTrigger04=TriggerVolume(CaptureEvent('Building2MT_Trigger05B'));
			building2MTTrigger05=TriggerVolume(CaptureEvent('Building2MT_Trigger07B'));
			building2MTTrigger06=TriggerVolume(CaptureEvent('Building2MT_Trigger08A'));
			building2MTTrigger07=TriggerVolume(CaptureEvent('Building2MT_Trigger09A'));
			building2MTTrigger08=TriggerVolume(CaptureEvent('Building2MT_Trigger10A'));
			building2MTTrigger09=TriggerVolume(CaptureEvent('Building2MT_Trigger11A'));
			building2MTTrigger10=TriggerVolume(CaptureEvent('Building2MT_Trigger12A'));
			building2MTTriggerCaptured=true;
		}
	}
}
State Building2InActive extends Building2Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		ChangeState('NoBuildingActive');
	}
	Function resetCapturedTargets()
	{
		building2M10Target1.ResetTarget(true);
		UnCaptureEvent(building2M10Target1);
		building2M10Target2.ResetTarget(true);
		UnCaptureEvent(building2M10Target2);
		building2M10Target3.ResetTarget(true);
		UnCaptureEvent(building2M10Target3);
		building2M10Target4.ResetTarget(true);
		UnCaptureEvent(building2M10Target4);
		building2M10Target5.ResetTarget(true);
		UnCaptureEvent(building2M10Target5);
		building2M10Target6.ResetTarget(true);
		UnCaptureEvent(building2M10Target6);
		building2M01Target1.ResetTarget(true);
		UnCaptureEvent(building2M01Target1);
		building2M02Target1.ResetTarget(true);
		UnCaptureEvent(building2M02Target1);
		building2M02Target2.ResetTarget(true);
		UnCaptureEvent(building2M02Target2);
		building2M11Target1.ResetTarget(true);
		UnCaptureEvent(building2M11Target1);
		building2M11Target2.ResetTarget(true);
		UnCaptureEvent(building2M11Target2);
		building2M11Target3.ResetTarget(true);
		UnCaptureEvent(building2M11Target3);
		building2M11Target4.ResetTarget(true);
		UnCaptureEvent(building2M11Target4);
		building2M11Target5.ResetTarget(true);
		UnCaptureEvent(building2M11Target5);
		building2M12Target1.ResetTarget(true);
		UnCaptureEvent(building2M12Target1);
		building2M12Target2.ResetTarget(true);
		UnCaptureEvent(building2M12Target2);
		building2M12Target3.ResetTarget(true);
		UnCaptureEvent(building2M12Target3);
		building2M13Target1.ResetTarget(true);
		UnCaptureEvent(building2M13Target1);
		building2M13Target2.ResetTarget(true);
		UnCaptureEvent(building2M13Target2);
		building2M13Target3.ResetTarget(true);
		UnCaptureEvent(building2M13Target3);
		building2M14Target1.ResetTarget(true);
		UnCaptureEvent(building2M14Target1);
		building2M14Target2.ResetTarget(true);
		UnCaptureEvent(building2M14Target2);
		building2M14Target3.ResetTarget(true);
		UnCaptureEvent(building2M14Target3);
		building2M14Target2.ResetTarget(true);
		UnCaptureEvent(building2M14Target2);
		building2M14Target3.ResetTarget(true);
		UnCaptureEvent(building2M14Target3);
		building2M15Target1.ResetTarget(true);
		UnCaptureEvent(building2M15Target1);
		building2M16Target1.ResetTarget(true);
		UnCaptureEvent(building2M16Target1);
		building2M16Target2.ResetTarget(true);
		UnCaptureEvent(building2M16Target2);
		building2M16Target3.ResetTarget(true);
		UnCaptureEvent(building2M16Target3);
		building2M17Target1.ResetTarget(true);
		UnCaptureEvent(building2M17Target1);
		building2M17Target2.ResetTarget(true);
		UnCaptureEvent(building2M17Target2);
		building2M18Target1.ResetTarget(true);
		UnCaptureEvent(building2M18Target1);
		building2M18Target2.ResetTarget(true);
		UnCaptureEvent(building2M18Target2);
		building2M18Target3.ResetTarget(true);
		UnCaptureEvent(building2M18Target3);
		building2M09Target1.ResetTarget(true);
		UnCaptureEvent(building2M09Target1);
		building2M09Target2.ResetTarget(true);
		UnCaptureEvent(building2M09Target2);
		building2M09Target3.ResetTarget(true);
		UnCaptureEvent(building2M09Target3);
		building2M09Target4.ResetTarget(true);
		UnCaptureEvent(building2M09Target4);
		building2M05Target1.ResetTarget(true);
		UnCaptureEvent(building2M05Target1);
		building2M05Target2.ResetTarget(true);
		UnCaptureEvent(building2M05Target2);
		building2M05Target3.ResetTarget(true);
		UnCaptureEvent(building2M05Target3);
		building2M06Target1.ResetTarget(true);
		UnCaptureEvent(building2M06Target1);
		building2M06Target2.ResetTarget(true);
		UnCaptureEvent(building2M06Target2);
		building2M06Target3.ResetTarget(true);
		UnCaptureEvent(building2M06Target3);
		building2M07Target1.ResetTarget(true);
		UnCaptureEvent(building2M07Target1);
		building2M07Target2.ResetTarget(true);
		UnCaptureEvent(building2M07Target2);
		building2M07Target3.ResetTarget(true);
		UnCaptureEvent(building2M07Target3);
		building2M08Target1.ResetTarget(true);
		UnCaptureEvent(building2M08Target1);
		building2M08Target2.ResetTarget(true);
		UnCaptureEvent(building2M08Target2);
		building2M04Target1.ResetTarget(true);
		UnCaptureEvent(building2M04Target1);
		building2M04Target2.ResetTarget(true);
		UnCaptureEvent(building2M04Target2);
		building2M04Target3.ResetTarget(true);
		UnCaptureEvent(building2M04Target3);
		building2M04Target4.ResetTarget(true);
		UnCaptureEvent(building2M04Target4);
		building2M04Target5.ResetTarget(true);
		UnCaptureEvent(building2M04Target5);
		building2M03Target1.ResetTarget(true);
		UnCaptureEvent(building2M03Target1);
		building2M03Target2.ResetTarget(true);
		UnCaptureEvent(building2M03Target2);
		building2M03Target3.ResetTarget(true);
		UnCaptureEvent(building2M03Target3);
	}
}
State Building3Active
{
	Function bool Building3MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			building3MTTrigger01.DisableTrigger();
			Building3MT_Trigger06B_Enter(Trigger,Instigator);
		}
		return true;
	}
	Function bool Building3MT_Trigger02ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building3M03Target1=MarksmanTarget(CaptureEvent('Building3Marker03Target01'));
		building3M03Target2=MarksmanTarget(CaptureEvent('Building3Marker03Target02'));
		building3M03Target3=MarksmanTarget(CaptureEvent('Building3Marker03Target03'));
		building3M03Target4=MarksmanTarget(CaptureEvent('Building3Marker03Target04'));
		building3M03Target5=MarksmanTarget(CaptureEvent('Building3Marker03Target05'));
		StartTimer('Building3MT_Trigger02ABC_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building3MTTrigger02);
		return true;
	}
	Function Building3MT_Trigger02ABC_Flip()
	{
		if (building3MTTrigger02.bActive)
		{
			building3M03Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M03Target1);
			building3M03Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M03Target2);
			building3M03Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M03Target3);
			building3M03Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M03Target4);
			building3M03Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M03Target5);
			building3MTTrigger02.DisableTrigger();
			StartTimer('Building3MT_Trigger02ABC_Reset',4);
		}
	}
	Function Building3MT_Trigger02ABC_Reset()
	{
		building3M03Target1.ResetTarget(true);
		building3M03Target2.ResetTarget(true);
		building3M03Target3.ResetTarget(true);
		building3M03Target4.ResetTarget(true);
		building3M03Target5.ResetTarget(true);
	}
	Function bool Building3MT_Trigger03ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building3M04Target1=MarksmanTarget(CaptureEvent('Building3Marker04Target01'));
		building3M04Target2=MarksmanTarget(CaptureEvent('Building3Marker04Target02'));
		building3M04Target3=MarksmanTarget(CaptureEvent('Building3Marker04Target03'));
		StartTimer('Building3MT_Trigger03ABC_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building3MTTrigger03);
		return true;
	}
	Function Building3MT_Trigger03ABC_Flip()
	{
		if (building3MTTrigger03.bActive)
		{
			building3M04Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M04Target1);
			building3M04Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M04Target2);
			building3M04Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M04Target3);
			building3MTTrigger03.DisableTrigger();
			StartTimer('Building3MT_Trigger03ABC_Reset',4);
		}
	}
	Function Building3MT_Trigger03ABC_Reset()
	{
		building3M04Target1.ResetTarget(true);
		building3M04Target2.ResetTarget(true);
		building3M04Target3.ResetTarget(true);
	}
	Function bool Building3MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Building3MT_Trigger04B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger04);
		}
		return true;
	}
	Function Building3MT_Trigger04B_Flip()
	{
		if (building3MTTrigger04.bActive)
		{
			building3M05Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M05Target1);
			building3M05Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M05Target2);
			building3M06Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M06Target1);
			building3MTTrigger04.DisableTrigger();
			StartTimer('Building3MT_Trigger04B_Reset',4);
		}
	}
	Function Building3MT_Trigger04B_Reset()
	{
		building3M05Target1.ResetTarget(true);
		building3M05Target2.ResetTarget(true);
		building3M06Target1.ResetTarget(true);
	}
	Function bool Building3MT_Trigger05B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Building3MT_Trigger05B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger05);
		}
		return true;
	}
	Function Building3MT_Trigger05B_Flip()
	{
		if (building3MTTrigger05.bActive)
		{
			building3M07Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target1);
			building3M07Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target2);
			building3M07Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target3);
			building3M07Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target4);
			building3M07Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target5);
			building3M07Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target6);
			building3M07Target7.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M07Target7);
			building3MTTrigger05.DisableTrigger();
			StartTimer('Building3MT_Trigger05B_Reset',4);
		}
	}
	Function Building3MT_Trigger05B_Reset()
	{
		building3M07Target1.ResetTarget(true);
		building3M07Target2.ResetTarget(true);
		building3M07Target3.ResetTarget(true);
		building3M07Target4.ResetTarget(true);
		building3M07Target5.ResetTarget(true);
		building3M07Target6.ResetTarget(true);
		building3M07Target7.ResetTarget(true);
	}
	Function bool Building3MT_Trigger06B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building3MT_Trigger06B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger06);
		}
		return true;
	}
	Function Building3MT_Trigger06B_Flip()
	{
		if (building3MTTrigger06.bActive)
		{
			building3M08Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target1);
			building3M08Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target2);
			building3M08Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target3);
			building3M08Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target4);
			building3M08Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target5);
			building3M08Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target6);
			building3M08Target7.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M08Target7);
			building3MTTrigger06.DisableTrigger();
			building3MTTrigger01.DisableTrigger();
			StartTimer('Building3MT_Trigger06B_Reset',4);
		}
	}
	Function Building3MT_Trigger06B_Reset()
	{
		building3M08Target1.ResetTarget(true);
		building3M08Target2.ResetTarget(true);
		building3M08Target3.ResetTarget(true);
		building3M08Target4.ResetTarget(true);
		building3M08Target5.ResetTarget(true);
		building3M08Target6.ResetTarget(true);
		building3M08Target7.ResetTarget(true);
	}
	Function bool Building3MT_Trigger07AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered || door2Entered)
		{
			StartTimer('Building3MT_Trigger07AB_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger07);
		}
		return true;
	}
	Function Building3MT_Trigger07AB_Flip()
	{
		if (building3MTTrigger07.bActive)
		{
			building3M09Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M09Target1);
			building3M10Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M10Target1);
			building3MTTrigger07.DisableTrigger();
			StartTimer('Building3MT_Trigger07AB_Reset',4);
		}
	}
	Function Building3MT_Trigger07AB_Reset()
	{
		building3M09Target1.ResetTarget(true);
		building3M10Target1.ResetTarget(true);
	}
	Function bool Building3MT_Trigger08AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered || door2Entered)
		{
			StartTimer('door3Pause',(FRand() * TargetFlipModifier));
		}
		return true;
	}
	Function door3Flip()
	{
		if (! bbuilding3Door3Flipped)
		{
			building3M01Target1=MarksmanTarget(CaptureEvent('Building3Marker01Target01'));
			building3M01Target2=MarksmanTarget(CaptureEvent('Building3Marker01Target02'));
			building3M01Target3=MarksmanTarget(CaptureEvent('Building3Marker01Target03'));
			building3M01Target4=MarksmanTarget(CaptureEvent('Building3Marker01Target04'));
			building3M01Target5=MarksmanTarget(CaptureEvent('Building3Marker01Target05'));
			building3M02Target1=MarksmanTarget(CaptureEvent('Building3Marker02Target01'));
			building3M02Target2=MarksmanTarget(CaptureEvent('Building3Marker02Target02'));
			building3M02Target3=MarksmanTarget(CaptureEvent('Building3Marker02Target03'));
			building3M01Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M01Target1);
			building3M01Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M01Target2);
			building3M01Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M01Target3);
			building3M01Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M01Target4);
			building3M01Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M01Target5);
			building3M02Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M02Target1);
			building3M02Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M02Target2);
			building3M02Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building3M02Target3);
			bbuilding3Door3Flipped=true;
			StartTimer('door3Reset',4);
		}
	}
	Function door3Reset()
	{
		building3M01Target1.ResetTarget(true);
		building3M01Target2.ResetTarget(true);
		building3M01Target3.ResetTarget(true);
		building3M01Target4.ResetTarget(true);
		building3M01Target5.ResetTarget(true);
		building3M02Target1.ResetTarget(true);
		building3M02Target2.ResetTarget(true);
		building3M02Target3.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'door3Pause':
			door3Flip();
			return true;
			case 'door3Reset':
			door3Reset();
			return true;
			case 'Building3MT_Trigger02ABC_Flip':
			Building3MT_Trigger02ABC_Flip();
			return true;
			case 'Building3MT_Trigger02ABC_Reset':
			Building3MT_Trigger02ABC_Reset();
			return true;
			case 'Building3MT_Trigger03ABC_Flip':
			Building3MT_Trigger03ABC_Flip();
			return true;
			case 'Building3MT_Trigger03ABC_Reset':
			Building3MT_Trigger03ABC_Reset();
			return true;
			case 'Building3MT_Trigger04B_Flip':
			Building3MT_Trigger04B_Flip();
			return true;
			case 'Building3MT_Trigger04B_Reset':
			Building3MT_Trigger04B_Reset();
			return true;
			case 'Building3MT_Trigger05B_Flip':
			Building3MT_Trigger05B_Flip();
			return true;
			case 'Building3MT_Trigger05B_Reset':
			Building3MT_Trigger05B_Reset();
			return true;
			case 'Building3MT_Trigger06B_Flip':
			Building3MT_Trigger06B_Flip();
			return true;
			case 'Building3MT_Trigger06B_Reset':
			Building3MT_Trigger06B_Reset();
			return true;
			case 'Building3MT_Trigger07AB_Flip':
			Building3MT_Trigger07AB_Flip();
			return true;
			case 'Building3MT_Trigger07AB_Reset':
			Building3MT_Trigger07AB_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building3M05Target1=MarksmanTarget(CaptureEvent('Building3Marker05Target01'));
		building3M05Target2=MarksmanTarget(CaptureEvent('Building3Marker05Target02'));
		building3M06Target1=MarksmanTarget(CaptureEvent('Building3Marker06Target01'));
		building3M07Target1=MarksmanTarget(CaptureEvent('Building3Marker07Target01'));
		building3M07Target2=MarksmanTarget(CaptureEvent('Building3Marker07Target02'));
		building3M07Target3=MarksmanTarget(CaptureEvent('Building3Marker07Target03'));
		building3M07Target4=MarksmanTarget(CaptureEvent('Building3Marker07Target04'));
		building3M07Target5=MarksmanTarget(CaptureEvent('Building3Marker07Target05'));
		building3M07Target6=MarksmanTarget(CaptureEvent('Building3Marker07Target06'));
		building3M07Target7=MarksmanTarget(CaptureEvent('Building3Marker07Target07'));
		building3M08Target1=MarksmanTarget(CaptureEvent('Building3Marker08Target01'));
		building3M08Target2=MarksmanTarget(CaptureEvent('Building3Marker08Target02'));
		building3M08Target3=MarksmanTarget(CaptureEvent('Building3Marker08Target03'));
		building3M08Target4=MarksmanTarget(CaptureEvent('Building3Marker08Target04'));
		building3M08Target5=MarksmanTarget(CaptureEvent('Building3Marker08Target05'));
		building3M08Target6=MarksmanTarget(CaptureEvent('Building3Marker08Target06'));
		building3M08Target7=MarksmanTarget(CaptureEvent('Building3Marker08Target07'));
		building3M09Target1=MarksmanTarget(CaptureEvent('Building3Marker09Target01'));
		building3M10Target1=MarksmanTarget(CaptureEvent('Building3Marker10Target01'));
		if (! building3MTTriggerCaptured)
		{
			building3MTTrigger01=TriggerVolume(CaptureEvent('Building3MT_Trigger03B'));
			building3MTTrigger02=TriggerVolume(CaptureEvent('Building3MT_Trigger02ABC'));
			building3MTTrigger03=TriggerVolume(CaptureEvent('Building3MT_Trigger03ABC'));
			building3MTTrigger04=TriggerVolume(CaptureEvent('Building3MT_Trigger04B'));
			building3MTTrigger05=TriggerVolume(CaptureEvent('Building3MT_Trigger05B'));
			building3MTTrigger06=TriggerVolume(CaptureEvent('Building3MT_Trigger06B'));
			building3MTTrigger07=TriggerVolume(CaptureEvent('Building3MT_Trigger07AB'));
			building3MTTrigger08=TriggerVolume(CaptureEvent('Building3MT_Trigger08AB'));
			building3MTTriggerCaptured=true;
		}
		if (door1Entered)
		{
			building3M05Target1.bHidden=true;
			building3M05Target2.bHidden=true;
			building3M06Target1.bHidden=true;
			building3M07Target1.bHidden=true;
			building3M07Target2.bHidden=true;
			building3M07Target3.bHidden=true;
			building3M07Target4.bHidden=true;
			building3M07Target5.bHidden=true;
			building3M07Target6.bHidden=true;
			building3M07Target7.bHidden=true;
			building3M08Target1.bHidden=false;
			building3M08Target2.bHidden=false;
			building3M08Target3.bHidden=false;
			building3M08Target4.bHidden=false;
			building3M08Target5.bHidden=false;
			building3M08Target6.bHidden=false;
			building3M08Target7.bHidden=false;
			building3M09Target1.bHidden=false;
			building3M10Target1.bHidden=false;
		}
		if (door2Entered)
		{
			building3M05Target1.bHidden=false;
			building3M05Target2.bHidden=false;
			building3M06Target1.bHidden=false;
			building3M07Target1.bHidden=false;
			building3M07Target2.bHidden=false;
			building3M07Target3.bHidden=false;
			building3M07Target4.bHidden=false;
			building3M07Target5.bHidden=false;
			building3M07Target6.bHidden=false;
			building3M07Target7.bHidden=false;
			building3M08Target1.bHidden=false;
			building3M08Target2.bHidden=false;
			building3M08Target3.bHidden=false;
			building3M08Target4.bHidden=false;
			building3M08Target5.bHidden=false;
			building3M08Target6.bHidden=false;
			building3M08Target7.bHidden=false;
			building3M09Target1.bHidden=false;
			building3M10Target1.bHidden=false;
		}
		if (door3Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer('door3Pause',preTimerPause);
			building3M05Target1.bHidden=true;
			building3M05Target2.bHidden=true;
			building3M06Target1.bHidden=true;
			building3M07Target1.bHidden=true;
			building3M07Target2.bHidden=true;
			building3M07Target3.bHidden=true;
			building3M07Target4.bHidden=true;
			building3M07Target5.bHidden=true;
			building3M07Target6.bHidden=true;
			building3M07Target7.bHidden=true;
			building3M08Target1.bHidden=true;
			building3M08Target2.bHidden=true;
			building3M08Target3.bHidden=true;
			building3M08Target4.bHidden=true;
			building3M08Target5.bHidden=true;
			building3M08Target6.bHidden=true;
			building3M08Target7.bHidden=true;
			building3M09Target1.bHidden=true;
			building3M10Target1.bHidden=true;
		}
	}
}
State Building3InActive extends Building3Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		door3Entered=false;
		building3M01Target1.ResetTarget(true);
		UnCaptureEvent(building3M01Target1);
		building3M01Target2.ResetTarget(true);
		UnCaptureEvent(building3M01Target2);
		building3M01Target3.ResetTarget(true);
		UnCaptureEvent(building3M01Target3);
		building3M01Target4.ResetTarget(true);
		UnCaptureEvent(building3M01Target4);
		building3M01Target5.ResetTarget(true);
		UnCaptureEvent(building3M01Target5);
		building3M02Target1.ResetTarget(true);
		UnCaptureEvent(building3M02Target1);
		building3M02Target2.ResetTarget(true);
		UnCaptureEvent(building3M02Target2);
		building3M02Target3.ResetTarget(true);
		UnCaptureEvent(building3M02Target3);
		building3M03Target1.ResetTarget(true);
		UnCaptureEvent(building3M03Target1);
		building3M03Target2.ResetTarget(true);
		UnCaptureEvent(building3M03Target2);
		building3M03Target3.ResetTarget(true);
		UnCaptureEvent(building3M03Target3);
		building3M03Target4.ResetTarget(true);
		UnCaptureEvent(building3M03Target4);
		building3M03Target5.ResetTarget(true);
		UnCaptureEvent(building3M03Target5);
		building3M04Target1.ResetTarget(true);
		UnCaptureEvent(building3M04Target1);
		building3M04Target2.ResetTarget(true);
		UnCaptureEvent(building3M04Target2);
		building3M04Target3.ResetTarget(true);
		UnCaptureEvent(building3M04Target3);
		building3M05Target1.ResetTarget(true);
		UnCaptureEvent(building3M05Target1);
		building3M05Target2.ResetTarget(true);
		UnCaptureEvent(building3M05Target2);
		building3M06Target1.ResetTarget(true);
		UnCaptureEvent(building3M06Target1);
		building3M07Target1.ResetTarget(true);
		UnCaptureEvent(building3M07Target1);
		building3M07Target2.ResetTarget(true);
		UnCaptureEvent(building3M07Target2);
		building3M07Target3.ResetTarget(true);
		UnCaptureEvent(building3M07Target3);
		building3M07Target4.ResetTarget(true);
		UnCaptureEvent(building3M07Target4);
		building3M07Target5.ResetTarget(true);
		UnCaptureEvent(building3M07Target5);
		building3M07Target6.ResetTarget(true);
		UnCaptureEvent(building3M07Target6);
		building3M07Target7.ResetTarget(true);
		UnCaptureEvent(building3M07Target7);
		building3M08Target1.ResetTarget(true);
		UnCaptureEvent(building3M08Target1);
		building3M08Target2.ResetTarget(true);
		UnCaptureEvent(building3M08Target2);
		building3M08Target3.ResetTarget(true);
		UnCaptureEvent(building3M08Target3);
		building3M08Target4.ResetTarget(true);
		UnCaptureEvent(building3M08Target4);
		building3M08Target5.ResetTarget(true);
		UnCaptureEvent(building3M08Target5);
		building3M08Target6.ResetTarget(true);
		UnCaptureEvent(building3M08Target6);
		building3M08Target7.ResetTarget(true);
		UnCaptureEvent(building3M08Target7);
		building3M09Target1.ResetTarget(true);
		UnCaptureEvent(building3M09Target1);
		building3M10Target1.ResetTarget(true);
		UnCaptureEvent(building3M10Target1);
		ChangeState('NoBuildingActive');
	}
}
State Building4Active
{
	Function bool Building4MT_Trigger02AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building4M02Target1=MarksmanTarget(CaptureEvent('Building4Marker02Target01'));
		building4M02Target2=MarksmanTarget(CaptureEvent('Building4Marker02Target02'));
		building4M02Target3=MarksmanTarget(CaptureEvent('Building4Marker02Target03'));
		building4M02Target4=MarksmanTarget(CaptureEvent('Building4Marker02Target04'));
		building4M02Target5=MarksmanTarget(CaptureEvent('Building4Marker02Target05'));
		StartTimer('Building4MT_Trigger02AB_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger02);
		return true;
	}
	Function Building4MT_Trigger02AB_Flip()
	{
		if (building4MTTrigger02.bActive)
		{
			building4M02Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M02Target1);
			building4M02Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M02Target2);
			building4M02Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M02Target3);
			building4M02Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M02Target4);
			building4M02Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M02Target5);
			building4MTTrigger02.DisableTrigger();
			StartTimer('Building4MT_Trigger02AB_Reset',4);
		}
	}
	Function Building4MT_Trigger02AB_Reset()
	{
		building4M02Target1.ResetTarget(true);
		building4M02Target2.ResetTarget(true);
		building4M02Target3.ResetTarget(true);
		building4M02Target4.ResetTarget(true);
		building4M02Target5.ResetTarget(true);
	}
	Function bool Building4MT_Trigger03AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building4M03Target1=MarksmanTarget(CaptureEvent('Building4Marker03Target01'));
		building4M03Target2=MarksmanTarget(CaptureEvent('Building4Marker03Target02'));
		building4M03Target3=MarksmanTarget(CaptureEvent('Building4Marker03Target03'));
		building4M03Target4=MarksmanTarget(CaptureEvent('Building4Marker03Target04'));
		StartTimer('Building4MT_Trigger03AB_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger03);
		return true;
	}
	Function Building4MT_Trigger03AB_Flip()
	{
		if (building4MTTrigger03.bActive)
		{
			building4M03Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M03Target1);
			building4M03Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M03Target2);
			building4M03Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M03Target3);
			building4M03Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M03Target4);
			building4MTTrigger03.DisableTrigger();
			StartTimer('Building4MT_Trigger03AB_Reset',4);
		}
	}
	Function Building4MT_Trigger03AB_Reset()
	{
		building4M03Target1.ResetTarget(true);
		building4M03Target2.ResetTarget(true);
		building4M03Target3.ResetTarget(true);
		building4M03Target4.ResetTarget(true);
	}
	Function bool Building4MT_Trigger04AB_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		building4M04Target1=MarksmanTarget(CaptureEvent('Building4Marker04Target01'));
		building4M04Target2=MarksmanTarget(CaptureEvent('Building4Marker04Target02'));
		building4M04Target3=MarksmanTarget(CaptureEvent('Building4Marker04Target03'));
		building4M04Target4=MarksmanTarget(CaptureEvent('Building4Marker04Target04'));
		building4M04Target5=MarksmanTarget(CaptureEvent('Building4Marker04Target05'));
		StartTimer('Building4MT_Trigger04AB_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger04);
		return true;
	}
	Function Building4MT_Trigger04AB_Flip()
	{
		if (building4MTTrigger04.bActive)
		{
			building4M04Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M04Target1);
			building4M04Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M04Target2);
			building4M04Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M04Target3);
			building4M04Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M04Target4);
			building4M04Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M04Target5);
			building4MTTrigger04.DisableTrigger();
			StartTimer('Building4MT_Trigger04AB_Reset',4);
		}
	}
	Function Building4MT_Trigger04AB_Reset()
	{
		building4M04Target1.ResetTarget(true);
		building4M04Target2.ResetTarget(true);
		building4M04Target3.ResetTarget(true);
		building4M04Target4.ResetTarget(true);
		building4M04Target5.ResetTarget(true);
	}
	Function doorTriggerFlip()
	{
		if (! bbuilding4DoorFlipped)
		{
			building4M01Target1=MarksmanTarget(CaptureEvent('Building4Marker01Target01'));
			building4M01Target2=MarksmanTarget(CaptureEvent('Building4Marker01Target02'));
			building4M01Target3=MarksmanTarget(CaptureEvent('Building4Marker01Target03'));
			building4M01Target4=MarksmanTarget(CaptureEvent('Building4Marker01Target04'));
			building4M01Target5=MarksmanTarget(CaptureEvent('Building4Marker01Target05'));
			building4M01Target6=MarksmanTarget(CaptureEvent('Building4Marker01Target06'));
			building4M01Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target1);
			building4M01Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target2);
			building4M01Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target3);
			building4M01Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target4);
			building4M01Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target5);
			building4M01Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building4M01Target6);
			bbuilding4DoorFlipped=true;
			StartTimer('doorTriggerReset',4);
		}
	}
	Function doorTriggerReset()
	{
		building4M01Target1.ResetTarget(true);
		building4M01Target2.ResetTarget(true);
		building4M01Target3.ResetTarget(true);
		building4M01Target4.ResetTarget(true);
		building4M01Target5.ResetTarget(true);
		building4M01Target6.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'doorTriggerFlip':
			doorTriggerFlip();
			return true;
			case 'doorTriggerReset':
			doorTriggerReset();
			return true;
			case 'Building4MT_Trigger02AB_Flip':
			Building4MT_Trigger02AB_Flip();
			return true;
			case 'Building4MT_Trigger02AB_Reset':
			Building4MT_Trigger02AB_Reset();
			return true;
			case 'Building4MT_Trigger03AB_Flip':
			Building4MT_Trigger03AB_Flip();
			return true;
			case 'Building4MT_Trigger03AB_Reset':
			Building4MT_Trigger03AB_Reset();
			return true;
			case 'Building4MT_Trigger04AB_Flip':
			Building4MT_Trigger04AB_Flip();
			return true;
			case 'Building4MT_Trigger04AB_Reset':
			Building4MT_Trigger04AB_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		if (! building4MTTriggerCaptured)
		{
			building4MTTrigger02=TriggerVolume(CaptureEvent('Building4MT_Trigger02AB'));
			building4MTTrigger03=TriggerVolume(CaptureEvent('Building4MT_Trigger03AB'));
			building4MTTrigger04=TriggerVolume(CaptureEvent('Building4MT_Trigger04AB'));
			building4MTTriggerCaptured=true;
		}
		if (! bAllMTTriggersDisabled)
		{
			StartTimer('doorTriggerFlip',preTimerPause);
		}
	}
}
State Building4InActive extends Building4Active
{
	Function BeginState()
	{
		building4M01Target1.ResetTarget(true);
		UnCaptureEvent(building4M01Target1);
		building4M01Target2.ResetTarget(true);
		UnCaptureEvent(building4M01Target2);
		building4M01Target3.ResetTarget(true);
		UnCaptureEvent(building4M01Target3);
		building4M01Target4.ResetTarget(true);
		UnCaptureEvent(building4M01Target4);
		building4M01Target5.ResetTarget(true);
		UnCaptureEvent(building4M01Target5);
		building4M01Target6.ResetTarget(true);
		UnCaptureEvent(building4M01Target6);
		building4M02Target1.ResetTarget(true);
		UnCaptureEvent(building4M02Target1);
		building4M02Target2.ResetTarget(true);
		UnCaptureEvent(building4M02Target2);
		building4M02Target3.ResetTarget(true);
		UnCaptureEvent(building4M02Target3);
		building4M02Target4.ResetTarget(true);
		UnCaptureEvent(building4M02Target4);
		building4M02Target5.ResetTarget(true);
		UnCaptureEvent(building4M02Target5);
		building4M03Target1.ResetTarget(true);
		UnCaptureEvent(building4M03Target1);
		building4M03Target2.ResetTarget(true);
		UnCaptureEvent(building4M03Target2);
		building4M03Target3.ResetTarget(true);
		UnCaptureEvent(building4M03Target3);
		building4M03Target4.ResetTarget(true);
		UnCaptureEvent(building4M03Target4);
		building4M04Target1.ResetTarget(true);
		UnCaptureEvent(building4M04Target1);
		building4M04Target2.ResetTarget(true);
		UnCaptureEvent(building4M04Target2);
		building4M04Target3.ResetTarget(true);
		UnCaptureEvent(building4M04Target3);
		building4M04Target4.ResetTarget(true);
		UnCaptureEvent(building4M04Target4);
		building4M04Target5.ResetTarget(true);
		UnCaptureEvent(building4M04Target5);
		ChangeState('NoBuildingActive');
	}
}
State Building5Active
{
	Function bool Building5MT_Trigger01A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger01A_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger01);
		return true;
	}
	Function Building5MT_Trigger01A_Flip()
	{
		if (building5MTTrigger01.bActive)
		{
			building5M01Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M01Target1);
			building5M01Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M01Target2);
			building5MTTrigger01.DisableTrigger();
			StartTimer('Building5MT_Trigger01A_Reset',4);
		}
	}
	Function Building5MT_Trigger01A_Reset()
	{
		building5M01Target1.ResetTarget(true);
		building5M01Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger02ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger02ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger02);
		}
		return true;
	}
	Function Building5MT_Trigger02ABC_Flip()
	{
		if (building5MTTrigger02.bActive)
		{
			building5M02Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target1);
			building5M02Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target2);
			building5M02Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target3);
			building5M02Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target4);
			building5M02Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target5);
			building5M02Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M02Target6);
			building5MTTrigger02.DisableTrigger();
			StartTimer('Building5MT_Trigger02ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger02ABC_Reset()
	{
		building5M02Target1.ResetTarget(true);
		building5M02Target2.ResetTarget(true);
		building5M02Target3.ResetTarget(true);
		building5M02Target4.ResetTarget(true);
		building5M02Target5.ResetTarget(true);
		building5M02Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger03ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger03ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger03);
		}
		return true;
	}
	Function Building5MT_Trigger03ABC_Flip()
	{
		if (building5MTTrigger03.bActive)
		{
			building5M03Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target1);
			building5M03Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target2);
			building5M03Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target3);
			building5M03Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target4);
			building5M03Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target5);
			building5M03Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M03Target6);
			building5MTTrigger03.DisableTrigger();
			StartTimer('Building5MT_Trigger03ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger03ABC_Reset()
	{
		building5M03Target1.ResetTarget(true);
		building5M03Target2.ResetTarget(true);
		building5M03Target3.ResetTarget(true);
		building5M03Target4.ResetTarget(true);
		building5M03Target5.ResetTarget(true);
		building5M03Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger04ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger04ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger04);
		}
		return true;
	}
	Function Building5MT_Trigger04ABC_Flip()
	{
		if (building5MTTrigger04.bActive)
		{
			building5M04Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M04Target1);
			building5M04Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M04Target2);
			building5M04Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M04Target3);
			building5M04Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M04Target4);
			building5MTTrigger04.DisableTrigger();
			StartTimer('Building5MT_Trigger04ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger04ABC_Reset()
	{
		building5M04Target1.ResetTarget(true);
		building5M04Target2.ResetTarget(true);
		building5M04Target3.ResetTarget(true);
		building5M04Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger05ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger05ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger05);
		}
		return true;
	}
	Function Building5MT_Trigger05ABC_Flip()
	{
		if (building5MTTrigger05.bActive)
		{
			building5M05Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target1);
			building5M05Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target2);
			building5M05Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target3);
			building5M05Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target4);
			building5M05Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target5);
			building5M05Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target6);
			building5M05Target7.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M05Target7);
			building5MTTrigger05.DisableTrigger();
			StartTimer('Building5MT_Trigger05ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger05ABC_Reset()
	{
		building5M05Target1.ResetTarget(true);
		building5M05Target2.ResetTarget(true);
		building5M05Target3.ResetTarget(true);
		building5M05Target4.ResetTarget(true);
		building5M05Target5.ResetTarget(true);
		building5M05Target6.ResetTarget(true);
		building5M05Target7.ResetTarget(true);
	}
	Function bool Building5MT_Trigger06ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger06ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger06);
		}
		return true;
	}
	Function Building5MT_Trigger06ABC_Flip()
	{
		if (building5MTTrigger06.bActive)
		{
			building5M06Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M06Target1);
			building5M06Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M06Target2);
			building5M06Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M06Target3);
			building5M06Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M06Target4);
			building5M06Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M06Target5);
			building5MTTrigger06.DisableTrigger();
			StartTimer('Building5MT_Trigger06ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger06ABC_Reset()
	{
		building5M06Target1.ResetTarget(true);
		building5M06Target2.ResetTarget(true);
		building5M06Target3.ResetTarget(true);
		building5M06Target4.ResetTarget(true);
		building5M06Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger07ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger07ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger07);
		}
		return true;
	}
	Function Building5MT_Trigger07ABC_Flip()
	{
		if (building5MTTrigger07.bActive)
		{
			building5M07Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M07Target1);
			building5M07Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M07Target2);
			building5M07Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M07Target3);
			building5M07Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M07Target4);
			building5MTTrigger07.DisableTrigger();
			StartTimer('Building5MT_Trigger07ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger07ABC_Reset()
	{
		building5M07Target1.ResetTarget(true);
		building5M07Target2.ResetTarget(true);
		building5M07Target3.ResetTarget(true);
		building5M07Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger08ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger08ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger08);
		}
		return true;
	}
	Function Building5MT_Trigger08ABC_Flip()
	{
		if (building5MTTrigger08.bActive)
		{
			building5M08Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M08Target1);
			building5M08Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M08Target2);
			building5M08Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M08Target3);
			building5MTTrigger08.DisableTrigger();
			StartTimer('Building5MT_Trigger08ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger08ABC_Reset()
	{
		building5M08Target1.ResetTarget(true);
		building5M08Target2.ResetTarget(true);
		building5M08Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger09ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger09ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger09);
		}
		return true;
	}
	Function Building5MT_Trigger09ABC_Flip()
	{
		if (building5MTTrigger09.bActive)
		{
			building5M09Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M09Target1);
			building5M09Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M09Target2);
			building5M09Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M09Target3);
			building5MTTrigger09.DisableTrigger();
			StartTimer('Building5MT_Trigger09ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger09ABC_Reset()
	{
		building5M09Target1.ResetTarget(true);
		building5M09Target2.ResetTarget(true);
		building5M09Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger10ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			StartTimer('Building5MT_Trigger10ABC_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger10);
		}
		return true;
	}
	Function Building5MT_Trigger10ABC_Flip()
	{
		if (building5MTTrigger10.bActive)
		{
			building5M10Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M10Target1);
			building5M10Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M10Target2);
			building5M10Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M10Target3);
			building5M10Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M10Target4);
			building5MTTrigger10.DisableTrigger();
			StartTimer('Building5MT_Trigger10ABC_Reset',4);
		}
	}
	Function Building5MT_Trigger10ABC_Reset()
	{
		building5M10Target1.ResetTarget(true);
		building5M10Target2.ResetTarget(true);
		building5M10Target3.ResetTarget(true);
		building5M10Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger11ABC_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (! door1Entered)
		{
			if (building5MTTrigger11.bActive)
			{
				building5M11Target1=MarksmanTarget(CaptureEvent('building5Marker11Target01'));
				building5M11Target2=MarksmanTarget(CaptureEvent('building5Marker11Target02'));
				building5M11Target3=MarksmanTarget(CaptureEvent('building5Marker11Target03'));
				StartTimer('Building5MT_Trigger12ABCD_Flip',(FRand() * TargetFlipModifier));
			}
		}
		return true;
	}
	Function bool Building5MT_Trigger12ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building5MT_Trigger12ABCD_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger12);
		}
		return true;
	}
	Function Building5MT_Trigger12ABCD_Flip()
	{
		if (building5MTTrigger12.bActive)
		{
			building5M11Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M11Target1);
			building5M11Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M11Target2);
			building5M11Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M11Target3);
			UnCaptureEvent(building5MTTrigger11);
			building5MTTrigger11.DisableTrigger();
			building5MTTrigger12.DisableTrigger();
			StartTimer('Building5MT_Trigger12ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger12ABCD_Reset()
	{
		building5M11Target1.ResetTarget(true);
		building5M11Target2.ResetTarget(true);
		building5M11Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger13ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger13ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger13);
		return true;
	}
	Function Building5MT_Trigger13ABCD_Flip()
	{
		if (building5MTTrigger13.bActive)
		{
			building5M12Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M12Target1);
			building5M12Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M12Target2);
			building5MTTrigger13.DisableTrigger();
			StartTimer('Building5MT_Trigger13ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger13ABCD_Reset()
	{
		building5M12Target1.ResetTarget(true);
		building5M12Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger14ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger14ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger14);
		return true;
	}
	Function Building5MT_Trigger14ABCD_Flip()
	{
		if (building5MTTrigger14.bActive)
		{
			building5M13Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M13Target1);
			building5M13Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M13Target2);
			building5M13Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M13Target3);
			building5M13Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M13Target4);
			building5MTTrigger14.DisableTrigger();
			StartTimer('Building5MT_Trigger14ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger14ABCD_Reset()
	{
		building5M13Target1.ResetTarget(true);
		building5M13Target2.ResetTarget(true);
		building5M13Target3.ResetTarget(true);
		building5M13Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger15ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger15ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger15);
		return true;
	}
	Function Building5MT_Trigger15ABCD_Flip()
	{
		if (building5MTTrigger15.bActive)
		{
			building5M14Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target1);
			building5M14Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target2);
			building5M14Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target3);
			building5M14Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target4);
			building5M14Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target5);
			building5M14Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target6);
			building5M14Target7.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target7);
			building5M14Target8.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M14Target8);
			building5MTTrigger15.DisableTrigger();
			StartTimer('Building5MT_Trigger15ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger15ABCD_Reset()
	{
		building5M14Target1.ResetTarget(true);
		building5M14Target2.ResetTarget(true);
		building5M14Target3.ResetTarget(true);
		building5M14Target4.ResetTarget(true);
		building5M14Target5.ResetTarget(true);
		building5M14Target6.ResetTarget(true);
		building5M14Target7.ResetTarget(true);
		building5M14Target8.ResetTarget(true);
	}
	Function bool Building5MT_Trigger16ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger16ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger16);
		return true;
	}
	Function Building5MT_Trigger16ABCD_Flip()
	{
		if (building5MTTrigger16.bActive)
		{
			building5M15Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M15Target1);
			building5M15Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M15Target2);
			building5M15Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M15Target3);
			building5M15Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M15Target4);
			building5M15Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M15Target5);
			building5MTTrigger16.DisableTrigger();
			StartTimer('Building5MT_Trigger16ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger16ABCD_Reset()
	{
		building5M15Target1.ResetTarget(true);
		building5M15Target2.ResetTarget(true);
		building5M15Target3.ResetTarget(true);
		building5M15Target4.ResetTarget(true);
		building5M15Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger17ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger17ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger17);
		return true;
	}
	Function Building5MT_Trigger17ABCD_Flip()
	{
		if (building5MTTrigger17.bActive)
		{
			building5M16Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target1);
			building5M16Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target2);
			building5M16Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target3);
			building5M16Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target4);
			building5M16Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target5);
			building5M16Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M16Target6);
			building5MTTrigger17.DisableTrigger();
			StartTimer('Building5MT_Trigger17ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger17ABCD_Reset()
	{
		building5M16Target1.ResetTarget(true);
		building5M16Target2.ResetTarget(true);
		building5M16Target3.ResetTarget(true);
		building5M16Target4.ResetTarget(true);
		building5M16Target5.ResetTarget(true);
		building5M16Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger18ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger18ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger18);
		return true;
	}
	Function Building5MT_Trigger18ABCD_Flip()
	{
		if (building5MTTrigger18.bActive)
		{
			building5M17Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M17Target1);
			building5M17Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M17Target2);
			building5MTTrigger18.DisableTrigger();
			StartTimer('Building5MT_Trigger18ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger18ABCD_Reset()
	{
		building5M17Target1.ResetTarget(true);
		building5M17Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger19ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger19ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger19);
		return true;
	}
	Function Building5MT_Trigger19ABCD_Flip()
	{
		if (building5MTTrigger19.bActive)
		{
			building5M18Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M18Target1);
			building5M18Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M18Target2);
			building5M18Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M18Target3);
			building5M18Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M18Target4);
			building5M18Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M18Target5);
			building5MTTrigger19.DisableTrigger();
			StartTimer('Building5MT_Trigger19ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger19ABCD_Reset()
	{
		building5M18Target1.ResetTarget(true);
		building5M18Target2.ResetTarget(true);
		building5M18Target3.ResetTarget(true);
		building5M18Target4.ResetTarget(true);
		building5M18Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger20ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger20ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger20);
		return true;
	}
	Function Building5MT_Trigger20ABCD_Flip()
	{
		if (building5MTTrigger20.bActive)
		{
			building5M19Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M19Target1);
			building5M19Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M19Target2);
			building5M19Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M19Target3);
			building5MTTrigger20.DisableTrigger();
			StartTimer('Building5MT_Trigger20ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger20ABCD_Reset()
	{
		building5M19Target1.ResetTarget(true);
		building5M19Target2.ResetTarget(true);
		building5M19Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger21ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger21ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger21);
		return true;
	}
	Function Building5MT_Trigger21ABCD_Flip()
	{
		if (building5MTTrigger21.bActive)
		{
			building5M20Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M20Target1);
			building5M20Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M20Target2);
			building5M20Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M20Target3);
			building5MTTrigger21.DisableTrigger();
			StartTimer('Building5MT_Trigger21ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger21ABCD_Reset()
	{
		building5M20Target1.ResetTarget(true);
		building5M20Target2.ResetTarget(true);
		building5M20Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger22ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger22ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger22);
		return true;
	}
	Function Building5MT_Trigger22ABCD_Flip()
	{
		if (building5MTTrigger22.bActive)
		{
			building5M21Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M21Target1);
			building5M21Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M21Target2);
			building5M21Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M21Target3);
			building5MTTrigger22.DisableTrigger();
			StartTimer('Building5MT_Trigger22ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger22ABCD_Reset()
	{
		building5M21Target1.ResetTarget(true);
		building5M21Target2.ResetTarget(true);
		building5M21Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger23ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger23ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger23);
		return true;
	}
	Function Building5MT_Trigger23ABCD_Flip()
	{
		if (building5MTTrigger23.bActive)
		{
			building5M22Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M22Target1);
			building5M22Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M22Target2);
			building5M22Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M22Target3);
			building5MTTrigger23.DisableTrigger();
			StartTimer('Building5MT_Trigger23ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger23ABCD_Reset()
	{
		building5M22Target1.ResetTarget(true);
		building5M22Target2.ResetTarget(true);
		building5M22Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger24ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger24ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger24);
		return true;
	}
	Function Building5MT_Trigger24ABCD_Flip()
	{
		if (building5MTTrigger24.bActive)
		{
			building5M23Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M23Target1);
			building5M23Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M23Target2);
			building5M23Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M23Target3);
			building5M23Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M23Target4);
			building5M23Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M23Target5);
			building5MTTrigger24.DisableTrigger();
			StartTimer('Building5MT_Trigger24ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger24ABCD_Reset()
	{
		building5M23Target1.ResetTarget(true);
		building5M23Target2.ResetTarget(true);
		building5M23Target3.ResetTarget(true);
		building5M23Target4.ResetTarget(true);
		building5M23Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger25ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger25ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger25);
		return true;
	}
	Function Building5MT_Trigger25ABCD_Flip()
	{
		if (building5MTTrigger25.bActive)
		{
			building5M24Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M24Target1);
			building5M24Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M24Target2);
			building5M24Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M24Target3);
			building5MTTrigger25.DisableTrigger();
			StartTimer('Building5MT_Trigger25ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger25ABCD_Reset()
	{
		building5M24Target1.ResetTarget(true);
		building5M24Target2.ResetTarget(true);
		building5M24Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger26ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger26ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger26);
		return true;
	}
	Function Building5MT_Trigger26ABCD_Flip()
	{
		if (building5MTTrigger26.bActive)
		{
			building5M25Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M25Target1);
			building5M25Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M25Target2);
			building5M25Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M25Target3);
			building5MTTrigger26.DisableTrigger();
			StartTimer('Building5MT_Trigger26ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger26ABCD_Reset()
	{
		building5M25Target1.ResetTarget(true);
		building5M25Target2.ResetTarget(true);
		building5M25Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger27ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger27ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger27);
		return true;
	}
	Function Building5MT_Trigger27ABCD_Flip()
	{
		if (building5MTTrigger27.bActive)
		{
			building5M26Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M26Target1);
			building5M26Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M26Target2);
			building5M26Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M26Target3);
			building5MTTrigger27.DisableTrigger();
			StartTimer('Building5MT_Trigger27ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger27ABCD_Reset()
	{
		building5M26Target1.ResetTarget(true);
		building5M26Target2.ResetTarget(true);
		building5M26Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger28ABCD_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		StartTimer('Building5MT_Trigger28ABCD_Flip',(FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger28);
		return true;
	}
	Function Building5MT_Trigger28ABCD_Flip()
	{
		if (building5MTTrigger28.bActive)
		{
			building5M27Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M27Target1);
			building5M27Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M27Target2);
			building5M27Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building5M27Target3);
			building5MTTrigger28.DisableTrigger();
			StartTimer('Building5MT_Trigger28ABCD_Reset',4);
		}
	}
	Function Building5MT_Trigger28ABCD_Reset()
	{
		building5M27Target1.ResetTarget(true);
		building5M27Target2.ResetTarget(true);
		building5M27Target3.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Building5MT_Trigger01A_Flip':
			Building5MT_Trigger01A_Flip();
			return true;
			case 'Building5MT_Trigger01A_Reset':
			Building5MT_Trigger01A_Reset();
			return true;
			case 'Building5MT_Trigger02ABC_Flip':
			Building5MT_Trigger02ABC_Flip();
			return true;
			case 'Building5MT_Trigger02ABC_Reset':
			Building5MT_Trigger02ABC_Reset();
			return true;
			case 'Building5MT_Trigger03ABC_Flip':
			Building5MT_Trigger03ABC_Flip();
			return true;
			case 'Building5MT_Trigger03ABC_Reset':
			Building5MT_Trigger03ABC_Reset();
			return true;
			case 'Building5MT_Trigger04ABC_Flip':
			Building5MT_Trigger04ABC_Flip();
			return true;
			case 'Building5MT_Trigger04ABC_Reset':
			Building5MT_Trigger04ABC_Reset();
			return true;
			case 'Building5MT_Trigger05ABC_Flip':
			Building5MT_Trigger05ABC_Flip();
			return true;
			case 'Building5MT_Trigger05ABC_Reset':
			Building5MT_Trigger05ABC_Reset();
			return true;
			case 'Building5MT_Trigger06ABC_Flip':
			Building5MT_Trigger06ABC_Flip();
			return true;
			case 'Building5MT_Trigger06ABC_Reset':
			Building5MT_Trigger06ABC_Reset();
			return true;
			case 'Building5MT_Trigger07ABC_Flip':
			Building5MT_Trigger07ABC_Flip();
			return true;
			case 'Building5MT_Trigger07ABC_Reset':
			Building5MT_Trigger07ABC_Reset();
			return true;
			case 'Building5MT_Trigger08ABC_Flip':
			Building5MT_Trigger08ABC_Flip();
			return true;
			case 'Building5MT_Trigger08ABC_Reset':
			Building5MT_Trigger08ABC_Reset();
			return true;
			case 'Building5MT_Trigger09ABC_Flip':
			Building5MT_Trigger09ABC_Flip();
			return true;
			case 'Building5MT_Trigger09ABC_Reset':
			Building5MT_Trigger09ABC_Reset();
			return true;
			case 'Building5MT_Trigger10ABC_Flip':
			Building5MT_Trigger10ABC_Flip();
			return true;
			case 'Building5MT_Trigger10ABC_Reset':
			Building5MT_Trigger10ABC_Reset();
			return true;
			case 'Building5MT_Trigger12ABCD_Flip':
			Building5MT_Trigger12ABCD_Flip();
			return true;
			case 'Building5MT_Trigger12ABCD_Reset':
			Building5MT_Trigger12ABCD_Reset();
			return true;
			case 'Building5MT_Trigger13ABCD_Flip':
			Building5MT_Trigger13ABCD_Flip();
			return true;
			case 'Building5MT_Trigger13ABCD_Reset':
			Building5MT_Trigger13ABCD_Reset();
			return true;
			case 'Building5MT_Trigger14ABCD_Flip':
			Building5MT_Trigger14ABCD_Flip();
			return true;
			case 'Building5MT_Trigger14ABCD_Reset':
			Building5MT_Trigger14ABCD_Reset();
			return true;
			case 'Building5MT_Trigger15ABCD_Flip':
			Building5MT_Trigger15ABCD_Flip();
			return true;
			case 'Building5MT_Trigger15ABCD_Reset':
			Building5MT_Trigger15ABCD_Reset();
			return true;
			case 'Building5MT_Trigger16ABCD_Flip':
			Building5MT_Trigger16ABCD_Flip();
			return true;
			case 'Building5MT_Trigger16ABCD_Reset':
			Building5MT_Trigger16ABCD_Reset();
			return true;
			case 'Building5MT_Trigger17ABCD_Flip':
			Building5MT_Trigger17ABCD_Flip();
			return true;
			case 'Building5MT_Trigger17ABCD_Reset':
			Building5MT_Trigger17ABCD_Reset();
			return true;
			case 'Building5MT_Trigger18ABCD_Flip':
			Building5MT_Trigger18ABCD_Flip();
			return true;
			case 'Building5MT_Trigger18ABCD_Reset':
			Building5MT_Trigger18ABCD_Reset();
			return true;
			case 'Building5MT_Trigger19ABCD_Flip':
			Building5MT_Trigger19ABCD_Flip();
			return true;
			case 'Building5MT_Trigger19ABCD_Reset':
			Building5MT_Trigger19ABCD_Reset();
			return true;
			case 'Building5MT_Trigger20ABCD_Flip':
			Building5MT_Trigger20ABCD_Flip();
			return true;
			case 'Building5MT_Trigger20ABCD_Reset':
			Building5MT_Trigger20ABCD_Reset();
			return true;
			case 'Building5MT_Trigger21ABCD_Flip':
			Building5MT_Trigger21ABCD_Flip();
			return true;
			case 'Building5MT_Trigger21ABCD_Reset':
			Building5MT_Trigger21ABCD_Reset();
			return true;
			case 'Building5MT_Trigger22ABCD_Flip':
			Building5MT_Trigger22ABCD_Flip();
			return true;
			case 'Building5MT_Trigger22ABCD_Reset':
			Building5MT_Trigger22ABCD_Reset();
			return true;
			case 'Building5MT_Trigger23ABCD_Flip':
			Building5MT_Trigger23ABCD_Flip();
			return true;
			case 'Building5MT_Trigger23ABCD_Reset':
			Building5MT_Trigger23ABCD_Reset();
			return true;
			case 'Building5MT_Trigger24ABCD_Flip':
			Building5MT_Trigger24ABCD_Flip();
			return true;
			case 'Building5MT_Trigger24ABCD_Reset':
			Building5MT_Trigger24ABCD_Reset();
			return true;
			case 'Building5MT_Trigger25ABCD_Flip':
			Building5MT_Trigger25ABCD_Flip();
			return true;
			case 'Building5MT_Trigger25ABCD_Reset':
			Building5MT_Trigger25ABCD_Reset();
			return true;
			case 'Building5MT_Trigger26ABCD_Flip':
			Building5MT_Trigger26ABCD_Flip();
			return true;
			case 'Building5MT_Trigger26ABCD_Reset':
			Building5MT_Trigger26ABCD_Reset();
			return true;
			case 'Building5MT_Trigger27ABCD_Flip':
			Building5MT_Trigger27ABCD_Flip();
			return true;
			case 'Building5MT_Trigger27ABCD_Reset':
			Building5MT_Trigger27ABCD_Reset();
			return true;
			case 'Building5MT_Trigger28ABCD_Flip':
			Building5MT_Trigger28ABCD_Flip();
			return true;
			case 'Building5MT_Trigger28ABCD_Reset':
			Building5MT_Trigger28ABCD_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building5M01Target1=MarksmanTarget(CaptureEvent('building5Marker01Target01'));
		building5M01Target2=MarksmanTarget(CaptureEvent('building5Marker01Target02'));
		building5M02Target1=MarksmanTarget(CaptureEvent('building5Marker02Target01'));
		building5M02Target2=MarksmanTarget(CaptureEvent('building5Marker02Target02'));
		building5M02Target3=MarksmanTarget(CaptureEvent('building5Marker02Target03'));
		building5M02Target4=MarksmanTarget(CaptureEvent('building5Marker02Target04'));
		building5M02Target5=MarksmanTarget(CaptureEvent('building5Marker02Target05'));
		building5M02Target6=MarksmanTarget(CaptureEvent('building5Marker02Target06'));
		building5M03Target1=MarksmanTarget(CaptureEvent('building5Marker03Target01'));
		building5M03Target2=MarksmanTarget(CaptureEvent('building5Marker03Target02'));
		building5M03Target3=MarksmanTarget(CaptureEvent('building5Marker03Target03'));
		building5M03Target4=MarksmanTarget(CaptureEvent('building5Marker03Target04'));
		building5M03Target5=MarksmanTarget(CaptureEvent('building5Marker03Target05'));
		building5M03Target6=MarksmanTarget(CaptureEvent('building5Marker03Target06'));
		building5M04Target1=MarksmanTarget(CaptureEvent('building5Marker04Target01'));
		building5M04Target2=MarksmanTarget(CaptureEvent('building5Marker04Target02'));
		building5M04Target3=MarksmanTarget(CaptureEvent('building5Marker04Target03'));
		building5M04Target4=MarksmanTarget(CaptureEvent('building5Marker04Target04'));
		building5M05Target1=MarksmanTarget(CaptureEvent('building5Marker05Target01'));
		building5M05Target2=MarksmanTarget(CaptureEvent('building5Marker05Target02'));
		building5M05Target3=MarksmanTarget(CaptureEvent('building5Marker05Target03'));
		building5M05Target4=MarksmanTarget(CaptureEvent('building5Marker05Target04'));
		building5M05Target5=MarksmanTarget(CaptureEvent('building5Marker05Target05'));
		building5M05Target6=MarksmanTarget(CaptureEvent('building5Marker05Target06'));
		building5M05Target7=MarksmanTarget(CaptureEvent('building5Marker05Target07'));
		building5M06Target1=MarksmanTarget(CaptureEvent('building5Marker06Target01'));
		building5M06Target2=MarksmanTarget(CaptureEvent('building5Marker06Target02'));
		building5M06Target3=MarksmanTarget(CaptureEvent('building5Marker06Target03'));
		building5M06Target4=MarksmanTarget(CaptureEvent('building5Marker06Target04'));
		building5M06Target5=MarksmanTarget(CaptureEvent('building5Marker06Target05'));
		building5M07Target1=MarksmanTarget(CaptureEvent('building5Marker07Target01'));
		building5M07Target2=MarksmanTarget(CaptureEvent('building5Marker07Target02'));
		building5M07Target3=MarksmanTarget(CaptureEvent('building5Marker07Target03'));
		building5M07Target4=MarksmanTarget(CaptureEvent('building5Marker07Target04'));
		building5M08Target1=MarksmanTarget(CaptureEvent('building5Marker08Target01'));
		building5M08Target2=MarksmanTarget(CaptureEvent('building5Marker08Target02'));
		building5M08Target3=MarksmanTarget(CaptureEvent('building5Marker08Target03'));
		building5M09Target1=MarksmanTarget(CaptureEvent('building5Marker09Target01'));
		building5M09Target2=MarksmanTarget(CaptureEvent('building5Marker09Target02'));
		building5M09Target3=MarksmanTarget(CaptureEvent('building5Marker09Target03'));
		building5M10Target1=MarksmanTarget(CaptureEvent('building5Marker10Target01'));
		building5M10Target2=MarksmanTarget(CaptureEvent('building5Marker10Target02'));
		building5M10Target3=MarksmanTarget(CaptureEvent('building5Marker10Target03'));
		building5M10Target4=MarksmanTarget(CaptureEvent('building5Marker10Target04'));
		building5M11Target1=MarksmanTarget(CaptureEvent('building5Marker11Target01'));
		building5M11Target2=MarksmanTarget(CaptureEvent('building5Marker11Target02'));
		building5M11Target3=MarksmanTarget(CaptureEvent('building5Marker11Target03'));
		building5M12Target1=MarksmanTarget(CaptureEvent('building5Marker12Target01'));
		building5M12Target2=MarksmanTarget(CaptureEvent('building5Marker12Target02'));
		building5M13Target1=MarksmanTarget(CaptureEvent('building5Marker13Target01'));
		building5M13Target2=MarksmanTarget(CaptureEvent('building5Marker13Target02'));
		building5M13Target3=MarksmanTarget(CaptureEvent('building5Marker13Target03'));
		building5M13Target4=MarksmanTarget(CaptureEvent('building5Marker13Target04'));
		building5M14Target1=MarksmanTarget(CaptureEvent('building5Marker14Target01'));
		building5M14Target2=MarksmanTarget(CaptureEvent('building5Marker14Target02'));
		building5M14Target3=MarksmanTarget(CaptureEvent('building5Marker14Target03'));
		building5M14Target4=MarksmanTarget(CaptureEvent('building5Marker14Target04'));
		building5M14Target5=MarksmanTarget(CaptureEvent('building5Marker14Target05'));
		building5M14Target6=MarksmanTarget(CaptureEvent('building5Marker14Target06'));
		building5M14Target7=MarksmanTarget(CaptureEvent('building5Marker14Target07'));
		building5M14Target8=MarksmanTarget(CaptureEvent('building5Marker14Target08'));
		building5M15Target1=MarksmanTarget(CaptureEvent('building5Marker15Target01'));
		building5M15Target2=MarksmanTarget(CaptureEvent('building5Marker15Target02'));
		building5M15Target3=MarksmanTarget(CaptureEvent('building5Marker15Target03'));
		building5M15Target4=MarksmanTarget(CaptureEvent('building5Marker15Target04'));
		building5M15Target5=MarksmanTarget(CaptureEvent('building5Marker15Target05'));
		building5M16Target1=MarksmanTarget(CaptureEvent('building5Marker16Target01'));
		building5M16Target2=MarksmanTarget(CaptureEvent('building5Marker16Target02'));
		building5M16Target3=MarksmanTarget(CaptureEvent('building5Marker16Target03'));
		building5M16Target4=MarksmanTarget(CaptureEvent('building5Marker16Target04'));
		building5M16Target5=MarksmanTarget(CaptureEvent('building5Marker16Target05'));
		building5M16Target6=MarksmanTarget(CaptureEvent('building5Marker16Target06'));
		building5M17Target1=MarksmanTarget(CaptureEvent('building5Marker17Target01'));
		building5M17Target2=MarksmanTarget(CaptureEvent('building5Marker17Target02'));
		building5M18Target1=MarksmanTarget(CaptureEvent('building5Marker18Target01'));
		building5M18Target2=MarksmanTarget(CaptureEvent('building5Marker18Target02'));
		building5M18Target3=MarksmanTarget(CaptureEvent('building5Marker18Target03'));
		building5M18Target4=MarksmanTarget(CaptureEvent('building5Marker18Target04'));
		building5M18Target5=MarksmanTarget(CaptureEvent('building5Marker18Target05'));
		building5M19Target1=MarksmanTarget(CaptureEvent('building5Marker19Target01'));
		building5M19Target2=MarksmanTarget(CaptureEvent('building5Marker19Target02'));
		building5M19Target3=MarksmanTarget(CaptureEvent('building5Marker19Target03'));
		building5M20Target1=MarksmanTarget(CaptureEvent('building5Marker20Target01'));
		building5M20Target2=MarksmanTarget(CaptureEvent('building5Marker20Target02'));
		building5M20Target3=MarksmanTarget(CaptureEvent('building5Marker20Target03'));
		building5M21Target1=MarksmanTarget(CaptureEvent('building5Marker21Target01'));
		building5M21Target2=MarksmanTarget(CaptureEvent('building5Marker21Target02'));
		building5M21Target3=MarksmanTarget(CaptureEvent('building5Marker21Target03'));
		building5M22Target1=MarksmanTarget(CaptureEvent('building5Marker22Target01'));
		building5M22Target2=MarksmanTarget(CaptureEvent('building5Marker22Target02'));
		building5M22Target3=MarksmanTarget(CaptureEvent('building5Marker22Target03'));
		building5M23Target1=MarksmanTarget(CaptureEvent('building5Marker23Target01'));
		building5M23Target2=MarksmanTarget(CaptureEvent('building5Marker23Target02'));
		building5M23Target3=MarksmanTarget(CaptureEvent('building5Marker23Target03'));
		building5M23Target4=MarksmanTarget(CaptureEvent('building5Marker23Target04'));
		building5M23Target5=MarksmanTarget(CaptureEvent('building5Marker23Target05'));
		building5M24Target1=MarksmanTarget(CaptureEvent('building5Marker24Target01'));
		building5M24Target2=MarksmanTarget(CaptureEvent('building5Marker24Target02'));
		building5M24Target3=MarksmanTarget(CaptureEvent('building5Marker24Target03'));
		building5M25Target1=MarksmanTarget(CaptureEvent('building5Marker25Target01'));
		building5M25Target2=MarksmanTarget(CaptureEvent('building5Marker25Target02'));
		building5M25Target3=MarksmanTarget(CaptureEvent('building5Marker25Target03'));
		building5M26Target1=MarksmanTarget(CaptureEvent('building5Marker26Target01'));
		building5M26Target2=MarksmanTarget(CaptureEvent('building5Marker26Target02'));
		building5M26Target3=MarksmanTarget(CaptureEvent('building5Marker26Target03'));
		building5M27Target1=MarksmanTarget(CaptureEvent('building5Marker27Target01'));
		building5M27Target2=MarksmanTarget(CaptureEvent('building5Marker27Target02'));
		building5M27Target3=MarksmanTarget(CaptureEvent('building5Marker27Target03'));
		if (door1Entered)
		{
			building5M02Target1.bHidden=true;
			building5M02Target2.bHidden=true;
			building5M02Target3.bHidden=true;
			building5M02Target4.bHidden=true;
			building5M02Target5.bHidden=true;
			building5M02Target6.bHidden=true;
			building5M03Target1.bHidden=true;
			building5M03Target2.bHidden=true;
			building5M03Target3.bHidden=true;
			building5M03Target4.bHidden=true;
			building5M03Target5.bHidden=true;
			building5M03Target6.bHidden=true;
			building5M04Target1.bHidden=true;
			building5M04Target2.bHidden=true;
			building5M04Target3.bHidden=true;
			building5M04Target4.bHidden=true;
			building5M05Target1.bHidden=true;
			building5M05Target2.bHidden=true;
			building5M05Target3.bHidden=true;
			building5M05Target4.bHidden=true;
			building5M05Target5.bHidden=true;
			building5M05Target6.bHidden=true;
			building5M05Target7.bHidden=true;
			building5M06Target1.bHidden=true;
			building5M06Target2.bHidden=true;
			building5M06Target3.bHidden=true;
			building5M06Target4.bHidden=true;
			building5M06Target5.bHidden=true;
			building5M07Target1.bHidden=true;
			building5M07Target2.bHidden=true;
			building5M07Target3.bHidden=true;
			building5M07Target4.bHidden=true;
			building5M08Target1.bHidden=true;
			building5M08Target2.bHidden=true;
			building5M08Target3.bHidden=true;
			building5M09Target1.bHidden=true;
			building5M09Target2.bHidden=true;
			building5M09Target3.bHidden=true;
			building5M10Target1.bHidden=true;
			building5M10Target2.bHidden=true;
			building5M10Target3.bHidden=true;
			building5M10Target4.bHidden=true;
		}
		else
		{
			building5M02Target1.bHidden=false;
			building5M02Target2.bHidden=false;
			building5M02Target3.bHidden=false;
			building5M02Target4.bHidden=false;
			building5M02Target5.bHidden=false;
			building5M02Target6.bHidden=false;
			building5M03Target1.bHidden=false;
			building5M03Target2.bHidden=false;
			building5M03Target3.bHidden=false;
			building5M03Target4.bHidden=false;
			building5M03Target5.bHidden=false;
			building5M03Target6.bHidden=false;
			building5M04Target1.bHidden=false;
			building5M04Target2.bHidden=false;
			building5M04Target3.bHidden=false;
			building5M04Target4.bHidden=false;
			building5M05Target1.bHidden=false;
			building5M05Target2.bHidden=false;
			building5M05Target3.bHidden=false;
			building5M05Target4.bHidden=false;
			building5M05Target5.bHidden=false;
			building5M05Target6.bHidden=false;
			building5M05Target7.bHidden=false;
			building5M06Target1.bHidden=false;
			building5M06Target2.bHidden=false;
			building5M06Target3.bHidden=false;
			building5M06Target4.bHidden=false;
			building5M06Target5.bHidden=false;
			building5M07Target1.bHidden=false;
			building5M07Target2.bHidden=false;
			building5M07Target3.bHidden=false;
			building5M07Target4.bHidden=false;
			building5M08Target1.bHidden=false;
			building5M08Target2.bHidden=false;
			building5M08Target3.bHidden=false;
			building5M09Target1.bHidden=false;
			building5M09Target2.bHidden=false;
			building5M09Target3.bHidden=false;
			building5M10Target1.bHidden=false;
			building5M10Target2.bHidden=false;
			building5M10Target3.bHidden=false;
			building5M10Target4.bHidden=false;
		}
		if (! building5MTTriggerCaptured)
		{
			building5MTTrigger01=TriggerVolume(CaptureEvent('Building5MT_Trigger01A'));
			building5MTTrigger02=TriggerVolume(CaptureEvent('Building5MT_Trigger02ABC'));
			building5MTTrigger03=TriggerVolume(CaptureEvent('Building5MT_Trigger03ABC'));
			building5MTTrigger04=TriggerVolume(CaptureEvent('Building5MT_Trigger04ABC'));
			building5MTTrigger05=TriggerVolume(CaptureEvent('Building5MT_Trigger05ABC'));
			building5MTTrigger06=TriggerVolume(CaptureEvent('Building5MT_Trigger06ABC'));
			building5MTTrigger07=TriggerVolume(CaptureEvent('Building5MT_Trigger07ABC'));
			building5MTTrigger08=TriggerVolume(CaptureEvent('Building5MT_Trigger08ABC'));
			building5MTTrigger09=TriggerVolume(CaptureEvent('Building5MT_Trigger09ABC'));
			building5MTTrigger10=TriggerVolume(CaptureEvent('Building5MT_Trigger10ABC'));
			building5MTTrigger11=TriggerVolume(CaptureEvent('Building5MT_Trigger11ABC'));
			building5MTTrigger12=TriggerVolume(CaptureEvent('Building5MT_Trigger12ABCD'));
			building5MTTrigger13=TriggerVolume(CaptureEvent('Building5MT_Trigger13ABCD'));
			building5MTTrigger14=TriggerVolume(CaptureEvent('Building5MT_Trigger14ABCD'));
			building5MTTrigger15=TriggerVolume(CaptureEvent('Building5MT_Trigger15ABCD'));
			building5MTTrigger16=TriggerVolume(CaptureEvent('Building5MT_Trigger16ABCD'));
			building5MTTrigger17=TriggerVolume(CaptureEvent('Building5MT_Trigger17ABCD'));
			building5MTTrigger18=TriggerVolume(CaptureEvent('Building5MT_Trigger18ABCD'));
			building5MTTrigger19=TriggerVolume(CaptureEvent('Building5MT_Trigger19ABCD'));
			building5MTTrigger20=TriggerVolume(CaptureEvent('Building5MT_Trigger20ABCD'));
			building5MTTrigger21=TriggerVolume(CaptureEvent('Building5MT_Trigger21ABCD'));
			building5MTTrigger22=TriggerVolume(CaptureEvent('Building5MT_Trigger22ABCD'));
			building5MTTrigger23=TriggerVolume(CaptureEvent('Building5MT_Trigger23ABCD'));
			building5MTTrigger24=TriggerVolume(CaptureEvent('Building5MT_Trigger24ABCD'));
			building5MTTrigger25=TriggerVolume(CaptureEvent('Building5MT_Trigger25ABCD'));
			building5MTTrigger26=TriggerVolume(CaptureEvent('Building5MT_Trigger26ABCD'));
			building5MTTrigger27=TriggerVolume(CaptureEvent('Building5MT_Trigger27ABCD'));
			building5MTTrigger28=TriggerVolume(CaptureEvent('Building5MT_Trigger28ABCD'));
			building5MTTriggerCaptured=true;
		}
	}
}
State Building5InActive extends Building5Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		door3Entered=false;
		door4Entered=false;
		building5M01Target1.ResetTarget(true);
		UnCaptureEvent(building5M01Target1);
		building5M01Target2.ResetTarget(true);
		UnCaptureEvent(building5M01Target2);
		building5M02Target1.ResetTarget(true);
		UnCaptureEvent(building5M02Target1);
		building5M02Target2.ResetTarget(true);
		UnCaptureEvent(building5M02Target2);
		building5M02Target3.ResetTarget(true);
		UnCaptureEvent(building5M02Target3);
		building5M02Target4.ResetTarget(true);
		UnCaptureEvent(building5M02Target4);
		building5M02Target5.ResetTarget(true);
		UnCaptureEvent(building5M02Target5);
		building5M02Target6.ResetTarget(true);
		UnCaptureEvent(building5M02Target6);
		building5M03Target1.ResetTarget(true);
		UnCaptureEvent(building5M03Target1);
		building5M03Target2.ResetTarget(true);
		UnCaptureEvent(building5M03Target2);
		building5M03Target3.ResetTarget(true);
		UnCaptureEvent(building5M03Target3);
		building5M03Target4.ResetTarget(true);
		UnCaptureEvent(building5M03Target4);
		building5M03Target5.ResetTarget(true);
		UnCaptureEvent(building5M03Target5);
		building5M03Target6.ResetTarget(true);
		UnCaptureEvent(building5M03Target6);
		building5M04Target1.ResetTarget(true);
		UnCaptureEvent(building5M04Target1);
		building5M04Target2.ResetTarget(true);
		UnCaptureEvent(building5M04Target2);
		building5M04Target3.ResetTarget(true);
		UnCaptureEvent(building5M04Target3);
		building5M04Target4.ResetTarget(true);
		UnCaptureEvent(building5M04Target4);
		building5M05Target1.ResetTarget(true);
		UnCaptureEvent(building5M05Target1);
		building5M05Target2.ResetTarget(true);
		UnCaptureEvent(building5M05Target2);
		building5M05Target3.ResetTarget(true);
		UnCaptureEvent(building5M05Target3);
		building5M05Target4.ResetTarget(true);
		UnCaptureEvent(building5M05Target4);
		building5M05Target5.ResetTarget(true);
		UnCaptureEvent(building5M05Target5);
		building5M05Target6.ResetTarget(true);
		UnCaptureEvent(building5M05Target6);
		building5M05Target7.ResetTarget(true);
		UnCaptureEvent(building5M05Target7);
		building5M06Target1.ResetTarget(true);
		UnCaptureEvent(building5M06Target1);
		building5M06Target2.ResetTarget(true);
		UnCaptureEvent(building5M06Target2);
		building5M06Target3.ResetTarget(true);
		UnCaptureEvent(building5M06Target3);
		building5M06Target4.ResetTarget(true);
		UnCaptureEvent(building5M06Target4);
		building5M06Target5.ResetTarget(true);
		UnCaptureEvent(building5M06Target5);
		building5M07Target1.ResetTarget(true);
		UnCaptureEvent(building5M07Target1);
		building5M07Target2.ResetTarget(true);
		UnCaptureEvent(building5M07Target2);
		building5M07Target3.ResetTarget(true);
		UnCaptureEvent(building5M07Target3);
		building5M07Target4.ResetTarget(true);
		UnCaptureEvent(building5M07Target4);
		building5M08Target1.ResetTarget(true);
		UnCaptureEvent(building5M08Target1);
		building5M08Target2.ResetTarget(true);
		UnCaptureEvent(building5M08Target2);
		building5M08Target3.ResetTarget(true);
		UnCaptureEvent(building5M08Target3);
		building5M09Target1.ResetTarget(true);
		UnCaptureEvent(building5M09Target1);
		building5M09Target2.ResetTarget(true);
		UnCaptureEvent(building5M09Target2);
		building5M09Target3.ResetTarget(true);
		UnCaptureEvent(building5M09Target3);
		building5M10Target1.ResetTarget(true);
		UnCaptureEvent(building5M10Target1);
		building5M10Target2.ResetTarget(true);
		UnCaptureEvent(building5M10Target2);
		building5M10Target3.ResetTarget(true);
		UnCaptureEvent(building5M10Target3);
		building5M10Target4.ResetTarget(true);
		UnCaptureEvent(building5M10Target4);
		building5M11Target1.ResetTarget(true);
		UnCaptureEvent(building5M11Target1);
		building5M11Target2.ResetTarget(true);
		UnCaptureEvent(building5M11Target2);
		building5M11Target3.ResetTarget(true);
		UnCaptureEvent(building5M11Target3);
		building5M12Target1.ResetTarget(true);
		UnCaptureEvent(building5M12Target1);
		building5M12Target2.ResetTarget(true);
		UnCaptureEvent(building5M12Target2);
		building5M13Target1.ResetTarget(true);
		UnCaptureEvent(building5M13Target1);
		building5M13Target2.ResetTarget(true);
		UnCaptureEvent(building5M13Target2);
		building5M13Target3.ResetTarget(true);
		UnCaptureEvent(building5M13Target3);
		building5M13Target4.ResetTarget(true);
		UnCaptureEvent(building5M13Target4);
		building5M14Target1.ResetTarget(true);
		UnCaptureEvent(building5M14Target1);
		building5M14Target2.ResetTarget(true);
		UnCaptureEvent(building5M14Target2);
		building5M14Target3.ResetTarget(true);
		UnCaptureEvent(building5M14Target3);
		building5M14Target4.ResetTarget(true);
		UnCaptureEvent(building5M14Target4);
		building5M14Target5.ResetTarget(true);
		UnCaptureEvent(building5M14Target5);
		building5M14Target6.ResetTarget(true);
		UnCaptureEvent(building5M14Target6);
		building5M14Target7.ResetTarget(true);
		UnCaptureEvent(building5M14Target7);
		building5M14Target8.ResetTarget(true);
		UnCaptureEvent(building5M14Target8);
		building5M15Target1.ResetTarget(true);
		UnCaptureEvent(building5M15Target1);
		building5M15Target2.ResetTarget(true);
		UnCaptureEvent(building5M15Target2);
		building5M15Target3.ResetTarget(true);
		UnCaptureEvent(building5M15Target3);
		building5M15Target4.ResetTarget(true);
		UnCaptureEvent(building5M15Target4);
		building5M15Target5.ResetTarget(true);
		UnCaptureEvent(building5M15Target5);
		building5M16Target1.ResetTarget(true);
		UnCaptureEvent(building5M16Target1);
		building5M16Target2.ResetTarget(true);
		UnCaptureEvent(building5M16Target2);
		building5M16Target3.ResetTarget(true);
		UnCaptureEvent(building5M16Target3);
		building5M16Target4.ResetTarget(true);
		UnCaptureEvent(building5M16Target4);
		building5M16Target5.ResetTarget(true);
		UnCaptureEvent(building5M16Target5);
		building5M16Target6.ResetTarget(true);
		UnCaptureEvent(building5M16Target6);
		building5M17Target1.ResetTarget(true);
		UnCaptureEvent(building5M17Target1);
		building5M17Target2.ResetTarget(true);
		UnCaptureEvent(building5M17Target2);
		building5M18Target1.ResetTarget(true);
		UnCaptureEvent(building5M18Target1);
		building5M18Target2.ResetTarget(true);
		UnCaptureEvent(building5M18Target2);
		building5M18Target3.ResetTarget(true);
		UnCaptureEvent(building5M18Target3);
		building5M18Target4.ResetTarget(true);
		UnCaptureEvent(building5M18Target4);
		building5M18Target5.ResetTarget(true);
		UnCaptureEvent(building5M18Target5);
		building5M19Target1.ResetTarget(true);
		UnCaptureEvent(building5M19Target1);
		building5M19Target2.ResetTarget(true);
		UnCaptureEvent(building5M19Target2);
		building5M19Target3.ResetTarget(true);
		UnCaptureEvent(building5M19Target3);
		building5M20Target1.ResetTarget(true);
		UnCaptureEvent(building5M20Target1);
		building5M20Target2.ResetTarget(true);
		UnCaptureEvent(building5M20Target2);
		building5M20Target3.ResetTarget(true);
		UnCaptureEvent(building5M20Target3);
		building5M21Target1.ResetTarget(true);
		UnCaptureEvent(building5M21Target1);
		building5M21Target2.ResetTarget(true);
		UnCaptureEvent(building5M21Target2);
		building5M21Target3.ResetTarget(true);
		UnCaptureEvent(building5M21Target3);
		building5M22Target1.ResetTarget(true);
		UnCaptureEvent(building5M22Target1);
		building5M22Target2.ResetTarget(true);
		UnCaptureEvent(building5M22Target2);
		building5M22Target3.ResetTarget(true);
		UnCaptureEvent(building5M22Target3);
		building5M23Target1.ResetTarget(true);
		UnCaptureEvent(building5M23Target1);
		building5M23Target2.ResetTarget(true);
		UnCaptureEvent(building5M23Target2);
		building5M23Target3.ResetTarget(true);
		UnCaptureEvent(building5M23Target3);
		building5M23Target4.ResetTarget(true);
		UnCaptureEvent(building5M23Target4);
		building5M23Target5.ResetTarget(true);
		UnCaptureEvent(building5M23Target5);
		building5M24Target1.ResetTarget(true);
		UnCaptureEvent(building5M24Target1);
		building5M24Target2.ResetTarget(true);
		UnCaptureEvent(building5M24Target2);
		building5M24Target3.ResetTarget(true);
		UnCaptureEvent(building5M24Target3);
		building5M25Target1.ResetTarget(true);
		UnCaptureEvent(building5M25Target1);
		building5M25Target2.ResetTarget(true);
		UnCaptureEvent(building5M25Target2);
		building5M25Target3.ResetTarget(true);
		UnCaptureEvent(building5M25Target3);
		building5M26Target1.ResetTarget(true);
		UnCaptureEvent(building5M26Target1);
		building5M26Target2.ResetTarget(true);
		UnCaptureEvent(building5M26Target2);
		building5M26Target3.ResetTarget(true);
		UnCaptureEvent(building5M26Target3);
		building5M27Target1.ResetTarget(true);
		UnCaptureEvent(building5M27Target1);
		building5M27Target2.ResetTarget(true);
		UnCaptureEvent(building5M27Target2);
		building5M27Target3.ResetTarget(true);
		UnCaptureEvent(building5M27Target3);
		ChangeState('NoBuildingActive');
	}
}
State Building6Active
{
	Function bool Building6MT_Trigger01B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building6MT_Trigger01B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger01);
		}
		return true;
	}
	Function Building6MT_Trigger01B_Flip()
	{
		if (building6MTTrigger01.bActive)
		{
			building6M01Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M01Target1);
			building6M01Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M01Target2);
			building6M01Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M01Target3);
			building6M02Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M02Target1);
			building6M02Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M02Target2);
			building6M02Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M02Target3);
			building6M03Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target1);
			building6M03Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target2);
			building6M03Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target3);
			building6M03Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target4);
			building6M03Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target5);
			building6M03Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target6);
			building6M03Target7.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M03Target7);
			building6M04Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M04Target1);
			building6M04Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M04Target2);
			building6M04Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M04Target3);
			building6MTTrigger01.DisableTrigger();
			StartTimer('Building6MT_Trigger01B_Reset',4);
		}
	}
	Function Building6MT_Trigger01B_Reset()
	{
		building6M01Target1.ResetTarget(true);
		building6M01Target2.ResetTarget(true);
		building6M01Target3.ResetTarget(true);
		building6M02Target1.ResetTarget(true);
		building6M02Target2.ResetTarget(true);
		building6M02Target3.ResetTarget(true);
		building6M03Target1.ResetTarget(true);
		building6M03Target2.ResetTarget(true);
		building6M03Target3.ResetTarget(true);
		building6M03Target4.ResetTarget(true);
		building6M03Target5.ResetTarget(true);
		building6M03Target6.ResetTarget(true);
		building6M03Target7.ResetTarget(true);
		building6M04Target1.ResetTarget(true);
		building6M04Target2.ResetTarget(true);
		building6M04Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building6MT_Trigger02B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger02);
		}
		return true;
	}
	Function Building6MT_Trigger02B_Flip()
	{
		if (building6MTTrigger02.bActive)
		{
			building6M05Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M05Target1);
			building6M05Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M05Target2);
			building6M05Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M05Target3);
			building6MTTrigger02.DisableTrigger();
			StartTimer('Building6MT_Trigger02B_Reset',4);
		}
	}
	Function Building6MT_Trigger02B_Reset()
	{
		building6M05Target1.ResetTarget(true);
		building6M05Target2.ResetTarget(true);
		building6M05Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building6MT_Trigger03B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger03);
		}
		return true;
	}
	Function Building6MT_Trigger03B_Flip()
	{
		if (building6MTTrigger03.bActive)
		{
			building6M06Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M06Target1);
			building6M06Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M06Target2);
			building6M07Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M07Target1);
			building6M07Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M07Target2);
			building6M07Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M07Target3);
			building6MTTrigger03.DisableTrigger();
			StartTimer('Building6MT_Trigger03B_Reset',4);
		}
	}
	Function Building6MT_Trigger03B_Reset()
	{
		building6M06Target1.ResetTarget(true);
		building6M06Target2.ResetTarget(true);
		building6M07Target1.ResetTarget(true);
		building6M07Target2.ResetTarget(true);
		building6M07Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door1Entered)
		{
			StartTimer('Building6MT_Trigger04B_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger04);
		}
		return true;
	}
	Function Building6MT_Trigger04B_Flip()
	{
		if (building6MTTrigger04.bActive)
		{
			building6M08Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M08Target1);
			building6M08Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M08Target2);
			building6M08Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M08Target3);
			building6MTTrigger04.DisableTrigger();
			StartTimer('Building6MT_Trigger04B_Reset',4);
		}
	}
	Function Building6MT_Trigger04B_Reset()
	{
		building6M08Target1.ResetTarget(true);
		building6M08Target2.ResetTarget(true);
		building6M08Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger05A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Building6MT_Trigger05A_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger05);
		}
		return true;
	}
	Function Building6MT_Trigger05A_Flip()
	{
		if (building6MTTrigger05.bActive)
		{
			building6M09Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M09Target1);
			building6M09Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M09Target2);
			building6M09Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M09Target3);
			building6M09Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M09Target4);
			building6M09Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M09Target5);
			building6M10Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M10Target1);
			building6M10Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M10Target2);
			building6M11Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M11Target1);
			building6M11Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M11Target2);
			building6M12Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M12Target1);
			building6M12Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M12Target2);
			building6MTTrigger05.DisableTrigger();
			StartTimer('Building6MT_Trigger05A_Reset',4);
		}
	}
	Function Building6MT_Trigger05A_Reset()
	{
		building6M09Target1.ResetTarget(true);
		building6M09Target2.ResetTarget(true);
		building6M09Target3.ResetTarget(true);
		building6M09Target4.ResetTarget(true);
		building6M09Target5.ResetTarget(true);
		building6M10Target1.ResetTarget(true);
		building6M10Target2.ResetTarget(true);
		building6M11Target1.ResetTarget(true);
		building6M11Target2.ResetTarget(true);
		building6M12Target1.ResetTarget(true);
		building6M12Target2.ResetTarget(true);
	}
	Function bool Building6MT_Trigger06A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Building6MT_Trigger06A_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger06);
		}
		return true;
	}
	Function Building6MT_Trigger06A_Flip()
	{
		if (building6MTTrigger06.bActive)
		{
			building6M13Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target1);
			building6M13Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target2);
			building6M13Target3.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target3);
			building6M13Target4.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target4);
			building6M13Target5.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target5);
			building6M13Target6.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M13Target6);
			building6MTTrigger06.DisableTrigger();
			StartTimer('Building6MT_Trigger06A_Reset',4);
		}
	}
	Function Building6MT_Trigger06A_Reset()
	{
		building6M13Target1.ResetTarget(true);
		building6M13Target2.ResetTarget(true);
		building6M13Target3.ResetTarget(true);
		building6M13Target4.ResetTarget(true);
		building6M13Target5.ResetTarget(true);
		building6M13Target6.ResetTarget(true);
	}
	Function bool Building6MT_Trigger07A_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		if (door2Entered)
		{
			StartTimer('Building6MT_Trigger07A_Flip',(FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger07);
		}
		return true;
	}
	Function Building6MT_Trigger07A_Flip()
	{
		if (building6MTTrigger07.bActive)
		{
			building6M14Target1.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M14Target1);
			building6M14Target2.TriggerSelf();
			PlayGameSound('m_hydraulic',building6M14Target2);
			building6MTTrigger07.DisableTrigger();
			StartTimer('Building6MT_Trigger07A_Reset',4);
		}
	}
	Function Building6MT_Trigger07A_Reset()
	{
		building6M14Target1.ResetTarget(true);
		building6M14Target2.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Building6MT_Trigger01B_Flip':
			Building6MT_Trigger01B_Flip();
			return true;
			case 'Building6MT_Trigger01B_Reset':
			Building6MT_Trigger01B_Reset();
			return true;
			case 'Building6MT_Trigger02B_Flip':
			Building6MT_Trigger02B_Flip();
			return true;
			case 'Building6MT_Trigger02B_Reset':
			Building6MT_Trigger02B_Reset();
			return true;
			case 'Building6MT_Trigger03B_Flip':
			Building6MT_Trigger03B_Flip();
			return true;
			case 'Building6MT_Trigger03B_Reset':
			Building6MT_Trigger03B_Reset();
			return true;
			case 'Building6MT_Trigger04B_Flip':
			Building6MT_Trigger04B_Flip();
			return true;
			case 'Building6MT_Trigger04B_Reset':
			Building6MT_Trigger04B_Reset();
			return true;
			case 'Building6MT_Trigger05A_Flip':
			Building6MT_Trigger05A_Flip();
			return true;
			case 'Building6MT_Trigger05A_Reset':
			Building6MT_Trigger05A_Reset();
			return true;
			case 'Building6MT_Trigger06A_Flip':
			Building6MT_Trigger06A_Flip();
			return true;
			case 'Building6MT_Trigger06A_Reset':
			Building6MT_Trigger06A_Reset();
			return true;
			case 'Building6MT_Trigger07A_Flip':
			Building6MT_Trigger07A_Flip();
			return true;
			case 'Building6MT_Trigger07A_Reset':
			Building6MT_Trigger07A_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building6M01Target1=MarksmanTarget(CaptureEvent('building6Marker01Target01'));
		building6M01Target2=MarksmanTarget(CaptureEvent('building6Marker01Target02'));
		building6M01Target3=MarksmanTarget(CaptureEvent('building6Marker01Target03'));
		building6M02Target1=MarksmanTarget(CaptureEvent('building6Marker02Target01'));
		building6M02Target2=MarksmanTarget(CaptureEvent('building6Marker02Target02'));
		building6M02Target3=MarksmanTarget(CaptureEvent('building6Marker02Target03'));
		building6M03Target1=MarksmanTarget(CaptureEvent('building6Marker03Target01'));
		building6M03Target2=MarksmanTarget(CaptureEvent('building6Marker03Target02'));
		building6M03Target3=MarksmanTarget(CaptureEvent('building6Marker03Target03'));
		building6M03Target4=MarksmanTarget(CaptureEvent('building6Marker03Target04'));
		building6M03Target5=MarksmanTarget(CaptureEvent('building6Marker03Target05'));
		building6M03Target6=MarksmanTarget(CaptureEvent('building6Marker03Target06'));
		building6M03Target7=MarksmanTarget(CaptureEvent('building6Marker03Target07'));
		building6M04Target1=MarksmanTarget(CaptureEvent('building6Marker04Target01'));
		building6M04Target2=MarksmanTarget(CaptureEvent('building6Marker04Target02'));
		building6M04Target3=MarksmanTarget(CaptureEvent('building6Marker04Target03'));
		building6M05Target1=MarksmanTarget(CaptureEvent('building6Marker05Target01'));
		building6M05Target2=MarksmanTarget(CaptureEvent('building6Marker05Target02'));
		building6M05Target3=MarksmanTarget(CaptureEvent('building6Marker05Target03'));
		building6M06Target1=MarksmanTarget(CaptureEvent('building6Marker06Target01'));
		building6M06Target2=MarksmanTarget(CaptureEvent('building6Marker06Target02'));
		building6M07Target1=MarksmanTarget(CaptureEvent('building6Marker07Target01'));
		building6M07Target2=MarksmanTarget(CaptureEvent('building6Marker07Target02'));
		building6M07Target3=MarksmanTarget(CaptureEvent('building6Marker07Target03'));
		building6M08Target1=MarksmanTarget(CaptureEvent('building6Marker08Target01'));
		building6M08Target2=MarksmanTarget(CaptureEvent('building6Marker08Target02'));
		building6M08Target3=MarksmanTarget(CaptureEvent('building6Marker08Target03'));
		building6M09Target1=MarksmanTarget(CaptureEvent('building6Marker09Target01'));
		building6M09Target2=MarksmanTarget(CaptureEvent('building6Marker09Target02'));
		building6M09Target3=MarksmanTarget(CaptureEvent('building6Marker09Target03'));
		building6M09Target4=MarksmanTarget(CaptureEvent('building6Marker09Target04'));
		building6M09Target5=MarksmanTarget(CaptureEvent('building6Marker09Target05'));
		building6M10Target1=MarksmanTarget(CaptureEvent('building6Marker10Target01'));
		building6M10Target2=MarksmanTarget(CaptureEvent('building6Marker10Target02'));
		building6M11Target1=MarksmanTarget(CaptureEvent('building6Marker11Target01'));
		building6M11Target2=MarksmanTarget(CaptureEvent('building6Marker11Target02'));
		building6M12Target1=MarksmanTarget(CaptureEvent('building6Marker12Target01'));
		building6M12Target2=MarksmanTarget(CaptureEvent('building6Marker12Target02'));
		building6M13Target1=MarksmanTarget(CaptureEvent('building6Marker13Target01'));
		building6M13Target2=MarksmanTarget(CaptureEvent('building6Marker13Target02'));
		building6M13Target3=MarksmanTarget(CaptureEvent('building6Marker13Target03'));
		building6M13Target4=MarksmanTarget(CaptureEvent('building6Marker13Target04'));
		building6M13Target5=MarksmanTarget(CaptureEvent('building6Marker13Target05'));
		building6M13Target6=MarksmanTarget(CaptureEvent('building6Marker13Target06'));
		building6M14Target1=MarksmanTarget(CaptureEvent('building6Marker14Target01'));
		building6M14Target2=MarksmanTarget(CaptureEvent('building6Marker14Target02'));
		if (door1Entered)
		{
			building6M01Target1.bHidden=false;
			building6M01Target2.bHidden=false;
			building6M01Target3.bHidden=false;
			building6M02Target1.bHidden=false;
			building6M02Target2.bHidden=false;
			building6M02Target3.bHidden=false;
			building6M03Target1.bHidden=false;
			building6M03Target2.bHidden=false;
			building6M03Target3.bHidden=false;
			building6M03Target4.bHidden=false;
			building6M03Target5.bHidden=false;
			building6M03Target6.bHidden=false;
			building6M03Target7.bHidden=false;
			building6M04Target1.bHidden=false;
			building6M04Target2.bHidden=false;
			building6M04Target3.bHidden=false;
			building6M05Target1.bHidden=false;
			building6M05Target2.bHidden=false;
			building6M05Target3.bHidden=false;
			building6M06Target1.bHidden=false;
			building6M06Target2.bHidden=false;
			building6M07Target1.bHidden=false;
			building6M07Target2.bHidden=false;
			building6M07Target3.bHidden=false;
			building6M08Target1.bHidden=false;
			building6M08Target2.bHidden=false;
			building6M08Target3.bHidden=false;
			building6M09Target1.bHidden=true;
			building6M09Target2.bHidden=true;
			building6M09Target3.bHidden=true;
			building6M09Target4.bHidden=true;
			building6M09Target5.bHidden=true;
			building6M10Target1.bHidden=true;
			building6M10Target2.bHidden=true;
			building6M11Target1.bHidden=true;
			building6M11Target2.bHidden=true;
			building6M12Target1.bHidden=true;
			building6M12Target2.bHidden=true;
			building6M13Target1.bHidden=true;
			building6M13Target2.bHidden=true;
			building6M13Target3.bHidden=true;
			building6M13Target4.bHidden=true;
			building6M13Target5.bHidden=true;
			building6M13Target6.bHidden=true;
			building6M14Target1.bHidden=true;
			building6M14Target2.bHidden=true;
		}
		if (door2Entered)
		{
			building6M01Target1.bHidden=true;
			building6M01Target2.bHidden=true;
			building6M01Target3.bHidden=true;
			building6M02Target1.bHidden=true;
			building6M02Target2.bHidden=true;
			building6M02Target3.bHidden=true;
			building6M03Target1.bHidden=true;
			building6M03Target2.bHidden=true;
			building6M03Target3.bHidden=true;
			building6M03Target4.bHidden=true;
			building6M03Target5.bHidden=true;
			building6M03Target6.bHidden=true;
			building6M03Target7.bHidden=true;
			building6M04Target1.bHidden=true;
			building6M04Target2.bHidden=true;
			building6M04Target3.bHidden=true;
			building6M05Target1.bHidden=true;
			building6M05Target2.bHidden=true;
			building6M05Target3.bHidden=true;
			building6M06Target1.bHidden=true;
			building6M06Target2.bHidden=true;
			building6M07Target1.bHidden=true;
			building6M07Target2.bHidden=true;
			building6M07Target3.bHidden=true;
			building6M08Target1.bHidden=true;
			building6M08Target2.bHidden=true;
			building6M08Target3.bHidden=true;
			building6M09Target1.bHidden=false;
			building6M09Target2.bHidden=false;
			building6M09Target3.bHidden=false;
			building6M09Target4.bHidden=false;
			building6M09Target5.bHidden=false;
			building6M10Target1.bHidden=false;
			building6M10Target2.bHidden=false;
			building6M11Target1.bHidden=false;
			building6M11Target2.bHidden=false;
			building6M12Target1.bHidden=false;
			building6M12Target2.bHidden=false;
			building6M13Target1.bHidden=false;
			building6M13Target2.bHidden=false;
			building6M13Target3.bHidden=false;
			building6M13Target4.bHidden=false;
			building6M13Target5.bHidden=false;
			building6M13Target6.bHidden=false;
			building6M14Target1.bHidden=false;
			building6M14Target2.bHidden=false;
		}
		if (! building6MTTriggerCaptured)
		{
			building6MTTrigger01=TriggerVolume(CaptureEvent('Building6MT_Trigger01B'));
			building6MTTrigger02=TriggerVolume(CaptureEvent('Building6MT_Trigger02B'));
			building6MTTrigger03=TriggerVolume(CaptureEvent('Building6MT_Trigger03B'));
			building6MTTrigger04=TriggerVolume(CaptureEvent('Building6MT_Trigger04B'));
			building6MTTrigger05=TriggerVolume(CaptureEvent('Building6MT_Trigger05A'));
			building6MTTrigger06=TriggerVolume(CaptureEvent('Building6MT_Trigger06A'));
			building6MTTrigger07=TriggerVolume(CaptureEvent('Building6MT_Trigger07A'));
			building6MTTriggerCaptured=true;
		}
	}
}
State Building6InActive extends Building6Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		building6M01Target1.ResetTarget(true);
		UnCaptureEvent(building6M01Target1);
		building6M01Target2.ResetTarget(true);
		UnCaptureEvent(building6M01Target2);
		building6M01Target3.ResetTarget(true);
		UnCaptureEvent(building6M01Target3);
		building6M02Target1.ResetTarget(true);
		UnCaptureEvent(building6M02Target1);
		building6M02Target2.ResetTarget(true);
		UnCaptureEvent(building6M02Target2);
		building6M02Target3.ResetTarget(true);
		UnCaptureEvent(building6M02Target3);
		building6M03Target1.ResetTarget(true);
		UnCaptureEvent(building6M03Target1);
		building6M03Target2.ResetTarget(true);
		UnCaptureEvent(building6M03Target2);
		building6M03Target3.ResetTarget(true);
		UnCaptureEvent(building6M03Target3);
		building6M03Target4.ResetTarget(true);
		UnCaptureEvent(building6M03Target4);
		building6M03Target5.ResetTarget(true);
		UnCaptureEvent(building6M03Target5);
		building6M03Target6.ResetTarget(true);
		UnCaptureEvent(building6M03Target6);
		building6M03Target7.ResetTarget(true);
		UnCaptureEvent(building6M03Target7);
		building6M04Target1.ResetTarget(true);
		UnCaptureEvent(building6M04Target1);
		building6M04Target2.ResetTarget(true);
		UnCaptureEvent(building6M04Target2);
		building6M04Target3.ResetTarget(true);
		UnCaptureEvent(building6M04Target3);
		building6M05Target1.ResetTarget(true);
		UnCaptureEvent(building6M05Target1);
		building6M05Target2.ResetTarget(true);
		UnCaptureEvent(building6M05Target2);
		building6M05Target3.ResetTarget(true);
		UnCaptureEvent(building6M05Target3);
		building6M06Target1.ResetTarget(true);
		UnCaptureEvent(building6M06Target1);
		building6M06Target2.ResetTarget(true);
		UnCaptureEvent(building6M06Target2);
		building6M07Target1.ResetTarget(true);
		UnCaptureEvent(building6M07Target1);
		building6M07Target2.ResetTarget(true);
		UnCaptureEvent(building6M07Target2);
		building6M07Target3.ResetTarget(true);
		UnCaptureEvent(building6M07Target3);
		building6M08Target1.ResetTarget(true);
		UnCaptureEvent(building6M08Target1);
		building6M08Target2.ResetTarget(true);
		UnCaptureEvent(building6M08Target2);
		building6M08Target3.ResetTarget(true);
		UnCaptureEvent(building6M08Target3);
		building6M09Target1.ResetTarget(true);
		UnCaptureEvent(building6M09Target1);
		building6M09Target2.ResetTarget(true);
		UnCaptureEvent(building6M09Target2);
		building6M09Target3.ResetTarget(true);
		UnCaptureEvent(building6M09Target3);
		building6M09Target4.ResetTarget(true);
		UnCaptureEvent(building6M09Target4);
		building6M09Target5.ResetTarget(true);
		UnCaptureEvent(building6M09Target5);
		building6M10Target1.ResetTarget(true);
		UnCaptureEvent(building6M10Target1);
		building6M10Target2.ResetTarget(true);
		UnCaptureEvent(building6M10Target2);
		building6M11Target1.ResetTarget(true);
		UnCaptureEvent(building6M11Target1);
		building6M11Target2.ResetTarget(true);
		UnCaptureEvent(building6M11Target2);
		building6M12Target1.ResetTarget(true);
		UnCaptureEvent(building6M12Target1);
		building6M12Target2.ResetTarget(true);
		UnCaptureEvent(building6M12Target2);
		building6M13Target1.ResetTarget(true);
		UnCaptureEvent(building6M13Target1);
		building6M13Target2.ResetTarget(true);
		UnCaptureEvent(building6M13Target2);
		building6M13Target3.ResetTarget(true);
		UnCaptureEvent(building6M13Target3);
		building6M13Target4.ResetTarget(true);
		UnCaptureEvent(building6M13Target4);
		building6M13Target5.ResetTarget(true);
		UnCaptureEvent(building6M13Target5);
		building6M13Target6.ResetTarget(true);
		UnCaptureEvent(building6M13Target6);
		building6M14Target1.ResetTarget(true);
		UnCaptureEvent(building6M14Target1);
		building6M14Target2.ResetTarget(true);
		UnCaptureEvent(building6M14Target2);
		ChangeState('NoBuildingActive');
	}
}
State NoBuildingActive
{
	Function BeginState()
	{
	}
}
*/
