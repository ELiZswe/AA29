// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamPlaylist/StreamPlaylist.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/Stream/Stream.h"

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
	int32 i = 0;
	ClearPlaylist();
	for (i = 0; i < Playlist.Num(); i++)
	{
		if (!FileManager->ValidFile(Playlist[i]))
		{
			//Log("Removing file from playlist '" + GetTitle() + "' - file not found", 'MusicPlayer');
			//Playlist.RemoveAt(i--, 1);
		}
		else
		{
			AddSong(Playlist[i],false);
		}
	}
	ResetRandomPool();
	bNeedSave = false;
	return true;
}

UStream* UStreamPlaylist::CreateStream(FString Filename)
{
	if (Filename == "")
	{
		return nullptr;
	}
	return FileManager->CreateStream(Filename,false);
}

int32 UStreamPlaylist::AddSong(FString SongFileName, bool bSkipNotification)
{
	UStream* NewStream = nullptr;
	EFileType Type = EFileType::FILE_None;
	int32 i = 0;
	/*
	if (SongFileName == "")
	{
		return - 1;
	}
	Type = ConvertToFileType(SongFileName);
	if (Type == 4)
	{
		NewStream = CreateStream(SongFileName);
		if (NewStream == nullptr)
		{
			return - 1;
		}
		i = AddStream(GetPlaylistLength(), NewStream, bSkipNotification);
		bNeedSave = bNeedSave || ValidStreamIndex(i);
		return i;
	}
	*/
	return - 1;
}

int32 UStreamPlaylist::AddStream(int32 Index, UStream* NewStream, bool bSkipNotification)
{
	int32 i = 0;
	FString str = "";
	if (NewStream == nullptr)
	{
		return - 1;
	}
	/*
	str = NewStream.GetFileName();
	if (str == "")
	{
		return - 1;
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
		RandomPool[RandomPool.Num()] = Index;
		if (!bSkipNotification)
		{
			OnPlaylistChanged();
		}
		return Index;
	}
	*/
	return i;
}

int32 UStreamPlaylist::InsertSong(int32 idx, FString Path, bool bSkipNotification)
{
	UStream* NewStream = nullptr;
	EFileType Type = EFileType::FILE_None;
	int32 i = 0;
	if (!ValidStreamIndex(idx))
	{
		return AddSong(Path, bSkipNotification);
	}
	if (Path == "")
	{
		return - 1;
	}
	/*
	Type = ConvertToFileType(Path);
	if (Type == 4)
	{
		NewStream = CreateStream(Path);
		if (NewStream == nullptr)
		{
			return - 1;
		}
		i = AddStream(idx, NewStream, bSkipNotification);
		bNeedSave = bNeedSave || ValidStreamIndex(i);
		return i;
	}
	*/
	return - 1;
}

bool UStreamPlaylist::RemoveSong(FString SongFileName, bool bSkipNotification)
{
	return RemoveSongAt(FindIndexByName(SongFileName), bSkipNotification);
}

bool UStreamPlaylist::RemoveSongAt(int32 idx, bool bSkipNotification)
{
	int32 i = 0;
	if (!ValidStreamIndex(idx))
	{
		return false;
	}
	/*
	Songs.RemoveAt(idx, 1);
	i = 0;
	if (i < RandomPool.Num())
	{
		if (RandomPool[i] == Songs.Num())
		{
			RandomPool.RemoveAt(i, 1);
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
	int32 i = 0;
	i = GetCurrent() + 1;
	/*
	if (!ValidStreamIndex(i) && bMayRepeat)
	{
		i = 0;
	}
	if (SetCurrent(i))
	{
		return Songs[Current].GetPath();
	}
	*/
	return "";
}

FString UStreamPlaylist::PrevSong(bool bMayRepeat)
{
	int32 i = 0;
	i = GetCurrent() - 1;
	/*
	if (!ValidStreamIndex(i) && bMayRepeat)
	{
		i = GetPlaylistLength() - 1;
	}
	if (SetCurrent(i))
	{
		return Songs[Current].GetPath();
	}
	*/
	return "";
}
void UStreamPlaylist::ReplaceWith(UStreamPlaylist* Other)
{
	if (Other == nullptr)
	{
		return;
	}
	/*
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
	bNeedSave = bNeedSave || Songs.Num() > 0;
	Songs.RemoveAt(0, Songs.Num());
	RandomPool.RemoveAt(0, RandomPool.Num());
	*/
	return true;
}

FString UStreamPlaylist::GetRandomSong()
{
	int32 idx = 0;
	UStream* RandomStream = nullptr;
	/*
	if (RandomPool.Num() == 0)
	{
		ResetRandomPool();
	}
	if (RandomPool.Num() > 0)
	{
		idx = Rand(RandomPool.Num() - 1);
		if (ValidStreamIndex(RandomPool[idx]))
		{
			RandomStream = Songs[RandomPool[idx]];
			RandomPool.RemoveAt(idx, 1);
			return RandomStream.GetPath();
		}
	}
	*/
	return "";
}

