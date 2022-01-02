// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "NPCBaseCivilianController.generated.h"

class USoundBase;
class APathNode;
class ANPCSpeechManager;

UCLASS()
class AA29_API ANPCBaseCivilianController : public ANPCBaseController
{
	GENERATED_BODY()
public:
	ANPCBaseCivilianController();

	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleWounded;										//var array<Sound> asoundAltDefFemaleWounded;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleFrightened;									//var array<Sound> asoundAltDefFemaleFrightened;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleAcknowledgeOrderNegative;						//var array<Sound> asoundAltDefFemaleAcknowledgeOrderNegative;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleAcknowledgeOrderPositive;						//var array<Sound> asoundAltDefFemaleAcknowledgeOrderPositive;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleWaitForNPC;									//var array<Sound> asoundAltDefFemaleWaitForNPC;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleCannotFollow;									//var array<Sound> asoundAltDefFemaleCannotFollow;
	UPROPERTY()					TArray<USoundBase*> asoundAltDefFemaleSeePlayer;									//var array<Sound> asoundAltDefFemaleSeePlayer;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleWounded;											//var array<Sound> asoundDefFemaleWounded;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleFrightened;										//var array<Sound> asoundDefFemaleFrightened;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleAcknowledgeOrderNegative;						//var array<Sound> asoundDefFemaleAcknowledgeOrderNegative;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleAcknowledgeOrderPositive;						//var array<Sound> asoundDefFemaleAcknowledgeOrderPositive;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleWaitForNPC;										//var array<Sound> asoundDefFemaleWaitForNPC;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleCannotFollow;									//var array<Sound> asoundDefFemaleCannotFollow;
	UPROPERTY()					TArray<USoundBase*> asoundDefFemaleSeePlayer;										//var array<Sound> asoundDefFemaleSeePlayer;
	UPROPERTY()					TArray<FName> anameAltDefFemaleWounded;												//var array<name> anameAltDefFemaleWounded;
	UPROPERTY()					TArray<FName> anameAltDefFemaleFrightened;											//var array<name> anameAltDefFemaleFrightened;
	UPROPERTY()					TArray<FName> anameAltDefFemaleAcknowledgeOrderNegative;							//var array<name> anameAltDefFemaleAcknowledgeOrderNegative;
	UPROPERTY()					TArray<FName> anameAltDefFemaleAcknowledgeOrderPositive;							//var array<name> anameAltDefFemaleAcknowledgeOrderPositive;
	UPROPERTY()					TArray<FName> anameAltDefFemaleWaitForNPC;											//var array<name> anameAltDefFemaleWaitForNPC;
	UPROPERTY()					TArray<FName> anameAltDefFemaleCannotFollow;										//var array<name> anameAltDefFemaleCannotFollow;
	UPROPERTY()					TArray<FName> anameAltDefFemaleSeePlayer;											//var array<name> anameAltDefFemaleSeePlayer;
	UPROPERTY()					TArray<FName> anameDefFemaleWounded;												//var array<name> anameDefFemaleWounded;
	UPROPERTY()					TArray<FName> anameDefFemaleFrightened;												//var array<name> anameDefFemaleFrightened;
	UPROPERTY()					TArray<FName> anameDefFemaleAcknowledgeOrderNegative;								//var array<name> anameDefFemaleAcknowledgeOrderNegative;
	UPROPERTY()					TArray<FName> anameDefFemaleAcknowledgeOrderPositive;								//var array<name> anameDefFemaleAcknowledgeOrderPositive;
	UPROPERTY()					TArray<FName> anameDefFemaleWaitForNPC;												//var array<name> anameDefFemaleWaitForNPC;
	UPROPERTY()					TArray<FName> anameDefFemaleCannotFollow;											//var array<name> anameDefFemaleCannotFollow;
	UPROPERTY()					TArray<FName> anameDefFemaleSeePlayer;												//var array<name> anameDefFemaleSeePlayer;
	UPROPERTY()					float fpNextWoundedAudioAllowedTime;												//var float fpNextWoundedAudioAllowedTime;
	UPROPERTY()					float fpNextAudioAllowedTime;														//var float fpNextAudioAllowedTime;
	UPROPERTY()					float fpMinTimeBetweenAudio;														//var float fpMinTimeBetweenAudio;
	UPROPERTY()					TArray<USoundBase*> asoundWounded;													//var array<Sound> asoundWounded;
	UPROPERTY()					TArray<USoundBase*> asoundFrightened;												//var array<Sound> asoundFrightened;
	UPROPERTY()					TArray<USoundBase*> asoundAcknowledgeOrderNegative;									//var array<Sound> asoundAcknowledgeOrderNegative;
	UPROPERTY()					TArray<USoundBase*> asoundAcknowledgeOrderPositive;									//var array<Sound> asoundAcknowledgeOrderPositive;
	UPROPERTY()					TArray<USoundBase*> asoundWaitForNPC;												//var array<Sound> asoundWaitForNPC;
	UPROPERTY()					TArray<USoundBase*> asoundCannotFollow;												//var array<Sound> asoundCannotFollow;
	UPROPERTY()					TArray<USoundBase*> asoundSeePlayer;												//var array<Sound> asoundSeePlayer;
	UPROPERTY()					TArray<FName> anameWounded;															//var array<name> anameWounded;
	UPROPERTY()					TArray<FName> anameFrightened;														//var array<name> anameFrightened;
	UPROPERTY()					TArray<FName> anameAcknowledgeOrderNegative;										//var array<name> anameAcknowledgeOrderNegative;
	UPROPERTY()					TArray<FName> anameAcknowledgeOrderPositive;										//var array<name> anameAcknowledgeOrderPositive;
	UPROPERTY()					TArray<FName> anameWaitForNPC;														//var array<name> anameWaitForNPC;
	UPROPERTY()					TArray<FName> anameCannotFollow;													//var array<name> anameCannotFollow;
	UPROPERTY()					TArray<FName> anameSeePlayer;														//var array<name> anameSeePlayer;
	UPROPERTY()					FName OrderAcknowledgement;															//var name OrderAcknowledgement;
	UPROPERTY()					FName SeePlayerEvent;																//var name SeePlayerEvent;
	UPROPERTY()					FName WoundedEvent;																	//var name WoundedEvent;
	UPROPERTY()					FName BuzzedEvent;																	//var name BuzzedEvent;
	UPROPERTY()					float fpAnimationDelayAfterHealing;													//var float fpAnimationDelayAfterHealing;
	UPROPERTY()					bool bStandAfterHealing;															//var bool bStandAfterHealing;
	UPROPERTY()					FName namePostHealedEvent;															//var name namePostHealedEvent;
	UPROPERTY()					TArray<USoundBase*> asndPreHealingAudio;											//var array<Sound> asndPreHealingAudio;
	UPROPERTY()					TArray<USoundBase*> asndPostHealingAudio;											//var array<Sound> asndPostHealingAudio;
	UPROPERTY()					FName namePostHealingAnimation;														//var name namePostHealingAnimation;
	UPROPERTY()					FName nameInitialInjuredAnimation;													//var name nameInitialInjuredAnimation;
	UPROPERTY()					bool bMustBeHealedToCommand;														//var bool bMustBeHealedToCommand;
	UPROPERTY()					bool bPreHealingAudioPlayed;														//var bool bPreHealingAudioPlayed;
	UPROPERTY()					float fpDistanceToTriggerPreHealingAudio;											//var float fpDistanceToTriggerPreHealingAudio;
	UPROPERTY()					bool bHealedByPlayer;																//var bool bHealedByPlayer;
	UPROPERTY()					APawn* pawnWhoHealed;																//var Pawn pawnWhoHealed;
	UPROPERTY()					bool bStartsInjured;																//var bool bStartsInjured;
	UPROPERTY()					int32 iFollowingTeam;																//var int iFollowingTeam;
	UPROPERTY()					float fpTimeEnteredCover;															//var float fpTimeEnteredCover;
	UPROPERTY()					float fpTimeOfLastFollowSpeech;														//var float fpTimeOfLastFollowSpeech;
	UPROPERTY()					APawn* pawnToFollow;																//var Pawn pawnToFollow;
	UPROPERTY()					float fpFollowDistance;																//var float fpFollowDistance;
	UPROPERTY()					APathNode* pnLastFollowingPathNode;													//var PathNode pnLastFollowingPathNode;
	UPROPERTY()					APathNode* pnFollowingPathNode;														//var PathNode pnFollowingPathNode;
	UPROPERTY()					bool bShouldFollowUser;																//var bool bShouldFollowUser;
	UPROPERTY()					ANPCSpeechManager* npcsmgrVoice;													//var NPCSpeechManager npcsmgrVoice;
	UPROPERTY()					bool bBusyPlayConversationPack;														//var bool bBusyPlayConversationPack;
	UPROPERTY()					TArray<USoundBase*> asCivilianFemaleInjured;										//var array<Sound> asCivilianFemaleInjured;
	UPROPERTY()					TArray<USoundBase*> asCivilianMaleInjured;											//var array<Sound> asCivilianMaleInjured;
	UPROPERTY()					TArray<USoundBase*> asCivilianWarnings;												//var array<Sound> asCivilianWarnings;
	UPROPERTY()					TArray<USoundBase*> asCivilianGroans;												//var array<Sound> asCivilianGroans;
	UPROPERTY()					TArray<USoundBase*> asCivilianComments;												//var array<Sound> asCivilianComments;
	UPROPERTY()					float fpTimeOfLastPawnSeen;															//var float fpTimeOfLastPawnSeen;
	UPROPERTY()					APawn* pawnLastSeen;																//var Pawn pawnLastSeen;
	UPROPERTY()					float fpTimeToTurnBackAround;														//var float fpTimeToTurnBackAround;
	UPROPERTY()					float fpEndTimeForViewingItemOfInterest;											//var float fpEndTimeForViewingItemOfInterest;
	UPROPERTY()					FString sDebugStatus;																//var string sDebugStatus;

	void DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* Canvas, float& YL, float& YPos, FColor NewColor);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void NPCChangeState(FName nmState, FName nmLabel);
	void BeginPlay();
	void InitializePawn();
	//void Possess(APawn* aPawn);
	void Start();
	bool DetermineConversationPackAvailable(APawn* pawnSeen);
	void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
	void NPCTriggerEvent(FName nmEvent, APawn* pawnInstigator);
	void NotifyBuzzedByBullet(AActor* aShooter);
	void NotifyPlayerPawnInSight(APawn* pawnSeen);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
	void NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi);
	void NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone);
	void Reset();
	float CivilianSay(int32 iSoundIndex);
	float CivilianWarning(int32 iSoundIndex);
	float CivilianGroan(int32 iSoundIndex);
	void NotifyAnotherPawnDied(ANPCBaseController* npcpc);
	void NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged);
	FString CommandCivilian(AHumanController* hcPlayer, FString sCmd);
	void AcknowledgeOrder();
	void NotifyPlayerHealedNPC(AAGP_Pawn* agpHealer);
	void PlayRandomLipSynch(TArray<FName> anameLipSynchs, bool bCutDelayTime);
	int32 getReportNPCDistance();
};
