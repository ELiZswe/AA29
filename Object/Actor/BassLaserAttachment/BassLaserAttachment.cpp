// All the original content belonged to the US Army

#include "AA29/Object/Actor/BassLaserAttachment/BassLaserAttachment.h"

// Sets default values
ABassLaserAttachment::ABassLaserAttachment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 2
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Objects/monoclaser.monoclaser'"), NULL, LOAD_None, NULL);

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	VisibleSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	VisibleSkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	if (Mesh)
	{
		VisibleSkeletalMesh->SetSkeletalMesh(Mesh);
		VisibleSkeletalMesh->SetWorldRotation(FRotator(0, 0, 180));
		VisibleSkeletalMesh->SetWorldScale3D(FVector(0.5, 0.5, 0.5));
	}
}

void ABassLaserAttachment::BeginPlay()
{
	Super::BeginPlay();
}

void ABassLaserAttachment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ABassLaserAttachment::GetTipLocation()
{
	//return Location;
	return GetActorLocation();
}
