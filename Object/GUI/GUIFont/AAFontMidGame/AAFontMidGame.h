// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIFont/GUIFont.h"
#include "AAFontMidGame.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAFontMidGame : public UGUIFont
{
	GENERATED_BODY()
public:
	UAAFontMidGame();

	UPROPERTY()					TArray<int32> FontScreenWidth;									//var int FontScreenWidth;

	void GetMidGameFont(int32 XRes);
	//AFont* UAAFontMidGame::GetFont(int32 XRes);

};
