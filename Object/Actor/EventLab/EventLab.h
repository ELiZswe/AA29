// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "EventLab.generated.h"

class AAGP_Character;
class AAGP_NPC;
class AAGP_Pawn;
class AAGP_Trigger;
class AAGP_Vehicle;
class AAGP_VehicleFactory;
class AAGP_Weapon;
class ABaseProjectile;
class ADamageDetector;
class ADoorTrigger;
class AGP_UseTrigger;
class AHttpGet;
class AHumanController;
class AInterpolationPoint;
class ALookTrigger;
class AMedExam;
class ANPC_EEGuard;
class ANPC_MedInstructor;
class ANPC_MedStudent;
class ANoiseTrigger;
class APickup;
class ARiskVolume;
class ASceneManager;
class ASpawningFactory;
class AStaticMeshSwitcher;
class AStudentController;
class ATargetManager;
class ATargetMover;
class AThrowWeaponPickup;
class ATrigger;
class AVehiclePosition;
class AVehicleWeapon;
class AAGP_HUD;
class USceneComponent;
class UBillboardComponent;

UCLASS()
class AEventLab : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventLab();

	UPROPERTY()						float LevelBeginFadeInTime;									//var float LevelBeginFadeInTime;
	UPROPERTY()						bool bUseLevelBeginFadeIn;									//var bool bUseLevelBeginFadeIn;
	UPROPERTY()						int32 MachineID;											//var int MachineID;
	UPROPERTY()						float StartGameSpeed;										//var float StartGameSpeed;
	UPROPERTY()						float NewGameSpeed;											//var float NewGameSpeed;
	UPROPERTY()						float GameSpeedTransTime;									//var float GameSpeedTransTime;
	UPROPERTY()						bool bTransGameSpeed;										//var bool bTransGameSpeed;
	UPROPERTY()						float OldFOV;												//var float OldFOV;
	UPROPERTY()						float NewFOV;												//var float NewFOV;
	UPROPERTY()						float FOVZoomTime;											//var float FOVZoomTime;
	UPROPERTY()						bool bZoomFOV;												//var bool bZoomFOV;
	UPROPERTY()						FName RememberedStates;										//var name RememberedStates;
	UPROPERTY()						TArray<FTimerEvent> TimerEvents;							//var array<TimerEvent> TimerEvents;
	UPROPERTY()						TArray<FQueueAnimation> AnimQueue;							//var array<QueueAnimation> AnimQueue;
	UPROPERTY()						FName PreviousState;										//var name PreviousState;
	UPROPERTY()						bool bInitialized;											//var bool bInitialized;
	UPROPERTY()						TArray<FString> ParmList;									//var array<String> ParmList;
	UPROPERTY()						AAGP_Pawn* Player;											//var AGP.AGP_Pawn Player;
	UPROPERTY()						AHumanController* Controller;								//var AGP.HumanController Controller;
	UPROPERTY(EditAnywhere)			bool bDoGeneralInit;										//var() bool bDoGeneralInit;
	UPROPERTY(EditAnywhere)			bool bEventsDisabled;										//var() bool bEventsDisabled;
	UPROPERTY(EditAnywhere)			bool bShowClockAtStartup;									//var() bool bShowClockAtStartup;
	UPROPERTY(EditAnywhere)			bool bLockPlayerRotation;									//var() bool bLockPlayerRotation;
	UPROPERTY(EditAnywhere)			bool bLockPlayerMovement;									//var() bool bLockPlayerMovement;
	UPROPERTY(EditAnywhere)			bool bHack;													//var() bool bHack;
	UPROPERTY(EditAnywhere)			bool bEnableCheats;											//var() bool bEnableCheats;
	UPROPERTY(EditAnywhere)			bool bDebug;												//var() bool bDebug;
	UPROPERTY(EditAnywhere)			TArray<FLSAnim> LSAnims;									//var() array<LSAnim> LSAnims;
	UPROPERTY(EditAnywhere)			TArray<FGameSound> GameSounds;								//var() array<GameSound> GameSounds;

	UPROPERTY(EditAnywhere)													USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void LoadEditorIcon();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void EventLabTick(float DeltaTime);
	bool TargerManager_DispatchComplete(ATargetManager* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Trigger_Trigger(AAGP_Trigger* NotifyActor, AActor* Instigator);
	bool AGP_Trigger_UnTrigger(AAGP_Trigger* NotifyActor, AActor* Instigator);
	bool NoiseTrigger_Trigger(ANoiseTrigger* NotifyActor, AActor* Instigator, FString Parms);
	bool NoiseTrigger_UnTrigger(ANoiseTrigger* NotifyActor, AActor* Instigator, FString Parms);
	bool LookTrigger_Trigger(ALookTrigger* NotifyActor, AActor* Instigator, FString Parms);
	bool LookTrigger_UnTrigger(ALookTrigger* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_UseTrigger_Trigger(AGP_UseTrigger* NotifyActor, AActor* Instigator);
	bool AGP_UseTrigger_UnTrigger(AGP_UseTrigger* NotifyActor, AActor* Instigator);
	bool AGP_UseTrigger_UsedBy(AGP_UseTrigger* NotifyActor, AActor* Instigator);
	bool StaticMeshSwitcher_UsedBy(AStaticMeshSwitcher* NotifyActor, AActor* Instigator);
	bool DoorTrigger_UsedBy(ADoorTrigger* NotifyActor, AActor* Instigator);
	bool DoorTrigger_Trigger(ADoorTrigger* NotifyActor, AActor* Instigator);
	bool DoorTrigger_UnTrigger(ADoorTrigger* NotifyActor, AActor* Instigator);
	bool RiskVolume_Enter(ARiskVolume* NotifyActor, AActor* Instigator, FString Parms);
	bool RiskVolume_Exit(ARiskVolume* NotifyActor, AActor* Instigator, FString Parms);
	bool TriggerVolume_Enter(ATriggerVolume* NotifyActor, AActor* Instigator);
	bool TriggerVolume_Exit(ATriggerVolume* NotifyActor, AActor* Instigator);
	bool PhysicsVolume_Enter(APhysicsVolume* NotifyActor, AActor* Instigator);
	bool PhysicsVolume_Exit(APhysicsVolume* NotifyActor, AActor* Instigator);
	bool Volume_Enter(AVolume* NotifyActor, AActor* Instigator);
	bool Volume_Exit(AVolume* NotifyActor, AActor* Instigator);
	bool Volume_Damaged(AVolume* NotifyActor, AActor* Instigator);
	bool Pawn_Custom(APawn* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Pawn_Custom(AAGP_Pawn* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_NPC_Custom(AAGP_NPC* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Pawn_Died(AAGP_Pawn* NotifyActor, AController* Instigator);
	bool Pawn_Died(APawn* NotifyActor, AController* Instigator);
	bool AGP_Character_Died(AAGP_Character* NotifyActor, AController* Instigator);
	bool AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* Instigator);
	bool Pawn_Damaged(APawn* NotifyActor, AController* Instigator);
	bool AGP_Pawn_Damaged(AAGP_Pawn* NotifyActor, AController* Instigator);
	bool AGP_Character_Damaged(AAGP_Character* NotifyActor, AController* Instigator);
	bool AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* Instigator);
	bool NPC_MedStudent_Custom(ANPC_MedStudent* NotifyActor, AActor* Instigator, FString Parms);
	bool NPC_MedInstructor_Custom(ANPC_MedInstructor* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Vehicle_Entered(AAGP_Vehicle* Vehicle, AActor* Controller, FString Parms);
	bool AGP_Vehicle_Exited(AAGP_Vehicle* Vehicle, AActor* Controller, FString Parms);
	bool AGP_Vehicle_Died(AAGP_Vehicle* Vehicle, AActor* Controller, FString Parms);
	bool VehiclePosition_Entered(AVehiclePosition* Position, AActor* Controller, FString Parms);
	bool VehiclePosition_Exited(AVehiclePosition* Position, AActor* Controller, FString Parms);
	bool Vehicle_At(AAGP_Vehicle* Vehicle, AActor* Controller, FString NavigationTag);
	bool AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms);
	bool Controller_LSAnimEnd(AController* NotifyActor, AActor* Instigator, FString Parms);
	bool HumanController_Custom(AHumanController* NotifyActor, AActor* Instigator, FString Parms);
	bool StudentController_Custom(AStudentController* NotifyActor, AActor* Instigator, FString Parms);
	bool HttpGet_HttpGet(AHttpGet* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Objective_Trigger(AAGP_Objective* NotifyActor, AActor* Instigator);
	bool AGP_Objective_UnTrigger(AAGP_Objective* NotifyActor, AActor* Instigator);
	bool BaseProjectile_Explode(ABaseProjectile* Projectile, AActor* Instigator, FString Parms);
	bool ThrowWeaponPickup_GrenadeEffects(AThrowWeaponPickup* Grenade);
	void GrenadeExploded(AActor* Grenade, EEventType Event, AActor* Instigator, FString Parms);
	bool Trigger_Entered(ATrigger* NotifyActor, AActor* Instigator);
	void MortarDamagedTarget(AActor* agpmrdoTarget, AActor* Instigator);
	void MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* Instigator);
	bool Pickup_PickedUp(APickup* NotifyActor, AActor* Instigator, FString Parms);
	bool Pickup_AbortPickup(APickup* NotifyPickup, APawn* User);
	bool TargetMover_Damaged(ATargetMover* NotifyActor, AActor* Instigator, FString Parms);
	bool DecoMesh_Damaged(ADecoMesh* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Weapon_Trace_Hit(AAGP_Weapon* NotifyActor, AActor* HitActor, FString Parms);
	bool AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Weapon_Dropped(AAGP_Weapon* NotifyActor, APickup* WeaponPickup, FString Parms);
	bool AGP_Weapon_Custom(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Weapon_Jam(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	bool VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* Instigator, FString Parms);
	bool SceneManager_SceneEnd(ASceneManager* NotifyActor, AActor* Instigator, FString Parms);
	bool SceneManager_SceneStart(ASceneManager* NotifyActor, AActor* Instigator, FString Parms);
	bool SceneManager_PointReached(ASceneManager* NotifyActor, AActor* Instigator, FString Parms);
	bool InterpolationPoint_PointReached(AInterpolationPoint* NotifyActor, AActor* Instigator, FString Parms);
	//bool LevelInfo_FirstDraw(ALevelInfo* NotifyActor, AActor* Instigator, FString Parms);
	bool NPC_EEGuard_Custom(ANPC_EEGuard* NotifyActor, AActor* Instigator, FString Parms);
	bool MedExam_Custom(AMedExam* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms);
	bool MarksmanTarget_Damaged(AMarksmanTarget* NotifyActor, AActor* Instigator, FString Parms);
	bool DamageDetector_Damaged(ADamageDetector* NotifyActor, AActor* Instigator, FString Parms);
	bool Actor_Custom(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Timer_Timer(FName Name);
	bool Timer_Sound(FName Name);
	bool Timer_Anim(FName Name);
	bool Timer_LSAnim(FName Name);
	bool QueueAnim_Begin(FName Name);
	bool QueueAnim_End(FName Name);
	bool ELCheat(FString cheat);
	void PreBeginPlay();
	void PostBeginPlay();
	void MissionBegin();
	void MissionComplete();
	int32 GetCrypticID();
	void DoTransGameSpeed(float DeltaTime);
	void DoZoomFOV(float DeltaTime);
	void QueueAnim(FName Anim, AActor* A, bool bLoop, float Rate, float TweenTime, int32 Channel);
	void QueueAnimDelay(AActor* A, float Delay, int32 Channel);
	void ProcessAnimQueue();
	void PlayNextQueueAnim(AActor* A);
	void FlagLoopingQueueAnims(AActor* A);
	bool AnimQueueIsEmpty(AActor* A);
	void ProcessTimerEvents(float DeltaTime);
	void SetTimerEvent(FName Name, float Time, ETimerType TType, bool bRepeat, AActor* Actor);
	float QueryTimer(FName Name, ETimerType Type);
	void InitRefs();
	void LogUnHandledActorEvent(AActor* NotifyActor, EEventType Event, FString Parms);
	void LogUnHandledTimerEvent(FName Name, ETimerType Type);
	bool ActorNotify(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Timer(FName Name, ETimerType Type);
	bool Dispatcher_TargetManager(AActor* NotifyActor, EEventType ActorEvent, AActor* Instigator, FString Parms);
	bool Dispatcher_SceneManager(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_InterpolationPoint(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Hud(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_StaticMeshSwitcher(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_UseTrigger(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_NoiseTrigger(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_LookTrigger(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Trigger(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Objective(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_GrenadeExploded(AActor* Grenade, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_BaseProjectile(AActor* Projectile, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Trigger(AActor* NotifyActor, AActor* Instigator, FString Parms);
	bool Dispatcher_Pickup(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_TargetMover(AActor* NotifyActor, EEventType InEvent, AActor* Instigator, FString Parms);
	bool Dispatcher_DecoMesh(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Weapon(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_VehicleWeapon(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_DoorTrigger(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Character(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Pawn(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_Pawn(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_AGP_NPC(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_NPC_MedStudent(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_NPC_MedInstructor(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_NPC_EEGuard(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Vehicle(AActor* NotifyActor, EEventType InEvent, AActor* Controller, FString Parms);
	bool Dispatcher_AGP_VehicleFactory(AActor* NotifyActor, EEventType InEvent, AActor* NewVehicle, FString Parms);
	bool Dispatcher_MedExam(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_TriggerVolume(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_PhysicsVolume(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Volume(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_RiskVolume(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_Controller(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_HumanController(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_HttpGet(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_LevelInfo(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_StudentController(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_DamageDetector(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool Dispatcher_MarksmanTarget(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	int32 GetMachineID();
	void CaptureController();
	void CapturePlayer();
	FString GetClockTime();
	int32 GetClockSeconds();
	FString FormatTime(float Time, bool bHundredths, bool bWrapAt100);
	bool AnimIsQueued(FName Anim, AActor* A);
	void EnableEvents();
	void DisableEvents();
	void DisableCheats();
	void EventLabNotifyCheat();
	void RememberState(FName State, int32 Slot);
	FName RecallState(int32 Slot);
	void StartTimer(FName Name, float Time, bool bRepeat);
	bool HasTimerEventName(FName TimerName);
	bool HasTimerEventType(ETimerType Type);
	bool StopTimerByType(ETimerType Type);
	bool StopTimer(FName StopName, ETimerType Type);
	void PauseTimer(FName Name, ETimerType Type);
	void RestartTimer(FName Name, ETimerType Type);
	bool IsTimerPaused(FName Name, ETimerType Type);
	FName GetCurrentState();
	FName GetPreviousState();
	void ChangeState(FName State, FName Label);
	AActor* CaptureEvent(FName Tag, AActor* classTypeToFind);
	void ReCaptureEvent(AActor* Actor);
	void UnCaptureEvent(AActor* Actor);
	void CaptureEventGroup(FName Tag);
	void UnCaptureEventGroup(FName Tag);
	void TriggerActor(AActor* TargetActor);
	void TriggerGroup(FName Tag);
	USoundBase* GetGameSound(FName Name);
	float PlayGameSound(FName Name, AActor* Target, ESoundSlot Slot, float Volume, float Radius, float AdditionalDelay);
	//ALSAnim* GetLSAnim(FName Name);
	void PlayLSAnim(FName Name, AActor* Target, float Volume, float Radius, float Pitch, float AdditionalDelay);
	void PlayGameAnim(FName Anim, AActor* Target, float Rate, float TweenTime, int32 Channel, float AdditionalDelay);
	void ParseParms(FString Parms);
	FString Trim(FString tString);
	FString ReplaceCommandString(FString Text);
	FString GetCommandKey(FString cmdname);
	float FRandS();
	int32 RandS(int32 Num);
	void SetCrossHairColor(FName Color);
	void EnableCrosshair();
	void DisableCrosshair();
	int32 QueryClock();
	void ResumeClock();
	void StartClock(int32 Time, bool bCountDown);
	void StopClock();
	void ClearClock();
	void ResetClock();
	void EnableHUD();
	void DisableHUD();
	void GiveBinocs(APawn Target, uint8 ItemNum);
	AActor* GetActor(FName ActorTag);
	FVector GetActorLocation(FName ActorTag);
	FRotator GetActorRotation(FName ActorTag);
	void HidePlayer();
	void ShowPlayer();
	ASceneManager* StartScene(FName scenetag, FName StartLocation);
	void EndScene(FName scenetag);
	void ZoomFOV(float StartFOV, float EndFOV, float Time);
	void RestoreFOV();
	void SetFOV(float FOV);
	float GetFOV();
	float GetDefaultFOV();
	void TransitionGameSpeed(float Speed, float Time);
	void SetGameSpeed(float Speed);
	float GetGameSpeed();
	void PlayTip(FString text1, FString text2, float FadeTime);
	void DisplayMissionCompleteOther(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, FString OtherMenu);
	void DisplayMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene);
	void DisplayMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene);
	void PlayerLock(bool Movement, bool Rotation);
	void FadeOut(float FadeTime, bool bBlack);
	void FadeIn(float FadeTime, bool bBlack);
	void FadeOutBlack(float FadeTime);
	void FadeInBlack(float FadeTime);
	void RunConsoleCommand(FString Command);
	void GhostPlayer();
	void UnGhostPlayer();
	void CueCamera(AActor* Camera);
	void CuePlayer();
	void SetTargetManagerScoreKeeper(ATargetManager* TM);
	void TargetManagerPause(ATargetManager* TM, bool bPause);
	int32 GetTargetManagerTotalScore(ATargetManager* TM);
	void TargetManagerActive(ATargetManager* TM, bool bTMActive);
	void TargetManagerPracticeMode(ATargetManager* TM, bool bPracticeMode);
	void TargetManagerResetScores(ATargetManager* TM);
	void PlayerPressedFire();
	void EL_ES2ObjectFound(int32 Score);
};
