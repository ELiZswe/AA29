// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/StreamPlaylistEditor/StreamPlaylistEditor.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/DirectoryTreeListBox/DirectoryTreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"

UStreamPlaylistEditor::UStreamPlaylistEditor()
{
	UAltSectionBackground* MainPanel = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	MainPanel->WinTop = 0.15;
	MainPanel->WinHeight = 0.7;
	MainPanel->RenderWeight = 0.2;
	//MainPanel->OnPreDraw=MainPanel.InternalPreDraw;
	UDirectoryTreeListBox* UserDirectory = NewObject<UDirectoryTreeListBox>(UDirectoryTreeListBox::StaticClass());
	UserDirectory->bVisibleWhenEmpty = true;
	//UserDirectory->OnCreateComponent=UserDirectory.InternalOnCreateComponent;
	UserDirectory->WinTop = 0.027778;
	UserDirectory->WinLeft = 0.020833;
	UserDirectory->WinWidth = 0.760413;
	UserDirectory->WinHeight = 0.939583;
	UserDirectory->bBoundToParent = true;
	UserDirectory->bScaleToParent = true;
	UGUIButton* AddButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddButton->Caption = "Add";
	AddButton->Hint = "Add selected item to playlist.  If selected item is a directory, all songs in the directory will be added to the playlist.";
	AddButton->WinTop = 0.041667;
	AddButton->WinLeft = 0.822917;
	AddButton->WinWidth = 0.14583;
	AddButton->ScalingType = EParentScaleType::SCALE_X;
	//AddButton->OnClick=StreamPlaylistEditor.InternalOnClick;
	//AddButton->OnKeyEvent=AddButton.InternalOnKeyEvent;
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption = "CLOSE";
	CloseButton->WinTop = 0.844444;
	CloseButton->WinLeft = 0.822917;
	CloseButton->WinWidth = 0.156247;
	CloseButton->ScalingType = EParentScaleType::SCALE_X;
	//CloseButton->OnClick=StreamPlaylistEditor.InternalOnClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UmoComboBox* lbDriveLetters = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	lbDriveLetters->CaptionWidth = 0.3;
	lbDriveLetters->Caption = "Directory:";
	//lbDriveLetters->OnCreateComponent=lbDriveLetters.InternalOnCreateComponent;
	lbDriveLetters->FontScale = EFontScale::FNS_Small;
	lbDriveLetters->WinTop = 0.1;
	lbDriveLetters->WinLeft = 0.1;
	lbDriveLetters->WinWidth = 0.9;
	lbDriveLetters->WinHeight = 32;
	//lbDriveLetters->OnChange=StreamPlaylistEditor.DCOnChange;
	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	//RCMenu->OnOpen=StreamPlaylistEditor.ContextOpen;
	//RCMenu->OnSelect=StreamPlaylistEditor.ContextClick;
	sb_Main = MainPanel;
	lb_Directory = UserDirectory;
	b_Add = AddButton;
	b_Done = CloseButton;
	co_DriveLetters = lbDriveLetters;
	GeneralFileItems = { "Play selected" };
	GeneralFolderItems = { "Add to playlist" };
	PlaylistItems = { "Remove from playlist" };
	NonPlaylistItems = { "Add to playlist","Add to playlist & play" };
	ImportItems = { "Import to new playlist","Import to current playlist" };
	WindowName = "Adding Songs to ";
	MinPageWidth = 0.375;
	MinPageHeight = 0.227902;
	bPersistent = true;
	ContextMenu = RCMenu;
	//OnRightClick = StreamPlaylistEditor.InternalRightClick;
	//OnKeyEvent = StreamPlaylistEditor.InternalOnKeyEvent;
}

/*
final operator(46) TArray<FString> += (TArray<FString>&A, TArray<FString> B)
{
	int32 i = 0;
	int32 j = 0;
	j = A.Length;
	A.Length = (B.Length + j);
	for (i = 0; i < B.Length; i++)
	{
		A[j++] = B[i];
	}
	return A;
}
*/

void UStreamPlaylistEditor::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local TArray<FString> dl;
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	sb_Main.ManageComponent(lb_Directory);
	if (!SetFileManager())
	{
		Warn("Error setting FileManager!");
	}
	li_Directory = lb_Directory.List;
	li_Directory.FileManager = FileManager;
	li_Directory.__OnChange__Delegate = UpdateCurrentPath;
	li_Directory.__OnDblClick__Delegate = InternalOnDblClick;
	li_Directory.bDropSource = true;
	li_Directory.bMultiSelect = true;
	FileManager.GetDriveLetters(dl);
	co_DriveLetters.MyComboBox.bIgnoreChangeWhenTyping = true;
	for (i = 0; i < dl.Length; i++)
	{
		co_DriveLetters.addItem(dl[i] $ FileManager.GetPathSeparator());
	}
	InitializeDirectoryList();
	*/
}

