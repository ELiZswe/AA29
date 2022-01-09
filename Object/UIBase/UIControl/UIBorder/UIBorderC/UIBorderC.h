// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorder.h"
#include "UIBorderC.generated.h"

UCLASS()
class UUIBorderC : public UUIBorder
{
	GENERATED_BODY()
public:
	UUIBorderC();
	
	void Draw(UCanvas* Canvas);
};
