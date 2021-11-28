// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"

AAgentController::AAgentController()
{

}


/*
State busy
{
}
State SuppressState
{
	Function EndState ()
	{
		DebugLog(DEBUG_Always,"Leaving Suppression state");
	}
	simulated Function GetViewRotation ()
	{
		local Object.Rotator R;
		R=MakeRot(FRand() * 4096 - 2048,FRand() * 8192 - 4096,0);
		Return Global.Weapon() + R;
	}
	Function NotifySeePawn ()
	{
		DebugLog(DEBUG_Always,"AgentController::SuppressState{}::NotifySeePawn()");
		actionFailed=True;
	}
}
State AttackState
{
	Function FriendHitHisTarget ()
	{
		if (OldTargetHealth > Enemy.Health)
		{
			Return True;
		}
		Return False;
	}
	Function FriendMarkHisTarget ()
	{
		OldTargetHealth=Enemy.Health;
	}
	Function DistanceToTargetGreater (float fLen)
	{
		local float fDist;
		local FVector vVec;
		vVec=Pawn.Location - Enemy.Location;
		fDist=VSize(vVec);
		if (fLen < fDist)
		{
			Return False;
		}
		Return True;
	}
	Function AttackWithGrenade (int Type, float fLen)
	{
		if (Type == 1)
		{
			iNPC_FragGrenade --;
			AGP_Pawn(Pawn).GetGrenade(0);
		}
		else
		{
			if (Type == 2)
			{
				iNPC_StunGrenade --;
				AGP_Pawn(Pawn).GetGrenade(2);
			}
			else
			{
				if (Type == 3)
				{
					iNPC_SmokeGrenade --;
					AGP_Pawn(Pawn).GetGrenade(1);
				}
				else
				{
					Log("AttackWithGrenade(int type)::HAHA how did this happen");
				}
			}
		}
		AGP_Pawn(Pawn).getItemToPutInHands();
		if (fLen < 512)
		{
			AGP_Pawn(Pawn).GrenadeThrow3p(AGP_Pawn(Pawn).8);
		}
		else
		{
			AGP_Pawn(Pawn).GrenadeThrow3p(AGP_Pawn(Pawn).7);
		}
	}
	Function NPC_GrenadeAttack ()
	{
		local Pawn p;
		local bool bFragGrenade;
		local bool bStunGrenade;
		local bool bSmokeGrenade;
		local int iFragWt;
		local int iSmokeWt;
		local int iStunWt;
		local bool bTargetVisible;
		local float fLen;
		local FVector vVec;
		if (CanSee(Enemy))
		{
			bTargetVisible=True;
		}
		vVec=Pawn.Location - Enemy.Location;
		fLen=VSize(vVec);
		if (fLen > 1024)
		{
			iSmokeWt=20;
			iFragWt=30;
			if (bTargetVisible)
			{
				iSmokeWt += 10;
			}
			else
			{
				iFragWt += 10;
			}
			ForEach DynamicActors(Class'Pawn',p)
			{
				if (infront(Enemy.Location,Pawn) > 0.5)
				{
					if (p.PressingFire() || p.PressingAltFire() || p.Weapon.IsFiring())
					{
						iSmokeWt += 20;
					}
				}
			}
		}
		else
		{
			if (bTargetVisible)
			{
				iFragWt += 20;
			}
			else
			{
				iFragWt += 10;
				iStunWt += 20;
			}
		}
		if (iNPC_FragGrenade > 0)
		{
			bFragGrenade=True;
		}
		if (iNPC_SmokeGrenade > 0)
		{
			bSmokeGrenade=True;
		}
		if (iNPC_StunGrenade > 0)
		{
			bStunGrenade=True;
		}
		if (bSmokeGrenade)
		{
			if (bFragGrenade)
			{
				if (iFragWt > iSmokeWt)
				{
					AttackWithGrenade(1,fLen);
				}
				else
				{
					AttackWithGrenade(3,fLen);
				}
			}
			else
			{
				AttackWithGrenade(3,fLen);
			}
		}
		else
		{
			if (bStunGrenade)
			{
				if (bFragGrenade)
				{
					if (iFragWt > iStunWt)
					{
						AttackWithGrenade(1,fLen);
					}
					else
					{
						AttackWithGrenade(2,fLen);
					}
				}
				else
				{
					AttackWithGrenade(2,fLen);
				}
			}
		}
	}
	Function NPC_HowAboutAGrenade ()
	{
		if (FRand() > fNPC_LikesToThrowGrenade && infront(Enemy.Location,Pawn) > 0.75)
		{
			Return True;
		}
		Return False;
	}
	Function MoveAroundCanSeeCheck ()
	{
		bMoveAroundCanSee=False;
		if (CanSee(Enemy))
		{
			bMoveAroundCanSee=True;
		}
	}
	Function LostContact (bool Test)
	{
		if (! Test)
		{
			if (fNPC_LostContactTime < Level.TimeSeconds)
			{
				if (FRand() * 100 > 100 - fNPC_Experience)
				{
					fNPC_LostContactTime=Level.TimeSeconds + 5;
					Return True;
				}
			}
		}
		Return False;
	}
	Function CanAttack ()
	{
		Target=Enemy;
		if (CanSee(Enemy))
		{
			Return True;
		}
		Return False;
	}
	Function CrouchProne (bool Test)
	{
		local float Len;
		local FVector vec;
		local float Dot;
		if (fNPC_CrouchTime > Level.TimeSeconds)
		{
			Return False;
		}
		vec=Pawn.Location - Enemy.Location;
		Len=VSize(vec);
		Dot=infront(Pawn.Location,Enemy);
		if (Len > 512)
		{
			if (CheckIfShouldProne(Pawn.Location,Enemy.Location,fNPC_LikesToProne) && NearWall(128))
			{
				Pawn.ShouldProne(True);
			}
			else
			{
				if (CheckIfShouldCrouch(Pawn.Location,Enemy.Location,fNPC_LikesToCrouch))
				{
					Pawn.ShouldCrouch(True);
				}
				else
				{
					if (FRand() > fNPC_LikesToStand)
					{
						Pawn.ShouldStand(True);
					}
				}
			}
			fNPC_CrouchTime=Level.TimeSeconds + 10;
		}
		else
		{
			if (FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(True);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(True);
					}
				}
				fNPC_CrouchTime=Level.TimeSeconds + 5;
			}
			else
			{
				if (Len < 128 || Dot < 0)
				{
					if (Pawn.bIsCrouched && ! Test)
					{
						Pawn.ShouldStand(True);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(True);
						}
					}
					fNPC_CrouchTime=Level.TimeSeconds + 3;
				}
			}
		}
		Return True;
	}
	Function ReloadWeapon ()
	{
		local int rounds;
		if (Enemy != None)
		{
			rounds=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
			if (rounds <= 0)
			{
				if (AGP_Pawn(Pawn).iNPC_Clip > 0)
				{
					AGP_Pawn(Pawn).NPC_Reload();
					NPC_GiveAmmo();
					AGP_Pawn(Pawn).iNPC_Clip --;
				}
				Return True;
			}
		}
		Return False;
	}
	Function AttackMoveTime ()
	{
		local float fVal;
		fVal=fNPC_AttackMoveAroundTime - Level.TimeSeconds;
	}
	Function HuntingPlace ()
	{
		SafeDestN=FindSafePlaceFrom(Enemy.Location,True,True);
	}
	Function SafePlace ()
	{
		SafeDestN=FindSafePlaceFrom(Enemy.Location,True,False);
	}
	Function CoverPlace ()
	{
		MoveTarget=None;
		MoveTarget=FindCoverNode(Enemy.Location);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
			Log("CoverPlace MoveTarget == NONE");
		}
	}
	Function FindPath ()
	{
		MoveTarget=FindPathToward(SafeDestN,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function AvoidGrenade ()
	{
		local ThrowWeaponPickup TWP_Danger;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != None)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(True);
			}
		}
		Return TWP_Danger;
	}
}
State IdleState
{
	Function isPassive ()
	{
		Return True;
	}
	Function NotifySeePawn ()
	{
		DebugLog(DEBUG_Always,"AgentController::IdleState{}::NotifySeePawn()");
		actionFailed=True;
		NotifyComplete();
	}
}
State PatrolState
{
	Function FindPatrolObject ()
	{
		local NavigationPoint N;
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (PathNode(N).Name != MoveObject.Tag)
			{
			}
			MoveObject=N;
			N=N.nextNavigationPoint;
		}
	}
	Function StartPatrolObject ()
	{
		local NavigationPoint N;
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (PathNode(N).Name != Pawn.Tag)
			{
			}
			MoveObject=N;
			N=N.nextNavigationPoint;
		}
	}
}
State QuickMovementState
{
	Function AvoidFearGrenade ()
	{
		local ThrowWeaponPickup TWP_Danger;
		TWP_Danger=ThreatGrenade();
		if (TWP_Danger._EffectDuration > 0)
		{
			fAvoidFearGrenadeTime=Level.TimeSeconds + TWP_Danger._EffectDuration;
			TWP_AvoidFearGrenade=TWP_Danger;
		}
		if (fAvoidFearGrenadeTime < Level.TimeSeconds)
		{
			TWP_AvoidFearGrenade=None;
		}
		if (FearGrenade != None)
		{
			if (CheckGrenadeAwareTime())
			{
				if (TWP_Danger != None)
				{
					SetGrenadeAwareTime(1);
					MoveObject=FindSafePlaceFrom(TWP_Danger.Location,False,False);
				}
			}
		}
		else
		{
			if (TWP_AvoidFearGrenade != None)
			{
				if (VSize(TWP_AvoidFearGrenade.Location - Pawn.Location) < 1024)
				{
					MoveObject=FindSafePlaceFrom(TWP_AvoidFearGrenade.Location,False,False);
				}
				else
				{
					MoveObject=Pawn;
				}
			}
			else
			{
				if (PUser != None && Enemy == None)
				{
					MoveObject=PUser;
				}
			}
		}
	}
	Function FindPath ()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; MoveObject = " $ MoveObject);
		MoveTarget=FindPathToward(MoveObject,True);
		if (MoveTarget == None)
		{
			Log("CurrentDest is: " $ CurrentDestination);
			DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; could not find a path to " $ MoveObject);
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function UpdateMe ()
	{
		local bool bPUserMoved;
		bPUserMoved=FollowTheLeaderMoved();
		if (bPUserMoved)
		{
			UpdateFollowPosture();
		}
	}
	Function TouchedMoveAway ()
	{
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector vVec;
		local FVector vec1;
		local FVector vec2;
		if (PToucher != None && isTouched() && infront(touchLocation,PToucher) > 0.75)
		{
			GetAxes(PUser.GetViewRotation(),X,Y,Z);
			vVec=PUser.Location;
			vVec += X * PUser.CollisionRadius * 2;
			if (FastTrace(Pawn.Location,vVec))
			{
				vUpdateFollowLocation=vVec;
				Return True;
			}
			vec1=Y;
			vec1=Normal(vec1);
			vec2=vVec;
			vec2=Normal(vec2);
			if (vec1 Dot vec2 < 0)
			{
				vVec += Y * PUser.CollisionRadius * 1;
			}
			else
			{
				Y *= -1;
				vVec += Y * PUser.CollisionRadius * 1;
			}
			if (FastTrace(Pawn.Location,vVec))
			{
				vUpdateFollowLocation=vVec;
				Return True;
			}
			else
			{
				MoveObject=FindSafePlaceFrom(PUser.Location,True,True);
			}
		}
		Return False;
	}
	Function UpdateFollowPosture ()
	{
		if (fUpdateFollowPostureTime > Level.TimeSeconds)
		{
			fUpdateFollowPostureTime=Level.TimeSeconds + 1;
			Return;
		}
		if (! PUser.bIsCrouched && ! PUser.bIsProne)
		{
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand(True);
			}
		}
		else
		{
			if (PUser.bIsCrouched && ! Pawn.bIsCrouched)
			{
				Pawn.ShouldCrouch(True);
			}
			else
			{
				if (PUser.bIsProne && ! Pawn.bIsCrouched)
				{
					Pawn.ShouldCrouch(True);
				}
			}
		}
	}
	Function FollowTheLeaderMoved ()
	{
		local FVector vVec;
		local float fLen;
		vVec=PUserOldPos - PUser.Location;
		fLen=VSize(vVec);
		PUserOldPos=PUser.Location;
		if (fLen > 0)
		{
			Return True;
		}
		Return False;
	}
}
State MovementState
{
	Function AssesDangerAndSomeFX ()
	{
		local Actor dActor;
		local Pawn p;
		local float fLen;
		local FVector vVec;
		local float fdetectdistance;
		local PlayerReplicationInfo PRI;
		local PlayerReplicationInfo UserPRI;
		fdetectdistance=1024;
		ForEach DynamicActors(Class'Pawn',p)
		{
			if (p == PUser)
			{
			}
			else
			{
				if (p != None && PlayerController(p.Controller) != None)
				{
					vVec=Pawn.Location - p.Location;
					fLen=VSize(vVec);
					if (fLen < fdetectdistance && infront(p.Location,Pawn) > 0.4)
					{
						dActor=p;
						PRI=PlayerReplicationInfo(dActor);
						UserPRI=PUser.PlayerReplicationInfo;
						if (CanSee(p) && PRI.Team.TeamIndex != UserPRI.Team.TeamIndex)
						{
							if (p.Weapon.IsFiring())
							{
								if (FRand() > 0.5)
								{
									NPC_PilotSay(0,True);
								}
								else
								{
									if (FRand() > 0.5)
									{
										NPC_PilotSay(1,True);
									}
									else
									{
										NPC_PilotSay(5,True);
									}
								}
							}
							else
							{
								NPC_PilotSay(0,True);
							}
						}
					}
				}
			}
		}
	}
	Function FriendStartAttack ()
	{
		local float fLen;
		local FVector vVec;
		vVec=Enemy.Location - Pawn.Location;
		fLen=VSize(vVec);
		Attack(fLen);
	}
	Function FollowMe ()
	{
		local float fLen;
		local FVector vVec;
		local FVector vDest;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local float fDistance;
		local FVector vec1;
		local FVector vec2;
		local bool bPUserMoved;
		if (CurrentOrder == 5)
		{
			UpdateFollowLocation();
			bPUserMoved=FollowTheLeaderMoved();
			vVec=MoveObject.Location - Pawn.Location;
			fLen=VSize(vVec);
			UpdateFollowPosture(bPUserMoved,fLen);
			fDistance=6;
			if (fLen < MoveObject.CollisionRadius * fDistance && bPUserMoved)
			{
				GetAxes(PUser.GetViewRotation(),X,Y,Z);
				vDest=vUpdateFollowLocation;
				vDest += X * MoveObject.CollisionRadius * 4;
				if (infront(Pawn.Location,PUser) > 0.5)
				{
					vec1=Y;
					vec1=Normal(vec1);
					vec2=vVec;
					vec2=Normal(vec2);
					if (vec1 Dot vec2 < 0)
					{
						vDest += Y * MoveObject.CollisionRadius * 2;
					}
					else
					{
						Y *= -1;
						vDest += Y * MoveObject.CollisionRadius * 2;
					}
				}
			}
			else
			{
				if (fLen < MoveObject.CollisionRadius * fDistance * 2 && zdiffCheck() && Physics != 11)
				{
					vDest=Pawn.Location;
				}
				else
				{
					if (Physics == 11)
					{
						vDest=PUser.Location;
					}
				}
			}
		}
		Return vDest;
	}
	Function zdiffCheck ()
	{
		local float fpawnz;
		local float fpuserz;
		local float zdiff;
		fpawnz=Pawn.Location.Z;
		fpuserz=PUser.Location.Z;
		zdiff=fpawnz - fpuserz;
		if (zdiff < -64 && zdiff > 64)
		{
			Return False;
		}
		Return True;
	}
	Function UpdateFollowPosture (bool bPUserMoved, float fLen)
	{
		WalkRun(fLen);
		if (fUpdateFollowPostureTime > Level.TimeSeconds)
		{
			fUpdateFollowPostureTime=Level.TimeSeconds + 1;
			Return;
		}
		if (! PUser.bIsCrouched && ! PUser.bIsProne)
		{
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand(True);
			}
		}
		else
		{
			if (PUser.bIsCrouched && ! Pawn.bIsCrouched)
			{
				Pawn.ShouldCrouch(True);
			}
			else
			{
				if (PUser.bIsProne && ! Pawn.bIsCrouched)
				{
					Pawn.ShouldCrouch(True);
				}
			}
		}
	}
	Function UpdateFollowLocation ()
	{
		local FVector vVec;
		local float fLen;
		local float fDistance;
		fDistance=4;
		vVec=vUpdateFollowLocation - PUser.Location;
		fLen=VSize(vVec);
		if (fLen > PUser.CollisionRadius * fDistance)
		{
			vUpdateFollowLocation=PUser.Location;
		}
	}
	Function FollowTheLeaderMoved ()
	{
		local FVector vVec;
		local float fLen;
		vVec=PUserOldPos - PUser.Location;
		fLen=VSize(vVec);
		PUserOldPos=PUser.Location;
		if (fLen > 0)
		{
			Return True;
		}
		Return False;
	}
	Function FindPath ()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; MoveObject = " $ MoveObject);
		MoveTarget=FindPathToward(MoveObject,False);
		if (MoveTarget == None)
		{
			Log("STUCK CurrentDest is: " $ CurrentDestination.Location);
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function AvoidFearGrenade ()
	{
		local ThrowWeaponPickup TWP_Danger;
		TWP_Danger=ThreatGrenade();
		if (TWP_Danger._EffectDuration > 0)
		{
			fAvoidFearGrenadeTime=Level.TimeSeconds + TWP_Danger._EffectDuration;
			TWP_AvoidFearGrenade=TWP_Danger;
		}
		if (fAvoidFearGrenadeTime < Level.TimeSeconds)
		{
			TWP_AvoidFearGrenade=None;
		}
		if (FearGrenade != None)
		{
			if (CheckGrenadeAwareTime())
			{
				if (TWP_Danger != None)
				{
					SetGrenadeAwareTime(1);
					MoveObject=FindSafePlaceFrom(TWP_Danger.Location,False,False);
				}
			}
		}
		else
		{
			if (TWP_AvoidFearGrenade != None)
			{
				if (VSize(TWP_AvoidFearGrenade.Location - Pawn.Location) < 1024)
				{
					MoveObject=FindSafePlaceFrom(TWP_AvoidFearGrenade.Location,False,False);
				}
				else
				{
					MoveObject=Pawn;
				}
			}
			else
			{
				if (PUser != None && Enemy == None)
				{
					MoveObject=PUser;
				}
			}
		}
	}
	Function TouchedMoveAway ()
	{
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector vVec;
		local FVector vec1;
		local FVector vec2;
		if (PUser != None && isTouched() && infront(touchLocation,PUser) > 0.75)
		{
			GetAxes(PUser.GetViewRotation(),X,Y,Z);
			vVec=PUser.Location;
			vVec += X * PUser.CollisionRadius * 2;
			if (FastTrace(Pawn.Location,vVec))
			{
				vUpdateFollowLocation=vVec;
				Return True;
			}
			vec1=Y;
			vec1=Normal(vec1);
			vec2=vVec;
			vec2=Normal(vec2);
			if (vec1 Dot vec2 < 0)
			{
				vVec += Y * PUser.CollisionRadius * 1;
			}
			else
			{
				Y *= -1;
				vVec += Y * PUser.CollisionRadius * 1;
			}
			if (FastTrace(Pawn.Location,vVec))
			{
				vUpdateFollowLocation=vVec;
				Return True;
			}
			else
			{
				MoveObject=FindSafePlaceFrom(PUser.Location,True,True);
			}
		}
		Return False;
	}
	Function DistanceToDestination ()
	{
		local float fLen;
		local FVector vVec;
		vVec=MoveObject.Location - Pawn.Location;
		fLen=VSize(vVec);
	}
	Function WalkRun (float fLen)
	{
		local bool bwalk;
		local float sfactor;
		local float minfactor;
		AGP_Pawn(Pawn).fRunSpeed=170;
		AGP_Pawn(Pawn).fWalkSpeed=85;
		if (fLen < 384 && MoveObject == PUser)
		{
			bwalk=True;
		}
		minfactor=0.25;
		sfactor=AGP_Pawn(Pawn).Health / fStartHealth;
		if (sfactor < minfactor)
		{
			sfactor=minfactor;
		}
		AGP_Pawn(Pawn).fRunSpeed *= sfactor;
		AGP_Pawn(Pawn).fWalkSpeed *= sfactor;
		AGP_Pawn(Pawn).SetWalking(False);
		Log("AGP_Pawn(Pawn).SetWalking(false);");
		Return bwalk;
	}
	Function FindSafeSpot ()
	{
		MoveObject=FindSafePlaceFrom(MoveObject.Location,True,False);
	}
}
State ChargeState
{
	Function FindPath ()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; MoveObject = " $ MoveObject);
		MoveTarget=FindPathToward(MoveObject,True);
		if (MoveTarget == None)
		{
			DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; could not find a MoveTarget");
			actionFailed=True;
			DebugLog(DEBUG_Always,"6");
			NotifyComplete();
		}
	}
}
State RecoveryState
{
	Function FindPath ()
	{
		MoveTarget=FindPathToward(MoveObject,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			DebugLog(DEBUG_Always,"8");
			NotifyComplete();
		}
	}
}
State WanderState
{
}
State DuckingState
{
}
State CowerState
{
	Function CrouchProne (bool Type)
	{
		local float Len;
		local FVector vec;
		local float Dot;
		if (fNPC_CrouchTime > Level.TimeSeconds)
		{
			Return False;
		}
		vec=Pawn.Location - Enemy.Location;
		Len=VSize(vec);
		Dot=infront(Pawn.Location,Enemy);
		if (Len > 512)
		{
			if (FastTrace(Enemy.Location,Pawn.Location) && Dot > 0.7 && FRand() > fNPC_LikesToProne && NearWall(128))
			{
				Pawn.ShouldProne(True);
			}
			else
			{
				if (Dot > 0.9 && FRand() > fNPC_LikesToCrouch)
				{
					Pawn.ShouldCrouch(True);
				}
				else
				{
					if (FRand() > fNPC_LikesToStand)
					{
						Pawn.ShouldStand(True);
					}
				}
			}
			fNPC_CrouchTime=Level.TimeSeconds + 10;
		}
		else
		{
			if (FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(True);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(True);
					}
				}
				fNPC_CrouchTime=Level.TimeSeconds + 5;
			}
			else
			{
				if (Len < 128 || Dot < 0)
				{
					if (Pawn.bIsCrouched && ! Type)
					{
						Pawn.ShouldStand(True);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(True);
						}
					}
					fNPC_CrouchTime=Level.TimeSeconds + 3;
				}
				else
				{
					Pawn.ShouldCrouch(True);
				}
			}
		}
		Return True;
	}
	Function FindSafeSpot ()
	{
		SafeDestN=FindSafePlaceFrom(Enemy.Location,False,False);
		MoveTarget=FindPathToward(SafeDestN,True);
	}
}
State StandState
{
	Function NPC_StandThink ()
	{
		local bool dangerGrenade;
		local ThrowWeaponPickup TWP_Danger;
		local float rounds;
		local FVector vVec;
		local float fLen;
		dangerGrenade=False;
		if (Enemy != None && AGP_Pawn(Enemy).isDead())
		{
			NPC_ResetToStand();
		}
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 0)
		{
			Return;
		}
		else
		{
			if (AGP_Pawn(Pawn).iNPC_ThinkType > 0)
			{
				if (CheckGrenadeAwareTime())
				{
					TWP_Danger=ThreatGrenade();
					if (TWP_Danger != None)
					{
						bGrenadeCheck=True;
						dangerGrenade=True;
						SetGrenadeAwareTime(1);
					}
					else
					{
						dangerGrenade=False;
					}
				}
				if (AGP_Pawn(Enemy).IsHeDead())
				{
					Enemy=None;
				}
				if (Enemy == None)
				{
					NPC_EnemyDetection();
				}
			}
		}
		NPC_UpdateOldVisionDistanceChecked();
		NPC_AmmoCheck();
		if (Enemy != None)
		{
			rounds=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
			if (rounds <= 0)
			{
				if (AGP_Pawn(Pawn).iNPC_Clip > 0)
				{
					Reload();
					NPC_GiveAmmo();
					AGP_Pawn(Pawn).iNPC_Clip --;
				}
				else
				{
					if (AGP_Pawn(Pawn).iNPC_Clip == 0 && bRunning == False)
					{
						bRunning=True;
						AGP_Pawn(Pawn).fNPC_Moral=0;
						AGP_Pawn(Pawn).TossWeapon(Pawn.Velocity +  Vector(Rotation) * 200 + vect(0 0 200));
					}
				}
			}
		}
		if (dangerGrenade == True)
		{
			SafeDestN=FindSafePlaceFrom(TWP_Danger.Location,False,False);
			if (SafeDestN != None)
			{
				MovementToward(SafeDestN);
				if (bHasWeapon == False)
				{
					bHasWeapon=True;
					NPC_GiveWeapon(1);
					NPC_GiveAmmo();
				}
				Stand();
				Return;
			}
			else
			{
				Log("can't find safe place from");
				Cower();
			}
		}
		if (bCower == True)
		{
			Cower();
		}
		else
		{
			if (bRunning == True)
			{
				Cower();
			}
			else
			{
				if (bTookDamage == True || Enemy != None)
				{
					if (bHasWeapon == False)
					{
						bHasWeapon=True;
						NPC_GiveWeapon(1);
						NPC_GiveAmmo();
					}
					if (NPC_CanReactDelayIsDone() && Enemy != None)
					{
						bAttackDone=False;
						if (CurrentOrder == 12)
						{
							Log("NPC_TakeCover :::::::::::::::");
							NPC_TakeCover(False);
						}
						else
						{
							vVec=Enemy.Location - Pawn.Location;
							fLen=VSize(vVec);
							Attack(fLen);
						}
					}
				}
			}
		}
		if (dangerGrenade == True || bRunning == True)
		{
			AGP_Pawn(Pawn).fNPC_Speed=AGP_Pawn(Pawn).fNPC_RunSpeed;
		}
		else
		{
			if (SafeDestN != None)
			{
				AGP_Pawn(Pawn).fNPC_Speed=AGP_Pawn(Pawn).fNPC_RunSpeed;
			}
			else
			{
				AGP_Pawn(Pawn).fNPC_Speed=AGP_Pawn(Pawn).fNPC_WalkSpeed;
			}
		}
	}
	Function NPC_TryToRunAway ()
	{
		local FVector vVec;
		local float fLen;
		vVec=Enemy.Location - Pawn.Location;
		fLen=VSize(vVec);
		if (fLen > 1024)
		{
			Return True;
		}
		Return False;
	}
	Function CrouchProne (bool Type)
	{
		local float Len;
		local FVector vec;
		local float Dot;
		if (fNPC_CrouchTime > Level.TimeSeconds)
		{
			Return False;
		}
		vec=Pawn.Location - Enemy.Location;
		Len=VSize(vec);
		Dot=infront(Pawn.Location,Enemy);
		if (Len > 512)
		{
			if (FastTrace(Enemy.Location,Pawn.Location) && Dot > 0.7 && FRand() > fNPC_LikesToProne && NearWall(128))
			{
				Pawn.ShouldProne(True);
			}
			else
			{
				if (Dot > 0.9 && FRand() > fNPC_LikesToCrouch && NearWall(128))
				{
					Pawn.ShouldCrouch(True);
				}
				else
				{
					if (Dot > 0.7 && FRand() > fNPC_LikesToProne && NearWall(128))
					{
						Pawn.ShouldProne(True);
					}
					else
					{
						if (FRand() > fNPC_LikesToStand)
						{
							Pawn.ShouldStand(True);
						}
					}
				}
			}
			fNPC_CrouchTime=Level.TimeSeconds + 10;
		}
		else
		{
			if (FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(True);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(True);
					}
				}
				fNPC_CrouchTime=Level.TimeSeconds + 5;
			}
			else
			{
				if (Len < 128 || Dot < 0)
				{
					if (Pawn.bIsCrouched && ! Type)
					{
						Pawn.ShouldStand(True);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(True);
						}
					}
					fNPC_CrouchTime=Level.TimeSeconds + 3;
				}
			}
		}
		Return True;
	}
}
State NPC_InvestigateState
{
	Function NPC_LookAround ()
	{
		LookAround();
	}
	Function StillSearching ()
	{
		if (fNPC_SearchingTime > Level.TimeSeconds)
		{
			Return True;
		}
		Return False;
	}
	Function CallABuddy ()
	{
		if (FRand() * 100 > 100 - fNPC_Experience && FRand() > 0.8)
		{
			NPC_InvestigateForceBuddyToSearch();
		}
	}
	Function NPC_TryToRunAway ()
	{
		local FVector vVec;
		local float fLen;
		vVec=Enemy.Location - Pawn.Location;
		fLen=VSize(vVec);
		if (fLen > 1024)
		{
			Return True;
		}
		Return False;
	}
	Function FindSafeDestNPath ()
	{
		MoveTarget=FindPathToward(SafeDestN,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function FindPath ()
	{
		MoveTarget=FindPathToward(InvestigateObject,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function AvoidGrenade ()
	{
		local ThrowWeaponPickup TWP_Danger;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != None)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(True);
			}
		}
		Return TWP_Danger;
	}
}
State NPC_GoToStartState
{
	Function FindPath ()
	{
		MoveTarget=FindPathToward(MoveObject,True);
	}
	Function FindPathToStartLocation ()
	{
		local NavigationPoint N;
		local NavigationPoint thisN;
		local float fLen;
		local FVector vVec;
		local float fOldLen;
		fOldLen=99999;
		N=Level.NavigationPointList;
		if (N != None)
		{
			vVec=N.Location - vNPC_StartLocation;
			fLen=VSize(vVec);
			if (fLen < fOldLen)
			{
				fOldLen=fLen;
				thisN=N;
			}
			N=N.nextNavigationPoint;
		}
		if (thisN != None)
		{
			MoveTarget=FindPathToward(thisN,True);
		}
		Return thisN;
	}
	Function FindSafeDestNPath ()
	{
		MoveTarget=FindPathToward(SafeDestN,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function AvoidGrenade ()
	{
		local ThrowWeaponPickup TWP_Danger;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != None)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(True);
			}
		}
		Return TWP_Danger;
	}
}
State NPC_TakingCoverState
{
	Function PickBehavior ()
	{
		if (AGP_Pawn(Pawn).MoralCheck(AGP_Pawn(Pawn).fNPC_Moral) == 0)
		{
			Cower();
			NotifyComplete();
			Return 0;
		}
		else
		{
			if (FRand() > AGP_Pawn(Pawn).fNPC_Agressiveness)
			{
				CurrentOrder=2;
				Stand();
				NotifyComplete();
				Return 0;
			}
		}
		if (Enemy != None && ! FastTrace(Enemy.Location,Pawn.Location))
		{
			if (FRand() > 0.5 || NearWall(128))
			{
				Pawn.ShouldProne(True);
			}
			else
			{
				Pawn.ShouldCrouch(True);
			}
			NotifyComplete();
			Return 0;
		}
		NotifyComplete();
		Return 1;
	}
	Function FindPath ()
	{
		SafePlace();
		MoveTarget=FindPathToward(SafeDestN,True);
		if (MoveTarget == None)
		{
			actionFailed=True;
			NotifyComplete();
		}
	}
	Function SafePlace ()
	{
		SafeDestN=FindSafePlaceFrom(Enemy.Location,True,False);
	}
}
State NPC_DeathState
{
	Function Dead_Dead ()
	{
		bIsDead_Dead=True;
	}
	Function Flambe ()
	{
	}
	Function Gibletts ()
	{
	}
	Function Flies ()
	{
	}
	Function BloodPool ()
	{
	}
	Function Respawn ()
	{
	}
}
*/

