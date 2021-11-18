// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIPanel : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIPanel();

	UPROPERTY(EditAnywhere, Category = "Panel")			UMaterialInstance*					Background;						//var(Panel) Material Background;

	bool OnPostDraw(UCanvas* Canvas);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);

};
