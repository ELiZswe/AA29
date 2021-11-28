// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "Components/BillboardComponent.h"

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
 	// Set this AActor* to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bDebug = true;
	bDoGeneralInit = true;
	//bHidden = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

// Called when the game starts or when spawned
void AEventLab::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

// Called every frame
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
		DebugLog(DEBUG_EventLab, "EventLab Initialized: " $ string(Tag));
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
	if (((Level.Game.Stats != None) && (AController* != None)) && (Controller.PlayerStatsIndex >= 0))
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
	/*
	local IpDrv.InternetLink ILink;
	int32 i = 0;
	int32 NameLen = 0;
	int32 Value = 0;
	FString hostname = "";
	ILink = Spawn(Class'IpDrv.InternetLink');
	if (ILink != None)
	{
		hostname = ILink.GetLocalHostName();
		ILink.Destroy();
		ILink = None;
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
		Log("EventLab: ILink couldn't Be Spawned for script: " $ string(Self));
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
	DebugLog(DEBUG_EventLab, "DoZoomFOV: " $ string(GetFOV()));
	*/
}

void AEventLab::QueueAnim(FName Anim, AActor* A, bool bLoop, float Rate, float TweenTime, int32 Channel)
{
	/*
	int32 Index = 0;
	float StartTime = 0;
	if (A == None)
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
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Queue is empty, playing: " $ string(Anim));
		A.PlayAnim(Anim, Rate, TweenTime, Channel);
		StartTime = Level.TimeSeconds;
		QueueAnim_Begin(Anim);
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Anim StartTime is: " $ string(StartTime));
	}
	else
	{
		DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Getting ready to flag looping anims for removal");
		FlagLoopingQueueAnims(A);
	}
	DebugLog(DEBUG_EventLab, "EventLab::QueueAnim(): Anim Queued: " $ string(Anim));
	Index = AnimQueue.Length;
	AnimQueue.insert(Index, 1);
	AnimQueue[Index].Anim = Anim;
	AnimQueue[Index].Length = A.GetAnimDuration(Anim, Rate);
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
	if (A == None)
	{
		Log("EventLab::QueueAnim(): Error: AActor* is None");
		return;
	}
	StartTime = -1;
	if (AnimQueueIsEmpty(A))
	{
		if (bDebug)
		{
			Log("EventLab::QueueAnimDelay(): Queue is empty, starting delay: " $ string(Delay));
		}
		StartTime = Level.TimeSeconds;
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
		Log("EventLab::QueueAnimDelay(): Delay Queued: " $ string(Delay));
	}
	Index = AnimQueue.Length;
	AnimQueue.insert(Index, 1);
	AnimQueue[Index].Anim = 'None';
	AnimQueue[Index].Length = Delay;
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
	/*
	int32 i = 0;
	local AActor* A;
	if (i < AnimQueue.Length)
	{
		if (AnimQueue[i].StartTime == float(-1))
		{
			i++;
		}
		else
		{
			if ((Level.TimeSeconds - AnimQueue[i].StartTime) >= AnimQueue[i].Length)
			{
				A = AnimQueue[i].Actor;
				if (!AnimQueue[i].bLoop)
				{
					QueueAnim_End(AnimQueue[i].Anim);
					AnimQueue.remove(i, 1);
					DebugLog(DEBUG_EventLab, "EventLab::ProcessAnimQueue(): Non-Looping Anim Removed: " $ string(AnimQueue[i].Anim) $ " - For Actor: " $ string(A.Tag));
				}
				else
				{
					if (AnimQueue[i].bRemove)
					{
						QueueAnim_End(AnimQueue[i].Anim);
						AnimQueue.remove(i, 1);
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
	for (i = 0; i < AnimQueue.Length; i++)
	{
		if (AnimQueue[i].Actor == A)
		{
			DebugLog(DEBUG_EventLab, "EventLab::PlayNextQueueAnim: Playing Anim: " $ string(AnimQueue[i].Anim) $ " - For Actor: " $ string(A.Tag));
			A.PlayAnim(AnimQueue[i].Anim, AnimQueue[i].Rate, AnimQueue[i].TweenTime, AnimQueue[i].Channel);
			AnimQueue[i].StartTime = Level.TimeSeconds;
			QueueAnim_Begin(AnimQueue[i].Anim);
			return;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::PlayNextQueueAnim(): Didn't find an anim to play for: " $ string(A.Tag));
	*/
}

