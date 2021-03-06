// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "LiveJumpScreenplay.generated.h"

UCLASS()
class ALiveJumpScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ALiveJumpScreenplay();

	void Init();
	void Draw(UCanvas* Canvas);
};
