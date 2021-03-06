// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "GUIVertList.generated.h"

class UGUIComponent;
UCLASS()
class UGUIVertList : public UGUIListBase
{
	GENERATED_BODY()
public:
	UGUIVertList();

	void GetItemHeight(UCanvas* C);
	void CenterMouse();
	int32 CalculateIndex(bool bRequireValidIndex);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyType(uint8& Key, FString Unicode);
	void WheelUp();
	void WheelDown();
	bool Up();
	bool Down();
	void home();
	void End();
	void PgUp();
	void PgDn();
};
