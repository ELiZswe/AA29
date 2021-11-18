// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIBase.h"

UUIBase::UUIBase()
{
	_iID = -1;
	_bAllowScaling = true;
}


void UUIBase::StaticUpdatePrecacheMaterials(AAA2_WorldSettings* L)
{
}
FPosition UUIBase::GetPos()
{
	FPosition p;

	p.X = _Pos.X;
	p.Y = _Pos.Y;
	p.W = _Pos.W;
	p.H = _Pos.H;
	return p;
}
void UUIBase::SetPos(FPosition p)
{
	_Pos.X = p.X;
	_Pos.Y = p.Y;
	_Pos.W = p.W;
	_Pos.H = p.H;
}
void UUIBase::CreateUIObject(FString ObjectName)
{
	/*
	local Object myObject;
	local class<Object>  cObject;
	cObject = class<Object>(DynamicLoadObject(ObjectName, Class'Class'));
	myObject = new (None) classcObject;
	Return myObject;
	*/
}
void UUIBase::SetDebug(bool Debug)
{
	_bDebug = Debug;
}
int32 UUIBase::GetID()
{
	return _iID;
}
void UUIBase::Draw(UCanvas* Canvas)
{
}
bool UUIBase::KeyType(int32 Key)
{
	return false;
}
bool UUIBase::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUIBase::Destroyed()
{
}