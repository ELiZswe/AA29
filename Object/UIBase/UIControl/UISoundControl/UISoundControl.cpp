// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UISoundControl.h"

UUISoundControl::UUISoundControl()
{

}

void UUISoundControl::Destroyed()
{
	Super::Destroyed();
	_sMouseOver = nullptr;
	_sMouseClick = nullptr;
}
void UUISoundControl::Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams)
{
	Super::Create(frame, screen, pID, pUIEvent, pParams);
	LoadSounds();
}
void UUISoundControl::LoadSounds()
{
	if (_sOverSound != "")
	{
		//_sMouseOver = Sound(DynamicLoadObject(_sOverSound, Class'Sound'));
	}
	if (_sClickSound != "")
	{
		//_sMouseClick = Sound(DynamicLoadObject(_sClickSound, Class'Sound'));
	}
}