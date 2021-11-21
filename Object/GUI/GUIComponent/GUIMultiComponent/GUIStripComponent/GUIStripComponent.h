// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIStripComponent.generated.h"

class UGUIHorzScrollButton;

UCLASS()
class AA29_API UGUIStripComponent : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIStripComponent();

	UPROPERTY(EditAnywhere)		UGUIHorzScrollButton*	LeftScroll;			//var() automated XInterface.GUIHorzScrollButton LeftScroll;
	UPROPERTY(EditAnywhere)		UGUIHorzScrollButton*	RightScroll;		//var() automated XInterface.GUIHorzScrollButton RightScroll;
	UPROPERTY(EditAnywhere)		float					ItemWidth;			//var() float ItemWidth;
	UPROPERTY(EditAnywhere)		float					ItemSpacing;		//var() float ItemSpacing;
	UPROPERTY(EditAnywhere)		TArray<UGUIComponent*>	Elements;			//var() editconstarray noexport TArray<GUIComponent> Elements;
	UPROPERTY()					int32					FirstVisibleIndex;	//var int32 FirstVisibleIndex;
	UPROPERTY()					int32					ItemsPerPage;		//var int32 ItemsPerPage;

	bool InternalOnPreDraw(UCanvas* Canvas);
	UGUIComponent* AppendComponent(UGUIComponent* NewComp, bool SkipRemap);
	UGUIComponent* InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap);
	bool RemoveComponent(UGUIComponent* Comp, bool SkipRemap);
	bool ScrollClick(UGUIComponent* Sender);
};
