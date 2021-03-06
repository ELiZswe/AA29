// All the original content belonged to the US Army

#include "AA29/Object/XAdminBase/xAdminGroup/xAdminGroup.h"
#include "AA29/Object/XAdminBase/xAdminUser/xAdminUser.h"
#include "AA29/Object/XAdminBase/xAdminUserList/xAdminUserList.h"

UxAdminGroup::UxAdminGroup()
{

}

void UxAdminGroup::Created()
{
	Users = NewObject<UxAdminUserList>(UxAdminUserList::StaticClass());
	Managers = NewObject<UxAdminUserList>(UxAdminUserList::StaticClass());
}

void UxAdminGroup::Init(FString sGroupName, FString sPrivileges, uint8 nGameSecLevel)
{
	GroupName = sGroupName;
	Privileges = sPrivileges;
	GameSecLevel = nGameSecLevel;
	if (GroupName == "Admin")
	{
		bMasterAdmin = true;
	}
}

void UxAdminGroup::SetPrivs(FString privs)
{
	int32 i = 0;
	Privileges = privs;
	for (i = 0; i < Users->Count(); i++)
	{
		Users->Get(i)->RedoMergedPrivs();
	}
}

bool UxAdminGroup::ValidName(FString uname)
{
	int32 i = 0;
	if (uname.Len() < 5)
	{
		return false;
	}
	for (i = 0; i < uname.Len(); i++)
	{
		/*
		if (InStr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJMLMNOPQRSTUVWXYZ0123456789!%^*(){}[]<>.,", Mid(uname, i, 1)) == -1)
		{
			return false;
		}
		*/
	}
	return true;
}

void UxAdminGroup::UnlinkUsers()
{
	int32 i = 0;
	for (i = 0; i < Users->Count(); i++)
	{
		Users->Get(i)->RemoveGroup(this);
	}
	for (i = 0; i < Managers->Count(); i++)
	{
		Managers->Get(i)->RemoveManagedGroup(this);
	}
}
void UxAdminGroup::RemoveUser(UxAdminUser* User)
{
	if (User != nullptr)
	{
		if (Users->Contains(User))
		{
			Users->Remove(User);
		}
		if (Managers->Contains(User))
		{
			Managers->Remove(User);
		}
	}
}

bool UxAdminGroup::HasPrivilege(FString priv)
{
	//return bMasterAdmin || InStr("|" + Privileges + "|", "|" + priv + "|") != -1 || InStr("|" + Left(Privileges, 1) + "|", "|" + priv + "|") != -1;
	return false;    //FAKE   /ELiZ
}
