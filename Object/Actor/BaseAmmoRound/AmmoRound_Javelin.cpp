// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Javelin.h"

AAmmoRound_Javelin::AAmmoRound_Javelin()
{
	//DrawType    = EDrawType::DT_None;
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PLoaded.Tube3PLoaded'"), NULL, LOAD_None, NULL);
}

void AAmmoRound_Javelin::AdjustAmmoRound(int32 total_ammo)
{
}
