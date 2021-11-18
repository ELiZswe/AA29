// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "VehicleMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVehicleMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	AVehicleMessage();

	UPROPERTY()												FColor YellowColor;								//var Object.Color YellowColor;
	UPROPERTY()												FColor RedColor;								//var Object.Color RedColor;
	UPROPERTY()												USoundBase* VictorySound;						//var Sound VictorySound;
	UPROPERTY()												TArray<FString> MessageAnnouncements;			//var name MessageAnnouncements;
	UPROPERTY(EditAnywhere, Category = "Message")			FString SPMAAcquiredString;						//var(Message) localized string SPMAAcquiredString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString MoveReticle;							//var(Message) localized string MoveReticle;
	UPROPERTY(EditAnywhere, Category = "Message")			FString CameraDeploy;							//var(Message) localized string CameraDeploy;
	UPROPERTY(EditAnywhere, Category = "Message")			FString AvrilLockOnString;						//var(Message) localized string AvrilLockOnString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString UnhealablePowerCoreString;				//var(Message) localized string UnhealablePowerCoreString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString PowerCoresAreDrainingString;			//var(Message) localized string PowerCoresAreDrainingString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerNodeSeveredString;				//var(Message) localized string BluePowerNodeSeveredString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerNodeSeveredString;				//var(Message) localized string RedPowerNodeSeveredString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerCoreDamagedString;				//var(Message) localized string BluePowerCoreDamagedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerCoreDamagedString;				//var(Message) localized string RedPowerCoreDamagedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerNodeUnderConstructionString;	//var(Message) localized string BluePowerNodeUnderConstructionString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerNodeUnderConstructionString;	//var(Message) localized string RedPowerNodeUnderConstructionString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerCoreVulnerableString;			//var(Message) localized string BluePowerCoreVulnerableString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerCoreVulnerableString;			//var(Message) localized string RedPowerCoreVulnerableString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString PressUseToTeleportString;				//var(Message) localized string PressUseToTeleportString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerCoreCriticalString;			//var(Message) localized string BluePowerCoreCriticalString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerCoreCriticalString;				//var(Message) localized string RedPowerCoreCriticalString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerNodeDestroyedString;			//var(Message) localized string BluePowerNodeDestroyedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerNodeDestroyedString;			//var(Message) localized string RedPowerNodeDestroyedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerCoreDestroyedString;			//var(Message) localized string BluePowerCoreDestroyedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerCoreDestroyedString;			//var(Message) localized string RedPowerCoreDestroyedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString UnpoweredString;						//var(Message) localized string UnpoweredString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString MissileLockOnString;					//var(Message) localized string MissileLockOnString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString InWayOfVehicleSpawnString;				//var(Message) localized string InWayOfVehicleSpawnString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerNodeAttackedString;			//var(Message) localized string BluePowerNodeAttackedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerNodeAttackedString;				//var(Message) localized string RedPowerNodeAttackedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BluePowerCoreAttackedString;			//var(Message) localized string BluePowerCoreAttackedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedPowerCoreAttackedString;				//var(Message) localized string RedPowerCoreAttackedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString UnattainableNodeString;					//var(Message) localized string UnattainableNodeString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString InvincibleCoreString;					//var(Message) localized string InvincibleCoreString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString VehicleLockedString;					//var(Message) localized string VehicleLockedString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BlueTeamPowerCoreString;				//var(Message) localized string BlueTeamPowerCoreString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedTeamPowerCoreString;					//var(Message) localized string RedTeamPowerCoreString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BlueTeamDominatesString;				//var(Message) localized string BlueTeamDominatesString;
	UPROPERTY(EditAnywhere, Category = "Message")			FString RedTeamDominatesString;					//var(Message) localized string RedTeamDominatesString;

	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetColor(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2);
	void GetPos(int32 Switch, EDrawPivot &OutDrawPivot, EStackMode &OutStackMode, float &OutPosX, float &OutPosY);
	void GetLifeTime(int32 Switch);
	void IsConsoleMessage(int32 Switch);


};

