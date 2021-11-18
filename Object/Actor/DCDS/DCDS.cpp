// All the original content belonged to the US Army


#include "AA29/Object/Actor/DCDS/DCDS.h"

// Sets default values
ADCDS::ADCDS()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	PointerProperty* DCDSSDK = NewObject<PointerProperty>(PointerProperty::StaticClass());
	PointerProperty* AssetRequest = NewObject<PointerProperty>(PointerProperty::StaticClass());
	*/
	TemporaryDownloadPath = "DynamicContent/DCDS";
	DestinationPath = "..";
	ManifestPath = "DynamicContent/DCDS";
	ManifestFileName = "dcds.manifest";
	DCDSCacheFileName = "dcds.cache";
	//bHidden = true;
}

// Called when the game starts or when spawned
void ADCDS::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADCDS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
State WaitingForCommunicationToComplete
{
	Function bool DownloadAsset(FString UserName, FString Password, FString AssetName)
	{
		EnqueueDownload(AssetName);
		return true;
	}
	Function BeginState()
	{
		SetTimer(0.02,true);
	}
	Function Timer()
	{
		if (RequestIsComplete())
		{
			SetTimer(0,false);
			DebugLog(DEBUG_Auth,string(Self) @ "DCDS:WaitingForCommunicationToComplete:Timer" @ string(RequestWasSuccessful()) @ string(AssetSize) @ SHA);
			if (!RequestWasSuccessful())
			{
				ShutdownDCDSSystem();
				GotoState('None');
				AssetFileName = "";
				bErrorFileUnavailable = (!bErrorFileUpToDate);
				if (bGettingManifest)
				{
					DownloadManifestComplete(false,bErrorFileUnavailable,bErrorFileUpToDate);
				}
				else
				{
					dOnDownloadAssetComplete(false,bErrorFileUnavailable,bErrorFileUpToDate);
				}
			}
			else
			{
				GotoState('DownloadingAsset');
			}
		}
	}
}

State DownloadingAsset
{
	Function bool DownloadAsset(FString UserName, FString Password, FString AssetName)
	{
		EnqueueDownload(AssetName);
		return true;
	}
	Function BeginState()
	{
		DownloadStartTimestamp = Level.TimeSeconds;
		if (!bGettingManifest)
		{
			dOnBeginningDownload(AssetFileName,AssetSize,SHA);
		}
		if (BeginDownload())
		{
			SetTimer(1,true);
		}
		else
		{
			Log("Failed to begin DCDS download.");
			ShutdownDCDSSystem();
			GotoState('None');
			AssetFileName = "";
			if (bGettingManifest)
			{
				DownloadManifestComplete(false,bErrorFileUnavailable,bErrorFileUpToDate);
			}
			else
			{
				dOnDownloadAssetComplete(false,bErrorFileUnavailable,bErrorFileUpToDate);
			}
		}
	}
	Function Timer()
	{
		local DCDSImageInfo Image;
		local FString Filename;
		if (IsDownloadComplete())
		{
			SetTimer(0,false);
			Filename = AssetFileName;
			AssetFileName = "";
			UserName = "";
			Password = "";
			ShutdownDCDSSystem();
			GotoState('None');
			if (bErrorDownloading)
			{
				FDelete(TemporaryDownloadPath $ "/" $ Filename $ ".fz");
			}
			else
			{
				if (!bGettingManifest)
				{
					CacheAsset(Filename,AssetSize,SHA);
				}
			}
			if (bGettingManifest)
			{
				DownloadManifestComplete((!bErrorDownloading),bErrorFileUnavailable,bErrorFileUpToDate);
			}
			else
			{
				dOnDownloadAssetComplete((!bErrorDownloading),bErrorFileUnavailable,bErrorFileUpToDate);
			}
		}
		else
		{
			if (!bGettingManifest)
			{
				dOnContinuingDownload(GetDownloadBitrate(),(Level.TimeSeconds - DownloadStartTimestamp),GetDownloadTimeRemaining(),GetAssetDownloadBytesCompleted());
				if (GetImageInfo(Image))
				{
					dOnImageReady(Image);
				}
			}
		}
	}
}
*/

