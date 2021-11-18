// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIImageListDisplay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIImageListDisplay : public UUIControl
{
	GENERATED_BODY()
public:
	UUIImageListDisplay();

	UPROPERTY()										UMaterialInstance* _NotAvailable;				//var Texture _NotAvailable;
	UPROPERTY()										UMaterialInstance* _Completed;					//var Texture _Completed;
	UPROPERTY()										UMaterialInstance* _AlphaShade;					//var Texture _AlphaShade;
	UPROPERTY()										int32 _iCenterImage;							//var int _iCenterImage;
	UPROPERTY()										bool _bTour;									//var bool _bTour;
	UPROPERTY()										TArray<FImageInfo> _Images;						//var array<ImageInfo> _Images;

	void Destroyed();
	void ProcessParams();
	void Draw(UCanvas* Canvas);
	void CheckStatus(UCanvas* Canvas, int32 Index, int32 XPos, int32 YPos);
	void AddImage(FString sInfo, FString sTexture, FString sData0, FString sData1, FString sData2, FString sData3, int32 Status);
	void SetData(int32 Data);
	void NextImage();
	void PrevImage();
	void GetImageName();
	void GetIndex();
	void GetData(int32 Index);
	void IsAvailable();

};
