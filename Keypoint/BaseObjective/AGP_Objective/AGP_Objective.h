// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/BaseObjective.h"
#include "AGP_Objective.generated.h"

class AHumanController;
class UaDamageType;
class ATeamInfo;
class AAGP_ObjectivePickup;

UCLASS()
class AA29_API AAGP_Objective : public ABaseObjective
{
	GENERATED_BODY()
public:

	AAGP_Objective(const FObjectInitializer& objectInitializer);

	
	UPROPERTY()																		bool spBeenAccountedFor;									//var bool spBeenAccountedFor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")					bool bDangerous;											//var(ESS) bool bDangerous;
	UPROPERTY()																		bool bESSObjectiveCompleteSoundPlayerOnly;					//var bool bESSObjectiveCompleteSoundPlayerOnly;
	UPROPERTY()																		USoundBase* anpcoaNPCResponse;								//var Sound anpcoaNPCResponse;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCReinforcements")	FName anpcoaNPCResponse;									//var(NPCReinforcements) array<NPCObjectiveResponse> anpcoaNPCResponse;
	UPROPERTY()																		FString OPFORPickupMsg;										//var string OPFORPickupMsg;
	UPROPERTY()																		FString USPickupMsg;										//var string USPickupMsg;
	UPROPERTY()																		TSubclassOf<class APawn> LinkedNPC;							//var Pawn LinkedNPC;
	UPROPERTY()																		TSubclassOf<class AActor> LocationProxy;					//var Actor LocationProxy;
	UPROPERTY()																		EObjectiveOnCompass _OriginalObjectiveOnCompass;			//var EObjectiveOnCompass _OriginalObjectiveOnCompass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompassVisibility")		EObjectiveOnCompass CompletedObjectiveOnCompass;			//var(CompassVisibility) EObjectiveOnCompass CompletedObjectiveOnCompass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompassVisibility")		bool bChangeObjectiveOnCompassOnCompletion;					//var(CompassVisibility) bool bChangeObjectiveOnCompassOnCompletion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompassVisibility")		FName VisibilityTag;										//var(CompassVisibility) name VisibilityTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompassVisibility")		FName VisibilityChildTag;									//var(CompassVisibility) name VisibilityChildTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CompassVisibility")		EObjectiveOnCompass ObjectiveOnCompass;						//var(CompassVisibility) EObjectiveOnCompass ObjectiveOnCompass;
	UPROPERTY()																		TArray<TSubclassOf<AAGP_Objective>> VisibilityChildren;		//var array<AGP_Objective> VisibilityChildren;
	UPROPERTY()																		float fpTimeUntilESSInvestigateRadioCompletes;				//var float fpTimeUntilESSInvestigateRadioCompletes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ESS")					FString sDiscoveredRadioMessage;							//var(ESS) string sDiscoveredRadioMessage;
	UPROPERTY()																		bool bPlayerRadioedObectiveInfo;							//var bool bPlayerRadioedObectiveInfo;
	UPROPERTY()																		TSubclassOf<class AController> ctrlrESSReporter;			//var Controller ctrlrESSReporter;
	UPROPERTY()																		TSubclassOf<class APawn> pawnMustBeUsedBy;					//var Pawn pawnMustBeUsedBy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomObjective")		FName RandomSelectedEvent;									//var(RandomObjective) name RandomSelectedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryObjective")	FName InventoryTag;											//var(InventoryObjective) name InventoryTag;
	UPROPERTY()																		TSubclassOf<AAGP_ObjectivePickup> InventoryPickup;			//var AGP_ObjectivePickup InventoryPickup;
	UPROPERTY()																		bool bInactive;												//var bool bInactive;
	UPROPERTY()																		TSubclassOf<class ASoldierClass> MustBeClass;				//var() class<SoldierClass> MustBeClass;
	UPROPERTY()																		uint8 iLastProgressPercent;									//var byte iLastProgressPercent;
	UPROPERTY()																		uint8 iLastPercent;											//var byte iLastPercent;
	UPROPERTY()																		float BlinkLatency;											//var float BlinkLatency;
	UPROPERTY()																		float LastRadarBlinkEndTime;								//var float LastRadarBlinkEndTime;
	UPROPERTY()																		float LastRadarBlinkStartTime;								//var float LastRadarBlinkStartTime;
	UPROPERTY()																		float RadarBlinkEndTime1;									//var float RadarBlinkEndTime1;
	UPROPERTY()																		float RadarBlinkStartTime1;									//var float RadarBlinkStartTime1;
	UPROPERTY()																		float RadarBlinkEndTime;									//var float RadarBlinkEndTime;
	UPROPERTY()																		float RadarBlinkStartTime;									//var float RadarBlinkStartTime;
	UPROPERTY()																		bool _bSquadTarget1;										//var bool _bSquadTarget1;
	UPROPERTY()																		bool _bSquadTarget;											//var bool _bSquadTarget;
	UPROPERTY()																		uint8 _OriginalAttackTeam;									//var byte _OriginalAttackTeam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			EGameDo DoWhenLinkKilled;									//var(LinkDamage) EGameDo DoWhenLinkKilled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			FName DoWhenLinkDamaged;									//var(LinkDamage) EGameDo DoWhenLinkDamaged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			bool bKickInstigator_Kill;									//var(LinkDamage) bool bKickInstigator_Kill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			bool bKickInstigator_Damage;								//var(LinkDamage) bool bKickInstigator_Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			float fROE_Damage_Multiplier;								//var(LinkDamage) float fROE_Damage_Multiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			int32 Kill_ROE_Penalty;										//var(LinkDamage) int Kill_ROE_Penalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			bool bUseLinkAccomplishes;									//var(LinkDamage) bool bUseLinkAccomplishes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			bool bCheckRequiredChildObjectives;							//var(SequenceObjective) bool bCheckRequiredChildObjectives;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")			FName EnabledEvent;											//var(SequenceObjective) name EnabledEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SequenceObjective")		EActivateOn ActivateOn;										//var(SequenceObjective) EActivateOn ActivateOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SequenceObjective")		TArray<FName> ParentTags;									//var(SequenceObjective) array<name> ParentTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SequenceObjective")		FName SequenceTag;											//var(SequenceObjective) name SequenceTag;
	UPROPERTY()																		TArray<TSubclassOf<AAGP_Objective>> ChildSequence;			//var array<AGP_Objective> ChildSequence;
	UPROPERTY()																		TArray<TSubclassOf<AAGP_Objective>> ParentSequence;			//var array<AGP_Objective> ParentSequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")			FName ObjectiveTag;											//var(CommLocation) name ObjectiveTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")				int32 Score_DefenderKill;									//var(Scoring) int Score_DefenderKill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")				int32 Score_AssaultSurvivor;								//var(Scoring) int Score_AssaultSurvivor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")				int32 Score_AssaultTeam;									//var(Scoring) int Score_AssaultTeam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")				int32 Score_AssaultHelper;									//var(Scoring) int Score_AssaultHelper;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")				int32 Score_AssaultPlayer;									//var(Scoring) int Score_AssaultPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* smTeam1Holds;									//var() StaticMesh smTeam1Holds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* smTeam0Holds;									//var() StaticMesh smTeam0Holds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* smUncaptured;									//var() StaticMesh smUncaptured;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										uint8 ProgressSoundInterval;								//var() byte ProgressSoundInterval;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										uint8 ProgressSoundStart;									//var() byte ProgressSoundStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										USoundBase* ProgressSound;									//var() Sound ProgressSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										USoundBase* AccomplishSound;								//var() Sound AccomplishSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString MBCDefenseDescription;								//var() localized string MBCDefenseDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString MBCAttackDescription;								//var() localized string MBCAttackDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString altDefenseDescription;								//var() localized string altDefenseDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString altAttackDescription;								//var() localized string altAttackDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString IFDefenseDescription;								//var() localized string IFDefenseDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString IFAttackDescription;								//var() localized string IFAttackDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString DefenseDescription;									//var() localized string DefenseDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString AttackDescription;									//var() localized string AttackDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString FailedDefenseMessage;								//var() localized string FailedDefenseMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString AccomplishMessage;									//var() localized string AccomplishMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										uint8 HUDLetter;											//var() byte HUDLetter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										uint8 AttackPriority;										//var() byte AttackPriority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										uint8 AttackTeam;											//var() byte AttackTeam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bLongRange;											//var() bool bLongRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bTakeTurns;											//var() bool bTakeTurns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bInstantWin;											//var() bool bInstantWin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bRequiredToWin;										//var() bool bRequiredToWin;
	UPROPERTY()																		uint8 AccomplishedBy;										//var byte AccomplishedBy;
	UPROPERTY()																		bool bFirstObjective;										//var bool bFirstObjective;
	UPROPERTY()																		bool bDisabled;												//var bool bDisabled;
	UPROPERTY()																		TSubclassOf<AAGP_Objective> nextObjective;					//var AGP_Objective nextObjective;


