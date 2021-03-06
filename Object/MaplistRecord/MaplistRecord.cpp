// All the original content belonged to the US Army

#include "AA29/Object/MaplistRecord/MaplistRecord.h"

UMaplistRecord::UMaplistRecord()
{

}

bool UMaplistRecord::CompareItems(FMapItem A, FMapItem B)
{
	return A==B;
}

bool UMaplistRecord::CompareItemsSlow(FMapItem A, FMapItem B)
{
	if (A==B)
	{
		return true;
	}
	if (A.MapName != B.MapName)
	{
		return false;
	}
	return false;
}

void UMaplistRecord::Created()
{
	CancelChanges();
}

void UMaplistRecord::SetCacheMaps(TArray<FMapItem> CacheMaps)
{
	CachedMaps=CacheMaps;
	VerifyMaps();
}

bool UMaplistRecord::SetTitle(FString NewTitle)
{
	if (NewTitle != "")
	{
		bDirty=bDirty || ! NewTitle.Compare(Title,ESearchCase::IgnoreCase);
		Title=NewTitle;
		return true;
	}
	return false;
}

bool UMaplistRecord::SetGameType(FString NewGameType)
{
	if (NewGameType != "")
	{
		bDirty=bDirty || ! NewGameType.Compare(GameType,ESearchCase::IgnoreCase);
		GameType=NewGameType;
		return true;
	}
	return false;
}

int32 UMaplistRecord::SetActiveMap(int32 i)
{
	if (ValidIndex(i))
	{
		bDirty=bDirty || Active != i;
		Active=i;
		return Active;
	}
	return -1;
}

void UMaplistRecord::SetMaplist(TArray<FString> NewMaps)
{
	CreateMapItemList(NewMaps,Maps);
	bDirty=true;
}

void UMaplistRecord::SetMapItemList(TArray<FMapItem> NewMaps)
{
	Maps=NewMaps;
	bDirty=true;
}

void UMaplistRecord::Save()
{
	int32 i = 0;
	if (bDirty)
	{
		if (! ValidIndex(Active))
		{
			Active=0;
		}
		DefaultTitle=Title;
		DefaultGameType=GameType;
		DefaultActive=Active;
		DefaultMaps.SetNum(Maps.Num());
		for (i=0; i<Maps.Num(); i++)
		{
			DefaultMaps[i]=Maps[i].FullURL;
		}
		SaveConfig();
	}
	bDirty=false;
}

void UMaplistRecord::VerifyMaps()
{
	int32 i = 0;
	for (i=DefaultMaps.Num()-1; i>=0; i--)
	{
		if (GetCacheIndex(DefaultMaps[i]) == -1)
		{
			//DefaultMaps->Remove(i,1);
		}
	}
	for (i=Maps.Num()-1; i>=0; i--)
	{
		if (GetCacheIndex(Maps[i].FullURL) == -1)
		{
			//Maps->Remove(i,1);
			bDirty=true;
		}
	}
}

void UMaplistRecord::CancelChanges()
{
	Title=DefaultTitle;
	GameType=DefaultGameType;
	Active=DefaultActive;
	CreateMapItemList(DefaultMaps,Maps);
	bDirty=false;
}

void UMaplistRecord::Clear(bool bReset)
{
	Active=-1;
	//Maps->Remove(0,Maps.Num());
	if (bReset)
	{
		Maps=CachedMaps;
	}
	bDirty=true;
}

bool UMaplistRecord::AddOptionString(int32 MapIndex, FString OptionString)
{
	return false;
}

bool UMaplistRecord::RemoveOptionString(int32 MapIndex, FString OptionString)
{
	return false;
}

void UMaplistRecord::RefreshMapItem(int32 MapIndex)
{
	FString FullMapURL = "";
	if (! ValidIndex(MapIndex))
	{
		return;
	}
	FullMapURL=Maps[MapIndex].MapName;
	Maps[MapIndex].FullURL=FullMapURL;
	Maps[MapIndex].MapName=GetBaseMapName(FullMapURL);
	Maps[MapIndex].OptionString=FullMapURL;
	bDirty=true;
}

bool UMaplistRecord::AddMap(FString MapName)
{
	int32 CacheIndex = 0;
	FMapItem Item = FMapItem({});
	/*
	CacheIndex=GetCacheIndex(MapName);
	if (CacheIndex == -1)
	{
		return false;
	}
	if (! CreateMapItem(MapName,Item))
	{
		return false;
	}
	if (GetMapItemIndex(Item) != -1)
	{
		return false;
	}
	Maps[Maps.Num()]=Item;
	*/
	bDirty = true;
	return true;
}

