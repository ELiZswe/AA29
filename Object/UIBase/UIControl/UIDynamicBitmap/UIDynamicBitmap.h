// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIDynamicBitmap.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIDynamicBitmap : public UUIControl
{
	GENERATED_BODY()
public:
	UUIDynamicBitmap();

	UPROPERTY()										int32 _iDrawType;						//var int _iDrawType;
	UPROPERTY()										int32 _iVSize;							//var int _iVSize;
	UPROPERTY()										int32 _iUSize;							//var int _iUSize;
	UPROPERTY()										bool _bAlpha;							//var bool _bAlpha;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;

	void Destroyed();
	void ProcessParams();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(FString Tex, int32 U, int32 V, int32 DrawType);

};
