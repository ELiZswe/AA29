// All the original content belonged to the US Army

#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FSTS_FA_MedicalAttachment.h"

// Sets default values
AFSTS_FA_MedicalAttachment::AFSTS_FA_MedicalAttachment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//DrawScale = 1.13;
}


void AFSTS_FA_MedicalAttachment::BeginPlay()
{
	Super::BeginPlay();
}


void AFSTS_FA_MedicalAttachment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFSTS_FA_MedicalAttachment::SwitchToAltStaticMesh()
{
	//SetStaticMesh(AltStaticMesh);
}

void AFSTS_FA_MedicalAttachment::SwitchToAltStaticMesh2()
{
	//SetStaticMesh(AltStaticMesh2);
}
