// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "MapList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AMapList : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMapList();

	UPROPERTY(config)									int32 MapNum;							//var config int MapNum;
	UPROPERTY(EditAnywhere, Config, Category="Maps")	TArray<FString> Maps;					//var(Maps) config array<String> Maps;
	UPROPERTY()											TArray<FMapRecord> CachedMaps;			//var array<CacheManager.MapRecord> CachedMaps;



	void PreBeginPlay();
	void PostBeginPlay();
	void GetNextMap();
	void UpdateMapNum(int32 NewMapNum);
	void FindCacheIndex(FString MapName);
	void GetMap(int32 MapIndex);
	void GetMaps();
	void StaticGetMaps();
	void HasInvalidMaps(bool bReadOnly);
	void StaticHasInvalidMaps(bool bReadOnly);
	void SetMaplist(int32 CurrentNum, TArray<FString> NewMaps);

};
