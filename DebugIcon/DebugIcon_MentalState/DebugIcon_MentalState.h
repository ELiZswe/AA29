// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DebugIcon/DebugIcon.h"
#include "AA29/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "DebugIcon_MentalState.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADebugIcon_MentalState : public ADebugIcon
{
	GENERATED_BODY()
public:
	ADebugIcon_MentalState();

	UPROPERTY()				UMaterialInstance* MentalState_Reckless_Texture;							//var Texture MentalState_Reckless_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Brave_Texture;								//var Texture MentalState_Brave_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Normal_Texture;								//var Texture MentalState_Normal_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Concerned_Texture;							//var Texture MentalState_Concerned_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Suppress_Texture;							//var Texture MentalState_Suppress_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Panic_Texture;								//var Texture MentalState_Panic_Texture;
	UPROPERTY()				UMaterialInstance* MentalState_Pain_Texture;								//var Texture MentalState_Pain_Texture;

	void UpdateMentalState(ANPCBaseController* CheckController);
};
