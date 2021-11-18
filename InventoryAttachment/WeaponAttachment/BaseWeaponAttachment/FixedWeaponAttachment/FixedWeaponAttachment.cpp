// All the original content belonged to the US Army


#include "FixedWeaponAttachment.h"


AFixedWeaponAttachment::AFixedWeaponAttachment()
{
	//KillPawnDamageType   = class'AGP.VehicleDamage'
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
		bDisabled=False;
	*/
}
void AFixedWeaponAttachment::LinkTurrets()
{
	/*
		AssociatedActor=GetActorByTag(EnemyTurretTag);
		EnemyTurret=FixedWeaponAttachment(AssociatedActor);
		if (bUseEnemyMesh && EnemyTurret == None)
		{
			bUseEnemyMesh=False;
			DebugLog(DEBUG_Warn,"FixedWeaponAttachment::LinkTurrets()	Turret (" @ Self @ ") Could not find Turret associated with EnemyTurretTag(" @ EnemyTurretTag @ ")");
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
		if (FWeapon == None)
		{
			FWeapon=FixedWeapon(AGP_Pawn(p).CreateInventory(FixedWeaponClass,True));
		}
		else
		{
			FWeapon.GiveTo(p);
			FWeapon.PickupFunction(p);
		}
		SetOwner(p);
		TurretController=p;
		Instigator=p;
		FWeapon.SetTurret(Self);
	*/
}
void AFixedWeaponAttachment::AbandonWeapon()
{
	/*
		local Weapon ReplaceWeapon;
		SetOwner(None);
		Instigator=None;
		ReplaceWeapon=Spawn(FixedWeaponClass);
		ReplaceWeapon.InitFor(FWeapon);
		ReplaceWeapon.Instigator=None;
		FWeapon=FixedWeapon(ReplaceWeapon);
	*/
}
void AFixedWeaponAttachment::BeginPlay()
{
	/*
		BeginPlay();
		EnableChannelNotify(0,1);
	*/
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
	/*
		local int Num;
		local float Rate;
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
		if (EnemyTurret != None)
		{
			EnemyTurret.ThirdPersonEffects();
		}
	*/
}
void AFixedWeaponAttachment::UpdateTurretRotation(FRotator NewRotation)
{
	/*
		bInterpolateRotation=False;
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
	/*
		local FRotator newRot;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			newRot.Pitch=new_pitch;
			newRot.Yaw=new_yaw;
			newRot.Roll=Rotation.Roll;
			SetTurretRotation(newRot);
			TurretPitch=new_pitch;
			TurretYaw=new_yaw;
		}
	*/
}
FRotator AFixedWeaponAttachment::GetTurretRotation()
{
	
	return TurretRotation;
	
}
void AFixedWeaponAttachment::SetTurretRotation(FRotator NewRotation)
{
	/*
		local FRotator PitchRot;
		local FRotator YawRot;
		TurretRotation=NewRotation;
		PitchRot=MakeRot(0,0,TurretRotation.Pitch);
		YawRot=MakeRot(- TurretRotation.Yaw,0,0);
		SetBoneRotation('Pitch',PitchRot);
		SetBoneRotation('Yaw',YawRot);
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			AmbientSound=sRotateLoop;
			SetTimer(0.05,False);
		}
	*/
}
void AFixedWeaponAttachment::moveTurret()
{
	/*
		if (Instigator == None || Instigator != Level.GetClientPawn())
		{
			bInterpolateRotation=True;
		}
	*/
}
void AFixedWeaponAttachment::Timer()
{
	/*
		AmbientSound=None;
		if (bTimerDoVerify)
		{
			ClientsVerifyMesh();
			bTimerDoVerify=False;
		}
	*/
}
void AFixedWeaponAttachment::GetSource()
{
	/*
		Return Self;
	*/
}
void AFixedWeaponAttachment::GetAngleDelta(int curr, int Old, float DeltaTime)
{
	/*
		local float timescalar;
		local float bdelta;
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
		Return bdelta * DeltaTime * timescalar;
	*/
}
void AFixedWeaponAttachment::InterpolateAngle(float Interp, int32 Target, float Delta, int32 Mid)
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
		Return Interp;
	*/
}
void AFixedWeaponAttachment::InterpolateRotation(float DeltaTime)
{
	/*
		local float Delta;
		local float NewPitch;
		local float NewYaw;
		if (bInterpolateRotation)
		{
			if (InterpolatedPitch == TurretPitch && InterpolatedYaw == TurretYaw)
			{
				bInterpolateRotation=False;
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
	*/
}
void AFixedWeaponAttachment::SetPitchYaw(float NewPitch, float NewYaw)
{
	/*
		local FRotator newRot;
		InterpolatedPitch=NewPitch;
		InterpolatedYaw=NewYaw;
		newRot.Pitch=NewPitch;
		newRot.Yaw=NewYaw;
		newRot.Roll=Rotation.Roll;
		SetTurretRotation(newRot);
		if (EnemyTurret != None)
		{
			EnemyTurret.SetTurretRotation(newRot);
		}
	*/
}
void AFixedWeaponAttachment::ClientsVerifyMesh(float fAgain)
{
	/*
		if (bUseEnemyMesh)
		{
			FWMeshCount ++;
			if (fAgain > 0)
			{
				bTimerDoVerify=True;
				SetTimer(fAgain,False);
			}
		}
	*/
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
				if (Level.GetClient().Team != None)
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
		PostNetBeginPlay();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			Enable('Tick');
		}
		VerifyMesh();
	*/
}
void AFixedWeaponAttachment::VerifyMesh()
{
	/*
		local PlayerReplicationInfo Client;
		local byte ClientTeam;
		if (! bUseEnemyMesh || GetNetMode() != ENetMode::NM_Client)
		{
			Return;
		}
		bMeshVerified=False;
		Client=Level.GetClient();
		if (Client.Team == None)
		{
			Enable('Tick');
			Return;
		}
		else
		{
			ClientTeam=Client.Team.TeamIndex;
		}
		bHidden=ClientTeam != FriendlyTeam;
		if (EnemyTurret != None)
		{
			EnemyTurret.bHidden=! bHidden;
		}
		bMeshVerified=True;
	*/
}
void AFixedWeaponAttachment::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
		if (bKillPawnWhenTriggered && Instigator != None)
		{
			Instigator.TakeDamage(100,EventInstigator,Instigator.Location,vect(0 0 0),KillPawnDamageType,,EventInstigator.Controller,Other);
		}
		if (bDisableWhenTriggered)
		{
			bDisabled=True;
		}
	*/
}
float AFixedWeaponAttachment::GetRotationMultiplier()
{
	return fRotationMultiplier;
}
void AFixedWeaponAttachment::CanManTurret(AAGP_Pawn* p, FString Reason)
{
	/*
		if (UseTeam != 255 && UseTeam != p.PlayerReplicationInfo.Team.TeamIndex)
		{
			Reason="";
			Return False;
		}
		else
		{
			if (bDisabled)
			{
				Reason="Vehicle is disabled";
				Return False;
			}
			else
			{
				if (Instigator != None)
				{
					Reason="This vehicle is already in use";
					Return False;
				}
				else
				{
					if (p.getHandsInventory() != None && p.getShoulderInventory() != None)
					{
						Reason="Cannot use vehicle while carrying two items";
						Return False;
					}
					else
					{
						Reason="";
						Return True;
					}
				}
			}
		}
	*/
}
