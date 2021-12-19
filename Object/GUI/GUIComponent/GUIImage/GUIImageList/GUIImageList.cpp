// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageList/GUIImageList.h"

UGUIImageList::UGUIImageList()
{
	StyleName = "NoBackground";
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
}

void UGUIImageList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	//__OnKeyEvent__Delegate = internalKeyEvent;
}
void UGUIImageList::AddMaterial(FString MatName, UMaterialInstance* mat)
{
	/*
	local int i;
	if (mat != None)
	{
		i = Materials.Length;
		Materials[i] = mat;
		MatNames[i] = MatName;
	}
	*/
}

FString UGUIImageList::GetCurMatName()
{
	/*
	if (CurIndex >= 0 && CurIndex < Materials.Length)
	{
		return MatNames[CurIndex];
	}
	*/
	return "";
}
void UGUIImageList::SetIndex(int32 Index)
{
	/*
	if (Index >= 0 && Index < Materials.Length)
	{
		CurIndex = Index;
		Image = Materials[Index];
	}
	else
	{
		Image = None;
		CurIndex = -1;
	}
	*/
}
bool UGUIImageList::internalKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	/*
	if (State != 3)
	{
		return false;
	}
	Switch(Key)
	{
			case 37:
			case 38:
			case 100:
			case 104:
			case 236:
				PrevImage();
				return true;
			case 39:
			case 40:
			case 98:
			case 102:
			case 237:
				NextImage();
				return true;
			case 36:
			case 103:
				FirstImage();
				return true;
			case 35:
			case 97:
				LastImage();
				return true;
			default:
				return false;
	}
	*/
	return false;    //FAKE    /ELiZ
}
void UGUIImageList::PrevImage()
{
	/*
	if (CurIndex < 1)
	{
		if (bWrap)
		{
			SetIndex(Materials.Length - 1);
		}
	}
	else
	{
		SetIndex(CurIndex - 1);
	}
	*/
}
void UGUIImageList::NextImage()
{
	/*
	if (CurIndex < 0)
	{
		SetIndex(0);
	}
	else
	{
		if (CurIndex + 1 >= Materials.Length)
		{
			if (bWrap)
			{
				SetIndex(0);
			}
		}
		else
		{
			SetIndex(CurIndex + 1);
		}
	}
	*/
}
void UGUIImageList::FirstImage()
{
	/*
	if (Materials.Length > 0)
	{
		SetIndex(0);
	}
	*/
}
void UGUIImageList::LastImage()
{
	/*
	if (Materials.Length > 0)
	{
		SetIndex(Materials.Length - 1);
	}
	*/
}
