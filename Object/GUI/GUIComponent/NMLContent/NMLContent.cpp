// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/NMLImageButton/NMLImageButton.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"
#include "AA29/Object/HttpLinkItem/HttpLinkItem.h"

UNMLContent::UNMLContent()
{
	DynamicContentPath = "DynamicContent\\NML";
	NMLStatusIconTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_new_nml_Mat.t_ui_gui_new_nml_Mat'"), NULL, LOAD_None, NULL);
}

void UNMLContent::dTargetForLinks(UGUIComponent* Sender)
{
}

void UNMLContent::dInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
}

void UNMLContent::dPreParser(FString NMLString)
{
}

//native Function Texture GetImageFromDDS(FString FilePath, Level LevelForFactory);
UMaterialInstance* UNMLContent::GetImageFromDDS(FString FilePath, ALevelInfo* LevelForFactory)
{
	return nullptr;
}

void UNMLContent::ParseNMLFromFile(FString Filename, UGUIContentBox* Panel)
{
	FString NMLString = "";
	FString NMLLine = "";
	if (bVerboseLogging)
	{
		//Log("--== NMLContent::ParseNMLFromFile() called. ==--");
	}
	LocalNMLFile = Filename;
	TargetPanel = Panel;
	/*
	if (DoesFileExist(Filename))
	{
		FOpen(Filename);
		if (FReadLine(NMLLine))
		{
			(NMLString += NMLLine);
		}
		FClose();
		TargetPanel.SetVisibility(false);
		TargetPanel.RemoveAllComponents();
		dPreParser(NMLString);
		if (bShouldFindDependencies)
		{
			ParseNMLForDependencies(NMLString, LocalCopyDependencies);
		}
		ParseNML(NMLString);
	}
	TargetPanel.SetVisibility(true);
	*/
}

void UNMLContent::ParseNMLFromServer(FString Filename, FString Server, int32 Port, UGUIContentBox* Panel, UGUIImage* Icon, UGUILabel* Text)
{
	AActor* SpawningActor = nullptr;
	UHttpLinkItem* RequestedItem = nullptr;
	UAAGUIController* GlobalController = nullptr;
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::ParseNMLFromServer() called. ==--");
	}
	TargetPanel = Panel;
	if (Icon != nullptr)
	{
		NMLStatusIcon = Icon;
		NMLStatusIcon.Image = NMLStatusIconTexture;
	}
	if (Text != nullptr)
	{
		NMLStatusText = Text;
	}
	StoredServer = Server;
	StoredPort = Port;
	Dependencies.RemoveAt(0, Dependencies.Num());
	PendingDependencies = 0;
	LocalNMLFile = FixFilePath(Filename);
	if (AlreadyRequested(LocalNMLFile))
	{
		if (DoesFileExist(LocalNMLFile))
		{
			bShouldFindDependencies = false;
			UpdateNMLStatus("Content is up-to-date.");
			ParseNMLFromFile(LocalNMLFile, TargetPanel);
			return;
		}
	}
	GlobalController = AAGUIController(Controller);
	if (GlobalController != nullptr)
	{
		if (GlobalController.GlobalNMLQueue == nullptr)
		{
			SpawningActor = FindActor();
			if (SpawningActor != nullptr)
			{
				GlobalController.GlobalNMLQueue = SpawningActor.Spawn(AHttpLink::StaticClass());
				DependencyLink = GlobalController.GlobalNMLQueue;
			}
			else
			{
				Log("SpawningActor is NONE!");
			}
		}
		else
		{
			DependencyLink = GlobalController.GlobalNMLQueue;
		}
	}
	if (DependencyLink != nullptr)
	{
		DependencyLink.SetHost(Server, Port);
		DependencyLink.SetLocalFilePath(DynamicContentPath);
		RequestedItem = DependencyLink.RequestText(Filename);
		RequestedItem.__OnReceivedText__Delegate = ReceivedNewNMLFile;
		RequestedItem.__OnReceivedCachedFile__Delegate = ReceivedCachedNMLFile;
		LocalNMLFile = FixFilePath(Filename);
		UpdateNMLStatus("Checking for updates...");
	}
	if (DoesFileExist(LocalNMLFile))
	{
		bShouldFindDependencies = true;
		ParseNMLFromFile(LocalNMLFile, TargetPanel);
	}
	*/
}

