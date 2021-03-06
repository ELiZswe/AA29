// All the original content belonged to the US Army

#include "AA29/Object/XAdminBase/xAdminUser/xAdminUser.h"
#include "AA29/Object/XAdminBase/xAdminGroup/xAdminGroup.h"
#include "AA29/Object/XAdminBase/xAdminGroupList/xAdminGroupList.h"
#include "AA29/Object/XAdminBase/xAdminUserList/xAdminUserList.h"

UxAdminUser::UxAdminUser()
{

}

void UxAdminUser::Created()
{
	Groups = NewObject<UxAdminGroupList>(UxAdminGroupList::StaticClass());
	ManagedGroups = NewObject<UxAdminGroupList>(UxAdminGroupList::StaticClass());
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
	if (Group != nullptr)
	{
		if (!Groups->Contains(Group))
		{
			Groups->Add(Group);
		}
		if (!Group->Users->Contains(this))
		{
			Group->Users->Add(this);
		}
		if (Group-bMasterAdmin)
		{
			bMasterAdmin = true;
		}
		else
		{
			MergePrivs(Group->Privileges);
		}
	}
}

void UxAdminUser::RemoveGroup(UxAdminGroup* Group)
{
	if (Group != nullptr && Groups->Contains(Group))
	{
		Group->Users->Remove(this);
		Groups->Remove(Group);
		RedoMergedPrivs();
	}
}

void UxAdminUser::AddManagedGroup(UxAdminGroup* Group)
{
	if (Group != nullptr)
	{
		if (!ManagedGroups->Contains(Group))
		{
			ManagedGroups->Add(Group);
		}
		if (!Group->Managers->Contains(this))
		{
			Group->Managers->Add(this);
		}
	}
}

void UxAdminUser::RemoveManagedGroup(UxAdminGroup* Group)
{
	if (Group != nullptr && ManagedGroups->Contains(Group))
	{
		Group->Managers->Remove(this);
		ManagedGroups->Remove(Group);
	}
}

void UxAdminUser::AddGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames)
{
	int32 i = 0;
	for (i = 0; i < aGroupNames.Num(); i++)
	{
		AddGroup(lGroups->FindByName(aGroupNames[i]));
	}
}

void UxAdminUser::AddManagedGroupsByName(UxAdminGroupList* lGroups, TArray<FString> aGroupNames)
{
	int32 i = 0;
	for (i = 0; i < aGroupNames.Num(); i++)
	{
		AddManagedGroup(lGroups->FindByName(aGroupNames[i]));
	}
}

bool UxAdminUser::HasPrivilege(FString priv)
{
	//return bMasterAdmin || InStr("|" + MergedPrivs + "|", "|" + priv + "|") != -1 || InStr("|" + MergedPrivs + "|", "|" + Left(priv, 1) + "|") != -1;
	return false;    //FAKE   /EliZ
}

void UxAdminUser::RedoMergedPrivs()
{
	int32 i = 0;
	bMasterAdmin = false;
	i = 0;
	if (i < Groups->Count())
	{
		if (Groups->Get(i)->bMasterAdmin)
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
		for (i = 0; i < Groups->Count(); i++)
		{
			MergePrivs(Groups->Get(i)->Privileges);
		}
	}
}

void UxAdminUser::MergePrivs(FString newprivs)
{
	FString priv = "";
	int32 pos = 0;
	if (newprivs != "")
	{
		pos = newprivs.Find("|");
		if (pos == -1)
		{
			priv = newprivs;
			newprivs = "";
		}
		else
		{
			priv = newprivs.Left(pos);
			newprivs = newprivs.Mid(pos + 1);
		}
		pos = FString("|" + MergedPrivs + "|").Find("|" + priv + "|");
		//pos = InStr("|" + MergedPrivs + "|", "|" + priv + "|");
		if (pos == -1)
		{
			if (MergedPrivs == "")
			{
				MergedPrivs = priv;
			}
			else
			{
				MergedPrivs = MergedPrivs + "|" + priv;
			}
		}
	}
}

bool UxAdminUser::CanManageGroup(UxAdminGroup* Group)
{
	return bMasterAdmin || ManagedGroups->Contains(Group);
}

bool UxAdminUser::CanManageUser(UxAdminUser* User)
{
	int32 i = 0;
	if (bMasterAdmin)
	{
		return true;
	}
	for (i = 0; i < ManagedGroups->Count(); i++)
	{
		if (ManagedGroups->Get(i)->Users->Contains(User))
		{
			return true;
		}
	}
	return false;
}

bool UxAdminUser::ValidPass(FString upass)
{
	int32 i = 0;
	if (upass.Len() < 6)
	{
		return false;
	}
	for (i = 0; i < upass.Len(); i++)
	{
		if(FString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJMLMNOPQRSTUVWXYZ0123456789!%^*(){}[]<>.,").Find(upass.Mid(i, 1)) == -1)
		{
			return false;
		}
	}
	return true;
}

bool UxAdminUser::ValidName(FString uname)
{
	int32 i = 0;
	if (uname.Len() < 1)
	{
		return false;
	}
	for (i = 0; i < uname.Len(); i++)
	{
		if (FString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJMLMNOPQRSTUVWXYZ0123456789!%^*(){}[]<>.,").Find(uname.Mid(i, 1)) == -1)
		{
			return false;
		}
	}
	return true;
}

int32 UxAdminUser::MaxSecLevel()
{
	int32 i = 0;
	int32 M = 0;
	if (bMasterAdmin)
	{
		return 255;
	}
	M = 0;
	for (i = 0; i < Groups->Count(); i++)
	{
		if (Groups->Get(i)->GameSecLevel > M)
		{
			M = Groups->Get(i)->GameSecLevel;
		}
	}
	return M;
}

UxAdminGroup* UxAdminUser::GetGroup(FString GroupName)
{
	return Groups->FindByName(GroupName);
}

UxAdminGroup* UxAdminUser::GetManagedGroup(FString GroupName)
{
	return ManagedGroups->FindByName(GroupName);
}

UxAdminUserList* UxAdminUser::GetManagedUsers(UxAdminGroupList* uAllGroups)
{
	UxAdminUserList* retList = {};
	UxAdminUserList* uList = {};
	UxAdminGroupList* uGroups = {};
	int32 i = 0;
	int32 j = 0;

	retList = NewObject<UxAdminUserList>(UxAdminUserList::StaticClass());
	if (bMasterAdmin)
	{
		uGroups = uAllGroups;
	}
	else
	{
		uGroups = ManagedGroups;
	}
	for (i = 0; i < uGroups->Count(); i++)
	{
		uList = uGroups->Get(i)->Users;
		for (j = 0; j < uList->Count(); j++)
		{
			retList->Add(uList->Get(j));
		}
	}
	return retList;
}

void UxAdminUser::UnlinkGroups()
{
	int32 i = 0;
	for (i = 0; i < Groups->Count(); i++)
	{
		Groups->Get(i)->RemoveUser(this);
	}
	for (i = 0; i < ManagedGroups->Count(); i++)
	{
		ManagedGroups->Get(i)->RemoveUser(this);
	}
}