//native Function bool DownloadAsset(FString UserName, FString Password, FString AssetName);
bool ADCDS::DownloadAsset(FString aUserName, FString aPassword, FString AssetName)
{
	return false;    //FAKE /ELiZ
}

//native Function bool HaltDownloadAsset();
bool ADCDS::HaltDownloadAsset()
{
	return false;    //FAKE /ELiZ
}

//native Function TArray<HaltedDownloadInfo>  GetHaltedDownloadList();
TArray<FHaltedDownloadInfo>  ADCDS::GetHaltedDownloadList()
{
	return {};    //FAKE   /ELiZ
}

//native Function CancelAllHaltedDownloads();
void ADCDS::CancelAllHaltedDownloads()
{
}

//native Function bool CancelHaltedDownload(FString AssetName);
bool ADCDS::CancelHaltedDownload(FString AssetName)
{
	return false;    //FAKE   /ELiZ
}

//native Function ClearDownloadChunks();
void ADCDS::ClearDownloadChunks()
{
}

void ADCDS::dOnDownloadAssetComplete(bool success, bool ErrorFileUnavailable, bool ErrorFileUpToDate)
{
}

void ADCDS::dOnBeginningDownload(FString Filename, int32 Size, FString aSHA)
{
}

void ADCDS::dOnContinuingDownload(int32 Bitrate, float ElapsedTime, int32 TimeRemaining, int32 DownloadBytesCompleted)
{
}

void ADCDS::dOnImageReady(FDCDSImageInfo Image)
{
}

void ADCDS::dOnManifestDownloadComplete(bool success)
{
}

//native Function bool RequestIsComplete();
bool ADCDS::RequestIsComplete()
{
	return false;    //FAKE /ELiZ
}

//native Function bool RequestWasSuccessful();
bool ADCDS::RequestWasSuccessful()
{
	return false;    //FAKE /ELiZ
}

//native Function bool BeginDownload();
bool ADCDS::BeginDownload()
{
	return false;    //FAKE /ELiZ
}

//native Function bool IsDownloadComplete();
bool ADCDS::IsDownloadComplete()
{
	return false;    //FAKE /ELiZ
}

//native Function int32 GetDownloadBitrate();
int32 ADCDS::GetDownloadBitrate()
{
	return 0;    //FAKE /ELiZ
}

//native Function int32 GetDownloadTimeRemaining();
int32 ADCDS::GetDownloadTimeRemaining()
{
	return 0;    //FAKE /ELiZ
}

//native Function int32 GetAssetDownloadBytesCompleted();
int32 ADCDS::GetAssetDownloadBytesCompleted()
{
	return 0;    //FAKE /ELiZ
}

//native Function bool GetImageInfo(DCDSImageInfo& Image);
bool ADCDS::GetImageInfo(FDCDSImageInfo& Image)
{
	return false;    //FAKE /ELiZ
}

//native Function ShutdownDCDSSystem();
void ADCDS::ShutdownDCDSSystem()
{
}

void ADCDS::Destroyed()
{
	/*
	Super::Destroyed();
	ShutdownDCDSSystem();
	*/
}

bool ADCDS::EnqueueDownload(FString AssetName)
{
	/*
	local int32 Index;
	if (AssetFileName ~= AssetName)
	{
		return false;
	}
	Index = FindQueuedAsset(AssetName);
	if (Index != -1)
	{
		return false;
	}
	QueuedDownloads[QueuedDownloads.Length] = AssetName;
	SaveConfig();
	*/
	return true;
}

