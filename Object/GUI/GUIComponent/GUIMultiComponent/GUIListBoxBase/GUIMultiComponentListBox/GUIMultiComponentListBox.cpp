// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiComponentListBox/GUIMultiComponentListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiComponentList/GUIMultiComponentList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"

UGUIMultiComponentListBox::UGUIMultiComponentListBox()
{
	NumColumns = 1;
	//DefaultListClass = "AGP_Interface.GUIMultiComponentList";
}

void UGUIMultiComponentListBox::InitBaseList(UGUIListBase* LocalList)
{
	UGUIMultiComponentList* L = nullptr;
	L = Cast<UGUIMultiComponentList>(LocalList);
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
		List = Cast<UGUIMultiComponentList>(AppendComponent(L));
	}
	else
	{
		List = Cast<UGUIMultiComponentList>(AppendComponent(L));
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

void UGUIMultiComponentListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUIMultiComponentList* L = nullptr;
	UGUIMultiComponentList* ListClass = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	MyScrollBar.Step = NumColumns;
	if (DefaultListClass != "")
	{
		ListClass = class<GUIMultiComponentList>(Controller.AddComponentClass(DefaultListClass));
		if (ListClass != nullptr)
		{
			L = new (None) classListClass;
		}
		if (L == nullptr)
		{
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

bool UGUIMultiComponentListBox::InternalOnClick(UGUIComponent* Sender)
{
	OnClick(this);
	return true;
}

void UGUIMultiComponentListBox::InternalOnChange(UGUIComponent* Sender)
{
	OnChange(Sender);
}

int32 UGUIMultiComponentListBox::ItemCount()
{
	return List->ItemCount;
}

void UGUIMultiComponentListBox::ListLoadIni(UGUIComponent* Sender, FString S)
{
	OnLoadINI(Sender, S);
}

FString UGUIMultiComponentListBox::ListSaveIni(UGUIComponent* Sender)
{
	return OnSaveINI(Sender);
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
	if (Cast<UGUIMultiComponentList>(NewComp) != nullptr)
	{
		GUIMultiComponentList(NewComp).NumColumns = NumColumns;
	}
	*/
}

void UGUIMultiComponentListBox::InternalOnScrollRelease(UGUIComponent* Sender)
{
	//MyScrollBar.GripPreDraw(MyScrollBar.MyGripButton);
}
