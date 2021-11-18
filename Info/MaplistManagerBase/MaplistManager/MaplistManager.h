// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/MaplistManagerBase/MaplistManagerBase.h"
#include "AA29/AA29.h"
#include "MaplistManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMaplistManager : public AMaplistManagerBase
{
	GENERATED_BODY()
public:
	AMaplistManager();

	UPROPERTY()					bool bDirty;								//var bool bDirty;
	UPROPERTY(EditAnywhere)		FString DefaultListExists;					//var() localized string DefaultListExists;
	UPROPERTY(EditAnywhere)		FString ReallyInvalidGameType;				//var() localized string ReallyInvalidGameType;
	UPROPERTY(EditAnywhere)		FString InvalidGameType;					//var() localized string InvalidGameType;
	UPROPERTY(EditAnywhere)		FString DefaultListName;					//var() localized string DefaultListName;
	UPROPERTY()					TArray<FMaplistRecordGroup> Groups;			//var array<MaplistRecordGroup> Groups;
	UPROPERTY()					TArray<FGameRecord> CachedGames;			//var array<CacheManager.GameRecord> CachedGames;
	UPROPERTY()					TArray<FString> MaplistRecordNames;			//var array<String> MaplistRecordNames;
	UPROPERTY(config)			FString Games;								//var config array<GameRecordGroup> Games;


	void PreBeginPlay();
	void Destroyed();
	void CreateDefaultList(int32 i);
	bool GetDefaultMaps(FString MapListClassName, TArray<FString>& Maps);
	void InitializeMaplistRecords();
	void InitializeActiveLists();
	int32 AddMaplistRecord(UMaplistRecord* Rec);
	int32 AddGroup(FString aGameType);
	int32 AddGameType(FString NewGameType);
	void GenerateGroupMaplist(int32 GroupIndex);
	bool RemoveGame(int32 i);
	int32 RemoveRecord(int32 GameIndex, int32 RecordIndex);
	int32 GetStoredGameIndex(FString aGameType);
	void Save();
	void CreateRecord(FString RecordName);
	bool IsNewGameType(FString GameClassName);
	void GetRecords(int32 GameIndex);
	bool ValidRecordIndex(int GameIndex, int MapListIndex);
	void MapChange(FString NewMap);
	int32 AddList(FString aGameType, FString NewName, TArray<FString> Maps);
	int32 RenameList(int32 GameIndex, int32 RecordIndex, FString NewName);
	int32 RemoveList(int32 GameIndex, int32 RecordIndex);
	bool SaveMapList(int32 GameIndex, int32 RecordIndex);
	bool ClearList(int32 GameIndex, int32 RecordIndex);
	void ResetList(int32 GameIndex, int32 RecordIndex);
	bool SaveGame(int32 GameIndex);
	void ResetGame(int32 GameIndex);
	bool ApplyMapList(int32 GameIndex, int32 RecordIndex);
	bool SetActiveList(int32 GameIndex, int32 NewActive);
	bool AddMap(int32 GameIndex, int32 RecordIndex, FString MapName);
	bool InsertMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 ListIndex);
	bool RemoveMap(int32 GameIndex, int32 RecordIndex, FString MapName);
	void ShiftMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 Count);
	int32 SetActiveMap(int32 GameIndex, int32 RecordIndex, int32 MapIndex);
	int32 GetGameIndex(FString aGameType);
	int32 GetCacheGameIndex(FString aGameType);
	TArray<FString> GetMapListNames(int GameIndex);
	TArray<FString> GetCurrentMapRotation();
	void GetActiveMapName(int32 GameIndex, int32 RecordIndex);
	void GetMapTitle(int32 GameIndex, int32 RecordIndex, int32 MapIndex);
	void GetMapURL(int32 GameIndex, int32 RecordIndex, int32 MapIndex);
	TArray<FString> GetMapList(int32 GameIndex, int32 RecordIndex);
	bool GetAvailableMaps(int32 GameIndex, TArray<FMapItem>& Ar);
	TArray<FString> GetCacheMapList(FString Acronym);
	int32 FindMaplistContaining(int32 GameIndex, FString MapName);
	int32 GetMapIndex(int32 GameIndex, int32 RecordIndex, FString MapName);
	int32 GetRecordIndex(int32 GameIndex, FString MapListName);
	FString GetMapListTitle(int32 GameIndex, int32 RecordIndex);
	int32 GetActiveList(int32 GameIndex);
	int32 GetActiveMap(int32 GameIndex, int32 RecordIndex);
	bool ValidCacheGameIndex(int32 i);
	bool ValidGameIndex(int32 i);
	bool ValidGameType(FString aGameType);
	bool ValidName(FString S);
	bool MaplistDirty(int32 GameIndex, int32 RecordIndex);
};