//native Function CalculatePathToGoal (FVector NewDestination);

void AAgentController::AAgentController::CalculatePathToGoal(FVector NewDestination)
{
}

//native Function GetNextWaypoint();
void AAgentController::AAgentController::GetNextWaypoint()
{
}


void AAgentController::AAgentController::Reset()
{
	/*
		Super::Reset();
		Enemy=nullptr;
		CurrentDestination=nullptr;
		PUser=nullptr;
		SafeDestN=nullptr;
		InvestigateObject=nullptr;
		DangerEntity=nullptr;
		enemyCont=nullptr;
		TWP_AvoidFearGrenade=nullptr;
		*/
}
void AAgentController::Destroyed()
{
	Super::Destroyed();
}
/*
void AAgentController::Possess(APawn* aPawn)
{
		if (! AGP_Pawn(aPawn).bDummyPawn)
		{
			Possess(aPawn);
			Pawn.SetMovementPhysics();
			if (! aPawn.IsA('AGP_Pawn'))
			{
				Log("ERROR:	AgentController::Possess()	Unknown Pawn " $ aPawn);
			}
			bPerfectAccuracy=true;
		}
}
*/
void AAgentController::CreateGoalDecider()
{
	/*
		local Goal_Interface local_interface;
		local class<Goal_Interface>  interface_class;
		interface_class=class<Goal_Interface>(DynamicLoadObject("AGP_AI.GoalDecider",Class'Class'));
		local_interface=Spawn(interface_class,Self);
		if (local_interface == None)
		{
			Log("ERROR: AgentController::createGoalDecider() failed to create interface");
		}
		else
		{
			my_goal_decider=local_interface;
		}
		*/
}
bool AAgentController::isPassive()
{
	return false;
}
bool AAgentController::weaponJammed()
{
	/*
		if (AGP_Weapon(Pawn.Weapon).bIsJammed == True)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
	return false;    //FAKE /ELiZ
}
bool AAgentController::weaponOutOfAmmo()
{
	/*
		if (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	*/
	return false;    //FAKE /ELiZ
}
void AAgentController::getMentalModel()
{
	/*
		Return AGP_Pawn(Pawn).getMentalModel();
		*/
}
void AAgentController::NPC_Walk(float Speed)
{
	/*
		AGP_Pawn(Pawn).fWalkSpeed=Speed;
		AGP_Pawn(Pawn).SetWalking(True);
		*/
}
void AAgentController::NPC_TakeCover(bool isProne)
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_TakingCoverState','Begin');
		}
		*/
}
void AAgentController::NPC_GoToStart()
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_GoToStartState','Begin');
		}
		*/
}
void AAgentController::NPC_Investigate()
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_InvestigateState','Begin');
		}
		*/
}
void AAgentController::NPC_DeadDead()
{
	/*
		GotoState('NPC_DeathState','End');
		*/
}
void AAgentController::NPC_DeathFX()
{
	/*
		GotoState('NPC_DeathState','Start');
		*/
}
void AAgentController::Start()
{
	/*
		if (AGP_Pawn(Pawn).bIsPatrolling == True)
		{
			bPatrolling=true;
			if (AGP_Pawn(Pawn).bIsScripted)
			{
				GotoState('PatrolState','Begin');
			}
			else
			{
				GotoState('PatrolState','Start');
			}
		}
		else
		{
			GotoState('StandState','Start');
		}
		*/
}
void AAgentController::Stand()
{
	//GotoState('StandState','Begin');
}
void AAgentController::Cower()
{
	/*
		Log("Cower state");
		if (! NPC_CheckIfDead())
		{
			GotoState('CowerState','Begin');
		}
		*/
}
void AAgentController::Suppress(AActor* SuppressionTarget)
{
	/*
		DebugLog(DEBUG_Always,"Got here " $ SuppressionTarget);
		Target=SuppressionTarget;
		GotoState('SuppressState','Begin');
		*/
}
void AAgentController::Attack(float fLen)
{
	/*
		local float fDelay;
		if (! NPC_CheckIfDead())
		{
			if (iNPC_AlertLevel <= 0)
			{
				iNPC_AlertLevel=1;
			}
			fDelay=1;
			fNPC_AttackDelay=fDelay;
			fNPC_AttackDelay += FRand() * 2;
			Check=1;
			GotoState('AttackState','Start');
		}
		*/
}
void AAgentController::Idle()
{
	//GotoState('IdleState','Begin');
}
void AAgentController::Patrol()
{
	//GotoState('PatrolState','Begin');
}
void AAgentController::MovementToward(AActor* new_move_object)
{
	/*
		MoveObject=new_move_object;
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 5 || AGP_Pawn(Pawn).iNPC_ThinkType == 6)
		{
			GotoState('QuickMovementState','Begin');
		}
		else
		{
			if (AGP_Pawn(Pawn).iNPC_ThinkType == 1)
			{
				GotoState('MovementState','Begin');
			}
			else
			{
				GotoState('QuickMovementState','Begin');
			}
		}
		*/
}
void AAgentController::MovementTo(FVector NewDestination)
{
	/*
		MoveDestination=NewDestination;
		MoveObject=nullptr;
		GotoState('MovementState','Begin');
		*/
}
void AAgentController::Wander()
{
	//GotoState('WanderState','Begin');
}
void AAgentController::Flee()
{
	//GotoState('MovementState','Begin');
}
void AAgentController::FixJam()
{
	/*
		GotoState('busy');
		AGP_Weapon(Pawn.Weapon).FixJam();
		*/
}
void AAgentController::Reload()
{
	/*
		if (! NPC_CheckIfDead())
		{
			AGP_Pawn(Pawn).NPC_Reload();
			fNPC_ReloadWeaponTime=Level.TimeSeconds + 5;
			GotoState('busy');
		}
		*/
}
void AAgentController::Recovery(APickup* recovery_pickup)
{
	/*
		DebugLog(DEBUG_InvAI,"AgentController::Recovery()	" $ recovery_pickup);
		MoveObject=recovery_pickup;
		GotoState('RecoveryState');
		*/
}
void AAgentController::TakeCover(bool goProne)
{
	/*
		DebugLog(DEBUG_AI,"dnback:: AgentController.TakeCover(); goProne = " $ goProne);
		if (goProne)
		{
			GotoState('DuckingState','Prone');
		}
		else
		{
			GotoState('DuckingState','Begin');
		}
		*/
}
void AAgentController::Charge()
{
	/*
		DebugLog(DEBUG_AI,"dnback:: AgentController.Charge()");
		GotoState('ChargeState','Begin');
		*/
}
void AAgentController::AdjustAround(APawn* Other)
{
	/*
		local float Speed;
		local FVector VelDir;
		local FVector OtherDir;
		local FVector SideDir;
		Speed=VSize(Pawn.Acceleration);
		if (Speed < Pawn.WalkingPct * Pawn.GroundSpeed)
		{
			return false;
		}
		VelDir=Pawn.Acceleration / Speed;
		VelDir.Z=0;
		OtherDir=Other.Location - Pawn.Location;
		OtherDir.Z=0;
		OtherDir=Normal(OtherDir);
		if (VelDir Dot OtherDir > 0.8)
		{
			bAdjusting=true;
			SideDir.X=VelDir.Y;
			SideDir.Y=-1 * VelDir.X;
			if (SideDir Dot OtherDir > 0)
			{
				SideDir *= -1;
			}
			AdjustLoc=Pawn.Location + 2 * Other.CollisionRadius * 0.5 * VelDir + SideDir;
		}
		*/
}
void AAgentController::SetPitch(FVector targ)
{
	/*
		local FVector D;
		local FRotator R;
		D=targ - Pawn.Location;
		R=D;
		NewPitch=R.Pitch;
		Return NewPitch;
		*/
}
void AAgentController::NeedToTurn(FVector targ)
{
	/*
		local FVector LookDir;
		local FVector AimDir;
		LookDir= Vector(Pawn.Rotation);
		LookDir=Normal(LookDir);
		AimDir=targ - Pawn.Location;
		AimDir=Normal(AimDir);
		DebugLog(DEBUG_AI,"dnback:: AgentController.NeedToTurn(); Dot Product =" $ LookDir Dot AimDir);
		Return LookDir Dot AimDir < 0.99;
		*/
}
void AAgentController::NPC_GiveAmmo()
{
	//Pawn.Weapon.GetCurrentAmmoType().AmmoAmount=30;
}
void AAgentController::NPC_isWeaponInstantHit()
{
	/*
		if (Pawn.Weapon.IsA('Weapon_RPG7_Rocket') || Pawn.Weapon.IsA('Weapon_AT4_Rocket') || Pawn.Weapon.IsA('Weapon_Guerilla_RPG7_Rocket'))
		{
			bNPC_RocketOnlyWeapon=true;
			Return 1;
		}
		else
		{
			if (Pawn.Weapon.IsA('Weapon_M203_Gren') || Pawn.Weapon.IsA('Weapon_GP30_Gren'))
			{
				bNPC_DualWeapon=true;
				Return 2;
			}
		}
		Return 0;
		*/
}
void AAgentController::NPC_SingleShotReloadTime()
{
	/*
		bIsSingleShot=false;
		fSingleShotTime=0;
		if (Pawn.Weapon.IsA('Weapon_M870_Shotgun'))
		{
			bIsSingleShot=true;
			fSingleShotTime=2;
		}
		else
		{
			if (Pawn.Weapon.IsA('Weapon_M203_Gren'))
			{
				bIsSingleShot=true;
				fSingleShotTime=3;
			}
			else
			{
				if (Pawn.Weapon.IsA('Weapon_GP30_Gren'))
				{
					bIsSingleShot=true;
					fSingleShotTime=3;
				}
				else
				{
					if (Pawn.Weapon.IsA('Weapon_M82_Sniper'))
					{
						bIsSingleShot=true;
						fSingleShotTime=4.5;
					}
					else
					{
						if (Pawn.Weapon.IsA('Weapon_M24_Sniper'))
						{
							bIsSingleShot=true;
							fSingleShotTime=2.5;
						}
						else
						{
							if (Pawn.Weapon.IsA('Weapon_MosinNagant_Sniper'))
							{
								bIsSingleShot=true;
								fSingleShotTime=3;
							}
							else
							{
								if (Pawn.Weapon.IsA('Weapon_SVD_Sniper'))
								{
									bIsSingleShot=true;
									fSingleShotTime=3.5;
								}
								else
								{
									if (Pawn.Weapon.IsA('Weapon_Freekin_Lasers'))
									{
										bIsSingleShot=true;
										fSingleShotTime=1;
									}
								}
							}
						}
					}
				}
			}
		}
		if (bIsSingleShot == True)
		{
			AGP_Weapon(Pawn.Weapon).eROF=1;
		}
		*/
}
void AAgentController::NPC_GiveWeapon(int32 whichone)
{
	/*
		local class<Weapon>  dWeapon;
		if (AGP_Pawn(Pawn).NPC_Weapon != None)
		{
			dWeapon=AGP_Pawn(Pawn).NPC_Weapon;
			Pawn.NPC_GiveWeapon(dWeapon);
			NPC_SingleShotReloadTime();
			NPC_isWeaponInstantHit();
			AGP_Pawn(Pawn)._InvGrenades[0]=10;
			AGP_Pawn(Pawn)._InvGrenades[1]=10;
			AGP_Pawn(Pawn)._InvGrenades[2]=10;
			Return;
		}
		else
		{
			Pawn.GiveWeapon("AGP_Inventory.Weapon_AK47_Rifle");
			NPC_isWeaponInstantHit();
			NPC_SingleShotReloadTime();
		}
		*/
}
void AAgentController::NPC_AmmoCheck()
{
	/*
		local int rounds;
		if (Enemy != None)
		{
			rounds=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
			if (rounds <= 0)
			{
				if (AGP_Pawn(Pawn).iNPC_Clip > 0)
				{
					Reload();
					NPC_GiveAmmo();
					AGP_Pawn(Pawn).iNPC_Clip --;
				}
				else
				{
					if (AGP_Pawn(Pawn).iNPC_Clip == 0 && bRunning == False)
					{
						bRunning=true;
						AGP_Pawn(Pawn).fNPC_Moral=0;
						AGP_Pawn(Pawn).TossWeapon(Pawn.Velocity +  Vector(Rotation) * 200 + vect(0 0 200));
					}
				}
			}
		}
		*/
}
void AAgentController::ShootTarget(AActor* NewTarget)
{
}
void AAgentController::NotifyTakeHit(APawn* instigatedBy, FVector HitLocation, int32 Damage, UaDamageType DamageType, FVector Momentum)
{
}
void AAgentController::Killed(AController* Killer, APawn* Other, UaDamageType DamageType)
{
	/*

		if (Other == Enemy)
		}
		{
		*/
}
void AAgentController::NotifySeePawn()
{
}
void AAgentController::SeePawn(APawn* Seen)
{
	/*
		local FVector vVec;
		local float fLen;
		local float fVisibilityDistance;
		local Pawn p;
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 1 && Enemy == None)
		{
			if (PlayerController(Seen.Controller) != None || AGP_Pawn(Seen).iNPC_ThinkType == 5 || AGP_Pawn(Seen).iNPC_ThinkType == 6)
			{
				vVec=Seen.Location - Pawn.Location;
				fLen=VSize(vVec);
				if (bIsSniper && AGP_Pawn(Pawn).DesiredBinoculars != None)
				{
					fVisibilityDistance=AGP_Pawn(Pawn).fVisionDistance * 2;
				}
				else
				{
					fVisibilityDistance=AGP_Pawn(Pawn).fVisionDistance;
				}
				if (fVisibilityDistance > fLen && NPC_isDistanceDetected(fLen,Seen) == True && NPC_CanReactDelayIsDone() || fLen < 512)
				{
					Log("SeePawn found :: " $ Seen);
					SetEnemy(Seen);
					bTookDamage=true;
					bNewOrder=true;
					bAttackDone=true;
					CurrentOrder=2;
					iNPC_AlertLevel ++;
					if (iNPC_AlertLevel > 3)
					{
						iNPC_AlertLevel=3;
					}
					fNPC_ReactDelayTime=Level.TimeSeconds + FRand() * 5 + 1 - fNPC_Experience * 10 + 3;
					ForEach DynamicActors(Class'Pawn',p)
					{
						if (p == Self)
						{
						}
						else
						{
							if (AgentController(p.Controller).Enemy != None)
							{
							}
							else
							{
								vVec=Seen.Location - p.Location;
								fLen=VSize(vVec);
								if (bIsSniper && AGP_Pawn(p).DesiredBinoculars != None)
								{
									fVisibilityDistance=AGP_Pawn(p).fVisionDistance * 2;
								}
								else
								{
									fVisibilityDistance=AGP_Pawn(p).fVisionDistance;
								}
								if (fVisibilityDistance > fLen && AgentController(p.Controller).NPC_isDistanceDetected(fLen,Seen) == True && AgentController(p.Controller).NPC_CanReactDelayIsDone() || fLen < 512)
								{
									Log("Tell a friend :: " $ Seen);
									AgentController(p.Controller).SetEnemy(Seen);
									AgentController(p.Controller).bTookDamage=true;
									AgentController(p.Controller).bNewOrder=true;
									AgentController(p.Controller).bAttackDone=true;
									AgentController(p.Controller).CurrentOrder=2;
									AgentController(p.Controller).iNPC_AlertLevel ++;
									if (AgentController(p.Controller).iNPC_AlertLevel > 3)
									{
										AgentController(p.Controller).iNPC_AlertLevel=3;
									}
									AgentController(p.Controller).fNPC_ReactDelayTime=Level.TimeSeconds + FRand() * 5 + 1 - AgentController(p.Controller).fNPC_Experience * 10 + 3;
								}
							}
						}
					}
				}
			}
		}
		*/
}
void AAgentController::SeePlayer(APawn* Seen)
{
	SeePawn(Seen);
}
void AAgentController::SeeMonster(APawn* Seen)
{
	SeePawn(Seen);
}
void AAgentController::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
	/*
		local Pawn dNoiseMaker;
		local bool jumpy;
		dNoiseMaker=Pawn(NoiseMaker);
		jumpy=false;
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 1 && Enemy == None)
		{
			jumpy=true;
			if (jumpy && PlayerController(dNoiseMaker.Controller) != None || AGP_Pawn(dNoiseMaker).iNPC_ThinkType == 5 || AGP_Pawn(dNoiseMaker).iNPC_ThinkType == 6)
			{
				Log("HearNoise found :: " $ dNoiseMaker);
				SetEnemy(dNoiseMaker);
				bTookDamage=true;
				bNewOrder=true;
				bAttackDone=true;
				CurrentOrder=2;
				iNPC_AlertLevel ++;
				if (iNPC_AlertLevel > 3)
				{
					iNPC_AlertLevel=3;
				}
				fNPC_ReactDelayTime=Level.TimeSeconds + FRand() * 5 + 1 - fNPC_Experience * 10 + 3;
			}
		}
		*/
}
bool AAgentController::SetEnemy(APawn* NewEnemy)
{
	/*
		if (NewEnemy == None)
		{
			Enemy=nullptr;
			return false;
		}
		if (Enemy == NewEnemy)
		{
			return true;
		}
		if (NewEnemy == Pawn || NewEnemy == None || NewEnemy.Health <= 0)
		{
			return false;
		}
		Enemy=NewEnemy;
		*/
	return true;
}
bool AAgentController::validEnemy()
{
	/*
		if (Enemy == None || Enemy == Pawn || Enemy.Health <= 0)
		{
			return false;
		}
		*/
	return true;
}
void AAgentController::NPC_ResetToStand()
{
	/*
		bCower=false;
		bRunning=false;
		bTookDamage=false;
		Enemy=nullptr;
		*/
}
void AAgentController::GetViewRotation()
{
	/*
		local FRotator ViewRot;
		ViewRot=Rotation;
		ViewRot.Pitch=NewPitch;
		Return ViewRot;
		*/
}
void AAgentController::NPC_AdjustAim(FVector projStart, int32 aimerror)
{
	/*
		local FVector D;
		local FRotator R;
		local FRotator ViewRot;
		D=Enemy.Location - Pawn.Location;
		R=D;
		NewPitch=R.Pitch;
		ViewRot=R;
		ViewRot.Pitch=NewPitch;
		Return R;
		*/
}
void AAgentController::DoFireEffectSwitchMode()
{
	/*
		if (fNPC_ProjectileAimTime < Level.TimeSeconds)
		{
			fNPC_ProjectileAimTime=Level.TimeSeconds + 20;
			Pawn.Weapon.GetCurrentAmmoType().bInstantHit=false;
			Pawn.Weapon.NPC_Fire(1,Enemy);
			Pawn.Weapon.GetCurrentAmmoType().bInstantHit=true;
			AGP_Pawn(Pawn).NPC_Reload();
		}
		*/
}
void AAgentController::DoFireEffect()
{
	/*
		local FVector StartPos;
		local FVector EndPos;
		local FRotator Aim;
		local float Spread;
		local float aimerror;
		local FVector D;
		local FVector d1;
		local FRotator r1;
		d1=Enemy.Location - Pawn.Location;
		r1=d1;
		Spread=0;
		aimerror=FRand() * 0;
		Pawn.MakeNoise(1);
		StartPos=Pawn.Location + Pawn.EyePosition();
		EndPos=Enemy.Location;
		D=EndPos - StartPos;
		Aim.Pitch=r1.Pitch;
		Pawn.SetViewRotation(Aim);
		if (AGP_Pawn(Pawn).IsHeDead())
		{
			Log("Dead guy is shooting !!!!!!!!");
		}
		if (FRand() < fNPC_ShootAccuracy)
		{
			Pawn.Weapon.NPC_Fire(1,Enemy);
		}
		else
		{
			Pawn.Weapon.NPC_Fire(0,Enemy);
		}
		*/
}
bool AAgentController::InRange()
{
	/*
		local float fLen;
		local FVector vVec;
		vVec=Enemy.Location - Pawn.Location;
		fLen=VSize(vVec);
		fNPC_AquireAimDistance=fLen;
		if (fLen < AGP_Pawn(Pawn).fVisionDistance * iNPC_AlertLevel + 1)
		{
			return true;
		}
		*/
	return false;
}
bool AAgentController::InExtendedRange()
{
	/*
		local float fLen;
		local float fAlert;
		fAlert=iNPC_AlertLevel;
		if (fAlert > 3)
		{
			fAlert=2;
		}
		if (fAlert <= 0)
		{
			fAlert=1;
		}
		fLen=AGP_Pawn(Pawn).fVisionDistance * fAlert * 2 / 1 / fNPC_Experience * fNPC_ShootAccuracy;
		if (fNPC_AquireAimDistance < AGP_Pawn(Pawn).fVisionDistance * iNPC_AlertLevel + 1 + fLen)
		{
			return true;
		}
		*/
	return false;
}
void AAgentController::SetAquireAimTime()
{
	/*
		local float CrouchedAquireTime;
		local float ProneAquireTime;
		local float StandingAquireTime;
		local float fFuzzyTime;
		fFuzzyTime=FRand() * 10 - 5;
		CrouchedAquireTime=3 + fFuzzyTime;
		ProneAquireTime=5 + fFuzzyTime;
		StandingAquireTime=10 + fFuzzyTime;
		if (Pawn.bIsCrouched)
		{
			fNPC_AquireAimTime=Level.TimeSeconds + CrouchedAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
		}
		else
		{
			if (Pawn.bIsProne)
			{
				fNPC_AquireAimTime=Level.TimeSeconds + ProneAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
			}
			else
			{
				fNPC_AquireAimTime=Level.TimeSeconds + StandingAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
			}
		}
		*/
}
bool AAgentController::NPC_FriendlyFire()
{
	/*
		local FVector HitLocation;
		local FVector HitNormal;
		local Actor Other;
		local FVector VStart;
		local FVector vEnd;
		if (bNoFriendlyFire || fNPC_Experience > FRand() * 100)
		{
			VStart=Pawn.Location;
			if (Pawn.bIsProne)
			{
				VStart.Z += Pawn.ProneEyeHeight;
			}
			else
			{
				if (Pawn.bIsCrouched)
				{
					VStart.Z += Pawn.CrouchEyeHeight;
				}
				else
				{
					VStart.Z += Pawn.BaseEyeHeight;
				}
			}
			vEnd=Enemy.Location;
			if (Enemy.bIsProne)
			{
				vEnd.Z += Enemy.ProneEyeHeight;
			}
			else
			{
				if (Enemy.bIsCrouched)
				{
					vEnd.Z += Enemy.CrouchEyeHeight;
				}
				else
				{
					vEnd.Z += Enemy.BaseEyeHeight;
				}
			}
			VStart=Pawn.Location + Pawn.Location;
			Other=Trace(HitLocation,HitNormal,vEnd,VStart,True);
			if (Other != None)
			{
				if (iNPC_GroupID == AgentController(Pawn(Other).Controller).iNPC_GroupID)
				{
					return true;
				}
			}
		}
		*/
	return false;
}
bool AAgentController::NearWall(float walldist)
{
	/*
		local Actor HitActor;
		local FVector HitLocation;
		local FVector HitNormal;
		local FVector ViewSpot;
		local FVector ViewDist;
		local FVector LookDir;
		LookDir= Vector(Rotation);
		ViewSpot=Pawn.Location + Pawn.BaseEyeHeight * vect(0 0 1);
		ViewDist=LookDir * walldist;
		HitActor=Trace(HitLocation,HitNormal,ViewSpot + ViewDist,ViewSpot,False);
		if (HitActor == None)
		{
			return false;
		}
		ViewDist=Normal(HitNormal Cross vect(0 0 1)) * walldist;
		if (FRand() < 0.5)
		{
			ViewDist *= -1;
		}
		Focus=nullptr;
		if (FastTrace(ViewSpot + ViewDist,ViewSpot))
		{
			FocalPoint=Pawn.Location + ViewDist;
			return true;
		}
		if (FastTrace(ViewSpot - ViewDist,ViewSpot))
		{
			FocalPoint=Pawn.Location - ViewDist;
			return true;
		}
		FocalPoint=Pawn.Location - LookDir * 300;
		*/
	return true;
}
bool AAgentController::CheckIfShouldCrouch(FVector StartPosition, FVector TargetPosition, float Probability)
{
	/*
		local Actor HitActor;
		local FVector HitNormal;
		local FVector HitLocation;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector projStart;
		if (! Pawn.bCanCrouch || ! Pawn.bIsCrouched && FRand() > Probability)
		{
			Pawn.bWantsToCrouch=false;
			return false;
		}
		GetAxes(Rotation,X,Y,Z);
		projStart=Pawn.Weapon.GetFireStart(X,Y,Z);
		projStart=projStart + StartPosition - Pawn.Location;
		projStart.Z=projStart.Z - 1.8 * Pawn.CollisionHeight - Pawn.CrouchHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,False);
		if (HitActor == None)
		{
			Pawn.bWantsToCrouch=true;
			return true;
		}
		projStart.Z=projStart.Z + 1.8 * Pawn.Default.CollisionHeight - Pawn.CrouchHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,False);
		if (HitActor == None)
		{
			Pawn.bWantsToCrouch=false;
			return false;
		}
		Pawn.bWantsToCrouch=true;
		*/
	return true;
}
bool AAgentController::CheckIfShouldProne(FVector StartPosition, FVector TargetPosition, float Probability)
{
	/*
		local Actor HitActor;
		local FVector HitNormal;
		local FVector HitLocation;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector projStart;
		if (! Pawn.bCanProne || ! Pawn.bIsProne && FRand() > Probability)
		{
			Pawn.bWantsToProne=false;
			return false;
		}
		GetAxes(Rotation,X,Y,Z);
		projStart=Pawn.Weapon.GetFireStart(X,Y,Z);
		projStart=projStart + StartPosition - Pawn.Location;
		projStart.Z=projStart.Z - 1.8 * Pawn.CollisionHeight - Pawn.ProneHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,False);
		if (HitActor == None)
		{
			Pawn.bWantsToProne=true;
			return true;
		}
		projStart.Z=projStart.Z + 1.8 * Pawn.Default.CollisionHeight - Pawn.ProneHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,False);
		if (HitActor == None)
		{
			Pawn.bWantsToProne=false;
			return false;
		}
		Pawn.bWantsToProne=true;
		*/
	return true;
}
void AAgentController::FireWeapon(bool bSuppressiveFire)
{
	/*
		local FVector StartPos;
		local FVector vVec;
		if (Pawn.Weapon != None)
		{
			if (InRange() == False)
			{
				if (fNPC_AquireAimTime < Level.TimeSeconds)
				{
					if (InExtendedRange() == True)
					{
						SetAquireAimTime();
					}
					else
					{
						actionFailed=true;
						Return;
					}
				}
				else
				{
					actionFailed=true;
					Return;
				}
			}
			if (! CanSee(Enemy))
			{
				actionFailed=true;
				Return;
			}
			if (AGP_Weapon(Pawn.Weapon).WeaponDisabled() == True)
			{
				DebugLog(DEBUG_AI,"AgentController::FireWeapon()	Weapon Disabled");
				actionFailed=true;
				Return;
			}
			if (bIsSingleShot)
			{
				if (fSingleShotDelayTime < Level.TimeSeconds)
				{
					bFireSingleShot=true;
					fSingleShotDelayTime=Level.TimeSeconds + fSingleShotTime;
				}
				else
				{
					actionFailed=true;
					bFireSingleShot=false;
					Return;
				}
			}
			if (NPC_FriendlyFire())
			{
				actionFailed=true;
				Return;
			}
			if (NPC_isWeaponInstantHit() == 0)
			{
				DoFireEffect();
			}
			else
			{
				StartPos=Pawn.Location;
				vVec= Vector(Pawn.Rotation);
				vVec += 32 * vVec;
				StartPos += vVec;
				if (Pawn.bIsProne)
				{
					StartPos.Z += Pawn.ProneEyeHeight;
				}
				else
				{
					if (Pawn.bIsCrouched)
					{
						StartPos.Z += Pawn.CrouchEyeHeight;
					}
					else
					{
						StartPos.Z += Pawn.BaseEyeHeight;
					}
				}
				if (FastTrace(Enemy.Location,StartPos))
				{
					DoFireEffectSwitchMode();
				}
				else
				{
					actionFailed=true;
					Return;
				}
			}
			DebugLog(DEBUG_AI,"dnback:: AgentController.fireWeapon(); " $ Pawn $ " shot at " $ Enemy);
			DebugLog(DEBUG_AI,"AgentController::FireWeapon()	" $ Pawn.Weapon.GetCurrentAmmoType().AmmoAmount $ " rounds");
			actionFailed=false;
		}
		else
		{
			actionFailed=true;
		}
		*/
}
/*
void AAgentController::registerNotification(AAction* new_action)
{
		ActiveAction=new_action;
		actionFailed=false;
}
*/

