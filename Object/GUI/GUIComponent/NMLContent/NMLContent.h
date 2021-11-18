// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "NMLContent.generated.h"

class AHttpLink;
class UGUIContentBox;
class UGUIImage;
class UGUILabel;
class UGUIGridLayout;
class UGUILabelButton;
class UNMLImageButton;
class UAAGUILabel;

/**
 * 
 */
UCLASS()
class AA29_API UNMLContent : public UGUIComponent
{
	GENERATED_BODY()
public:
	UNMLContent();

	UPROPERTY()														AHttpLink* DependencyLink;						//var IpDrv.HttpLink DependencyLink;
	UPROPERTY()														TArray<FString> Dependencies;					//var array<String> Dependencies;
	UPROPERTY()														int32 PendingDependencies;						//var int PendingDependencies;
	UPROPERTY()														FString StoredServer;							//var string StoredServer;
	UPROPERTY()														int32 StoredPort;								//var int StoredPort;
	UPROPERTY()														FString DynamicContentPath;						//var string DynamicContentPath;
	UPROPERTY()														FString LocalNMLFile;							//var string LocalNMLFile;
	UPROPERTY()														FString DownloadedNMLChunk;						//var string DownloadedNMLChunk;
	UPROPERTY()														UGUIContentBox* TargetPanel;					//var GUIContentBox TargetPanel;
	UPROPERTY()														UGUIImage* NMLStatusIcon;						//var XInterface.GUIImage NMLStatusIcon;
	UPROPERTY()														UGUILabel* NMLStatusText;						//var XInterface.GUILabel NMLStatusText;
	UPROPERTY()														UMaterialInstance* NMLStatusIconTexture;		//var Texture NMLStatusIconTexture;
	UPROPERTY()														bool bShouldFindDependencies;					//var bool bShouldFindDependencies;
	UPROPERTY()														TArray<FString> LocalCopyDependencies;			//var array<String> LocalCopyDependencies;
	UPROPERTY()														TArray<FString> RequestedPages;					//var array<String> RequestedPages;
	UPROPERTY()														bool bVerboseLogging;							//var bool bVerboseLogging;



	void dTargetForLinks(UGUIComponent* Sender);
	void dInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3);
	void dPreParser(FString NMLString);
	//UMaterialInstance* GetImageFromDDS(FString FilePath, Level LevelForFactory);
	void ParseNMLFromFile(FString Filename, UGUIContentBox* Panel);
	void ParseNMLFromServer(FString Filename, FString Server, int32 Port, UGUIContentBox* Panel, UGUIImage* Icon, UGUILabel* Text);
	void ParseNMLFromString(FString NMLString, UGUIContentBox* Panel);
	void ReceivedNewNMLFile(FString Filename, FString NMLChunk);
	void SaveAndProcessNML(FString Filename, FString NMLChunk);
	void ParseNMLForDependencies(FString NMLChunk, TArray<FString>& DependencyArray);
	void GetDependenciesFromServer();
	bool SaveBinaryDependencyToDisk(FString Filename, TArray<uint8> ReceivedFile);
	void SaveTextDependencyToDisk(FString Filename, FString ReceivedFile);
	void ReceivedCachedNMLFile(FString Filename);
	void ReceivedCachedBinaryFile(FString Filename);
	void DependenciesLoaded();
	void UpdateNMLStatus(FString NewStatus);
	void CleanUpGarbage();
	void ParseNMLChunk(FString& WorkingString, FString& Token, FString& Content);
	void ParseNML(FString NMLText);
	void ParseTerminalTextLink(UGUILabelButton* Lbl, FString Properties);
	void ParseTerminalText(UAAGUILabel* Lbl, FString Properties);
	void ParseTerminalHR(UAAGUILabel* Lbl, FString Properties);
	void ParseTerminalImage(UNMLImageButton* img, FString Properties);
	void ParseTerminalPanelLink(UNMLImageButton* img, FString Properties);
	void ParseTerminalNews(UGUIGridLayout* Grid, FString Properties);
	void ParseNonTerminalGrid(UGUIGridLayout* Grid, FString Content);
	void ParseNonTerminalPanel(UGUIContentBox* SubPanel, FString Content);
	bool OnLinkButtonClick(UGUIComponent* Sender);
	bool OnImageButtonClick(UGUIComponent* Sender);
	bool OnInterPanelLink(UGUIComponent* Sender);
	//Level SearchForLevel();
	bool DoesFileExist(FString Filename);
	AActor* FindActor();
	uint8 GetCellAlign(FString Key);
	FString FixFilePath(FString FilePath);
	bool AlreadyRequested(FString File);
	bool IsADependency(FString File);

};
