// All the original content belonged to the US Army


#include "AA29/Object/DrawOpBase/DrawOpBase.h"

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

AFont* UDrawOpBase::GetFont(FString FontClassName, float ResX)
{
	AFont* fnt = nullptr;
	/*
	fnt = GetGUIFont(FontClassName, ResX);
	if (fnt == None)
	{
		fnt = Font(DynamicLoadObject(FontClassName, Class'Font'));
	}
	if (fnt == None)
	{
		Log(string(Name) $ " - FONT NOT FOUND '" $ FontClassName $ "'", 'Error');
	}
	*/
	return fnt;
}

AFont* UDrawOpBase::GetGUIFont(FString FontClassName, float ResX)
{
	/*
	local class<GUIFont>  FntCls;
	local GUIFont fnt;
	FntCls = class<GUIFont>(DynamicLoadObject(FontClassName, Class'Class', true));
	if (FntCls != None)
	{
		fnt = new (None) classFntCls;
	}
	if (fnt == None)
	{
		return None;
	}
	return fnt.GetFont(int(ResX));
	*/
	return nullptr;   //FAKE    /ELiZ
}
