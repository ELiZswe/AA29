// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AAListBox_DefenseTeam.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAListBox_DefenseTeam : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UAAListBox_DefenseTeam();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnDraw(UCanvas* C);
};
