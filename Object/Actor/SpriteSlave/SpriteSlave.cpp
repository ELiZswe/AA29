// All the original content belonged to the US Army

#include "AA29/Object/Actor/SpriteSlave/SpriteSlave.h"

// Sets default values
ASpriteSlave::ASpriteSlave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Texture = nullptr;
	//Style = STY_None;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}


void ASpriteSlave::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASpriteSlave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

