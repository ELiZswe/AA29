// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/StreamPlayer/StreamPlayer.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"


UStreamPlayer::UStreamPlayer()
{
	UGUISlider* StreamVolume = NewObject<UGUISlider>(UGUISlider::StaticClass());
	StreamVolume->MaxValue = 1;
	StreamVolume->Hint = "Volume";
	StreamVolume->WinWidth = 0.544922;
	StreamVolume->WinHeight = 1;
	StreamVolume->TabOrder = 0;
	//StreamVolume->OnClick=StreamVolume.InternalOnClick;
	//StreamVolume->OnMousePressed=StreamVolume.InternalOnMousePressed;
	//StreamVolume->OnMouseRelease=StreamVolume.InternalOnMouseRelease;
	//StreamVolume->OnChange=StreamPlayer.InternalOnChange;
	//StreamVolume->OnKeyEvent=StreamVolume.InternalOnKeyEvent;
	//StreamVolume->OnCapturedMouseMove=StreamVolume.InternalCapturedMouseMove;
	UGUIScrollTextBox* SongInfoBox = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	SongInfoBox->bNoTeletype = true;
	//SongInfoBox->OnCreateComponent=SongInfoBox.InternalOnCreateComponent;
	SongInfoBox->WinWidth = 0.2;
	SongInfoBox->WinHeight = 0.2;
	SongInfoBox->bTabStop = false;
	SongInfoBox->bAcceptsInput = false;
	SongInfoBox->bNeverFocus = true;
	UGUIGFXButton* PrevTrackButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	PrevTrackButton->Position = EIconPosition::ICP_Scaled;
	PrevTrackButton->StyleName = "TextLabel";
	PrevTrackButton->Hint = "Previous";
	PrevTrackButton->WinLeft = 0.542109;
	PrevTrackButton->WinWidth = 0.04;
	PrevTrackButton->TabOrder = 1;
	PrevTrackButton->bTabStop = true;
	//PrevTrackButton->OnClick=StreamPlayer.InternalOnClick;
	//PrevTrackButton->OnKeyEvent=PrevTrackButton.InternalOnKeyEvent;
	UGUIGFXButton* StopButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	StopButton->Position = EIconPosition::ICP_Scaled;
	StopButton->StyleName = "TextLabel";
	StopButton->Hint = "Stop";
	StopButton->WinLeft = 0.605859;
	StopButton->WinWidth = 0.04;
	StopButton->TabOrder = 2;
	StopButton->bTabStop = true;
	//StopButton->OnClick=StreamPlayer.InternalOnClick;
	//StopButton->OnKeyEvent=StopButton.InternalOnKeyEvent;
	UGUIGFXButton* NextTrackButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	NextTrackButton->Position = EIconPosition::ICP_Scaled;
	NextTrackButton->StyleName = "TextLabel";
	NextTrackButton->Hint = "Next";
	NextTrackButton->WinLeft = 0.66086;
	NextTrackButton->WinWidth = 0.04;
	NextTrackButton->TabOrder = 3;
	NextTrackButton->bTabStop = true;
	//NextTrackButton->OnClick=StreamPlayer.InternalOnClick;
	//NextTrackButton->OnKeyEvent=NextTrackButton.InternalOnKeyEvent;
	UGUIGFXButton* PlayButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	PlayButton->Position = EIconPosition::ICP_Scaled;
	PlayButton->StyleName = "TextLabel";
	PlayButton->WinLeft = 0.71711;
	PlayButton->WinWidth = 0.04;
	PlayButton->TabOrder = 4;
	PlayButton->bTabStop = true;
	//PlayButton->OnClick=StreamPlayer.InternalOnClick;
	//PlayButton->OnKeyEvent=PlayButton.InternalOnKeyEvent;
	UGUICheckBoxButton* RepeatCheck = NewObject<UGUICheckBoxButton>(UGUICheckBoxButton::StaticClass());
	RepeatCheck->bAllOverlay = true;
	RepeatCheck->Hint = "Repeat";
	RepeatCheck->WinTop = 0.666667;
	RepeatCheck->WinLeft = 0.76;
	RepeatCheck->WinWidth = 0.04;
	RepeatCheck->TabOrder = 0;
	//RepeatCheck->OnChange=StreamPlayer.InternalOnChange;
	//RepeatCheck->OnKeyEvent=RepeatCheck.InternalOnKeyEvent;
	UGUICheckBoxButton* RepeatAllCheck = NewObject<UGUICheckBoxButton>(UGUICheckBoxButton::StaticClass());
	RepeatAllCheck->bAllOverlay = true;
	RepeatAllCheck->Hint = "Repeat All";
	RepeatAllCheck->WinTop = 0.666667;
	RepeatAllCheck->WinLeft = 0.8;
	RepeatAllCheck->WinWidth = 0.04;
	RepeatAllCheck->TabOrder = 1;
	//RepeatAllCheck->OnChange=StreamPlayer.InternalOnChange;
	//RepeatAllCheck->OnKeyEvent=RepeatAllCheck.InternalOnKeyEvent;
	UGUICheckBoxButton* ShuffleCheck = NewObject<UGUICheckBoxButton>(UGUICheckBoxButton::StaticClass());
	ShuffleCheck->bAllOverlay = true;
	ShuffleCheck->Hint = "Shuffle";
	ShuffleCheck->WinTop = 0.666667;
	ShuffleCheck->WinLeft = 0.84;
	ShuffleCheck->WinWidth = 0.04;
	ShuffleCheck->TabOrder = 2;
	//ShuffleCheck->OnChange=StreamPlayer.InternalOnChange;
	//ShuffleCheck->OnKeyEvent=ShuffleCheck.InternalOnKeyEvent;
	UGUICheckBoxButton* ShuffleAllCheck = NewObject<UGUICheckBoxButton>(UGUICheckBoxButton::StaticClass());
	ShuffleAllCheck->bAllOverlay = true;
	ShuffleAllCheck->Hint = "Shuffle All";
	ShuffleAllCheck->WinTop = 0.666667;
	ShuffleAllCheck->WinLeft = 0.88;
	ShuffleAllCheck->WinWidth = 0.04;
	ShuffleAllCheck->TabOrder = 3;
	//ShuffleAllCheck->OnChange=StreamPlayer.InternalOnChange;
	//ShuffleAllCheck->OnKeyEvent=ShuffleAllCheck.InternalOnKeyEvent;
	UGUIGFXButton* ShowPlaylistButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	ShowPlaylistButton->StyleName = "RoundScaledButton";
	ShowPlaylistButton->WinLeft = 0.82547;
	ShowPlaylistButton->WinWidth = 0.052422;
	ShowPlaylistButton->WinHeight = 0.925;
	ShowPlaylistButton->TabOrder = 5;
	ShowPlaylistButton->bTabStop = true;
	//ShowPlaylistButton->OnClick=StreamPlayer.InternalOnClick;
	//ShowPlaylistButton->OnKeyEvent=ShowPlaylistButton.InternalOnKeyEvent;
	//ShowPlaylistButton->OnDragOver=StreamPlayer.ManageDragOver;
	UGUIGFXButton* ManagePlaylistsButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	ManagePlaylistsButton->StyleName = "RoundScaledButton";
	ManagePlaylistsButton->Hint = "Manage Playlists";
	ManagePlaylistsButton->WinLeft = 0.88336;
	ManagePlaylistsButton->WinWidth = 0.052422;
	ManagePlaylistsButton->WinHeight = 0.925;
	ManagePlaylistsButton->TabOrder = 6;
	ManagePlaylistsButton->bTabStop = true;
	//ManagePlaylistsButton->OnClick=StreamPlayer.InternalOnClick;
	//ManagePlaylistsButton->OnKeyEvent=ManagePlaylistsButton.InternalOnKeyEvent;
	//ManagePlaylistsButton->OnDragOver=StreamPlayer.ManageDragOver;
	UGUIListBox* PlaylistListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	PlaylistListBox->bVisibleWhenEmpty = true;
	//PlaylistListBox->OnCreateComponent=PlaylistListBox.InternalOnCreateComponent;
	PlaylistListBox->Hint = "Current Playlist";
	PlaylistListBox->WinTop = 0.3;
	PlaylistListBox->WinLeft = 0.010859;
	PlaylistListBox->WinWidth = 0.977425;
	PlaylistListBox->WinHeight = 0.588941;
	PlaylistListBox->RenderWeight = 0.503;
	PlaylistListBox->TabOrder = 6;
	PlaylistListBox->bVisible = false;
	UGUIListBox* SelectPlaylistListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	SelectPlaylistListBox->bVisibleWhenEmpty = true;
	//SelectPlaylistListBox->OnCreateComponent=SelectPlaylistListBox.InternalOnCreateComponent;
	SelectPlaylistListBox->Hint = "Select A Playlist";
	SelectPlaylistListBox->WinTop = 0.235;
	SelectPlaylistListBox->WinLeft = 0.010859;
	SelectPlaylistListBox->WinWidth = 0.977425;
	SelectPlaylistListBox->WinHeight = 0.7175;
	SelectPlaylistListBox->TabOrder = 1;
	SelectPlaylistListBox->bBoundToParent = true;
	SelectPlaylistListBox->bVisible = false;
	UAltSectionBackground* sbManagement = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	sbManagement->bFillClient = true;
	sbManagement->Caption = "Play List Manager";
	sbManagement->LeftPadding = 0;
	sbManagement->RightPadding = 0;
	sbManagement->WinTop = 0.2;
	sbManagement->WinLeft = 0.2;
	sbManagement->WinWidth = 0.2;
	sbManagement->WinHeight = 0.2;
	sbManagement->bVisible = false;
	//sbManagement->OnPreDraw=sbManagement.InternalPreDraw;
	UAltSectionBackground* sbPlayList = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	sbPlayList->bFillClient = true;
	sbPlayList->Caption = "Current Playlist";
	sbPlayList->LeftPadding = 0;
	sbPlayList->RightPadding = 0;
	sbPlayList->WinTop = 0.2;
	sbPlayList->WinLeft = 0.2;
	sbPlayList->WinWidth = 0.2;
	sbPlayList->WinHeight = 0.2;
	sbPlayList->bVisible = false;
	//sbPlayList->OnPreDraw=sbPlayList.InternalPreDraw;
	UGUIButton* bBotA = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bBotA->Caption = "Add";
	bBotA->StyleName = "FooterButton";
	bBotA->Tag = 1;
	bBotA->bVisible = false;
	//bBotA->OnClick=StreamPlayer.InternalOnClick;
	//bBotA->OnKeyEvent=bBotA.InternalOnKeyEvent;
	UGUIButton* bBotB = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bBotB->Caption = "Remove";
	bBotB->StyleName = "FooterButton";
	bBotB->Tag = 1;
	bBotB->bVisible = false;
	//bBotB->OnClick=StreamPlayer.InternalOnClick;
	//bBotB->OnKeyEvent=bBotB.InternalOnKeyEvent;
	UGUIButton* bBotC = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bBotC->Caption = "Clear";
	bBotC->StyleName = "FooterButton";
	bBotC->Tag = 1;
	bBotC->bVisible = false;
	//bBotC->OnClick=StreamPlayer.InternalOnClick;
	//bBotC->OnKeyEvent=bBotC.InternalOnKeyEvent;
	UGUIContextMenu* SongRCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	SongRCMenu->ContextItems = { "Play Selected","Open Playlist Editor","-","Remove From Playlist","Clear Playlist" };
	//SongRCMenu->OnSelect=StreamPlayer.SongMenuClick;
	UGUIContextMenu* PlaylistRCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	PlaylistRCMenu->ContextItems = { "Activate Playlist","Rename Playlist","Create new Playlist","-","Delete Playlist","Clear Playlist" };
	//PlaylistRCMenu->OnSelect=StreamPlayer.PlaylistMenuClick;
	UGUIContextMenu* PlayerRCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	PlayerRCMenu->ContextItems = { "Change Settings" };
	//PlayerRCMenu->OnSelect=StreamPlayer.PlayerMenuClick;
	UGUILabel* SongTime = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SongTime->Caption = "0:00";
	SongTime->TextAlign = ETextAlign::TXTA_Center;
	SongTime->VertAlign = ETextAlign::TXTA_Center;
	SongTime->FontScale = EFontScale::FNS_Large;
	SongTime->StyleName = "TextLabel";
	SongTime->WinTop = -0.2;
	SongTime->WinLeft = 0.2;
	SongTime->WinWidth = 0.241172;
	SongTime->WinHeight = 0.550191;
	UGUIImage* Img1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Img1->ImageStyle = EImgStyle::ISTY_Stretched;
	Img1->WinTop = 0.2;
	Img1->WinLeft = 0.2;
	Img1->WinWidth = 0.2;
	Img1->WinHeight = 0.2;
	UGUIImage* Img2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Img2->ImageStyle = EImgStyle::ISTY_Scaled;
	Img2->WinTop = 0.2;
	Img2->WinLeft = 0.2;
	Img2->WinWidth = 0.2;
	Img2->WinHeight = 0.2;
	Bk1 = Img1;
	bk2 = Img2;
	sb_PlayList = sbPlayList;
	sb_Management = sbManagement;
	lb_SongInfo = SongInfoBox;
	l_Time = SongTime;
	lb_Playlist = PlaylistListBox;
	lb_AllPlaylists = SelectPlaylistListBox;
	b_BotA = bBotA;
	b_BotB = bBotB;
	b_BotC = bBotC;
	sl_Volume = StreamVolume;
	b_Play = PlayButton;
	b_Stop = StopButton;
	b_NextTrack = NextTrackButton;
	b_PrevTrack = PrevTrackButton;
	b_Playlist = ShowPlaylistButton;
	b_Management = ManagePlaylistsButton;
	ch_Shuffle = ShuffleCheck;
	ch_ShuffleAll = ShuffleAllCheck;
	ch_Repeat = RepeatCheck;
	ch_RepeatAll = RepeatAllCheck;
	ID3TagEditorMenu = "AGP_Interface.ID3TagEditor";
	PlaylistEditorMenu = "AGP_Interface.StreamPlaylistEditor";
	ExpandedHeight = 0.5;
	ConstrictedHeight = 0.32;
	CollapsePlaylistHint = "Hide Current Playlist";
	ExpandPlaylistHint = "Show Current Playlist";
	PlayHint = "Play";
	PauseHint = "Pause";
	CollapseManagementHint = "Hide Playlist Options";
	ExpandManagementHint = "Show Playlist Options";
	RenameCaption = "Rename Playlist";
	NewCaption = "Create New Playlist";
	PlaylistNameCaption = "Name: ";
	PLAdd = "Add";
	PLRemove = "Remove";
	PLClear = "Clear";
	MGNew = "New";
	MGRemove = "Remove";
	MGRename = "Rename";
	cm_Playlist = SongRCMenu;
	cm_AllLists = PlaylistRCMenu;
	WindowName = "Music Player";
	MinPageWidth = 0.75;
	MinPageHeight = 0.32;
	MaxPageWidth = 0.9;
	bResizeHeightAllowed = false;
	bPersistent = true;
	bAllowedAsLast = true;
	WinHeight = 0.32;
	ContextMenu = PlayerRCMenu;
}

