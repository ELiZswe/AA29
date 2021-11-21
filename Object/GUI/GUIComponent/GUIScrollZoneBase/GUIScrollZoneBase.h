// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIScrollZoneBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIScrollZoneBase : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIScrollZoneBase();

	void OnScrollZoneClick(float Delta);
	bool InternalOnClick(UGUIComponent* Sender);
};
