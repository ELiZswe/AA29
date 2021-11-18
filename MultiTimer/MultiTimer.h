// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "MultiTimer.generated.h"

UCLASS()
class AA29_API AMultiTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMultiTimer();

	UPROPERTY()										TArray<AActor*> Hosts;							//var array<Actor> Hosts;
	UPROPERTY()										TArray<FTimerEvent> TimerEvents;				//var array<TimerEvent> TimerEvents;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void TimerNotify(FName TimerName, AMultiTimer* Timer);
	void ProcessTimerEvents();
	void NotifyHosts(FName TimerName, AMultiTimer* Timer);
	void SetTimerEvent(FName Name, float Time, bool bRepeat, AActor* Actor);
	void SetTimerHost(AActor* Host);
	void RemoveTimerHost(AActor* Host);
	void StartTimer(FName Name, float Time, bool bRepeat);
	void StopTimer(FName Name);
	void StopAllTimers();
	bool HasTimers();



};
