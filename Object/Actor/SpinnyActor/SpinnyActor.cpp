// All the original content belonged to the US Army


#include "AA29/Object/Actor/SpinnyActor/SpinnyActor.h"

// Sets default values
ASpinnyActor::ASpinnyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spinRate = 20000;
	//DrawType = DT_StaticMesh;
	//RemoteRole = ROLE_None;
	//LODBias = 100000;
	//DrawScale = 0.5;
	//bUnlit = true;
	//bAlwaysTick = true;

}

// Called when the game starts or when spawned
void ASpinnyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinnyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newRot = FRotator(0, 0, 0);
	newRot = GetActorRotation();
	(newRot.Yaw += int((DeltaTime * float(spinRate))));
	SetActorRotation(newRot);
	(CurrentTime += DeltaTime);
}



