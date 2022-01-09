// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "StreamPlaylist.generated.h"

class UStreamInterface;
class UStream;

UCLASS(Config = Game)
class UStreamPlaylist : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamPlaylist();

	UPROPERTY(EditAnywhere)									TArray<UStream*>	Songs;			//var() editconstarray editconst array<Stream> Songs;
	UPROPERTY(EditAnywhere)									UStreamInterface*	FileManager;	//var() editconst StreamInterface FileManager;
	UPROPERTY(EditAnywhere)									TArray<int32>		RandomPool;		//var() editconstarray transient editconst array<int> RandomPool;
	UPROPERTY(EditAnywhere, Config)							bool				bNeedSave;		//var() config bool bNeedSave;
	UPROPERTY(EditAnywhere)									FString				Title;			//var() string Title;
	UPROPERTY(EditAnywhere, Config)							TArray<FString>		Playlist;		//var() config array<String> Playlist;
	UPROPERTY(EditAnywhere, Config)							int32				Current;		//var() config int Current;

	void OnPlaylistChanged();
	bool InitializePlaylist(UStreamInterface* InManager);
	bool LoadPlaylist();
	UStream* CreateStream(FString Filename);
	int32 AddSong(FString SongFileName, bool bSkipNotification);
	int32 AddStream(int32 Index, UStream* NewStream, bool bSkipNotification);
	int32 InsertSong(int32 idx, FString Path, bool bSkipNotification);
	bool RemoveSong(FString SongFileName, bool bSkipNotification);
	bool RemoveSongAt(int32 idx, bool bSkipNotification);
	FString NextSong(bool bMayRepeat);
	FString PrevSong(bool bMayRepeat);
	void ReplaceWith(UStreamPlaylist* Other);
	bool ClearPlaylist();
	FString GetRandomSong();
	void ResetRandomPool();
	bool SetTitle(FString NewTitle);
	bool SetCurrent(int32 Index);
	bool SetSongs(TArray<UStream*> NewSongs);
	bool IsInitialized();
	FString GetTitle();
	int32 GetCurrent();
	void GetSongs(TArray<UStream*>& SongArray);
	UStream* GetCurrentStream();
	UStream* GetStream(FString StreamName);
	UStream* GetStreamAt(int32 Index);
	int32 GetPlaylistLength();
	int32 FindIndexByName(FString Test);
	int32 FindIndexByPath(FString Test);
	int32 FindIndexByFullName(FString Test);
	int32 FindIndexByFileName(FString Test);
	bool ValidStreamName(FString Filename);
	bool ValidStreamIndex(int32 Index);
	void DebugInfo();
	bool HandleDebugExec(FString Command, FString Param);
	void Save();
};
