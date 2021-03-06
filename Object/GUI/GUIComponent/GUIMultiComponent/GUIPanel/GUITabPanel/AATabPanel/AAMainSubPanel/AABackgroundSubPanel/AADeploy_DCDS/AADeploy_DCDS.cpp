// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_DCDS/AADeploy_DCDS.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/AAGUIProgressBar/AAGUIProgressBar.h"
#include "AA29/Object/Actor/DCDS/DCDS.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAADeploy_DCDS::UAADeploy_DCDS()
{
	UGUIListBox* FileList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	FileList->bVisibleWhenEmpty = true;
	//FileList->OnCreateComponent=FileList.InternalOnCreateComponent;
	FileList->StyleName = "ComboListBox";
	FileList->WinTop = 0.6;
	FileList->WinLeft = 0.01;
	FileList->WinWidth = 0.45;
	FileList->WinHeight = 0.2775;
	FileList->RenderWeight = 0.9;
	FileList->bBoundToParent = true;
	FileList->bScaleToParent = true;
	//FileList->OnChange=AADeploy_DCDS.InternalOnChange;
	UGUIButton* DownloadButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DownloadButton->Caption = "Download";
	DownloadButton->MenuState = EMenuState::MSAT_Disabled;
	DownloadButton->StyleName = "SquareMenuButton";
	DownloadButton->Hint = "Download selected file from DCDS Server";
	DownloadButton->WinTop = 0.875;
	DownloadButton->WinLeft = 0.54;
	DownloadButton->WinWidth = 0.2;
	DownloadButton->WinHeight = 0.05;
	DownloadButton->RenderWeight = 0.6;
	DownloadButton->bBoundToParent = true;
	DownloadButton->bScaleToParent = true;
	//DownloadButton->OnClick=AADeploy_DCDS.InternalButtonClick;
	//DownloadButton->OnKeyEvent=DownloadButton.InternalOnKeyEvent;
	UGUIButton* ResumeButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ResumeButton->Caption = "Resume";
	ResumeButton->MenuState = EMenuState::MSAT_Disabled;
	ResumeButton->StyleName = "SquareMenuButton";
	ResumeButton->Hint = "Resume downloading the current DCDS download";
	ResumeButton->WinTop = 0.805;
	ResumeButton->WinLeft = 0.54;
	ResumeButton->WinWidth = 0.2;
	ResumeButton->WinHeight = 0.05;
	ResumeButton->RenderWeight = 0.6;
	ResumeButton->bBoundToParent = true;
	ResumeButton->bScaleToParent = true;
	//ResumeButton->OnClick=AADeploy_DCDS.InternalButtonClick;
	//ResumeButton->OnKeyEvent=ResumeButton.InternalOnKeyEvent;
	UGUIButton* HaltButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HaltButton->Caption = "Pause";
	HaltButton->MenuState = EMenuState::MSAT_Disabled;
	HaltButton->StyleName = "SquareMenuButton";
	HaltButton->Hint = "Halt the current DCDS download to be resumed later";
	HaltButton->WinTop = 0.805;
	HaltButton->WinLeft = 0.78;
	HaltButton->WinWidth = 0.2;
	HaltButton->WinHeight = 0.05;
	HaltButton->RenderWeight = 0.6;
	HaltButton->bBoundToParent = true;
	HaltButton->bScaleToParent = true;
	//HaltButton->OnClick=AADeploy_DCDS.InternalButtonClick;
	//HaltButton->OnKeyEvent=HaltButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "Cancel";
	CancelButton->MenuState = EMenuState::MSAT_Disabled;
	CancelButton->StyleName = "SquareMenuButton";
	CancelButton->Hint = "Cancel all download progress for selected download";
	CancelButton->WinTop = 0.875;
	CancelButton->WinLeft = 0.78;
	CancelButton->WinWidth = 0.2;
	CancelButton->WinHeight = 0.05;
	CancelButton->RenderWeight = 0.6;
	CancelButton->bBoundToParent = true;
	CancelButton->bScaleToParent = true;
	//CancelButton->OnClick=AADeploy_DCDS.InternalButtonClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UGUIContentBox* DCDSNewsPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	DCDSNewsPanel->ItemSpacing = 0;
	DCDSNewsPanel->bScaleItemsToWidth = true;
	DCDSNewsPanel->SideGaps = 0;
	DCDSNewsPanel->WinTop = 0.07625;
	DCDSNewsPanel->WinLeft = 0.02;
	DCDSNewsPanel->WinWidth = 0.96;
	DCDSNewsPanel->WinHeight = 0.475;
	DCDSNewsPanel->RenderWeight = 0.4;
	DCDSNewsPanel->bBoundToParent = true;
	DCDSNewsPanel->bScaleToParent = true;
	UGUIImage* NewsBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	NewsBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
	NewsBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	NewsBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	NewsBackground->WinTop = 0.06625;
	NewsBackground->WinLeft = 0.01;
	NewsBackground->WinWidth = 0.98;
	NewsBackground->WinHeight = 0.495;
	NewsBackground->RenderWeight = 0.3;
	NewsBackground->bBoundToParent = true;
	NewsBackground->bScaleToParent = true;
	UAAGUILabel* DownloadStatsFileName = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadStatsFileName->TextColor = FColor(137, 185, 147, 255);
	DownloadStatsFileName->TextFont = "AAFontSmall";
	DownloadStatsFileName->WinTop = 0.6;
	DownloadStatsFileName->WinLeft = 0.575;
	DownloadStatsFileName->WinWidth = 0.69;
	DownloadStatsFileName->WinHeight = 0.2;
	DownloadStatsFileName->RenderWeight = 0.7;
	DownloadStatsFileName->bVisible = false;
	UAAGUILabel* DownloadStatsFileSize = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadStatsFileSize->TextColor = FColor(137, 185, 147, 255);
	DownloadStatsFileSize->TextFont = "AAFontSmall";
	DownloadStatsFileSize->WinTop = 0.63;
	DownloadStatsFileSize->WinLeft = 0.575;
	DownloadStatsFileSize->WinWidth = 0.69;
	DownloadStatsFileSize->WinHeight = 0.2;
	DownloadStatsFileSize->RenderWeight = 0.7;
	DownloadStatsFileSize->bVisible = false;
	UAAGUILabel* DownloadStatsProgress = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadStatsProgress->TextColor = FColor(137, 185, 147, 255);
	DownloadStatsProgress->TextFont = "AAFontSmall";
	DownloadStatsProgress->WinTop = 0.66;
	DownloadStatsProgress->WinLeft = 0.575;
	DownloadStatsProgress->WinWidth = 0.69;
	DownloadStatsProgress->WinHeight = 0.2;
	DownloadStatsProgress->RenderWeight = 0.7;
	DownloadStatsProgress->bVisible = false;
	UAAGUILabel* DownloadStatsBitRate = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadStatsBitRate->TextColor = FColor(137, 185, 147, 255);
	DownloadStatsBitRate->TextFont = "AAFontSmall";
	DownloadStatsBitRate->WinTop = 0.69;
	DownloadStatsBitRate->WinLeft = 0.575;
	DownloadStatsBitRate->WinWidth = 0.69;
	DownloadStatsBitRate->WinHeight = 0.2;
	DownloadStatsBitRate->RenderWeight = 0.7;
	DownloadStatsBitRate->bVisible = false;
	UAAGUILabel* DownloadStatsIdle = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadStatsIdle->Caption = "No Download In Progress";
	DownloadStatsIdle->TextAlign = ETextAlign::TXTA_Center;
	DownloadStatsIdle->TextColor = FColor(137, 185, 147, 255);
	DownloadStatsIdle->TextFont = "AAFontSmall";
	DownloadStatsIdle->WinTop = 0.69;
	DownloadStatsIdle->WinLeft = 0.575;
	DownloadStatsIdle->WinWidth = 0.38;
	DownloadStatsIdle->WinHeight = 0.2;
	DownloadStatsIdle->RenderWeight = 0.7;
	UAAGUIProgressBar* DownloadProgress = NewObject<UAAGUIProgressBar>(UAAGUIProgressBar::StaticClass());
	DownloadProgress->BarColor = FColor(27, 153, 186, 255);
	DownloadProgress->WinTop = 0.735;
	DownloadProgress->WinLeft = 0.54;
	DownloadProgress->WinWidth = 0.44;
	DownloadProgress->WinHeight = 0.05;
	DownloadProgress->RenderWeight = 0.6;
	DownloadProgress->bBoundToParent = true;
	DownloadProgress->bScaleToParent = true;
	UAAGUILabel* DownloadInstructions = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DownloadInstructions->Caption = "Select a map and click Download to begin";
	DownloadInstructions->TextColor = FColor(137, 185, 147, 255);
	DownloadInstructions->TextFont = "AAFontSmall";
	DownloadInstructions->WinTop = 0.6;
	DownloadInstructions->WinLeft = 0.563;
	DownloadInstructions->WinWidth = 0.69;
	DownloadInstructions->WinHeight = 0.2;
	DownloadInstructions->RenderWeight = 0.7;
	l_DownloadStatsFileName = DownloadStatsFileName;
	l_DownloadStatsFileSize = DownloadStatsFileSize;
	l_DownloadStatsProgress = DownloadStatsProgress;
	l_DownloadStatsBitRate = DownloadStatsBitRate;
	l_DownloadStatsIdle = DownloadStatsIdle;
	l_DownloadInstructions = DownloadInstructions;
	b_Resume = ResumeButton;
	b_Cancel = CancelButton;
	b_Halt = HaltButton;
	b_Download = DownloadButton;
	pb_DownloadProgress = DownloadProgress;
	guicb_DCDSNewsPanel = DCDSNewsPanel;
	i_NewsBackground = NewsBackground;
	lb_DCDSFileList = FileList;

	NMLString = "<grid><columns>3</columns><columnwidth>0.0</columnwidth><columnwidth>0.3</columnwidth><columnwidth>0.65</columnwidth><columnspacing>0.025</columnspacing><rowspacing>0.0</rowspacing><cell><text><content></content></text></cell><cell><panel><nobackground>true</nobackground><itemspacing>0.001</itemspacing><winheight>0.3</winheight><noscrollbar>true</noscrollbar><topoffset>2</topoffset><bottomoffset>2</bottomoffset><leftoffset>2</leftoffset><rightoffset>2</rightoffset><row><image><height>1.0</height><width>1.0</width>%DCDSImage%</image></row></panel></cell><cell><panel><noscrollbar>true</noscrollbar><topoffset>4</topoffset><bottomoffset>4</bottomoffset><leftoffset>4</leftoffset><rightoffset>4</rightoffset><itemspacing>0.001</itemspacing><winheight>0.435</winheight><row><text><content>%Caption%</content><style>MediumText</style></text></row><row><text><content>Click Here: </content><style>MediumText</style></text></row><row>%HttpLink%</row></panel></cell></grid>";
	CachedMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/logo_AA_Mat.logo_AA_Mat'"), NULL, LOAD_None, NULL);
	CachedHttpLink = "<textlink><content>http://www.americasarmy.com/</content><link>http://www.americasarmy.com/</link></textlink>";
	CachedCaption = "Visit the America's Army website for more information.";
	CaptionText = "You must download this map (%AssetTitle%) before you can join this server.||This map is available for immediate download.";
	NotFoundCaptionText = "The map '%AssetName%' is not available for download through DCDS at this time.";
	CompletedCaptionText = "Your download of map '%AssetTitle%' is complete.";
	AssetMappings = {
		FAA2_AssetMapping({ "Insurgent_Camp", "Insurgent_Camp.aao", "Insurgent Camp" }),
		FAA2_AssetMapping({ "SFDockside", "SFDockside.aao", "SF Dockside"}),
		FAA2_AssetMapping({ "Steamroller", "Steamroller.aao", "Steamroller"}) 
	};
	PanelCaption = "Dynamic Content Delivery Service";
	PropagateVisibility = false;
}

