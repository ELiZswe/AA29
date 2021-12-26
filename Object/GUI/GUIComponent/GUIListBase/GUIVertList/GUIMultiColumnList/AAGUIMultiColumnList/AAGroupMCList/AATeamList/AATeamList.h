// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AAGroupMCList.h"
#include "AATeamList.generated.h"

class AAGP_TeamInfo;
class ATeamInfo;
class AAGP_PlayerStart;

UCLASS()
class UAATeamList : public UAAGroupMCList
{
	GENERATED_BODY()
public:
	UAATeamList();

	UPROPERTY()						TArray<UMaterialInstance*> tFT;							//var() array<Texture> tFT;
	UPROPERTY()						AAGP_TeamInfo* Team;									//var AGP_Gameplay.AGP_TeamInfo Team;
	UPROPERTY()						UMaterialInstance* Invalid;								//var Material Invalid;
	UPROPERTY()						TArray<FString> GroupDescriptions;						//var array<String> GroupDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> Group;						//var array<Material> Group;
	UPROPERTY()						TArray<FString> GuerrillaDescriptions;					//var array<String> GuerrillaDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> Guerrilla;					//var array<Material> Guerrilla;
	UPROPERTY()						TArray<FString> ExtraSpecialForcesDescriptions;			//var array<String> ExtraSpecialForcesDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> ExtraSpecialForces;			//var array<Material> ExtraSpecialForces;
	UPROPERTY()						TArray<FString> SpecialForcesDescriptions;				//var array<String> SpecialForcesDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> SpecialForces;				//var array<Material> SpecialForces;
	UPROPERTY()						TArray<FString> SubClassDescriptions;					//var array<String> SubClassDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> SubClass;					//var array<Material> SubClass;
	UPROPERTY()						TArray<FString> ClassDescriptions;						//var array<String> ClassDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> Class;						//var array<Material> Class;
	UPROPERTY()						TArray<FString> RankDescriptions;						//var array<String> RankDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> rank;						//var array<Material> rank;
	UPROPERTY()						TArray<FString> IconDescriptions;						//var() localized array<String> IconDescriptions;
	UPROPERTY()						TArray<UMaterialInstance*> Icons;						//var() array<Material> Icons;
	UPROPERTY()						bool bScores;											//var bool bScores;

	void SetTeam(ATeamInfo* TI);
	UMaterialInstance* GetGroupIcon(AAA2_PlayerState* PRI);
	UMaterialInstance* GetSubClassIcon(AAA2_PlayerState* PRI);
	UMaterialInstance* GetRankIcon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetSFIcon(AAGP_PlayerStart* PS);
	uint8 GetNativeWeapon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetClassIcon(AAGP_PlayerStart* PS);
	UMaterialInstance* GetIcon(UMaterialInstance* M, AAGP_PlayerStart* PS);
	UMaterialInstance* MaybeGray(UMaterialInstance* M);
	UMaterialInstance* GetGray(UMaterialInstance* M);
	AAGP_PlayerStart* GetPlayerStart(AAA2_PlayerState* PlayerItem);
	AAA2_PlayerState* GetPlayerAtIndex(int32 Index);
	FString GetPlayerName(AAA2_PlayerState* PRI);
	uint8 GetPlayerState(AAA2_PlayerState* PRI);
	bool IsEnabled();
	bool IsPSEnabled(AAGP_PlayerStart* PS);
	bool IsQualified(AAGP_PlayerStart* PS, AAA2_PlayerState* PRI);
	bool IsSFQualified(AAA2_PlayerState* PRI);
	bool IsSniperQualified(AAA2_PlayerState* PRI);
	bool IsJavelinQualified(AAA2_PlayerState* PRI);
	bool IsAdmin(AAA2_PlayerState* PRI);
	int32 GetGroup(int32 Index);
	int32 GetPositionInGroup(int32 Group, int32 Index);
};
