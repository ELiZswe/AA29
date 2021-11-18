// All the original content belonged to the US Army


#include "AA29/Info/MaplistManagerBase/MaplistManager/MaplistManager.h"

AMaplistManager::AMaplistManager()
{
	//Games(0) = (GameType = "AGP_Gameplay.AGP_GameTeamObjective", ActiveMaplist = "Default Team Objective");
	DefaultListName = "Default";
	InvalidGameType = "could not be loaded.  Normally, this means an .u file has been deleted, but the .int file has not.";
	ReallyInvalidGameType = "The requested gametype '%gametype%' could not be loaded.";
	DefaultListExists = "Gametype already has a default list!";
}

void AMaplistManager::PreBeginPlay()
{
	/*
	local int i;
	local int idx;
	PreBeginPlay();
	'CacheManager'.GetGameTypeList(CachedGames);
	InitializeMaplistRecords();
	for (i = 0; i < CachedGames.Length; i++)
	{
		idx = AddGroup(CachedGames[i].ClassName);
		if (Groups[idx].Records.Length <= 0)
		{
			CreateDefaultList(i);
		}
	}
	InitializeActiveLists();
	if (bDirty)
	{
		Save();
	}
	*/
}

void AMaplistManager::Destroyed()
{
	/*
	if (bDirty)
	{
		Save();
	}
	Super::Destroyed();
	*/
}

void AMaplistManager::CreateDefaultList(int32 i)
{
	/*
	local string ListName;
	local array<String> Arr;
	if (!ValidCacheGameIndex(i))
	{
		Return;
	}
	ListName = DefaultListName @ CachedGames[i].GameAcronym;
	if (GetDefaultMaps(CachedGames[i].MapListClassName, Arr))
	{
		AddList(CachedGames[i].ClassName, ListName, Arr);
	}
	*/
}
bool AMaplistManager::GetDefaultMaps(FString MapListClassName, TArray<FString> &Maps)
{
	/*
	local class<MapList>  List;
	if (MapListClassName == "")
	{
		return false;
	}
	List = class<MapList>(DynamicLoadObject(MapListClassName, Class'Class', True));
	if (List == None)
	{
		return false;
	}
	Maps = List.StaticGetMaps();
	*/
	return true;
}

void AMaplistManager::InitializeMaplistRecords()
{
	/*
	local int i;
	local int cnt;
	local MaplistRecord Rec;
	MaplistRecordNames = GetPerObjectNames("System", "MaplistRecord");
	cnt = MaplistRecordNames.Length;
	for (i = 0; i < Groups.Length; i++)
	{
		if (Groups[i].Records.Length > 0)
		{
			Groups[i].Records.remove(0, Groups[i].Records.Length);
		}
	}
	i = 0;
	if (i < cnt && i < MaplistRecordNames.Length)
	{
		if (MaplistRecordNames[i] == "")
		{
		}
		Rec = CreateRecord(MaplistRecordNames[i]);
		if (!ValidGameType(Rec.GetGameType()))
		{
			Rec.ClearConfig();
		}
		else
		{
			AddMaplistRecord(Rec);
		}
		i++;
	}
	*/
}

void AMaplistManager::InitializeActiveLists()
{
	/*
	local int i;
	local int RecordIndex;
	local int idx;
	for (i = Games.Length - 1; i >= 0; i--)
	{
		if (Games[i].GameType == "")
		{
			RemoveGame(i);
		}
		else
		{
			idx = GetGameIndex(Games[i].GameType);
			if (idx == -1)
			{
			}
			RecordIndex = GetRecordIndex(idx, Games[i].ActiveMaplist);
			if (RecordIndex < 0 || RecordIndex >= Groups[idx].Records.Length)
			{
				RecordIndex = 0;
			}
			SetActiveList(idx, RecordIndex);
			Groups[idx].LastActive = Groups[idx].Active;
		}
	}
	*/
}

int32 AMaplistManager::AddMaplistRecord(UMaplistRecord* Rec)
{
	int32 j=0;
	/*
	local int i;
	if (Rec == None || Rec.GetGameType() == "")
	{
		Return - 1;
	}
	i = AddGroup(Rec.GetGameType());
	j = Groups[i].Records.Length;
	Rec.SetCacheMaps(Groups[i].AllMaps);
	Groups[i].Records[j] = Rec;
	*/
	return j;
}

