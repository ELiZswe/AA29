// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/ListTest/ListTest.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UListTest::UListTest()
{
	UGUIButton* btnAddItems = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnAddItems->WinTop = 0.55;
	btnAddItems->WinLeft = 0.05;
	btnAddItems->WinWidth = 0.4;
	btnAddItems->WinHeight = 0.06;
	//btnAddItems->OnClick=ListTest.AddClick;
	//btnAddItems->OnKeyEvent=btnAddItems.InternalOnKeyEvent;
	UGUIScrollTextBox* Scroller = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	Scroller->CharDelay = 0.05;
	Scroller->EOLDelay = 0.6;
	//Scroller->OnCreateComponent=Scroller.InternalOnCreateComponent;
	Scroller->WinTop = 0.05;
	Scroller->WinLeft = 0.05;
	Scroller->WinWidth = 0.35;
	Scroller->WinHeight = 0.2;
	Controls = { Scroller,btnAddItems };
}

void UListTest::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString NewText = "";
	Super::InitComponent(MyController, MyOwner);
	tScroll = GUIScrollTextBox(Controls[0]).MyScrollText;
	NewText = "This is a simple test of multiline splitting that should be happening very easily but i will debug to be sure that whatever the length is set at it wont bug." $ Chr(10) $ Chr(10);
	NewText = NewText $ "But more importantly i must also handle having more than just 1 line of text and see how this is dealt with." $ Chr(10);
	NewText = NewText $ "I wonder how this would be dealt with if i wasnt taking care of it and if Joe wasnt going to do it." $ Chr(10) $ Chr(10);
	NewText = NewText $ "Bah, We'll see later since no one seems to reply to my messages.";
	tScroll.SetContent(NewText);
	Controller.bDesignMode = false;
	*/
}

bool UListTest::AddClick(UGUIComponent* Sender)
{
	return true;
}