void UAADeploy_DCDS::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	InitMyDCDS();
	lb_DCDSFileList.List.TextAlign = 0;
	LoadDynamicPanel(CachedMaterial, CachedHttpLink, CachedCaption);
	*/
}

void UAADeploy_DCDS::InitMyDCDS()
{
	AActor* SpawnActor = nullptr;
	if (MyDCDS != nullptr)
	{
		return;
	}
	/*
	ForEach AllObjects(Class'Actor', SpawnActor)
	{
		GOTO JL0020;
	JL0020:
	}
	MyDCDS = SpawnActor.Spawn(ADCDS::StaticClass());
	if (MyDCDS != nullptr)
	{
		MyDCDS.__dOnDownloadAssetComplete__Delegate = InternalDownloadAssetComplete;
		MyDCDS.__dOnBeginningDownload__Delegate = InternalBeginningDownload;
		MyDCDS.__dOnContinuingDownload__Delegate = InternalContinuingDownload;
		MyDCDS.__dOnImageReady__Delegate = InternalImageReady;
		MyDCDS.__dOnManifestDownloadComplete__Delegate = InternalManifestDownloadComplete;
	}
	*/
}

FString UAADeploy_DCDS::GetFullName(UObject* obj)
{
	FString FullName="";
	TArray<UObject*> Outers = {};
	int32 i = 0;
	if (obj == nullptr)
	{
		return "";
	}
	/*
	Outers[0] = obj;
	if (Outers[0].Outer != nullptr)
	{
		Outers.insert(0, 1);
		Outers[0] = Outers[1].Outer;
	}
	for (i = 0; i < Outers.Num(); i++)
	{
		if (FullName != "")
		{
			FullName += ".";
		}
		FullName += FString::FromInt(Outers[i].Name);
	}
	*/
		return FullName;
}

