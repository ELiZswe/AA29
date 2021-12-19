// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminUser.generated.h"

class UxAdminGroupList;
class UxAdminGroup;
class UxAdminUserList;

UCLASS()
class AA29_API UxAdminUser : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminUser();

	UPROPERTY()				bool				bMasterAdmin;		//var bool bMasterAdmin;
	UPROPERTY()				UxAdminGroupList*	ManagedGroups;		//var xAdminGroupList ManagedGroups;
	UPROPERTY()				UxAdminGroupList*	Groups;				//var xAdminGroupList Groups;
	UPROPERTY()				FString				MergedPrivs;		//var string MergedPrivs;
	UPROPERTY()				FString				Privileges;			//var string Privileges;
	UPROPERTY()				FString				Password;			//var string Password;
	UPROPERTY()				FString				UserName;			//var string UserName;

	void Created();
	void Init(FString uname, FString Pass, FString privs);
	void AddGroup(UxAdminGroup* Group);
	void RemoveGroup(UxAdminGroup* Group);
	void AddManagedGroup(UxAdminGroup* Group);
	void RemoveManagedGroup(UxAdminGroup* Group);
	void AddGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames);
	void AddManagedGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames);
	bool HasPrivilege(FString priv);
	void RedoMergedPrivs();
	void MergePrivs(FString newprivs);
	bool CanManageGroup(UxAdminGroup* Group);
	bool CanManageUser(UxAdminUser* User);
	bool ValidPass(FString upass);
	bool ValidName(FString uname);
	int32 MaxSecLevel();
	UxAdminGroup* GetGroup(FString GroupName);
	UxAdminGroup* GetManagedGroup(FString GroupName);
	UxAdminUserList* GetManagedUsers(UxAdminGroupList* uAllGroups);
	void UnlinkGroups();

};
