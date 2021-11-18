// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "GUIVertList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIVertList : public UGUIListBase
{
	GENERATED_BODY()
public:
	UGUIVertList();



	void GetItemHeight(UCanvas* C);
	void CenterMouse();
	int32 CalculateIndex(bool bRequireValidIndex);
	void InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyType(uint8& Key, FString Unicode);
	void WheelUp();
	void WheelDown();
	void Up();
	void Down();
	void home();
	void End();
	void PgUp();
	void PgDn();
};
