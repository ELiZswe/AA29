// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "StreamPlaylistEditor.generated.h"

//class UStreamInteraction;
class UStreamInterface;
class UStreamPlaylistManager;
class UStreamPlaylist;
class UDirectoryTreeList;
class UGUISectionBackground;
class UDirectoryTreeListBox;
class UGUIButton;
class UmoComboBox;

UCLASS()
class AA29_API UStreamPlaylistEditor : public UFloatingWindow
{
	GENERATED_BODY()
public:
	UStreamPlaylistEditor();

	//UPROPERTY(EditAnywhere)		UStreamInteraction*			Handler;				//var() editconst noexport StreamInteraction Handler;
	UPROPERTY(EditAnywhere)		UStreamInterface*			FileManager;			//var() editconst noexport StreamInterface FileManager;
	UPROPERTY(EditAnywhere)		UStreamPlaylistManager*		PlaylistManager;		//var() editconst noexport StreamPlaylistManager PlaylistManager;
	UPROPERTY(EditAnywhere)		UStreamPlaylist*			CurrentPlaylist;		//var() noexport StreamPlaylist CurrentPlaylist;
	UPROPERTY(EditAnywhere)		UDirectoryTreeList*			li_Directory;			//var() noexport DirectoryTreeList li_Directory;
	UPROPERTY(EditAnywhere)		UGUISectionBackground*		sb_Main;				//var() automated XInterface.GUISectionBackground sb_Main;
	UPROPERTY(EditAnywhere)		UDirectoryTreeListBox*		lb_Directory;			//var() automated DirectoryTreeListBox lb_Directory;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Add;					//var() automated XInterface.GUIButton b_Add;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Done;					//var() automated XInterface.GUIButton b_Done;
	UPROPERTY(EditAnywhere)		UmoComboBox*				co_DriveLetters;		//var() automated XInterface.moComboBox co_DriveLetters;
	UPROPERTY(EditAnywhere)		TArray<FString>				GeneralFileItems;		//var() localized TArray<FString> GeneralFileItems;
	UPROPERTY(EditAnywhere)		TArray<FString>				GeneralFolderItems;		//var() localized TArray<FString> GeneralFolderItems;
	UPROPERTY(EditAnywhere)		TArray<FString>				PlaylistItems;			//var() localized TArray<FString> PlaylistItems;
	UPROPERTY(EditAnywhere)		TArray<FString>				NonPlaylistItems;		//var() localized TArray<FString> NonPlaylistItems;
	UPROPERTY(EditAnywhere)		TArray<FString>				ImportItems;			//var() localized TArray<FString> ImportItems;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void DCOnChange(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool InternalOnKeyEvent(uint8& iKey, uint8& State, float Delta);
	bool InternalOnClick(UGUIComponent* Sender);
	void ContextClick(UGUIContextMenu* Menu, int32 Index);
	void UpdateCurrentPath(UGUIComponent* Sender);
	bool InternalOnDblClick(UGUIComponent* Sender);
	bool AddPreDraw(UCanvas* C);
	bool ClosePreDraw(UCanvas* C);
	bool InternalRightClick(UGUIComponent* Sender);
	bool ContextOpen(UGUIContextMenu* Menu);
	bool SetFileManager();
	bool SetPlaylistManager();
	bool SetHandler();
	void InitializeDirectoryList();
	bool AddToPlaylist(FString Filename);
	bool HandleDebugExec(FString Command, FString Param);
	bool FloatingPreDraw(UCanvas* C);

};
