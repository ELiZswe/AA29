// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2LoadingWeapons.generated.h"

class UTab_WeaponPref;

UCLASS()
class UUT2LoadingWeapons : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2LoadingWeapons();

	UPROPERTY()				UTab_WeaponPref*	WeaponTab;				//var Tab_WeaponPref WeaponTab;

	void Timer();
	void StartLoad(UTab_WeaponPref* Tab);
};
