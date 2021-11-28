// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "BMP1_APC.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABMP1_APC : public AAGP_TreadCraft
{
	GENERATED_BODY()
public:
	ABMP1_APC();

	UPROPERTY()								USoundBase* sndTreadSound;							//var Sound sndTreadSound;

	//void StaticPrecache(LevelInfo L);
	void FindEntryVehicle(APawn * p);
	bool TryToDrive(APawn* p);
	void InitializeDamageZones();
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
	void AttachDriver(APawn* p);
	void IdleSoundTimer();
	void KDriverEnter(APawn* p);
	void KDriverLeave(bool bForceLeave);
	void Timer();
	//void TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  InDamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);

};