void UAADeploy_DCDS::LoadDynamicPanel(UMaterialInstance* Image, FString HttpLink, FString Caption)
{
	UNMLContent* MyNML = nullptr;
	/*
	guicb_DCDSNewsPanel.RemoveAllComponents();
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(Controller, MenuOwner);
		}
		NMLString = Default.NMLString;
		NMLString = Repl(NMLString, "%DCDSImage%", "<packagesrc>" + GetFullName(Image) + "</packagesrc>");
		NMLString = Repl(NMLString, "%HttpLink%", HttpLink);
		NMLString = Repl(NMLString, "%Caption%", Caption);
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.ParseNMLFromString(NMLString, guicb_DCDSNewsPanel);
	}
	*/
}

void UAADeploy_DCDS::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	/*
	Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Param3, PanelName);
	*/
}

ADCDS* UAADeploy_DCDS::GetMyDCDS()
{
	if (MyDCDS == nullptr)
	{
		InitMyDCDS();
	}
	return MyDCDS;
}

void UAADeploy_DCDS::DownloadNextHaltedAsset()
{
	TArray<FHaltedDownloadInfo> HaltedDownloadList = {};
	/*
	if (bManuallyHalted && (Len(RequestedFile) > 0))
	{
		DownloadAsset(RequestedFile);
	}
	else
	{
		if (GetMyDCDS() != nullptr)
		{
			HaltedDownloadList = GetMyDCDS().GetHaltedDownloadList();
			if (HaltedDownloadList.Num() > 0)
			{
				DownloadAsset(HaltedDownloadList[0].AssetName);
			}
		}
	}
	*/
}

