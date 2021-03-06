// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "Favorites.generated.h"

class AUpdateFavoritesRequestAdapter;

UCLASS()
class UFavorites : public UObject
{
	GENERATED_BODY()
public:
	UFavorites();

	UPROPERTY()			FFavoriteServer				PendingServer;					//var FavoriteServer PendingServer;
	UPROPERTY()			FString						PendingBuddy;					//var string PendingBuddy;
	UPROPERTY()			bool						bUpdateInProgress;				//var bool bUpdateInProgress;
	UPROPERTY()			TArray<FString>				BattleBuddies;					//var TArray<FString> BattleBuddies;
	UPROPERTY()			TArray<FFavoriteServer>		FavoriteServers;				//var array<FavoriteServer> FavoriteServers;

	void dOnFavoritesOperationComplete(int32 Result, FString Message);
	void OnSuccessfulUpdate();
	bool StringToFavoriteServer(FFavoriteServer& Server, FString IPAddress);
	int32 NumFavoriteServers();
	FFavoriteServer GetFavoriteServer(int32 Index);
	TArray<FFilterItem> MakeFavoriteServersFilter(FString UserName);
	int32 GetIndexOfFavoriteServer(FFavoriteServer Server);
	void InternalOnUpdateFavoritesRequestComplete(int32 ResultCode);
	void InternalOnSuccessfulUpdate_AddServer();
	void InternalOnSuccessfulUpdate_RemoveServer();
	void InternalOnSuccessfulUpdate_AddBattleBuddy();
	void InternalOnSuccessfulUpdate_RemoveBattleBuddy();
	AUpdateFavoritesRequestAdapter* SpawnRequest(AActor* SpawnActor);
	void AddFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void RemoveFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith);
	int32 NumBattleBuddies();
	FString GetBattleBuddy(int32 Index);
	TArray<FFilterItem> MakeBattleBuddyFilter(FString UserName);
	int32 GetIndexOfBattleBuddy(FString Buddy);
	void AddBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void RemoveBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void InternalOnGetFavoritesRequestComplete(int32 ResultCode, TArray<FString> BuddyList, TArray<FString> serverList);
	void RefreshFavoritesFromServer(FString UserName, FString Password, AActor* ActorToSpawnWith);
};
