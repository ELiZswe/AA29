// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "StreamPlaylistManager.generated.h"

class UStreamPlaylist;
class UStreamInterface;
//class UPlaylistParserBase;
//class UPlaylistParser;

UCLASS(Config = Game)
class AA29_API UStreamPlaylistManager : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamPlaylistManager();



	//UPROPERTY()									TArray<UPlaylistParserBase*> Parsers;						//var() editconstarray editconst array<PlaylistParserBase> Parsers;
	//UPROPERTY()									TArray<UPlaylistParser*> ParserType;						//var() config array<PlaylistParser> ParserType;
	UPROPERTY()									FString DefaultPlaylistName;								//var() localized string DefaultPlaylistName;
	UPROPERTY()									bool bRepeatAll;											//var() config bool bRepeatAll;
	UPROPERTY()									bool bRepeat;												//var() config bool bRepeat;
	UPROPERTY()									bool bShuffleAll;											//var() config bool bShuffleAll;
	UPROPERTY()									bool bShuffle;												//var() config bool bShuffle;
	UPROPERTY()									bool bDirty;												//var() transient bool bDirty;
	UPROPERTY()									bool bDisableNotification;									//var() bool bDisableNotification;
	UPROPERTY()									TArray<UStreamPlaylist*> Playlists;							//var() editconstarray array<StreamPlaylist> Playlists;
	UPROPERTY()									UStreamInterface* FileManager;								//var() editconst StreamInterface FileManager;
	UPROPERTY()									int32 CurrentPlaylist;										//var() config editconst int CurrentPlaylist;


	void ChangedActivePlaylist(UStreamPlaylist* NewPlaylist);
	void Initialize(UStreamInterface* InFileManager);
	void InitializePlaylists();
	void InitializeParsers();
	void CreateDefaultPlaylist();
	bool ActivatePlaylist(int32 ListIndex, bool bNoFail);
	void AddPlaylist(FString& NewPlaylistName);
	int32 AppendPlaylist(UStreamPlaylist* Playlist);
	bool RemovePlaylist(FString PlaylistName);
	bool RemovePlaylistAt(int32 Index);
	bool RenamePlaylist(int32 Index, FString& NewName);
	void AddToPlaylist(int32 PlaylistIndex, FString Path, bool bSkipNotification);
	void InsertInPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bSkipNotification);
	bool RemoveFromCurrentPlaylist(FString Path, bool bSkipNotification);
	void ClearCurrentPlaylist();
	void GetPlaylistType(FString Path);
	bool AddDirectory(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bRecurseDirectories);
	bool ImportPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path);
	FString NextSong(bool bForce);
	FString PrevSong(bool bForce);
	FString GetRandomSong();
	int32 GetCurrentIndex();
	void GetCurrentPlaylist();
	void GetRandomPlaylist();
	void GetPlaylistAt(int32 idx);
	void GetPlaylistCount();
	void ValidIndex(int32 Index);
	int32 FindNameIndex(FString PlaylistName);
	int32 FindPlaylistIndex(UStreamPlaylist* Playlist);
	bool ValidName(FString Test);
	bool GetShuffle();
	bool GetShuffleAll();
	bool GetRepeat();
	bool GetRepeatAll();
	void SetShuffle(bool bEnable);
	void SetShuffleAll(bool bEnable);
	void SetRepeat(bool bEnable);
	void SetRepeatAll(bool bEnable);
	UStreamPlaylist* CreatePlaylist(FString PlaylistName);
	void HandleDebugExec(FString Command, FString Param);
	void Save();
	void GetCurrentTitle();

};
