// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AGP_ServerInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ServerInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AAGP_ServerInfo();

	UPROPERTY()			int32 numCurrentServerSettings;							//var int numCurrentServerSettings;
	UPROPERTY()			TArray<FServerSettings> CurrentServerSettings;			//var array<ServerSettings> CurrentServerSettings;


	void PreBeginPlay();
	int32 GetSettingsCount();
	FString GetKey(int32 Index);
	void SetKey(int32 Index, FString Key);
	FString GetKeyValue(int32 Index);
	void SetKeyValue(int32 Index, FString Value);
	void UpdateServerKey(int32 Index, FString Key);
	void UpdateServerKeyValue(int32 Index, FString Value);
	void RefreshServerSettings();
	void ServerRequestServerInfo(bool bUpdate);
	void ClientReceiveServerInfo(int32 Index, FString Key, FString Value, bool bUpdate);


};
