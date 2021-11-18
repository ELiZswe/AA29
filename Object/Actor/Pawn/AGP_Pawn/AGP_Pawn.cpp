// All the original content belonged to the US Army


#include "AGP_Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineGlobals.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/Controller.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"

#include "AA29/Inventory/Inventory.h"
#include "AA29/Inventory/DummyItem/DummyItem.h"
#include "AA29/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "AA29/AuxCollisionCylinder/AuxCollisionCylinder.h"

#include "AA29\Inventory\Weapon\AGP_Weapon\TraceWeapon\SniperRifle\Weapon_M82_Sniper\Weapon_M82_Sniper.h"
#include "AA29\Inventory\Weapon\AGP_Weapon\TraceWeapon\SniperRifle\Weapon_M24_Sniper\Weapon_M24_Sniper.h"
#include "AA29\Inventory\Weapon\AGP_Weapon\TraceWeapon\SniperRifle\Weapon_M24_Sniper\Weapon_MosinNagant_Sniper\Weapon_MosinNagant_Sniper.h"
#include "AA29\Inventory\Weapon\AGP_Weapon\TraceWeapon\SniperRifle\Weapon_SVD_Sniper\Weapon_SVD_Sniper.h"

#include "AA29/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

#include "AA29/Mover/Mover.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AA29/Eventlab/Eventlab.h"

#include "EngineGlobals.h"
#include "Engine/Engine.h"


#include "Materials/MaterialInstance.h"


void AAGP_Pawn::LoadMesh()
{
	UMaterialInstance* Mat;
	if (CustomMesh)
	{
		Mesh_3P->SetSkeletalMesh(CustomMesh);
		if (Mesh_3P != nullptr)
		{
			if (Skins.Num() > 0)
			{
				for (int i = 0; i < Skins.Num(); i++)
				{
					Mat = Skins[i];
					Mesh_3P->SetMaterial(i, Mat);
				}
			}
			Mesh_3P->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
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
		}
	}
}



// Sets default values
AAGP_Pawn::AAGP_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bReplicates = true;

	NPC_LikesToProne         = 50;
	NPC_LikesToCrouch        = 50;
	NPC_LikesToStand         = 50;
	NPC_LikesToAmbush        = 50;
	NPC_LikesToAssault       = 50;
	NPC_LikesToTalk          = 50;
	NPC_LikesToAmbient       = 50;
	NPC_LikesToThrowGrenade  = 50;
	NPC_ShootAccuracy       = 5;
	iNPC_FragGrenade        = 3;
	iNPC_StunGrenade        = 1;
	iNPC_SmokeGrenade       = 1;
	RagdollOverride         = "SoldierM";
	RagInvInertia           = 4;
	RagShootStrength        = 10000;
	RagSpinScale            = 13;
	RagProneProjectileScale = 0.35;
	followmouse             = true;
	bEyeTrack               = true;
	bUseAuxCollision        = true;
	sBulletWhip             = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby1.WeaponFX_Passby_Passby1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby2.WeaponFX_Passby_Passby2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby3.WeaponFX_Passby_Passby3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby4.WeaponFX_Passby_Passby4"), NULL, LOAD_None, NULL)
	};
	sBulletCrack            = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack1.WeaponFX_Passby_Crack1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack2.WeaponFX_Passby_Crack2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack3.WeaponFX_Passby_Crack3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack4.WeaponFX_Passby_Crack4"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack5.WeaponFX_Passby_Crack5"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack6.WeaponFX_Passby_Crack6"), NULL, LOAD_None, NULL)
	};
	sMilesGraze             = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/miles/WeaponFX_MILES_NearMiss.WeaponFX_MILES_NearMiss"), NULL, LOAD_None, NULL)
	};
	sParaLanding            = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground1.paratrooperhitsground1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground2.paratrooperhitsground2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground3.paratrooperhitsground3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground4.paratrooperhitsground4"), NULL, LOAD_None, NULL)
	};
	sCrouchToProne          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_CrouchToProne.Human_Movement_CrouchToProne"), NULL, LOAD_None, NULL);
	sProneToCrouch          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_ProneToCrouch.Human_Movement_ProneToCrouch"), NULL, LOAD_None, NULL);
	sProneToStand           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_ProneToStand.Human_Movement_ProneToStand"), NULL, LOAD_None, NULL);
	sStandToProne           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_StandToProne.Human_Movement_StandToProne"), NULL, LOAD_None, NULL);
	fHealDivisor            = 5;
	fpBleedRate             = 5;
	CurrentZoneTimeToKill   = 9999999;
	bNewAccuracy            = true;
	fSpeedPenalty           = 1;
	bCanSwapWeapons         = true;
	bCanCrouch              = true;
	bCanClimbLadders        = true;
	bCanStrafe              = true;
	bCanWalkOffLedges       = true;
	bCanPickupInventory     = true;
	GroundSpeed             = 90;
	WaterSpeed              = 300;
	AirSpeed                = 1200;
	AccelRate               = 2048;
	JumpZ                   = 400;
	AirControl              = 0.35;
	MaxFallSpeed            = 750;
	bCanProne               = true;
	bCanSprint              = true;
	LeanDirection           = 1;
	LeanSpeed               = 4;
	LeanOffsetRight         = FVector(2, 16, -4);
	LeanOffsetLeft          = FVector(-2, 16 , 4);
	LeanRollView            = 2000;
	BreathInSound           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Breathe/BreatheIn.BreatheIn"), NULL, LOAD_None, NULL);
	BreathOutSound          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Breathe/BreathOut.BreathOut"), NULL, LOAD_None, NULL);
	fWalkSpeed              = 120;
	fWalkRearPct            = 0.83;
	fRunSpeed               = 220;
	fRunSidePct             = 0.6;
	fCrouchSpeed            = 60;
	fFastCrouchSpeed        = 100;
	fHCrawlSpeed            = 68;
	fLCrawlSpeed            = 25;
	fRollTime               = 1.5;
	CE_RecoveryPenalty      = 1;
	CE_MeterValue           = 1;
	fMaxGrabHeight          = 64;
	fGrabBufferDist         = 5;
	fMantleSpeed            = 50;
	fFallDamageSpd          = -500;
	PrePivot                = FVector(0, 0, -38);
	SoundRadius             = 240;
	bBulletPenetration      = true;
	//KParams = KarmaParamsSkel'AGP.AGP_Pawn.PawnKParams'
	


	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(25.f, 96.0f);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Create a CameraComponent	
	//FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	//FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	//FirstPersonCameraComponent->SetRelativeLocation(FVector(-5.0f, 0.0f, 25 + BaseEyeHeight));
	//FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a 1P Mesh	
	CustomMesh_1P = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P.M249_1P"), NULL, LOAD_None, NULL);
	//Anim_1P       = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Select.Select'"), NULL, LOAD_None, NULL);
	Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Still.Still'"), NULL, LOAD_None, NULL);

	// Create a 3P Mesh	
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman.SoldierM_Infantry_Arctic_Rifleman'"), NULL, LOAD_None, NULL);

	Anim_3P    = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman/StdLgFr.StdLgFr'"), NULL, LOAD_None, NULL);
	

	//Prepare the 1P Mesh
	Mesh_1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	Mesh_1P->SetupAttachment(RootComponent);
	//Mesh_1P->SetupAttachment(FirstPersonCameraComponent);

	//Prepare the 3P Mesh
	Mesh_3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ThirdPersonMesh"));
	Mesh_3P->SetupAttachment(RootComponent);
	
	ProjectileClass = AProjectile::StaticClass();

	/*
	UAnimSequence* LoadedAnimation = LoadObject<UAnimSequence>(NULL, *AnimPath, NULL, LOAD_None, NULL);
	FString AnimPath = GetAnimationPath();
	B2Utility::LogInfo(AnimPath);
	UAnimSequence* LoadedAnimation = LoadObject<UAnimSequence>(NULL, *AnimPath, NULL, LOAD_None, NULL);
	if (LoadedAnimation)
	{
		UAnimationAsset* AnimationAsset = Cast<UAnimationAsset>(LoadedAnimation);
		if (AnimationAsset)
		{
			AvatarMesh->SetAnimation(AnimationAsset);
			AvatarMesh->PlayAnimation(AnimationAsset, true);
		}
	}
	*/
	LoadMesh();

	//From Pawn:
	HealthMax = 100.000000;
	Health = 100;


	AGP_Direction = 50;				//Forward -50 -> 50
	AGP_Speed = 0;				//Sprint Forward 0 -> 100

	/*
	//Specify Animation BluePrint
	Mesh_3P->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> FoundAnimBP(TEXT("/Game/AmericasArmy/Blueprints/Anim/SoldierM_AnimBlueprint.SoldierM_AnimBlueprint"));
	UAnimBlueprintGeneratedClass* PreviewBP = FoundAnimBP.Object->GetAnimBlueprintGeneratedClass();
	Mesh_3P->SetAnimInstanceClass(PreviewBP);
	*/

}










// Called when the game starts or when spawned
void AAGP_Pawn::BeginPlay()
{
	FString myName;

	//Inventory = AWeapon_M16A2_Rifle::StaticClass();

	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		fInitialAnimationComplete = true;
	}
	Super::BeginPlay();
	

	if (GetNetMode() == ENetMode::NM_Client)
	{
		
		/*
		if (AGP_GameInfo(Level.Game).bNoInventory)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::BeginPlay()	Not giving InvContainers!"));
		}
		else
		{
			if (_InvHands == nullptr)
			{
				_InvHands=SpawnContainer("AGP_Inventory.InvHands");
				_InvShoulder=SpawnContainer("AGP_Inventory.InvShoulder");
				_InvUtility=SpawnContainer("AGP_Inventory.InvUtility");
				_InvHolster=SpawnContainer("AGP_Inventory.InvHolster");
				_InvHip=SpawnContainer("AGP_Inventory.InvHip");
				_InvAltShoulder=SpawnContainer("AGP_Inventory.InvAltShoulder");
			}
		}
		*/

		/*
			//Spawn a M24
			UWorld* const World = GetWorld();
			//FVector myLocation = GetActorLocation();
			myLocation = FVector(1900.998901, -282.000000, 262.000671);
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = Instigator;
				AActor* const SpawningObject = World->SpawnActor<AActor>(AWeapon_M24_Sniper::StaticClass(), myLocation, FRotator::ZeroRotator, SpawnParams);
			}
		*/
	}

}



// Called every frame
void AAGP_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FastTick(DeltaTime);
}



//These is the new ones:
void AAGP_Pawn::AAGP_Pawn::Clone()
{
}
void AAGP_Pawn::AAGP_Pawn::AnimateGrenadeMoving()
{
}
void AAGP_Pawn::AAGP_Pawn::RemoveParachuteSkins()
{
}
void AAGP_Pawn::AAGP_Pawn::MatchStarting()
{
}
void AAGP_Pawn::AAGP_Pawn::ConfigureLinkDamage()
{
}
void AAGP_Pawn::AAGP_Pawn::ActivateLinkedObjective(APawn* User)
{
}
void AAGP_Pawn::AAGP_Pawn::SetWeaponRelativeRotation(FRotator rotNew)
{
}
void AAGP_Pawn::AAGP_Pawn::SetAnimAction(FName NewAction)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		//EnableChannelNotify(1,1);
		//AnimBlendParams(1,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim(NewAction,1,0.05,1);

	}
	else
	{
		//EnableChannelNotify(1,1);
		//AnimBlendParams(1,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim(NewAction,1,0.05,1);
		//AnimAction=NewAction;
	}
}
void AAGP_Pawn::AAGP_Pawn::ClientSetViewRotation(FRotator NewRotation)
{
	//SetViewRotation(NewRotation);
}
void AAGP_Pawn::AAGP_Pawn::KNotifySimError()
{
	/*
	local HumanController HC;
	HC=HumanController(Level.GetClientController());
	if (HC.ViewTarget == Self)
	{
		HC.NotifyLostViewTarget();
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::SetupBoneAuxCylinder()
{
	if (BoneAuxCyl == nullptr)
	{
		//BoneAuxCyl=Spawn(Class'AuxCollisionCylinder',Self,,Location);
	}
	//BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	BoneAuxCyl->SetAuxCylinder(false);
	//BoneAuxCyl->SetBase(this);
	BoneAuxCyl->SetOwner(this);
	//BoneAuxCyl->bProjTarget=true;
	//BoneAuxCyl->bBlockBulletTraces=true;
	//bBlockBulletTraces=false;
}

void AAGP_Pawn::AAGP_Pawn::PreBeginPlay()
{
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	//Super::PreBeginPlay();
	if (bUseAuxCollision)
	{
		SetupBoneAuxCylinder();
		//GetAxes(Rotation,X,Y,Z);
		if (FrontAuxCyl == nullptr)
		{
			//FrontAuxCyl=Spawn(Class'AuxCollisionCylinder',Self,,Location + X * ProneRadius * 1.5);
		}
		if (BackAuxCyl == nullptr)
		{
			//BackAuxCyl=Spawn(Class'AuxCollisionCylinder',Self,,Location - X * ProneRadius * 1.3);
		}
		//FrontAuxCyl->SetBase(this);
		//BackAuxCyl->SetBase(this);
		FrontAuxCyl->SetAuxCylinder(false);
		BackAuxCyl->SetAuxCylinder(false);
		//BoneAuxCyl->SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
		
		bInProneTransition=false;
	}
	//NV_AmbientGlow=Cast<AAA2_WorldSettings>(GetWorldSettings())->Pawn_NV_AmbientGlow;
	fHopTimer=8;
}


void AAGP_Pawn::AAGP_Pawn::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PostBeginPlay()	" $ Self);
	Super::PostBeginPlay();
	SetRotation(MakeRot(0,Rotation.Yaw,0));
	if (GetNetMode() != ENetMode::NM_Client)
	{
		SetCustomTimer(1,True,'AlertAIOfPlayerNoiseTimer');
	}
	*/
}

void AAGP_Pawn::AAGP_Pawn::AlertAIOfPlayerNoiseTimer()
{
	
	if (bIsProne || bIsCrouched || bIsWalking)
	{
		return;
	}
	//if (VSize(Velocity) > 0)
	//{
	//	MakeNoise(1,Self);
	//}
}
void AAGP_Pawn::AAGP_Pawn::PostBeginNetPlay()
{
	/*
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PostBeginNetPlay()	" $ Self);
	SetRotation(MakeRot(0,Rotation.Yaw,0));
	*/
}
bool AAGP_Pawn::AAGP_Pawn::AllowAnimFiring()
{
	return true;
}
void AAGP_Pawn::AAGP_Pawn::SpawnContainer(FString class_name)
{
	/*
	local InvContainer local_container;
	local class<InvContainer>  container_class;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SpawnContainer() - creating " $ class_name);
	}
	container_class=class<InvContainer>(DynamicLoadObject(class_name,Class'Class'));
	if (container_class != None)
	{
		local_container=Spawn(container_class,Self);
		if (local_container != None)
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			{
				DebugLog(DEBUG_Inv,"PickupFunction for " $ local_container);
			}
			local_container.PickupFunction(Self);
			AddContainer(local_container);
			return local_container;
		}
	}
	DebugLog(DEBUG_Warn,"AGP_Pawn::SpawnContainer()	Failed to create InvContainer " $ class_name);
	return None;
	*/
}

void AAGP_Pawn::AAGP_Pawn::AddContainer (AInvContainer* Add)
{
	AInvContainer* Last;
	if (_InvTop == nullptr)
	{
		_InvTop=Add;
	}
	else
	{
		Last=_InvTop;
		if (Last->nextContainer != nullptr)
		{
			Last=Last->nextContainer;
		}
		Last->nextContainer=Add;
	}
}


void AAGP_Pawn::AAGP_Pawn::PossessedBy(AController* C)
{
	Super::PossessedBy(C);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("%s, Possessed by : %s"), *GetHumanReadableName(), *C->GetName()), false);
	}
	/*
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Entered");
	DebugLog(DEBUG_Multi,"Possessing:" @ Self);
	PossessedBy(C);
	if (PlayerReplicationInfo != None)
	{
		DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy PRI != None; Calling ServerSetMyPawn()");
		PlayerReplicationInfo.ServerSetMyPawn(Self);
	}
	if (C.IsA('AIController'))
	{
		return;
	}
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Calling SpawnTeamClass()");
	
	SpawnTeamClass(Cast<AAGP_Pawn>(C)->TeamClassClass);
	
	if (PlayerReplicationInfo != None)
	{
		PlayerReplicationInfo.requiredClass=C.TeamClassClass;
	}
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Leaving");
	*/
}

void AAGP_Pawn::AAGP_Pawn::SpawnTeamClass(AActor* actor_class)
{
//	ASoldierClass*  sclass;
	AHumanController* HC;

	HC = Cast<AHumanController>(Controller);


	if (HC != nullptr && !HC->QualifiedFor(actor_class))
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changing to Rifleman " $ Self @ actor_class);
	}

	/*
	local class<SoldierClass>  sclass;
	local HumanController HC;
	HC=HumanController(Controller);
	if (HC != None && ! HC.QualifiedFor(actor_class))
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changing to Rifleman " $ Self @ actor_class);
		if (PlayerReplicationInfo.bGuerrillaPS)
		{
			sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassGuerrillaAK74su",Class'Class'));
		}
		else
		{
			if (PlayerReplicationInfo.bSpecialForcesPS)
			{
				sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassSFRifleman",Class'Class'));
			}
			else
			{
				Switch(PlayerReplicationInfo.Team.UseAltClass(0))
				{
					case 1:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRiflemanM4A1AutoIron",Class'Class'));
					break;
					case 2:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRiflemanM4A1Auto",Class'Class'));
					break;
					default:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRifleman",Class'Class'));
				}
				DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changed to: " $ Self $ sclass);
			}
		}
	}
	else
	{
		sclass=class<SoldierClass>(actor_class);
	}
	if (sclass == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Got a null SoldierClass - defaulting to Recruit");
		sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRecruit",Class'Class'));
	}
	DebugLog(DEBUG_Inv,"AGP_Pawn::SpawnTeamClass() " $ Self @ sclass);
	if (PlayerReplicationInfo != None && PlayerReplicationInfo.bSpecialForcesPS && ! PlayerReplicationInfo.bQualifiedSF)
	{
		sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassGuerrillaAK74su",Class'Class'));
	}
	if (TeamClass != None && sclass != None && TeamClass.Class != sclass)
	{
		DebugLog(DEBUG_Warn,"sclass doesn't match current TeamClass");
	}
	if (TeamClass == None && sclass != None)
	{
		TeamClass=Spawn(sclass,Self);
	}
	TeamClass.adjustAttributes();
	*/
}
void AAGP_Pawn::AAGP_Pawn::SpawnTeamRole(AActor* actor_class)
{
	/*
	local class<SoldierRole>  srole;
	srole=class<SoldierRole>(actor_class);
	if (srole == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamRole()	Got a null SoldierRole - defaulting to FTMember");
		srole=class<SoldierRole>(DynamicLoadObject("AGP_AI.FTMemberRole",Class'Class'));
	}
	TeamRole=Spawn(srole,Self);
	*/
}
void AAGP_Pawn::AAGP_Pawn::getMentalModel()
{
	/*
	if (_mentalModel == None && Leader != None)
	{
		return Leader.getMentalModel();
	}
	else
	{
		return _mentalModel;
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::createMentalModel()
{
	/*
	_mentalModel=Spawn('MentalModel');
	return getMentalModel();
	*/
}
void AAGP_Pawn::AAGP_Pawn::resetMentalModel()
{
	/*
	_mentalModel=None;
	return getMentalModel();
	*/
}
/*
void AAGP_Pawn::AAGP_Pawn::setMentalModel (MentalModel set_mm)
{
	_mentalModel=set_mm;
}
*/
void AAGP_Pawn::AAGP_Pawn::ownsMentalModel()
{
	/*
	if (_mentalModel == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::GetInterpolatedRotation()
{
	//return MakeRot(InterpolatedPitch,InterpolatedYaw,0);
}
void AAGP_Pawn::AAGP_Pawn::LockMovement(bool bLock)
{
	bLockMovement=bLock;
}
void AAGP_Pawn::AAGP_Pawn::LimitRotation(bool bLimit)
{
	bLimitRotation=bLimit;
}
void AAGP_Pawn::AAGP_Pawn::SetMovementPhysics()
{
	/*
	if (Physics == 2)
	{
		return;
	}
	else
	{
		if (DrivenVehicle == None)
		{
			SetPhysics(1);
		}
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::SetWalking(bool bNewIsWalking)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"SLOWMODE," $ bNewIsWalking);
	}
	if (Physics == 17)
	{
		return;
	}
	if (bNewIsWalking != bIsWalking || bIsScriptedWalking)
	{
		bIsWalking=bNewIsWalking;
		if (bIsScriptedWalking)
		{
			bIsWalking=True;
		}
		if (bIsWalking)
		{
			bWantsToSprint=False;
		}
		if (Weapon != None)
		{
			Weapon.SetFastMove(! bIsWalking);
		}
	}
	UpdateGroundspeeds();
	*/
}
void AAGP_Pawn::AAGP_Pawn::UpdateGroundspeeds()
{
	if (bIsProne)
	{
		if (! bIsWalking)
		{
			GroundSpeed=fHCrawlSpeed * fSpeedPenalty;
		}
		else
		{
			GroundSpeed=fLCrawlSpeed * fSpeedPenalty;
		}
		AccelRate=2048;
	}
	else
	{
		if (bIsCrouched)
		{
			if (! bIsWalking)
			{
				GroundSpeed=fFastCrouchSpeed * fSpeedPenalty;
			}
			else
			{
				GroundSpeed=fCrouchSpeed * fSpeedPenalty;
			}
			AccelRate=2048;
		}
		else
		{
			if (! bIsWalking)
			{
				GroundSpeed=fRunSpeed * fSpeedPenalty;
				//AccelRate=Default.AccelRate;
			}
			else
			{
				GroundSpeed=fWalkSpeed * fSpeedPenalty;
				AccelRate=2048;
			}
		}
	}
}
/*
void AAGP_Pawn::AAGP_Pawn::EndClimbLadder(ALadderVolume* OldLadder)
{

	if (Controller != None)
	{
		Controller.EndClimbLadder();
	}
	if (Controller != None && GetNetMode() == ENetMode::NM_Standalone)
	{
		StudentController(Controller).EndClimbingLadder(OldLadder);
	}
	if (Physics == 11)
	{
		if (Controller.IsA('AIController'))
		{
			SetPhysics(2);
		}
		else
		{
			SetPhysics(1);
		}
	}
	if (Weapon != None)
	{
		Weapon.TempRaiseWeapon();
	}
	LimitRotation(False);

}
*/
/*
void AAGP_Pawn::AAGP_Pawn::ClimbLadder (ALadderVolume* L)
{
	if (isDead())
	{
		return;
	}
	TakeFallingDamage();
	if (Velocity.Z < -1.4 * JumpZ)
	{
		Log("Velocity fast when entering ladder volume: " $ Velocity.Z $ " Damage is " $ GetFallingDamage(Velocity.Z));
		MakeNoise(-0.5 * Velocity.Z / FMax(JumpZ,150));
	}
	if (Controller != None && GetNetMode() == ENetMode::NM_Standalone)
	{
		StudentController(Controller).StartClimbingLadder(L);
	}
	OnLadder=L;
	SetRotation(OnLadder.WallDir);
	SetPhysics(11);
	if (IsHumanControlled())
	{
		Controller.GotoState('PlayerClimbing');
	}
	GotoState('None');
	if (Weapon != None && ! Weapon.IsInState('BusyTempLowering') || Weapon.IsInState('BusyTempDown'))
	{
		Weapon.TempLowerWeapon();
	}
	bWantsToSprint=False;
	ResetLean();
	CombatEffectivenessEvent(9);
	LimitRotation(True);
	rRotationLimits=Default.rRotationLimits;
	rBaseRotation=L.WallDir;

}
*/
void AAGP_Pawn::AAGP_Pawn::CanGrabLadder()
{
	//return bCanClimbLadders && Physics != 11;
}
void AAGP_Pawn::AAGP_Pawn::GetSprintModifier(float DeltaYaw, float DeltaTime, bool bJumped)
{
	/*
	local float mod;
	if (bIsSprinting)
	{
		CombatEffectivenessEvent(4,DeltaTime);
		if (DeltaYaw > 32768)
		{
			mod=1;
		}
		else
		{
			if (DeltaYaw != 0)
			{
				mod=FClamp(fSprintMod - Default.fSprintMod - 1 * DeltaYaw / 32768,1,Default.fSprintMod);
			}
			else
			{
				mod=FClamp(fSprintMod + Default.fSprintMod - 1 * DeltaTime * 0.75,1,Default.fSprintMod);
			}
		}
	}
	else
	{
		if (fSprintMod != Default.fSprintMod)
		{
			mod=FClamp(fSprintMod + Default.fSprintMod - 1 * DeltaTime * 0.75,1,Default.fSprintMod);
		}
		else
		{
			mod=fSprintMod;
		}
	}
	if (bJumped)
	{
		mod *= 0.75;
	}
	return mod;
	*/
}

/*
 // ======================================================================================
 // AGP function - GetSpeedModifier
 // Retrieves a scalar [0,1] that limits the total groundspeed of the pawn
 // Takes into account Strength, Inventory Weight, and Damage
 // output:	float [0,1] to scale groundspeed
 // last modified by:  superville 12/20/01
 // ======================================================================================
*/

void AAGP_Pawn::AAGP_Pawn::GetSpeedModifier()
{
	/*
	local float Modifier;
	local Pawn.EHealthCondition HC;
	Modifier=1;
	if (fInvWeight > fStrength)
	{
		Modifier *= 1 - fInvWeight - fStrength / fInvWeight / 2;
	}
	if (Level.GamePlayMode == 0)
	{
		HC=GetHealthCondition();
		if (HC == 0)
		{
			Modifier *= 1;
		}
		else
		{
			if (HC == 1)
			{
				Modifier *= 0.8;
			}
			else
			{
				if (HC == 2)
				{
					Modifier *= 0.6;
				}
				else
				{
					Modifier *= 0;
				}
			}
		}
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"GetSpeedModifier:" @ SpeedRatio);
	}
	return Modifier;
	*/
}


/* =================================================================================== *
 * AGP function GetSpeedModifier_Always()
 *	The normal speed modifier only applies to your max possible speed (standing/fast mode)
 *	This modifier gets applied to your current speed, no matter what mode you are in.
 *	Right now, only being zoomed currently affects your speed in all cases.
 *
 * output:	float [0,1] to scale groundspeed
 *
 * last modified by: cmb
 * =================================================================================== */
