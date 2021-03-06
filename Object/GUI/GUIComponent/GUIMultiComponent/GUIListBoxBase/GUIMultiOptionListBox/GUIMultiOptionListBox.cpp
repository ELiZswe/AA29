// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIMenuOption.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiOptionList/GUIMultiOptionList.h"

UGUIMultiOptionListBox::UGUIMultiOptionListBox()
{
	NumColumns = 1;
	//DefaultListClass = "XInterface.GUIMultiOptionList";
}

void UGUIMultiOptionListBox::InitBaseList(UGUIListBase* LocalList)
{
	UGUIMultiOptionList* L = nullptr;
	L = Cast<UGUIMultiOptionList>(LocalList);
	/*
	if (L == nullptr || L == List)
	{
		return;
	}
	InitBaseList(LocalList);
	if (List != nullptr)
	{
		List.KillTimer();
		List.__OnClick__Delegate = nullptr;
		List.__OnChange__Delegate = nullptr;
		List.__OnCreateComponent__Delegate = nullptr;
		List.__OnSaveINI__Delegate = nullptr;
		List.__OnLoadINI__Delegate = nullptr;
		RemoveComponent(List, true);
		List = GUIMultiOptionList(AppendComponent(L));
	}
	else
	{
		List = GUIMultiOptionList(AppendComponent(L));
	}
	if (List != nullptr)
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
	UGUIMultiOptionList* L = nullptr;
	UGUIMultiOptionList* ListClass = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	MyScrollBar.Step = NumColumns;
	if (DefaultListClass != "")
	{
		ListClass = class<GUIMultiOptionList>(Controller.AddComponentClass(DefaultListClass));
		if (ListClass != nullptr)
		{
			L = new (None) classListClass;
		}
		if (L == nullptr)
		{
			Log(Class + ".InitComponent - Could not create default list [" + DefaultListClass + "]");
			return;
		}
		if (L == nullptr)
		{
			Warn("Could not initialize list!");
			return;
		}
		InitBaseList(L);
	}
	*/
}

bool UGUIMultiOptionListBox::InternalOnClick(UGUIComponent* Sender)
{
	//OnClick(this);
	return true;
}

void UGUIMultiOptionListBox::InternalOnChange(UGUIComponent* Sender)
{
	//OnChange(Sender);
}

int32 UGUIMultiOptionListBox::ItemCount()
{
	//return List.ItemCount;
	return 0;    //FAKE   /EliZ
}

void UGUIMultiOptionListBox::ListLoadIni(UGUIComponent* Sender, FString S)
{
	//OnLoadINI(Sender, S);
}

FString UGUIMultiOptionListBox::ListSaveIni(UGUIComponent* Sender)
{
	return OnSaveINI(Sender);
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
	if (Cast<UGUIMultiOptionList>(NewComp) != nullptr)
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
	int32 i = 0;
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
	int32 i = 0;
	DisableMe();
	for (i = 0; i < List.ItemCount; i++)
	{
		DisableComponent(List.GetItem(i));
	}
	*/
}
