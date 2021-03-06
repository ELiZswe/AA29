// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UISoundControl.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/Sound/Sound.h"

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
		//_sMouseOver = Sound(DynamicLoadObject(_sOverSound, USound::StaticClass()));
	}
	if (_sClickSound != "")
	{
		//_sMouseClick = Sound(DynamicLoadObject(_sClickSound, USound::StaticClass()));
	}
}
