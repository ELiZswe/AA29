// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Controller/AIController/aAIController.h"
#include "AA29/HUD/AGP_HUD/AGP_HUD.h"
#include "NPCBaseController.generated.h"

/**
 * 
 */
class AAGP_Weapon;
class ANPCPlayerStart;
class AMover;
class AThrowWeaponPickup;

UCLASS()
class AA29_API ANPCBaseController : public AaAIController
{
	GENERATED_BODY()
public:

		ANPCBaseController();

		UPROPERTY()										bool bReportableCivi;								//var bool bReportableCivi;
		UPROPERTY()										int32 iReportEventDistance;							//var int iReportEventDistance;
		UPROPERTY()										FName ReportedEvent;								//var name ReportedEvent;
		UPROPERTY()										int32 iNPCHealthLevelToTrigger;						//var int iNPCHealthLevelToTrigger;
		UPROPERTY()										bool bTriggerLinkedToObjective;						//var bool bTriggerLinkedToObjective;
		UPROPERTY()										FName TriggerToActivate;							//var name TriggerToActivate;
		UPROPERTY()										bool bEnableUseToActivateTrigger;					//var bool bEnableUseToActivateTrigger;
		UPROPERTY()										int32 iSquadID;										//var int iSquadID;
		UPROPERTY()										int32 iFireteamID;									//var int iFireteamID;
		UPROPERTY()										int32 iPlatoonID;									//var int iPlatoonID;
		UPROPERTY()										float fpMortarRequestSkill;							//var float fpMortarRequestSkill;
		UPROPERTY()										AAGP_Weapon* nameSecondaryWeapon;					//var class<AGP_Weapon> nameSecondaryWeapon;
		UPROPERTY()										AAGP_Weapon* namePrimaryWeapon;						//var class<AGP_Weapon> namePrimaryWeapon;
		UPROPERTY()										int32 iPrimaryWeaponReloads;						//var int iPrimaryWeaponReloads;
		UPROPERTY()										bool bHasBinoculars;								//var bool bHasBinoculars;
		UPROPERTY()										int32 i203Rounds;									//var int i203Rounds;
		UPROPERTY()										int32 iRPGCount;									//var int iRPGCount;
		UPROPERTY()										int32 iFlashGrenadeCount;							//var int iFlashGrenadeCount;
		UPROPERTY()										int32 iSmokeGrenadeCount;							//var int iSmokeGrenadeCount;
		UPROPERTY()										int32 iFragGrenadeCount;							//var int iFragGrenadeCount;
		//UPROPERTY()										TArray<ANPCPathNode*> apnPathNodesForPatrol;						//var array<NPCPathNode> apnPathNodesForPatrol;
		UPROPERTY()										FRotator rotInitialRotation;						//var Object.Rotator rotInitialRotation;
		UPROPERTY()										FVector vInitialLocation;							//var FVector vInitialLocation;
		UPROPERTY()										ETravelSpeed etsTravelSpeed;						//var ETravelSpeed etsTravelSpeed;
		UPROPERTY()										bool bStart;										//var bool bStart;
		UPROPERTY()										float fpFlashBangDuration;							//var float fpFlashBangDuration;
		UPROPERTY()										float fpFlashBangedAudioIntensity;					//var float fpFlashBangedAudioIntensity;
		UPROPERTY()										float fpFlashBangedVisualIntensity;					//var float fpFlashBangedVisualIntensity;
		UPROPERTY()										float fpFlashBangedEndTime;							//var float fpFlashBangedEndTime;
		UPROPERTY()										float fpRunAnimRate;								//var float fpRunAnimRate;
		UPROPERTY()										float fpTurnRate;									//var float fpTurnRate;
		UPROPERTY()										bool bAutoReversePath;								//var bool bAutoReversePath;
		UPROPERTY()										bool bAscendingNodeDirection;						//var bool bAscendingNodeDirection;
		UPROPERTY()										float fChanceOfStoppingAtNode;						//var float fChanceOfStoppingAtNode;
		UPROPERTY()										bool bScanWhenStopped;								//var bool bScanWhenStopped;
		UPROPERTY()										int32 iStartingPathNodeIndex;						//var int iStartingPathNodeIndex;
		UPROPERTY()										bool bLikesToCloseDoorBehindSelf;					//var bool bLikesToCloseDoorBehindSelf;
		UPROPERTY()										FString sRHExternalLinkCaption;						//var string sRHExternalLinkCaption;
		UPROPERTY()										FString sRHExternalLinkTitle;						//var string sRHExternalLinkTitle;
		UPROPERTY()										FString sRHModalText;								//var string sRHModalText;
		UPROPERTY()										float fpVolumeMovieToPlayOnUse;						//var float fpVolumeMovieToPlayOnUse;
		UPROPERTY()										FString sMOSMovieCaption;							//var string sMOSMovieCaption;
		UPROPERTY()										FString sMOSMovieTitleForPlayOnUse;					//var string sMOSMovieTitleForPlayOnUse;
		UPROPERTY()										FString sMovieCaption;								//var string sMovieCaption;
		UPROPERTY()										FString sMovieTitleForPlayOnUse;					//var string sMovieTitleForPlayOnUse;
		UPROPERTY()										int32 iMOSMovieToPlayOnUseFramerate;				//var int iMOSMovieToPlayOnUseFramerate;
		UPROPERTY()										int32 iMovieToPlayOnUseFramerate;					//var int iMovieToPlayOnUseFramerate;
		UPROPERTY()										USoundBase* sndAudioToPlayOnUse;					//var Sound sndAudioToPlayOnUse;
		UPROPERTY()										FString sMOSMovieToPlayOnUse;						//var string sMOSMovieToPlayOnUse;
		UPROPERTY()										FString sMovieToPlayOnUse;							//var string sMovieToPlayOnUse;
		UPROPERTY()										float fpNPCWeaponEffectiveRange;					//var float fpNPCWeaponEffectiveRange;
		UPROPERTY()										float fpTimeUntilNextSpeech;						//var float fpTimeUntilNextSpeech;
		UPROPERTY()										float fpVoicePitch;									//var float fpVoicePitch;
		UPROPERTY()										int32 iVoiceIndex;									//var int iVoiceIndex;
		UPROPERTY()										bool bMaleVoice;									//var bool bMaleVoice;
		UPROPERTY()										int32 iMinThreatLevel;								//var int iMinThreatLevel;
		UPROPERTY()										float fNPCLikesToCrouch;							//var float fNPCLikesToCrouch;
		UPROPERTY()										float fNPCExperience;								//var float fNPCExperience;
		UPROPERTY()										float fpNodeMentalStateRecoveryModifier;			//var float fpNodeMentalStateRecoveryModifier;
		UPROPERTY()										float fpNodeHearingRangeModifier;					//var float fpNodeHearingRangeModifier;
		UPROPERTY()										float fpNodeVisionConeAngle;						//var float fpNodeVisionConeAngle;
		UPROPERTY()										float fpNodeVisionRangeModifier;					//var float fpNodeVisionRangeModifier;
		UPROPERTY()										float fpNodeMentalStateChangeModifier;				//var float fpNodeMentalStateChangeModifier;
		UPROPERTY()										float fpNodeWeaponAccuracyBonus;					//var float fpNodeWeaponAccuracyBonus;
		UPROPERTY()										float fpNodeMentalStateBonus;						//var float fpNodeMentalStateBonus;
		UPROPERTY()										float fpMaxDistanceForGuardWandering;				//var float fpMaxDistanceForGuardWandering;
		UPROPERTY()										bool bCaptureToActiveLinkedObjective;				//var bool bCaptureToActiveLinkedObjective;
		UPROPERTY()										bool bUseFastSprint;								//var bool bUseFastSprint;
		UPROPERTY()										float fpNPCWeaponAccuracy;							//var float fpNPCWeaponAccuracy;
		UPROPERTY()										bool bNPCCanBeHealed;								//var bool bNPCCanBeHealed;
		UPROPERTY()										bool bNPCSpeaksEnglish;								//var bool bNPCSpeaksEnglish;
		UPROPERTY()										float fpNPCMaxVisualRange;							//var float fpNPCMaxVisualRange;
		UPROPERTY()										float fpNPCVisionConeAngle;							//var float fpNPCVisionConeAngle;
		UPROPERTY()										float fpNPCHearingRadius;							//var float fpNPCHearingRadius;
		UPROPERTY()										int32 iNPCTeamID;									//var int iNPCTeamID;
		UPROPERTY()										int32 iNPCLeadershipMentalStateRange;				//var int iNPCLeadershipMentalStateRange;
		UPROPERTY()										int32 iNPCLeadershipMentalStateBonus;				//var int iNPCLeadershipMentalStateBonus;
		UPROPERTY()										int32 iNPCInitialMentalState;						//var int iNPCInitialMentalState;
		UPROPERTY()										int32 iNPCTacticalOrders;							//var int iNPCTacticalOrders;
		UPROPERTY()										int32 iNPCCurrentOrders;							//var int iNPCCurrentOrders;
		UPROPERTY()										int32 iNPCPrimaryOrders;							//var int iNPCPrimaryOrders;
		UPROPERTY()										float fpDelayedInitialOrderExecutionTime;			//var float fpDelayedInitialOrderExecutionTime;
		UPROPERTY()										bool bUsePatrolStartTrigger;						//var bool bUsePatrolStartTrigger;
		UPROPERTY()										bool bUseResumePatrolStartTrigger;					//var bool bUseResumePatrolStartTrigger;
		UPROPERTY()										int32 iCurrentIdleAnimIndex;						//var int iCurrentIdleAnimIndex;
		UPROPERTY()										TArray<FNPCAnimSequenceSet> anpcassNPCIdleAnimations;						//var array<NPCAnimSequenceSet> anpcassNPCIdleAnimations;
		UPROPERTY()										FName nameAssaultLocationTag;						//var name nameAssaultLocationTag;
		UPROPERTY()										float fNPCLastTalkTime;								//var float fNPCLastTalkTime;
		UPROPERTY()										bool bUseAlternatePath;								//var bool bUseAlternatePath;
		UPROPERTY()										bool bOnLadder;										//var bool bOnLadder;
		UPROPERTY()										int32 iDefaultYawTurnRate;							//var int iDefaultYawTurnRate;
		UPROPERTY()										float fpTimeLastNervousnessChange;					//var float fpTimeLastNervousnessChange;
		UPROPERTY()										float fpConfidence;									//var float fpConfidence;
		UPROPERTY()										float fpTimeLastSeen;								//var float fpTimeLastSeen;
		UPROPERTY()										AActor* aLastActorSeen;								//var Actor aLastActorSeen;
		UPROPERTY()										float fpTimeLastHeard;								//var float fpTimeLastHeard;
		UPROPERTY()										AActor* aLastActorHeard;							//var Actor aLastActorHeard;
		UPROPERTY()										float fpTimeLastPawnHeard;							//var float fpTimeLastPawnHeard;
		UPROPERTY()										AThrowWeaponPickup* twpLastGrenadeHeard;			//var ThrowWeaponPickup twpLastGrenadeHeard;
		UPROPERTY()										float fpTimeGrenadeHeard;							//var float fpTimeGrenadeHeard;
		UPROPERTY()										float fpTimeLastBuzzed;								//var float fpTimeLastBuzzed;
		UPROPERTY()										float fpPawnHCLastSeen;								//var float fpPawnHCLastSeen;
		UPROPERTY()										APawn* pawnHCLastSeen;								//var Pawn pawnHCLastSeen;
		UPROPERTY()										AActor* actThreat;									//var Actor actThreat;
		UPROPERTY()										TArray<USoundBase*> sEnemyLeader;					//var Sound sEnemyLeader;
		UPROPERTY()										TArray<USoundBase*> sWhisperSquad;					//var Sound sWhisperSquad;
		UPROPERTY()										TArray<USoundBase*> sShoutSquad;					//var Sound sShoutSquad;
		UPROPERTY()										TArray<USoundBase*> sWhisperFriendly;				//var Sound sWhisperFriendly;
		UPROPERTY()										TArray<USoundBase*> sShoutFriendly;					//var Sound sShoutFriendly;
		UPROPERTY()										TArray<USoundBase*> sWhisperEnemy;					//var Sound sWhisperEnemy;
		UPROPERTY()										TArray<USoundBase*> sShoutEnemy;					//var Sound sShoutEnemy;
		UPROPERTY()										bool bDebugCombat;									//var bool bDebugCombat;
		UPROPERTY()										bool bDebugMode;									//var bool bDebugMode;
		UPROPERTY()										bool bDebugPath;									//var bool bDebugPath;
		UPROPERTY()										bool bDebugSenses;									//var bool bDebugSenses;
		UPROPERTY()										FGrenadeThreatContact agtcGrenadeThreats;						//var NPCBaseController.GrenadeThreatContact agtcGrenadeThreats;
		UPROPERTY()										FRecentContact arcContactHistory;						//var NPCBaseController.RecentContact arcContactHistory;
		UPROPERTY()										int32 iMaxContactAge;						//var int iMaxContactAge;
		UPROPERTY()										TArray<AActor*> actAttachments;				//var array<Actor> actAttachments;
		UPROPERTY()										TArray<FNPCAttachObject> aoAttachments;	//var array<NPCAttachObject> aoAttachments;
		UPROPERTY()										FName namePreConversationPackState;						//var name namePreConversationPackState;
		//UPROPERTY()										ANPCConversationPack* npccpCurrentConversation;						//var NPCConversationPack npccpCurrentConversation;
		//UPROPERTY()										TArray<ANPCConversationPack*> anpccpConversations;						//var array<NPCConversationPack> anpccpConversations;
		UPROPERTY()										float fpUnmanagedAudioMinDelayTime;					//var float fpUnmanagedAudioMinDelayTime;
		UPROPERTY()										float fpUnmanagedAudioTimeNextPlay;					//var float fpUnmanagedAudioTimeNextPlay;
		UPROPERTY()										float fpAudioTriggerRangeToPlayerUU;				//var float fpAudioTriggerRangeToPlayerUU;
		UPROPERTY()										bool bPlayOnPlayerSight;							//var bool bPlayOnPlayerSight;
		UPROPERTY()										TArray<FName> anameIdleRandomLipSyncAudio;			//var array<name> anameIdleRandomLipSyncAudio;
		UPROPERTY()										bool bUseLipSynch;									//var bool bUseLipSynch;
		UPROPERTY()										TArray<USoundBase*> asndIdleRandomAudio;			//var array<Sound> asndIdleRandomAudio;
		UPROPERTY()										float fpAudioFullVolumeRadius;						//var float fpAudioFullVolumeRadius;
		UPROPERTY()										AActor* actLastSoundPlayedEffect;					//var Actor actLastSoundPlayedEffect;
		UPROPERTY()										USoundBase* sndLastSoundPlayed;						//var Sound sndLastSoundPlayed;
		UPROPERTY()										bool bDummyPawnIgnoreAllEvents;						//var bool bDummyPawnIgnoreAllEvents;
		UPROPERTY()										bool bDummyPawnLoopIdleAnim;						//var bool bDummyPawnLoopIdleAnim;
		UPROPERTY()										int32 AnimChannel;									//var int AnimChannel;
		UPROPERTY()										float AnimTime;										//var float AnimTime;
		UPROPERTY()										float AnimRate;										//var float AnimRate;
		UPROPERTY()										float fpAnimFreezeTime;								//var float fpAnimFreezeTime;
		UPROPERTY()										FName AnimSequence;									//var name AnimSequence;
		UPROPERTY()										bool bStartAsDummyPawn;								//var bool bStartAsDummyPawn;
		UPROPERTY()										APawn* pawnBumped;									//var Pawn pawnBumped;
		UPROPERTY()										float fpItemOfInterestSearchRange;					//var float fpItemOfInterestSearchRange;
		UPROPERTY()										bool bSupportItemOfInterestSearch;					//var bool bSupportItemOfInterestSearch;
		UPROPERTY()										FString sNPCWaypointTag;							//var string sNPCWaypointTag;
		UPROPERTY()										FString sNPCName;									//var string sNPCName;
		UPROPERTY()										AActor* actorNextPathLocation;						//var Actor actorNextPathLocation;
		UPROPERTY()										int32 iBumpsThisPathnode;							//var int iBumpsThisPathnode;
		UPROPERTY()										FName namePawnName;									//var name namePawnName;
		UPROPERTY()										AMover* mLastDoorOpened;							//var Mover mLastDoorOpened;
		UPROPERTY()										FName nameWaitingAnimation;							//var name nameWaitingAnimation;
		UPROPERTY()										float fpTimeSinceLastSawIOI;						//var float fpTimeSinceLastSawIOI;
		//UPROPERTY()										ANPCItemOfInterest* npcioiLastFound;					//var NPCItemOfInterest npcioiLastFound;
		//UPROPERTY()										ALadderVolume* lvLadderEntry;							//var LadderVolume lvLadderEntry;
		//UPROPERTY()										APathNode* pnCurrentNodeLeadingToPathNode;				//var PathNode pnCurrentNodeLeadingToPathNode;
		//UPROPERTY()										APathNode* pnCurrentNodeOnPathToCover;					//var PathNode pnCurrentNodeOnPathToCover;
		//UPROPERTY()										ANPCPathNode* pnCoverNode;								//var NPCPathNode pnCoverNode;
		//UPROPERTY()										ANPCCoverPositionPathNode* npccpnLastCoverNodeUsed;		//var NPCCoverPositionPathNode npccpnLastCoverNodeUsed;
		//UPROPERTY()										ANPCPathNode* pnLastDebuggedNavPoint;					//var NPCPathNode pnLastDebuggedNavPoint;
		//UPROPERTY()										ANPCPathNode* pnCurrentPathNode;						//var NPCPathNode pnCurrentPathNode;
		//UPROPERTY()										ANPCPathNode* pnCurrentLocation;						//var NPCPathNode pnCurrentLocation;
		UPROPERTY()										int32 iCurrentPathNodeIndex	;								//var int iCurrentPathNodeIndex;
		UPROPERTY()										bool bTrainingCadre;										//var bool bTrainingCadre;
		//UPROPERTY()										ANPCAICombatController* npcaiccCombatController;		//var NPCAICombatController npcaiccCombatController;
		UPROPERTY()										ANPCPlayerStart* npcpsPlayerStart;							//var NPCPlayerStart npcpsPlayerStart;

