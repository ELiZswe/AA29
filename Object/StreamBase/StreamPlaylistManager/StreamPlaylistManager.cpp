// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamPlaylistManager/StreamPlaylistManager.h"
#include "AA29/Object/StreamBase/StreamPlaylist/StreamPlaylist.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/StreamInterface/PlaylistParserBase/PlaylistParserBase.h"
#include "AA29/Object/StreamBase/Stream/Stream.h"

UStreamPlaylistManager::UStreamPlaylistManager()
{
	bRepeatAll = true;
	DefaultPlaylistName = "New Playlist";
	//ParserType(0) = (Type = 3, ParserClass = "Engine.B4SParser");
	//ParserType(1) = (Type = 1, ParserClass = "Engine.M3UParser");
	//ParserType(2) = (Type = 2, ParserClass = "Engine.PLSParser");

}

void UStreamPlaylistManager::ChangedActivePlaylist(UStreamPlaylist* NewPlaylist)
{
}

void UStreamPlaylistManager::Initialize(UStreamInterface* InFileManager)
{
	FileManager = InFileManager;
	InitializePlaylists();
	InitializeParsers();
}

void UStreamPlaylistManager::InitializePlaylists()
{
	TArray<FString> PlaylistNames = {};
	UStreamPlaylist* NewList = nullptr;
	int32 i = 0;
	/*
	PlaylistNames = GetPerObjectNames("UPlaylists", "StreamPlaylist");
	for (i = 0; i < PlaylistNames.Num(); i++)
	{
		if (PlaylistNames[i] == "")
		{
		}
		NewList = CreatePlaylist(PlaylistNames[i]);
		AppendPlaylist(NewList);
	}
	if (Playlists.Num() == 0)
	{
		CreateDefaultPlaylist();
	}
	else
	{
		if (!ActivatePlaylist(CurrentPlaylist))
		{
			ActivatePlaylist(0);
		}
	}
	*/
}

void UStreamPlaylistManager::InitializeParsers()
{
	int32 i = 0;
	int32 j = 0;
	UPlaylistParserBase* ParseClass = nullptr;
	/*
	for (i = 0; i < ParserType.Num(); i++)
	{
		if (ParserType[i].ParserClass != "")
		{
			ParseClass = class<PlaylistParserBase>(DynamicLoadObject(ParserType[i].ParserClass, Class'Class'));
			if (ParseClass != nullptr)
			{
				j = Parsers.Num();
				Parsers[j] = new (this) classParseClass;
				Parsers[j].SetType(ParserType[i].Type);
			}
		}
	}
	*/
}

UStreamPlaylist* UStreamPlaylistManager::CreateDefaultPlaylist()
{
	int32 i = 0;
	FString Nothing = "";
	Nothing = DefaultPlaylistName;
	i = AddPlaylist(Nothing);
	if (ValidIndex(i) && ActivatePlaylist(i,false))
	{
		return Playlists[CurrentPlaylist];
	}
	return nullptr;
}

bool UStreamPlaylistManager::ActivatePlaylist(int32 ListIndex, bool bNoFail)
{
	/*
	if (!ValidIndex(ListIndex))
	{
		if (bNoFail)
		{
			return false;
		}
		if (GetRepeatAll())
		{
			if (ListIndex < 0)
			{
				ListIndex = Playlists.Num() - 1;
			}
			else
			{
				if (ListIndex >= Playlists.Num())
				{
					ListIndex = 0;
				}
			}
			if (!ValidIndex(ListIndex))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bDirty = bDirty || ListIndex != CurrentPlaylist;
	Playlists[ListIndex].InitializePlaylist(FileManager);
	CurrentPlaylist = ListIndex;
	if (!bDisableNotification)
	{
		ChangedActivePlaylist(Playlists[ListIndex]);
	}
	*/
	return true;
}

int32 UStreamPlaylistManager::AddPlaylist(FString &NewPlaylistName)
{
	/*
	FString str;
	int32 i = 0;
	if (NewPlaylistName == "")
	{
		NewPlaylistName = DefaultPlaylistName;
	}
	str = NewPlaylistName;
	if (ValidName(NewPlaylistName))
	{
		NewPlaylistName = str + i++;
	}
	return AppendPlaylist(CreatePlaylist(NewPlaylistName));
	*/
	return 0;    //FAKE   /EliZ
}

int32 UStreamPlaylistManager::AppendPlaylist(UStreamPlaylist* Playlist)
{
	int i=0;
	if (Playlist == nullptr)
	{
		return - 1;
	}
	i = FindPlaylistIndex(Playlist);
	if (i == -1)
	{
		Playlists.Add(Playlist);
		i = Playlists.Num();
	}
	Playlists[i] = Playlist;
	bDirty = true;
	return i;
}

