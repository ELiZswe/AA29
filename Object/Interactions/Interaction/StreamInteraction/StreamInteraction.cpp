// All the original content belonged to the US Army

#include "AA29/Object/Interactions/Interaction/StreamInteraction/StreamInteraction.h"
#include "AA29/Object/StreamBase/StreamPlaylistManager/StreamPlaylistManager.h"
#include "AA29/Object/StreamBase/Stream/Stream.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "AA29/Object/StreamBase/StreamTag/StreamTag.h"

UStreamInteraction::UStreamInteraction()
{
	FadeInSeconds = 0.5;
	FadeOutSeconds = 0.5;
	bRequiresTick = true;
}

static const int32 INVALIDSONGHANDLE = 0;

void UStreamInteraction::OnStreamChanged(FString NewStreamFileName)
{
}

void UStreamInteraction::OnStreamingStopped()
{
}

void UStreamInteraction::OnAdjustVolume(float NewVolume)
{
}

void UStreamInteraction::Initialized()
{
	//Super::Initialized();
	ClearSongInfo();
	FileManager = CreateFileManager();
	PlaylistManager = CreatePlaylistManager();
	if (PlaylistManager != nullptr)
	{
		PlaylistManager->Initialize(FileManager);
	}
	if (bAutoStart)
	{
		QueueNextSong();
	}
}

UStreamInterface* UStreamInteraction::CreateFileManager()
{
	//return new () UStreamInterface::StaticClass();
	return nullptr;     //FAKE   /ELiZ
}

UStreamPlaylistManager* UStreamInteraction::CreatePlaylistManager()
{
	UStreamPlaylistManager* PlaylistManagerClass = nullptr;
	/*
	if (PlaylistManagerType != "")
	{
		PlaylistManagerClass = class<StreamPlaylistManager>(DynamicLoadObject(PlaylistManagerType, Class'Class'));
	}
	if (PlaylistManagerClass == nullptr)
	{
		PlaylistManagerClass = UStreamPlaylistManager::StaticClass();
	}
	return new () classPlaylistManagerClass;
	*/
	return nullptr;     //FAKE   /ELiZ
}

void UStreamInteraction::QueueNextSong()
{
	bTrackWaiting = true;
}

void UStreamInteraction::Tick(float DeltaTime)
{
	if (bTrackWaiting)
	{
		NextSong(false);
	}
	else
	{
		if (bRestartTrack)
		{
			bRestartTrack = false;
			PlayStream(CurrentSong, int(CurrentSongPosition));
		}
		else
		{
			if ((!IsPaused(0)) && (CurrentSongHandle != 0))
			{
				//(CurrentSongPosition += (DeltaTime / ViewportOwner.Actor.Level.TimeDilation));
			}
		}
	}
}

//native final Function bool IsPaused(int32 SongHandle);
bool UStreamInteraction::IsPaused(int32 SongHandle)
{
	return false;
}

void UStreamInteraction::SetStreamAttachment(UStream* StreamObj)
{
	UStreamTag* sTag = nullptr;
	/*
	CurrentStreamAttachment = StreamObj;
	if (CurrentStreamAttachment != nullptr)
	{
		sTag = CurrentStreamAttachment.GetTag();
		if (sTag != nullptr)
		{
			CurrentSongDuration = (float(sTag.Duration.FieldValue) / 1000);
		}
	}
	*/
}

void UStreamInteraction::StreamFinished(int32 Handle, EStreamFinishReason Reason)
{
	/*
	Super::StreamFinished(Handle, Reason);
	PlaylistManager.Save();
	Log("StreamFinished() Handle:" + FString::FromInt(Handle) @ "Reason:" + FString::FromInt(GetEnum(Enum'Engine.Interactions.EStreamFinishReason', Reason)), "MusicPlayer");
	if ((Handle == CurrentSongHandle) && (CurrentSongHandle != 0))
	{
		Log("CurrentSongPosition:" + UStreamBase::StaticClass().FormatTimeDisplay(CurrentSongPosition) @ "Total song time:" + UStreamBase::StaticClass().FormatTimeDisplay(GetStreamDuration()));
		CurrentSongPosition = 0;
		CurrentSongHandle = 0;
		SetStreamAttachment(nullptr);
		OnStreamingStopped();
		QueueNextSong();
	}
	else
	{
		Log(string(Name) @ "StreamFinished Invalid Song Handle", "MusicPlayer");
	}
	*/
}

void UStreamInteraction::NotifyLevelChange()
{
	if ((CurrentSongHandle != 0) && (CurrentSong != ""))
	{
		bRestartTrack = true;
	}
}

FString UStreamInteraction::GetCurrentStream()
{
	HasPlayer();
	//Log("CurrentSongHandle:" + FString::FromInt(CurrentSongHandle) @ "CurrentSong:" + CurrentSong @ "IsPaused:" + FString::FromInt(IsPaused()));
	return CurrentSong;
}

int32 UStreamInteraction::CurrentHandle()
{
	return CurrentSongHandle;
}

void UStreamInteraction::NextSong(bool bForce)
{
	if (!HasPlayer())
	{
		return;
	}
	bTrackWaiting = false;
	//PlayStream(PlaylistManager.NextSong(bForce));
}

void UStreamInteraction::PrevSong(bool bForce)
{
	if (!HasPlayer())
	{
		return;
	}
	bTrackWaiting = false;
	if (CurrentSongPosition > 3)
	{
		PlayStream(CurrentSong,false);
	}
	else
	{
		//PlayStream(PlaylistManager.PrevSong(bForce));
	}
}

