// All the original content belonged to the US Army


#include "AA29/Object/CheatManager/AA2_CheatManager.h"

UAA2_CheatManager::UAA2_CheatManager()
{

}

void UAA2_CheatManager::ReviewJumpSpots(FName TestLabel)
{
	/*
	if (TestLabel == 'Transloc')
	{
		TestLabel = 'Begin';
	}
	else
	{
		if (TestLabel == 'Jump')
		{
			TestLabel = 'Finished';
		}
		else
		{
			if (TestLabel == 'Combo')
			{
				TestLabel = 'FinishedJumping';
			}
			else
			{
				if (TestLabel == 'LowGrav')
				{
					TestLabel = 'FinishedComboJumping';
				}
			}
		}
	}
	Log("TestLabel is " $ string(TestLabel));
	Outer.Level.Game.ReviewJumpSpots(TestLabel);
	*/
}

void UAA2_CheatManager::ListDynamicActors()
{
	/*
	local Actor A;
	int32 i = 0;
	ForEach Outer.DynamicActors(Class'Actor', A)
	{
		i++;
		Log(string(i) @ string(A));
	}
	Log("Num dynamic actors: " $ string(i));
	*/
}

void UAA2_CheatManager::FreezeFrame(float Delay)
{
	/*
	Outer.Level.Game.SetPause(true, Outer);
	Outer.Level.PauseDelay = (Outer.Level.TimeSeconds + Delay);
	*/
}

void UAA2_CheatManager::WriteToLog(FString Param)
{
	//Log("NOW!" $ Eval((Param != ""), " '" $ Param $ "'", ""));
}

void UAA2_CheatManager::SetFlash(float F)
{
	//Outer.FlashScale.X = F;
}

void UAA2_CheatManager::SetFogR(float F)
{
	//Outer.FlashFog.X = F;
}

void UAA2_CheatManager::SetFogG(float F)
{
	//Outer.FlashFog.Y = F;
}

void UAA2_CheatManager::SetFogB(float F)
{
	//Outer.FlashFog.Z = F;
}

void UAA2_CheatManager::KillViewedActor()
{
	/*
	if (Outer.ViewTarget != None)
	{
		if ((Pawn(Outer.ViewTarget) != None) && (Pawn(Outer.ViewTarget).Controller != None))
		{
			Pawn(Outer.ViewTarget).Controller.Destroy();
		}
		Outer.ViewTarget.Destroy();
		Outer.SetViewTarget(None);
		ReportCheat("KillViewedActor");
	}
	*/
}

void UAA2_CheatManager::LogScriptedSequences()
{
	/*
	local AIScript S;
	ForEach Outer.AllActors(Class'AIScript', S)
	{
		S.bLoggingEnabled = (!S.bLoggingEnabled);
	}
	*/
}

void UAA2_CheatManager::Teleport()
{
	/*
	local Actor HitActor;
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	if (!areCheatsEnabled())
	{
		return;
	}
	HitActor = Outer.Trace(HitLocation, HitNormal, (Outer.ViewTarget.Location + (float(10000) * Vector(Outer.Rotation))), Outer.ViewTarget.Location, true);
	if (HitActor == None)
	{
		HitLocation = (Outer.ViewTarget.Location + (float(10000) * Vector(Outer.Rotation)));
	}
	else
	{
		HitLocation = (HitLocation + (Outer.ViewTarget.CollisionRadius * HitNormal));
	}
	Outer.ViewTarget.SetLocation(HitLocation);
	ReportCheat("Teleport");
	*/
}

void UAA2_CheatManager::ChangeSize(float F)
{
	/*
	if (Outer.Pawn.SetCollisionSize((Outer.Pawn.Default.CollisionRadius * F), (Outer.Pawn.Default.CollisionHeight * F)))
	{
		Outer.Pawn.SetDrawScale(F);
		Outer.Pawn.SetLocation(Outer.Pawn.Location);
	}
	*/
}

void UAA2_CheatManager::LockCamera()
{
	/*
	FVector LockedLocation = FVector(0, 0, 0);
	FRotator LockedRot = FRotator(0, 0, 0);
	local Actor LockedActor;
	if (!Outer.bCameraPositionLocked)
	{
		Outer.PlayerCalcView(LockedActor, LockedLocation, LockedRot);
		Outer.SetLocation(LockedLocation);
		LockedRotation = LockedRot;
		Outer.SetViewTarget(Outer);
	}
	else
	{
		Outer.SetViewTarget(Outer.Pawn);
	}
	Outer.bCameraPositionLocked = (!Outer.bCameraPositionLocked);
	Outer.bBehindView = Outer.bCameraPositionLocked;
	Outer.bFreeCamera = false;
	*/
}