void AEventLab::FlagLoopingQueueAnims(AActor* A)
{
	/*
	int32 i = 0;
	for (i = 0; i < AnimQueue.Length; i++)
	{
		if ((AnimQueue[i].Actor == A) && AnimQueue[i].bLoop)
		{
			AnimQueue[i].bRemove = true;
			DebugLog(DEBUG_EventLab, "EventLab::FlagLoopingQueueAnims(): Looping Anim: " $ string(AnimQueue[i].Anim) $ " flagged for removal for Actor: " $ string(A));
		}
	}
	*/
}

bool AEventLab::AnimQueueIsEmpty(AActor* A)
{
	/*
	int32 i = 0;
	if (AnimQueue.Length == 0)
	{
		return true;
	}
	else
	{
		for (i = 0; i < AnimQueue.Length; i++)
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
	if (i < TimerEvents.Length)
	{
		if (TimerEvents[i].bPause)
		{
			(TimerEvents[i].StartTime += DeltaTime);
		}
		if ((Level.TimeSeconds - TimerEvents[i].StartTime) >= TimerEvents[i].WaitTime)
		{
			if (!Dispatcher_Timer(TimerEvents[i].Name, TimerEvents[i].TType))
			{
				LogUnHandledTimerEvent(TimerEvents[i].Name, TimerEvents[i].TType);
			}
			if (!TimerEvents[i].bRepeat)
			{
				TimerEvents.remove(i, 1);
			}
			else
			{
			else
			{
				TimerEvents[i].StartTime = Level.TimeSeconds;
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
	Index = TimerEvents.Length;
	i = 0;
	if (i < TimerEvents.Length)
	{
		if ((TimerEvents[i].Name == Name) && (TimerEvents[i].TType == TType))
		{
			Index = i;
			DebugLog(DEBUG_EventLab, "EventLab::SetTimerEvent(): Duplicate name: " $ string(Name) $ " was replaced in the timer list");
		}
		else
		{
			i++;
		}
	}
	if (Index == TimerEvents.Length)
	{
		TimerEvents.insert(Index, 1);
	}
	TimerEvents[Index].Name = Name;
	TimerEvents[Index].StartTime = Level.TimeSeconds;
	TimerEvents[Index].WaitTime = Time;
	TimerEvents[Index].TType = TType;
	TimerEvents[Index].bRepeat = bRepeat;
	*/
}

float AEventLab::QueryTimer(FName Name, ETimerType Type)
{
	/*
	int32 i = 0;
	for (i = 0; i < TimerEvents.Length; i++)
	{
		if ((TimerEvents[i].TType == Type) && (TimerEvents[i].Name == Name))
		{
			return FMax(((TimerEvents[i].WaitTime - Level.TimeSeconds) + TimerEvents[i].StartTime), 0);
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::QueryTimer(): Timer not found: " $ string(Name) $ " with type: " $ string(GetEnum(Enum'AGP_Script.EventLab.ETimerType', Type)));
	*/
	return 0;
}

void AEventLab::InitRefs()
{
	/*
	Controller = HumanController(Level.GetClientController());
	Player = AGP_Pawn(Level.GetClientPawn());
	*/
}

void AEventLab::LogUnHandledActorEvent(AActor* NotifyActor, EEventType Event, FString Parms)
{
	//DebugLog(DEBUG_EventLab, "EventLab::LogUnHandledActorEvent(): " $ "Event type: " $ string(GetEnum(Enum'Engine.EEventType', Event)) $ " for actor: " $ string(NotifyActor) $ " of class: " $ string(NotifyActor.Class) $ " with tag: " $ string(NotifyActor.Tag) $ " with parms: " $ Parms);
}

void AEventLab::LogUnHandledTimerEvent(FName Name, ETimerType Type)
{
	//DebugLog(DEBUG_EventLab, "EventLab::LogUnHandledTimerEvent(): " $ "Name: " $ string(Name) $ " Type: " $ string(GetEnum(Enum'AGP_Script.EventLab.ETimerType', Type)));
}

