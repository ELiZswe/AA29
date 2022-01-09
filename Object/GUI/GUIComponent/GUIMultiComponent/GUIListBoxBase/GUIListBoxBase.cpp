// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUIVertScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"

UGUIListBoxBase::UGUIListBoxBase()
{
	UGUIVertScrollBar* TheScrollbar = NewObject<UGUIVertScrollBar>(UGUIVertScrollBar::StaticClass());
	TheScrollbar->bVisible = false;
	//TheScrollbar->OnPreDraw=TheScrollbar.GripPreDraw;
	UGUIToolTip* GUIListBoxBaseToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	SectionStyleName = "ListSection";
	MyScrollBar = TheScrollbar;
	bInitializeList = true;
	PropagateVisibility = true;
	//OnCreateComponent = GUIListBoxBase.InternalOnCreateComponent;
	FontScale = EFontScale::FNS_Small;
	StyleName = "NoBackground";
	bAcceptsInput = true;
	ToolTip = GUIListBoxBaseToolTip;
}

void UGUIListBoxBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local bool bTemp;
	bTemp = PropagateVisibility;
	PropagateVisibility = false;
	InitComponent(MyController, MyOwner);
	PropagateVisibility = bTemp;
	*/
}

void UGUIListBoxBase::InitBaseList(UGUIListBase* LocalList)
{
	/*
	MyList = LocalList;
	LocalList.bNeverScale = true;
	LocalList.StyleName = StyleName;
	LocalList.bVisibleWhenEmpty = bVisibleWhenEmpty;
	LocalList.MyScrollBar = MyScrollBar;
	LocalList.bInitializeList = bInitializeList;
	LocalList.bSorted = bSorted;
	LocalList.FontScale = FontScale;
	MyScrollBar.bTabStop = false;
	MyScrollBar.SetList(LocalList);
	SetVisibility(bVisible);
	SetHint(Hint);
	*/
}

void UGUIListBoxBase::SetHint(FString NewHint)
{
	/*
	int32 i;
	SetHint(NewHint);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].SetHint(NewHint);
	}
	*/
}

void UGUIListBoxBase::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (GUIListBase(NewComp) != nullptr)
	{
		GUIListBase(NewComp).bInitializeList = bInitializeList;
		if (StyleName != "")
		{
			NewComp.StyleName = StyleName;
		}
		if (SelectedStyleName != "")
		{
			GUIListBase(NewComp).SelectedStyleName = SelectedStyleName;
		}
		if (SectionStyleName != "")
		{
			GUIListBase(NewComp).SectionStyleName = SectionStyleName;
		}
		if (OutlineStyleName != "")
		{
			GUIListBase(NewComp).OutlineStyleName = OutlineStyleName;
		}
	}
	*/
}

void UGUIListBoxBase::SetFriendlyLabel(UGUILabel* NewLabel)
{
	/*
	SetFriendlyLabel(NewLabel);
	if (MyList != nullptr)
	{
		MyList.SetFriendlyLabel(NewLabel);
	}
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.SetFriendlyLabel(NewLabel);
	}
	*/
}
