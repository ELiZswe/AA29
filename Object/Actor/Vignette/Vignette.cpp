// All the original content belonged to the US Army


#include "AA29/Object/Actor/Vignette/Vignette.h"

// Sets default values
AVignette::AVignette()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_None;
	//bNetTemporary = true;
	//RemoteRole = ROLE_None;
	//bUnlit = true;
	//bGameRelevant = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
}

// Called when the game starts or when spawned
void AVignette::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVignette::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVignette::Init()
{
}

void AVignette::DrawVignette(UCanvas* C, float Progress)
{
}
