// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "T62A.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AT62A : public AAGP_TreadCraft
{
	GENERATED_BODY()
public:
	AT62A();

	UPROPERTY()								USoundBase* sndTreadSound;						//var Sound sndTreadSound;

	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void FindEntryVehicle(APawn* p);
	void IdleSoundTimer();
	void KDriverEnter(APawn* p);
	void KDriverLeave(bool bForceLeave);
	void Timer();
	bool TryToDrive(APawn* p);
	void UpdatePrecacheMaterials();

};
