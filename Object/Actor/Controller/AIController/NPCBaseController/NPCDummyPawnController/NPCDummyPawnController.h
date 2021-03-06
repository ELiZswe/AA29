// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "NPCDummyPawnController.generated.h"

class AAGP_Weapon;
class ANPCBaseController;
class ANPCItemOfInterest;
class AThrowWeaponPickup;
UCLASS()
class ANPCDummyPawnController : public ANPCBaseController
{
	GENERATED_BODY()
public:
	ANPCDummyPawnController();

	void PostBeginPlay();
	void SeePlayer(APawn* Seen);
	void NotifyBuzzedByBullet(AActor* aShooter);
	void HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
	bool NotifyBump(AActor* Other);
	bool NotifyHitWall(FVector HitNormal, AActor* Wall);
	void AdjustConfidenceByTime();
	void NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
	bool NearWall(float walldist);
	void ArrivedAtPathnode();
	void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
	void Touch(AActor* Other);
	void EnemyNotVisible();
	void NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade);
	void Timer();
	void NotifyAnotherPawnDied(ANPCBaseController* npcpc);
	void NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged);
	void NotifyNPCTouchedByPlayer(APawn* pawnTouch);
	void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
	void NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard);
	void NotifyPlayerPawnInSight(APawn* pawnSeen);
	void NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade);
	void NotifyNPCSeen(APawn* Seen);
	void SeeMonster(APawn* Seen);
	void Start();
	void NPCChangeState(FName nmState, FName nmLabel);
	bool UsedBy(APawn* User);
};
