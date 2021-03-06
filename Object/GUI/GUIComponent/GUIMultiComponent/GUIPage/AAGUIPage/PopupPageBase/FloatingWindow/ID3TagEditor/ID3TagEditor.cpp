// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/ID3TagEditor/ID3TagEditor.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/AnimatedEditBox/AnimatedEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/GUIMultiOptionList.h"
#include "AA29/Object/StreamBase/Stream/Stream.h"
#include "AA29/Object/Interactions/Interaction/StreamInteraction/StreamInteraction.h"
#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/StreamTag/StreamTag.h"
#include "Engine/Canvas.h"

UID3TagEditor::UID3TagEditor()
{
	UGUIMultiOptionListBox* FieldList = NewObject<UGUIMultiOptionListBox>(UGUIMultiOptionListBox::StaticClass());
	FieldList->bVisibleWhenEmpty = true;
	//FieldList->OnCreateComponent=FieldList.InternalOnCreateComponent;
	FieldList->WinHeight = 1;
	FieldList->bBoundToParent = true;
	FieldList->bScaleToParent = true;
	UGUIPanel* MainPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	MainPanel->WinTop = 0.091595;
	MainPanel->WinLeft = 0.01125;
	MainPanel->WinWidth = 0.97875;
	MainPanel->WinHeight = 0.89625;
	MainPanel->RenderWeight = 0.2;
	p_Main = MainPanel;
	lb_Fields = FieldList;
	EditBoxHint = "Click to edit";
	WindowName = "Tag Editor";
	MinPageWidth = 0.458984;
	MinPageHeight = 0.330155;
}

void UID3TagEditor::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	p_Main.__OnCreateComponent__Delegate = InternalOnCreateComponent;
	p_Main.AppendComponent(lb_Fields);
	li_Fields = lb_Fields.List;
	li_Fields.__OnCreateComponent__Delegate = ListCreateComponent;
	li_Fields.bDrawSelectionBorder = false;
	SetFileManager();
	*/
}

void UID3TagEditor::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	Super::Closed(Sender, bCancelled);
	Stream.SaveID3Tag();
	*/
}

bool UID3TagEditor::SetFileManager()
{
	/*
	if (FileManager != nullptr)
	{
		if ((Handler == nullptr) && (!SetHandler()))
		{
			return false;
		}
		return true;
	}
	if ((Handler == nullptr) && (!SetHandler()))
	{
		return false;
	}
	FileManager = Handler.FileManager;
	*/
	return (FileManager != nullptr);
}

bool UID3TagEditor::SetHandler()
{
	/*
	int32 i = 0;
	if ((Controller == nullptr) || (Controller.ViewportOwner == nullptr))
	{
		return false;
	}
	for (i = 0; i < Controller.ViewportOwner.LocalInteractions.Num(); i++)
	{
		if (Cast<UStreamInteraction>(Controller.ViewportOwner.LocalInteractions[i]) != nullptr)
		{
			Handler = StreamInteraction(Controller.ViewportOwner.LocalInteractions[i]);
			return true;
		}
	}
	Log("StreamPlayer.SetHandler() - no StreamInteractions found!", 'MusicPlayer');
	*/
	return false;
}

void UID3TagEditor::HandleObject(UObject* obj, UObject* OptionalObject_1, UObject* OptionalObj_2)
{
	/*
	Assert((Filename != ""));
	if (obj != nullptr)
	{
		Stream = Stream(obj);
	}
	if (Stream == nullptr)
	{
		Stream = FileManager.CreateStream(Filename);
	}
	if (Stream != nullptr)
	{
		ID3Tag = Stream.GetTag();
	}
	ReadTag();
	*/
}

void UID3TagEditor::HandleParameters(FString ParamA, FString ParamB)
{
	//Filename = ParamA;
}

void UID3TagEditor::InternalOnChange(UGUIComponent* Sender)
{
	int32 i = 0;
	int32 idx = 0;
	UGUIMenuOption* mo = nullptr;
	/*
	if (Cast<UGUIMultiOptionList>(Sender) != nullptr)
	{
		mo = li_Fields.Get();
		if (mo == nullptr)
		{
			Warn("mo was None");
			return;
		}
		idx = FindFieldIndex(mo.Caption);
		if (i != -1)
		{
			ID3Tag.Fields[i].FieldValue = mo.GetComponentValue();
		}
	}
	*/
}

int32 UID3TagEditor::FindFieldIndex(FString Caption)
{
	int32 i = 0;
	for (i = 0; i < ID3Tag->Fields.Num(); i++)
	{
		if (ID3Tag->Fields[i].FieldName == Caption)
		{
			return i;
		}
	}
	return -1;
}

void UID3TagEditor::ReadTag()
{
	int32 i = 0;
	UAnimatedEditBox* Box = nullptr;
	/*
	if (ID3Tag == nullptr)
	{
		return;
	}
	for (i = 0; i < ID3Tag.Fields.Num(); i++)
	{
		Box = AnimatedEditBox(li_Fields.addItem("GUI2K4.AnimatedEditBox", None, ID3Tag.Fields[i].FieldName));
		Box.SetComponentValue(ID3Tag.Fields[i].FieldValue, true);
	}
	*/
}

void UID3TagEditor::SetPanelPosition(UCanvas* C)
{
	/*
	float At = 0;
	At = ((t_WindowTitle.ActualTop() + t_WindowTitle.ActualHeight()) + 2);
	p_Main.WinTop = p_Main.RelativeTop(At);
	p_Main.WinHeight = p_Main.RelativeHeight(((Bounds[3] - ActualHeight(0.015)) - At));
	*/
}

void UID3TagEditor::ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender)
{
	//NewComp.bAutoSizeCaption = false;
}
