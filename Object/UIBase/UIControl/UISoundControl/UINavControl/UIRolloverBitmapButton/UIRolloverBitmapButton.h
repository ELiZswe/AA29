// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIRolloverBitmapButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIRolloverBitmapButton : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIRolloverBitmapButton();


	UPROPERTY()										bool _bFirstOver;						//var bool _bFirstOver;
	UPROPERTY()										FString _sInfo;							//var string _sInfo;
	UPROPERTY()										int32 _iState;							//var int _iState;
	UPROPERTY()										FPosition _iTexDim;						//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void SetTexture(FString Tex);

};
