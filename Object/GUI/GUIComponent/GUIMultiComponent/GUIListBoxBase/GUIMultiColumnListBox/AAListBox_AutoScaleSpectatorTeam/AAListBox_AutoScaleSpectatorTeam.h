// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AAListBox_AutoScaleSpectatorTeam.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAAListBox_AutoScaleSpectatorTeam : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UAAListBox_AutoScaleSpectatorTeam();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnDraw(UCanvas* C);
};
