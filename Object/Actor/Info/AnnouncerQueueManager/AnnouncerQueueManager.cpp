// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/AnnouncerQueueManager/AnnouncerQueueManager.h"

AAnnouncerQueueManager::AAnnouncerQueueManager()
{
	GapTime = 0.1;
}

void AAnnouncerQueueManager::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//LastTimerCheck = GetWorld()->GetTimeSeconds();
	//SetTimer(0.1, true);
}

void AAnnouncerQueueManager::InitFor(APlayerController* PC)
{
	Receiver = PC;
}

bool AAnnouncerQueueManager::AddItemToQueue(FName ASound, EAPriority Priority, uint8 Switch)
{
	FQueueItem NewItem = FQueueItem({});
	/*
	if (Receiver == nullptr)
	{
		return false;
	}
	if (Priority == 2 && IsQueueing())
	{
		return false;
	}
	if (Priority == 3 && !IsQueueingswitch(Switch))
	{
		return false;
	}
	if (Priority == 1 && CanFindSoundInQueue(ASound))
	{
		return false;
	}
	NewItem.Voice = ASound;
	NewItem.Switch = Switch;
	if (Priority == 3)
	{
		NewItem.Delay = 0.01;
	}
	else
	{
		if (ASound != "None" && Receiver.StatusAnnouncer != nullptr)
		{
			NewItem.Delay = GetSoundDuration(Receiver.StatusAnnouncer.GetSound(ASound)) + GapTime;
		}
		else
		{
			NewItem.Delay = GapTime;
		}
	}
	if (Queue.Num() == 0)
	{
		LastTimerCheck = GetWorld()->GetTimeSeconds();
		ProcessQueueItem(NewItem);
	}
	Queue[Queue.Num()] = NewItem;
	*/
	return true;
}

bool AAnnouncerQueueManager::CanFindSoundInQueue(FName DaSoundName)
{
	int32 i = 0;
	for (i = 0; i < Queue.Num()-1; i++)
	{
		//if (Queue[i].Voice == DaSoundName)
		if (Queue[i].Name == DaSoundName)
		{
			return true;
		}
	}
	return false;
}

bool AAnnouncerQueueManager::IsQueueing()
{
	return Queue.Num() > 0;
}

bool AAnnouncerQueueManager::IsQueueingswitch(uint8 Switch)
{
	int32 i = 0;
	if (Queue.Num()== 0)
	{
		return true;
	}
	for (i = 0; i < Queue.Num()-1; i++)
	{
		if (Queue[i].Switch != Switch)
		{
			return false;
		}
	}
	return true;
}

float AAnnouncerQueueManager::GetQueueWaitTime()
{
	int32 i = 0;
	float WaitTime = 0;
	if (!IsQueueing())
	{
		return 0;
	}
	for (i = 0; i < Queue.Num(); i++)
	{
		WaitTime += Queue[i].Delay;
	}
	return WaitTime;
}
void AAnnouncerQueueManager::Timer()
{
	float DeltaTime = 0;
	/*
	DeltaTime = GetWorld()->GetTimeSeconds() - LastTimerCheck / Level.TimeDilation;
	if (Queue.Num() > 0)
	{
		Queue[0].Delay -= DeltaTime;
		if (Queue[0].Delay <= 0)
		{
			if (Queue.Num() > 1)
			{
				ProcessQueueItem(Queue[1]);
			}
			Queue.RemoveAt(0, 1);
		}
	}
	LastTimerCheck = GetWorld()->GetTimeSeconds();
	*/
}

void AAnnouncerQueueManager::ProcessQueueItem(FQueueItem Item)
{
	if (Receiver == nullptr)
	{
		return;
	}
	/*
	if (Item.Voice != "None")
	{
		Receiver.PlayStatusAnnouncement(Item.Voice, 0, true);
	}
	if (Item.Switch > 0)
	{
		Receiver.MyHUD.AnnouncementPlayed(Item.Voice, Item.Switch);
	}
	*/
}
