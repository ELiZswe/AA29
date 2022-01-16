// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AAGame_ListBase.generated.h"

class AAGP_PlayerStart;

UCLASS()
class UAAGame_ListBase : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UAAGame_ListBase();

	UPROPERTY()			UMaterialInstance*			Invalid;						//var Material Invalid;
	UPROPERTY()			TArray<FString>				GroupDescriptions;				//var TArray<FString> GroupDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	Group;							//var array<Material> Group;
	UPROPERTY()			TArray<FString>				GuerrillaDescriptions;			//var TArray<FString> GuerrillaDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	Guerrilla;						//var array<Material> Guerrilla;
	UPROPERTY()			TArray<FString>				SpecialForcesDescriptions;		//var TArray<FString> SpecialForcesDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	SpecialForces;					//var array<Material> SpecialForces;
	UPROPERTY()			TArray<FString>				SubClassDescriptions;			//var TArray<FString> SubClassDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	SubClass;						//var array<Material> SubClass;
	UPROPERTY()			TArray<FString>				ClassDescriptions;				//var TArray<FString> ClassDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	Class;							//var array<Material> Class;
	UPROPERTY()			TArray<FString>				RankDescriptions;				//var TArray<FString> RankDescriptions;
	UPROPERTY()			TArray<UMaterialInstance*>	rank;							//var array<Material> rank;

	bool IsEnabled();
	UMaterialInstance* MaybeGray(UMaterialInstance* M);
	UMaterialInstance* GetGray(UMaterialInstance* M);
	uint8 GetNativeWeapon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetGroupIcon(AAA2_PlayerState* PRI);
	UMaterialInstance* GetSubClassIcon(AAA2_PlayerState* PRI);
	UMaterialInstance* GetRankIcon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetSFIcon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetClassIcon(AAGP_PlayerStart* PS);
	FString GetPlayerName(AAA2_PlayerState* PRI);
	uint8 GetPlayerState(AAA2_PlayerState* PRI);
}; 
