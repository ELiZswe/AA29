// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/KVehicle/KVehicle.h"

// Sets default values
AKVehicle::AKVehicle()
{
	CameraHistory.SetNum(5);
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bHistoryWarmup = true;
	//bSpecialCalcView = true;
	bAlwaysRelevant = true;
	//bNetInitialRotation = true;
	//Physics = 13;
	//bCollideWorld = false;
	//bBlockKarma = true;
	//bEdShouldSnap = true;
}


void AKVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}


void AKVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//native final Function GraphData(string DataName, float DataValue);
void AKVehicle::GraphData(FString DataName, float DataValue)
{

}

/*
void AKVehicle::TakeDamage(int32 Damage, APawn instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
}
*/

void AKVehicle::VehicleStateReceived()
{
}

void AKVehicle::KVehicleUpdateParams()
{
}

bool AKVehicle::TryToDrive(APawn* p)
{
	/*
	if (!bIsLocal || p.bIsCrouched || p.Controller == nullptr || Driver != nullptr || !p.Controller.bIsPlayer)
	{
		return false;
	}
	if (!p.IsHumanControlled() || !p.Controller.IsInState('PlayerDriving'))
	{
		KDriverEnter(p);
		return true;
	}
	*/
	return false;
}

void AKVehicle::ClientKDriverEnter(APlayerController* PC)
{
	/*
	PC.myHUD.bCrosshairShow = false;
	PC.myHUD.bShowWeaponInfo = false;
	PC.myHUD.bShowPoints = false;
	PC.bBehindView = true;
	PC.bFreeCamera = true;
	PC.SetRotation(FVector(-1 0 0) >> Rotation);
	*/
}

void AKVehicle::KDriverEnter(APawn* p)
{
	/*
	APlayerController* PC = nullptr;
	AController* C = nullptr;
	Driver = p;
	Driver.SetCollision(false, false);
	Driver.bCollideWorld = false;
	Driver.bPhysicsAnimUpdate = false;
	Driver.Velocity = FVector(0,0,0);
	Driver.SetPhysics(0);
	Driver.SetBase(this);
	C = p.Controller;
	p.Controller.UnPossess();
	Driver.SetOwner(C);
	C.Possess(this);
	PC = Cast<APlayerController>(C);
	if (PC != nullptr)
	{
		PC.ClientSetViewTarget(this);
		PC.GotoState('PlayerDriving');
		ClientKDriverEnter(PC);
	}
	*/
}
void AKVehicle::ClientKDriverLeave(APlayerController* PC)
{
	/*
	PC.bBehindView = false;
	PC.bFreeCamera = false;
	PC.myHUD.bCrosshairShow = PC.myHUD.Default.bCrosshairShow;
	PC.myHUD.bShowWeaponInfo = PC.myHUD.Default.bShowWeaponInfo;
	PC.myHUD.bShowPoints = PC.myHUD.Default.bShowPoints;
	NextHistorySlot = 0;
	bHistoryWarmup = true;
	*/
}

bool AKVehicle::KDriverLeave(bool bForceLeave)
{
	APlayerController* PC = nullptr;
	int32 i = 0;
	bool havePlaced = false;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector tryPlace = FVector(0, 0, 0);
	if (Driver == nullptr)
	{
		return false;
	}
	if (!bRemoteControlled)
	{
		//Driver->bCollideWorld = true;
		//Driver->SetCollision(true, true);
		havePlaced = false;
		i = 0;
		/*
		if (i < ExitPositions.Num() && havePlaced == false)
		{
			tryPlace = Location + ExitPositions[i] >> Rotation;
			if (Trace(HitLocation, HitNormal, tryPlace, Location, False) != nullptr)
			{
			}
			if (!Driver.SetLocation(tryPlace))
			{
			}
			havePlaced = true;
			i++;
		}
		if (!havePlaced && !bForceLeave)
		{
			Log("Could not place driver.");
			Driver.bCollideWorld = false;
			Driver.SetCollision(false, false);
			return false;
		}
		*/
	}
	PC = Cast<APlayerController>(Controller);
	ClientKDriverLeave(PC);
	PC->UnPossess();
	PC->Possess(Driver);
	PC->ClientSetViewTarget(Driver);
	Controller = nullptr;
	/*
	Driver->PlayWaiting();
	Driver->bPhysicsAnimUpdate = Driver->Default->bPhysicsAnimUpdate;
	if (!bRemoteControlled)
	{
		Driver->Acceleration = FVector(0,0,24000);
		Driver->SetPhysics(2);
		Driver->SetBase(nullptr);
	}
	*/
	Driver = nullptr;
	Throttle = 0;
	Steering = 0;
	bVehicleIsFiring = false;
	bVehicleIsAltFiring = false;
	return true;
}

bool AKVehicle::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	FVector CamLookAt = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0,0,0);
	APlayerController* PC = nullptr;
	int32 i = 0;
	int32 averageOver = 0;
	/*
	PC = Cast<APlayerController>(Controller);
	if (PC == nullptr || PC.ViewTarget != Self)
	{
		return false;
	}
	ViewActor = this;
	CamLookAt = Location + FVector(-100 0 100) >> Rotation;
	CameraHistory[NextHistorySlot] = CamLookAt;
	NextHistorySlot++;
	if (bHistoryWarmup)
	{
		averageOver = NextHistorySlot;
	}
	else
	{
		averageOver = 5;
	}
	CamLookAt = FVector(0,0,0);
	for (i = 0; i < averageOver; i++)
	{
		CamLookAt += CameraHistory[i];
	}
	CamLookAt /= averageOver;
	if (NextHistorySlot == 5)
	{
		NextHistorySlot = 0;
		bHistoryWarmup = false;
	}
	CameraLocation = CamLookAt + FVector(-600 0 0) >> CameraRotation;
	if (Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, false, FVector(10 10 10)) != nullptr)
	{
		CameraLocation = HitLocation;
	}
	*/
	return true;
}

void AKVehicle::Destroyed()
{
	if (Driver != nullptr)
	{
		Driver->Destroy();
	}
	if (DestroyEffectClass != nullptr)
	{
		//Spawn(DestroyEffectClass, , , Location, Rotation);
	}
	Super::Destroyed();
}

