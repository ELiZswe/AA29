// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2MusicManager/UT2MusicManager.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UUT2MusicManager::UUT2MusicManager()
{
	bPersistent = true;
}

void UUT2MusicManager::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	ExtendedConsole(Controller.Master.Console).MusicManager = this;
	*/
}

void UUT2MusicManager::SetMusic(FString NewSong)
{
	//Playlist.Current = NewSong;
}

FString UUT2MusicManager::SetInitialMusic(FString NewSong)
{
	/*
	int32 i = 0;
	if (Playlist.Songs.Num() == 0)
	{
		return NewSong;
	}
	for (i = 0; i < Playlist.Songs.Num(); i++)
	{
		if (Playlist.Songs[i] ~= NewSong)
		{
			return NewSong;
		}
	}
	if (Playlist.Current == "")
	{
		return Playlist.Songs[0];
	}
	return Playlist.Current;
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void UUT2MusicManager::MusicChanged()
{
	/*
	int32 i = 0;
	int32 Index = 0;
	if (Playlist.Songs.Num() == 0)
	{
		return;
	}
	if (Playlist.bShuffle)
	{
		i = Rand(Playlist.Songs.Num());
		PlayerOwner().ClientSetMusic(Playlist.Songs[i], 3);
	}
	else
	{
		Index = -1;
		for (i = 0; i < Playlist.Songs.Num(); i++)
		{
			if (Playlist.Songs[i] ~= Playlist.Current)
			{
				Index = i;
			}
		}
		Index++;
		if ((Index == Playlist.Songs.Num()) && Playlist.bRepeat)
		{
			Index = 0;
		}
		PlayerOwner().ClientSetMusic(Playlist.Songs[Index], 3);
	}
	*/
}

bool UUT2MusicManager::NotifyLevelChange()
{
	return false;
}
