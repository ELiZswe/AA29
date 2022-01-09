// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "AIScript.generated.h"

class AAIMarker;
class AaAIController;

UCLASS()
class AAIScript : public AKeypoint
{
	GENERATED_BODY()
public:
	AAIScript(const FObjectInitializer& objectInitializer);

	UPROPERTY()						AAIMarker*			myMarker;				//var AIMarker myMarker;
	UPROPERTY()						bool				bLoggingEnabled;		//var bool bLoggingEnabled;
	UPROPERTY()						bool				bNavigate;				//var bool bNavigate;
	UPROPERTY(EditAnywhere)			AaAIController*		ControllerClass;		//var() class<AIController> ControllerClass;

	void SpawnControllerFor(APawn* p);
	AActor* GetMoveTarget();
	void TakeOver(APawn* p);
};
