// All the original content belonged to the US Army

#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FSTS_FA_MedicalPickups.h"

// Sets default values
AFSTS_FA_MedicalPickups::AFSTS_FA_MedicalPickups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//bOrientOnSlope = true;
	//ActionIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_HUD_USE_ICON_S_Mat.T_UI_HUD_USE_ICON_S_Mat'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 10;
	//CollisionHeight = 5;
	//bCollideActors = true;
	//bCollideWorld = true;
	//bProjTarget = true;
	//bUseCylinderCollision = true;
}


void AFSTS_FA_MedicalPickups::BeginPlay()
{
	Super::BeginPlay();
}


void AFSTS_FA_MedicalPickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFSTS_FA_MedicalPickups::DisablePickup()
{
	/*
	bUseActionIcon = false;
	bHidden = true;
	bProjTarget = false;
	bBlockZeroExtentTraces = false;
	bBlockBulletTraces = false;
	bUseCylinderCollision = true;
	*/
}

void AFSTS_FA_MedicalPickups::ActivatePickup()
{
	/*
	bHidden = false;
	bProjTarget = true;
	bBlockZeroExtentTraces = true;
	bBlockBulletTraces = true;
	bUseCylinderCollision = true;
	*/
}

void AFSTS_FA_MedicalPickups::Reset()
{
	ActivatePickup();
}
