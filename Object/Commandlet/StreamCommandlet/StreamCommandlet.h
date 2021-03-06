// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Commandlet/AA2_Commandlet.h"
#include "StreamCommandlet.generated.h"

UCLASS()
class UStreamCommandlet : public UAA2_Commandlet
{
	GENERATED_BODY()
public:
	UStreamCommandlet();
	
	//int32 Main(FString Parms);
	void chart(FString Src);
	int32 RevInStr(FString Src, FString Match);
};
