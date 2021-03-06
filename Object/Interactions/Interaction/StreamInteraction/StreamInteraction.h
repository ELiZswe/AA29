// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "StreamInteraction.generated.h"

class UStreamPlaylistManager;
class UStreamInterface;
class UStream;

UCLASS(Config = Game)
class UStreamInteraction : public UInteraction
{
	GENERATED_BODY()
public:
	UStreamInteraction();

	UPROPERTY(EditAnywhere, Config)					float					FadeInSeconds;				//var() config float FadeInSeconds;
	UPROPERTY(EditAnywhere, Config)					float					FadeOutSeconds;				//var() config float FadeOutSeconds;
	UPROPERTY(EditAnywhere, Config)					FString					PlaylistManagerType;		//var() config FString PlaylistManagerType;
	UPROPERTY(EditAnywhere)							UStreamPlaylistManager*	PlaylistManager;			//var() editconst noexport StreamPlaylistManager PlaylistManager;
	UPROPERTY(EditAnywhere)							UStreamInterface*		FileManager;				//var() editconst noexport StreamInterface FileManager;
	UPROPERTY(EditAnywhere)							int32					CurrentSongHandle;			//var() editconst noexport int32 CurrentSongHandle;
	UPROPERTY(EditAnywhere)							float					CurrentSongPosition;		//var() editconst noexport float CurrentSongPosition;
	UPROPERTY(EditAnywhere)							float					LastPlayTime;				//var() editconst noexport float LastPlayTime;
	UPROPERTY(EditAnywhere)							float					CurrentSongDuration;		//var() editconst noexport float CurrentSongDuration;
	UPROPERTY(EditAnywhere)							FString					CurrentSong;				//var() editconst noexport FString CurrentSong;
	UPROPERTY(EditAnywhere)							UStream*				CurrentStreamAttachment;	//var() editconst noexport Stream CurrentStreamAttachment;
	UPROPERTY(EditAnywhere, Config)					bool					bAutoStart;					//var() config bool bAutoStart;
	UPROPERTY(EditAnywhere, Config)					bool					bDisplayTrackChanges;		//var() config bool bDisplayTrackChanges;
	UPROPERTY(EditAnywhere)							bool					bRestartTrack;				//var() transient editconst noexport bool bRestartTrack;
	UPROPERTY(EditAnywhere)							bool					bTrackWaiting;				//var() transient editconst noexport bool bTrackWaiting;

	void OnStreamChanged(FString NewStreamFileName);
	void OnStreamingStopped();
	void OnAdjustVolume(float NewVolume);
	void Initialized();
	UStreamInterface* CreateFileManager();
	UStreamPlaylistManager* CreatePlaylistManager();
	void QueueNextSong();
	void Tick(float DeltaTime);
	bool IsPaused(int32 SongHandle);
	void SetStreamAttachment(UStream* StreamObj);
	void StreamFinished(int32 Handle, EStreamFinishReason Reason);
	void NotifyLevelChange();
	FString GetCurrentStream();
	int32 CurrentHandle();
	void NextSong(bool bForce);
	void PrevSong(bool bForce);
	void PauseSong();
	void PlaySong(FString SongName, float InitialTime);
	void StopSong();
	void SetMusicVolume(float NewVolume);
	void SeekStream(float Seconds);
	bool Seek(float SeekSeconds);
	void PlayStream(FString Filename, int32 SeekSeconds);
	float GetStreamPosition();
	float GetStreamVolume();
	float GetStreamDuration();
	bool IsPlaying();
	bool HasPlayer();
	void ClearSongInfo();
	void KillMusic();
	APlayerController* PC();
	void streamdebug(FString Command, FString Param);
};