void AAgentController::NotifyComplete()
{
	/*
		if (ActiveAction != None)
		{
			ActiveAction.NotifyComplete(actionFailed);
			ActiveAction=nullptr;
		}
		*/
}
bool AAgentController::HandlePickupQuery(APickup* pick)
{
	return true;
}
bool AAgentController::NPC_isDistanceDetected(float fLen, APawn* p)
{
	/*
		local float ratio;
		local FVector D;
		local float distanceofD;
		local bool bCreeping;
		bCreeping=false;
		if (VSize(EnemyTrackedPosition) == 0)
		{
			EnemyTrackedPosition=p.Location;
		}
		D=EnemyTrackedPosition - p.Location;
		distanceofD=VSize(D);
		EnemyTrackedPosition=p.Location;
		if (distanceofD < 64 && fLen > 1024)
		{
			ratio=fLen / AGP_Pawn(Pawn).fVisionDistance;
			ratio *= fNPC_Experience;
			if (p.bIsCrouched)
			{
				ratio *= 0.8;
			}
			else
			{
				if (p.bIsProne)
				{
					ratio *= 0.6;
				}
			}
			if (iNPC_AlertLevel == 0)
			{
				ratio *= 0.8;
			}
			else
			{
				if (iNPC_AlertLevel == 1)
				{
					ratio *= 1;
				}
				else
				{
					if (iNPC_AlertLevel == 2)
					{
						ratio *= 1.2;
					}
					else
					{
						if (iNPC_AlertLevel == 3)
						{
							ratio *= 2;
						}
					}
				}
			}
			if (0.5 > ratio)
			{
				return true;
			}
			bCreeping=true;
		}
		if (p.bIsCrouched)
		{
			fLen *= 0.8;
		}
		else
		{
			if (p.bIsProne)
			{
				fLen *= 0.6;
			}
		}
		if (bCreeping == True)
		{
			fLen *= 0.5;
		}
		if (iNPC_AlertLevel == 0)
		{
			fLen *= 0.8;
		}
		else
		{
			if (iNPC_AlertLevel == 1)
			{
				fLen *= 1;
			}
			else
			{
				if (iNPC_AlertLevel == 2)
				{
					fLen *= 1.2;
				}
				else
				{
					if (iNPC_AlertLevel == 3)
					{
						fLen *= 2;
					}
				}
			}
		}
		if (fLen < 0)
		{
			return false;
		}
		if (bAsleep)
		{
			return false;
		}
		if (fNPC_OldVisionDistanceChecked - FRand() * 256 < fLen || 1024 > fLen)
		{
			InvestigateObject=p;
			InvestigateTrackedPosition=p.Location;
			return true;
		}
		fNPC_OldVisionDistanceChecked=fLen;
		*/
	return false;
}
void AAgentController::NPC_UpdateOldVisionDistanceChecked()
{
	/*
		if (FRand() < fNPC_Experience)
		{
			if (fNPC_OldVisionDistanceChecked > 0)
			{
				fNPC_OldVisionDistanceChecked -= FRand() * fNPC_Experience;
			}
			else
			{
				fNPC_OldVisionDistanceChecked=0;
			}
		}
		*/
}
void AAgentController::NPC_AlertYourBuddies(APawn* p)
{
	/*
		local AgentController Buddy;
		local float HearIt;
		local float SeeIt;
		local FVector vec;
		ForEach DynamicActors('AgentController',Buddy)
		{
			if (APawn* == Buddy)
			{
			}
			else
			{
				if (bIsSniper)
				{
				}
				else
				{
					if (Buddy.Enemy != None)
					{
					}
					else
					{
						if (Buddy.iNPC_GroupID == iNPC_GroupID || bIsALeader)
						{
							if (bHandSignalsOnly)
							{
								vec=Buddy.Location - Pawn.Location;
								SeeIt=VSize(vec);
								if (Buddy.CanSee(Pawn) && SeeIt < AGP_Pawn(Pawn).fVisionDistance)
								{
									if (iNPC_AlertLevel < 3)
									{
										iNPC_AlertLevel ++;
									}
								}
							}
							else
							{
								if (Buddy.fNPC_ReactDelayTime == 0)
								{
									vec=Buddy.Location - Pawn.Location;
									HearIt=VSize(vec);
									if (HearIt < AGP_Pawn(Pawn).fHearingDistance)
									{
										if (iNPC_AlertLevel < 3)
										{
											iNPC_AlertLevel ++;
										}
										Buddy.fNPC_ReactDelayTime=Level.TimeSeconds + FRand() * 5 + 1 - fNPC_Experience * 3;
										Buddy.SetEnemy(Enemy);
									}
								}
							}
						}
					}
				}
			}
		}
		*/
}
bool AAgentController::NPC_CanReactDelayIsDone()
{
	/*
		if (fNPC_ReactDelayTime > Level.TimeSeconds)
		{
			return false;
		}
		fNPC_ReactDelayTime=0;
		return true;
		*/
	return false;    //FAKE /ELiZ
}
void AAgentController::AAgentController::NPC_EnemyDetection()
{
	/*
		local Pawn p;
		local FVector vVec;
		local float fLen;
		local FVector StartPos;
		local FVector EndPos;
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 1)
		{
			GOTO JL0263;
		}
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 5 || AGP_Pawn(Pawn).iNPC_ThinkType == 6)
		{
			ForEach DynamicActors(Class'Pawn',p)
			{
				if (p != None && PlayerController(p.Controller) == None)
				{
					if (AGP_Pawn(p).iNPC_ThinkType == 1)
					{
						vVec=p.Location - Pawn.Location;
						fLen=VSize(vVec);
						if (AGP_Pawn(Pawn).fVisionDistance > fLen)
						{
							StartPos=p.Location;
							if (p.bIsProne)
							{
								StartPos.Z += p.ProneEyeHeight;
							}
							else
							{
								if (p.bIsCrouched)
								{
									StartPos.Z += p.CrouchEyeHeight;
								}
								else
								{
									StartPos.Z += p.BaseEyeHeight;
								}
							}
							EndPos=Pawn.Location;
							if (Pawn.bIsProne)
							{
								EndPos.Z += Pawn.ProneEyeHeight;
							}
							else
							{
								if (Pawn.bIsCrouched)
								{
									EndPos.Z += Pawn.CrouchEyeHeight;
								}
								else
								{
									EndPos.Z += Pawn.BaseEyeHeight;
								}
							}
							if (CanSee(p) || FastTrace(p.Location,Pawn.Location))
							{
								SetEnemy(p);
								bTookDamage=true;
								bNewOrder=true;
								bAttackDone=true;
								CurrentOrder=2;
							}
						}
					}
				}
			}
	JL0263:
		}
		*/
}
void AAgentController::NPC_InvestigateThink()
{
	/*
		local FVector vVec;
		local float fLen;
		vVec=InvestigateObject.Location - Pawn.Location;
		fLen=VSize(vVec);
		if (1024 > fLen)
		{
			if (CanSee(InvestigateObject))
			{
				SetEnemy(InvestigateObject);
				Attack(fLen);
				NPC_Say(3,True,True,False);
				NPC_AlertYourBuddies(InvestigateObject);
			}
		}
		vVec=InvestigateTrackedPosition - Pawn.Location;
		fLen=VSize(vVec);
		if (200 > fLen)
		{
			NPC_GoToStart();
			NPC_Say(6,True,True,False);
		}
		*/
}
void AAgentController::NPC_InvestigateForceBuddyToSearch()
{
	/*
		local AgentController Buddy;
		local float HearIt;
		local float SeeIt;
		local FVector vec;
		ForEach DynamicActors('AgentController',Buddy)
		{
			if (Pawn == Buddy)
			{
			}
			else
			{
				if (bIsSniper)
				{
				}
				else
				{
					if (Buddy.Enemy != None)
					{
					}
					else
					{
						if (Buddy.iNPC_GroupID == iNPC_GroupID || bIsALeader)
						{
							if (bHandSignalsOnly)
							{
								vec=Buddy.Location - Pawn.Location;
								SeeIt=VSize(vec);
								if (Buddy.CanSee(Pawn) && SeeIt < AGP_Pawn(Pawn).fVisionDistance)
								{
									if (iNPC_AlertLevel < 3)
									{
										iNPC_AlertLevel ++;
									}
								}
							}
							else
							{
								if (Buddy.fNPC_ReactDelayTime == 0 && Buddy.bNPC_GoCheckItOut == False)
								{
									vec=Buddy.Location - Pawn.Location;
									HearIt=VSize(vec);
									if (HearIt < AGP_Pawn(Pawn).fHearingDistance)
									{
										if (iNPC_AlertLevel < 3)
										{
											iNPC_AlertLevel ++;
										}
										Buddy.fNPC_ReactDelayTime=Level.TimeSeconds + FRand() * 5 + 1 - fNPC_Experience * 10;
										Buddy.bNPC_GoCheckItOut=true;
										Buddy.InvestigateObject=InvestigateObject;
										Buddy.InvestigateTrackedPosition=InvestigateObject.Location;
										Buddy.EnemyTrackedPosition=InvestigateObject.Location;
										Buddy.NPC_Investigate();
										if (AGP_Pawn(Pawn).bIsBoss && InRange())
										{
											NPC_Say(Rand(10) + 4,True,False,False);
										}
										else
										{
											Buddy.NPC_Say(0,True,True,False);
										}
										if (Buddy.bHasWeapon == False)
										{
											Buddy.bHasWeapon=true;
											Buddy.NPC_GiveWeapon(1);
											Buddy.NPC_GiveAmmo();
										}
									}
								}
							}
						}
					}
				}
			}
		}
		*/
}
bool AAgentController::LookAround()
{
	/*
		if (fIsLookingTime < Level.TimeSeconds)
		{
			fIsLookingTime=Level.TimeSeconds + 2;
			DesiredRotation=Pawn.Rotation;
			if (bIsLookingAroundDir == True)
			{
				DesiredRotation.Yaw += 1024;
				bIsLookingAroundDir=false;
				bRotateToDesired=true;
			}
			else
			{
				DesiredRotation.Yaw -= 1024;
				bIsLookingAroundDir=true;
				bRotateToDesired=true;
			}
			return true;
		}
		*/
	return false;
}
bool AAgentController::NPC_GotBuzzed()
{
	/*
		if (AGP_Pawn(Pawn).IsHeDead())
		{
			return false;
		}
		if (AGP_Pawn(Pawn).NPC_isGotBuzzed() == True)
		{
			if (PUser != None || AGP_Pawn(Pawn).iNPC_ThinkType != 1)
			{
				if (FRand() > 0.5)
				{
					NPC_PilotSay(1,True);
				}
				else
				{
					NPC_PilotSay(5,True);
				}
			}
			else
			{
				if (AGP_Pawn(Pawn).bIsBoss)
				{
					NPC_Say(Rand(7) + 4,True,False,False);
				}
				else
				{
					NPC_Say(4,True,False,False);
				}
			}
			return true;
		}
		*/
	return false;
}
bool AAgentController::CheckGrenadeAwareTime()
{
	/*
		if (AGP_Pawn(Pawn).fGrenadeAwareTime > Level.TimeSeconds)
		{
			return false;
		}
		else
		{
			AGP_Pawn(Pawn).fGrenadeAwareTime=0;
		}
		*/
	return true;
}
void AAgentController::SetGrenadeAwareTime(float Time)
{
	/*
		AGP_Pawn(Pawn).fGrenadeAwareTime=Level.TimeSeconds + Time;
		*/
}
void AAgentController::ThreatGrenade()
{
	/*
		local float dist;
		local FVector vec;
		local FVector ZOffset;
		vec=FearGrenade.Location - Pawn.Location;
		dist=VSize(vec);
		ZOffset=Pawn.Location;
		ZOffset.Z=ZOffset.Z + Pawn.CrouchHeight;
		if (FastTrace(FearGrenade.Location,ZOffset) && dist < 1024)
		{
			Return FearGrenade;
		}
		Return None;
		*/
}
void AAgentController::NPC_GiveClip(int32 Num)
{
	/*
		AGP_Pawn(Pawn).iNPC_Clip=AGP_Pawn(Pawn).iNPC_Clip + Num;
		*/
}
void AAgentController::NPC_SetActorAttributes()
{
	/*
		fNPC_LikesToProne=AGP_Pawn(Pawn).NPC_LikesToProne / 100;
		fNPC_LikesToCrouch=AGP_Pawn(Pawn).NPC_LikesToCrouch / 100;
		fNPC_LikesToStand=AGP_Pawn(Pawn).NPC_LikesToStand / 100;
		fNPC_LikesToAmbush=AGP_Pawn(Pawn).NPC_LikesToAmbush / 100;
		fNPC_LikesToAssault=AGP_Pawn(Pawn).NPC_LikesToAssault / 100;
		fNPC_LikesToTalk=AGP_Pawn(Pawn).NPC_LikesToTalk / 100;
		fNPC_LikesToAmbient=AGP_Pawn(Pawn).NPC_LikesToAmbient / 100;
		fNPC_LikesToThrowGrenade=AGP_Pawn(Pawn).NPC_LikesToThrowGrenade / 100;
		fNPC_ShootAccuracy=AGP_Pawn(Pawn).NPC_ShootAccuracy / 100;
		fNPC_Experience=AGP_Pawn(Pawn).fNPC_Experience;
		iNPC_GroupID=AGP_Pawn(Pawn).iNPC_GroupID;
		iNPC_FragGrenade=AGP_Pawn(Pawn).iNPC_FragGrenade;
		iNPC_SmokeGrenade=AGP_Pawn(Pawn).iNPC_SmokeGrenade;
		iNPC_StunGrenade=AGP_Pawn(Pawn).iNPC_StunGrenade;
		bIsSniper=AGP_Pawn(Pawn).bIsSniper;
		if (bIsSniper)
		{
			Log("We have a sniper");
		}
		Pawn.PeripheralVision=0.7;
		SetDrawType(2);
		*/
}
void AAgentController::NPC_Think()
{
	/*
		if (bStart == False)
		{
			Level.Game.GameDifficulty=2;
			bStart=true;
			fStartHealth=AGP_Pawn(Pawn).Health;
			NPC_SetActorAttributes();
			if (AGP_Pawn(Pawn).bDummyPawn == True && AGP_Pawn(Pawn).NPC_Weapon != None)
			{
				bHasWeapon=true;
				NPC_GiveWeapon(1);
				NPC_GiveAmmo();
				NPC_GiveClip(10);
				Reload();
				Return;
			}
			if (Pawn.IsA('NPC_soldier'))
			{
				if (AGP_Pawn(Pawn).bIsScriptedWalking)
				{
					NPC_Walk(85);
				}
				if (AGP_Pawn(Pawn).NPC_ActorType() == 5 || AGP_Pawn(Pawn).NPC_ActorType() == 6)
				{
					bCanBeUsed=true;
					bNoFriendlyFire=true;
					fNPC_ShootAccuracy=1;
					AGP_Pawn(Pawn).iNPC_ThinkType=5;
					iNPC_GroupID=777;
				}
				else
				{
					AGP_Pawn(Pawn).iNPC_ThinkType=1;
				}
				if (AGP_Pawn(Pawn).iNPC_Clip == 0)
				{
					NPC_GiveClip(10);
				}
				if (iNPC_GroupID == 0)
				{
					iNPC_GroupID=1;
				}
				if (AGP_Pawn(Pawn).bIsStartsWithWeapon)
				{
					if (bHasWeapon == False)
					{
						bHasWeapon=true;
						NPC_GiveWeapon(1);
						NPC_GiveAmmo();
					}
				}
				Start();
			}
			else
			{
				if (Pawn.IsA('NPC_TowerObserver'))
				{
				}
				if (Pawn.IsA('NPC_doctor') || Pawn.IsA('NPC_Ambient') || Pawn.IsA('NPC_civilian'))
				{
					if (AGP_Pawn(Pawn).iNPC_ThinkType == 5 || AGP_Pawn(Pawn).iNPC_ThinkType == 6 || AGP_Pawn(Pawn).NPC_ActorType() == 5 || AGP_Pawn(Pawn).NPC_ActorType() == 6)
					{
						fNPC_ShootAccuracy=1;
						AGP_Pawn(Pawn).fNPC_Agressiveness=100;
						bCanBeUsed=true;
						AGP_Pawn(Pawn).iNPC_ThinkType=5;
						iNPC_GroupID=777;
						if (AGP_Pawn(Pawn).iNPC_Clip == 0)
						{
							NPC_GiveClip(30);
						}
						if (bHasWeapon == False)
						{
							bHasWeapon=true;
							NPC_GiveWeapon(1);
							NPC_GiveAmmo();
						}
					}
					else
					{
						bCanBeUsed=true;
						AGP_Pawn(Pawn).iNPC_ThinkType=3;
						if (AGP_Pawn(Pawn).iNPC_Clip == 0)
						{
							NPC_GiveClip(0);
						}
					}
					Start();
				}
			}
		}
		*/
}
bool AAgentController::NPC_CheckIfDead()
{
	/*
		if (bIsDead == False && AGP_Pawn(Pawn).IsHeDead())
		{
			SetPhysics(0);
			bIsDead=true;
			NPC_DeathFX();
			return true;
		}
		else
		{
			if (bIsDead_Dead == True)
			{
				NPC_DeadDead();
				return true;
			}
		}
		*/
	return false;
}
void AAgentController::Timer()
{
	/*
		NPC_Think();
		*/
}

