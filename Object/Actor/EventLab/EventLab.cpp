// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/AGP_VehicleFactory.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/AAGameplay/DamageDetector/DamageDetector.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpGet/HttpGet.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Keypoint/InterpolationPoint/InterpolationPoint.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/AGP_Trigger/LookTrigger/LookTrigger.h"
#include "AA29/Object/Actor/AAGameplay/MarksmanTarget/MarksmanTarget.h"
#include "AA29/Object/Actor/MedExam/MedExam.h"
#include "AA29/Object/Actor/AGP_Trigger/NoiseTrigger/NoiseTrigger.h"
#include "AA29/Object/Actor/AAGameplay/NPC_EEGuard/NPC_EEGuard.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedStudent/NPC_MedStudent.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/TriggerVolume/RiskVolume/RiskVolume.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/Actor/AGP_UseTrigger/StaticMeshSwitcher/StaticMeshSwitcher.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/DecoMesh/Mover/TargetMover/TargetMover.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

void AEventLab::LoadEditorIcon()
{

#if WITH_EDITORONLY_DATA
	bool UBillboardComponentExists = false;

	TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* ThisObject : ObjectArray)
	{
		if (ThisObject->GetName() == "Sprite")
		{
			if (Texture != NULL)
			{
				SpriteComponent = Cast<UBillboardComponent>(ThisObject);
				SpriteComponent->Sprite = Texture;
				UBillboardComponentExists = true;
			}
		}
	}
	if (!UBillboardComponentExists)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
		SpriteComponent->Sprite = Texture;
		SpriteComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
		SpriteComponent->SetWorldScale3D(FVector(4, 4, 4));
	}
#endif // WITH_EDITORONLY_DATA
}

// Sets default values
AEventLab::AEventLab()
{
	RememberedStates.SetNum(10);
 	// Set this AActor* to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bDebug = true;
	bDoGeneralInit = true;
	//bHidden = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void AEventLab::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


void AEventLab::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (!bInitialized)
	{
		bInitialized = true;
		InitRefs();
		MachineID = GetCrypticID();
		if (bDoGeneralInit)
		{
			PlayerLock(bLockPlayerMovement, bLockPlayerRotation);
			if (!bEnableCheats)
			{
				DisableCheats();
			}
			if (!bShowClockAtStartup)
			{
				ClearClock();
			}
			if (bUseLevelBeginFadeIn)
			{
				FadeOut(0, true);
				FadeIn(LevelBeginFadeInTime, true);
				SetTimerEvent('LevelBeginFadeInComplete', LevelBeginFadeInTime, 0, false);
			}
			MissionBegin();
		}
		PostPostInit();
		DebugLog(DEBUG_EventLab, "EventLab Initialized: " + FString::FromInt(Tag));
	}
	EventLabTick(DeltaTime);
	ProcessTimerEvents(DeltaTime);
	ProcessAnimQueue();
	if (bZoomFOV)
	{
		DoZoomFOV(DeltaTime);
	}
	if (bTransGameSpeed)
	{
		DoTransGameSpeed(DeltaTime);
	}
	*/
}

//const MAX_REMEMBERED_STATES = 10;

void AEventLab::PreInit()
{
}

void AEventLab::Init()
{
}

void AEventLab::PostInit()
{
}

void AEventLab::PostPostInit()
{
}

void AEventLab::EventLabTick(float DeltaTime)
{
}