void UNMLContent::ParseNMLFromString(FString NMLString, UGUIContentBox* Panel)
{
	if (bVerboseLogging)
	{
		//Log("--== NMLContent::ParseNMLFromString() called. ==--");
	}
	TargetPanel = Panel;
	//TargetPanel->RemoveAllComponents();
	ParseNML(NMLString);
}

void UNMLContent::ReceivedNewNMLFile(FString Filename, FString NMLChunk)
{
	UpdateNMLStatus("Updating content...");
	if (LocalNMLFile != FixFilePath(Filename))
	{
		return;
	}
	SaveAndProcessNML(Filename, NMLChunk);
}

void UNMLContent::SaveAndProcessNML(FString Filename, FString NMLChunk)
{
	FString PristineVersion = "";
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::SaveAndProcessNML() called. ==--");
	}
	LocalNMLFile = FixFilePath(Filename);
	PristineVersion = NMLChunk;
	dPreParser(NMLChunk);
	ParseNMLForDependencies(NMLChunk, Dependencies);
	if (Dependencies.Num() != 0)
	{
		DownloadedNMLChunk = PristineVersion;
		GetDependenciesFromServer();
	}
	else
	{
		if (bVerboseLogging)
		{
			Log("No dependencies found...saving file to disk...");
		}
		SaveTextDependencyToDisk(LocalNMLFile, PristineVersion);
		RequestedPages[RequestedPages.Num()] = LocalNMLFile;
		UpdateNMLStatus("Content is up-to-date.");
		ParseNMLFromFile(LocalNMLFile, TargetPanel);
		if (bShouldFindDependencies)
		{
			CleanUpGarbage();
		}
	}
	*/
}

void UNMLContent::ParseNMLForDependencies(FString NMLChunk, TArray<FString>& DependencyArray)
{
	int32 i = 0;
	int32 bp = 0;
	int32 ep = 0;
	FString NewDependency = "";
	bool bIsDuplicate = false;
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::ParseNMLForDependencies() called. ==--");
	}
	bp = (InStr(NMLChunk, "<imagesrc>") + 10);
	ep = InStr(NMLChunk, "</imagesrc>");
	if (bp == (ep + 10))
	{
		return;
	}
	NewDependency = Mid(NMLChunk, bp, (ep - bp));
	i = 0;
	if (i < Dependencies.Num())
	{
		if (DependencyArray[i] == NewDependency)
		{
			bIsDuplicate = true;
		}
		else
		{
			i++;
		}
	}
	if ((!bIsDuplicate) && (InStr(NewDependency, "%") == -1))
	{
		DependencyArray.insert(0, 1);
		DependencyArray[0] = NewDependency;
	}
	ParseNMLForDependencies(Mid(NMLChunk, (ep + 6)), DependencyArray);
	*/
}

void UNMLContent::GetDependenciesFromServer()
{
	UHttpLinkItem* RequestedItem = nullptr;
	int32 i = 0;
	UAAGUIController* GlobalController = nullptr;
	AActor* SpawningActor = nullptr;
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::GetDependenciesFromServer() called. ==--");
	}
	GlobalController = AAGUIController(Controller);
	if (GlobalController != nullptr)
	{
		if (GlobalController.GlobalNMLQueue == nullptr)
		{
			SpawningActor = FindActor();
			if (SpawningActor != nullptr)
			{
				GlobalController.GlobalNMLQueue = SpawningActor.Spawn(AHttpLink::StaticClass());
				DependencyLink = GlobalController.GlobalNMLQueue;
			}
			else
			{
				Log("SpawningActor is NONE!");
			}
		}
		else
		{
			DependencyLink = GlobalController.GlobalNMLQueue;
		}
	}
	if (DependencyLink != nullptr)
	{
		for (i = 0; i < Dependencies.Num(); i++)
		{
			RequestedItem = DependencyLink.RequestBinary(Dependencies[i]);
			RequestedItem.__OnReceivedBinary__Delegate = SaveBinaryDependencyToDisk;
			RequestedItem.__OnReceivedCachedFile__Delegate = ReceivedCachedBinaryFile;
			PendingDependencies++;
		}
	}
	*/
}

//native Function bool SaveBinaryDependencyToDisk(FString Filename, array<byte> ReceivedFile);
bool UNMLContent::SaveBinaryDependencyToDisk(FString Filename, TArray<uint8> ReceivedFile)
{
	return false;   //FAKE   /ELiZ
}

