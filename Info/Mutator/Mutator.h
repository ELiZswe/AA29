// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "Mutator.generated.h"

class AWeapon;
class AVehicle;
class AaAIController;
class AInventory;
class UPlayInfo;

UCLASS()
class AA29_API AMutator : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMutator();

	UPROPERTY()			AMutator* NextMutator;							//var Mutator NextMutator;
	UPROPERTY()			AWeapon* DefaultWeapon;							//var class<Weapon> DefaultWeapon;
	UPROPERTY()			FString DefaultWeaponName;						//var FString DefaultWeaponName;
	UPROPERTY()			bool bUserAdded;								//var bool bUserAdded;
	UPROPERTY()			bool bAddToServerPackages;						//var bool bAddToServerPackages;
	UPROPERTY()			FString IconMaterialName;						//var() cache FString IconMaterialName;
	UPROPERTY()			FString ConfigMenuClassName;					//var() cache FString ConfigMenuClassName;
	UPROPERTY()			FString GroupName;								//var() cache FString GroupName;
	UPROPERTY()			FString FriendlyName;							//var() localized cache FString FriendlyName;
	UPROPERTY()			FString Description;							//var() localized cache FString Description;

	void PreBeginPlay();
	bool MutatorIsAllowed();
	void Destroyed();
	void Mutate(FString MutateString, APlayerController* Sender);
	void ModifyLogin(FString& Portal, FString& Options);
	void NotifyLogout(AController* Exiting);
	void ModifyPlayer(APawn* Other);
	AWeapon* GetDefaultWeapon();
	AInventory* GetInventoryClass(FString InventoryClassName);
	FString GetInventoryClassOverride(FString InventoryClassName);
	AWeapon* MyDefaultWeapon();
	void AddMutator(AMutator* M);
	FString RecommendCombo(FString ComboName);
	FString NewRecommendCombo(FString ComboName, AaAIController* C);
	bool ReplaceWith(AActor* Other, FString aClassName);
	bool AlwaysKeep(AActor* Other);
	bool IsRelevant(AActor* Other, uint8& bSuperRelevant);
	bool CheckRelevance(AActor* Other);
	bool CheckReplacement(AActor* Other, uint8& bSuperRelevant);
	void PlayerChangedClass(AController* aPlayer);
	void GetServerDetails(FServerResponseLine& ServerState);
	void GetServerPlayers(FServerResponseLine& ServerState);
	FString ParseChatPercVar(AController* Who, FString Cmd);
	void MutatorFillPlayInfo(UPlayInfo* PlayInfo);
	bool OverrideDownload(FString PlayerIP, FString PlayerID, FString PlayerURL, FString& RedirectURL);
	void ServerTraveling(FString URL, bool bItems);
	bool CanEnterVehicle(AVehicle* V, APawn* p);
	void DriverEnteredVehicle(AVehicle* V, APawn* p);
	bool CanLeaveVehicle(AVehicle* V, APawn* p);
	void DriverLeftVehicle(AVehicle* V, APawn* p);
};