int32 UAADeploy_DCDS::GetAssetIndex(FString AssetName, bool bIsFileName)
{
	int32 i = 0;
	/*
	for (i = 0; i < Default.AssetMappings.Num(); i++)
	{
		if (((!bIsFileName) && (Default.AssetMappings[i].AssetName ~= AssetName)) || (bIsFileName && (Default.AssetMappings[i].AssetFileName ~= AssetName)))
		{
			return i;
		}
	}
	*/
		return -1;
}

bool UAADeploy_DCDS::IsPausedOrInit()
{
	int32 i = 0;
	FString ListName= "";
	FString CurrentProperty = "";
	FString BitBucket = "";
	/*
	for (i = 0; i < lb_DCDSFileList.List.Elements.Num(); i++)
	{
		ListName = lb_DCDSFileList.List.getItemAtIndex(i);
		Divide(ListName, " (", BitBucket, CurrentProperty);
		Divide(CurrentProperty, ")", CurrentProperty, BitBucket);
		if ((CurrentProperty ~= "Initializing") || (CurrentProperty ~= "Paused"))
		{
			return true;
		}
	}
	*/
	return false;
}

bool UAADeploy_DCDS::DownloadAsset(FString Filename)
{
	AHumanController* HC = nullptr;
	bool retval = false;
	if (GetMyDCDS() != nullptr)
	{
		HC = Cast<AHumanController>(PlayerOwner());
		if ((HC != nullptr) && (Filename != ""))
		{
			bManuallyHalted = false;
			if (RequestedFile == Filename)
			{
				retval = GetMyDCDS()->DownloadAsset(HC->UserName, HC->UserPassword, Filename);
			}
			else
			{
				if (IsPausedOrInit())
				{
					retval = MyDCDS->EnqueueDownload(Filename);
					SetListProperty(Filename, "Queued");
				}
				else
				{
					if (RequestedFile == "")
					{
						SetListProperty(Filename, "Initializing");
					}
					else
					{
						SetListProperty(Filename, "Queued");
					}
					retval = GetMyDCDS()->DownloadAsset(HC->UserName, HC->UserPassword, Filename);
				}
			}
			QueuedFile = Filename;
			return retval;
		}
	}
	return false;
}

