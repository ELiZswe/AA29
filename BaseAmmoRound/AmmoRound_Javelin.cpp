// All the original content belonged to the US Army


#include "AmmoRound_Javelin.h"

AAmmoRound_Javelin::AAmmoRound_Javelin()
{
	DrawType    = EDrawType::DT_None;
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PLoaded.Tube3PLoaded"), NULL, LOAD_None, NULL);
}