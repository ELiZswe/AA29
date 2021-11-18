// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDMenuCrosshair.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDMenuCrosshair : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDMenuCrosshair();

	UPROPERTY()										bool _bEdit;								//var bool _bEdit;
	UPROPERTY()										bool _bButtonDown2;							//var bool _bButtonDown2;
	UPROPERTY()										int32 _iState;								//var int _iState;
	UPROPERTY()										TArray<UMaterialInstance*> _tCrosshair;		//var Texture _tCrosshair;
	UPROPERTY()										int32 iCrosshairIndex;						//var int iCrosshairIndex;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void PrevMode();
	void NextMode();
	void Draw(UCanvas* Canvas);
	void Refresh();
	void SetCrosshair(int32 C);
	void NextCrosshair();
};
