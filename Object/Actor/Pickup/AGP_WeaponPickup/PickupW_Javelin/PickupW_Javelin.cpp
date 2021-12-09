// All the original content belonged to the US Army


#include "PickupW_Javelin.h"
#include "AA29/Object/Actor/Inventory/Weapon\AGP_Weapon\RocketWeapon\WEAPON_Javelin\WEAPON_Javelin.h"

APickupW_Javelin::APickupW_Javelin()
{
	InventoryType			= AWEAPON_Javelin::StaticClass();
	PickupMessage			= FString("You found a Javelin.");
	EnemyPickupClass		= APickupW_Javelin::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/clu.clu"), NULL, LOAD_None, NULL));
	LandedRotationOffset	= FRotator(25.83984375, 0, 0);
	bShouldFallOnSide		= false;
	DrawScale				= 1.13;
}