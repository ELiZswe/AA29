// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamPlaylistManager/StreamPlaylistManager.h"

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
	/*
	local array<String> PlaylistNames;
	local StreamPlaylist NewList;
	local int i;
	PlaylistNames = GetPerObjectNames("UPlaylists", "StreamPlaylist");
	for (i = 0; i < PlaylistNames.Length; i++)
	{
		if (PlaylistNames[i] == "")
		{
		}
		NewList = CreatePlaylist(PlaylistNames[i]);
		AppendPlaylist(NewList);
	}
	if (Playlists.Length == 0)
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
	/*
	local int i;
	local int j;
	local class<PlaylistParserBase>  ParseClass;
	for (i = 0; i < ParserType.Length; i++)
	{
		if (ParserType[i].ParserClass != "")
		{
			ParseClass = class<PlaylistParserBase>(DynamicLoadObject(ParserType[i].ParserClass, Class'Class'));
			if (ParseClass != None)
			{
				j = Parsers.Length;
				Parsers[j] = new (Self) classParseClass;
				Parsers[j].SetType(ParserType[i].Type);
			}
		}
	}
	*/
}
void UStreamPlaylistManager::CreateDefaultPlaylist()
{
	/*
	local int i;
	local string Nothing;
	Nothing = DefaultPlaylistName;
	i = AddPlaylist(Nothing);
	if (ValidIndex(i) && ActivatePlaylist(i))
	{
		Return Playlists[CurrentPlaylist];
	}
	return nullptr;
	*/
}
bool UStreamPlaylistManager::ActivatePlaylist(int32 ListIndex, bool bNoFail)
{
	/*
	if (!ValidIndex(ListIndex))
	{
		if (bNoFail)
		{
			Return False;
		}
		if (GetRepeatAll())
		{
			if (ListIndex < 0)
			{
				ListIndex = Playlists.Length - 1;
			}
			else
			{
				if (ListIndex >= Playlists.Length)
				{
					ListIndex = 0;
				}
			}
			if (!ValidIndex(ListIndex))
			{
				Return False;
			}
		}
		else
		{
			Return False;
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
void UStreamPlaylistManager::AddPlaylist(FString &NewPlaylistName)
{
	/*
	local string str;
	local int i;
	if (NewPlaylistName == "")
	{
		NewPlaylistName = DefaultPlaylistName;
	}
	str = NewPlaylistName;
	if (ValidName(NewPlaylistName))
	{
		NewPlaylistName = str $ i++;
	}
	Return AppendPlaylist(CreatePlaylist(NewPlaylistName));
	*/
}
int32 UStreamPlaylistManager::AppendPlaylist(UStreamPlaylist* Playlist)
{
	int i=0;
	if (Playlist == nullptr)
	{
		return - 1;
	}
	i = FindPlaylistIndex(Playlist);
	/*
	if (i == -1)
	{
		i = Playlists.Length;
	}
	*/
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
	/*
	local bool bWasActive;
	if (!ValidIndex(Index))
	{
		Return False;
	}
	bWasActive = CurrentPlaylist == Index;
	Playlists[Index].ClearConfig();
	Playlists.remove(Index, 1);
	if (bWasActive)
	{
		ActivatePlaylist(0);
	}
	*/
	return true;
}
bool UStreamPlaylistManager::RenamePlaylist(int32 Index, FString &NewName)
{
	/*
	local StreamPlaylist Temp;
	local string str;
	local int i;
	if (!ValidIndex(Index) || NewName == "")
	{
		Return False;
	}
	str = NewName;
	if (ValidName(NewName))
	{
		NewName = str $ i++;
	}
	Temp = CreatePlaylist(NewName);
	if (Temp == None)
	{
		Return False;
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
void UStreamPlaylistManager::AddToPlaylist(int32 PlaylistIndex, FString Path, bool bSkipNotification)
{
	/*
	if (!ValidIndex(PlaylistIndex))
	{
		if (!ValidIndex(CurrentPlaylist))
		{
			Return False;
		}
		PlaylistIndex = CurrentPlaylist;
	}
	Return InsertInPlaylist(PlaylistIndex, -1, Path, bSkipNotification);
	*/
}
void UStreamPlaylistManager::InsertInPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bSkipNotification)
{
	/*
	local StreamBase.EFileType Type;
	local bool bResult;
	if (!ValidIndex(PlaylistIndex))
	{
		Return False;
	}
	Type = ConvertToFileType(Path);
	Playlists[PlaylistIndex].InitializePlaylist(FileManager);
	Switch(Type)
	{
			case 0:
				bDisableNotification = true;
				bResult = AddDirectory(PlaylistIndex, InsertPosition, Path, True);
				bDisableNotification = False;
				if (bResult && !bSkipNotification)
				{
					Playlists[PlaylistIndex].OnPlaylistChanged();
				}
				Return bResult;
			case 5:
				bDisableNotification = true;
				bResult = ImportPlaylist(PlaylistIndex, InsertPosition, Path);
				bDisableNotification = False;
				if (bResult && !bSkipNotification)
				{
					Playlists[PlaylistIndex].OnPlaylistChanged();
				}
				Return bResult;
			case 4:
				Return Playlists[PlaylistIndex].InsertSong(InsertPosition, Path, bDisableNotification || bSkipNotification) != -1;
			default:
				Return False;
	}
	*/
}
bool UStreamPlaylistManager::RemoveFromCurrentPlaylist(FString Path, bool bSkipNotification)
{
	/*
	if (ValidIndex(CurrentPlaylist))
	{
		Return Playlists[CurrentPlaylist].RemoveSong(Path, bSkipNotification);
	}
	*/
	return false;
}
void UStreamPlaylistManager::ClearCurrentPlaylist()
{
	/*
	if (!ValidIndex(CurrentPlaylist))
	{
		Return False;
	}
	Return Playlists[CurrentPlaylist].ClearPlaylist();
	*/
}
void UStreamPlaylistManager::GetPlaylistType(FString Path)
{
	/*
	local string Ext;
	Ext = ParseExtension(Path);
	Switch(Locs(Ext))
	{
			case "m3u":
				Return 1;
			case "b4s":
				Return 3;
			case "pls":
				Return 2;
			default:
				Return 0;
	}
	*/
}
bool UStreamPlaylistManager::AddDirectory(int32 PlaylistIndex, int32 InsertPosition, FString Path, bool bRecurseDirectories)
{
	bool bValue=false;
	/*
	local int i;
	local array<String> Results;
	if (bRecurseDirectories)
	{
		if (FileManager.GetDirectoryContents(Results, Path, 1))
		{
			for (i = Results.Length - 1; i >= 0; i--)
			{
				bValue = AddDirectory(PlaylistIndex, InsertPosition, Path $ Results[i] $ GetPathSeparator(), True) || bValue;
			}
		}
	}
	Results.remove(0, Results.Length);
	if (FileManager.GetDirectoryContents(Results, Path, 4))
	{
		if (!Playlists[PlaylistIndex].ValidStreamIndex(InsertPosition))
		{
			InsertPosition = Playlists[PlaylistIndex].GetPlaylistLength();
		}
		for (i = Results.Length - 1; i >= 0; i--)
		{
			bValue = Playlists[PlaylistIndex].InsertSong(InsertPosition, Path $ Results[i], bDisableNotification) != -1 || bValue;
		}
	}
	*/
	return bValue;
}
bool UStreamPlaylistManager::ImportPlaylist(int32 PlaylistIndex, int32 InsertPosition, FString Path)
{
	/*
	local int i;
	local StreamBase.EStreamPlaylistType Type;
	Type = GetPlaylistType(Path);
	for (i = 0; i < Parsers.Length; i++)
	{
		if (Parsers[i].GetType() == Type)
		{
			Return Parsers[i].Import(PlaylistIndex, InsertPosition, Path);
		}
	}
	*/
	return false;
}
FString UStreamPlaylistManager::NextSong(bool bForce)
{
	/*
	local StreamPlaylist List;
	local Stream S;
	local string str;
	if (GetShuffleAll() || GetShuffle())
	{
		Return GetRandomSong();
	}
	List = GetCurrentPlaylist();
	if (List == None)
	{
		Log("PlaylistManager.NextSong() - no playlists found!", 'MusicPlayer');
		Return "";
	}
	if (GetRepeat())
	{
		S = List.GetCurrentStream();
		if (S != None)
		{
			Return S.GetPath();
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
			Return str;
		}
	}
	*/
	return "";
}
FString UStreamPlaylistManager::PrevSong(bool bForce)
{
	/*
	local StreamPlaylist List;
	local Stream S;
	local string str;
	if (GetShuffleAll() || GetShuffle())
	{
		Return GetRandomSong();
	}
	List = GetCurrentPlaylist();
	if (List == None)
	{
		Log("PlaylistManager.PrevSong() - no playlists found!", 'MusicPlayer');
		Return "";
	}
	if (GetRepeat())
	{
		S = List.GetCurrentStream();
		if (S != None)
		{
			Return S.GetPath();
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
			Return str;
		}
	}
	*/
	return "";
}
FString UStreamPlaylistManager::GetRandomSong()
{
	/*
	local StreamPlaylist List;
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
	if (List != None)
	{
		Return List.GetRandomSong();
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
void UStreamPlaylistManager::GetCurrentPlaylist()
{
	/*
	if (ValidIndex(CurrentPlaylist))
	{
		Return Playlists[CurrentPlaylist];
	}
	if (ActivatePlaylist(0))
	{
		Return Playlists[0];
	}
	Return CreateDefaultPlaylist();
	*/
}
void UStreamPlaylistManager::GetRandomPlaylist()
{
	/*
	local int i;
	local int idx;
	if (Playlists.Length == 0)
	{
		Return None;
	}
	idx = Rand(Playlists.Length - 1);
	if (++i < 10)
	{
		if (ActivatePlaylist(idx))
		{
			Return Playlists[CurrentPlaylist];
		}
		idx = Rand(Playlists.Length - 1);
	}
	Return None;
	*/
}
void UStreamPlaylistManager::GetPlaylistAt(int32 idx)
{
	/*
	if (!ValidIndex(idx))
	{
		Return None;
	}
	Return Playlists[idx];
	*/
}
void UStreamPlaylistManager::GetPlaylistCount()
{
	//Return Playlists.Length;
}
void UStreamPlaylistManager::ValidIndex(int32 Index)
{
	//return Index >= 0 && Index < Playlists.Length;
}
int32 UStreamPlaylistManager::FindNameIndex(FString PlaylistName)
{
	/*
	local int i;
	if (PlaylistName == "")
	{
		Return - 1;
	}
	for (i = 0; i < Playlists.Length; i++)
	{
		if (Playlists[i].GetTitle() ~= PlaylistName)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
int32 UStreamPlaylistManager::FindPlaylistIndex(UStreamPlaylist* Playlist)
{
	/*
	local int i;
	if (Playlist == None)
	{
		Return - 1;
	}
	for (i = 0; i < Playlists.Length; i++)
	{
		if (Playlists[i] == Playlist)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
bool UStreamPlaylistManager::ValidName(FString Test)
{
	/*
	local int i;
	for (i = 0; i < Playlists.Length; i++)
	{
		if (Test ~= Playlists[i].GetTitle())
		{
			Return True;
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
		SetRepeatAll(False);
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
		SetRepeat(False);
	}
	*/
}
UStreamPlaylist* UStreamPlaylistManager::CreatePlaylist(FString PlaylistName)
{
	UStreamPlaylist* List=nullptr;
	/*
	
	if (PlaylistName == "")
	{
		Return None;
	}
	List = new (NoneRepl(PlaylistName, " ", Chr(27))) class'StreamPlaylist';
	if (List != None)
	{
		List.SetTitle(Repl(PlaylistName, Chr(27), " "));
		List.Save();
	}
	*/
	return List;
}
void UStreamPlaylistManager::HandleDebugExec(FString Command, FString Param)
{
	/*
	local int i;
	local bool Result;
	if (HandleDebugExec(Command, Param))
	{
		Return True;
	}
	Switch(Locs(Command))
	{
	case "activate":
		if (Playlists.Length > 0)
		{
			ActivatePlaylist(0);
			break;
		}
		ActivatePlaylist(Param);
	}
	Log("Active Playlist:" $ Playlists[CurrentPlaylist].GetTitle() @ "Tracks:" $ Playlists[CurrentPlaylist].GetPlaylistLength(), 'MusicPlayer');
	GOTO JL0134;
	case "lists":
		Log(" === All existing playlists === ", 'MusicPlayer');
		for (i = 0; i < Playlists.Length; i++)
		{
			Log(" Playlist" @ i @ " '" $ Playlists[i].GetTitle(), 'MusicPlayer');
		}
	default:
	JL0134:
		for (i = 0; i < Playlists.Length; i++)
		{
			Result = Playlists[i].HandleDebugExec(Command, Param) || Result;
		}
		Return Result;
	*/
}
void UStreamPlaylistManager::Save()
{
	/*
	local int i;
	for (i = 0; i < Playlists.Length; i++)
	{
		Playlists[i].Save();
	}
	if (!bDirty)
	{
		Return;
	}
	SaveConfig();
	bDirty = False;
	*/
}
void UStreamPlaylistManager::GetCurrentTitle()
{
	//Return Playlists[GetCurrentIndex()].GetTitle();
}
