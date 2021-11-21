// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIStripComponent/GUIStripComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIHorzScrollButton/GUIHorzScrollButton.h"

UGUIStripComponent::UGUIStripComponent()
{
	UGUIHorzScrollButton* LeftButton = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	LeftButton->Position = EIconPosition::ICP_Center;
	LeftButton->WinWidth = 0.023438;
	//LeftButton->OnClick=GUIStripComponent.ScrollClick;
	//LeftButton->OnKeyEvent=LeftButton.InternalOnKeyEvent;
	UGUIHorzScrollButton* RightButton = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	RightButton->bIncreaseButton = true;
	RightButton->Position = EIconPosition::ICP_Center;
	RightButton->WinWidth = 0.023438;
	//RightButton->OnClick=GUIStripComponent.ScrollClick;
	//RightButton->OnKeyEvent=RightButton.InternalOnKeyEvent;
	LeftScroll = LeftButton;
	RightScroll = RightButton;
	ItemWidth = 0.2;
	ItemSpacing = 0.01;
	//OnPreDraw = GUIStripComponent.InternalOnPreDraw;
}

bool UGUIStripComponent::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	float PortalLeft = 0;
	float PortalRight = 0;
	float PortalWidth = 0;
	float AItemSpacing = 0;
	float AItemWidth = 0;
	float AItemHeight = 0;
	float CurrentLeft = 0;
	float TotalItemSpacing = 0;
	int32 i = 0;
	if (ItemSpacing < 2)
	{
		AItemSpacing = (ItemSpacing * float(Controller.ResX));
	}
	else
	{
		AItemSpacing = ItemSpacing;
	}
	if (ItemWidth < 2)
	{
		AItemWidth = (ItemWidth * float(Controller.ResX));
	}
	else
	{
		AItemWidth = ItemWidth;
	}
	AItemHeight = (ClientBounds[3] - ClientBounds[1]);
	PortalLeft = ((ClientBounds[0] + LeftScroll.ActualWidth()) + AItemSpacing);
	PortalRight = (ClientBounds[2] - RightScroll.ActualWidth());
	PortalWidth = (PortalRight - PortalLeft);
	ItemsPerPage = int((PortalWidth / (AItemWidth + AItemSpacing)));
	TotalItemSpacing = (AItemWidth + AItemSpacing);
	LeftScroll.WinLeft = ClientBounds[0];
	LeftScroll.WinTop = ClientBounds[1];
	LeftScroll.WinHeight = AItemHeight;
	RightScroll.WinLeft = (PortalLeft + (float(ItemsPerPage) * TotalItemSpacing));
	RightScroll.WinTop = ClientBounds[1];
	RightScroll.WinHeight = AItemHeight;
	if (ItemsPerPage >= Elements.Length)
	{
		LeftScroll.DisableMe();
		RightScroll.DisableMe();
	}
	else
	{
		if (FirstVisibleIndex == 0)
		{
			LeftScroll.DisableMe();
			RightScroll.EnableMe();
		}
		else
		{
			if (FirstVisibleIndex == (Elements.Length - ItemsPerPage))
			{
				LeftScroll.EnableMe();
				RightScroll.DisableMe();
			}
			else
			{
				LeftScroll.EnableMe();
				RightScroll.EnableMe();
			}
		}
	}
	CurrentLeft = PortalLeft;
	for (i = 0; i < Elements.Length; i++)
	{
		if ((i < FirstVisibleIndex) || (i >= (FirstVisibleIndex + ItemsPerPage)))
		{
			Elements[i].bVisible = false;
		}
		else
		{
			Elements[i].bVisible = true;
			Elements[i].WinLeft = CurrentLeft;
			Elements[i].WinWidth = AItemWidth;
			Elements[i].WinTop = ClientBounds[1];
			Elements[i].WinHeight = AItemHeight;
			CurrentLeft += TotalItemSpacing;
		}
	}
	*/
	return false;
}

UGUIComponent* UGUIStripComponent::AppendComponent(UGUIComponent* NewComp, bool SkipRemap)
{
	/*
	Super::AppendComponent(NewComp, SkipRemap);
	NewComp.bScaleToParent = false;
	NewComp.bBoundToParent = false;
	Elements[Elements.Length] = NewComp;
	*/
	return NewComp;
}

UGUIComponent* UGUIStripComponent::InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap)
{
	/*
	Super::InsertComponent(NewComp, Index, SkipRemap);
	NewComp.bScaleToParent = false;
	NewComp.bBoundToParent = false;
	Elements.insert(Index, 1);
	Elements[Index] = NewComp;
	*/
	return NewComp;
}

 bool UGUIStripComponent::RemoveComponent(UGUIComponent* Comp, bool SkipRemap)
{
	/*
	int32 i = 0;
	int32 Num = 0;
	Num = -1;
	i = 0;
	if (i < Elements.Length)
	{
		if (Elements[i] == Comp)
		{
			Num = i;
		}
		else
		{
			i++;
		}
	}
	if (Num < 0)
	{
		return false;
	}
	if (Super::RemoveComponent(Comp, SkipRemap))
	{
		Elements.remove(Num, 1);
		return true;
	}
	*/
	return false;
}

bool UGUIStripComponent::ScrollClick(UGUIComponent* Sender)
{
	/*
	if (Sender == LeftScroll)
	{
		if (FirstVisibleIndex > 0)
		{
			FirstVisibleIndex--;
		}
	}
	else
	{
		if (FirstVisibleIndex < (Elements.Length - ItemsPerPage))
		{
			FirstVisibleIndex++;
		}
	}
	*/
	return true;
}