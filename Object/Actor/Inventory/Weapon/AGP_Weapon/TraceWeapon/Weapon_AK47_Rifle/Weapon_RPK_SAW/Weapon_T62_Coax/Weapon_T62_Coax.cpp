// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_RPK_SAW/Weapon_T62_Coax/Weapon_T62_Coax.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_T62_Coax/AttachW_T62_Coax.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"

AWeapon_T62_Coax::AWeapon_T62_Coax()
{
	FireOffset       = FVector(200, 0, 0);
	AttachmentClass  = { AAttachW_T62_Coax::StaticClass() };
	Mesh             = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M82_1P.M82_1P"), NULL, LOAD_None, NULL);
}

void AWeapon_T62_Coax::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
		if (GetCurrentAmmoType() == nullptr && Pawn(GetOwner()) != nullptr)
		{
			GiveAmmo(Cast<APawn>(GetOwner()));
		}
		if (GetCurrentAmmoType() != nullptr && GetCurrentAmmoType().HasAmmo())
		{
			if (IsInState('BusyFiring'))
			{
				BeginState();
			}
			else
			{
				if (! IsInState('BusyTempLowering'))
				{
					GotoState('BusyFiring');
				}
			}
		}
		else
		{
			DebugLog(DEBUG_Inv,"AGP_Weapon::VehicleCoaxServerFire() Got here with no ammo! " @ Self);
		}
	*/
}

void AWeapon_T62_Coax::TraceFire(float Accuracy, float YOffset, float ZOffset)
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0,0,0);
	ABaseWeaponAttachment* BA = nullptr;
	int32 total_traces = 0;
	FCoords cBoneLocation = FCoords({});
	/*
	Instigator=Pawn(GetOwner());
	cBoneLocation=Vehicle(Instigator).GetActiveWeaponSystem().GetBoneCoords('Muzzle_Bone');
	Owner.MakeNoise(1,Self);
	GetAxes(rotCoaxWeaponAim,X,Y,Z);
	StartTrace=Location + FVector(150 0 0);
	DebugLog(DEBUG_Bullet,"Adding offset to coax weapon start location from " + StartTrace.X + ", " + StartTrace.Y + ", " + StartTrace.Z);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	VtoPV(StartTrace,BA.BulletTrace[0]);
	GetCurrentAmmoType().UseBullet(StartTrace,X);
	if (BA != nullptr)
	{
		total_traces=DoTrace(BA.GetSource(),StartTrace,X,TraceDist,1,0,BA);
	}
	DebugLog(DEBUG_Bullet,"AGP_Weapon::TraceFire() Did (" @ total_traces @ ") total traces");
	BA.TraceCount ++;
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		BA.ThirdPersonTrace();
	}
	DebugLog(DEBUG_Bullet,"-----------------------------");
	*/
}

int32 AWeapon_T62_Coax::DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	AActor* HitActor = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0,0,0);
	float CosTheta = 0;
	bool bDidRicochet = false;
	FVector EndTrace = FVector(0,0,0);
	FVector Unused1 = FVector(0,0,0);
	FVector Unused2 = FVector(0,0,0);
	int32 total_traces = 0;
	num_traces ++;
	/*
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
	if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
	{
		fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
		if (fStrength < 0.1)
		{
			return 0;
		}
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	BA.SetBulletImpactType(num_traces,0);
	GetCurrentAmmoType().ProcessTraceHit(this,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	if (CanTraceMore(BA,num_traces))
	{
		if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
		{
			CosTheta=FMath::Abs(- HitNormal Dot TraceDirection);
			if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FMath::FRand())
			{
				fStrength *= 0.9;
				TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,2);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,false);
				bDidRicochet=true;
			}
		}
		if (HitActor.bBulletPenetration && ! bDidRicochet)
		{
			fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
			if (fStrength > 0.1)
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " + fStrength);
				TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,1);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,true);
			}
			else
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " + fStrength @ num_traces);
			}
		}
	}
	*/
	return total_traces + 1;
}

void AWeapon_T62_Coax::IncrementFlashCount()
{
	ABaseWeaponAttachment* BA = nullptr;
	/*
	FlashCount=FlashCount + 1 % 254;
	BA=BaseWeaponAttachment(ThirdPersonActor);
	BA.SetOwner(this);
	if (BA != nullptr)
	{
		switch(eROF)
		{
			case 1:
			BA.FiringMode='ROF_Single';
			break;
			case 2:
			BA.FiringMode='ROF_Burst';
			break;
			case 3:
			BA.FiringMode='ROF_Auto';
			break;
			case 4:
			BA.FiringMode='ROF_SingleGren';
			break;
			default:
		}
		BA.FlashCount=FlashCount;
		BA.ThirdPersonEffects();
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_Weapon::IncrementFlashCount()	Could not find BaseWeaponAttachment " + ThirdPersonActor);
	}
	*/
}
