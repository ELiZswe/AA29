// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"

#include "CacheManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCacheManager : public UObject
{
	GENERATED_BODY()
public:
	UCacheManager();


	UPROPERTY()											Fpointer Tracker;											//var const native transient pointer Tracker;
	UPROPERTY()											Fpointer FileManager;										//var const native transient pointer FileManager;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FAnnouncerRecord> CacheAnnouncers;					//var() const array<AnnouncerRecord> CacheAnnouncers;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FGameRecord> CacheGameTypes;							//var() const array<GameRecord> CacheGameTypes;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FCrosshairRecord> CacheCrosshairs;					//var() const array<CrosshairRecord> CacheCrosshairs;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FVehicleRecord> CacheVehicles;						//var() const array<VehicleRecord> CacheVehicles;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FWeaponRecord> CacheWeapons;							//var() const array<WeaponRecord> CacheWeapons;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FMapRecord> CacheMaps;								//var() const array<MapRecord> CacheMaps;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FMutatorRecord> CacheMutators;						//var() const array<MutatorRecord> CacheMutators;
	UPROPERTY(EditAnywhere, BluePrintReadWrite)			TArray<FStandard> DefaultContent;							//var() const array<Standard> DefaultContent;




	void InitCache();
	void Is2003Content(FString Item);
	void Is2004Content(FString Item);
	void IsBPContent(FString Item);
	void IsDefaultContent(FString Item);
	void GetGameTypeList(TArray<FGameRecord> GameRecords, FString FilterType);
	void GetMapList(TArray<FMapRecord> MapRecords, FString Acronym);
	void GetWeaponList(TArray<FWeaponRecord> WeaponRecords);
	void GetVehicleList(TArray<FVehicleRecord> VehicleRecords);
	void GetCrosshairList(TArray<FCrosshairRecord> CrosshairRecords);
	void GetMutatorList(TArray<FMutatorRecord> MutatorRecords);
	void GetAnnouncerList(TArray<FAnnouncerRecord> AnnouncerRecords);
	void GetTeamSymbolList(TArray<FString> FSymbolNames, bool bNoSinglePlayer);
	void GetGameRecord(FString ClassName);
	void GetMapRecord(FString MapName);
	void GetMutatorRecord(FString ClassName);
	void GetWeaponRecord(FString ClassName);
	void GetVehicleRecord(FString ClassName);
	void GetAnnouncerRecord(FString ClassName);

};
