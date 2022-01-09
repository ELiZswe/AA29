// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUI.h"
#include "AA29/AA29.h"
#include "GUIUserKeyBinding.generated.h"

UCLASS()
class UGUIUserKeyBinding : public UGUI
{
	GENERATED_BODY()
public:
	UGUIUserKeyBinding();

	UPROPERTY()											TArray<FKeyInfo> KeyData;								//var array<KeyInfo> KeyData;
};
