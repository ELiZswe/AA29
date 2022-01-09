// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "LeavenworthScreenplay.generated.h"

UCLASS()
class ALeavenworthScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ALeavenworthScreenplay();

	void Init();
};
