// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "MapList.generated.h"

UCLASS()
class AMapList : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMapList();

	UPROPERTY(config)									int32				MapNum;				//var config int MapNum;
	UPROPERTY(EditAnywhere, Config, Category="Maps")	TArray<FString>		Maps;				//var(Maps) config TArray<FString> Maps;
	UPROPERTY()											TArray<FMapRecord>	CachedMaps;			//var array<CacheManager.MapRecord> CachedMaps;

	void PreBeginPlay();
	void PostBeginPlay();
	FString GetNextMap();
	FString UpdateMapNum(int32 NewMapNum);
	int32 FindCacheIndex(FString MapName);
	FString GetMap(int32 MapIndex);
	TArray<FString> GetMaps();
	TArray<FString> StaticGetMaps();
	bool HasInvalidMaps(bool bReadOnly);
	bool StaticHasInvalidMaps(bool bReadOnly);
	bool SetMaplist(int32 CurrentNum, TArray<FString> NewMaps);

};
