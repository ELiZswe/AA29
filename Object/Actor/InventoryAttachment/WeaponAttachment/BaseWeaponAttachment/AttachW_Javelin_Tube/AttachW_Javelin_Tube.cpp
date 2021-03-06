// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_Javelin_Tube/AttachW_Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAttachW_Javelin_Tube::AAttachW_Javelin_Tube()
{
	TubeInHands = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PIH.Tube3PIH'"), NULL, LOAD_None, NULL);
	SlungWeaponLocationOffset  = FVector(2, 2, 0);
	_WeaponOffset3P            = FVector(0, 0, 0);
	EnemyAttachmentClass       = AAttachW_Javelin_Tube::StaticClass();
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube_OnBack.Tube_OnBack'"), NULL, LOAD_None, NULL);
}

UStaticMesh* AAttachW_Javelin_Tube::GetStaticMesh(bool bFriendly)
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Base);
	if ((p->getAltShoulderInventory() != nullptr) && p->getAltShoulderInventory()->IsChildOf(AJavelin_Tube::StaticClass()))
	{
		return GetDefault<AAttachW_Javelin_Tube>()->StaticMesh;
	}
	else
	{
		return TubeInHands;
	}
}

void AAttachW_Javelin_Tube::AttachmentAnimation()
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Base);
	if (p != nullptr)
	{
		if (IsAnimState(1))
		{
			/*
			p.AttachToBone(this, "WeaponBone");
			SetStaticMesh(TubeInHands);
			Self.SetRelativeLocation(FVector(0, 0, 0));
			SetDrawType(Default.DrawType);
			bCurrentlySelectedAttachment = true;
			*/
		}
		else
		{
			/*
			p.AttachToBone(this, "RSlungWeapon");
			SetStaticMesh(Default.StaticMesh);
			if (IsNotUS(p))
			{
				Self.SetRelativeLocation((_WeaponOffset3P + SlungWeaponLocationOffset));
			}
			else
			{
				Self.SetRelativeLocation(SlungWeaponLocationOffset);
			}
			SetDrawType(Default.DrawType);
			bCurrentlySelectedAttachment = false;
			*/
		}
	}
}
