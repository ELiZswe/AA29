// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"

ASoldierClass::ASoldierClass()
{
	WM_Override.SetNum(6);
	MILESEquipment.SetNum(8);
	ClassEquipment.SetNum(32);
	fOriginalStrength  = 20;
	nativeBonus        = 1.1;
	_ShortName         = "?";
}

FString ASoldierClass::GetClassID()
{
	return _ShortName;
}

void ASoldierClass::PreBeginPlay()
{
	//myPawn             = Cast<AAGP_Pawn>(GetOwner());
	fOriginalSpeed     = Cast<AAGP_Pawn>(myPawn)->fSpeed;
	fOriginalStrength  = Cast<AAGP_Pawn>(myPawn)->fStrength;
	fOriginalAgility   = Cast<AAGP_Pawn>(myPawn)->fAgility;
	fOriginalEndurance = Cast<AAGP_Pawn>(myPawn)->fEndurance;
	//DebugLog(DEBUG_Char,"SoldierClass::PreBeginPlay()	Got myPawn " + myPawn);
}

void ASoldierClass::adjustAttributes(ASoldierClass* LastClass)
{
	if (LastClass != NULL)
	{
		Cast<AAGP_Pawn>(myPawn)->fStrength=LastClass->fOriginalStrength;
		Cast<AAGP_Pawn>(myPawn)->fSpeed=LastClass->fOriginalSpeed;
		Cast<AAGP_Pawn>(myPawn)->fAgility=LastClass->fOriginalAgility;
		Cast<AAGP_Pawn>(myPawn)->fEndurance=LastClass->fOriginalEndurance;
	}
	fOriginalSpeed     = Cast<AAGP_Pawn>(myPawn)->fSpeed;
	fOriginalStrength  = Cast<AAGP_Pawn>(myPawn)->fStrength;
	fOriginalAgility   = Cast<AAGP_Pawn>(myPawn)->fAgility;
	fOriginalEndurance = Cast<AAGP_Pawn>(myPawn)->fEndurance;
}

void ASoldierClass::addClassInventory(bool bMaybeSkip)
{
	/*
		int i;
		AAGP_PlayerStart* PS;
		bool bPlayerForcedFromSniper;
		FString AddEquipment;
		bool bUseAlternate;
		bool bIndigenous;
		if (myPawn == NULL)
		{
			return;
		}
		if (bMaybeSkip)
		{
			PS=Cast<AAGP_PlayerStart>(myPawn.Controller.StartSpot);
			if (PS != NULL)
			{
				PS->ResetSkipInventory();
			}
			else
			{
				bMaybeSkip=false;
			}
		}
		if (PS != NULL && myPawn.PlayerReplicationInfo != nullptr)
		{
			if (PS.bSpecialForces && ! myPawn.PlayerReplicationInfo.bQualifiedSF)
			{
				bIndigenous=true;
				bUseAlternate=true;
			}
			else
			{
				bIndigenous=PS.bGuerrilla;
				bUseAlternate=false;
			}
		}
		else
		{
			bIndigenous=false;
			bUseAlternate=false;
		}
		if (PS != nullptr && PS.SpawnClass != nullptr && PS.SpawnClass.Default.nativeWeapon == 4)
		{
			if (Default.nativeWeapon != 4)
			{
				if (! myPawn.bForcedWeaponChange)
				{
					bPlayerForcedFromSniper=true;
				}
			}
		}
		for (i=0; i<32; i++)
		{
			if (PS != nullptr && PS.SpawnClass != nullptr && PS.SpawnClass.Default.nativeWeapon == 4 && i == 0 && bPlayerForcedFromSniper)
			{
				AddEquipment="AGP_Inventory.Weapon_M16A2_Rifle";
			}
			else
			{
				if (bUseAlternate)
				{
					AddEquipment=GetAlternateClass().Default.ClassEquipment[i];
				}
				else
				{
					AddEquipment=ClassEquipment[i];
				}
			}
			if (bPlayerForcedFromSniper)
			{
				if (AddEquipment ~= "AGP_Inventory.Throw_M67_Frag" || AddEquipment ~= "AGP_Inventory.Throw_MILES_Grenade" || AddEquipment ~= "AGP_Inventory.Throw_M14_Incendiary" || AddEquipment ~= "AGP_Inventory.Throw_POM_2S" || AddEquipment ~= "AGP_Inventory.Throw_RGD5_FRag" || AddEquipment ~= "AGP_Inventory.Weapon_M9_Pistol")
				{
				}
			}
			else
			{
				if (! bMaybeSkip || PS != nullptr && ! PS.SkipInventory(AddEquipment))
				{
					myPawn.CreateInventoryFromName(AddEquipment,bIndigenous);
				}
			}
		}
		if (Level.GamePlayMode == 1)
		{
			for (i=0; i<8; i++)
			{
				if (! bMaybeSkip || PS != nullptr && ! PS.SkipInventory(MILESEquipment[i]))
				{
					myPawn.CreateInventoryFromName(MILESEquipment[i]);
				}
			}
		}
		if (AddBinocs())
		{
			myPawn.CreateInventoryFromName(Level.GetDefaultBinoc());
		}
		if (myPawn.PlayerReplicationInfo != nullptr && myPawn.PlayerReplicationInfo.bIsMedic)
		{
			myPawn._InvMedPacks=3;
		}
		if (myPawn.PlayerReplicationInfo != nullptr && myPawn.PlayerReplicationInfo.bQualifiedMedic)
		{
			myPawn._InvSelfHealMedPacks=1;
		}
	*/
}

