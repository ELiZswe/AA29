// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIImage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIImage : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIImage();

	UPROPERTY()										int32 iScreenBottom;						//var int iScreenBottom;
	UPROPERTY()										int32 iScreenTop;							//var int iScreenTop;
	UPROPERTY()										int32 iScreenRight;							//var int iScreenRight;
	UPROPERTY()										int32 iScreenLeft;							//var int iScreenLeft;
	UPROPERTY(EditAnywhere)							float Y3;									//var() float Y3;
	UPROPERTY(EditAnywhere)							float X3;									//var() float X3;
	UPROPERTY(EditAnywhere)							int32 BorderOffsets;						//var() float BorderOffsets;
	UPROPERTY(EditAnywhere)							int32 DropShadowY;							//var() int DropShadowY;
	UPROPERTY(EditAnywhere)							int32 DropShadowX;							//var() int DropShadowX;
	UPROPERTY(EditAnywhere)							int32 Y2;									//var() int Y2;
	UPROPERTY(EditAnywhere)							int32 X2;									//var() int X2;
	UPROPERTY(EditAnywhere)							int32 Y1;									//var() int Y1;
	UPROPERTY(EditAnywhere)							int32 X1;									//var() int X1;
	UPROPERTY(EditAnywhere)							EImgAlign ImageAlign;						//var() GUI.eImgAlign ImageAlign;
	UPROPERTY(EditAnywhere)							EMenuRenderStyle ImageRenderStyle;			//var() GUI.EMenuRenderStyle ImageRenderStyle;
	UPROPERTY(EditAnywhere)							EImgStyle ImageStyle;						//var() GUI.eImgStyle ImageStyle;
	UPROPERTY(EditAnywhere)							FColor ImageColor;							//var() Object.Color ImageColor;
	UPROPERTY(EditAnywhere)							UMaterialInstance* DropShadow;				//var() Material DropShadow;
	UPROPERTY(EditAnywhere)							UMaterialInstance* Image;					//var() Material Image;

	FString AdditionalDebugString();
};