int32 ADCDS::FindQueuedAsset(FString AssetName)
{
	/*
	local int32 i;
	for (i = 0; i < QueuedDownloads.Length; i++)
	{
		if (QueuedDownloads[i] ~= AssetName)
		{
			return i;
		}
	}
	*/
	return -1;
}

bool ADCDS::IsDownloading()
{
	//return (!IsInState('None'));
	return false;    //FAKE /ELiZ
}

bool ADCDS::CancelQueuedDownload(FString AssetName)
{
	/*
	local int32 i;
	if (AssetFileName ~= AssetName)
	{
		return false;
	}
	i = FindQueuedAsset(AssetName);
	if (i != -1)
	{
		QueuedDownloads.remove(i, 1);
		SaveConfig();
		return true;
	}
	*/
	return false;    //FAKE /ELiZ
}

bool ADCDS::IsQueued(FString AssetName)
{
	/*
	local int32 i;
	local int32 j;
	i = FindAsset(AssetName);
	if (i != -1)
	{
		for (j = 0; j < QueuedDownloads.Length; j++)
		{
			if (QueuedDownloads[j] ~= AssetInfoList[i].FullName)
			{
				return true;
			}
		}
	}
	*/
	return false;
}

bool ADCDS::DownloadFileManifest(FString aUserName, FString aPassword)
{
	/*
	if (AssetFileName == "")
	{
		bGettingManifest = true;
		DestinationPath = ManifestPath;
		FDelete(ManifestPath $ "/" $ ManifestFileName);
		DownloadAsset(aUserName, aPassword, ManifestFileName);
	}
	else
	{
		Log("----- Error attempting to download " $ ManifestFileName $ " from DCDS server: Already downloading a file -----");
		return false;
	}
	*/
	return true;
}

void ADCDS::DownloadManifestComplete(bool success, bool ErrorFileUnavailable, bool ErrorFileUpToDate)
{
	/*
	if (!success)
	{
		Log("----- Error downloading " $ ManifestFileName $ " from DCDS server -----");
	}
	else
	{
		ParseManifestFile();
		ParseCacheFile();
	}
	dOnManifestDownloadComplete(success);
	DestinationPath = Default.DestinationPath;
	bGettingManifest = false;
	*/
}

bool ADCDS::IsAssetUpToDate(FString AssetName)
{
	/*
	local int32 i;
	local int32 j;
	if ((AssetInfoList.Length == 0) || (CacheInfoList.Length == 0))
	{
		return false;
	}
	i = FindAsset(AssetName);
	j = FindCachedAsset(AssetName);
	if ((i == -1) || (j == -1))
	{
		return false;
	}
	if (CacheInfoList[j].SHA ~= AssetInfoList[i].SHA)
	{
		return true;
	}
	*/
	return false;
}

int32 ADCDS::FindCachedAsset(FString AssetName)
{
	/*
	local int32 i;
	for (i = 0; i < CacheInfoList.Length; i++)
	{
		if (CacheInfoList[i].Name ~= AssetName)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 ADCDS::FindAsset(FString AssetName)
{
	/*
	local int32 i;
	for (i = 0; i < AssetInfoList.Length; i++)
	{
		if (AssetInfoList[i].Name ~= AssetName)
		{
			return i;
		}
	}
	*/
	return -1;
}

void ADCDS::ParseManifestFile()
{
	/*
	local FString FileLine;
	local FString LineField;
	local FString RHS;
	local AssetFileInfo Info;
	AssetInfoList.remove(0, AssetInfoList.Length);
	if (!FOpen(ManifestPath $ "/" $ ManifestFileName))
	{
		Log("----- Error: Unable to load manifest file: " $ ManifestPath $ "/" $ ManifestFileName $ " -----");
		return;
	}
	if (FReadLine(FileLine))
	{
		Divide(FileLine, ",", LineField, RHS);
		Info.FullName = LineField;
		Info.Name = StripAssetFullName(LineField);
		Info.Path = GetAssetPath(LineField, Info.Name);
		Divide(RHS, ",", LineField, RHS);
		Info.FileLength = int(LineField);
		Divide(RHS, ",", LineField, RHS);
		Info.SHA = LineField;
		Divide(RHS, ",", LineField, RHS);
		Info.Date = LineField;
		Divide(RHS, ",", LineField, RHS);
		Info.bShouldRemove = int((LineField ~= "True"));
		if (bool(Info.bShouldRemove))
		{
			FDelete(DestinationPath $ "/" $ Info.FullName);
		}
		else
		{
			AssetInfoList[AssetInfoList.Length] = Info;
		}
	}
	FClose();
	*/
}

