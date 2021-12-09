// All the original content belonged to the US Army


#include "AA29/Object/Actor/AnimBrowserMesh/AnimBrowserMesh.h"

// Sets default values
AAnimBrowserMesh::AAnimBrowserMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 2;
	//AmbientGlow = 255;
	//SoundOcclusion = 1;
}

// Called when the game starts or when spawned
void AAnimBrowserMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimBrowserMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

