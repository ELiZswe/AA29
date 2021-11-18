// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiComponentListBox/GUIMultiComponentListBox.h"

UGUIMultiComponentListBox::UGUIMultiComponentListBox()
{
	NumColumns = 1;
	//DefaultListClass = "AGP_Interface.GUIMultiComponentList";
}



void UGUIMultiComponentListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	local GUIMultiComponentList L;
	L = GUIMultiComponentList(LocalList);
	if (L == None || L == List)
	{
		Return;
	}
	InitBaseList(LocalList);
	if (List != None)
	{
		List.KillTimer();
		List.__OnClick__Delegate = None;
		List.__OnChange__Delegate = None;
		List.__OnCreateComponent__Delegate = None;
		List.__OnSaveINI__Delegate = None;
		List.__OnLoadINI__Delegate = None;
		RemoveComponent(List, True);
		List = GUIMultiComponentList(AppendComponent(L));
	}
	else
	{
		List = GUIMultiComponentList(AppendComponent(L));
	}
	if (List != None)
	{
		List.__OnClick__Delegate = InternalOnClick;
		List.OnClickSound = 1;
		List.__OnChange__Delegate = InternalOnChange;
		List.__OnCreateComponent__Delegate = ListCreateComponent;
		List.__OnSaveINI__Delegate = ListSaveIni;
		List.__OnLoadINI__Delegate = ListLoadIni;
	}
	*/
}

void UGUIMultiComponentListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUIMultiComponentList L;
	local class<GUIMultiComponentList>  ListClass;
	InitComponent(MyController, MyOwner);
	MyScrollBar.Step = NumColumns;
	if (DefaultListClass != "")
	{
		ListClass = class<GUIMultiComponentList>(Controller.AddComponentClass(DefaultListClass));
		if (ListClass != None)
		{
			L = new (None) classListClass;
		}
		if (L == None)
		{
			Return;
		}
		if (L == None)
		{
			Warn("Could not initialize list!");
			Return;
		}
		InitBaseList(L);
	}
	*/
}

bool UGUIMultiComponentListBox::InternalOnClick(UGUIComponent* Sender)
{
	//OnClick(Self);
	return true;
}

void UGUIMultiComponentListBox::InternalOnChange(UGUIComponent* Sender)
{
	//OnChange(Sender);
}

void UGUIMultiComponentListBox::ItemCount()
{
	//Return List.ItemCount;
}

void UGUIMultiComponentListBox::ListLoadIni(UGUIComponent* Sender, FString S)
{
	//OnLoadINI(Sender, S);
}

void UGUIMultiComponentListBox::ListSaveIni(UGUIComponent* Sender)
{
	//Return OnSaveINI(Sender);
}

void UGUIMultiComponentListBox::ListCreateComponent(UGUIComponent* NewComp, UGUIMultiComponentList* Sender)
{
	/*
	NewComp.IniOption = "@Internal";
	NewComp.__OnSaveINI__Delegate = ListSaveIni;
	NewComp.__OnLoadINI__Delegate = ListLoadIni;
	OnCreateComponent(NewComp, Sender);
	*/
}

void UGUIMultiComponentListBox::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	InternalOnCreateComponent(NewComp, Sender);
	if (GUIMultiComponentList(NewComp) != None)
	{
		GUIMultiComponentList(NewComp).NumColumns = NumColumns;
	}
	*/
}

void UGUIMultiComponentListBox::InternalOnScrollRelease(UGUIComponent* Sender)
{
	//MyScrollBar.GripPreDraw(MyScrollBar.MyGripButton);
}