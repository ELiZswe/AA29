// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIFont/GUIFont.h"
#include "UT2MidGameFont.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2MidGameFont : public UGUIFont
{
	GENERATED_BODY()
public:
	UUT2MidGameFont();

	UPROPERTY()					TArray<int32> FontScreenWidth;										//var int FontScreenWidth;


	void GetMidGameFont(int32 XRes);
	//AFont* GetFont(int32 XRes)
};