void UStreamPlaylist::ResetRandomPool()
{
	int32 i = 0;
	/*
	RandomPool.Num() = Songs.Num();
	for (i = 0; i < Songs.Num(); i++)
	{
		RandomPool[i] = i;
	}
	*/
}

bool UStreamPlaylist::SetTitle(FString NewTitle)
{
	if (NewTitle == "")
	{
		return false;
	}
	Title = NewTitle;
	OnPlaylistChanged();
	Save();
	return true;
}

bool UStreamPlaylist::SetCurrent(int32 Index)
{
	if (!ValidStreamIndex(Index))
	{
		return false;
	}
	Current = Index;
	bNeedSave = true;
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

void UStreamPlaylist::GetSongs(TArray<UStream*>& SongArray)
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
		return Songs[Index];
	}
	*/
	return nullptr;
}

int32 UStreamPlaylist::GetPlaylistLength()
{
	return Songs.Num();
}
int32 UStreamPlaylist::FindIndexByName(FString Test)
{
	FFilePath APath = FFilePath({});
	/*
	if (ParsePath(Test, APath))
	{
		if (APath.Extension != "")
		{
			if (APath.Directory != "")
			{
				return FindIndexByPath(APath.FullPath);
			}
			else
			{
				if (APath.Filename != "")
				{
					return FindIndexByFullName(APath.Filename + "." + APath.Extension);
				}
			}
		}
		else
		{
			return FindIndexByFileName(APath.Filename);
		}
	}
	*/
	return - 1;
}

int32 UStreamPlaylist::FindIndexByPath(FString Test)
{
	int32 i = 0;
	if (Test == "")
	{
		return - 1;
	}
	for (i = 0; i < Songs.Num(); i++)
	{
		if (Songs[i]->GetPath().Compare(Test,ESearchCase::IgnoreCase))
		{
			return i;
		}
	}
	return - 1;
}

int32 UStreamPlaylist::FindIndexByFullName(FString Test)
{
	int32 i = 0;
	int32 Num;
	if (Test == "")
	{
		return - 1;
	}
	Num = GetPlaylistLength();
	for (i = 0; i < Num; i++)
	{
		if (Songs[i]->GetFullName().Compare(Test,ESearchCase::IgnoreCase))
		{
			return i;
		}
	}
	return - 1;
}

int32 UStreamPlaylist::FindIndexByFileName(FString Test)
{
	int32 i = 0;
	int32 Num = 0;
	if (Test == "")
	{
		return - 1;
	}
	Num = GetPlaylistLength();
	for (i = 0; i < Num; i++)
	{
		if (Songs[i]->GetFileName().Compare(Test, ESearchCase::IgnoreCase))
		{
			return i;
		}
	}
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
	return ((Index >= 0) && (Index < Songs.Num()));
}

void UStreamPlaylist::DebugInfo()
{
	int32 i = 0;
	//Log("   Playlist '" + GetTitle() + "', Length:" + GetPlaylistLength(), 'MusicPlayer');
	for (i = 0; i < GetPlaylistLength(); i++)
	{
		//Log("    " + i + ")" @ Songs[i].GetSongTitle(), 'MusicPlayer');
	}
}

bool UStreamPlaylist::HandleDebugExec(FString Command, FString Param)
{
	int32 i = 0;
	/*
	if (HandleDebugExec(Command, Param))
	{
		return true;
	}
	switch(Locs(Command))
	{
		case "addsong":
			AddSong(Param);
			return true;
		case "dumptags":
			i = 0;
			if (i < Songs.Num())
			{
				Songs[i].DumpTags();
				i++;
				break;
			}
			return true;
		case "scripttags":
			for (i = 0; i < Songs.Num(); i++)
			{
				Songs[i].DumpScriptTag();
			}
		case "showsongs":
			Log("Playlist" @ GetTitle() @ "has" @ Songs.Num() @ "songs", 'MusicPlayer');
			for (i = 0; i < Songs.Num(); i++)
			{
				Log("  " + i + ")" @ Songs[i].GetPath(), 'MusicPlayer');
			}
			return true;
		default:
			return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

void UStreamPlaylist::Save()
{
	int32 i = 0;
	/*
	if (!bNeedSave)
	{
		return;
	}
	Playlist.RemoveAt(0, Playlist.Num());
	for (i = 0; i < Songs.Num(); i++)
	{
		if (Songs[i] != nullptr)
		{
			Playlist[i] = Songs[i].GetPath();
		}
	}
	bNeedSave = false;
	SaveConfig();
	*/
}
