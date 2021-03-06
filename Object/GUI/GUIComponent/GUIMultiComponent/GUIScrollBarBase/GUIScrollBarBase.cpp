// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIGripButtonBase.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIScrollButtonBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIScrollZoneBase.h"

UGUIScrollBarBase::UGUIScrollBarBase()
{
	Step = 1;
	PropagateVisibility = true;
	bTabStop = false;
}

void UGUIScrollBarBase::PositionChanged(int32 NewPos)
{
}

void UGUIScrollBarBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (MyList != nullptr)
	{
		Refocus(MyList);
		BigStep = (MyList->ItemsPerPage * Step);
		ItemCount = MyList->ItemCount;
		CurPos = MyList->Top;
	}
	MyScrollZone->bNeverScale = true;
	MyIncreaseButton->bNeverScale = true;
	MyDecreaseButton->bNeverScale = true;
	MyGripButton->bNeverScale = true;
}

void UGUIScrollBarBase::SetList(UGUIListBase* List)
{
	MyList = List;
	Refocus(List);
	if (List != nullptr)
	{
		BigStep = List->ItemsPerPage;
		ItemCount = List->ItemCount;
		CurPos = MyList->Top;
	}
	else
	{
		BigStep = 0;
		ItemCount = 0;
		CurPos = 0;
	}
}

void UGUIScrollBarBase::UpdateGripPosition(float NewPos)
{
	if (MyList != nullptr)
	{
		MyList->MakeVisible(NewPos);
		ItemCount = MyList->ItemCount;
	}
	GripPos = NewPos;
	CurPos = int((float((ItemCount - ItemsPerPage)) * GripPos));
	PositionChanged(CurPos);
}

void UGUIScrollBarBase::MoveGripBy(int32 items)
{
	int32 NewItem = 0;
	if (MyList != nullptr)
	{
		NewItem = (MyList->Top + items);
		ItemCount = MyList->ItemCount;
		if (MyList->ItemCount > 0)
		{
			MyList->SetTopItem(NewItem);
			AlignThumb();
		}
	}
	(CurPos += items);
	if (CurPos < 0)
	{
		CurPos = 0;
	}
	if (CurPos > (ItemCount - ItemsPerPage))
	{
		CurPos = (ItemCount - ItemsPerPage);
	}
	if (MyList == nullptr)
	{
		if (ItemCount > 0)
		{
			AlignThumb();
		}
	}
	PositionChanged(CurPos);
}

bool UGUIScrollBarBase::DecreaseClick(UGUIComponent* Sender)
{
	WheelUp();
	return true;
}

bool UGUIScrollBarBase::IncreaseClick(UGUIComponent* Sender)
{
	WheelDown();
	return true;
}

void UGUIScrollBarBase::WheelUp()
{
	if (!Controller->CtrlPressed)
	{
		MoveGripBy((-Step));
	}
	else
	{
		MoveGripBy((-BigStep));
	}
}

void UGUIScrollBarBase::WheelDown()
{
	if (!Controller->CtrlPressed)
	{
		MoveGripBy(Step);
	}
	else
	{
		MoveGripBy(BigStep);
	}
}

void UGUIScrollBarBase::AlignThumb()
{
	float NewPos = 0;
	if (MyList != nullptr)
	{
		BigStep = (MyList->ItemsPerPage * Step);
		if (MyList->ItemCount == 0)
		{
			NewPos = 0;
		}
		else
		{
			NewPos = (float(MyList->Top) / float((MyList->ItemCount - MyList->ItemsPerPage)));
		}
	}
	else
	{
		if (ItemCount == 0)
		{
			NewPos = 0;
		}
		else
		{
			NewPos = (float(CurPos) / float((ItemCount - ItemsPerPage)));
		}
	}
	//GripPos =FMath::Clamp(NewPos, 0, 1);
}

void UGUIScrollBarBase::Refocus(UGUIComponent* Who)
{
	int32 i = 0;
	if ((Who != nullptr) && (Controls.Num() > 0))
	{
		for (i = 0; i < Controls.Num(); i++)
		{
			Controls[i]->FocusInstead = Who;
			Controls[i]->bNeverFocus = true;
		}
	}
}

bool UGUIScrollBarBase::GripPreDraw(UGUIComponent* Sender)
{
	return false;
}

void UGUIScrollBarBase::SetFriendlyLabel(UGUILabel* NewLabel)
{
	Super::SetFriendlyLabel(NewLabel);
	if (MyScrollZone != nullptr)
	{
		MyScrollZone->SetFriendlyLabel(NewLabel);
	}
	if (MyIncreaseButton != nullptr)
	{
		MyIncreaseButton->SetFriendlyLabel(NewLabel);
	}
	if (MyDecreaseButton != nullptr)
	{
		MyDecreaseButton->SetFriendlyLabel(NewLabel);
	}
	if (MyGripButton != nullptr)
	{
		MyGripButton->SetFriendlyLabel(NewLabel);
	}
}
