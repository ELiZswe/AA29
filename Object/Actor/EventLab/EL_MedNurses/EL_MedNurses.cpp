// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MedNurses/EL_MedNurses.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_Nurse/NPC_Nurse.h"

AEL_MedNurses::AEL_MedNurses()
{
	GameSounds = {
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Date_Cue.J1_Date_Cue'"), NULL, LOAD_None, NULL), "J1_Date",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Date_Cue.N2_Date_Cue'"), NULL, LOAD_None, NULL), "N2_Date",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Groceries_Cue.J1_Groceries_Cue'"), NULL, LOAD_None, NULL), "J1_Groceries",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Groceries_Cue.N2_Groceries_Cue'"), NULL, LOAD_None, NULL), "N2_Groceries",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Macho_Cue.J1_Macho_Cue'"), NULL, LOAD_None, NULL), "J1_Macho",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Macho_Cue.N2_Macho_Cue'"), NULL, LOAD_None, NULL), "N2_Macho",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Break_Cue.J2_Break_Cue'"), NULL, LOAD_None, NULL), "J2_Break",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Break_Cue.N1_Break_Cue'"), NULL, LOAD_None, NULL), "N1_Break",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Housing_Cue.J2_Housing_Cue'"), NULL, LOAD_None, NULL), "J2_Housing",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Housing_Cue.N1_Housing_Cue'"), NULL, LOAD_None, NULL), "N1_Housing",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Lunch_Cue.J2_Lunch_Cue'"), NULL, LOAD_None, NULL), "J2_Lunch",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Lunch_Cue.N1_Lunch_Cue'"), NULL, LOAD_None, NULL), "N1_Lunch",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Movie_Cue.J2_Movie_Cue'"), NULL, LOAD_None, NULL), "J2_Movie",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Movie_Cue.N1_Movie_Cue'"), NULL, LOAD_None, NULL), "N1_Movie",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_PCS_Cue.J2_PCS_Cue'"), NULL, LOAD_None, NULL), "J2_PCS",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_PCS_Cue.N1_PCS_Cue'"), NULL, LOAD_None, NULL), "N1_PCS",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_PX_Cue.J2_PX_Cue'"), NULL, LOAD_None, NULL), "J2_PX",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_PX_Cue.N1_PX_Cue'"), NULL, LOAD_None, NULL), "N1_PX",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_Boyfriend_Cue.J_Boyfriend_Cue'"), NULL, LOAD_None, NULL), "J_Boyfriend",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_Class_Cue.J_Class_Cue'"), NULL, LOAD_None, NULL), "J_Class",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_ThatGuy_Cue.J_ThatGuy_Cue'"), NULL, LOAD_None, NULL), "J_ThatGuy",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_YoureNot_Cue.J_YoureNot_Cue'"), NULL, LOAD_None, NULL), "J_YoureNot",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Busy_Cue.N_Busy_Cue'"), NULL, LOAD_None, NULL), "N_Busy",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Class_Cue.N_Class_Cue'"), NULL, LOAD_None, NULL), "N_Class",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Help_Cue.N_Help_Cue'"), NULL, LOAD_None, NULL), "N_Help",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Married_Cue.N_Married_Cue'"), NULL, LOAD_None, NULL), "N_Married",0 }),
		FGameSound({ LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Waiting_Cue.N_Waiting_Cue'"), NULL, LOAD_None, NULL), "N_Waiting",0 })
	};

	LSAnims = {
		FLSAnim({ "J1_Date",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Date_Cue.J1_Date_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N2_Date",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Date_Cue.N2_Date_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J1_Groceries",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Groceries_Cue.J1_Groceries_Cue'"),	NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N2_Groceries",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Groceries_Cue.N2_Groceries_Cue'"),	NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J1_Macho",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Macho_Cue.J1_Macho_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N2_Macho",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N2_Macho_Cue.N2_Macho_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_Break",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Break_Cue.J2_Break_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_Break",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Break_Cue.N1_Break_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_Housing",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Housing_Cue.J2_Housing_Cue'"),		NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_Housing",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Housing_Cue.N1_Housing_Cue'"),		NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_Lunch",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Lunch_Cue.J2_Lunch_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_Lunch",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Lunch_Cue.N1_Lunch_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_Movie",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_Movie_Cue.J2_Movie_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_Movie",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Movie_Cue.N1_Movie_Cue'"),				NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_PCS",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_PCS_Cue.J2_PCS_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_PCS",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_PCS_Cue.N1_PCS_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J2_PX",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J2_PX_Cue.J2_PX_Cue'"),						NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N1_PX",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_PX_Cue.N1_PX_Cue'"),						NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J_Boyfriend",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_Boyfriend_Cue.J_Boyfriend_Cue'"),		NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J_Class",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_Class_Cue.J_Class_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J_ThatGuy",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_ThatGuy_Cue.J_ThatGuy_Cue'"),			NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "J_YoureNot",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_YoureNot_Cue.J_YoureNot_Cue'"),		NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N_Busy",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Busy_Cue.N_Busy_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N_Class",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Class_Cue.N_Class_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N_Help",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Help_Cue.N_Help_Cue'"),					NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N_Married",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Married_Cue.N_Married_Cue'"),			NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "N_Waiting",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Waiting_Cue.N_Waiting_Cue'"),			NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"} , {0,0,0,0,0,0,0,0,0,0} })
	};
}

