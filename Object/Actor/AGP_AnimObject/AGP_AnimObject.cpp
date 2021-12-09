// All the original content belonged to the US Army


#include "AGP_AnimObject.h"


void AAGP_AnimObject::SetMesh()
{
	if (!CustomMesh)
	{
		CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Objects/RangeFlag.RangeFlag'"), NULL, LOAD_None, NULL);
	}

	//if (!Anim)
	//{
	//	Anim = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_Objects/USFlag/Wave.Wave'"), NULL, LOAD_None, NULL);
	//}

	if (CustomMesh)
	{
		SkeletalMesh->SetSkeletalMesh(CustomMesh);

		if (Anim != nullptr)
		{
			SkeletalMesh->SetAnimation(Anim);
			SkeletalMesh->PlayAnimation(Anim, true);
		}
	}
}

// Sets default values
AAGP_AnimObject::AAGP_AnimObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AnimRate = 1;
	//DrawType = 2;


		//Mesh=SkeletalMesh'A_AA2_Objects.RangeFlag'

	RangeRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RangeRoot"));
	RootComponent = RangeRoot;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	if (SkeletalMesh)
	{
		SkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}
	SetMesh();

}

// Called when the game starts or when spawned
void AAGP_AnimObject::BeginPlay()
{
	Super::BeginPlay();

	if (SkeletalMesh)
	{

		SetMesh();
	}
	
}

// Called every frame
void AAGP_AnimObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGP_AnimObject::PostNetBeginPlay()
{
	/*
	PostNetBeginPlay();
	DoAnimLoop();
	*/
}
void AAGP_AnimObject::MatchStarting()
{
	/*
	SetAnimFrame(StartFrame, AnimChannel);
	DoAnimLoop();
	SetDrawType(2);
	*/
}
void AAGP_AnimObject::DoAnimLoop()
{
	/*
	if (AnimSequence != 'None' && AnimSequence != 'None')
	{
		LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
	*/
}