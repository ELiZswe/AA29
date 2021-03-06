// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "GUIHorzList.generated.h"

class UGUIComponent;
UCLASS()
class UGUIHorzList : public UGUIListBase
{
	GENERATED_BODY()
public:
	UGUIHorzList();

	int32 CalculateIndex(bool bRequireValidIndex);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyType(uint8& Key, FString Unicode);
	void WheelUp();
	void WheelDown();
	bool MoveLeft();
	bool MoveRight();
	void ScrollLeft();
	void ScrollRight();
	void home();
	void End();
	void PgUp();
	void PgDn();
};
