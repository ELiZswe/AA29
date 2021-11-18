// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIContainer/UIContainer.h"

UUIContainer::UUIContainer()
{

}


void UUIContainer::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIContainer::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(sBitmapName, Class'Texture'));
	}
}
bool UUIContainer::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUIContainer::Draw(UCanvas* Canvas)
{
	if (_Texture != nullptr)
	{
		//Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		//Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	else
	{
		if (_bDebug)
		{
			//Canvas.DrawText("UIContainer - NO BITMAP " $ sBitmapName);
		}
	}
}