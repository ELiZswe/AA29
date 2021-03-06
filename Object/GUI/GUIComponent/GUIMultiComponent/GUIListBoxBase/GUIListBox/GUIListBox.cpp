// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"

UGUIListBox::UGUIListBox()
{
	//DefaultListClass = "XInterface.GUIList";
}

void UGUIListBox::InitBaseList(UGUIListBase* LocalList)
{
	if (List == nullptr || List != LocalList && Cast<UGUIList>(LocalList) != nullptr)
	{
		List = Cast<UGUIList>(LocalList);
	}
	//List.__OnClick__Delegate = InternalOnClick;
	//List.OnClickSound = 1;
	//List.__OnDblClick__Delegate = InternalOnDblClick;
	//List.__OnChange__Delegate = InternalOnChange;
	Super::InitBaseList(LocalList);
}

void UGUIListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (DefaultListClass != "")
	{
		List = Cast<UGUIList>(AddComponent(DefaultListClass,false));
		if (List == nullptr)
		{
			//Log(Class + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
	}
	if (List == nullptr)
	{
		//Warn("Could not initialize list!");
		return;
	}
	InitBaseList(List);
}

bool UGUIListBox::InternalOnClick(UGUIComponent* Sender)
{
	List->InternalOnClick(Sender);
	OnClick(this);
	return true;
}

bool UGUIListBox::InternalOnDblClick(UGUIComponent* Sender)
{
	return true;
}

void UGUIListBox::InternalOnChange(UGUIComponent* Sender)
{
	if (Controller != nullptr && Controller->bCurMenuInitialized)
	{
		OnChange(this);
	}
}

int32 UGUIListBox::ItemCount()
{
	return List->ItemCount;
}

bool UGUIListBox::MyOpen(UGUIContextMenu* Menu)
{
	return HandleContextMenuOpen(this, Menu, Menu->MenuOwner);
}

bool UGUIListBox::MyClose(UGUIContextMenu* Sender)
{
	return HandleContextMenuClose(Sender);
}
