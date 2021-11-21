// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIScrollZoneBase.h"
#include "GUIHorzScrollZone.generated.h"

UCLASS()
class AA29_API UGUIHorzScrollZone : public UGUIScrollZoneBase
{
	GENERATED_BODY()
public:
	UGUIHorzScrollZone();

	bool InternalOnClick(UGUIComponent* Sender);
};
