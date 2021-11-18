// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetInfo.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "InternetLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInternetLink : public AInternetInfo
{
	GENERATED_BODY()
public:
	AInternetLink();

	UPROPERTY()			EReceiveMode ReceiveMode;					//var EReceiveMode ReceiveMode;
	UPROPERTY()			int32 DataPending;							//var const int DataPending;
	UPROPERTY()			Fpointer PrivateResolveInfo;				//var const native transient pointer PrivateResolveInfo;
	UPROPERTY()			Fpointer RemoteSocket;						//var const transient pointer RemoteSocket;
	UPROPERTY()			int32 Port;									//var const int Port;
	UPROPERTY()			Fpointer Socket;							//var const transient pointer Socket;
	UPROPERTY()			ELineMode OutLineMode;						//var ELineMode OutLineMode;
	UPROPERTY()			ELineMode InLineMode;						//var ELineMode InLineMode;
	UPROPERTY()			ELinkMode LinkMode;							//var ELinkMode LinkMode;

	void IsDataPending();
	void ParseURL(FString URL, FString &Addr, int32 &APort, FString LevelName, FString &EntryName);
	void Resolve(FString Domain);
	void GetLastError();
	void IpAddrToString(FIpAddr Arg);
	void StringToIpAddr(FString str, FIpAddr &Addr, bool hostOrder);
	void GameSpyValidate(FString ValidationString);
	void GameSpyGameName();
	void GetLocalHostName();
	void GetLocalIP(FIpAddr &Arg);
	FString GetLocalIPAsString();
	void Resolved(FIpAddr Addr);
	void ResolveFailed();
	void PostResolved();


};
