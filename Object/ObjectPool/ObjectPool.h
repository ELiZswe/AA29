// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectPool.generated.h"

UCLASS()
class UObjectPool : public UObject
{
	GENERATED_BODY()
public:
	UObjectPool();

	UPROPERTY()					TArray<UObject*> Objects;						//var array<Object> Objects;

	UObject* AllocateObject(UObject* ObjectClass);
	void FreeObject(UObject* obj);
	void Shrink();
};
