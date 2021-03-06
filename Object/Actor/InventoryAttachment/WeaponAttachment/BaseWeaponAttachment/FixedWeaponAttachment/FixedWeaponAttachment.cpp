// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/FixedWeaponAttachment/FixedWeaponAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "AA29/Object/DamageType/AGP_DamageType/VehicleDamage/VehicleDamage.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

AFixedWeaponAttachment::AFixedWeaponAttachment()
{
	//KillPawnDamageType   = AVehicleDamage::StaticClass()
	UseTeam              = 255;
	fRotationMultiplier  = 7;
	bReplicateTurret     = true;
	//bCollideActors       = true;
}

void AFixedWeaponAttachment::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//ClientsVerifyMesh();
}
void AFixedWeaponAttachment::MatchStarting()
{
	/*
		MatchStarting();
		ServerSetTurretValues(0,0);
		Self.LinkTurrets();
		ClientsVerifyMesh(1);
		bDisabled=false;
	*/
}
void AFixedWeaponAttachment::LinkTurrets()
{
	/*
		AssociatedActor=GetActorByTag(EnemyTurretTag);
		EnemyTurret=FixedWeaponAttachment(AssociatedActor);
		if (bUseEnemyMesh && EnemyTurret == nullptr)
		{
			bUseEnemyMesh=false;
			DebugLog(DEBUG_Warn,"FixedWeaponAttachment::LinkTurrets()	Turret (" @ this @ ") Could not find Turret associated with EnemyTurretTag(" @ EnemyTurretTag @ ")");
		}
	*/
}
AFixedWeaponAttachment* AFixedWeaponAttachment::GetEnemyTurret()
{
	return EnemyTurret;
}
void AFixedWeaponAttachment::ManTurret(APawn* p)
{
	/*
		if (FWeapon == nullptr)
		{
			FWeapon=Cast<AFixedWeapon>(Cast<AAGP_Pawn>(p).CreateInventory(FixedWeaponClass,True));
		}
		else
		{
			FWeapon.GiveTo(p);
			FWeapon.PickupFunction(p);
		}
		SetOwner(p);
		TurretController=p;
		Instigator=p;
		FWeapon.SetTurret(this);
	*/
}
void AFixedWeaponAttachment::AbandonWeapon()
{
	AWeapon* ReplaceWeapon = nullptr;
	SetOwner(nullptr);
	//Instigator=nullptr;
	//ReplaceWeapon=Spawn(FixedWeaponClass);
	ReplaceWeapon->InitFor(FWeapon);
	//ReplaceWeapon->instigator=nullptr;
	FWeapon=Cast<AFixedWeapon>(ReplaceWeapon);
}
void AFixedWeaponAttachment::BeginPlay()
{
	Super::BeginPlay();
	//EnableChannelNotify(0,1);
}

void AFixedWeaponAttachment::AnimEnd(int32 Channel)
{
	if (FWeapon != NULL)
	{
		FWeapon->AnimEnd(Channel);
	}
}

void AFixedWeaponAttachment::ThirdPersonEffects()
{
	int32 Num = 0;
	float Rate = 0;
	/*
	if (! bHidden)
	{
		ThirdPersonEffects();
		if (HasAnim('Fire'))
		{
			Rate=0.5 + 0.5 * FixedWeaponClass.Default.FireAdjust;
			if (HasAnim('FireB'))
			{
				if (HasAnim('FireC'))
				{
					Num=Rand(3);
				}
				else
				{
					Num=Rand(2);
				}
			}
			else
			{
				Num=0;
			}
			PlayAnim(FixedWeaponClass.Default.FireAnims[Num],Rate,0.05);
		}
	}
	if (EnemyTurret != nullptr)
	{
		EnemyTurret.ThirdPersonEffects();
	}
	*/
}
void AFixedWeaponAttachment::UpdateTurretRotation(FRotator NewRotation)
{
	/*
		bInterpolateRotation=false;
		if (NewRotation.Pitch != TurretRotation.Pitch || NewRotation.Yaw != TurretRotation.Yaw)
		{
			SetTurretRotation(NewRotation);
			EnemyTurret.SetTurretRotation(NewRotation);
			ServerSetTurretValues(TurretRotation.Pitch,TurretRotation.Yaw);
			TurretPitch=TurretRotation.Pitch;
			TurretYaw=TurretRotation.Yaw;
			InterpolatedPitch=TurretRotation.Pitch;
			InterpolatedYaw=TurretRotation.Yaw;
		}
	*/
}

void AFixedWeaponAttachment::ServerSetTurretValues(int32 new_pitch, int32 new_yaw)
{
	FRotator newRot = FRotator(0,0,0);
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		newRot.Pitch=new_pitch;
		newRot.Yaw=new_yaw;
		//newRot.Roll=Rotation.Roll;
		SetTurretRotation(newRot);
		TurretPitch=new_pitch;
		TurretYaw=new_yaw;
	}
}

FRotator AFixedWeaponAttachment::GetTurretRotation()
{
	return TurretRotation;
}
void AFixedWeaponAttachment::SetTurretRotation(FRotator NewRotation)
{
	FRotator PitchRot = FRotator(0,0,0);
	FRotator YawRot = FRotator(0, 0, 0);
	/*
	TurretRotation=NewRotation;
	PitchRot=FRotator(0,0,TurretRotation.Pitch);
	YawRot=FRotator(- TurretRotation.Yaw,0,0);
	SetBoneRotation('Pitch',PitchRot);
	SetBoneRotation('Yaw',YawRot);
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		AmbientSound=sRotateLoop;
		SetTimer(0.05,false);
	}
	*/
}
void AFixedWeaponAttachment::moveTurret()
{
	/*
	if (Instigator == nullptr || Instigator != Level.GetClientPawn())
	{
		bInterpolateRotation=true;
	}
	*/
}
void AFixedWeaponAttachment::Timer()
{
	/*
	AmbientSound=nullptr;
	if (bTimerDoVerify)
	{
		ClientsVerifyMesh();
		bTimerDoVerify=false;
	}
	*/
}

