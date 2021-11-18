// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIScrollbar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIScrollbar : public UUIControl
{
	GENERATED_BODY()
public:
	UUIScrollbar();

	UPROPERTY()										int32 _iMouseDragOffset;					//var int _iMouseDragOffset;
	UPROPERTY()										UMaterialInstance* _BackTex;				//var Texture _BackTex;
	UPROPERTY()										UMaterialInstance* _ThumbTex;				//var Texture _ThumbTex;
	UPROPERTY()										uint8 _iScaledTrackSizeY;					//var int _iScaledTrackSizeY;
	UPROPERTY()										int32 _iScaledTrackSizeX;					//var int _iScaledTrackSizeX;
	UPROPERTY()										int32 _iTrackSizeY;							//var int _iTrackSizeY;
	UPROPERTY()										int32 _iTrackSizeX;							//var int _iTrackSizeX;
	UPROPERTY()										int32 _iScaledStartDragThumbPos;			//var int _iScaledStartDragThumbPos;
	UPROPERTY()										int32 _iScaledThumbSize;					//var int _iScaledThumbSize;
	UPROPERTY()										int32 _iScaledThumbPos;						//var int _iScaledThumbPos;
	UPROPERTY()										int32 _iThumbSize;							//var int _iThumbSize;
	UPROPERTY()										int32 _iThumbPos;							//var int _iThumbPos;
	UPROPERTY()										int32 _iImageHeight;						//var int _iImageHeight;
	UPROPERTY()										int32 _iImageWidth;							//var int _iImageWidth;
	UPROPERTY()										FPosition ClippingRegion;					//var UIBase.Position ClippingRegion;
	UPROPERTY()										FPosition _ScaledThumbPos;					//var UIBase.Position _ScaledThumbPos;
	UPROPERTY()										FPosition _ThumbPos;						//var UIBase.Position _ThumbPos;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void SizeThumb(float percentage);
	void Draw(UCanvas* Canvas);
	void SetImageDimensions(int32 imgW, int32 imgH);
	void SetThumbTexture(UMaterialInstance* Tex);
	void SetBackTexture(UMaterialInstance* Tex);

};
