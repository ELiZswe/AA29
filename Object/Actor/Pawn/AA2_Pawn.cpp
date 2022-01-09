// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AA2_Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "AA29/Object/Actor/AnimManager/AnimManager.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParamsCollision.h"


// Sets default values
AAA2_Pawn::AAA2_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Prepare the 3P Mesh
	Mesh_3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RootComponent"));
	Mesh_3P->SetupAttachment(RootComponent);

}


void AAA2_Pawn::BeginPlay()
{
	Super::BeginPlay();
	LoadMesh();
}


void AAA2_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAA2_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAA2_Pawn::LoadMesh()
{
	UMaterialInstance* Mat;
	if (Mesh)
	{
		Mesh_3P->SetSkeletalMesh(Mesh);
		if (Mesh_3P != nullptr)
		{
			if (Skins.Num() > 0)
			{
				for (int32 i = 0; i < Skins.Num(); i++)
				{
					Mat = Skins[i];
					Mesh_3P->SetMaterial(i, Mat);
				}
			}
			/*
			Mesh_3P->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
			PrePivot.Z = PrePivot.Z - 11;
			Mesh_3P->SetRelativeLocation(PrePivot * 2);
			Mesh_3P->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			Mesh_3P->bOnlyOwnerSee = false;
			Mesh_3P->bOwnerNoSee = true;
			Mesh_3P->CastShadow = true;

			// prevent anim frame skipping optimization based on visibility etc
			Mesh_3P->SetIsReplicated(true);
			Mesh_3P->bEnableUpdateRateOptimizations = false;
			Mesh_3P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
			Mesh_3P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
			Mesh_3P->bReceivesDecals = false;
			bNetUseOwnerRelevancy = true;
			*/
		}
	}
}

