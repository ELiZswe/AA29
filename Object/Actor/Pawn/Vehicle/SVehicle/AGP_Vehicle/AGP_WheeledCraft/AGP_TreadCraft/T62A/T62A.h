// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/AGP_TreadCraft.h"
#include "T62A.generated.h"

class ALevelInfo;
class AVehicle;

UCLASS()
class AT62A : public AAGP_TreadCraft
{
	GENERATED_BODY()
public:
	AT62A();

	UPROPERTY()								USoundBase* sndTreadSound;						//var Sound sndTreadSound;

	void StaticPrecache(ALevelInfo* L);
	void UpdatePrecacheStaticMeshes();
	AVehicle* FindEntryVehicle(APawn* p);
	void IdleSoundTimer();
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	void Timer();
	bool TryToDrive(APawn* p);
	void UpdatePrecacheMaterials();

};
