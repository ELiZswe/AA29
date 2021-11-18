// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "TextDisplay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATextDisplay : public AAAGameplay
{
	GENERATED_BODY()
public:
	ATextDisplay();


	UPROPERTY()						TArray<UMaterialInstance*> LED;					//var array<Texture> LED;
	UPROPERTY()						TArray<UMaterialInstance*> Courier;				//var array<Texture> Courier;
	UPROPERTY(EditAnywhere)			TArray<FScoreItem> items;						//var() array<ScoreItem> items;
	UPROPERTY(EditAnywhere)			FVector DigitScale3D;							//var() FVector DigitScale3D;
	UPROPERTY(EditAnywhere)			float DigitScale;								//var() float DigitScale;
	UPROPERTY(EditAnywhere)			float DigitSpacing;								//var() float DigitSpacing;



	void PreBeginPlay();
	void SetValue(FName ItemName, FString str);
	void SetItem(int32 ItemIndex, FString str, EFontType Font);
	void SetCharacter(int32 ItemIndex, int32 Place, int32 Ascii, EFontType Font);
	int32 GetItemIndex(FName Name);
	void InitPosActors();
	void InitDigit(int32 Item, int32 Place);
	UMaterialInstance* GetCharTex(int32 Ascii, EFontType Font);
	void DestroyDigits(int32 Index);



};
