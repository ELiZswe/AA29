// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AdminBase/AdminBase.h"
#include "Admin.generated.h"

UCLASS()
class AA29_API UAdmin : public UAdminBase
{
	GENERATED_BODY()
public:
	UAdmin();

	void DoLogin(FString UserName, FString Password);
	void DoLogout();
};
