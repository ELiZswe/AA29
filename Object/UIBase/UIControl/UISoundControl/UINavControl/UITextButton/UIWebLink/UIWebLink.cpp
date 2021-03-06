// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UIWebLink/UIWebLink.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "Engine/Canvas.h"

UUIWebLink::UUIWebLink()
{

}

void UUIWebLink::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	int32 old_style = 0;
	FColor OldColor = FColor(0,0,0,0);
	if (!_bEnabled)
	{
		return;
	}
	//old_style = Canvas->Style;
	//Canvas->Style = ERenderStyle::STY_Normal;
	if (cFrame->_cMouseOver == this)
	{
		_iState = 1;
	}
	OldColor.R = Canvas->DrawColor.R;
	OldColor.G = Canvas->DrawColor.G;
	OldColor.B = Canvas->DrawColor.B;
	if (_iState == 1)
	{
		Canvas->SetDrawColor(255, 255, 255);
	}
	else
	{
		Canvas->SetDrawColor(196, 190, 141);
	}
	//temp_font = Canvas->Font;
	//Canvas->Font = cFrame->Fonts[6];
	//Canvas->SetPos(_iLabelX, _iLabelY);
	//Canvas->DrawText(_sLabel);
	//Canvas->Font = temp_font;
	Canvas->SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	//Canvas->Style = old_style;
}
