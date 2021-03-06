// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_SFWeapons_Range/EL_SFWeapons_Range.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_SpecialForces/NPC_SpecialForces.h"

AEL_SFWeapons_Range::AEL_SFWeapons_Range()
{

}

/*
State Waiting
{
	Function BeginState()
	{
	}
	Function bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "PracticeCadreTrigger":
			return Practice_UsedBy(Trigger,Instigator);
			ChangeState("Practice_Intro");
			break;
			case "RifleCadreTrigger":
			return Rifle_UsedBy(Trigger,Instigator);
			ChangeState("Rifle_Intro");
			break;
			case "GrenadeCadreTrigger":
			return Grenade_UsedBy(Trigger,Instigator);
			ChangeState("Grenade_Intro");
			break;
			case "RocketCadreTrigger":
			return Rocket_UsedBy(Trigger,Instigator);
			ChangeState("Rocket_Intro");
			break;
			default:
			return false;
		}
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "PracticeChallengeVolume":
			return PracticeChallengeVolume_Enter(Trigger,Instigator);
			break;
			case "RifleChallengeVolume":
			break;
			case "GrenadeChallengeVolume":
			break;
			case "RocketChallengeVolume":
			break;
			default:
			return false;
		}
		return true;
	}
Begin:
	if (! LevelStarted)
	{
		LevelStarted=true;
		FadeIn(5,true);
	}
	Sleep(4);
	PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
}
*/

/*
State Practice_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Practice Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "Practice_Downrange":
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case "Practice_Leaving":
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Downrange")
		{
			PlayTip("Practice Station Ended...","Bummer.",2);
			ChangeState("Waiting");
			return true;
		}
		else
		{
			if (Name == "Leaving")
			{
				PlayTip("Practice Station Ended...","Bummer.",2);
				ChangeState("Waiting");
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
*/

/*
State Practice_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Practice_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Rifle_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Rifle Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "Rifle_Downrange":
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case "Rifle_Leaving":
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Downrange")
		{
			PlayTip("Rifle Station Ended...","Bummer.",2);
			ChangeState("Waiting");
			return true;
		}
		else
		{
			if (Name == "Leaving")
			{
				PlayTip("Rifle Station Ended...","Bummer.",2);
				ChangeState("Waiting");
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
*/

/*
State Rifle_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Rifle_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Grenade_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Grenade Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "Grenade_Downrange":
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case "Grenade_Leaving":
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Downrange")
		{
			PlayTip("Grenade Station Ended...","Bummer.",2);
			ChangeState("Waiting");
			return true;
		}
		else
		{
			if (Name == "Leaving")
			{
				PlayTip("Grenade Station Ended...","Bummer.",2);
				ChangeState("Waiting");
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
*/

/*
State Grenade_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Grenade_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Rocket_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Rocket Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		switch(Trigger.Tag)
		{
			case "Rocket_Downrange":
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case "Rocket_Leaving":
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Downrange")
		{
			PlayTip("Rocket Station Ended...","Bummer.",2);
			ChangeState("Waiting");
			return true;
		}
		else
		{
			if (Name == "Leaving")
			{
				PlayTip("Rocket Station Ended...","Bummer.",2);
				ChangeState("Waiting");
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
*/