float AAGP_Pawn::AAGP_Pawn::GetSpeedModifier_Always()
{
	float Modifier;
	Modifier=1;
	if (IsZoomed())
	{
		Modifier *= 1;
	}
	return Modifier;
}
void AAGP_Pawn::AAGP_Pawn::StartMantle(int32 EndPosture, FVector MantleLoc, FRotator BaseRot)
{
	/*
	local FVector Move;
	iMantleEndPosture=EndPosture;
	vMantlePoint=MantleLoc;
	rBaseRotation=BaseRot;
	rRotationLimits=Default.rRotationLimits;
	LimitRotation(True);
	Move=Location - vMantlePoint;
	Move.Z=0;
	Move=Normal(Move) * CollisionRadius + fGrabBufferDist;
	Move=vMantlePoint + Move;
	Move.Z=Location.Z;
	SetLocation(Move);
	if (Controller != None)
	{
		Controller.GotoState('PlayerMantle');
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::EndMantle(int32 EndPosture)
{
	/*
	LimitRotation(False);
	if (EndPosture == 0)
	{
		ShouldStand();
	}
	else
	{
		if (EndPosture == 1)
		{
			ShouldCrouch(True);
		}
		else
		{
			ShouldProne(True);
		}
	}
	SetPhysics(2);
	if (Controller != None)
	{
		Controller.GotoState('PlayerWalking');
	}
	*/
}
/*
void AAGP_Pawn::AAGP_Pawn::GetViewRotation ()
{

	if (UseAnimatedEyeRotation())
	{
		return EyeRotation();
	}
	else
	{
		return GetViewRotation();
	}

}
*/
bool AAGP_Pawn::AAGP_Pawn::UseAnimatedEyeRotation()
{
	return false;
}
FVector AAGP_Pawn::AAGP_Pawn::EyePosition()
{
	//return EyeHeight * FVector(0, 0, 1) + WalkBob + Location;
	return FVector(0, 0, 0);   //FAKE ELiZ
}
void AAGP_Pawn::AAGP_Pawn::EyeRotation()
{
	//return GetViewRotation();
}
void AAGP_Pawn::AAGP_Pawn::CheckBob(float DeltaTime, FVector Y)
{
	/*
	local float Speed2D;
	Speed2D=Sqrt(Velocity.X * Velocity.X + Velocity.Y * Velocity.Y);
	if (Speed2D < 10)
	{
		bobtime += 0.2 * DeltaTime;
	}
	else
	{
		bobtime += DeltaTime * 0.3 + 0.7 * Speed2D / GroundSpeed * 2.5;
	}
	WalkBob=Y * 0.2 * Bob * Speed2D * Sin(8 * bobtime);
	AppliedBob=AppliedBob * 1 - FMin(1,16 * DeltaTime);
	if (Speed2D < 10)
	{
		WalkBob.Z=AppliedBob;
	}
	else
	{
		WalkBob.Z=AppliedBob + 0.1 * Bob * Speed2D * Sin(16 * bobtime);
	}
	*/
}
void AAGP_Pawn::AAGP_Pawn::AngleEditorCalculate()
{
	
	FRotator Rotator;
	float multiplier;
	multiplier=182;
	
	if (s1boneangle1R > 180)
	{
		s1boneangle1R=s1boneangle1R - 180 - 180;
	}
	if (s1boneangle1R < -180)
	{
		s1boneangle1R=s1boneangle1R + 180 + 180;
	}
	if (s1boneangle1P > 180)
	{
		s1boneangle1P=s1boneangle1P - 180 - 180;
	}
	if (s1boneangle1P < -180)
	{
		s1boneangle1P=s1boneangle1P + 180 + 180;
	}
	if (s1boneangle1Y > 180)
	{
		s1boneangle1Y=s1boneangle1Y - 180 - 180;
	}
	if (s1boneangle1Y < -180)
	{
		s1boneangle1Y=s1boneangle1Y + 180 + 180;
	}
	if (s1boneangle2R > 180)
	{
		s1boneangle2R=s1boneangle2R - 180 - 180;
	}
	if (s1boneangle2R < -180)
	{
		s1boneangle2R=s1boneangle2R + 180 + 180;
	}
	if (s1boneangle2P > 180)
	{
		s1boneangle2P=s1boneangle2P - 180 - 180;
	}
	if (s1boneangle2P < -180)
	{
		s1boneangle2P=s1boneangle2P + 180 + 180;
	}
	if (s1boneangle2Y > 180)
	{
		s1boneangle2Y=s1boneangle2Y - 180 - 180;
	}
	if (s1boneangle2Y < -180)
	{
		s1boneangle2Y=s1boneangle2Y + 180 + 180;
	}
	if (s1boneangle3R > 180)
	{
		s1boneangle3R=s1boneangle3R - 180 - 180;
	}
	if (s1boneangle3R < -180)
	{
		s1boneangle3R=s1boneangle3R + 180 + 180;
	}
	if (s1boneangle3P > 180)
	{
		s1boneangle3P=s1boneangle3P - 180 - 180;
	}
	if (s1boneangle3P < -180)
	{
		s1boneangle3P=s1boneangle3P + 180 + 180;
	}
	if (s1boneangle3Y > 180)
	{
		s1boneangle3Y=s1boneangle3Y - 180 - 180;
	}
	if (s1boneangle3Y < -180)
	{
		s1boneangle3Y=s1boneangle3Y + 180 + 180;
	}
	if (s2boneangle1R > 180)
	{
		s2boneangle1R=s2boneangle1R - 180 - 180;
	}
	if (s2boneangle1R < -180)
	{
		s2boneangle1R=s2boneangle1R + 180 + 180;
	}
	if (s2boneangle1P > 180)
	{
		s2boneangle1P=s2boneangle1P - 180 - 180;
	}
	if (s2boneangle1P < -180)
	{
		s2boneangle1P=s2boneangle1P + 180 + 180;
	}
	if (s2boneangle1Y > 180)
	{
		s2boneangle1Y=s2boneangle1Y - 180 - 180;
	}
	if (s2boneangle1Y < -180)
	{
		s2boneangle1Y=s2boneangle1Y + 180 + 180;
	}
	if (s2boneangle2R > 180)
	{
		s2boneangle2R=s2boneangle2R - 180 - 180;
	}
	if (s2boneangle2R < -180)
	{
		s2boneangle2R=s2boneangle2R + 180 + 180;
	}
	if (s2boneangle2P > 180)
	{
		s2boneangle2P=s2boneangle2P - 180 - 180;
	}
	if (s2boneangle2P < -180)
	{
		s2boneangle2P=s2boneangle2P + 180 + 180;
	}
	if (s2boneangle2Y > 180)
	{
		s2boneangle2Y=s2boneangle2Y - 180 - 180;
	}
	if (s2boneangle2Y < -180)
	{
		s2boneangle2Y=s2boneangle2Y + 180 + 180;
	}
	if (s2boneangle3R > 180)
	{
		s2boneangle3R=s2boneangle3R - 180 - 180;
	}
	if (s2boneangle3R < -180)
	{
		s2boneangle3R=s2boneangle3R + 180 + 180;
	}
	if (s2boneangle3P > 180)
	{
		s2boneangle3P=s2boneangle3P - 180 - 180;
	}
	if (s2boneangle3P < -180)
	{
		s2boneangle3P=s2boneangle3P + 180 + 180;
	}
	if (s2boneangle3Y > 180)
	{
		s2boneangle3Y=s2boneangle3Y - 180 - 180;
	}
	if (s2boneangle3Y < -180)
	{
		s2boneangle3Y=s2boneangle3Y + 180 + 180;
	}
	if (s3boneangle1R > 180)
	{
		s3boneangle1R=s3boneangle1R - 180 - 180;
	}
	if (s3boneangle1R < -180)
	{
		s3boneangle1R=s3boneangle1R + 180 + 180;
	}
	if (s3boneangle1P > 180)
	{
		s3boneangle1P=s3boneangle1P - 180 - 180;
	}
	if (s3boneangle1P < -180)
	{
		s3boneangle1P=s3boneangle1P + 180 + 180;
	}
	if (s3boneangle1Y > 180)
	{
		s3boneangle1Y=s3boneangle1Y - 180 - 180;
	}
	if (s3boneangle1Y < -180)
	{
		s3boneangle1Y=s3boneangle1Y + 180 + 180;
	}
	if (s3boneangle2R > 180)
	{
		s3boneangle2R=s3boneangle2R - 180 - 180;
	}
	if (s3boneangle2R < -180)
	{
		s3boneangle2R=s3boneangle2R + 180 + 180;
	}
	if (s3boneangle2P > 180)
	{
		s3boneangle2P=s3boneangle2P - 180 - 180;
	}
	if (s3boneangle2P < -180)
	{
		s3boneangle2P=s3boneangle2P + 180 + 180;
	}
	if (s3boneangle2Y > 180)
	{
		s3boneangle2Y=s3boneangle2Y - 180 - 180;
	}
	if (s3boneangle2Y < -180)
	{
		s3boneangle2Y=s3boneangle2Y + 180 + 180;
	}
	if (s3boneangle3R > 180)
	{
		s3boneangle3R=s3boneangle3R - 180 - 180;
	}
	if (s3boneangle3R < -180)
	{
		s3boneangle3R=s3boneangle3R + 180 + 180;
	}
	if (s3boneangle3P > 180)
	{
		s3boneangle3P=s3boneangle3P - 180 - 180;
	}
	if (s3boneangle3P < -180)
	{
		s3boneangle3P=s3boneangle3P + 180 + 180;
	}
	if (s3boneangle3Y > 180)
	{
		s3boneangle3Y=s3boneangle3Y - 180 - 180;
	}
	if (s3boneangle3Y < -180)
	{
		s3boneangle3Y=s3boneangle3Y + 180 + 180;
	}
	Rotator.Roll=s1boneangle1R * multiplier;
	Rotator.Pitch=s1boneangle1P * multiplier;
	Rotator.Yaw=s1boneangle1Y * multiplier;
	//SetBoneRotation('spine01',Rotator,0,1);
	Rotator.Roll=s1boneangle2R * multiplier;
	Rotator.Pitch=s1boneangle2P * multiplier;
	Rotator.Yaw=s1boneangle2Y * multiplier;
	//SetBoneRotation('Spine02',Rotator,0,1);
	Rotator.Roll=s1boneangle3R * multiplier;
	Rotator.Pitch=s1boneangle3P * multiplier;
	Rotator.Yaw=s1boneangle3Y * multiplier;
	//SetBoneRotation('head',Rotator,0,1);
	Rotator.Roll=s2boneangle1R * multiplier;
	Rotator.Pitch=s2boneangle1P * multiplier;
	Rotator.Yaw=s2boneangle1Y * multiplier;
	//SetBoneRotation('RArmUp',Rotator,0,1);
	Rotator.Roll=s2boneangle2R * multiplier;
	Rotator.Pitch=s2boneangle2P * multiplier;
	Rotator.Yaw=s2boneangle2Y * multiplier;
	//SetBoneRotation('RArmLow',Rotator,0,1);
	Rotator.Roll=s2boneangle3R * multiplier;
	Rotator.Pitch=s2boneangle3P * multiplier;
	Rotator.Yaw=s2boneangle3Y * multiplier;
	//SetBoneRotation('RHand',Rotator,0,1);
	Rotator.Roll=s3boneangle1R * multiplier;
	Rotator.Pitch=s3boneangle1P * multiplier;
	Rotator.Yaw=s3boneangle1Y * multiplier;
	//SetBoneRotation('LArmUp',Rotator,0,1);
	Rotator.Roll=s3boneangle2R * multiplier;
	Rotator.Pitch=s3boneangle2P * multiplier;
	Rotator.Yaw=s3boneangle2Y * multiplier;
	//SetBoneRotation('LArmLow',Rotator,0,1);
	Rotator.Roll=s3boneangle3R * multiplier;
	Rotator.Pitch=s3boneangle3P * multiplier;
	Rotator.Yaw=s3boneangle3Y * multiplier;
	//SetBoneRotation('LHand',Rotator,0,1);
}
void AAGP_Pawn::AAGP_Pawn::PlayBoneAnim(FName BoneName)
{
	/*
	boneAnimFrame=0;
	boneAnimDirection=True;
	boneAnimComplete=False;
	boneAnimName=BoneName;
	rotTorsoFire.Yaw=0;
	rotTorsoFire.Pitch=0;
	if (Controller != None)
	{
		rotTorsoFire.Roll=Controller.Rotation.Pitch;
	}
	else
	{
		rotTorsoFire.Roll=AnimPitch;
	}
	*/
}
void AAGP_Pawn::UpdateBoneAnim()
{
	/*
	if (boneAnimComplete)
	{
		return;
	}
	if (boneAnimFrame < 5 && boneAnimDirection)
	{
		rotTorsoFire.Pitch=rotTorsoFire.Pitch - 200;
		rotTorsoFire.Roll=rotTorsoFire.Roll + 400;
		boneAnimFrame ++;
	}
	else
	{
		boneAnimFrame --;
		boneAnimDirection=False;
		rotTorsoFire.Pitch=rotTorsoFire.Pitch + 200;
		rotTorsoFire.Roll=rotTorsoFire.Roll - 400;
		if (boneAnimFrame < 1)
		{
			boneAnimComplete=True;
		}
	}
	rotTorsoFire.Yaw=0;
	SetBoneRotation(boneAnimName,rotTorsoFire,0,1);
	*/
}
void AAGP_Pawn::ShouldDrawCrosshair()
{
	/*
	if (Controller == None || Controller.IsInState('BaseSpectating'))
	{
		return false;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		if (bForceDrawCrosshair || Controller.IsInState('MedicTraining_TakingExam') || Controller.IsInState('MedicTraining_TakingExam2') || Controller.IsInState('SFTraining_TakingExam'))
		{
			return true;
		}
	}
	if (IsBusy() || bIsSprinting || Weapon == None || bIsDead)
	{
		return false;
	}
	return Weapon.ShouldDrawCrosshair() && Controller.ShouldRenderWeapon();
	*/
}
/*
void AAGP_Pawn::StopDriving (Vehicle V)
{
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.Destroy();
		BoneAuxCyl=None;
		SetupBoneAuxCylinder();
	}
	StopDriving(V);
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != None && Controller.IsA('PlayerController'))
	{
		PlayerController(Controller).LockPlayer(False,False);
	}
}
*/
void AAGP_Pawn::AnimEnd(int32 Channel)
{
	/*
	if (_AnimationMonitor != None)
	{
		_AnimationMonitor.AnimEnd(Channel);
		return;
	}
	if (Channel == 13)
	{
		FullBodyAnimComplete();
	}
	else
	{
		if (Channel == 15)
		{
			if (UpperBodyAnim == 7 || UpperBodyAnim == 8)
			{
				UpperBodyAnim=1;
			}
			else
			{
				if (Role > 2)
				{
					if (UpperBodyAnim != 9 && UpperBodyAnim != 12)
					{
						UpperBodyAnimComplete();
					}
				}
				else
				{
					PredictUpperBodyAnim();
				}
			}
			ChangeAnimation();
		}
	}
	if (Channel == 13 || Channel == 15 && ! IsAnimating(13))
	{
		if (isDead())
		{
			GotoState('Dying');
		}
		else
		{
			GotoState('None');
		}
	}
	*/
}

/*
 // ======================================================================================
 // AGP function - PredictUpperBodyAnim
 // Used for SimulatedProxy pawns to help predict the next animation sequence to blend to
 // This helps prevent animation popping over a lagged network.
 // last modified by:  superville 06/03/01
 // ======================================================================================
*/

void AAGP_Pawn::PredictUpperBodyAnim()
{

	switch (UpperBodyAnim)
	{
		// Predict that the pawn came from a position with or without a gun and will go back to that position
		// since gun swaps aren't allowed during hand signals
		case EUpperBodyAnim::UBANIM_HAND_MoveOut:
		case EUpperBodyAnim::UBANIM_HAND_Hold:
		case EUpperBodyAnim::UBANIM_HAND_TakeCover:
		case EUpperBodyAnim::UBANIM_HAND_PointFwd:
		case EUpperBodyAnim::UBANIM_HAND_Ready:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTime:
		case EUpperBodyAnim::UBANIM_HAND_Affirm:
		case EUpperBodyAnim::UBANIM_HAND_Neg:

		case EUpperBodyAnim::UBANIM_HAND_MoveOutGn:
		case EUpperBodyAnim::UBANIM_HAND_HoldGn:
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverGn:
		case EUpperBodyAnim::UBANIM_HAND_PointFwdGn:
		case EUpperBodyAnim::UBANIM_HAND_ReadyGn:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeGn:
		case EUpperBodyAnim::UBANIM_HAND_AffirmGn:
		case EUpperBodyAnim::UBANIM_HAND_NegGn:

		case EUpperBodyAnim::UBANIM_HAND_MoveOutSm:
		case EUpperBodyAnim::UBANIM_HAND_HoldSm:
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverSm:
		case EUpperBodyAnim::UBANIM_HAND_PointFwdSm:
		case EUpperBodyAnim::UBANIM_HAND_ReadySm:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeSm:
		case EUpperBodyAnim::UBANIM_HAND_AffirmSm:
		case EUpperBodyAnim::UBANIM_HAND_NegSm:
			UpperBodyAnim = LastUpperBodyAnim;
			return;

			// Predict that if a pawn is raising a weapon it will be a large weapon
		case EUpperBodyAnim::UBANIM_WEAP_RaiseLg:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Large;
			return;

			// Predict that if the player is reloading, they will play the same idle anim they were playing before
		case EUpperBodyAnim::UBANIM_WEAP_Reload:
			UpperBodyAnim = LastUpperBodyAnim;
			return;

			// Predict that if a pawn is lowering a weapon it will have empty hands after
			//agp:aafa [mwd] javelin animation code
		case EUpperBodyAnim::UBANIM_Jav_LowerJav:
		case EUpperBodyAnim::UBANIM_WEAP_LowerLg:
		case EUpperBodyAnim::UBANIM_GREN_LowerGn:
		case EUpperBodyAnim::UBANIM_BINOC_LowerBn:
		case EUpperBodyAnim::UBANIM_RPG_LowerRPG:
		case EUpperBodyAnim::UBANIM_RPG_LowerRPG_NS:
		case EUpperBodyAnim::UBANIM_AT4_LowerAT4:
		case EUpperBodyAnim::UBANIM_BDM_LowerBDM:
		case EUpperBodyAnim::UBANIM_PISTOL_Lower:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Empty;
			return;

		case EUpperBodyAnim::UBANIM_GREN_Throwing_Over:
		case EUpperBodyAnim::UBANIM_GREN_Throwing_Under:
			if (LastUpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large)
				UpperBodyAnim = EUpperBodyAnim::UBANIM_WEAP_RaiseLg;
			else
				UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Empty;
			return;

			// Predict that if a pawn is raising a grenade it will be a greande in his hands
		case EUpperBodyAnim::UBANIM_GREN_RaiseGn:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_GREN_Ready;
			return;

			// Predict that if a pawn is raising binoculars or lowering from zoom it will be binocs ready
		case EUpperBodyAnim::UBANIM_BINOC_RaiseBn:
		case EUpperBodyAnim::UBANIM_BINOC_LowerZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_BINOC_Ready;
			return;

			// Predict that if a pawn is raising to zoom it will be binocs zoom
		case EUpperBodyAnim::UBANIM_BINOC_RaiseZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			return;

			//agp:aafa [mwd] javelin animation code
			// Predict that if a pawn is raising the Javelin it will be Ready RPG
		case EUpperBodyAnim::UBANIM_Jav_RaiseJav:
		case EUpperBodyAnim::UBANIM_Jav_LowerZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_Jav_Ready;
			return;

			//agp:aafa [mwd] javelin animation code
			// Predict that if a pawn is raising to zoom it will be binocs zoom
		case EUpperBodyAnim::UBANIM_Jav_RaiseZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_Jav_ReadyZoom;
			return;

			// Predict that if a pawn is raising the RPG it will be Ready RPG
		case EUpperBodyAnim::UBANIM_RPG_RaiseRPG:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_RPG_Ready;
			return;

			// Predict that if a pawn is raising the non swapping RPG it will be Ready RPG non swapping
		case EUpperBodyAnim::UBANIM_RPG_RaiseRPG_NS:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_RPG_Ready_NS;
			return;

			// Predict that if a pawn is raising the AT4 it will be Ready AT4
		case EUpperBodyAnim::UBANIM_AT4_RaiseAT4:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_AT4_Ready;
			return;

			// Predict that if a pawn is raising the BDM it will be Ready BDM but uses the AT4 ready.
		case EUpperBodyAnim::UBANIM_BDM_RaiseBDM:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_AT4_Ready;
			return;

			// Predict that if a pawn is raising a weapon it will be a pistol
		case EUpperBodyAnim::UBANIM_PISTOL_Raise:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_PISTOL_Ready;
			return;
	}

}
void AAGP_Pawn::PlayRolling(EFullBodyAnim Anim)
{
	/*
	EnableChannelNotify(13,1);
	AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
	bTransitionAnim=true;
	if (Weapon != NULL)
	{
		Weapon->TempLowerWeapon();
	}
	if (FullBodyAnim == 2)
	{
		if (UpperBodyAnim == 2)
		{
			PlayAnim('RollLtLg',1.3,0,13);
		}
		else
		{
			if (UpperBodyAnim == 39)
			{
				PlayAnim('RollLtSm',1.3,0,13);
			}
			else
			{
				PlayAnim('RollLtGn',1.3,0,13);
			}
		}
	}
	else
	{
		if (UpperBodyAnim == 2)
		{
			PlayAnim('RollRtLg',1.3,0,13);
		}
		else
		{
			if (UpperBodyAnim == 39)
			{
				PlayAnim('RollRtSm',1.3,0,13);
			}
			else
			{
				PlayAnim('RollRtGn',1.3,0,13);
			}
		}
	}
	*/
}
void AAGP_Pawn::PlayProningSound()
{
}
void AAGP_Pawn::StartSprint()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"SPRINTMODE,True");
	}
	if (Weapon != None)
	{
		if (Weapon.IsInState('BusyChangingFireMode'))
		{
			if (HumanController(Controller) != None)
			{
				HumanController(Controller).ClientMessage("You are too busy adjusting your weapon to sprint.");
			}
			return;
		}
		Weapon.TempLowerWeapon();
	}
	SetWalking(False);
	bIsSprinting=True;
	ResetLean();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Start Sprint");
	}
	*/
}
void AAGP_Pawn::StopSprint()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"SPRINTMODE,False");
	}
	bIsSprinting=False;
	bWantsToSprint=False;
	SetWalking(bIsWalking);
	if (Weapon != None && Physics != 11 && ! IsInState('BusyProning'))
	{
		AGP_Weapon(Weapon).ForceTempRaiseWeapon();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Stop Sprint");
	}
	*/
}
void AAGP_Pawn::ResetLean()
{
	/*
	local byte LastDir;
	LastDir=LeanDirection;
	LeanDirection=1;
	if (IsHumanControlled())
	{
		HumanController(Controller).bLeanRight=0;
		HumanController(Controller).bLeanLeft=0;
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
void AAGP_Pawn::LeanLeft(bool bFullLeft)
{
	/*
	local int LastDir;
	LastDir=LeanDirection;
	if (bFullLeft)
	{
		LeanDirection=0;
	}
	else
	{
		LeanDirection=Max(LeanDirection + -1,0);
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
void AAGP_Pawn::LeanRight(bool bFullRight)
{
	/*
	local int LastDir;
	LastDir=LeanDirection;
	if (bFullRight)
	{
		LeanDirection=2;
	}
	else
	{
		LeanDirection=Min(LeanDirection + 1,2);
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
bool AAGP_Pawn::CanLean()
{
	if (bIsDead || bLockMovement || bTransitionAnim || bIsProne || IsSupported() || Weapon != nullptr && !Cast<AWeapon>(Weapon)->CanLean())
	{
		return false;
	}
	return true;
}
bool AAGP_Pawn::CanLeanInAnimationState()
{
	return false;
}
bool AAGP_Pawn::CanHandSignal()
{
	/*
	if (IsBusy() || bIsProne || IsInState('Dying') || bIsDead || Weapon != None && Weapon.IsBusy())
	{
		return false;
	}
	*/
	return true;
}

bool AAGP_Pawn::CanCommo()
{
	/*
	if (IsInState('Dying'))
	{
		return false;
	}
	*/
	return true;
}

void AAGP_Pawn::CanJump()
{
	/*
	if (IsSupported() && Weapon.IsBusy() || bLockMovement && ! IsSupported() || bUsingObjective || UpperBodyAnim == 11 || UpperBodyAnim == 5 || UpperBodyAnim == 24 || UpperBodyAnim == 28 || UpperBodyAnim == 32 || UpperBodyAnim == 36 || UpperBodyAnim == 38 || UpperBodyAnim == 66 || UpperBodyAnim == 73 || FullBodyAnim != 0)
	{
		return false;
	}
	return CanJump();
	*/
}

void AAGP_Pawn::CanSprint()
{
	/*
	if (! fInitialAnimationComplete && Weapon != None)
	{
		ClientMessage("You cannot sprint while readying your weapon.");
		DebugLog(DEBUG_Inv,"AGP_Pawn::CanSprint() - initial animation not complete");
		return false;
	}
	DebugLog(DEBUG_Inv,"Can Sprint Pawn.IsBusy: " $ IsBusy() $ ", Weapon CAn Sprint: " $ Weapon.CanSprint() $ " Weapon state: " $ Weapon.GetStateName());
	return fInitialAnimationComplete || Weapon == None && ! IsBusy() && Weapon == None || Weapon.CanSprint();
	*/
}

void AAGP_Pawn::DoJump(bool bUpdating)
{
	/*
	local float fSlowDown;
	if (! bIsCrouched && ! bWantsToCrouch && ! bIsProne && ! bWantsToProne && Physics == 1 || Physics == 11 && fHopTimer > 0)
	{
		if (Role == 4)
		{
			if (Level.Game != None && Level.Game.GameDifficulty > 0)
			{
				MakeNoise(0.1 * Level.Game.GameDifficulty);
			}
			if (bCountJumps && Inventory != None)
			{
				Inventory.OwnerEvent('Jumped');
			}
		}
		if (Physics == 11)
		{
			Velocity.Z=0;
		}
		else
		{
			if (bIsWalking)
			{
				Velocity.Z=Default.JumpZ;
			}
			else
			{
				Velocity.Z=JumpZ;
			}
		}
		if (Base != None && ! Base.bWorldGeometry)
		{
			Velocity.Z += Base.Velocity.Z;
		}
		fSlowDown=fHopTimer / 3;
		fSlowDown=FClamp(fSlowDown,0,1);
		fHopTimer -= 2;
		Switch(GetHealthCondition())
		{
			case 2:
			fSlowDown *= 0.6;
			break;
			case 1:
			fSlowDown *= 0.8;
			break;
			default:
			fSlowDown *= 1;
			break;
		}
		Velocity.X *= fSlowDown;
		Velocity.Y *= fSlowDown;
		if (fSlowDown < 0.4)
		{
			Velocity.Z *= 0.75;
		}
		SetPhysics(2);
		CombatEffectivenessEvent(5);
		return true;
	}
	return false;
	*/
}

bool AAGP_Pawn::CanChangePosture(bool bForce, bool bForceUnzoom)
{
	/*
	EnableChannelNotify(13,1);
	if (HumanController(Controller) != None && HumanController(Controller).GameReplicationInfo.iDelayedStartTimeRemaining > 0)
	{
		return false;
	}
	if (! bForce)
	{
		if (Physics == 2 || FullBodyAnim != 0 || bLockMovement && ! IsSupported() || IsSupported() && Weapon.IsBusy())
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
			{
				DebugLog(DEBUG_Anim,"Can't change posture - Physics" @ Physics @ "FullBodyAnim" @ FullBodyAnim @ "Lock/Support" @ bLockMovement @ IsSupported());
			}
			return false;
		}
	}
	if (Weapon != None)
	{
		if (IsSupported())
		{
			SetSupported(False,True);
		}
		else
		{
			if (bForceUnzoom)
			{
				Weapon.ForceUnzoom();
			}
		}
		Weapon.StopCrawling();
	}
	return true;
	*/

	return true;     //FAKE     /ELiZ
}
bool AAGP_Pawn::CanCombatRoll(bool bActual)
{
	/*
	if (! bIsProne || Physics == 2 || FullBodyAnim != 0 || bLockMovement || IsSupported() || IsInState('BusyDrawingBack') || ! _InvAltShoulder.isEmpty() || Weapon != None && ! Weapon.CanCombatRoll(bActual))
	{
		return false;
	}
	return true;
	*/
	return true;      //FAKE  /ELiZ
}
void AAGP_Pawn::ShouldStand(bool bForce)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Stand");
	}
	if (bIsProne)
	{
		if (! CanChangePosture(bForce,True))
		{
			return;
		}
	}
	else
	{
		if (! CanChangePosture(bForce))
		{
			return;
		}
	}
	bWantsToCrouch=False;
	bWantsToProne=False;
	*/
}
void AAGP_Pawn::ShouldCrouch(bool Crouch)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"ShouldCrouch" @ Crouch);
	}
	*/


	
	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1Y += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2Y += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3Y += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1Y += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2Y += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3Y += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1Y += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2Y += 2.5;
										}
										else
										{
											s3boneangle3Y += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1Y -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2Y -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3Y -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1Y -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2Y -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3Y -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1Y -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2Y -= 2.5;
										}
										else
										{
											s3boneangle3Y -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
	if (bIsProne)
	{
		if (! CanChangePosture(false,true))
		{
			return;
		}
	}
	else
	{
		if (! CanChangePosture(false, false))
		{
			return;
		}
	}
	ShouldCrouch(Crouch);
	if (Crouch)
	{
		bWantsToProne=false;
	}
}
void AAGP_Pawn::EndCrouch(float HeightAdjust)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"CROUCHMODE,False");
	}
	EndCrouch(HeightAdjust);
	OldZ += HeightAdjust;
	bCrawler=Default.bCrawler;
	ShouldStand(True);
	if (FrontAuxCyl != None)
	{
		FrontAuxCyl.SetAuxCylinder(False);
	}
	if (BackAuxCyl != None)
	{
		BackAuxCyl.SetAuxCylinder(False);
	}
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	*/
}
void AAGP_Pawn::StartCrouch(float HeightAdjust)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"CROUCHMODE,True");
	}
	EyeHeight += HeightAdjust;
	OldZ -= HeightAdjust;
	BaseEyeHeight=CrouchEyeHeight;
	bCrawler=Default.bCrawler;
	if (FrontAuxCyl != None)
	{
		FrontAuxCyl.SetAuxCylinder(False);
	}
	if (BackAuxCyl != None)
	{
		BackAuxCyl.SetAuxCylinder(False);
	}
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	if (bIsProne)
	{
		bInProneTransition=True;
	}
	*/
}
void AAGP_Pawn::ShouldProne(bool Prone)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"ShouldProne" @ Prone);
	}
	*/

	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1P += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2P += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3P += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1P += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2P += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3P += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1P += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2P += 2.5;
										}
										else
										{
											s3boneangle3P += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1P -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2P -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3P -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1P -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2P -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3P -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1P -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2P -= 2.5;
										}
										else
										{
											s3boneangle3P -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
	if (! CanChangePosture(false,true))
	{
		return;
	}
	bWantsToProne=Prone;
	if (Prone)
	{
		bWantsToCrouch=false;
	}
}

