// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIContentScrollBar/GUIContentScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIContentBoxHeader/GUIContentBoxHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

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
	FontScale = EFontScale::FNS_Small;
	StyleName = "NoBackground";
	bAcceptsInput = true;
	ToolTip = GUIListBoxBaseToolTip;
}

void UGUIContentBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int i;
	InitComponent(MyController, MyOwner);
	if (DefaultPanelClass != "")
	{
		MyPanel = GUIContentPanel(AddComponent(DefaultPanelClass));
		if (MyPanel == None)
		{
			Log(Class $ ".InitComponent - Could not create default panel [" $ DefaultPanelClass $ "]");
			Return;
		}
		MyPanel.StyleName = StyleName;
		MyPanel.ItemSpacing = ItemSpacing;
		MyPanel.bCenterItems = bCenterItems;
		MyPanel.bScaleItemsToWidth = bScaleItemsToWidth;
		GUIContentScrollBar(MyScrollBar).MyPanel = MyPanel;
		MyPanel.MyScrollBar = MyScrollBar;
		MyScrollBar.__AlignThumb__Delegate = MyPanel.ScrollAlignThumb;
		i = 0;
		if (i < ColumnWidths.Length && i < ColumnHeadings.Length)
		{
			MyHeader.ColumnWidths[i] = ColumnWidths[i];
			MyHeader.ColumnHeadings[i] = ColumnHeadings[i];
			i++;
		}
	}
	*/
}

void UGUIContentBox::addItem(FString NewClass)
{
	//Return MyPanel.AddComponent(NewClass, True);
}

void UGUIContentBox::AppendItem(UGUIComponent* NewComp)
{
	//MyPanel.AppendComponent(NewComp, True);
}

void UGUIContentBox::InsertItem(UGUIComponent* NewComp, int idx)
{
	//MyPanel.InsertComponent(NewComp, idx, True);
}

void UGUIContentBox::RemoveItem(UGUIComponent* Comp)
{
	//MyPanel.RemoveComponent(Comp, True);
}

void UGUIContentBox::RemoveAllComponents()
{
	/*
	if (MyPanel.Elements.Length > 0)
	{
		MyPanel.RemoveComponent(MyPanel.Elements[0], False);
	}
	MyPanel.bInitialPredraw = True;
	*/
}