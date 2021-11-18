// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "UIHUDRackItem.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIHUDRackItem : public UUIInvSlotBase
{
	GENERATED_BODY()
public:
	UUIHUDRackItem();

	//const kBorderSize = 1;


	UPROPERTY()										FPosition _BorderBottom;					//var UIBase.Position _BorderBottom;
	UPROPERTY()										FPosition _BorderTop;						//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderRight;						//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderLeft;						//var UIBase.Position _BorderLeft;
	UPROPERTY()										int32 _iRackIndex;							//var int _iRackIndex;
	UPROPERTY()										FPosition _iTexDim;							//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _BorderTexture;			//var Texture _BorderTexture;


	void Destroyed();
	void Draw(UCanvas* Canvas);
	void SetBorderTexture(UMaterialInstance* Tex);
	void SetTextureDimensions(FPosition dim);
	void SetRackIndex(int32 Index);
	void ScaleControl(UCanvas* Canvas);
};
