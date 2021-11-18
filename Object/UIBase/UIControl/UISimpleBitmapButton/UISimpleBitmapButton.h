// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UISimpleBitmapButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUISimpleBitmapButton : public UUIControl
{
	GENERATED_BODY()
public:
	UUISimpleBitmapButton();


	//const kResX = 1280.0;
	//const kResY = 1024.0;


	UPROPERTY()										FString _sInfo;							//var string _sInfo;
	UPROPERTY()										int32 iState;							//var int iState;
	UPROPERTY()										FPosition _iTexDim;						//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);

};
