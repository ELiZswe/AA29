// All the original content belonged to the US Army

#include "AA29/Object/DrawOpBase/DrawOpBase.h"
#include "AA29/Object/GUI/GUIFont/GUIFont.h"
#include "Engine/Canvas.h"

UDrawOpBase::UDrawOpBase()
{
	//RenderStyle = 1;
	//DrawColor = FColor(255, 255, 255, 255);
}

void UDrawOpBase::SetPos(float t, float L)
{
	//Top = t;
	//Lft = L;
}

void UDrawOpBase::SetSize(float H, float W)
{
	//Height = H;
	//Width = W;
}

void UDrawOpBase::Draw(UCanvas* Canvas)
{
	/*
	Canvas.SetPos((Lft * float(Canvas.SizeX)), (Top * float(Canvas.SizeY)));
	Canvas.Style = RenderStyle;
	Canvas.DrawColor = DrawColor;
	*/
}

UFont* UDrawOpBase::GetFont(FString FontClassName, float ResX)
{
	UFont* fnt = nullptr;
	/*
	fnt = GetGUIFont(FontClassName, ResX);
	if (fnt == nullptr)
	{
		fnt = Font(DynamicLoadObject(FontClassName, Class'Font'));
	}
	if (fnt == nullptr)
	{
		Log(string(Name) + " - FONT NOT FOUND '" + FontClassName + "'", 'Error');
	}
	*/
	return fnt;
}

UFont* UDrawOpBase::GetGUIFont(FString FontClassName, float ResX)
{
	UGUIFont* FntCls = nullptr;
	UGUIFont* fnt = nullptr;
	/*
	FntCls = class<GUIFont>(DynamicLoadObject(FontClassName, Class'Class', true));
	if (FntCls != nullptr)
	{
		fnt = new (None) classFntCls;
	}
	if (fnt == nullptr)
	{
		return nullptr;
	}
	return fnt.GetFont(int(ResX));
	*/
	return nullptr;   //FAKE    /ELiZ
}