void UStreamPlayer::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	li_Playlist = lb_Playlist.List;
	li_Playlist.TextAlign = 0;
	li_Playlist.__OnDblClick__Delegate = PlaylistDblClick;
	li_Playlist.__OnChange__Delegate = InternalOnChange;
	li_Playlist.bMultiSelect = true;
	li_Playlist.bDropSource = true;
	li_Playlist.bDropTarget = true;
	li_Playlist.__OnDragDrop__Delegate = PlaylistReceiveDrop;
	li_Playlist.__OnEndDrag__Delegate = PlaylistDragEnded;
	li_Playlist.ContextMenu = cm_Playlist;
	li_AllLists = lb_AllPlaylists.List;
	li_AllLists.TextAlign = 0;
	li_AllLists.__OnDblClick__Delegate = PlaylistDblClick;
	li_AllLists.__OnChange__Delegate = InternalOnChange;
	li_AllLists.bMultiSelect = false;
	li_AllLists.bDropTarget = true;
	li_AllLists.bInitializeList = false;
	li_AllLists.ContextMenu = cm_AllLists;
	li_AllLists.__OnDragDrop__Delegate = AllListsReceiveDrop;
	sl_Volume.__OnPreDrawCaption__Delegate = SliderPreDrawCaption;
	sb_PlayList.ManageComponent(lb_Playlist);
	sb_Management.ManageComponent(lb_AllPlaylists);
	*/
}