void AAGP_Pawn::EndProne(float HeightAdjust)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"PRONEMODE,False");
	}
	EyeHeight -= HeightAdjust;
	OldZ += HeightAdjust;
	BaseEyeHeight=Default.BaseEyeHeight;
	bCrawler=Default.bCrawler;
	if (FrontAuxCyl != None)
	{
		FrontAuxCyl.SetAuxCylinder(False);
	}
	if (BackAuxCyl != None)
	{
		BackAuxCyl.SetAuxCylinder(False);
	}
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	ShouldStand(True);
	bInProneTransition=True;
	*/
}

void AAGP_Pawn::HidePawn(bool bNewHidePawn)
{
	/*
	bHidePawn=bNewHidePawn;
	bHidden=bHidePawn;
	OnlyAffectPawns(bHidePawn);
	bBlockZeroExtentTraces=! bNewHidePawn;
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.bProjTarget=! bNewHidePawn;
		BoneAuxCyl.bBlockBulletTraces=! bNewHidePawn;
		BoneAuxCyl.SetCollision(! bNewHidePawn,False,False);
	}
	*/
}

void AAGP_Pawn::StartProne(float HeightAdjust)
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"PRONEMODE,True");
	}
	if (bIsSprinting)
	{
		Dive3p(7);
	}
	EyeHeight += HeightAdjust;
	OldZ -= HeightAdjust;
	BaseEyeHeight=ProneEyeHeight;
	bCrawler=True;
	if (FrontAuxCyl != None)
	{
		FrontAuxCyl.SetAuxCylinder(True);
	}
	if (BackAuxCyl != None)
	{
		BackAuxCyl.SetAuxCylinder(True);
	}
	if (BoneAuxCyl != None)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	*/
}

bool AAGP_Pawn::IsSupported()
{
	if (Weapon == nullptr)
	{
		return false;
	}
	return Cast<AWeapon>(Weapon)->IsSupported();
}

bool AAGP_Pawn::IsZoomed()
{
	if (Weapon != nullptr)
	{
		bPawnZoomed= Cast<AWeapon>(Weapon)->IsZoomed();
	}
	return bPawnZoomed;
}

void AAGP_Pawn::SetZoomed(bool bNewZoomed)
{
	bPawnZoomed=bNewZoomed;
}

void AAGP_Pawn::NPCSetWeaponZoom(bool bZoomWeapon)
{
	if (Weapon == nullptr)
	{
		return;
	}
	bPawnZoomed=bZoomWeapon;
	Cast<AAGP_Weapon>(Weapon)->DoZoom(bZoomWeapon);
	if (bZoomWeapon)
	{
		if (Weapon->IsA(AItem_Binoculars::StaticClass()))
		{
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			//PlayMoving();
		}
	}
	else
	{
		if (Weapon->IsA(AItem_Binoculars::StaticClass()))
		{
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_Ready;
			//PlayMoving();
		}
	}
}

float AAGP_Pawn::GetZoomMultiplier()
{
	if (Weapon == nullptr || ! IsZoomed())
	{
		return 1.0f;
	}
	return Cast<AWeapon>(Weapon)->GetZoomMultiplier();
}

void AAGP_Pawn::SetSupported(bool newSupported, bool bForce)
{
	/*
	local FRotator CurrentRot;
	if (newSupported == IsSupported())
	{
		return newSupported;
	}
	if (newSupported && ! bForce && ! SupportablePosition())
	{
		LimitRotation(False);
		if (Weapon != None)
		{
			Weapon.FailedSupported();
		}
		if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
		{
			DebugLog(DEBUG_Anim,"FAILED SUPPORTED: Not a supportable position");
		}
		return false;
	}
	if (newSupported)
	{
		ResetLean();
		rBaseRotation.Pitch=FloorRotation.Pitch;
		rBaseRotation.Yaw=Rotation.Yaw;
		rBaseRotation.Roll=0;
		rRotationLimits=Weapon.rSupportedLimit;
		CurrentRot=GetViewRotation();
		if (! RestrictRotation(CurrentRot,rBaseRotation,rRotationLimits))
		{
			if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
			{
				DebugLog(DEBUG_Anim,"FAILED SUPPORTED: Rotation Limit");
			}
			return false;
		}
	}
	CombatEffectivenessEvent(8);
	Weapon.SetSupported(newSupported);
	return true;
	*/
}

bool AAGP_Pawn::SupportablePosition()
{
	return bIsProne && !IsBusy() && Weapon != nullptr && !Cast<AWeapon>(Weapon)->IsBusy() && Cast<AWeapon>(Weapon)->bCanSupport;
}

bool AAGP_Pawn::OverRotated(FRotator Desired, FRotator Actual)
{
	return true;
}

void AAGP_Pawn::UpdateParachute(int32 Type)
{
	if (Type == 4)
	{
		bParachuteOutfit=false;
		RemoveParachuteSkins();
		//Log(Self $ "." $ GetStateName() $ ".UpdateParachute() - Weapon now: " $ Weapon);
		SwapHands();
	}
	if (Weapon != nullptr && Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		switch(Type)
		{
			case 0:
			case 3:
			case 4:
				break;
			default:
				SetWalking(true);
		}
		Cast<AWeapon>(Weapon)->NotifyNewParachuteState(Type);
	}
	else
	{
		//DebugLog(DEBUG_Warn,Self @ "AGP_Pawn::UpdateParachute()	No parachute! Weapon=" $ Weapon);
	}
}

void AAGP_Pawn::FlareParachute()
{
	/*
	if (AGP_PlayerStart(Controller.StartSpot).bNoPLFDamage)
	{
		return;
	}
	UpdateParachute(5);
	*/
}

bool AAGP_Pawn::HasParachute()
{
	return bParachuteOutfit;
}

void AAGP_Pawn::CheckParachuteLandingFall()
{
	/*
	local int Damage;
	local FVector View2D;
	local FVector Vel2D;
	local float ViewDotVel;
	local float ViewDotZ;
	local float VelSize2D;
	if (AGP_PlayerStart(Controller.StartSpot).bNoPLFDamage)
	{
		return 0;
	}
	View2D= Vector(Rotation);
	Vel2D=Velocity;
	View2D.Z=0;
	Vel2D.Z=0;
	VelSize2D=VSize(Vel2D);
	View2D=Normal(View2D);
	Vel2D=Normal(Vel2D);
	if (Level.debugParachute)
	{
		ViewDotVel=View2D Dot Vel2D;
		ViewDotZ=View2D Dot vect(0 0 1);
		if (Damage == 0)
		{
			ScreenPrint("PLF Successful: ViewDotVel = " @ ViewDotVel @ "(must be > 0.90631) - ViewDotZ =" @ ViewDotZ @ "(must be > 0.0)");
		}
		else
		{
			ScreenPrint("PLF Failed:	  ViewDotVel = " @ ViewDotVel @ "(must be > 0.90631) - ViewDotZ =" @ ViewDotZ @ "(must be > 0.0)");
		}
	}
	return Damage;
	*/
}
void AAGP_Pawn::ParachuteLanding(bool bFailed)
{
	//DebugLog(DEBUG_Anim,"AGP_PAWN::ParachuteLanding" @ bFailed);
	UpdateParachute(3);
	if (bFailed)
	{
		PLF3p(EFullBodyAnim::FBANIM_PLF_Fail);
	}
	else
	{
		PLF3p(EFullBodyAnim::FBANIM_PLF_Pass);
	}
}
void AAGP_Pawn::PlayPLF()
{
	/*
	if (_AnimationMonitor == None)
	{
		EnableChannelNotify(13,1);
		AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		if (bIsDead)
		{
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
			{
				SetDeathAnim(24);
				PlayAnim('PLFDead',1,0,13);
			}
			else
			{
				SetDeathAnim(25);
				PlayAnim('PLF',1,0,13);
			}
		}
		else
		{
			if (FullBodyAnim == 6)
			{
				PlayAnim('PLF',1,0,13);
				if (IsHumanControlled() && GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					PlayerController(Controller).DoFade(True,False,2);
				}
			}
			else
			{
				PlayAnim('PLF',1,0,13);
			}
		}
		PlaySound(sParaLanding[Rand(sParaLanding.Length)],0,1,,,,False);
		bTransitionAnim=True;
		LockMovement(True);
		Velocity=vect(0 0 0);
		Acceleration=vect(0 0 0);
	}
	*/
}

void AAGP_Pawn::ChangeAnimation()
{
	/*
	if (Controller != None && Controller.IsInState('Manning_Turret'))
	{
		return;
	}
	if (isDead())
	{
		if (! IsInState('Dying'))
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::ChangeAnimation() Pawn should have been in state Dying! " @ Self @ GetStateName());
			GotoState('Dying');
		}
		return;
	}
	if (Controller != None && Controller.bControlAnimations)
	{
		return;
	}
	if (bClearSplitAnims)
	{
		ClearSplitAnims();
		PlayWaiting();
	}
	else
	{
		if (bWasWalking == bIsWalking)
		{
			PlayWaiting();
		}
	}
	PlayMoving();
	bWasCrouched=bIsCrouched;
	bWasProne=bIsProne;
	bWasWalking=bIsWalking;
	bWasSprinting=bIsSprinting;
	*/
}

void AAGP_Pawn::ClearSplitAnims()
{
	/*
	AnimBlendToAlpha(15,0,0.25);
	AnimBlendToAlpha(15 - 1,0,0.25);
	EnableChannelNotify(15,0);
	EnableChannelNotify(15 - 1,0);
	bClearSplitAnims=False;
	*/
}

void AAGP_Pawn::UpperBodyAnimComplete()
{
	if (Weapon != NULL)
	{
		UpperBodyAnim = Cast<AAGP_Weapon>(Weapon)->GetUpperBodyReadyAnim();
	}
	else
	{
		UpperBodyAnim= EUpperBodyAnim::UBANIM_NONE_Empty;
	}
	//PlayMoving();
}

void AAGP_Pawn::FullBodyAnimComplete()
{
	/*
	FullBodyAnim=0;
	PlayMoving();
	*/
}

void AAGP_Pawn::HandSignalSet(FName h_name)
{
	/*
	Switch(h_name)
	{
		case 'SgnlMoveOutLg':
		if (UpperBodyAnim <= 2)
		{
			UpperBodyAnim=41;
			break;
		}
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=57;
			break;
		}
		UpperBodyAnim=49;
	}
	GOTO JL02A5;
	case 'SgnlHoldLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=42;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=58;
		}
		else
		{
			UpperBodyAnim=50;
		}
	}
	GOTO JL02A5;
	case 'SgnlTakeCoverLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=43;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=59;
		}
		else
		{
			UpperBodyAnim=51;
		}
	}
	GOTO JL02A5;
	case 'SgnlPointFwdLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=44;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=60;
		}
		else
		{
			UpperBodyAnim=52;
		}
	}
	GOTO JL02A5;
	case 'SgnlReadyLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=45;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=61;
		}
		else
		{
			UpperBodyAnim=53;
		}
	}
	GOTO JL02A5;
	case 'SgnlDoubleTimeLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=46;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=62;
		}
		else
		{
			UpperBodyAnim=54;
		}
	}
	GOTO JL02A5;
	case 'SgnlAffirmLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=47;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=63;
		}
		else
		{
			UpperBodyAnim=55;
		}
	}
	GOTO JL02A5;
	case 'SgnlNegLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=48;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=64;
		}
		else
		{
			UpperBodyAnim=56;
		}
	}
	GOTO JL02A5;
	default:
	DebugLog(DEBUG_Warn,"AGP_Pawn::HandSignalSet()	Unknown Name " $ h_name);
	if (Role > 2)
	{
		UpperBodyAnimComplete();
	}
	GOTO JL02A5;
JL02A5:

	*/
}

FName AAGP_Pawn::HandSignalGet()
{
	switch(UpperBodyAnim)
	{
		case EUpperBodyAnim::UBANIM_HAND_MoveOut:		return "SgnlMoveOutLg";
		case EUpperBodyAnim::UBANIM_HAND_Hold:			return "SgnlHoldLg";
		case EUpperBodyAnim::UBANIM_HAND_TakeCover:		return "SgnlTakeCoverLg";
		case EUpperBodyAnim::UBANIM_HAND_PointFwd:		return "SgnlPointFwdLg";
		case EUpperBodyAnim::UBANIM_HAND_Ready:			return "SgnlReadyLg";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTime:	return "SgnlDoubleTimeLg";
		case EUpperBodyAnim::UBANIM_HAND_Affirm:		return "SgnlAffirmLg";
		case EUpperBodyAnim::UBANIM_HAND_Neg:			return "SgnlNegLg";

		case EUpperBodyAnim::UBANIM_HAND_MoveOutGn:		return "SgnlMoveOutGn";
		case EUpperBodyAnim::UBANIM_HAND_HoldGn:		return "SgnlHoldGn";
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverGn:	return "SgnlTakeCoverGn";
		case EUpperBodyAnim::UBANIM_HAND_PointFwdGn:	return "SgnlPointFwdGn";
		case EUpperBodyAnim::UBANIM_HAND_ReadyGn:		return "SgnlReadyGn";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeGn:	return "SgnlDoubleTimeGn";
		case EUpperBodyAnim::UBANIM_HAND_AffirmGn:		return "SgnlAffirmGn";
		case EUpperBodyAnim::UBANIM_HAND_NegGn:			return "SgnlNegGn";

		case EUpperBodyAnim::UBANIM_HAND_MoveOutSm:		return "SgnlMoveOutSm";
		case EUpperBodyAnim::UBANIM_HAND_HoldSm:		return "SgnlHoldSm";
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverSm:	return "SgnlTakeCoverSm";
		case EUpperBodyAnim::UBANIM_HAND_PointFwdSm:	return "SgnlPointFwdSm";
		case EUpperBodyAnim::UBANIM_HAND_ReadySm:		return "SgnlReadySm";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeSm:	return "SgnlDoubleTimeSm";
		case EUpperBodyAnim::UBANIM_HAND_AffirmSm:		return "SgnlAffirmSm";
		case EUpperBodyAnim::UBANIM_HAND_NegSm:			return "SgnlNegSm";
		default:
			//DebugLog(DEBUG_Warn, "AGP_Pawn::HandSignalGet()	Unknown Index " $UpperBodyAnim);
			return "";
	}
}

void AAGP_Pawn::PlayHandSignalIndex()
{
	//PlayHandSignal(HandSignalGet());
}

void AAGP_Pawn::PlayHandSignal(FName Anim)
{
	/*
	if (! CanHandSignal())
	{
		return;
	}
	commosignalanim=Anim;
	GotoState('BusySignaling');
	*/
}

void AAGP_Pawn::GetWeaponAttachment()
{
	/*
	local BaseWeaponAttachment BWA;
	Switch(Level.NetMode)
	{
		case 1:
		case 0:
		if (Weapon != None && Weapon.ThirdPersonActor != None)
		{
			return BaseWeaponAttachment(Weapon.ThirdPersonActor);
			break;
		}
		return None;
	}
	case 3:
	ForEach AllActors('BaseWeaponAttachment',BWA)
	{
		if (BWA.Instigator == Self && BWA.bCurrentlySelectedAttachment)
		{
			return BWA;
		}
	}
	default:
	return None;
	*/
}

void AAGP_Pawn::PlayJumping()
{
	if (angleEditor)
	{
		if (boneaxisdirection == 1)
		{
			boneaxisdirection=0;
		}
		else
		{
			boneaxisdirection=1;
		}
		return;
	}
	//GotoState('BusyJumping');
}

void AAGP_Pawn::PlayLanding()
{
	//GotoState('BusyLanding');
}

void AAGP_Pawn::PlayFiring(float Rate, FName FiringMode)
{
}

void AAGP_Pawn::ClientPlayBulletWhip(FVector HitLocation, bool bCrack, AActor* aShooter)
{
	/*
	local Actor SoundActor;
	local Sound SoundPtr;
	local int R;
	if (IsHumanControlled() && IsLocallyControlled())
	{
		if (Level.GamePlayMode == 1)
		{
			if (FastTrace(HitLocation,EyePosition()))
			{
				R=Rand(sMilesGraze.Length);
				SoundPtr=sMilesGraze[R];
			}
		}
		else
		{
			if (bCrack)
			{
				R=Rand(sBulletCrack.Length);
				SoundPtr=sBulletCrack[R];
			}
			else
			{
				R=Rand(sBulletWhip.Length);
				SoundPtr=sBulletWhip[R];
			}
		}
		if (SoundPtr != None)
		{
			SoundActor=Spawn(Class'EffectLocation',,,HitLocation);
			SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
			SoundActor.PlaySound(SoundPtr,0,1,,,,False);
		}
	}
	else
	{
		if (Controller != None && Controller.IsA('AgentController'))
		{
			bGotBulletBuzzed=True;
		}
		else
		{
			if (Controller != None && Controller.IsA('AIController'))
			{
				AIController(Controller).NotifyBuzzedByBullet(aShooter);
			}
		}
	}
	*/
}

bool AAGP_Pawn::CanUseWeapon(int32 DesiredAction)
{
	/*
	if (IsBusy() || bWantsToSprint || bIsSprinting || Weapon == None || bIsDead || bUsingObjective)
	{
		return false;
	}
	if (bIsProne != bWantsToProne)
	{
		return false;
	}
	if (Controller != None && Controller.IsA('HumanController'))
	{
		if (HumanController(Controller).bAutoWalkZoom == false)
		{
			if (DesiredAction == 6 && ! FVector::IsZero(Acceleration) && ! bIsWalking)
			{
				return false;
			}
		}
	}
	if (DesiredAction == 3 && bTransitionAnim)
	{
		return false;
	}
	if (Weapon == None)
	{
		return false;
	}
	return Weapon.CanUseWeapon(DesiredAction);
	*/
	return false;     //FAKE   /EliZ
}

bool AAGP_Pawn::IsBusy()
{
	return PressingAction();
}

bool AAGP_Pawn::CanMantle(float Height)
{
	if (Height > fMaxGrabHeight)
	{
		return false;
	}
	return true;
}

bool AAGP_Pawn::PressingAction()
{
	//return Controller != None && HumanController(Controller) != None && HumanController(Controller).bAction != 0;
	return false;				//Not the real one /ELiZ
}

void AAGP_Pawn::AddDefaultInventory()
{
	
}

void AAGP_Pawn::CreateInventoryFromName(FString InventoryClassName, bool bIndigenous)
{
}

void AAGP_Pawn::CreateInventory(AInventory* InventoryClass, bool bRealInventory, bool bIndigenous)
{
}

void AAGP_Pawn::IsValidInventory(AInventory* InventoryClass, AInventory*  out_AltClass)
{
}

void AAGP_Pawn::CalcDrawOffset(AInventory* Inv)
{
	/*
	local FVector DrawOffset;
	local FRotator Rot;
	if (Controller == None)
	{
		return Inv.PlayerViewOffset >> Rotation + EyePosition();
	}
	if (! Inv.bUseInstigatorRotation)
	{
		Rot=GetViewRotation();
	}
	else
	{
		Rot=Rotation;
	}
	DrawOffset=0.9 / Controller.FovAngle * 100 * ModifiedPlayerViewOffset(Inv) >> Rot;
	if (! IsLocallyControlled() || ! Inv.IsA('Weapon'))
	{
		DrawOffset += EyePosition();
	}
	else
	{
		DrawOffset += EyePosition();
		DrawOffset += WeaponBob(Inv.BobDamping);
	}
	return DrawOffset;
	*/
}

void AAGP_Pawn::Reload3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim=Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	GotoState('BusyReloading');
	*/
}

void AAGP_Pawn::GuardWeapon3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim=Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	GotoState('BusyGuardingWeapon');
	*/
}

