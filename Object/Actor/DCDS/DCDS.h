// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AA29.h"
#include "GameFramework/Actor.h"
#include "DCDS.generated.h"

UCLASS(Config = Game)
class ADCDS : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ADCDS();

	UPROPERTY()							Fpointer						DCDSSDK;							//var const native transient Fpointer DCDSSDK;
	UPROPERTY()							Fpointer						AssetRequest;						//var const native transient Fpointer AssetRequest;
	UPROPERTY()							FString							TemporaryDownloadPath;				//var FString TemporaryDownloadPath;
	UPROPERTY()							FString							DestinationPath;					//var FString DestinationPath;
	UPROPERTY()							FString							AssetFileName;						//var FString AssetFileName;
	UPROPERTY()							FString							UserName;							//var FString UserName;
	UPROPERTY()							FString							Password;							//var FString Password;
	UPROPERTY()							int32							AssetSize;							//var int32 AssetSize;
	UPROPERTY()							FString							SHA;								//var FString SHA;
	UPROPERTY()							float							DownloadStartTimestamp;				//var float DownloadStartTimestamp;
	UPROPERTY(config)					TArray<FString>					QueuedDownloads;					//var config TArray<FString> QueuedDownloads;
	UPROPERTY()							bool							bErrorDownloading;					//var bool bErrorDownloading;
	UPROPERTY()							bool							bErrorFileUnavailable;				//var bool bErrorFileUnavailable;
	UPROPERTY()							bool							bErrorFileUpToDate;					//var bool bErrorFileUpToDate;
	UPROPERTY()							FString							ManifestPath;						//var FString ManifestPath;
	UPROPERTY()							FString							ManifestFileName;					//var FString ManifestFileName;
	UPROPERTY()							FString							DCDSCacheFileName;					//var FString DCDSCacheFileName;
	UPROPERTY()							bool							bGettingManifest;					//var bool bGettingManifest;
	UPROPERTY()							TArray<FAssetFileInfo>			AssetInfoList;						//var TArray<AssetFileInfo> AssetInfoList;
	UPROPERTY()							TArray<FAssetFileInfo>			CacheInfoList;						//var TArray<AssetFileInfo> CacheInfoList;

	bool DownloadAsset(FString UserName, FString Password, FString AssetName);
	bool HaltDownloadAsset();
	TArray<FHaltedDownloadInfo>  GetHaltedDownloadList();
	void CancelAllHaltedDownloads();
	bool CancelHaltedDownload(FString AssetName);
	void ClearDownloadChunks();
	void dOnDownloadAssetComplete(bool success, bool ErrorFileUnavailable, bool ErrorFileUpToDate);
	void dOnBeginningDownload(FString Filename, int32 Size, FString SHA);
	void dOnContinuingDownload(int32 Bitrate, float ElapsedTime, int32 TimeRemaining, int32 DownloadBytesCompleted);
	void dOnImageReady(FDCDSImageInfo Image);
	void dOnManifestDownloadComplete(bool success);
	bool RequestIsComplete();
	bool RequestWasSuccessful();
	bool BeginDownload();
	bool IsDownloadComplete();
	int32 GetDownloadBitrate();
	int32 GetDownloadTimeRemaining();
	int32 GetAssetDownloadBytesCompleted();
	bool GetImageInfo(FDCDSImageInfo& Image);
	void ShutdownDCDSSystem();
	void Destroyed();
	bool EnqueueDownload(FString AssetName);
	int32 FindQueuedAsset(FString AssetName);
	bool IsDownloading();
	bool CancelQueuedDownload(FString AssetName);
	bool IsQueued(FString AssetName);
	bool DownloadFileManifest(FString UserName, FString Password);
	void DownloadManifestComplete(bool success, bool ErrorFileUnavailable, bool ErrorFileUpToDate);
	bool IsAssetUpToDate(FString AssetName);
	int32 FindCachedAsset(FString AssetName);
	int32 FindAsset(FString AssetName);
	void ParseManifestFile();
	FString GetAssetPath(FString AssetFullName, FString Filename);
	void ParseCacheFile();
	FString StripAssetFullName(FString AssetFullName);
	void CacheAsset(FString AssetName, int32 AssetLength, FString AssetSHA);
	void testonly_SetTemporaryDownloadPath(FString Path);
	void testonly_SetDestinationPath(FString Path);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};

