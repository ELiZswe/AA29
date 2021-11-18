// All the original content belonged to the US Army


#include "AA29/Object/XAdminBase/xAdminUser/xAdminUser.h"

UxAdminUser::UxAdminUser()
{

}

void UxAdminUser::Created()
{
	/*
	Groups = new (None) class'xAdminGroupList';
	ManagedGroups = new (None) class'xAdminGroupList';*/
}
void UxAdminUser::Init(FString uname, FString Pass, FString privs)
{
	UserName = uname;
	Password = Pass;
	Privileges = privs;
	MergedPrivs = privs;
}
void UxAdminUser::AddGroup(UxAdminGroup* Group)
{
	/*
	if (Group != None)
	{
		if (!Groups.Contains(Group))
		{
			Groups.Add(Group);
		}
		if (!Group.Users.Contains(Self))
		{
			Group.Users.Add(Self);
		}
		if (Group.bMasterAdmin)
		{
			bMasterAdmin = true;
		}
		else
		{
			MergePrivs(Group.Privileges);
		}
	}
	*/
}
void UxAdminUser::RemoveGroup(UxAdminGroup* Group)
{
	/*
	if (Group != None && Groups.Contains(Group))
	{
		Group.Users.Remove(Self);
		Groups.Remove(Group);
		RedoMergedPrivs();
	}
	*/
}
void UxAdminUser::AddManagedGroup(UxAdminGroup* Group)
{
	/*
	if (Group != None)
	{
		if (!ManagedGroups.Contains(Group))
		{
			ManagedGroups.Add(Group);
		}
		if (!Group.Managers.Contains(Self))
		{
			Group.Managers.Add(Self);
		}
	}
	*/
}
void UxAdminUser::RemoveManagedGroup(UxAdminGroup* Group)
{
	/*
	if (Group != None && ManagedGroups.Contains(Group))
	{
		Group.Managers.Remove(Self);
		ManagedGroups.Remove(Group);
	}
	*/
}
void UxAdminUser::AddGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames)
{
	/*
	local int i;
	for (i = 0; i < aGroupNames.Length; i++)
	{
		AddGroup(lGroups.FindByName(aGroupNames[i]));
	}
	*/
}
void UxAdminUser::AddManagedGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames)
{
	/*
	local int i;
	for (i = 0; i < aGroupNames.Length; i++)
	{
		AddManagedGroup(lGroups.FindByName(aGroupNames[i]));
	}
	*/
}
void UxAdminUser::HasPrivilege(FString priv)
{
	//Return bMasterAdmin || InStr("|" $ MergedPrivs $ "|", "|" $ priv $ "|") != -1 || InStr("|" $ MergedPrivs $ "|", "|" $ Left(priv, 1) $ "|") != -1;
}
void UxAdminUser::RedoMergedPrivs()
{
	/*
	local int i;
	bMasterAdmin = False;
	i = 0;
	if (i < Groups.Count())
	{
		if (Groups.Get(i).bMasterAdmin)
		{
			bMasterAdmin = true;
		}
		else
		{
			i++;
		}
	}
	if (bMasterAdmin)
	{
		MergedPrivs = "";
	}
	else
	{
		MergedPrivs = Privileges;
		for (i = 0; i < Groups.Count(); i++)
		{
			MergePrivs(Groups.Get(i).Privileges);
		}
	}
	*/
}
void UxAdminUser::MergePrivs(FString newprivs)
{
	/*
	local string priv;
	local int pos;
	if (newprivs != "")
	{
		pos = InStr(newprivs, "|");
		if (pos == -1)
		{
			priv = newprivs;
			newprivs = "";
		}
		else
		{
			priv = Left(newprivs, pos);
			newprivs = Mid(newprivs, pos + 1);
		}
		pos = InStr("|" $ MergedPrivs $ "|", "|" $ priv $ "|");
		if (pos == -1)
		{
			if (MergedPrivs == "")
			{
				MergedPrivs = priv;
			}
			else
			{
				MergedPrivs = MergedPrivs $ "|" $ priv;
			}
		}
	}
	*/
}
void UxAdminUser::CanManageGroup(UxAdminGroup* Group)
{
	//Return bMasterAdmin || ManagedGroups.Contains(Group);
}
bool UxAdminUser::CanManageUser(UxAdminUser* User)
{
	/*
	local int i;
	if (bMasterAdmin)
	{
		Return True;
	}
	for (i = 0; i < ManagedGroups.Count(); i++)
	{
		if (ManagedGroups.Get(i).Users.Contains(User))
		{
			Return True;
		}
	}
	*/
	return false;
}
bool UxAdminUser::ValidPass(FString upass)
{
	/*
	local int i;
	if (Len(upass) < 6)
	{
		Return False;
	}
	for (i = 0; i < Len(upass); i++)
	{
		if (InStr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJMLMNOPQRSTUVWXYZ0123456789!%^*(){}[]<>.,", Mid(upass, i, 1)) == -1)
		{
			Return False;
		}
	}
	*/
	return true;
}
void UxAdminUser::ValidName(FString uname)
{
	/*
	local int i;
	if (Len(uname) < 1)
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
void UxAdminUser::MaxSecLevel()
{
	/*
	local int i;
	local int M;
	if (bMasterAdmin)
	{
		Return 255;
	}
	M = 0;
	for (i = 0; i < Groups.Count(); i++)
	{
		if (Groups.Get(i).GameSecLevel > M)
		{
			M = Groups.Get(i).GameSecLevel;
		}
	}
	Return M;
	*/
}
void UxAdminUser::GetGroup(FString GroupName)
{
	//Return Groups.FindByName(GroupName);
}
void UxAdminUser::GetManagedGroup(FString GroupName)
{
	//Return ManagedGroups.FindByName(GroupName);
}
void UxAdminUser::GetManagedUsers(UxAdminGroupList* uAllGroups)
{
	/*
	local xAdminUserList retList;
	local xAdminUserList uList;
	local xAdminGroupList uGroups;
	local int i;
	local int j;
	retList = new (None) class'xAdminUserList';
	if (bMasterAdmin)
	{
		uGroups = uAllGroups;
	}
	else
	{
		uGroups = ManagedGroups;
	}
	for (i = 0; i < uGroups.Count(); i++)
	{
		uList = uGroups.Get(i).Users;
		for (j = 0; j < uList.Count(); j++)
		{
			retList.Add(uList.Get(j));
		}
	}
	Return retList;
	*/
}
void UxAdminUser::UnlinkGroups()
{
	/*
	local int i;
	for (i = 0; i < Groups.Count(); i++)
	{
		Groups.Get(i).RemoveUser(Self);
	}
	for (i = 0; i < ManagedGroups.Count(); i++)
	{
		ManagedGroups.Get(i).RemoveUser(Self);
	}
	*/
}
