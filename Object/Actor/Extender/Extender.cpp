// All the original content belonged to the US Army

#include "AA29/Object/Actor/Extender/Extender.h"

// Sets default values
AExtender::AExtender()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/Extender/extender_a.extender_a'"), NULL, LOAD_None, NULL);
}


void AExtender::BeginPlay()
{
	Super::BeginPlay();
	
}


void AExtender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
