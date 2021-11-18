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
void UMaplistRecord::SetTitle(FString NewTitle)
{
	/*
	if (NewTitle != "")
	{
		bDirty=bDirty || ! NewTitle ~= Title;
		Title=NewTitle;
		Return True;
	}
	Return False;
	*/
}
void UMaplistRecord::SetGameType(FString NewGameType)
{
	/*
	if (NewGameType != "")
	{
		bDirty=bDirty || ! NewGameType ~= GameType;
		GameType=NewGameType;
		Return True;
	}
	Return False;
	*/
}
void UMaplistRecord::SetActiveMap(int32 i)
{
	/*
	if (ValidIndex(i))
	{
		bDirty=bDirty || Active != i;
		Active=i;
		Return Active;
	}
	Return -1;
	*/
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
	/*
	local int i;
	if (bDirty)
	{
		if (! ValidIndex(Active))
		{
			Active=0;
		}
		DefaultTitle=Title;
		DefaultGameType=GameType;
		DefaultActive=Active;
		DefaultMaps.Length=Maps.Length;
		for (i=0; i<Maps.Length; i++)
		{
			DefaultMaps[i]=Maps[i].FullURL;
		}
		SaveConfig();
	}
	bDirty=False;
	*/
}
void UMaplistRecord::VerifyMaps()
{
	/*
	local int i;
	for (i=DefaultMaps.Length-1; i>=0; i--)
	{
		if (GetCacheIndex(DefaultMaps[i]) == -1)
		{
			DefaultMaps.remove (i,1);
		}
	}
	for (i=Maps.Length-1; i>=0; i--)
	{
		if (GetCacheIndex(Maps[i].FullURL) == -1)
		{
			Maps.remove (i,1);
			bDirty=True;
		}
	}
	*/
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
	/*
	Active=-1;
	Maps.remove (0,Maps.Length);
	if (bReset)
	{
		Maps=CachedMaps;
	}
	bDirty=True;
	*/
}
bool UMaplistRecord::AddOptionString(int32 MapIndex, FString OptionString)
{
	return false;
}
bool UMaplistRecord::RemoveOptionString (int32 MapIndex, FString OptionString)
{
	return false;
}
void UMaplistRecord::RefreshMapItem(int32 MapIndex)
{
	/*
	local string FullMapURL;
	if (! ValidIndex(MapIndex))
	{
		Return;
	}
	FullMapURL=Maps[MapIndex].MapName;
	Maps[MapIndex].FullURL=FullMapURL;
	Maps[MapIndex].MapName=GetBaseMapName(FullMapURL);
	Maps[MapIndex].OptionString=FullMapURL;
	bDirty=True;
	*/
}
void UMaplistRecord::AddMap(FString MapName)
{
	/*
	local int CacheIndex;
	local MapItem Item;
	CacheIndex=GetCacheIndex(MapName);
	if (CacheIndex == -1)
	{
		Return False;
	}
	if (! CreateMapItem(MapName,Item))
	{
		Return False;
	}
	if (GetMapItemIndex(Item) != -1)
	{
		Return False;
	}
	Maps[Maps.Length]=Item;
	bDirty=True;
	Return True;
	*/
}
void UMaplistRecord::InsertMap(FString MapName, int32 Index)
{
	/*
	local MapItem Item;
	if (GetCacheIndex(MapName) == -1)
	{
		Return False;
	}
	if (! CreateMapItem(MapName,Item))
	{
		Return False;
	}
	if (GetMapItemIndex(Item) != -1)
	{
		Return False;
	}
	Maps.insert (Index,1);
	Maps[Index]=Item;
	bDirty=True;
	Return True;
	*/
}
void UMaplistRecord::RemoveMap(FString MapName)
{
	/*
	local int i;
	local MapItem Item;
	if (GetCacheIndex(MapName) == -1)
	{
		Return False;
	}
	if (! CreateMapItem(MapName,Item))
	{
		Return False;
	}
	i=GetMapItemIndex(Item);
	if (i == -1)
	{
		Return False;
	}
	Maps.remove (i,1);
	bDirty=True;
	Return True;
	*/
}
void UMaplistRecord::SetMapOptions(int32 MapIndex, FString OptionString)
{
	/*
	local string MapName;
	if (! ValidIndex(MapIndex))
	{
		Return False;
	}
	MapName=GetBaseMapName(OptionString);
	if (MapName == "")
	{
		MapName=Maps[MapIndex].MapName;
	}
	MapName $= OptionString;
	if (! CreateMapItem(MapName,Maps[MapIndex]))
	{
		Return False;
	}
	bDirty=True;
	Return True;
	*/
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
TArray<FString> UMaplistRecord::GetAllMapURL ()
{
	int32 i;
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
void UMaplistRecord::GetCacheIndex(FString MapName)
{
	/*
	local int i;
	local string str;
	str=GetBaseMapName(MapName);
	for (i=0; i<CachedMaps.Length; i++)
	{
		if (str ~= CachedMaps[i].MapName)
		{
			Return i;
		}
	}
	Return -1;
	*/
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
int32 UMaplistRecord::GetMapItemIndex (FMapItem Item)
{
	int32 i;
	for (i=0; i<Maps.Max(); i++)
	{
		if (Maps[i] == Item)
		{
			return i;
		}
	}
	return -1;
}
bool UMaplistRecord::ValidMap (FString MapName)
{
	return GetMapIndex(MapName) != -1;
}
bool UMaplistRecord::ValidIndex(int i)
{
	return i >= 0 && i < Maps.Max();
}
bool UMaplistRecord::ValidOptionIndex(int MapIndex, int OptionIndex)
{
	return false;
}
FString UMaplistRecord::GetBaseMapName(FString FullMapURL)
{
	FString str;
	str=FullMapURL;
	return str;
}
bool UMaplistRecord::CreateMapItem(FString FullMapURL, FMapItem Item)
{
	return false;
}
void UMaplistRecord::CreateMapItemList(TArray<FString> MapURLs, TArray<FMapItem> MapItems)
{
	/*
	local int i;
	local MapItem Item;
	MapItems.remove (0,MapItems.Length);
	for (i=0; i<MapURLs.Length; i++)
	{
		if (CreateMapItem(MapURLs[i],Item))
		{
			MapItems[MapItems.Length]=Item;
		}
	}
	*/
}
