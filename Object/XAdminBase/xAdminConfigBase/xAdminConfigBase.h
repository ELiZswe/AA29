// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/XAdminBase/XAdminBase.h"
#include "xAdminConfigBase.generated.h"

class UxAdminUserList;
class UxAdminGroupList;

UCLASS()
class UxAdminConfigBase : public UXAdminBase
{
	GENERATED_BODY()
public:
	UxAdminConfigBase();

	bool Load(UxAdminUserList* Users, UxAdminGroupList* Groups, bool bDontAddDefaultAdmin);
	bool Save(UxAdminUserList* Users, UxAdminGroupList* Groups);
};
