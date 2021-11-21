// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2Congratulations.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2Congratulations : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2Congratulations();

	void SetupPage(FString PageCaption, FString PageMessage, FString ContinueCaption, UMaterialInstance* CongratsPic);
};
