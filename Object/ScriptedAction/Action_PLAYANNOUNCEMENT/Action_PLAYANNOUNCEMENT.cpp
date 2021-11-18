// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_PLAYANNOUNCEMENT/Action_PLAYANNOUNCEMENT.h"

UAction_PLAYANNOUNCEMENT::UAction_PLAYANNOUNCEMENT()
{
	ActionString = "play announcement";
}



bool UAction_PLAYANNOUNCEMENT::InitActionFor(UScriptedController* C)
{
	/*
	local PlayerController p;
	local name SoundName;
	if (C.Level.NetMode == 0)
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
FName UAction_PLAYANNOUNCEMENT::LastMinuteHack_ShipIt(UScriptedController* C)
{
	FName SoundName = "";
	/*
	local PlayerController LocalPlayer;
	local name SoundName;
	LocalPlayer = C.Level.GetLocalPlayerController();
	if (Sound != None)
	{
		SoundName = Sound.Name;
	}
	if (Sound == None && C.Tag == 'Play_Intro3' && C.MyScript.Tag == 'Hack_RIP_Epic_MegaCar')
	{
		SoundName = 'MotherShip_intro';
	}
	else
	{
		if (C.MyScript.Tag == 'Hack_I_Love_Mina')
		{
			if (C.Tag == 'Play_Brief4' && LocalPlayer.StatusAnnouncer.GetSound('Junkyard_brief4a') != None)
			{
				SoundName = 'Junkyard_brief4a';
			}
			else
			{
				if (Sound == None)
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
	//Return ActionString @ Sound;
	return "";    //FAKE   /ELiZ
}
void UAction_PLAYANNOUNCEMENT::PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds)
{
	/*
	if (!bRewardSounds && !bSoundsPrecached)
	{
		bSoundsPrecached = true;
		if (Sound != None)
		{
			V.PrecacheSound(Sound.Name);
		}
	}
	*/
}