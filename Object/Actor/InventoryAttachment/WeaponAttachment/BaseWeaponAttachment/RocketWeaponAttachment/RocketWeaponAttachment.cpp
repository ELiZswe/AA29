// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/RocketWeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

ARocketWeaponAttachment::ARocketWeaponAttachment()
{
	_WeaponOffset3P = FVector(0, 0, 0);
}

void ARocketWeaponAttachment::PlayAttachmentReload(int32 SpecialReload)
{
	AAGP_Pawn* p = nullptr;
	/*
	p=Cast<AAGP_Pawn>(Base);
	AnimState=AnimState | 16;
	AttachmentAnimation();
	if (SpecialReload == -1)
	{
		PlayAnim(IdleAnim,1,0.05);
	}
	else
	{
		PlayAnim(EmptyReloadAnim,1,0);
	}
	*/
}

void ARocketWeaponAttachment::ThirdPersonEffects()
{
	/*
	ThirdPersonEffects();
	AnimState=AnimState & ~ 16;
	AttachmentAnimation();
	if (HasAnim(IdleEmptyAnim))
	{
		PlayAnim(IdleEmptyAnim,1,0.05);
	}
	*/
}

void ARocketWeaponAttachment::Destroyed()
{
	Super::Destroyed();
	if (RPGBackpack != NULL)
	{
		//RPGBackpack->Destroy();
	}
	if (AmmoRound3P != NULL)
	{
		//AmmoRound3P->Destroy();
	}
}

uint8 ARocketWeaponAttachment::AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv)
{
	/*
	if (! Cast<AAGP_Weapon>(Inv).OutOfAmmo() || Cast<AAGP_Weapon>(Inv).IsInState('BusyReloading'))
	{
		NewAnimState=NewAnimState | 16;
	}
	*/
	return NewAnimState;
}

void ARocketWeaponAttachment::AttachmentAnimation()
{
	/*
		AttachmentAnimation();
		if (AmmoRound3P == nullptr)
		{
			return;
		}
		if (IsAnimState(16))
		{
			AmmoRound3P.ShowRound(true);
		}
		else
		{
			AmmoRound3P.ShowRound(false);
		}
	*/
}