bool UMaplistRecord::InsertMap(FString MapName, int32 Index)
{
	FMapItem Item = FMapItem({});
	if (GetCacheIndex(MapName) == -1)
	{
		return false;
	}
	if (! CreateMapItem(MapName,Item))
	{
		return false;
	}
	if (GetMapItemIndex(Item) != -1)
	{
		return false;
	}
	//Maps.insert (Index,1);
	Maps[Index]=Item;
	bDirty=true;
	return true;
}

bool UMaplistRecord::RemoveMap(FString MapName)
{
	int32 i = 0;
	FMapItem Item = FMapItem({});
	if (GetCacheIndex(MapName) == -1)
	{
		return false;
	}
	if (! CreateMapItem(MapName,Item))
	{
		return false;
	}
	i=GetMapItemIndex(Item);
	if (i == -1)
	{
		return false;
	}
	//Maps->Remove(i,1);
	bDirty=true;
	return true;
}

bool UMaplistRecord::SetMapOptions(int32 MapIndex, FString OptionString)
{
	FString MapName = "";
	if (! ValidIndex(MapIndex))
	{
		return false;
	}
	MapName=GetBaseMapName(OptionString);
	if (MapName == "")
	{
		MapName=Maps[MapIndex].MapName;
	}
	MapName += OptionString;
	if (! CreateMapItem(MapName,Maps[MapIndex]))
	{
		return false;
	}
	bDirty=true;
	return true;
}

FString UMaplistRecord::GetTitle()
{
	return Title;
}

FString UMaplistRecord::GetGameType()
{
	
	return GameType;
	
}

FString UMaplistRecord::GetActiveMapName()
{
	return GetMapName(Active);
}

FString UMaplistRecord::GetActiveMapURL()
{
	return GetMapURL(Active);
}

FString UMaplistRecord::GetMapName(int32 i)
{
	if (ValidIndex(i))
	{
		return Maps[i].MapName;
	}
	return "";
}

FString UMaplistRecord::GetMapURL(int32 Index)
{
	if (ValidIndex(Index))
	{
		return Maps[Index].FullURL;
	}
	return "";
}

TArray<FMapItem> UMaplistRecord::GetMaps()
{
	return Maps;
}

TArray<FString> UMaplistRecord::GetAllMapURL()
{
	int32 i = 0;
	TArray<FString> Ar;
	for (i=0; i<Maps.Max(); i++)
	{
		Ar.Add (Maps[i].FullURL);
	}
	return Ar;
}

bool UMaplistRecord::IsDirty()
{
	return bDirty;
}

int32 UMaplistRecord::GetCacheIndex(FString MapName)
{
	int32 i = 0;
	FString str = "";
	str=GetBaseMapName(MapName);
	for (i=0; i<CachedMaps.Num(); i++)
	{
		if (str.Compare(CachedMaps[i].MapName,ESearchCase::IgnoreCase))
		{
			return i;
		}
	}
	return -1;
}

int32 UMaplistRecord::GetActiveMapIndex()
{
	return Active;
}

int32 UMaplistRecord::GetMapIndex(FString MapName)
{
	FMapItem Item;
	if (CreateMapItem(MapName,Item))
	{
		return GetMapItemIndex(Item);
	}
	return -1;
}

int32 UMaplistRecord::GetMapItemIndex(FMapItem Item)
{
	int32 i = 0;
	for (i=0; i<Maps.Max(); i++)
	{
		if (Maps[i] == Item)
		{
			return i;
		}
	}
	return -1;
}

bool UMaplistRecord::ValidMap(FString MapName)
{
	return GetMapIndex(MapName) != -1;
}

bool UMaplistRecord::ValidIndex(int32 i)
{
	return i >= 0 && i < Maps.Max();
}

bool UMaplistRecord::ValidOptionIndex(int32 MapIndex, int OptionIndex)
{
	return false;
}

FString UMaplistRecord::GetBaseMapName(FString& FullMapURL)
{
	FString str;
	str=FullMapURL;
	return str;
}

bool UMaplistRecord::CreateMapItem(FString FullMapURL, FMapItem& Item)
{
	return false;
}

void UMaplistRecord::CreateMapItemList(TArray<FString> MapURLs, TArray<FMapItem>& MapItems)
{
	int32 i = 0;
	FMapItem Item = FMapItem({});
	//MapItems.Remove(0,MapItems.Num());
	for (i=0; i<MapURLs.Num(); i++)
	{
		if (CreateMapItem(MapURLs[i],Item))
		{
			MapItems[MapItems.Num()]=Item;
		}
	}
}
