// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AnimatedEditBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimatedEditBox : public UmoEditBox
{
	GENERATED_BODY()
public:
	UAnimatedEditBox();

	UPROPERTY(EditAnywhere)						float	increment;					//var() float increment;
	UPROPERTY(EditAnywhere)						bool	bUseValueForCaption;		//var() bool bUseValueForCaption;
	UPROPERTY(EditAnywhere)						bool	bUpdated;					//var() editconst noexport bool bUpdated;

	bool InternalOnPreDraw(UCanvas* C);
	void SetText(FString str);
	void InternalOnActivate();
	void InternalOnDeactivate();
	void ShowEditBox();
	void ShowLabel();
	void InternalOnChange(UGUIComponent* Sender);
};