void UNMLContent::SaveTextDependencyToDisk(FString Filename, FString ReceivedFile)
{
	FString Buffer = "";
	int32 BufferHead = 0;
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::SaveTextDependencyToDisk() called. ==--");
		Log("Length of ReceivedFile:  " + FString::FromInt(Len(ReceivedFile)));
		Log("FileName:  " + Filename);
	}
	if (FOpenWrite(Filename))
	{
		BufferHead = 0;
		if (BufferHead <= Len(ReceivedFile))
		{
			Buffer = Mid(ReceivedFile, BufferHead, 768);
			FWrite(Buffer);
			(BufferHead += 768);
		}
		FClose();
	}
	*/
}

void UNMLContent::ReceivedCachedNMLFile(FString Filename)
{
	FString NMLString = "";
	FString NMLLine = "";
	/*
	if (LocalNMLFile != FixFilePath(Filename))
	{
		return;
	}
	RequestedPages[RequestedPages.Num()] = LocalNMLFile;
	UpdateNMLStatus("Content is up-to-date.");
	if (DoesFileExist(FixFilePath(Filename)))
	{
		FOpen(FixFilePath(Filename));
		if (FReadLine(NMLLine))
		{
			(NMLString += NMLLine + Chr(13) + Chr(10));
		}
		FClose();
	}
	SaveAndProcessNML(Filename, NMLString);
	*/
}

void UNMLContent::ReceivedCachedBinaryFile(FString Filename)
{
	/*
	if (!IsADependency(Filename))
	{
		Dependencies.RemoveAt(0, Dependencies.Num());
		PendingDependencies = 0;
		return;
	}
	(PendingDependencies);
	if (PendingDependencies == 0)
	{
		DependenciesLoaded();
	}
	*/
}

void UNMLContent::DependenciesLoaded()
{
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::DependenciesLoaded() called. ==--");
	}
	SaveTextDependencyToDisk(LocalNMLFile, DownloadedNMLChunk);
	TargetPanel.RemoveAllComponents();
	ParseNMLFromFile(LocalNMLFile, TargetPanel);
	RequestedPages[RequestedPages.Num()] = LocalNMLFile;
	UpdateNMLStatus("Content is up-to-date.");
	if (bShouldFindDependencies)
	{
		CleanUpGarbage();
	}
	*/
}

void UNMLContent::UpdateNMLStatus(FString NewStatus)
{
	/*
	if ((NMLStatusIcon != nullptr) && (NMLStatusText != nullptr))
	{
		NMLStatusIcon.bVisible = true;
		NMLStatusText.Caption = NewStatus;
	}
	*/
}

void UNMLContent::CleanUpGarbage()
{
	int32 i = 0;
	int32 j = 0;
	bool bShouldDelete = false;
	/*
	if (bVerboseLogging)
	{
		Log("--== NMLContent::CleanUpGarbage() called. ==--");
	}
	for (i = 0; i < LocalCopyDependencies.Num(); i++)
	{
		bShouldDelete = true;
		j = 0;
		if (j < Dependencies.Num())
		{
			if (LocalCopyDependencies[i] == Dependencies[j])
			{
				bShouldDelete = false;
			}
			else
			{
				j++;
			}
		}
		if (bShouldDelete)
		{
			if (FDelete(FixFilePath(LocalCopyDependencies[i])))
			{
				DependencyLink.DeleteFileFromCache(LocalCopyDependencies[i]);
			}
		}
	}
	*/
}

void UNMLContent::ParseNMLChunk(FString& WorkingString, FString& Token, FString& Content)
{
	int32 bp = 0;
	int32 ep = 0;
	/*
	bp = InStr(WorkingString, "<");
	ep = InStr(WorkingString, ">");
	Token = Mid(WorkingString, (bp + 1), ((ep - bp) - 1));
	bp = InStr(WorkingString, "</" + Token + ">");
	Content = Mid(WorkingString, (ep + 1), ((bp - ep) - 1));
	WorkingString = Mid(WorkingString, ((bp + Len(Token)) + 3));
	*/
}

