// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPointObj/UIHUDCompassPointObj.h"

UUIHUDCompassPointObj::UUIHUDCompassPointObj()
{

}

void UUIHUDCompassPointObj::Destroyed()
{
	Super::Destroyed();
	_Objective = nullptr;
}
void UUIHUDCompassPointObj::setObjective(ABaseObjective* obj)
{
	_Objective = obj;
	//_TrackingActor = obj;
}
void UUIHUDCompassPointObj::GetLocation()
{
	//Return _Objective.GetCompassLocation();
}
void UUIHUDCompassPointObj::IsOnCompass(AController* ctrlRequesting)
{
	//Return _Objective.IsOnCompass(ctrlRequesting);
}
void UUIHUDCompassPointObj::IsEnabled()
{
	//Return _Objective.IsEnabled();
}
void UUIHUDCompassPointObj::IsSquadTarget(int32 iTeamIndex)
{
	//Return _Objective.IsSquadTarget(iTeamIndex);
}
FString UUIHUDCompassPointObj::GetString()
{
	/*
	local string retval;
	retval = _Objective.GetDescriptionByController(cFrame.cHUD.PlayerOwner);
	if (retval == "")
	{
		Return "";
	}
	if (isPriority())
	{
		Return "*" $ _sSymbol $ ": " $ retval;
	}
	else
	{
		Return " " $ _sSymbol $ ": " $ retval;
	}
	*/
	return "";     //FAKE   /ELiZ
}
void UUIHUDCompassPointObj::isPriority()
{
	//Return _Objective.IsInstantWin();
}
void UUIHUDCompassPointObj::SetText(FString txt)
{
	//_sSymbol = txt;
}