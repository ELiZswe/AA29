// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_ES2_SetupObjs/Action_ES2_SetupObjs.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_ES2_SetupObjs::UAction_ES2_SetupObjs()
{

}

bool UAction_ES2_SetupObjs::InitActionFor(AScriptedController* C)
{
	AAGP_CoopESSObjective* iter = nullptr;
	int32 i = 0;
	int32 j = 0;
	TArray<AAGP_CoopESSObjective*> ObjList;
	int32 numToHide = 0;
	int32 RandNum = 0;
	if (ES2_GroupTags.Num() == 0)
	{
		return false;
	}
	if (nMaxObjs > ES2_GroupTags.Num())
	{
		nMaxObjs = ES2_GroupTags.Num();
	}
	/*
	ForEach C.AllActors(AAGP_CoopESSObjective::StaticClass(), iter)
	{
		for (i = 0; i < ES2_GroupTags.Num(); i++)
		{
			if (((iter.Tag == ES2_GroupTags[i]) && (!iter.bHidden)) && (!iter.bHidden))
			{
				ObjList.insert(ObjList.Num(), 1);
				ObjList[(ObjList.Num() - 1)] = iter;
			}
		}
	}
	RandNum = (Rand(((nMaxObjs - nMinObjs) + 1)) + nMinObjs);
	if (RandNum <= 0)
	{
		numToHide = ObjList.Num();
	}
	else
	{
		numToHide = (ObjList.Num() - RandNum);
	}
	if (numToHide > 0)
	{
		i = Rand(ObjList.Num());
		ObjList[i].bHidden = true;
		ObjList[i].bDisabled = true;
		ObjList[i].SetCollision(false, false);
		ObjList[i].TriggerEvent(ObjList[i].getBecomeActiveEvent(), ObjList[i], nullptr);
		ObjList.RemoveAt(i, 1);
		numToHide--;
	}
	*/
	return false;    //FAKE /ELiZ
}
