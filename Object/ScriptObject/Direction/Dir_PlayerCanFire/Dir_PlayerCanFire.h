// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_PlayerCanFire.generated.h"

UCLASS()
class UDir_PlayerCanFire : public UDirection
{
	GENERATED_BODY()
public:
	UDir_PlayerCanFire();

	UPROPERTY()						bool		bCanFire;		//var bool bCanFire;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
};