void UNMLContent::ParseNML(FString NMLText)
{
	UAAGUILabel* Lbl = nullptr;
	UGUILabelButton* LblBtn = nullptr;
	UNMLImageButton* img = nullptr;
	UGUIGridLayout* Grid = nullptr;
	UGUIContentBox* SubPanel = nullptr;
	FString myToken = "";
	FString myContent = "";
	int32 OuterSafety = 0;
	/*
	OuterSafety = (Len(NMLText) + 1);
	if (Len(NMLText) > 0)
	{
		if (Len(NMLText) == OuterSafety)
		{
		}
		OuterSafety = Len(NMLText);
		ParseNMLChunk(NMLText, myToken, myContent);
		switch(myToken)
		{
			case "text":
				Lbl = Cast<UAAGUILabel>(TargetPanel.addItem("AGP_Interface.AAGUILabel"));
				if (Lbl != nullptr)
				{
					ParseTerminalText(Lbl, myContent);
				}
				break;
			case "textlink":
				LblBtn = Cast<UGUILabelButton>(TargetPanel.addItem("AGP_Interface.GUILabelButton"));
				if (LblBtn != nullptr)
				{
					ParseTerminalTextLink(LblBtn, myContent);
				}
				break;
			case "image":
				img = NMLImageButton(TargetPanel.addItem("AGP_Interface.NMLImageButton"));
				if (img != nullptr)
				{
					ParseTerminalImage(img, myContent);
				}
				break;
			case "hr":
				Lbl = Cast<UAAGUILabel>(TargetPanel.addItem("AGP_Interface.AAGUILabel"));
				if (Lbl != nullptr)
				{
					ParseTerminalHR(Lbl, myContent);
				}
				break;
			case "news":
				Grid = GUIGridLayout(TargetPanel.addItem("AGP_Interface.GUIGridLayout"));
				if (Grid != nullptr)
				{
					ParseTerminalNews(Grid, myContent);
				}
				break;
			case "grid":
				Grid = GUIGridLayout(TargetPanel.addItem("AGP_Interface.GUIGridLayout"));
				if (Grid != nullptr)
				{
					ParseNonTerminalGrid(Grid, myContent);
				}
				break;
			case "panel":
				SubPanel = GUIContentBox(TargetPanel.addItem("AGP_Interface.GUIContentBox"));
				if (SubPanel != nullptr)
				{
					ParseNonTerminalPanel(SubPanel, myContent);
				}
				break;
			default:
		}
	}
	*/
}

void UNMLContent::ParseTerminalTextLink(UGUILabelButton* Lbl, FString Properties)
{
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	/*
	Lbl.Style = Controller.GetStyle("LinkButton", FontScale);
	Lbl.bMultiLine = true;
	Lbl.TextAlign = 0;
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "content":
				Lbl.Caption = myContent;
				break;
			case "style":
				Lbl.Style = Controller.GetStyle(myContent, FontScale);
				break;
			case "align":
				switch(myContent)
				{
			case "left":
				Lbl.TextAlign = 0;
				break;
			case "right":
				Lbl.TextAlign = 2;
				break;
			case "center":
				Lbl.TextAlign = 1;
				break;
			default:
				}
			case "link":
				Lbl.link = myContent;
				Lbl.__OnClick__Delegate = OnLinkButtonClick;
			default:
		}
	}
	Lbl.bMultiLine = true;
	*/
}

void UNMLContent::ParseTerminalText(UAAGUILabel* Lbl, FString Properties)
{
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	/*
	Lbl.Style = Controller.GetStyle("MediumText", FontScale);
	Lbl.bMultiLine = true;
	Lbl.TextAlign = 0;
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "content":
				Lbl.Caption = myContent;
				break;
			case "style":
				Lbl.Style = Controller.GetStyle(myContent, FontScale);
				break;
			case "align":
				switch(myContent)
				{
			case "left":
				Lbl.TextAlign = 0;
				break;
			case "right":
				Lbl.TextAlign = 2;
				break;
			case "center":
				Lbl.TextAlign = 1;
				break;
			default:
				}
			default:
		}
	}
	Lbl.bMultiLine = true;
	*/
}

void UNMLContent::ParseTerminalHR(UAAGUILabel* Lbl, FString Properties)
{
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	/*
	Lbl.Caption = "         -----------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	Lbl.Style = Controller.GetStyle("NMLTinyText", FontScale);
	Lbl.bMultiLine = false;
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "style":
				Lbl.Style = Controller.GetStyle(myContent, FontScale);
				break;
			default:
				break;
		}
	}
	*/
}

