// All the original content belonged to the US Army

#include "AA29/Object/XAdminBase/xAdminUserList/xAdminUserList.h"
#include "AA29/Object/XAdminBase/xAdminUser/xAdminUser.h"

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
	if (NewUser != nullptr)
	{
		NewUser.Init(UserName, Password, Privileges);
	}
	*/
	return NewUser;
}
void UxAdminUserList::Add(UxAdminUser* NewUser)
{
	/*
	if (NewUser != nullptr && !Contains(NewUser))
	{
		Users.Num() = Users.Num() + 1;
		Users[Users.Num() - 1] = NewUser;
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
	int32 i;
	if (User != nullptr)
	{
		for (i = 0; i < Users.Num(); i++)
		{
			if (Users[i] == User)
			{
				Users.remove(i, 1);
				return;
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
	int32 i;
	if (User != nullptr)
	{
		for (i = 0; i < Users.Num(); i++)
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
	int32 i;
	if (UserName != "")
	{
		for (i = 0; i < Users.Num(); i++)
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
