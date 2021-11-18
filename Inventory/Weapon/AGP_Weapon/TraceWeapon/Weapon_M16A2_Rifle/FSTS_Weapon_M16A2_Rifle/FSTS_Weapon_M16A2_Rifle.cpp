// All the original content belonged to the US Army


#include "FSTS_Weapon_M16A2_Rifle.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"


AFSTS_Weapon_M16A2_Rifle::AFSTS_Weapon_M16A2_Rifle()
{
	bInitializeWeaponDown  = true;
	fRuinedPct             = 0;
	AmmoName               = AFA_Ammo_556_30_Mag_Blanks::StaticClass();
	iMisFire               = 0;
}
/*

void AFSTS_Weapon_M16A2_Rifle::DisplayDebug(UCanvas* Canvas, float YL, float YPos)
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
void AFSTS_Weapon_M16A2_Rifle::TweenDown()
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
void AFSTS_Weapon_M16A2_Rifle::DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	/*
		local Actor HitActor;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		local FVector HitLocation;
		local FVector HitNormal;
		local FVector EndTrace;
		local FVector Unused1;
		local FVector Unused2;
		local int total_traces;
		num_traces ++;
		EndTrace=StartTrace + fTraceDistance * TraceDirection;
		TraceFrom.bUseCollisionStaticMesh=True;
		HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,True);
		TraceFrom.bUseCollisionStaticMesh=False;
		if (HitActor == None)
		{
			Return 0;
		}
		if (HitActor == Instigator)
		{
			DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Don't ever hit yourself");
			Return 0;
		}
		VtoPV(HitLocation,BA.BulletTrace[num_traces]);
		GetCurrentAmmoType().ProcessTraceHit(Self,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
		Return total_traces + 1;
	*/
}
void AFSTS_Weapon_M16A2_Rifle::SetupClientWeapon()
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