bool UStreamPlaylistManager::RemovePlaylist(FString PlaylistName)
{
	int32 i=0;
	i = FindNameIndex(PlaylistName);
	if (i != -1)
	{
		return RemovePlaylistAt(i);
	}
	return false;
}

bool UStreamPlaylistManager::RemovePlaylistAt(int32 Index)
{
	bool bWasActive = false;
	/*
	if (!ValidIndex(Index))
	{
		return false;
	}
	bWasActive = CurrentPlaylist == Index;
	Playlists[Index].ClearConfig();
	Playlists.RemoveAt(Index, 1);
	if (bWasActive)
	{
		ActivatePlaylist(0);
	}
	*/
	return true;
}

bool UStreamPlaylistManager::RenamePlaylist(int32 Index, FString &NewName)
{
	UStreamPlaylist* Temp = nullptr;
	FString str;
	int32 i = 0;
	/*
	if (!ValidIndex(Index) || NewName == "")
	{
		return false;
	}
	str = NewName;
	if (ValidName(NewName))
	{
		NewName = str + i++;
	}
	Temp = CreatePlaylist(NewName);
	if (Temp == nullptr)
	{
		return false;
	}
	Temp.ReplaceWith(Playlists[Index]);
	Playlists[Index].ClearConfig();
	Playlists[Index] = Temp;
	Playlists[Index].Save();
	if (!bDisableNotification)
	{
		ChangedActivePlaylist(Playlists[Index]);
	}
	*/
	return true;
}

bool UStreamPlaylistManager::AddToPlaylist(int32 PlaylistIndex, FString Path, bool bSkipNotification)
{
	/*
	if (!ValidIndex(PlaylistIndex))
	{
		if (!ValidIndex(CurrentPlaylist))
		{
			return false;
		}
		PlaylistIndex = CurrentPlaylist;
	}
	return InsertInPlaylist(PlaylistIndex, -1, Path, bSkipNotification);
	*/
	return false;    //FAKE   /ELiZ
}

bool UStreamPlaylistManager::InsertInPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bSkipNotification)
{
	EFileType Type = EFileType::FILE_None;
	bool bResult = false;
	/*
	if (!ValidIndex(PlaylistIndex))
	{
		return false;
	}
	Type = ConvertToFileType(Path);
	Playlists[PlaylistIndex].InitializePlaylist(FileManager);
	switch(Type)
	{
		case 0:
			bDisableNotification = true;
			bResult = AddDirectory(PlaylistIndex, InsertPosition, Path, true);
			bDisableNotification = false;
			if (bResult && !bSkipNotification)
			{
				Playlists[PlaylistIndex].OnPlaylistChanged();
			}
			return bResult;
		case 5:
			bDisableNotification = true;
			bResult = ImportPlaylist(PlaylistIndex, InsertPosition, Path);
			bDisableNotification = false;
			if (bResult && !bSkipNotification)
			{
				Playlists[PlaylistIndex].OnPlaylistChanged();
			}
			return bResult;
		case 4:
			return Playlists[PlaylistIndex].InsertSong(InsertPosition, Path, bDisableNotification || bSkipNotification) != -1;
		default:
			return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UStreamPlaylistManager::RemoveFromCurrentPlaylist(FString Path, bool bSkipNotification)
{
	/*
	if (ValidIndex(CurrentPlaylist))
	{
		return Playlists[CurrentPlaylist].RemoveSong(Path, bSkipNotification);
	}
	*/
	return false;
}

bool UStreamPlaylistManager::ClearCurrentPlaylist()
{
	/*
	if (!ValidIndex(CurrentPlaylist))
	{
		return false;
	}
	return Playlists[CurrentPlaylist].ClearPlaylist();
	*/
	return false;    //FAKE   /ELiZ
}

uint8 UStreamPlaylistManager::GetPlaylistType(FString Path)
{
	/*
	FString Ext;
	Ext = ParseExtension(Path);
	switch(Locs(Ext))
	{
			case "m3u":
				return 1;
			case "b4s":
				return 3;
			case "pls":
				return 2;
			default:
				return 0;
	}
	*/
	return 0;    //FAKE   /ELiZ
}

