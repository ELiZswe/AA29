// All the original content belonged to the US Army


#include "AA29/Object/ObjectPool/ObjectPool.h"

UObjectPool::UObjectPool()
{

}

void UObjectPool::AllocateObject(UObject* ObjectClass)
{
	/*
	local Object Result;
	local int ObjectIndex;
	ObjectIndex = 0;
	if (ObjectIndex < Objects.Length)
	{
		if (Objects[ObjectIndex].Class == ObjectClass)
		{
			Result = Objects[ObjectIndex];
			Objects.remove(ObjectIndex, 1);
		}
		else
		{
			ObjectIndex++;
		}
	}
	if (Result == None)
	{
		Result = new (Outer) classObjectClass;
	}
	Return Result;
	*/
}
void UObjectPool::FreeObject(UObject* obj)
{
	/*
	Objects.Length = Objects.Length + 1;
	Objects[Objects.Length - 1] = obj;
	*/
}
void UObjectPool::Shrink()
{
	/*
	if (Objects.Length > 0)
	{
		Objects.remove(Objects.Length - 1, 1);
	}
	*/
}