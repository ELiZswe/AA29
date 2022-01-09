// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminGroup.generated.h"

class UxAdminUserList;
class UxAdminUser;

UCLASS()
class UxAdminGroup : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminGroup();

	UPROPERTY()				bool						bMasterAdmin;		//var bool bMasterAdmin;
	UPROPERTY()				TArray<UxAdminUserList*>	Managers;			//var xAdminUserList Managers;
	UPROPERTY()				TArray<UxAdminUserList*>	Users;				//var xAdminUserList Users;
	UPROPERTY()				uint8						GameSecLevel;		//var byte GameSecLevel;
	UPROPERTY()				FString						Privileges;			//var string Privileges;
	UPROPERTY()				FString						GroupName;			//var string GroupName;

	void Created();
	void Init(FString sGroupName, FString sPrivileges, uint8 nGameSecLevel);
	void SetPrivs(FString privs);
	bool ValidName(FString uname);
	void UnlinkUsers();
	void RemoveUser(UxAdminUser* User);
	bool HasPrivilege(FString priv);
};
