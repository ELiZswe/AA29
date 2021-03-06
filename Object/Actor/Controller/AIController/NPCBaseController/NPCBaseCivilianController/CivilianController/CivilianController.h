// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"
#include "CivilianController.generated.h"

class AAGP_Weapon;
class ANPCBaseController;
class APathNode;
class AThrowWeaponPickup;
UCLASS()
class ACivilianController : public ANPCBaseCivilianController
{
	GENERATED_BODY()
public:
	ACivilianController();

	UPROPERTY()			float					fElapsedTime;			//var float fElapsedTime;
	UPROPERTY()			int32					nWanderTargetID;		//var int32 nWanderTargetID;
	UPROPERTY()			TArray<ANPCPathNode*>	aWanderTargets;			//var TArray<NPCPathNode> aWanderTargets;
	UPROPERTY()			int32					nNumRoutePoints;		//var int32 nNumRoutePoints;
	UPROPERTY()			int32					nRouteNum;				//var int32 nRouteNum;
	UPROPERTY()			TArray<AActor*>			aDangerLocations;		//var TArray<Actor> aDangerLocations;
	UPROPERTY()			APathNode*				CoverNode;				//var PathNode CoverNode;

	//void Possess(APawn* aPawn);
	void Start();
	void StartUp();
	void FindWanderTargets();
	void NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard);
	void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
	void NotifyBuzzedByBullet(AActor* aShooter);
	void NotifyHeardBulletImpactNoise(AActor* NoiseMaker, FVector vImpactLocation);
	void NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade);
	void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
	void NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone);
	void NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade);
	void NotifyAnotherPawnDied(ANPCBaseController* npcpc);
	void NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged);
	void ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
	void HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
	bool CheckDistance(FVector Location, float dist);
	bool ValidateCover();
};
