// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"

// Sets default values
AAI_Primitive::AAI_Primitive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//bSkipActorPropertyReplication = true;
	//bOnlyDirtyReplication = true;
}


void AAI_Primitive::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAI_Primitive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

