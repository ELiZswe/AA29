// All the original content belonged to the US Army

#include "AA29/Object/XAdminBase/xAdminUserList/xAdminUserList.h"

UxAdminUserList::UxAdminUserList()
{

}

int32 UxAdminUserList::Count()
{
	return Users.Num();
}

UxAdminUser* UxAdminUserList::Create(FString UserName, FString Password, FString Privileges)
{
	UxAdminUser* NewUser = nullptr;
	/*
	NewUser = new (None) class'xAdminUser';
	if (NewUser != None)
	{
		NewUser.Init(UserName, Password, Privileges);
	}
	*/
	return NewUser;
}
void UxAdminUserList::Add(UxAdminUser* NewUser)
{
	/*
	if (NewUser != None && !Contains(NewUser))
	{
		Users.Length = Users.Length + 1;
		Users[Users.Length - 1] = NewUser;
	}
	*/
}

UxAdminUser* UxAdminUserList::Get(int32 i)
{
	return Users[i];
}

void UxAdminUserList::Remove(UxAdminUser* User)
{
	/*
	local int i;
	if (User != None)
	{
		for (i = 0; i < Users.Length; i++)
		{
			if (Users[i] == User)
			{
				Users.remove(i, 1);
				Return;
			}
		}
	}
	*/
}
void UxAdminUserList::Clear()
{
	Users = {};
}
bool UxAdminUserList::Contains(UxAdminUser* User)
{
	/*
	local int i;
	if (User != None)
	{
		for (i = 0; i < Users.Length; i++)
		{
			if (Users[i] == User)
			{
				return true;
			}
		}
	}
	*/
	return false;
}

UxAdminUser* UxAdminUserList::FindByName(FString UserName)
{
	/*
	local int i;
	if (UserName != "")
	{
		for (i = 0; i < Users.Length; i++)
		{
			if (Users[i].UserName == UserName)
			{
				return Users[i];
			}
		}
	}
	*/
	return nullptr;
}
