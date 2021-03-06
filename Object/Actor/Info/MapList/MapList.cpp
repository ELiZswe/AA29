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
	if (Maps.Num() == 0)
	{
		Warn(Name @ "has no maps configured!");
	}
	PostBeginPlay();
	*/
}

FString AMapList::GetNextMap()
{
	FString CurrentMap = "";
	int32 i = 0;
	/*
	CurrentMap=GetURLMap(true);
	if (CurrentMap == "")
	{
		i=MapNum;
	}
	else
	{
		for (i=0; i<Maps.Num(); i++)
		{
			if (CurrentMap ~= Maps[i])
			{
			}
		}
	}
	*/
	return UpdateMapNum(i + 1);
}

FString AMapList::UpdateMapNum(int32 NewMapNum)
{
	/*
	if (Maps.Num() == 0)
	{
		Warn("No maps configured for game maplist! Unable to change maps!");
		return "";
	}
	if (true)
	{
		if (NewMapNum < 0 || NewMapNum >= Maps.Num())
		{
			NewMapNum=0;
		}
		if (NewMapNum == MapNum || MapNum < 0 || MapNum >= Maps.Num())
		{
		}
		if (FindCacheIndex(Maps[NewMapNum]) != -1)
		{
		}
		NewMapNum ++;
	}
	MapNum=NewMapNum;
	if (Level.Game.MaplistHandler != nullptr)
	{
		Level.Game.MaplistHandler.MapChange(Maps[MapNum]);
	}
	SaveConfig();
	*/
	return Maps[MapNum];
}

int32 AMapList::FindCacheIndex(FString MapName)
{
	/*
	int32 i = 0;
	FString tmp;
	tmp='MaplistRecord'.GetBaseMapName(MapName);
	for (i=0; i<CachedMaps.Num(); i++)
	{
		if (CachedMaps[i].MapName ~= tmp)
		{
			return i;
		}
	}
	*/
	return -1;
}

FString AMapList::GetMap(int32 MapIndex)
{
	/*
	if (MapIndex < 0 || MapIndex >= Maps.Num())
	{
		return "";
	}
	*/
	return Maps[MapIndex];
}

TArray<FString> AMapList::GetMaps()
{
	if (HasInvalidMaps(false))
	{
		MapNum=0;
		SaveConfig();
	}
	return Maps;
}

TArray<FString> AMapList::StaticGetMaps()
{
	if (StaticHasInvalidMaps(false))
	{
		//GetDefault<AMapList>()->MapNum=0;
		//StaticSaveConfig();
	}
	return GetDefault<AMapList>()->Maps;
}

bool AMapList::HasInvalidMaps(bool bReadOnly)
{
	int32 i = 0;
	bool bInvalid = false;
	/*
	for (i=Maps.Num()-1; i>=0; i--)
	{
		if (Maps[i] == "")
		{
			bInvalid=true;
			if (! bReadOnly)
			{
				Maps->Remove(i,1);
			}
		}
		else
		{
			if (FindCacheIndex(Maps[i]) == -1)
			{
				bInvalid=true;
				if (! bReadOnly)
				{
					Maps->Remove(i,1);
				}
			}
		}
	}
	*/
	return bInvalid;
}

bool AMapList::StaticHasInvalidMaps(bool bReadOnly)
{
	int32 i = 0;
	int32 j = 0;
	bool bInvalid = false;
	TArray<FMapRecord> Recs = {};
	FString URL = "";
	FString MapName = "";
	/*
	'CacheManager'.GetMapList(Recs);
	for (i=Default.Maps.Num()-1; i>=0; i--)
	{
		if (Default.Maps[i] == "")
		{
			bInvalid=true;
			if (! bReadOnly)
			{
				Default.Maps->Remove(i,1);
			}
		}
		else
		{
			URL=Default.Maps[i];
			MapName='MaplistRecord'.GetBaseMapName(URL);
			for (j=0; j<Recs.Num(); j++)
			{
				if (Recs[j].MapName ~= MapName)
				{
				}
			}
			if (j == Recs.Num())
			{
				bInvalid=true;
				if (! bReadOnly)
				{
					Default.Maps->Remove(i,1);
				}
			}
		}
	}
	*/
	return bInvalid;
}

bool AMapList::SetMaplist(int32 CurrentNum, TArray<FString> NewMaps)
{
	/*
	if (CurrentNum >= NewMaps.Num())
	{
		CurrentNum=0;
	}
	Default.MapNum=CurrentNum;
	Default.Maps=NewMaps;
	StaticSaveConfig();
	*/
	return true;
}