bool UStreamPlaylistManager::AddDirectory(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bRecurseDirectories)
{
	bool bValue=false;
	int32 i = 0;
	TArray<FString> Results = {};
	/*
	if (bRecurseDirectories)
	{
		if (FileManager.GetDirectoryContents(Results, Path, 1))
		{
			for (i = Results.Num() - 1; i >= 0; i--)
			{
				bValue = AddDirectory(PlaylistIndex, InsertPosition, Path + Results[i] + GetPathSeparator(), True) || bValue;
			}
		}
	}
	Results.RemoveAt(0, Results.Num());
	if (FileManager.GetDirectoryContents(Results, Path, 4))
	{
		if (!Playlists[PlaylistIndex].ValidStreamIndex(InsertPosition))
		{
			InsertPosition = Playlists[PlaylistIndex].GetPlaylistLength();
		}
		for (i = Results.Num() - 1; i >= 0; i--)
		{
			bValue = Playlists[PlaylistIndex].InsertSong(InsertPosition, Path + Results[i], bDisableNotification) != -1 || bValue;
		}
	}
	*/
	return bValue;
}
bool UStreamPlaylistManager::ImportPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path)
{
	int32 i = 0;
	EStreamPlaylistType Type = EStreamPlaylistType::SPT_None;
	/*
	Type = GetPlaylistType(Path);
	for (i = 0; i < Parsers.Num(); i++)
	{
		if (Parsers[i].GetType() == Type)
		{
			return Parsers[i].Import(PlaylistIndex, InsertPosition, Path);
		}
	}
	*/
	return false;
}

FString UStreamPlaylistManager::NextSong(bool bForce)
{
	UStreamPlaylist* List = nullptr;
	UStream* S = nullptr;
	FString str = "";
	/*
	if (GetShuffleAll() || GetShuffle())
	{
		return GetRandomSong();
	}
	List = GetCurrentPlaylist();
	if (List == nullptr)
	{
		Log("PlaylistManager.NextSong() - no playlists found!", 'MusicPlayer');
		return "";
	}
	if (GetRepeat())
	{
		S = List.GetCurrentStream();
		if (S != nullptr)
		{
			return S.GetPath();
		}
	}
	else
	{
		str = List.NextSong(bForce || GetRepeat());
		if (str == "" && GetRepeatAll() && ActivatePlaylist(CurrentPlaylist + 1))
		{
			str = Playlists[CurrentPlaylist].NextSong(bForce);
		}
		if (str != "")
		{
			return str;
		}
	}
	*/
	return "";
}

FString UStreamPlaylistManager::PrevSong(bool bForce)
{
	UStreamPlaylist* List = nullptr;
	UStream* S = nullptr;
	FString str = "";
	/*
	if (GetShuffleAll() || GetShuffle())
	{
		return GetRandomSong();
	}
	List = GetCurrentPlaylist();
	if (List == nullptr)
	{
		Log("PlaylistManager.PrevSong() - no playlists found!", 'MusicPlayer');
		return "";
	}
	if (GetRepeat())
	{
		S = List.GetCurrentStream();
		if (S != nullptr)
		{
			return S.GetPath();
		}
	}
	else
	{
		str = List.PrevSong(bForce || GetRepeat());
		if (str == "" && GetRepeatAll() && ActivatePlaylist(CurrentPlaylist - 1))
		{
			str = Playlists[CurrentPlaylist].PrevSong(bForce);
		}
		if (str != "")
		{
			return str;
		}
	}
	*/
	return "";
}

FString UStreamPlaylistManager::GetRandomSong()
{
	UStreamPlaylist* List = nullptr;
	/*
	if (GetShuffle())
	{
		List = GetCurrentPlaylist();
	}
	else
	{
		if (GetShuffleAll())
		{
			List = GetRandomPlaylist();
		}
	}
	if (List != nullptr)
	{
		return List.GetRandomSong();
	}
	*/
	return "";
}

int32 UStreamPlaylistManager::GetCurrentIndex()
{
	/*
	if (ValidIndex(CurrentPlaylist))
	{
		return CurrentPlaylist;
	}
	*/
	return - 1;
}

UStreamPlaylist* UStreamPlaylistManager::GetCurrentPlaylist()
{
	/*
	if (ValidIndex(CurrentPlaylist))
	{
		return Playlists[CurrentPlaylist];
	}
	if (ActivatePlaylist(0))
	{
		return Playlists[0];
	}
	return CreateDefaultPlaylist();
	*/
	return nullptr;    //FAKE  ELiZ
}

UStreamPlaylist* UStreamPlaylistManager::GetRandomPlaylist()
{
	/*
	int32 i = 0;
	int32 idx;
	if (Playlists.Num() == 0)
	{
		return nullptr;
	}
	idx = Rand(Playlists.Num() - 1);
	if (++i < 10)
	{
		if (ActivatePlaylist(idx))
		{
			return Playlists[CurrentPlaylist];
		}
		idx = Rand(Playlists.Num() - 1);
	}
	*/
	return nullptr;
}

UStreamPlaylist* UStreamPlaylistManager::GetPlaylistAt(int32 idx)
{
	/*
	if (!ValidIndex(idx))
	{
		return nullptr;
	}
	return Playlists[idx];
	*/
	return nullptr;    //FAKE  ELiZ
}
int32 UStreamPlaylistManager::GetPlaylistCount()
{
	//return Playlists.Num();
	return 0;    //FAKE  ELiZ
}