int32 AMaplistManager::AddGroup(FString aGameType)
{
	int32 i=0;
	/*
	if (GameType == "")
	{
		Return - 1;
	}
	i = GetGameIndex(GameType);
	if (i == -1)
	{
		i = Groups.Length;
		Groups.Length = i + 1;
		Groups[i].GameType = GameType;
		GenerateGroupMaplist(i);
	}
	AddGameType(GameType);
	*/
	return i;
}

int32 AMaplistManager::AddGameType(FString NewGameType)
{
	int32 i=0;
	/*
	i = GetStoredGameIndex(NewGameType);
	if (i == -1)
	{
		i = Games.Length;
		Games.Length = i + 1;
		Games[i].GameType = NewGameType;
		bDirty = true;
	}
	*/
	return i;
}

void AMaplistManager::GenerateGroupMaplist(int32 GroupIndex)
{
}

bool AMaplistManager::RemoveGame(int32 i)
{
	/*
	if (i < 0 || i >= Games.Length)
	{
		return false;
	}
	Games.remove(i, 1);
	bDirty = true;
	*/
	return true;
}

int32 AMaplistManager::RemoveRecord(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return - 1;
	}
	Groups[GameIndex].Records[RecordIndex].ClearConfig();
	Groups[GameIndex].Records.remove(RecordIndex, 1);
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		RecordIndex = 0;
	}
	*/
	return RecordIndex;
}

int32 AMaplistManager::GetStoredGameIndex(FString aGameType)
{
	/*
	local int i;
	if (GameType == "")
	{
		Return - 1;
	}
	for (i = 0; i < Games.Length; i++)
	{
		if (Games[i].GameType ~= GameType)
		{
			Return i;
		}
	}
	*/
	return -1;
}

void AMaplistManager::Save()
{
	/*
	if (bDirty)
	{
		SaveConfig();
		bDirty = False;
	}
	*/
}

void AMaplistManager::CreateRecord(FString RecordName)
{
	/*
	if (RecordName == "")
	{
		Return None;
	}
	Return new (NoneRepl(RecordName, " ", Chr(27))) class'MaplistRecord';
	*/
}

bool AMaplistManager::IsNewGameType(FString GameClassName)
{
	//Return GetStoredGameIndex(GameClassName) == -1;
	return false;    //FAKE   /ELiZ
}

void AMaplistManager::GetRecords(int32 GameIndex)
{
	/*
	if (ValidGameIndex(GameIndex))
	{
		Return Groups[GameIndex].Records;
	}
	*/
}

bool AMaplistManager::ValidRecordIndex(int GameIndex, int MapListIndex)
{
	//Return ValidGameIndex(GameIndex) && MapListIndex >= 0 && MapListIndex < Groups[GameIndex].Records.Length&& Groups[GameIndex].Records[MapListIndex] != None;
	return true;    //FAKE    /ELiZ
}

void AMaplistManager::MapChange(FString NewMap)
{
	/*
	local int i;
	local int GameIndex;
	local int RecordIndex;
	GameIndex = AddGroup(Level.Game.Class);
	if (ValidRecordIndex(GameIndex, Groups[GameIndex].Active))
	{
		RecordIndex = Groups[GameIndex].Active;
		i = Groups[GameIndex].Records[RecordIndex].GetMapIndex(NewMap);
		if (i == -1)
		{
			RecordIndex = FindMaplistContaining(GameIndex, NewMap);
			if (SetActiveList(GameIndex, RecordIndex))
			{
				i = Groups[GameIndex].Records[RecordIndex].GetMapIndex(NewMap);
			}
		}
	}
	else
	{
		RecordIndex = FindMaplistContaining(GameIndex, NewMap);
		if (SetActiveList(GameIndex, RecordIndex))
		{
			i = Groups[GameIndex].Records[RecordIndex].GetMapIndex(NewMap);
		}
	}
	if (i != -1 && ValidRecordIndex(GameIndex, RecordIndex))
	{
		Groups[GameIndex].Records[RecordIndex].SetActiveMap(i);
		SaveMapList(GameIndex, RecordIndex);
	}
	*/
}
int32 AMaplistManager::AddList(FString aGameType, FString NewName, TArray<FString> Maps)
{
	int32 i=0;
	/*
	local MaplistRecord NewRecord;
	local string DesiredName;
	if (!ValidGameType(GameType))
	{
		Return - 1;
	}
	DesiredName = NewName;
	if (ValidName(NewName))
	{
		NewName = DesiredName $ i++;
	}
	if (Len(NewName) > 512)
	{
		Return - 1;
	}
	NewRecord = CreateRecord(NewName);
	if (NewRecord == None)
	{
		Return - 1;
	}
	NewRecord.SetGameType(GameType);
	NewRecord.SetTitle(NewName);
	i = AddMaplistRecord(NewRecord);
	if (Maps.Length == 0)
	{
		NewRecord.Clear(True);
	}
	else
	{
		NewRecord.SetMaplist(Maps);
	}
	NewRecord.Save();
	if (bDirty)
	{
		Save();
	}
	*/
	return i;
}

