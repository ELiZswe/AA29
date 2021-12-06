// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/EEAnimHelper/EEAnimHelper.h"

AEEAnimHelper::AEEAnimHelper()
{
	//bUseDynamicLights = false;
	//bAcceptsProjectors = false;
	//DrawScale = 1.13;
	//bUnlit = true;
	//bShadowCast = false;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bProjTarget = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bDirectional = false;
}
/*
State DignanIdle
{
Begin:
	switch (Host.GetStateName())
	{
		case 'Guarding':
		Host.LoopAnim('Relax_A',1,0.25,0);
		Host.LoopAnim('Relax_A',1,0.25,1);
		break;
		default:
		Host.LoopAnim('Agitated_Idle',1,0.25,0);
		Host.LoopAnim('Agitated_Idle',1,0.25,1);
		break;
	}
	JL'End'
;
	bTurning = true;
	switch (Host.GetStateName())
	{
		case 'Guarding':
		Host.LoopAnim('Relax_A',1,0.25,1);
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		Sleep(0.75);
		break;
		default:
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		Host.LoopAnim('AgitatedRotateL',1,0.25,1);
		Sleep(0.75);
		break;
	}
	bTurning = false;
	JL'Begin'
;
}

State PhilIdle
{
Begin:
	switch (Host.GetStateName())
	{
		case 'Guarding':
		Host.LoopAnim('Relax_B',1,0.25,0);
		Host.LoopAnim('Relax_B',1,0.25,1);
		break;
		default:
		Host.LoopAnim('Agitated_Idle',1,0.25,0);
		Host.LoopAnim('Agitated_Idle',1,0.25,1);
		break;
	}
	JL'End'
;
	bTurning = true;
	switch (Host.GetStateName())
	{
		case 'Guarding':
		Host.LoopAnim('Relax_B',1,0.25,1);
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		Sleep(0.75);
		break;
		default:
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		Host.LoopAnim('AgitatedRotateL',1,0.25,1);
		Sleep(0.75);
		break;
	}
	bTurning = false;
	JL'Begin'
;
}

State JasonIdle
{
Begin:
	switch (Host.GetStateName())
	{
		case 'Guarding':
		if (bAgitated)
		{
			Host.PlayAnim('C_Transition_B',1,0.25,0);
			Host.PlayAnim('C_Transition_B',1,0.25,1);
			Sleep(Host.GetAnimDuration('C_Transition_B'));
		}
		Host.LoopAnim('Relax_C',1,0.25,0);
		Host.LoopAnim('Relax_C',1,0.25,1);
		bAgitated = false;
		break;
		default:
		if (!bAgitated)
		{
			Host.PlayAnim('C_Transition_F',1,0.25,0);
			Host.PlayAnim('C_Transition_F',1,0.25,1);
			Sleep(Host.GetAnimDuration('C_Transition_F'));
		}
		Host.LoopAnim('Agitated_Idle',1,0.25,0);
		Host.LoopAnim('Agitated_Idle',1,0.25,1);
		bAgitated = true;
		break;
	}
	JL'End'
;
	bTurning = true;
	switch (Host.GetStateName())
	{
		case 'Guarding':
		if (bAgitated)
		{
			Host.PlayAnim('C_Transition_B',1,0.25,0);
			Host.PlayAnim('C_Transition_B',1,0.25,1);
			Sleep(Host.GetAnimDuration('C_Transition_B'));
		}
		Host.LoopAnim('Relax_C',1,0.25,1);
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		if (bAgitated)
		{
			Sleep((0.75 - GetAnimDuration('C_Transition_B')));
			break;
		}
		Sleep(0.75);
	}
	bAgitated = false;
	GOTO JL0304;
	default:
	if (!bAgitated)
	{
		Host.PlayAnim('C_Transition_F',1,0.25,0);
		Host.PlayAnim('C_Transition_F',1,0.25,1);
		Sleep(Host.GetAnimDuration('C_Transition_F'));
	}
	Host.LoopAnim('AgitatedRotateL',1,0.25,0);
	Host.LoopAnim('AgitatedRotateL',1,0.25,1);
	if (!bAgitated)
	{
		Sleep((0.75 - GetAnimDuration('C_Transition_F')));
	}
	else
	{
		Sleep(0.75);
	}
	bAgitated = true;
	GOTO JL0304;
JL0304:
	bTurning = false;
	JL'Begin'
;
}

State JerryIdle
{
Begin:
	switch (Host.GetStateName())
	{
		case 'Guarding':
		if (bAgitated)
		{
			Host.PlayAnim('D_Transition_B',1,0.25,0);
			Host.PlayAnim('D_Transition_B',1,0.25,1);
			Sleep(Host.GetAnimDuration('D_Transition_B'));
		}
		Host.LoopAnim('Relax_D',1,0.25,0);
		Host.LoopAnim('Relax_D',1,0.25,1);
		bAgitated = false;
		break;
		default:
		if (!bAgitated)
		{
			Host.PlayAnim('D_Transition_F',1,0.25,0);
			Host.PlayAnim('D_Transition_F',1,0.25,1);
			Sleep(Host.GetAnimDuration('D_Transition_F'));
		}
		Host.LoopAnim('Agitated_Idle',1,0.25,0);
		Host.LoopAnim('Agitated_Idle',1,0.25,1);
		bAgitated = true;
		break;
	}
	JL'End'
;
	bTurning = true;
	switch (Host.GetStateName())
	{
		case 'Guarding':
		if (bAgitated)
		{
			Host.PlayAnim('D_Transition_B',1,0.25,0);
			Host.PlayAnim('D_Transition_B',1,0.25,1);
			Sleep(Host.GetAnimDuration('D_Transition_B'));
		}
		Host.LoopAnim('Relax_D',1,0.25,1);
		Host.LoopAnim('AgitatedRotateL',1,0.25,0);
		if (bAgitated)
		{
			Sleep((0.75 - GetAnimDuration('D_Transition_B')));
			break;
		}
		Sleep(0.75);
	}
	bAgitated = false;
	GOTO JL0304;
	default:
	if (!bAgitated)
	{
		Host.PlayAnim('D_Transition_F',1,0.25,0);
		Host.PlayAnim('D_Transition_F',1,0.25,1);
		Sleep(Host.GetAnimDuration('D_Transition_F'));
	}
	Host.LoopAnim('AgitatedRotateL',1,0.25,0);
	Host.LoopAnim('AgitatedRotateL',1,0.25,1);
	if (!bAgitated)
	{
		Sleep((0.75 - GetAnimDuration('D_Transition_F')));
	}
	else
	{
		Sleep(0.75);
	}
	bAgitated = true;
	GOTO JL0304;
JL0304:
	bTurning = false;
	JL'Begin'
;
}
*/

