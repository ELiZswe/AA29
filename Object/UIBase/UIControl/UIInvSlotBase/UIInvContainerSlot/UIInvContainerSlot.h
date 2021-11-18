// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "UIInvContainerSlot.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIInvContainerSlot : public UUIInvSlotBase
{
	GENERATED_BODY()
public:
	UUIInvContainerSlot();

	//const kBorderSize = 1;


	UPROPERTY()										FPosition _BorderBottom;					//var UIBase.Position _BorderBottom;
	UPROPERTY()										FPosition _BorderTop;						//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderRight;						//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderLeft;						//var UIBase.Position _BorderLeft;
	UPROPERTY()										FPosition _iTexDim;							//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _BorderTexture;			//var Texture _BorderTexture;
	UPROPERTY()										int32 nSelection;							//var int nSelection;
	UPROPERTY()										int32 nButtonDownSlot;						//var int nButtonDownSlot;
	UPROPERTY()										bool bButtonDown;							//var bool bButtonDown;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetBorderTexture(UMaterialInstance* Tex);
	void SetTextureDimensions(FPosition dim);
	void ScaleControl(UCanvas* Canvas);
};