void UNMLContent::ParseTerminalImage(UNMLImageButton* img, FString Properties)
{
	UMaterialInstance* ImageRef = nullptr;
	ALevelInfo* ImageFactoryLevel = nullptr;
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	/*
	img.ImageRenderStyle = 1;
	img.ImageStyle = 2;
	img.WinWidth = 256;
	img.WinHeight = 256;
	img.bAcceptsInput = false;
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "imagesrc":
				if (myContent == "")
				{
					break;
				}
				ImageFactoryLevel = SearchForLevel();
				myContent = FixFilePath(myContent);
				if ((ImageFactoryLevel != nullptr) && DoesFileExist(myContent))
				{
					ImageRef = GetImageFromDDS(myContent, ImageFactoryLevel);
				}
				img.Image = ImageRef;
				break;
			case "localsrc":
				if (myContent == "")
				{
					break;
				}
				ImageFactoryLevel = SearchForLevel();
				myContent = FixFilePath(myContent);
				if ((ImageFactoryLevel != nullptr) && DoesFileExist(myContent))
				{
					ImageRef = GetImageFromDDS(myContent, ImageFactoryLevel);
				}
				img.Image = ImageRef;
				break;
			case "packagesrc":
				if (myContent == "")
				{
					break;
				}
				img.Image = Texture(DynamicLoadObject(myContent, Class'Texture'));
				break;
			case "width":
				img.WinWidth = float(myContent);
				break;
			case "height":
				img.WinHeight = float(myContent);
				break;
			case "nmllink":
				img.bAcceptsInput = true;
				img.link = myContent;
				img.__OnClick__Delegate = OnImageButtonClick;
				break;
			case "panellink":
				ParseTerminalPanelLink(img, myContent);
				img.bAcceptsInput = true;
				img.__OnClick__Delegate = OnInterPanelLink;
				break;
			default:
				break;
		}
	}
	*/
}

void UNMLContent::ParseTerminalPanelLink(UNMLImageButton* img, FString Properties)
{
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	/*
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "panelname":
				img.LinkPanelName = myContent;
				break;
			case "param1":
				img.LinkParam1 = int(myContent);
				break;
			case "param2":
				img.LinkParam2 = int(myContent);
				break;
			case "param3":
				img.LinkParam3 = myContent;
				break;
			default:
				break;
		}
	}
	*/
}

void UNMLContent::ParseTerminalNews(UGUIGridLayout* Grid, FString Properties)
{
	UGUIGridLayout* SubGrid = nullptr;
	UAAGUILabel* Lbl = nullptr;
	ALevelInfo* ImageFactoryLevel = nullptr;
	UMaterialInstance* ImageRef = nullptr;
	UGUILabelButton* lb_Link = nullptr;
	UNMLImageButton* img = nullptr;
	FString NewsTitle = "";
	FString NewsDate = "";
	FString NewsAuthor = "";
	FString NewsContent = "";
	FString NewsLink = "";
	FString NewsImage = "";
	FString myToken = "";
	FString myContent = "";
	int32 InnerSafety = 0;
	NewsTitle = "";
	NewsDate = "";
	NewsAuthor = "";
	NewsContent = "";
	NewsLink = "";
	NewsImage = "";
	/*
	InnerSafety = (Len(Properties) + 1);
	if (Len(Properties) > 0)
	{
		if (InnerSafety == Len(Properties))
		{
		}
		InnerSafety = Len(Properties);
		ParseNMLChunk(Properties, myToken, myContent);
		switch(myToken)
		{
			case "title":
				NewsTitle = myContent;
				break;
			case "date":
				NewsDate = myContent;
				break;
			case "author":
				NewsAuthor = myContent;
				break;
			case "content":
				NewsContent = myContent;
				break;
			case "link":
				NewsLink = myContent;
				break;
			case "imagesrc":
				NewsImage = FixFilePath(myContent);
				break;
			default:
				break;
		}
	}
	Grid->NumColumns = 2;
	Grid->RowSpacing = 0.025;
	Grid->ColumnSpacing = 0;
	SubGrid = GUIGridLayout(Grid->CreateItem("AGP_Interface.GUIGridLayout", 4));
	SubGrid->NumColumns = 1;
	SubGrid->RowSpacing = 0.01;
	Lbl = Cast<UAAGUILabel>(SubGrid->CreateItem("AGP_Interface.AAGUILabel", 4));
	Lbl.Caption = NewsTitle;
	Lbl.Style = Controller.GetStyle("Header", FontScale);
	Lbl.bMultiLine = true;
	Lbl = Cast<UAAGUILabel>(SubGrid->CreateItem("AGP_Interface.AAGUILabel", 4));
	Lbl.Caption = NewsDate;
	if (Len(NewsAuthor) > 0)
	{
		(Lbl.Caption += " - by " + NewsAuthor);
	}
	Lbl.Style = Controller.GetStyle("SmallText", FontScale);
	Lbl.bMultiLine = true;
	Lbl = Cast<UAAGUILabel>(SubGrid->CreateItem("AGP_Interface.AAGUILabel", 5));
	Lbl.Caption = NewsContent;
	Lbl.Style = Controller.GetStyle("MediumText", FontScale);
	Lbl.bMultiLine = true;
	lb_Link = Cast<UGUILabelButton>(SubGrid->CreateItem("AGP_Interface.GUILabelButton", 5));
	lb_Link.Style = Controller.GetStyle("LinkButton", FontScale);
	lb_Link.Caption = "Click Here For More >>";
	lb_Link.link = NewsLink;
	lb_Link.bMultiLine = true;
	lb_Link.__OnClick__Delegate = OnLinkButtonClick;
	ImageFactoryLevel = SearchForLevel();
	if ((ImageFactoryLevel != nullptr) && DoesFileExist(NewsImage))
	{
		ImageRef = GetImageFromDDS(NewsImage, ImageFactoryLevel);
	}
	img = NMLImageButton(Grid->CreateItem("AGP_Interface.NMLImageButton", 1));
	img.Image = ImageRef;
	img.ImageRenderStyle = 1;
	img.ImageStyle = 2;
	img.WinWidth = 0.25;
	img.WinHeight = 0.25;
	img.bAcceptsInput = false;
	*/
}

