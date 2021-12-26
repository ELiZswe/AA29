// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/KVehicle/KVehicle.h"

// Sets default values
AKVehicle::AKVehicle()
{
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

// Called when the game starts or when spawned
void AKVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
	if (!bIsLocal || p.bIsCrouched || p.Controller == nullptr || Driver != None || !p.Controller.bIsPlayer)
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
	PC.myHUD.bCrosshairShow = False;
	PC.myHUD.bShowWeaponInfo = False;
	PC.myHUD.bShowPoints = False;
	PC.bBehindView = true;
	PC.bFreeCamera = true;
	PC.SetRotation(vect(-1 0 0) >> Rotation);
	*/
}

void AKVehicle::KDriverEnter(APawn* p)
{
	/*
	local PlayerController PC;
	local Controller C;
	Driver = p;
	Driver.SetCollision(False, False);
	Driver.bCollideWorld = False;
	Driver.bPhysicsAnimUpdate = False;
	Driver.Velocity = vect(0 0 0);
	Driver.SetPhysics(0);
	Driver.SetBase(Self);
	C = p.Controller;
	p.Controller.UnPossess();
	Driver.SetOwner(C);
	C.Possess(Self);
	PC = PlayerController(C);
	if (PC != None)
	{
		PC.ClientSetViewTarget(Self);
		PC.GotoState('PlayerDriving');
		ClientKDriverEnter(PC);
	}
	*/
}
void AKVehicle::ClientKDriverLeave(APlayerController* PC)
{
	/*
	PC.bBehindView = False;
	PC.bFreeCamera = False;
	PC.myHUD.bCrosshairShow = PC.myHUD.Default.bCrosshairShow;
	PC.myHUD.bShowWeaponInfo = PC.myHUD.Default.bShowWeaponInfo;
	PC.myHUD.bShowPoints = PC.myHUD.Default.bShowPoints;
	NextHistorySlot = 0;
	bHistoryWarmup = true;
	*/
}

bool AKVehicle::KDriverLeave(bool bForceLeave)
{
	/*
	local PlayerController PC;
	local int i;
	local bool havePlaced;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local Object.Vector tryPlace;
	if (Driver == nullptr)
	{
		return false;
	}
	if (!bRemoteControlled)
	{
		Driver.bCollideWorld = true;
		Driver.SetCollision(True, True);
		havePlaced = False;
		i = 0;
		if (i < ExitPositions.Length && havePlaced == False)
		{
			tryPlace = Location + ExitPositions[i] >> Rotation;
			if (Trace(HitLocation, HitNormal, tryPlace, Location, False) != None)
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
			Driver.bCollideWorld = False;
			Driver.SetCollision(False, False);
			return false;
		}
	}
	PC = PlayerController(Controller);
	ClientKDriverLeave(PC);
	PC.UnPossess();
	PC.Possess(Driver);
	PC.ClientSetViewTarget(Driver);
	Controller = nullptr;
	Driver.PlayWaiting();
	Driver.bPhysicsAnimUpdate = Driver.Default.bPhysicsAnimUpdate;
	if (!bRemoteControlled)
	{
		Driver.Acceleration = vect(0 0 24000);
		Driver.SetPhysics(2);
		Driver.SetBase(None);
	}
	Driver = nullptr;
	Throttle = 0;
	Steering = 0;
	bVehicleIsFiring = False;
	bVehicleIsAltFiring = False;
	*/
	return true;
}

bool AKVehicle::SpecialCalcView(AActor* &ViewActor, FVector &CameraLocation, FRotator &CameraRotation)
{
	/*
	local Object.Vector CamLookAt;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local PlayerController PC;
	local int i;
	local int averageOver;
	PC = PlayerController(Controller);
	if (PC == nullptr || PC.ViewTarget != Self)
	{
		return false;
	}
	ViewActor = Self;
	CamLookAt = Location + vect(-100 0 100) >> Rotation;
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
	CamLookAt = vect(0 0 0);
	for (i = 0; i < averageOver; i++)
	{
		CamLookAt += CameraHistory[i];
	}
	CamLookAt /= averageOver;
	if (NextHistorySlot == 5)
	{
		NextHistorySlot = 0;
		bHistoryWarmup = False;
	}
	CameraLocation = CamLookAt + vect(-600 0 0) >> CameraRotation;
	if (Trace(HitLocation, HitNormal, CameraLocation, CamLookAt, False, vect(10 10 10)) != None)
	{
		CameraLocation = HitLocation;
	}
	*/
	return true;
}

void AKVehicle::Destroyed()
{
	/*
	if (Driver != None)
	{
		Driver.Destroy();
	}
	if (DestroyEffectClass != None)
	{
		Spawn(DestroyEffectClass, , , Location, Rotation);
	}
	*/
	Super::Destroyed();
}

