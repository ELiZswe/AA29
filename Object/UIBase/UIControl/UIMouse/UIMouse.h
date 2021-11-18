// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIMouse.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIMouse : public UUIControl
{
	GENERATED_BODY()
public:
	UUIMouse();


	UPROPERTY()										bool bDrawnBusy;						//var bool bDrawnBusy;
	UPROPERTY()										bool _bBusy;							//var bool _bBusy;
	UPROPERTY()										bool _bHasMoved;						//var bool _bHasMoved;
	UPROPERTY()										UMaterialInstance* _BusyTexture;		//var Texture _BusyTexture;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;
	UPROPERTY()										FString _sBitmapName;					//var string _sBitmapName;
	UPROPERTY()										int32 iMouseY;							//var int iMouseY;
	UPROPERTY()										int32 iMouseX;							//var int iMouseX;



	void Destroyed();
	void CreateTexture();
	void SetMouse(int32 mX, int32 mY);
	void Draw(UCanvas* Canvas);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void SetBitmapString(FString Bitmap);
	bool HasMouseMoved();
	void SetBusy(bool busy);
};
