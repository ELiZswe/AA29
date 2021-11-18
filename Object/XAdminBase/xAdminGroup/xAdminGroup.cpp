// All the original content belonged to the US Army


#include "AA29/Object/XAdminBase/xAdminGroup/xAdminGroup.h"

UxAdminGroup::UxAdminGroup()
{

}

void UxAdminGroup::Created()
{
	/*
	Users = new (None) class'xAdminUserList';
	Managers = new (None) class'xAdminUserList';
	*/
}
void UxAdminGroup::Init(FString sGroupName, FString sPrivileges, uint8 nGameSecLevel)
{
	/*
	GroupName = sGroupName;
	Privileges = sPrivileges;
	GameSecLevel = nGameSecLevel;
	if (GroupName == "Admin")
	{
		bMasterAdmin = true;
	}
	*/
}
void UxAdminGroup::SetPrivs(FString privs)
{
	/*
	local int i;
	Privileges = privs;
	for (i = 0; i < Users.Count(); i++)
	{
		Users.Get(i).RedoMergedPrivs();
	}
	*/
}
void UxAdminGroup::ValidName(FString uname)
{
	/*
	local int i;
	if (Len(uname) < 5)
	{
		Return False;
	}
	for (i = 0; i < Len(uname); i++)
	{
		if (InStr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJMLMNOPQRSTUVWXYZ0123456789!%^*(){}[]<>.,", Mid(uname, i, 1)) == -1)
		{
			Return False;
		}
	}
	Return True;
	*/
}
void UxAdminGroup::UnlinkUsers()
{
	/*
	local int i;
	for (i = 0; i < Users.Count(); i++)
	{
		Users.Get(i).RemoveGroup(Self);
	}
	for (i = 0; i < Managers.Count(); i++)
	{
		Managers.Get(i).RemoveManagedGroup(Self);
	}
	*/
}
void UxAdminGroup::RemoveUser(UxAdminUser* User)
{
	/*
	if (User != None)
	{
		if (Users.Contains(User))
		{
			Users.Remove(User);
		}
		if (Managers.Contains(User))
		{
			Managers.Remove(User);
		}
	}
	*/
}
void UxAdminGroup::HasPrivilege(FString priv)
{
	//Return bMasterAdmin || InStr("|" $ Privileges $ "|", "|" $ priv $ "|") != -1 || InStr("|" $ Left(Privileges, 1) $ "|", "|" $ priv $ "|") != -1;
}
