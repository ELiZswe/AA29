// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "Packbot.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APackbot : public AAGP_TreadCraft
{
	GENERATED_BODY()
public:
	APackbot();

	UPROPERTY()								USoundBase* sndTreadSound;							//var Sound sndTreadSound;

	//void DisplayDebug(UCanvas* Canvas, float& YL, float& YPos);
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