void AAGP_Pawn::Roll3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyRolling');
}
void AAGP_Pawn::Dive3p(EFullBodyAnim Anim)
{
	FullBodyAnim=Anim;
	//GotoState('BusyDiving');
}
void AAGP_Pawn::Parachute3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyParachuting');
}
void AAGP_Pawn::PLF3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyPLF');
}
void AAGP_Pawn::GrenadeThrow3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim = Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	if (UpperBodyAnim == 12)
	{
		GotoState('BusyDrawing');
		if (Weapon != None)
		{
			Weapon.AttachToPawn(Self);
		}
		AnimateGrenadeMoving();
	}
	else
	{
		if (UpperBodyAnim == 9)
		{
			GotoState('BusyPullingPinGrenade');
		}
		else
		{
			if (UpperBodyAnim == 13 || UpperBodyAnim == 14)
			{
				GotoState('BusyDeployingBreacherUS');
			}
			else
			{
				if (UpperBodyAnim == 15 || UpperBodyAnim == 16)
				{
					GotoState('BusyDeployingBreacherOPFOR');
				}
				else
				{
					if (Weapon != None)
					{
						if (Weapon.IsA('ThrowWeapon'))
						{
							Weapon.DetachFromPawn(Self,True);
						}
					}
					if (UpperBodyAnim == 7 || UpperBodyAnim == 8)
					{
						GotoState('BusyThrowingGrenade');
					}
					else
					{
						GotoState('None');
						ChangeAnimation();
					}
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::WeaponSwap3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim = Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		DebugLog(DEBUG_Anim,"T");
		UpperBodyAnimComplete();
	}
	followmouse=False;
	switch(UpperBodyAnim)
	{
		case 66:
		case 73:
		case 5:
		case 11:
		case 20:
		case 19:
		case 24:
		case 28:
		case 32:
		case 36:
		case 38:
			GotoState('BusyDrawingBack');
			break;
		case 65:
		case 70:
		case 72:
		case 4:
		case 10:
		case 17:
		case 18:
		case 23:
		case 27:
		case 31:
		case 35:
		case 37:
			GotoState('BusyDrawing');
			break;
		default:
			DebugLog(DEBUG_Anim,"AGP_Pawn::WeaponSwap3P() Don't know what to do with UpperBodyAnim " $ UpperBodyAnim);
			break;
	}
	*/
}
void AAGP_Pawn::SkipWeaponAdjustment(EUpperBodyAnim Anim)
{
	switch(Anim)
	{
		case EUpperBodyAnim::UBANIM_BINOC_LowerZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_Ready;
			break;
		case EUpperBodyAnim::UBANIM_BINOC_RaiseZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			break;
		case EUpperBodyAnim::UBANIM_Jav_LowerZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_Jav_Ready;
			break;
		case EUpperBodyAnim::UBANIM_Jav_RaiseZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_Jav_ReadyZoom;
			break;
		default:
			//DebugLog(DEBUG_Warn,"AGP_Pawn::BusyPostureChange::WeaponAdjust3p()	Unexpected Anim " $ Anim);
			break;
	}
	ChangeAnimation();
}
void AAGP_Pawn::WeaponAdjust3p(EUpperBodyAnim Anim)
{
	/*
	local int i;
	for (i=4; i<8; i++)
	{
		if (IsAnimating(i))
		{
			DebugLog(DEBUG_Anim,"AGP_Pawn::WeaponAdjust3p()	Not playing adjustment animation while animating a movement ");
			SkipWeaponAdjustment(Anim);
			return;
		}
	}
	UpperBodyAnim=Anim;
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	followmouse=False;
	PlayWeaponAdjustAnim();
	*/
}
void AAGP_Pawn::PlayWeaponAdjustAnim()
{
	/*
	if (_AnimationMonitor == None)
	{
		EnableChannelNotify(15,1);
		if (bIsProne)
		{
			AnimBlendParams(15,1,0,0,'spine01');
		}
		else
		{
			AnimBlendParams(15,1,0,0,'Spine02');
		}
		Switch(UpperBodyAnim)
		{
			case 18:
			if (bIsProne)
			{
				PlayAnim('PrnBinocsUp',2.2,0.25,15);
				break;
			}
			if (bIsCrouched)
			{
				PlayAnim('CrhBinocsUp',2.2,0.25,15);
				break;
			}
			PlayAnim('StdBinocsUp',2.2,0.25,15);
		}
		case 19:
		if (bIsProne)
		{
			PlayAnim('PrnBinocsDn',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhBinocsDn',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdBinocsDn',2.2,0.25,15);
			}
		}
		case 70:
		if (bIsProne)
		{
			PlayAnim('PrnCLUUp',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhCluUp',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdCluUp',2.2,0.25,15);
			}
		}
		case 71:
		if (bIsProne)
		{
			PlayAnim('PrnCLUDwn',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhCluDwn',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdCluDwn',2.2,0.25,15);
			}
		}
		default:
		DebugLog(DEBUG_Warn,"AGP_Pawn::BusyAdjustingWeapon::BeginState()	Don't know what to do here!");
		bClearSplitAnims=True;
	}
	*/
}
void AAGP_Pawn::ClientWeaponActionFailed()
{
	/*
	DebugLog(DEBUG_Warn,"AGP_Pawn::ClientWeaponActionFailed() Will interrupt if possible: " $ GetStateName() @ Weapon.GetStateName());
	if (IsInState('BusyReloading'))
	{
		if (Weapon != None && Weapon.IsA('WEAPON_Javelin'))
		{
			if (Weapon.CheckJavelinTube())
			{
				Weapon.SetbTubeAttached(False);
				bCanProne=True;
			}
			else
			{
				Weapon.SetbTubeAttached(True);
				bCanProne=False;
			}
		}
		ChangeAnimation();
	}
	if (Weapon == None)
	{
		return;
	}
	if (Weapon.IsInState('BusyReloading'))
	{
		DebugLog(DEBUG_Anim,"AGP_Pawn::ClientWeaponActionFailed() Sending weapon to Idle state");
		Weapon.GotoState('Idle');
	}
	*/
}
void AAGP_Pawn::DoReload()
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		//GotoState('BusyReloading');
		Cast<AWeapon>(Weapon)->Reload();
		Cast<AWeapon>(Weapon)->ReloadClip(Cast<AWeapon>(Weapon)->GetBestClip());
		//ClientDoReload(Weapon->GetCurrentAmmoType()->AmmoAmount);
		return;
	}
	ServerReload();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		//GotoState('BusyReloading');
		Cast<AWeapon>(Weapon)->Reload();
	}
}
void AAGP_Pawn::ClientDoReload(int32 iAmmoAmount)
{
	/*
	if (IsInState('BusyReloading'))
	{
		Weapon.Reload();
		GotoState('BusyReloading');
	}
	if (Weapon.IsA('Weapon_M24_Sniper'))
	{
		GOTO JL0056;
	}
	Weapon.GetCurrentAmmoType().AmmoAmount=iAmmoAmount;
JL0056:
	*/
}
void AAGP_Pawn::ServerReload()
{
	/*
	if (Controller == None)
	{
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && ! PlayerController(Controller).CanUseWeapon(3))
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::ServerReload()	Client requested a reload but server was unable to comply");
		ClientWeaponActionFailed();
		return;
	}
	if (Weapon == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::ServerReload() - No Weapon");
		ClientWeaponActionFailed();
		return;
	}
	GotoState('BusyReloading');
	Weapon.Reload();
	Weapon.ReloadClip(Weapon.GetBestClip());
	ClientDoReload(Weapon.GetCurrentAmmoType().AmmoAmount);
	NPCAlertPlayerEvent();
	*/

	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1R += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2R += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3R += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1R += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2R += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3R += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1R += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2R += 2.5;
										}
										else
										{
											s3boneangle3R += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1R -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2R -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3R -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1R -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2R -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3R -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1R -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2R -= 2.5;
										}
										else
										{
											s3boneangle3R -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
	
}
void AAGP_Pawn::ClientReload()
{
	Cast<AWeapon>(Weapon)->Reload();
	//GotoState('BusyReloading');
}
void AAGP_Pawn::ReloadWithThisClip(AAmmunition* newclip)
{
	/*
	local Ammunition oldclip;
	if (newclip != None)
	{
		if (Weapon != None)
		{
			if (AGP_Weapon(Weapon).IsInState('GunReloading'))
			{
				return None;
			}
			oldclip=Weapon.GetCurrentAmmoType();
			AGP_Weapon(Weapon).Reload();
			Weapon.SetCurrentAmmoType(newclip);
		}
	}
	return oldclip;
	*/
}
void AAGP_Pawn::DropSpecificItem(AInventory* Item)
{
	/*
	local Pickup Pickup;
	if (Item == None)
	{
		return;
	}
	if (Item.IsA('Weapon'))
	{
		Item.DropFrom(Self.Location + 72 *  Vector(Rotation) + vect(0 0 1) * 15);
		return;
	}
	Pickup=Spawn(Item.PickupClass,,'None',Self.Location + 72 *  Vector(Rotation) + vect(0 0 1) * 15);
	if (Pickup == None)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			ScreenPrint("InvContainer:dropCurrentItem failed fabrication.");
		}
	}
	if (Pickup.IsA('Ammo'))
	{
		Ammo(Pickup).AmmoAmount=Ammunition(Item).AmmoAmount;
	}
	*/
}
void AAGP_Pawn::DropSpecificItemBehind(AInventory* Item)
{
	/*
	local Pickup Pickup;
	if (Item == None)
	{
		return;
	}
	if (Item.IsA('Weapon'))
	{
		Item.DropFrom(Self.Location + 72 *  Vector(Rotation) + vect(0 0 1) * 15);
		return;
	}
	Pickup=Spawn(Item.PickupClass,,'None',Self.Location - 72 *  Vector(Rotation) + vect(0 0 1) * 15);
	if (Pickup == None)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			ScreenPrint("InvContainer:dropCurrentItem failed fabrication.");
		}
	}
	if (Pickup.IsA('Ammo'))
	{
		Ammo(Pickup).AmmoAmount=Ammunition(Item).AmmoAmount;
	}
	*/
}
void AAGP_Pawn::EmptyInventory(bool bDropObjectives)
{
	AInvContainer* invCon;
	int32 i;
	//Controller->CleanUp();
	invCon=_InvTop;
	if (invCon != nullptr)
	{
		//EmptyContainer(invCon,bDropObjectives);
		invCon=invCon->nextContainer;
	}
	if (_OpticsDevice != nullptr)
	{
		_OpticsDevice->Destroy();
		_OpticsDevice= nullptr;
	}
	
	for (i=0; i<7; i++)
	{
		_InvGrenades[i]=0;
	}
}
/*
void AAGP_Pawn::EmptyContainer (AInvContainer* container,bool bDropObjectives)
{
	local Inventory Item;
	if (! container.isEmpty())
	{
		Item=container.getFirstItem();
		if (bDropObjectives && Item.IsA('AGP_ObjectiveInventory'))
		{
			DropUtilityInventory();
		}
		else
		{
			if (container.DeleteItem(Item))
			{
				Item.Destroy();
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
				{
					DebugLog(DEBUG_Inv,"ERROR - AGP_Pawn::EmptyContainer " $ container.thename $ " could not delete " $ Item.Name);
				}
			}
		}
		else
		{
		}
	}
	RecalcInvWeight();
}
*/
void AAGP_Pawn::NextItem()
{
	UE_LOG(LogTemp, Log, TEXT("AGP_Pawn::NextItem called.  No-op."));
}
void AAGP_Pawn::FindInventoryType(AInventory* DesiredClass)
{
	/*
	local InvContainer invCon;
	local Inventory InvItem;
	InvItem=None;
	invCon=_InvTop;
	if (invCon != None)
	{
		InvItem=invCon.FindInventoryType(DesiredClass);
		if (InvItem != None)
		{
			return InvItem;
		}
		invCon=invCon.nextContainer;
	}
	return None;
	*/
}
void AAGP_Pawn::CountInventoryType(AInventory* DesiredClass)
{
	/*
	local InvContainer invCon;
	local int Count;
	local byte Index;
	if (DesiredClass == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType() received null desired class.");
		return -1;
	}
	if (ClassIsChildOf(DesiredClass,'ThrowWeapon'))
	{
		Index=class<ThrowWeapon>(DesiredClass).Default.InvGrenadeIndex;
		if (Index < 7)
		{
			return _InvGrenades[Index];
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType()	Unknown ThrowWeapon " $ DesiredClass);
			return -1;
		}
	}
	if (Role != 4)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType()	No client side functionality!");
		return -1;
	}
	Count=0;
	invCon=_InvTop;
	if (invCon != None)
	{
		Count += invCon.CountInventoryType(DesiredClass);
		invCon=invCon.nextContainer;
	}
	return Count;
	*/
}
bool AAGP_Pawn::AddInventory(TSubclassOf<AInventory> NewItem)
{
	TSubclassOf<AInventory> actor = NewItem;
	if (actor != NULL)
	{
		UWorld* myWorld = GetWorld();
		AActor* myActor = myWorld->SpawnActor(actor);
		//My_Pawn_Inventory.Add(myActor);
		//My_Pawn_Inventory.Add(actor);
	}
	return false;

	//AInventory* Inv;
	TSubclassOf<AInvContainer> holder;

	//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	//{
	//	DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory adding " @ NewItem.GetHumanReadableName());
	//}


	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	Class Name:%s"), *NewItem->GetName()), false);

	if (NewItem == NULL)
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::AddInventory()	Received NULL item");
		return false;
	}

	/*
	//Therse Works:
	if (NewItem->GetName() == FString("Throw_M67_Frag"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(1)  Name=Throw_M67_Frag")), false);
		//return false;
	}
	
	if (NewItem->IsChildOf(AWeapon::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(2) Is a Child of Weapon")), false);
		//return false;
	}
	if (NewItem->IsChildOf(AInventory::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(3) Is a Child of Inventory")), false);
		//return false;
	}
	if (NewItem->IsChildOf(AThrow_M67_Frag::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(4) Is a Child of Throw_M67_Frag")), false);
		//return false;
	}
	*/
	

	
	if (NewItem->IsChildOf(AInvContainer::StaticClass()))
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::AddInventory()	Can't add containers here");
		return false;
	}
	
	if (NewItem->IsChildOf(AItem_Parachute::StaticClass()))
	{
		/*
		Inv=_InvHands->getFirstItem();
		if (Inv == NULL)
		{
			//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			//{
			//	ScreenPrint("Hands are empty. Adding parachute.");
			//}
			_InvHands->addItem(NewItem);
			NewItem->SetOwner(this);
			NewItem->SetInstigator(this);
			ChangeInventoryWeight(NewItem->fWeight);
			Weapon = Cast<AWeapon>(NewItem);
			if (Controller != NULL)
			{
			//	Controller.NotifyAddInventory(NewItem);
			}
			NewItem->AttachToPawn(this);
			return true;
		}
		else
		{
			//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			//{
			//	ScreenPrint("Hands are not empty.  Moving Weapon to shoulder.");
			//}
			if (_InvHands->DeleteItem(Inv))
			{
				if (_InvShoulder->addItem(Inv))
				{
					_InvHands->addItem(NewItem);
					NewItem->SetOwner(this);
					NewItem->SetInstigator(this);
					ChangeInventoryWeight(NewItem->fWeight);
					Weapon = Cast<AWeapon>(NewItem);
					if (Controller != NULL)
					{
						//Controller.NotifyAddInventory(NewItem);
					}
					NewItem->AttachToPawn(this);
					Inv->AttachToPawn(this);
					//Inv->SetRelativeLocation(GetDefault<AInventory>()->RelativeLocation);
					//Inv->SetRelativeRotation(GetDefault<AInventory>()->RelativeRotation);

					UpperBodyAnimComplete();
					return true;
				}
			}
		}
		*/
		return false;
	}
	/*
	if (NewItem->IsChildOf(ADummyItem::StaticClass()))
	{
		//NewItem->AttachToPawn(this);
		//return true;
	}
	holder=NULL;
	//holder=Cast<AInvContainer>(this->FindInventoryItem(NewItem));
	if (holder != NULL)
	{
		//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		//{
		//	DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory tried to add item that it already owns.");
		//}
		return false;
	}
	
	holder=FindInventorySpace(NewItem);
	if (holder == NULL)
	{
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory can't find any space for " @ NewItem.GetHumanReadableName());
		if (! NewItem->IsA(ADummyItem::StaticClass()))
		{
			DropSpecificItemBehind(NewItem);
		}
		return false;
	}
	if (holder->addItem(NewItem))
	{
		ChangeInventoryWeight(NewItem->fWeight);
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory added " @ NewItem.GetHumanReadableName() @ " to " @ holder.thename);
		NewItem->SetOwner(this);
		NewItem->SetInstigator(this);
		if (Controller != NULL)
		{
			//Controller->NotifyAddInventory(NewItem);
		}
		if (NewItem->IsA(AWeapon::StaticClass()))
		{
			if (NewItem == getHandsInventory())
			{
				PendingWeapon = Cast<AWeapon>(NewItem);
				ChangedWeapon();
			}
			NewItem->AttachToPawn(this);
		}
		if (NewItem->IsA(AItem_Bullseye::StaticClass()))
		{
			NewItem->AttachToPawn(this);
		}
		return true;
	}
	else
	{
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory() Failed to add item: " $ NewItem);
	}
	DropSpecificItemBehind(NewItem);
	*/
	return false;
}
void AAGP_Pawn::DeleteInventory(AInventory* Item)
{
	/*
	local InvContainer holder;
	holder=Self.FindInventoryItem(Item);
	DebugLog(DEBUG_Inv,"AGP_Pawn::DeleteInventory() " $ Item @ holder);
	if (holder != None)
	{
		holder.DeleteItem(Item);
		Item.SetOwner(None);
		ChangeInventoryWeight(- Item.fWeight);
	}
	*/
}
void AAGP_Pawn::ChangedWeapon()
{
	/*
	local Weapon OldWeapon;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() " $ Weapon @ PendingWeapon);
	if (Weapon != None && Weapon.Owner == None)
	{
		Weapon.SetOwner(Self);
	}
	OldWeapon=Weapon;
	if (PendingWeapon == None && Weapon == None)
	{
		return;
	}
	if (Weapon == PendingWeapon)
	{
		if (Weapon.IsInState('BusyLoweringWeapon'))
		{
			Weapon.GotoState('Idle');
		}
		PendingWeapon=None;
		DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() Place 1 " $ OldWeapon @ Weapon);
		ServerChangedWeapon(OldWeapon,Weapon);
		return;
	}
	Weapon=PendingWeapon;
	if (Weapon != None)
	{
		Weapon.Instigator=Self;
		Weapon.BringUp();
	}
	PendingWeapon=None;
	DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() Place 2 " $ OldWeapon @ Weapon);
	ServerChangedWeapon(OldWeapon,Weapon);
	if (Controller != None)
	{
		Controller.ChangedWeapon();
	}
	*/
}
void AAGP_Pawn::ServerChangedWeapon(AWeapon* OldWeapon, AWeapon* W)
{
	/*
	DebugLog(DEBUG_Inv,"AGP_Pawn::ServerChangedWeapon() " $ OldWeapon @ W);
	Weapon=W;
	bSwapWhenLanded=False;
	if (Weapon == None)
	{
		if (Controller != None && Controller.IsA('HumanController'))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::ServerChangedWeapon()	" $ Weapon @ HumanController(Controller).bAutoSwapFromGrenade @ Physics);
			if (OldWeapon.IsA('ThrowWeapon') && HumanController(Controller).bAutoSwapFromGrenade)
			{
				Switch(Physics)
				{
					case 1:
					SwapHands();
					break;
					case 2:
					bSwapWhenLanded=True;
					break;
					default:
					DebugLog(DEBUG_Warn,"AGP_Pawn::ServerChangedWeapon()	Unable to auto-swap for Physics state " $ Physics);
				}
			}
		}
		return;
	}
	Weapon.AttachToPawn(Self);
	Weapon.SetRelativeLocation(Weapon.Default.RelativeLocation);
	Weapon.SetRelativeRotation(Weapon.Default.RelativeRotation);
	if (OldWeapon == Weapon)
	{
		if (Weapon.IsInState('BusyLoweringWeapon'))
		{
			Weapon.BringUp();
		}
		return;
	}
	else
	{
		if (Level.Game != None)
		{
			MakeNoise(0.1 * Level.Game.GameDifficulty);
		}
	}
	W.RecountAmmo();
	PlayWeaponSwitch(W);
	Weapon.BringUp();
	if (AGP_Weapon(Weapon).fpWeaponThreatLevel > fpPlayerThreatLevel)
	{
		fpPlayerThreatLevel=AGP_Weapon(Weapon).fpWeaponThreatLevel;
	}
	*/
}
void AAGP_Pawn::WeaponChanged()
{
	/*
	if (Weapon != NULL)
	{
		if (CommoState == 0 && ! CommoCanHandSignal())
		{
			CommoCycleState();
		}
		Weapon.OwnerRecieved();
	}
	*/
}
FName AAGP_Pawn::GetWeaponBoneFor(TSubclassOf<AInventory> i)
{
	return "WeaponBone";
}
AInvContainer* AAGP_Pawn::FindInventoryItem(TSubclassOf<AInventory> p_item)
{
	/*
	AInvContainer* invCon;
	invCon=_InvTop;
	if (invCon != NULL)
	{
		if (invCon->FindInventoryItem(p_item))
		{
			return invCon;
		}
		invCon=invCon->nextContainer;
	}
	*/
	return NULL;
}
AInvContainer* AAGP_Pawn::FindInventorySpace(TSubclassOf<AInventory> p_item)
{
	/*
	AInvContainer* IC;
	if (p_item == NULL)
	{
		return NULL;
	}
	if (p_item->IsA(AItem_Bullseye::StaticClass()))
	{
		return _InvUtility;
	}
	if (Cast<AInventory>(p_item)->VirtualWeapon() || Cast<AInventory>(p_item)->isHandsOnly())
	{
		if (_InvHands != nullptr && _InvHands->FindInventorySpace(p_item))
		{
			return _InvHands;
		}
		else
		{
			return NULL;
		}
	}
	Cast<AInventory>(p_item)->SetInstigator(this);
	if (_InvHands->FindInventorySpace(p_item))
	{
		return _InvHands;
	}
	else
	{
		IC= Cast<AInventory>(p_item)->GetSwapContainer();
		if (IC != nullptr && IC->FindInventorySpace(p_item))
		{
			return IC;
		}
	}
	*/
	return NULL;
}
TSubclassOf<AInventory> AAGP_Pawn::getShoulderInventory()
{
	if (_InvShoulder != NULL)
	{
		return _InvShoulder->getCurrentItem();
	}
	return NULL;
}
TSubclassOf<AInventory> AAGP_Pawn::getHandsInventory()
{
	if (_InvHands != NULL)
	{
		return _InvHands->getCurrentItem();
	}
	return NULL;
}
TSubclassOf<AInventory> AAGP_Pawn::getHolsterInventory()
{
	if (_InvHolster != NULL)
	{
		return _InvHolster->getCurrentItem();
	}
	return NULL;
}
TSubclassOf<AInventory> AAGP_Pawn::getHipInventory()
{
	if (_InvHip != NULL)
	{
		return _InvHip->getCurrentItem();
	}
	return NULL;
}
TSubclassOf<AInventory> AAGP_Pawn::getAltShoulderInventory()
{
	if (_InvAltShoulder != NULL)
	{
		return _InvAltShoulder->getCurrentItem();
	}
	return NULL;
}
void AAGP_Pawn::DiscardInventory()
{
	/*
	local InvContainer Prev;
	local InvContainer Next;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::DiscardInventory() - Destroying");
	}
	Prev=_InvTop;
	if (Prev != None)
	{
		Next=Prev.nextContainer;
		Prev.Destroy();
		Prev=Next;
	}
	if (_OpticsDevice != None)
	{
		_OpticsDevice.Destroy();
		_OpticsDevice=None;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::DiscardInventory() - Setting to None");
	}
	_InvTop=None;
	_InvHands=None;
	_InvShoulder=None;
	_InvHolster=None;
	_InvHip=None;
	_InvAltShoulder=None;
	*/
}
void AAGP_Pawn::KnowAll(FString S)
{
	/*
	if (Level.debugThis(18))
	{
		DebugLog(DEBUG_Inv,S $ "	NextSwap  -" @ NextSwap);
		DebugLog(DEBUG_Inv,S $ "	Weapon    -" @ Weapon);
		DebugLog(DEBUG_Inv,S $ "	Hands     -" @ getHandsInventory());
		DebugLog(DEBUG_Inv,S $ "	Shoulder  -" @ getShoulderInventory());
		DebugLog(DEBUG_Inv,S $ "	Holster   -" @ getHolsterInventory());
	}
	*/
}
void AAGP_Pawn::CanSwapHands()
{
	/*
	if (bAllowSwap)
	{
		bAllowSwap=False;
		return true;
	}
	if (! bCanSwapWeapons || IsBusy() || IsSupported() || bIsSprinting || Physics == 11 || bIsDead || Weapon != None && Weapon.IsBusy() && ! Weapon.IsTempBusy() || Weapon.IsA('Item_Parachute'))
	{
		return false;
	}
	return true;
	*/
}
void AAGP_Pawn::SwapHands()
{
	/*
	local Inventory handitem;
	StopSprint();
	handitem=getHandsInventory();
	NextSwap=getShoulderInventory();
	KnowAll("AGP_Pawn::SwapHands()	");
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.IsA('Weapon'))
		{
			Weapon(handitem).PutDown();
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::SwapHands()	Don't know how to handle non-weapon " $ handitem,True);
			NextSwap=None;
		}
	}
	*/
}
void AAGP_Pawn::SwapHip()
{
	/*
	local AGP_Weapon handitem;
	StopSprint();
	KnowAll("AGP_Pawn::SwapHip()");
	handitem=AGP_Weapon(getHandsInventory());
	NextSwap=getHipInventory();
	if (NextSwap == None && ! handitem.IsA('WEAPON_Javelin'))
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHip()	No CLU to swap");
		return;
	}
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (! CanPutAway(handitem))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	Can't put the hand item away!");
			NextSwap=None;
		}
		else
		{
			handitem.PutDown();
		}
	}
	*/
}
void AAGP_Pawn::SwapAltShoulder()
{
	/*
	local Inventory handitem;
	KnowAll("AGP_Pawn::SwapAltShoulder()");
	handitem=getHandsInventory();
	NextSwap=getAltShoulderInventory();
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.IsA('Weapon'))
		{
			Weapon(handitem).PutDown();
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::SwapHands()	Don't know how to handle non-weapon " $ handitem,True);
			NextSwap=None;
		}
	}
	*/
}
void AAGP_Pawn::DropAndSwap()
{
	/*
	NextSwap=getShoulderInventory();
	if (getHandsInventory() == None)
	{
		FinishSwapHands();
	}
	else
	{
		HumanController(Controller).ServerThrowWeapon();
	}
	*/
}
void AAGP_Pawn::getItemToPutInHands()
{
	/*
	local ThrowWeapon Grenade;
	local AGP_Weapon binoculars;
	if (DesiredGrenade != None)
	{
		Grenade=Spawn(DesiredGrenade);
		if (! HaveUnlimitedAmmo())
		{
			_InvGrenades[Grenade.InvGrenadeIndex] --;
		}
		return Grenade;
	}
	else
	{
		if (DesiredBinoculars != None)
		{
			binoculars=Spawn(DesiredBinoculars);
			return binoculars;
		}
		else
		{
			return NextSwap;
		}
	}
	*/
}
void AAGP_Pawn::GetSwapContainer()
{
	//return AGP_Weapon(NextSwap).GetSwapContainer();
}
void AAGP_Pawn::FinishSwapHands()
{
	/*
	local Inventory NextItem;
	local Inventory handitem;
	local bool bSuccess;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		DebugLog(DEBUG_Warn,"How did it get here?");
		return false;
	}
	if (EventLab != None)
	{
		if (Weapon.IsA('item_headphones'))
		{
			return false;
		}
	}
	handitem=getHandsInventory();
	NextItem=getItemToPutInHands();
	if (handitem == None)
	{
		if (NextItem == None)
		{
			bSuccess=True;
		}
		else
		{
			if (CanPutInHands(NextItem))
			{
				NextItem.GetSwapContainer().DeleteItem(NextItem);
				ItemPutInHands(NextItem);
				bSuccess=True;
			}
		}
	}
	else
	{
		if (NextItem == None)
		{
			if (CanPutAway(handitem))
			{
				_InvHands.DeleteItem(handitem);
				ItemPutAway(handitem);
				bSuccess=True;
			}
		}
		else
		{
			_InvHands.DeleteItem(handitem);
			NextItem.GetSwapContainer().DeleteItem(NextItem);
			if (CanPutAway(handitem) && CanPutInHands(NextItem))
			{
				ItemPutAway(handitem);
				ItemPutInHands(NextItem);
				bSuccess=True;
			}
			else
			{
				_InvHands.addItem(handitem);
				NextItem.GetSwapContainer().addItem(NextItem);
			}
		}
	}
	KnowAll("AGP_Pawn::FinishSwapHands()	Before ");
	if (! bSuccess)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::FinishSwapHands() Unable to swap " $ handitem @ NextItem);
	}
	else
	{
		PendingWeapon=Weapon(getHandsInventory());
		ChangedWeapon();
	}
	KnowAll("AGP_Pawn::FinishSwapHands()	After ");
	DesiredGrenade=None;
	DesiredBinoculars=None;
	NextSwap=None;
	return bSuccess;
	*/
}
bool AAGP_Pawn::CanPutInHands(TSubclassOf<AInventory> Item)
{
	return _InvHands->FindInventorySpace(Item);
}


