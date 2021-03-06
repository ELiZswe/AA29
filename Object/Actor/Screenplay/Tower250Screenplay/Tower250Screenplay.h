// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "Tower250Screenplay.generated.h"

UCLASS()
class ATower250Screenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ATower250Screenplay();

	void Init();
	void Draw(UCanvas* Canvas);
	void SetActor(int32 Type, AActor* Actor);
};
