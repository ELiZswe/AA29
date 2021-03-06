// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "TargetMover.generated.h"

class ATargetManager;

UCLASS()
class ATargetMover : public AMover
{
	GENERATED_BODY()
public:
	ATargetMover();

	UPROPERTY()										bool bTargetPractice;						//var bool bTargetPractice;
	UPROPERTY()										bool bDoUnTrigger;							//var bool bDoUnTrigger;
	UPROPERTY()										ATargetManager* my_manager;					//var TargetManager my_manager;
	UPROPERTY()										bool bWasDamageTriggered;					//var bool bWasDamageTriggered;
	UPROPERTY(EditAnywhere)							float fTargetPracticeDownTime;				//var() float fTargetPracticeDownTime;
	UPROPERTY(EditAnywhere)							int32 GroupNumber;							//var() int GroupNumber;
};