bool AAGP_Pawn::CanPutAway(TSubclassOf<AInventory> Item)
{
	AAGP_Weapon* weap;
	weap=Cast<AAGP_Weapon>(Item);
	if (weap == NULL)
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::CanPutAway()	Don't know what to do with no weapon. item(" @ Item @ ") weap(" @ weap @ ")");
		return false;
	}
	if (weap->VirtualWeapon())
	{
		return true;
	}
	else
	{
		//return Cast<AInventory>(weap->GetSwapContainer())->isEmpty();
		return true;   //FAKE /ELiZ
	}
}
void AAGP_Pawn::ItemPutInHands(TSubclassOf<AInventory> Item)
{
	/*
	if (Item.IsA('ThrowWeapon') || Item.IsA('Item_Binoculars'))
	{
		Item.GiveTo(Self);
		Item.PickupFunction(Self);
	}
	_InvHands.addItem(Item);
	if (Item.IsA('AGP_Weapon'))
	{
		if (AGP_Weapon(Item).fpWeaponThreatLevel > fpPlayerThreatLevel)
		{
			fpPlayerThreatLevel=AGP_Weapon(Item).fpWeaponThreatLevel;
		}
	}
	NPCAlertPlayerEvent();
	*/
}
void AAGP_Pawn::ItemPutAway(TSubclassOf<AInventory> Item)
{
	/*
	if (Weapon(Item).VirtualWeapon())
	{
		if (Item.IsA('ThrowWeapon'))
		{
			_InvGrenades[ThrowWeapon(Item).InvGrenadeIndex] ++;
		}
		else
		{
			if (Item.IsA('Item_Binoculars'))
			{
				if (_InvBinoculars != Item_Binoculars(Item).InvBinocularsIndex)
				{
					DebugLog(DEBUG_Warn,"AGP_Pawn::ItemPutAway()	Trying to hold two different binocs! Keeping last!");
					_InvBinoculars=Item_Binoculars(Item).InvBinocularsIndex;
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::ItemPutAway() " @ Item @ AGP_Weapon(Item).GetSwapContainer());
		AGP_Weapon(Item).GetSwapContainer().addItem(Item);
	}
	NPCAlertPlayerEvent();
	*/
}
void AAGP_Pawn::PrintInventory()
{
	/*
	local InvContainer invCon;
	invCon=_InvTop;
	if (invCon != None)
	{
		ScreenPrint("Container: " @ invCon.thename);
		ScreenPrint(invCon.toString());
		invCon=invCon.nextContainer;
	}
	*/
}
void AAGP_Pawn::LogInventory()
{
	/*
	local InvContainer invCon;
	invCon=_InvTop;
	if (invCon != None)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::LogInventory() Container: " @ invCon.thename);
		Log(invCon.toString());
		invCon=invCon.nextContainer;
	}
	*/
}
AInvContainer* AAGP_Pawn::getInvContainerHands()
{
	return _InvHands;
}
AInvContainer* AAGP_Pawn::getInvContainerShoulder()
{
	return _InvShoulder;
}
AInvContainer* AAGP_Pawn::getInvContainerHolster()
{
	return _InvHolster;
}
AInvContainer* AAGP_Pawn::getInvContainerUtility()
{
	return _InvUtility;
}
AInvContainer* AAGP_Pawn::getInvContainerHip()
{
	return _InvHip;
}
AInvContainer* AAGP_Pawn::getInvContainerAltShoulder()
{
	return _InvAltShoulder;
}
void AAGP_Pawn::GetGrenade(uint8 Index)
{
	/*
	local Inventory handitem;
	local class<Inventory>  AltClass;
	DesiredGrenade=None;
	Index --;
	if (Index >= 7)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GetGrenade()	Invalid index received " $ Index);
		return;
	}
	if (_InvGrenades[Index] == 0 && ! HaveUnlimitedAmmo())
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	No more grenades at index " $ Index);
		return;
	}
	Switch(Index)
	{
		case 0:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M67_Frag",Class'Class'));
		break;
		case 1:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
		break;
		case 2:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun",Class'Class'));
		break;
		case 3:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M14_Incendiary",Class'Class'));
		break;
		case 5:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Demo_DoorBreacher",Class'Class'));
		break;
		case 6:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_GreenSmoke",Class'Class'));
		break;
		default:
	}
	if (! IsValidInventory(DesiredGrenade,AltClass))
	{
		DesiredGrenade=class<ThrowWeapon>(AltClass);
	}
	if (DesiredGrenade == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GetGrenade()	This Grenade is not valid!");
		return;
	}
	handitem=getHandsInventory();
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.Class == DesiredGrenade)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	Already holding this grenade");
			DesiredGrenade=None;
		}
		else
		{
			if (! CanPutAway(handitem))
			{
				DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	Nowhere to put the weapon");
				DesiredGrenade=None;
			}
			else
			{
				Weapon(handitem).PutDown();
			}
		}
	}
	*/
}
void AAGP_Pawn::GetBinoculars()
{
	/*
	local Inventory handitem;
	if (_InvBinoculars == 0)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	You don't have binoculars!");
		return;
	}
	Switch(_InvBinoculars)
	{
		case 1:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocM22_A",Class'Class'));
		break;
		case 2:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocM24_B",Class'Class'));
		break;
		case 3:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocTank_A",Class'Class'));
		break;
		case 4:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocNewt_B",Class'Class'));
		break;
		case 5:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_VIPER",Class'Class'));
		break;
		default:
		break;
	}
	handitem=getHandsInventory();
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.Class == DesiredBinoculars)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	Already holding these binoculars");
			Weapon(handitem).PutDown();
			DesiredBinoculars=None;
		}
		else
		{
			if (! CanPutAway(handitem))
			{
				DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	Nowhere to put the weapon");
				DesiredBinoculars=None;
			}
			else
			{
				Weapon(handitem).PutDown();
			}
		}
	}
	*/
}
void AAGP_Pawn::PutAwayHandItem()
{
	TSubclassOf<AInventory> handitem;
	handitem=getHandsInventory();
	if (handitem != NULL)
	{
		Cast<AWeapon>(handitem)->PutDown();
	}
}
void AAGP_Pawn::SwapHolster()
{
	/*
	local AGP_Weapon handitem;
	KnowAll("AGP_Pawn::SwapHolster()");
	handitem=AGP_Weapon(getHandsInventory());
	NextSwap=getHolsterInventory();
	if (NextSwap == None && ! handitem.IsA('PistolWeapon'))
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	No pistol to swap");
		return;
	}
	if (handitem == None)
	{
		FinishSwapHands();
	}
	else
	{
		if (! CanPutAway(handitem))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	Can't put the hand item away!");
			NextSwap=None;
		}
		else
		{
			handitem.PutDown();
		}
	}
	*/
}
void AAGP_Pawn::RecalcInvWeight()
{
	float accumWeight;
	accumWeight = 0;
	if (_InvHands != NULL)
	{
		accumWeight += _InvHands->fWeight;
	}
	if (_InvShoulder != NULL)
	{
		accumWeight += _InvShoulder->fWeight;
	}
	if (_InvHolster != NULL)
	{
		accumWeight += _InvHolster->fWeight;
	}
	if (_InvHip != NULL)
	{
		accumWeight += _InvHip->fWeight;
	}
	if (_InvHip != NULL)
	{
		accumWeight += _InvAltShoulder->fWeight;
	}
	SetInventoryWeight(accumWeight);
}
void AAGP_Pawn::ChangeInventoryWeight(float Weight)
{
	/*
	fInvWeight += Weight;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		ScreenPrint("fInvWeight=" @ fInvWeight @ "SpeedRatio=" @ SpeedRatio);
	}
	*/
}
void AAGP_Pawn::SetInventoryWeight(float Weight)
{
	fInvWeight=Weight;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		ScreenPrint("fInvWeight=" @ fInvWeight @ "SpeedRatio=" @ SpeedRatio);
	}
	*/
}
float AAGP_Pawn::GetInventoryWeight()
{
	return fInvWeight;
}
void AAGP_Pawn::CanUseAmmo(AInventory* weap, AInventory* Ammo)
{
	//return weap != None && weap.IsA('Weapon') && AGP_Weapon(weap).ValidAmmo(Ammo.Class);
}
void AAGP_Pawn::CanPickupItem(AInventory* Item, bool bVirtual)
{
	/*
	if (Item.IsA('WEAPON_Javelin'))
	{
		if (getHipInventory() != None)
		{
			if (getHipInventory().IsA('WEAPON_Javelin'))
			{
				return false;
			}
		}
		if (getHandsInventory() != None)
		{
			if (getHandsInventory().IsA('WEAPON_Javelin'))
			{
				return false;
			}
		}
	}
	if (Item.IsA('Javelin_Tube'))
	{
		if (getAltShoulderInventory() != None)
		{
			if (getAltShoulderInventory().IsA('Javelin_Tube'))
			{
				return false;
			}
		}
		if (getHandsInventory() != None)
		{
			if (getHandsInventory().IsA('Javelin_Tube'))
			{
				return false;
			}
		}
	}
	if (bVirtual)
	{
		if (Item.IsA('Ammunition'))
		{
			return CanUseAmmo(Weapon,Item) || CanUseAmmo(_InvShoulder.getFirstItem(),Item) || CanUseAmmo(_InvHolster.getFirstItem(),Item);
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (FindInventorySpace(Item) == None)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::CanPickupItem()	Pawn " $ Self $ " cannot pick up " $ Item);
			return false;
		}
		else
		{
			if (Item.IsA('Weapon') && Controller.IsInState('PlayerClimbing'))
			{
				HumanController(Controller).ClientMessage("You cannot pick up weapons while climbing.");
				return false;
			}
			DebugLog(DEBUG_Inv,"AGP_Pawn::CanPickupItem()	Pawn " $ Self $ " can pick up " $ Item);
			return true;
		}
	}
	*/
}
bool AAGP_Pawn::AreHandsEmpty()
{
	if (_InvHands != NULL)
	{
		return _InvHands->isEmpty();
	}
	return true;
}
void AAGP_Pawn::NotifyOpticsStatusChangingTo(bool bActive)
{
	/*
	if (bActive && Weapon != None && Weapon.IsA('Item_Binoculars'))
	{
		Weapon.ForceUnzoom(True);
	}
	*/
}
void AAGP_Pawn::NotifyBinocularsStatusChangingTo(bool bZoom)
{
	/*
	if (bZoom && GetOpticsDevice() != None && GetOpticsDevice().IsActive())
	{
		DeactivateOptics();
	}
	*/
}
void AAGP_Pawn::ToggleOptics()
{
	if (GetOpticsDevice() != NULL)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Toggle();
	}
}
void AAGP_Pawn::CleanupOptics()
{
	if (GetOpticsDevice() != NULL)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->CleanUp();
	}
}
void AAGP_Pawn::DeactivateOptics()
{
	if (GetOpticsDevice() != NULL)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Deactivate();
	}
}
void AAGP_Pawn::ActivateOptics()
{
	if (GetOpticsDevice() != NULL)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Activate();
	}
}
ABaseOptics* AAGP_Pawn::GetOpticsDevice()
{
	return _OpticsDevice;
}
void AAGP_Pawn::ChangeFireMode()
{
	//Weapon.ChangeFireMode();
}
void AAGP_Pawn::FixJam()
{
	/*
	if (Weapon != None && Weapon.IsInState('BusySupporting') || Weapon.IsInState('BusyChangingFireMode'))
	{
		Log("User tried to fix jame while busy using supported function or changing modes");
		return;
	}
	if (angleEditor)
	{
		boneaxis += 1;
		if (boneaxis == 9)
		{
			boneaxis=0;
		}
		return;
	}
	NPCAlertPlayerEvent();
	Weapon.FixJam();
	*/
}
void AAGP_Pawn::ClientTossWeapon(FVector TossVel)
{
	
	if (Weapon != NULL)
	{
		Cast<AWeapon>(Weapon)->UnZoom();
	}
	//SetSupported(False,True);
	//WeaponSwap3p(5);
	
}
void AAGP_Pawn::TossWeapon(FVector TossVel)
{
	/*
	local FVector loc;
	ClientTossWeapon(TossVel);
	Weapon.Velocity=TossVel;
	loc=GetPickupSpawnLocation(Weapon.PickupClass);
	Weapon.DropFrom(loc);
	WeaponSwap3p(5);
	*/
}
void AAGP_Pawn::GetPickupSpawnLocation(APickup*  PickupClass)
{
	/*
	local FVector WeaponLoc;
	local FVector SpawnLoc;
	local FVector loc;
	local FVector Dir;
	local Object.Range PickupCyl;
	local Object.Range PawnCyl;
	local float PawnRadius;
	WeaponLoc=GetBoneCoords('WeaponBone').Origin;
	if (bIsProne && FrontAuxCyl != None)
	{
		loc=FrontAuxCyl.Location;
		PawnRadius=FrontAuxCyl.CollisionRadius;
	}
	else
	{
		loc=Location;
		PawnRadius=CollisionRadius;
	}
	Dir=Normal(WeaponLoc - loc);
	Dir *= FMax(0,PawnRadius - PickupClass.Default.CollisionRadius);
	SpawnLoc=loc + Dir;
	SpawnLoc.Z=WeaponLoc.Z;
	PickupCyl.Min=SpawnLoc.Z - PickupClass.Default.CollisionHeight / 2;
	PickupCyl.Max=SpawnLoc.Z + PickupClass.Default.CollisionHeight / 2;
	PawnCyl.Min=Location.Z - CollisionHeight / 2;
	PawnCyl.Max=Location.Z + CollisionHeight / 2;
	if (PickupCyl.Min < PawnCyl.Min)
	{
		SpawnLoc.Z=PawnCyl.Min + PickupClass.Default.CollisionHeight / 2;
	}
	else
	{
		if (PickupCyl.Max > PawnCyl.Max)
		{
			SpawnLoc.Z=PawnCyl.Max - PickupClass.Default.CollisionHeight / 2;
		}
	}
	return SpawnLoc;
	*/
}
void AAGP_Pawn::HaveUnlimitedAmmo()
{
	//return Controller->bUnlimitedAmmo;
}
void AAGP_Pawn::WeaponEffectivenessBonus()
{
	/*
	local float retvalue;
	if (AGP_Weapon(Weapon) == None)
	{
		return 0;
	}
	retvalue=TeamClass.WeaponEffectivenessBonus(AGP_Weapon(Weapon));
	if (Controller != None && Controller.bNoWeaponPenalty)
	{
		return 1;
	}
	if (AGP_Weapon(Weapon).IsOpFor())
	{
		if (Weapon.bGuerrillaWeapon && bGuerrillaMesh)
		{
			retvalue *= 1;
		}
		else
		{
			if (! bGuerrillaMesh)
			{
				retvalue *= 0.75;
			}
		}
	}
	if (bGuerrillaMesh && ! Weapon.bGuerrillaWeapon)
	{
		retvalue *= 0.75;
	}
	return retvalue;
	*/
}
void AAGP_Pawn::BreatheCycle(float DeltaTime)
{
	/*
	local float OldZoomCycle;
	local FRotator BreatheRot;
	local float CEMToStopWander;
	CEMToStopWander=0.95;
	fZoomTime += DeltaTime;
	fDeviateCycle += DeltaTime;
	if (Weapon != None && Weapon.ShouldBreatheCycle())
	{
		OldZoomCycle=fZoomCycle;
		fZoomCycle=Sin(fZoomTime + 1 - CE_MeterValue) ** 3;
		if (IsHumanControlled())
		{
			PlayerController(Controller).ResetSoundDampening();
		}
		if (OldZoomCycle > 0 && fZoomCycle < 0)
		{
			PlaySound(BreathOutSound,0,1,,,,False);
		}
		else
		{
			if (OldZoomCycle < 0 && fZoomCycle > 0)
			{
				PlaySound(BreathInSound,0,1,,,,False);
			}
		}
		if (IsHumanControlled())
		{
			PlayerController(Controller).CalcSoundDampening();
		}
		if (IsHumanControlled() && PlayerController(Controller).debugAiming)
		{
			if (Abs(fZoomCycle) < 0.2 * CE_MeterValue)
			{
				ScreenPrint("Fire Here " @ fZoomCycle @ "Threshold" @ 0.2 * CE_MeterValue);
			}
		}
		fZoomCycle *= AGP_Weapon(Weapon).GetBreatheMultiplier();
		BreatheRot=rot(13 0 0) * fZoomCycle * 1 - CE_MeterValue;
		if (fDeviateCycle > fDeviateTime)
		{
			fDeviateCycle=0;
			fDeviateTime=0.25 * CE_MeterValue + FRand() * CE_MeterValue;
			rDeviation=Weapon.CalcZoomWander() * 1 - CE_MeterValue;
			if (IsSupported())
			{
				if (CE_MeterValue >= CEMToStopWander)
				{
					rDeviation=rot(0 0 0);
				}
				else
				{
					rDeviation *= CEMToStopWander - CE_MeterValue / CEMToStopWander;
				}
			}
		}
		if (Abs(fZoomCycle) < 0.2 * CE_MeterValue)
		{
			BreatheRot += rDeviation * 0.85 * DeltaTime;
		}
		else
		{
			BreatheRot += rDeviation * DeltaTime;
		}
		return BreatheRot;
	}
	return rot(0 0 0);
	*/
}

/*
 // ======================================================================================
 // AGP function - GetHealthCondition
 // Classifies pawn's health level as Green/Yellow/Red/Dead
 // output:	Enum value of health condition
 // last modified by:  superville 12/21/01
 // ======================================================================================
*/
EHealthCondition AAGP_Pawn::GetHealthCondition()
{
	if (Health > 70)
	{
		return EHealthCondition::HC_GREEN;
	}
	else
	{
		if (Health > 40)
		{
			return EHealthCondition::HC_YELLOW;
		}
		else
		{
			if (Health > 0)
			{
				return EHealthCondition::HC_RED;
			}
			else
			{
				return EHealthCondition::HC_DEAD;
			}
		}
	}
}

/* =================================================================================== *
 * AGP function GetWoundSeverity()
 *	Get the severity of the wound. This is the amount of CEM that can be restored by
 *	a medic.
 *
 * output:	EWoundSeverity	- enum representing severity
 * last modified by: cmb
 * =================================================================================== */
