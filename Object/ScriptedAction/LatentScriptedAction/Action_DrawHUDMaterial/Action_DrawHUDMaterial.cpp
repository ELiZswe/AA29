// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_DrawHUDMaterial/Action_DrawHUDMaterial.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_DrawHUDMaterial::UAction_DrawHUDMaterial()
{
	PosX = 0.4;
	PosY = 0.4;
	Width = 0.2;
	Height = 0.2;
	DisplayTime = 1;
	ActionString = "draw HUD texture";
}

bool UAction_DrawHUDMaterial::InitActionFor(AScriptedController* C)
{
	/*
	APlayerController* PC = nullptr;
	PC = C.Level.GetLocalPlayerController();
	if (PC == nullptr)
	{
		Warn("No local player!");
		return false;
	}
	if (PC.myHUD == nullptr)
	{
		Warn("Local player has no HUD!");
		return false;
	}
	Overlay = C.Spawn('ScriptedHudOverlay', PC);
	Overlay.HUDMaterial = HUDMaterial;
	Overlay.PosX = PosX;
	Overlay.PosY = PosY;
	Overlay.Width = Width;
	Overlay.Height = Height;
	PC.myHUD.AddHudOverlay(Overlay);
	C.CurrentAction = this;
	C.SetTimer(DisplayTime, false);
	*/
	return true;
}
void UAction_DrawHUDMaterial::ActionCompleted()
{
	//Overlay.Destroy();
}
bool UAction_DrawHUDMaterial::CompleteWhenTriggered()
{
	return true;
}
bool UAction_DrawHUDMaterial::CompleteWhenTimer()
{
	return true;
}