void UAADeploy_DCDS::HaltDownloadAsset()
{
	if (GetMyDCDS() != nullptr)
	{
		bManuallyHalted = true;
		if (GetMyDCDS()->HaltDownloadAsset())
		{
			l_DownloadStatsBitRate->Caption = "Bit Rate: Transfer halted.";
			SetListProperty(RequestedFile, "Paused");
		}
	}
}

void UAADeploy_DCDS::CancelDownloadAsset(FString Filename)
{
	if (GetListProperty(Filename) == "Queued")
	{
		if (MyDCDS != nullptr)
		{
			MyDCDS->CancelQueuedDownload(Filename);
		}
		SetListProperty(Filename, "");
	}
	else
	{
		HaltDownloadAsset();
		if (GetMyDCDS() != nullptr)
		{
			GetMyDCDS()->CancelHaltedDownload(RequestedFile);
		}
		SetListProperty(RequestedFile, "");
		if (RequestedFile == QueuedFile)
		{
			QueuedFile = "";
		}
		RequestedFile = "";
		DownloadNextHaltedAsset();
		pb_DownloadProgress->CurrentValue = pb_DownloadProgress->MinValue;
		ResetProgress();
		l_DownloadStatsFileName->bVisible = false;
		l_DownloadStatsFileSize->bVisible = false;
		l_DownloadStatsProgress->bVisible = false;
		l_DownloadStatsBitRate->bVisible = false;
		l_DownloadStatsIdle->bVisible = true;
		l_DownloadInstructions->bVisible = true;
	}
}

void UAADeploy_DCDS::ClearDownloadQueue()
{
	if (RequestedFile != "")
	{
		CancelDownloadAsset(RequestedFile);
	}
	if (GetMyDCDS() != nullptr)
	{
		GetMyDCDS()->CancelAllHaltedDownloads();
	}
}