void AAgentController::BeginPlay()
{
	/*
		SetTimer(1,True);
		*/
}

void AAgentController::UsedBy(APawn* User)
{
	/*
		if (AGP_Pawn(Pawn).bIsScripted)
		{
			AGP_Pawn(Pawn).bIsScripted=false;
			return true;
		}
		if (bCanBeUsed == True)
		{
			if (fWait < Level.TimeSeconds)
			{
				return true;
			}
		}
		return false;
		*/
}

bool AAgentController::isTouched()
{
	if (bTouched == true)
	{
		bTouched=false;
		return true;
	}
	bTouched=false;
	PToucher=nullptr;
	return false;
}

void AAgentController::Touch(AActor* Other)
{
	/*
		local Pawn User;
		local AGP_Pawn IDPawn;
		bTouched=true;
		if (Other.IsA('AuxCollisionCylinder'))
		{
			IDPawn=AGP_Pawn(AuxCollisionCylinder(Other).Owner);
			User=IDPawn;
			PToucher=User;
			touchLocation=PToucher.Location;
		}
		if (User == None)
		{
			Return;
		}
		if (Pawn.IsA('NPC_soldier'))
		{
			if (IDPawn.Controller.IsA('HumanController'))
			{
				if (AGP_Pawn(Pawn).NPC_ActorType() != 5 || AGP_Pawn(Pawn).NPC_ActorType() != 6)
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldStand(True);
					}
					iNPC_AlertLevel=3;
					SetEnemy(User);
					bTookDamage=true;
					if (AGP_Pawn(Pawn).IsHeDead() == True && bIsDead_Dead == True)
					{
						bDeadDeadTwitch=true;
					}
					if (AGP_Pawn(Pawn).bIsBoss)
					{
						NPC_Say(Rand(14) + 4,True,False,False);
					}
					else
					{
						NPC_Say(24,True,False,False);
					}
				}
			}
		}
		Return;
		*/
}