void UStreamPlayer::ResolutionChanged(int32 ResX, int32 ResY)
{
	/*
	if (WindowMode == 0)
	{
		Constrict();
	}
	Super::ResolutionChanged(ResX, ResY);
	*/
}

void UStreamPlayer::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	Constrict();
	if (!SetPlaylistManager())
	{
		Warn("Error setting PlaylistManager!");
	}
	sl_Volume.SetValue(float(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.AudioDevice MusicVolume")));
	RefreshPlaylistSelections();
	RefreshCurrentPlaylist();
	RefreshPlaybackOptions();
	*/
}

void UStreamPlayer::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	int32 i = 0;
	i = Controller.FindMenuIndexByName(PlaylistEditorMenu);
	if (Controller.bCurMenuInitialized && (i != -1))
	{
		Controller.RemoveMenuAt(i, true);
	}
	Super::Closed(Sender, bCancelled);
	PlaylistManager.Save();
	HideAll();
	*/
}

void UStreamPlayer::SaveCurrentPosition()
{
	/*
	if (WindowMode != 0)
	{
		ExpandedHeight = WinHeight;
	}
	DefaultLeft = WinLeft;
	DefaultTop = WinTop;
	DefaultWidth = WinWidth;
	if (Controller.ResX <= 640)
	{
		DefaultHeight = 0.32;
	}
	else
	{
		DefaultHeight = 0.27;
	}
	SaveConfig();
	*/
}

