// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminUserList.generated.h"

class UxAdminUser;
UCLASS()
class UxAdminUserList : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminUserList();
	
	UPROPERTY()										TArray<UxAdminUser*> Users;					//var array<xAdminUser> Users;

	int32 Count();
	UxAdminUser* Create(FString UserName, FString Password, FString Privileges);
	void Add(UxAdminUser* NewUser);
	UxAdminUser* Get(int32 i);
	void Remove(UxAdminUser* User);
	void Clear();
	bool Contains(UxAdminUser* User);
	UxAdminUser* FindByName(FString UserName);
};