void UStreamInteraction::PauseSong()
{
	if (!HasPlayer())
	{
		return;
	}
	if (CurrentSongHandle != 0)
	{
		//PC().PauseStream(CurrentSongHandle);
	}
}

void UStreamInteraction::PlaySong(FString SongName, float InitialTime)
{
	if (!HasPlayer())
	{
		return;
	}
	PlayStream(SongName, int(InitialTime));
}

void UStreamInteraction::StopSong()
{
	if (!HasPlayer())
	{
		return;
	}
	if (CurrentSongHandle != 0)
	{
		//PC().StopStream(CurrentSongHandle, FadeOutSeconds);
	}
	//PC().AllowMusicPlayback(true);
	ClearSongInfo();
}

void UStreamInteraction::SetMusicVolume(float NewVolume)
{
	if (HasPlayer())
	{
		//PC().AdjustVolume(CurrentSongHandle,FMath::Clamp(NewVolume, 0, 1));
		OnAdjustVolume(NewVolume);
	}
}

void UStreamInteraction::SeekStream(float Seconds)
{
	Seek(Seconds);
}

bool UStreamInteraction::Seek(float SeekSeconds)
{
	return false;
	/*
	if (CurrentSongHandle != 0)
	{
		if (PC().SeekStream(CurrentSongHandle, SeekSeconds) > 0)
		{
			CurrentSongPosition = SeekSeconds;
			return true;
		}
	}
	*/
	return false;
}

void UStreamInteraction::PlayStream(FString Filename, int32 SeekSeconds)
{
	int32 LastSongHandle = 0;
	/*
	if (Filename != "")
	{
		if (((Filename == CurrentSong) && IsPaused()) && (float(SeekSeconds) == 0))
		{
			PauseSong();
			return;
		}
		SeekSeconds = 0;
		LastSongHandle = CurrentSongHandle;
		if ((float(SeekSeconds) > 0) && (CurrentSong == Filename))
		{
			CurrentSongHandle = PC().PlayStream(Filename, true);
		}
		else
		{
			CurrentSongHandle = PC().PlayStream(Filename, true);
		}
		if (CurrentSongHandle == 0)
		{
			Log("StreamInteraction::PlaySong() Invalid song name:" @ Filename, "MusicPlayer");
		}
		else
		{
			KillMusic();
			CurrentSongPosition = float(SeekSeconds);
			CurrentSongDuration = 0;
			if (LastSongHandle != 0)
			{
				if ((float(SeekSeconds) > 0) && (CurrentSong == Filename))
				{
					PC().StopStream(LastSongHandle);
				}
				else
				{
					PC().StopStream(LastSongHandle, FadeOutSeconds);
				}
			}
			CurrentSong = Filename;
			if (bDisplayTrackChanges)
			{
				PC().ClientMessage("Now playing '" + CurrentSong + "' Handle:" + FString::FromInt(CurrentSongHandle));
			}
			OnStreamChanged(CurrentSong);
		}
	}
	else
	{
		if (CurrentSongHandle == 0)
		{
			PC().AllowMusicPlayback(true);
			ClearSongInfo();
		}
	}
	*/
}

float UStreamInteraction::GetStreamPosition()
{
	return CurrentSongPosition;
}

float UStreamInteraction::GetStreamVolume()
{
	if (HasPlayer())
	{
		//return float(PC().ConsoleCommand("get ini:Engine.Engine.AudioDevice MusicVolume"));
	}
	return 0.8;
}

float UStreamInteraction::GetStreamDuration()
{
	if (!IsPlaying())
	{
		return 0;
	}
	if (CurrentSongDuration == 0)
	{
		//CurrentSongDuration = float(PC().ConsoleCommand("GETDURATION" @ FString::FromInt(CurrentSongHandle)));
	}
	return CurrentSongDuration;
}

bool UStreamInteraction::IsPlaying()
{
	return CurrentSongHandle != 0;
}

bool UStreamInteraction::HasPlayer()
{
	/*
	if (ViewportOwner == nullptr)
	{
		Log("StreamInteraction::HasPlayer() - No ViewportOwner!", "MusicPlayer");
		return false;
	}
	if (ViewportOwner.Actor == nullptr)
	{
		Log("StreamInteraction::HasPlayer() - No PlayerController!", "MusicPlayer");
		return false;
	}
	*/
	return true;
}

void UStreamInteraction::ClearSongInfo()
{
	SetStreamAttachment(nullptr);
	CurrentSong = "";
	CurrentSongHandle = 0;
	CurrentSongPosition = 0;
	CurrentSongDuration = 0;
}

void UStreamInteraction::KillMusic()
{
	if (!HasPlayer())
	{
		return;
	}
	//PC().StopAllMusic();
	//PC().AllowMusicPlayback(false);
}

APlayerController* UStreamInteraction::PC()
{
	if (HasPlayer())
	{
		//return ViewportOwner.Actor;
	}
	return nullptr;
}

void UStreamInteraction::streamdebug(FString Command, FString Param)
{
	/*
	if (Command ~= "getstats")
	{
		Log(" CurrentSong '" + CurrentSong + "' Handle:" + FString::FromInt(CurrentSongHandle) @ "Pos:" + FString::FromInt(CurrentSongPosition) @ "Duration:" + FString::FromInt(CurrentSongDuration));
		return;
	}
	if (FileManager.HandleDebugExec(Command, Param))
	{
		return;
	}
	if (PlaylistManager.HandleDebugExec(Command, Param))
	{
		return;
	}
	*/
}