bool UStreamPlayer::SetHandler()
{
	/*
	int32 i = 0;
	if ((Controller == None) || (Controller.ViewportOwner == None))
	{
		return false;
	}
	for (i = 0; i < Controller.ViewportOwner.LocalInteractions.Length; i++)
	{
		if (StreamInteraction(Controller.ViewportOwner.LocalInteractions[i]) != None)
		{
			Handler = StreamInteraction(Controller.ViewportOwner.LocalInteractions[i]);
			Handler.__OnStreamChanged__Delegate = HandleStreamChange;
			Handler.__OnStreamingStopped__Delegate = HandleStreamStop;
			Handler.__OnAdjustVolume__Delegate = HandleAdjustVolume;
			return true;
		}
	}
	Log("StreamPlayer.SetHandler() - no StreamInteractions found!", 'MusicPlayer');
	*/
	return false;
}

bool UStreamPlayer::SetPlaylistManager()
{
	/*
	if (PlaylistManager != None)
	{
		if ((Handler == None) && (!SetHandler()))
		{
			return false;
		}
		return true;
	}
	if ((Handler == None) && (!SetHandler()))
	{
		return false;
	}
	PlaylistManager = Handler.PlaylistManager;
	PlaylistManager.__ChangedActivePlaylist__Delegate = ActivePlaylistChanged;
	return (PlaylistManager != None);
	*/
	return 0;     //FAKE   /ELiZ
}

void UStreamPlayer::RefreshPlaybackOptions()
{
	/*
	sl_Volume.SetValue(Handler.GetStreamVolume());
	ch_Shuffle.bChecked = PlaylistManager.GetShuffle();
	ch_ShuffleAll.bChecked = PlaylistManager.GetShuffleAll();
	ch_Repeat.bChecked = PlaylistManager.GetRepeat();
	ch_RepeatAll.bChecked = PlaylistManager.GetRepeatAll();
	*/
}

void UStreamPlayer::RefreshPlaylistSelections()
{
	/*
	local StreamPlaylist List;
	int32 i = 0;
	FString str = "";
	if (PlaylistManager == None)
	{
		return;
	}
	str = li_AllLists.Get();
	li_AllLists.Clear();
	for (i = 0; i < PlaylistManager.GetPlaylistCount(); i++)
	{
		List = PlaylistManager.GetPlaylistAt(i);
		li_AllLists.Add(List.GetTitle(), List);
	}
	i = li_AllLists.FindIndex(str);
	if ((i == -1) && (CurrentPlaylist != None))
	{
		i = PlaylistManager.FindPlaylistIndex(CurrentPlaylist);
	}
	li_AllLists.SilentSetIndex(i);
	*/
}

void UStreamPlayer::ActivePlaylistChanged(UStreamPlaylist* NewList)
{
	/*
	RefreshCurrentPlaylist();
	if (WindowMode == 2)
	{
		ShowPlayList();
	}
	*/
}

void UStreamPlayer::RefreshCurrentPlaylist()
{
	/*
	if (CurrentPlaylist != None)
	{
		CurrentPlaylist.__OnPlaylistChanged__Delegate = None;
	}
	CurrentPlaylist = PlaylistManager.GetCurrentPlaylist();
	if (CurrentPlaylist == None)
	{
		Warn("Invalid playlist selected!");
		return;
	}
	LoadCurrentPlaylist();
	li_Playlist.SetIndex(li_Playlist.FindIndex("", , , CurrentPlaylist.GetCurrentStream()));
	li_AllLists.SilentSetIndex(li_AllLists.FindIndex("", , , CurrentPlaylist));
	*/
}

void UStreamPlayer::LoadCurrentPlaylist()
{
	/*
	int32 i = 0;
	local TArray<Stream> Songs;
	li_Playlist.Clear();
	if (CurrentPlaylist == None)
	{
		return;
	}
	CurrentPlaylist.GetSongs(Songs);
	for (i = 0; i < Songs.Length; i++)
	{
		li_Playlist.Add(Songs[i].GetSongTitle(), Songs[i], Songs[i].GetPath());
	}
	CurrentPlaylist.__OnPlaylistChanged__Delegate = HandlePlaylistChange;
	*/
}

void UStreamPlayer::HandlePlaylistChange()
{
	//LoadCurrentPlaylist();
	//PlaylistManager.Save();
}

void UStreamPlayer::HandleStreamChange(FString NewStreamFileName)
{
	/*
	local Stream S;
	int32 i = 0;
	i = CurrentPlaylist.FindIndexByName(NewStreamFileName);
	S = CurrentPlaylist.GetStreamAt(i);
	ResetSongCounter();
	if (S != None)
	{
		CurrentPlaylist.SetCurrent(i);
	}
	else
	{
		li_Playlist.SetIndex(-1);
		S = Handler.FileManager.CreateStream(NewStreamFileName);
	}
	ReadStream(S);
	PlaylistManager.Save();
	*/
}

void UStreamPlayer::HandleStreamStop()
{
	/*
	UpdateSongTimeDisplay();
	UpdatePlayButton();
	li_Playlist.SetIndex(-1);
	DisableComponent(b_Stop);
	PlaylistManager.Save();
	*/
}

void UStreamPlayer::HandleAdjustVolume(float NewVolume)
{
	//sl_Volume.SetValue(NewVolume);
}

bool UStreamPlayer::InternalOnClick(UGUIComponent* C)
{
	/*
	local Stream obj;
	switch (C)
	{
	case b_Play:
		if ((!li_Playlist.IsValid()) && (!Handler.IsPlaying()))
		{
			li_Playlist.SilentSetIndex(0);
			Play();
		}
		obj = Stream(li_Playlist.GetObject());
		if ((obj == None) || (obj != Handler.CurrentStreamAttachment))
		{
			Play();
			return true;
		}
		PauseCurrent();
		return true;
	case b_Stop:
		StopCurrent();
		return true;
	case b_NextTrack:
		NextTrack();
		return true;
	case b_PrevTrack:
		PrevTrack();
		return true;
	case b_Playlist:
		TogglePlaylist();
		return true;
	case b_Management:
		ToggleManagement();
		return true;
	case b_BotA:
		if (WindowMode == 1)
		{
			return Controller.OpenMenu(PlaylistEditorMenu, CurrentPlaylist.GetTitle());
			break;
		}
		if (WindowMode == 2)
		{
			NewPlaylist();
		}
	}
	return true;
	case b_BotB:
		if (WindowMode == 1)
		{
			CurrentListRemove();
		}
		else
		{
			if (WindowMode == 2)
			{
				RemovePlaylist();
			}
		}
		return true;
	case b_BotC:
		if (WindowMode == 1)
		{
			CurrentListClear();
		}
		else
		{
			if (WindowMode == 2)
			{
				RenamePlaylist();
			}
		}
	default:
		return true;
	}
	*/
	return false;    //FAKE    /ELiZ
}

