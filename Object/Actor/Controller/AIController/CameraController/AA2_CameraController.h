// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA2_CameraController.generated.h"

class UScriptObject;

UCLASS()
class AA29_API AAA2_CameraController : public AaAIController
{
	GENERATED_BODY()
public:
	AAA2_CameraController();

	UPROPERTY()										float fCosVisionAngle;							//var transient float fCosVisionAngle;
	UPROPERTY()										float fScanTime;								//var transient float fScanTime;
	UPROPERTY()										UScriptObject* _EnemySpottedMonitor;			//var ScriptObject _EnemySpottedMonitor;
	UPROPERTY()										float fViewDist;								//var float fViewDist;
	UPROPERTY()										float fSinFreq;									//var float fSinFreq;
	UPROPERTY()										FRotator rSinAmp;								//var Object.Rotator rSinAmp;
	UPROPERTY()										float fVisionAngle;								//var float fVisionAngle;

	void BeginState();
	void Tick(float DeltaTime);
	bool EnemyIsVisible();
	void SetEnemySpottedMonitor(UScriptObject* esm);
};
