// All the original content belonged to the US Army

#include "AA29/Object/Actor/Vignette/UT2LoadingPageBase/UT2LoadingPageBase.h"
#include "AA29/Object/DrawOpBase/DrawOpImage/DrawOpImage.h"
#include "AA29/Object/DrawOpBase/DrawOpText/DrawOpText.h"
#include "Engine/Canvas.h"

AUT2LoadingPageBase::AUT2LoadingPageBase()
{

}

void AUT2LoadingPageBase::DrawVignette(UCanvas* C, float Progress)
{
	/*
	int32 i = 0;
	for (i = 0; i < Operations.Num(); i++)
	{
		Operations[i].Draw(C);
	}
	*/
}

UDrawOpImage* AUT2LoadingPageBase::AddImage(UMaterialInstance* Image, float Top, float Left, float Height, float Width)
{
	UDrawOpImage* NewImage = nullptr;
	/*
	NewImage = new (None) UDrawOpImage::StaticClass();
	Operations[Operations.Num()] = NewImage;
	NewImage.Image = Image;
	NewImage.SetPos(Top, Left);
	NewImage.SetSize(Height, Width);
	*/
	return NewImage;
}

UDrawOpImage* AUT2LoadingPageBase::AddImageStretched(UMaterialInstance* Image, float Top, float Left, float Height, float Width)
{
	UDrawOpImage* NewImage = nullptr;
	/*
	NewImage = AddImage(Image, Top, Left, Height, Width);
	NewImage.ImageStyle = 1;
	*/
	return NewImage;
}

UDrawOpText* AUT2LoadingPageBase::AddText(FString Text, float Top, float Left)
{
	UDrawOpText* NewText = nullptr;
	/*
	NewText = new (None) UDrawOpText::StaticClass();
	Operations[Operations.Num()] = NewText;
	NewText.SetPos(Top, Left);
	NewText.Text = Text;
	*/
	return NewText;
}

UDrawOpText* AUT2LoadingPageBase::AddMultiLineText(FString Text, float Top, float Left, float Height, float Width)
{
	UDrawOpText* NewText = nullptr;
	/*
	NewText = AddText(Text, Top, Left);
	NewText.SetSize(Height, Width);
	*/
	return NewText;
}

UDrawOpText* AUT2LoadingPageBase::AddJustifiedText(FString Text, uint8 Just, float Top, float Left, float Height, float Width, uint8 VAlign)
{
	UDrawOpText* NewText=nullptr;
	/*
	NewText = AddText(Text, Top, Left);
	NewText.SetSize(Height, Width);
	NewText.Justification = Just;
	NewText.VertAlign = VAlign;
	*/
	return NewText;
}

UMaterialInstance* AUT2LoadingPageBase::DLOTexture(FString TextureFullName)
{
	//return Cast<UMaterialInstance>(DynamicLoadObject(TextureFullName, Class'Material'));
	return nullptr;
}
