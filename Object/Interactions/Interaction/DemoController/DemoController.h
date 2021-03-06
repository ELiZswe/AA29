// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "DemoController.generated.h"

UCLASS(Config = Game)
class UDemoController : public UInteraction
{
	GENERATED_BODY()
public:
	UDemoController();

	// UPROPERTY()								FViewport			Viewport;				//var Viewport Viewport;
	UPROPERTY()								float				DemoModeTriggerTime;	//var float DemoModeTriggerTime;
	UPROPERTY()								float				DemoTimer;				//var float DemoTimer;
	UPROPERTY()								bool				bDemoStarted;			//var bool bDemoStarted;
	UPROPERTY()								bool				bNoDemosFound;			//var bool bNoDemosFound;
	UPROPERTY(EditAnywhere, globalconfig)	TArray<FString>		SavedDemos;				//var() globalconfig FString SavedDemos[32];
	UPROPERTY(EditAnywhere, globalconfig)	int32				DemoPlayTriggerTime;	//var() globalconfig int32 DemoPlayTriggerTime;

	bool PlayDemo(FString DemoName);
	void Initialized();
	void ViewportInitialized();
	void NotifyDemoCompleted();
	void ResetDemoTriggerTime();
	void StartRandomDemo();
	void Tick(float DeltaTime);
};
