// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "fx_exp_DebrisA.generated.h"

UCLASS()
class Afx_exp_DebrisA : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	Afx_exp_DebrisA();

	void BeginPlay();
};