int32 AMaplistManager::RenameList(int32 GameIndex, int32 RecordIndex, FString NewName)
{
	/*
	local MaplistRecord OldRecord;
	local bool IsActive;
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return - 1;
	}
	if (NewName == "")
	{
		Return - 1;
	}
	IsActive = GetActiveList(GameIndex) == RecordIndex;
	OldRecord = Groups[GameIndex].Records[RecordIndex];
	RemoveRecord(GameIndex, RecordIndex);
	RecordIndex = AddList(OldRecord.GetGameType(), NewName, OldRecord.GetAllMapURL());
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Groups[GameIndex].Records[RecordIndex].SetActiveMap(OldRecord.GetActiveMapIndex());
		if (IsActive && !SetActiveList(GameIndex, RecordIndex))
		{
			RecordIndex = GetActiveList(GameIndex);
		}
	}
	*/
	return RecordIndex;
}

int32 AMaplistManager::RemoveList(int32 GameIndex, int32 RecordIndex)
{
	int32 i=0;
	int32 idx=0;
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return GetActiveList(GameIndex);
	}
	idx = RemoveRecord(GameIndex, RecordIndex);
	if (Groups[GameIndex].Records.Length == 0)
	{
		i = GetCacheGameIndex(Groups[GameIndex].GameType);
		CreateDefaultList(i);
	}
	if (Groups[GameIndex].Active < 0 || Groups[GameIndex].Active == RecordIndex || Groups[GameIndex].Active >= Groups[GameIndex].Records.Length)
	{
		SetActiveList(GameIndex, 0);
		ApplyMapList(GameIndex, 0);
	}
	if (bDirty)
	{
		Save();
	}
	*/
	return idx;
}
bool AMaplistManager::SaveMapList(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return false;
	}
	Save();
	Groups[GameIndex].Records[RecordIndex].Save();
	*/
	return true;
}

bool AMaplistManager::ClearList(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return false;
	}
	Groups[GameIndex].Records[RecordIndex].Clear();
	*/
	return true;
}
void AMaplistManager::ResetList(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return;
	}
	Groups[GameIndex].Records[RecordIndex].CancelChanges();
	*/
}
bool AMaplistManager::SaveGame(int32 GameIndex)
{
	/*
	local int i;
	local int Active;
	if (!ValidGameIndex(GameIndex))
	{
		return false;
	}
	Groups[GameIndex].LastActive = Groups[GameIndex].Active;
	i = AddGameType(Groups[GameIndex].GameType);
	Active = GetActiveList(GameIndex);
	if (!ValidRecordIndex(GameIndex, Active))
	{
		SetActiveList(GameIndex, 0);
	}
	for (i = 0; i < Groups[GameIndex].Records.Length; i++)
	{
		SaveMapList(GameIndex, i);
	}
	Save();
	*/
	return true;
}
void AMaplistManager::ResetGame(int32 GameIndex)
{
	/*
	local int i;
	local int RecordIndex;
	if (!ValidGameIndex(GameIndex))
	{
		Return;
	}
	for (i = 0; i < Groups[GameIndex].Records.Length; i++)
	{
		ResetList(GameIndex, i);
	}
	i = GetStoredGameIndex(Groups[GameIndex].GameType);
	RecordIndex = GetRecordIndex(GameIndex, Games[i].ActiveMaplist);
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		RecordIndex = 0;
	}
	SetActiveList(GameIndex, RecordIndex);
	*/
}
bool AMaplistManager::ApplyMapList(int32 GameIndex, int32 RecordIndex)
{
	/*
	local class<MapList>  ListClass;
	local int i;
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		SetActiveList(GameIndex, RecordIndex);
		SaveGame(GameIndex);
		i = GetCacheGameIndex(Groups[GameIndex].GameType);
		if (i == -1)
		{
			Warn("Error applying maplist:" @ Groups[GameIndex].GameType);
			return false;
		}
		ListClass = class<MapList>(DynamicLoadObject(CachedGames[i].MapListClassName, Class'Class'));
		if (ListClass == None)
		{
			Log("Invalid maplist class:" @ CachedGames[i].MapListClassName @ "for gametype" @ CachedGames[i].ClassName);
			return false;
		}
		ListClass.SetMaplist(GetActiveMap(GameIndex, RecordIndex), GetMapList(GameIndex, RecordIndex));
		return true;
	}
	else
	{
		Log("Invalid maplist index");
	}
	*/
	return false;
}
bool AMaplistManager::SetActiveList(int32 GameIndex, int32 NewActive)
{
	/*
	local int i;
	if (!ValidRecordIndex(GameIndex, NewActive))
	{
		return false;
	}
	i = AddGameType(Groups[GameIndex].GameType);
	Games[i].ActiveMaplist = Groups[GameIndex].Records[NewActive].GetTitle();
	Groups[GameIndex].Active = NewActive;
	bDirty = true;
	*/
	return true;
}
bool AMaplistManager::AddMap(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].AddMap(MapName);
	}
	*/
	return false;
}

