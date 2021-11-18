// All the original content belonged to the US Army


#include "RocketWeaponAttachment.h"


ARocketWeaponAttachment::ARocketWeaponAttachment()
{
	_WeaponOffset3P = FVector(0, 0, 0);
}

void ARocketWeaponAttachment::PlayAttachmentReload(int32 SpecialReload)
{
	/*
		local AGP_Pawn p;
		p=AGP_Pawn(Base);
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
void ARocketWeaponAttachment::AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv)
{
	/*
		if (! AGP_Weapon(Inv).OutOfAmmo() || AGP_Weapon(Inv).IsInState('BusyReloading'))
		{
			NewAnimState=NewAnimState | 16;
		}
		Return NewAnimState;
	*/
}
void ARocketWeaponAttachment::AttachmentAnimation()
{
	/*
		AttachmentAnimation();
		if (AmmoRound3P == None)
		{
			Return;
		}
		if (IsAnimState(16))
		{
			AmmoRound3P.ShowRound(True);
		}
		else
		{
			AmmoRound3P.ShowRound(False);
		}
	*/
}
