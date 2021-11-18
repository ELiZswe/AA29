// All the original content belonged to the US Army


#include "FSTS_Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"

AFSTS_Weapon_M4A1_Rifle_Mod::AFSTS_Weapon_M4A1_Rifle_Mod()
{
	bInitializeWeaponDown  = true;
	fRuinedPct             = 0;
	AmmoName               = AFA_Ammo_556_30_Mag_Blanks::StaticClass();
	iMisFire               = 0;
}

/*
void AFSTS_Weapon_M4A1_Rifle_Mod::DisplayDebug(UCanvas* Canvas, float YL, float YPos)
{
		if (True)
		{
			Canvas.DrawText("WEAPON " $ GetItemName(Self));
			YPos += YL;
			Canvas.SetPos(4,YPos);
		}
		else
		{
			DisplayDebug(Canvas,YL,YPos);
		}
}
*/
void AFSTS_Weapon_M4A1_Rifle_Mod::TweenDown()
{
	/*
		local name SeqName;
		local float AnimFrame;
		local float AnimRate;
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
					bInitializeWeaponDown=False;
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
		Instigator=Pawn(Owner);
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
			bBusyRaiseWeaponPending=False;
			bBusyLowerWeaponPending=False;
		}
	*/
}