void UNMLContent::ParseNonTerminalGrid(UGUIGridLayout* Grid, FString Content)
{
	UAAGUILabel* Lbl = nullptr;
	UGUILabelButton* LblBtn = nullptr;
	UNMLImageButton* img = nullptr;
	UGUIGridLayout* ChildGrid = nullptr;
	UGUIContentBox* SubPanel = nullptr;
	FString myToken = "";
	FString myContent = "";
	FString ChildToken = "";
	FString ChildContent = "";
	int32 OuterSafety = 0;
	/*
	OuterSafety = (Len(Content) + 1);
	Grid->NumColumns = 1;
	Grid->RowSpacing = 0.025;
	Grid->ColumnSpacing = 0;
	if (Len(Content) > 0)
	{
		if (Len(Content) == OuterSafety)
		{
		}
		OuterSafety = Len(Content);
		ParseNMLChunk(Content, myToken, myContent);
		switch(myToken)
		{
			case "columns":
				Grid->NumColumns = int(myContent);
				break;
			case "columnwidth":
				Grid->AddColumnWidth(float(myContent));
				break;
			case "rowspacing":
				Grid->RowSpacing = float(myContent);
				break;
			case "columnspacing":
				Grid->ColumnSpacing = float(myContent);
				break;
			case "winwidth":
				Grid->WinWidth = float(myContent);
				break;
			case "winheight":
				Grid->WinHeight = float(myContent);
				break;
			case "cell":
			case "topcell":
			case "bottomcell":
				ParseNMLChunk(myContent, ChildToken, ChildContent);
				switch(ChildToken)
				{
			case "text":
				Lbl = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", GetCellAlign(myToken)));
				if (Lbl != nullptr)
				{
					ParseTerminalText(Lbl, ChildContent);
				}
				break;
			case "textlink":
				LblBtn = Cast<UGUILabelButton>(Grid->CreateItem("AGP_Interface.GUILabelButton", GetCellAlign(myToken)));
				if (LblBtn != nullptr)
				{
					ParseTerminalTextLink(LblBtn, ChildContent);
				}
				break;
			case "image":
				img = NMLImageButton(Grid->CreateItem("AGP_Interface.NMLImageButton", GetCellAlign(myToken)));
				if (img != nullptr)
				{
					ParseTerminalImage(img, ChildContent);
				}
				break;
			case "hr":
				Lbl = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", GetCellAlign(myToken)));
				if (Lbl != nullptr)
				{
					ParseTerminalHR(Lbl, ChildContent);
				}
				break;
			case "news":
				ChildGrid = GUIGridLayout(Grid->CreateItem("AGP_Interface.GUIGridLayout", GetCellAlign(myToken)));
				if (ChildGrid != nullptr)
				{
					ParseTerminalNews(ChildGrid, ChildContent);
				}
				break;
			case "panel":
				SubPanel = GUIContentBox(Grid->CreateItem("AGP_Interface.GUIContentBox", GetCellAlign(myToken)));
				if (SubPanel != nullptr)
				{
					ParseNonTerminalPanel(SubPanel, ChildContent);
				}
				break;
			default:
				break;
				}
			default:
		}
	}
	*/
}

