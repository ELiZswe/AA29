// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_AnimObject/AGP_AnimObject.h"
#include "AGP_RangeFlag.generated.h"

UCLASS()
class AAGP_RangeFlag : public AAGP_AnimObject
{
	GENERATED_BODY()
public:
	AAGP_RangeFlag();
		

	void BeginPlay();
	void Tick(float DeltaTime);
	
protected:

};
