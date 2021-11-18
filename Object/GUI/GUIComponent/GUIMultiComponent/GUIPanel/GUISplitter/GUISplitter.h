// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "GUISplitter.generated.h"

class UGUIComponent;

UCLASS()
class AA29_API UGUISplitter : public UGUIPanel
{
	GENERATED_BODY()
public:
	UGUISplitter();

	UPROPERTY(EditAnywhere)								float						MaxPercentage;					//var() float MaxPercentage;
	UPROPERTY(EditAnywhere)								UGUIComponent*				Panels;							//var() GUIComponent Panels;
	UPROPERTY(EditAnywhere)								FString						DefaultPanels;					//var() string DefaultPanels;
	UPROPERTY(EditAnywhere)								float						SplitAreaSize;					//var() float SplitAreaSize;
	UPROPERTY(EditAnywhere)								bool						bDrawSplitter;					//var() bool bDrawSplitter;
	UPROPERTY(EditAnywhere)								bool						bFixedSplitter;					//var() bool bFixedSplitter;
	UPROPERTY(EditAnywhere)								float						SplitPosition;					//var() float SplitPosition;
	UPROPERTY(EditAnywhere)								EGUISplitterType			SplitOrientation;				//var() EGUISplitterType SplitOrientation;

	void OnReleaseSplitter(UGUIComponent* Sender, float NewPosition);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	UGUIComponent* AppendComponent(UGUIComponent* NewComp, bool SkipRemap);
	void SplitterUpdatePositions();
};
