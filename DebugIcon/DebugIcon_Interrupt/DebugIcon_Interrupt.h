// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DebugIcon/DebugIcon.h"
#include "DebugIcon_Interrupt.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADebugIcon_Interrupt : public ADebugIcon
{
	GENERATED_BODY()
public:
	ADebugIcon_Interrupt();

	UPROPERTY()				UMaterialInstance* Interrupt_See_Vehicle_Tex;								//var Texture Interrupt_See_Vehicle_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_See_Enemy_Tex;									//var Texture Interrupt_See_Enemy_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_See_Grenade_Tex;								//var Texture Interrupt_See_Grenade_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Kill_Enemy_Tex;								//var Texture Interrupt_Kill_Enemy_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Injured_Tex;									//var Texture Interrupt_Injured_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Hear_Movement_Tex;								//var Texture Interrupt_Hear_Movement_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Hear_Gunfire_Tex;								//var Texture Interrupt_Hear_Gunfire_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Friendly_Die_Tex;								//var Texture Interrupt_Friendly_Die_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Enemy_Lost_Tex;								//var Texture Interrupt_Enemy_Lost_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Bullet_Whip_Tex;								//var Texture Interrupt_Bullet_Whip_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Ammo_Jam_Tex;									//var Texture Interrupt_Ammo_Jam_Tex;
	UPROPERTY()				UMaterialInstance* Interrupt_Action_Complete_Tex;							//var Texture Interrupt_Action_Complete_Tex;

	void UpdateAction(FString NewAction);
};
