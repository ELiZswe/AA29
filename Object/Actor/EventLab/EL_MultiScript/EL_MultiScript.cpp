// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/EL_MultiScript.h"

AEL_MultiScript::AEL_MultiScript()
{

}

/*
simulated State MasterActiveExecute
{
}
*/

/*
simulated State MasterDormant
{
}
*/

/*
simulated State ActiveExecute
{
}
*/

/*
simulated State Dormant
{
}
*/

/*
simulated State MasterActiveExecute
{
}
*/

/*
simulated State MasterDormant
{
}
*/

/*
simulated State ActiveExecute
{
}
*/

/*
simulated State Dormant
{
}
*/

void AEL_MultiScript::EventLabTick(float DeltaTime)
{
	if (bDormant)
	{
		return;
	}
}

void AEL_MultiScript::PostInit()
{
	Super::PostInit();
	if (bMasterScript)
	{
		InitLevelScripts();
	}
}

void AEL_MultiScript::PostPostInit()
{
	Super::PostPostInit();
	SetMasterScript();
}

void AEL_MultiScript::SetMasterScript()
{
	/*
	if (bMasterScript)
	{
		MasterScript = Self;
	}
	else
	{
		if (EL_MultiScript(Owner) != None)
		{
			MasterScript = EL_MultiScript(Owner);
		}
		else
		{
			Log("EL_MultiScript WARNING - " $ string(Self) $ " - MasterScript could not be set!");
		}
	}
	*/
}

void AEL_MultiScript::InitLevelScripts()
{
	int32 i = 0;
	/*
	if (bMasterScript)
	{
		if ((LevelScriptsClasses.Length > 0) && (LevelScriptsList.Length <= 0))
		{
			LevelScriptsList.insert(0, (LevelScriptsClasses.Length + 1));
			LevelScriptsList[0] = Self;
			for (i = 0; i < LevelScriptsClasses.Length; i++)
			{
				LevelScriptsList[(i + 1)] = Spawn(LevelScriptsClasses[i], Self);
			}
		}
		CreateCustomLevelScriptsLinks();
	}
	*/
}

void AEL_MultiScript::ResetScript(AEL_MultiScript* ScriptToReset, bool bReenterScriptAfterReset)
{
	/*
	if ((!bMasterScript) || (ScriptToReset == None))
	{
		return;
	}
	SetActiveScript(MasterScript);
	ScriptToReset.Reset();
	if (bReenterScriptAfterReset)
	{
		SetActiveScript(ScriptToReset);
	}
	*/
}

AEL_MultiScript* AEL_MultiScript::GetActiveScript()
{
	int32 i = 0;
	/*
	if (bActiveScriptTransition)
	{
		Log("EL_MultiScript WARNING: Call to GetActiveScript() failed because Active Script Transition in progress");
		return None;
	}
	for (i = 0; i < LevelScriptsList.Length; i++)
	{
		if (!LevelScriptsList[i].bDormant)
		{
			return LevelScriptsList[i];
		}
	}
	Log("EL_MultiScript WARNING: Unable to locate an ActiveScript in GetActiveScript()");
	*/
	return nullptr;
}

void AEL_MultiScript::ScriptComplete(AEL_MultiScript* CompletedScript)
{
	/*
	if (CompletedScript == MasterScript)
	{
		Log("EL_MultiScript WARNING - Unable to execute ScriptComplete() on parameter MasterScript");
		return;
	}
	if (!bMasterScript)
	{
		MasterScript.ScriptComplete(CompletedScript);
	}
	else
	{
		SetActiveScript(MasterScript, CompletedScript);
	}
	*/
}

void AEL_MultiScript::SetActiveScript(AEL_MultiScript* NewActiveScript, AEL_MultiScript* OldActiveScript, FName NewActiveState, FName NewDeactiveState, bool bForceTransition)
{
	/*
	if (((!bMasterScript) || (NewActiveScript == None)) || (!AllowScriptStart(NewActiveScript)))
	{
		return;
	}
	if (OldActiveScript == None)
	{
		OldActiveScript = GetActiveScript();
	}
	if (((!bForceTransition) && (OldActiveScript != None)) && (OldActiveScript == NewActiveScript))
	{
		return;
	}
	bActiveScriptTransition = true;
	DeactivateScript(OldActiveScript, NewDeactiveState);
	ActivateScript(NewActiveScript, NewActiveState);
	bActiveScriptTransition = false;
	*/
}

void AEL_MultiScript::ActivateScript(AEL_MultiScript* ScriptToChange, FName NewState)
{
	/*
	if ((!bMasterScript) || (ScriptToChange == None))
	{
		Log("Erroring out of ActivateScript() with bMasterScript = " $ string(bMasterScript) $ " and ScriptToChange = " $ string(ScriptToChange));
		return;
	}
	Log("ActivateScript for " $ string(ScriptToChange));
	if (ScriptToChange.bMasterScript)
	{
		if ((NewState == "None") || (NewState == "None"))
		{
			NewState = "MasterActiveExecute";
		}
	}
	else
	{
		if ((NewState == "None") || (NewState == "None"))
		{
			NewState = "ActiveExecute";
		}
	}
	ScriptToChange.bDormant = false;
	ScriptToChange.ChangeState(NewState);
	*/
}

void AEL_MultiScript::DeactivateScript(AEL_MultiScript* ScriptToChange, FName NewState)
{
	/*
	if ((!bMasterScript) || (ScriptToChange == None))
	{
		return;
	}
	Log("DeactivateScript for " $ string(ScriptToChange));
	if (ScriptToChange.bMasterScript)
	{
		if ((NewState == "None") || (NewState == "None"))
		{
			NewState = "MasterDormant";
		}
	}
	else
	{
		if ((NewState == "None") || (NewState == "None"))
		{
			NewState = "Dormant";
		}
	}
	ScriptToChange.bDormant = true;
	ScriptToChange.ChangeState(NewState);
	*/
}

void AEL_MultiScript::Destroyed()
{
	int32 i = 0;
	if (bMasterScript)
	{
		/*
		for (i = 1; i < LevelScriptsList.Length; i++)
		{
			if (LevelScriptsList[i] != nullptr)
			{
				LevelScriptsList[i].Destroy();
			}
		}
		*/
	}
	MasterScript = nullptr;
	Super::Destroyed();
}

void AEL_MultiScript::CreateCustomLevelScriptsLinks()
{
}

void AEL_MultiScript::Reset()
{
}

bool AEL_MultiScript::AllowScriptStart(AEL_MultiScript* NewActiveScript)
{
	return true;
}

