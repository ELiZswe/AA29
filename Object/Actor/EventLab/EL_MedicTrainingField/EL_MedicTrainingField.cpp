// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MedicTrainingField/EL_MedicTrainingField.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedStudent/NPC_MedStudent.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage.h"

AEL_MedicTrainingField::AEL_MedicTrainingField()
{
	GameSounds = {
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Crucial_Cue.InstRAD_Crucial_Cue'"), NULL, LOAD_None, NULL),"InstRAD_Crucial",0}),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_GoodJob_Cue.InstRAD_GoodJob_Cue'"), NULL, LOAD_None, NULL),"InstRAD_GoodJob",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Hurry_Cue.InstRAD_Hurry_Cue'"), NULL, LOAD_None, NULL),"InstRAD_Hurry",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_OK_Cue.InstRAD_OK_Cue'"), NULL, LOAD_None, NULL),"InstRAD_OK",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Qual_Cue.InstRAD_Qual_Cue'"), NULL, LOAD_None, NULL),"InstRAD_Qual",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Recycle_Cue.InstRAD_Recycle_Cue'"), NULL, LOAD_None, NULL),"InstRAD_Recycle",0 })
	};
	LSAnims = {
		FLSAnim({ "INSTINT_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/INSTINT_01_Cue.INSTINT_01_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "INSTINT_02",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/INSTINT_02_Cue.INSTINT_02_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_Crucial",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Crucial_Cue.InstRAD_Crucial_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_GoodJob",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_GoodJob_Cue.InstRAD_GoodJob_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_Hurry",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Hurry_Cue.InstRAD_Hurry_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_OK",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_OK_Cue.InstRAD_OK_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_Qual",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Qual_Cue.InstRAD_Qual_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "InstRAD_Recycle",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Instructor/InstRAD_Recycle_Cue.InstRAD_Recycle_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Donny_Moan",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Donny_Moan_Cue.Donny_Moan_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Jeffrey_OK",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Jeffrey_OK_Cue.Jeffrey_OK_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Jeffrey_Worse",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Jeffrey_Worse_Cue.Jeffrey_Worse_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Walter_Donny",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Walter_Donny_Cue.Walter_Donny_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Walter_Groan",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Walter_Groan_Cue.Walter_Groan_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Walter_Groan2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Walter_Groan2_Cue.Walter_Groan2_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} })
	};
}

/*
State ScriptHack
{
	Function BeginState()
	{
		Cast<AStudentController>(Controller)->bUsedCheats=true;
		Jeffrey.TakeDamage(20,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
		Walter.TakeDamage(30,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
		Donny.TakeDamage(98,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
		Jeffrey.CallForMedic();
		Walter.CallForMedic();
		Donny.CallForMedic();
		StartTimer("ScriptHack_Begin",1);
	}
	Function bool Timer_Timer(FName Name)
	{
		ChangeState("FindAndHeal");
		return true;
	}
}
*/

/*
State Intro
{
	Function BeginState()
	{
		StartTimer("Intro_Begin",3);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "INSTINT_01")
		{
			StartTimer("Explosion_Delay",1);
			return true;
		}
		return false;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Intro_Begin")
		{
			PlayLSAnim("INSTINT_01",Instructor,1,512);
			return true;
		}
		if (Name == "Explosion_Delay")
		{
			TriggerGroup("Explosion");
			StartTimer("CallMedic1_Delay",2);
			StartTimer("CallMedic2_Delay",4);
			return true;
		}
		if (Name == "CallMedic1_Delay")
		{
			TriggerGroup("CallMedic");
			Jeffrey.CallForMedic();
			return true;
		}
		if (Name == "CallMedic2_Delay")
		{
			TriggerGroup("CallMedic2");
			Walter.CallForMedic();
			Donny.CallForMedic();
			ChangeState("Incident");
			return true;
		}
		return false;
	}
}
*/

/*
State Incident
{
	Function BeginState()
	{
		StartTimer("Incident_Begin",2);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Incident_Begin")
		{
			PlayLSAnim("INSTINT_02",Instructor,1,512);
			return true;
		}
		return false;
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "INSTINT_02")
		{
			Jeffrey.TakeDamage(20,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
			Walter.TakeDamage(30,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
			Donny.TakeDamage(98,Player,FVector(0,0,0),FVector(0,0,0),AProjectileDamage::StaticClass());
			PlayerLock(false,false);
			ChangeState("FindAndHeal");
			return true;
		}
		return false;
	}
}
*/

/*
State FindAndHeal
{
	Function BeginState()
	{
		StartTimer("Global",120);
		IncidentArea=AGP_Trigger(CaptureEvent("IncidentArea"));
		Donny_Proximity=AGP_Trigger(CaptureEvent("Donny_Proximity"));
		Walter_Proximity=AGP_Trigger(CaptureEvent("Walter_Proximity"));
		Jeffrey_Proximity=AGP_Trigger(CaptureEvent("Jeffrey_Proximity"));
		PlayTip("Find and treat your injured teammates.","Use the SAI to help you find them.",5);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Global")
		{
			ChangeState("FailTime");
		}
		return true;
	}
	Function bool Timer_Anim(FName Name)
	{
		if (Name == "None")
		{
			return false;
		}
		return false;
	}
	Function bool QueueAnim_Begin(FName Name)
	{
		if (Name == "wounded01_reach")
		{
		}
		return true;
	}
	Function bool QueueAnim_End(FName Name)
	{
		return true;
	}
	Function bool AGP_Trigger_Trigger(AGP_Gameplay.AGP_Trigger* NotifyActor, AActor* Instigator)
	{
		if (NotifyActor.Tag == "IncidentArea")
		{
			UnCaptureEvent(IncidentArea);
			PlayGameSound("InstRAD_OK",Player);
			return true;
		}
		if (NotifyActor.Tag == "Donny_Proximity")
		{
			UnCaptureEvent(Donny_Proximity);
			PlayLSAnim("Donny_Moan",Donny);
		}
		if (NotifyActor.Tag == "Walter_Proximity")
		{
			UnCaptureEvent(Walter_Proximity);
			PlayLSAnim("Walter_Groan2",Walter);
			QueueAnim("wounded01_reach",Walter);
			QueueAnim("wounded01_idle",Walter,true);
		}
		if (NotifyActor.Tag == "Jeffrey_Proximity")
		{
			UnCaptureEvent(Jeffrey_Proximity);
			PlayLSAnim("Jeffrey_OK",Jeffrey);
		}
		if (! bDidPlayHealTip)
		{
			PlayTip("To heal somebody, press and hold","the <action> key while facing them",5);
			bDidPlayHealTip=true;
		}
		return true;
	}
	Function bool NPC_MedStudent_Custom(AGP_Characters.NPC_MedStudent* NotifyActor, AActor* Instigator, FString Parms)
	{
		if (Parms == "ISHEALING")
		{
			if (bIsHealing)
			{
				return true;
			}
			bIsHealing=true;
			switch(NotifyActor.PlayerReplicationInfo.PlayerName)
			{
				case "Walter":
				if (HealCounter != 1)
				{
					if (! bWalterDidWarn)
					{
						PlayLSAnim("Walter_Donny",Walter,1,512);
					}
					bWalterDidWarn=true;
					break;
				}
				if (! bWalterDidGroan)
				{
					PlayLSAnim("Walter_Groan",Walter);
					bWalterDidGroan=true;
				}
			}
			return true;
			case "Jeffrey":
			if (HealCounter != 2)
			{
				if (! bJeffreyDidWarn)
				{
					PlayLSAnim("Jeffrey_Worse",Jeffrey,1,512);
				}
				bJeffreyDidWarn=true;
			}
			return true;
			default:
		}
		if (Parms == "HEALTHDEGRADE")
		{
			switch(NotifyActor.PlayerReplicationInfo.PlayerName)
			{
				case "Donny":
				if ((! bIsHealing) && (! bInstGoodJob))
				{
					PlayGameSound("InstRAD_Crucial",Player);
				}
				break;
				case "Walter":
				if ((! bIsHealing) && (! bInstGoodJob))
				{
					PlayGameSound("InstRAD_Hurry",Player);
				}
				break;
				default:
			}
			return true;
		}
		if (Parms == "HEALSUCCESSFUL")
		{
			bIsHealing=false;
			switch(NotifyActor.PlayerReplicationInfo.PlayerName)
			{
				case "Donny":
				bDonnyIsHealed=true;
				if (HealCounter == 0)
				{
					PlayGameSound("InstRAD_GoodJob",Player);
					bInstGoodJob=true;
					QueueAnim("wounded02_healed_idle",Donny,true);
					break;
				}
				bWrongOrder=true;
			}
			HealCounter ++;
			case "Walter":
			bWalterIsHealed=true;
			if (HealCounter == 1)
			{
				QueueAnim("wounded01_healed_trans",Walter);
				QueueAnim("wounded01_healed_idle",Walter,true);
			}
			else
			{
				bWrongOrder=true;
			}
			HealCounter ++;
			case "Jeffrey":
			bJeffreyIsHealed=true;
			if (HealCounter == 2)
			{
				QueueAnim("wounded03_healing",Jeffrey);
				QueueAnim("wounded03_healed",Jeffrey,true);
			}
			else
			{
				bWrongOrder=true;
			}
			HealCounter ++;
			default:
			if (HealCounter > 2)
			{
				StopTimer("Global",0);
				ChangeState("DoneHealing");
			}
			return true;
		}
		if (Parms == "HEALINTERRUPTED")
		{
			bIsHealing=false;
			return true;
		}
		return false;
	}
}
*/

/*
State DoneHealing
{
	Function BeginState()
	{
		if (! bWrongOrder)
		{
			PlayGameSound("InstRAD_Qual",Player);
		}
		StartTimer("Done_Begin",5);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Done_Begin")
		{
			if (bWrongOrder)
			{
				ChangeState("FailOrder");
			}
			else
			{
				ChangeState("Qualified");
			}
		}
		return true;
	}
}
*/

/*
State Qualified
{
	Function UpdateCompletionFields()
	{
		ASecurity* secLocalSecurity = nullptr;
		ASecurity* scLocalSecurityClass = nullptr;
		TArray<FString> asMD5ForMap = {};
		TArray<FString> asMD5ForScript = {};
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != nullptr)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != nullptr)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/Medic_Field.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
				sMD5ForMap=asMD5ForMap[0];
				sMD5ForScript=asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
	}
	Function BeginState()
	{
		Cast<AStudentController>(Controller)->ResetAuthExtraMissionData();
		UpdateCompletionFields();
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(false);
			DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","Cheats detected, cannot qualify",128,128,7,"None");
		}
		else
		{
			Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(true);
			DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Congratulations!","You are qualified as a Combat Medic",128,128,7,"None");
		}
	}
}
*/

/*
State FailOrder
{
	Function BeginState()
	{
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Mission Failed! You didn't treat","the most serious casualties first",128,128,7,"None");
	}
}
*/

/*
State FailTime
{
	Function BeginState()
	{
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_MedicTraining","Mission Failed!","You took too long to treat teammates",128,128,7,"None");
	}
}
*/

void AEL_MedicTrainingField::PreInit()
{
	Instructor = Cast<ANPC_MedInstructor>(CaptureEvent("Instructor", nullptr));
	Jeffrey = Cast<ANPC_MedStudent>(CaptureEvent("Jeffrey", nullptr));
	Walter = Cast<ANPC_MedStudent>(CaptureEvent("Walter", nullptr));
	Donny = Cast<ANPC_MedStudent>(CaptureEvent("Donny", nullptr));
}

void AEL_MedicTrainingField::Init()
{
	/*
	QueueAnim('DrillIdle', Instructor, true, 1, 0.25, 0);
	QueueAnim('wounded03_hurt_idle', Jeffrey, true);
	QueueAnim('wounded01_idle', Walter, true);
	QueueAnim('wounded02_hurt_idle', Donny, true);
	*/
}

void AEL_MedicTrainingField::PostInit()
{
}

void AEL_MedicTrainingField::PostPostInit()
{
	/*
	ReCaptureEvent(Controller);
	if (Cast<AStudentController>(Controller)->bFieldSkipIntro)
	{
		PlayerLock(false, false);
		Cast<AStudentController>(Controller)->bUsedCheats = true;
	}
	else
	{
		PlayerLock(true, false);
	}
	Player.PlayerReplicationInfo.bIsMedic = true;
	Player._InvMedPacks = 3;
	Jeffrey.fHealDivisor = 8;
	Walter.fHealDivisor = 8;
	Donny.fHealDivisor = 8;
	Team = Spawn(AAGP_TeamInfo::StaticClass());
	Team.AddToTeamSP(Player);
	Team.AddToTeamSP(Jeffrey);
	Team.AddToTeamSP(Walter);
	Team.AddToTeamSP(Donny);
	FadeIn(5, true);
	if (Cast<AStudentController>(Controller)->bFieldSkipIntro)
	{
		ChangeState('ScriptHack');
		Cast<AStudentController>(Controller)->bUsedCheats = true;
	}
	else
	{
		ChangeState('Intro');
	}
	*/
}