EWoundSeverity AAGP_Pawn::GetWoundSeverity()
{
	if (Health == 100)
	{
		return EWoundSeverity::WS_NotWounded;
	}
	else
	{
		if (BleedMax == 0)
		{
			return EWoundSeverity::WS_Treated;
		}
		else
		{
			if (BleedMax <= 10)
			{
				return EWoundSeverity::WS_Minor;
			}
			else
			{
				if (BleedMax <= 25)
				{
					return EWoundSeverity::WS_Moderate;
				}
				else
				{
					return EWoundSeverity::WS_Urgent;
				}
			}
		}
	}
}
FString AAGP_Pawn::GetHealthString()
{
	EHealthCondition HC;
	HC=GetHealthCondition();
	switch(HC)
	{
		case EHealthCondition::HC_GREEN:
			return "Green";
		case EHealthCondition::HC_YELLOW:
			return "Yellow";
		case EHealthCondition::HC_RED:
			return "Red";
		default:
			return "Dead";
	}
	return "";
}
/*
void AAGP_Pawn::Landed (FVector HitNormal)
{

	local bool bPlayLanding;
	if (Physics == 17)
	{
		bPlayLanding=False;
	}
	else
	{
		bPlayLanding=True;
	}
	TakeFallingDamage();
	if (Health > 0 && bPlayLanding)
	{
		PlayLanded(Velocity.Z);
	}
	if (Velocity.Z < -1.4 * JumpZ)
	{
		MakeNoise(-0.5 * Velocity.Z / FMax(JumpZ,150));
	}
	bJustLanded=True;
	if (bMidJump)
	{
		ServerSpawnSideEffect('SideEffectSlowHop',0);
		bMidJump=False;
	}
	if (bSwapWhenLanded)
	{
		SwapHands();
	}
	bSwapWhenLanded=False;

}
*/
void AAGP_Pawn::HitWall(FVector HitNormal, AActor* Wall)
{
	/*
	HitWall(HitNormal,Wall);
	if (ForceActor != None)
	{
		ForceVelocity *= -1;
	}
	*/
}
void AAGP_Pawn::ClientSpawnSideEffect(ASideEffect* SideEffectClass, int32 Damage)
{
	/*
	local SideEffect SE;
	if (SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_DedicatedServer && ! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Client && SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Standalone && ! SideEffectClass.Default.bServerEffect && Controller != Level.GetLocalPlayerController())
	{
		return;
	}
	SE=Spawn(SideEffectClass,Controller);
	SE.ScaleByDamage(Damage);
	SE.Start();
	*/
}
void AAGP_Pawn::ServerSpawnSideEffect(ASideEffect* SideEffectClass, int32 Damage)
{
	/*
	local SideEffect SE;
	if (! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_DedicatedServer && ! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Client && SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Standalone && ! SideEffectClass.Default.bServerEffect && Controller != Level.GetLocalPlayerController())
	{
		return;
	}
	SE=Spawn(SideEffectClass,Controller);
	SE.ScaleByDamage(Damage);
	SE.Start();
	*/
}
/*
void AAGP_Pawn::TakeDamage (int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType,Actor.BoneInfo Bone,AController KillerController,AActor ResponsibleActor,UTexture2D HitMaterial)
{
	local PlayerReplicationInfo KillerPRI;
	local FVector MomentumDir;
	local float FFMultiplier;
	local AGP_Pawn aPawn;
	local float BleedDamage;
	local Pawn.EHealthCondition HC;
	local int InitialHealth;
	local int ActualROE;
	local class<AGP_DamageType>  AGPDamType;
	local array<class<SideEffect> > SideEffects;
	local int i;
	if (Role < 4 || isDead())
	{
		if (isDead())
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: is already dead ");
		}
		if (bIsDead)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: bIsDead ");
		}
		if (bNetAlreadyDead)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: bNetAlreadyDead ");
		}
		if (Health <= 0)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: Health <= 0 ");
		}
		return;
	}
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,8,instigatedBy);
	}
	if (InGodMode() || Controller != None && Controller.IsA('PlayerController') && PlayerController(Controller).GameReplicationInfo.bRoundIsSuspended)
	{
		Damage=0;
	}
	if (instigatedBy == None)
	{
		if (ClassIsChildOf(DamageType,'AGP_FellDamage'))
		{
			instigatedBy=Self;
		}
		else
		{
			if (KillerController != None)
			{
				instigatedBy=KillerController.Pawn;
			}
		}
	}
	else
	{
		KillerPRI=instigatedBy.PlayerReplicationInfo;
	}
	if (instigatedBy != None)
	{
		if (KillerController == None)
		{
			KillerController=instigatedBy.Controller;
		}
		if (KillerController != None)
		{
			KillerPRI=KillerController.PlayerReplicationInfo;
		}
		if (PlayerReplicationInfo != None && PlayerReplicationInfo.IsFriend(KillerPRI) && DamageType.Default.FFMultiplier == 0)
		{
			KillerController=Controller;
			KillerPRI=PlayerReplicationInfo;
		}
	}
	if (Physics == 0)
	{
		SetMovementPhysics();
	}
	if (Physics == 1)
	{
		Momentum.Z=FMax(Momentum.Z,0.4 * VSize(Momentum));
	}
	if (KillerController == Controller)
	{
		Momentum *= 0.6;
	}
	Momentum /= Mass;
	if (ClassIsChildOf(DamageType,'MilesDamage') && Damage > 0)
	{
		Damage=30;
	}
	if (FVector::IsZero(HitLocation))
	{
		HitLocation=Location;
	}
	MomentumDir=Normal(Momentum);
	PlayHit(Damage,instigatedBy,HitLocation,DamageType,MomentumDir);
	AddVelocity(Momentum);
	InitialHealth=Health;
	BleedDamage=Damage * DamageType.Default.DamageBleedPercent;
	if (BleedDamage > BleedHealth)
	{
		if (IsBleeding())
		{
			Health -= BleedHealth;
		}
		fHealPercent=0;
		if (Health - Damage > 0)
		{
			VirtualHealth=0;
			if (BleedMax > BleedDamage)
			{
				BleedMax=BleedMax + BleedDamage / 2;
			}
			else
			{
				BleedMax=BleedDamage + BleedMax / 2;
			}
			BleedHealth=BleedDamage;
			Damage -= BleedHealth;
		}
		fpBleedRate=5;
	}
	HC=GetHealthCondition();
	Health=Max(0,Health - Damage);
	BleedHealth=Min(BleedHealth,Health);
	if (! InGodMode() && Controller != None && Controller.bSuperGodMode && ! AGP_GameInfo(Level.Game).bDisableTakeDamageViewShift)
	{
		AGPDamType=class<AGP_DamageType>(DamageType);
		if (Damage > 5)
		{
			if (AGPDamType != None)
			{
				SideEffects=AGPDamType.GetSideEffects(Controller,Damage,instigatedBy,HitLocation,Momentum,Bone,KillerController,ResponsibleActor);
				for (i=0; i<SideEffects.Length; i++)
				{
					if (SideEffects[i] != None)
					{
						ClientSpawnSideEffect(SideEffects[i],Damage);
						ServerSpawnSideEffect(SideEffects[i],Damage);
					}
				}
			}
		}
	}
	if (HC < GetHealthCondition())
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Self,"HEALTHDEGRADE");
		}
	}
	if (Health <= 0)
	{
		if (bPhysicsAnimUpdate)
		{
			TearOffMomentum=Momentum;
		}
		if (KillerController == None && instigatedBy.IsA('VehiclePosition'))
		{
			if (Pawn(instigatedBy.Owner).Controller != None)
			{
				KillerController=Pawn(instigatedBy.Owner).Controller;
			}
		}
		Died(KillerController,DamageType,HitLocation,MomentumDir,Bone);
	}
	else
	{
		if (Controller != None)
		{
			Controller.NotifyTakeHit(instigatedBy,HitLocation,Damage,DamageType,Momentum);
		}
	}
	MakeNoise(1);
	if (instigatedBy != None && instigatedBy.Controller != None && instigatedBy.Controller.IsA('StudentController'))
	{
		aPawn=AGP_Pawn(instigatedBy);
		if (aPawn._FriendlyFireMonitor != None)
		{
			if (idTeam == 1 || idTeam == 2 && Self != instigatedBy)
			{
				aPawn._FriendlyFireMonitor.Notify();
			}
			else
			{
				if (NPCBaseController(Controller) != None && NPCBaseController(Controller).bTrainingCadre)
				{
					aPawn._FriendlyFireMonitor.Notify();
				}
			}
		}
	}
	if (HumanController(Controller) != None && Damage > 0 && instigatedBy.IsA('AGP_Character_NPC'))
	{
		Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByAI(HumanController(Controller).Pawn.Location);
	}
	if (PlayerReplicationInfo != None && PlayerReplicationInfo.IsFriend(KillerPRI))
	{
		if (KillerPRI != PlayerReplicationInfo && HumanController(Controller) != None && Damage > 0)
		{
			Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByFriendlyFire(HumanController(Controller).Pawn.Location);
			for (i=0; i<Level.Game.Stats.PlayerStats.Length; i++)
			{
				if (Level.Game.Stats.PlayerStats[i] != None)
				{
					Level.Game.Stats.PlayerStats[i].StatEvent_ROEFriendlyFireHits();
				}
			}
		}
		if (PlayerReplicationInfo != KillerPRI)
		{
			aPawn=AGP_Pawn(instigatedBy);
			if (aPawn != None && aPawn._FriendlyFireMonitor != None)
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::TakeDamage(): Notifying FriendlyFireMonitor");
				aPawn._FriendlyFireMonitor.Notify();
			}
			else
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::TakeDamage(): FF occurred, but APawn or FriendlyFireMonitor is None");
			}
			FFMultiplier=DamageType.Default.FFMultiplier;
			if (Level.Game.GetTimeElapsed() < 45)
			{
				FFMultiplier *= 2;
			}
			if (ClassIsChildOf(DamageType,'ProjectileDamage') || ClassIsChildOf(DamageType,'MilesDamage'))
			{
				if (instigatedBy != None && VSize(instigatedBy.Location - Location) < GetTraceDistance())
				{
					FFMultiplier *= 2;
				}
			}
			if (AGP_GameInfo(Level.Game) != None)
			{
				ActualROE=FFMultiplier * Damage;
				AGP_GameInfo(Level.Game).RecordFriendlyFire(KillerPRI,Self,ActualROE);
				if (instigatedBy != None && instigatedBy.Controller != None && instigatedBy.Controller.IsA('HumanController'))
				{
					HumanController(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You are hitting a friendly.");
				}
			}
		}
	}
	NotifyShotHit(instigatedBy,DamageType);
	CombatEffectivenessEvent(10);
	if (ResponsibleActor != None)
	{
		if (ClassIsChildOf(DamageType,'BleedDamage'))
		{
		}
		if (! ClassIsChildOf(DamageType,'AGP_FellDamage'))
		{
			ClientSetHitQuadrant(ResponsibleActor.Location);
		}
	}
	else
	{
		if (instigatedBy != None)
		{
			if (ClassIsChildOf(DamageType,'BleedDamage'))
			{
			}
			if (! ClassIsChildOf(DamageType,'AGP_FellDamage'))
			{
				ClientSetHitQuadrant(instigatedBy.Location);
			}
		}
	}
}
*/
void AAGP_Pawn::NotifyShotHit(APawn* instigatedBy, UaDamageType* DamageType)
{
	/*
	local PlayerController PC;
	if (instigatedBy != None && instigatedBy.Controller != None && instigatedBy.Controller != Controller)
	{
		PC=PlayerController(instigatedBy.Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
		{
			Switch(DamageType.Default.AmmoType)
			{
				case 3:
				case 4:
				case 15:
				case 2:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitGrenade();
				break;
				case 14:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitRocket();
				break;
				case 18:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitMachineGun();
				break;
				default:
				if (AGP_Weapon(instigatedBy.Weapon) != None && ! instigatedBy.Weapon.IsA('ThrowWeapon') && ! instigatedBy.Weapon.IsA('RocketWeapon'))
				{
					Switch(AGP_Weapon(instigatedBy.Weapon).StatWeaponType)
					{
						case 3:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitPistol();
							break;
						case 4:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitSniperRifle();
							break;
						case 5:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitMachineGun();
							break;
						case 6:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitAssaultRifle();
							break;
						default:
					}
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::ClientSetHitQuadrant(FVector HitSource)
{
	/*
	local FVector NormalizedVectorToSource;
	local float Angle;
	NormalizedVectorToSource=Normal(HitSource - Location);
	Angle=NormalizedVectorToSource Dot vect(1 0 0);
	if (Angle <= 1 && Angle > 0.7071)
	{
		FixedHitQuadrants[0]=1;
	}
	else
	{
		if (Angle <= 0.7071 && Angle >= -0.7071)
		{
			if (NormalizedVectorToSource.Y >= 0)
			{
				FixedHitQuadrants[3]=1;
			}
			else
			{
				FixedHitQuadrants[1]=1;
			}
		}
		else
		{
			FixedHitQuadrants[2]=1;
		}
	}
	NormalizedVectorToSource=NormalizedVectorToSource << Rotation;
	Angle=NormalizedVectorToSource Dot vect(1 0 0);
	if (Angle <= 1 && Angle > 0.7071)
	{
		HitQuadrants[0]=1;
	}
	else
	{
		if (Angle <= 0.7071 && Angle >= -0.7071)
		{
			if (NormalizedVectorToSource.Y >= 0)
			{
				HitQuadrants[3]=1;
			}
			else
			{
				HitQuadrants[1]=1;
			}
		}
		else
		{
			HitQuadrants[2]=1;
		}
	}
	*/
}
float AAGP_Pawn::GetInjuryPenalty(int32 test_health)
{
	return 0.75 + 0.25*(test_health / 100);
}
bool AAGP_Pawn::IsBleeding()
{
	return BleedHealth> 0 && !bHealingInProgress;
}
bool AAGP_Pawn::IsWounded()
{
/*
	if (Cast<ANPCBaseCivilianController>(Controller) != nullptr && Cast<ANPCBaseCivilianController>(Controller)->bNPCCanBeHealed && Health < 100 && ! Cast<ANPCBaseCivilianController>(Controller)->bHealedByPlayer)
	{
		return true;
	}
*/
	return BleedHealth > 0 || BleedMax > 0;
	
}
bool AAGP_Pawn::PressingSelfHealAction()
{
	return Cast<AHumanController>(Controller) != nullptr && Cast<AHumanController>(Controller)->bHealSelfAction != 0;
}
bool AAGP_Pawn::IsHealing()
{
	if (bHealingInterrupted)
	{
		return false;
	}
	else
	{
		if (Healer == this && PressingSelfHealAction() && Velocity.IsZero())
		{
			if (EventLab != nullptr)
			{
				//EventLab.ActorNotify(Self,31,Self,"ISHEALING");
			}
			return true;
		}
		if (Healer->PressingAction() && (Healer->Velocity).IsZero() && Velocity.IsZero())
		{
			if (EventLab != nullptr)
			{
				//EventLab.ActorNotify(Self,31,Self,"ISHEALING");
			}
			return true;
		}
		return false;
	}
}
bool AAGP_Pawn::FlashBleeding()
{
	float F;
	int32 i;
	F=2 * fBleedTimer;
	i=F;
	return (i%2 == 0);
}
void AAGP_Pawn::BleedTick(float DeltaTime)
{
	/*
	if (IsBleeding())
	{
		fBleedTimer += DeltaTime;
		if (fBleedTimer > GetBleedTime())
		{
			DoBleed();
			fBleedTimer=0;
		}
	}
	else
	{
		if (Healer != None)
		{
			if (Healer == Self)
			{
				fBleedTimer += DeltaTime;
				if (fBleedTimer > GetBleedTime())
				{
					DoBleed();
					fBleedTimer=0;
				}
			}
			if (IsHealing())
			{
				fHealPercent += DeltaTime / fHealDivisor;
				if (Healer != Self)
				{
					fBleedTimer=0;
				}
				if (fHealPercent >= 1)
				{
					StopBleeding();
				}
				else
				{
					SendHealingPercentage();
				}
			}
			else
			{
				if (fBleedTimer == 0)
				{
					HealingInterrupted();
				}
				else
				{
					if (fBleedTimer > 2)
					{
						HealingCanceled();
					}
					else
					{
						if (ReTryHeal())
						{
							if (Healer == Self)
							{
								MedicHealSelf();
							}
							else
							{
								UsedBy(Healer);
							}
						}
					}
				}
				if (Healer != Self)
				{
					fBleedTimer += DeltaTime;
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::CheckInventoryOverload()
{
	/*
	bCanSprint=True;
	if (getAltShoulderInventory() != None && getShoulderInventory() != None && getHandsInventory() != None)
	{
		if (getHandsInventory().IsA('PistolWeapon') || getHandsInventory().IsA('Item_Binoculars') || getHandsInventory().IsA('WEAPON_Javelin') || getHandsInventory().IsA('ThrowWeapon'))
		{
			return;
		}
		else
		{
			bCanSprint=False;
			SetWalking(True);
		}
	}
	*/
}
void AAGP_Pawn::ReTryHeal()
{
	/*
	if (Healer == Self)
	{
		if (Healer.PressingSelfHealAction() && bHealingInterrupted && Velocity.IsZero())
		{
			return true;
		}
		else
		{
			HealingInterrupted();
			return false;
		}
	}
	if (Healer.PressingAction() && bHealingInterrupted && (Healer.Velocity).IsZero() && Velocity.IsZero() && VSize(Healer.Location - Location) <= HumanController(Healer.Controller).GetTraceDistance())
	{
		return true;
	}
	else
	{
		HealingInterrupted();
		return false;
	}
	*/
}
void AAGP_Pawn::DoBleed(int32 drain)
{
	/*
	if (Role != 4)
	{
		return;
	}
	if (drain <= 0)
	{
		drain=1;
	}
	drain=Min(drain,BleedHealth);
	BleedHealth -= drain;
	TakeDamage(drain,Self,vect(0 0 0),vect(0 0 0),'BleedDamage');
	*/
}
float AAGP_Pawn::GetBleedTime()
{
	return fpBleedRate;
}
bool AAGP_Pawn::CanHealMe(APawn* H)
{
	if (Healer != nullptr)
	{
		return Healer == H;
	}
	else
	{
		return Cast<AAGP_Pawn>(H)->_InvMedPacks > 0 && IsFriend(H);
	}
}
void AAGP_Pawn::IsCarrying()
{
	/*
	if (Carrier.PressingAction() && (Carrier.Velocity).IsZero() && Velocity.IsZero())
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Self,"ISCARRYING");
		}
		return true;
	}
	*/
}
void AAGP_Pawn::IsPickingUp()
{
	/*
	if (Carrier.PressingAction() && (Carrier.Velocity).IsZero() && Velocity.IsZero())
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Self,"ISPICKINGUP");
		}
		return true;
	}
	*/
}
bool AAGP_Pawn::MustBeCarried()
{
	return bCanBeCarried;
}
bool AAGP_Pawn::CanCarryMe(APawn* C)
{
	if (Carrier != nullptr)
	{
		return Carrier == C;
	}
	return false;
}
void AAGP_Pawn::UsedBy(APawn* User)
{
	/*
	local bool bResumedHealing;
	local class<CommoLocalMessage>  CommoType;
	DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() " @ Self @ " by " @ User @ ")");
	if (Controller != None && Controller.IsA('NPCBaseController'))
	{
		if (NPCBaseController(Controller).UsedBy(User))
		{
			Log("UsedBy overridden by NPC controller");
			return true;
		}
	}
	if (CanHealMe(User) && User != Self)
	{
		if (bHealingInterrupted)
		{
			bHealingInterrupted=False;
			if (Healer != User)
			{
				HealingCanceled();
				Healer=AGP_Pawn(User);
			}
			else
			{
				bResumedHealing=True;
				Healer.HealLock(True,bResumedHealing);
			}
		}
		else
		{
			if (IsWounded())
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() I am wounded!");
				bHealingInProgress=True;
				Healer=AGP_Pawn(User);
				Healer.HealLock(true,false);
				Healer.NPCAlertPlayerEvent();
				NPCAlertPlayerEvent();
			}
			else
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() I am not wounded!");
			}
		}
		if (Healer == User)
		{
			if (! bResumedHealing || fBleedTimer > 5)
			{
				if (Healer.bIsWalking)
				{
					CommoType='CommoWhisper';
				}
				else
				{
					CommoType='CommoShout';
				}
				if (GetNetMode() != ENetMode::NM_Standalone)
				{
					HumanController(Healer.Controller).CommoSend(CommoType,30);
				}
			}
			return true;
		}
	}
	if (CanGiveMeObjective(User))
	{
		fObjectiveGivePercentage=0;
		ObjectiveGiver=AGP_Pawn(User);
		ObjectiveGiver.HealLock(True,false);
		return true;
	}
	return false;
	*/
}
void AAGP_Pawn::MedicHealSelf()
{
	/*
	local bool bResumedHealing;
	if (_InvSelfHealMedPacks > 0)
	{
		if (bHealingInterrupted)
		{
			bHealingInterrupted=False;
			if (Healer != Self)
			{
				HealingCanceled();
				Healer=Self;
			}
			else
			{
				bResumedHealing=True;
				HealLock(True,bResumedHealing);
			}
		}
		else
		{
			if (IsWounded())
			{
				bHealingInProgress=True;
				Healer=Self;
				HealLock(True, false);
			}
			else
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::MedicHealSelf() I am not wounded!");
			}
		}
	}
	*/
}
void AAGP_Pawn::HealLock(bool bLock, bool bSuppressWeaponMove)
{
	/*
	HumanController(Controller).LockPlayer(bLock,bLock);
	if (Weapon != None && ! bSuppressWeaponMove)
	{
		if (bLock)
		{
			Weapon.TempLowerWeapon();
		}
		else
		{
			if (Weapon.IsInState('BusyTempDown') || Weapon.IsInState('BusyTempLowering'))
			{
				Weapon.TempRaiseWeapon();
			}
		}
	}
	*/
}
void AAGP_Pawn::HealingInterrupted()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(Self,31,Self,"HEALINTERRUPTED");
	}
	Healer->HealLock(false,true);
	bHealingInterrupted=true;
	if (Healer == this)
	{
		iLastPercent=-1;
		return;
	}
	iLastPercent=-1;
}
void AAGP_Pawn::HealingCanceled()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"HEALCANCELED");
	}
	bHealingInterrupted=False;
	bHealingInProgress=False;
	fHealPercent=0;
	SendHealingComplete();
	Healer.HealLock(False);
	if (Healer != Self && Healer._InvMedPacks == 0)
	{
		Healer.PlayerReplicationInfo.bIsMedic=False;
	}
	Healer=None;
	*/
}
void AAGP_Pawn::StopBleeding()
{
	/*
	local PlayerController PC;
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,31,Self,"HEALSUCCESSFUL");
	}
	if (Healer != Self)
	{
		Healer.PlayerReplicationInfo.PScoreObjective(GetHealScore());
		PC=PlayerController(Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_WasHealed();
		}
		PC=PlayerController(Healer.Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_HealedTeammate();
		}
	}
	if (Healer == Self)
	{
		fpBleedRate=10;
		BleedHealth /= 2;
		ClientMessage("You have reduced your rate of bleeding.");
	}
	else
	{
		VirtualHealth=BleedMax;
		BleedMax=0;
		BleedHealth=0;
		fBleedTimer=0;
	}
	bHealingInProgress=False;
	bHealingInterrupted=False;
	fHealPercent=0;
	iLastPercent=-1;
	PlayerReplicationInfo.bCallForMedic=False;
	CombatEffectivenessEvent(11);
	SendHealingComplete();
	Healer.HealLock(False);
	if (Healer == Self)
	{
		if (_InvSelfHealMedPacks > 0)
		{
			_InvSelfHealMedPacks --;
		}
		Healer=None;
		return;
	}
	if (Healer._InvMedPacks > 0)
	{
		Healer._InvMedPacks --;
	}
	if (Healer._InvMedPacks == 0)
	{
		Healer.PlayerReplicationInfo.bIsMedic=False;
	}
	if (NPCBaseCivilianController(Controller) != None)
	{
		NPCBaseCivilianController(Controller).NotifyPlayerHealedNPC(Healer);
	}
	Healer=None;
	*/
}
void AAGP_Pawn::GetHealScore()
{
	/*
	switch(GetWoundSeverity())
	{
		case 2:
			return Max(BleedHealth,5);
		case 3:
			return Max(BleedHealth,10);
		case 4:
			return Max(BleedHealth,15);
		case 5:
			return Max(BleedHealth,20);
		default:
			return BleedHealth;
	}
	*/
}
void AAGP_Pawn::SendHealingPercentage()
{
	/*
	local int iPercent;
	local PlayerController myPC;
	local PlayerController hlPC;
	iPercent=fHealPercent * 100;
	if (iLastPercent != iPercent)
	{
		myPC=PlayerController(Controller);
		hlPC=PlayerController(Healer.Controller);
		if (Healer != Self)
		{
			Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'HealLocalMessage',iPercent,PlayerReplicationInfo,hlPC.PlayerReplicationInfo);
		}
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,hlPC,'HealLocalMessage',iPercent,PlayerReplicationInfo,hlPC.PlayerReplicationInfo);
		iLastPercent=iPercent;
	}
	*/
}
void AAGP_Pawn::SendHealingComplete()
{
	/*
	local PlayerController myPC;
	local PlayerController hlPC;
	myPC=PlayerController(Controller);
	hlPC=PlayerController(Healer.Controller);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'HealLocalMessage',-1);
	if (Healer != Self)
	{
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,hlPC,'HealLocalMessage',-1);
	}
	*/
}
void AAGP_Pawn::GetFirstObjectiveInventory()
{
	/*
	local Inventory Inv;
	local AGP_ObjectiveInventory ObjI;
	if (getInvContainerUtility() == None)
	{
		return None;
	}
	Inv=getInvContainerUtility().getFirstItem();
	if (Inv != None)
	{
		ObjI=AGP_ObjectiveInventory(Inv);
		if (ObjI != None)
		{
			return ObjI;
		}
		Inv=getInvContainerUtility().getNextItem();
	}
	*/
}
void AAGP_Pawn::CanGiveMeObjective(APawn* p)
{
	/*
	local AGP_ObjectiveInventory ObjI;
	if (ObjectiveGiver == None && IsFriend(p) && FVector::IsZero(Velocity) && FVector::IsZero(p.Velocity))
	{
		ObjI=AGP_Pawn(p).GetFirstObjectiveInventory();
		if (ObjI != None && CanPickupItem(ObjI))
		{
			return true;
		}
	}
	return false;
	*/
}
void AAGP_Pawn::IsGivingObjective()
{
	/*
	if (ObjectiveGiver.PressingAction() && FVector::IsZero(ObjectiveGiver.Velocity) && FVector::IsZero(Velocity))
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
}
void AAGP_Pawn::ObjectiveGiveTick(float DeltaTime)
{
	/*
	if (ObjectiveGiver != None)
	{
		if (IsGivingObjective())
		{
			fObjectiveGivePercentage += DeltaTime / 3;
			if (fObjectiveGivePercentage >= 1)
			{
				GiveObjective();
			}
			else
			{
				SendObjectiveGivePercentage();
			}
		}
		else
		{
			ObjectiveGiveCanceled();
		}
	}
	*/
}
void AAGP_Pawn::GiveObjective()
{
	/*
	local AGP_ObjectiveInventory Copy;
	local AGP_ObjectiveInventory ObjI;
	ObjI=ObjectiveGiver.GetFirstObjectiveInventory();
	Copy=Spawn(ObjI.Class,Self,,,rot(0 0 0));
	if (CanPickupItem(Copy))
	{
		Copy.InitFor(ObjI);
		Copy.GiveTo(Self);
		Copy.PickupFunction(Self);
		ObjI.DetachFromPawn(ObjectiveGiver);
		ObjectiveGiver.DeleteInventory(ObjI);
		ObjI.Destroy();
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GiveObjective()	Could not give the objective away!");
		Copy.Destroy();
	}
	ResetObjectiveGive();
	*/
}
void AAGP_Pawn::ObjectiveGiveCanceled()
{
	ResetObjectiveGive();
}
void AAGP_Pawn::ResetObjectiveGive()
{
	fObjectiveGivePercentage=0;
	ObjectiveGiver->HealLock(false, false);
	SendObjectiveGiveComplete();
	ObjectiveGiver=nullptr;
}
void AAGP_Pawn::SendObjectiveGivePercentage()
{
	/*
	local int iPercent;
	local PlayerController myPC;
	local PlayerController gvPC;
	iPercent=fObjectiveGivePercentage * 100;
	if (iLastObjectiveGivePercent != iPercent)
	{
		myPC=PlayerController(Controller);
		gvPC=PlayerController(ObjectiveGiver.Controller);
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'ObjectiveGiveLocalMessage',iPercent,PlayerReplicationInfo,gvPC.PlayerReplicationInfo);
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,gvPC,'ObjectiveGiveLocalMessage',iPercent,PlayerReplicationInfo,gvPC.PlayerReplicationInfo);
		iLastObjectiveGivePercent=iPercent;
	}
	*/
}
void AAGP_Pawn::SendObjectiveGiveComplete()
{
	/*
	local PlayerController myPC;
	local PlayerController gvPC;
	myPC=PlayerController(Controller);
	gvPC=PlayerController(ObjectiveGiver.Controller);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'ObjectiveGiveLocalMessage',-1);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,gvPC,'ObjectiveGiveLocalMessage',-1);
	*/
}
void AAGP_Pawn::PickupLock(bool bLock)
{
	//Cast<AHumanController>(Controller)->LockPlayer(bLock,bLock);
	if (Weapon != nullptr)
	{
		if (bLock)
		{
			Weapon->TempLowerWeapon(false);
		}
		else
		{
			Weapon->TempRaiseWeapon();
		}
	}
}
void AAGP_Pawn::PickupInterrupted()
{
	
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31, this,"PICKUPINTERRUPTED");
	}
	Carrier->PickupLock(false);
	
}
void AAGP_Pawn::PickupCanceled()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31,this,"PICKUPCANCELED");
	}
	Carrier->PickupLock(false);
	Carrier=nullptr;
}
void AAGP_Pawn::FinishedPickup()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31,Self,"PICKUPSUCCESSFUL");
	}
	Carrier->PickupLock(false);
	Carrier=nullptr;
}
void AAGP_Pawn::GetFallingDamage(float fallspeed)
{
	/*
	if (Physics == 17 && AGP_PlayerStart(Controller.StartSpot).bNoParaFallDamage && Weapon.IsA('Item_Parachute') && Weapon.Charge != 6)
	{
		return 0;
	}
	else
	{
		return Max(0,-100 * fallspeed + MaxFallSpeed / MaxFallSpeed);
	}
	*/
}
void AAGP_Pawn::SaveFallSpeed(float fallspeed)
{
	SavedFallSpeed=fallspeed;
}
void AAGP_Pawn::TakeFallingDamage()
{
	/*
	local float Shake;
	local int Damage;
	local int Dir;
	if (Level.debugFalling)
	{
		DebugLog(DEBUG_Multi,"TakeFallingDamage Vel" @ Velocity.Z @ "MaxFallSpd" @ MaxFallSpeed @ "Base" @ Base);
		if (Velocity.Z < -1 * MaxFallSpeed)
		{
			DebugLog(DEBUG_Multi,"TakeFallingDamage Damage" @ -100 * Velocity.Z + MaxFallSpeed / MaxFallSpeed);
		}
	}
	if (Velocity.Z < -0.5 * MaxFallSpeed)
	{
		MakeNoise(FMin(2,-0.5 * Velocity.Z / FMax(JumpZ,150)));
		if (Role == 4)
		{
			SaveFallSpeed(Velocity.Z);
			Damage=GetFallingDamage(Velocity.Z);
			if (Damage > 0)
			{
				if (Damage > 33 || Damage > Health)
				{
					TakeDamage(Damage,None,Location,vect(0 0 0),'FallDamage');
				}
				else
				{
					TakeDamage(Damage,None,Location,vect(0 0 0),'MinorFallDamage');
				}
			}
		}
		if (Controller != None)
		{
			Shake=FMin(1,-1 * Velocity.Z / MaxFallSpeed);
			if (FRand() < 0.5)
			{
				Dir=-1;
			}
			else
			{
				Dir=1;
			}
		}
	}
	if (Physics == 17 || IsInState('BusyParachuting') || FullBodyAnim == 4)
	{
		Damage=CheckParachuteLandingFall();
		if (Damage != 0)
		{
			if (Level.debugFalling)
			{
				Log("TakePLFDamage" @ Damage);
			}
			TakeDamage(Damage,None,Location,vect(0 0 0),'FallDamage');
		}
		if (! bIsDead)
		{
			ParachuteLanding(Damage != 0);
		}
	}
	*/
}
int32 AAGP_Pawn::AbsorbDamage(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	return Damage;
}
void AAGP_Pawn::AddVelocity(FVector NewVelocity)
{
	/*
	if (bIgnoreForces)
	{
		return;
	}
	if (Health <= 0)
	{
		GOTO JL00CE;
	}
	if (Physics == 11 || Physics == 9 && NewVelocity.Z > Default.JumpZ)
	{
		SetPhysics(2);
		if (Velocity.Z > 380 && NewVelocity.Z > 0)
		{
			NewVelocity.Z *= 0.5;
		}
		Velocity += NewVelocity;
	}
	else
	{
		Velocity.Y += NewVelocity.Y;
		Velocity.X += NewVelocity.X;
JL00CE:
	}
	*/
}
void AAGP_Pawn::PlayHit(float Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FVector Momentum)
{
	/*
	if (Damage <= 0 && Controller != None && ! Controller.bGodMode)
	{
		return;
	}
	CombatEffectivenessEvent(10);
	PlayHit(Damage,instigatedBy,HitLocation,DamageType,Momentum);
	*/
}
void AAGP_Pawn::PlayTakeHit(FVector HitLoc, int32 Damage, UaDamageType* DamageType)
{
	/*
	local Sound DesiredSound;
	DesiredSound=DamageType.GetPawnDamageSound();
	if (DesiredSound != None)
	{
		PlaySound(DesiredSound,0,1,,40,,False);
	}
	*/
}
void AAGP_Pawn::IsEnemy(APawn* Other)
{
	/*
	if (Other == Self)
	{
		return false;
	}
	if (PlayerReplicationInfo != None && Other.PlayerReplicationInfo != None)
	{
		return PlayerReplicationInfo.IsEnemy(Other.PlayerReplicationInfo);
	}
	return false;
	*/
}
bool AAGP_Pawn::IsFriend(APawn* Other)
{
	
	if (Other == this)
	{
		return true;
	}
	/*
	if (Controller != nullptr && Controller.IsA('NPCBaseController') && Cast<ANPCBaseController*>(Controller)->bNPCCanBeHealed)
	{
		return true;
	}
	if (PlayerReplicationInfo != nullptr && Other->PlayerReplicationInfo != nullptr)
	{
		return PlayerReplicationInfo->IsFriend(Other->PlayerReplicationInfo);
	}
	*/
	return false;
	
}
void AAGP_Pawn::ReportCivilianEvent(APawn* Other, float OthersDistance_sq, AController* hcInstigator)
{
	/*
	local int EventDistance_sq;
	if (Other == None)
	{
		return;
	}
	Log("AGP_Pawn: ReportCivilianEvent Called with: " @ OthersDistance_sq @ " and " $ NPCBaseCivilianController(Other.Controller));
	if (Other.Controller != None)
	{
		if (NPCBaseController(Other.Controller).bReportableCivi)
		{
			EventDistance_sq=NPCBaseController(Other.Controller).iReportEventDistance * NPCBaseController(Other.Controller).iReportEventDistance;
			Log("Calling: ReportCivilianEvent with: " @ OthersDistance_sq @ " and " $ NPCBaseController(Other.Controller));
			Log("NPC ReportDistanc is : " @ NPCBaseController(Other.Controller).iReportEventDistance @ " EventDistance_sq = " @ EventDistance_sq);
			if (OthersDistance_sq < EventDistance_sq)
			{
				TriggerEvent(NPCBaseController(Other.Controller).ReportedEvent,None,None);
				NPCBaseController(Other.Controller).bReportableCivi=False;
				HumanController(hcInstigator).bNPCReported=True;
			}
		}
	}
	else
	{
		Log("Controller is NONE in ReportCivillianEvent");
	}
	*/
}
void AAGP_Pawn::IsReportableCivi(APawn* Other)
{
	/*
	if (Other == Self)
	{
		Log("Reporting Me");
		return true;
	}
	if (Other.Controller != None)
	{
		if (Other.Controller.IsA('NPCBaseCivilianController'))
		{
			if (NPCBaseCivilianController(Other.Controller).bReportableCivi)
			{
				Log("Fine... this is something that should be reportable");
				return true;
			}
		}
	}
	else
	{
		Log("Controller still NONE!!!");
	}
	Log("Guess Not!");
	return false;
	*/
}
void AAGP_Pawn::CivilianReportDistance(APawn* Other)
{
	/*
	if (Other.Controller != None)
	{
		Log("Wonder how far we have to be: " @ NPCBaseCivilianController(Other.Controller).iReportEventDistance);
		return NPCBaseCivilianController(Other.Controller).iReportEventDistance;
	}
	*/
}
void AAGP_Pawn::CivilianReportEvent(APawn* Other)
{
	/*
	if (Other.Controller != None)
	{
		return NPCBaseCivilianController(Other.Controller).ReportedEvent;
	}
	*/
}
/*
void AAGP_Pawn::SetDeathMonitor (ScriptObject mon)
{
	_DeathMonitor=mon;
}
*/
void AAGP_Pawn::DropUtilityInventory()
{
	/*
	local Inventory Inv;
	local AGP_ObjectiveInventory ObjI;
	local name AttachBone;
	if (getInvContainerUtility() == None)
	{
		return;
	}
	Inv=getInvContainerUtility().getFirstItem();
	if (Inv != None)
	{
		ObjI=AGP_ObjectiveInventory(Inv);
		if (ObjI != None)
		{
			AttachBone=ObjI.ThirdPersonActor.AttachmentBone;
			ObjI.Velocity=Velocity * 0.85;
			ObjI.DropFrom(GetBoneCoords(AttachBone).Origin);
		}
		Inv=getInvContainerUtility().getNextItem();
	}
	*/
}
void AAGP_Pawn::DropWeaponsAfterDeath()
{
	/*
	local Weapon weap;
	if (Role == 4)
	{
		weap=Weapon;
		if (weap != None)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('WeaponBone').Origin);
			Weapon=None;
		}
		weap=Weapon(getShoulderInventory());
		if (weap != None)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('RSlungWeapon').Origin);
		}
		DropUtilityInventory();
		weap=Weapon(getAltShoulderInventory());
		if (weap != None)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('RSlungWeapon').Origin);
		}
		weap=Weapon(getHipInventory());
		if (weap != None)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('ButtPouch').Origin);
		}
	}
	*/
}
void AAGP_Pawn::ClientStopSideEffects()
{
	/*
	local SideEffect SE;
	ForEach AllActors('SideEffect',SE)
	{
		if (SE.Owner == Controller)
		{
			SE.End();
		}
	}
	*/
}
/*
void AAGP_Pawn::Died (Controller Killer, class<DamageType>  DamageType, FVector HitLocation,FVector HitDir,Actor.BoneInfo Bone)
{
	local AGP_Objective Objective;
	local int i;
	if (VisionDistActor != None)
	{
		VisionDistActor.Destroy();
	}
	if (AudioDistActor != None)
	{
		AudioDistActor.Destroy();
	}
	DestroyDebugIcons();
	if (DrivenVehicle == None)
	{
		DropWeaponsAfterDeath();
	}
	ClientStopSideEffects();
	if (_DeathMonitor != None)
	{
		_DeathMonitor.Notify();
	}
	if (Team != None)
	{
		if (removeAsLeader() == false)
		{
			removeAsSubordinate();
		}
		checkTeamSize();
		Team.printTeam();
	}
	DebugLog(DEBUG_Stats,"Current objective trigger on death: " $ GetCurrentTrigger() $ " objective: " $ AGP_Objective(GetCurrentTrigger()));
	Objective=AGP_Objective(GetCurrentTrigger());
	if (Objective != None)
	{
		Objective.PawnDied(Self);
	}
	if (bDeleteMe)
	{
		return;
	}
	if (Healer != None)
	{
		HealingCanceled();
	}
	BleedHealth=0;
	if (DrivenVehicle != None)
	{
		Velocity=DrivenVehicle.Velocity;
		DrivenVehicle.DriverDied();
	}
	Health=Min(0,Health);
	if (DrivenVehicle == None)
	{
		Level.Game.Killed(Killer,Controller,Self,DamageType);
	}
	else
	{
		Level.Game.Killed(Killer,DrivenVehicle.Controller,Self,DamageType);
	}
	if (Killer != None)
	{
		TriggerEvent(Event,Self,Killer.Pawn);
	}
	else
	{
		TriggerEvent(Event,Self,None);
	}
	Velocity.Z *= 1.3;
	if (IsHumanControlled())
	{
		PlayerController(Controller).ForceDeathUpdate();
	}
	PlayDying(DamageType,HitLocation,HitDir,Bone);
	if (Level.Game != None && Level.Game.bGameEnded)
	{
		return;
	}
	if (! bPhysicsAnimUpdate && ! IsLocallyControlled())
	{
		ClientDying(DamageType,HitLocation,HitDir,Bone);
	}
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,11,Killer);
	}
	if (HumanController(Controller) != None)
	{
		if (Killer != None)
		{
			if (Killer.Pawn.IsA('AGP_Character_NPC'))
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByAI();
			}
			else
			{
				if (Killer.PlayerReplicationInfo != None && Controller.PlayerReplicationInfo.IsFriend(Killer.PlayerReplicationInfo))
				{
					Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByFriendlyFire();
					for (i=0; i<Level.Game.Stats.PlayerStats.Length; i++)
					{
						if (Level.Game.Stats.PlayerStats[i] != None)
						{
							Level.Game.Stats.PlayerStats[i].StatEvent_ROEFriendlyFireDeaths();
						}
					}
				}
			}
		}
		else
		{
			if (bHitByIED)
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByObject();
			}
		}
	}
	if (Self.IsA('NPC_civilian'))
	{
		if (HumanController(Killer) != None)
		{
			Level.Game.Stats.PlayerStats[HumanController(Killer).PlayerStatsIndex].StatEvent_ROECivilianDeaths();
		}
		else
		{
			if (bHitByIED)
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_ROECivilianDeathsByIED();
			}
		}
	}
}
*/
/*
void AAGP_Pawn::PlayDying (UaDamageType DamageType, FVector HitLoc,FVector HitDir,Actor.BoneInfo Bone)
{
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PlayDying() " $ Self);
	SetCollision(False,False,False);
	if (FrontAuxCyl != None)
	{
		FrontAuxCyl.Destroy();
	}
	if (BackAuxCyl != None)
	{
		BackAuxCyl.Destroy();
	}
	bUseAuxCollision=False;
	AmbientSound=None;
	bCanTeleport=False;
	bReplicateMovement=False;
	bTearOff=True;
	bPlayedDeath=True;
	HitDamageType=DamageType;
	TakeHitLocation=HitLoc;
	AnimBlendParams(1,0);
	if (RagdollLifeSpan > 0)
	{
		LifeSpan=RagdollLifeSpan;
	}
	DebugLog(DEBUG_Anim,"AGP_Pawn::PlayDying() Pawn(" @ Self @ ") Controller(" @ Controller @ ") Owner(" @ Owner @ ") Weapon(" @ Weapon @ ")");
	GotoState('Dying');
	PlayDyingAnimation(DamageType,HitLoc);
}
*/
void AAGP_Pawn::CloseEyes()
{
	FVector eyeloc;
	FRotator eyerot;
	eyeloc.Y=0.504;
	eyeloc.X=-0.031;
	eyeloc.Z=-0.067;
	eyerot.Yaw=1474;
	eyerot.Pitch=852;
	eyerot.Roll=0;
	//SetBoneLocation('bn_lblink',eyeloc,1);
	//SetBoneRotation('bn_lblink',eyerot,,1);
	eyerot.Yaw=-973;
	eyerot.Pitch=-534;
	eyerot.Roll=0;
	eyeloc.Y=0.57;
	eyeloc.X=0.027;
	eyeloc.Z=0;
	//SetBoneLocation('bn_rblink',eyeloc,1);
	//SetBoneRotation('bn_rblink',eyerot,,1);
}
void AAGP_Pawn::CloseHands()
{
	FRotator rightthumbrot;
	FRotator rightindexrot;
	FRotator rightpinkyrot;
	FRotator leftthumbrot;
	FRotator leftindexrot;
	FRotator leftpinkyrot;
	rightthumbrot.Roll=-3164;
	rightthumbrot.Pitch=204;
	rightthumbrot.Yaw=2092;
	//SetBoneRotation('rthumb1',rightthumbrot,,1);
	rightthumbrot.Roll=-614;
	rightthumbrot.Pitch=-1091;
	rightthumbrot.Yaw=2473;
	//SetBoneRotation('rthumb2',rightthumbrot,,1);
	rightindexrot.Roll=1071;
	rightindexrot.Pitch=-278;
	rightindexrot.Yaw=7209;
	//SetBoneRotation('rindex1',rightindexrot,,1);
	rightindexrot.Roll=0;
	rightindexrot.Pitch=0;
	rightindexrot.Yaw=4123;
	//SetBoneRotation('rindex2',rightindexrot,,1);
	rightindexrot.Roll=0;
	rightindexrot.Pitch=0;
	rightindexrot.Yaw=1619;
	//SetBoneRotation('rindex3',rightindexrot,,1);
	rightpinkyrot.Roll=851;
	rightpinkyrot.Pitch=1213;
	rightpinkyrot.Yaw=10429;
	//SetBoneRotation('rpinky1',rightpinkyrot,,1);
	rightpinkyrot.Roll=1033;
	rightpinkyrot.Pitch=186;
	rightpinkyrot.Yaw=3979;
	//SetBoneRotation('rpinky2',rightpinkyrot,,1);
	rightpinkyrot.Roll=1918;
	rightpinkyrot.Pitch=141;
	rightpinkyrot.Yaw=3521;
	//SetBoneRotation('rpinky3',rightpinkyrot,,1);
	leftthumbrot.Roll=-4891;
	leftthumbrot.Pitch=442;
	leftthumbrot.Yaw=-381;
	//SetBoneRotation('lthumb1',leftthumbrot,,1);
	leftthumbrot.Roll=-1107;
	leftthumbrot.Pitch=778;
	leftthumbrot.Yaw=-2004;
	//SetBoneRotation('lthumb2',leftthumbrot,,1);
	leftthumbrot.Roll=-203;
	leftthumbrot.Pitch=396;
	leftthumbrot.Yaw=-1051;
	//SetBoneRotation('lthumb3',leftthumbrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-4443;
	//SetBoneRotation('lindex1',leftindexrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-5543;
	//SetBoneRotation('lindex2',leftindexrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-2051;
	//SetBoneRotation('lindex3',leftindexrot,,1);
	leftpinkyrot.Roll=1261;
	leftpinkyrot.Pitch=-836;
	leftpinkyrot.Yaw=-5660;
	//SetBoneRotation('lpinky1',leftpinkyrot,,1);
	leftpinkyrot.Roll=1253;
	leftpinkyrot.Pitch=-110;
	leftpinkyrot.Yaw=-8522;
	//SetBoneRotation('lpinky2',leftpinkyrot,,1);
	leftpinkyrot.Roll=1257;
	leftpinkyrot.Pitch=-210;
	leftpinkyrot.Yaw=-3665;
	//SetBoneRotation('lpinky3',leftpinkyrot,,1);
}
void AAGP_Pawn::PlayDyingAnimation(UaDamageType* DamageType, FVector HitLoc)
{
	/*
	local FVector shotDir;
	local FVector hitLocRel;
	local FVector deathAngVel;
	local FVector shotStrength;
	local float maxDim;
	local string RagSkelName;
	local KarmaParamsSkel skelParams;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (GetNetMode() != ENetMode::NM_DedicatedServer && Level.PhysicsDetailLevel == 0 && GetWorld()->GetTimeSeconds() - LastRenderTime > 3)
		{
			Log("PlayDyingAnimation() - detail too low, destroying pawn");
			Destroy();
			return;
		}
		if (Level.GamePlayMode != 1 && OutOfBounds <= 0 && AnimManager == None || ! AnimManager.CanPlayDeathAnim())
		{
			if (RagdollOverride != "")
			{
				RagSkelName=RagdollOverride;
			}
			else
			{
				DebugLog(DEBUG_Anim,"PlayDying: No RagdollOverride");
			}
			if (RagSkelName != "")
			{
				KMakeRagdollAvailable();
			}
			if (KIsRagdollAvailable() && RagSkelName != "")
			{
				skelParams=KarmaParamsSkel(KParams);
				skelParams.KSkeleton=RagSkelName;
				KParams=skelParams;
				StopAnimating(True);
				CloseEyes();
				CloseHands();
				if (DamageType != None && DamageType.Default.bKUseOwnDeathVel)
				{
					RagDeathVel=DamageType.Default.KDeathVel;
					RagDeathUpKick=DamageType.Default.KDeathUpKick;
					RagShootStrength=DamageType.Default.KDamageImpulse;
					DebugLog(DEBUG_Karma,"PlayDyingAnimation() Player was killed by DamageType= " $ DamageType);
					if (ClassIsChildOf(DamageType,'ProjectileDamage') && bIsProne)
					{
						RagDeathUpKick=0;
						RagSpinScale *= RagProneProjectileScale;
						RagInvInertia *= RagProneProjectileScale;
						RagShootStrength *= RagProneProjectileScale;
					}
				}
				shotDir=Normal(TearOffMomentum);
				shotStrength=RagDeathVel * shotDir;
				hitLocRel=TakeHitLocation - Location;
				hitLocRel.X *= RagSpinScale;
				hitLocRel.Y *= RagSpinScale;
				if (VSize(TearOffMomentum) < 0.01)
				{
					DebugLog(DEBUG_Karma,"TearOffMomentum magnitude of Zero");
					deathAngVel=VRand() * 18000;
				}
				else
				{
					deathAngVel=RagInvInertia * hitLocRel Cross shotStrength;
				}
				skelParams.KStartLinVel.X=0.6 * Velocity.X;
				skelParams.KStartLinVel.Y=0.6 * Velocity.Y;
				skelParams.KStartLinVel.Z=1 * Velocity.Z;
				skelParams.KStartLinVel += shotStrength;
				if (Velocity.Z > -10)
				{
					skelParams.KStartLinVel.Z += RagDeathUpKick;
				}
				skelParams.KStartAngVel=deathAngVel;
				maxDim=Max(CollisionRadius,CollisionHeight);
				skelParams.KShotStart=TakeHitLocation - 1 * shotDir;
				skelParams.KShotEnd=TakeHitLocation + 2 * maxDim * shotDir;
				skelParams.KShotStrength=RagShootStrength;
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagShootStrength= " $ RagShootStrength);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagSpinScale= " $ RagSpinScale);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagInvInertia= " $ RagInvInertia);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagDeathVel= " $ RagDeathVel);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagDeathUpKick= " $ RagDeathUpKick);
				KSetBlockKarma(True);
				SetPhysics(14);
				return;
			}
		}
		else
		{
			if (bPhysicsAnimUpdate)
			{
				bReplicateMovement=False;
			}
			bPlayedDeath=True;
		}
	}
	*/
}
bool AAGP_Pawn::isDead()
{
	return bIsDead || bNetAlreadyDead || Health <= 0;
}
void AAGP_Pawn::ClientAlertOutOfBounds(int32 Seconds)
{
	/*
	if (PlayerController(Controller).MyHUD != None)
	{
		if (bOOBIsTrainingVolume)
		{
			PlayerController(Controller).MyHUD.DisplayCenteredMessage(1.1,"You have left the training area!","You have" @ Seconds @ "seconds to return...");
		}
		else
		{
			PlayerController(Controller).MyHUD.DisplayCenteredMessage(1.1,"You have left the combat zone!","You have" @ Seconds @ "seconds to return...");
		}
	}
	*/
}
void AAGP_Pawn::OutOfBoundsNotifyKillPlayer()
{
	/*
	if (PlayerController(Controller).MyHUD != None)
	{
		PlayerController(Controller).MyHUD.DisplayCenteredMessage(3,"Failed to return to combat.");
	}
	*/
}
void AAGP_Pawn::ClientAlertReturnedToCombat()
{
	/*
	if (PlayerController(Controller).MyHUD != None)
	{
		if (bOOBIsTrainingVolume)
		{
			PlayerController(Controller).MyHUD.DisplayCenteredMessage(3,"You have returned to the training area.");
		}
		else
		{
			PlayerController(Controller).MyHUD.DisplayCenteredMessage(3,"You have returned to combat.");
		}
	}
	*/
}
void AAGP_Pawn::OutOfBoundsCheck()
{
	/*
	if (OutOfBounds > 0)
	{
		TimeOutOfBounds += 0.5;
		ClientAlertOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
	}
	if (CurrentZoneTimeToKill - TimeOutOfBounds <= 0)
	{
		StopCustomTimer('OutOfBoundsCheck');
		OutOfBounds ++;
		if (bOOBIsTrainingVolume)
		{
			HumanController(Controller).DisplayMissionFailure("","You failed to stay within training areas.","Come back tomorrow and try again.",128,128,6,'None');
		}
		else
		{
			KilledBy(Self);
		}
	}
	*/
}
void AAGP_Pawn::AnimateDead()
{
}
void AAGP_Pawn::GetDeathAnimName(bool bEndLoop)
{
}
bool AAGP_Pawn::CanTransitionDeath(EDeathAnim NewAnim)
{
	switch(DeathAnim)
	{
		case EDeathAnim::DEATH_None:
			return true;
		case EDeathAnim::DEATH_ParachuteDead:
			return NewAnim == EDeathAnim::DEATH_PLFDead || NewAnim == EDeathAnim::DEATH_PLFMilesDead;
		default:
			return DeathAnim == NewAnim;
	}
}
void AAGP_Pawn::SetDeathAnim(EDeathAnim NewAnim)
{
	if (CanTransitionDeath(NewAnim))
	{
		DeathAnim=NewAnim;
	}
	else
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::SetDeathAnim() Can't change the death anim from(" @ DeathAnim @ ") to (" @ NewAnim @ ")");
	}
}
void AAGP_Pawn::Destroyed()
{

	/*
	if (VisionDistActor != None)
	{
		VisionDistActor.Destroy();
	}
	if (AudioDistActor != None)
	{
		AudioDistActor.Destroy();
	}
	DebugLog(DEBUG_NetClean,"AGP_Pawn::Destroyed() for player " $ OwnerName $ " " $ Self);
	DebugLog(DEBUG_Multi,"Resetting reload time on destruction");
	fTimeSinceLastReload=0;
	if (Role != 4)
	{
		if (Level.GetClientController() != None)
		{
			Level.GetClientController().NotifyPawnDestroyed(Self);
		}
		if (PlayerReplicationInfo != None)
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	" $ PlayerReplicationInfo @ PlayerReplicationInfo.myPawn);
			PlayerReplicationInfo.myPawn=None;
		}
		if (Controller != None)
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	controller: " $ Controller);
			if (Controller.IsA('PlayerController'))
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	HUD: " $ PlayerController(Controller).MyHUD);
			}
			if (Controller.IsA('HumanController'))
			{
				DebugLog(DEBUG_HUD,"AGP_Pawn::Destroyed() - Praying for AGP_HUD not to crash! PawnOwner was " $ AGP_HUD(HumanController(Controller).MyHUD).PawnOwner,True);
				AGP_HUD(HumanController(Controller).MyHUD).bDrawHUD=False;
			}
		}
	}
	*/
	DiscardInventory();
	if (_OpticsDevice != nullptr)
	{
		_OpticsDevice->Destroy();
		_OpticsDevice=nullptr;
	}
	if (TeamRole != nullptr)
	{
		TeamRole->Destroy();
		TeamRole= nullptr;
	}
	if (TeamClass != nullptr)
	{
		//TeamClass->Destroy();
		TeamClass= nullptr;
	}
	Super::Destroyed();
}
bool AAGP_Pawn::removeAsLeader()
{
	AAGP_Pawn* new_leader= nullptr;
	bool new_sub=false;
	int32 i=0;
	int32 j = 0;
	float high_leader;
	int32 high_rank;
	if (nSubordinates == 0)
	{
		return false;
	}
	//DebugLog(DEBUG_Team,"AGP_Pawn::removeAsLeader() Removing as leader " @ Self);
	high_leader=0;
	high_rank=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i]->rank > high_rank)
		{
			high_rank=Subordinate[i]->rank;
			high_leader=Subordinate[i]->fLeadership;
			new_leader=Subordinate[i];
		}
		else
		{
			if (Subordinate[i]->rank == high_rank && Subordinate[i]->fLeadership > high_leader)
			{
				high_leader=Subordinate[i]->fLeadership;
				new_leader=Subordinate[i];
			}
		}
	}
	/*
	if (this->ownsMentalModel())
	{
		new_leader->setMentalModel(this->getMentalModel());
	}
	*/
	if (Leader != nullptr)
	{
		Leader->replaceSubordinate(this,new_leader);
	}
	else
	{
		Team->replaceSubordinate(this,new_leader);
	}
	//DebugLog(DEBUG_Team,"AGP_Pawn::removeAsLeader	Elevating this leader " @ new_leader);
	//new_sub=new_leader->removeAsLeader();
	if (new_sub == true)
	{
		new_leader->nSubordinates=nSubordinates;
	}
	else
	{
		new_leader->nSubordinates=nSubordinates - 1;
	}
	j=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] != new_leader)
		{
			Subordinate[i]->Leader=new_leader;
			new_leader->Subordinate[j]=Subordinate[i];
			j ++;
		}
	}
	new_leader->Leader=Leader;
	new_leader->idUnitNumber=idUnitNumber;
	new_leader->idRole=idRole;
	//new_leader->TeamRole=TeamRole->spawnNewRole();
	new_leader->TeamRole->my_AGP_Pawn=new_leader;
	return true;
	
}
void AAGP_Pawn::checkTeamSize()
{
	/*
	local int i;
	local AGP_Pawn squad_leader;
	local AGP_Pawn leader_1;
	local AGP_Pawn leader_2;
	local AGP_Pawn swap_pawn;
	local bool Resize;
	if (TeamRole.squadBasedRole() == false)
	{
		return;
	}
	squad_leader=TeamRole.getUnitLeader();
	Resize=False;
	if (squad_leader == None)
	{
		return;
	}
	if (squad_leader.nSubordinates > 1)
	{
		if (squad_leader.Subordinate[0].TeamRole.getUnitSize() < 3)
		{
			Resize=True;
			leader_1=squad_leader.Subordinate[0];
			leader_2=squad_leader.Subordinate[1];
		}
		else
		{
			if (squad_leader.Subordinate[1].TeamRole.getUnitSize() < 3)
			{
				Resize=True;
				leader_1=squad_leader.Subordinate[1];
				leader_2=squad_leader.Subordinate[0];
			}
		}
	}
	if (Resize == true)
	{
		if (leader_2.TeamRole.getUnitSize() > 3)
		{
			leader_2.nSubordinates --;
			swap_pawn=leader_2.Subordinate[leader_2.nSubordinates];
			swap_pawn.Leader=leader_1;
			leader_1.Subordinate[leader_1.nSubordinates]=swap_pawn;
			leader_1.nSubordinates ++;
		}
		else
		{
			if (leader_2.rank > leader_1.rank || leader_2.rank == leader_1.rank && leader_2.fLeadership > leader_1.fLeadership)
			{
				swap_pawn=leader_1;
				leader_1=leader_2;
				leader_2=swap_pawn;
			}
			for (i=0; i<leader_2.nSubordinates; i++)
			{
				leader_1.addSubordinate(leader_2.Subordinate[i]);
			}
			leader_1.addSubordinate(leader_2);
			leader_2.TeamRole=leader_1.TeamRole.spawnSubordinateRole();
			leader_2.TeamRole.my_AGP_Pawn=leader_2;
			leader_2.nSubordinates=0;
			leader_1.Leader.removeSubordinate(leader_2);
		}
	}
	*/
}
bool AAGP_Pawn::replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub)
{
	int32 i;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] == old_sub)
		{
			Subordinate[i]=new_sub;
			return true;
		}
	}
	//DebugLog(DEBUG_Team,"Could not replace" @ old_sub @ new_sub);
	return false;
}
bool AAGP_Pawn::removeAsSubordinate()
{
	if (Leader == nullptr)
	{
		return false;
	}
	else
	{
		return Leader->removeSubordinate(this);
	}
}
bool AAGP_Pawn::removeSubordinate(AAGP_Pawn* Remove)
{
	int32 i;
	int32 j;
	bool Found;
	Found=false;
	j=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] != Remove)
		{
			Subordinate[j]=Subordinate[i];
			j ++;
		}
		else
		{
			Found=true;
		}
	}
	if (Found)
	{
		nSubordinates --;
	}
	else
	{
		//DebugLog(DEBUG_Team,Remove @ "could not be found in" @ Self);
	}
	return Found;
}

