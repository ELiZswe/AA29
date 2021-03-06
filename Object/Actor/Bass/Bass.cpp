// All the original content belonged to the US Army

#include "AA29/Object/Actor/Bass/Bass.h"
#include "AA29/Object/Actor/BassLaserAttachment/BassLaserAttachment.h"
#include "AA29/Object/Actor/xEmitter/BassLaserBeam/BassLaserBeam.h"

// Sets default values
ABass::ABass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	//DrawType = 2
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Objects/seabass.seabass'"), NULL, LOAD_None, NULL);
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	VisibleSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	VisibleSkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	if (Mesh)
	{
		VisibleSkeletalMesh->SetSkeletalMesh(Mesh);
	}
}

void ABass::BeginPlay()
{
	Super::BeginPlay();
	
	PostBeginPlay();
}

void ABass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABass::PostBeginPlay()
{
	FString AnimPath = "AnimSequence'/Game/AmericasArmy/Animations/A_AA2_Objects/seabass/swim_loop.swim_loop'";
	FName fnWeaponSocket = TEXT("WeaponSocket");
	UWorld* const World = GetWorld();
	FVector myLocation = GetActorLocation();
	FRotator myRotation = GetActorRotation();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		
		LaserAttachment = World->SpawnActor<ABassLaserAttachment>(ABassLaserAttachment::StaticClass(), myLocation, myRotation, SpawnParams);
		if(LaserAttachment)
		{
			LaserAttachment->AttachToComponent(VisibleSkeletalMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LazerCon_joint"));
		}
		
		MyBeam = World->SpawnActor<ABassLaserBeam>(ABassLaserBeam::StaticClass(), myLocation, myRotation, SpawnParams);
		if (MyBeam)
		{
			MyBeam->AttachToComponent(VisibleSkeletalMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LazerCon_joint"));
			MyBeam->IlltemperedSeaBass = this;
		}
		UAnimSequence* LoadedAnimation = LoadObject<UAnimSequence>(NULL, *AnimPath, NULL, LOAD_None, NULL);
		if (LoadedAnimation)
		{
			UAnimationAsset* AnimationAsset = Cast<UAnimationAsset>(LoadedAnimation);
			VisibleSkeletalMesh->PlayAnimation(AnimationAsset, true);
		}
	}
}

void ABass::Destroyed()
{
	Super::Destroyed();
	
	if (LaserAttachment != NULL)
	{
		LaserAttachment->Destroy();
		LaserAttachment = NULL;
	}
	if (MyBeam != NULL)
	{
		MyBeam->Destroy();
		MyBeam = NULL;
	}
}
