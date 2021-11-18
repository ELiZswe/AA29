// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"

UUIScrollbar::UUIScrollbar()
{
	_iThumbSize = 30;
}


void UUIScrollbar::Destroyed()
{
	Super::Destroyed();
	_ThumbTex = nullptr;
	_BackTex = nullptr;
}
void UUIScrollbar::MouseMove(int32 mX, int32 mY)
{
}
bool UUIScrollbar::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUIScrollbar::SizeThumb(float percentage)
{
}
void UUIScrollbar::Draw(UCanvas* Canvas)
{
}
void UUIScrollbar::SetImageDimensions(int32 imgW, int32 imgH)
{
	_iImageWidth = imgW;
	_iImageHeight = imgH;
}
void UUIScrollbar::SetThumbTexture(UMaterialInstance* Tex)
{
	_ThumbTex = Tex;
}
void UUIScrollbar::SetBackTexture(UMaterialInstance* Tex)
{
	_BackTex = Tex;
}


