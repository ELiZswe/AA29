// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterList.h"
#include "GUICharacterListTeam.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUICharacterListTeam : public UGUICharacterList
{
	GENERATED_BODY()
public:
	UGUICharacterListTeam();

	void InitList();
	void InitListInclusive(FString S);
	void InitListIncl(TArray<FString> menus, FString Race);
	void InitListExclusive(FString S, FString s2);
	void InitListExcl(TArray<FString> menus, FString Race);
	void PopulateList(TArray<FString> PlayerNames);

};
