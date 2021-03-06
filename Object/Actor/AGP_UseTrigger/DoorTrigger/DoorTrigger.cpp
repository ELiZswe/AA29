// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"

ADoorTrigger::ADoorTrigger()
{
	DoorTriggerHelp.SetNum(13);
	DoorTriggerHelp = { "Can be used to open and close doors or other movers.","Use this entity to trigger it's event.","When triggered, locks and unlocks 'door'","","[bLocked] Whether the 'door' is locked.","[bOpen] Whether the door is to be considered open.","Setting this flag does not actually trigger the mover","one way or the other. Use it if you need another actor","to track the status of the door.","[DoorTag] The name of the door/mover to trigger.","[SoundLocked] The sound to make when used if locked","[SoundLocking] The sound to make when actually locking","[SoundUnlocking] The sound to make when unlocking" };
	TextUnlocked = "Open/Close";
	TextLocked = "Locked";
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_DoorTrigger.S_DoorTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
	//CollisionRadius = 32;
	//CollisionHeight = 64;
}

bool ADoorTrigger::IsLocked()
{
	return bIsLocked;
}

bool ADoorTrigger::IsOpen()
{
	return bOpen;
}

void ADoorTrigger::SetLocked(bool Locked)
{
	bIsLocked = Locked;
	if (bIsLocked)
	{
		//PlaySound(SoundLocking);
	}
	else
	{
		//PlaySound(SoundUnLocking);
	}
	MySetHUDText();
}

void ADoorTrigger::BeginPlay()
{
	SetLocked(bLocked);
}

void ADoorTrigger::MySetHUDText()
{
	if (bIsLocked)
	{
		HUDText = TextLocked;
	}
	else
	{
		HUDText = TextUnlocked;
	}
}

void ADoorTrigger::MatchStarting()
{
	SetLocked(bLocked);
}

bool ADoorTrigger::UsedBy(APawn* User)
{
	if (!bActive)
	{
		return true;
	}
	if (bIsLocked)
	{
		//PlaySound(SoundLocked);
		return true;
	}
	else
	{
		//TriggerEvent(DoorTag, this, User);
		//TriggerEvent(Event, this, User);
		bOpen = (!bOpen);
		/*
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this, 1);
		}
		if (_Target != nullptr)
		{
			_Target.Notify();
		}
		*/
	}
	return true;
}

void ADoorTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (!bActive)
	{
		return;
	}
	/*
	switch (LockType)
	{
	case 1:
		if (IsLocked())
		{
			SetLocked(false);
			break;
		}
		SetLocked(true);
	}
	GOTO JL0056;
	case 2:
		if (!IsLocked())
		{
			SetLocked(true);
		}
		GOTO JL0056;
	default:
		GOTO JL0056;
	JL0056:
	}
	*/
}

void ADoorTrigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	if (!bActive)
	{
		return;
	}
	/*
	switch (LockType)
	{
	case 2:
		if (bLocked)
		{
			SetLocked(false);
		}
		break;
	default:
		break;
	}
	*/
}

bool ADoorTrigger::ToggleOpen()
{
	if (bIsLocked)
	{
		//PlaySound(SoundLocked);
		return false;
	}
	else
	{
		//TriggerEvent(DoorTag, this, nullptr);
		bOpen = (!bOpen);
		/*
		if (_Target != nullptr)
		{
			_Target.Notify();
		}
		*/
		return true;
	}
}

void ADoorTrigger::Open()
{
	if (!bOpen)
	{
		//TriggerEvent(DoorTag, this, nullptr);
		bOpen = true;
	}
}

void ADoorTrigger::Close()
{
	if (bOpen)
	{
		//TriggerEvent(DoorTag, this, nullptr);
		bOpen = false;
	}
}