bool UAADeploy_DCDS::InternalButtonClick(UGUIComponent* Sender)
{
	AHumanController* HC = nullptr;
	FString AssetFileName = "";
	HC = Cast<AHumanController>(PlayerOwner());
	/*
	AssetFileName = GetAssetFullName(lb_DCDSFileList.List.GetExtra());
	switch (Sender)
	{
	case b_Resume:
		DownloadAsset(AssetFileName);
		return true;
	case b_Cancel:
		CancelDownloadAsset(AssetFileName);
		return true;
	case b_Halt:
		HaltDownloadAsset();
		return true;
	case b_Download:
		DownloadAsset(AssetFileName);
		return true;
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

void UAADeploy_DCDS::InternalOnChange(UGUIComponent* Sender)
{
	FString MapProperty = "";
	if (bNoUpdates)
	{
		return;
	}
	/*
	if (Sender == lb_DCDSFileList)
	{
		MapProperty = GetCurrentListProperty();
		switch (MapProperty)
		{
		case "Complete":
		case "Completing":
		case "Initializing":
		case "Unavailable":
		case "Already Updated":
			b_Cancel.DisableMe();
			b_Halt.DisableMe();
			b_Download.DisableMe();
			b_Resume.DisableMe();
			break;
		case "Queued":
			b_Cancel.EnableMe();
			b_Halt.DisableMe();
			b_Download.DisableMe();
			b_Resume.DisableMe();
			break;
		case "Paused":
			b_Cancel.EnableMe();
			b_Halt.DisableMe();
			b_Download.DisableMe();
			b_Resume.EnableMe();
			break;
		case "Downloading":
			b_Cancel.EnableMe();
			b_Halt.EnableMe();
			b_Download.DisableMe();
			b_Resume.DisableMe();
			break;
		case "Error":
			b_Cancel.DisableMe();
			b_Halt.DisableMe();
			b_Download.EnableMe();
			b_Resume.DisableMe();
			break;
		case "":
			b_Cancel.DisableMe();
			b_Halt.DisableMe();
			b_Download.EnableMe();
			b_Resume.DisableMe();
			break;
		default:
		}
	}
	*/
}

void UAADeploy_DCDS::ResetProgress()
{
	Transferred = 0;
	FileSize = 0;
}

void UAADeploy_DCDS::InternalManifestDownloadComplete(bool success)
{
	int32 i = 0;
	FString Mission = "";
	FString MapName = "";
	FString MapSz = "";
	bNoUpdates = false;
	/*
	if (success && (MyDCDS != nullptr))
	{
		lb_DCDSFileList.List.Clear();
		for (i = 0; i < MyDCDS.AssetInfoList.Num(); i++)
		{
			MapName = MyDCDS.AssetInfoList[i].Name;
			if (!MyDCDS.IsAssetUpToDate(MapName))
			{
				Mission = GetLevelMissionName(MapName);
				MapSz = FString::FromInt((float(MyDCDS.AssetInfoList[i].FileLength) / float(1000000)));
				MapSz = Left(MapSz, 3);
				lb_DCDSFileList.List.Add(Mission + " - " + MapSz + "MB", None, MyDCDS.AssetInfoList[i].Name);
				if (MyDCDS.IsQueued(MapName))
				{
					SetListProperty(MyDCDS.AssetInfoList[i].FullName, "Queued");
				}
			}
		}
		if (!lb_DCDSFileList.List.IsValidIndex(0))
		{
			bNoUpdates = true;
			lb_DCDSFileList.List.Add("No new updates available for download");
		}
		DownloadNextHaltedAsset();
	}
	else
	{
		bNoUpdates = true;
		lb_DCDSFileList.List.Add("Unable to get listing from server");
	}
	InternalOnChange(lb_DCDSFileList);
	*/
}

FString UAADeploy_DCDS::GetLevelMissionName(FString sLevelName)
{
	FString sFile = "";
	FString sTemp = "";
	FString sLine = "";
	FString sInfo = "";
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iCurNumTours = 0;
	int32 iCurNumMissions = 0;
	FString sMissionName = "";
	/*
	if (sLevelName ~= "entry")
	{
		return "";
	}
	sTemp = GetBaseDir();
	sFile = sTemp + "tours.ini";
	iCurNumTours = GetPrivateProfileInt(sFile, "Tours", "NumTours");
	for (iCurTour = 0; iCurTour < iCurNumTours; iCurTour++)
	{
		sLine = "Tour(" + FString::FromInt(iCurTour) + ")";
		sInfo = GetPrivateProfileString(sFile, "Tours", sLine);
		sLine = sInfo;
		iCurNumMissions = GetPrivateProfileInt(sFile, sLine, "NumMissions");
		for (iCurMission = 0; iCurMission < iCurNumMissions; iCurMission++)
		{
			sMissionName = GetPrivateProfileString(sFile, sLine, "MissionMapFilename(" + FString::FromInt(iCurMission) + ")");
			if (sMissionName ~= sLevelName)
			{
				return GetPrivateProfileString(sFile, sLine, "MissionMBSTitle(" + FString::FromInt(iCurMission) + ")");
			}
		}
	}
	*/
	return sLevelName;
}

