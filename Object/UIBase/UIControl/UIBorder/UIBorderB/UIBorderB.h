// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorder.h"
#include "UIBorderB.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBorderB : public UUIBorder
{
	GENERATED_BODY()
public:
	UUIBorderB();

	void ScaleControl(UCanvas* Canvas);
};
