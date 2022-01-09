// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminGroupList.generated.h"

class UxAdminGroup;

UCLASS()
class UxAdminGroupList : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminGroupList();

	UPROPERTY()										TArray<UxAdminGroup*> Groups;					//var array<xAdminGroup> Groups;

	int32 Count();
	UxAdminGroup* CreateGroup(FString GroupName, FString Privileges, uint8 GameSecLevel);
	void Add(UxAdminGroup* Group);
	void Remove(UxAdminGroup* Group);
	UxAdminGroup* Get(int32 Index);
	UxAdminGroup* FindByName(FString GroupName);
	bool Contains(UxAdminGroup* Group);
	UxAdminGroup* FindMasterGroup();
	void Clear();
};
