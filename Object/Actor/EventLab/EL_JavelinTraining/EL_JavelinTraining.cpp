// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_JavelinTraining/EL_JavelinTraining.h"

AEL_JavelinTraining::AEL_JavelinTraining()
{

}

/*
State StartMission
{
	Function BeginState()
	{
		if (PassedBST())
		{
			SpawnLFSignupInstructor();
		}
		else
		{
			LiveFireSignUpTrigger.bDisabled=true;
			LiveFireSignUpTrigger.HUDText="";
		}
	}
Begin:
	FadeIn(2,true);
	PlayTip("Report directly to the Javelin training tent.","",(PlayTipDisplayTime + 3));
	Sleep(3);
	Player.PlaySound(WelcomeSound,0,1,,10000,,false);
	Sleep(5);
	PlayerLock(false,false);
	ChangeState('WalkingAround');
}
State WalkingAround
{
	Function BeginState()
	{
		if (! bPassedBST)
		{
			StartTimer('tmrIdleWarning',60,false);
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrTalktoTentInstructor')
		{
			PlayerLock(false,false);
			TentInstructorTrigger.HUDText=TentInstructorUseTip;
			return true;
		}
		if (Name == 'tmrTalktoLFSignUp')
		{
			LiveFireSignUpTrigger.HUDText="";
			LiveFireSignUpTrigger.bDisabled=true;
			FadeOut(2,true);
			ChangeState('InitializeLF');
			return true;
		}
		if ((Name == 'tmrIdleWarning') && (! bEnteredTent))
		{
			if (! bEnteredTent)
			{
				IdleWarn ++;
				if (IdleWarn >= 3)
				{
					Controller.ConsoleCommand("disconnect");
				}
				PlayTip("Report directly to the Javelin training tent.","",PlayTipDisplayTime);
				StartTimer('tmrIdleWarning',60,true);
			}
			else
			{
				StopTimer('tmrIdleWarning',0);
			}
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state Start");
	}
	Pickup_Javelin_BST_Tube(JTube).bCanPickUp=false;
	Pickup_Javelin_BST_CLU(BSTCLU).bCanPickUp=false;
}
State WelcomeBST
{
	Function BeginState()
	{
		PlayerLock(true,false);
		Player.ResetLean();
		Player.rBaseRotation.Pitch=Controller.Rotation.Pitch;
		Player.rBaseRotation.Yaw=Controller.Rotation.Yaw;
		Player.rBaseRotation.Roll=0;
		CaptureBSTVehicleFactories();
	}
Begin:
	BinkSound.SoundVolume=0;
	Controller.bDontLockAfterMisionComplete=true;
	Controller.RouteGoal=TentLockpoint;
	Controller.GotoState('MoveToForcedLocation');
	if (Controller.IsInState('MoveToForcedLocation'))
	{
		Sleep(0.25);
	}
	bInBST=true;
	if (bDebug)
	{
		Log("AAGA in begin of state WelcomeBST");
	}
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_00',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[0] + LengthDelay));
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_01',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[1] + LengthDelay));
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_02',BST_Instructor,1,512);
	Sleep(LengthBSTInstructor[2]);
	PlayTip("Press <Action> to pick up the Javelin Tube.","",PlayTipDisplayTime);
	Pickup_Javelin_BST_Tube(JTube).bCanPickUp=true;
	ChangeState('WaitPickedJT');
}
State WaitPickedJT
{
	Function BeginState()
	{
		StartTimer('tmrPickedJT',10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrPickedJT')
		{
			PlayLSAnim('S_Jave_Bst_Instructor_Vo_03',BST_Instructor,1,512);
			PlayTip("Press <Action> to pick up the Javelin Tube.","",PlayTipDisplayTime);
			StartTimer('tmrPickedJT',10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitPickedJT");
	}
}
State PickedJT
{
Begin:
	if (bDebug)
	{
		Log("AAGA in PickedJT state");
	}
	USERJT=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
	Player.bCanSwapWeapons=false;
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_04',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[4] + LengthDelay));
	PlayTip("Press <SwapHands> to shoulder the Javelin Tube.","",PlayTipDisplayTime);
	Player.bCanSwapWeapons=true;
	ChangeState('WaitShoulderedJT');
}
State WaitShoulderedJT
{
	Function BeginState()
	{
		StartTimer('tmrShoulderedJT',10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrShoulderedJT')
		{
			PlayLSAnim('S_Jave_Bst_Instructor_Vo_05',BST_Instructor,1,512);
			PlayTip("Press <SwapHands> to shoulder the Javelin Tube.","",PlayTipDisplayTime);
			StartTimer('tmrShoulderedJT',10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitShoulderedJT");
	}
}
State ShoulderedJT
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state ShoulderedJT");
	}
	Player.bCanSwapWeapons=false;
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_06',BST_Instructor,1,512);
	Sleep(LengthBSTInstructor[6]);
	PlayTip("Press <Action> to pick up the CLU.","",PlayTipDisplayTime);
	Pickup_Javelin_BST_CLU(BSTCLU).bCanPickUp=true;
	ChangeState('WaitPickedCLU');
}
State WaitPickedCLU
{
	Function BeginState()
	{
		StartTimer('tmrPickedCLU',10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrPickedCLU')
		{
			PlayLSAnim('S_Jave_Bst_Instructor_Vo_07',BST_Instructor,1,512);
			PlayTip("Press <Action> to pick up the CLU.","",PlayTipDisplayTime);
			StartTimer('tmrPickedCLU',10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitPickedCLU");
	}
}
State PickedCLU
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PickedCLU");
	}
	PCtoCLUWire1.bHidden=true;
	PCtoCLUWire1.ResetStaticFilterState();
	if (Player.getHandsInventory().IsA('WEAPON_Javelin'))
	{
		USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
		Javelin_BST_CLU(USERCLU).bCanZoom=false;
		Controller.bNoReload=true;
		Javelin_BST_CLU(USERCLU).bCanFire=false;
		Javelin_BST_CLU(USERCLU).bCanSupport=false;
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_08',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[8] + LengthDelay));
	PlayTip("Using the <SwapAltShoulder> key allows you to bring out the Javelin Tube.","Press <Binoculars> to take out or put away the CLU.",(2 * PlayTipDisplayTime));
	Player.bCanSwapWeapons=true;
	ChangeState('WaitCLUInHands');
}
State WaitCLUInHands
{
	Function BeginState()
	{
		StartTimer('tmrCLUInHands',5,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrCLUInHands')
		{
			Player.bCanSwapWeapons=false;
			USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
			if (((Javelin_BST_CLU(USERCLU) != None) && USERCLU.IsInState('Idle')) && (Player.NextSwap == None))
			{
				Javelin_BST_CLU(USERCLU).bCanZoom=false;
				Controller.bNoReload=true;
				StartTimer('tmrPostCLUInHands',3,true);
			}
			else
			{
				Player.bCanSwapWeapons=true;
				PlayTip("Press <Binoculars> to take out or put away the CLU.","",PlayTipDisplayTime);
				StartTimer('tmrCLUInHands',5,true);
			}
			return true;
		}
		if (Name == 'tmrPostCLUInHands')
		{
			ChangeState('CLUInHands');
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitAwayCLU");
	}
}
State CLUInHands
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state CLUInHands");
	}
	Target1=AGP_Vehicle(CaptureEvent('T62A_JT_Target1'));
	Player.bCanSwapWeapons=false;
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_10',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[10] + LengthDelay));
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
}
State CLUZooming
{
Begin:
	if (bDebug)
	{
		Log("AAGA CLUZooming State Enter");
	}
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[11],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[11] + LengthDelay));
	PlayTip("Press <NV> to cycle view modes.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
}
State CLUCycled
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state CLYCycled");
	}
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Player.PlaySound(BSTInstructorSound[12],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[12]);
	PlayTip("Press <Reload> to load the Javelin tube.","",PlayTipDisplayTime);
	Controller.bNoReload=false;
	ForcePlayerCrouch(true);
}
State WaitForCrouch
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitForCrouch");
	}
}
State Crouched
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Crouched");
	}
	if ((bUserCrouched && bBSTLoaded) && (! bJLoadedAndCrouchedOnce))
	{
		ChangeState('JLoadedAndCrouched');
	}
}
State WaitForReload
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitForReload");
	}
}
State Reloaded
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Reloaded");
	}
	Controller.bNoReload=true;
	if ((bBSTLoaded && bUserCrouched) && (! bJLoadedAndCrouchedOnce))
	{
		ChangeState('JLoadedAndCrouched');
	}
}
State JLoadedAndCrouched
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state JLoadedAndCrouched");
	}
	bJLoadedAndCrouchedOnce=true;
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_13',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[13] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
}
State PlayerLookingThroughSight
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PlayerLookingThroughSight");
	}
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[15],0,1,,10000,,false);
	Sleep(((1 + LengthBSTInstructor[15]) + LengthDelay));
	Player.PlaySound(BSTInstructorSound[16],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[16] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	PlayTip("Click and hold  <AltFire> for two seconds while keeping the target centered.","",PlayTipDisplayTime);
}
State ForceMisFire
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state ForceMisFire");
	}
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Sleep(LengthDelay);
	Player.PlaySound(BSTInstructorSound[29],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[29] + LengthDelay));
	PlayTip("Press <Fixjam> to fix missile bit error.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanFixJam=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	ChangeState('WaitFixJam');
}
State WaitFixJam
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitFixJam");
	}
}
State FixJamFixed
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state FixJamFixed");
	}
	Javelin_BST_CLU(USERCLU).bCanFixJam=false;
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	PlayLSAnim('S_Jave_Bst_Instructor_Vo_30',BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[30] + LengthDelay));
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
}
State PlayerLookingThroughSight2
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PlayerLookingThroughSight2");
	}
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[31],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[31] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	PlayTip("Click and hold  <AltFire> for two seconds while keeping the target centered.","",PlayTipDisplayTime);
}
State NoLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[17] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[17],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[17] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
State NoLock2
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock2");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[18] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[18],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[18] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
State NoLock3
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock3");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[19] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[19],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[19] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
State HasLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state HasLock");
	}
	bLengthyLockVO=true;
	StartTimer('tmrLengthyLockVO',(LengthBSTInstructor[20] + LengthDelay),false);
	Player.PlaySound(BSTInstructorSound[20],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[20]);
	if (Javelin_BST_CLU(USERCLU).bLockedOn)
	{
		PlayTip("Click the <Fire> key to fire Javelin.","",PlayTipDisplayTime);
	}
	Javelin_BST_CLU(USERCLU).bCanFire=true;
}
State LostLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LostLock");
	}
	PlayTip("You have lost the lock.","Please reacquire the lock",PlayTipDisplayTime);
}
State RegainedLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state RegainedLock");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("Click the <Fire> key to fire Javelin.","",PlayTipDisplayTime);
		Javelin_BST_CLU(USERCLU).bCanFire=true;
	}
}
State T72Hit
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state T72Hit");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Player.PlaySound(BSTInstructorSound[21],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[21]);
	FadeOut(2,true);
	TargetFactory2=AGP_VehicleFactory(CaptureEvent('VValidTargetFactory2'));
	Sleep(1);
	DestroyVT72Target(Target1);
	TargetFactory2.SpawnVehicle();
	Sleep(1);
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState('SettingUpSecondTarget');
}
State SettingUpSecondTarget
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state state SettingUpSecondTarget");
	}
	Javelin_BST_CLU(USERCLU).bDirectOnly=true;
	Player.PlaySound(BSTInstructorSound[22],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[22] + LengthDelay));
	target2=AGP_Vehicle(CaptureEvent('T62A_JT_Target2'));
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	PlayTip("Press the <SupportedFire> key to toggle between top and direct attack modes.","",PlayTipDisplayTime);
}
State SecondT72Hit
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state SecondT72Hit");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).bDirectOnly=false;
	Player.PlaySound(BSTInstructorSound[23],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[23] + LengthDelay));
	FadeOut(2,true);
	Sleep(2);
	DestroyVT72Target(target2);
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	Javelin_BST_CLU(USERCLU).bDirectFire=false;
	Javelin_BST_CLU(USERCLU).ToggleVision(false);
	Javelin_BST_CLU(USERCLU).myscope.fZoomMultiplier=4;
	Javelin_BST_CLU(USERCLU).myscope.iZoomFOV=0;
	Javelin_BST_CLU(USERCLU).bDisableNV=false;
	FadeIn(2,true);
	Player.PlaySound(BSTInstructorSound[24],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[24] + LengthDelay));
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	bInVirtual=true;
	if (bDebug)
	{
		Log("AAGA changing bInVirtual to true, " $ string(bInVirtual));
	}
	ChangeState('PreStartVirtual');
	if (bDebug)
	{
		Log("AAGA after bInvirtual and ChangeState");
	}
}
State PreStartVirtual
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PreStartVirtual");
	}
	ChangeState('StartVirtual');
}
State StartVirtual
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'VTimeLimitExceeded')
		{
			ChangeState('VFailTime');
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state StartVirtual");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	Javelin_BST_CLU(USERCLU).bDirectFire=false;
	Javelin_BST_CLU(USERCLU).ToggleVision(false);
	Javelin_BST_CLU(USERCLU).myscope.fZoomMultiplier=4;
	Javelin_BST_CLU(USERCLU).myscope.iZoomFOV=0;
	Javelin_BST_CLU(USERCLU).bDisableNV=false;
	Controller.DesiredFOV=Javelin_BST_CLU(USERCLU).myscope.aZoomFOV[Javelin_BST_CLU(USERCLU).myscope.iZoomFOV];
	Controller.FovAngle=Controller.DesiredFOV;
	SetClockTimedV();
}
State VFailInvalid
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state VFailInvalid");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).CancelLock(false);
	Player.PlaySound(BSTInstructorSound[25],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[25] + LengthDelay));
	FadeOut(2,true);
	Sleep(2);
	DestroyVirtualTargets();
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState('StartVirtual');
}
State VFailTime
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state VFailTime");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).CancelLock(false);
	Player.PlaySound(BSTInstructorSound[26],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[26] + LengthDelay));
	FadeOut(2,true);
	DestroyVirtualTargets();
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState('StartVirtual');
}
State VPass
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrCheckGUI')
		{
			if (bReadyForOpportunity)
			{
				ChangeState('Opportunity');
				return true;
			}
			else
			{
				StartTimer('tmrCheckGUI',1.5,true);
			}
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state VPass");
	}
	SpawnLFSignupInstructor();
	if (bDebug)
	{
		Log("Showing Javelin");
	}
	Javelin_Assembled.bHidden=false;
	Javelin_Assembled.ResetStaticFilterState();
	PCtoCLUWire2.bHidden=false;
	PCtoCLUWire2.ResetStaticFilterState();
	Player.PlaySound(BSTInstructorSound[27],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[27] + LengthDelay));
	bInVirtual=false;
	bPassedBST=true;
	uploadStatsBST();
	StartTimer('tmrCheckGUI',1,true);
}
State DelayAndCloseSaveAndContinue
{
Begin:
	Sleep(2);
	Controller.ClientCloseMenu(true,false);
	GotoState('Opportunity');
}
State Opportunity
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Opportunity");
	}
	Player.PlaySound(BSTInstructorSound[28],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[28] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanDrop=true;
	BinkSound.SoundVolume=BinkVolume;
	PlayTip("Press the <ThrowWeapon> key to drop the BST.","",PlayTipDisplayTime);
}
State BSTThrown
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state BSTThrown");
	}
	bInBST=false;
	PlayerLock(false,false);
	BST_Instructor_Trigger.SetCollision(false,false);
	Controller.bNoReload=false;
	ChangeState('WalkingAround');
}
State InitializeLF
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state InitializeLF");
	}
	CaptureLFTargets();
	ChangeState('WelcomeLF');
}
State WelcomeLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'LFInstructorIntro')
		{
			ChangeState('CountdownLF');
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WelcomeLF");
	}
	Player.SetLocation(LiveFireLockpoint.Location);
	Controller.SetRotation(LiveFireLockpoint.Rotation);
	Player.LimitRotation(false);
	bInTent=false;
	FadeIn(2,true);
	PlayerLock(true,false);
	Sleep(LengthDelay);
	LFSkipIntroTrigger.SetCollision(true,false);
	LFSkipIntroTrigger.bDisabled=false;
	LFSkipIntroTrigger.HUDText=LFSkipIntroUseTip;
	Speaker_LF01.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	StartTimer('LFInstructorIntro',(LengthLFInstructor[0] - float(LengthLFEcho)),false);
}
State CountdownLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'LFInstructorOutro')
		{
			ChangeState('StartLF');
			return true;
		}
		return false;
	}
Begin:
	LFSkipIntroTrigger.SetCollision(false,false);
	LFSkipIntroTrigger.bDisabled=true;
	LFSkipIntroTrigger.HUDText="";
	Speaker_LF01.StopSound(LFInstructorSound[0]);
	Speaker_LF02.StopSound(LFInstructorSound[0]);
	Speaker_LF03.StopSound(LFInstructorSound[0]);
	Speaker_LF04.StopSound(LFInstructorSound[0]);
	Speaker_LF05.StopSound(LFInstructorSound[0]);
	Speaker_LF01.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	StartTimer('LFInstructorOutro',(LengthLFInstructor[1] - float(LengthLFEcho)),false);
}
State StartLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'LFCheckOutofTubes')
		{
			if (LFValidTargetsHit < LFInitialValidTargets)
			{
				ChangeState('LFOutofTubes');
			}
			return true;
		}
		if (Name == 'LFTimeLimitExceeded')
		{
			ChangeState('LFFailTime');
			return true;
		}
		if (Name == 'CaptureLFCLU')
		{
			USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
			return true;
		}
		if (Name == 'LFEncouragement')
		{
			PlayLFEncouragement();
		}
		return false;
	}
Begin:
	Speaker_LF01.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	PlayerLock(false,false);
	SetClockTimedLF();
	bInLF=true;
	Pickup_Javelin_LF_CLU(LFCLU).bCanPickUp=true;
}
State LFFailOutsideZone
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFFailOutsideZone");
	}
	Javelin_LF_CLU(USERCLU).bCanFire=false;
	bFailLFZone=true;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Sleep(1);
	Speaker_LF01.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[1] - float(LengthLFEcho)));
	aarScoreboard();
}
State LFFailTime
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFFailTime");
	}
	Javelin_LF_CLU(USERCLU).bTotalLock=true;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[2] + LengthDelay));
	aarScoreboard();
}
State LFOutofTubes
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFOutofTubes");
	}
	Javelin_LF_CLU(USERCLU).bCanFire=false;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[3] + LengthDelay));
	aarScoreboard();
}
State LFComplete
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFComplete");
	}
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[4] + LengthDelay));
	FadeOut(2,true);
	FadeIn(2,true);
	bInLF=false;
	aarScoreboard();
}
State PlayerDiedInLF
{
Begin:
	Sleep(LengthDelay);
	Speaker_LF01.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[10] - float(LengthLFEcho)));
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You have been injured.","Would you like to restart the training?",128,128,7,'None',"AGP_Interface.AAMissionCompletePageJavelinTraining_Died");
}
State PlayerDiedNotInLF
{
Begin:
	Player.PlaySound(PlayerDiedNotLFSound,0,1,,10000,,false);
	Sleep(LengthPlayerDiedNotLFSound);
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You have been injured.","Would you like to restart the training?",128,128,7,'None',"AGP_Interface.AAMissionCompletePageJavelinTraining_Died");
}
State Cheater
{
	simulated Function BeginState()
	{
		if (Tent_Instructor.IsPlayingLIPSincAnim())
		{
			Tent_Instructor.StopLIPSincAnim();
		}
		if (BST_Instructor.IsPlayingLIPSincAnim())
		{
			BST_Instructor.StopLIPSincAnim();
		}
		if (LFSignUp_Instructor.IsPlayingLIPSincAnim())
		{
			LFSignUp_Instructor.StopLIPSincAnim();
		}
		if (Controller != None)
		{
			DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You Cheated","Would you like to try again?",128,128,7,'None',"AGP_Interface.AAMissionCompletePageJavelinTraining_LF");
		}
	}
}
*/
