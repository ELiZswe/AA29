// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "RifleRangeScreenplay.generated.h"

class ATargetManager;
class AAGP_HUD;

UCLASS()
class ARifleRangeScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ARifleRangeScreenplay();

	UPROPERTY()			ATargetManager*			_TargetManager;					//var AGP_Gameplay.TargetManager* _TargetManager;
	UPROPERTY()			AAGP_HUD*				_agp_hud;						//var AAGP_HUD* _agp_hud;
	
	void Init();
	void Draw(UCanvas* Canvas);
};
