// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "Favorites.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UFavorites : public UObject
{
	GENERATED_BODY()
public:
	UFavorites();

	UPROPERTY(EditAnywhere)								FFavoriteServer				PendingServer;					//var FavoriteServer PendingServer;
	UPROPERTY(EditAnywhere)								FString						PendingBuddy;					//var string PendingBuddy;
	UPROPERTY(EditAnywhere)								bool						bUpdateInProgress;				//var bool bUpdateInProgress;
	UPROPERTY(EditAnywhere)								TArray<FString>				BattleBuddies;					//var array<String> BattleBuddies;
	UPROPERTY(EditAnywhere)								TArray<FFavoriteServer>		FavoriteServers;				//var array<FavoriteServer> FavoriteServers;


	void dOnFavoritesOperationComplete(int32 Result, FString Message);
	void OnSuccessfulUpdate();
	bool StringToFavoriteServer(FFavoriteServer& Server, FString IPAddress);
	void NumFavoriteServers();
	void GetFavoriteServer(int32 Index);
	void MakeFavoriteServersFilter(FString UserName);
	int32 GetIndexOfFavoriteServer(FFavoriteServer Server);
	void InternalOnUpdateFavoritesRequestComplete(int32 ResultCode);
	void InternalOnSuccessfulUpdate_AddServer();
	void InternalOnSuccessfulUpdate_RemoveServer();
	void InternalOnSuccessfulUpdate_AddBattleBuddy();
	void InternalOnSuccessfulUpdate_RemoveBattleBuddy();
	void SpawnRequest(AActor* SpawnActor);
	void AddFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void RemoveFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void NumBattleBuddies();
	void GetBattleBuddy(int32 Index);
	void MakeBattleBuddyFilter(FString UserName);
	int32 GetIndexOfBattleBuddy(FString Buddy);
	void AddBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void RemoveBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith);
	void InternalOnGetFavoritesRequestComplete(int32 ResultCode, TArray<FString> BuddyList, TArray<FString> serverList);
	void RefreshFavoritesFromServer(FString UserName, FString Password, AActor* ActorToSpawnWith);
};
