// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_PLAYANNOUNCEMENT/Action_PLAYANNOUNCEMENT.h"
#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_PLAYANNOUNCEMENT::UAction_PLAYANNOUNCEMENT()
{
	ActionString = "play announcement";
}

bool UAction_PLAYANNOUNCEMENT::InitActionFor(AScriptedController* C)
{
	APlayerController* p = nullptr;
	FName SoundName = "";
	/*
	if (C.GetWorld()->GetNetMode() == 0)
	{
		SoundName = LastMinuteHack_ShipIt(C);
	}
	else
	{
		SoundName = Sound.Name;
	}
	ForEach C.DynamicActors(Class'PlayerController', p)
	{
		p.QueueAnnouncement(SoundName, 1, 0);
	}
	*/
	return false;
}

FName UAction_PLAYANNOUNCEMENT::LastMinuteHack_ShipIt(AScriptedController* C)
{
	FName SoundName = "";
	APlayerController* LocalPlayer = nullptr;
	/*
	LocalPlayer = C.Level.GetLocalPlayerController();
	if (Sound != nullptr)
	{
		SoundName = Sound.Name;
	}
	if (Sound == nullptr && C.Tag == 'Play_Intro3' && C.MyScript.Tag == 'Hack_RIP_Epic_MegaCar')
	{
		SoundName = 'MotherShip_intro';
	}
	else
	{
		if (C.MyScript.Tag == 'Hack_I_Love_Mina')
		{
			if (C.Tag == 'Play_Brief4' && LocalPlayer.StatusAnnouncer.GetSound('Junkyard_brief4a') != nullptr)
			{
				SoundName = 'Junkyard_brief4a';
			}
			else
			{
				if (Sound == nullptr)
				{
					if (C.Tag == 'Play_Brief5')
					{
						SoundName = 'Junkyard_brief5a';
					}
					else
					{
						if (C.Tag == 'Play_Brief6')
						{
							SoundName = 'Junkyard_brief6a';
						}
						else
						{
							if (C.Tag == 'Play_Brief7')
							{
								SoundName = 'Junkyard_brief7a';
							}
						}
					}
				}
			}
		}
	}
	*/
	return SoundName;
}
FString UAction_PLAYANNOUNCEMENT::GetActionString()
{
	//return ActionString @ Sound;
	return "";    //FAKE   /ELiZ
}
void UAction_PLAYANNOUNCEMENT::PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds)
{
	/*
	if (!bRewardSounds && !bSoundsPrecached)
	{
		bSoundsPrecached = true;
		if (Sound != nullptr)
		{
			V.PrecacheSound(Sound.Name);
		}
	}
	*/
}
