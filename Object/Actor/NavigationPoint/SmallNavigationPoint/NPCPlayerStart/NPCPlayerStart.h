// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BillboardComponent.h"
#include "NPCPlayerStart.generated.h"

class ANPCBaseController;
class ANPCAICombatController;
class ANPCPathNode;
class ANPCConversationPack;
class AAGP_Weapon;

class AAGP_Pawn;
class ANPCBaseSoldierController;
class APathNode;
UCLASS()
class ANPCPlayerStart : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ANPCPlayerStart();

	UPROPERTY()																				ANPCAICombatController* npcaiccCombatController;			//var NPCAICombatController npcaiccCombatController;
	UPROPERTY()																				ANPCPathNode* npcpnStartingPathNode;						//var NPCPathNode npcpnStartingPathNode;
	UPROPERTY(EditAnywhere, Category = "NPCController")					TArray<ANPCConversationPack*> anpccpConversationList;		//var(NPCController) array<NPCConversationPack> anpccpConversationList;
	UPROPERTY(EditAnywhere, Category = "NPCCombatDecisions")			float fpBOPMajorDisadvantageThreshold;						//var(NPCCombatDecisions) float fpBOPMajorDisadvantageThreshold;
	UPROPERTY(EditAnywhere, Category = "NPCCombatDecisions")			float fpBOPMinorDisadvantageThreshold;						//var(NPCCombatDecisions) float fpBOPMinorDisadvantageThreshold;
	UPROPERTY(EditAnywhere, Category = "NPCCombatDecisions")			float fpBOPMinorAdvantageThreshold;							//var(NPCCombatDecisions) float fpBOPMinorAdvantageThreshold;
	UPROPERTY(EditAnywhere, Category = "NPCCombatDecisions")			float fpBOPMajorAdvantageThreshold;							//var(NPCCombatDecisions) float fpBOPMajorAdvantageThreshold;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagProneProjectileScale;								//var(NPCPawnKarma) float RagProneProjectileScale;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagDeathUpKick;										//var(NPCPawnKarma) float RagDeathUpKick;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagSpinScale;											//var(NPCPawnKarma) float RagSpinScale;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagShootStrength;										//var(NPCPawnKarma) float RagShootStrength;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagDeathVel;											//var(NPCPawnKarma) float RagDeathVel;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagInvInertia;										//var(NPCPawnKarma) float RagInvInertia;
	UPROPERTY(EditAnywhere, Category = "NPCPawnKarma")					float RagdollLifeSpan;										//var(NPCPawnKarma) float RagdollLifeSpan;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				TArray<FNPCPSAttachObject> aoAttachments;					//var(NPCPawnOptions) array<NPCPSAttachObject> aoAttachments;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				float fpRunAnimRate;										//var(NPCPawnOptions) float fpRunAnimRate;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				FName PawnTag;												//var(NPCPawnOptions) name PawnTag;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				bool bUseFastSprint;										//var(NPCPawnOptions) bool bUseFastSprint;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				float fpPawnScale;											//var(NPCPawnOptions) float fpPawnScale;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				bool bSeesThroughDecomeshes;								//var(NPCPawnOptions) bool bSeesThroughDecomeshes;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				FString RagdollOverride;									//var(NPCPawnOptions) string RagdollOverride;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				USkeletalMesh* meshPawn;									//var(NPCPawnOptions) Mesh meshPawn;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				bool bUserSetSkin;											//var(NPCPawnOptions) bool bUserSetSkin;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				UMaterialInstance* setFace;									//var(NPCPawnOptions) Material setFace;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				UMaterialInstance* setHands;								//var(NPCPawnOptions) Material setHands;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				UMaterialInstance* setShirt;								//var(NPCPawnOptions) Material setShirt;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				UMaterialInstance* setPants;								//var(NPCPawnOptions) Material setPants;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")				AAGP_Pawn* PawnSpawnClass;									//var(NPCPawnOptions) class<AGP_Pawn> PawnSpawnClass;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					float fpNPCWeaponEffectiveRange;							//var(NPCWeaponry) float fpNPCWeaponEffectiveRange;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					float fpMortarRequestSkill;									//var(NPCWeaponry) float fpMortarRequestSkill;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					bool bNoDefaultWeapons;										//var(NPCWeaponry) bool bNoDefaultWeapons;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					AAGP_Weapon* nameSecondaryWeapon;							//var(NPCWeaponry) class<AGP_Weapon> nameSecondaryWeapon;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					AAGP_Weapon* namePrimaryWeapon;								//var(NPCWeaponry) class<AGP_Weapon> namePrimaryWeapon;
	UPROPERTY()																				FString sSecondaryWeaponDefaultClass;						//var string sSecondaryWeaponDefaultClass;
	UPROPERTY()																				FString sPrimaryWeaponDefaultClass;							//var string sPrimaryWeaponDefaultClass;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iSecondaryWeaponReloads;								//var(NPCWeaponry) int iSecondaryWeaponReloads;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iPrimaryWeaponReloads;								//var(NPCWeaponry) int iPrimaryWeaponReloads;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					bool bHasBinoculars;										//var(NPCWeaponry) bool bHasBinoculars;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 i203Rounds;											//var(NPCWeaponry) int i203Rounds;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iRPGCount;											//var(NPCWeaponry) int iRPGCount;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iFlashGrenadeCount;									//var(NPCWeaponry) int iFlashGrenadeCount;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iSmokeGrenadeCount;									//var(NPCWeaponry) int iSmokeGrenadeCount;
	UPROPERTY(EditAnywhere, Category = "NPCWeaponry")					int32 iFragGrenadeCount;									//var(NPCWeaponry) int iFragGrenadeCount;
	UPROPERTY()																				bool bGroupSpawnFieldHolder;								//var bool bGroupSpawnFieldHolder;
	UPROPERTY()																				bool bSpawnable;											//var bool bSpawnable;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					FName nRandomGroupTag;										//var(NPCNavigation) name nRandomGroupTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bRandomGroupSpawn;										//var(NPCNavigation) bool bRandomGroupSpawn;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					float fpMaxDistanceForGuardWandering;						//var(NPCNavigation) float fpMaxDistanceForGuardWandering;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					int32 iFireteamID;											//var(NPCNavigation) int iFireteamID;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					int32 iSquadID;												//var(NPCNavigation) int iSquadID;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					int32 iPlatoonID;											//var(NPCNavigation) int iPlatoonID;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bVehiclePassenger;										//var(NPCNavigation) bool bVehiclePassenger;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					int32 iRespawnsAllowed;										//var(NPCNavigation) int iRespawnsAllowed;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bSpawnAsReserve;										//var(NPCNavigation) bool bSpawnAsReserve;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					float fpTurnRate;											//var(NPCNavigation) float fpTurnRate;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bDebugPath;											//var(NPCNavigation) bool bDebugPath;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					float fpChanceOfSpawning;									//var(NPCNavigation) float fpChanceOfSpawning;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bLikesToCloseDoorBehindSelf;							//var(NPCNavigation) bool bLikesToCloseDoorBehindSelf;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bAutoReversePath;										//var(NPCNavigation) bool bAutoReversePath;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bAscendingNodeDirection;								//var(NPCNavigation) bool bAscendingNodeDirection;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					float fChanceOfStoppingAtNode;								//var(NPCNavigation) float fChanceOfStoppingAtNode;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bScanWhenStopped;										//var(NPCNavigation) bool bScanWhenStopped;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bUseRandomStartingNode;								//var(NPCNavigation) bool bUseRandomStartingNode;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bStartAndSpawnAtRandomNode;							//var(NPCNavigation) bool bStartAndSpawnAtRandomNode;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					bool bMustSpawn;											//var(NPCNavigation) bool bMustSpawn;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					int32 iStartingPathNodeIndex;								//var(NPCNavigation) int iStartingPathNodeIndex;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")					FString sNPCWaypointTag;									//var(NPCNavigation) string sNPCWaypointTag;
	UPROPERTY(EditAnywhere, Category = "NPCOrders")						ENPCTacticalOrders enptoTacticalOrders;						//var(NPCOrders) ENPCTacticalOrders enptoTacticalOrders;
	UPROPERTY(EditAnywhere, Category = "NPCOrders")						float fpDelayedInitialOrderExecutionTime;					//var(NPCOrders) float fpDelayedInitialOrderExecutionTime;
	UPROPERTY(EditAnywhere, Category = "NPCOrders")						ENPCOrders enpcoPrimaryOrders;								//var(NPCOrders) ENPCOrders enpcoPrimaryOrders;
	UPROPERTY(EditAnywhere, Category = "NPCOrders")						FName nameAssaultLocationTag;								//var(NPCOrders) name nameAssaultLocationTag;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					bool bReportableCivi;										//var(NPCTrigger) bool bReportableCivi;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					int32 iReportEventDistance;									//var(NPCTrigger) int iReportEventDistance;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName ReportedEvent;										//var(NPCTrigger) name ReportedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName OrderAcknowledgement;									//var(NPCTrigger) name OrderAcknowledgement;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName SeePlayerEvent;										//var(NPCTrigger) name SeePlayerEvent;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName WoundedEvent;											//var(NPCTrigger) name WoundedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName BuzzedEvent;											//var(NPCTrigger) name BuzzedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName HealedEvent;											//var(NPCTrigger) name HealedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					bool bTriggerLinkedToObjective;								//var(NPCTrigger) bool bTriggerLinkedToObjective;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					FName TriggerToActivate;									//var(NPCTrigger) name TriggerToActivate;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					int32 iNPCHealthLevelToTrigger;								//var(NPCTrigger) int iNPCHealthLevelToTrigger;
	UPROPERTY(EditAnywhere, Category = "NPCTrigger")					bool bEnableUseToActivateTrigger;							//var(NPCTrigger) bool bEnableUseToActivateTrigger;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")					bool bCaptureToActiveLinkedObjective;						//var(LinkDamage) bool bCaptureToActiveLinkedObjective;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")					int32 KillHealth;											//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")					FName KillEvent;											//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")					FName DamageTag;											//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")					FName DamageEvent;											//var(LinkDamage) name DamageEvent;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		bool bDummyPawnIgnoreAllEvents;								//var(NPCDummyPawnController) bool bDummyPawnIgnoreAllEvents;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		bool bDummyPawnLoopIdleAnim;								//var(NPCDummyPawnController) bool bDummyPawnLoopIdleAnim;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		int32 AnimChannel;											//var(NPCDummyPawnController) int AnimChannel;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		float AnimTime;												//var(NPCDummyPawnController) float AnimTime;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		float AnimRate;												//var(NPCDummyPawnController) float AnimRate;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		float fpAnimFreezeTime;										//var(NPCDummyPawnController) float fpAnimFreezeTime;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		FName AnimSequence;											//var(NPCDummyPawnController) name AnimSequence;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		bool bStartAsDummyPawn;										//var(NPCDummyPawnController) bool bStartAsDummyPawn;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		bool bUseResumePatrolStartTrigger;							//var(NPCDummyPawnController) bool bUseResumePatrolStartTrigger;
	UPROPERTY(EditAnywhere, Category = "NPCDummyPawnController")		bool bUsePatrolStartTrigger;								//var(NPCDummyPawnController) bool bUsePatrolStartTrigger;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sRHExternalLinkCaption;								//var(NPCMovie) string sRHExternalLinkCaption;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sRHExternalLinkTitle;								//var(NPCMovie) string sRHExternalLinkTitle;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sRHModalText;										//var(NPCMovie) string sRHModalText;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						float fpVolumeMovieToPlayOnUse;								//var(NPCMovie) float fpVolumeMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMOSMovieCaption;									//var(NPCMovie) string sMOSMovieCaption;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMOSMovieTitleForPlayOnUse;							//var(NPCMovie) string sMOSMovieTitleForPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMovieCaption;										//var(NPCMovie) string sMovieCaption;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMovieTitleForPlayOnUse;							//var(NPCMovie) string sMovieTitleForPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						int32 iMOSMovieToPlayOnUseFramerate;						//var(NPCMovie) int iMOSMovieToPlayOnUseFramerate;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						int32 iMovieToPlayOnUseFramerate;							//var(NPCMovie) int iMovieToPlayOnUseFramerate;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						USoundBase* sndAudioToPlayOnUse;							//var(NPCMovie) Sound sndAudioToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMOSMovieToPlayOnUse;								//var(NPCMovie) string sMOSMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCMovie")						FString sMovieToPlayOnUse;									//var(NPCMovie) string sMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, Category = "NPCController")					FName ControllerTag;										//var(NPCController) name ControllerTag;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bDebugCombat;											//var(NPCController) bool bDebugCombat;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bDebugSenses;											//var(NPCController) bool bDebugSenses;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bDebugMode;											//var(NPCController) bool bDebugMode;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fpVoicePitch;											//var(NPCController) float fpVoicePitch;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iVoiceIndex;											//var(NPCController) int iVoiceIndex;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bMaleVoice;											//var(NPCController) bool bMaleVoice;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iMinThreatLevel;										//var(NPCController) int iMinThreatLevel;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fNPCLikesToCrouch;									//var(NPCController) float fNPCLikesToCrouch;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fNPCExperience;										//var(NPCController) float fNPCExperience;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fpNPCWeaponAccuracy;									//var(NPCController) float fpNPCWeaponAccuracy;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bNPCCanBeHealed;										//var(NPCController) bool bNPCCanBeHealed;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bNPCSpeaksEnglish;										//var(NPCController) bool bNPCSpeaksEnglish;
	UPROPERTY(EditAnywhere, Category = "NPCController")					ENPCVisionAbility enpcvaVisionAbility;						//var(NPCController) ENPCVisionAbility enpcvaVisionAbility;
	UPROPERTY(EditAnywhere, Category = "NPCItemOfInterest")				float fpItemOfInterestSearchRange;							//var(NPCItemOfInterest) float fpItemOfInterestSearchRange;
	UPROPERTY(EditAnywhere, Category = "NPCItemOfInterest")				bool bSupportItemOfInterestSearch;							//var(NPCItemOfInterest) bool bSupportItemOfInterestSearch;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fpNPCMaxVisualRange;									//var(NPCController) float fpNPCMaxVisualRange;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fpNPCVisionConeAngle;									//var(NPCController) float fpNPCVisionConeAngle;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bIgnoreFogDistance;									//var(NPCController) bool bIgnoreFogDistance;
	UPROPERTY(EditAnywhere, Category = "NPCController")					float fpNPCHearingRadius;									//var(NPCController) float fpNPCHearingRadius;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iNPCTeamID;											//var(NPCController) int iNPCTeamID;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iNPCLeadershipMentalStateRange;						//var(NPCController) int iNPCLeadershipMentalStateRange;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iNPCLeadershipMentalStateBonus;						//var(NPCController) int iNPCLeadershipMentalStateBonus;
	UPROPERTY(EditAnywhere, Category = "NPCController")					int32 iNPCInitialMentalState;								//var(NPCController) int iNPCInitialMentalState;
	UPROPERTY(EditAnywhere, Category = "NPCController")					FName nameInitAnimSequence;									//var(NPCController) name nameInitAnimSequence;
	UPROPERTY(EditAnywhere, Category = "NPCController")					bool bTrainingCadre;										//var(NPCController) bool bTrainingCadre;
	UPROPERTY(EditAnywhere, Category = "NPCController")					ANPCBaseController* ControllerClass;						//var(NPCController) class<NPCBaseController> ControllerClass;
	UPROPERTY(EditAnywhere, Category = "NPCAnimation")					TArray<FNPCPSAnimSequenceSet> anpcassNPCIdleAnimations;		//var(NPCAnimation) array<NPCPSAnimSequenceSet> anpcassNPCIdleAnimations;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				float fpUnmanagedAudioMinDelayTime;							//var(NPCUnmanagedAudio) float fpUnmanagedAudioMinDelayTime;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				float fpAudioTriggerRangeToPlayerUU;						//var(NPCUnmanagedAudio) float fpAudioTriggerRangeToPlayerUU;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				bool bPlayOnPlayerSight;									//var(NPCUnmanagedAudio) bool bPlayOnPlayerSight;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				TArray<FName> anameIdleRandomLipSyncAudio;					//var(NPCUnmanagedAudio) array<name> anameIdleRandomLipSyncAudio;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				bool bUseLipSynch;											//var(NPCUnmanagedAudio) bool bUseLipSynch;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				TArray<USoundBase*> asndIdleRandomAudio;					//var(NPCUnmanagedAudio) array<Sound> asndIdleRandomAudio;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				float fpAudioFullVolumeRadius;								//var(NPCUnmanagedAudio) float fpAudioFullVolumeRadius;
	UPROPERTY(EditAnywhere, Category = "NPCUnmanagedAudio")				bool bCamperNodesFound;										//var bool bCamperNodesFound;
	UPROPERTY()																				bool bCanDelaySpawn;										//var() bool bCanDelaySpawn;
	UPROPERTY(EditAnywhere)												bool bDebugInit;											//var() bool bDebugInit;
	UPROPERTY()																				bool bEnabled;												//var bool bEnabled;

	UPROPERTY(VisibleAnywhere)		class USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere)												FString Group;

	void BeginPlay();
	void DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker);
	void Reset();
	void PostBeginPlay();
	bool ShouldUseStartSpot();
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	ANPCBaseController* CreateNPC(bool bOverrideLocation, FVector vOverrideLocation, FRotator rotOverride, bool bDebugNow);
	void FindAICC();
	void RegisterControllerWithAICC(ANPCBaseSoldierController* npcbc, ANPCPathNode* npcpnStart);
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
	AAGP_Pawn* GetPawnSpawnClass();
	int32 GetPathNodeCount(ANPCBaseController* npcbc);
	APathNode* GetRequestedPathNode(ANPCBaseController* npcbc, int32 iPathNodeIndex);
	void SetInitialPrimaryOrders(int32 iOrderIndex);
};
