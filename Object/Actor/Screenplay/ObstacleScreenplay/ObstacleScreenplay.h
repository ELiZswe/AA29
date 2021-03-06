// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "ObstacleScreenplay.generated.h"

class AAGP_Timer;

UCLASS()
class AObstacleScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	AObstacleScreenplay();

	UPROPERTY()			AAGP_Timer*		_DisplayTimer;						//var AGP_Gameplay.AGP_Timer* _DisplayTimer;
	void Init();
	void Draw(UCanvas* Canvas);
	void SetActor(int32 Type, AActor* Actor);
};
