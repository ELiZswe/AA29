// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "moFormatNumEdit.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UmoFormatNumEdit : public UmoNumericEdit
{
	GENERATED_BODY()
public:
	UmoFormatNumEdit();

	FString FormatValue(int32 NewValue);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString InternalFormatValue(int32 NewValue);

};