void AAGP_Pawn::addSubordinate(AAGP_Pawn* Add)
{
	/*
	Add.Leader=Self;
	Subordinate[nSubordinates]=Add;
	nSubordinates ++;
	*/
}

void AAGP_Pawn::SetCurrentFFMonitor (UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_FriendlyFireMonitor= nullptr;
		UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::SetCurrentFFMonitor(None)"));
	}
	else
	{
		//DebugLog(DEBUG_Multi,"AGP_Pawn::SetCurrentFFMonitor(" $ mon.Name $ ")");
		_FriendlyFireMonitor=mon;
	}
}


void AAGP_Pawn::SetCurrentFireMonitor (UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_FireMonitor= nullptr;
		UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::SetCurrentFireMonitor(None)"));
	}
	else
	{
		//DebugLog(DEBUG_Multi,"AGP_Pawn::SetCurrentFireMonitor(" $ mon.Name $ ")");
		_FireMonitor=mon;
	}
}

bool AAGP_Pawn::CommoCanHandSignal()
{
	if (bIsProne)
	{
		return false;
	}
	else
	{
		if (Weapon != nullptr && Weapon->IsA(ARocketWeapon::StaticClass()))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

/* ======================================================================================
 * AGP function CommoCycleState
 * Cycles to the next available commo state.  For radio, the function checks
 * if the player has radio access.
 * effects: changes current CommoState
 * last modified by:  capps 1/2/02
 * ======================================================================================
 */
void AAGP_Pawn::CommoCycleState()
{
	switch (CommoState)
	{
	case ECommoType::COMMOTYPE_Hand:		CommoState = ECommoType::COMMOTYPE_Whisper;		break;
	case ECommoType::COMMOTYPE_Whisper: 	CommoState = ECommoType::COMMOTYPE_Shout;			break;
	case ECommoType::COMMOTYPE_Shout:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Radio;
		}
		break;
	case ECommoType::COMMOTYPE_Radio:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else if (PlayerReplicationInfo->IsSquadLeader() && !PlayerReplicationInfo->bGuerrillaPS)
		{
			CommoState = ECommoType::COMMOTYPE_Squad;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Global;
		}
		break;
	case ECommoType::COMMOTYPE_Squad:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Global;
		}
		break;
	case ECommoType::COMMOTYPE_Global:
		CommoState = ECommoType::COMMOTYPE_Hand;
		break;
	default:
		//DebugLog(DEBUG_Warn, "AGP_Pawn::CommoCycleState() Unknown CommoState("@CommoState@")");
		CommoState = ECommoType::COMMOTYPE_Global;
		break;
	}
	/*
	if (CommoState == ECommoType::COMMOTYPE_Hand && !CommoCanHandSignal())
	{
		CommoState = ECommoType::COMMOTYPE_Whisper;
	}
	*/
}


void AAGP_Pawn::SetCommoState(ECommoType Type)
{

	switch(Type)
	{
		case ECommoType::COMMOTYPE_Hand:
			/*
			if(!CommoCanHandSignal())	return;
			else						break;
			*/
		case ECommoType::COMMOTYPE_Squad:
			if(!PlayerReplicationInfo->IsSquadLeader())	return;
			else										break;
	}

	CommoState = Type;
	
}

/* ======================================================================================
 * AGP function SetCurrentVolumeMonitor
 *
 * effects:  sets the volume monitor for the pawn
 * last modified by:  mpr
 * ======================================================================================
 */

void AAGP_Pawn::SetCurrentVolumeMonitor (UScriptObject* vol)
{
	if (vol == nullptr)
	{
		_VolumeMonitor= nullptr;
	}
	else
	{
		_VolumeMonitor=vol;
	}
}


/* ======================================================================================
 * AGP function SetCurrentVolume
 *
 * effects:  sets the volume the pawn is in
 * last modified by:  mpr
 * ======================================================================================
 */

void AAGP_Pawn::SetCurrentVolume (AVolume* vol)
{
	if (vol == nullptr)
	{
		_CurrentVolume = nullptr;
		//		Log("AGP_Pawn::SetCurrentVolume(None)");
	}
	else
	{
		_CurrentVolume = nullptr;
		//		Log("AGP_Pawn::SetCurrentVolume(" $ vol.tag $ ")");
	}

	if (_VolumeMonitor != nullptr)
	{
		if (vol != nullptr)
		{
			//			Log("AGP_Pawn::SetCurrentVolume(" $ vol.tag $ ") - calling _VolumeMonitor.Update()");
		}
		_VolumeMonitor->update();
	}
}

AVolume* AAGP_Pawn::GetCurrentVolume()
{
	return _CurrentVolume;
}

void AAGP_Pawn::EnterVolume (AVolume* vol)
{
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != nullptr)
	{
		//Controller->EnterVolume(vol);
	}
	if (vol == nullptr)
	{
		return;
	}
	SetCurrentVolume(vol);
}


void AAGP_Pawn::ExitVolume (AVolume* vol)
{
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != nullptr)
	{
		//Controller.ExitVolume(vol);
	}
	if (vol == nullptr)
	{
		return;
	}
	if (_CurrentVolume == vol)
	{
		SetCurrentVolume(nullptr);
	}
}


void AAGP_Pawn::SetCurrentTriggerMonitor (UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor= nullptr;
	}
	else
	{
		_TriggerMonitor=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor2 (UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor2= nullptr;
	}
	else
	{
		_TriggerMonitor2=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor3 (UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor3= nullptr;
	}
	else
	{
		_TriggerMonitor3=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor4 (UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor4= nullptr;
	}
	else
	{
		_TriggerMonitor4=trig;
	}
}

void AAGP_Pawn::SetCurrentTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		_CurrentTrigger=nullptr;
	}
	else
	{
		_CurrentTrigger=trig;
		//DebugLog(DEBUG_Stats,"AGP_Pawn::SetCurrentTrigger(" $ trig.Tag $ ")");
	}
	if (_TriggerMonitor != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor->update();
		}
	}
	if (_TriggerMonitor2 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor2->update();
		}
	}
	if (_TriggerMonitor3 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor3->update();
		}
	}
	if (_TriggerMonitor4 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor4->update();
		}
	}
}
AActor* AAGP_Pawn::GetCurrentTrigger()
{
	return _CurrentTrigger;
}
void AAGP_Pawn::EnterTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		return;
	}
	SetCurrentTrigger(trig);
}
void AAGP_Pawn::ExitTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		return;
	}
	if (_CurrentTrigger == trig)
	{
		SetCurrentTrigger(nullptr);
	}
}
/*
void AAGP_Pawn::SetAnimationMonitor (AnimationController AM)
{
	_AnimationMonitor=AM;
}
*/
/*
void AAGP_Pawn::SetAmmoMonitor (ScriptObject monitor, bool weaponly)
{
	local Inventory Item;
	if (AGP_Weapon(Weapon) != None)
	{
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetAmmoMonitor Tracking ammo in gun");
		}
		AGP_Weapon(Weapon).SetAmmoMonitor(monitor);
	}
	if (! weaponly)
	{
		Item=_InvShoulder.getFirstItem();
		if (AGP_Weapon(Item) != None)
		{
			AGP_Weapon(Item).SetAmmoMonitor(monitor);
		}
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetAmmoMonitor tracking shoulder.");
		}
	}
}
*/
/*
void AAGP_Pawn::SetJammedMonitor (ScriptObject monitor)
{
	if (AGP_Weapon(Weapon) != None)
	{
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetJammedMonitor  Tracking gun jams");
		}
		AGP_Weapon(Weapon).SetJammedMonitor(monitor);
	}
}
*/
void AAGP_Pawn::InduceJam()
{
	//AGP_Weapon(Weapon).ClientHandleMisfire();
}
void AAGP_Pawn::IsOutOfAmmo(bool weaponly)
{
	/*
	local Inventory Item;
	local Weapon Gun;
	DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  called with argument weapononly=" $ weaponly);
	if (weaponly)
	{
		if (Weapon == None)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, but no weapon.");
			return true;
		}
		if (Weapon.GetCurrentAmmoType() == None)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, but no magazine in weapon.");
			return true;
		}
		if (Weapon.GetCurrentAmmoType().HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, magazine has ammo.");
			return false;
		}
		else
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, magazine is empty.");
			return true;
		}
	}
	if (Weapon != None)
	{
		if (Weapon.HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; weapon has ammo.");
			return false;
		}
	}
	Item=_InvShoulder.getFirstItem();
	if (Item != None && Item.IsA('Weapon'))
	{
		Gun=Weapon(Item);
		if (Gun.HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; weapon on shoulder has ammo.");
			return false;
		}
	}
	DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; found no ammo in hand or shoulder weapon.");
	return true;
	*/
}
void AAGP_Pawn::getBestAmmoFromWeapon(AWeapon* weap, AAmmunition* AmmoName)
{
	//return Max(weap.AmmoType.AmmoAmount,weap.GetClipCount(weap.GetBestClip()));
}
void AAGP_Pawn::CombatEffectivenessEvent(ECombatEffectEvent Event, float DeltaTime)
{
	if(GetNetMode()==ENetMode::NM_Client)
	{
		return;
	}
	switch(Event)
	{
		case ECombatEffectEvent::CE_EVENT_BULLETWHIP:
			CE_RecoveryPenalty *= 0.85;
			CE_PanicValue += 1;
			break;
		case ECombatEffectEvent::CE_EVENT_BULLETCRACK:
			CE_RecoveryPenalty *= 0.75;
			CE_PanicValue += 0.75;
			break;
		case ECombatEffectEvent::CE_EVENT_FLASHBANG:
			CE_RecoveryPenalty *= UKismetMathLibrary::FMax(1 - DeltaTime,0.001);
			CE_PanicValue += 1;
			break;
		case ECombatEffectEvent::CE_EVENT_OBJECTIVE:
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_SUPPORTING:
			break;
		case ECombatEffectEvent::CE_EVENT_CLIMBING:
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_EXPLOSION:
			CE_PanicValue += 0.75;
			break;
		case ECombatEffectEvent::CE_EVENT_SPRINT:
			CE_RecoveryPenalty= UKismetMathLibrary::FMax(CE_RecoveryPenalty * (DeltaTime / (DeltaTime + 0.000008)), 0.001);
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_JUMP:
			CE_RecoveryPenalty *= 0.5;
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_DIVE:
			CE_RecoveryPenalty *= 0.5;
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_INJURY:
		case ECombatEffectEvent::CE_EVENT_BLEEDING:
			break;
		default:
			break;
	}
}

