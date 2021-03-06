// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPointObj/UIHUDCompassPointObj.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"

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
	_TrackingActor = obj;
}

FVector UUIHUDCompassPointObj::GetLocation()
{
	return _Objective->GetCompassLocation();
}

bool UUIHUDCompassPointObj::IsOnCompass(AController* ctrlRequesting)
{
	return _Objective->IsOnCompass(ctrlRequesting);
}

bool UUIHUDCompassPointObj::IsEnabled()
{
	return _Objective->IsEnabled();
}

bool UUIHUDCompassPointObj::IsSquadTarget(int32 iTeamIndex)
{
	return _Objective->IsSquadTarget(iTeamIndex);
}

FString UUIHUDCompassPointObj::GetString()
{
	/*
	FString retval;
	retval = _Objective.GetDescriptionByController(cFrame->cHUD.PlayerOwner);
	if (retval == "")
	{
		return "";
	}
	if (isPriority())
	{
		return "*" + _sSymbol + ": " + retval;
	}
	else
	{
		return " " + _sSymbol + ": " + retval;
	}
	*/
	return "";     //FAKE   /ELiZ
}

bool UUIHUDCompassPointObj::isPriority()
{
	return _Objective->IsInstantWin();
}

void UUIHUDCompassPointObj::SetText(FString txt)
{
	_sSymbol = txt;
}
