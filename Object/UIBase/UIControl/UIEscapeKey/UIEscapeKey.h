// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIEscapeKey.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIEscapeKey : public UUIControl
{
	GENERATED_BODY()
public:
	UUIEscapeKey();


	UPROPERTY()										bool bKeyDown;					//var bool bKeyDown;

	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);

};
