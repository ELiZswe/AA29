// All the original content belonged to the US Army


#include "AGP_ActivatedObjective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAGP_ActivatedObjective::AAGP_ActivatedObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	AccomplishMessage		= "Objective activated.";
	FailedDefenseMessage	= "Your team failed to prevent activation of the Objective.";
	//bProjTarget				= true;
	//bBlockBulletTraces		= false;
}

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
			if (Self.IsA('AGP_CoopESSObjective'))
			{
				if (bPlayerRadioedObectiveInfo && fpTimeUntilESSInvestigateRadioCompletes > 0 && fpTimeUntilESSInvestigateRadioCompletes > GetWorld()->GetTimeSeconds())
				{
					if (HumanController(User.Controller) != None)
					{
						HumanController(User.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
					}
					else
					{
						Log("I ain't talking to you");
					}
					Return False;
				}
			}
			TriggerEvent(StartedEvent,Self,User);
			if (fTimeToTrigger <= 0)
			{
				AccomplishObjective(User);
			}
			else
			{
				if (User.Weapon != None && User.Weapon.IsInState('BusyReloading') || User.Weapon.IsInState('Reloading'))
				{
					Return False;
				}
				if (User.Physics == 2)
				{
					Return False;
				}
				StoredInstigator=User;
				HumanController(StoredInstigator.Controller).LockPlayer(True,True);
				StoredInstigator.CombatEffectivenessEvent(7);
				iLastProgressPercent=0;
				GotoState('Counting');
			}
			Return True;
		}
		Return False;
	*/
	return false;    //FAKE  /ELiZ
}
void AAGP_ActivatedObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	/*
		HumanController(Instigator.Controller).LockPlayer(False,False);
		if (Instigator.Weapon != None)
		{
			Instigator.Weapon.TempRaiseWeapon();
		}
		AccomplishObjective(_Instigator);
	*/
}
