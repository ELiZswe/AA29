// All the original content belonged to the US Army

#include "AA29/Object/Actor/DecoVolumeObject/DecoVolumeObject.h"

// Sets default values
ADecoVolumeObject::ADecoVolumeObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
}

// Called when the game starts or when spawned
void ADecoVolumeObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecoVolumeObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