/*
State Rocket_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

/*
State Rocket_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/

void AEL_SFWeapons_Range::PreInit()
{
	/*
	PracticeCadre.Actor = Cast<ANPC_SpecialForces>(CaptureEvent("PracticeCadre"));
	RifleCadre.Actor = Cast<ANPC_SpecialForces>(CaptureEvent(RifleCadre.Tag));
	RocketCadre.Actor = Cast<ANPC_SpecialForces>(CaptureEvent(RocketCadre.Tag));
	GrenadeCadre.Actor = Cast<ANPC_SpecialForces>(CaptureEvent(GrenadeCadre.Tag));
	RifleCadre.CadreTrigger = Cast<AAGP_UseTrigger>(CaptureEvent("RifleCadreTrigger"));
	RocketCadre.CadreTrigger = Cast<AAGP_UseTrigger>(CaptureEvent("RocketCadreTrigger"));
	GrenadeCadre.CadreTrigger = Cast<AAGP_UseTrigger>(CaptureEvent("GrenadeCadreTrigger"));
	Practice_USE_Trigger = Cast<AAGP_UseTrigger>(CaptureEvent("PracticeCadreTrigger"));
	PracticeStation.ChallengeVolume = Cast<ATriggerVolume>(CaptureEvent(PracticeStation.ChallengeVolumeTag));
	Practice_Leaving = Cast<ATriggerVolume>(CaptureEvent("Practice_Leaving"));
	Practice_Downrange = Cast<ATriggerVolume>(CaptureEvent("Practice_Downrange"));
	PracticeStation.Instructor = PracticeCadre;
	Rifle_Leaving = Cast<ATriggerVolume>(CaptureEvent("Rifle_Leaving"));
	Rifle_Downrange = Cast<ATriggerVolume>(CaptureEvent("Rifle_Downrange"));
	RifleStation.Instructor = RifleCadre;
	Grenade_Leaving = Cast<ATriggerVolume>(CaptureEvent("Grenade_Leaving"));
	Grenade_Downrange = Cast<ATriggerVolume>(CaptureEvent("Grenade_Downrange"));
	GrenadeStation.Instructor = GrenadeCadre;
	Rocket_Leaving = Cast<ATriggerVolume>(CaptureEvent("Rocket_Leaving"));
	Rocket_Downrange = Cast<ATriggerVolume>(CaptureEvent("Rocket_Downrange"));
	*/
}

void AEL_SFWeapons_Range::Init()
{
}

void AEL_SFWeapons_Range::PostInit()
{
}

void AEL_SFWeapons_Range::PostPostInit()
{
	/*
	PracticeCadre.Actor.LoopAnim("DrillIdle");
	RifleCadre.Actor.LoopAnim("DrillIdle");
	GrenadeCadre.Actor.LoopAnim("DrillIdle");
	RocketCadre.Actor.LoopAnim("DrillIdle");
	PlayerRestartLocation = Player.Location;
	PlayerRestartRotation = Player.Rotation;
	CapturePlayer();
	CaptureChallengeVolumes();
	FadeOut(1, true);
	RunConsoleCommand("mpcheat class m4a1auto");
	ChangeState("Waiting");
	*/
}

void AEL_SFWeapons_Range::CaptureChallengeVolumes()
{
	/*
	ReCaptureEvent(PracticeStation.ChallengeVolume);
	ReCaptureEvent(RifleStation.ChallengeVolume);
	ReCaptureEvent(GrenadeStation.ChallengeVolume);
	ReCaptureEvent(RocketStation.ChallengeVolume);
	*/
}

void AEL_SFWeapons_Range::UnCaptureChallengeVolumes()
{
	/*
	UnCaptureEvent(PracticeStation.ChallengeVolume);
	UnCaptureEvent(RifleStation.ChallengeVolume);
	UnCaptureEvent(GrenadeStation.ChallengeVolume);
	UnCaptureEvent(RocketStation.ChallengeVolume);
	*/
}

bool AEL_SFWeapons_Range::IsPlayerArmed()
{
	/*
	if ((Player.getHandsInventory() != nullptr) || (Player.getShoulderInventory() != nullptr))
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_SFWeapons_Range::DownrangeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("You Are too far down range!", "Come back or you will exit the station!", 5);
	//StartTimer("Downrange", 5, false);
	return true;
}

bool AEL_SFWeapons_Range::LeavingVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("You are about to leave this station!", "Come back or you will exit the station!", 5);
	//StartTimer("Leaving", 5, false);
	return true;
}

bool AEL_SFWeapons_Range::PracticeChallengeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (IsPlayerArmed())
	{
		ChangeState("Practice_Intro");
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_SFWeapons_Range::Practice_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Practice_Intro");
	return true;
}

bool AEL_SFWeapons_Range::PracticeVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("You Are In The Practice Volume.", "WOW", 3);
	return true;
}

bool AEL_SFWeapons_Range::Rocket_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Rocket_Intro");
	return true;
}

bool AEL_SFWeapons_Range::Rifle_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Rifle_Intro");
	return true;
}

bool AEL_SFWeapons_Range::Grenade_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//ChangeState("Grenade_Intro");
	return true;
}
