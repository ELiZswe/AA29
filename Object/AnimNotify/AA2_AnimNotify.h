// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA2_AnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAA2_AnimNotify : public UObject
{
	GENERATED_BODY()
public:
	UAA2_AnimNotify();

	UPROPERTY()													int32 Revision;								//var transient int Revision
};
