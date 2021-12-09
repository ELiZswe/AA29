// All the original content belonged to the US Army


#include "Weapon_T62_Coax.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachW_T62_Coax/AttachW_T62_Coax.h"

AWeapon_T62_Coax::AWeapon_T62_Coax()
{
	FireOffset       = FVector(200, 0, 0);
	AttachmentClass  = { AAttachW_T62_Coax::StaticClass() };
	Mesh             = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M82_1P.M82_1P"), NULL, LOAD_None, NULL);
}


void AWeapon_T62_Coax::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
		if (GetCurrentAmmoType() == None && Pawn(Owner) != None)
		{
			GiveAmmo(Pawn(Owner));
		}
		if (GetCurrentAmmoType() != None && GetCurrentAmmoType().HasAmmo())
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
	/*
		local FVector StartTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local AGP.BaseWeaponAttachment BA;
		local int total_traces;
		local Object.Coords cBoneLocation;
		Instigator=Pawn(Owner);
		cBoneLocation=Vehicle(Instigator).GetActiveWeaponSystem().GetBoneCoords('Muzzle_Bone');
		Owner.MakeNoise(1,Self);
		GetAxes(rotCoaxWeaponAim,X,Y,Z);
		StartTrace=Location + vect(150 0 0);
		DebugLog(DEBUG_Bullet,"Adding offset to coax weapon start location from " $ StartTrace.X $ ", " $ StartTrace.Y $ ", " $ StartTrace.Z);
		BA=BaseWeaponAttachment(ThirdPersonActor);
		VtoPV(StartTrace,BA.BulletTrace[0]);
		GetCurrentAmmoType().UseBullet(StartTrace,X);
		if (BA != None)
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
void AWeapon_T62_Coax::DoTrace(AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	/*
		local Actor HitActor;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		local FVector HitLocation;
		local FVector HitNormal;
		local float CosTheta;
		local bool bDidRicochet;
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
		if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
		{
			fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
			if (fStrength < 0.1)
			{
				Return 0;
			}
		}
		VtoPV(HitLocation,BA.BulletTrace[num_traces]);
		BA.SetBulletImpactType(num_traces,0);
		GetCurrentAmmoType().ProcessTraceHit(Self,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
		if (CanTraceMore(BA,num_traces))
		{
			if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
			{
				CosTheta=Abs(- HitNormal Dot TraceDirection);
				if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FRand())
				{
					fStrength *= 0.9;
					TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
					fTraceDistance -= VSize(StartTrace - HitLocation);
					fTraceDistance *= fStrength;
					BA.SetBulletImpactType(num_traces,2);
					total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,False);
					bDidRicochet=True;
				}
			}
			if (HitActor.bBulletPenetration && ! bDidRicochet)
			{
				fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
				if (fStrength > 0.1)
				{
					DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " $ fStrength);
					TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
					fTraceDistance -= VSize(StartTrace - HitLocation);
					fTraceDistance *= fStrength;
					BA.SetBulletImpactType(num_traces,1);
					total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,True);
				}
				else
				{
					DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " $ fStrength @ num_traces);
				}
			}
		}
		Return total_traces + 1;
	*/
}
void AWeapon_T62_Coax::IncrementFlashCount()
{
	/*
		local AGP.BaseWeaponAttachment BA;
		FlashCount=FlashCount + 1 % 254;
		BA=BaseWeaponAttachment(ThirdPersonActor);
		BA.SetOwner(Self);
		if (BA != None)
		{
			Switch(eROF)
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
			DebugLog(DEBUG_Warn,"AGP_Weapon::IncrementFlashCount()	Could not find BaseWeaponAttachment " $ ThirdPersonActor);
		}
	*/
}
