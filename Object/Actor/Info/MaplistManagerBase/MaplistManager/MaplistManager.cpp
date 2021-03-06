// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/MaplistManagerBase/MaplistManager/MaplistManager.h"
#include "AA29/Object/MaplistRecord/MaplistRecord.h"
#include "AA29/Object/Actor/Info/MapList/MapList.h"

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
	int32 i = 0;
	int32 idx;
	PreBeginPlay();
	'CacheManager'.GetGameTypeList(CachedGames);
	InitializeMaplistRecords();
	for (i = 0; i < CachedGames.Num(); i++)
	{
		idx = AddGroup(CachedGames[i].ClassName);
		if (Groups[idx].Records.Num() <= 0)
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
	if (bDirty)
	{
		Save();
	}
	Super::Destroyed();
}

void AMaplistManager::CreateDefaultList(int32 i)
{
	FString ListName;
	TArray<FString> Arr = {};
	/*
	if (!ValidCacheGameIndex(i))
	{
		return;
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
	AMapList* List = nullptr;
	if (MapListClassName == "")
	{
		return false;
	}
	//List = class<MapList>(DynamicLoadObject(MapListClassName, Class'Class', True));
	if (List == nullptr)
	{
		return false;
	}
	Maps = List->StaticGetMaps();
	return true;
}

void AMaplistManager::InitializeMaplistRecords()
{
	int32 i = 0;
	int32 cnt = 0;
	UMaplistRecord* Rec = nullptr;
	/*
	MaplistRecordNames = GetPerObjectNames("System", "MaplistRecord");
	cnt = MaplistRecordNames.Num();
	for (i = 0; i < Groups.Num(); i++)
	{
		if (Groups[i].Records.Num() > 0)
		{
			Groups[i].Records.RemoveAt(0, Groups[i].Records.Num());
		}
	}
	i = 0;
	if (i < cnt && i < MaplistRecordNames.Num())
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
	int32 i = 0;
	int32 RecordIndex = 0;
	int32 idx = 0;
	/*
	for (i = Games.Num() - 1; i >= 0; i--)
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
			if (RecordIndex < 0 || RecordIndex >= Groups[idx].Records.Num())
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
	int32 j = 0;
	int32 i = 0;
	if (Rec == nullptr || Rec->GetGameType() == "")
	{
		return - 1;
	}
	i = AddGroup(Rec->GetGameType());
	j = Groups[i].Records.Num();
	Rec->SetCacheMaps(Groups[i].AllMaps);
	Groups[i].Records[j] = Rec;
	return j;
}

int32 AMaplistManager::AddGroup(FString aGameType)
{
	int32 i=0;
	/*
	if (GameType == "")
	{
		return - 1;
	}
	i = GetGameIndex(GameType);
	if (i == -1)
	{
		i = Groups.Num();
		Groups.Num() = i + 1;
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
		i = Games.Num();
		Games.Num() = i + 1;
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
	if (i < 0 || i >= Games.Num())
	{
		return false;
	}
	Games.RemoveAt(i, 1);
	bDirty = true;
	*/
	return true;
}

int32 AMaplistManager::RemoveRecord(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return - 1;
	}
	Groups[GameIndex].Records[RecordIndex].ClearConfig();
	Groups[GameIndex].Records.RemoveAt(RecordIndex, 1);
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
	int32 i = 0;
	if (GameType == "")
	{
		return - 1;
	}
	for (i = 0; i < Games.Num(); i++)
	{
		if (Games[i].GameType ~= GameType)
		{
			return i;
		}
	}
	*/
	return -1;
}

void AMaplistManager::Save()
{
	if (bDirty)
	{
		SaveConfig();
		bDirty = false;
	}
}

UMaplistRecord* AMaplistManager::CreateRecord(FString RecordName)
{
	if (RecordName == "")
	{
		return nullptr;
	}
	//return new (NoneRepl(RecordName, " ", Chr(27))) UMaplistRecord::StaticClass();
	return nullptr;   ///FAKE   /ELiZ
}

bool AMaplistManager::IsNewGameType(FString GameClassName)
{
	//return GetStoredGameIndex(GameClassName) == -1;
	return false;    //FAKE   /ELiZ
}

TArray<UMaplistRecord*> AMaplistManager::GetRecords(int32 GameIndex)
{
	if (ValidGameIndex(GameIndex))
	{
		return Groups[GameIndex].Records;
	}
	return {};    //FAKE   /ELiZ
}

bool AMaplistManager::ValidRecordIndex(int32 GameIndex, int MapListIndex)
{
	//return ValidGameIndex(GameIndex) && MapListIndex >= 0 && MapListIndex < Groups[GameIndex].Records.Num()&& Groups[GameIndex].Records[MapListIndex] != nullptr;
	return true;    //FAKE    /ELiZ
}

