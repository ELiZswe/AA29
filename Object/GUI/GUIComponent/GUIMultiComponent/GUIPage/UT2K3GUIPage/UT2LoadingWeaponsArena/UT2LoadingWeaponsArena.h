// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2LoadingWeaponsArena.generated.h"

class UUT2ArenaConfig;

UCLASS()
class AA29_API UUT2LoadingWeaponsArena : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2LoadingWeaponsArena();

	UPROPERTY()				UUT2ArenaConfig* Config;				//var UT2ArenaConfig Config;

	void Timer();
	void StartLoad(UUT2ArenaConfig* arena);
};
