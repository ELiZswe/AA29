// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminGroupList.generated.h"

class UxAdminGroup;

UCLASS()
class AA29_API UxAdminGroupList : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminGroupList();

	UPROPERTY()										TArray<UxAdminGroup*> Groups;					//var array<xAdminGroup> Groups;

	void Count();
	void CreateGroup(FString GroupName, FString Privileges, uint8 GameSecLevel);
	void Add(UxAdminGroup* Group);
	void Remove(UxAdminGroup* Group);
	void Get(int32 Index);
	void FindByName(FString GroupName);
	bool Contains(UxAdminGroup* Group);
	void FindMasterGroup();
	void Clear();
};
