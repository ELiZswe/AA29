// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDRoleInfo/HUDRoleInfo.h"

UHUDRoleInfo::UHUDRoleInfo()
{

}

void UHUDRoleInfo::Destroyed()
{
	Super::Destroyed();
	_roleTexture = nullptr;
}
void UHUDRoleInfo::Draw(UCanvas* Canvas)
{
}