// All the original content belonged to the US Army

#include "AA29/Object/Actor/Effects/Fragment/Fragment.h"

AFragment::AFragment()
{
	Fragments.SetNum(11);
	bFirstHit = true;
	//DrawType = DT_Mesh;
	//Physics = PHYS_Falling;
	//LifeSpan = 20;
	//bDestroyInPainVolume = true;
	//SoundVolume = 0;
	//CollisionRadius = 18;
	//CollisionHeight = 4;
	//bCollideWorld = true;
	//bBounce = true;
	//bFixedRotationDir = true;
}

/*
auto State Flying
{
	simulated Function Timer()
	{
		GotoState("Dying");
	}
	simulated Function PhysicsVolumeChange(APhysicsVolume* NewVolume)
	{
		if (NewVolume.bWaterVolume)
		{
			Velocity=(0.2 * Velocity);
			if (bFirstHit)
			{
				bFirstHit=false;
				bRotateToDesired=true;
				bFixedRotationDir=false;
				DesiredRotation.Pitch=0;
				DesiredRotation.Yaw=int((FMath::FRand() * float(65536)));
				DesiredRotation.Roll=0;
			}
			RotationRate=(0.2 * RotationRate);
			GotoState("Dying");
		}
	}
	simulated Function BeginState()
	{
		RandSpin(125000);
		if (FMath::Abs(float(RotationRate.Pitch)) < float(10000))
		{
			RotationRate.Pitch=10000;
		}
		if (FMath::Abs(float(RotationRate.Roll)) < float(10000))
		{
			RotationRate.Roll=10000;
		}
		LinkMesh(Fragments[int((FMath::FRand() * float(numFragmentTypes)))]);
		if (GetWorld()->GetNetMode() == NM_Standalone)
		{
			LifeSpan=(20 + (float(40) * FMath::FRand()));
		}
		SetTimer(5,true);
	}
}
*/

/*
State Dying
{
	Function TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	{
		Destroy();
	}
	simulated Function Timer()
	{
		if (! PlayerCanSeeMe())
		{
			Destroy();
		}
	}
	simulated Function BeginState()
	{
		SetTimer((1 + FMath::FRand()),true);
		SetCollision(true,false,false);
	}
}
*/

bool AFragment::CanSplash()
{
	/*
	if ((((GetWorld()->GetTimeSeconds() - SplashTime) > 0.25) && (Physics == 2)) && (FMath::Abs(Velocity.Z) > float(100)))
	{
		SplashTime = GetWorld()->GetTimeSeconds();
		return true;
	}
	*/
	return false;
}

void AFragment::CalcVelocity(FVector Momentum)
{
	float ExplosionSize = 0;
	/*
	ExplosionSize = (0.011 * VSize(Momentum));
	Velocity = ((0.0033 * Momentum) + ((0.7 * VRand()) * ((ExplosionSize + (FMath::FRand() * 100)) + 100)));
	(Velocity.Z += (0.5 * ExplosionSize));
	*/
}

void AFragment::HitWall(FVector HitNormal, AActor* HitWall)
{
	float Speed = 0;
	/*
	Velocity = (0.5 * ((((Velocity Dot HitNormal) * HitNormal) * -2) + Velocity));
	Speed = VSize(Velocity);
	if (bFirstHit && (Speed < float(400)))
	{
		bFirstHit = false;
		bRotateToDesired = true;
		bFixedRotationDir = false;
		DesiredRotation.Pitch = 0;
		DesiredRotation.Yaw = int((FMath::FRand() * float(65536)));
		DesiredRotation.Roll = 0;
	}
	RotationRate.Yaw = int((float(RotationRate.Yaw) * 0.75));
	RotationRate.Roll = int((float(RotationRate.Roll) * 0.75));
	RotationRate.Pitch = int((float(RotationRate.Pitch) * 0.75));
	if ((Speed < float(60)) && (HitNormal.Z > 0.7))
	{
		SetPhysics(PHYS_None);
		bBounce = false;
		GotoState('Dying');
	}
	else
	{
		if (Speed > float(80))
		{
			if (FMath::FRand() < 0.5)
			{
				PlaySound(ImpactSound, 0, , , 300, (0.85 + (FMath::FRand() * 0.3)), true);
			}
			else
			{
				PlaySound(AltImpactSound, 0, , , 300, (0.85 + (FMath::FRand() * 0.3)), true);
			}
		}
	}
	*/
}

void AFragment::RandSpin(float spinRate)
{
	/*
	DesiredRotation = RotRand();
	RotationRate.Yaw = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	RotationRate.Pitch = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	RotationRate.Roll = int((((spinRate * 2) * FMath::FRand()) - spinRate));
	*/
}

