// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDSupportBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDSupportBox : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDSupportBox();



	UPROPERTY()										UMaterialInstance* _Texture;		//var Texture _Texture;
	UPROPERTY()										UMaterialInstance* _Texture2;		//var Texture _Texture2;
	UPROPERTY()										FPosition _iTexDim;					//var UIBase.Position _iTexDim;
	UPROPERTY()										FPosition _BorderLeft;				//var UIBase.Position _BorderLeft;
	UPROPERTY()										FPosition _BorderRight;				//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderTop;				//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderBottom;			//var UIBase.Position _BorderBottom;
	UPROPERTY()										int32 _iXOffset;					//var int _iXOffset;
	UPROPERTY()										int32 _iYOffset;					//var int _iYOffset;
	UPROPERTY()										bool _bSetSupported;				//var bool _bSetSupported;

	void Destroyed();
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void ScaleControl(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* Tex);
	void SetTexture2(UMaterialInstance* Tex);

};