int32 UStreamPlayer::GetPlaylistManagerIndex(int32 ListIndex)
{
	/*
	if ((PlaylistManager == None) || (li_AllLists == None))
	{
		return -1;
	}
	if (!li_AllLists.IsValidIndex(ListIndex))
	{
		ListIndex = li_AllLists.Index;
	}
	return PlaylistManager.FindNameIndex(li_AllLists.getItemAtIndex(ListIndex));
	*/
	return 0;    //FAKE    /ELiZ
}

void UStreamPlayer::InternalOnChange(UGUIComponent* C)
{
	/*
	switch (C)
	{
	case sl_Volume:
		Handler.SetMusicVolume(sl_Volume.Value);
		break;
	case ch_Shuffle:
		PlaylistManager.SetShuffle(ch_Shuffle.bChecked);
		ch_ShuffleAll.bChecked = PlaylistManager.GetShuffleAll();
		break;
	case ch_ShuffleAll:
		PlaylistManager.SetShuffleAll(ch_ShuffleAll.bChecked);
		ch_Shuffle.bChecked = PlaylistManager.GetShuffle();
		break;
	case ch_Repeat:
		PlaylistManager.SetRepeat(ch_Repeat.bChecked);
		ch_RepeatAll.bChecked = PlaylistManager.GetRepeatAll();
		break;
	case ch_RepeatAll:
		PlaylistManager.SetRepeatAll(ch_RepeatAll.bChecked);
		ch_Repeat.bChecked = PlaylistManager.GetRepeat();
		break;
	case li_Playlist:
		if ((!Handler.IsPlaying()) && li_Playlist.IsValid())
		{
			ReadTagInfo(Stream(li_Playlist.GetObject()));
		}
		break;
	default:
	}
	*/
}

bool UStreamPlayer::SliderPreDrawCaption(float& X, float& Y, float& XL, float& YL, EeTextAlign& Justification)
{
	return true;
}

bool UStreamPlayer::AllListsReceiveDrop(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	int32 idx = 0;
	local TArray<GUIListElem> Elems;
	local TArray<FString> items;
	local Stream str;
	local StreamPlaylist List;
	if (Controller.DropSource == li_Playlist)
	{
		List = PlaylistManager.GetPlaylistAt(GetPlaylistManagerIndex(li_AllLists.DropIndex));
		if ((List == None) || (List == CurrentPlaylist))
		{
			return false;
		}
		List.InitializePlaylist(Handler.FileManager);
		Elems = li_Playlist.GetPendingElements(true);
		i = (Elems.Length - 1);
		if (i >= 0)
		{
			str = Stream(Elems[i].ExtraData);
			if (str != None)
			{
				List.AddStream(-1, str, true);
			}
			(i);
		}
		return true;
	}
	else
	{
		if (DirectoryTreeList(Controller.DropSource) != None)
		{
			items = DirectoryTreeList(Controller.DropSource).GetPendingItems();
			idx = GetPlaylistManagerIndex(li_AllLists.DropIndex);
			List = PlaylistManager.GetPlaylistAt(idx);
			if (List == None)
			{
				return false;
			}
			i = (items.Length - 1);
			if (i >= 0)
			{
				PlaylistManager.InsertInPlaylist(idx, -1, items[i], (i > 0));
				(i);
			}
			return true;
		}
	}
	*/
	return false;
}

bool UStreamPlayer::PlaylistReceiveDrop(UGUIComponent* Sender)
{
	/*
	local TArray<FString> items;
	int32 i = 0;
	int32 idx = 0;
	if (Sender == li_Playlist)
	{
		if ((Controller.DropSource != li_AllLists) && li_Playlist.InternalOnDragDrop(Sender))
		{
			return true;
		}
		if (DirectoryTreeList(Controller.DropSource) != None)
		{
			items = DirectoryTreeList(Controller.DropSource).GetPendingItems();
			idx = li_Playlist.DropIndex;
			if (!li_Playlist.IsValidIndex(idx))
			{
				idx = li_Playlist.Elements.Length;
			}
			i = (items.Length - 1);
			if (i >= 0)
			{
				PlaylistManager.InsertInPlaylist(PlaylistManager.GetCurrentIndex(), idx, items[i], (i > 0));
				(i);
			}
			li_Playlist.SetIndex(idx);
			return true;
		}
	}
	*/
	return false;
}

void UStreamPlayer::PlaylistDragEnded(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	int32 i = 0;
	local TArray<Stream> Streams;
	li_Playlist.InternalOnEndDrag(Accepting, bAccepted);
	if (bAccepted)
	{
		if (Accepting == li_Playlist)
		{
			Streams.Length = li_Playlist.Elements.Length;
			for (i = 0; i < li_Playlist.Elements.Length; i++)
			{
				Streams[i] = Stream(li_Playlist.GetObjectAtIndex(i));
			}
			CurrentPlaylist.InitializePlaylist(Handler.FileManager);
			CurrentPlaylist.SetSongs(Streams);
		}
	}
	*/
}

void UStreamPlayer::Play()
{
	//Handler.PlaySong(li_Playlist.GetExtra(), 0);
	//UpdatePlayButton();
}

void UStreamPlayer::StopCurrent()
{
	//Handler.StopSong();
	//UpdatePlayButton();
}

void UStreamPlayer::NextTrack()
{
	//Handler.NextSong();
	//UpdatePlayButton();
}

void UStreamPlayer::PrevTrack()
{
	//Handler.PrevSong();
}

void UStreamPlayer::PauseCurrent()
{
	/*
	if (!Handler.IsPlaying())
	{
		Play();
	}
	else
	{
		Handler.PauseSong();
		UpdatePlayButton();
	}
	*/
}