void UStreamPlaylistEditor::DCOnChange(UGUIComponent* Sender)
{
	/*
	FString S = "";
	S = co_DriveLetters.GetText();
	li_Directory.ChDir(S);
	*/
}

void UStreamPlaylistEditor::HandleParameters(FString Param1, FString Param2)
{
	//t_WindowTitle.SetCaption(WindowName @ "-" @ Param1);
}

void UStreamPlaylistEditor::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
	//PlaylistManager.Save();
}

bool UStreamPlaylistEditor::InternalOnKeyEvent(uint8& iKey, uint8& State, float Delta)
{
	/*
	local Interactions.EInputKey Key;
	if ((State != 3) || (FocusedControl != lb_Directory))
	{
		return false;
	}
	if (((Key == 8) || (Key == 37)) || (Key == 100))
	{
		li_Directory.ChDir("..");
		return true;
	}
	if (((Key == 13) || (Key == 39)) || (Key == 102))
	{
		InternalOnDblClick(None);
		return true;
	}
	*/
	return false;
}

bool UStreamPlaylistEditor::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local TArray<FString> items;
	int32 i = 0;
	int32 PlaylistIndex = 0;
	int32 idx = 0;
	bool bResult = false;
	switch (Sender)
	{
	case b_Add:
		items = li_Directory.GetPendingItems(true);
		PlaylistIndex = PlaylistManager.GetCurrentIndex();
		idx = PlaylistManager.GetCurrentPlaylist().GetPlaylistLength();
		i = (items.Length - 1);
		if (i >= 0)
		{
			bResult = PlaylistManager.InsertInPlaylist(PlaylistIndex, idx, items[i], (i > 0));
			(i);
			break;
		}
		return bResult;
	case b_Done:
		Controller.CloseMenu(false);
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UStreamPlaylistEditor::ContextClick(UGUIContextMenu* Menu, int32 Index)
{
	/*
	local StreamBase.FilePath Path;
	PlaylistManager.ParsePath(li_Directory.Get(true), Path);
	switch (Menu.ContextItems[Index])
	{
	case GeneralFileItems[0]:
		Handler.PlaySong(Path.FullPath, 0);
		break;
	case PlaylistItems[0]:
		PlaylistManager.RemoveFromCurrentPlaylist(Path.FullPath);
		break;
	case GeneralFolderItems[0]:
	case NonPlaylistItems[0]:
		AddToPlaylist(Path.FullPath);
		break;
	case NonPlaylistItems[1]:
		AddToPlaylist(Path.FullPath);
		Handler.PlaySong(Path.FullPath, 0);
		break;
	case ImportItems[0]:
		PlaylistManager.ImportPlaylist(-1, -1, Path.FullPath);
		break;
	case ImportItems[1]:
		AddToPlaylist(Path.FullPath);
		break;
	default:
	}
	*/
}

void UStreamPlaylistEditor::UpdateCurrentPath(UGUIComponent* Sender)
{
	/*
	if (Sender == li_Directory)
	{
		co_DriveLetters.SetText(FileManager.GetCurrentDirectory());
	}
	*/
}

bool UStreamPlaylistEditor::InternalOnDblClick(UGUIComponent* Sender)
{
	/*
	FString S = "";
	S = li_Directory.Get();
	if (PlaylistManager.HasExtension(S))
	{
		AddToPlaylist(li_Directory.Get(true));
	}
	else
	{
		li_Directory.ChDir(li_Directory.GetPath());
	}
	*/
	return true;
}

bool UStreamPlaylistEditor::AddPreDraw(UCanvas* C)
{
	/*
	if ((!bCaptureMouse) || bMoving)
	{
		return false;
	}
	b_Add.WinTop = b_Add.RelativeTop(lb_Directory.ActualTop());
	*/
	return true;
}

bool UStreamPlaylistEditor::ClosePreDraw(UCanvas* C)
{
	/*
	if ((!bCaptureMouse) || bMoving)
	{
		return false;
	}
	b_Done.WinTop = b_Done.RelativeTop(((lb_Directory.ActualTop() + lb_Directory.ActualHeight()) - b_Done.ActualHeight()));
	*/
	return true;
}

bool UStreamPlaylistEditor::InternalRightClick(UGUIComponent* Sender)
{
	/*
	if ((Controller == None) || (Controller.ActiveControl != li_Directory))
	{
		return false;
	}
	*/
	return true;
}

bool UStreamPlaylistEditor::ContextOpen(UGUIContextMenu* Menu)
{
	/*
	FString selected = "";
	local StreamBase.FilePath Path;
	selected = li_Directory.Get(true);
	if (PlaylistManager.ParsePath(selected, Path))
	{
		if (Path.FullPath != "")
		{
			if (Path.Extension != "")
			{
				Menu.ContextItems = GeneralFileItems;
				if (((Path.Extension == "m3u") || (Path.Extension == "b4u")) || (Path.Extension == "pls"))
				{
					AddEqual_StrStr(Menu.ContextItems, ImportItems);
				}
				else
				{
					if (CurrentPlaylist.FindIndexByPath(Path.FullPath) != -1)
					{
						AddEqual_StrStr(Menu.ContextItems, PlaylistItems);
					}
					else
					{
						AddEqual_StrStr(Menu.ContextItems, NonPlaylistItems);
					}
				}
			}
			else
			{
				Menu.ContextItems = GeneralFolderItems;
			}
		}
		return true;
	}
	*/
	return false;
}

bool UStreamPlaylistEditor::SetFileManager()
{
	/*
	if (FileManager != None)
	{
		if ((PlaylistManager == None) && (!SetPlaylistManager()))
		{
			return false;
		}
		return true;
	}
	if ((PlaylistManager == None) && (!SetPlaylistManager()))
	{
		return false;
	}
	FileManager = Handler.FileManager;
	*/
	return (FileManager != nullptr);
}

bool UStreamPlaylistEditor::SetPlaylistManager()
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
	CurrentPlaylist = PlaylistManager.GetCurrentPlaylist();
	*/
	return true;
}

