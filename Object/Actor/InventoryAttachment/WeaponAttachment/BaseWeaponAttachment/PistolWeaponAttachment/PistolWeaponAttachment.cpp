// All the original content belonged to the US Army


#include "PistolWeaponAttachment.h"


APistolWeaponAttachment::APistolWeaponAttachment()
{
	PawnStdReloadAnimation  = FName("StdSmRld_E");
	PawnPrnReloadAnimation  = FName("PrnSmRld");
	bHasAttachmentReload    = true;
	IdleAnim                = FName("Full");
	FireAnim                = FName("Fire");
	FireLastAnim            = FName("FireLast");
	IdleEmptyAnim           = FName("Empty");
	FixJamAnim              = FName("StdSmFxjm");
	EmptyReloadAnim         = FName("StdSmRld_E");
	FullReloadAnim          = FName("StdSmRld_F");
	PrnEmptyReloadAnim      = FName("PrnSmRld_E");
	PrnFullReloadAnim       = FName("PrnSmRld_F");
	DrawType                = EDrawType::DT_Mesh;
}


void APistolWeaponAttachment::PostBeginPlay()
{
	/*
		PostBeginPlay();
	*/
}
void APistolWeaponAttachment::AdjustAttachmentFor(AInventory* Inv)
{
	/*
		if (Inv.Instigator.Weapon == Inv)
		{
			if (AGP_Weapon(Inv).IsInState('BusyFiring') && AGP_Weapon(Inv).GetCurrentAmmoType().AmmoAmount > 1)
			{
				Return;
			}
			if (AGP_Weapon(Inv).IsInState('BusyReloading'))
			{
				Return;
			}
			if (AGP_Weapon(Inv).IsInState('BusyFiring') && AGP_Weapon(Inv).GetCurrentAmmoType().AmmoAmount < 1)
			{
				AnimState=2;
			}
			else
			{
				if (AGP_Weapon(Inv).IsInState('BusyFixingJam'))
				{
					AnimState=6;
				}
				else
				{
					if (AGP_Weapon(Inv).OutOfAmmo())
					{
						AnimState=3;
					}
					else
					{
						if (AGP_Weapon(Inv).IsInState('Idle'))
						{
							AnimState=0;
						}
					}
				}
			}
		}
		else
		{
			AnimState=7;
		}
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			AttachmentAnimation();
		}
	*/
}
void APistolWeaponAttachment::AttachmentAnimation()
{
	/*
		local AGP_Pawn p;
		p=AGP_Pawn(Base);
		if (p == None)
		{
			Return;
		}
		if (AnimState == 7)
		{
			p.AttachToBone(Self,'RSideArm');
			if (IsNotUS(p))
			{
				SetDrawType(0);
			}
			else
			{
				SetDrawType(Default.DrawType);
			}
			bCurrentlySelectedAttachment=False;
		}
		else
		{
			p.AttachToBone(Self,'RHandObject');
			SetDrawType(Default.DrawType);
			bCurrentlySelectedAttachment=True;
		}
		Switch(AnimState)
		{
			case 2:
			PlayAnim(FireLastAnim,1,0);
			break;
			case 3:
			PlayAnim(IdleEmptyAnim,1,0.05);
			break;
			case 6:
			PlayAnim(FixJamAnim,1,0.05);
			break;
			case 0:
			PlayAnim(IdleAnim,1,0);
			break;
			case 7:
			PlayAnim(IdleAnim,1,0);
			break;
			default:
			PlayAnim(IdleAnim,1,0);
			break;
		}
	*/
}
void APistolWeaponAttachment::PlayThirdPersonFiring()
{
	/*
		if (AnimState != 2)
		{
			PlayAnim(FireAnim,1,0);
		}
	*/
}
void APistolWeaponAttachment::PlayAttachmentReload(int32 SpecialReload)
{
	/*
		local AGP_Pawn p;
		p=AGP_Pawn(Base);
		if (SpecialReload == -1)
		{
			PlayAnim(IdleAnim,1,0.05);
			Return;
		}
		if (AnimState == 3)
		{
			if (p.bIsProne)
			{
				PlayAnim(PrnEmptyReloadAnim,1,0.05);
			}
			else
			{
				PlayAnim(EmptyReloadAnim,1,0.05);
			}
		}
		else
		{
			if (p.bIsProne)
			{
				PlayAnim(PrnFullReloadAnim,1,0.05);
			}
			else
			{
				PlayAnim(FullReloadAnim,1,0.05);
			}
		}
	*/
}
void APistolWeaponAttachment::ThirdPersonEffects()
{
	/*
		ThirdPersonEffects();
		PlayThirdPersonFiring();
	*/
}
