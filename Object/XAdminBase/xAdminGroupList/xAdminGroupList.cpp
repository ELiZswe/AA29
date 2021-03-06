// All the original content belonged to the US Army

#include "AA29/Object/XAdminBase/xAdminGroupList/xAdminGroupList.h"
#include "AA29/Object/XAdminBase/xAdminGroup/xAdminGroup.h"

UxAdminGroupList::UxAdminGroupList()
{

}

int32 UxAdminGroupList::Count()
{
	return Groups.Num();
}

UxAdminGroup* UxAdminGroupList::CreateGroup(FString GroupName, FString Privileges, uint8 GameSecLevel)
{
	UxAdminGroup* newgroup = nullptr;
	newgroup = FindByName(GroupName);
	if (newgroup == nullptr)
	{
		newgroup = NewObject<UxAdminGroup>(UxAdminGroup::StaticClass());
		if (newgroup != nullptr)
		{
			newgroup->Init(GroupName, Privileges, GameSecLevel);
		}
		return newgroup;
	}
	return nullptr;
}

void UxAdminGroupList::Add(UxAdminGroup* Group)
{
	if (Group != nullptr && !Contains(Group))
	{
		Groups.Add(Group);
	}
}

void UxAdminGroupList::Remove(UxAdminGroup* Group)
{
	int32 i = 0;
	if (Group != nullptr)
	{
		for (i = 0; i < Groups.Num(); i++)
		{
			if (Groups[i] == Group)
			{
				Groups.RemoveAt(i, 1);
				return;
			}
		}
	}
}

UxAdminGroup* UxAdminGroupList::Get(int32 Index)
{
	if (Index < 0 || Index >= Groups.Num())
	{
		return nullptr;
	}
	return Groups[Index];
}

UxAdminGroup* UxAdminGroupList::FindByName(FString GroupName)
{
	int32 i = 0;
	for (i = 0; i < Groups.Num(); i++)
	{
		if (Groups[i]->GroupName == GroupName)
		{
			return Groups[i];
		}
	}
	return nullptr;
}

bool UxAdminGroupList::Contains(UxAdminGroup* Group)
{
	int32 i = 0;
	for (i = 0; i < Groups.Num(); i++)
	{
		if (Groups[i] == Group)
		{
			return true;
		}
	}
	return false;
}

UxAdminGroup* UxAdminGroupList::FindMasterGroup()
{
	int32 i = 0;
	for (i = 0; i < Groups.Num(); i++)
	{
		if (Groups[i]->GameSecLevel == 255)
		{
			return Groups[i];
		}
	}
	return nullptr;
}

void UxAdminGroupList::Clear()
{
	Groups.Empty();
}
