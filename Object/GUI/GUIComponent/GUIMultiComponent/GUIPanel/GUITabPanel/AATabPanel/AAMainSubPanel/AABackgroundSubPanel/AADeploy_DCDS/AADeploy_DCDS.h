// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AADeploy_DCDS.generated.h"

class UAAGUILabel;
class UGUIButton;
class UAAGUIProgressBar;
class UGUIContentBox;
class UGUIImage;
class ADCDS;
class UGUIListBox;


UCLASS()
class AA29_API UAADeploy_DCDS : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAADeploy_DCDS();

	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadStatsFileName;			//var() automated AAGUILabel l_DownloadStatsFileName;
	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadStatsFileSize;			//var() automated AAGUILabel l_DownloadStatsFileSize;
	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadStatsProgress;			//var() automated AAGUILabel l_DownloadStatsProgress;
	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadStatsBitRate;			//var() automated AAGUILabel l_DownloadStatsBitRate;
	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadStatsIdle;				//var() automated AAGUILabel l_DownloadStatsIdle;
	UPROPERTY(EditAnywhere)			UAAGUILabel* l_DownloadInstructions;			//var() automated AAGUILabel l_DownloadInstructions;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Resume;							//var() automated XInterface.GUIButton b_Resume;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Cancel;							//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Halt;								//var() automated XInterface.GUIButton b_Halt;
	UPROPERTY(EditAnywhere)			UGUIButton* b_Download;							//var() automated XInterface.GUIButton b_Download;
	UPROPERTY(EditAnywhere)			UAAGUIProgressBar* pb_DownloadProgress;			//var() automated AAGUIProgressBar pb_DownloadProgress;
	UPROPERTY(EditAnywhere)			UGUIContentBox* guicb_DCDSNewsPanel;			//var() automated GUIContentBox guicb_DCDSNewsPanel;
	UPROPERTY(EditAnywhere)			UGUIImage* i_NewsBackground;					//var() automated XInterface.GUIImage i_NewsBackground;
	UPROPERTY(EditAnywhere)			UGUIListBox* lb_DCDSFileList;					//var() automated XInterface.GUIListBox lb_DCDSFileList;
	UPROPERTY()						ADCDS* MyDCDS;									//var DBAuth.DCDS MyDCDS;
	UPROPERTY()						FString RequestedFile;							//var FString RequestedFile;
	UPROPERTY()						FString QueuedFile;								//var FString QueuedFile;
	UPROPERTY()						int32 FileSize;									//var int32 FileSize;
	UPROPERTY()						int32 Transferred;								//var int32 Transferred;
	UPROPERTY()						FString NMLString;								//var FString NMLString;
	UPROPERTY()						UMaterialInstance* CachedMaterial;				//var Material CachedMaterial;
	UPROPERTY()						FString CachedHttpLink;							//var FString CachedHttpLink;
	UPROPERTY()						FString CachedCaption;							//var FString CachedCaption;
	UPROPERTY()						bool bImageLoaded;								//var bool bImageLoaded;
	UPROPERTY()						bool bNoUpdates;								//var bool bNoUpdates;
	UPROPERTY()						bool bManuallyHalted;							//var bool bManuallyHalted;
	UPROPERTY()						bool bAlreadyAutoResumed;						//var bool bAlreadyAutoResumed;
	UPROPERTY()						FString CaptionText;							//var FString CaptionText;
	UPROPERTY()						FString NotFoundCaptionText;					//var FString NotFoundCaptionText;
	UPROPERTY()						FString CompletedCaptionText;					//var FString CompletedCaptionText;
	UPROPERTY()						TArray<FAA2_AssetMapping> AssetMappings;		//var TArray<AssetMapping> AssetMappings;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitMyDCDS();
	FString GetFullName(UObject* obj);
	void LoadDynamicPanel(UMaterialInstance* Image, FString HttpLink, FString Caption);
	void OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);
	ADCDS* GetMyDCDS();
	void DownloadNextHaltedAsset();
	int32 GetAssetIndex(FString AssetName, bool bIsFileName);
	bool IsPausedOrInit();
	bool DownloadAsset(FString Filename);
	void HaltDownloadAsset();
	void CancelDownloadAsset(FString Filename);
	void ClearDownloadQueue();
	bool InternalButtonClick(UGUIComponent * Sender);
	void InternalOnChange(UGUIComponent * Sender);
	void ResetProgress();
	void InternalManifestDownloadComplete(bool success);
	FString GetLevelMissionName(FString sLevelName);
	FString GetAssetFullName(FString AssetName);
	FString GetAssetName(FString AssetFullName);
	int32 GetListIndex(FString Filename);
	void SetListProperty(FString Filename, FString Property);
	FString GetListProperty(FString Filename);
	FString GetCurrentListProperty();
	void InternalDownloadAssetComplete(bool success, bool ErrorUnavailable, bool ErrorUpToDate);
	void InternalBeginningDownload(FString Filename, int32 Size, FString SHA);
	void InternalContinuingDownload(int32 Bitrate, float ElapsedTime, int32 TimeRemaining, int32 DownloadBytesCompleted);
	void UpdateDownloadProgressUI(int32 Bitrate);
	void InternalImageReady(FDCDSImageInfo Image);
};
