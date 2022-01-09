// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PropertyManagerBase.generated.h"

class UGUIController;

UCLASS()
class UPropertyManagerBase : public UObject
{
	GENERATED_BODY()
public:
	UPropertyManagerBase();

	UPROPERTY()			UGUIController* Parent;							//var GUIController Parent;
};
