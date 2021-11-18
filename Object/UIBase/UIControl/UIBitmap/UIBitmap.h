// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIBitmap.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBitmap : public UUIControl
{
	GENERATED_BODY()
public:
	UUIBitmap();

	UPROPERTY()										bool _bAlpha;							//var bool _bAlpha;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void ProcessParams();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(FString Tex);
};
