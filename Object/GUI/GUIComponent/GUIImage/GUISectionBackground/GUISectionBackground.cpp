// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/GUISectionBackground.h"

UGUISectionBackground::UGUISectionBackground()
{
	CaptionStyleName = "TextLabel";
	bRemapStack = true;
	ColPadding = 0.05;
	LeftPadding = 0.05;
	RightPadding = 0.05;
	ImageOffset = { 16,44,16,18 };
	NumColumns = 1;
	FontScale = EFontScale::FNS_Small;
	RenderWeight = 0.09;
	//__OnPreDraw__Delegate = "GUISectionBackground.InternalPreDraw";
}

void UGUISectionBackground::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (CaptionStyleName != "")
	{
		//CaptionStyle = Controller.GetStyle(CaptionStyleName, FontScale);
	}
}
void UGUISectionBackground::SetVisibility(bool bIsVisible)
{
	/*
	local int i;
	SetVisibility(bIsVisible);
	for (i = 0; i < AlignStack.Length; i++)
	{
		AlignStack[i].SetVisibility(bIsVisible);
	}
	*/
}
bool UGUISectionBackground::ManageComponent(UGUIComponent* Component)
{
	/*
	local int i;
	if (Component == None)
	{
		Return False;
	}
	i = FindComponentIndex(Component);
	if (i == -1)
	{
		if (bRemapStack)
		{
			for (i = 0; i < AlignStack.Length; i++)
			{
				if (AlignStack[i].TabOrder > Component.TabOrder)
				{
				}
			}
		}
		else
		{
			i = AlignStack.Length;
		}
		AlignStack.insert(i, 1);
		AlignStack[i] = Component;
		Return True;
	}
	Return False;
	*/
	return false;   //FAKE   /ELiZ
}
bool UGUISectionBackground::UnmanageComponent(UGUIComponent* Comp)
{
	/*
	local int i;
	i = FindComponentIndex(Comp);
	if (i != -1 && i >= 0 && i < AlignStack.Length)
	{
		AlignStack.remove(i, 1);
		Return True;
	}
	Return False;
	*/
	return false;   //FAKE   /EliZ
}
int32 UGUISectionBackground::FindComponentIndex(UGUIComponent* Comp)
{
	int32 i;
	if (Comp == nullptr)
	{
		return - 1;
	}
	for (i = 0; i < AlignStack.Max(); i++)
	{
		if (AlignStack[i] == Comp)
		{
			return i;
		}
	}
	return - 1;
}
void UGUISectionBackground::Reset()
{
	//AlignStack.remove(0, AlignStack.Length);
	bInit = true;
}
void UGUISectionBackground::InternalPreDraw(UCanvas* C)
{
	/*
	local float AL;
	local float At;
	local float AW;
	local float AH;
	local float LPad;
	local float RPad;
	local float TPad;
	local float BPad;
	if (AlignStack.Length == 0)
	{
		Return False;
	}
	AL = ActualLeft();
	At = ActualTop();
	AW = ActualWidth();
	AH = ActualHeight();
	LPad = LeftPadding * AW + ImageOffset[0];
	TPad = TopPadding * AH + ImageOffset[1];
	RPad = RightPadding * AW + ImageOffset[2];
	BPad = BottomPadding * AH + ImageOffset[3];
	if (Style != None)
	{
		LPad += BorderOffsets[0];
		TPad += BorderOffsets[1];
		RPad += BorderOffsets[2];
		BPad += BorderOffsets[3];
	}
	AutoPosition(AlignStack, AL, At, AL + AW, At + AH, LPad, TPad, RPad, BPad, NumColumns, ColPadding);
	Return False;
	*/
}
void UGUISectionBackground::ResolutionChanged(int32 ResX, int32 ResY)
{
	/*
	ResolutionChanged(ResX, ResY);
	*/
	bInit = true;
}
void UGUISectionBackground::SetPosition(float NewLeft, float NewTop, float NewWidth, float NewHeight, bool bRelative)
{
	//SetPosition(NewLeft, NewTop, NewWidth, NewHeight, bRelative);
	bInit = true;
}