void UAA2_CheatManager::SetCameraDist(float F)
{
	//Outer.CameraDist = FMax(F, 2);
}

void UAA2_CheatManager::EndPath()
{
}

void UAA2_CheatManager::FreeCamera(bool B)
{
	/*
	Outer.bFreeCamera = B;
	Outer.bBehindView = B;
	*/
}

void UAA2_CheatManager::CauseEvent(FName EventName)
{
	//Outer.TriggerEvent(EventName, Outer.Pawn, Outer.Pawn);
}

void UAA2_CheatManager::Amphibious()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Pawn.UnderWaterTime = 999999;
	ReportCheat("Amphibious");
	*/
}

void UAA2_CheatManager::Fly()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if ((Outer.Pawn != None) && Outer.Pawn.CheatFly())
	{
		Outer.ClientMessage("You feel much lighter");
		Outer.bCheatFlying = true;
		Outer.GotoState('PlayerFlying');
		ReportCheat("Fly");
	}
	*/
}

void UAA2_CheatManager::Walk()
{
	/*
	Outer.bCheatFlying = false;
	if ((Outer.Pawn != None) && Outer.Pawn.CheatWalk())
	{
		Outer.ClientReStart(Outer.Pawn);
	}
	*/
}

void UAA2_CheatManager::Ghost()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if ((Outer.Pawn != None) && Outer.Pawn.CheatGhost())
	{
		Outer.ClientMessage("You feel ethereal");
		Outer.bCheatFlying = true;
		Outer.GotoState('PlayerFlying');
		ReportCheat("Ghost");
	}
	*/
}

void UAA2_CheatManager::AllAmmo()
{
	//ReportCheat("AllAmmo");
}

void UAA2_CheatManager::Invisible(bool B)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Pawn.bHidden = B;
	if (B)
	{
		Outer.Pawn.Visibility = 0;
	}
	else
	{
		Outer.Pawn.Visibility = Outer.Pawn.Default.Visibility;
	}
	ReportCheat("Invisible");
	*/
}

void UAA2_CheatManager::Phil()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if (!Outer.bGodMode)
	{
		Outer.bGodMode = true;
		Outer.ClientMessage("phil == god");
		ReportCheat("God");
	}
	else
	{
		Outer.bGodMode = false;
		Outer.ClientMessage("you're not phil!");
	}
	*/
}

void UAA2_CheatManager::God()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if (Outer.bGodMode)
	{
		Outer.bGodMode = false;
		Outer.ClientMessage("God mode off");
		return;
	}
	Outer.bGodMode = true;
	Outer.ClientMessage("God Mode on");
	ReportCheat("God");
	*/
}

void UAA2_CheatManager::SloMo(float t)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Level.Game.SetGameSpeed(t);
	Outer.Level.Game.SaveConfig();
	Outer.Level.Game.GameReplicationInfo.SaveConfig();
	ReportCheat("SloMo");
	*/
}

void UAA2_CheatManager::SetJumpZ(float F)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Pawn.JumpZ = F;
	ReportCheat("SetJumpZ");
	*/
}

void UAA2_CheatManager::SetGravity(float F)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.PhysicsVolume.Gravity.Z = F;
	ReportCheat("SetGravity");
	*/
}

void UAA2_CheatManager::SetSpeed(float F)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Pawn.GroundSpeed = (Outer.Pawn.Default.GroundSpeed * F);
	Outer.Pawn.WaterSpeed = (Outer.Pawn.Default.WaterSpeed * F);
	ReportCheat("SetSpeed");
	*/
}

void UAA2_CheatManager::KillPawns()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.KillAllPawns(Class'Pawn');
	ReportCheat("KillPawns");
	*/
}

void UAA2_CheatManager::Avatar(FString ClassName)
{
	/*
	local class<Actor>  NewClass;
	local Pawn p;
	NewClass = class<Actor>(DynamicLoadObject(ClassName, Class'Class'));
	if (NewClass != None)
	{
		ForEach Outer.DynamicActors(Class'Pawn', p)
		{
			if ((p.Class == NewClass) && (p != Outer.Pawn))
			{
				if (Outer.Pawn.Controller != None)
				{
					Outer.Pawn.Controller.PawnDied(Outer.Pawn);
				}
				Outer.Possess(p);
			}
			else
			{
			}
		}
	}
	*/
}

