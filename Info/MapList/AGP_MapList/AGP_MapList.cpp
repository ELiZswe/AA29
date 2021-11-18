// All the original content belonged to the US Army


#include "AA29/Info/MapList/AGP_MapList/AGP_MapList.h"

AAGP_MapList::AAGP_MapList()
{
	Maps	= { "Radio_Tower.aao", "Insurgent_Camp.aao", "Pipeline.aao", "Weapons_Cache.aao", "Bridge.aao" };
	MapNum	= 5;
}


void AAGP_MapList::PreBeginPlay()
{
}
void AAGP_MapList::PostBeginPlay()
{
}
 FString AAGP_MapList::GetNextMap()
{
	FString CurrentMap;
	int32 i;
	CurrentMap = GetWorld()->GetMapName();
	if (CurrentMap != "")
	{
		if (CurrentMap.Right(5) == ".umap")
		{
			CurrentMap = CurrentMap;
		}
		else
		{
			CurrentMap += ".umap";
		}
		for (i = 0; i < Maps.Max(); i++)
		{
			if (CurrentMap == Maps[i])
			{
				MapNum = i;
				break;
			}
		}
	}
	// Move to next map in list - if we hit end of list we
	//  wrap back to beginning.   If the map entry found is empty
	//  (like might happen with "Maps=" in INI) we go back to 
	//  beginning.
	MapNum++;
	if (MapNum > Maps.Max() - 1)
	{
		MapNum = 0;
	}
	if (Maps[MapNum] == "")
	{
		MapNum = 0;
	}
	SaveConfig();
	return Maps[MapNum];
}