	virtual void BeginPlay() override;
	virtual void PostNetBeginPlay();
	virtual void PostBeginPlay();

	void BlinkObjectiveOnRadar(int32 iTeam, float BlinkDuration);
	void InitializeVolumesAndZones();
	void InitializeNPCObjective();
	void HandleGrenadeDamage();
	void InitializeVisibilityObjective();
	void InitializeInventoryObjective();
	void ResetLocationProxy();
	void SetLocationProxy(TSubclassOf<class AActor> new_proxy);
	void IsOnCompass(AController* ctrlRequesting);
	FVector GetCompassLocation();
	void InitializeSequenceObjective();
	void VerifyAllParentsFound();
	bool IsAParentOf(TSubclassOf<AAGP_Objective> AO);
	void AddSequenceParent(TSubclassOf<AAGP_Objective> AO);
	void AddSequenceChild(TSubclassOf<AAGP_Objective> AO);
	void NotifySequenceChildren();
	void ParentAccomplished(TSubclassOf<AAGP_Objective> AO);
	void NotifyLinkUsedBy(APawn* User);
	void NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints);
	void NotifyLinkDamage(APawn* instigatedBy, int32 Damage);
	void NotifyLinkKill(APawn* instigatedBy);
	void NotifyShortCut(APawn* instigatedBy, int32 ROE, bool Kick, EGameDo DoWhen);
	void SetTeamMesh();
	void PawnDied(APawn* p);
	void StopCounting();
	void NotifyParentInactive();
	void SetInactive(bool new_inactive);
	void SetDisabled(bool E);
	void SetSquadTarget(int32 iTeam, bool E);
	virtual bool IsEnabled();
	virtual bool IsInstantWin();
	bool IsSquadTarget(int32 iTeam);
	bool IsRequired();
	void CheckAllowedPickupTeam(APawn* User);
	void DetermineCarriedCompassVisbility(APawn* ObjCarrier, bool bDropped);
	void CarryObjectiveUsed(APawn* User);
	int32 GetPickupTeamOwner();
	bool IsAlternating();
	virtual float GetPercentComplete();
	void GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener);
	void GetDescriptionByTeam(uint8 listener);
	void GetDescriptionByPawn(APawn* listener);
	void GetDescriptionByController(AController* listener);
	void IsHigherPriorityThan(ABaseObjective* otherb);
	uint8 GetHUDPosition();
	bool AnyTeamCanAttack();
	bool CanTeamAttack(uint8 B);
	bool CanTeamInfoAttack(ATeamInfo* t);
	bool CanAccomplish(APawn* p);
	bool WasAccomplishedBy(uint8 some_team);
	void AccomplishObjective(APawn* _Instigator, AController* Killer);
	void PlayESSCompletionMessage(APlayerController* PC);
	void SendPercentage(APawn* whocares);
	void SideReset();
	void Reset();
	void grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController);
	void getReportDistance();
	void getObserveDistance();
	void getDangerDistance();
	void isDangerous();
	void isReportable();
	void MakeES2ObjectiveReportable();
	void getAcknowledgeVO();
	void getAcknowledgeText();
	void getFlagTag();
	void getFlagReference();
	void isUseable();
	void getDialogLength();
	void getLinkedArray();
	//void ActivateFromRadio(AHumanController* Instigator);
	void isOnRadar();
	void MakeESSObjectAppearOnRadar();
	void getReportEventName();
	void isDummyTrainingObject();
	void getBecomeActiveEvent();
	void isUseOnReport();

};