void UAA2_CheatManager::SummonNPCSoldier()
{
	/*
	local class<Actor>  NewClass;
	FVector SpawnLoc = FVector(0, 0, 0);
	if (!areCheatsEnabled())
	{
		return;
	}
	NewClass = class<Actor>(DynamicLoadObject("AGP_Characters.NPC_Soldier", Class'Class'));
	if (NewClass != None)
	{
		if (Outer.Pawn != None)
		{
			SpawnLoc = Outer.Pawn.Location;
		}
		else
		{
			SpawnLoc = Outer.Location;
		}
		Outer.Spawn(NewClass, , , ((SpawnLoc + (float(72) * Vector(Outer.Rotation))) + (vect(0, 0, 1) * float(15))));
	}
	ReportCheat("Summoned Soldier");
	*/
}

void UAA2_CheatManager::Summon(FString ClassName)
{
}

void UAA2_CheatManager::PlayersOnly()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Level.bPlayersOnly = (!Outer.Level.bPlayersOnly);
	ReportCheat("PlayersOnly");
	*/
}

void UAA2_CheatManager::FreezeAll()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	Outer.Level.bPlayersOnly = (!Outer.Level.bPlayersOnly);
	Outer.Level.bFreezeKarma = Outer.Level.bPlayersOnly;
	ReportCheat("FreezeAll");
	*/
}

void UAA2_CheatManager::ClearAllDebugLines()
{
	/*
	local Actor A;
	ForEach Outer.AllActors(Class'Actor', A)
	{
		A.ClearStayingDebugLines();
	}
	*/
}

void UAA2_CheatManager::RememberSpot()
{
	/*
	if (Outer.Pawn != None)
	{
		Outer.Destination = Outer.Pawn.Location;
	}
	else
	{
		Outer.Destination = Outer.Location;
	}
	*/
}

void UAA2_CheatManager::ViewSelf(bool bQuiet)
{
	/*
	Outer.bBehindView = false;
	Outer.bViewBot = false;
	if (Outer.Pawn != None)
	{
		Outer.SetViewTarget(Outer.Pawn);
	}
	else
	{
		Outer.SetViewTarget(Outer);
	}
	if (!bQuiet)
	{
		Outer.ClientMessage(Outer.OwnCamera, 'Event');
	}
	Outer.FixFOV();
	*/
}

void UAA2_CheatManager::ViewPlayer(FString S)
{
	/*
	local Controller p;
	p = Outer.Level.ControllerList;
	if (p != None)
	{
		if (p.bIsPlayer && (p.PlayerReplicationInfo.PlayerName ~= S))
		{
		}
		p = p.nextController;
	}
	if (p.Pawn != None)
	{
		Outer.ClientMessage(Outer.ViewingFrom @ p.PlayerReplicationInfo.PlayerName, 'Event');
		Outer.SetViewTarget(p.Pawn);
	}
	Outer.bBehindView = (Outer.ViewTarget != Outer.Pawn);
	if (Outer.bBehindView)
	{
		Outer.ViewTarget.BecomeViewTarget();
	}
	*/
}

void UAA2_CheatManager::ViewActor(FName ActorName)
{
	/*
	local Actor A;
	ForEach Outer.AllActors(Class'Actor', A)
	{
		if (A.Name == ActorName)
		{
			Outer.SetViewTarget(A);
			Outer.bBehindView = true;
			return;
		}
	}
	*/
}

void UAA2_CheatManager::ViewFlag()
{
	/*
	local Controller C;
	C = Outer.Level.ControllerList;
	if (C != None)
	{
		if ((C.IsA('AIController') && (C.PlayerReplicationInfo != None)) && (C.PlayerReplicationInfo.HasFlag != None))
		{
			Outer.SetViewTarget(C.Pawn);
			return;
		}
		C = C.nextController;
	}
	*/
}

