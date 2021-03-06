// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIContentScrollBar/GUIContentScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIContentBoxHeader/GUIContentBoxHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIContentPanel/GUIContentPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIContentBox::UGUIContentBox()
{
	
	UGUIContentScrollBar* TheScrollbar = NewObject<UGUIContentScrollBar>(UGUIContentScrollBar::StaticClass());
	TheScrollbar->RenderWeight=1;
	TheScrollbar->bVisible=false;
	//TheScrollbar->OnPreDraw=TheScrollbar.GripPreDraw;
	UGUIContentBoxHeader* TheHeader = NewObject<UGUIContentBoxHeader>(UGUIContentBoxHeader::StaticClass());
	TheHeader->bVisible=false;
	UGUIToolTip* GUIListBoxBaseToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());

	MyHeader = TheHeader;
	MyScrollBar = TheScrollbar;
	//DefaultPanelClass = "AGP_Interface.GUIContentPanel";
	ItemSpacing = 0.01;
	SideGaps = 0.015;
	PropagateVisibility = true;
	FontScale = EeFontScale::FNS_Small;
	StyleName = "NoBackground";
	bAcceptsInput = true;
	ToolTip = GUIListBoxBaseToolTip;
}

void UGUIContentBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	InitComponent(MyController, MyOwner);
	if (DefaultPanelClass != "")
	{
		MyPanel = GUIContentPanel(AddComponent(DefaultPanelClass));
		if (MyPanel == nullptr)
		{
			Log(Class + ".InitComponent - Could not create default panel [" + DefaultPanelClass + "]");
			return;
		}
		MyPanel.StyleName = StyleName;
		MyPanel.ItemSpacing = ItemSpacing;
		MyPanel.bCenterItems = bCenterItems;
		MyPanel.bScaleItemsToWidth = bScaleItemsToWidth;
		GUIContentScrollBar(MyScrollBar).MyPanel = MyPanel;
		MyPanel.MyScrollBar = MyScrollBar;
		MyScrollBar.__AlignThumb__Delegate = MyPanel.ScrollAlignThumb;
		i = 0;
		if (i < ColumnWidths.Num() && i < ColumnHeadings.Num())
		{
			MyHeader.ColumnWidths[i] = ColumnWidths[i];
			MyHeader.ColumnHeadings[i] = ColumnHeadings[i];
			i++;
		}
	}
	*/
}

UGUIComponent* UGUIContentBox::addItem(FString NewClass)
{
	return MyPanel->AddComponent(NewClass, true);
}

void UGUIContentBox::AppendItem(UGUIComponent* NewComp)
{
	MyPanel->AppendComponent(NewComp, true);
}

void UGUIContentBox::InsertItem(UGUIComponent* NewComp, int idx)
{
	MyPanel->InsertComponent(NewComp, idx, true);
}

void UGUIContentBox::RemoveItem(UGUIComponent* Comp)
{
	MyPanel->RemoveComponent(Comp, true);
}

void UGUIContentBox::RemoveAllComponents()
{
	/*
	if (MyPanel.Elements.Num() > 0)
	{
		MyPanel.RemoveComponent(MyPanel.Elements[0], false);
	}
	MyPanel.bInitialPredraw = true;
	*/
}