		void WarnAboutToRunOverTeammate(AController* ctrlTeammate);
		void FastPreloadPathNodeList();
		void  FastGetPathnodeByTagString(FString sTag);
		void  FastFindCoverPathNode(bool bFindFarthestPointFromThreat);
		void  FastFindEscapePathNode(float fpMinDistance);
		void  LocateClosestNodeToLocation(FVector vLocation);
		void  NPCPrivateLog(FString sLogText);
		void  IsLocationInFront(FVector vLocation);
		void  GetAngleToLocation(FVector vLocation);
		void DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas Canvas, float &YL, float &YPos, FColor NewColor);
		//void GameHasEnded();
		bool IsNormal();
		bool IsConcerned();
		bool IsInPain();
		bool IsReckless();
		bool IsBrave();
		bool IsAgitated();
		bool IsSuppressed();
		bool IsInPanic();
		void DecrementConfidenceLevel();
		void IncrementConfidenceLevel();
		void SetConfidenceLevel(float fpNewConfidence);
		float GetConfidenceLevel();
		void ChangeOrders(int32 iNewOrders);
		void NPCChangeState(FName nmState, FName nmLabel);
		void NotifyTacticalOrderChange(int32 iNewTacOrders);
		void Reset();
		void InitializePawn();
		void Destroyed();
		//void Possess(APawn* aPawn);
		void DebugEnableVisionCone(bool bEnable);
		void Start();
		void DelayedInitialOrders();
		void Timer();
		void Run(bool bJog);
		void Walk();
		void Stand();
		void Jump();
		void Crouch();
		void Prone();
		void StopMovement();
		void TurnToActor(AActor* aActor, float Rate);
		void PlayTakingFireAudio();
		void NotifyBuzzedByBullet(AActor* aShooter);
		void AlertSquadMatesOfDamage(APawn* pawnInstigator);
		void MayFall();
		void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
		void NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone);
		void NotifyAnotherPawnDied(ANPCBaseController* npcpc);
		void NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged);
		void EnemyNotVisible();
		void NotifyEnemyNotVisible();
		void NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade);
		void HearBulletImpactNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
		void NotifyHeardBulletImpactNoise(AActor* NoiseMaker, FVector vImpactLocation);
		void HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
		void Touch(AActor* Other);
		bool UsedBy(APawn* User);
		void NotifyNPCTouchedByPlayer(APawn* pawnTouch);
		void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
		//void NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi);
		void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
		void NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard);
		void NotifyPlayerPawnInSight(APawn* pawnSeen);
		bool IsInMortalDanger();
		void NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade);
		void IncreaseNervousness(EMentalStateAdjustor msa);
		void AdjustStateByConfidenceLevel();
		void AdjustConfidenceByTime();
		void IncreaseConfidence(EMentalStateAdjustor msa);
		void CanPawnSeeMe(APawn* pawnSeen, bool bTestForAimingAtMe);
		void NotifyNPCSeen(APawn* Seen);
		void SeeMonster(APawn* Seen);
		void GetMaxVisionCone();
		void GetPawnViewRotation();
		float EvaluateEnemyThreat(APawn* pawnToEvaluate, bool bWatchingMe, float fpClosureRate);
		void PreloadPathNodeList();
		void GetPathnodeByTag(FName Tag);
		void GetPathnodeByTagString(FString sTag);
		void GetLadderPathnodeByName(FName nameOfNode);
		void GetNearbyLadderVolume(APathNode* pnToSearchNear);
		bool IsLocationDirectlyInFront(FVector vLocation);
		void DetermineNextPathNode();
		void FindNextPatrolPathNode();
		void DetermineNodeAfterCurrentNode();
		void CloseDoor(AMover* mDoor);
		//void OpenDoor(ANPCDoorEntryPathNode* npcdepn);
		void OpenDoorFromHere(FVector vLocation, AMover* moverBumpedDoor);
		//void FindDoor(ANPCDoorEntryPathNode* npcdepn);
		bool ShouldMoveToNextPathNode();
		void DebugDumpRoute();
		void DebugMarkNextNode(APathNode* pnNext);
		//void UpdatePathNodeBonuses(ANPCPathNode* npcpn);
		void PatrolStartTriggerEvent();
		void PatrolResumeTriggerEvent();
		void FallBackTriggerEvent();
		void DefendAreaTriggerEvent(FVector vLocToMoveTo);
		void EndClimbLadder();
		//void StartClimbingLadder(ALadderVolume* lvLadder);
		//void NotifyConversationPackStart(ANPCConversationPack* npccpNew);
		//void NotifyConversationPackEnded(ANPCConversationPack* npccpJustEnded);
		void GetLookRotationRate();
		void LookRight(float fpYaw);
		void LookLeft(float fpYaw);
		void NPCSay(int32 theSound, bool shout, bool forceplay);
		void FindCoverPathNode(bool bFindFarthestPointFromThreat);
		void FindEscapePathNode(float fpMinDistance);
		void ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir);
		void GetNearbyItemOfInterest();
		void SelectIdleRelatedAnimation(bool bForcePlaying);
		void PlayIdleRelatedAnimation(bool bForcePlaying, bool bLoopAnimation);
		void PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate);
		void PlayCustomSound(USoundBase* sndToPlay);
		bool NotifyHitWall(FVector HitNormal, AActor* Wall);
		void BackupAfterBump(APawn* pawnBumpedInto);
		bool NotifyBump(AActor* Other);
		void Startle(AActor* Feared);
		void InitPlayerReplicationInfo();
		void NotifyPhysicsVolumeChange(APhysicsVolume* NewVolume);
		void AdjustAround(APawn* Other, bool bNoAdjustOther);
		void NearWall(float walldist);
		void WantsToRun();
		void WantsToWalk();
		void WantsToCrawl();
		void WantsToCrouch();
		void ShouldRun();
		void ResumeTravelSpeed();
		void PawnDied(APawn* p);
		//void UnPossess();
		void AddHistoryContact(APawn* pawnSeen, bool bUpdateExistingContactOnly);
		void LostHistoryContact(APawn* pawnLost);
		void AgeHistoryContacts();
		void GetHighestThreatContactIndex(bool bRequireLOS);
		void AddGrenadeContact(AThrowWeaponPickup* twpGrenade);
		void SurrenderedThrowDownWeapon();
		void NPCLog(FString sLogText);
		void NPCPathLog(FString sLogText);


};
