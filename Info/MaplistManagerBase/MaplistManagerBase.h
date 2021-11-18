// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "MaplistManagerBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMaplistManagerBase : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMaplistManagerBase();


	bool ValidGameType(FString GameType);
	bool ValidName(FString S);
	bool ValidCacheGameIndex(int32 i);
	bool ValidGameIndex(int32 i);
	int32 AddList(FString GameType, FString NewName, TArray<FString> Maps);
	int32 RemoveList(int32 GameIndex, int32 RecordIndex);
	void ResetGame(int32 GameIndex);
	void ResetList(int32 GameIndex, int32 RecordIndex);
	int32 RenameList(int32 GameIndex, int32 RecordIndex, FString NewName);
	bool ClearList(int32 GameIndex, int32 RecordIndex);
	bool AddMap(int32 GameIndex, int32 RecordIndex, FString MapName);
	bool RemoveMap(int32 GameIndex, int32 MapIndex, FString MapName);
	int32 GetGameIndex(FString GameType);
	int32 GetMapIndex(int32 GameIndex, int32 RecordIndex, FString MapName);
	int32 GetRecordIndex(int32 GameIndex, FString MapListName);
	FString GetMapListTitle(int32 GameIndex, int32 RecordIndex);
	void GetMapListNames(int32 GameIndex);
	void GetCurrentMapRotation();
	void GetMapList(int32 GameIndex, int32 RecordIndex);
	int32 GetActiveList(int32 GameIndex);
	bool SetActiveList(int32 GameIndex, int32 NewActive);
	int32 GetActiveMap(int32 GameIndex, int32 RecordIndex);
	bool ApplyMapList(int32 GameIndex, int32 RecordIndex);
	void MapChange(FString NewMapName);
	bool SaveGame(int GameIndex);
	bool SaveMapList(int32 GameIndex, int32 RecordIndex);
	void ShiftMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 Count);
	int32 FindCacheGameIndex(FString GameType);
	void GetCacheMapList(FString Acronym);

};