void AMaplistManager::MapChange(FString NewMap)
{
	/*
	int32 i = 0;
	int32 GameIndex;
	int32 RecordIndex;
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
	UMaplistRecord* NewRecord =nullptr;
	FString DesiredName = "";
	/*
	if (!ValidGameType(GameType))
	{
		return - 1;
	}
	DesiredName = NewName;
	if (ValidName(NewName))
	{
		NewName = DesiredName + i++;
	}
	if (Len(NewName) > 512)
	{
		return - 1;
	}
	NewRecord = CreateRecord(NewName);
	if (NewRecord == nullptr)
	{
		return - 1;
	}
	NewRecord.SetGameType(GameType);
	NewRecord.SetTitle(NewName);
	i = AddMaplistRecord(NewRecord);
	if (Maps.Num() == 0)
	{
		NewRecord.Clear(true);
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
	UMaplistRecord* OldRecord = nullptr;
	bool IsActive = false;
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return - 1;
	}
	if (NewName == "")
	{
		return - 1;
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
		return GetActiveList(GameIndex);
	}
	idx = RemoveRecord(GameIndex, RecordIndex);
	if (Groups[GameIndex].Records.Num() == 0)
	{
		i = GetCacheGameIndex(Groups[GameIndex].GameType);
		CreateDefaultList(i);
	}
	if (Groups[GameIndex].Active < 0 || Groups[GameIndex].Active == RecordIndex || Groups[GameIndex].Active >= Groups[GameIndex].Records.Num())
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
		return;
	}
	Groups[GameIndex].Records[RecordIndex].CancelChanges();
	*/
}
bool AMaplistManager::SaveGame(int32 GameIndex)
{
	/*
	int32 i = 0;
	int32 Active;
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
	for (i = 0; i < Groups[GameIndex].Records.Num(); i++)
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
	int32 i = 0;
	int32 RecordIndex;
	if (!ValidGameIndex(GameIndex))
	{
		return;
	}
	for (i = 0; i < Groups[GameIndex].Records.Num(); i++)
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
	AMapList* ListClass = nullptr;
	int32 i = 0;
	/*
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
		if (ListClass == nullptr)
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
	int32 i = 0;
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
		return Groups[GameIndex].Records[RecordIndex].AddMap(MapName);
	}
	*/
	return false;
}

bool AMaplistManager::InsertMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 ListIndex)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		return Groups[GameIndex].Records[RecordIndex].InsertMap(MapName, ListIndex);
	}
	*/
	return false;
}

bool AMaplistManager::RemoveMap(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	/*
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		return Groups[GameIndex].Records[RecordIndex].RemoveMap(MapName);
	}
	*/
	return false;
}

void AMaplistManager::ShiftMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 Count)
{
	int32 i = 0;
	TArray<FMapItem> Maps = {};
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return;
	}
	if (Count == 0)
	{
		return;
	}
	i = Groups[GameIndex].Records[RecordIndex].GetMapIndex(MapName);
	if (i == -1)
	{
		return;
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
		Maps.RemoveAt(i + 1, 1);
	}
	else
	{
		if (i + Count + 1 >= Maps.Num())
		{
			Count = Maps.Num() - i - 1;
		}
		Maps.insert(i + Count + 1, 1);
		Maps[i + Count + 1] = Maps[i];
		Maps.RemoveAt(i, 1);
	}
	Groups[GameIndex].Records[RecordIndex].SetMapItemList(Maps);
	*/
}
int32 AMaplistManager::SetActiveMap(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return - 1;
	}
	return Groups[GameIndex].Records[RecordIndex].SetActiveMap(MapIndex);
	*/
	return 0;    //FAKE   /ELiZ
}

int32 AMaplistManager::GetGameIndex(FString aGameType)
{
	/*
	int32 i = 0;
	if (GameType == "")
	{
		return - 1;
	}
	for (i = 0; i < Groups.Num(); i++)
	{
		if (Groups[i].GameType ~= GameType)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 AMaplistManager::GetCacheGameIndex(FString aGameType)
{
	/*
	int32 i = 0;
	for (i = 0; i < CachedGames.Num(); i++)
	{
		if (CachedGames[i].ClassName ~= GameType)
		{
			return i;
		}
	}
	*/
	return -1;
}

TArray<FString> AMaplistManager::GetMapListNames(int32 GameIndex)
{
	TArray<FString> Arr = {};
	int32 i = 0;
	int32 idx = 0;
	TArray<UMaplistRecord*> Records = {};
	/*
	if (ValidGameIndex(GameIndex))
	{
		Records = GetRecords(GameIndex);
		if (Records.Num() == 0)
		{
			idx = GetCacheGameIndex(Groups[GameIndex].GameType);
			CreateDefaultList(idx);
			Records = GetRecords(GameIndex);
		}
		Arr.Num() = Records.Num();
		for (i = 0; i < Records.Num(); i++)
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
	int32 GameIndex = 0;
	int32 RecordIndex = 0;
	int32 CurrentMap = 0;
	int32 i = 0;
	/*
	if (Level.Game == nullptr)
	{
		return Ar;
	}
	GameIndex = GetGameIndex(Level.Game.Class);
	RecordIndex = GetActiveList(GameIndex);
	CurrentMap = GetActiveMap(GameIndex, RecordIndex);
	for (Ar = GetMapList(GameIndex, RecordIndex); i < CurrentMap; Ar[Ar.Num()] = Ar[i++])
	{
	}
	if (i > 0 && Ar.Num() > 0)
	{
		Ar.RemoveAt(0, i);
	}
	*/
	return Ar;
}