void UNMLContent::ParseNonTerminalPanel(UGUIContentBox* SubPanel, FString Content)
{
	UAAGUILabel* Lbl = nullptr;
	UGUILabelButton* LblBtn = nullptr;
	UNMLImageButton* img = nullptr;
	UGUIGridLayout* ChildGrid = nullptr;
	FString myToken = "";
	FString myContent = "";
	FString ChildToken = "";
	FString ChildContent = "";
	int32 OuterSafety = 0;
	/*
	OuterSafety = (Len(Content) + 1);
	SubPanel.ItemSpacing = 0.0005;
	SubPanel.WinHeight = 0.25;
	SubPanel.MyPanel.Background = Texture'T_AA2_UI.Menu.field_tabwindow';
	SubPanel.Style = Controller.GetStyle("NMLPanel", FontScale);
	SubPanel.MyPanel.Style = Controller.GetStyle("NMLPanel", FontScale);
	SubPanel.bAcceptsInput = false;
	SubPanel.bCenterItems = false;
	SubPanel.SideGaps = 0;
	if (Len(Content) > 0)
	{
		if (Len(Content) == OuterSafety)
		{
		}
		OuterSafety = Len(Content);
		ParseNMLChunk(Content, myToken, myContent);
		switch(myToken)
		{
			case "itemspacing":
				SubPanel.ItemSpacing = float(myContent);
				break;
			case "winheight":
				SubPanel.WinHeight = float(myContent);
				break;
			case "winwidth":
				SubPanel.WinWidth = float(myContent);
				break;
			case "noscrollbar":
				if (myContent == "true")
				{
					SubPanel.bNoScrollBar = true;
				}
				else
				{
					if (myContent == "false")
					{
						SubPanel.bNoScrollBar = false;
					}
				}
			case "scaletocontents":
				if (myContent == "true")
				{
					SubPanel.MyPanel.bScaleHeightToContents = true;
				}
				else
				{
					if (myContent == "false")
					{
						SubPanel.MyPanel.bScaleHeightToContents = false;
					}
				}
			case "leftoffset":
				SubPanel.MyPanel.DynamicBorderOffsets[0] = float(myContent);
				SubPanel.MyPanel.bUseDynamicBorderOffsets = true;
			case "rightoffset":
				SubPanel.MyPanel.DynamicBorderOffsets[2] = float(myContent);
				SubPanel.MyPanel.bUseDynamicBorderOffsets = true;
			case "topoffset":
				SubPanel.MyPanel.DynamicBorderOffsets[1] = float(myContent);
				SubPanel.MyPanel.bUseDynamicBorderOffsets = true;
			case "bottomoffset":
				SubPanel.MyPanel.DynamicBorderOffsets[3] = float(myContent);
				SubPanel.MyPanel.bUseDynamicBorderOffsets = true;
			case "nobackground":
				if (myContent == "true")
				{
					SubPanel.MyPanel.Background = nullptr;
					SubPanel.Style = Controller.GetStyle("NoBackground", FontScale);
					SubPanel.MyPanel.Style = Controller.GetStyle("NoBackground", FontScale);
				}
			case "center":
				if (myContent == "true")
				{
					SubPanel.MyPanel.bCenterItems = true;
				}
			case "row":
				ParseNMLChunk(myContent, ChildToken, ChildContent);
				switch(ChildToken)
				{
			case "text":
				Lbl = Cast<UAAGUILabel>(SubPanel.addItem("AGP_Interface.AAGUILabel"));
				if (Lbl != nullptr)
				{
					ParseTerminalText(Lbl, ChildContent);
				}
				break;
			case "textlink":
				LblBtn = Cast<UGUILabelButton>(SubPanel.addItem("AGP_Interface.GUILabelButton"));
				if (LblBtn != nullptr)
				{
					ParseTerminalTextLink(LblBtn, ChildContent);
				}
				break;
			case "image":
				img = NMLImageButton(SubPanel.addItem("AGP_Interface.NMLImageButton"));
				if (img != nullptr)
				{
					ParseTerminalImage(img, ChildContent);
					if (SubPanel.MyPanel.bScaleHeightToContents)
					{
						img.bScaleToParent = false;
					}
				}
				break;
			case "hr":
				Lbl = Cast<UAAGUILabel>(SubPanel.addItem("AGP_Interface.AAGUILabel"));
				if (Lbl != nullptr)
				{
					ParseTerminalHR(Lbl, myContent);
				}
				break;
			case "news":
				ChildGrid = GUIGridLayout(SubPanel.addItem("AGP_Interface.GUIGridLayout"));
				if (ChildGrid != nullptr)
				{
					ParseTerminalNews(ChildGrid, ChildContent);
				}
				break;
			case "grid":
				ChildGrid = GUIGridLayout(SubPanel.addItem("AGP_Interface.GUIGridLayout"));
				if (ChildGrid != nullptr)
				{
					ParseNonTerminalGrid(ChildGrid, ChildContent);
				}
				break;
			default:
				break;
				}
			default:
		}
	}
	*/
}