AActor* AFixedWeaponAttachment::GetSource()
{
	return this;
}

float AFixedWeaponAttachment::GetAngleDelta(int32 curr, int Old, float DeltaTime)
{
	float timescalar = 0;
	float bdelta = 0;
	/*
	bdelta=curr - Old;
	if (bdelta > 32768)
	{
		bdelta -= 65536;
	}
	if (bdelta < -32768)
	{
		bdelta += 65536;
	}
	timescalar=16;
	return bdelta * DeltaTime * timescalar;
	*/
	return 0;    //FAKE   /EliZ
}

float AFixedWeaponAttachment::InterpolateAngle(float Interp, int32 Target, float Delta, int32 Mid)
{
	/*
	Interp += Delta;
	if (Delta < 0)
	{
		if (Interp < Mid && Target > Mid)
		{
			if (Interp < 0)
			{
				Interp += 65536;
			}
		}
		else
		{
			Interp=FMax(Target,Interp);
		}
	}
	else
	{
		if (Interp > Mid && Target < Mid)
		{
			if (Interp > 65536)
			{
				Interp -= 65536;
			}
		}
		else
		{
			Interp=FMin(Target,Interp);
		}
	}
	return Interp;
	*/
	return 0;    //FAKE   /EliZ
}
void AFixedWeaponAttachment::InterpolateRotation(float DeltaTime)
{
	float Delta = 0;
	float NewPitch = 0;
	float NewYaw = 0;
	if (bInterpolateRotation)
	{
		if (InterpolatedPitch == TurretPitch && InterpolatedYaw == TurretYaw)
		{
			bInterpolateRotation=false;
		}
		else
		{
			Delta=0;
			Delta=GetAngleDelta(TurretPitch,InterpolatedPitch,DeltaTime);
			NewPitch=InterpolateAngle(InterpolatedPitch,TurretPitch,Delta,32768);
			Delta=GetAngleDelta(TurretYaw,InterpolatedYaw,DeltaTime);
			NewYaw=InterpolateAngle(InterpolatedYaw,TurretYaw,Delta,0);
			SetPitchYaw(NewPitch,NewYaw);
		}
	}
}
void AFixedWeaponAttachment::SetPitchYaw(float NewPitch, float NewYaw)
{
	FRotator newRot = FRotator(0,0,0);
	InterpolatedPitch=NewPitch;
	InterpolatedYaw=NewYaw;
	newRot.Pitch=NewPitch;
	newRot.Yaw=NewYaw;
	//newRot.Roll=Rotation.Roll;
	SetTurretRotation(newRot);
	if (EnemyTurret != nullptr)
	{
		EnemyTurret->SetTurretRotation(newRot);
	}
}

void AFixedWeaponAttachment::ClientsVerifyMesh(float fAgain)
{
	if (bUseEnemyMesh)
	{
		FWMeshCount ++;
		if (fAgain > 0)
		{
			bTimerDoVerify=true;
			//SetTimer(fAgain,false);
		}
	}
}

void AFixedWeaponAttachment::Tick(float DeltaTime)
{
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		Disable('Tick');
	}
	else
	{
		if (bMeshVerified)
		{
			InterpolateRotation(DeltaTime);
		}
		else
		{
			if (Level.GetClient().Team != nullptr)
			{
				VerifyMesh();
			}
		}
	}
	*/
}
void AFixedWeaponAttachment::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Enable('Tick');
	}
	VerifyMesh();
	*/
}

void AFixedWeaponAttachment::VerifyMesh()
{
	AAA2_PlayerState* Client = nullptr;
	uint8 ClientTeam = 0;
	/*
	if (! bUseEnemyMesh || GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	bMeshVerified=false;
	Client=Level.GetClient();
	if (Client.Team == nullptr)
	{
		Enable('Tick');
		return;
	}
	else
	{
		ClientTeam=Client.Team.TeamIndex;
	}
	bHidden=ClientTeam != FriendlyTeam;
	if (EnemyTurret != nullptr)
	{
		EnemyTurret.bHidden=! bHidden;
	}
	bMeshVerified=true;
	*/
}

void AFixedWeaponAttachment::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bKillPawnWhenTriggered && Instigator != nullptr)
	{
		Instigator.TakeDamage(100,EventInstigator,Instigator->GetActorLocation(),FVector(0,0,0),KillPawnDamageType,,EventInstigator.Controller,Other);
	}
	if (bDisableWhenTriggered)
	{
		bDisabled=true;
	}
	*/
}

float AFixedWeaponAttachment::GetRotationMultiplier()
{
	return fRotationMultiplier;
}

bool AFixedWeaponAttachment::CanManTurret(AAGP_Pawn* p, FString& Reason)
{
	/*
	if (UseTeam != 255 && UseTeam != p.PlayerReplicationInfo.Team.TeamIndex)
	{
		Reason="";
		return false;
	}
	else
	{
		if (bDisabled)
		{
			Reason="Vehicle is disabled";
			return false;
		}
		else
		{
			if (Instigator != nullptr)
			{
				Reason="This vehicle is already in use";
				return false;
			}
			else
			{
				if (p.getHandsInventory() != nullptr && p.getShoulderInventory() != nullptr)
				{
					Reason="Cannot use vehicle while carrying two items";
					return false;
				}
				else
				{
					Reason="";
					return true;
				}
			}
		}
	}
	*/
	return false;   //FAKE   /ELiZ
}