FString AMaplistManager::GetActiveMapName(int32 GameIndex, int32 RecordIndex)
{
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		return Groups[GameIndex].Records[RecordIndex]->GetActiveMapName();
	}
	return "";
}

FString AMaplistManager::GetMapTitle(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		return Groups[GameIndex].Records[RecordIndex]->GetMapName(MapIndex);
	}
	return "";
}

FString AMaplistManager::GetMapURL(int32 GameIndex, int32 RecordIndex, int32 MapIndex)
{
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		return Groups[GameIndex].Records[RecordIndex]->GetMapURL(MapIndex);
	}
	return "";
}

TArray<FString> AMaplistManager::GetMapList(int32 GameIndex, int32 RecordIndex)
{
	TArray<FString> Maps = {};
	if (ValidRecordIndex(GameIndex, RecordIndex))
	{
		Maps = Groups[GameIndex].Records[RecordIndex]->GetAllMapURL();
	}
	return Maps;
}

bool AMaplistManager::GetAvailableMaps(int32 GameIndex, TArray<FMapItem> &Ar)
{
	if (!ValidGameIndex(GameIndex))
	{
		return false;
	}
	Ar = Groups[GameIndex].AllMaps;
	return true;
}

TArray<FString> AMaplistManager::GetCacheMapList(FString Acronym)
{
	TArray<FString> Arr;
	TArray<FMapRecord> TempRecords = {};
	int32 i = 0;
	int32 j = 0;
	/*
	'CacheManager'.GetMapList(TempRecords, Acronym);
	Arr.Num() = TempRecords.Num();
	for (i = TempRecords.Num() - 1; i >= 0; i--)
	{
		Arr[j++] = TempRecords[i].MapName;
	}
	*/

	return Arr;
}

int32 AMaplistManager::FindMaplistContaining(int32 GameIndex, FString MapName)
{
	/*
	int32 i = 0;
	int32 idx;
	if (ValidGameIndex(GameIndex))
	{
		for (i = 0; i < Groups[GameIndex].Records.Num(); i++)
		{
			idx = Groups[GameIndex].Records[i].GetMapIndex(MapName);
			if (idx != -1)
			{
				return i;
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
		return Groups[GameIndex].Records[RecordIndex].GetMapIndex(MapName);
	}
	*/
	return -1;
}

int32 AMaplistManager::GetRecordIndex(int32 GameIndex, FString MapListName)
{
	int32 i = 0;
	TArray<UMaplistRecord*> Records = {};
	/*
	if (ValidGameIndex(GameIndex))
	{
		if (MapListName == "")
		{
			return GetActiveList(GameIndex);
		}
		Records = GetRecords(GameIndex);
		for (i = 0; i < Records.Num(); i++)
		{
			if (Records[i] != nullptr && Records[i].GetTitle() ~= MapListName)
			{
				return i;
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
		return Groups[GameIndex].Records[RecordIndex].GetTitle();
	}
	*/
	return "";
}

int32 AMaplistManager::GetActiveList(int32 GameIndex)
{
	/*
	if (ValidGameIndex(GameIndex))
	{
		return Groups[GameIndex].Active;
	}
	*/
	return -1;
}
int32 AMaplistManager::GetActiveMap(int32 GameIndex, int32 RecordIndex)
{
	/*
	if (!ValidRecordIndex(GameIndex, RecordIndex))
	{
		return - 1;
	}
	return Groups[GameIndex].Records[RecordIndex].GetActiveMapIndex();
	*/
	return 0;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidCacheGameIndex(int32 i)
{
	//return i >= 0 && i < CachedGames.Num();
	return false;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidGameIndex(int32 i)
{
	//return i >= 0 && i < Groups.Num();
	return false;    //FAKE   /ELiZ
}

bool AMaplistManager::ValidGameType(FString aGameType)
{
	/*
	int32 i = 0;
	for (i = 0; i < CachedGames.Num(); i++)
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
	int32 i = 0;
	int32 j = 0;
	if (S == "")
	{
		return false;
	}
	for (i = 0; i < Groups.Num(); i++)
	{
		for (j = 0; j < Groups[i].Records.Num(); j++)
		{
			if (Groups[i].Records[j] != nullptr && Groups[i].Records[j].GetTitle() ~= S)
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
		return Groups[GameIndex].Records[RecordIndex].IsDirty() || bDirty;
	}
	*/
	return bDirty;
}