bool UStreamPlayer::PlaylistDblClick(UGUIComponent* C)
{
	/*
	int32 i = 0;
	if (C == li_Playlist)
	{
		Play();
		return true;
	}
	else
	{
		if (C == li_AllLists)
		{
			i = PlaylistManager.FindPlaylistIndex(StreamPlaylist(li_AllLists.GetObject()));
			PlaylistManager.ActivatePlaylist(i);
			return true;
		}
	}
	*/
	return false;
}

void UStreamPlayer::ReadTagInfo(UStream* StreamObj)
{
	/*
	FString TagText = "";
	local StreamTag sTag;
	sTag = StreamObj.GetTag();
	TagText = StreamObj.GetSongTitle();
	if (sTag != None)
	{
		if (TagText != "")
		{
			(TagText $ = "|");
		}
		(TagText $ = sTag.Artist.FieldValue);
		if (TagText != "")
		{
			(TagText $ = "|");
		}
		(TagText $ = sTag.Album.FieldValue);
	}
	lb_SongInfo.SetContent(TagText);
	*/
}

void UStreamPlayer::ReadStream(UStream* StreamObj)
{
	/*
	if (StreamObj == None)
	{
		Log("ReadStream() called with StreamObj == None", 'MusicPlayer');
		return;
	}
	ReadTagInfo(StreamObj);
	EnableComponent(b_Stop);
	li_Playlist.SilentSetIndex(li_Playlist.FindIndex("", , , StreamObj));
	Handler.SetStreamAttachment(StreamObj);
	*/
}

void UStreamPlayer::ReadStreamAt(int32 Index)
{
	/*
	local Stream StreamObj;
	StreamObj = Stream(lb_Playlist.List.GetObjectAtIndex(Index));
	if (StreamObj == None)
	{
		Log("ReadStreamInfo couldn't find stream object at index" @ string(Index), 'MusicPlayer');
		return;
	}
	ReadStream(StreamObj);
	*/
}

void UStreamPlayer::Timer()
{
	/*
	if (Handler != None)
	{
		UpdateSongTimeDisplay();
	}
	*/
}

void UStreamPlayer::ResetSongCounter(bool bNoRestart)
{
	/*
	SongSeconds = 0;
	if (bNoRestart)
	{
		KillTimer();
	}
	else
	{
		SetTimer(1, true);
	}
	Timer();
	*/
}

void UStreamPlayer::UpdateSongTimeDisplay()
{
	/*
	SongSeconds = int(Handler.GetStreamPosition());
	l_Time.Caption = Class'StreamBase'.FormatTimeDisplay(float(SongSeconds));
	*/
}

void UStreamPlayer::UpdatePlayButton()
{
	/*
	if (Handler == None)
	{
		return;
	}
	if (Handler.IsPlaying() && (!Handler.IsPaused()))
	{
		b_Play.Graphic = PauseImage;
		b_Play.SetHint(PauseHint);
	}
	else
	{
		b_Play.SetHint(PlayHint);
		b_Play.Graphic = PlayImage;
	}
	*/
}

void UStreamPlayer::PlayerMenuClick(UGUIContextMenu* Menu, int32 Index)
{
	/*
	if ((Index < 0) || (Index >= Menu.ContextItems.Length))
	{
		return;
	}
	if (Menu.ContextItems[Index] == "-")
	{
		return;
	}
	switch (Index)
	{
	case 0:
		Controller.OpenMenu(OptionsMenu);
		return;
	default:
	}
	*/
}

void UStreamPlayer::RemovePlaylist()
{
	/*
	PlaylistManager.RemovePlaylist(li_AllLists.Get());
	RefreshPlaylistSelections();
	*/
}

void UStreamPlayer::CurrentListClear()
{
	/*
	PlaylistManager.ClearCurrentPlaylist();
	LoadCurrentPlaylist();
	*/
}

void UStreamPlayer::PlaylistMenuClick(UGUIContextMenu* Menu, int32 Index)
{
	/*
	int32 i = 0;
	if ((Index < 0) || (Index >= Menu.ContextItems.Length))
	{
		return;
	}
	if (Menu.ContextItems[Index] == "-")
	{
		return;
	}
	switch (Index)
	{
	case 0:
		i = PlaylistManager.FindPlaylistIndex(StreamPlaylist(li_AllLists.GetObject()));
		PlaylistManager.ActivatePlaylist(i);
		break;
	case 1:
		RenamePlaylist();
		break;
	case 2:
		NewPlaylist();
		break;
	case 4:
		RemovePlaylist();
		break;
	case 5:
		CurrentListClear();
		break;
	default:
	}
	*/
}

void UStreamPlayer::CurrentListRemove()
{
	/*
	local TArray<GUIListElem> Paths;
	int32 i = 0;
	Paths = li_Playlist.GetPendingElements(true);
	for (i = 0; i < Paths.Length; i++)
	{
		PlaylistManager.RemoveFromCurrentPlaylist(Paths[i].ExtraStrData, (i < (Paths.Length - 1)));
	}
	*/
}

void UStreamPlayer::SongMenuClick(UGUIContextMenu* Menu, int32 Index)
{
	/*
	if ((Index < 0) || (Index >= Menu.ContextItems.Length))
	{
		return;
	}
	if (Menu.ContextItems[Index] == "-")
	{
		return;
	}
	switch (Index)
	{
	case 0:
		Play();
		break;
	case 1:
		Controller.OpenMenu(PlaylistEditorMenu);
		break;
	case 3:
		CurrentListRemove();
		break;
	case 4:
		CurrentListClear();
		break;
	default:
	}
	li_Playlist.ClearPendingElements();
	*/
}

void UStreamPlayer::NewPlaylist()
{
	/*
	if (Controller.OpenMenu(Controller.RequestDataMenu, NewCaption, PlaylistNameCaption))
	{
		Controller.ActivePage.__OnClose__Delegate = NewPlaylistClosed;
	}
	*/
}

void UStreamPlayer::RenamePlaylist()
{
	/*
	if (Controller.OpenMenu(Controller.RequestDataMenu, RenameCaption, PlaylistNameCaption))
	{
		Controller.ActivePage.SetDataString(li_AllLists.Get());
		Controller.ActivePage.__OnClose__Delegate = RenameClosed;
	}
	*/
}