float AAGP_Pawn::GetPostureComponent()
{
	float Result;
	if (bIsProne)
	{
		Result=0.25;					// Prone
	}
	else
	{
		if (bIsCrouched)
		{
			Result=0.09;			// Crouched
		}
		else
		{
			if (Weapon != nullptr && Cast<AWeapon>(Weapon)->CheckJavelinTube())
			{
				return 0;
			}
			else
			{
				Result=0;
			}
		}
	}
	if (IsZoomed())				// Unzoomed Penalty
	{
		Result += 0.7;
	}
	if (IsSupported())
	{
		Result += 0.45;			// Supported
	}
	if (IsLeaning())
	{
		Result *= 0.9;
	}
	if (Result >= 1)
	{
		Result = 1;
	}
	return Result;
}
void AAGP_Pawn::GetWeapEffectivenessComponent()
{
	/*
	local float Result;
	if (Controller != None && Controller.bNoWeaponPenalty)
	{
		return 1;
	}
	if (AGP_Weapon(Weapon) == None)
	{
		return 0;
	}
	if (AGP_Weapon(Weapon).IsOpFor() && ! bGuerrillaMesh)
	{
		Result=0;
	}
	else
	{
		if (! Weapon.bGuerrillaWeapon && bGuerrillaMesh)
		{
			Result=0;
		}
		else
		{
			Result=1;
		}
	}
	return Result;
	*/
}
void AAGP_Pawn::GetFriendlyMorale(float TMBonusRadius)
{
	/*
	local int i;
	for (i=0; i<32; i++)
	{
		if (PlayerReplicationInfo != None && PlayerReplicationInfo.Team != None)
		{
			if (PlayerReplicationInfo.Team.TeamList[i] != None && PlayerReplicationInfo.Team.TeamList[i] != PlayerReplicationInfo)
			{
				if (VSize(PlayerReplicationInfo.Team.TeamList[i].GetPawnLocation() - Location) <= TMBonusRadius)
				{
					return 0.5;
				}
			}
		}
	}
	return 0;
	*/
}
void AAGP_Pawn::GetMoraleComponent()
{
	/*
	local PlayerReplicationInfo FTL;
	local PlayerReplicationInfo SQL;
	SQL=PlayerReplicationInfo.GetSquadLeader();
	FTL=PlayerReplicationInfo.GetFTLeader();
	if (PlayerReplicationInfo != SQL && PlayerReplicationInfo.LinkedToSquadLeader)
	{
		return 1;
	}
	else
	{
		if (PlayerReplicationInfo != SQL && PlayerReplicationInfo != FTL && PlayerReplicationInfo.LinkedToFTLeader)
		{
			return 0.8;
		}
		else
		{
			if (PlayerReplicationInfo.LinkedTo != 0)
			{
				return 0.5;
			}
			else
			{
				return 0;
			}
		}
	}
	*/
}
void AAGP_Pawn::GetPanicComponent()
{
	/*
	local float Result;
	Result=FClamp(CE_PanicValue,0,1);
	Result=1 - Result;
	return Result;
	*/
}
void AAGP_Pawn::GetHealthSubcomponent()
{
	/*
	local float Result;
	local float MaxHealthPenalty;
	MaxHealthPenalty=0.35;
	Result=Health / 100 * MaxHealthPenalty;
	Result=FClamp(Result + 1 - MaxHealthPenalty,0,1);
	return Result;
	*/
}
void AAGP_Pawn::GetBleedingSubcomponent()
{
	/*
	local float Result;
	local float MaxBleedPenalty;
	MaxBleedPenalty=0.15;
	if (IsBleeding() && Level.GamePlayMode != 1)
	{
		Result=- MaxBleedPenalty;
	}
	return Result;
	*/
}
void AAGP_Pawn::GetInjuryFactor()
{
	/*
	local float Result;
	Result=GetHealthSubcomponent() + GetBleedingSubcomponent();
	Result=FClamp(Result,0,1);
	return Result;
	*/
}
float AAGP_Pawn::GetMovementFactor()
{
	/*
	
	float Result;
	if (FVector::IsZero(Velocity))
	{
		Result=1;
	}
	else
	{
		if (bIsWalking)
		{
			Result=0.9;
		}
		else
		{
			Result=0.7;
		}
	}
	return Result;
	*/
	return 0;    //FAKE /ELiZ
}
void AAGP_Pawn::GetWeapQualifyFactor()
{
	/*
	local float Result;
	if (! PlayerReplicationInfo.bQualifiedSniper && Weapon != None && Weapon.IsA('SniperRifle') && GetNetMode() != ENetMode::NM_Standalone)
	{
		Result=0.75;
	}
	else
	{
		Result=1;
	}
	return Result;
	*/
}
float AAGP_Pawn::GetActivityFlag()
{
	float Result;
	Result=CE_ActivityValue;
	return Result;
}
void AAGP_Pawn::RecoveryTick(float DeltaTime)
{
	/*
	CE_RecoveryPenalty=FClamp(CE_RecoveryPenalty,0.18,1);
	CE_PanicValue=FClamp(CE_PanicValue,0,1);
	if (HumanController(Controller) == None || HumanController(Controller)._FlashSoundTime <= 0 && HumanController(Controller)._GrenadeShakeTime <= 0)
	{
		CE_PanicValue=FMax(CE_PanicValue - 0.45 * CE_RecoveryPenalty * DeltaTime,0);
	}
	if (! bIsSprinting && ! IsBusy() && ! PressingAction() && Physics == 1)
	{
		if (Weapon == None || ! Weapon.IsBusy() || Weapon.IsTempBusy())
		{
			CE_ActivityValue=FMax(CE_ActivityValue - 0.5 * DeltaTime,0);
			if (CE_MeterValue == CE_DesiredValue)
			{
				CE_RecoveryPenalty=FMin(CE_RecoveryPenalty + 0.075 * DeltaTime,1);
			}
		}
		else
		{
			CE_ActivityValue=FMax(CE_ActivityValue - 0.1 * DeltaTime,0);
			if (CE_MeterValue == CE_DesiredValue)
			{
				CE_RecoveryPenalty=FMin(CE_RecoveryPenalty + 0.025 * DeltaTime,1);
			}
		}
	}
	if (CE_DesiredValue < CE_MeterValue)
	{
		CE_MeterValue=FMax(CE_MeterValue - DeltaTime,CE_DesiredValue);
	}
	else
	{
		CE_MeterValue=FMin(CE_MeterValue + 0.75 * DeltaTime * CE_RecoveryPenalty,CE_DesiredValue);
	}
	*/
}
void AAGP_Pawn::UpdateCombatEffectiveness(float DeltaTime)
{
	/*
	local float COEFF_Pos;
	local float COEFF_Wea;
	local float COEFF_Mor;
	local float COEFF_Pan;
	local float COMP_Posture;
	local float COMP_WeapEffectiveness;
	local float COMP_Morale;
	local float COMP_Panic;
	local float FACT_Injury;
	local float FACT_Movement;
	local float FACT_WeapQualify;
	local float FLAG_Activity;
	local float OldMeterValue;
	local float CEMWhenActive;
	if (GetNetMode() == ENetMode::NM_Client || PlayerReplicationInfo == None)
	{
		return;
	}
	OldMeterValue=CE_MeterValue;
	CEMWhenActive=0.1;
	COEFF_Pos=0.71;
	COEFF_Wea=0.07;
	COEFF_Mor=0.13;
	COEFF_Pan=0.09;
	COMP_Posture=GetPostureComponent();
	COMP_WeapEffectiveness=GetWeapEffectivenessComponent();
	COMP_Morale=GetMoraleComponent();
	COMP_Panic=GetPanicComponent();
	FACT_Injury=GetInjuryFactor();
	FACT_Movement=GetMovementFactor();
	FACT_WeapQualify=GetWeapQualifyFactor();
	FLAG_Activity=GetActivityFlag();
	if (FLAG_Activity > 0)
	{
		CE_DesiredValue=CEMWhenActive;
	}
	else
	{
		CE_DesiredValue=COEFF_Pos * COMP_Posture + COEFF_Wea * COMP_WeapEffectiveness + COEFF_Mor * COMP_Morale + COEFF_Pan * COMP_Panic;
		CE_DesiredValue *= FACT_Injury * FACT_Movement * FACT_WeapQualify;
	}
	CE_DesiredValue=FClamp(CE_DesiredValue,0,1);
	if (FLAG_Activity > 0)
	{
		CE_MaxMeterValue=CEMWhenActive;
	}
	else
	{
		CE_MaxMeterValue=COEFF_Pos * COMP_Posture + COEFF_Wea * COMP_WeapEffectiveness + COEFF_Mor * COMP_Morale + COEFF_Pan * 1;
		CE_MaxMeterValue *= GetHealthSubcomponent() * FACT_WeapQualify;
	}
	RecoveryTick(DeltaTime);
	*/
}
bool AAGP_Pawn::IsSniperClass(APawn* p)
{
	
	if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_M82_Sniper::StaticClass()))
	{
		return true;
	}
	else
	{
		if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_M24_Sniper::StaticClass()))
		{
			return true;
		}
		else
		{
			if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_MosinNagant_Sniper::StaticClass()))
			{
				return true;
			}
			else
			{
				if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_SVD_Sniper::StaticClass()))
				{
					return true;
				}
			}
		}
	}
	return false;
}
void AAGP_Pawn::infront(FVector vec, APawn* Who)
{
	/*
	local FVector LookDir;
	local FVector AimDir;
	LookDir= Vector(Who.Rotation);
	LookDir=Normal(LookDir);
	AimDir=vec - Who.Location;
	AimDir=Normal(AimDir);
	return LookDir Dot AimDir;
	*/
}
void AAGP_Pawn::StealthBlend(float DeltaTime)
{
	/*
	local Pawn p;
	local int TeamNum;
	local PlayerReplicationInfo aPRI;
	local float fSniperVisibilityProbability;
	local HumanController HC;
	return;
	HC=HumanController(Controller);
	if (HC == None)
	{
		return;
	}
	ForEach DynamicActors(Class'Pawn',p)
	{
		if (p.IsA('HumanController') || p.IsA('NPC_soldier'))
		{
			aPRI=p.Controller.PlayerReplicationInfo;
			TeamNum=aPRI.Team.TeamIndex;
			if (TeamNum == PlayerReplicationInfo.Team.TeamIndex)
			{
				p.Controller.iAlpha=0;
				AGP_Pawn(p).fStealthBlendTime=0;
			}
			else
			{
				if (! IsSniperClass(p))
				{
					p.Controller.iAlpha=0;
					AGP_Pawn(p).fStealthBlendTime=0;
				}
				else
				{
					if (p.bIsSprinting && p.IsBusy() && AGP_Pawn(p).PressingAction() && ! p.FVector::IsZero(Velocity))
					{
						AGP_Pawn(p).fStealthBlendTime=0;
						p.iAlpha=0;
					}
					else
					{
						AGP_Pawn(p).fStealthBlendTime=AGP_Pawn(p).fStealthBlendTime + DeltaTime;
					}
					if (AGP_Pawn(p).fStealthBlendTime == 0)
					{
					}
					else
					{
						if (AGP_Pawn(p).fStealthBlendTime > 60)
						{
							AGP_Pawn(p).fStealthBlendTime=60;
						}
						fSniperVisibilityProbability=1;
						if (bIsSprinting && IsBusy() && PressingAction() && FVector::IsZero(Velocity))
						{
							fSniperVisibilityProbability=fSniperVisibilityProbability * 1.4;
						}
						if (Weapon == None || ! Weapon.IsBusy() || Weapon.IsTempBusy())
						{
							fSniperVisibilityProbability=fSniperVisibilityProbability * 1.8;
						}
						if (fSniperVisibilityProbability > 1)
						{
							fSniperVisibilityProbability=1;
						}
						fSniperVisibilityProbability=fSniperVisibilityProbability * 255;
						fSniperVisibilityProbability=fSniperVisibilityProbability * AGP_Pawn(p).fStealthBlendTime / 60;
						p.iAlpha=255 - fSniperVisibilityProbability;
						if (p.iAlpha > 255)
						{
							p.iAlpha=255;
						}
					}
				}
			}
		}
	}
	*/
}
/*
void AAGP_Pawn::FastTick(float DeltaTime)
{
}
*/

void AAGP_Pawn::Cower(int32 Type)
{
	if (Type == 1)
	{
		//LoopAnim('CivSitPanic',1,0.05);
	}
	else
	{
		//LoopAnim('DocPanic',1,0.05);
	}
}
void AAGP_Pawn::PickIdle(int32 pickOne)
{
	
	if (pickOne == 1)
	{
		//LoopAnim('DocIdleA',1,0.05);
	}
	else
	{
		if (pickOne == 2)
		{
			//LoopAnim('DocIdleB',1,0.05);
		}
		else
		{
			//LoopAnim('DocIdleC',1,0.05);
		}
	}
}
int32 AAGP_Pawn::MoralCheck(float fNPCMoral)
{
	if (fNPCMoral > Health)
	{
		return 0;
	}
	return 1;
}
bool AAGP_Pawn::IsHeDead()
{
	if (Health < 0)
	{
		return true;
	}
	return false;
}
void AAGP_Pawn::SetMoveTarget(AActor* NewTarget)
{
	if (Controller != nullptr)
	{
		//Controller->MoveTarget=NewTarget;
	}
}
void AAGP_Pawn::NPC_Drop2Prone(int32 Type)
{
	if (Type == 1)
	{
		//AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim('Drop2PrnLg',1,0.05,15);
	}
	else
	{
		//AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim('Drop2PrnNo',1,0.05,15);
	}
}
void AAGP_Pawn::NPC_Reload()
{
	/*
	BeginState();
	EnableChannelNotify(15,1);
	Reload3p(3);
	if (_AnimationMonitor == None)
	{
		AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,'Spine02');
		if (bIsProne)
		{
			PlayAnim('PrnLgRld',1,0.05,15);
		}
		else
		{
			PlayAnim('StdLgRld',1,0.05,15);
		}
	}
	*/
}
bool AAGP_Pawn::NPC_isGotBuzzed()
{
	if (bGotBulletBuzzed == true)
	{
		bGotBulletBuzzed=false;
		return true;
	}
	return false;
}
int32 AAGP_Pawn::NPC_ActorType()
{
	switch (Actor_t)
	{
		case EATypes::NPC_none:
			return 0;
		case EATypes::NPC_civilian:
			return 1;
		case EATypes::NPC_soldier:
			return 2;
		case EATypes::NPC_doctor:
			return 3;
		case EATypes::NPC_pilot:
			return 4;
		case EATypes::NPC_friendly:
			return 5;
		case EATypes::NPC_squad:
			return 6;
		default:
			return 0;
	}
	return 0;
}
void AAGP_Pawn::NPC_Serpentine(float SerpTime)
{
	//SerpentineTime=SerpTime;
}
FRotator AAGP_Pawn::SwapAxes(FRotator R)
{
	FRotator t;
	t=R;
	R.Pitch=- t.Yaw;
	R.Yaw=t.Roll;
	R.Roll=t.Pitch;
	return R;
}

void AAGP_Pawn::EyeTrack()
{
	/*
	local NPCRealHeroController RHController;
	local FVector RHAdjustment;
	local FVector LookDir;
	local FVector AimDir;
	local FRotator LEyeRot;
	local FRotator REyeRot;
	local FRotator NeckRot;
	local float Dot;
	local FRotator Dir;
	local FRotator RDir;
	local FVector pos;
	local float fyaw;
	HController=HumanController(Level.GetClientController());
	Player=AGP_Pawn(Level.GetClientPawn());
	RHController=NPCRealHeroController(Controller);
	if (RHController != None)
	{
		RHAdjustment.Z=RHController.fpVertCollisionOffsetDown;
	}
	if (HController == None || Player == None || ! bEyeTrack)
	{
		return;
	}
	LookDir= Vector(Rotation);
	LookDir=Normal(LookDir);
	AimDir=Player.Location - Location;
	AimDir=Normal(AimDir);
	Dot=LookDir Dot AimDir;
	if (Dot > 0.6)
	{
		NeckRot=GetBoneRotation('Neck');
		AimDir=Player.Location - RHAdjustment - Location;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw;
		if (Dot > 0.9)
		{
			fyaw=RDir.Yaw;
			flastYaw=fyaw;
		}
		else
		{
			fyaw=flastYaw;
		}
		RDir=SwapAxes(RDir);
		NeckRot=RDir;
		if (Dot > 0.9)
		{
			SetBoneDirection('Neck',NeckRot);
		}
		pos=GetBoneCoords('BN_LEyeBall').Origin;
		pos.Z=Location.Z;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw + fyaw;
		RDir=SwapAxes(RDir);
		LEyeRot=RDir;
		SetBoneDirection('BN_LEyeBall',LEyeRot);
		pos=GetBoneCoords('BN_REyeBall').Origin;
		pos.Z=Location.Z;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw + fyaw;
		RDir=SwapAxes(RDir);
		REyeRot=RDir;
		SetBoneDirection('BN_REyeBall',REyeRot);
	}
	else
	{
		if (Dot < -0.5)
		{
			RDir=Rotation;
			Dir=LookDir;
			flastYaw=0;
			RDir.Yaw=RDir.Yaw - Dir.Yaw;
			fyaw=RDir.Yaw;
			RDir=SwapAxes(RDir);
			NeckRot=RDir;
			SetBoneDirection('Neck',NeckRot);
			REyeRot=RDir;
			SetBoneDirection('BN_REyeBall',REyeRot);
			LEyeRot=RDir;
			SetBoneDirection('BN_LEyeBall',LEyeRot);
		}
	}
	*/
}

void AAGP_Pawn::NotifyFire(AAGP_Weapon* W, FString Parms)
{
	
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(W,17,Self,Parms);
	}
	
}

void AAGP_Pawn::NotifyTrace(AAGP_Weapon* W, AActor* HitActor, FString Parms)
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(W,18,HitActor,Parms);
	}
}

void AAGP_Pawn::NotifyThrow(AThrowWeapon* W, FString Parms)
{
	if (EventLab != nullptr)
	{
		//EventLab->ActorNotify(W,19,this,Parms);
	}
}

void AAGP_Pawn::MatchEnding()
{
	
	UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn.MatchEnding() - Hiding pawn"));
	//SetDrawType(0);
	
}

void AAGP_Pawn::DestroyDebugIcons()
{
	/*
	if (MyDebug_InterruptIcon != nullptr)
	{
		MyDebug_InterruptIcon->Destroy();
	}
	if (MyDebug_MentalStateIcon != nullptr)
	{
		MyDebug_MentalStateIcon->Destroy();
	}
	if (MyDebug_ActionIcon != nullptr)
	{
		MyDebug_ActionIcon->Destroy();
	}
	*/
}
void AAGP_Pawn::AttachDebugIcons()
{
	/*
	local Object.BoneOffset BO;
	MyDebug_InterruptIcon=Spawn('DebugIcon_Interrupt');
	MyDebug_ActionIcon=Spawn('DebugIcon_Action');
	MyDebug_MentalStateIcon=Spawn('DebugIcon_MentalState');
	if (MyDebug_MentalStateIcon != None)
	{
		MyDebug_MentalStateIcon.bHidden=False;
		MyDebug_MentalStateIcon.SetDrawScale(1);
		BO.VOffset=vect(-33 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_MentalStateIcon,BO);
	}
	if (MyDebug_ActionIcon != None)
	{
		MyDebug_ActionIcon.bHidden=False;
		MyDebug_ActionIcon.SetDrawScale(1);
		BO.VOffset=vect(0 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_ActionIcon,BO);
	}
	if (MyDebug_InterruptIcon != None)
	{
		MyDebug_InterruptIcon.bHidden=False;
		MyDebug_InterruptIcon.SetDrawScale(1);
		BO.VOffset=vect(33 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_InterruptIcon,BO);
	}
	*/
}
void AAGP_Pawn::CreateVisualHearingDebugSpheres(float fpHearingDistance, float fpVisualDistance)
{
	UE_LOG(LogTemp, Warning, TEXT("CreateVisualHearingDebugSpheres() entered"));
	if (fpVisualDistance > 0)
	{
		//VisionDistActor=CreateDebugSphere(true);
		//VisionDistActor.SetDrawScale(fpVisualDistance * 1 / 128);
	}
	if (fpHearingDistance > 0)
	{
		//AudioDistActor=CreateDebugSphere(false);
		//AudioDistActor.SetDrawScale(fpHearingDistance * 1 / 128);
	}
}
void AAGP_Pawn::CreateDebugSphere(bool bVisionSphere)
{
	/*
	local DebugSphere D;
	Log("CreateDebugSphere entered - visionsphere:" $ bVisionSphere);
	if (bVisionSphere)
	{
		D=Spawn('DebugSphereVisual');
	}
	else
	{
		D=Spawn('DebugSphereAudio');
	}
	if (D != None)
	{
		D.bHidden=False;
		D.SetDrawScale(1);
		AttachToBone(D,'BN_HeadEnd');
	}
	return D;
	*/
}
/*
void AAGP_Pawn::DisplayDebug (UCanvas* Canvas, float YL, float YPos)
{
	DisplayDebug(Canvas,YL,YPos);
	Canvas.SetDrawColor(0,128,255);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("Pawn threat level: " $ fpPlayerThreatLevel $ " adjusted: " $ GetThreatLevel());
	YPos += YL;
	Canvas.SetPos(4,YPos);
}
*/
void AAGP_Pawn::GetThreatLevel()
{
	/*
	if (IsInState('BusyReloading'))
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
	}
	if (Weapon == None)
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.45;
	}
	else
	{
		if (Weapon.IsInState('BusyFixingJam'))
		{
			return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.6;
		}
		else
		{
			if (Weapon.IsInState('BusyReloading'))
			{
				return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
			}
			else
			{
				if (Weapon.IsInState('BusyFiring'))
				{
					return fpPlayerThreatLevel + fpPlayerThreatLevel * 0.25;
				}
				else
				{
					if (Weapon.IsInState('BusySupporting'))
					{
						return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
					}
					else
					{
						if (Weapon.IsInState('BusyChangingFireMode'))
						{
							return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
						}
					}
				}
			}
		}
	}
	if (bHealingInProgress || bLockMovement)
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.9;
	}
	return fpPlayerThreatLevel;
	*/
}
void AAGP_Pawn::NPCAlertPlayerEvent()
{
	
	AController* ctrlrIterator = nullptr;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (! IsHumanControlled())
	{
		return;
	}
	/*
	ctrlrIterator=Level.ControllerList;
	if (ctrlrIterator != nullptr)
	{
		if (! ctrlrIterator.IsA('NPCBaseController'))
		{
		}
		NPCBaseController(ctrlrIterator).AddHistoryContact(Self,True);
		ctrlrIterator=ctrlrIterator.nextController;
	}
	*/
}
void AAGP_Pawn::AltFire(float F)
{
	if (bIsSprinting)
	{
		if (Cast<AHumanController>(Controller) != nullptr)
		{
			Cast<AHumanController>(Controller)->ClientMessage("You are too busy sprinting to adjust your weapon.");
		}
		return;
	}
	if (Weapon != nullptr)
	{
		Weapon->AltFire(F);
	}
}
bool AAGP_Pawn::isKilledByIED()
{
	return bHitByIED;
}




//myOwn



bool AAGP_Pawn::IsLeaning()
{
	return false;
}


void AAGP_Pawn::Client_Set_Weapon_Implementation(TSubclassOf<ASoldierClass> SC)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		if (SC)
		{
			//auto FreshObject = NewObject<TSubclassOf<ASoldierClass>>(this, SC->GetFName(), RF_NoFlags, SC->GetDefaultObject());
			//TeamClass = FreshObject;


			//Spawing 
			/*
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			ASoldierClass* NewSoldierClass = GetWorld()->SpawnActor<ASoldierClass>(SC, SpawnInfo);
			FString T= Cast<ASoldierClass>(NewSoldierClass)->_ShortName;
			TArray<TSubclassOf<AInventory>> DefaultInventory = Cast<ASoldierClass>(NewSoldierClass)->ClassEquipment;
			*/
			
			if (Mesh_1P!=nullptr)
			{
				Mesh_1P->SetRelativeLocation(FVector(-15.0f, 0.0f, -10.0f));
				Mesh_1P->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
				Mesh_1P->bOnlyOwnerSee = true;
				Mesh_1P->bOwnerNoSee = false;
				Mesh_1P->bCastDynamicShadow = false;
				Mesh_1P->CastShadow = false;
				if(CustomMesh_1P != nullptr)
				{
					Mesh_1P->SetSkeletalMesh(CustomMesh_1P);
				}
				if (Anim_1P != nullptr)
				{
					Mesh_1P->PlayAnimation(Anim_1P, true);
					
				}
			}


			/*
			if (Anim_3P != nullptr)
			{
				Mesh_3P->SetAnimation(Anim_3P);
				Mesh_3P->PlayAnimation(Anim_3P, true);
			}
			*/
			if (Mesh_3P->SkeletalMesh)
			{
				USkeleton* MySkeleton = Mesh_3P->SkeletalMesh->GetSkeleton();
				if (MySkeleton != nullptr)
				{
					TArray<UAnimationAsset*> AllAnimations = GetAllAnimationOfSkeleton(MySkeleton);
					if (AllAnimations.Num() > 0)
					{
						Mesh_3P->PlayAnimation(AllAnimations[0], true);
					}
					else
					{
						if (Anim_3P != nullptr)
						{
							Mesh_3P->PlayAnimation(Anim_3P, true);
						}
					}
				}
			}

		}
	}
}

void AAGP_Pawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(GetLocalRole() == ROLE_Authority)
	{
		//Health = GetMaxHealth();
		//SpawnDefaultInventory();
	}

	
	// set initial mesh visibility (3rd person view)
	//UpdatePawnMeshes();

	// create material instance for setting team colors (3rd person view)
	//for (int32 iMat = 0; iMat < GetMesh()->GetNumMaterials(); iMat++)
	//{
	//	MeshMIDs.Add(GetMesh()->CreateAndSetMaterialInstanceDynamic(iMat));
	//}

	// play respawn effects
	if (GetNetMode() != NM_DedicatedServer)
	{
		//if (RespawnFX)
		//{
		//	UGameplayStatics::SpawnEmitterAtLocation(this, RespawnFX, GetActorLocation(), GetActorRotation());
		//}
		//if (RespawnSound)
		//{
		//	UGameplayStatics::PlaySoundAtLocation(this, RespawnSound, GetActorLocation());
		//}
	}
}



void AAGP_Pawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAGP_Pawn, Weapon);
	
	//first Person Stuff
	DOREPLIFETIME(AAGP_Pawn, CustomMesh_1P);
	DOREPLIFETIME(AAGP_Pawn, Anim_1P);

	//Third Person Stuff
	DOREPLIFETIME(AAGP_Pawn, Mesh_3P);
	DOREPLIFETIME(AAGP_Pawn, Anim_3P);

	DOREPLIFETIME(AAGP_Pawn, Health);
	DOREPLIFETIME(AAGP_Pawn, TeamClass);

	DOREPLIFETIME(AAGP_Pawn, bIsProne);
	DOREPLIFETIME(AAGP_Pawn, bIsSprinting);
	DOREPLIFETIME(AAGP_Pawn, bIsWalking);
	DOREPLIFETIME(AAGP_Pawn, bIsCrouching);
	DOREPLIFETIME(AAGP_Pawn, bIsCrouched2);

	DOREPLIFETIME(AAGP_Pawn, AGP_Speed);
	DOREPLIFETIME(AAGP_Pawn, AGP_Direction);
}


bool AAGP_Pawn::IsPlayerPawn()
{
	return GetController() != nullptr && Cast<AHumanController>(GetController())->bIsPlayer;
}

bool AAGP_Pawn::IsHumanControlled()
{
	return (Cast<APlayerController>(GetController()) != nullptr);
}

/*
const FString AAGP_Pawn::GetAnimationPath() const
{
	FString FileName = FString::Printf(TEXT("A_Character_Idle_%s.A_Character_Idle_%s"), *AvatarCharacterName, *AvatarCharacterName);
	return FString::Printf(TEXT("%s%s%s%s%s"), *ANIMATION_PATH, *AvatarCharacterName, *F_DLIM, *FileName, *R_DLIM);
}
*/



TArray<UAnimationAsset*> AAGP_Pawn::GetAllAnimationOfSkeleton(USkeleton* Skeleton)
{
	TArray<UAnimationAsset*> AnimsArray;

	if (Skeleton == NULL) { return AnimsArray; }

	for (TObjectIterator<UAnimationAsset> Itr; Itr; ++Itr)
	{
		//if (Skeleton->GetWorld() != (*Itr)->GetWorld()) { continue; }

		if (Skeleton == (*Itr)->GetSkeleton())
		{
			AnimsArray.Add(*Itr);
		}
	}
	return AnimsArray;
}

