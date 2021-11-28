// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/MaplistManagerBase/MaplistManagerBase.h"

AMaplistManagerBase::AMaplistManagerBase()
{

}

bool AMaplistManagerBase::ValidGameType(FString aGameType)
{
	return false;
}

bool AMaplistManagerBase::ValidName(FString S)
{
	return false;
}

bool AMaplistManagerBase::ValidCacheGameIndex(int32 i)
{
	return false;
}
bool AMaplistManagerBase::ValidGameIndex(int32 i)
{
	return false;
}
int32 AMaplistManagerBase::AddList(FString aGameType, FString NewName, TArray<FString> Maps)
{
	return - 1;
}
int32 AMaplistManagerBase::RemoveList(int32 GameIndex, int32 RecordIndex)
{
	return - 1;
}

void AMaplistManagerBase::ResetGame(int32 GameIndex)
{
}

void AMaplistManagerBase::ResetList(int32 GameIndex, int32 RecordIndex)
{
}

int32 AMaplistManagerBase::RenameList(int32 GameIndex, int32 RecordIndex, FString NewName)
{
	return - 1;
}

bool AMaplistManagerBase::ClearList(int32 GameIndex, int32 RecordIndex)
{
	return true;
}

bool AMaplistManagerBase::AddMap(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	return false;
}

bool AMaplistManagerBase::RemoveMap(int32 GameIndex, int32 MapIndex, FString MapName)
{
	return false;
}

int32 AMaplistManagerBase::GetGameIndex(FString aGameType)
{
	return - 1;
}

int32 AMaplistManagerBase::GetMapIndex(int32 GameIndex, int32 RecordIndex, FString MapName)
{
	return - 1;
}

int32 AMaplistManagerBase::GetRecordIndex(int32 GameIndex, FString MapListName)
{
	return - 1;
}

FString AMaplistManagerBase::GetMapListTitle(int32 GameIndex, int32 RecordIndex)
{
	return "";
}

void AMaplistManagerBase::GetMapListNames(int32 GameIndex)
{
}

void AMaplistManagerBase::GetCurrentMapRotation()
{
}

void AMaplistManagerBase::GetMapList(int32 GameIndex, int32 RecordIndex)
{
}

int32 AMaplistManagerBase::GetActiveList(int32 GameIndex)
{
	return -1;
}

bool AMaplistManagerBase::SetActiveList(int32 GameIndex, int32 NewActive)
{
	return true;
}

int32 AMaplistManagerBase::GetActiveMap(int32 GameIndex, int32 RecordIndex)
{
	return -1;
}

bool AMaplistManagerBase::ApplyMapList(int32 GameIndex, int32 RecordIndex)
{
	return false;
}

void AMaplistManagerBase::MapChange(FString NewMapName)
{
}

bool AMaplistManagerBase::SaveGame(int GameIndex)
{
	return true;
}

bool AMaplistManagerBase::SaveMapList(int32 GameIndex, int32 RecordIndex)
{
	return true;
}

void AMaplistManagerBase::ShiftMap(int32 GameIndex, int32 RecordIndex, FString MapName, int32 Count)
{
}

int32 AMaplistManagerBase::FindCacheGameIndex(FString aGameType)
{
	return - 1;
}

void AMaplistManagerBase::GetCacheMapList(FString Acronym)
{
}