FString UAADeploy_DCDS::GetAssetFullName(FString AssetName)
{
	int32 i = 0;
	if (MyDCDS != nullptr)
	{
		for (i = 0; i < MyDCDS->AssetInfoList.Num(); i++)
		{
			/*
			if (MyDCDS->AssetInfoList[i]->Name ~= AssetName)
			{
				return MyDCDS->AssetInfoList[i].FullName;
			}
			*/
		}
	}
	return "";
}

FString UAADeploy_DCDS::GetAssetName(FString AssetFullName)
{
	int32 i = 0;
	if (MyDCDS != nullptr)
	{
		/*
		for (i = 0; i < MyDCDS.AssetInfoList.Num(); i++)
		{
			if (MyDCDS.AssetInfoList[i].FullName ~= AssetFullName)
			{
				return MyDCDS.AssetInfoList[i].Name;
			}
		}
		*/
	}
	return "";
}

int32 UAADeploy_DCDS::GetListIndex(FString Filename)
{
	return lb_DCDSFileList->List->FindIndex(GetAssetName(Filename), false, true, nullptr);
}

void UAADeploy_DCDS::SetListProperty(FString Filename, FString Property)
{
	int32 i = 0;
	FString ListName = "";
	FString BitBucket = "";
	i = lb_DCDSFileList->List->FindIndex(GetAssetName(Filename), false, true, nullptr);
	ListName = lb_DCDSFileList->List->getItemAtIndex(i);
	/*
	Divide(ListName, " (", ListName, BitBucket);
	switch (Property)
	{
	case "Unavailable":
	case "Downloading":
	case "Complete":
	case "Completing":
	case "Queued":
	case "Initializing":
	case "Paused":
	case "Error":
	case "Already Updated":
		lb_DCDSFileList.List.SetItemAtIndex(i, ListName + " (" + Property + ")");
		break;
	case "":
		lb_DCDSFileList.List.SetItemAtIndex(i, ListName);
		break;
	default:
	}
	InternalOnChange(lb_DCDSFileList);
	*/
}

FString UAADeploy_DCDS::GetListProperty(FString Filename)
{
	int32 i=0;
	FString CurrentProperty="";
	FString ListName = "";
	FString BitBucket = "";
	/*
	i = lb_DCDSFileList.List.FindIndex(GetAssetName(Filename), false, true);
	ListName = lb_DCDSFileList.List.getItemAtIndex(i);
	ListName = lb_DCDSFileList.List.Get();
	Divide(ListName, " (", BitBucket, CurrentProperty);
	Divide(CurrentProperty, ")", CurrentProperty, BitBucket);
	*/
		return CurrentProperty;
}

FString UAADeploy_DCDS::GetCurrentListProperty()
{
	FString CurrentProperty="";
	FString ListName = "";
	FString BitBucket = "";
	/*
	ListName = lb_DCDSFileList.List.Get();
	Divide(ListName, " (", BitBucket, CurrentProperty);
	Divide(CurrentProperty, ")", CurrentProperty, BitBucket);
	*/
		return CurrentProperty;
}

