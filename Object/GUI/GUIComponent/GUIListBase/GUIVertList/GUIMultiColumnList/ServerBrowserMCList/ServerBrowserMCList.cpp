// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/ServerBrowserMCList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

UServerBrowserMCList::UServerBrowserMCList()
{
	FavoritesStyleName = "BrowserListFavorite";
	bVisibleWhenEmpty = true;
	SelectedStyleName = "BrowserListSelection";
	//__OnDrawItem__Delegate = "ServerBrowserMCList.MyOnDrawItem";
	StyleName = "ServerBrowserGrid";
	RenderWeight = 1;
}

void UServerBrowserMCList::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	InitComponent(InController, InOwner);
	if (FavoritesStyleName != "" && FavoritesStyle == nullptr)
	{
		FavoritesStyle = InController.GetStyle(FavoritesStyleName, FontScale);
	}
	*/
}

void UServerBrowserMCList::MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
}