void AAgentController::ClosestNavPoint()
{
	/*
		local NavigationPoint N;
		local NavigationPoint dN;
		local float Distance;
		local float fLen;
		Distance=99999;
		N=Level.NavigationPointList;
		if (N != None)
		{
			fLen=VSize(N.Location - Pawn.Location);
			if (fLen < Distance && FastTrace(N.Location,Pawn.Location) && MoveObject != N)
			{
				dN=N;
				Distance=fLen;
			}
			N=N.nextNavigationPoint;
		}
		Return dN;
		*/
}
void AAgentController::FindCoverNode(FVector VPosition)
{
	/*
		local NavigationPoint N;
		local FVector vVec;
		local NavigationPoint Dest;
		local float fOldLen;
		local float fLen;
		fOldLen=99999;
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (PathNode(N).NodeType != 1)
			{
			}
			if (N == NCoverPlace)
			{
			}
			if (PathNode(N).CoverTaken > 2)
			{
			}
			vVec=N.Location - Pawn.Location;
			fLen=VSize(vVec);
			if (fLen < fOldLen)
			{
				fOldLen=fLen;
				Dest=N;
				PathNode(N).CoverTaken ++;
			}
			N=N.nextNavigationPoint;
		}
		NCoverPlace=Dest;
		Return Dest;
		*/
}
void AAgentController::FindSafePlaceFrom(FVector InstigatedByLocation, bool bNear, bool abHunting)
{
	/*
		local NavigationPoint N;
		local NavigationPoint DestN;
		local float Distance;
		local FVector vVec;
		local float fLen;
		local float fLenToPlayer;
		local float fLenToLocation;
		local float fMINDIST;
		fMINDIST=256;
		DestN=nullptr;
		if (bNear == True)
		{
			Distance=99999;
		}
		else
		{
			Distance=0;
		}
		fLenToPlayer=0;
		fLenToLocation=0;
		fLen=0;
		N=Level.NavigationPointList;
		if (N != None)
		{
			vVec=N.Location - Pawn.Location;
			fLenToLocation=VSize(vVec);
			fLen=fLenToLocation;
			if (SafeDestN == N)
			{
			}
			if (! FastTrace(N.vFloor,InstigatedByLocation))
			{
				vVec=N.Location - InstigatedByLocation;
				fLenToPlayer=VSize(vVec);
				if (abHunting == True)
				{
					if (fLenToLocation > fLenToPlayer)
					{
						if (bNear == True)
						{
							if (fLen < Distance && fLen > fMINDIST)
							{
								Distance=fLen;
								DestN=N;
							}
						}
						else
						{
							if (fLen > Distance)
							{
								Distance=fLen;
								DestN=N;
							}
						}
					}
				}
				else
				{
					if (fLenToLocation < fLenToPlayer)
					{
						if (bNear == True)
						{
							if (fLen < Distance)
							{
								Distance=fLen;
								DestN=N;
							}
						}
						else
						{
							if (fLen > Distance)
							{
								Distance=fLen;
								DestN=N;
								Log("FindSafePlaceFrom: " $ Distance);
							}
						}
					}
				}
			}
			N=N.nextNavigationPoint;
		}
		Return DestN;
		*/
}
/*

void AAgentController::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* AHitMaterial)
{
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 1)
		{
			iNPC_AlertLevel=3;
			SetEnemy(instigatedBy);
			if (bTookDamage == False)
			{
				CurrentOrder=12;
			}
			bTookDamage=true;
			if (AGP_Pawn(Pawn).IsHeDead() == True && bIsDead_Dead == True)
			{
				bDeadDeadTwitch=true;
			}
			if (AGP_Pawn(Pawn).bIsBoss)
			{
				NPC_Say(Rand(14) + 4,True,False,False);
			}
			else
			{
				NPC_Say(24,True,False,False);
			}
		}
		else
		{
			if (AGP_Pawn(Pawn).iNPC_ThinkType == 5 || AGP_Pawn(Pawn).iNPC_ThinkType == 6)
			{
				SetEnemy(instigatedBy);
				if (bTookDamage == False)
				{
					CurrentOrder=12;
				}
				bTookDamage=true;
				if (AGP_Pawn(Pawn).IsHeDead() == True && bIsDead_Dead == True)
				{
					bDeadDeadTwitch=true;
				}
				Attack(1);
				NPC_Say(24,True,False,True);
			}
			else
			{
				fNPC_TalkFrequency=1;
				NPC_PilotSay(Rand(3) + 2,False);
			}
		}
}
*/
void AAgentController::GrenadeTakeCover(bool bProne)
{
	/*
		bGrenadeCheck=false;
		TakeCover(bProne);
		*/
}
void AAgentController::infront(FVector vec, APawn* Who)
{
	/*
		local FVector LookDir;
		local FVector AimDir;
		LookDir= Vector(Who.Rotation);
		LookDir=Normal(LookDir);
		AimDir=vec - Who.Location;
		AimDir=Normal(AimDir);
		Return LookDir Dot AimDir;
		*/
}
void AAgentController::NPC_PilotSay(int32 Snd, bool Force)
{
	/*
		local Actor SoundActor;
		local Sound SoundPtr;
		if (fNPC_LastTalkTime < Level.TimeSeconds || Force == True)
		{
			fNPC_LastTalkTime=Level.TimeSeconds + 1 * FRand() + 2;
			SoundPtr=sPilot[Snd];
			if (SoundPtr != None)
			{
				SoundActor=Spawn(Class'EffectLocation',,,Pawn.Location);
				SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
				SoundActor.PlaySound(SoundPtr,0,1,,,,False);
			}
		}
		*/
}
void AAgentController::NPC_Say(int32 theSound, bool shout, bool forceplay, bool bFriend)
{
	/*
		local Actor SoundActor;
		local Sound SoundPtr;
		local int R;
		if (AGP_Pawn(Pawn).iNPC_ThinkType == 5 || AGP_Pawn(Pawn).iNPC_ThinkType == 6)
		{
			if (Level.bCoOpGame)
			{
				bFriend=true;
			}
		}
		if (FRand() > fNPC_TalkFrequency && fNPC_LastTalkTime < Level.TimeSeconds || forceplay == True)
		{
			fNPC_LastTalkTime=Level.TimeSeconds + 5 * FRand() + 5;
			if (! AGP_Pawn(Pawn).bIsBoss)
			{
				if (theSound == 999)
				{
					R=Rand(27);
				}
				else
				{
					R=theSound;
				}
				if (shout == True)
				{
					if (bFriend)
					{
						SoundPtr=sShoutFriendly[R];
					}
					else
					{
						SoundPtr=sShoutEnemy[R];
					}
				}
				else
				{
					R=Rand(27);
					if (bFriend)
					{
						SoundPtr=sWhisperFriendly[R];
					}
					else
					{
						SoundPtr=sWhisperEnemy[R];
					}
				}
			}
			else
			{
				R=theSound;
				SoundPtr=sEnemyLeader[R];
			}
			if (SoundPtr != None)
			{
				SoundActor=Spawn(Class'EffectLocation',,,Pawn.Location);
				SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
				SoundActor.PlaySound(SoundPtr,0,1,,,,False);
			}
		}
		*/
}