void UAADeploy_DCDS::InternalDownloadAssetComplete(bool success, bool ErrorUnavailable, bool ErrorUpToDate)
{
	AHumanController* HC = nullptr;
	FString NotificationCaption = "";
	FString RequestedMap = "";
	/*
	if (success && (!bManuallyHalted))
	{
		if (RequestedFile != "")
		{
			SetListProperty(RequestedFile, "Complete");
			RequestedMap = GetLevelMissionName(GetAssetName(RequestedFile));
			NotificationCaption = Repl(CompletedCaptionText, "%AssetTitle%", RequestedMap);
			HC = Cast<AHumanController>(PlayerOwner());
			if ((HC != nullptr) && (Controller.GetMenuStackSize() == 0))
			{
				HC.SetPlayTips("DCDS Download Notification", NotificationCaption, 5);
			}
			else
			{
				Controller.OpenMenu("AGP_Interface.AAGameMenu_DCDS_Complete", , NotificationCaption);
			}
		}
		UpdateDownloadProgressUI(0);
		pb_DownloadProgress.CurrentValue = pb_DownloadProgress.MaxValue;
		l_DownloadStatsProgress.Caption = "Progress: 100% downloaded";
		l_DownloadStatsBitRate.Caption = "Bit Rate:" @ "Transfer completed!";
		RequestedFile = "";
		QueuedFile = "";
		DownloadNextHaltedAsset();
	}
	else
	{
		if (bManuallyHalted)
		{
			l_DownloadStatsBitRate.Caption = "Bit Rate:" @ "Transfer failed.";
		}
		else
		{
			if (ErrorUnavailable)
			{
				if (RequestedFile != "")
				{
					SetListProperty(RequestedFile, "Unavailable");
				}
				else
				{
					SetListProperty(QueuedFile, "Unavailable");
				}
				RequestedFile = "";
				QueuedFile = "";
				DownloadNextHaltedAsset();
			}
			else
			{
				if (ErrorUpToDate)
				{
					if (RequestedFile != "")
					{
						SetListProperty(RequestedFile, "Already Updated");
					}
					else
					{
						SetListProperty(QueuedFile, "Already Updated");
					}
					RequestedFile = "";
					QueuedFile = "";
					DownloadNextHaltedAsset();
				}
				else
				{
					if (RequestedFile != "")
					{
						SetListProperty(RequestedFile, "Error");
					}
					else
					{
						SetListProperty(QueuedFile, "Error");
					}
					RequestedFile = "";
					QueuedFile = "";
					DownloadNextHaltedAsset();
				}
			}
		}
	}
	ResetProgress();
	*/
}

void UAADeploy_DCDS::InternalBeginningDownload(FString Filename, int32 Size, FString SHA)
{
	ResetProgress();
	QueuedFile = "";
	RequestedFile = Filename;
	FileSize = Size;
	SetListProperty(RequestedFile, "Downloading");
	l_DownloadStatsFileName->bVisible = true;
	l_DownloadStatsFileSize->bVisible = true;
	l_DownloadStatsProgress->bVisible = true;
	l_DownloadStatsBitRate->bVisible = true;
	l_DownloadStatsIdle->bVisible = false;
	l_DownloadInstructions->bVisible = false;
}

void UAADeploy_DCDS::InternalContinuingDownload(int32 Bitrate, float ElapsedTime, int32 TimeRemaining, int32 DownloadBytesCompleted)
{
	Transferred = DownloadBytesCompleted;
	UpdateDownloadProgressUI(Bitrate);
}

void UAADeploy_DCDS::UpdateDownloadProgressUI(int32 Bitrate)
{
	/*
	pb_DownloadProgress.CurrentValue =FMath::Clamp((float(Transferred) / float(FileSize)), pb_DownloadProgress.MinValue, pb_DownloadProgress.MaxValue);
	l_DownloadStatsFileName.Caption = "File Name:" @ RequestedFile;
	l_DownloadStatsFileSize.Caption = "File Size:" @ FString::FromInt((FileSize / 1024)) @ "kb";
	l_DownloadStatsProgress.Caption = "Progress:" @ FString::FromInt((pb_DownloadProgress.CurrentValue * 100)) + "% downloaded";
	l_DownloadStatsBitRate.Caption = "Bit Rate:" @ FString::FromInt((Bitrate / 1024)) @ "kb/sec (transfer speed)";
	if (pb_DownloadProgress.CurrentValue >= 0.95)
	{
		SetListProperty(RequestedFile, "Completing");
	}
	*/
}

void UAADeploy_DCDS::InternalImageReady(FDCDSImageInfo Image)
{
	FString MyLink = "";
	/*
	MyLink = "<textlink><content>" + Image.HttpLink + "</content><link>" + Image.HttpLink + "</link><style>MediumText</style></textlink>";
	LoadDynamicPanel(Image.Image, MyLink, Image.Caption);
	*/
}

