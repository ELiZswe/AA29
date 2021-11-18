// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamPlaylist/StreamPlaylist.h"

UStreamPlaylist::UStreamPlaylist()
{
	bNeedSave = true;
}

void UStreamPlaylist::OnPlaylistChanged()
{
}

bool UStreamPlaylist::InitializePlaylist(UStreamInterface* InManager)
{
	if (InManager == nullptr || IsInitialized())
	{
		return false;
	}
	FileManager = InManager;
	LoadPlaylist();
	return true;
}
bool UStreamPlaylist::LoadPlaylist()
{
	/*
	local int i;
	ClearPlaylist();
	for (i = 0; i < Playlist.Length; i++)
	{
		if (!FileManager.ValidFile(Playlist[i]))
		{
			Log("Removing file from playlist '" $ GetTitle() $ "' - file not found", 'MusicPlayer');
			Playlist.remove(i--, 1);
		}
		else
		{
			AddSong(Playlist[i]);
		}
	}
	ResetRandomPool();
	bNeedSave = false;
	*/
	return true;
}
void UStreamPlaylist::CreateStream(FString Filename)
{
	/*
	if (Filename == "")
	{
		return nullptr;
	}
	Return FileManager.CreateStream(Filename);
	*/
}
void UStreamPlaylist::AddSong(FString SongFileName, bool bSkipNotification)
{
	/*
	local Stream NewStream;
	local StreamBase.EFileType Type;
	local int i;
	if (SongFileName == "")
	{
		Return - 1;
	}
	Type = ConvertToFileType(SongFileName);
	if (Type == 4)
	{
		NewStream = CreateStream(SongFileName);
		if (NewStream == None)
		{
			Return - 1;
		}
		i = AddStream(GetPlaylistLength(), NewStream, bSkipNotification);
		bNeedSave = bNeedSave || ValidStreamIndex(i);
		Return i;
	}
	Return - 1;
	*/
}
void UStreamPlaylist::AddStream(int32 Index, UStream* NewStream, bool bSkipNotification)
{
	/*
	local int i;
	local string str;
	if (NewStream == None)
	{
		Return - 1;
	}
	str = NewStream.GetFileName();
	if (str == "")
	{
		Return - 1;
	}
	i = FindIndexByName(str);
	if (!ValidStreamIndex(i))
	{
		if (!ValidStreamIndex(Index))
		{
			Index = GetPlaylistLength();
		}
		Songs.insert(Index, 1);
		Songs[Index] = NewStream;
		RandomPool[RandomPool.Length] = Index;
		if (!bSkipNotification)
		{
			OnPlaylistChanged();
		}
		Return Index;
	}
	Return i;
	*/
}
void UStreamPlaylist::InsertSong(int32 idx, FString Path, bool bSkipNotification)
{
	/*
	local Stream NewStream;
	local StreamBase.EFileType Type;
	local int i;
	if (!ValidStreamIndex(idx))
	{
		Return AddSong(Path, bSkipNotification);
	}
	if (Path == "")
	{
		Return - 1;
	}
	Type = ConvertToFileType(Path);
	if (Type == 4)
	{
		NewStream = CreateStream(Path);
		if (NewStream == None)
		{
			Return - 1;
		}
		i = AddStream(idx, NewStream, bSkipNotification);
		bNeedSave = bNeedSave || ValidStreamIndex(i);
		Return i;
	}
	Return - 1;
	*/
}
void UStreamPlaylist::RemoveSong(FString SongFileName, bool bSkipNotification)
{
	//Return RemoveSongAt(FindIndexByName(SongFileName), bSkipNotification);
}
bool UStreamPlaylist::RemoveSongAt(int32 idx, bool bSkipNotification)
{
	/*
	local int i;
	if (!ValidStreamIndex(idx))
	{
		Return False;
	}
	Songs.remove(idx, 1);
	i = 0;
	if (i < RandomPool.Length)
	{
		if (RandomPool[i] == Songs.Length)
		{
			RandomPool.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	if (idx == Current && !SetCurrent(idx - 1))
	{
		SetCurrent(0);
	}
	bNeedSave = true;
	if (!bSkipNotification)
	{
		OnPlaylistChanged();
	}
	*/
	return true;
}
FString UStreamPlaylist::NextSong(bool bMayRepeat)
{
	/*
	local int i;
	i = GetCurrent() + 1;
	if (!ValidStreamIndex(i) && bMayRepeat)
	{
		i = 0;
	}
	if (SetCurrent(i))
	{
		Return Songs[Current].GetPath();
	}
	*/
	return "";
}
FString UStreamPlaylist::PrevSong(bool bMayRepeat)
{
	/*
	local int i;
	i = GetCurrent() - 1;
	if (!ValidStreamIndex(i) && bMayRepeat)
	{
		i = GetPlaylistLength() - 1;
	}
	if (SetCurrent(i))
	{
		Return Songs[Current].GetPath();
	}
	*/
	return "";
}
void UStreamPlaylist::ReplaceWith(UStreamPlaylist* Other)
{
	/*
	if (Other == None)
	{
		Return;
	}
	FileManager = Other.FileManager;
	Other.GetSongs(Songs);
	ResetRandomPool();
	SetCurrent(Other.GetCurrent());
	*/
	bNeedSave = true;
}
bool UStreamPlaylist::ClearPlaylist()
{
	/*
	bNeedSave = bNeedSave || Songs.Length > 0;
	Songs.remove(0, Songs.Length);
	RandomPool.remove(0, RandomPool.Length);
	*/
	return true;
}
FString UStreamPlaylist::GetRandomSong()
{
	/*
	local int idx;
	local Stream RandomStream;
	if (RandomPool.Length == 0)
	{
		ResetRandomPool();
	}
	if (RandomPool.Length > 0)
	{
		idx = Rand(RandomPool.Length - 1);
		if (ValidStreamIndex(RandomPool[idx]))
		{
			RandomStream = Songs[RandomPool[idx]];
			RandomPool.remove(idx, 1);
			Return RandomStream.GetPath();
		}
	}
	*/
	return "";
}
void UStreamPlaylist::ResetRandomPool()
{
	/*
	local int i;
	RandomPool.Length = Songs.Length;
	for (i = 0; i < Songs.Length; i++)
	{
		RandomPool[i] = i;
	}
	*/
}
bool UStreamPlaylist::SetTitle(FString NewTitle)
{
	/*
	if (NewTitle == "")
	{
		return false;
	}
	Title = NewTitle;
	OnPlaylistChanged();
	Save();
	*/
	return true;
}
bool UStreamPlaylist::SetCurrent(int32 Index)
{
	/*
	if (!ValidStreamIndex(Index))
	{
		return false;
	}
	Current = Index;
	bNeedSave = true;
	*/
	return true;
}
bool UStreamPlaylist::SetSongs(TArray<UStream*> NewSongs)
{
	Songs = NewSongs;
	ResetRandomPool();
	bNeedSave = true;
	return true;
}
bool UStreamPlaylist::IsInitialized()
{
	return FileManager != nullptr;
}
FString UStreamPlaylist::GetTitle()
{
	return Title;
}
int32 UStreamPlaylist::GetCurrent()
{
	return Current;
}
void UStreamPlaylist::GetSongs(TArray<UStream*> SongArray)
{
	SongArray = Songs;
}
UStream* UStreamPlaylist::GetCurrentStream()
{
	return GetStreamAt(GetCurrent());
}
UStream* UStreamPlaylist::GetStream(FString StreamName)
{
	int32 i=0;
	//i = FindIndexByName(StreamName);
	return GetStreamAt(i);
}
UStream* UStreamPlaylist::GetStreamAt(int32 Index)
{
	/*
	if (ValidStreamIndex(Index))
	{
		Return Songs[Index];
	}
	*/
	return nullptr;
}
void UStreamPlaylist::GetPlaylistLength()
{
	//Return Songs.Length;
}
int32 UStreamPlaylist::FindIndexByName(FString Test)
{
	/*
	local StreamBase.FilePath APath;
	if (ParsePath(Test, APath))
	{
		if (APath.Extension != "")
		{
			if (APath.Directory != "")
			{
				Return FindIndexByPath(APath.FullPath);
			}
			else
			{
				if (APath.Filename != "")
				{
					Return FindIndexByFullName(APath.Filename $ "." $ APath.Extension);
				}
			}
		}
		else
		{
			Return FindIndexByFileName(APath.Filename);
		}
	}
	*/
	return - 1;
}
int32 UStreamPlaylist::FindIndexByPath(FString Test)
{
	/*
	local int i;
	if (Test == "")
	{
		Return - 1;
	}
	for (i = 0; i < Songs.Length; i++)
	{
		if (Songs[i].GetPath() ~= Test)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
int32 UStreamPlaylist::FindIndexByFullName(FString Test)
{
	/*
	local int i;
	local int Num;
	if (Test == "")
	{
		Return - 1;
	}
	Num = GetPlaylistLength();
	for (i = 0; i < Num; i++)
	{
		if (Songs[i].GetFullName() ~= Test)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
int32 UStreamPlaylist::FindIndexByFileName(FString Test)
{
	/*
	local int i;
	local int Num;
	if (Test == "")
	{
		Return - 1;
	}
	Num = GetPlaylistLength();
	for (i = 0; i < Num; i++)
	{
		if (Songs[i].GetFileName() ~= Test)
		{
			Return i;
		}
	}
	*/
	return - 1;
}
bool UStreamPlaylist::ValidStreamName(FString Filename)
{
	if (Filename == "")
	{
		return false;
	}
	return ValidStreamIndex(FindIndexByName(Filename));
}
bool UStreamPlaylist::ValidStreamIndex(int32 Index)
{
	//return Index >= 0 && Index < Songs.Length;
	return true;     //FALSE   /FAKE
}
void UStreamPlaylist::DebugInfo()
{
	/*
	local int i;
	Log("   Playlist '" $ GetTitle() $ "', Length:" $ GetPlaylistLength(), 'MusicPlayer');
	for (i = 0; i < GetPlaylistLength(); i++)
	{
		Log("    " $ i $ ")" @ Songs[i].GetSongTitle(), 'MusicPlayer');
	}
	*/
}
void UStreamPlaylist::HandleDebugExec(FString Command, FString Param)
{
	/*
	local int i;
	if (HandleDebugExec(Command, Param))
	{
		Return True;
	}
	switch(Locs(Command))
	{
		case "addsong":
			AddSong(Param);
			Return True;
		case "dumptags":
			i = 0;
			if (i < Songs.Length)
			{
				Songs[i].DumpTags();
				i++;
				break;
			}
			Return True;
		case "scripttags":
			for (i = 0; i < Songs.Length; i++)
			{
				Songs[i].DumpScriptTag();
			}
		case "showsongs":
			Log("Playlist" @ GetTitle() @ "has" @ Songs.Length @ "songs", 'MusicPlayer');
			for (i = 0; i < Songs.Length; i++)
			{
				Log("  " $ i $ ")" @ Songs[i].GetPath(), 'MusicPlayer');
			}
			Return True;
		default:
			Return False;
	}
	*/
}
void UStreamPlaylist::Save()
{
	/*
	local int i;
	if (!bNeedSave)
	{
		Return;
	}
	Playlist.remove(0, Playlist.Length);
	for (i = 0; i < Songs.Length; i++)
	{
		if (Songs[i] != None)
		{
			Playlist[i] = Songs[i].GetPath();
		}
	}
	bNeedSave = False;
	SaveConfig();
	*/
}