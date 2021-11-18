// All the original content belonged to the US Army


#include "AA29/Object/XAdminBase/xAdminUserList/xAdminUserList.h"

UxAdminUserList::UxAdminUserList()
{

}


void UxAdminUserList::Count()
{
	//Return Users.Length;
}
void UxAdminUserList::Create(FString UserName, FString Password, FString Privileges)
{
	/*

	local xAdminUser NewUser;
	NewUser = new (None) class'xAdminUser';
	if (NewUser != None)
	{
		NewUser.Init(UserName, Password, Privileges);
	}
	Return NewUser;
	*/
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
void UxAdminUserList::Get(int32 i)
{
	//Return Users[i];
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
	/*
	Users.Length = 0;
	*/
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
				Return True;
			}
		}
	}
	*/
	return false;
}
void UxAdminUserList::FindByName(FString UserName)
{
	/*
	local int i;
	if (UserName != "")
	{
		for (i = 0; i < Users.Length; i++)
		{
			if (Users[i].UserName == UserName)
			{
				Return Users[i];
			}
		}
	}
	Return None;
	*/
}
