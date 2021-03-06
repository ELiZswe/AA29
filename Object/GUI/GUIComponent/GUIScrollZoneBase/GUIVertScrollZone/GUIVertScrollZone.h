// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIScrollZoneBase.h"
#include "GUIVertScrollZone.generated.h"

class UGUIComponent;
UCLASS()
class UGUIVertScrollZone : public UGUIScrollZoneBase
{
	GENERATED_BODY()
public:
	UGUIVertScrollZone();

	bool InternalOnClick(UGUIComponent* Sender);
};
