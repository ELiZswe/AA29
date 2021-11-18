// All the original content belonged to the US Army


#include "AA29/Object/XAdminBase/xAdminGroupList/xAdminGroupList.h"

UxAdminGroupList::UxAdminGroupList()
{

}

void UxAdminGroupList::Count()
{
	//Return Groups.Length;
}
void UxAdminGroupList::CreateGroup(FString GroupName, FString Privileges, uint8 GameSecLevel)
{
	/*
	local xAdminGroup newgroup;
	newgroup = FindByName(GroupName);
	if (newgroup == None)
	{
		newgroup = new (None) class'xAdminGroup';
		if (newgroup != None)
		{
			newgroup.Init(GroupName, Privileges, GameSecLevel);
		}
		Return newgroup;
	}
	Return None;
	*/
}
void UxAdminGroupList::Add(UxAdminGroup* Group)
{
	/*
	if (Group != None && !Contains(Group))
	{
		Groups.Length = Groups.Length + 1;
		Groups[Groups.Length - 1] = Group;
	}
	*/
}
void UxAdminGroupList::Remove(UxAdminGroup* Group)
{
	/*
	local int i;
	if (Group != None)
	{
		for (i = 0; i < Groups.Length; i++)
		{
			if (Groups[i] == Group)
			{
				Groups.remove(i, 1);
				Return;
			}
		}
	}
	*/
}
void UxAdminGroupList::Get(int32 Index)
{
	/*
	if (Index < 0 || Index >= Groups.Length)
	{
		Return None;
	}
	Return Groups[Index];
	*/
}
void UxAdminGroupList::FindByName(FString GroupName)
{
	/*
	local int i;
	for (i = 0; i < Groups.Length; i++)
	{
		if (Groups[i].GroupName == GroupName)
		{
			Return Groups[i];
		}
	}
	Return None;
	*/
}
bool UxAdminGroupList::Contains(UxAdminGroup* Group)
{
	/*
	local int i;
	for (i = 0; i < Groups.Length; i++)
	{
		if (Groups[i] == Group)
		{
			Return True;
		}
	}
	*/
	return false;
}
void UxAdminGroupList::FindMasterGroup()
{
	/*
	local int i;
	for (i = 0; i < Groups.Length; i++)
	{
		if (Groups[i].GameSecLevel == 255)
		{
			Return Groups[i];
		}
	}
	Return None;
	*/
}
void UxAdminGroupList::Clear()
{
	//Groups.remove(0, Groups.Length);
}