bool UStreamPlaylistEditor::SetHandler()
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
			return true;
		}
	}
	Log("StreamPlayer.SetHandler() - no StreamInteractions found!", 'MusicPlayer');
	*/
	return false;
}

void UStreamPlaylistEditor::InitializeDirectoryList()
{
	/*
	int32 i = 0;
	local TArray<FString> Drives;
	if (!FileManager.GetDriveLetters(Drives))
	{
		Warn("FileManager returned no valid drives!");
		return;
	}
	li_Directory.bNotify = false;
	li_Directory.Clear();
	for (i = 0; i < Drives.Length; i++)
	{
		li_Directory.AddNode(None, Drives[i]);
	}
	li_Directory.bNotify = true;
	li_Directory.ChDir(FileManager.GetCurrentDirectory());
	*/
}

bool UStreamPlaylistEditor::AddToPlaylist(FString Filename)
{
	//return PlaylistManager.AddToPlaylist(-1, Filename);
	return false;    //FAKE   /ELiZ
}

bool UStreamPlaylistEditor::HandleDebugExec(FString Command, FString Param)
{
	//return li_Directory.HandleDebugExec(Command, Param);
	return false;    //FAKE   /ELiZ
}

bool UStreamPlaylistEditor::FloatingPreDraw(UCanvas* C)
{
	float At = 0;
	float bh = 0;
	float bl = 0;
	float bt = 0;
	bool B = false;
	/*
	B = Super::FloatingPreDraw(C);
	bh = b_Done.ActualHeight();
	bt = (((ActualTop() + ActualHeight()) - float(20)) - bh);
	bl = (((ActualLeft() + ActualWidth()) - float(24)) - b_Done.ActualWidth());
	b_Done.WinTop = b_Done.RelativeTop(bt);
	b_Done.WinLeft = b_Done.RelativeLeft(bl);
	(bl -= (b_Add.ActualWidth() + (ActualWidth() * 0.01)));
	b_Add.WinLeft = b_Add.RelativeLeft(bl);
	b_Add.WinTop = b_Add.RelativeTop(bt);
	At = ((t_WindowTitle.ActualTop() + t_WindowTitle.ActualHeight()) + (ActualHeight() * 0.01));
	co_DriveLetters.WinLeft = co_DriveLetters.RelativeLeft((ActualLeft() + (ActualWidth() * 0.04)));
	co_DriveLetters.WinTop = co_DriveLetters.RelativeTop(At);
	co_DriveLetters.WinWidth = co_DriveLetters.RelativeWidth((ActualWidth() * 0.92));
	(At += (co_DriveLetters.ActualHeight() + (ActualHeight() * 0.01)));
	sb_Main.WinTop = sb_Main.RelativeTop(At);
	sb_Main.WinHeight = sb_Main.RelativeHeight(((bt - (ActualHeight() * 0.01)) - At));
	sb_Main.WinLeft = sb_Main.RelativeLeft(ActualLeft());
	sb_Main.WinWidth = sb_Main.RelativeWidth(ActualWidth());
	*/
	return B;
}