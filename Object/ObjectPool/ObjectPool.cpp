// All the original content belonged to the US Army

#include "AA29/Object/ObjectPool/ObjectPool.h"

UObjectPool::UObjectPool()
{

}

UObject* UObjectPool::AllocateObject(UObject* ObjectClass)
{
	UObject* Result =nullptr;
	int32 ObjectIndex = 0;
	ObjectIndex = 0;
	/*
	if (ObjectIndex < Objects.Num())
	{
		if (Objects[ObjectIndex].Class == ObjectClass)
		{
			Result = Objects[ObjectIndex];
			Objects.RemoveAt(ObjectIndex, 1);
		}
		else
		{
			ObjectIndex++;
		}
	}
	if (Result == nullptr)
	{
		Result = new (Outer) classObjectClass;
	}
	*/
	return Result;
}
void UObjectPool::FreeObject(UObject* obj)
{
	/*
	Objects.Num() = Objects.Num() + 1;
	Objects[Objects.Num() - 1] = obj;
	*/
}
void UObjectPool::Shrink()
{
	/*
	if (Objects.Num() > 0)
	{
		Objects.RemoveAt(Objects.Num() - 1, 1);
	}
	*/
}