/*
State Idle
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function bool JoanneTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		switch(JoanneUseCount)
		{
			case 0:
			PlayLSAnim("J_YoureNot",Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 1:
			PlayLSAnim("J_Class",Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 2:
			PlayLSAnim("J_ThatGuy",Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 3:
			PlayLSAnim("J_Boyfriend",Joanne,0.75,512);
			JoanneUseCount=0;
			return true;
			default:
			return true;
		}
	}
	Function bool NicholeTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		switch(NicholeUseCount)
		{
			case 0:
			PlayLSAnim("N_Waiting",Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 1:
			PlayLSAnim("N_Class",Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 2:
			PlayLSAnim("N_Help",Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 3:
			PlayLSAnim("N_Married",Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 4:
			PlayLSAnim("N_Busy",Nichole,0.75,512);
			NicholeUseCount=0;
			return true;
			default:
			return true;
		}
	}
	Function bool NurseConvVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(ConversationCount)
		{
			case 0:
			ConversationCount ++;
			ChangeState("Date");
			return true;
			case 1:
			ConversationCount ++;
			ChangeState("Groceries");
			return true;
			case 2:
			ConversationCount ++;
			ChangeState("Macho");
			return true;
			case 3:
			ConversationCount ++;
			ChangeState("Break");
			return true;
			case 4:
			ConversationCount ++;
			ChangeState("Housing");
			return true;
			case 5:
			ConversationCount ++;
			ChangeState("Lunch");
			return true;
			case 6:
			ConversationCount ++;
			ChangeState("Movie");
			return true;
			case 7:
			ConversationCount ++;
			ChangeState("PCS");
			return true;
			case 8:
			ConversationCount=0;
			ChangeState("pX");
			return true;
			default:
			return true;
		}
	}
}
*/

/*
State Date
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Date_Start",0.5,false);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Date_Start":
			Date_Start();
			return true;
			case "Date_PT2":
			Date_PT2();
			return true;
			case "Date_End":
			Date_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "J1_Date":
			StartTimer("Date_PT2",0.5,false);
			return true;
			case "N2_Date":
			StartTimer("Date_End",0.1);
			return true;
			default:
			return false;
		}
	}
	Function Date_Start()
	{
		PlayLSAnim("J1_Date",Joanne,0.75,512);
	}
	Function Date_PT2()
	{
		PlayLSAnim("N2_Date",Nichole,0.75,512);
	}
	Function Date_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Groceries
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Groceries_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Groceries_Start":
			Groceries_Start();
			return true;
			case "Groceries_PT2":
			Groceries_PT2();
			return true;
			case "Groceries_End":
			Groceries_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "J1_Groceries":
			StartTimer("Groceries_PT2",0.5,false);
			return true;
			case "N2_Groceries":
			StartTimer("Groceries_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Groceries_Start()
	{
		PlayLSAnim("J1_Groceries",Joanne,0.75,512);
	}
	Function Groceries_PT2()
	{
		PlayLSAnim("N2_Groceries",Nichole,0.75,512);
	}
	Function Groceries_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Macho
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Macho_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Macho_Start":
			Macho_Start();
			return true;
			case "Macho_PT2":
			Macho_PT2();
			return true;
			case "Macho_End":
			Macho_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "J1_Macho":
			StartTimer("Macho_PT2",0.5,false);
			return true;
			case "N2_Macho":
			StartTimer("Macho_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Macho_Start()
	{
		PlayLSAnim("J1_Macho",Nichole,0.75,512);
	}
	Function Macho_PT2()
	{
		PlayLSAnim("N2_Macho",Joanne,0.75,512);
	}
	Function Macho_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Break
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Break_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Break_Start":
			Break_Start();
			return true;
			case "Break_PT2":
			Break_PT2();
			return true;
			case "Break_End":
			Break_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_Break":
			StartTimer("Break_PT2",0.5,false);
			return true;
			case "J2_Break":
			StartTimer("Break_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Break_Start()
	{
		PlayLSAnim("N1_Break",Nichole,0.75,512);
	}
	Function Break_PT2()
	{
		PlayLSAnim("J2_Break",Joanne,0.75,512);
	}
	Function Break_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Housing
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Housing_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Housing_Start":
			Housing_Start();
			return true;
			case "Housing_PT2":
			Housing_PT2();
			return true;
			case "Housing_End":
			Housing_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_Housing":
			StartTimer("Housing_PT2",0.5,false);
			return true;
			case "J2_Housing":
			StartTimer("Housing_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Housing_Start()
	{
		PlayLSAnim("N1_Housing",Nichole,0.75,512);
	}
	Function Housing_PT2()
	{
		PlayLSAnim("J2_Housing",Joanne,0.75,512);
	}
	Function Housing_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Lunch
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Lunch_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Lunch_Start":
			Lunch_Start();
			return true;
			case "Lunch_PT2":
			Lunch_PT2();
			return true;
			case "Lunch_End":
			Lunch_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_Lunch":
			StartTimer("Lunch_PT2",0.5,false);
			return true;
			case "J2_Lunch":
			StartTimer("Lunch_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Lunch_Start()
	{
		PlayLSAnim("N1_Lunch",Nichole,0.75,512);
	}
	Function Lunch_PT2()
	{
		PlayLSAnim("J2_Lunch",Joanne,0.75,512);
	}
	Function Lunch_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State Movie
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("Movie_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Movie_Start":
			Movie_Start();
			return true;
			case "Movie_PT2":
			Movie_PT2();
			return true;
			case "Movie_End":
			Movie_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_Movie":
			StartTimer("Movie_PT2",0.5,false);
			return true;
			case "J2_Movie":
			StartTimer("Movie_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Movie_Start()
	{
		PlayLSAnim("N1_Movie",Nichole,0.75,512);
	}
	Function Movie_PT2()
	{
		PlayLSAnim("J2_Movie",Joanne,0.75,512);
	}
	Function Movie_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State PCS
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("PCS_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "PCS_Start":
			PCS_Start();
			return true;
			case "PCS_PT2":
			PCS_PT2();
			return true;
			case "PCS_End":
			PCS_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_PCS":
			StartTimer("PCS_PT2",0.5,false);
			return true;
			case "J2_PCS":
			StartTimer("PCS_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function PCS_Start()
	{
		PlayLSAnim("N1_PCS",Nichole,0.75,512);
	}
	Function PCS_PT2()
	{
		PlayLSAnim("J2_PCS",Joanne,0.75,512);
	}
	Function PCS_End()
	{
		ChangeState("Idle");
	}
}
*/