void AEEAnimHelper::SetAnimHost(ANPC_EEGuard* AnimHost)
{
	/*
	if (AnimHost != None)
	{
		Host = AnimHost;
		Host.AnimBlendParams(1, 1, , , 'spine01');
	}
	else
	{
		Log("EEAnimHelper::SetAnimHost(): Error: Host is None for EEAnimHelper: " $ string(Self));
	}
	*/
}

FAnimInfo2 AEEAnimHelper::GetAnimInfo(int32 Channel)
{
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	FAnimInfo2 Info;
	/*
	GetAnimParams(Channel, SeqName, AnimFrame, AnimRate);
	Info.SeqName = SeqName;
	Info.AnimFrame = AnimFrame;
	Info.AnimRate = AnimRate;
	*/
	return Info;
}

void AEEAnimHelper::BeginPlay()
{
}

bool AEEAnimHelper::IsTurning()
{
	return bTurning;
}

void AEEAnimHelper::PlayTurning()
{
	//GotoState(GetStateName(), 'Turning');
}

void AEEAnimHelper::BeginAnims()
{
	/*
	switch (Host.DudeType)
	{
	case 0:
		GotoState('DignanIdle');
		break;
	case 1:
		GotoState('PhilIdle');
		break;
	case 2:
		GotoState('JasonIdle');
		break;
	case 3:
		GotoState('JerryIdle');
		break;
	default:
		break;
	}
	*/
}