bool AMaplistManager::InsertMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 ListIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].InsertMap(MapName, ListIndex);
	}
	*/
	return false;
}

bool AMaplistManager::RemoveMap(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].RemoveMap(MapName);
	}
	*/
	return false;
}

void AMaplistManager::ShiftMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 Count)
{
	/*
	local int i;
	local array<MaplistRecord.MapItem> Maps;
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return;
	}
	if (Count == 0)
	{
		Return;
	}
	i = Groups[GameIndex].Records[RecordIndex].GetMapIndex(MapName);
	if (i == -1)
	{
		Return;
	}
	Maps = Groups[GameIndex].Records[RecordIndex].GetMaps();
	if (Count < 0)
	{
		if (i + Count < 0)
		{
			Count = -i;
		}
		Maps.insert(i + Count, 1);
		Maps[i + Count] = Maps[i + 1];
		Maps.remove(i + 1, 1);
	}
	else
	{
		if (i + Count + 1 >= Maps.Length)
		{
			Count = Maps.Length - i - 1;
		}
		Maps.insert(i + Count + 1, 1);
		Maps[i + Count + 1] = Maps[i];
		Maps.remove(i, 1);
	}
	Groups[GameIndex].Records[RecordIndex].SetMapItemList(Maps);
	*/
}
int32 AMaplistManager::SetActiveMap(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return - 1;
	}
	Return Groups[GameIndex].Records[RecordIndex].SetActiveMap(MapIndex);
	*/
	return 0;    //FAKE   /ELiZ
}

int32 AMaplistManager::GetGameIndex(FString aGameType)
{
	/*
	local int i;
	if (GameType == "")
	{
		Return - 1;
	}
	for (i = 0; i < Groups.Length; i++)
	{
		if (Groups[i].GameType ~= GameType)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 AMaplistManager::GetCacheGameIndex(FString aGameType)
{
	/*
	local int i;
	for (i = 0; i < CachedGames.Length; i++)
	{
		if (CachedGames[i].ClassName ~= GameType)
		{
			Return i;
		}
	}
	*/
	return -1;
}

TArray<FString> AMaplistManager::GetMapListNames(int GameIndex)
{
	TArray<FString> Arr = {};
	/*
	local int i;
	local int idx;
	local array<MaplistRecord> Records;
	
	if (ValidGameIndex(GameIndex))
	{
		Records = GetRecords(GameIndex);
		if (Records.Length == 0)
		{
			idx = GetCacheGameIndex(Groups[GameIndex].GameType);
			CreateDefaultList(idx);
			Records = GetRecords(GameIndex);
		}
		Arr.Length = Records.Length;
		for (i = 0; i < Records.Length; i++)
		{
			Arr[i] = Records[i].GetTitle();
		}
	}
	*/
	return Arr;
}

TArray<FString> AMaplistManager::GetCurrentMapRotation()
{
	TArray<FString> Ar = {};
	/*
	local int GameIndex;
	local int RecordIndex;
	local int CurrentMap;
	local int i;
	
	if (Level.Game == None)
	{
		Return Ar;
	}
	GameIndex = GetGameIndex(Level.Game.Class);
	RecordIndex = GetActiveList(GameIndex);
	CurrentMap = GetActiveMap(GameIndex, RecordIndex);
	for (Ar = GetMapList(GameIndex, RecordIndex); i < CurrentMap; Ar[Ar.Length] = Ar[i++])
	{
	}
	if (i > 0 && Ar.Length > 0)
	{
		Ar.remove(0, i);
	}
	*/
	return Ar;
}

