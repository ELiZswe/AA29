// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AA2_Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "AA29/Object/Actor/AnimManager/AnimManager.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParamsCollision.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Inventory/Powerups/Powerups.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Projector/ShadowProjector/ShadowProjector.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"

// Sets default values
AAA2_Pawn::AAA2_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Prepare the 3P Mesh
	Mesh_3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RootComponent"));
	Mesh_3P->SetupAttachment(RootComponent);


	MovementAnims.SetNum(4);
	SwimAnims.SetNum(4);
	CrouchAnims.SetNum(4);
	WalkAnims.SetNum(4);
	AirAnims.SetNum(4);
	TakeoffAnims.SetNum(4);
	LandAnims.SetNum(4);
	DoubleJumpAnims.SetNum(4);
	DodgeAnims.SetNum(4);
	TauntAnimNames.SetNum(16);
	MovementAnimRate.SetNum(4);
	FriendlyMaterial.SetNum(5);
	EnemyMaterial.SetNum(5);
	MovementBlendAlpha.SetNum(4);
	_InvGrenades.SetNum(7);
	HiddenAttachmentClasses.SetNum(24);

}

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bIsWalking, bIsCrouched, bSimulateGravity, bSpecialHUD, DrivenVehicle, HeadScale, PlayerReplicationInfo, AnimAction, AnimLoopAction, TakeHitLocation, HitDamageType, JavelinReloadAnimation;
	reliable if (((bTearOff && bNetDirty) && (Role == ROLE_Authority)))
		TearOffMomentum;
	reliable if (((bNetDirty && (!bNetOwner)) && (Role == ROLE_Authority)))
		bSteadyFiring, ViewPitch;
	reliable if (((bNetDirty && bNetOwner) && (Role == ROLE_Authority)))
		Controller, bCanWallDodge, GroundSpeed, WaterSpeed, AirSpeed, AccelRate, JumpZ, AirControl, PitchUpLimit, PitchDownLimit, SelectedItem;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		Health;
	reliable if (((bNetDirty && bNetInitial) && (Role == ROLE_Authority)))
		HealthMax;
	reliable if (((!bNetOwner) && (Role == ROLE_Authority)))
		PawnPosition;
	reliable if ((Role == ROLE_Authority))
		ShieldStrength, HitFx, HitFxTicker;
	reliable if ((Role < ROLE_Authority))
		ServerChangedWeapon, NextItem, ServerNoTranslocator, ReportCivilianEvent;
	reliable if (((!bNetOwner) && (Role == ROLE_Authority)))
		PawnCollisionHeight, PawnPrePivotZ;
	reliable if (((bNetDirty && bNetInitial) && (Role == ROLE_Authority)))
		bNetAlreadyDead;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bGuerrillaMesh, ShadowDarkness;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		Weapon, bIsProne, bIsHipShooting, bIsSprinting, SpeedRatio, SpeedRatio_Always, fInvWeight, bUpdateSkinsAndMeshes, FriendlyMaterial, EnemyMaterial, FriendlyMesh, EnemyMesh, bPawnZoomed;
	reliable if (((bNetDirty && (!bNetOwner)) && (Role == ROLE_Authority)))
		LeanDirection, FullBodyAnim, UpperBodyAnim, AnimPitch;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		DeathAnim;
	reliable if (((!bNetOwner) && (Role == ROLE_Authority)))
		bCanClimbLadders, OnLadder;
	reliable if ((Role < ROLE_Authority))
		ServerLean, ServerReload;
	reliable if ((Role == ROLE_Authority))
		ClientPlayBulletWhip;
	reliable if ((Role == ROLE_Authority))
		AnimManager;
	reliable if (((bNetOwner && bNetDirty) && (Role == ROLE_Authority)))
		CE_MeterValue, bUsingObjective, _InvHands, _InvShoulder, _InvHolster, _InvUtility, _InvHip, _InvAltShoulder, _InvGrenades, _InvBinoculars, _InvMedPacks, _InvSelfHealMedPacks;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		VirtualHealth, BleedHealth, BleedMax;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		CE_RecoveryPenalty, CE_DesiredValue, CE_MaxMeterValue;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bHidePawn;
	reliable if ((Role == ROLE_Authority))
		MovementAnimFrame, MovementBlendAlpha;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		HiddenAttachmentClasses;
}
*/



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
void AAA2_Pawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAA2_Pawn, Weapon);
	DOREPLIFETIME(AAA2_Pawn, bIsProne);
	DOREPLIFETIME(AAA2_Pawn, bIsSprinting);
	DOREPLIFETIME(AAA2_Pawn, bIsWalking);
	DOREPLIFETIME(AAA2_Pawn, Health);

	DOREPLIFETIME(AAA2_Pawn, Anim_1P);

	//Third Person Stuff
	DOREPLIFETIME(AAA2_Pawn, Mesh_3P);
	DOREPLIFETIME(AAA2_Pawn, Anim_3P);

	/*
	DOREPLIFETIME(AAA2_Pawn, bIsCrouching);
	DOREPLIFETIME(AAA2_Pawn, TeamClass);


	DOREPLIFETIME(AAA2_Pawn, bIsCrouched2);

	DOREPLIFETIME(AAA2_Pawn, AGP_Speed);
	DOREPLIFETIME(AAA2_Pawn, AGP_Direction);
	*/
}
