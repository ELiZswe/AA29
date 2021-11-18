// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIInvDropBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIInvDropBox : public UUIControl
{
	GENERATED_BODY()
public:
	UUIInvDropBox();


	//const kBorderSize = 1;


	UPROPERTY()										FPosition _BorderBottom;					//var UIBase.Position _BorderBottom;
	UPROPERTY()										FPosition _BorderTop;						//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderRight;						//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderLeft;						//var UIBase.Position _BorderLeft;
	UPROPERTY()										FPosition _iTexDim;							//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _BorderTexture;			//var Texture _BorderTexture;
	UPROPERTY()										int32 _iItemID;								//var int _iItemID;
	UPROPERTY()										int32 nSelection;							//var int nSelection;
	UPROPERTY()										int32 nButtonDownSlot;						//var int nButtonDownSlot;
	UPROPERTY()										bool bButtonDown;							//var bool bButtonDown;
	UPROPERTY()										UMaterialInstance* _TexSel;					//var Texture _TexSel;
	UPROPERTY()										UMaterialInstance* _Texture;				//var Texture _Texture;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);
	void SetTexture2(UMaterialInstance* Tex);
	void SetBorderTexture(UMaterialInstance* Tex);
	void SetTextureDimensions(FPosition dim);
	void ScaleControl(UCanvas* Canvas);
};
