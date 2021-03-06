// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIFont/GUIFont.h"
#include "UT2MidGameFont.generated.h"

UCLASS()
class UUT2MidGameFont : public UGUIFont
{
	GENERATED_BODY()
public:
	UUT2MidGameFont();

	UPROPERTY()					TArray<int32> FontScreenWidth;										//var int FontScreenWidth;

	UFont* GetMidGameFont(int32 XRes);
	UFont* GetFont(int32 XRes);
};
