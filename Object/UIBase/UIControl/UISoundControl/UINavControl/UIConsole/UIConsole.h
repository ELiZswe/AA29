// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIConsole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIConsole : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIConsole();


	UPROPERTY()										bool _bFirstOver;						//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;							//var int _iState;

	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
};
