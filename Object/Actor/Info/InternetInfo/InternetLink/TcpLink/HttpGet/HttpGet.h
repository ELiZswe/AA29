// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "HttpGet.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHttpGet : public ATcpLink
{
	GENERATED_BODY()
public:
	AHttpGet();

	UPROPERTY()			TArray<uint8> RequestedBinary;		// var array<byte> RequestedBinary;
	UPROPERTY()			TArray<FString> RequestedText;		// var array<String> RequestedText;
	UPROPERTY()			int32 _PacketCount;					// var int _PacketCount;
	UPROPERTY()			int32 _ByteCount;					// var int _ByteCount;
	UPROPERTY()			bool _bMadeRequest;					// var bool _bMadeRequest;
	UPROPERTY()			FString _Connection;				// var string _Connection;
	UPROPERTY()			FString _Agent;						// var string _Agent;
	UPROPERTY()			FString _Host;						// var string _Host;
	UPROPERTY()			FString _Protocol;					// var string _Protocol;
	UPROPERTY()			FString _File;						// var string _File;
	UPROPERTY()			FString _Request;					// var string _Request;
	UPROPERTY()			int32 _HostPort;					// var int _HostPort;
	UPROPERTY()			bool _bDebug;						// var bool _bDebug;


	void PostBeginPlay();
	void RequestText(FString FileHost, FString FilePath, int32 HostPort);
	void RequestBinary(FString FileHost, FString FilePath, int32 HostPort);
	void ReceivedText(FString Text);
	void ReceivedLine(FString Line);
	void ReceivedBinary(int32 Count, uint8 B);
	void ReceivedLongBinary(int32 Count, int32 B);
	void Resolved(FIpAddr Addr);
	void Opened();
	void Closed();
	void ResolveFailed();
	void Timer();
	void LogConnectionStatus();


};
