// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "AI_Interface.generated.h"

UCLASS()
class AAI_Interface : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AAI_Interface();

	void Init();
};