void AMaplistManager::GetActiveMapName(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].GetActiveMapName();
	}
	*/
}

void AMaplistManager::GetMapTitle(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].GetMapName(MapIndex);
	}
	*/
}

void AMaplistManager::GetMapURL(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].GetMapURL(MapIndex);
	}
	*/
}

TArray<FString> AMaplistManager::GetMapList(int32 GameIndex, int32 RecordIndex)
{
	TArray<FString> Maps = {};
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Maps = Groups[GameIndex].Records[RecordIndex].GetAllMapURL();
	}
	*/
	return Maps;
}

bool AMaplistManager::GetAvailableMaps(int32 GameIndex, TArray<FMapItem> &Ar)
{
	/*
	if (!ValidGameIndex(GameIndex))
	{
		return false;
	}
	Ar = Groups[GameIndex].AllMaps;
	*/
	return true;
}

TArray<FString> AMaplistManager::GetCacheMapList(FString Acronym)
{
	TArray<FString> Arr;
	/*
	local int i;
	local int j;
	local array<CacheManager.MapRecord> TempRecords;
	
	'CacheManager'.GetMapList(TempRecords, Acronym);
	Arr.Length = TempRecords.Length;
	for (i = TempRecords.Length - 1; i >= 0; i--)
	{
		Arr[j++] = TempRecords[i].MapName;
	}
	*/

	return Arr;
}

int32 AMaplistManager::FindMaplistContaining(int32 GameIndex, FString MapName)
{
	/*
	local int i;
	local int idx;
	if (ValidGameIndex(GameIndex))
	{
		for (i = 0; i < Groups[GameIndex].Records.Length; i++)
		{
			idx = Groups[GameIndex].Records[i].GetMapIndex(MapName);
			if (idx != -1)
			{
				Return i;
			}
		}
	}
	*/
	return -1;
}

int32 AMaplistManager::GetMapIndex(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].GetMapIndex(MapName);
	}
	*/
	return -1;
}

int32 AMaplistManager::GetRecordIndex(int32 GameIndex, FString MapListName)
{
	/*
	local int i;
	local array<MaplistRecord> Records;
	if (ValidGameIndex(GameIndex))
	{
		if (MapListName == "")
		{
			Return GetActiveList(GameIndex);
		}
		Records = GetRecords(GameIndex);
		for (i = 0; i < Records.Length; i++)
		{
			if (Records[i] != None && Records[i].GetTitle() ~= MapListName)
			{
				Return i;
			}
		}
	}
	*/
	return -1;
}
FString AMaplistManager::GetMapListTitle(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].GetTitle();
	}
	*/
	return "";
}
int32 AMaplistManager::GetActiveList(int32 GameIndex)
{
	/*
	if (ValidGameIndex(GameIndex))
	{
		Return Groups[GameIndex].Active;
	}
	*/
	return -1;
}
int32 AMaplistManager::GetActiveMap(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return - 1;
	}
	Return Groups[GameIndex].Records[RecordIndex].GetActiveMapIndex();
	*/
	return 0;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidCacheGameIndex(int32 i)
{
	//Return i >= 0 && i < CachedGames.Length;
	return false;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidGameIndex(int32 i)
{
	//Return i >= 0 && i < Groups.Length;
	return false;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidGameType(FString aGameType)
{
	/*
	local int i;
	for (i = 0; i < CachedGames.Length; i++)
	{
		if (GameType ~= CachedGames[i].ClassName)
		{
			return true;
		}
	}
	*/
	return false;
}

bool AMaplistManager::ValidName(FString S)
{
	/*
	local int i;
	local int j;
	if (S == "")
	{
		return false;
	}
	for (i = 0; i < Groups.Length; i++)
	{
		for (j = 0; j < Groups[i].Records.Length; j++)
		{
			if (Groups[i].Records[j] != None && Groups[i].Records[j].GetTitle() ~= S)
			{
				return true;
			}
		}
	}
	*/
	return false;
}

bool AMaplistManager::MaplistDirty(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Return Groups[GameIndex].Records[RecordIndex].IsDirty() || bDirty;
	}
	*/
	return bDirty;
}