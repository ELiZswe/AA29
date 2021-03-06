// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/RocketProjectile.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_AT4_Explosive/Proj_AT4_Explosive.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketFragDamage/RocketFragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/RocketImpact.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/RocketExplosionDamage/RocketExplosionDamage.h"
#include "AA29/Object/Actor/ProjAttach_RocketTrail/ProjAttach_RocketTrail.h"

ARocketProjectile::ARocketProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InitialSpeed          = 1800;
	AccelRate             = 1.25;
	AccelDuration         = 0.01;
	PropellantDuration    = 1.5;
	RandomScaleFactor     = 300;
	SpeedJacked           = 1500;
	RandomMinTime         = 0.2;
	RandomMaxTime         = 1;
	JackedDuration        = 0.01;
	ArmingTimeRange.Min   = 0.25f;
	ArmingTimeRange.Max   = 0.25f;
	ImpactDamage          = 100;
	ImpactDamageType      = URocketImpact::StaticClass();
	FragDamageType        = URocketFragDamage::StaticClass();
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Explosions/PlainExplosions/Explosion3_Cue.Explosion3_Cue'"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_AT4_Explosive::StaticClass();
	Speed                 = 5000;
	MaxSpeed              = 5000;
	Damage                = 150;
	DamageRadius          = 1312.335938;
	MyDamageType          = URocketExplosionDamage::StaticClass();
	LightType             = ELightType::LT_Steady;
	LightEffect           = ELightEffect::LE_NonIncidence;
	LightHue              = 22;
	LightSaturation       = 177;
	LightBrightness       = 150;
	LightRadius           = 22;
	bDynamicLight         = true;
	//bUpdateSimulatedPosition = true;
	//Physics = 6;
	AmbientGlow           = 255;
	//bRotateToDesired = true;
}

/*
auto State Flying
{
	simulated Function Tick(float DeltaTime)
	{
		FVector ForceDir = FVector(0,0,0);
		float VelMag = 0;
		FRotator NewRotation = FRotator(0,0,0);
		Super::Tick(DeltaTime);
		if (bOutOfPropellant)
		{
			StopTrail();
		}
		if (GetNetMode() != ENetMode::NM_Client)
		{
			if (! bOutOfPropellant)
			{
				if (PropellantTimer <= PropellantDuration)
				{
					(PropellantTimer += DeltaTime);
				}
				else
				{
					bOutOfPropellant=true;
					SetPhysics(PHYS_Falling);
				}
				if ((! bReachedMaxSpeed) && (! bJacked))
				{
					if (VSize(Velocity) < MaxSpeed)
					{
						if (AccelDuration > AccelCounter)
						{
							(AccelCounter += DeltaTime);
						}
						else
						{
							(Velocity *= AccelRate);
							AccelCounter=Default.AccelCounter;
						}
					}
					else
					{
						bReachedMaxSpeed=true;
					}
				}
				if (JackedDuration > JackedCounter)
				{
					(JackedCounter += DeltaTime);
				}
				else
				{
					if (bJacked && (ProjState != 2))
					{
						if (Max(RandRocketPitch,TempPitch) == TempPitch)
						{
							(TempPitch -= RandomScaleFactor);
						}
						else
						{
							(TempPitch += RandomScaleFactor);
						}
						if (Max(RandRocketYaw,TempYaw) == TempYaw)
						{
							(TempYaw -= RandomScaleFactor);
						}
						else
						{
							(TempYaw += RandomScaleFactor);
						}
						if (Max(RandRocketRoll,TempRoll) == TempRoll)
						{
							(TempRoll -= RandomScaleFactor);
						}
						else
						{
							(TempRoll += RandomScaleFactor);
						}
						NewRotation.Pitch=TempPitch;
						NewRotation.Yaw=TempYaw;
						NewRotation.Roll=TempRoll;
						Speed=float(SpeedJacked);
						if (InitialDir == FVector(0,0,0))
						{
							InitialDir=Normal(Velocity);
						}
						ForceDir=Normal( Vector(NewRotation));
						if ((ForceDir Dot InitialDir) > 0)
						{
							VelMag=VSize(Velocity);
							ForceDir=Normal((((ForceDir * 0.5) * VelMag) + Velocity));
							Velocity=(VelMag * ForceDir);
							Acceleration=(Speed * ForceDir);
						}
					}
					JackedCounter=Default.AccelCounter;
				}
			}
		}
		if ((! IsZero(Velocity)) && (RocketTrail != nullptr))
		{
			if (bJacked)
			{
				RocketTrail.SetRelativeLocation(FVector(0,0,-32));
			}
			RocketTrail.SetRotation((rotator(Velocity) + FRotator(0,0,0)));
		}
	}
	simulated Function BeginState()
	{
		Super::BeginState();
		if ((GetNetMode() != ENetMode::NM_Client) && bJacked)
		{
			RandRocketPitch=RandSigned(65000);
			RandRocketYaw=RandSigned(65000);
			RandRocketRoll=RandSigned(65000);
			TempPitch=Rotation.Pitch;
			TempYaw=Rotation.Yaw;
			TempRoll=Rotation.Roll;
			SetTimer(0.5,false);
		}
	}
}
*/

