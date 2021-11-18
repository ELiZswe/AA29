// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "HttpLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHttpLink : public ATcpLink
{
	GENERATED_BODY()
public:
	AHttpLink();

	UPROPERTY()			bool bDebugMD5;									//var bool bDebugMD5;
	UPROPERTY()			int32 MAX_RETRIES;								//var int MAX_RETRIES;
	UPROPERTY()			int32 RetryAttempts;							//var int RetryAttempts;
	UPROPERTY()			bool bPaused;									//var bool bPaused;
	UPROPERTY()			bool bVerboseLogging;							//var bool bVerboseLogging;
	UPROPERTY()			bool bConnectionBusy;							//var bool bConnectionBusy;
	UPROPERTY()			bool bResolvedHost;								//var bool bResolvedHost;
	UPROPERTY()			FString LocalFilePath;							//var string LocalFilePath;
	//UPROPERTY()			TArray<AHttpLinkItem*> QueuedFiles;				//var array<HttpLinkItem> QueuedFiles;
	UPROPERTY()			FIpAddr ResolvedAddr;							//var InternetLink.IpAddr ResolvedAddr;
	UPROPERTY()			FString CacheFileName;							//var string CacheFileName;
	UPROPERTY()			FString TargetVersionFolder;					//var string TargetVersionFolder;
	UPROPERTY()			int32 TargetPort;								//var int TargetPort;
	UPROPERTY()			FString TargetHost;								//var string TargetHost;

	void CheckBinaryMD5(TArray<uint8> File);
	void CheckTextMD5(FString File);
	void PauseDownloads();
	void ResumeDownloads();
	void SetHost(FString Host, int32 HostPort);
	void SetLocalFilePath(FString ContentPath);
	void Connect();
	void Disconnect();
	void RequestText(FString FilePath);
	void RequestBinary(FString FilePath);
	void GetNextFile();
	void Opened();
	void Resolved(FIpAddr Addr);
	void ReceivedText(FString Text);
	void ReceivedBinary(int32 Count, uint8 B);
	void Closed();
	void StripTextHTTPHeader(FString ResponseToStrip);
	void StripBinaryHTTPHeader(TArray<uint8> B);
	void ResolveFailed();
	void CheckHTTPResponse();
	void AddCurrentFileToCache();
	void DeleteFileFromCache(FString CachedFile);
	void DoesFileExist(FString Filename);
	void ParseCurrentHTTPHeader(FString FieldName);
	FString FixFilePath(FString FilePath);

};