FString ADCDS::GetAssetPath(FString AssetFullName, FString Filename)
{
	FString BitBucket="";
	FString Path = "";
	//Divide(AssetFullName, "/" $ Filename, Path, BitBucket);
	return Path;
}

void ADCDS::ParseCacheFile()
{
	/*
	local FString FileLine;
	local FString LineField;
	local FString RHS;
	local AssetFileInfo Info;
	CacheInfoList.remove(0, CacheInfoList.Length);
	if (!FOpen(ManifestPath $ "/" $ DCDSCacheFileName))
	{
		return;
	}
	if (FReadLine(FileLine))
	{
		Divide(FileLine, ",", LineField, RHS);
		Info.FullName = LineField;
		Divide(RHS, ",", LineField, RHS);
		Info.Name = LineField;
		Divide(RHS, ",", LineField, RHS);
		Info.FileLength = int(LineField);
		Divide(RHS, ",", LineField, RHS);
		Info.SHA = LineField;
		Divide(RHS, ",", LineField, RHS);
		Info.Date = LineField;
		CacheInfoList[CacheInfoList.Length] = Info;
	}
	FClose();
	*/
}

FString ADCDS::StripAssetFullName(FString AssetFullName)
{
	FString BitBucket="";
	FString TempField="";
	/*
	TempField = AssetFullName;
	if (InStr(TempField, "/") != -1)
	{
		Divide(TempField, "/", BitBucket, TempField);
	}
	Divide(TempField, ".", TempField, BitBucket);
	*/
	return TempField;
}

void ADCDS::CacheAsset(FString AssetName, int32 AssetLength, FString AssetSHA)
{
	/*
	local int32 i;
	local AssetFileInfo Info;
	local FString AssetLine;
	Info.FullName = AssetName;
	Info.Name = StripAssetFullName(AssetName);
	Info.FileLength = AssetLength;
	Info.SHA = "";
	i = FindAsset(Info.Name);
	if (i != -1)
	{
		Info.SHA = AssetInfoList[i].SHA;
	}
	Info.Date = "00.00.00";
	i = FindCachedAsset(Info.Name);
	if (i != -1)
	{
		if (CacheInfoList[i].SHA ~= Info.SHA)
		{
			return;
		}
		CacheInfoList.remove(i, 1);
	}
	CacheInfoList[CacheInfoList.Length] = Info;
	if (!FOpenWrite(ManifestPath $ "/" $ DCDSCacheFileName))
	{
		Log("----- Error Writing to " $ ManifestPath $ "/" $ DCDSCacheFileName);
		return;
	}
	for (i = 0; i < CacheInfoList.Length; i++)
	{
		AssetLine = CacheInfoList[i].FullName $ "," $ CacheInfoList[i].Name $ "," $ string(CacheInfoList[i].FileLength) $ "," $ CacheInfoList[i].SHA $ "," $ CacheInfoList[i].Date $ ",";
		FWriteLine(AssetLine);
	}
	FClose();
	*/
}

void ADCDS::testonly_SetTemporaryDownloadPath(FString Path)
{
	TemporaryDownloadPath = Path;
}

void ADCDS::testonly_SetDestinationPath(FString Path)
{
	DestinationPath = Path;
}

