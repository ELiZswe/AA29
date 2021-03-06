// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "BMP1_APC.generated.h"

class ALevelInfo;

class AVehicle;
UCLASS()
class ABMP1_APC : public AAGP_TreadCraft
{
	GENERATED_BODY()
public:
	ABMP1_APC();

	UPROPERTY()								USoundBase* sndTreadSound;							//var Sound sndTreadSound;

	void StaticPrecache(ALevelInfo* L);
	AVehicle* FindEntryVehicle(APawn * p);
	bool TryToDrive(APawn* p);
	void InitializeDamageZones();
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
	void AttachDriver(APawn* p);
	void IdleSoundTimer();
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	void Timer();
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  InDamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
};