void UStreamPlayer::NewPlaylistClosed(bool bCancelled)
{
	/*
	FString PlaylistName = "";
	if (!bCancelled)
	{
		PlaylistName = Controller.ActivePage.GetDataString();
		if (PlaylistManager.ActivatePlaylist(PlaylistManager.AddPlaylist(PlaylistName), true))
		{
			RefreshPlaylistSelections();
		}
	}
	*/
}

void UStreamPlayer::RenameClosed(bool bCancelled)
{
	/*
	FString PlaylistName = "";
	if (!bCancelled)
	{
		PlaylistName = Controller.ActivePage.GetDataString();
		if (PlaylistManager.RenamePlaylist(GetPlaylistManagerIndex(-1), PlaylistName))
		{
			RefreshPlaylistSelections();
		}
	}
	*/
}

void UStreamPlayer::SetVisibility(bool bIsVisible)
{
	/*
	int32 i = 0;
	if (!bIsVisible)
	{
		Super::SetVisibility(bIsVisible);
		return;
	}
	SetVisibility(bIsVisible);
	if (!PropagateVisibility)
	{
		return;
	}
	for (i = 0; i < Controls.Length; i++)
	{
		if (((Controls[i] == sb_PlayList) && (WindowMode != 1)) || ((Controls[i] == sb_Management) && (WindowMode != 2)))
		{
		}
		Controls[i].SetVisibility(true);
	}
	*/
}

void UStreamPlayer::Expand()
{
	/*
	bResizeHeightAllowed = true;
	if (ExpandedHeight < WinHeight)
	{
		ExpandedHeight = (WinHeight + 0.1);
	}
	WinHeight = RelativeHeight(ExpandedHeight);
	MinPageHeight = 0.4;
	CheckBounds();
	*/
}

void UStreamPlayer::Constrict()
{
	/*
	bResizeHeightAllowed = false;
	WindowMode = 0;
	if (Controller.ResX <= 640)
	{
		MinPageHeight = 0.32;
		WinHeight = 0.32;
	}
	else
	{
		MinPageHeight = 0.27;
		WinHeight = 0.27;
	}
	*/
}

void UStreamPlayer::HideAll()
{
	/*
	Constrict();
	sb_PlayList.SetVisibility(false);
	sb_Management.SetVisibility(false);
	b_BotA.SetVisibility(false);
	b_BotB.SetVisibility(false);
	b_BotC.SetVisibility(false);
	*/
}

void UStreamPlayer::TogglePlaylist()
{
	/*
	if (WindowMode != 1)
	{
		ShowPlayList();
	}
	else
	{
		HidePlayList();
	}
	*/
}

void UStreamPlayer::ShowPlayList()
{
	/*
	if (WindowMode == 0)
	{
		Expand();
	}
	sb_PlayList.Caption = PlaylistManager.GetCurrentTitle();
	b_BotA.SetVisibility(true);
	b_BotA.Caption = PLAdd;
	b_BotB.SetVisibility(true);
	b_BotB.Caption = PLRemove;
	b_BotC.SetVisibility(true);
	b_BotC.Caption = PLClear;
	sb_PlayList.SetVisibility(true);
	sb_Management.SetVisibility(false);
	WindowMode = 1;
	b_Playlist.Graphic = OpenFolder;
	*/
}

void UStreamPlayer::HidePlayList()
{
	/*
	Constrict();
	b_BotA.SetVisibility(false);
	b_BotB.SetVisibility(false);
	b_BotC.SetVisibility(false);
	sb_PlayList.SetVisibility(false);
	b_Playlist.Graphic = ClosedFolder;
	*/
}

void UStreamPlayer::ToggleManagement()
{
	/*
	if (WindowMode != 2)
	{
		ShowManagement();
	}
	else
	{
		HideManagement();
	}
	*/
}

void UStreamPlayer::ShowManagement()
{
	/*
	if (WindowMode == 0)
	{
		Expand();
	}
	b_BotA.SetVisibility(true);
	b_BotA.Caption = MGNew;
	b_BotB.SetVisibility(true);
	b_BotB.Caption = MGRemove;
	b_BotC.SetVisibility(true);
	b_BotC.Caption = MGRename;
	sb_PlayList.SetVisibility(false);
	sb_Management.SetVisibility(true);
	WindowMode = 2;
	b_Playlist.Graphic = ClosedFolder;
	*/
}

void UStreamPlayer::HideManagement()
{
	/*
	Constrict();
	b_BotA.SetVisibility(false);
	b_BotB.SetVisibility(false);
	b_BotC.SetVisibility(false);
	sb_Management.SetVisibility(false);
	*/
}

void UStreamPlayer::ManageDragOver(UGUIComponent* Sender)
{
	/*
	if (bAnimating)
	{
		return;
	}
	if ((Sender == b_Management) && (WindowMode != 2))
	{
		ShowManagement();
	}
	else
	{
		if ((Sender == b_Playlist) && (WindowMode != 1))
		{
			ShowPlayList();
		}
	}
	*/
}

