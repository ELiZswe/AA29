// All the original content belonged to the US Army

#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"

// Sets default values
AAuxCollisionCylinder::AAuxCollisionCylinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//bSkipActorPropertyReplication = true;
	//bOnlyDirtyReplication = true;
	//DrawScale = 0.25;
	//CollisionRadius = 18;
	//CollisionHeight = 12;
	//bBlockBulletTraces = false;
}


void AAuxCollisionCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAuxCollisionCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAuxCollisionCylinder::UsedBy(APawn* User)
{
	//return Pawn(GetOwner())->UsedBy(User);
	return false;      //FAKE   /ELiZ
}
void AAuxCollisionCylinder::SetAuxCylinder(bool bEnable)
{
	//bCollideWorld = bEnable;
	//SetCollision(true, bEnable, bEnable);
	//bProjTarget = bEnable;
}
