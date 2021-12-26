// All the original content belonged to the US Army

#include "AA29/Object/Actor/BassLaserAttachment/BassLaserAttachment.h"

// Sets default values
ABassLaserAttachment::ABassLaserAttachment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 2
	//Mesh = SkeletalMesh'A_AA2_Objects.monoclaser'
}

// Called when the game starts or when spawned
void ABassLaserAttachment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABassLaserAttachment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ABassLaserAttachment::GetTipLocation()
{
	//return Location;
	return GetActorLocation();
}
