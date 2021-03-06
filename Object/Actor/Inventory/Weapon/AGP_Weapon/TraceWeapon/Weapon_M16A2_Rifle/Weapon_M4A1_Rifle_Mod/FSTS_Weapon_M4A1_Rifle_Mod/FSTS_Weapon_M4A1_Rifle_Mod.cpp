// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/FSTS_Weapon_M4A1_Rifle_Mod/FSTS_Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"
#include "Engine/Canvas.h"

AFSTS_Weapon_M4A1_Rifle_Mod::AFSTS_Weapon_M4A1_Rifle_Mod()
{
	bInitializeWeaponDown  = true;
	fRuinedPct             = 0;
	AmmoName               = AFA_Ammo_556_30_Mag_Blanks::StaticClass();
	iMisFire               = 0;
}

void AFSTS_Weapon_M4A1_Rifle_Mod::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	if (true)
	{
		Canvas.DrawText("WEAPON " + GetItemName(this));
		YPos += YL;
		Canvas.SetPos(4,YPos);
	}
	else
	{
		DisplayDebug(Canvas,YL,YPos);
	}
	*/
}

void AFSTS_Weapon_M4A1_Rifle_Mod::TweenDown()
{
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	/*
		GetAnimParams(0,SeqName,AnimFrame,AnimRate);
		if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
		{
			TweenAnim(SeqName,AnimFrame * 0.4);
		}
		else
		{
			if (_bActive)
			{
				if (HasAnim('Drop'))
				{
					RunAnimation('Drop',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
			else
			{
				if (bInitializeWeaponDown)
				{
					bInitializeWeaponDown=false;
				}
				else
				{
					PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				}
				if (SeqName == 'Drop' || SeqName == 'DropStill')
				{
					RunAnimation('LowDown',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
		}
	*/
}
void AFSTS_Weapon_M4A1_Rifle_Mod::SetupClientWeapon()
{
	/*
		Instigator=Pawn(GetOwner());
		SpawnAndAttachAmmoRounds();
		SpawnAndAttachMILESGear();
		SetWeaponSkins();
		SpawnMuzzleFlash();
		SpawnAndAttachScope();
		UpdateCurrentAmmoRounds();
		BaseWeaponAttachment(ThirdPersonActor).InitializeShellEmitter();
		if (bBusyRaiseWeaponPending)
		{
			GotoState('BusyLoweringWeapon');
			bBusyRaiseWeaponPending=false;
			bBusyLowerWeaponPending=false;
		}
	*/
}
