// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "StreamPlayer.generated.h"

class UGUIImage;
class UGUISectionBackground;
class UGUIScrollTextBox;
class UGUILabel;
class UGUIListBox;
class UGUIButton;
class UGUISlider;
class UGUIGFXButton;
class UGUICheckBoxButton;
class UGUIList;
//class AStreamInteraction;
class UStreamPlaylistManager;
class UStreamPlaylist;
class UStream;
class UStreamPlaylist;

UCLASS()
class AA29_API UStreamPlayer : public UFloatingWindow
{
	GENERATED_BODY()
public:
	UStreamPlayer();

	UPROPERTY(EditAnywhere)		UGUIImage*				Bk1;						//var() automated XInterface.GUIImage Bk1;
	UPROPERTY(EditAnywhere)		UGUIImage*				bk2;						//var() automated XInterface.GUIImage bk2;
	UPROPERTY(EditAnywhere)		UGUISectionBackground* sb_PlayList;					//var() automated XInterface.GUISectionBackground sb_PlayList;
	UPROPERTY(EditAnywhere)		UGUISectionBackground* sb_Management;				//var() automated XInterface.GUISectionBackground sb_Management;
	UPROPERTY(EditAnywhere)		UGUIScrollTextBox*		lb_SongInfo;				//var() automated XInterface.GUIScrollTextBox lb_SongInfo;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Time;						//var() automated XInterface.GUILabel l_Time;
	UPROPERTY(EditAnywhere)		UGUIListBox*			lb_Playlist;				//var() automated XInterface.GUIListBox lb_Playlist;
	UPROPERTY(EditAnywhere)		UGUIListBox*			lb_AllPlaylists;			//var() automated XInterface.GUIListBox lb_AllPlaylists;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_BotA;						//var() automated XInterface.GUIButton b_BotA;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_BotB;						//var() automated XInterface.GUIButton b_BotB;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_BotC;						//var() automated XInterface.GUIButton b_BotC;
	UPROPERTY(EditAnywhere)		UGUISlider*				sl_Volume;					//var() automated XInterface.GUISlider sl_Volume;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_Play;						//var() automated XInterface.GUIGFXButton b_Play;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_Stop;						//var() automated XInterface.GUIGFXButton b_Stop;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_NextTrack;				//var() automated XInterface.GUIGFXButton b_NextTrack;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_PrevTrack;				//var() automated XInterface.GUIGFXButton b_PrevTrack;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_Playlist;					//var() automated XInterface.GUIGFXButton b_Playlist;
	UPROPERTY(EditAnywhere)		UGUIGFXButton*			b_Management;				//var() automated XInterface.GUIGFXButton b_Management;
	UPROPERTY(EditAnywhere)		UGUICheckBoxButton*		ch_Shuffle;					//var() automated XInterface.GUICheckBoxButton ch_Shuffle;
	UPROPERTY(EditAnywhere)		UGUICheckBoxButton*		ch_ShuffleAll;				//var() automated XInterface.GUICheckBoxButton ch_ShuffleAll;
	UPROPERTY(EditAnywhere)		UGUICheckBoxButton*		ch_Repeat;					//var() automated XInterface.GUICheckBoxButton ch_Repeat;
	UPROPERTY(EditAnywhere)		UGUICheckBoxButton*		ch_RepeatAll;				//var() automated XInterface.GUICheckBoxButton ch_RepeatAll;
	UPROPERTY(EditAnywhere)		UGUIList*				li_Playlist;				//var() editconst noexport XInterface.GUIList li_Playlist;
	UPROPERTY(EditAnywhere)		UGUIList*				li_AllLists;				//var() editconst noexport XInterface.GUIList li_AllLists;
//	UPROPERTY(EditAnywhere)		AStreamInteraction*		Handler;					//var() editconst noexport StreamInteraction Handler;
	UPROPERTY(EditAnywhere)		UStreamPlaylistManager* PlaylistManager;			//var() editconst noexport StreamPlaylistManager PlaylistManager;
	UPROPERTY(EditAnywhere)		UStreamPlaylist*		CurrentPlaylist;			//var() editconst noexport StreamPlaylist CurrentPlaylist;
	UPROPERTY(EditAnywhere)		FString					OptionsMenu;				//var() config FString OptionsMenu;
	UPROPERTY(EditAnywhere)		FString					ID3TagEditorMenu;			//var() config FString ID3TagEditorMenu;
	UPROPERTY(EditAnywhere)		FString					PlaylistEditorMenu;			//var() config FString PlaylistEditorMenu;
	UPROPERTY(EditAnywhere)		float					ExpandedHeight;				//var() config float ExpandedHeight;
	UPROPERTY(EditAnywhere)		float					ConstrictedHeight;			//var() float ConstrictedHeight;
	UPROPERTY(EditAnywhere)		int32					SongSeconds;				//var() editconst noexport int32 SongSeconds;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		PauseImage;					//var() Material PauseImage;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		PlayImage;					//var() Material PlayImage;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		OpenFolder;					//var() Material OpenFolder;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		ClosedFolder;				//var() Material ClosedFolder;
	UPROPERTY(EditAnywhere)		FString					CollapsePlaylistHint;		//var() localized FString CollapsePlaylistHint;
	UPROPERTY(EditAnywhere)		FString					ExpandPlaylistHint;			//var() localized FString ExpandPlaylistHint;
	UPROPERTY(EditAnywhere)		FString					PlayHint;					//var() localized FString PlayHint;
	UPROPERTY(EditAnywhere)		FString					PauseHint;					//var() localized FString PauseHint;
	UPROPERTY(EditAnywhere)		FString					CollapseManagementHint;		//var() localized FString CollapseManagementHint;
	UPROPERTY(EditAnywhere)		FString					ExpandManagementHint;		//var() localized FString ExpandManagementHint;
	UPROPERTY(EditAnywhere)		FString					RenameCaption;				//var() localized FString RenameCaption;
	UPROPERTY(EditAnywhere)		FString					NewCaption;					//var() localized FString NewCaption;
	UPROPERTY(EditAnywhere)		FString					PlaylistNameCaption;		//var() localized FString PlaylistNameCaption;
	UPROPERTY(EditAnywhere)		FString					PLAdd;						//var() localized FString PLAdd;
	UPROPERTY(EditAnywhere)		FString					PLRemove;					//var() localized FString PLRemove;
	UPROPERTY(EditAnywhere)		FString					PLClear;					//var() localized FString PLClear;
	UPROPERTY(EditAnywhere)		FString					MGNew;						//var() localized FString MGNew;
	UPROPERTY(EditAnywhere)		FString					MGRemove;					//var() localized FString MGRemove;
	UPROPERTY(EditAnywhere)		FString					MGRename;					//var() localized FString MGRename;
	UPROPERTY(EditAnywhere)		int32					DebugIndex;					//var() int32 DebugIndex;
	UPROPERTY(EditAnywhere)		bool					bExpand;					//var() bool bExpand;
	UPROPERTY(EditAnywhere)		bool					bConstrict;					//var() bool bConstrict;
	UPROPERTY(EditAnywhere)		UGUIContextMenu*		cm_Playlist;				//var() editconst noexport XInterface.GUIContextMenu cm_Playlist;
	UPROPERTY(EditAnywhere)		UGUIContextMenu*		cm_AllLists;				//var() editconst noexport XInterface.GUIContextMenu cm_AllLists;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ResolutionChanged(int32 ResX, int32 ResY);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void SaveCurrentPosition();
	bool SetHandler();
	bool SetPlaylistManager();
	void RefreshPlaybackOptions();
	void RefreshPlaylistSelections();
	void ActivePlaylistChanged(UStreamPlaylist* NewList);
	void RefreshCurrentPlaylist();
	void LoadCurrentPlaylist();
	void HandlePlaylistChange();
	void HandleStreamChange(FString NewStreamFileName);
	void HandleStreamStop();
	void HandleAdjustVolume(float NewVolume);
	bool InternalOnClick(UGUIComponent* C);
	int32 GetPlaylistManagerIndex(int32 ListIndex);
	void InternalOnChange(UGUIComponent* C);
	bool SliderPreDrawCaption(float& X, float& Y, float& XL, float& YL, EeTextAlign& Justification);
	bool AllListsReceiveDrop(UGUIComponent* Sender);
	bool PlaylistReceiveDrop(UGUIComponent* Sender);
	void PlaylistDragEnded(UGUIComponent* Accepting, bool bAccepted);
	void Play();
	void StopCurrent();
	void NextTrack();
	void PrevTrack();
	void PauseCurrent();
	bool PlaylistDblClick(UGUIComponent* C);
	void ReadTagInfo(UStream* StreamObj);
	void ReadStream(UStream* StreamObj);
	void ReadStreamAt(int32 Index);
	void Timer();
	void ResetSongCounter(bool bNoRestart);
	void UpdateSongTimeDisplay();
	void UpdatePlayButton();
	void PlayerMenuClick(UGUIContextMenu* Menu, int32 Index);
	void RemovePlaylist();
	void CurrentListClear();
	void PlaylistMenuClick(UGUIContextMenu* Menu, int32 Index);
	void CurrentListRemove();
	void SongMenuClick(UGUIContextMenu* Menu, int32 Index);
	void NewPlaylist();
	void RenamePlaylist();
	void NewPlaylistClosed(bool bCancelled);
	void RenameClosed(bool bCancelled);
	void SetVisibility(bool bIsVisible);
	void Expand();
	void Constrict();
	void HideAll();
	void TogglePlaylist();
	void ShowPlayList();
	void HidePlayList();
	void ToggleManagement();
	void ShowManagement();
	void HideManagement();
	void ManageDragOver(UGUIComponent* Sender);
	bool FloatingPreDraw(UCanvas* C);
	void MoveButton(UGUIButton* B, float& L, float t, float W, float H, float S);
	void SetBottomButtons(UCanvas* C, float Left, float Top, float Width, float Height);
	void ResizedBoth();
	void ResizedHeight();
};
