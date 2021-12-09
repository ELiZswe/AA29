// All the original content belonged to the US Army

/* =================================================================================== *
 * AGP class BaseAmmoRound
 * Author: cmb
 * =================================================================================== *
 *	This is a (linked-list) mesh of the first person ammo round. It gets attached to
 *	bones in the 1P weapon animation, and turned on/off when appropos based on the
 *	number of rounds currently in a clip.
 * =================================================================================== */


#include "BaseAmmoRound.h"

// Sets default values
ABaseAmmoRound::ABaseAmmoRound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ammo_id			= -1;
	DrawType		= EDrawType::DT_StaticMesh;
	//bOnlyOwnerSee = true;
}

// Called when the game starts or when spawned
void ABaseAmmoRound::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAmmoRound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/* =================================================================================== *
 * AGP function AdjustAmmoRound()
 *	Given a total ammount of ammo, turn this one off if this one should not be
 *	displayed, then call for the next one on the list. Make the round in the
 *  breech appear and disappear based on the anim notify
 *
 * input:	total_ammo	- The total amount of ammo
 * last modified by: Ramm - 08/22/03
 * =================================================================================== */
void ABaseAmmoRound::AdjustAmmoRound()
{

}
/* =================================================================================== *
* AGP function AdjustSpecialAmmoRounds()
*	Make the special ammo round appear and disappear based on the animation notify.
*
* input:	bRender	- whether or not to render the ammo round
* last modified by: Ramm - 08/22/03
* =================================================================================== */
void ABaseAmmoRound::AdjustSpecialAmmoRounds()
{

}

/************************/
/*	GETTERS/SETTERS		*/
/************************/
void ABaseAmmoRound::SetAmmoID()
{

}

void ABaseAmmoRound::GetBoneName()
{

}

