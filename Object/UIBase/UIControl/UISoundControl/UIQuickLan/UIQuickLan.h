// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UISoundControl.h"
#include "UIQuickLan.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIQuickLan : public UUISoundControl
{
	GENERATED_BODY()
public:
	UUIQuickLan();


	UPROPERTY()										int32 _iNumOver;						//var int _iNumOver;
	UPROPERTY()										int32 _iNumLan;							//var int _iNumLan;
	UPROPERTY()										bool _bFirstOver;						//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;							//var int _iState;



	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void ConnectToLanServer();

};
