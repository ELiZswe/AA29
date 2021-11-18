// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AAListBox_AutoScaleDefenseTeam.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAListBox_AutoScaleDefenseTeam : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UAAListBox_AutoScaleDefenseTeam();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnDraw(UCanvas* C);

};
