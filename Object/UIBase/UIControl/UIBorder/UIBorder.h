// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIBorder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBorder : public UUIControl
{
	GENERATED_BODY()
public:
	UUIBorder();

	//const kBorderSize = 1;


	UPROPERTY()										bool _bDrawBack;						//var bool _bDrawBack;
	UPROPERTY()										FPosition _BorderBottom;				//var UIBase.Position _BorderBottom;
	UPROPERTY()										FPosition _BorderTop;					//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderRight;					//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderLeft;					//var UIBase.Position _BorderLeft;
	UPROPERTY()										FPosition _iTexDim;						//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _Texture2;			//var Texture _Texture2;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void ProcessParams();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void ScaleControl(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);
	void SetTexture2(UMaterialInstance* Tex);
};
