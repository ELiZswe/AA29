// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"

// Sets default values
ASVehicle::ASVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VehicleMass = 1;
	FlipTorque = 300;
	FlipTime = 2;
	//bSpecialCalcView = true;
	//bNetInitialRotation = true;
	//Physics = 13;
	//bCollideWorld = false;
	//bBlockKarma = true;
	//bEdShouldSnap = true;
}


void ASVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	if (FlipTimeLeft > 0)
	{
		KWake();
		FlipTimeLeft -= DeltaTime;
		if (FlipTimeLeft <= 0 && !bDriving)
		{
			Disable('Tick');
		}
	}
	*/
}

// Called to bind functionality to input
void ASVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//native final Function GraphData(string DataName, float DataValue);
void ASVehicle::GraphData(FString DataName, float DataValue)
{
}

void ASVehicle::VehicleStateReceived()
{
}
//native Event UpdateVehicle(float DeltaTime);
void ASVehicle::UpdateVehicle(float DeltaTime)
{
}

void ASVehicle::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	//SVehicleUpdateParams();
}
void ASVehicle::JumpOffPawn()
{
}
void ASVehicle::SVehicleUpdateParams()
{
	//KSetMass(VehicleMass);
}
void ASVehicle::Flip(FVector HitNormal, float ForceScale)
{
	/*
	if (!bCanFlip)
	{
		return;
	}
	FlipTimeLeft = FlipTime;
	FlipScale = ForceScale;
	FlipAxis = HitNormal;
	FlipAxis.Z = 0;
	Enable('Tick');
	*/
}

void ASVehicle::KApplyForce(FVector& Force, FVector& Torque)
{
	float torqueScale = 0;
	FVector worldUp = FVector(0, 0, 0);
	FVector torqueAxis = FVector(0,0,0);
	/*
	KApplyForce(Force, Torque);
	if (FlipTimeLeft <= 0)
	{
		return;
	}
	worldUp = FVector(0 0 1) >> Rotation;
	torqueAxis = Normal(FlipAxis Cross worldUp);
	torqueScale = Acos(worldUp Dot FVector(0 0 1)) / 3.1416;
	Torque = FlipScale * FlipTorque * torqueScale * torqueAxis;
	*/
}

void ASVehicle::Destroyed()
{
	/*
	if (DestroyEffectClass != nullptr)
	{
		Spawn(DestroyEffectClass, , , Location, Rotation);
	}
	*/
	Super::Destroyed();
}
