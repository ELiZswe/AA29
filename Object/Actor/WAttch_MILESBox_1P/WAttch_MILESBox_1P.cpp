// All the original content belonged to the US Army


#include "AA29/Object/Actor/WAttch_MILESBox_1P/WAttch_MILESBox_1P.h"

// Sets default values
AWAttch_MILESBox_1P::AWAttch_MILESBox_1P()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_1p/m-miles_weapon_1p.m-miles_weapon_1p'"), NULL, LOAD_None, NULL);
	//bOnlyOwnerSee = true;

}

// Called when the game starts or when spawned
void AWAttch_MILESBox_1P::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWAttch_MILESBox_1P::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

