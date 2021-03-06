// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/FSTS_Weapon_M16A2_Rifle/FSTS_Weapon_M16A2_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "Engine/Canvas.h"

AFSTS_Weapon_M16A2_Rifle::AFSTS_Weapon_M16A2_Rifle()
{
	bInitializeWeaponDown  = true;
	fRuinedPct             = 0;
	AmmoName               = AFA_Ammo_556_30_Mag_Blanks::StaticClass();
	iMisFire               = 0;
}
void AFSTS_Weapon_M16A2_Rifle::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
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

void AFSTS_Weapon_M16A2_Rifle::TweenDown()
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

int32 AFSTS_Weapon_M16A2_Rifle::DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	AActor* HitActor = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector Unused1 = FVector(0, 0, 0);
	FVector Unused2 = FVector(0, 0, 0);
	int32 total_traces = 0;
	/*
	num_traces ++;
	EndTrace=StartTrace + fTraceDistance * TraceDirection;
	TraceFrom.bUseCollisionStaticMesh=true;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,true);
	TraceFrom.bUseCollisionStaticMesh=false;
	if (HitActor == nullptr)
	{
		return 0;
	}
	if (HitActor == Instigator)
	{
		DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Don't ever hit yourself");
		return 0;
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	GetCurrentAmmoType().ProcessTraceHit(this,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	*/
	return total_traces + 1;
}
void AFSTS_Weapon_M16A2_Rifle::SetupClientWeapon()
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
