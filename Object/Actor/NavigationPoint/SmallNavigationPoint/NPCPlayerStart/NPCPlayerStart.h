// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BillboardComponent.h"
#include "NPCPlayerStart.generated.h"

class NPCBaseController;

UCLASS()
class AA29_API ANPCPlayerStart : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ANPCPlayerStart();


	//UPROPERTY()																			ANPCAICombatController* npcaiccCombatController;			//var NPCAICombatController npcaiccCombatController;
	//UPROPERTY()																			ANPCPathNode* npcpnStartingPathNode;						//var NPCPathNode npcpnStartingPathNode;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")				TArray<ANPCConversationPack*> anpccpConversationList;		//var(NPCController) array<NPCConversationPack> anpccpConversationList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCombatDecisions")			float fpBOPMajorDisadvantageThreshold;						//var(NPCCombatDecisions) float fpBOPMajorDisadvantageThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCombatDecisions")			float fpBOPMinorDisadvantageThreshold;						//var(NPCCombatDecisions) float fpBOPMinorDisadvantageThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCombatDecisions")			float fpBOPMinorAdvantageThreshold;							//var(NPCCombatDecisions) float fpBOPMinorAdvantageThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCombatDecisions")			float fpBOPMajorAdvantageThreshold;							//var(NPCCombatDecisions) float fpBOPMajorAdvantageThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagProneProjectileScale;								//var(NPCPawnKarma) float RagProneProjectileScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagDeathUpKick;										//var(NPCPawnKarma) float RagDeathUpKick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagSpinScale;											//var(NPCPawnKarma) float RagSpinScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagShootStrength;										//var(NPCPawnKarma) float RagShootStrength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagDeathVel;											//var(NPCPawnKarma) float RagDeathVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagInvInertia;										//var(NPCPawnKarma) float RagInvInertia;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnKarma")					float RagdollLifeSpan;										//var(NPCPawnKarma) float RagdollLifeSpan;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				TArray<FNPCPSAttachObject> aoAttachments;					//var(NPCPawnOptions) array<NPCPSAttachObject> aoAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				float fpRunAnimRate;										//var(NPCPawnOptions) float fpRunAnimRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				FName PawnTag;												//var(NPCPawnOptions) name PawnTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				bool bUseFastSprint;										//var(NPCPawnOptions) bool bUseFastSprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				float fpPawnScale;											//var(NPCPawnOptions) float fpPawnScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				bool bSeesThroughDecomeshes;								//var(NPCPawnOptions) bool bSeesThroughDecomeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				FString RagdollOverride;									//var(NPCPawnOptions) string RagdollOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				USkeletalMesh* meshPawn;									//var(NPCPawnOptions) Mesh meshPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				bool bUserSetSkin;											//var(NPCPawnOptions) bool bUserSetSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				UMaterialInstance* setFace;									//var(NPCPawnOptions) Material setFace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				UMaterialInstance* setHands;								//var(NPCPawnOptions) Material setHands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				UMaterialInstance* setShirt;								//var(NPCPawnOptions) Material setShirt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				UMaterialInstance* setPants;								//var(NPCPawnOptions) Material setPants;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")				AAGP_Pawn* PawnSpawnClass;									//var(NPCPawnOptions) class<AGP_Pawn> PawnSpawnClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					float fpNPCWeaponEffectiveRange;							//var(NPCWeaponry) float fpNPCWeaponEffectiveRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					float fpMortarRequestSkill;									//var(NPCWeaponry) float fpMortarRequestSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					bool bNoDefaultWeapons;										//var(NPCWeaponry) bool bNoDefaultWeapons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					AAGP_Weapon* nameSecondaryWeapon;							//var(NPCWeaponry) class<AGP_Weapon> nameSecondaryWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					AAGP_Weapon* namePrimaryWeapon;								//var(NPCWeaponry) class<AGP_Weapon> namePrimaryWeapon;
	UPROPERTY()																				FString sSecondaryWeaponDefaultClass;						//var string sSecondaryWeaponDefaultClass;
	UPROPERTY()																				FString sPrimaryWeaponDefaultClass;							//var string sPrimaryWeaponDefaultClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iSecondaryWeaponReloads;								//var(NPCWeaponry) int iSecondaryWeaponReloads;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iPrimaryWeaponReloads;								//var(NPCWeaponry) int iPrimaryWeaponReloads;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					bool bHasBinoculars;										//var(NPCWeaponry) bool bHasBinoculars;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 i203Rounds;											//var(NPCWeaponry) int i203Rounds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iRPGCount;											//var(NPCWeaponry) int iRPGCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iFlashGrenadeCount;									//var(NPCWeaponry) int iFlashGrenadeCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iSmokeGrenadeCount;									//var(NPCWeaponry) int iSmokeGrenadeCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCWeaponry")					int32 iFragGrenadeCount;									//var(NPCWeaponry) int iFragGrenadeCount;
	UPROPERTY()																				bool bGroupSpawnFieldHolder;								//var bool bGroupSpawnFieldHolder;
	UPROPERTY()																				bool bSpawnable;											//var bool bSpawnable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					FName nRandomGroupTag;										//var(NPCNavigation) name nRandomGroupTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bRandomGroupSpawn;										//var(NPCNavigation) bool bRandomGroupSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					float fpMaxDistanceForGuardWandering;						//var(NPCNavigation) float fpMaxDistanceForGuardWandering;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					int32 iFireteamID;											//var(NPCNavigation) int iFireteamID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					int32 iSquadID;												//var(NPCNavigation) int iSquadID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					int32 iPlatoonID;											//var(NPCNavigation) int iPlatoonID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bVehiclePassenger;										//var(NPCNavigation) bool bVehiclePassenger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					int32 iRespawnsAllowed;										//var(NPCNavigation) int iRespawnsAllowed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bSpawnAsReserve;										//var(NPCNavigation) bool bSpawnAsReserve;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					float fpTurnRate;											//var(NPCNavigation) float fpTurnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bDebugPath;											//var(NPCNavigation) bool bDebugPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					float fpChanceOfSpawning;									//var(NPCNavigation) float fpChanceOfSpawning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bLikesToCloseDoorBehindSelf;							//var(NPCNavigation) bool bLikesToCloseDoorBehindSelf;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bAutoReversePath;										//var(NPCNavigation) bool bAutoReversePath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bAscendingNodeDirection;								//var(NPCNavigation) bool bAscendingNodeDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					float fChanceOfStoppingAtNode;								//var(NPCNavigation) float fChanceOfStoppingAtNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bScanWhenStopped;										//var(NPCNavigation) bool bScanWhenStopped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bUseRandomStartingNode;								//var(NPCNavigation) bool bUseRandomStartingNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bStartAndSpawnAtRandomNode;							//var(NPCNavigation) bool bStartAndSpawnAtRandomNode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					bool bMustSpawn;											//var(NPCNavigation) bool bMustSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					int32 iStartingPathNodeIndex;								//var(NPCNavigation) int iStartingPathNodeIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")					FString sNPCWaypointTag;									//var(NPCNavigation) string sNPCWaypointTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCOrders")						ENPCTacticalOrders enptoTacticalOrders;						//var(NPCOrders) ENPCTacticalOrders enptoTacticalOrders;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCOrders")						float fpDelayedInitialOrderExecutionTime;					//var(NPCOrders) float fpDelayedInitialOrderExecutionTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCOrders")						ENPCOrders enpcoPrimaryOrders;								//var(NPCOrders) ENPCOrders enpcoPrimaryOrders;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCOrders")						FName nameAssaultLocationTag;								//var(NPCOrders) name nameAssaultLocationTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					bool bReportableCivi;										//var(NPCTrigger) bool bReportableCivi;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					int32 iReportEventDistance;									//var(NPCTrigger) int iReportEventDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName ReportedEvent;										//var(NPCTrigger) name ReportedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName OrderAcknowledgement;									//var(NPCTrigger) name OrderAcknowledgement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName SeePlayerEvent;										//var(NPCTrigger) name SeePlayerEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName WoundedEvent;											//var(NPCTrigger) name WoundedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName BuzzedEvent;											//var(NPCTrigger) name BuzzedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName HealedEvent;											//var(NPCTrigger) name HealedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					bool bTriggerLinkedToObjective;								//var(NPCTrigger) bool bTriggerLinkedToObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					FName TriggerToActivate;									//var(NPCTrigger) name TriggerToActivate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					int32 iNPCHealthLevelToTrigger;								//var(NPCTrigger) int iNPCHealthLevelToTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCTrigger")					bool bEnableUseToActivateTrigger;							//var(NPCTrigger) bool bEnableUseToActivateTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")					bool bCaptureToActiveLinkedObjective;						//var(LinkDamage) bool bCaptureToActiveLinkedObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")					int32 KillHealth;											//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")					FName KillEvent;											//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")					FName DamageTag;											//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")					FName DamageEvent;											//var(LinkDamage) name DamageEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		bool bDummyPawnIgnoreAllEvents;								//var(NPCDummyPawnController) bool bDummyPawnIgnoreAllEvents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		bool bDummyPawnLoopIdleAnim;								//var(NPCDummyPawnController) bool bDummyPawnLoopIdleAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		int32 AnimChannel;											//var(NPCDummyPawnController) int AnimChannel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		float AnimTime;												//var(NPCDummyPawnController) float AnimTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		float AnimRate;												//var(NPCDummyPawnController) float AnimRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		float fpAnimFreezeTime;										//var(NPCDummyPawnController) float fpAnimFreezeTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		FName AnimSequence;											//var(NPCDummyPawnController) name AnimSequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		bool bStartAsDummyPawn;										//var(NPCDummyPawnController) bool bStartAsDummyPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		bool bUseResumePatrolStartTrigger;							//var(NPCDummyPawnController) bool bUseResumePatrolStartTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCDummyPawnController")		bool bUsePatrolStartTrigger;								//var(NPCDummyPawnController) bool bUsePatrolStartTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sRHExternalLinkCaption;								//var(NPCMovie) string sRHExternalLinkCaption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sRHExternalLinkTitle;								//var(NPCMovie) string sRHExternalLinkTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sRHModalText;										//var(NPCMovie) string sRHModalText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						float fpVolumeMovieToPlayOnUse;								//var(NPCMovie) float fpVolumeMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMOSMovieCaption;									//var(NPCMovie) string sMOSMovieCaption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMOSMovieTitleForPlayOnUse;							//var(NPCMovie) string sMOSMovieTitleForPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMovieCaption;										//var(NPCMovie) string sMovieCaption;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMovieTitleForPlayOnUse;							//var(NPCMovie) string sMovieTitleForPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						int32 iMOSMovieToPlayOnUseFramerate;						//var(NPCMovie) int iMOSMovieToPlayOnUseFramerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						int32 iMovieToPlayOnUseFramerate;							//var(NPCMovie) int iMovieToPlayOnUseFramerate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						USoundBase* sndAudioToPlayOnUse;							//var(NPCMovie) Sound sndAudioToPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMOSMovieToPlayOnUse;								//var(NPCMovie) string sMOSMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMovie")						FString sMovieToPlayOnUse;									//var(NPCMovie) string sMovieToPlayOnUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					FName ControllerTag;										//var(NPCController) name ControllerTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bDebugCombat;											//var(NPCController) bool bDebugCombat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bDebugSenses;											//var(NPCController) bool bDebugSenses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bDebugMode;											//var(NPCController) bool bDebugMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fpVoicePitch;											//var(NPCController) float fpVoicePitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iVoiceIndex;											//var(NPCController) int iVoiceIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bMaleVoice;											//var(NPCController) bool bMaleVoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iMinThreatLevel;										//var(NPCController) int iMinThreatLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fNPCLikesToCrouch;									//var(NPCController) float fNPCLikesToCrouch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fNPCExperience;										//var(NPCController) float fNPCExperience;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fpNPCWeaponAccuracy;									//var(NPCController) float fpNPCWeaponAccuracy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bNPCCanBeHealed;										//var(NPCController) bool bNPCCanBeHealed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bNPCSpeaksEnglish;										//var(NPCController) bool bNPCSpeaksEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					ENPCVisionAbility enpcvaVisionAbility;						//var(NPCController) ENPCVisionAbility enpcvaVisionAbility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCItemOfInterest")				float fpItemOfInterestSearchRange;							//var(NPCItemOfInterest) float fpItemOfInterestSearchRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCItemOfInterest")				bool bSupportItemOfInterestSearch;							//var(NPCItemOfInterest) bool bSupportItemOfInterestSearch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fpNPCMaxVisualRange;									//var(NPCController) float fpNPCMaxVisualRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fpNPCVisionConeAngle;									//var(NPCController) float fpNPCVisionConeAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bIgnoreFogDistance;									//var(NPCController) bool bIgnoreFogDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					float fpNPCHearingRadius;									//var(NPCController) float fpNPCHearingRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iNPCTeamID;											//var(NPCController) int iNPCTeamID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iNPCLeadershipMentalStateRange;						//var(NPCController) int iNPCLeadershipMentalStateRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iNPCLeadershipMentalStateBonus;						//var(NPCController) int iNPCLeadershipMentalStateBonus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					int32 iNPCInitialMentalState;								//var(NPCController) int iNPCInitialMentalState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					FName nameInitAnimSequence;									//var(NPCController) name nameInitAnimSequence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					bool bTrainingCadre;										//var(NPCController) bool bTrainingCadre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCController")					ANPCBaseController* ControllerClass;						//var(NPCController) class<NPCBaseController> ControllerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAnimation")					TArray<FNPCPSAnimSequenceSet> anpcassNPCIdleAnimations;		//var(NPCAnimation) array<NPCPSAnimSequenceSet> anpcassNPCIdleAnimations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				float fpUnmanagedAudioMinDelayTime;							//var(NPCUnmanagedAudio) float fpUnmanagedAudioMinDelayTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				float fpAudioTriggerRangeToPlayerUU;						//var(NPCUnmanagedAudio) float fpAudioTriggerRangeToPlayerUU;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				bool bPlayOnPlayerSight;									//var(NPCUnmanagedAudio) bool bPlayOnPlayerSight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				TArray<FName> anameIdleRandomLipSyncAudio;					//var(NPCUnmanagedAudio) array<name> anameIdleRandomLipSyncAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				bool bUseLipSynch;											//var(NPCUnmanagedAudio) bool bUseLipSynch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				TArray<USoundBase*> asndIdleRandomAudio;					//var(NPCUnmanagedAudio) array<Sound> asndIdleRandomAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				float fpAudioFullVolumeRadius;								//var(NPCUnmanagedAudio) float fpAudioFullVolumeRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCUnmanagedAudio")				bool bCamperNodesFound;										//var bool bCamperNodesFound;
	UPROPERTY()																				bool bCanDelaySpawn;										//var() bool bCanDelaySpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)												bool bDebugInit;											//var() bool bDebugInit;
	UPROPERTY()																				bool bEnabled;												//var bool bEnabled;



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
	void GetPathNodeCount(ANPCBaseController* npcbc);
	void GetRequestedPathNode(ANPCBaseController* npcbc, int32 iPathNodeIndex);
	void SetInitialPrimaryOrders(int32 iOrderIndex);



	


	UPROPERTY(VisibleAnywhere)		class USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)												FString Group;
};