bool UNMLContent::OnLinkButtonClick(UGUIComponent* Sender)
{
	/*
	if (Cast<UGUILabelButton>(Sender) != nullptr)
	{
		if (Cast<UGUILabelButton>(Sender).link != "")
		{
			Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUILabelButton>(Sender).link, Cast<UGUILabelButton>(Sender).link);
			return true;
		}
	}
	*/
	return false;
}

bool UNMLContent::OnImageButtonClick(UGUIComponent* Sender)
{
	/*
	if (UNMLImageButton*(Sender) != nullptr)
	{
		if (UNMLImageButton*(Sender).link != "")
		{
			if (bVerboseLogging)
			{
				Log("Image Button Clicked!");
			}
			Sender.LoseFocus(nullptr);
			TargetPanel.RemoveAllComponents();
			if (StoredServer == "")
			{
				ParseNMLFromFile(FixFilePath(UNMLImageButton*(Sender).link), TargetPanel);
			}
			else
			{
				ParseNMLFromServer(UNMLImageButton*(Sender).link, StoredServer, StoredPort, TargetPanel);
			}
			return true;
		}
	}
	*/
	return false;
}

bool UNMLContent::OnInterPanelLink(UGUIComponent* Sender)
{
	UNMLImageButton* LinkButton = nullptr;
	/*
	LinkButton = NMLImageButton(Sender);
	if (LinkButton != nullptr)
	{
		if (bVerboseLogging)
		{
			Log("Inter-panel Image Button Clicked!");
		}
		LinkButton.LoseFocus(nullptr);
		dInterPanelLink(LinkButton.LinkPanelName, LinkButton.LinkParam1, LinkButton.LinkParam2, LinkButton.LinkParam3);
	}
	*/
	return false;
}

ALevelInfo* UNMLContent::SearchForLevel()
{
	//local Level SomeLevel;
	//ForEach AllObjects(Class'Level', SomeLevel)
	//{
	//	return SomeLevel;
	//}
	return nullptr;
}
bool UNMLContent::DoesFileExist(FString Filename)
{
	/*
	if (FOpen(Filename))
	{
		FClose();
		return true;
	}
	*/
	return false;
}

AActor* UNMLContent::FindActor()
{
	AActor* SomeActor = nullptr;
	/*
	ForEach AllObjects(Class'Actor', SomeActor)
	{
		return SomeActor;
	}
	*/
	return nullptr;
}

uint8 UNMLContent::GetCellAlign(FString Key)
{
	if (Key == "cell")
	{
		return 4;
	}
	if (Key == "topcell")
	{
		return 1;
	}
	if (Key == "bottomcell")
	{
		return 7;
	}
	return 4;
}

FString UNMLContent::FixFilePath(FString FilePath)
{
	//FilePath = DynamicContentPath + FilePath;
	//return Repl(FilePath, "/", "\\");

	return "FAKE";    //FAKE    /ELiZ
}

bool UNMLContent::AlreadyRequested(FString File)
{
	/*
	int32 i = 0;
	if (RequestedPages.Num() == 0)
	{
		return false;
	}
	for (i = 0; i < RequestedPages.Num(); i++)
	{
		if (RequestedPages[i] == File)
		{
			return true;
		}
	}
	*/
	return false;
}

bool UNMLContent::IsADependency(FString File)
{
	/*
	int32 i = 0;
	if (Dependencies.Num() == 0)
	{
		return false;
	}
	for (i = 0; i < Dependencies.Num(); i++)
	{
		if (Dependencies[i] == File)
		{
			return true;
		}
	}
	*/
	return false;
}