void UAA2_CheatManager::ViewBot()
{
	/*
	local Actor first;
	bool bFound = false;
	local Controller C;
	Outer.bViewBot = true;
	C = Outer.Level.ControllerList;
	if (C != None)
	{
		if (C.IsA('Bot') && (C.Pawn != None))
		{
			if (bFound || (first == None))
			{
				first = C;
				if (bFound)
				{
				}
			}
			else
			{
				if (C == Outer.RealViewTarget)
				{
					bFound = true;
				}
			}
			C = C.nextController;
		}
	}
	if (first != None)
	{
		Outer.SetViewTarget(first);
		Outer.bBehindView = true;
		Outer.ViewTarget.BecomeViewTarget();
		Outer.FixFOV();
	}
	else
	{
		ViewSelf(true);
	}
	*/
}

void UAA2_CheatManager::ViewTurret()
{
	/*
	local Actor first;
	bool bFound = false;
	local Controller C;
	Outer.bViewBot = true;
	C = Outer.Level.ControllerList;
	if (C != None)
	{
		if ((C.IsA('AIController') && (C.Pawn != None)) && (!C.IsA('Bot')))
		{
			if (bFound || (first == None))
			{
				first = C.Pawn;
				if (bFound)
				{
				}
			}
			else
			{
				if (C.Pawn == Outer.ViewTarget)
				{
					bFound = true;
				}
			}
			C = C.nextController;
		}
	}
	if (first != None)
	{
		Outer.SetViewTarget(first);
		Outer.bBehindView = true;
		Outer.ViewTarget.BecomeViewTarget();
		Outer.FixFOV();
	}
	else
	{
		ViewSelf(true);
	}
	*/
}

void UAA2_CheatManager::EnableDebugView()
{
	/*
	Outer.myHUD.bShowDebugInfo = true;
	Outer.myHUD.bPortalDebugView = true;
	*/
}

void UAA2_CheatManager::FocusOn(AActor* aClass, bool bQuiet)
{
	/*
	EnableDebugView();
	if (aClass != None)
	{
		FocusClass(aClass, bQuiet);
	}
	*/
}

void UAA2_CheatManager::FocusOnName(FName ActorName)
{
	/*
	EnableDebugView();
	if (ActorName != 'None')
	{
		FocusClass(Class'Actor', , , ActorName);
	}
	*/
}

void UAA2_CheatManager::FocusOnTaggedPawn(FName TagName)
{
	/*
	EnableDebugView();
	if (TagName != 'None')
	{
		FocusClass(Class'Pawn', , TagName);
	}
	*/
}

void UAA2_CheatManager::FocusOnNamedPawn(FName nameName)
{
	/*
	EnableDebugView();
	if (nameName != 'None')
	{
		FocusClass(Class'Pawn', , , nameName);
	}
	*/
}

void UAA2_CheatManager::FocusOnTargetedPawn(APawn* pawnTarget)
{
	/*
	EnableDebugView();
	Log("Setting focus to " $ string(pawnTarget));
	Outer.SetFocusTarget(pawnTarget);
	*/
}

void UAA2_CheatManager::FocusOnTag(FName TagName)
{
	/*
	EnableDebugView();
	if (TagName != 'None')
	{
		FocusClass(Class'Actor', , TagName);
	}
	*/
}

void UAA2_CheatManager::FocusOnPawn()
{
	/*
	EnableDebugView();
	FocusClass(Class'Pawn');
	*/
}

void UAA2_CheatManager::FocusOnAIVehicle()
{
	/*
	EnableDebugView();
	FocusClass(Class'Vehicle', , , , true);
	*/
}

void UAA2_CheatManager::FocusClass(AActor* aClass, bool bQuiet, FName TagName, FName ActorName, bool bAIOnly)
{
	/*
	local Actor Other;
	local Actor first;
	bool bFound = false;
	first = None;
	ForEach Outer.AllActors(aClass, Other)
	{
		if ((bAIOnly && Other.IsA('Vehicle')) && ((Vehicle(Other).Controller == None) || (!Vehicle(Other).Controller.IsA('AIController'))))
		{
			continue;
		}
		if (((TagName == 'None') || (Other.Tag == TagName)) && ((ActorName == 'None') || (Other.Name == ActorName)))
		{
			if (bFound || (first == None))
			{
				first = Other;
				if (bFound)
				{
				}
			}
			else
			{
				if (Other == Outer.FocusTarget)
				{
					bFound = true;
				}
			}
		}
	}
	if (first != None)
	{
		Outer.ClientMessage("Focusing On: " $ string(first.Name), 'Event');
		Outer.SetFocusTarget(first);
	}
	else
	{
		Outer.SetFocusTarget(Outer.Pawn);
	}
	*/
}