bool UStreamPlaylistManager::ValidIndex(int32 Index)
{
	return Index >= 0 && Index < Playlists.Num();
}

int32 UStreamPlaylistManager::FindNameIndex(FString PlaylistName)
{
	/*
	int32 i = 0;
	if (PlaylistName == "")
	{
		return - 1;
	}
	for (i = 0; i < Playlists.Num(); i++)
	{
		if (Playlists[i].GetTitle() ~= PlaylistName)
		{
			return i;
		}
	}
	*/
	return - 1;
}
int32 UStreamPlaylistManager::FindPlaylistIndex(UStreamPlaylist* Playlist)
{
	/*
	int32 i = 0;
	if (Playlist == nullptr)
	{
		return - 1;
	}
	for (i = 0; i < Playlists.Num(); i++)
	{
		if (Playlists[i] == Playlist)
		{
			return i;
		}
	}
	*/
	return - 1;
}
bool UStreamPlaylistManager::ValidName(FString Test)
{
	/*
	int32 i = 0;
	for (i = 0; i < Playlists.Num(); i++)
	{
		if (Test ~= Playlists[i].GetTitle())
		{
			return true;
		}
	}
	*/
	return false;
}
bool UStreamPlaylistManager::GetShuffle()
{
	return bShuffle;
}
bool UStreamPlaylistManager::GetShuffleAll()
{
	return bShuffleAll;
}
bool UStreamPlaylistManager::GetRepeat()
{
	return bRepeat;
}
bool UStreamPlaylistManager::GetRepeatAll()
{
	return bRepeatAll;
}
void UStreamPlaylistManager::SetShuffle(bool bEnable)
{
	bDirty = bDirty || bEnable != bShuffle;
	bShuffle = bEnable;
	if (bEnable && bShuffleAll)
	{
		SetShuffleAll(false);
	}
}
void UStreamPlaylistManager::SetShuffleAll(bool bEnable)
{
	bDirty = bDirty || bEnable != bShuffleAll;
	bShuffleAll = bEnable;
	if (bEnable && bShuffle)
	{
		SetShuffle(false);
	}
}
void UStreamPlaylistManager::SetRepeat(bool bEnable)
{
	/*
	bDirty = bDirty || bEnable != bRepeat;
	bRepeat = bEnable;
	if (bEnable && bRepeatAll)
	{
		SetRepeatAll(false);
	}
	*/
}
void UStreamPlaylistManager::SetRepeatAll(bool bEnable)
{
	/*
	bDirty = bDirty || bEnable != bRepeatAll;
	bRepeatAll = bEnable;
	if (bEnable && bRepeat)
	{
		SetRepeat(false);
	}
	*/
}
UStreamPlaylist* UStreamPlaylistManager::CreatePlaylist(FString PlaylistName)
{
	UStreamPlaylist* List=nullptr;
	/*
	
	if (PlaylistName == "")
	{
		return nullptr;
	}
	List = new (NoneRepl(PlaylistName, " ", Chr(27))) UStreamPlaylist::StaticClass();
	if (List != nullptr)
	{
		List.SetTitle(Repl(PlaylistName, Chr(27), " "));
		List.Save();
	}
	*/
	return List;
}

bool UStreamPlaylistManager::HandleDebugExec(FString Command, FString Param)
{
	int32 i = 0;
	bool Result = false;
	/*
	if (HandleDebugExec(Command, Param))
	{
		return true;
	}
	switch(Locs(Command))
	{
	case "activate":
		if (Playlists.Num() > 0)
		{
			ActivatePlaylist(0);
			break;
		}
		ActivatePlaylist(Param);
	}
	Log("Active Playlist:" + Playlists[CurrentPlaylist].GetTitle() @ "Tracks:" + Playlists[CurrentPlaylist].GetPlaylistLength(), 'MusicPlayer');
	GOTO JL0134;
	case "lists":
		Log(" === All existing playlists === ", 'MusicPlayer');
		for (i = 0; i < Playlists.Num(); i++)
		{
			Log(" Playlist" @ i @ " '" + Playlists[i].GetTitle(), 'MusicPlayer');
		}
	default:
	JL0134:
		for (i = 0; i < Playlists.Num(); i++)
		{
			Result = Playlists[i].HandleDebugExec(Command, Param) || Result;
		}
		return Result;
	*/
	return false;    //FAKE   /EliZ
}

void UStreamPlaylistManager::Save()
{
	/*
	int32 i = 0;
	for (i = 0; i < Playlists.Num(); i++)
	{
		Playlists[i].Save();
	}
	if (!bDirty)
	{
		return;
	}
	SaveConfig();
	bDirty = false;
	*/
}

FString UStreamPlaylistManager::GetCurrentTitle()
{
	return Playlists[GetCurrentIndex()]->GetTitle();
}