/*
replication
{
	reliable if ((bNetInitial && (Role == ROLE_Authority)))
		InitialDir;
	reliable if (((Role == ROLE_Authority) && bNetDirty))
		bReachedMaxSpeed, bOutOfPropellant, bJacked;
}
*/

void ARocketProjectile::BeginPlay()
{
	/*
	Super::BeginPlay();
	Speed = InitialSpeed;
	if (FMath::FRand() < JackedPct)
	{
		bJacked = true;
		SetPhysics(PHYS_Projectile);
	}
	if (!Level.IsServer())
	{
		RocketTrail = Spawn(AProjAttach_RocketTrail::StaticClass());
		RocketTrail.SetBase(this);
		RocketTrail.SetRelativeLocation(RocketTrailOffset);
	}
	*/
}

int32 ARocketProjectile::RandSigned(int32 i)
{
	/*
	if (FMath::FRand() >= 0.5)
	{
		return (Rand(i) * -1);
	}
	else
	{
		return Rand(i);
	}
	*/
	return 0;    //FAKE   /ELiZ
}

void ARocketProjectile::Timer()
{
	/*
	if (bJacked && (GetNetMode() != ENetMode::NM_Client))
	{
		RandRocketPitch = RandSigned(65000);
		RandRocketYaw = RandSigned(65000);
		RandRocketRoll = RandSigned(65000);
		SetTimer(FMax((FMath::FRand() * RandomMaxTime), RandomMinTime), false);
	}
	else
	{
		Super::Timer();
	}
	*/
}

bool ARocketProjectile::ShouldExplode()
{
	/*
	if (bJacked && (FMath::FRand() > 0.5))
	{
		return false;
	}
	else
	{
		return Super::ShouldExplode();
	}
	*/
	return false;    //FAKE   /ELiZ
}

void ARocketProjectile::StopTrail()
{
	//Super::StopTrail();
	if (RocketTrail != nullptr)
	{
		RocketTrail->Destroy();
		RocketTrail = nullptr;
	}
	LightEffect = ELightEffect::LE_None;
	LightRadius = 0;
	LightBrightness = 0;
}

void ARocketProjectile::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	/*
	if (IsInstigator(HitActor) && (ProjState != 2))
	{
		return;
	}
	bReachedMaxSpeed = true;
	SetPhysics(PHYS_Falling);
	Super::Collision(HitActor, HitLocation, HitNormal, HitMaterial, Type);
	if (bJacked)
	{
		bJacked = false;
	}
	*/
	StopTrail();
}

void ARocketProjectile::Destroyed()
{
	Super::Destroyed();
	if (RocketTrail != nullptr)
	{
		RocketTrail->Destroy();
	}
}
