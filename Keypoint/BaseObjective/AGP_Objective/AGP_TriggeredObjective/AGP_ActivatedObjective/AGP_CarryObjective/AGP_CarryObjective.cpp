// All the original content belonged to the US Army

#include "AGP_CarryObjective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"

AAGP_CarryObjective::AAGP_CarryObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	bWaitingFirstPickup = true;
	//bHidden = true;
}


void AAGP_CarryObjective::Reset()
{
	/*
		InventoryPickup.bWaitingFirstPickup=True;
		bWaitingFirstPickup=True;
		bObjectiveInPlay=False;
		if (InventoryPickup != None && Role == 4)
		{
			InventoryPickup.ResetPickupLocation();
		}
		Reset();
	*/
}
uint8 AAGP_CarryObjective::GetPickupTeamOwner()
{
	return AttackTeam;
}
bool AAGP_CarryObjective::NoPickupsInsideFor(APawn* User)
{
	return true;
}
bool AAGP_CarryObjective::IsEnabled()
{
	return ! bDisabled;
}
bool AAGP_CarryObjective::CarryableInPlay()
{
	return ! bDisabled || bDisabled && bObjectiveInPlay;
}
bool AAGP_CarryObjective::UsedBy(APawn* User)
{
	return false;
}
void AAGP_CarryObjective::CarryObjectiveUsed(APawn* User)
{
	/*
		if (CheckAllowedPickupTeam(User) && CarryableInPlay() && NoPickupsInsideFor(User))
		{
			if (CanAccomplish(User))
			{
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
					StoredInstigator=User;
					HumanController(StoredInstigator.Controller).LockPlayer(True,True);
					StoredInstigator.CombatEffectivenessEvent(7);
					GotoState('Counting');
				}
			}
			else
			{
				GiveInventoryPickup(User);
			}
			Return True;
		}
		Return False;
	*/
}
bool AAGP_CarryObjective::CanAccomplish(APawn* User)
{
	if (bWaitingFirstPickup)
	{
		return Super::CanAccomplish(User);
	}
	else
	{
		return false;
	}
}
void AAGP_CarryObjective::DetermineCarriedCompassVisbility(APawn* ObjCarrier, bool bDropped)
{
	int32 TeamNum;
	if (ObjCarrier != NULL && Cast<AAGP_Pawn>(ObjCarrier)->PlayerReplicationInfo != nullptr && Cast<AAGP_Pawn>(ObjCarrier)->PlayerReplicationInfo->Team != nullptr)
	{
		TeamNum= Cast<AAGP_Pawn>(ObjCarrier)->PlayerReplicationInfo->Team->TeamIndex;
	}
	else
	{
		TeamNum=-1;
		UE_LOG(LogTemp, Log, TEXT("%s - Unable to determine Team of Objective Carrier, can't set compass visibility, defaulting to Normal!"), this);
		ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Normal;
		return;
	}
	if (! bDropped)
	{
		switch(CompassVisibilityWhenCarried)
		{
			case ECompassVisibilityCarried::CarriedVisibility_NotOnCompass:
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_NotOnCompass;
					break;
			case ECompassVisibilityCarried::CarriedVisibility_Normal:
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Normal;
					break;
			case ECompassVisibilityCarried::CarriedVisibility_FriendlyOnly:
					if (TeamNum == 0)
					{
						ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team0Only;
					}
					else
					{
						ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team1Only;
					}
			case ECompassVisibilityCarried::CarriedVisibility_EnemyOnly:
				if (TeamNum == 1)
				{
					ObjectiveOnCompass= EObjectiveOnCompass::ONCOMPASS_Team1Only;
				}
				else
				{
					ObjectiveOnCompass= EObjectiveOnCompass::ONCOMPASS_Team0Only;
				}
			default:
				break;
		}
	}
	else
	{
		switch(CompassVisibilityWhenDropped)
		{
		case ECompassVisibilityDropped::DroppedVisibility_Normal:
				ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Normal;
				break;
		case ECompassVisibilityDropped::DroppedVisibility_NotOnCompass:
				ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_NotOnCompass;
				break;
		case ECompassVisibilityDropped::DroppedVisibility_Team0Only:
				ObjectiveOnCompass= EObjectiveOnCompass::ONCOMPASS_Team0Only;
				break;
		case ECompassVisibilityDropped::DroppedVisibility_Team1Only:
				ObjectiveOnCompass= EObjectiveOnCompass::ONCOMPASS_Team1Only;
				break;
		case ECompassVisibilityDropped::DroppedVisibility_FriendlyOnly:
				if (TeamNum == 0)
				{
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team0Only;
				}
				else
				{
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team1Only;
				}
		case ECompassVisibilityDropped::DroppedVisibility_EnemyOnly:
				if (TeamNum == 1)
				{
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team1Only;
				}
				else
				{
					ObjectiveOnCompass=EObjectiveOnCompass::ONCOMPASS_Team0Only;
				}
			default:
				break;
		}
	}
	bChangeObjectiveOnCompassOnCompletion=false;
}
bool AAGP_CarryObjective::IsOnCompass(AController* ctrlRequesting)
{
	
		AAA2_PlayerState* ProxyPRI;
		AAA2_PlayerState* ClientPRI;
		if (ctrlRequesting == nullptr)
		{
			//ctrlRequesting=Level.GetClient().GetController();
		}
		switch(ObjectiveOnCompass)
		{
			case EObjectiveOnCompass::ONCOMPASS_NotOnCompass:
					return false;
			case EObjectiveOnCompass::ONCOMPASS_Team0Only:
				if (Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team->TeamIndex != 0)
				{
					return false;
				}
				break;
			case EObjectiveOnCompass::ONCOMPASS_Team1Only:
				if (Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team->TeamIndex != 1)
				{
					return false;
				}
				break;
			case EObjectiveOnCompass::ONCOMPASS_ObjEnabledTeam0Only:
				if (! IsEnabled() || Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team != nullptr && Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team->TeamIndex != 0)
				{
					return false;
				}
				break;
			case EObjectiveOnCompass::ONCOMPASS_ObjEnabledTeam1Only:
				if (! IsEnabled() || Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team != nullptr && Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo->Team->TeamIndex != 1)
				{
					return false;
				}
				break;
			default:
				break;
		}
		if (LocationProxy != nullptr)
		{
			if (Cast<AAA2_PlayerState>(LocationProxy)==nullptr)
			{
				ClientPRI= Cast<AHumanController>(ctrlRequesting)->PlayerReplicationInfo;
				ProxyPRI= Cast<AAA2_PlayerState>(LocationProxy);

				if (ClientPRI == nullptr || ProxyPRI == ClientPRI)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (Cast<AAGP_ObjectivePickup>(LocationProxy)==nullptr)
				{
					return true;
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			return IsEnabled();
		}
	
}
void AAGP_CarryObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	if (_Instigator == nullptr)
	{
		return;
	}
	AccomplishObjective(_Instigator,Killer);
	Cast<AAGP_ObjectivePickup>(InventoryPickup)->bBroadcastPickupMsgs=true;
	bObjectiveInPlay=true;
	Cast<AAGP_ObjectivePickup>(InventoryPickup)->bWaitingFirstPickup=false;
	bWaitingFirstPickup=false;
	GiveInventoryPickup(_Instigator);
}
void AAGP_CarryObjective::GiveInventoryPickup(APawn* _Instigator)
{
	AInventory* Item = nullptr;
	if (InventoryPickup != nullptr && _Instigator != nullptr)
	{
		Item = Cast<AAGP_ObjectivePickup>(InventoryPickup)->TakeItem(_Instigator);
		DetermineCarriedCompassVisbility(_Instigator,false);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT(this $ " InventoryPickup is " $ InventoryPickup $ " and Instigator is " $ _Instigator));
	}
	
	if (Item == nullptr || Cast<AAGP_ObjectivePickup>(InventoryPickup)->GetInstigator() != _Instigator)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AGP_CarryObjective::AccomplishObjective()	Item(" @ Item @ ") Instigator(" @ Instigator @ ") InventoryPickup(" @ InventoryPickup @ ") IP.Instigator(" @ InventoryPickup.Instigator @ ")"));
	}
	
}
bool AAGP_CarryObjective::CheckAllowedPickupTeam(APawn* User)
{
	AController* C;
	int32 TeamIndex;
	if (AttackTeam == 255)
	{
		return true;
	}
	if (User != nullptr)
	{
		C=Cast<AAGP_Pawn>(User)->Controller;
		if (C != nullptr && Cast<AAGP_Pawn>(C)->PlayerReplicationInfo != nullptr)
		{
			TeamIndex= Cast<AAGP_Pawn>(C)->PlayerReplicationInfo->Team->TeamIndex;
			if (AttackTeam == TeamIndex)
			{
				return true;
			}
		}
	}
	return false;
}