UClass* ASoldierClass::GetAlternateClass()
{
	return this->GetClass();
}

bool ASoldierClass::AddBinocs()
{
	AAA2_PlayerState* PRI = nullptr;
	/*
	PRI = myPawn->PlayerReplicationInfo;
	if (PRI != nullptr)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bAddSLBinocs && PRI->IsSquadLeader())
		{
			return true;
		}
		else
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bAddFTBinocs && PRI->isTeamLeader())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	*/
	return false;
}

void ASoldierClass::addTeamInventory()
{
	int32 i = 0;
	uint8 TeamNum = 0;
	AInventory* invclass = nullptr;
	/*
	if (myPawn.PlayerReplicationInfo == nullptr || myPawn.PlayerReplicationInfo.Team == nullptr)
	{
		return;
	}
	TeamNum=myPawn.PlayerReplicationInfo.Team.TeamIndex;
	if (TeamNum == 0 && Level.bTeam0HasNVGs && ! myPawn.PlayerReplicationInfo.bGuerrillaPS || TeamNum == 1 && Level.bTeam1HasNVGs && ! myPawn.PlayerReplicationInfo.bGuerrillaPS)
	{
		myPawn._OpticsDevice=Spawn(class<BaseOptics>(DynamicLoadObject("AGP_Inventory.NightOpticsDevice",Class'Class')),myPawn);
		myPawn._OpticsDevice.DoAttachStuffWhichShouldBeDoneInInventory();
	}
	if (myPawn.Weapon != nullptr && ! myPawn.Weapon->IsA(AItem_Parachute::StaticClass()) && TeamNum == 0 && Level.bTeam0HasParachute || TeamNum == 1 && Level.bTeam1HasParachute)
	{
		myPawn.CreateInventoryFromName("AGP_Inventory.Item_Parachute");
	}
	for (i=0; i<16; i++)
	{
		if (TeamNum == 0)
		{
			invclass=Level.Team0Inventory[i];
		}
		else
		{
			invclass=Level.Team1Inventory[i];
		}
		if (invclass != nullptr)
		{
			myPawn.CreateInventory(invclass);
		}
	}
	*/
}

void ASoldierClass::addPSInventory()
{
	int32 i = 0;
	AAGP_PlayerStart* PS = nullptr;
	bool bPlayerForcedFromSniper = false;
	PS =Cast<AAGP_PlayerStart>(Cast<APawn>(myPawn)->Controller->StartSpot);
	/*
	if (PS != nullptr)
	{
		if (PS.SpawnClass != nullptr && PS.SpawnClass.Default.nativeWeapon == 4)
		{
			if (Default.nativeWeapon != 4)
			{
				bPlayerForcedFromSniper=true;
			}
		}
		for (i=0; i<16; i++)
		{
			if (InStr(PS.AddedInventory[i],"Sniper") != -1 && bPlayerForcedFromSniper)
			{
			}
			else
			{
				if (! PS.bGuerrilla)
				{
					myPawn.CreateInventory(PS.AddedInventory[i]);
				}
				else
				{
					myPawn.CreateInventory(PS.AddedInventory[i],,true);
				}
			}
		}
		if (myPawn.Weapon != nullptr)
		{
			if (PS.bGiveParachute && ! myPawn.Weapon->IsA(AItem_Parachute::StaticClass()))
			{
				myPawn.CreateInventoryFromName("AGP_Inventory.Item_Parachute");
			}
			if (PS.ShouldSetInitialParaState() && myPawn.Weapon->IsA(AItem_Parachute::StaticClass()))
			{
				myPawn.UpdateParachute(PS.GetInitialParaState());
			}
		}
	}
	*/
}

bool ASoldierClass::IsInLoadout(AInventory* InventoryClass)
{
	/*
	int i;
	FString invstring;
	invstring=InventoryClass;
	for (i=0; i<32; i++)
	{
		if (ClassEquipment[i] ~= invstring)
		{
			return true;
		}
	}
	*/
	return false;   //FAKE    /EliZ
}

float ASoldierClass::WeaponEffectivenessBonus(AAGP_Weapon* W)
{
	/*
	if (W != NULL && IsBonusEquivalent(W->weaponType,nativeWeapon) || Cast<AAGP_Pawn>(myPawn)->Controller->bNativeBonus)
	{
		return nativeBonus;
	}
	else
	{
		return 1;
	}
	*/
	return 1;	//Fake   /ELiZ
}

bool ASoldierClass::IsBonusEquivalent(EWeaponType t1, EWeaponType t2)
{
	if (t1 == t2)
	{
		return true;
	}
	switch(t1)
	{
	case EWeaponType::WEAPON_Rifle:
			return t2 == EWeaponType::WEAPON_Gren;
		case EWeaponType::WEAPON_Gren:
			return t2 == EWeaponType::WEAPON_Rifle;
		default:
			return false;
	}
}