bool AEventLab::ActorNotify(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	if (bEventsDisabled)
	{
		DebugLog(DEBUG_EventLab, "EventLab::ActorNotify(): Event recieved, but events are disabled." $ " event type: " $ string(GetEnum(Enum'Engine.EEventType', Event)) $ " for actor: " $ string(NotifyActor) $ " of class: " $ string(NotifyActor.Class) $ " with tag: " $ string(NotifyActor.Tag) $ " with parms: " $ Parms);
		return false;
	}
	if (Actor_Custom(NotifyActor, Event, aInstigator, Parms))
	{
		return true;
	}
	if (NotifyActor.IsA('TargetManager'))
	{
		if (!Dispatcher_TargetManager(NotifyActor, Event, aInstigator, Parms))
		{
			LogUnHandledActorEvent(NotifyActor, Event, Parms);
		}
		return true;
	}
	if (NotifyActor.IsA('Trigger'))
	{
		if (!Dispatcher_Trigger(NotifyActor, aInstigator, Parms))
		{
			LogUnHandledActorEvent(NotifyActor, Event, Parms);
		}
		return true;
	}
	if (NotifyActor.IsA('AGP_Trigger'))
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
		if (NotifyActor.IsA('AGP_UseTrigger'))
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
			if (NotifyActor.IsA('Volume'))
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
				if (NotifyActor.IsA('Vehicle'))
				{
					if (!Dispatcher_Vehicle(NotifyActor, Event, aInstigator, Parms))
					{
						LogUnHandledActorEvent(NotifyActor, Event, Parms);
					}
					return true;
				}
				if (NotifyActor.IsA('Pawn'))
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
					case Class'AGP.AGP_Pawn':
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
					if (NotifyActor.IsA('AGP_VehicleFactory'))
					{
						if (!Dispatcher_AGP_VehicleFactory(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					}
					if (NotifyActor.IsA('Controller') && (Event == 30))
					{
						if (ELCheat(Parms))
						{
							Log("EventLab::ELCheat - EventLab Cheat \"" $ Parms $ "\" called");
						}
						break;
					}
					if (NotifyActor.IsA('Controller'))
					{
						switch (NotifyActor.Class)
						{
						case Class'AGP.StudentController':
							if (!Dispatcher_StudentController(NotifyActor, Event, aInstigator, Parms))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						case Class'AGP.HumanController':
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
					if (NotifyActor.IsA('ThrowWeaponPickup'))
					{
						if (Event == 10)
						{
							if (!ThrowWeaponPickup_GrenadeEffects(ThrowWeaponPickup(NotifyActor)))
							{
								LogUnHandledActorEvent(NotifyActor, Event, Parms);
							}
							return true;
						}
					}
					if (NotifyActor.IsA('BaseProjectile'))
					{
						if (!Dispatcher_BaseProjectile(NotifyActor, Event, aInstigator, Parms))
						{
							LogUnHandledActorEvent(NotifyActor, Event, Parms);
						}
						return true;
					}
					if (NotifyActor.IsA('AGP_Objective'))
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
						if (NotifyActor.IsA('Pickup'))
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
						if (NotifyActor.IsA('DecoMesh'))
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
							if (NotifyActor.IsA('AGP_Weapon'))
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
								if (NotifyActor.IsA('VehicleWeapon'))
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
								case Class'SceneManager':
									if (!Dispatcher_SceneManager(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case Class'InterpolationPoint':
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
								case Class'IpDrv.HttpGet':
									if (!Dispatcher_HttpGet(NotifyActor, Event, aInstigator, Parms))
									{
										LogUnHandledActorEvent(NotifyActor, Event, Parms);
									}
									return true;
								case Class'AGP.AGP_HUD':
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
		return TargerManager_DispatchComplete(TargetManager(NotifyActor), aInstigator, Parms);
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
		return SceneManager_SceneStart(SceneManager(NotifyActor), aInstigator, Parms);
	case 14:
		return SceneManager_SceneEnd(SceneManager(NotifyActor), aInstigator, Parms);
	case 15:
		return SceneManager_PointReached(SceneManager(NotifyActor), aInstigator, Parms);
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
		return InterpolationPoint_PointReached(InterpolationPoint(NotifyActor), aInstigator, Parms);
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
		return AGP_Hud_Custom(AGP_HUD(NotifyActor), aInstigator, Parms);
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
		return StaticMeshSwitcher_UsedBy(StaticMeshSwitcher(NotifyActor), aInstigator);
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
		return AGP_UseTrigger_UsedBy(AGP_UseTrigger(NotifyActor), aInstigator);
	case 4:
		return AGP_UseTrigger_Trigger(AGP_UseTrigger(NotifyActor), aInstigator);
	case 5:
		return AGP_UseTrigger_UnTrigger(AGP_UseTrigger(NotifyActor), aInstigator);
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
		return NoiseTrigger_Trigger(NoiseTrigger(NotifyActor), aInstigator, Parms);
	case 5:
		return NoiseTrigger_UnTrigger(NoiseTrigger(NotifyActor), aInstigator, Parms);
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
		return LookTrigger_Trigger(LookTrigger(NotifyActor), aInstigator, Parms);
	case 5:
		return LookTrigger_UnTrigger(LookTrigger(NotifyActor), aInstigator, Parms);
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
		return AGP_Trigger_Trigger(AGP_Trigger(NotifyActor), aInstigator);
	case 5:
		return AGP_Trigger_UnTrigger(AGP_Trigger(NotifyActor), aInstigator);
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
		return AGP_Objective_Trigger(AGP_Objective(NotifyActor), aInstigator);
	case 5:
		return AGP_Objective_UnTrigger(AGP_Objective(NotifyActor), aInstigator);
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
		return BaseProjectile_Explode(BaseProjectile(Projectile), aInstigator, Parms);
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
	//Trigger_Entered(Trigger(NotifyActor), aInstigator);
	return true;
}

bool AEventLab::Dispatcher_Pickup(AActor* NotifyActor, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	switch (Event)
	{
	case 2:
		return Pickup_PickedUp(Pickup(NotifyActor), aInstigator, Parms);
	case 1:
		return Pickup_AbortPickup(Pickup(NotifyActor), Pawn(aInstigator));
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
		return TargetMover_Damaged(TargetMover(NotifyActor), aInstigator, Parms);
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
		return DecoMesh_Damaged(DecoMesh(NotifyActor), aInstigator, Parms);
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
		return AGP_Weapon_Fire(AGP_Weapon(NotifyActor), aInstigator, Parms);
	case 18:
		return AGP_Weapon_Trace_Hit(AGP_Weapon(NotifyActor), aInstigator, Parms);
	case 19:
		return AGP_Weapon_Throw(AGP_Weapon(NotifyActor), aInstigator, Parms);
	case 3:
		return AGP_Weapon_Dropped(AGP_Weapon(NotifyActor), Pickup(aInstigator), Parms);
	case 31:
		return AGP_Weapon_Custom(AGP_Weapon(NotifyActor), aInstigator, Parms);
	case 20:
		return AGP_Weapon_Jam(AGP_Weapon(NotifyActor), aInstigator, Parms);
	case 21:
		return AGP_Weapon_Empty(AGP_Weapon(NotifyActor), aInstigator, Parms);
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
		return VehicleWeapon_Fire(VehicleWeapon(NotifyActor), aInstigator, Parms);
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
		return DoorTrigger_UsedBy(DoorTrigger(NotifyActor), aInstigator);
	case 4:
		return DoorTrigger_Trigger(DoorTrigger(NotifyActor), aInstigator);
	case 5:
		return DoorTrigger_UnTrigger(DoorTrigger(NotifyActor), aInstigator);
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
		return AGP_Character_Died(AGP_Character(NotifyActor), Controller(aInstigator));
	case 8:
		return AGP_Character_Damaged(AGP_Character(NotifyActor), Controller(aInstigator));
	case 31:
		return AGP_Character_Custom(AGP_Character(NotifyActor), aInstigator, Parms);
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
		return Pawn_Died(Pawn(NotifyActor), Controller(aInstigator));
	case 8:
		return Pawn_Damaged(Pawn(NotifyActor), Controller(aInstigator));
	case 31:
		return Pawn_Custom(Pawn(NotifyActor), aInstigator, Parms);
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
		return AGP_Pawn_Died(AGP_Pawn(NotifyActor), Controller(aInstigator));
	case 8:
		return AGP_Pawn_Damaged(AGP_Pawn(NotifyActor), Controller(aInstigator));
	case 31:
		return AGP_Pawn_Custom(AGP_Pawn(NotifyActor), aInstigator, Parms);
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
		return AGP_NPC_Died(AGP_NPC(NotifyActor), Controller(aInstigator));
	case 8:
		return AGP_NPC_Damaged(AGP_NPC(NotifyActor), Controller(aInstigator));
	case 31:
		return AGP_NPC_Custom(NPC_MedStudent(NotifyActor), aInstigator, Parms);
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
		return NPC_MedStudent_Custom(NPC_MedStudent(NotifyActor), aInstigator, Parms);
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
		return NPC_MedInstructor_Custom(NPC_MedInstructor(NotifyActor), aInstigator, Parms);
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
		return NPC_EEGuard_Custom(NPC_EEGuard(NotifyActor), aInstigator, Parms);
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
		if (AGP_Vehicle(NotifyActor) != None)
		{
			return AGP_Vehicle_Entered(AGP_Vehicle(NotifyActor), aController, Parms);
			break;
		}
		if (VehiclePosition(NotifyActor) != None)
		{
			return VehiclePosition_Entered(VehiclePosition(NotifyActor), aController, Parms);
		}
	}
	GOTO JL0129;
	case 26:
		if (AGP_Vehicle(NotifyActor) != None)
		{
			return AGP_Vehicle_Exited(AGP_Vehicle(NotifyActor), aController, Parms);
		}
		else
		{
			if (VehiclePosition(NotifyActor) != None)
			{
				return VehiclePosition_Exited(VehiclePosition(NotifyActor), aController, Parms);
			}
		}
	case 27:
		if (AGP_Vehicle(NotifyActor) != None)
		{
			return Vehicle_At(AGP_Vehicle(NotifyActor), aController, Parms);
		}
	case 28:
		if (AGP_Vehicle(NotifyActor) != None)
		{
			return AGP_Vehicle_Died(AGP_Vehicle(NotifyActor), aController, Parms);
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
		AGP_Vehicle_Spawned(AGP_VehicleFactory(NotifyActor), AGP_Vehicle(NewVehicle), Parms);
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
		return MedExam_Custom(MedExam(NotifyActor), aInstigator, Parms);
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
		return TriggerVolume_Enter(TriggerVolume(NotifyActor), aInstigator);
	case 7:
		return TriggerVolume_Exit(TriggerVolume(NotifyActor), aInstigator);
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
		return PhysicsVolume_Enter(PhysicsVolume(NotifyActor), aInstigator);
	case 7:
		return PhysicsVolume_Exit(PhysicsVolume(NotifyActor), aInstigator);
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
		return Volume_Enter(Volume(NotifyActor), aInstigator);
	case 7:
		return Volume_Exit(Volume(NotifyActor), aInstigator);
	case 8:
		return Volume_Damaged(Volume(NotifyActor), aInstigator);
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
		return RiskVolume_Enter(RiskVolume(NotifyActor), aInstigator, Parms);
	case 7:
		return RiskVolume_Exit(RiskVolume(NotifyActor), aInstigator, Parms);
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
		return Controller_LSAnimEnd(Controller(NotifyActor), aInstigator, Parms);
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
		return HumanController_Custom(HumanController(NotifyActor), aInstigator, Parms);
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
		return HttpGet_HttpGet(HttpGet(NotifyActor), aInstigator, Parms);
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
		return LevelInfo_FirstDraw(LevelInfo(NotifyActor), aInstigator, Parms);
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
		return StudentController_Custom(StudentController(NotifyActor), aInstigator, Parms);
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
		return DamageDetector_Damaged(DamageDetector(NotifyActor), aInstigator, Parms);
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
		return MarksmanTarget_Damaged(MarksmanTarget(NotifyActor), aInstigator, Parms);
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
	//Controller.SetEventLab(Self);
}

void AEventLab::CapturePlayer()
{
	//Player.SetEventLab(Self);
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
		sMinutes = "0" $ string(nMinutes);
	}
	else
	{
		sMinutes = string(nMinutes);
	}
	if (bHundredths)
	{
		if (nSeconds < float(10))
		{
			sSeconds = "0" $ string(nSeconds);
		}
		else
		{
			sSeconds = string(nSeconds);
		}
	}
	else
	{
		if (nSeconds < float(10))
		{
			sSeconds = "0" $ string(int(nSeconds));
		}
		else
		{
			sSeconds = string(int(nSeconds));
		}
	}
	return sMinutes $ ":" $ sSeconds;
	*/
	return "FAKE";     //FAKE    /EliZ
}

bool AEventLab::AnimIsQueued(FName Anim, AActor* A)
{
	/*
	int32 i = 0;
	for (i = 0; i < AnimQueue.Length; i++)
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
	for (i = 0; i < TimerEvents.Length; i++)
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
	for (i = 0; i < TimerEvents.Length; i++)
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
	for (i = 0; i < TimerEvents.Length; i++)
	{
		if (TimerEvents[i].TType == Type)
		{
			TimerEvents[i].Name = 'None';
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
	for (i = 0; i < TimerEvents.Length; i++)
	{
		if ((TimerEvents[i].Name == StopName) && (TimerEvents[i].TType == Type))
		{
			TimerEvents[i].Name = 'None';
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
	for (i = 0; i < TimerEvents.Length; i++)
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
	for (i = 0; i < TimerEvents.Length; i++)
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
	for (i = 0; i < TimerEvents.Length; i++)
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
	DebugLog(DEBUG_EventLab, "EventLab::ChangeState(): Before state change, state is " @ string(GetStateName()));
	PreviousState = GetStateName();
	GotoState(State, Label);
	DebugLog(DEBUG_EventLab, "EventLab::ChangeState(): State is now: " @ string(GetStateName()));
	DebugLog(DEBUG_EventLab, "-----------------------------------------------------------");
	*/
}

AActor* AEventLab::CaptureEvent(FName Tag, AActor* classTypeToFind)
{
	/*
	local AActor* A;
	local AActor* cActor;
	int32 ACount = 0;
	ForEach AllActors(Class'Actor', A)
	{
		if (classTypeToFind != None)
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
	if (cActor == None)
	{
		Log("EventLab::CaptureEvent: Error: Tag not found: " @ string(Tag));
		return None;
	}
	else
	{
		if (ACount > 1)
		{
			Log("EventLab::CaptureEvent: Error: Multiple tags found: " @ string(Tag));
			return None;
		}
		else
		{
			cActor.SetEventLab(Self);
			return cActor;
		}
	}
	*/
	return nullptr;
}

void AEventLab::ReCaptureEvent(AActor* Actor)
{
	/*
	if (AActor* != None)
	{
		Actor.SetEventLab(Self);
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
	if (AActor* != None)
	{
		Actor.SetEventLab(None);
	}
	else
	{
		Log("EventLab::UnCaptureEvent(): Error: AActor* is None");
	}
	*/
}

void AEventLab::CaptureEventGroup(FName Tag)
{
	/*
	local AActor* A;
	int32 ACount = 0;
	ForEach AllActors(Class'Actor', A)
	{
		if (A.Tag == Tag)
		{
			A.SetEventLab(Self);
			ACount++;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::CaptureEventGroup: Captured " $ string(ACount) $ " actors with tag " $ string(Tag));
	if (ACount == 0)
	{
		DebugLog(DEBUG_EventLab, "EventLab::CaptureEventGroup: Warning: No actors found with tag: " $ string(Tag));
	}
	*/
}

void AEventLab::UnCaptureEventGroup(FName Tag)
{
	/*
	local AActor* A;
	int32 ACount = 0;
	ForEach AllActors(Class'Actor', A)
	{
		if (A.Tag == Tag)
		{
			A.SetEventLab(None);
			ACount++;
		}
	}
	DebugLog(DEBUG_EventLab, "EventLab::UnCaptureEventGroup: UnCaptured " $ string(ACount) $ " actors with tag " $ string(Tag));
	if (ACount == 0)
	{
		DebugLog(DEBUG_EventLab, "EventLab::UnCaptureEventGroup: Warning: No actors found with tag: " $ string(Tag));
	}
	*/
}

void AEventLab::TriggerActor(AActor* TargetActor)
{
	/*
	if (TargetActor != None)
	{
		TargetActor.Trigger(Self, Player);
	}
	else
	{
		Log("EventLab::TriggerActor(): Error: TargetActor is None");
	}
	*/
}

void AEventLab::TriggerGroup(FName Tag)
{
	//TriggerEvent(Tag, Self, Player);
}

USoundBase* AEventLab::GetGameSound(FName Name)
{
	/*
	int32 i = 0;
	for (i = 0; i < GameSounds.Length; i++)
	{
		if (GameSounds[i].Name == Name)
		{
			return GameSounds[i].Sound;
		}
	}
	Log("EventLab::GetGameSound(): Error: GameSound not found for " $ string(Name));
	*/
	return nullptr;
}

float AEventLab::PlayGameSound(FName Name, AActor* Target, ESoundSlot Slot, float Volume, float Radius, float AdditionalDelay)
{
	/*
	local Sound Sound;
	if (AVolume* == 0)
	{
		Volume = 1;
	}
	Sound = GetGameSound(Name);
	DebugLog(DEBUG_EventLab, "Sound " $ string(Name) $ " is: " $ string(Sound));
	if ((Sound != None) && (Target != None))
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

/*
ALSAnim* AEventLab::GetLSAnim(FName Name)
{
	int32 i = 0;
	for (i = 0; i < LSAnims.Length; i++)
	{
		if (LSAnims[i].Anim == Name)
		{
			return LSAnims[i];
		}
	}
	Log("EventLab::GetLSAnim(): Error: Name not found: " @ string(Name));
}
*/

void AEventLab::PlayLSAnim(FName Name, AActor* Target, float Volume, float Radius, float Pitch, float AdditionalDelay)
{
	/*
	local LSAnim LSAnim;
	int32 i = 0;
	float LastGestureTime = 0;
	if (AVolume* == 0)
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
	if ((LSAnim.Anim != 'None') && (LSAnim.Anim != 'None'))
	{
		if (Target != None)
		{
			DebugLog(DEBUG_EventLab, "EventLab::PlayLSAnim(): Calling PlayLipSincAnim() for anim: " $ string(LSAnim.Anim));
			SetTimerEvent(LSAnim.Anim, (GetSoundDuration(LSAnim.Sound) + AdditionalDelay), 3, false);
			Target.PlayLIPSincAnim(LSAnim.Anim, Volume, Radius, Pitch);
			if (10 > 0)
			{
				LastGestureTime = 0;
				i = 0;
				if ((i < 10) && (LSAnim.GestureAnim[i] != 'None'))
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
		Log("EventLab::PlayLSAnim(): Error: Anim not found: " @ string(Name));
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
	if (Target != None)
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
	ParmList.Length = 0;
	pos = InStr(Parms, ",");
	if (pos >= 0)
	{
		TempStr = Left(Parms, pos);
		ParmList.Length = (ParmList.Length + 1);
		ParmList[(ParmList.Length - 1)] = Trim(TempStr);
		Parms = Right(Parms, (Len(Parms) - (pos + 1)));
		pos = InStr(Parms, ",");
	}
	ParmList.Length = (ParmList.Length + 1);
	ParmList[(ParmList.Length - 1)] = Trim(Parms);
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
		DebugLog(DEBUG_EventLab, "EventLab::AddCommandkeys(): Warning: matching command symbols not found ( <...> ) for text: " $ Text);
		return Text;
	}
	if ((pos1 >= 0) && (pos2 >= 0))
	{
		TempStr = Left(Text, pos1);
		ActionKey = Left(Text, pos2);
		ActionKey = Right(ActionKey, (Len(ActionKey) - (pos1 + 1)));
		TempStr = TempStr $ GetCommandKey(ActionKey);
		Text = Right(Text, (Len(Text) - (pos2 + 1)));
		FinalStr = FinalStr $ TempStr;
		pos1 = InStr(Text, "<");
		pos2 = InStr(Text, ">");
	}
	FinalStr = FinalStr $ Text;
	*/
	return FinalStr;
}

FString AEventLab::GetCommandKey(FString cmdname)
{
	/*
	local Console Console;
	FString cmdkeyname = "";
	local Interactions.EInputKey cmdkey;
	int32 Count = 0;
	FString retval = "";
	Console = Controller.Player.Console;
	retval = "<";
	cmdkeyname = "";
	Count = 0;
	if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
	{
		if (Count > 0)
		{
			retval = retval $ " or ";
		}
		retval = retval $ Caps(cmdkeyname);
		Count++;
	}
	if (retval == "")
	{
		return "ERROR!";
	}
	return retval $ ">";
	*/
	return "FAKE";     //FAKE    /EliZ
}

float AEventLab::FRandS()
{
	/*
	if (FRand() >= 0.5)
	{
		return (FRand() * float(-1));
	}
	else
	{
		return FRand();
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
	if (AController* != None)
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
		AGP_HUD(Controller.myHUD).SetHUDActor();
		HUDCrosshair(AGP_HUD(Controller.myHUD).GetHUDControl(10)).SetCrossHairColor(iColor);
		AGP_HUD(Controller.myHUD).FreeHUDActor();
	}
	else
	{
		Log("EventLab::SetCrosshairColor(): ERROR: AController* Is None for " $ string(Class));
	}
	*/
}

void AEventLab::EnableCrosshair()
{
	/*
	if (Player != None)
	{
		Player.bForceDrawCrosshair = true;
	}
	else
	{
		Log("EventLab::EnableCrosshair(): ERROR: Player Is None for " $ string(Class));
	}
	*/
}

void AEventLab::DisableCrosshair()
{
	/*
	if (Player != None)
	{
		Player.bForceDrawCrosshair = false;
	}
	else
	{
		Log("EventLab::DisableCrosshair(): ERROR: Player Is None for " $ string(Class));
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
	if (AController* != None)
	{
		Controller.AGPHUD(true);
	}
	else
	{
		Log("EventLab::EnableHUD(): ERROR: AController* Is None for " $ string(Class));
	}
	*/
}

void AEventLab::DisableHUD()
{
	/*
	if (AController* != None)
	{
		Controller.AGPHUD(false);
	}
	else
	{
		Log("EventLab::DisableHUD(): ERROR: AController* Is None for " $ string(Class));
	}
	*/
}

void AEventLab::GiveBinocs(APawn Target, uint8 ItemNum)
{
	//ItemNum = byte(Clamp(ItemNum, 0, 4));
	//Target._InvBinoculars = ItemNum;
}

AActor* AEventLab::GetActor(FName ActorTag)
{
	/*
	local AActor* A;
	A = GetActorByTag(ActorTag);
	if (A != None)
	{
		return A;
	}
	else
	{
		Log("EventLab::GetActor(): ERROR: AActor* with tag " $ string(ActorTag) $ " not found");
	}
	*/
	return nullptr;    //FAKE    /EliZ

}

FVector AEventLab::GetActorLocation(FName ActorTag)
{
	/*
	local AActor* A;
	A = GetActorByTag(ActorTag);
	if (A != None)
	{
		if (bDebug)
		{
			DebugLog(DEBUG_EventLab, "EventLab::GetActorLocation(): Returning Location: " $ string(A.Location));
		}
		return A.Location;
	}
	else
	{
		Log("EventLab::GetActorLocation(): ERROR: AActor* with tag " $ string(ActorTag) $ " not found");
	}
	*/
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}

FRotator AEventLab::GetActorRotation(FName ActorTag)
{
	/*
	local AActor* A;
	A = GetActorByTag(ActorTag);
	if (A != None)
	{
		return A.Rotation;
	}
	else
	{
		Log("EventLab::GetActorRotation(): ERROR: AActor* with tag " $ string(ActorTag) $ " not found");
	}
	*/
	return FRotator(0,0,0);    //FAKE   /ELiZ
}

void AEventLab::HidePlayer()
{
	/*
	if (Player != None)
	{
		Player.bHidden = true;
		SetCollision(false, false, false);
	}
	else
	{
		Log("EventLab::HidePlayer(): ERROR: Player Is None for " $ string(Class));
	}
	*/
}

void AEventLab::ShowPlayer()
{
	/*
	if (Player != None)
	{
		Player.bHidden = false;
		SetCollision(true, true, true);
	}
	else
	{
		Log("EventLab::ShowPlayer(): ERROR: Player Is None for " $ string(Class));
	}
	*/
}

ASceneManager* AEventLab::StartScene(FName scenetag, FName StartLocation)
{
	/*
	local SceneManager SM;
	SM = SceneManager(GetActorByTag(scenetag));
	if (SM == None)
	{
		Log("SceneManager::StartScene(): Error: SceneManager not found with Tag: " $ string(scenetag));
		return None;
	}
	else
	{
		SM.SetEventLab(Self);
		SM.StartScene();
		return SM;
	}
	*/
	return nullptr;       //FAKE   /EliZ
}

void AEventLab::EndScene(FName scenetag)
{
	/*
	local SceneManager SM;
	SM = SceneManager(GetActorByTag(scenetag));
	if (SM == None)
	{
		Log("SceneManager::EndScene(): Error: SceneManager not found with Tag: " $ string(scenetag));
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
	DebugLog(DEBUG_EventLab, "StartFOV: " $ string(StartFOV) $ " - EndFOV: " $ string(EndFOV) $ " - Time: " $ string(Time));
	*/
}

void AEventLab::RestoreFOV()
{
	/*
	if (AController* != None)
	{
		Controller.SetFOV(GetDefaultFOV());
	}
	*/
}

void AEventLab::SetFOV(float FOV)
{
	/*
	if (AController* != None)
	{
		Controller.SetFOV(FOV);
	}
	*/
}

float AEventLab::GetFOV()
{
	/*
	if (AController* != None)
	{
		return Controller.FovAngle;
	}
	*/
	return 0;    //FAKE   /EliZ
}

float AEventLab::GetDefaultFOV()
{
	/*
	if (AController* != None)
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
	if (((Level.Game.Stats != None) && (AController* != None)) && (Controller.PlayerStatsIndex >= 0))
	{
		Level.Game.Stats.PlayerStats[Controller.PlayerStatsIndex].StatEvent_TrainingMissionSuccess();
	}
	*/
}

void AEventLab::DisplayMissionFailure(FString aTexture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	Controller.DisplayMissionFailure(aTexture, Text, text2, USize, VSize, RenderStyle, replayscene);
	if (((Level.Game.Stats != None) && (AController* != None)) && (Controller.PlayerStatsIndex >= 0))
	{
		Level.Game.Stats.PlayerStats[Controller.PlayerStatsIndex].StatEvent_TrainingMissionFailure();
	}
	*/
}

void AEventLab::PlayerLock(bool Movement, bool Rotation)
{
	/*
	if (AController* != None)
	{
		Controller.LockPlayer(Movement, Rotation);
	}
	else
	{
		Log("EventLab::PlayerLock(): Error: AController* is None for " $ string(Self));
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
	if (AGP_HUD(Controller.myHUD).mrFrame != None)
	{
		AGP_HUD(Controller.myHUD).mrFrame.SetScoreKeeper(TM.getScoreKeeper());
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
	if (TM != None)
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
	if (TM != None)
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
	if (TM != None)
	{
		if (bTMActive)
		{
			TM.Trigger(Self, None);
		}
		else
		{
			TM.UnTrigger(Self, None);
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
	if (TM != None)
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

