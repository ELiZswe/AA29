// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DrawOpBase/DrawOpBase.h"
#include "DrawOpText.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDrawOpText : public UDrawOpBase
{
	GENERATED_BODY()
public:
	UDrawOpText();

	UPROPERTY()		FString Text;					//var localized FString Text;
	UPROPERTY()		FString FontName;				//var FString FontName;
	UPROPERTY()		int32 MaxLines;					//var int32 MaxLines;
	UPROPERTY()		bool bWrapText;					//var bool bWrapText;
	UPROPERTY()		uint8 VertAlign;				//var uint8 VertAlign;

	void Draw(UCanvas* Canvas);


};
