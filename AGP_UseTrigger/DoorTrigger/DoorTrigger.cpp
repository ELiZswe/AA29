// All the original content belonged to the US Army


#include "AA29/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"

ADoorTrigger::ADoorTrigger()
{
	DoorTriggerHelp = { "Can be used to open and close doors or other movers.","Use this entity to trigger it's event.","When triggered, locks and unlocks 'door'","","[bLocked] Whether the 'door' is locked.","[bOpen] Whether the door is to be considered open.","Setting this flag does not actually trigger the mover","one way or the other. Use it if you need another actor","to track the status of the door.","[DoorTag] The name of the door/mover to trigger.","[SoundLocked] The sound to make when used if locked","[SoundLocking] The sound to make when actually locking","[SoundUnlocking] The sound to make when unlocking" };
	TextUnlocked = "Open/Close";
	TextLocked = "Locked";
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_DoorTrigger.S_DoorTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

	//CollisionRadius = 32;
	//CollisionHeight = 64;
}