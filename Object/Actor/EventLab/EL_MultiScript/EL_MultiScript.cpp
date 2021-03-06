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
	if (bMasterScript)
	{
		MasterScript = this;
	}
	else
	{
		if (Cast<AEL_MultiScript>(GetOwner()) != nullptr)
		{
			MasterScript = Cast<AEL_MultiScript>(GetOwner());
		}
		else
		{
			//Log("EL_MultiScript WARNING - " + FString::FromInt(this) + " - MasterScript could not be set!");
		}
	}
}

bool AEL_MultiScript::IsMasterScript()
{
	return bMasterScript;
}

int32 AEL_MultiScript::GetLevelScriptsListIndex()
{
	return LevelScriptsListIndex;
}

void AEL_MultiScript::InitLevelScripts()
{
	int32 i = 0;
	if (bMasterScript)
	{
		/*
			if ((LevelScriptsClasses.Num() > 0) && (LevelScriptsList.Num() <= 0))
		{
			LevelScriptsList.insert(0, (LevelScriptsClasses.Num() + 1));
			LevelScriptsList[0] = this;
			for (i = 0; i < LevelScriptsClasses.Num(); i++)
			{
				LevelScriptsList[(i + 1)] = Spawn(LevelScriptsClasses[i], this);
			}
		}
		CreateCustomLevelScriptsLinks();
		*/
	}
}

void AEL_MultiScript::ResetScript(AEL_MultiScript* ScriptToReset, bool bReenterScriptAfterReset)
{
	if ((!bMasterScript) || (ScriptToReset == nullptr))
	{
		return;
	}
	SetActiveScript(MasterScript, nullptr, "", "", false);
	ScriptToReset->Reset();
	if (bReenterScriptAfterReset)
	{
		SetActiveScript(ScriptToReset,nullptr,"","",false);
	}
}

AEL_MultiScript* AEL_MultiScript::GetActiveScript()
{
	int32 i = 0;
	if (bActiveScriptTransition)
	{
		//Log("EL_MultiScript WARNING: Call to GetActiveScript() failed because Active Script Transition in progress");
		return nullptr;
	}
	for (i = 0; i < LevelScriptsList.Num(); i++)
	{
		if (!LevelScriptsList[i]->bDormant)
		{
			return LevelScriptsList[i];
		}
	}
	//Log("EL_MultiScript WARNING: Unable to locate an ActiveScript in GetActiveScript()");
	return nullptr;
}

void AEL_MultiScript::ScriptComplete(AEL_MultiScript* CompletedScript)
{
	if (CompletedScript == MasterScript)
	{
		//Log("EL_MultiScript WARNING - Unable to execute ScriptComplete() on parameter MasterScript");
		return;
	}
	if (!bMasterScript)
	{
		MasterScript->ScriptComplete(CompletedScript);
	}
	else
	{
		SetActiveScript(MasterScript, CompletedScript,"","",false);
	}
}

void AEL_MultiScript::SetActiveScript(AEL_MultiScript* NewActiveScript, AEL_MultiScript* OldActiveScript, FName NewActiveState, FName NewDeactiveState, bool bForceTransition)
{
	/*
	if (((!bMasterScript) || (NewActiveScript == nullptr)) || (!AllowScriptStart(NewActiveScript)))
	{
		return;
	}
	if (OldActiveScript == nullptr)
	{
		OldActiveScript = GetActiveScript();
	}
	if (((!bForceTransition) && (OldActiveScript != nullptr)) && (OldActiveScript == NewActiveScript))
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
	if ((!bMasterScript) || (ScriptToChange == nullptr))
	{
		Log("Erroring out of ActivateScript() with bMasterScript = " + FString::FromInt(bMasterScript) + " and ScriptToChange = " + FString::FromInt(ScriptToChange));
		return;
	}
	Log("ActivateScript for " + FString::FromInt(ScriptToChange));
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
	if ((!bMasterScript) || (ScriptToChange == nullptr))
	{
		return;
	}
	Log("DeactivateScript for " + FString::FromInt(ScriptToChange));
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
		for (i = 1; i < LevelScriptsList.Num(); i++)
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

