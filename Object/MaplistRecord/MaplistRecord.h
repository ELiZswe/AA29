// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "MaplistRecord.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UMaplistRecord : public UObject
{
	GENERATED_BODY()
public:
		UMaplistRecord();

		UPROPERTY()				bool bDirty;									//var bool bDirty;
		UPROPERTY()				FString Title;									//var string Title;								// Title of this custom maplist
		UPROPERTY()				FString GameType;								//var string GameType;							// The gametype associated with this custom maplist
		UPROPERTY()				int32 Active;									//var int Active;								// The index of the currently active map
		UPROPERTY()				TArray<FMapItem> Maps;							//var array<MapItem> Maps;

//	accessing default values of PerObjectConfig objects doesn't work as desired
//  (does not access the default values for that object)

		UPROPERTY(Config)		FString DefaultTitle;							//var config string DefaultTitle;
		UPROPERTY(Config)		FString DefaultGameType;						//var config string DefaultGameType;
		UPROPERTY(Config)		int32 DefaultActive;							//var config int DefaultActive;
		UPROPERTY(Config)		TArray<FString> DefaultMaps;					//var config array<String> DefaultMaps;
		UPROPERTY()				TArray<FMapItem> CachedMaps;					//var array<MapItem> CachedMaps;

		bool CompareItems(FMapItem A, FMapItem B);
		bool CompareItemsSlow(FMapItem A, FMapItem B);
		void Created();
		void SetCacheMaps(TArray<FMapItem> CacheMaps);
		void SetTitle(FString NewTitle);
		void SetGameType(FString NewGameType);
		void SetActiveMap(int32 i);
		void SetMaplist(TArray<FString> NewMaps);
		void SetMapItemList(TArray<FMapItem> NewMaps);
		void Save();
		void VerifyMaps();
		void CancelChanges();
		void Clear(bool bReset);
		bool AddOptionString(int32 MapIndex, FString OptionString);
		bool RemoveOptionString(int32 MapIndex, FString OptionString);
		void RefreshMapItem(int32 MapIndex);
		void AddMap(FString MapName);
		void InsertMap(FString MapName, int32 Index);
		void RemoveMap(FString MapName);
		void SetMapOptions(int32 MapIndex, FString OptionString);
		FString GetTitle();
		FString GetGameType();
		FString GetActiveMapName();
		FString GetActiveMapURL();
		FString GetMapName(int32 i);
		FString GetMapURL(int32 Index);
		TArray<FMapItem> GetMaps();
		TArray<FString> GetAllMapURL();
		bool IsDirty();
		void GetCacheIndex(FString MapName);
		int32 GetActiveMapIndex();
		int32 GetMapIndex(FString MapName);
		int32 GetMapItemIndex(FMapItem Item);
		bool ValidMap(FString MapName);
		bool ValidIndex(int i);
		bool ValidOptionIndex(int MapIndex, int OptionIndex);
		FString GetBaseMapName(FString FullMapURL);
		bool CreateMapItem(FString FullMapURL, FMapItem Item);
		void CreateMapItemList(TArray<FString> MapURLs, TArray<FMapItem> MapItems);

};
