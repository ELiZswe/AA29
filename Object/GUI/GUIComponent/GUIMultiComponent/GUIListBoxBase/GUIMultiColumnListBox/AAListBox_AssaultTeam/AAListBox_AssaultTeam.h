// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AAListBox_AssaultTeam.generated.h"

class UGUIController;
class UGUIComponent;

UCLASS()
class AA29_API UAAListBox_AssaultTeam : public UGUIMultiColumnListBox
{
	GENERATED_BODY()
public:
	UAAListBox_AssaultTeam();


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnDraw(UCanvas* C);
};
