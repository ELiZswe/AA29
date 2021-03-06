// All the original content belonged to the US Army

#include "AA29/Object/Actor/Decoration/Decoration.h"
#include "AA29/Object/Actor/Effects/Fragment/Fragment.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/DamageType/Crushed/Crushed.h"

// Sets default values
ADecoration::ADecoration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_Mesh;
	//bStatic = true;
	//bStasis = true;
	//bOrientOnSlope = true;
	//NetUpdateFrequency = 10;
	//bCanBeDamaged = true;
	//bShouldBaseAtStartup = true;
}


void ADecoration::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADecoration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoration::NotReachableBy(APawn* p)
{
}

bool ADecoration::CanSplash()
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

void ADecoration::Drop(FVector NewVel)
{
}

void ADecoration::Landed(FVector HitNormal)
{
	FRotator newRot = FRotator(0, 0, 0);
	/*
	if (Velocity.Z < float(-500))
	{
		TakeDamage(100, Pawn(GetOwner()), HitNormal, (HitNormal * float(10000)), ACrushed::StaticClass());
	}
	Velocity = FVector(0, 0, 0);
	newRot = Rotation;
	newRot.Pitch = 0;
	newRot.Roll = 0;
	SetActorRotation(newRot);
	*/
}

void ADecoration::HitWall(FVector HitNormal, AActor* Wall)
{
	Landed(HitNormal);
}

/*
void ADecoration::TakeDamage(int32 NDamage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	Instigator = instigatedBy;
	if ((!bDamageable) || (Health < 0))
	{
		return;
	}
	if (Instigator != nullptr)
	{
		MakeNoise(1);
	}
	(Health -= NDamage);
	FragMomentum = Momentum;
	if (Health < 0)
	{
		Destroy();
	}
	else
	{
		SetPhysics(PHYS_Falling);
		Momentum.Z = 1000;
		Velocity = (Momentum / Mass);
	}
}
*/

void ADecoration::PhysicsVolumeChange(APhysicsVolume* NewVolume)
{
	/*
	if (NewVolume.bWaterVolume)
	{
		if (((((bSplash && (!PhysicsVolume.bWaterVolume)) && (Mass <= Buoyancy)) && ((FMath::Abs(Velocity.Z) < float(100)) || (Mass == 0))) && (FMath::FRand() < 0.05)) && (!PlayerCanSeeMe()))
		{
			bSplash = false;
			SetPhysics(PHYS_None);
		}
	}
	if (PhysicsVolume.bWaterVolume && (Buoyancy > Mass))
	{
		if (Buoyancy > (1.1 * Mass))
		{
			Buoyancy = (0.95 * Buoyancy);
		}
		else
		{
			if (Buoyancy > (1.03 * Mass))
			{
				Buoyancy = (0.99 * Buoyancy);
			}
		}
	}
	*/
}

void ADecoration::Trigger(AActor* Other, APawn* EventInstigator)
{
	//Instigator = EventInstigator;
	//TakeDamage(1000, Instigator, Location, (FVector(0, 0, 1) * float(900)), ACrushed::StaticClass());
}

void ADecoration::BaseChange()
{
	/*
	if (Velocity.Z < float(-500))
	{
		TakeDamage(int((1 - (Velocity.Z / float(30)))), Instigator, Location, FVector(0, 0, 0), ACrushed::StaticClass());
	}
	if (Base == nullptr)
	{
		if (((!bInterpolating) && bPushable) && (Physics == 0))
		{
			SetPhysics(PHYS_Falling);
		}
	}
	else
	{
		if (Cast<APawn>(Base) != nullptr)
		{
			Base.TakeDamage(int(((float(int((1 - (Velocity.Z / float(400))))) * Mass) / Base.Mass)), Instigator, Location, (0.5 * Velocity), ACrushed::StaticClass());
			Velocity.Z = 100;
			if (FMath::FRand() < 0.5)
			{
				(Velocity.X += float(70));
			}
			else
			{
				(Velocity.Y += float(70));
			}
			SetPhysics(PHYS_Falling);
		}
		else
		{
			if ((Cast<ADecoration>(Base) != nullptr) && (Velocity.Z < float(-500)))
			{
				Base.TakeDamage(int((1 - (((Mass / Base.Mass) * Velocity.Z) / float(30)))), Instigator, Location, (0.2 * Velocity), ACrushed::StaticClass());
				Velocity.Z = 100;
				if (FMath::FRand() < 0.5)
				{
					(Velocity.X += float(70));
				}
				else
				{
					(Velocity.Y += float(70));
				}
				SetPhysics(PHYS_Falling);
			}
			else
			{
				Instigator = nullptr;
			}
		}
	}
	*/
}

void ADecoration::Destroyed()
{
	AInventory* dropped = nullptr;
	int32 i = 0;
	AFragment* S = nullptr;
	float BaseSize = 0;
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		if ((Contents != nullptr) && (!Level.bStartup))
		{
			dropped = Spawn(Contents);
			dropped.DropFrom(Location);
		}
		TriggerEvent(Event, this, None);
		if (bPushSoundPlaying)
		{
			PlaySound(EndPushSound, 1);
		}
	}
	if ((((GetNetMode() != ENetMode::NM_DedicatedServer) && (!PhysicsVolume.bDestructive)) && (NumFrags > 0)) && (FragType != nullptr))
	{
		BaseSize = ((0.8 * Sqrt((CollisionRadius * CollisionHeight))) / float(NumFrags));
		for (i = 0; i < NumFrags; i++)
		{
			S = Spawn(FragType, Owner, , (Location + (CollisionRadius * VRand())));
			S.CalcVelocity(FragMomentum);
			if (FragSkin != nullptr)
			{
				S.Skins[0] = FragSkin;
			}
			S.SetDrawScale((BaseSize * (0.5 + (0.7 * FMath::FRand()))));
		}
	}
	Super::Destroyed();
	*/
}

void ADecoration::Timer()
{
	//PlaySound(EndPushSound, 1);
	//bPushSoundPlaying = false;
}

void ADecoration::Bump(AActor* Other)
{
	float Speed = 0;
	float OldZ = 0;
	/*
	if ((bPushable && (Cast<APawn>(Other) != nullptr)) && (Other.Mass > float(40)))
	{
		OldZ = Velocity.Z;
		Speed = VSize(Other.Velocity);
		Velocity = ((Other.Velocity * FMin(120, (20 + Speed))) / Speed);
		if (Physics == 0)
		{
			Velocity.Z = 25;
			if (!bPushSoundPlaying)
			{
				PlaySound(PushSound, 1);
				bPushSoundPlaying = true;
			}
		}
		else
		{
			Velocity.Z = OldZ;
		}
		SetPhysics(PHYS_Falling);
		SetTimer(0.3, false);
		Instigator = Cast<APawn>(Other);
	}
	*/
}
