// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/MapList/MapList.h"

AMapList::AMapList()
{

}
void AMapList::PreBeginPlay()
{
	/*
	PreBeginPlay();
	'CacheManager'.GetMapList(CachedMaps);
	if (HasInvalidMaps())
	{
		MapNum=0;
		SaveConfig();
		Log("MapList had invalid entries!");
	}
	*/
}
void AMapList::PostBeginPlay()
{
	/*
	if (Maps.Length == 0)
	{
		Warn(Name @ "has no maps configured!");
	}
	PostBeginPlay();
	*/
}
void AMapList::GetNextMap()
{
	/*
	local string CurrentMap;
	local int i;
	CurrentMap=GetURLMap(True);
	if (CurrentMap == "")
	{
		i=MapNum;
	}
	else
	{
		for (i=0; i<Maps.Length; i++)
		{
			if (CurrentMap ~= Maps[i])
			{
			}
		}
	}
	Return UpdateMapNum(i + 1);
	*/
}
void AMapList::UpdateMapNum(int32 NewMapNum)
{
	/*
	if (Maps.Length == 0)
	{
		Warn("No maps configured for game maplist! Unable to change maps!");
		Return "";
	}
	if (True)
	{
		if (NewMapNum < 0 || NewMapNum >= Maps.Length)
		{
			NewMapNum=0;
		}
		if (NewMapNum == MapNum || MapNum < 0 || MapNum >= Maps.Length)
		{
		}
		if (FindCacheIndex(Maps[NewMapNum]) != -1)
		{
		}
		NewMapNum ++;
	}
	MapNum=NewMapNum;
	if (Level.Game.MaplistHandler != None)
	{
		Level.Game.MaplistHandler.MapChange(Maps[MapNum]);
	}
	SaveConfig();
	Return Maps[MapNum];
	*/
}
void AMapList::FindCacheIndex(FString MapName)
{
	/*
	local int i;
	local string tmp;
	tmp='MaplistRecord'.GetBaseMapName(MapName);
	for (i=0; i<CachedMaps.Length; i++)
	{
		if (CachedMaps[i].MapName ~= tmp)
		{
			Return i;
		}
	}
	Return -1;
	*/
}
void AMapList::GetMap(int32 MapIndex)
{
	/*
	if (MapIndex < 0 || MapIndex >= Maps.Length)
	{
		Return "";
	}
	Return Maps[MapIndex];
	*/
}
void AMapList::GetMaps()
{
	/*
	if (HasInvalidMaps())
	{
		MapNum=0;
		SaveConfig();
	}
	Return Maps;
	*/
}
void AMapList::StaticGetMaps()
{
	/*
	if (StaticHasInvalidMaps())
	{
		Default.MapNum=0;
		StaticSaveConfig();
	}
	Return Default.Maps;
	*/
}
void AMapList::HasInvalidMaps(bool bReadOnly)
{
	/*
	local int i;
	local bool bInvalid;
	for (i=Maps.Length-1; i>=0; i--)
	{
		if (Maps[i] == "")
		{
			bInvalid=True;
			if (! bReadOnly)
			{
				Maps.remove (i,1);
			}
		}
		else
		{
			if (FindCacheIndex(Maps[i]) == -1)
			{
				bInvalid=True;
				if (! bReadOnly)
				{
					Maps.remove (i,1);
				}
			}
		}
	}
	Return bInvalid;
	*/
}
void AMapList::StaticHasInvalidMaps(bool bReadOnly)
{
	/*
	local int i;
	local int j;
	local bool bInvalid;
	local array<CacheManager.MapRecord> Recs;
	local string URL;
	local string MapName;
	'CacheManager'.GetMapList(Recs);
	for (i=Default.Maps.Length-1; i>=0; i--)
	{
		if (Default.Maps[i] == "")
		{
			bInvalid=True;
			if (! bReadOnly)
			{
				Default.Maps.remove (i,1);
			}
		}
		else
		{
			URL=Default.Maps[i];
			MapName='MaplistRecord'.GetBaseMapName(URL);
			for (j=0; j<Recs.Length; j++)
			{
				if (Recs[j].MapName ~= MapName)
				{
				}
			}
			if (j == Recs.Length)
			{
				bInvalid=True;
				if (! bReadOnly)
				{
					Default.Maps.remove (i,1);
				}
			}
		}
	}
	Return bInvalid;
	*/
}
void AMapList::SetMaplist(int32 CurrentNum, TArray<FString> NewMaps)
{
	/*
	if (CurrentNum >= NewMaps.Length)
	{
		CurrentNum=0;
	}
	Default.MapNum=CurrentNum;
	Default.Maps=NewMaps;
	StaticSaveConfig();
	Return True;
	*/
}