/*
State pX
{
	Function BeginState()
	{
		UnCaptureEventGroup("NurseConvVolume");
		StartTimer("PX_Start",0.5);
	}
	Function EndState()
	{
		CaptureEventGroup("NurseConvVolume");
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "PX_Start":
			PX_Start();
			return true;
			case "PX_PT2":
			PX_PT2();
			return true;
			case "PX_End":
			PX_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "N1_PX":
			StartTimer("PX_PT2",0.5,false);
			return true;
			case "J2_PX":
			StartTimer("PX_End",0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function PX_Start()
	{
		PlayLSAnim("N1_PX",Nichole,0.75,512);
	}
	Function PX_PT2()
	{
		PlayLSAnim("J2_PX",Joanne,0.75,512);
	}
	Function PX_End()
	{
		ChangeState("Idle");
	}
}
*/

bool AEL_MedNurses::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "NurseClosetVolume":
		return NurseClosetVolume_Enter(Trigger, aInstigator);
	case "NurseConvVolume":
		return NurseConvVolume_Enter(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NurseClosetVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NurseConvVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "NurseClosetVolume":
		return NurseClosetVolume_Exit(Trigger, aInstigator);
	case "NurseConvVolume":
		return NurseConvVolume_Exit(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NurseClosetVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NurseConvVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "JoanneTrigger":
		return JoanneTrigger_UsedBy(Trigger, aInstigator);
	case "NicholeTrigger":
		return NicholeTrigger_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::JoanneTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NicholeTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "NicholeTouch":
		return NicholeTouch_Trigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

bool AEL_MedNurses::NicholeTouch_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;     //FAKE   /ELiZ
}

void AEL_MedNurses::PreInit()
{
	/*
	Joanne = Cast<ANPC_Nurse>(CaptureEvent("Joanne"));
	Nichole = Cast<ANPC_Nurse>(CaptureEvent("Nichole"));
	NurseCloset1 = Cast<ADoorTrigger>(GetActorByTag("NurseCloset1"));
	NurseCloset2 = Cast<ADoorTrigger>(GetActorByTag("NurseCloset2"));
	JoanneTouch = Cast<AAGP_Trigger>(CaptureEvent("JoanneTouch"));
	JoanneTrigger = Cast<AAGP_UseTrigger>(CaptureEvent("JoanneTrigger"));
	NicholeTrigger = Cast<AAGP_UseTrigger>(CaptureEvent("NicholeTrigger"));
	CaptureEventGroup("NurseConvVolume");
	*/
}

void AEL_MedNurses::Init()
{
}

void AEL_MedNurses::PostInit()
{
}

void AEL_MedNurses::PostPostInit()
{
	/*
	PlayerLock(false, false);
	Joanne.LoopAnim("NurseInventory");
	Nichole.LoopAnim("NurseTyping");
	NurseCloset1.SoundLocked = nullptr;
	NurseCloset1.ToggleOpen();
	NurseCloset1.SetLocked(true);
	NurseCloset2.SoundLocked = nullptr;
	NurseCloset2.ToggleOpen();
	NurseCloset2.SetLocked(true);
	ConversationCount = Rand(9);
	ChangeState("Idle");
	FadeOut(0.01, true);
	StartTimer("tmrFadeIn", 4);
	*/
}

bool AEL_MedNurses::Timer_Timer(FName Name)
{
	if (Name == "tmrFadeIn")
	{
		FadeIn(4, true);
		return true;
	}
	return false;
}

