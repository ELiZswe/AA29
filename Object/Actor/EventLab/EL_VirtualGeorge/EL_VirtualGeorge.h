// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_VirtualGeorge.generated.h"

class ANPC_VirtualGeorge;

UCLASS()
class AEL_VirtualGeorge : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_VirtualGeorge();

	UPROPERTY()						ANPC_VirtualGeorge* VG;											//var AGP_Characters.NPC_VirtualGeorge VG;

	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();

};