void UAA2_CheatManager::FocusOff()
{
	/*
	Outer.myHUD.bPortalDebugView = false;
	Outer.myHUD.bShowDebugInfo = false;
	*/
}

void UAA2_CheatManager::ViewClass(AActor* aClass, bool bQuiet, bool bCheat)
{
	/*
	local Actor Other;
	local Actor first;
	bool bFound = false;
	if (((!bCheat) && (Outer.Level.Game != None)) && (!Outer.Level.Game.bCanViewOthers))
	{
		return;
	}
	first = None;
	ForEach Outer.AllActors(aClass, Other)
	{
		if (bFound || (first == None))
		{
			first = Other;
			if (bFound)
			{
			}
		}
		else
		{
			if (Other == Outer.ViewTarget)
			{
				bFound = true;
			}
		}
	}
	if (first != None)
	{
		if (!bQuiet)
		{
			if (Pawn(first) != None)
			{
				Outer.ClientMessage(Outer.ViewingFrom @ first.GetHumanReadableName(), 'Event');
			}
			else
			{
				Outer.ClientMessage(Outer.ViewingFrom @ string(first), 'Event');
			}
		}
		Outer.SetViewTarget(first);
		Outer.bBehindView = (Outer.ViewTarget != Outer);
		if (Outer.bBehindView)
		{
			Outer.ViewTarget.BecomeViewTarget();
		}
		Outer.FixFOV();
	}
	else
	{
		ViewSelf(bQuiet);
	}
	*/
}

void UAA2_CheatManager::Loaded()
{
	//ReportCheat("Loaded");
}

void UAA2_CheatManager::AllWeapons()
{
	//ReportCheat("AllWeapons");
}

void UAA2_CheatManager::SkipMatch()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if ((Outer.Level.NetMode != NM_Standalone) || (Outer.Pawn == None))
	{
		return;
	}
	ReportCheat("SkipMatch");
	if (Outer.Level.Game.CurrentGameProfile != None)
	{
		Outer.Level.Game.CurrentGameProfile.CheatSkipMatch(Outer.Level.Game);
	}
	*/
}

void UAA2_CheatManager::JumpMatch(int32 ladderrung)
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	if ((Outer.Level.NetMode != NM_Standalone) || (Outer.Pawn == None))
	{
		return;
	}
	if (ladderrung < 0)
	{
		return;
	}
	ReportCheat("JumpMatch");
	if (Outer.Level.Game.CurrentGameProfile != None)
	{
		Outer.Level.Game.CurrentGameProfile.CheatJumpMatch(Outer.Level.Game, ladderrung);
	}
	*/
}

void UAA2_CheatManager::WinMatch()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	ReportCheat("WinMatch");
	if (Outer.PlayerReplicationInfo.Team != None)
	{
		Outer.PlayerReplicationInfo.Team.Score = float(Outer.Level.Game.GoalScore);
	}
	else
	{
		Outer.PlayerReplicationInfo.Score_Total = Outer.Level.Game.GoalScore;
	}
	Outer.Level.Game.CheckScore(Outer.PlayerReplicationInfo);
	*/
}

void UAA2_CheatManager::EnableCheats()
{
	/*
	bCheatsEnabled = true;
	Outer.ClientMessage("Cheats enabled");
	*/
}

bool UAA2_CheatManager::areCheatsEnabled()
{
	/*
	if (Outer.Level.Game.CurrentGameProfile != None)
	{
		if (!bCheatsEnabled)
		{
			Outer.ClientMessage("Cheats are NOT enabled, to enable cheats type: EnableCheats");
			Outer.ClientMessage("Enabling cheats prevents you from unlocking the bonus characters");
		}
		return bCheatsEnabled;
	}
	*/
	return true;
}

void UAA2_CheatManager::ReportCheat(FString cheat)
{
	/*
	if (Outer.Level.Game.CurrentGameProfile != None)
	{
		Outer.Level.Game.CurrentGameProfile.ReportCheat(Outer, cheat);
	}
	*/
}

void UAA2_CheatManager::WeakObjectives()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	ReportCheat("WeakObjectives");
	Outer.Level.Game.WeakObjectives();
	*/
}

void UAA2_CheatManager::DisableNextObjective()
{
	/*
	if (!areCheatsEnabled())
	{
		return;
	}
	ReportCheat("DisableNextObjective");
	Outer.Level.Game.DisableNextObjective();
	*/
}

void UAA2_CheatManager::ruler()
{
}
