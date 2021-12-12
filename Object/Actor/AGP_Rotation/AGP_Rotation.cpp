// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Rotation/AGP_Rotation.h"

// Sets default values
AAGP_Rotation::AAGP_Rotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//bDirectional = true;
}

// Called when the game starts or when spawned
void AAGP_Rotation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGP_Rotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