bool AEventLab::TargerManager_DispatchComplete(ATargetManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Trigger_Trigger(AAGP_Trigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Trigger_UnTrigger(AAGP_Trigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::NoiseTrigger_Trigger(ANoiseTrigger* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::NoiseTrigger_UnTrigger(ANoiseTrigger* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::LookTrigger_Trigger(ALookTrigger* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::LookTrigger_UnTrigger(ALookTrigger* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_UseTrigger_Trigger(AGP_UseTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_UseTrigger_UnTrigger(AGP_UseTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_UseTrigger_UsedBy(AGP_UseTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::StaticMeshSwitcher_UsedBy(AStaticMeshSwitcher* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::DoorTrigger_UsedBy(ADoorTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::DoorTrigger_Trigger(ADoorTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::DoorTrigger_UnTrigger(ADoorTrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::RiskVolume_Enter(ARiskVolume* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::RiskVolume_Exit(ARiskVolume* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::TriggerVolume_Enter(ATriggerVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::TriggerVolume_Exit(ATriggerVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::PhysicsVolume_Enter(APhysicsVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::PhysicsVolume_Exit(APhysicsVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Volume_Enter(AVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Volume_Exit(AVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Volume_Damaged(AVolume* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Pawn_Custom(APawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Pawn_Custom(AAGP_Pawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_NPC_Custom(AAGP_NPC* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Pawn_Died(AAGP_Pawn* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Pawn_Died(APawn* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Pawn_Damaged(AAGP_Pawn* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Character_Damaged(AAGP_Character* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::NPC_MedStudent_Custom(ANPC_MedStudent* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::NPC_MedInstructor_Custom(ANPC_MedInstructor* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Vehicle_Entered(AAGP_Vehicle* Vehicle, AActor* aController, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Vehicle_Exited(AAGP_Vehicle* Vehicle, AActor* aController, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Vehicle_Died(AAGP_Vehicle* Vehicle, AActor* aController, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::VehiclePosition_Entered(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::VehiclePosition_Exited(AVehiclePosition* Position, AActor* aController, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Vehicle_At(AAGP_Vehicle* Vehicle, AActor* aController, FString NavigationTag)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Controller_LSAnimEnd(AController* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::HumanController_Custom(AHumanController* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::StudentController_Custom(AStudentController* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::HttpGet_HttpGet(AHttpGet* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Objective_Trigger(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Objective_UnTrigger(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::BaseProjectile_Explode(ABaseProjectile* Projectile, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::ThrowWeaponPickup_GrenadeEffects(AThrowWeaponPickup* Grenade)
{
	return false;   //FAKE   /ELiZ
}

void AEventLab::GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms)
{
}

bool AEventLab::Trigger_Entered(ATrigger* NotifyActor, AActor* aInstigator)
{
	return false;   //FAKE   /ELiZ
}

void AEventLab::MortarDamagedTarget(AActor* agpmrdoTarget, AActor* aInstigator)
{
}

void AEventLab::MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* aInstigator)
{
}

bool AEventLab::Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Pickup_AbortPickup(APickup* NotifyPickup, APawn* User)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::TargetMover_Damaged(ATargetMover* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::DecoMesh_Damaged(ADecoMesh* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Trace_Hit(AAGP_Weapon* NotifyActor, AActor* HitActor, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Dropped(AAGP_Weapon* NotifyActor, APickup* WeaponPickup, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Custom(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Jam(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::SceneManager_SceneEnd(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::SceneManager_SceneStart(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::SceneManager_PointReached(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::InterpolationPoint_PointReached(AInterpolationPoint* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

/*
bool AEventLab::LevelInfo_FirstDraw(ALevelInfo* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}
*/

bool AEventLab::NPC_EEGuard_Custom(ANPC_EEGuard* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::MedExam_Custom(AMedExam* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::MarksmanTarget_Damaged(AMarksmanTarget* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::DamageDetector_Damaged(ADamageDetector* NotifyActor, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Actor_Custom(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Timer_Timer(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Timer_Sound(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Timer_Anim(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Timer_LSAnim(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::QueueAnim_Begin(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::QueueAnim_End(FName Name)
{
	return false;   //FAKE   /ELiZ
}

bool AEventLab::ELCheat(FString cheat)
{
	return false;   //FAKE   /ELiZ
}

void AEventLab::PreBeginPlay()
{
	PreInit();
}
void AEventLab::PostBeginPlay()
{
	PostInit();
}

void AEventLab::MissionBegin()
{
	/*
	if (((Level.Game.Stats != nullptr) && (AController* != nullptr)) && (Controller.PlayerStatsIndex >= 0))
	{
		Level.Game.Stats.PlayerStats[Controller.PlayerStatsIndex].StatEvent_TrainingMissionStart();
	}
	*/
}

void AEventLab::MissionComplete()
{
}

int32 AEventLab::GetCrypticID()
{
	AInternetLink* ILink = nullptr;
	int32 i = 0;
	int32 NameLen = 0;
	int32 Value = 0;
	FString hostname = "";
	/*
	ILink = Spawn(AInternetLink::StaticClass());
	if (ILink != nullptr)
	{
		hostname = ILink.GetLocalHostName();
		ILink.Destroy();
		ILink = nullptr;
		if (hostname == "")
		{
			hostname = "Ezekiel";
		}
		NameLen = Len(hostname);
		for (i = 0; i < NameLen; i++)
		{
			Value += Asc(Mid(hostname, i, 1));
		}
		return int((Square(float(Value)) + float(Value)));
	}
	else
	{
		Log("EventLab: ILink couldn't Be Spawned for script: " + FString::FromInt(this));
		return int((Square(777) + float(777)));
	}
	*/
	return 0;     //FAKE   /EliZ
}

void AEventLab::DoTransGameSpeed(float DeltaTime)
{
}

void AEventLab::DoZoomFOV(float DeltaTime)
{
	/*
	if (GetFOV() > NewFOV)
	{
		SetFOV((GetFOV() + (((NewFOV - OldFOV) * DeltaTime) / FOVZoomTime)));
	}
	else
	{
		bZoomFOV = false;
	}
	DebugLog(DEBUG_EventLab, "DoZoomFOV: " + FString::FromInt(GetFOV()));
	*/
}

void AEventLab::QueueAnim(FName Anim, AActor* A, bool bLoop, float Rate, float TweenTime, int32 Channel)
{
	/*
	int32 Index = 0;
	float StartTime = 0;
	if (A == nullptr)
	{
		Log("EventLab::QueueAnim(): Error: AActor* is None");
		return;
	}
	if (Rate == 0)
	{
		Rate = 1;
	}
	if (TweenTime == 0)
	{
		TweenTime = 0.5;
	}
	StartTime = -1;
	if (AnimQueueIsEmpty(A))
	{
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Queue is empty, playing: " + FString::FromInt(Anim));
		A.PlayAnim(Anim, Rate, TweenTime, Channel);
		StartTime = GetWorld()->GetTimeSeconds();
		QueueAnim_Begin(Anim);
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Anim StartTime is: " + FString::FromInt(StartTime));
	}
	else
	{
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Getting ready to flag looping anims for removal");
		FlagLoopingQueueAnims(A);
	}
	DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Anim Queued: " + FString::FromInt(Anim));
	Index = AnimQueue.Num();
	AnimQueue.insert(Index, 1);
	AnimQueue[Index].Anim = Anim;
	AnimQueue[Index].Num() = A.GetAnimDuration(Anim, Rate);
	AnimQueue[Index].bLoop = bLoop;
	AnimQueue[Index].Rate = Rate;
	AnimQueue[Index].TweenTime = TweenTime;
	AnimQueue[Index].Channel = Channel;
	AnimQueue[Index].Actor = A;
	AnimQueue[Index].StartTime = StartTime;
	*/
}

void AEventLab::QueueAnimDelay(AActor* A, float Delay, int32 Channel)
{
	/*
	int32 Index = 0;
	float StartTime = 0;
	if (A == nullptr)
	{
		Log("EventLab::QueueAnim(): Error: AActor* is None");
		return;
	}
	StartTime = -1;
	if (AnimQueueIsEmpty(A))
	{
		if (bDebug)
		{
			Log("EventLab::QueueAnimDelay(): Queue is empty, starting delay: " + FString::FromInt(Delay));
		}
		StartTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if (bDebug)
		{
			Log("EventLab::QueueAnim(): Getting ready to flag looping anims for removal for delay");
		}
		FlagLoopingQueueAnims(A);
	}
	if (bDebug)
	{
		Log("EventLab::QueueAnimDelay(): Delay Queued: " + FString::FromInt(Delay));
	}
	Index = AnimQueue.Num();
	AnimQueue.insert(Index, 1);
	AnimQueue[Index].Anim = "None";
	AnimQueue[Index].Num() = Delay;
	AnimQueue[Index].bLoop = false;
	AnimQueue[Index].Rate = 1;
	AnimQueue[Index].TweenTime = 0.1;
	AnimQueue[Index].Channel = Channel;
	AnimQueue[Index].Actor = A;
	AnimQueue[Index].StartTime = StartTime;
	*/
}

void AEventLab::ProcessAnimQueue()
{
	int32 i = 0;
	AActor* A = nullptr;
	/*
	if (i < AnimQueue.Num())
	{
		if (AnimQueue[i].StartTime == float(-1))
		{
			i++;
		}
		else
		{
			if ((GetWorld()->GetTimeSeconds() - AnimQueue[i].StartTime) >= AnimQueue[i].Num())
			{
				A = AnimQueue[i].Actor;
				if (!AnimQueue[i].bLoop)
				{
					QueueAnim_End(AnimQueue[i].Anim);
					AnimQueue.RemoveAt(i, 1);
					DebugLog(DEBUG_EventLab, "EventLab::ProcessAnimQueue(): Non-Looping Anim Removed: " + FString::FromInt(AnimQueue[i].Anim) + " - For Actor: " + FString::FromInt(A.Tag));
				}
				else
				{
					if (AnimQueue[i].bRemove)
					{
						QueueAnim_End(AnimQueue[i].Anim);
						AnimQueue.RemoveAt(i, 1);
					}
					else
					{
						i++;
					}
				}
				PlayNextQueueAnim(A);
			}
			else
			{
				i++;
			}
		}
	}
	*/
}

void AEventLab::PlayNextQueueAnim(AActor* A)
{
	/*
	int32 i = 0;
	for (i = 0; i < AnimQueue.Num(); i++)
	{
		if (AnimQueue[i].Actor == A)
		{
			DebugLog(DEBUG_EventLab, "EventLab::PlayNextQueueAnim: Playing Anim: " + FString::FromInt(AnimQueue[i].Anim) + " - For Actor: " + FString::FromInt(A.Tag));
			A.PlayAnim(AnimQueue[i].Anim, AnimQueue[i].Rate, AnimQueue[i].TweenTime, AnimQueue[i].Channel);
			AnimQueue[i].StartTime = GetWorld()->GetTimeSeconds();
			QueueAnim_Begin(AnimQueue[i].Anim);
			return;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::PlayNextQueueAnim(): Didn't find an anim to play for: " + FString::FromInt(A.Tag));
	*/
}

void AEventLab::FlagLoopingQueueAnims(AActor* A)
{
	/*
	int32 i = 0;
	for (i = 0; i < AnimQueue.Num(); i++)
	{
		if ((AnimQueue[i].Actor == A) && AnimQueue[i].bLoop)
		{
			AnimQueue[i].bRemove = true;
			DebugLog(DEBUG_EventLab, "EventLab::FlagLoopingQueueAnims(): Looping Anim: " + FString::FromInt(AnimQueue[i].Anim) + " flagged for removal for Actor: " + FString::FromInt(A));
		}
	}
	*/
}

bool AEventLab::AnimQueueIsEmpty(AActor* A)
{
	/*
	int32 i = 0;
	if (AnimQueue.Num() == 0)
	{
		return true;
	}
	else
	{
		for (i = 0; i < AnimQueue.Num(); i++)
		{
			if (AnimQueue[i].Actor == A)
			{
				return false;
			}
		}
	}
	*/
	return true;
}

void AEventLab::ProcessTimerEvents(float DeltaTime)
{
	/*
	int32 i = 0;
	if (i < TimerEvents.Num())
	{
		if (TimerEvents[i].bPause)
		{
			(TimerEvents[i].StartTime += DeltaTime);
		}
		if ((GetWorld()->GetTimeSeconds() - TimerEvents[i].StartTime) >= TimerEvents[i].WaitTime)
		{
			if (!Dispatcher_Timer(TimerEvents[i].Name, TimerEvents[i].TType))
			{
				LogUnHandledTimerEvent(TimerEvents[i].Name, TimerEvents[i].TType);
			}
			if (!TimerEvents[i].bRepeat)
			{
				TimerEvents.RemoveAt(i, 1);
			}
			else
			{
			else
			{
				TimerEvents[i].StartTime = GetWorld()->GetTimeSeconds();
			}
			}
			i++;
		}
	}
	*/
}

void AEventLab::SetTimerEvent(FName Name, float Time, ETimerType TType, bool bRepeat, AActor* Actor)
{
	/*
	int32 i = 0;
	int32 Index = 0;
	Index = TimerEvents.Num();
	i = 0;
	if (i < TimerEvents.Num())
	{
		if ((TimerEvents[i].Name == Name) && (TimerEvents[i].TType == TType))
		{
			Index = i;
			DebugLog(DEBUG_EventLab, "EventLab::SetTimerEvent(): Duplicate name: " + FString::FromInt(Name) + " was replaced in the timer list");
		}
		else
		{
			i++;
		}
	}
	if (Index == TimerEvents.Num())
	{
		TimerEvents.insert(Index, 1);
	}
	TimerEvents[Index].Name = Name;
	TimerEvents[Index].StartTime = GetWorld()->GetTimeSeconds();
	TimerEvents[Index].WaitTime = Time;
	TimerEvents[Index].TType = TType;
	TimerEvents[Index].bRepeat = bRepeat;
	*/
}

float AEventLab::QueryTimer(FName Name, ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if ((TimerEvents[i].TType == Type) && (TimerEvents[i].Name == Name))
		{
			return FMax(((TimerEvents[i].WaitTime - GetWorld()->GetTimeSeconds()) + TimerEvents[i].StartTime), 0);
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::QueryTimer(): Timer not found: " + FString::FromInt(Name) + " with type: " + FString::FromInt(GetEnum(Enum'AGP_Script.EventLab.ETimerType', Type)));
	*/
	return 0;
}

void AEventLab::InitRefs()
{
	/*
	Controller = Cast<AHumanController>(Level.GetClientController());
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	*/
}

void AEventLab::LogUnHandledActorEvent(AActor* NotifyActor, EEventType Event, FString Parms)
{
	//DebugLog(DEBUG_EventLab, "EventLab::LogUnHandledActorEvent(): " + "Event type: " + FString::FromInt(GetEnum(Enum'Engine.EEventType', Event)) + " for actor: " + FString::FromInt(NotifyActor) + " of class: " + FString::FromInt(NotifyActor.Class) + " with tag: " + FString::FromInt(NotifyActor.Tag) + " with parms: " + Parms);
}

void AEventLab::LogUnHandledTimerEvent(FName Name, ETimerType Type)
{
	//DebugLog(DEBUG_EventLab, "EventLab::LogUnHandledTimerEvent(): " + "Name: " + FString::FromInt(Name) + " Type: " + FString::FromInt(GetEnum(Enum'AGP_Script.EventLab.ETimerType', Type)));
}

bool AEventLab::ActorNotify(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	if (bEventsDisabled)
	{
		DebugLog(DEBUG_EventLab, "EventLab::ActorNotify(): Event recieved, but events are disabled." + " event type: " + FString::FromInt(GetEnum(Enum'Engine.EEventType', Event)) + " for actor: " + FString::FromInt(NotifyActor) + " of class: " + FString::FromInt(NotifyActor.Class) + " with tag: " + FString::FromInt(NotifyActor.Tag) + " with parms: " + Parms);
		return false;
	}
	if (Actor_Custom(NotifyActor, Event, aInstigator, Parms))
	{
		return true;
	}
	if (NotifyActor->IsA(ATargetManager::StaticClass()))
	{
		if (!Dispatcher_TargetManager(NotifyActor, Event, aInstigator, Parms))
		{
			LogUnHandledActorEvent(NotifyActor, Event, Parms);
		}
		return true;
	}
	if (NotifyActor->IsA(ATrigger::StaticClass()))
	{
		if (!Dispatcher_Trigger(NotifyActor, aInstigator, Parms))
		{
			LogUnHandledActorEvent(NotifyActor, Event, Parms);
		}
		return true;
	}
	if (NotifyActor->IsA(AAGP_Trigger::StaticClass()))
	{
		switch (NotifyActor.Class)
		{
		case Class'ANoiseTrigger*':
			if (!Dispatcher_NoiseTrigger(NotifyActor, Event, aInstigator, Parms))
			{
				LogUnHandledActorEvent(NotifyActor, Event, Parms);
			}
			return true;
		case Class'ALookTrigger*':
			if (!Dispatcher_LookTrigger(NotifyActor, Event, aInstigator, Parms))
			{
				LogUnHandledActorEvent(NotifyActor, Event, Parms);
			}
			return true;
		default:
			if (!Dispatcher_AGP_Trigger(NotifyActor, Event, aInstigator, Parms))
			{
				LogUnHandledActorEvent(NotifyActor, Event, Parms);
			}
			return true;
		}
		if (NotifyActor->IsA(AAGP_UseTrigger::StaticClass()))
		{
			switch (NotifyActor.Class)
			{
			case Class'ADoorTrigger*':
				if (!Dispatcher_DoorTrigger(NotifyActor, Event, aInstigator, Parms))
				{
					LogUnHandledActorEvent(NotifyActor, Event, Parms);
				}
				return true;
			case Class'AStaticMeshSwitcher*':
				if (!Dispatcher_StaticMeshSwitcher(NotifyActor, Event, aInstigator, Parms))
				{
					LogUnHandledActorEvent(NotifyActor, Event, Parms);
				}
				return true;
			default:
				if (!Dispatcher_AGP_UseTrigger(NotifyActor, Event, aInstigator, Parms))
				{
					LogUnHandledActorEvent(NotifyActor, Event, Parms);
				}
				return true;
			}
			if (NotifyActor->IsA(AVolume::StaticClass()))
			{
				switch (NotifyActor.Class)
				{
				case Class'ARiskVolume*':
					if (!Dispatcher_RiskVolume(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				case Class'ATriggerVolume*':
					if (!Dispatcher_TriggerVolume(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				case Class'PhysicsVolume':
					if (!Dispatcher_PhysicsVolume(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				default:
					if (!Dispatcher_Volume(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				}
				if (NotifyActor->IsA(AVehicle::StaticClass()))
				{
					if (!Dispatcher_Vehicle(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				}
				if (NotifyActor->IsA(APawn::StaticClass()))
				{
					switch (NotifyActor.Class)
					{
					case Class'ANPC_MedStudent*':
						if (!Dispatcher_NPC_MedStudent(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					case Class'ANPC_MedInstructor':
						if (!Dispatcher_NPC_MedInstructor(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					case Class'AAGP_NPC*':
						if (!Dispatcher_AGP_NPC(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					case Class'AAGP_Character*':
						if (!Dispatcher_AGP_Character(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					case AAGP_Pawn::StaticClass():
						if (!Dispatcher_AGP_Pawn(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					default:
						if (!Dispatcher_Pawn(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					}
					if (NotifyActor->IsA(AAGP_VehicleFactory::StaticClass()))
					{
						if (!Dispatcher_AGP_VehicleFactory(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					}
					if (NotifyActor->IsA(AController::StaticClass()) && (Event == 30))
					{
						if (ELCheat(Parms))
						{
							Log("EventLab::ELCheat - EventLab Cheat \"" + Parms + "\" called");
						}
						break;
					}
					if (NotifyActor->IsA(AController::StaticClass()))
					{
						switch (NotifyActor.Class)
						{
						case AStudentController::StaticClass():
							if (!Dispatcher_StudentController(NotifyActor, Event, aInstigator, Parms))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						case AHumanController::StaticClass():
							if (!Dispatcher_HumanController(NotifyActor, Event, aInstigator, Parms))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						default:
							if (!Dispatcher_Controller(NotifyActor, Event, aInstigator, Parms))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						}
					}
					if (NotifyActor->IsA(AThrowWeaponPickup::StaticClass()))
					{
						if (Event == 10)
						{
							if (!ThrowWeaponPickup_GrenadeEffects(Cast<AThrowWeaponPickup>(NotifyActor)))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						}
					}
					if (NotifyActor->IsA(ABaseProjectile::StaticClass()))
					{
						if (!Dispatcher_BaseProjectile(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					}
					if (NotifyActor->IsA(AAGP_Objective::StaticClass()))
					{
						switch (NotifyActor.Class)
						{
						default:
							if (!Dispatcher_AGP_Objective(NotifyActor, Event, aInstigator, Parms))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						}
						if (NotifyActor->IsA(APickup::StaticClass()))
						{
							if (Parms ~= "Grenade_Explode")
							{
								if (!Dispatcher_GrenadeExploded(NotifyActor, Event, aInstigator, Parms))
								{
									LogUnHandledActorEvent(NotifyActor, Event, Parms);
								}
								return true;
							}
							switch (NotifyActor.Class)
							{
							default:
								if (Event == 1)
								{
									return Dispatcher_Pickup(NotifyActor, Event, aInstigator, Parms);
									break;
								}
								if (!Dispatcher_Pickup(NotifyActor, Event, aInstigator, Parms))
								{
									LogUnHandledActorEvent(NotifyActor, Event, Parms);
								}
							}
							return true;
						}
						if (NotifyActor->IsA(ADecoMesh::StaticClass()))
						{
							switch (NotifyActor.Class)
							{
							case Class'ATargetMover*':
								if (!Dispatcher_TargetMover(NotifyActor, Event, aInstigator, Parms))
								{
									LogUnHandledActorEvent(NotifyActor, Event, Parms);
								}
								return true;
							default:
								if (!Dispatcher_DecoMesh(NotifyActor, Event, aInstigator, Parms))
								{
									LogUnHandledActorEvent(NotifyActor, Event, Parms);
								}
								return true;
							}
							if (NotifyActor->IsA(AAGP_Weapon::StaticClass()))
							{
								switch (NotifyActor.Class)
								{
								default:
									if (!Dispatcher_AGP_Weapon(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								}
								if (NotifyActor->IsA(AVehicleWeapon::StaticClass()))
								{
									if (!Dispatcher_VehicleWeapon(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								}
								switch (NotifyActor.Class)
								{
								case Class'ADamageDetector*':
									if (!Dispatcher_DamageDetector(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case Class'AMarksmanTarget*':
									if (!Dispatcher_MarksmanTarget(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case Class'AMedExam*':
									if (!Dispatcher_MedExam(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case ASceneManager::StaticClass():
									if (!Dispatcher_SceneManager(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case AInterpolationPoint::StaticClass():
									if (!Dispatcher_InterpolationPoint(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case Class'ANPC_EEGuard*':
									if (!Dispatcher_NPC_EEGuard(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case AHttpGet::StaticClass():
									if (!Dispatcher_HttpGet(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case AAGP_HUD::StaticClass():
									if (!Dispatcher_AGP_Hud(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								default:
									if (!Actor_Custom(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
									return;
								}
	*/

	return false;     //FAKE   /EliZ
}

bool AEventLab::Dispatcher_Timer(FName Name, ETimerType Type)
{
	/*
	switch (Type)
	{
	case 0:
		return Timer_Timer(Name);
	case 1:
		return Timer_Sound(Name);
	case 2:
		return Timer_Anim(Name);
	case 3:
		return Timer_LSAnim(Name);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_TargetManager(AActor* NotifyActor, EEventType ActorEvent, AActor* aInstigator, FString Parms)
{
	/*
	switch (ActorEvent)
	{
	case 29:
		return TargerManager_DispatchComplete(Cast<ATargetManager>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_SceneManager(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 13:
		return SceneManager_SceneStart(Cast<ASceneManager>(NotifyActor), aInstigator, Parms);
	case 14:
		return SceneManager_SceneEnd(Cast<ASceneManager>(NotifyActor), aInstigator, Parms);
	case 15:
		return SceneManager_PointReached(Cast<ASceneManager>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_InterpolationPoint(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 15:
		return InterpolationPoint_PointReached(Cast<AInterpolationPoint>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Hud(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return AGP_Hud_Custom(Cast<AAGP_HUD>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_StaticMeshSwitcher(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 1:
		return StaticMeshSwitcher_UsedBy(Cast<AStaticMeshSwitcher>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_UseTrigger(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 1:
		return AGP_UseTrigger_UsedBy(Cast<AAGP_UseTrigger>(NotifyActor), aInstigator);
	case 4:
		return AGP_UseTrigger_Trigger(Cast<AAGP_UseTrigger>(NotifyActor), aInstigator);
	case 5:
		return AGP_UseTrigger_UnTrigger(Cast<AAGP_UseTrigger>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_NoiseTrigger(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 4:
		return NoiseTrigger_Trigger(Cast<ANoiseTrigger>(NotifyActor), aInstigator, Parms);
	case 5:
		return NoiseTrigger_UnTrigger(Cast<ANoiseTrigger>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_LookTrigger(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 4:
		return LookTrigger_Trigger(Cast<ALookTrigger>(NotifyActor), aInstigator, Parms);
	case 5:
		return LookTrigger_UnTrigger(Cast<ALookTrigger>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Trigger(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 4:
		return AGP_Trigger_Trigger(Cast<AAGP_Trigger>(NotifyActor), aInstigator);
	case 5:
		return AGP_Trigger_UnTrigger(Cast<AAGP_Trigger>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Objective(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 4:
		return AGP_Objective_Trigger(Cast<AAGP_Objective>(NotifyActor), aInstigator);
	case 5:
		return AGP_Objective_UnTrigger(Cast<AAGP_Objective>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	GrenadeExploded(Grenade, Event, aInstigator, Parms);
	return true;
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_BaseProjectile(AActor* Projectile, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 10:
		return BaseProjectile_Explode(Cast<ABaseProjectile>(Projectile), aInstigator, Parms);
		break;
	default:
		return false;
	}
	return true;
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_Trigger(AActor* NotifyActor, AActor* aInstigator, FString Parms)
{
	//Trigger_Entered(Cast<ATrigger>(NotifyActor), aInstigator);
	return true;
}

bool AEventLab::Dispatcher_Pickup(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 2:
		return Pickup_PickedUp(Cast<APickup>(NotifyActor), aInstigator, Parms);
	case 1:
		return Pickup_AbortPickup(Cast<APickup>(NotifyActor), Pawn(aInstigator));
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_TargetMover(AActor* NotifyActor, EEventType InEvent, AActor* aInstigator, FString Parms)
{
	/*
	switch (InEvent)
	{
	case 8:
		return TargetMover_Damaged(Cast<ATargetMover>(NotifyActor), aInstigator, Parms);
	default:
		return false;
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_DecoMesh(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 8:
		return DecoMesh_Damaged(Cast<ADecoMesh>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Weapon(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 17:
		return AGP_Weapon_Fire(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	case 18:
		return AGP_Weapon_Trace_Hit(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	case 19:
		return AGP_Weapon_Throw(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	case 3:
		return AGP_Weapon_Dropped(Cast<AAGP_Weapon>(NotifyActor), Cast<APickup>(aInstigator), Parms);
	case 31:
		return AGP_Weapon_Custom(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	case 20:
		return AGP_Weapon_Jam(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	case 21:
		return AGP_Weapon_Empty(Cast<AAGP_Weapon>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_VehicleWeapon(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 23:
		return VehicleWeapon_Fire(Cast<AVehicleWeapon>(NotifyActor), aInstigator, Parms);
	default:
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_DoorTrigger(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 1:
		return DoorTrigger_UsedBy(Cast<ADoorTrigger>(NotifyActor), aInstigator);
	case 4:
		return DoorTrigger_Trigger(Cast<ADoorTrigger>(NotifyActor), aInstigator);
	case 5:
		return DoorTrigger_UnTrigger(Cast<ADoorTrigger>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Character(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 11:
		return AGP_Character_Died(Cast<AAGP_Character>(NotifyActor), Cast<AController>(aInstigator));
	case 8:
		return AGP_Character_Damaged(Cast<AAGP_Character>(NotifyActor), Cast<AController>(aInstigator));
	case 31:
		return AGP_Character_Custom(Cast<AAGP_Character>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_Pawn(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 11:
		return Pawn_Died(Cast<APawn>(NotifyActor), Cast<AController>(aInstigator));
	case 8:
		return Pawn_Damaged(Cast<APawn>(NotifyActor), Cast<AController>(aInstigator));
	case 31:
		return Pawn_Custom(Cast<APawn>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_Pawn(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 11:
		return AGP_Pawn_Died(Cast<AAGP_Pawn>(NotifyActor), Cast<AController>(aInstigator));
	case 8:
		return AGP_Pawn_Damaged(Cast<AAGP_Pawn>(NotifyActor), Cast<AController>(aInstigator));
	case 31:
		return AGP_Pawn_Custom(Cast<AAGP_Pawn>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_NPC(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 11:
		return AGP_NPC_Died(Cast<AAGP_NPC>(NotifyActor), Cast<AController>(aInstigator));
	case 8:
		return AGP_NPC_Damaged(Cast<AAGP_NPC>(NotifyActor), Cast<AController>(aInstigator));
	case 31:
		return AGP_NPC_Custom(Cast<ANPC_MedStudent>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}	
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_NPC_MedStudent(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return NPC_MedStudent_Custom(Cast<ANPC_MedStudent>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_NPC_MedInstructor(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return NPC_MedInstructor_Custom(Cast<ANPC_MedInstructor>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_NPC_EEGuard(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return NPC_EEGuard_Custom(Cast<ANPC_EEGuard>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_Vehicle(AActor* NotifyActor, EEventType InEvent, AActor* aController, FString Parms)
{
	/*
	switch (InEvent)
	{
	case 25:
		if (Cast<AAGP_Vehicle>(NotifyActor) != nullptr)
		{
			return AGP_Vehicle_Entered(Cast<AAGP_Vehicle>(NotifyActor), aController, Parms);
			break;
		}
		if (Cast<AVehiclePosition>(NotifyActor) != nullptr)
		{
			return VehiclePosition_Entered(Cast<AVehiclePosition>(NotifyActor), aController, Parms);
		}
	}
	GOTO JL0129;
	case 26:
		if (Cast<AAGP_Vehicle>(NotifyActor) != nullptr)
		{
			return AGP_Vehicle_Exited(Cast<AAGP_Vehicle>(NotifyActor), aController, Parms);
		}
		else
		{
			if (Cast<AVehiclePosition>(NotifyActor) != nullptr)
			{
				return VehiclePosition_Exited(Cast<AVehiclePosition>(NotifyActor), aController, Parms);
			}
		}
	case 27:
		if (Cast<AAGP_Vehicle>(NotifyActor) != nullptr)
		{
			return Vehicle_At(Cast<AAGP_Vehicle>(NotifyActor), aController, Parms);
		}
	case 28:
		if (Cast<AAGP_Vehicle>(NotifyActor) != nullptr)
		{
			return AGP_Vehicle_Died(Cast<AAGP_Vehicle>(NotifyActor), aController, Parms);
		}
	default:
	JL0129:
		return false;

	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_AGP_VehicleFactory(AActor* NotifyActor, EEventType InEvent, AActor* NewVehicle, FString Parms)
{
	/*
	switch (InEvent)
	{
	case 24:
		AGP_Vehicle_Spawned(Cast<AAGP_VehicleFactory>(NotifyActor), Cast<AAGP_Vehicle>(NewVehicle), Parms);
		return true;
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_MedExam(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return MedExam_Custom(Cast<AMedExam>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_TriggerVolume(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 6:
		return TriggerVolume_Enter(Cast<ATriggerVolume>(NotifyActor), aInstigator);
	case 7:
		return TriggerVolume_Exit(Cast<ATriggerVolume>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_PhysicsVolume(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 6:
		return PhysicsVolume_Enter(Cast<APhysicsVolume>(NotifyActor), aInstigator);
	case 7:
		return PhysicsVolume_Exit(Cast<APhysicsVolume>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_Volume(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 6:
		return Volume_Enter(Cast<AVolume>(NotifyActor), aInstigator);
	case 7:
		return Volume_Exit(Cast<AVolume>(NotifyActor), aInstigator);
	case 8:
		return Volume_Damaged(Cast<AVolume>(NotifyActor), aInstigator);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_RiskVolume(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 6:
		return RiskVolume_Enter(Cast<ARiskVolume>(NotifyActor), aInstigator, Parms);
	case 7:
		return RiskVolume_Exit(Cast<ARiskVolume>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_Controller(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 12:
		return Controller_LSAnimEnd(Cast<AController>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_HumanController(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return HumanController_Custom(Cast<AHumanController>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_HttpGet(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 16:
		return HttpGet_HttpGet(Cast<AHttpGet>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_LevelInfo(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 22:
		return LevelInfo_FirstDraw(Cast<ALevelInfo>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_StudentController(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 31:
		return StudentController_Custom(Cast<AStudentController>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
		return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_DamageDetector(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 8:
		return DamageDetector_Damaged(Cast<ADamageDetector>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEventLab::Dispatcher_MarksmanTarget(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 8:
		return MarksmanTarget_Damaged(Cast<AMarksmanTarget>(NotifyActor), aInstigator, Parms);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

int32 AEventLab::GetMachineID()
{
	return MachineID;
}

void AEventLab::CaptureController()
{
	//Controller.SetEventLab(this);
}

void AEventLab::CapturePlayer()
{
	//Player.SetEventLab(this);
}

FString AEventLab::GetClockTime()
{
	//return FormatTime(float(GetClockSeconds()));
	return "FAKE";     //FAKE    /EliZ
}

int32 AEventLab::GetClockSeconds()
{
	//return Level.Game.GameReplicationInfo.RemainingTime;
	return 0;     //FAKE    /EliZ
}

FString AEventLab::FormatTime(float Time, bool bHundredths, bool bWrapAt100)
{
	/*
	int32 nMinutes = 0;
	float nSeconds = 0;
	FString sMinutes = "";
	FString sSeconds = "";
	nMinutes = int((Time / float(60)));
	nSeconds = (Time % float(60));
	if (bWrapAt100 && (nMinutes > 99))
	{
		nMinutes = 0;
	}
	if (nMinutes < 10)
	{
		sMinutes = "0" + FString::FromInt(nMinutes);
	}
	else
	{
		sMinutes = FString::FromInt(nMinutes);
	}
	if (bHundredths)
	{
		if (nSeconds < float(10))
		{
			sSeconds = "0" + FString::FromInt(nSeconds);
		}
		else
		{
			sSeconds = FString::FromInt(nSeconds);
		}
	}
	else
	{
		if (nSeconds < float(10))
		{
			sSeconds = "0" + FString::FromInt(int(nSeconds));
		}
		else
		{
			sSeconds = FString::FromInt(int(nSeconds));
		}
	}
	return sMinutes + ":" + sSeconds;
	*/
	return "FAKE";     //FAKE    /EliZ
}

bool AEventLab::AnimIsQueued(FName Anim, AActor* A)
{
	/*
	int32 i = 0;
	for (i = 0; i < AnimQueue.Num(); i++)
	{
		if ((AnimQueue[i].Anim == Anim) && (AnimQueue[i].Actor == A))
		{
			return true;
		}
	}
	*/
	return false;
}

void AEventLab::EnableEvents()
{
	//bEventsDisabled = false;
}

void AEventLab::DisableEvents()
{
	//bEventsDisabled = true;
}

void AEventLab::DisableCheats()
{
	//Controller.KillCheats();
}

void AEventLab::EventLabNotifyCheat()
{
}

void AEventLab::RememberState(FName State, int32 Slot)
{
	/*
	if ((Slot < 10) && (Slot >= 0))
	{
		RememberedStates[Slot] = State;
	}
	else
	{
		Log("EventLab::RememberState(): Error: Index out of range");
	}
	*/
}

FName AEventLab::RecallState(int32 Slot)
{
	/*
	if ((Slot < 10) && (Slot >= 0))
	{
		return RememberedStates[Slot];
	}
	else
	{
		Log("EventLab::RecallState(): Error: Index out of range");
	}
	*/
	return "";     //FAKE   /EliZ
}

void AEventLab::StartTimer(FName Name, float Time, bool bRepeat)
{
	//SetTimerEvent(Name, Time, 0, bRepeat);
}

bool AEventLab::HasTimerEventName(FName TimerName)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].Name == TimerName)
		{
			return true;
		}
	}
	*/
	return false;
}

bool AEventLab::HasTimerEventType(ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].TType == Type)
		{
			return true;
		}
	}
	*/
	return false;
}

bool AEventLab::StopTimerByType(ETimerType Type)
{
	int32 i = 0;
	bool bReturnValue = false;
	/*
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].TType == Type)
		{
			TimerEvents[i].Name = "None";
			TimerEvents[i].WaitTime = 0;
			TimerEvents[i].bRepeat = false;
			bReturnValue = true;
		}
	}
	*/
	return bReturnValue;
}

bool AEventLab::StopTimer(FName StopName, ETimerType Type)
{
	int32 i = 0;
	bool bReturnValue = false;
	/*
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if ((TimerEvents[i].Name == StopName) && (TimerEvents[i].TType == Type))
		{
			TimerEvents[i].Name = "None";
			TimerEvents[i].WaitTime = 0;
			TimerEvents[i].bRepeat = false;
			bReturnValue = true;
		}
	}
	*/
	return bReturnValue;
}

void AEventLab::PauseTimer(FName Name, ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].Name == Name)
		{
			if (TimerEvents[i].TType == Type)
			{
				TimerEvents[i].bPause = true;
			}
		}
	}
	*/
}

void AEventLab::RestartTimer(FName Name, ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].Name == Name)
		{
			if (TimerEvents[i].TType == Type)
			{
				TimerEvents[i].bPause = false;
			}
		}
	}
	*/
}

bool AEventLab::IsTimerPaused(FName Name, ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Num(); i++)
	{
		if (TimerEvents[i].Name == Name)
		{
			if (TimerEvents[i].TType == Type)
			{
				return TimerEvents[i].bPause;
			}
		}
	}
	*/
	return false;     //FAKE   /EliZ
}

FName AEventLab::GetCurrentState()
{
	//return GetStateName();
	return "";   //FAKE   /ELiZ
}

FName AEventLab::GetPreviousState()
{
	return PreviousState;
}

void AEventLab::ChangeState(FName State, FName Label)
{
	/*
	DebugLog(DEBUG_EventLab, "");
	DebugLog(DEBUG_EventLab, "");
	DebugLog(DEBUG_EventLab, "EventLab::ChangeState(): Before state change, state is " @ FString::FromInt(GetStateName()));
	PreviousState = GetStateName();
	GotoState(State, Label);
	DebugLog(DEBUG_EventLab, "EventLab::ChangeState(): State is now: " @ FString::FromInt(GetStateName()));
	DebugLog(DEBUG_EventLab, "-----------------------------------------------------------");
	*/
}

AActor* AEventLab::CaptureEvent(FName Tag, AActor* classTypeToFind)
{
	AActor* A = nullptr;
	AActor* cActor = nullptr;
	int32 ACount = 0;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		if (classTypeToFind != nullptr)
		{
			if (!A.IsA(classTypeToFind.Name))
			{
				continue;
			}
		}
		if (A.Tag == Tag)
		{
			cActor = A;
			ACount++;
		}
	}
	if (cActor == nullptr)
	{
		Log("EventLab::CaptureEvent: Error: Tag not found: " @ FString::FromInt(Tag));
		return nullptr;
	}
	else
	{
		if (ACount > 1)
		{
			Log("EventLab::CaptureEvent: Error: Multiple tags found: " @ FString::FromInt(Tag));
			return nullptr;
		}
		else
		{
			cActor.SetEventLab(this);
			return cActor;
		}
	}
	*/
	return nullptr;
}

void AEventLab::ReCaptureEvent(AActor* Actor)
{
	/*
	if (AActor* != nullptr)
	{
		Actor.SetEventLab(this);
	}
	else
	{
		Log("EventLab::ReCaptureEvent(): Error: AActor* is None");
	}
	*/
}

void AEventLab::UnCaptureEvent(AActor* Actor)
{
	/*
	if (AActor* != nullptr)
	{
		Actor.SetEventLab(nullptr);
	}
	else
	{
		Log("EventLab::UnCaptureEvent(): Error: AActor* is None");
	}
	*/
}

void AEventLab::CaptureEventGroup(FName Tag)
{
	AActor* A = nullptr;
	int32 ACount = 0;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		if (A.Tag == Tag)
		{
			A.SetEventLab(this);
			ACount++;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::CaptureEventGroup: Captured " + FString::FromInt(ACount) + " actors with tag " + FString::FromInt(Tag));
	if (ACount == 0)
	{
		DebugLog(DEBUG_EventLab, "EventLab::CaptureEventGroup: Warning: No actors found with tag: " + FString::FromInt(Tag));
	}
	*/
}

void AEventLab::UnCaptureEventGroup(FName Tag)
{
	AActor* A = nullptr;
	int32 ACount = 0;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		if (A.Tag == Tag)
		{
			A.SetEventLab(nullptr);
			ACount++;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::UnCaptureEventGroup: UnCaptured " + FString::FromInt(ACount) + " actors with tag " + FString::FromInt(Tag));
	if (ACount == 0)
	{
		DebugLog(DEBUG_EventLab, "EventLab::UnCaptureEventGroup: Warning: No actors found with tag: " + FString::FromInt(Tag));
	}
	*/
}

void AEventLab::TriggerActor(AActor* TargetActor)
{
	/*
	if (TargetActor != nullptr)
	{
		TargetActor.Trigger(this, Player);
	}
	else
	{
		Log("EventLab::TriggerActor(): Error: TargetActor is None");
	}
	*/
}

void AEventLab::TriggerGroup(FName Tag)
{
	//TriggerEvent(Tag, this, Player);
}

USoundBase* AEventLab::GetGameSound(FName Name)
{
	/*
	int32 i = 0;
	for (i = 0; i < GameSounds.Num(); i++)
	{
		if (GameSounds[i].Name == Name)
		{
			return GameSounds[i].Sound;
		}
	}
	Log("EventLab::GetGameSound(): Error: GameSound not found for " + FString::FromInt(Name));
	*/
	return nullptr;
}

float AEventLab::PlayGameSound(FName Name, AActor* Target, ESoundSlot Slot, float Volume, float Radius, float AdditionalDelay)
{
	USoundBase* Sound = nullptr;
	if (Volume == 0)
	{
		Volume = 1;
	}
	/*
	Sound = GetGameSound(Name);
	DebugLog(DEBUG_EventLab, "Sound " + FString::FromInt(Name) + " is: " + FString::FromInt(Sound));
	if ((Sound != nullptr) && (Target != nullptr))
	{
		Target.PauseSound(true);
		if (Radius <= 0)
		{
			Target.PlaySound(Sound, Slot, Volume);
		}
		else
		{
			Target.PlaySound(Sound, Slot, Volume, , Radius);
		}
		SetTimerEvent(Name, (GetSoundDuration(Sound) + AdditionalDelay), 1, false);
	}
	else
	{
		Log("EventLab::PlayGameSound(): Error: Sound or Target are None");
	}
	return GetSoundDuration(Sound);
	*/
	return 0;     //FAKE   /ELiZ
}

FLSAnim AEventLab::GetLSAnim(FName Name)
{
	int32 i = 0;
	for (i = 0; i < LSAnims.Num(); i++)
	{
		if (LSAnims[i].Anim == Name)
		{
			return LSAnims[i];
		}
	}
	//Log("EventLab::GetLSAnim(): Error: Name not found: " @ FString::FromInt(Name));
	return FLSAnim({});
}

void AEventLab::PlayLSAnim(FName Name, AActor* Target, float Volume, float Radius, float Pitch, float AdditionalDelay)
{
	FLSAnim LSAnim = FLSAnim({});
	int32 i = 0;
	float LastGestureTime = 0;
	if (Volume == 0)
	{
		Volume = 1;
	}
	if (Radius == 0)
	{
		Radius = 256;
	}
	if (Pitch == 0)
	{
		Pitch = 1;
	}
	LSAnim = GetLSAnim(Name);
	/*
	if ((LSAnim.Anim != "None") && (LSAnim.Anim != "None"))
	{
		if (Target != nullptr)
		{
			DebugLog(DEBUG_EventLab, "EventLab::PlayLSAnim(): Calling PlayLipSincAnim() for anim: " + FString::FromInt(LSAnim.Anim));
			SetTimerEvent(LSAnim.Anim, (GetSoundDuration(LSAnim.Sound) + AdditionalDelay), 3, false);
			Target.PlayLIPSincAnim(LSAnim.Anim, Volume, Radius, Pitch);
			if (10 > 0)
			{
				LastGestureTime = 0;
				i = 0;
				if ((i < 10) && (LSAnim.GestureAnim[i] != "None"))
				{
					if (LSAnim.GestureDelay[i] > LastGestureTime)
					{
						QueueAnimDelay(Target, (LSAnim.GestureDelay[i] - LastGestureTime));
						(LastGestureTime += LSAnim.GestureDelay[i]);
					}
					QueueAnim(LSAnim.GestureAnim[i], Target);
					(LastGestureTime += Target.GetAnimDuration(LSAnim.GestureAnim[i]));
					i++;
				}
			}
		}
		else
		{
			Log("EventLab::PlayLSAnim: Error: Target is None");
		}
	}
	else
	{
		Log("EventLab::PlayLSAnim(): Error: Anim not found: " @ FString::FromInt(Name));
	}
	*/
}

void AEventLab::PlayGameAnim(FName Anim, AActor* Target, float Rate, float TweenTime, int32 Channel, float AdditionalDelay)
{
	/*
	if (Rate == 0)
	{
		Rate = 1;
	}
	if (Target != nullptr)
	{
		SetTimerEvent(Anim, (Target.GetAnimDuration(Anim) + AdditionalDelay), 2, false);
		Target.PlayAnim(Anim, Rate, TweenTime, Channel);
	}
	else
	{
		Log("EventLab::PlayAnim(): Error: Target is None");
		return;
	}
	*/
}

void AEventLab::ParseParms(FString Parms)
{
	/*
	int32 pos = 0;
	FString TempStr = "";
	ParmList.Num() = 0;
	pos = InStr(Parms, ",");
	if (pos >= 0)
	{
		TempStr = Left(Parms, pos);
		ParmList.Num() = (ParmList.Num() + 1);
		ParmList[(ParmList.Num() - 1)] = Trim(TempStr);
		Parms = Right(Parms, (Len(Parms) - (pos + 1)));
		pos = InStr(Parms, ",");
	}
	ParmList.Num() = (ParmList.Num() + 1);
	ParmList[(ParmList.Num() - 1)] = Trim(Parms);
	*/
}

FString AEventLab::Trim(FString tString)
{
	/*
	if (Left(tString, 1) == " ")
	{
		tString = Right(tString, (Len(tString) - 1));
	}
	if (Right(tString, 1) == " ")
	{
		tString = Left(tString, (Len(tString) - 1));
	}
	*/
	return tString;
}

FString AEventLab::ReplaceCommandString(FString Text)
{
	int32 pos1 = 0;
	int32 pos2 = 0;
	FString ActionKey = "";
	FString TempStr = "";
	FString FinalStr = "";
	/*
	pos1 = InStr(Text, "<");
	pos2 = InStr(Text, ">");
	if ((pos1 < 0) && (pos2 < 0))
	{
		DebugLog(DEBUG_EventLab, "EventLab::AddCommandkeys(): Warning: matching command symbols not found ( <...> ) for text: " + Text);
		return Text;
	}
	if ((pos1 >= 0) && (pos2 >= 0))
	{
		TempStr = Left(Text, pos1);
		ActionKey = Left(Text, pos2);
		ActionKey = Right(ActionKey, (Len(ActionKey) - (pos1 + 1)));
		TempStr = TempStr + GetCommandKey(ActionKey);
		Text = Right(Text, (Len(Text) - (pos2 + 1)));
		FinalStr = FinalStr + TempStr;
		pos1 = InStr(Text, "<");
		pos2 = InStr(Text, ">");
	}
	FinalStr = FinalStr + Text;
	*/
	return FinalStr;
}

FString AEventLab::GetCommandKey(FString cmdname)
{
	UConsole* Console = nullptr;
	FString cmdkeyname = "";
	EInputKey cmdkey = EInputKey::IK_None;
	int32 Count = 0;
	FString retval = "";
	/*
	Console = Controller.Player.Console;
	retval = "<";
	cmdkeyname = "";
	Count = 0;
	if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
	{
		if (Count > 0)
		{
			retval = retval + " or ";
		}
		retval = retval + Caps(cmdkeyname);
		Count++;
	}
	if (retval == "")
	{
		return "ERROR!";
	}
	return retval + ">";
	*/
	return "FAKE";     //FAKE    /EliZ
}

float AEventLab::FRandS()
{
	/*
	if (FMath::FRand() >= 0.5)
	{
		return (FMath::FRand() * float(-1));
	}
	else
	{
		return FMath::FRand();
	}
	*/
	return 0;   //FAKE   /ELiZ
}

int32 AEventLab::RandS(int32 Num)
{
	/*
	if (Rand(2) == 0)
	{
		return (Rand(Num) * -1);
	}
	else
	{
		return Rand(Num);
	}
	*/
	return 0;   //FAKE   /ELiZ
}

void AEventLab::SetCrossHairColor(FName Color)
{
	/*
	uint8 iColor = 0;
	if (AController* != nullptr)
	{
		switch (Color)
		{
		case 'Yellow':
			iColor = 0;
			break;
		case 'Green':
			iColor = 1;
			break;
		case 'Red':
			iColor = 2;
			break;
		default:
			break;
		}
		Cast<AAGP_HUD>(Controller.myHUD).SetHUDActor();
		HUDCrosshair(Cast<AAGP_HUD>(Controller.myHUD).GetHUDControl(10)).SetCrossHairColor(iColor);
		Cast<AAGP_HUD>(Controller.myHUD).FreeHUDActor();
	}
	else
	{
		Log("EventLab::SetCrosshairColor(): ERROR: AController* Is None for " + FString::FromInt(Class));
	}
	*/
}

void AEventLab::EnableCrosshair()
{
	/*
	if (Player != nullptr)
	{
		Player.bForceDrawCrosshair = true;
	}
	else
	{
		Log("EventLab::EnableCrosshair(): ERROR: Player Is None for " + FString::FromInt(Class));
	}
	*/
}

void AEventLab::DisableCrosshair()
{
	/*
	if (Player != nullptr)
	{
		Player.bForceDrawCrosshair = false;
	}
	else
	{
		Log("EventLab::DisableCrosshair(): ERROR: Player Is None for " + FString::FromInt(Class));
	}
	*/
}

int32 AEventLab::QueryClock()
{
	//return Level.Game.GameReplicationInfo.TimeLimit;

	return 0;     //FAKE    /EliZ
}

void AEventLab::ResumeClock()
{
	//Level.Game.GameReplicationInfo.bStopCountDown = false;
}

void AEventLab::StartClock(int32 Time, bool bCountDown)
{
	/*
	Level.Game.GameReplicationInfo.TimeLimit = 32767;
	Level.Game.GameReplicationInfo.RemainingTime = Time;
	Level.Game.GameReplicationInfo.bStopCountDown = false;
	Level.Game.GameReplicationInfo.bCountUp = (!bCountDown);
	*/
}

void AEventLab::StopClock()
{
	//Level.Game.GameReplicationInfo.bStopCountDown = true;
}

void AEventLab::ClearClock()
{
	/*
	Level.Game.GameReplicationInfo.TimeLimit = -1;
	Level.Game.GameReplicationInfo.RemainingTime = 0;
	Level.Game.GameReplicationInfo.bStopCountDown = true;
	Level.Game.GameReplicationInfo.bCountUp = false;
	*/
}

void AEventLab::ResetClock()
{
	/*
	Level.Game.GameReplicationInfo.TimeLimit = 32767;
	Level.Game.GameReplicationInfo.RemainingTime = 0;
	Level.Game.GameReplicationInfo.bStopCountDown = true;
	Level.Game.GameReplicationInfo.bCountUp = false;
	*/
}

void AEventLab::EnableHUD()
{
	/*
	if (AController* != nullptr)
	{
		Controller.AGPHUD(true);
	}
	else
	{
		Log("EventLab::EnableHUD(): ERROR: AController* Is None for " + FString::FromInt(Class));
	}
	*/
}

void AEventLab::DisableHUD()
{
	/*
	if (AController* != nullptr)
	{
		Controller.AGPHUD(false);
	}
	else
	{
		Log("EventLab::DisableHUD(): ERROR: AController* Is None for " + FString::FromInt(Class));
	}
	*/
}

void AEventLab::GiveBinocs(APawn Target, uint8 ItemNum)
{
	//ItemNum = uint8(Clamp(ItemNum, 0, 4));
	//Target._InvBinoculars = ItemNum;
}

AActor* AEventLab::GetActor(FName ActorTag)
{
	AActor* A = nullptr;
	/*
	A = GetActorByTag(ActorTag);
	if (A != nullptr)
	{
		return A;
	}
	else
	{
		Log("EventLab::GetActor(): ERROR: AActor* with tag " + FString::FromInt(ActorTag) + " not found");
	}
	*/
	return nullptr;    //FAKE    /EliZ

}

FVector AEventLab::GetActorLocation(FName ActorTag)
{
	AActor* A = nullptr;
	/*
	A = GetActorByTag(ActorTag);
	if (A != nullptr)
	{
		if (bDebug)
		{
			DebugLog(DEBUG_EventLab, "EventLab::GetActorLocation(): Returning Location: " + FString::FromInt(A.Location));
		}
		return A.Location;
	}
	else
	{
		Log("EventLab::GetActorLocation(): ERROR: AActor* with tag " + FString::FromInt(ActorTag) + " not found");
	}
	*/
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}

FRotator AEventLab::GetActorRotation(FName ActorTag)
{
	AActor* A = nullptr;
	/*
	A = GetActorByTag(ActorTag);
	if (A != nullptr)
	{
		return A.Rotation;
	}
	else
	{
		Log("EventLab::GetActorRotation(): ERROR: AActor* with tag " + FString::FromInt(ActorTag) + " not found");
	}
	*/
	return FRotator(0,0,0);    //FAKE   /ELiZ
}

void AEventLab::HidePlayer()
{
	/*
	if (Player != nullptr)
	{
		Player.bHidden = true;
		SetCollision(false, false, false);
	}
	else
	{
		Log("EventLab::HidePlayer(): ERROR: Player Is None for " + FString::FromInt(Class));
	}
	*/
}

void AEventLab::ShowPlayer()
{
	/*
	if (Player != nullptr)
	{
		Player.bHidden = false;
		SetCollision(true, true, true);
	}
	else
	{
		Log("EventLab::ShowPlayer(): ERROR: Player Is None for " + FString::FromInt(Class));
	}
	*/
}

ASceneManager* AEventLab::StartScene(FName scenetag, FName StartLocation)
{
	ASceneManager* SM = nullptr;
	/*
	SM = SceneManager(GetActorByTag(scenetag));
	if (SM == nullptr)
	{
		Log("SceneManager::StartScene(): Error: SceneManager not found with Tag: " + FString::FromInt(scenetag));
		return nullptr;
	}
	else
	{
		SM.SetEventLab(this);
		SM.StartScene();
		return SM;
	}
	*/
	return nullptr;       //FAKE   /EliZ
}

void AEventLab::EndScene(FName scenetag)
{
	ASceneManager* SM = nullptr;
	/*
	SM = SceneManager(GetActorByTag(scenetag));
	if (SM == nullptr)
	{
		Log("SceneManager::EndScene(): Error: SceneManager not found with Tag: " + FString::FromInt(scenetag));
	}
	else
	{
		SM.EndScene();
	}
	*/
}

void AEventLab::ZoomFOV(float StartFOV, float EndFOV, float Time)
{
	/*
	FOVZoomTime = Time;
	OldFOV = StartFOV;
	NewFOV = EndFOV;
	bZoomFOV = true;
	Controller.SetFOV(StartFOV);
	DebugLog(DEBUG_EventLab, "StartFOV: " + FString::FromInt(StartFOV) + " - EndFOV: " + FString::FromInt(EndFOV) + " - Time: " + FString::FromInt(Time));
	*/
}

void AEventLab::RestoreFOV()
{
	/*
	if (AController* != nullptr)
	{
		Controller.SetFOV(GetDefaultFOV());
	}
	*/
}

void AEventLab::SetFOV(float FOV)
{
	/*
	if (AController* != nullptr)
	{
		Controller.SetFOV(FOV);
	}
	*/
}

float AEventLab::GetFOV()
{
	/*
	if (AController* != nullptr)
	{
		return Controller.FovAngle;
	}
	*/
	return 0;    //FAKE   /EliZ
}

float AEventLab::GetDefaultFOV()
{
	/*
	if (AController* != nullptr)
	{
		return Controller.DefaultFOV;
	}
	*/
	return 0;    //FAKE   /EliZ
}

void AEventLab::TransitionGameSpeed(float Speed, float Time)
{
	/*
	GameSpeedTransTime = Time;
	NewGameSpeed = Speed;
	StartGameSpeed = Level.TimeDilation;
	bTransGameSpeed = true;
	*/
}

void AEventLab::SetGameSpeed(float Speed)
{
	/*
	if (Speed == 0)
	{
		return;
	}
	Level.Game.SetGameSpeed(Speed);
	*/
}

float AEventLab::GetGameSpeed()
{
	//return Level.TimeDilation;
	return 0;    //FAKE   /EliZ
}

void AEventLab::PlayTip(FString text1, FString text2, float FadeTime)
{
	/*
	Controller.SetPlayTips(ReplaceCommandString(text1), ReplaceCommandString(text2), FadeTime);
	DebugLog(DEBUG_EventLab, "EventLab::PlayTip()");
	*/
}

void AEventLab::DisplayMissionCompleteOther(FString aTexture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, FString OtherMenu)
{
	//Controller.DisplayMissionCompleteOther(aTexture, Text, text2, USize, VSize, RenderStyle, replayscene, OtherMenu);
}

void AEventLab::DisplayMissionSuccess(FString aTexture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	Controller.DisplayMissionSuccess(aTexture, Text, text2, USize, VSize, RenderStyle, replayscene);
	if (((Level.Game.Stats != nullptr) && (AController* != nullptr)) && (Controller.PlayerStatsIndex >= 0))
	{
		Level.Game.Stats.PlayerStats[Controller.PlayerStatsIndex].StatEvent_TrainingMissionSuccess();
	}
	*/
}

void AEventLab::DisplayMissionFailure(FString aTexture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	Controller.DisplayMissionFailure(aTexture, Text, text2, USize, VSize, RenderStyle, replayscene);
	if (((Level.Game.Stats != nullptr) && (AController* != nullptr)) && (Controller.PlayerStatsIndex >= 0))
	{
		Level.Game.Stats.PlayerStats[Controller.PlayerStatsIndex].StatEvent_TrainingMissionFailure();
	}
	*/
}

void AEventLab::PlayerLock(bool Movement, bool Rotation)
{
	/*
	if (AController* != nullptr)
	{
		Controller.LockPlayer(Movement, Rotation);
	}
	else
	{
		Log("EventLab::PlayerLock(): Error: AController* is None for " + FString::FromInt(this));
	}
	*/
}

void AEventLab::FadeOut(float FadeTime, bool bBlack)
{
	//Controller.DoFade(false, bBlack, FadeTime);
}

void AEventLab::FadeIn(float FadeTime, bool bBlack)
{
	//Controller.DoFade(true, bBlack, FadeTime);
}

void AEventLab::FadeOutBlack(float FadeTime)
{
	//Controller.DoFade(false, true, FadeTime);
}

void AEventLab::FadeInBlack(float FadeTime)
{
	//Controller.DoFade(true, true, FadeTime);
}

void AEventLab::RunConsoleCommand(FString Command)
{
	//Controller.ConsoleCommand(Command);
}

void AEventLab::GhostPlayer()
{
	//Controller.MPCheat_EnterGhostMode();
}

void AEventLab::UnGhostPlayer()
{
	//Controller.MPCheat_Walk();
}

void AEventLab::CueCamera(AActor* Camera)
{
	//Controller.ClientSetViewTarget2(Camera);
}

void AEventLab::CuePlayer()
{
	//Controller.ClientSetViewTarget2(Player);
}

void AEventLab::SetTargetManagerScoreKeeper(ATargetManager* TM)
{
	/*
	if (Cast<AAGP_HUD>(Controller.myHUD).mrFrame != nullptr)
	{
		Cast<AAGP_HUD>(Controller.myHUD).mrFrame.SetScoreKeeper(TM.getScoreKeeper());
	}
	else
	{
		Log("SetTargetManagerScoreKeeper() - mrFrame none");
	}
	*/
}

void AEventLab::TargetManagerPause(ATargetManager* TM, bool bPause)
{
	/*
	if (TM != nullptr)
	{
		TM.bPaused = bPause;
	}
	else
	{
		Log("TargetManagerPause() - TargetManager none");
	}
	*/
}

int32 AEventLab::GetTargetManagerTotalScore(ATargetManager* TM)
{
	/*
	if (TM != nullptr)
	{
		return TM._ScoreKeeper.TotalScore.nShot;
	}
	else
	{
		Log("GetTargetScore() - TargetManager none");
	}
	*/
	return -1;
}

void AEventLab::TargetManagerActive(ATargetManager* TM, bool bTMActive)
{
	/*
	if (TM != nullptr)
	{
		if (bTMActive)
		{
			TM.Trigger(this, nullptr);
		}
		else
		{
			TM.UnTrigger(this, nullptr);
		}
	}
	else
	{
		Log("TargetManagerActive() - TargetManager none");
	}
	*/
}

void AEventLab::TargetManagerPracticeMode(ATargetManager* TM, bool bPracticeMode)
{
	/*
	if (TM != nullptr)
	{
		TM.SetTargetPractice(bPracticeMode);
	}
	else
	{
		Log("TargetManagerPracticeMode() - TargetManager none");
	}
	*/
}

void AEventLab::TargetManagerResetScores(ATargetManager* TM)
{
	//TM.ResetScores();
}

void AEventLab::PlayerPressedFire()
{
}

void AEventLab::EL_ES2ObjectFound(int32 Score)
{
}

