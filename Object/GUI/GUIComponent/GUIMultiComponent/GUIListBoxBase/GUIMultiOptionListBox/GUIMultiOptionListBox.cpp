// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"

UGUIMultiOptionListBox::UGUIMultiOptionListBox()
{
	NumColumns = 1;
	//DefaultListClass = "XInterface.GUIMultiOptionList";
}

void UGUIMultiOptionListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	local GUIMultiOptionList L;
	L = GUIMultiOptionList(LocalList);
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
		List = GUIMultiOptionList(AppendComponent(L));
	}
	else
	{
		List = GUIMultiOptionList(AppendComponent(L));
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

void UGUIMultiOptionListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local GUIMultiOptionList L;
	local class<GUIMultiOptionList>  ListClass;
	InitComponent(MyController, MyOwner);
	MyScrollBar.Step = NumColumns;
	if (DefaultListClass != "")
	{
		ListClass = class<GUIMultiOptionList>(Controller.AddComponentClass(DefaultListClass));
		if (ListClass != None)
		{
			L = new (None) classListClass;
		}
		if (L == None)
		{
			Log(Class $ ".InitComponent - Could not create default list [" $ DefaultListClass $ "]");
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

bool UGUIMultiOptionListBox::InternalOnClick(UGUIComponent* Sender)
{
	//OnClick(Self);
	return true;
}

void UGUIMultiOptionListBox::InternalOnChange(UGUIComponent* Sender)
{
	//OnChange(Sender);
}

void UGUIMultiOptionListBox::ItemCount()
{
	//Return List.ItemCount;
}

void UGUIMultiOptionListBox::ListLoadIni(UGUIComponent* Sender, FString S)
{
	//OnLoadINI(Sender, S);
}

void UGUIMultiOptionListBox::ListSaveIni(UGUIComponent* Sender)
{
	//Return OnSaveINI(Sender);
}

void UGUIMultiOptionListBox::ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender)
{
	/*
	NewComp.IniOption = "@Internal";
	NewComp.__OnSaveINI__Delegate = ListSaveIni;
	NewComp.__OnLoadINI__Delegate = ListLoadIni;
	OnCreateComponent(NewComp, Sender);
	*/
}

void UGUIMultiOptionListBox::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	InternalOnCreateComponent(NewComp, Sender);
	if (GUIMultiOptionList(NewComp) != None)
	{
		GUIMultiOptionList(NewComp).NumColumns = NumColumns;
	}
	*/
}

void UGUIMultiOptionListBox::InternalOnScrollRelease(UGUIComponent* Sender)
{
	//MyScrollBar.GripPreDraw(MyScrollBar.MyGripButton);
}

void UGUIMultiOptionListBox::EnableMe()
{
	/*
	local int i;
	EnableMe();
	for (i = 0; i < List.ItemCount; i++)
	{
		EnableComponent(List.GetItem(i));
	}
	*/
}

void UGUIMultiOptionListBox::DisableMe()
{
	/*
	local int i;
	DisableMe();
	for (i = 0; i < List.ItemCount; i++)
	{
		DisableComponent(List.GetItem(i));
	}
	*/
}