// All the original content belonged to the US Army

/* =================================================================================== *
* aafa class AmmoRound_3P_Javelin
* Author: mwd
* =================================================================================== *
*	This third person ammo round for the Javelin.
*   Copied from AmmoRound_3P_RPG7_Rocket and modified.
* =================================================================================== */

#include "AmmoRound_3P_Javelin.h"

AAmmoRound_3P_Javelin::AAmmoRound_3P_Javelin()
{
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PLoaded.Tube3PLoaded"), NULL, LOAD_None, NULL);
	DrawScale   = 1.13;
}


void AAmmoRound_3P_Javelin::ShowRound(bool bShouldShowRound)
{
}