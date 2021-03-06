// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplayColor/UITextDisplayColor.h"

UUITextDisplayColor::UUITextDisplayColor()
{

}

void UUITextDisplayColor::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	FColor OldColor = FColor(0,0,0,0);
	if (_bLabelChanged)
	{
		ScaleControl(Canvas);
	}
	if (!_bEnabled)
	{
		return;
	}
	//temp_font = Canvas.Font;
	//Canvas.Font = cFrame->GetLargeFont();
	//OldColor = Canvas.DrawColor;
	//Canvas.DrawColor = _cColor;
	//Canvas.SetPos(_iLabelX, _iLabelY);
	//Canvas.DrawText(_sLabel);
	//Canvas.DrawColor = OldColor;
	//Canvas.Font = temp_font;
}

void UUITextDisplayColor::SetColor(FColor cColor)
{
	_cColor = cColor;
}
