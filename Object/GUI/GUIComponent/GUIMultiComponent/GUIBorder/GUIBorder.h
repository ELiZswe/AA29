// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIBorder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIBorder : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIBorder();
	UPROPERTY(EditAnywhere)				int32					TextIndent;						//var() int TextIndent;
	UPROPERTY(EditAnywhere)				EeTextAlign				Justification;					//var() GUI.eTextAlign Justification;
	UPROPERTY(EditAnywhere)				FString					Caption;						//var() localized string Caption;

	void SetCaption(FString NewCaption);
	FString GetCaption();

};
