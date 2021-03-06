// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "AuthorizeServerRequestAdapter.generated.h"

UCLASS()
class AAuthorizeServerRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
	
public:
	AAuthorizeServerRequestAdapter();

	UPROPERTY()						FString	ServerModeName;						//var string ServerModeName;
	UPROPERTY()						int32	ServerModeId;						//var int ServerModeId;
	UPROPERTY(globalconfig)			FString ServerAuthPassword;					//var globalconfig string ServerAuthPassword;
	UPROPERTY(globalconfig)			FString ServerAuthUsername;					//var globalconfig string ServerAuthUsername;

	void GetServerAuthUsername();
	void GetServerAuthPassword();
	void GetLegacyServerAuthIP();
	void Request(FString IPAddress, int32 Port, int32 Tour, int32 Mission, int32 MaxPlayers, FString ServerPassword, FString sAuthMapData);
	void AdaptResults();
	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	FString GetServerAuthIP();
	void SetServerAuthUsername(FString UserName);
	void SetServerAuthPassword(FString Password);
};
