// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_ES2_SetupObjs/Action_ES2_SetupObjs.h"

UAction_ES2_SetupObjs::UAction_ES2_SetupObjs()
{

}

void UAction_ES2_SetupObjs::InitActionFor(UScriptedController* C)
{
	/*
	local AGP_CoopESSObjective iter;
	local int i;
	local int j;
	local array<AGP_CoopESSObjective> ObjList;
	local int numToHide;
	local int RandNum;
	if (ES2_GroupTags.Length == 0)
	{
		Return False;
	}
	if (nMaxObjs > ES2_GroupTags.Length)
	{
		nMaxObjs = ES2_GroupTags.Length;
	}
	ForEach C.AllActors('AGP_CoopESSObjective', iter)
	{
		for (i = 0; i < ES2_GroupTags.Length; i++)
		{
			if (iter.Tag == ES2_GroupTags[i] && !iter.bHidden && !iter.bHidden)
			{
				ObjList.insert(ObjList.Length, 1);
				ObjList[ObjList.Length - 1] = iter;
			}
		}
	}
	RandNum = Rand(nMaxObjs - nMinObjs + 1) + nMinObjs;
	if (RandNum <= 0)
	{
		numToHide = ObjList.Length;
	}
	else
	{
		numToHide = ObjList.Length - RandNum;
	}
	if (numToHide > 0)
	{
		i = Rand(ObjList.Length);
		ObjList[i].bHidden = true;
		ObjList[i].bDisabled = true;
		ObjList[i].SetCollision(False, False);
		ObjList[i].TriggerEvent(ObjList[i].getBecomeActiveEvent(), ObjList[i], None);
		ObjList.remove(i, 1);
		numToHide--;
	}
	*/
}