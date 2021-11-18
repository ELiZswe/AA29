// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DrawOpBase.generated.h"

class AFont;

UCLASS()
class AA29_API UDrawOpBase : public UObject
{
	GENERATED_BODY()
public:
	UDrawOpBase();

	UPROPERTY()		float Top;					//var float Top;
	UPROPERTY()		float Lft;					//var float Lft;
	UPROPERTY()		float Height;				//var float Height;
	UPROPERTY()		float Width;				//var float Width;
	UPROPERTY()		uint8 RenderStyle;			//var uint8 RenderStyle;
	UPROPERTY()		uint8 Justification;		//var uint8 Justification;
	UPROPERTY()		FColor DrawColor;			//var Color DrawColor;

	void SetPos(float t, float L);
	void SetSize(float H, float W);
	void Draw(UCanvas* Canvas);
	AFont* GetFont(FString FontClassName, float ResX);
	AFont* GetGUIFont(FString FontClassName, float ResX);

};
