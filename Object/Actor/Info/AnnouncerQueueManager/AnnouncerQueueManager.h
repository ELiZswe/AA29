// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "AnnouncerQueueManager.generated.h"

UCLASS()
class AAnnouncerQueueManager : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAnnouncerQueueManager();

	UPROPERTY()			APlayerController*	Receiver;			//var PlayerController Receiver;
	UPROPERTY()			float				GapTime;			//var float GapTime;
	UPROPERTY()			float				LastTimerCheck;		//var float LastTimerCheck;
	UPROPERTY()			TArray<FQueueItem>	Queue;				//var array<QueueItem> Queue;

	void PostBeginPlay();
	void InitFor(APlayerController* PC);
	bool AddItemToQueue(FName ASound, EAPriority Priority, uint8 Switch);
	bool CanFindSoundInQueue(FName DaSoundName);
	bool IsQueueing();
	bool IsQueueingswitch(uint8 Switch);
	float GetQueueWaitTime();
	void Timer();
	void ProcessQueueItem(FQueueItem Item);
};
