// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_NoBackground/STY_BindBox/STY_BindBox.h"

USTY_BindBox::USTY_BindBox()
{
	KeyName = "BindBox";
	FontColors[3] = FColor(0, 200, 230, 255);
	RStyles[0] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[1] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[2] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[3] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[4] = EMenuRenderStyle::MSTY_Alpha;
}