bool UStreamPlayer::FloatingPreDraw(UCanvas* C)
{
	bool B = false;
	/*
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	float BK1L = 0;
	float BK1T = 0;
	float BK1W = 0;
	float BK1H = 0;
	float L = 0;
	float t = 0;
	float W = 0;
	float H = 0;
	float bl = 0;
	float bt = 0;
	float BW = 0;
	float bh = 0;
	float bs = 0;
	if (bInit)
	{
		Constrict();
	}
	B = Super::FloatingPreDraw(C);
	t = (t_WindowTitle.ActualTop() + t_WindowTitle.ActualHeight());
	L = ActualLeft();
	W = ActualWidth();
	l_Time.Style.TextSize(C, MenuState, "100:00", XL, YL, l_Time.FontScale);
	H = (YL * 3);
	X = ((L + W) - (float(C.SizeX) * 0.01));
	Y = (t + (float(C.SizeY) * 0.01));
	Bk1.WinTop = Bk1.RelativeTop(Y);
	Bk1.WinHeight = Bk1.RelativeHeight((3 * YL));
	Bk1.WinWidth = Bk1.RelativeWidth((XL + (XL * 0.32)));
	Bk1.WinLeft = Bk1.RelativeLeft((X - Bk1.ActualWidth()));
	BK1T = Bk1.ActualTop();
	BK1W = Bk1.ActualWidth();
	BK1H = Bk1.ActualHeight();
	BK1L = Bk1.ActualLeft();
	l_Time.SetPosition(BK1L, BK1T, BK1W, BK1H, true);
	X = (BK1L - (float(C.SizeX) * 0.01));
	lb_SongInfo.WinTop = lb_SongInfo.RelativeTop((Y - (float(C.SizeY) * 0.01)));
	lb_SongInfo.WinLeft = lb_SongInfo.RelativeLeft((L + (float(C.SizeX) * 0.02)));
	lb_SongInfo.WinWidth = lb_SongInfo.RelativeWidth((X - lb_SongInfo.ActualLeft()));
	bh = ActualHeight(ch_Shuffle.StandardHeight);
	BW = bh;
	bt = ((BK1T + BK1H) - bh);
	bs = (float(C.SizeX) * 0.01);
	bl = (X - BW);
	MoveButton(ch_ShuffleAll, bl, bt, BW, bh, bs);
	MoveButton(ch_Shuffle, bl, bt, BW, bh, bs);
	MoveButton(ch_RepeatAll, bl, bt, BW, bh, bs);
	MoveButton(ch_Repeat, bl, bt, BW, bh, bs);
	MoveButton(b_NextTrack, bl, bt, BW, bh, bs);
	MoveButton(b_Play, bl, bt, BW, bh, bs);
	MoveButton(b_Stop, bl, bt, BW, bh, bs);
	MoveButton(b_PrevTrack, bl, bt, BW, bh, bs);
	sl_Volume.WinLeft = sl_Volume.RelativeLeft(lb_SongInfo.ActualLeft());
	sl_Volume.WinTop = sl_Volume.RelativeTop(bt);
	sl_Volume.WinHeight = sl_Volume.RelativeHeight(bh);
	sl_Volume.WinWidth = sl_Volume.RelativeWidth((bl - sl_Volume.ActualLeft()));
	lb_SongInfo.WinHeight = lb_SongInfo.RelativeHeight(((sl_Volume.ActualTop() - (float(C.SizeY) * 0.01)) - lb_SongInfo.ActualTop()));
	t = ((sl_Volume.ActualTop() + sl_Volume.ActualHeight()) + (float(C.SizeY) * 0.01));
	L = sl_Volume.ActualLeft();
	b_Playlist.SetPosition(L, t, BW, bh, true);
	b_Management.SetPosition(((L + BW) + bs), t, BW, bh, true);
	L = ((L + (BW * 2)) + (bs * 2));
	bt = (t + (bh * 0.32));
	bk2.WinLeft = bk2.RelativeLeft(L);
	bk2.WinTop = bk2.RelativeTop(bt);
	bk2.WinHeight = bk2.RelativeHeight((bh * 0.5));
	bk2.WinWidth = bk2.RelativeWidth((((BK1L + BK1W) - BW) - bk2.ActualLeft()));
	L = ActualLeft();
	W = ActualWidth();
	t = (bt + (bh * 1.5));
	if (WindowMode == 1)
	{
		sb_PlayList.WinLeft = sb_PlayList.RelativeLeft(L);
		sb_PlayList.WinWidth = sb_PlayList.RelativeWidth(W);
		sb_PlayList.WinTop = sb_PlayList.RelativeTop(t);
		sb_PlayList.WinHeight = sb_PlayList.RelativeHeight(((ActualTop() + ActualHeight()) - t));
		t = ((t + sb_PlayList.ActualHeight()) - float(32));
		SetBottomButtons(C, sb_PlayList.ActualLeft(), t, sb_PlayList.ActualWidth(), 32);
	}
	if (WindowMode == 2)
	{
		sb_Management.WinLeft = sb_Management.RelativeLeft(L);
		sb_Management.WinWidth = sb_Management.RelativeWidth(W);
		sb_Management.WinTop = sb_Management.RelativeTop(t);
		sb_Management.WinHeight = sb_Management.RelativeHeight(((ActualTop() + ActualHeight()) - t));
		t = ((t + sb_Management.ActualHeight()) - float(32));
		SetBottomButtons(C, sb_Management.ActualLeft(), t, sb_Management.ActualWidth(), 32);
	}
	*/
	return B;
}

void UStreamPlayer::MoveButton(UGUIButton* B, float& L, float t, float W, float H, float S)
{
	/*
	B.SetPosition(L, t, W, H, true);
	(L -= (W + S));
	*/
}

void UStreamPlayer::SetBottomButtons(UCanvas* C, float Left, float Top, float Width, float Height)
{
	/*
	int32 i = 0;
	float Xsize = 0;
	float XL = 0;
	float YL = 0;
	float S = 0;
	local UGUIButton* B;
	S = (float(Controller.ResX) * 0.01);
	for (i = 0; i < Controls.Length; i++)
	{
		if (Controls[i].Tag > 0)
		{
			B = GUIButton(Controls[i]);
			B.Style.TextSize(C, B.MenuState, B.Caption, XL, YL, B.FontScale);
			Xsize += (XL + S);
			Controls[i].WinWidth = Controls[i].RelativeWidth((XL + S));
		}
	}
	Left = ((Left + (Width / 2)) - (Xsize / 2));
	for (i = 0; i < Controls.Length; i++)
	{
		if (Controls[i].Tag > 0)
		{
			Controls[i].WinTop = Controls[i].RelativeTop(Top);
			Controls[i].WinLeft = Controls[i].RelativeLeft(Left);
			Controls[i].WinHeight = Controls[i].RelativeHeight(Height);
			Left += Controls[i].ActualWidth();
		}
	}
	*/
}


void UStreamPlayer::ResizedBoth()
{
	/*
	ExpandedHeight = RelativeHeight();
	Super::ResizedBoth();
	*/
}

void UStreamPlayer::ResizedHeight()
{
	/*
	ExpandedHeight = RelativeHeight();
	Super::ResizedHeight();
	*/
}
