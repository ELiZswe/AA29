// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ActivatedObjective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"

AAGP_ActivatedObjective::AAGP_ActivatedObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	AccomplishMessage		= "Objective activated.";
	FailedDefenseMessage	= "Your team failed to prevent activation of the Objective.";
	//bProjTarget				= true;
	//bBlockBulletTraces		= false;
}

/*
State Counting
{
	Event bool UsedBy(APawn* User)
	{
		if (User == StoredInstigator)
		{
			BeginState();
			return true;
		}
		return false;
	}
	Function StopCounting()
	{
		if (StoredInstigator != nullptr)
		{
			Cast<AHumanController>(StoredInstigator.Controller).LockPlayer(false,false);
		}
		if (StoredInstigator != nullptr)
		{
			StoredInstigator.bUsingObjective=false;
		}
		TriggerEvent(InterruptedEvent,Self,StoredInstigator);
		Super::StopCounting();
	}
	Function Tick(float Delta)
	{
		if ((Cast<AAGP_Pawn>(StoredInstigator) != nullptr) && Cast<AAGP_Pawn>(StoredInstigator).PressingAction())
		{
			SendPercentage(StoredInstigator);
		}
		else
		{
			StopCounting();
		}
	}
	Function PawnDied(APawn* p)
	{
		Super::PawnDied(p);
		if (p == StoredInstigator)
		{
			StopCounting();
		}
	}
	Function BeginState()
	{
		Super::BeginState();
		if (StoredInstigator != nullptr)
		{
			StoredInstigator.bUsingObjective=true;
		}
	}
	Function EndState()
	{
		if (StoredInstigator != nullptr)
		{
			StoredInstigator.bUsingObjective=false;
		}
		Super::EndState();
	}
}
*/

void AAGP_ActivatedObjective::Touch(AActor* Other)
{
}
void AAGP_ActivatedObjective::Trigger(AActor* Other, APawn* _Instigator)
{
}
bool AAGP_ActivatedObjective::NoPickupsInsideFor(APawn* User)
{
	AHumanController* HC;
	HC=Cast<AHumanController>(Cast<AAGP_Pawn>(User)->Controller);
	if (HC != NULL)
	{
		//if (Cast<AHumanController>(HC)->SearchForPickup(Cast<AHumanController>(HC)->GetTraceDistance()))
		//{
		//	return false;
		//}
	}
	return true;
}
bool AAGP_ActivatedObjective::UsedBy(APawn* User)
{
	/*
		if (IsEnabled() && CanAccomplish(User) && NoPickupsInsideFor(User))
		{
			if (Self->IsA(AAGP_CoopESSObjective::StaticClass()))
			{
				if (bPlayerRadioedObectiveInfo && fpTimeUntilESSInvestigateRadioCompletes > 0 && fpTimeUntilESSInvestigateRadioCompletes > GetWorld()->GetTimeSeconds())
				{
					if (Cast<AHumanController>(User.Controller) != nullptr)
					{
						Cast<AHumanController>(User.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
					}
					else
					{
						Log("I ain't talking to you");
					}
					return false;
				}
			}
			TriggerEvent(StartedEvent,Self,User);
			if (fTimeToTrigger <= 0)
			{
				AccomplishObjective(User);
			}
			else
			{
				if (User.Weapon != nullptr && User.Weapon.IsInState('BusyReloading') || User.Weapon.IsInState('Reloading'))
				{
					return false;
				}
				if (User.Physics == 2)
				{
					return false;
				}
				StoredInstigator=User;
				Cast<AHumanController>(StoredInstigator.Controller).LockPlayer(true,true);
				StoredInstigator.CombatEffectivenessEvent(7);
				iLastProgressPercent=0;
				GotoState('Counting');
			}
			return true;
		}
		return false;
	*/
	return false;    //FAKE  /ELiZ
}
void AAGP_ActivatedObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	/*
		Cast<AHumanController>(Instigator.Controller).LockPlayer(false,false);
		if (Instigator.Weapon != nullptr)
		{
			Instigator.Weapon.TempRaiseWeapon();
		}
		AccomplishObjective(_Instigator);
	*/
}
