// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AASupport_Glossary.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UAASupport_Glossary : public UAASupportContentSubPanel
{
	GENERATED_BODY()
public:
	UAASupport_Glossary();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
