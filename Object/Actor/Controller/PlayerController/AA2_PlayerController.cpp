// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/AA2_PlayerController.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "AA29/Object/Actor/Info/VoicePack/VoicePack.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/Object/CheatManager/AA2_CheatManager.h"
#include "AA29/Object/CameraEffect/CameraEffect.h"
#include "AA29/Object/Actor/Info/SavedMove/SavedMove.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VotingReplicationInfoBase/VotingReplicationInfoBase.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/LocalMessage/ChatRoomMessage/ChatRoomMessage.h"
#include "AA29/Object/Actor/Info/MaplistManagerBase/MaplistManagerBase.h"
#include "AA29/Object/Actor/Info/PlayerChatManager/PlayerChatManager.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/AnnouncerQueueManager/AnnouncerQueueManager.h"
#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoard.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/AdminBase/AdminBase.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Info/LocalMessage/GameMessage/GameMessage.h"
#include "AA29/Object/DamageType/Suicided/Suicided.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "GameFramework/LocalMessage.h"
#include "Engine/Canvas.h"

AAA2_PlayerController::AAA2_PlayerController()
{
	bAlwaysMouseLook = true;
	bKeyboardLook = true;
	bCanFire = true;
	bZeroRoll = true;
	bAllowScoreShown = true;
	bNoTextToSpeechVoiceMessages = true;
	bDynamicNetSpeed = true;
	bSmallWeapons = true;
	bWeaponViewShake = true;
	bLandingShake = true;
	bForceFeedbackSupported = true;
	bVoiceChatEnabled = true;
	bEnableInitialChatRoom = true;
	FOVBias = 1;
	AutoJoinMask = 5;
	AnnouncerLevel = 2;
	AnnouncerVolume = 4;
	TextToSpeechVoiceVolume = 1;
	MaxResponseTime = 0.125;
	VehicleCheckRadius = 700;
	OrthoZoom = 40000;
	CameraDist = 9;
	CameraDistRange = FRange({ 3, 40 });
	DesiredFOV = 85;
	DefaultFOV = 85;
	FlashScale = FVector(1, 1, 1);
	ScreenFlashScaling = 1;
	bPauseMusic = true;
	ProgressTimeOut = 8;
	QuickSaveString = "Quick Saving";
	NoPauseMessage = "Game is not pauseable";
	ViewingFrom = "Now viewing from";
	OwnCamera = "Now viewing from own camera";
	//LocalMessageClass = class'Engine.LocalMessage';
	//ChatRoomMessageClass = AChatRoomMessage::StaticClass();
	EnemyTurnSpeed = -20536;
	//CheatClass = class'Engine.CheatManager';
	//InputClass = class'Engine.PlayerInput';
	PlayerChatType = "Engine.PlayerChatManager";
	TeamBeaconMaxDist = 6000;
	TeamBeaconPlayerInfoMaxDist = 1800;
	TeamBeaconTeamColors = {
		FColor(0, 0, 180, 255),
		FColor(200, 80, 80, 255)
	};
	TeamBeaconCustomColor = FColor(0, 255, 255, 255);
	SoundDampening = 1;
	SpectatorSpeedScalar = 0.06;
	bShowRadarBlinking = true;
	SpectateSpeed = 600;
	DynamicPingThreshold = 400;
	MidGameMenuClass = "GUI2K4.UT2K4DisconnectOptionPage";
	DemoMenuClass = "AGP_Interface.AAGameMenu_DemoControls";
	AdminMenuClass = "GUI2K4.RemoteAdmin";
	ChatPasswordMenuClass = "AGP_Interface.AAChatPassword";
	VoiceChatCodec = "CODEC_48NB";
	VoiceChatLANCodec = "CODEC_96WB";
	LastSpeedHackLog = -100;
	PlayerStatsIndex = -1;
	bNotifyMedicAtRoundStart = true;
	bIsPlayer = true;
	bCanOpenDoors = true;
	bCanDoSpecial = true;
	NetPriority = 3;
	//bTravel = true;
}

/*
replication
{
	reliable if (((bNetDirty && bNetOwner) && (Role == ROLE_Authority)))
		GameReplicationInfo, VoiceReplicationInfo, ChatManager, LoginDelay;
	reliable if ((((bNetOwner && (Role == ROLE_Authority)) && (ViewTarget != Pawn)) && (Cast<APawn>(ViewTarget) != nullptr)))
		TargetViewRotation, TargetEyeHeight;
	reliable if ((bDemoRecording && (Role == ROLE_Authority)))
		DemoViewPitch, DemoViewYaw;
	reliable if ((Role == ROLE_Authority))
		ClientSetActiveRoom, ClientSetTimeRemaining, ClientNetworkMessage, ClientCloseMenu, ClientReplaceMenu, ClientOpenMenu, ClientReStart, SimpleClientRestart, SetProgressTime, SetProgressMessage, ClearProgressMessages, ProgressCommand, ClientAdjustGlow, ClientSetBehindView, ClientSetFixedCamera, ClientSetMusic, ClientReliablePlaySound, ChatRoomMessage, ClientSetHUD, GivePawn, ClientGotoState, ClientReset, ClientSetScoreMode, ClientSetViewTarget, ClientCapBandwidth, ClientSetWeaponViewShake, ClientSetAccessControlKickMessage, ClientValidate, ClientNotifyAdminMessage;
	reliable if ((Role == ROLE_Authority))
		QueueAnnouncement, TeamMessage, ClientMessage, ReceiveLocalizedMessage;
	reliable if (((Role == ROLE_Authority) && (!bDemoRecording)))
		ClientPlaySound, PlayAnnouncement, PlayRewardAnnouncement, PlayStatusAnnouncement;
	reliable if (((Role == ROLE_Authority) && (!bDemoRecording)))
		ClientStopForceFeedback, ClientSetClassicView, ClientTravel;
	reliable if ((Role == ROLE_Authority))
		OpenDemoControls, ClientDamageShake, ClientFlash, LongClientAdjustPosition, ClientAdjustPosition, ShortClientAdjustPosition, VeryShortClientAdjustPosition, ClientUpdateFlagHolder;
	reliable if ((((!bDemoRecording) || (bClientDemoRecording && bClientDemoNetFunc)) && (Role == ROLE_Authority)))
		ClientHearSound;
	reliable if ((bClientDemoRecording && (Role == ROLE_Authority)))
		DemoClientSetHUD;
	reliable if ((Role < ROLE_Authority))
		ServerUpdatePing, ServerMove, ShortServerMove, RocketServerMove;
	reliable if ((Role < ROLE_Authority))
		ServerShortTimeout;
	reliable if ((Role < ROLE_Authority))
		ServerVoiceCommand, ServerViewSelf, ServerViewNextPlayer, ServerToggleBehindView, ServerUse, ServerDrive, DualServerMove, DualTurretServerMove, TurretServerMove, DualSpaceFighterServerMove, SpaceFighterServerMove, DualRocketServerMove, ServerSetHandedness, ServerSetAutoTaunt, ServerTeamSay;
	reliable if ((Role < ROLE_Authority))
		ServerSetClientDemo, BecomeActivePlayer, BecomeSpectator, ServerSpectate, BehindView, ServerChangeTeam, ChangeName, ChangeVoiceType, Suicide, ActivateItem, PrevItem, NextWeapon, PrevWeapon, ServerThrowWeapon, ServerPause, SetPause, ServerSpeech, Typing, ServerRestartGame, ServerMutate, ServerAcknowledgePossession, AskForPawn, LockPlayer, ServerVerifyViewTarget, ServerSpectateSpeed, BanPlayer, KickPlayer, ServerUpdateSelfHealActionState, ServerValidationResponse;
	reliable if ((Role < ROLE_Authority))
		ServerChatRestriction, ServerRequestBanInfo, ServerChangeVoiceChatMode, ServerSetChatPassword, ServerSpeak, ServerLeaveVoiceChannel, ServerJoinVoiceChannel, ServerGetWeaponStats;
	reliable if ((Role < ROLE_Authority))
		ServerChatDebug;
	reliable if ((Role == ROLE_Authority))
		ClientBecameActivePlayer, ClientBecameSpectator, ResetFOV;
	reliable if ((Role == ROLE_Authority))
		NotifyPlayerOfMedicStatus, ClientDisconnect, ClientOpenMap, ResetSkinsAndMeshes, SetFOVAngle, ClientLockPlayer, SetServerSettingReply, QueryServerListReply, NotifyNoScore, NotifyPromotion;
	reliable if ((Role == ROLE_Authority))
		TelnetMessage;
	reliable if ((Role < ROLE_Authority))
		RequestChangeTeam, ServerAddDistributionKey, ServerUTrace, SetServerKeyValue, SetServerKey, SetServerSetting, SetServerSection, QueryServerList;
	reliable if (((Role == ROLE_Authority) && (!bDemoRecording)))
		ClientGrenaded, ClientFlashBanged, ClientStartScreenShake;
	reliable if ((Role < ROLE_Authority))
		ServerUploadStats, ServerUploadTrustAndExperience;
}
*/

/*
State PlayerWalking
{
	simulated Function int32 GetTraceDistance()
	{
		return int((float(Pawn.GetShortTraceDistance()) * 0.75));
	}
	void Fire(float F)
	{
		if (CanFire())
		{
			Global.CollisionRadius(F);
		}
	}
	Function bool NotifyPhysicsVolumeChange(APhysicsVolume * NewVolume)
	{
		if (NewVolume.bWaterVolume)
		{
			GotoState(Pawn.WaterMovementState);
		}
		return false;
	}
	Function bool TestWeaponGuard()
	{
		if (((((Pawn.Weapon != nullptr) && (Pawn.Physics == 1)) && (!Pawn.bIsDead)) && (!Pawn.IsSupported())) && (!Pawn.bIsSprinting))
		{
			switch (Pawn.UpperBodyAnim)
			{
				case 2:
				case 6:
				case 25:
				case 26:
				case 29:
				case 30:
				case 33:
				case 34:
				case 39:
				case 40:
				case 69:
				case 67:
				case 75:
				case 74:
				return true;
				default:
			}
			return false;
		}
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		AActor* HitActor = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		if (GetPawn() == nullptr)
		{
			return;
		}
		UpdateTimers(DeltaTime);
		if (!IsZero(NewAccel))
		{
			Pawn.SpeedRatio = Pawn.GetSpeedModifier();
			Pawn.SpeedRatio_Always = Pawn.GetSpeedModifier_Always();
			Pawn.ResetLean();
		}
		if ((DoubleClickMove == 3) && Pawn.bCanSprint)
		{
			if (Pawn.bIsProne || Pawn.bIsCrouched)
			{
				Pawn.ShouldStand();
			}
			Pawn.SetWalking(false);
			if (Pawn.CanSprint() && (!Pawn.IsInState("BusyDrawing")))
			{
				Pawn.bWantsToSprint = true;
			}
		}
		else
		{
			if (Pawn.bWantsToRollLeft || Pawn.bWantsToRollRight)
			{
				if (Pawn.CanCombatRoll(false))
				{
					if (Pawn.IsSupported())
					{
						Pawn.SetSupported(false,true);
					}
					else
					{
						if (Pawn.IsZoomed())
						{
							Pawn.Weapon.ForceUnzoom();
						}
					}
					if (Pawn.CanCombatRoll(true))
					{
						if (Pawn.bWantsToRollLeft)
						{
							Pawn.iRollDirection = Pawn. - 1;
							GotoState("PlayerRolling");
						}
						else
						{
							Pawn.iRollDirection = Pawn.1;
							GotoState("PlayerRolling");
						}
						Pawn.bWantsToRollLeft = false;
						Pawn.bWantsToRollRight = false;
					}
				}
				else
				{
					Pawn.bWantsToRollLeft = false;
					Pawn.bWantsToRollRight = false;
				}
			}
		}
		if (TestWeaponGuard())
		{
			GetAxes(Rotation,X,Y,Z);
			HitActor = Pawn.Trace(HitLocation,HitNormal,(Pawn.Weapon.GetFireStart(X,Y,Z) + (X * Pawn.Weapon.WallTraceDist)),Pawn.Weapon.GetFireStart(X,Y,Z),true);
			if (((HitActor != nullptr) && ((HitNormal Dot Pawn.Floor) < 0.7)) || Pawn.bUsingObjective)
			{
				switch (Pawn.UpperBodyAnim)
				{
					case 2:
					Pawn.GuardWeapon3p(6);
					break;
					case 25:
					Pawn.GuardWeapon3p(26);
					break;
					case 29:
					Pawn.GuardWeapon3p(30);
					break;
					case 33:
					Pawn.GuardWeapon3p(34);
					break;
					case 39:
					Pawn.GuardWeapon3p(40);
					break;
					case 67:
					Pawn.GuardWeapon3p(69);
					break;
					case 75:
					Pawn.GuardWeapon3p(74);
					break;
					default:
				}
			}
			else
			{
				switch (Pawn.UpperBodyAnim)
				{
					case 69:
					case 74:
					case 6:
					case 26:
					case 30:
					case 34:
					case 40:
					Pawn.UpperBodyAnimComplete();
					default:
				}
				break;
			}
			switch (Pawn.UpperBodyAnim)
			{
				case 69:
				case 74:
				case 6:
				case 26:
				case 30:
				case 34:
				case 40:
				Pawn.UpperBodyAnimComplete();
				default:
			}
			if (Pawn.Acceleration != NewAccel)
			{
				Pawn.Acceleration = NewAccel;
			}
			if (bPressedJump)
			{
				Pawn.DoJump(bUpdating);
				Pawn.bMidJump = true;
			}
			if (((((Pawn.bWasCrouched != Pawn.bIsCrouched) || (Pawn.bWasProne != Pawn.bIsProne)) && (!Pawn.bTransitionAnim)) || (Pawn.bWasWalking != Pawn.bIsWalking)) || (Pawn.bWasSprinting != Pawn.bIsSprinting))
			{
				Pawn.ChangeAnimation();
			}
		}
	}
	Function FVector CalcAcceleration(FVector X, FVector Y, FVector Z, FRotator & ViewRotation)
	{
		FVector Accel = FVector(0,0,0);
		Accel = ((aForward * X) + (aStrafe * Y));
		Accel.Z = 0;
		return Accel;
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector NewAccel = FVector(0,0,0);
		EDoubleClickDir DoubleClickMove;
		FRotator OldRotation = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		bool bSaveJump = false;
		if (GetPawn() == nullptr)
		{
			GotoState("Dead");
			return;
		}
		if (Pawn.isDead())
		{
			return;
		}
		GetAxes(Pawn.Rotation,X,Y,Z);
		NewAccel = ((aForward * X) + (aStrafe * Y));
		NewAccel.Z = 0;
		if ((VSize(NewAccel) < 1) || Pawn.IsSupported())
		{
			NewAccel = FVector(0,0,0);
		}
		GroundPitch = 0;
		ViewRotation = Rotation;
		DoubleClickMove = PlayerInput->CheckForDoubleClickMove(((1.1 * DeltaTime) / Level.TimeDilation));
		if (!bPerfectAccuracy)
		{
			(ViewRotation += Pawn.BreatheCycle(DeltaTime));
		}
		if ((bSprint != 0) && (aForward > 0))
		{
			DoubleClickMove = 3;
		}
		if (PlayerInput->bLockMovement)
		{
			DoubleClickMove = 0;
		}
		if (Pawn.Weapon != nullptr)
		{
			if (Pawn.Weapon.IsZoomed())
			{
				if ((Pawn.Physics == 2) || ((!Pawn.bIsWalking) && (!IsZero(NewAccel))))
				{
					Pawn.Weapon.ForceUnzoom(true);
				}
			}
		}
		if (Pawn.bIsProne)
		{
			(aTurn *= 0.5);
		}
		else
		{
			if (Pawn.IsZoomed())
			{
				(aTurn *= 0.5);
			}
		}
		if (Pawn.Physics == 1)
		{
			if ((bLook == 0) && (((Pawn.Acceleration != FVector(0,0,0)) && bSnapToLevel) || (!bKeyboardLook)))
			{
				if (bLookUpStairs || bSnapToLevel)
				{
					GroundPitch = FindStairRotation(DeltaTime);
					ViewRotation.Pitch = GroundPitch;
				}
				else
				{
					if (bCenterView && (!bool(bAction)))
					{
						ViewRotation.Pitch = (ViewRotation.Pitch & 65535);
						if (ViewRotation.Pitch > 32768)
						{
							(ViewRotation.Pitch -= 65536);
						}
						ViewRotation.Pitch = int((float(ViewRotation.Pitch) * (1 - (float(12) * FMin(0.0833,DeltaTime)))));
						if (FMath::Abs(float(ViewRotation.Pitch)) < float(1000))
						{
							ViewRotation.Pitch = -249;
						}
					}
				}
			}
		}
		else
		{
			if ((((!bKeyboardLook) && (bLook == 0)) && bCenterView) && (!bool(bAction)))
			{
				ViewRotation.Pitch = (ViewRotation.Pitch & 65535);
				if (ViewRotation.Pitch > 32768)
				{
					(ViewRotation.Pitch -= 65536);
				}
				ViewRotation.Pitch = int((float(ViewRotation.Pitch) * (1 - (float(12) * FMin(0.0833,DeltaTime)))));
				if (FMath::Abs(float(ViewRotation.Pitch)) < float(1000))
				{
					ViewRotation.Pitch = -249;
				}
			}
		}
		Pawn.CheckBob(DeltaTime,Y);
		SetActorRotation(ViewRotation);
		OldRotation = Rotation;
		UpdateRotation(DeltaTime,1);
		if (bPressedJump && Pawn.CannotJumpNow())
		{
			bSaveJump = true;
			bPressedJump = false;
		}
		else
		{
			bSaveJump = false;
		}
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		bPressedJump = bSaveJump;
	}
	Function BeginState()
	{
		if (ViewTarget != Pawn)
		{
			SetViewTarget(Pawn);
		}
		DoubleClickDir = 0;
		bPressedJump = false;
		GroundPitch = 0;
		if (Pawn != nullptr)
		{
			if (Pawn.Mesh == nullptr)
			{
				Pawn.SetMesh();
			}
			if ((Pawn.Physics != 2) && (Pawn.Physics != 13))
			{
				Pawn.SetPhysics(PHYS_Walking);
			}
			if (Pawn.Weapon != nullptr)
			{
				Pawn.Weapon.StopCrawling();
			}
			Pawn.ResetLean();
		}
	}
	Function EndState()
	{
		GroundPitch = 0;
	}
}
*/

/*
State PlayerCrouching extends PlayerWalking
{
	simulated Function int32 GetTraceDistance()
	{
		return int((float(Pawn.GetShortTraceDistance()) * 0.5));
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "PlayerController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (Pawn != nullptr)
		{
			Pawn.AccelRate = 2048;
			Pawn.bWantsToSprint = false;
			if (!Pawn.bIsWalking)
			{
				Pawn.GroundSpeed = Pawn.fFastCrouchSpeed;
			}
			else
			{
				Pawn.GroundSpeed = Pawn.fCrouchSpeed;
			}
		}
	}
}
*/

/*
State PlayerCrawling extends PlayerWalking
{
	simulated Function int32 GetTraceDistance()
	{
		return int((float(Pawn.GetShortTraceDistance()) * 0.375));
	}
	simulated Function bool ClientRejectStateTransition(FName NewState)
	{
		return (NewState == "PlayerRolling");
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		Super::ProcessMove(DeltaTime,NewAccel,DoubleClickMove,DeltaRot);
		if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
		{
			if ((!IsZero(NewAccel)) && (!Pawn.bTransitionAnim))
			{
				if (!Pawn.Weapon.IsCrawling())
				{
					if ((!Pawn.Weapon.IsInState("OutCrawling")) && (Pawn.CrawlTimer > 0.5))
					{
						Pawn.Weapon.StartCrawling();
					}
					else
					{
						(Pawn.CrawlTimer += DeltaTime);
					}
				}
			}
			else
			{
				Pawn.Weapon.StopCrawling();
				Pawn.CrawlTimer = 0;
			}
		}
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "PlayerController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (Pawn != nullptr)
		{
			Pawn.AccelRate = 2048;
			Pawn.bWantsToSprint = false;
			if (!Pawn.bIsWalking)
			{
				Pawn.GroundSpeed = Pawn.fHCrawlSpeed;
			}
			else
			{
				Pawn.GroundSpeed = Pawn.fLCrawlSpeed;
			}
		}
	}
	Function EndState()
	{
		Super::EndState();
		if (Pawn != nullptr)
		{
			if (Pawn.Weapon != nullptr)
			{
				Pawn.Weapon.StopCrawling();
			}
		}
	}
}
*/

/*
State PlayerClimbing
{
	void Fire(float F)
	{
	}
	void AltFire(float F)
	{
	}
	void SupportedFire()
	{
	}
	Function DropSpecificItem(AInventory * Item)
	{
	}
	simulated Function int32 GetTraceDistance()
	{
		return int((float(Pawn.GetShortTraceDistance()) * 0.25));
	}
	Function bool NotifyPhysicsVolumeChange(APhysicsVolume * NewVolume)
	{
		if (NewVolume.bWaterVolume)
		{
			GotoState(Pawn.WaterMovementState);
		}
		else
		{
			GotoState(Pawn.LandMovementState);
		}
		return false;
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		FVector OldAccel = FVector(0,0,0);
		UpdateTimers(DeltaTime);
		OldAccel = Pawn.Acceleration;
		if (Pawn.Acceleration != NewAccel)
		{
			Pawn.Acceleration = NewAccel;
		}
		if (bPressedJump)
		{
			Pawn.DoJump(bUpdating);
			if (Pawn.Physics == 2)
			{
				GotoState("PlayerWalking");
			}
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector NewAccel = FVector(0,0,0);
		EDoubleClickDir DoubleClickMove;
		FRotator OldRotation = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		bool bSaveJump = false;
		if (Pawn.OnLadder != nullptr)
		{
			GetAxes(Pawn.OnLadder.WallDir,X,Y,Z);
			NewAccel = ((aForward * Pawn.OnLadder.ClimbDir) + (aStrafe * Y));
		}
		else
		{
			GetAxes(Rotation,X,Y,Z);
			NewAccel = ((aForward * X) + (aStrafe * Y));
		}
		if (VSize(NewAccel) < 1)
		{
			NewAccel = FVector(0,0,0);
		}
		ViewRotation = Rotation;
		SetActorRotation(ViewRotation);
		OldRotation = Rotation;
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		bPressedJump = bSaveJump;
	}
	Function BeginState()
	{
		Pawn.ShouldCrouch(false);
		Pawn.UpperBodyAnimComplete();
		bPressedJump = false;
		if (Pawn != nullptr)
		{
			if (Pawn.Weapon != nullptr)
			{
				Pawn.Weapon.ForceUnzoom();
			}
		}
	}
	Function EndState()
	{
		if (Pawn != nullptr)
		{
			Pawn.ShouldCrouch(false);
		}
	}
}
*/

/*
State PlayerDriving
{
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
	}
	Function ProcessDrive(float InForward, float InStrafe, float InUp, bool InJump)
	{
		AVehicle* CurrentVehicle = nullptr;
		CurrentVehicle = Vehicle(Pawn);
		if (CurrentVehicle == nullptr)
		{
			return;
		}
		CurrentVehicle.Throttle =FMath::Clamp((InForward / 5000),-1,1);
		CurrentVehicle.Steering =FMath::Clamp(((-InStrafe) / 5000),-1,1);
		CurrentVehicle.Rise =FMath::Clamp((InUp / 5000),-1,1);
	}
	Function PlayerMove(float DeltaTime)
	{
		AVehicle* CurrentVehicle = nullptr;
		float NewPing = 0;
		CurrentVehicle = Vehicle(Pawn);
		UpdateRotation(DeltaTime,2);
		if (Role < 4)
		{
			if ((((GetWorld()->GetTimeSeconds() - LastPingUpdate) > 4) && (PlayerReplicationInfo != nullptr)) && (!bDemoOwner))
			{
				LastPingUpdate = GetWorld()->GetTimeSeconds();
				NewPing = float(ConsoleCommand("GETPING"));
				if (ExactPing < 0.006)
				{
					ExactPing = FMin(0.1,(0.001 * NewPing));
				}
				else
				{
					ExactPing = ((0.99 * ExactPing) + (0.0001 * NewPing));
				}
				PlayerReplicationInfo->Ping = uint8(Min(int((float(250) * ExactPing)),255));
				PlayerReplicationInfo->bReceivedPing = true;
				OldPing = ExactPing;
				ServerUpdatePing(int((float(1000) * ExactPing)));
			}
			if (((((((!bSkippedLastUpdate) && (Player.CurrentNetSpeed < 10000)) && ((GetWorld()->GetTimeSeconds() - ClientUpdateTime) < 0.0222)) && (bPressedJump == bLastPressedJump)) && ((aUp - aLastUp) < 0.01)) && ((aForward - aLastForward) < 0.01)) && ((aStrafe - aLastStrafe) < 0.01))
			{
				bSkippedLastUpdate = true;
				return;
			}
			else
			{
				bSkippedLastUpdate = false;
				ClientUpdateTime = GetWorld()->GetTimeSeconds();
				bLastPressedJump = bPressedJump;
				aLastUp = aUp;
				aLastForward = aForward;
				aLastStrafe = aStrafe;
				if (CurrentVehicle != nullptr)
				{
					CurrentVehicle.Throttle =FMath::Clamp((aForward / 5000),-1,1);
					CurrentVehicle.Steering =FMath::Clamp(((-aStrafe) / 5000),-1,1);
					CurrentVehicle.Rise =FMath::Clamp((aUp / 5000),-1,1);
				}
				ServerDrive(aForward,aStrafe,aUp,bPressedJump,(((32767 & (Rotation.Pitch / 2)) * 32768) + (32767 & (Rotation.Yaw / 2))));
			}
		}
		else
		{
			ProcessDrive(aForward,aStrafe,aUp,bPressedJump);
		}
		if (CurrentVehicle != nullptr)
		{
			if ((bFire == 0) && CurrentVehicle.bWeaponisFiring)
			{
				CurrentVehicle.ClientVehicleCeaseFire(false);
			}
			if ((bAltFire == 0) && CurrentVehicle.bWeaponisAltFiring)
			{
				CurrentVehicle.ClientVehicleCeaseFire(true);
			}
		}
	}
	Function BeginState()
	{
		PlayerReplicationInfo->bReceivedPing = false;
		CleanOutSavedMoves();
	}
	Function EndState()
	{
		CleanOutSavedMoves();
	}
}
*/

/*
State PlayerSpidering
{
	Event bool NotifyHitWall(FVector HitNormal, AActor * HitActor)
	{
		Pawn.SetPhysics(PHYS_Spider);
		Pawn.SetBase(HitActor,HitNormal);
		return true;
	}
	Function UpdateRotation(float DeltaTime, float maxPitch)
	{
		FRotator ViewRotation = FRotator(0,0,0);
		FVector MyFloor = FVector(0,0,0);
		FVector CrossDir = FVector(0,0,0);
		FVector FwdDir = FVector(0,0,0);
		FVector OldFwdDir = FVector(0,0,0);
		FVector OldX = FVector(0,0,0);
		FVector RealFloor = FVector(0,0,0);
		if (bInterpolating || Pawn.bInterpolating)
		{
			ViewShake(DeltaTime);
			return;
		}
		TurnTarget = nullptr;
		bRotateToDesired = false;
		bSetTurnRot = false;
		if ((Pawn.Base == nullptr) || (Pawn.Floor == FVector(0,0,0)))
		{
			MyFloor = FVector(0,0,1);
		}
		else
		{
			MyFloor = Pawn.Floor;
		}
		if (MyFloor != OldFloor)
		{
			RealFloor = MyFloor;
			MyFloor = Normal((((6 * DeltaTime) * MyFloor) + ((1 - (6 * DeltaTime)) * OldFloor)));
			if ((RealFloor Dot MyFloor) > 0.999)
			{
				MyFloor = RealFloor;
			}
			else
			{
				CrossDir = Normal((RealFloor Cross OldFloor));
				FwdDir = (CrossDir Cross MyFloor);
				OldFwdDir = (CrossDir Cross OldFloor);
				ViewX = (((MyFloor * (OldFloor Dot ViewX)) + (CrossDir * (CrossDir Dot ViewX))) + (FwdDir * (OldFwdDir Dot ViewX)));
				ViewX = Normal(ViewX);
				ViewZ = (((MyFloor * (OldFloor Dot ViewZ)) + (CrossDir * (CrossDir Dot ViewZ))) + (FwdDir * (OldFwdDir Dot ViewZ)));
				ViewZ = Normal(ViewZ);
				OldFloor = MyFloor;
				ViewY = Normal((MyFloor Cross ViewX));
			}
		}
		if ((aTurn != 0) || (aLookUp != 0))
		{
			if (aTurn != 0)
			{
				ViewX = Normal((ViewX + ((2 * ViewY) * Sin(((0.0005 * DeltaTime) * aTurn)))));
			}
			if (aLookUp != 0)
			{
				OldX = ViewX;
				ViewX = Normal((ViewX + ((2 * ViewZ) * Sin(((0.0005 * DeltaTime) * aLookUp)))));
				ViewZ = Normal((ViewX Cross ViewY));
				if ((ViewZ Dot MyFloor) < 0.707)
				{
					OldX = Normal((OldX - (MyFloor * (MyFloor Dot OldX))));
					if ((ViewX Dot MyFloor) > 0)
					{
						ViewX = Normal((OldX + MyFloor));
					}
					else
					{
						ViewX = Normal((OldX - MyFloor));
					}
					ViewZ = Normal((ViewX Cross ViewY));
				}
			}
			ViewY = Normal((MyFloor Cross ViewX));
		}
		ViewRotation = OrthoRotation(ViewX,ViewY,ViewZ);
		SetActorRotation(ViewRotation);
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		Pawn.FaceRotation(ViewRotation,DeltaTime);
	}
	Function bool NotifyLanded(FVector HitNormal)
	{
		Pawn.SetPhysics(PHYS_Spider);
		return bUpdating;
	}
	Function bool NotifyPhysicsVolumeChange(APhysicsVolume * NewVolume)
	{
		if (NewVolume.bWaterVolume)
		{
			GotoState(Pawn.WaterMovementState);
		}
		return false;
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		FVector OldAccel = FVector(0,0,0);
		OldAccel = Pawn.Acceleration;
		if (Pawn.Acceleration != NewAccel)
		{
			Pawn.Acceleration = NewAccel;
		}
		if (bPressedJump)
		{
			Pawn.DoJump(bUpdating);
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector NewAccel = FVector(0,0,0);
		EDoubleClickDir DoubleClickMove;
		FRotator OldRotation = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		bool bSaveJump = false;
		GroundPitch = 0;
		ViewRotation = Rotation;
		Pawn.CheckBob(DeltaTime,FVector(0,0,0));
		SetActorRotation(ViewRotation);
		OldRotation = Rotation;
		UpdateRotation(DeltaTime,1);
		NewAccel = ((aForward * Normal((ViewX - (OldFloor * (OldFloor Dot ViewX))))) + (aStrafe * ViewY));
		if (VSize(NewAccel) < 1)
		{
			NewAccel = FVector(0,0,0);
		}
		if (bPressedJump && Pawn.CannotJumpNow())
		{
			bSaveJump = true;
			bPressedJump = false;
		}
		else
		{
			bSaveJump = false;
		}
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		bPressedJump = bSaveJump;
	}
	Function BeginState()
	{
		if (Pawn.Mesh == nullptr)
		{
			Pawn.SetMesh();
		}
		OldFloor = FVector(0,0,1);
		GetAxes(Rotation,ViewX,ViewY,ViewZ);
		DoubleClickDir = 0;
		Pawn.ShouldCrouch(false);
		bPressedJump = false;
		if (Pawn.Physics != 2)
		{
			Pawn.SetPhysics(PHYS_Spider);
		}
		GroundPitch = 0;
		Pawn.bCrawler = true;
		Pawn.SetCollisionSize(Pawn.Default.CollisionHeight,Pawn.Default.CollisionHeight);
	}
	Function EndState()
	{
		GroundPitch = 0;
		if (Pawn != nullptr)
		{
			Pawn.SetCollisionSize(Pawn.Default.CollisionRadius,Pawn.Default.CollisionHeight);
			Pawn.ShouldCrouch(false);
			Pawn.bCrawler = Pawn.Default.bCrawler;
		}
	}
}
*/

/*
State PlayerSwimming
{
	Function bool WantsSmoothedView()
	{
		return (!Pawn.bJustLanded);
	}
	Function bool NotifyLanded(FVector HitNormal)
	{
		if (Pawn.PhysicsVolume.bWaterVolume)
		{
			Pawn.SetPhysics(PHYS_Swimming);
		}
		else
		{
			GotoState(Pawn.LandMovementState);
		}
		return bUpdating;
	}
	Function bool NotifyPhysicsVolumeChange(APhysicsVolume * NewVolume)
	{
		AActor* HitActor = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector checkpoint = FVector(0,0,0);
		if (!NewVolume.bWaterVolume)
		{
			Pawn.SetPhysics(PHYS_Falling);
			if (Pawn.Velocity.Z > 0)
			{
				if (Pawn.bUpAndOut && Pawn.CheckWaterJump(HitNormal))
				{
					Pawn.Velocity.Z = (FMax(Pawn.JumpZ,420) + (2 * Pawn.CollisionRadius));
					GotoState(Pawn.LandMovementState);
				}
				else
				{
					if ((Pawn.Velocity.Z > float(160)) || (!Pawn.TouchingWaterVolume()))
					{
						GotoState(Pawn.LandMovementState);
					}
					else
					{
						checkpoint = Pawn.Location;
						(checkpoint.Z -= (Pawn.CollisionHeight + 6));
						HitActor = Trace(HitLocation,HitNormal,checkpoint,Pawn->GetActorLocation(),false);
						if (HitActor != nullptr)
						{
							GotoState(Pawn.LandMovementState);
						}
						else
						{
							Enable("Timer");
							SetTimer(0.7,false);
						}
					}
				}
			}
		}
		else
		{
			Disable("Timer");
			Pawn.SetPhysics(PHYS_Swimming);
		}
		return false;
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector OldAccel = FVector(0,0,0);
		bool bUpAndOut = false;
		GetAxes(Rotation,X,Y,Z);
		OldAccel = Pawn.Acceleration;
		if (Pawn.Acceleration != NewAccel)
		{
			Pawn.Acceleration = NewAccel;
		}
		bUpAndOut = (((X Dot Pawn.Acceleration) > 0) && ((Pawn.Acceleration.Z > 0) || (Rotation.Pitch > 2048)));
		if (Pawn.bUpAndOut != bUpAndOut)
		{
			Pawn.bUpAndOut = bUpAndOut;
		}
		if (!Pawn.PhysicsVolume.bWaterVolume)
		{
			NotifyPhysicsVolumeChange(Pawn.PhysicsVolume);
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FRotator OldRotation = FRotator(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector NewAccel = FVector(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		NewAccel = (((aForward * X) + (aStrafe * Y)) + (aUp * FVector(0,0,1)));
		if (VSize(NewAccel) < 1)
		{
			NewAccel = FVector(0,0,0);
		}
		Pawn.CheckBob(DeltaTime,Y);
		OldRotation = Rotation;
		UpdateRotation(DeltaTime,2);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,0,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,0,(OldRotation - Rotation));
		}
		bPressedJump = false;
	}
	Function Timer()
	{
		if ((!Pawn.PhysicsVolume.bWaterVolume) && (GetRemoteRole() == ENetRole::ROLE_MAX))
		{
			GotoState(Pawn.LandMovementState);
		}
		Disable("Timer");
	}
	Function BeginState()
	{
		Disable("Timer");
		Pawn.SetPhysics(PHYS_Swimming);
	}
}
*/

/*
State PlayerFlying
{
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		Pawn.Acceleration = ((aForward * X) + (aStrafe * Y));
		if (VSize(Pawn.Acceleration) < 1)
		{
			Pawn.Acceleration = FVector(0,0,0);
		}
		UpdateRotation(DeltaTime,2);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
	}
	Function BeginState()
	{
		Pawn.SetPhysics(PHYS_Flying);
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		UpdateTimers(DeltaTime);
		if (Pawn != nullptr)
		{
			Pawn.Acceleration = NewAccel;
			if (bCheatFlying && (Pawn.Acceleration == FVector(0,0,0)))
			{
				Pawn.Velocity = FVector(0,0,0);
			}
		}
	}
}
*/

/*
State PlayerSpaceFlying
{
	Function CallServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, bool NewbPendingJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		FRotator ViewRot = FRotator(0,0,0);
		if (GetPawn() == nullptr)
		{
			ViewRot = Rotation;
		}
		else
		{
			ViewRot = Pawn.Rotation;
		}
		if (PendingMove != nullptr)
		{
			DualSpaceFighterServerMove(PendingMove.TimeStamp,(PendingMove.Acceleration * float(10)),PendingMove.bDuck,PendingMove.Rotation.Pitch,PendingMove.Rotation.Yaw,PendingMove.Rotation.Roll,TimeStamp,InAccel,ClientLoc,NewbDuck,ViewRot.Pitch,ViewRot.Yaw,ViewRot.Roll);
		}
		else
		{
			SpaceFighterServerMove(TimeStamp,InAccel,ClientLoc,NewbDuck,ViewRot.Pitch,ViewRot.Yaw,ViewRot.Roll);
		}
	}
	Function ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		if (CurrentTimeStamp >= TimeStamp)
		{
			return;
		}
		if (AcknowledgedPawn != Pawn)
		{
			OldTimeDelta = 0;
			InAccel = FVector(0,0,0);
		}
		else
		{
			Pawn.AutonomousPhysics((TimeStamp - CurrentTimeStamp));
		}
		CurrentTimeStamp = TimeStamp;
		ServerTimeStamp = GetWorld()->GetTimeSeconds();
	}
	Function PlayerMove(float DeltaTime)
	{
		if (GetPawn() == nullptr)
		{
			GotoState("Dead");
			return;
		}
		Pawn.UpdateRocketAcceleration(DeltaTime,aTurn,aLookUp);
		SetActorRotation(Pawn.Rotation);
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,Pawn.Acceleration,0,Pawn.Rotation);
		}
		else
		{
			ProcessMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		if (GetPawn() == nullptr)
		{
			return;
		}
		if (Pawn.Acceleration != NewAccel)
		{
			Pawn.Acceleration = NewAccel;
		}
		if (DeltaRot != FRotator(0,0,0))
		{
			if (Pawn.Rotation != DeltaRot)
			{
				Pawn.SetRotation(DeltaRot);
			}
			if (Rotation != DeltaRot)
			{
				SetActorRotation(DeltaRot);
			}
		}
		Pawn.Velocity = ((Pawn.Acceleration * Pawn.AirSpeed) * 0.001);
		Pawn.ProcessMove(DeltaTime,NewAccel,DoubleClickMove,DeltaRot);
	}
	Function BeginState()
	{
		if (Pawn != nullptr)
		{
			Pawn.SetPhysics(PHYS_Flying);
		}
		RotationRate.Pitch = 8192;
		bIsSpaceFighter = true;
	}
	Function EndState()
	{
		RotationRate.Pitch = Default.RotationRate.Pitch;
		bIsSpaceFighter = false;
	}
}
*/

/*
State PlayerRocketing
{
	Function CallServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, bool NewbPendingJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		if (PendingMove != nullptr)
		{
			DualRocketServerMove(PendingMove.TimeStamp,(PendingMove.Acceleration * float(10)),PendingMove.bDuck,byte((byte((PendingMove.Rotation.Roll >> 8)) & 255)),(((32767 & (PendingMove.Rotation.Pitch / 2)) * 32768) + (32767 & (PendingMove.Rotation.Yaw / 2))),TimeStamp,InAccel,ClientLoc,NewbDuck,ClientRoll,View);
		}
		else
		{
			RocketServerMove(TimeStamp,InAccel,ClientLoc,NewbDuck,ClientRoll,View);
		}
	}
	Function ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		if (CurrentTimeStamp >= TimeStamp)
		{
			return;
		}
		if (!CheckSpeedHack((TimeStamp - CurrentTimeStamp)))
		{
			if (!bWasSpeedHack)
			{
				if ((GetWorld()->GetTimeSeconds() - LastSpeedHackLog) > float(20))
				{
					Log("Possible speed hack by " + PlayerReplicationInfo->PlayerName);
					LastSpeedHackLog = GetWorld()->GetTimeSeconds();
				}
				ClientMessage("Speed Hack Detected!","CriticalEvent");
			}
			else
			{
				bWasSpeedHack = true;
			}
		}
		else
		{
			if (AcknowledgedPawn != Pawn)
			{
				OldTimeDelta = 0;
				InAccel = FVector(0,0,0);
			}
			else
			{
				Pawn.AutonomousPhysics((TimeStamp - CurrentTimeStamp));
			}
		}
		CurrentTimeStamp = TimeStamp;
		ServerTimeStamp = GetWorld()->GetTimeSeconds();
	}
	Function RocketServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
	{
		Global.TeamInfo(TimeStamp,InAccel,ClientLoc,false,NewbDuck,false,false,0,ClientRoll,View);
	}
	Function DualRocketServerMove(float TimeStamp0, FVector InAccel0, bool NewbDuck0, uint8 ClientRoll0, int32 View0, float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
	{
		Global.TeamInfo(TimeStamp0,InAccel0,FVector(0,0,0),false,NewbDuck0,false,false,0,ClientRoll0,View0);
		Global.TeamInfo(TimeStamp,InAccel,ClientLoc,false,NewbDuck,false,false,0,ClientRoll,View);
	}
	Function PlayerMove(float DeltaTime)
	{
		Pawn.UpdateRocketAcceleration(DeltaTime,aTurn,aLookUp);
		SetActorRotation(Pawn.Rotation);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		if (GetPawn() == nullptr)
		{
			return;
		}
		if (Pawn.Acceleration != NewAccel)
		{
			Pawn.Acceleration = NewAccel;
		}
	}
	Function BeginState()
	{
		if (Pawn != nullptr)
		{
			Pawn.SetPhysics(PHYS_Flying);
		}
		RotationRate.Pitch = 8192;
	}
	Function EndState()
	{
		RotationRate.Pitch = Default.RotationRate.Pitch;
	}
}
*/

/*
State PlayerTurreting
{
	Function CallServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, bool NewbPendingJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		if (PendingMove != nullptr)
		{
			DualTurretServerMove(PendingMove.TimeStamp,PendingMove.bDuck,byte((byte((PendingMove.Rotation.Roll >> 8)) & 255)),(((32767 & (PendingMove.Rotation.Pitch / 2)) * 32768) + (32767 & (PendingMove.Rotation.Yaw / 2))),TimeStamp,ClientLoc,NewbDuck,ClientRoll,View);
		}
		else
		{
			TurretServerMove(TimeStamp,ClientLoc,NewbDuck,ClientRoll,View);
		}
	}
	Function ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		if (CurrentTimeStamp >= TimeStamp)
		{
			return;
		}
		if (AcknowledgedPawn != Pawn)
		{
			OldTimeDelta = 0;
			InAccel = FVector(0,0,0);
		}
		if ((AcknowledgedPawn == Pawn) && (CurrentTimeStamp < TimeStamp))
		{
			Pawn.AutonomousPhysics((TimeStamp - CurrentTimeStamp));
		}
		CurrentTimeStamp = TimeStamp;
		ServerTimeStamp = GetWorld()->GetTimeSeconds();
	}
	Function TurretServerMove(float TimeStamp, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
	{
		Global.TeamInfo(TimeStamp,FVector(0,0,0),ClientLoc,false,NewbDuck,false,false,0,ClientRoll,View);
	}
	Function DualTurretServerMove(float TimeStamp0, bool NewbDuck0, uint8 ClientRoll0, int32 View0, float TimeStamp, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
	{
		Global.TeamInfo(TimeStamp0,FVector(0,0,0),FVector(0,0,0),false,NewbDuck0,false,false,0,ClientRoll0,View0);
		Global.TeamInfo(TimeStamp,FVector(0,0,0),ClientLoc,false,NewbDuck,false,false,0,ClientRoll,View);
	}
	Function PlayerMove(float DeltaTime)
	{
		AVehicle* CurrentVehicle = nullptr;
		if (GetPawn() == nullptr)
		{
			GotoState("Dead");
			return;
		}
		Pawn.UpdateRocketAcceleration(DeltaTime,aTurn,aLookUp);
		if (!bFreeCamera)
		{
			SetActorRotation(Pawn.Rotation);
		}
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,Pawn.Acceleration,0,FRotator(0,0,0));
		}
		CurrentVehicle = Vehicle(Pawn);
		if (CurrentVehicle != nullptr)
		{
			if ((bFire == 0) && CurrentVehicle.bWeaponisFiring)
			{
				CurrentVehicle.ClientVehicleCeaseFire(false);
			}
			if ((bAltFire == 0) && CurrentVehicle.bWeaponisAltFiring)
			{
				CurrentVehicle.ClientVehicleCeaseFire(true);
			}
		}
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		if (GetPawn() == nullptr)
		{
			return;
		}
		Pawn.Acceleration = NewAccel;
	}
	Function BeginState()
	{
		if (Pawn != nullptr)
		{
			Pawn.SetPhysics(PHYS_Flying);
		}
		RotationRate.Pitch = 16384;
	}
	Function EndState()
	{
		RotationRate.Pitch = Default.RotationRate.Pitch;
	}
}
*/

/*
State BaseSpectating
{
	simulated Function int32 GetTraceDistance()
	{
		return 0;
	}
	Function bool IsSpectating()
	{
		return true;
	}
	Function ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
	{
		UpdateTimers(DeltaTime);
		Acceleration = NewAccel;
		MoveSmooth(((SpectateSpeed * Normal(Acceleration)) * DeltaTime));
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		if ((Cast<APawn>(ViewTarget) != nullptr) && (GetWorld()->GetNetMode() == NM_Client))
		{
			if (Cast<APawn>(ViewTarget).bSimulateGravity)
			{
				TargetViewRotation.Roll = 0;
			}
			BlendedTargetViewRotation.Pitch = BlendRot(DeltaTime,BlendedTargetViewRotation.Pitch,(TargetViewRotation.Pitch & 65535));
			BlendedTargetViewRotation.Yaw = BlendRot(DeltaTime,BlendedTargetViewRotation.Yaw,(TargetViewRotation.Yaw & 65535));
			BlendedTargetViewRotation.Roll = BlendRot(DeltaTime,BlendedTargetViewRotation.Roll,(TargetViewRotation.Roll & 65535));
		}
		GetAxes(Rotation,X,Y,Z);
		Acceleration = (SpectatorSpeedScalar * (((aForward * X) + (aStrafe * Y)) + (aUp * FVector(0,0,1))));
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,Acceleration,0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,Acceleration,0,FRotator(0,0,0));
		}
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "PlayerController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		CleanUp();
	}
}
*/

/*
State Scripting
{
	void Fire(float F)
	{
	}
	void AltFire(float F)
	{
		Fire(F);
	}
}
*/

/*
State Spectating extends BaseSpectating
{
	void RestartLevel()
	{
	}
	Function ClientReStart(APawn * NewPawn, bool bDontClearLevelParam)
	{
	}
	void Suicide()
	{
	}
	void ThrowWeapon()
	{
	}
	Function SimpleClientRestart(APawn * NewPawn)
	{
	}
	Function BeginState()
	{
		if (Pawn != nullptr)
		{
			SetActorLocation(Pawn.Location);
			UnPossess();
		}
		bCollideWorld = true;
		CameraDist = Default.CameraDist;
	}
	Function EndState()
	{
		bCollideWorld = false;
	}
}
*/

/*
State AttractMode extends Spectating
{
}
*/

/*
auto State PlayerWaiting extends BaseSpectating
{
	Function TakeDamage(int32 Damage, APawn * EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController * KillerController, AActor * ResponsibleActor, UMaterialInstance** HitMaterial)
	{
	}
	void NextWeapon()
	{
	}
	void PrevWeapon()
	{
	}
	void SwitchToBestWeapon()
	{
	}
	void Jump(float F)
	{
	}
	void Suicide()
	{
	}
	Function ChangeTeam(int32 N)
	{
		Level.Game.ChangeTeam(this,N,true);
	}
	Function ServerReStartPlayer()
	{
		if (GetWorld()->GetTimeSeconds() < WaitDelay)
		{
			return;
		}
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		if (Level.Game.bWaitingToStartMatch)
		{
			PlayerReplicationInfo->bReadyToPlay = true;
		}
		else
		{
			Level.Game.RestartPlayer(this);
		}
	}
	void Fire(float F)
	{
		LoadPlayers();
		if ((!bForcePrecache) && (GetWorld()->GetTimeSeconds() > 0.2))
		{
			ServerReStartPlayer();
		}
	}
	void AltFire(float F)
	{
		Fire(F);
	}
	Function EndState()
	{
		if (Pawn != nullptr)
		{
			Pawn.SetMesh();
		}
		bCollideWorld = false;
	}
	Function BeginState()
	{
		Super::BeginState();
		CameraDist = Default.CameraDist;
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo->SetWaitingPlayer(true);
		}
		bCollideWorld = true;
		if (((Level.Game != nullptr) && (!Level.Game.IsInState("MatchInProgress"))) && (!Level.Game.IsInState("DelayedMatchInProgress")))
		{
			GotoState("GameEnded");
			ClientGotoState("GameEnded","Begin");
		}
	}
}
*/

/*
State WaitingForPawn extends BaseSpectating
{
	Function KilledBy(APawn * EventInstigator)
	{
	}
	void Fire(float F)
	{
		AskForPawn();
	}
	void AltFire(float F)
	{
	}
	Function LongClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, float NewVelX, float NewVelY, float NewVelZ, AActor * NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
	{
		if ((PlayerReplicationInfo != nullptr) && (!bDemoOwner))
		{
			if (ExactPing < 0.006)
			{
				ExactPing = (GetWorld()->GetTimeSeconds() - TimeStamp);
			}
			else
			{
				ExactPing = ((0.99 * ExactPing) + (0.009 * (GetWorld()->GetTimeSeconds() - TimeStamp)));
			}
			PlayerReplicationInfo->Ping = uint8(FClamp((1000 * ExactPing),0,9999));
			if ((GetWorld()->GetTimeSeconds() - LastPingUpdate) > 4)
			{
				LastPingUpdate = GetWorld()->GetTimeSeconds();
				ServerUpdatePing(int(FClamp((1000 * ExactPing),0,9999)));
			}
		}
		if ((NewState == "GameEnded") || (NewState == "RoundEnded"))
		{
			GotoState(NewState);
		}
	}
	Function PlayerTick(float DeltaTime)
	{
		Global.tickAccum(DeltaTime);
		if (Pawn != nullptr)
		{
			Pawn.Controller = this;
			Pawn.bUpdateEyeheight = true;
			ClientReStart(Pawn);
			MaybeDelaySpawn();
		}
		else
		{
			if ((TimerRate <= 0) || (TimerRate > 1))
			{
				SetTimer(0.2,true);
				AskForPawn();
			}
		}
	}
	Function Timer()
	{
		AskForPawn();
	}
	Function BeginState()
	{
		SetTimer(0.2,true);
		AskForPawn();
	}
	Function EndState()
	{
		bBehindView = false;
		SetTimer(0,false);
	}
}
*/

/*
State GameEnded
{
	Function KilledBy(APawn * EventInstigator)
	{
	}
	Function TakeDamage(int32 Damage, APawn * EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController * KillerController, AActor * ResponsibleActor, UMaterialInstance** HitMaterial)
	{
	}
	void Suicide()
	{
	}
	void Reload()
	{
	}
	void FixJam()
	{
	}
	Function ServerReStartPlayer()
	{
	}
	Function bool IsSpectating()
	{
		return true;
	}
	void Use()
	{
	}
	void SwitchWeapon(uint8 t)
	{
	}
	void ThrowWeapon()
	{
	}
	Function Possess(APawn * aPawn)
	{
		Global.PlayInfo(aPawn);
	}
	Function ServerRestartGame()
	{
		if (Level.Game.PlayerCanRestartGame(this))
		{
			Level.Game.RestartGame();
		}
	}
	void Fire(float F)
	{
		if (Role < 4)
		{
			return;
		}
		if (!bFrozen)
		{
			ServerRestartGame();
		}
		else
		{
			if (TimerRate <= 0)
			{
				SetTimer(1.5,false);
			}
		}
	}
	void AltFire(float F)
	{
		Fire(F);
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		if (!bFixedCamera)
		{
			ViewRotation = Rotation;
			(ViewRotation.Yaw += int(((32 * DeltaTime) * aTurn)));
			(ViewRotation.Pitch += int(((32 * DeltaTime) * aLookUp)));
			if (Pawn != nullptr)
			{
				ViewRotation.Pitch = Pawn.LimitPitch(ViewRotation.Pitch);
			}
			SetActorRotation(ViewRotation);
		}
		else
		{
			if (ViewTarget != nullptr)
			{
				SetActorRotation(ViewTarget.Rotation);
			}
		}
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
		bPressedJump = false;
	}
	Function ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		Global.TeamInfo(TimeStamp,InAccel,ClientLoc,NewbIsWalking,NewbDuck,NewbProne,NewbJumpStatus,DoubleClickMove,ClientRoll,(((Rotation.Yaw & 65535) << 16) + (Rotation.Pitch & 65535)));
	}
	Function FindGoodView()
	{
		FVector cameraLoc = FVector(0,0,0);
		FRotator cameraRot = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		int32 tries = 0;
		int32 besttry = 0;
		float bestDist = 0;
		float newdist = 0;
		int32 startYaw = 0;
		AActor* ViewActor = nullptr;
		ViewRotation = Rotation;
		ViewRotation.Pitch = 56000;
		tries = 0;
		besttry = 0;
		bestDist = 0;
		startYaw = ViewRotation.Yaw;
		for (tries = 0; tries < 16; tries++)
		{
			cameraLoc = ViewTarget.Location;
			SetActorRotation(ViewRotation);
			PlayerCalcView(ViewActor,cameraLoc,cameraRot);
			newdist = VSize((cameraLoc - ViewTarget.Location));
			if (newdist > bestDist)
			{
				bestDist = newdist;
				besttry = tries;
			}
			ViewRotation.Yaw += 4096;
		}
		ViewRotation.Yaw = (startYaw + (besttry * 4096));
		SetActorRotation(ViewRotation);
	}
	Function Timer()
	{
		bFrozen = false;
	}
	Function LongClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, float NewVelX, float NewVelY, float NewVelZ, AActor * NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
	{
		if ((PlayerReplicationInfo != nullptr) && (!bDemoOwner))
		{
			if (ExactPing < 0.006)
			{
				ExactPing = (GetWorld()->GetTimeSeconds() - TimeStamp);
			}
			else
			{
				ExactPing = ((0.99 * ExactPing) + (0.009 * (GetWorld()->GetTimeSeconds() - TimeStamp)));
			}
			PlayerReplicationInfo->Ping = uint8(FClamp((1000 * ExactPing),0,9999));
			if ((GetWorld()->GetTimeSeconds() - LastPingUpdate) > 4)
			{
				LastPingUpdate = GetWorld()->GetTimeSeconds();
				ServerUpdatePing(int(FClamp((1000 * ExactPing),0,9999)));
			}
		}
	}
	Function BeginState()
	{
		APawn* p = nullptr;
		EndZoom();
		StopForceFeedback();
		CameraDist = Default.CameraDist;
		FovAngle = DesiredFOV;
		bFire = 0;
		bAltFire = 0;
		if (Pawn != nullptr)
		{
			if (Cast<AVehicle>(Pawn) != nullptr)
			{
				Pawn.StopWeaponFiring();
			}
			Pawn.TurnOff();
			Pawn.bSpecialHUD = false;
			Pawn.SimAnim.AnimRate = 0;
			if (Pawn.Weapon != nullptr)
		}
		{
		}
		bFrozen = true;
		if (!bFixedCamera)
		{
			FindGoodView();
			bBehindView = true;
		}
		SetTimer(5,false);
		ForEach DynamicActors(Class'Pawn',p)
		{
			if ((p.Controller != nullptr) && p.Controller->IsA(AaAIController::StaticClass()))
			{
				continue;
			}
			if (p.Role == 4)
			{
				p.RemoteRole = ROLE_DumbProxy;
			}
			p.TurnOff();
		}
	}
}
*/

/*
State RoundEnded
{
	Function KilledBy(APawn * EventInstigator)
	{
	}
	Function TakeDamage(int32 Damage, APawn * EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController * KillerController, AActor * ResponsibleActor, UMaterialInstance** HitMaterial)
	{
	}
	void Suicide()
	{
	}
	Function ServerReStartPlayer()
	{
	}
	Function bool IsSpectating()
	{
		return true;
	}
	void Use()
	{
	}
	void SwitchWeapon(uint8 t)
	{
	}
	void ThrowWeapon()
	{
	}
	void Fire(float F)
	{
		if (Role < 4)
		{
			return;
		}
		if (!bFrozen)
		{
			ServerRestartGame();
		}
		else
		{
			if (TimerRate <= 0)
			{
				SetTimer(1.5,false);
			}
		}
	}
	void AltFire(float F)
	{
		Fire(F);
	}
	Function ServerRestartGame()
	{
		if (Level.Game.PlayerCanRestartGame(this))
		{
			Level.Game.RestartGame();
		}
	}
	Function Possess(APawn * aPawn)
	{
		Global.PlayInfo(aPawn);
		if (Pawn != nullptr)
		{
			Pawn.TurnOff();
		}
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		if (!bFixedCamera)
		{
			ViewRotation = Rotation;
			(ViewRotation.Yaw += int(((32 * DeltaTime) * aTurn)));
			(ViewRotation.Pitch += int(((32 * DeltaTime) * aLookUp)));
			if (Pawn != nullptr)
			{
				ViewRotation.Pitch = Pawn.LimitPitch(ViewRotation.Pitch);
			}
			SetActorRotation(ViewRotation);
		}
		else
		{
			if (ViewTarget != nullptr)
			{
				SetActorRotation(ViewTarget.Rotation);
			}
		}
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
		bPressedJump = false;
	}
	Function ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbWalk, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		Global.TeamInfo(TimeStamp,InAccel,ClientLoc,NewbWalk,NewbDuck,NewbProne,NewbJumpStatus,DoubleClickMove,ClientRoll,(((Rotation.Yaw & 65535) << 16) + (Rotation.Pitch & 65535)));
	}
	Function FindGoodView()
	{
		FVector cameraLoc = FVector(0,0,0);
		FRotator cameraRot = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		int32 tries = 0;
		int32 besttry = 0;
		float bestDist = 0;
		float newdist = 0;
		int32 startYaw = 0;
		AActor* ViewActor = nullptr;
		ViewRotation = Rotation;
		if (ViewTarget->IsA(APawn::StaticClass()))
		{
			ViewRotation.Pitch = 56000;
		}
		tries = 0;
		besttry = 0;
		bestDist = 0;
		startYaw = ViewRotation.Yaw;
		for (tries = 0; tries < 16; tries++)
		{
			cameraLoc = ViewTarget.Location;
			SetActorRotation(ViewRotation);
			PlayerCalcView(ViewActor,cameraLoc,cameraRot);
			newdist = VSize((cameraLoc - ViewTarget.Location));
			if (newdist > bestDist)
			{
				bestDist = newdist;
				besttry = tries;
			}
			ViewRotation.Yaw += 4096;
		}
		ViewRotation.Yaw = (startYaw + (besttry * 4096));
		SetActorRotation(ViewRotation);
	}
	Function LongClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, float NewVelX, float NewVelY, float NewVelZ, AActor * NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
	{
		if ((PlayerReplicationInfo != nullptr) && (!bDemoOwner))
		{
			if (ExactPing < 0.006)
			{
				ExactPing = (GetWorld()->GetTimeSeconds() - TimeStamp);
			}
			else
			{
				ExactPing = ((0.99 * ExactPing) + (0.009 * (GetWorld()->GetTimeSeconds() - TimeStamp)));
			}
			PlayerReplicationInfo->Ping = uint8(FClamp((1000 * ExactPing),0,9999));
			if ((GetWorld()->GetTimeSeconds() - LastPingUpdate) > 4)
			{
				LastPingUpdate = GetWorld()->GetTimeSeconds();
				ServerUpdatePing(int(FClamp((1000 * ExactPing),0,9999)));
			}
		}
		if (NewState == "PlayerWaiting")
		{
			GotoState(NewState);
		}
	}
	Function BeginState()
	{
		APawn* p = nullptr;
		CleanUp();
		EndZoom();
		CameraDist = Default.CameraDist;
		FovAngle = DesiredFOV;
		bFire = 0;
		bAltFire = 0;
		if (Pawn != nullptr)
		{
			if (Cast<AVehicle>(Pawn) != nullptr)
			{
				Pawn.StopWeaponFiring();
			}
			Pawn.TurnOff();
			Pawn.bSpecialHUD = false;
			Pawn.SimAnim.AnimRate = 0;
		}
		if (!bFixedCamera)
		{
			FindGoodView();
			bBehindView = true;
		}
		ForEach DynamicActors(Class'Pawn',p)
		{
			if ((p.Controller != nullptr) && p.Controller->IsA(AaAIController::StaticClass()))
			{
				continue;
			}
			if (p.Role == 4)
			{
				p.RemoteRole = ROLE_DumbProxy;
			}
			p.TurnOff();
		}
		StopForceFeedback();
	}
	Function CalcBehindView(FVector & CameraLocation, FRotator & CameraRotation, float dist)
	{
		FVector View = FVector(0,0,0);
		float ViewDist = 0;
		float RealDist = 0;
		FVector globalX = FVector(0,0,0);
		FVector globalY = FVector(0,0,0);
		FVector globalZ = FVector(0,0,0);
		FVector localX = FVector(0,0,0);
		FVector localY = FVector(0,0,0);
		FVector localZ = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		AActor* HitActor = nullptr;
		CameraRotation = Rotation;
		CameraRotation.Roll = 0;
		(CameraLocation.Z += float(12));
		(CameraRotation += CameraDeltaRotation);
		View = (FVector(1,0,0) >> CameraRotation);
		RealDist = dist;
		(dist += CameraDeltaRad);
		HitActor = Trace(HitLocation,HitNormal,(CameraLocation - (dist * Vector(CameraRotation))),CameraLocation,false,FVector(10,10,10));
		if ((HitActor != nullptr) && (!HitActor->IsA(ABlockingVolume::StaticClass())))
		{
			ViewDist = FMin(((CameraLocation - HitLocation) Dot View),dist);
		}
		else
		{
			ViewDist = dist;
		}
		if (((!bBlockCloseCamera) || (!bValidBehindCamera)) || (ViewDist > (float(10) + FMax(ViewTarget.CollisionRadius,ViewTarget.CollisionHeight))))
		{
			bValidBehindCamera = true;
			OldCameraLoc = (CameraLocation - (ViewDist * View));
			OldCameraRot = CameraRotation;
		}
		else
		{
			SetActorRotation(OldCameraRot);
		}
		CameraLocation = OldCameraLoc;
		CameraRotation = OldCameraRot;
		GetAxes(CameraSwivel,globalX,globalY,globalZ);
		localX = (globalX >> CameraRotation);
		localY = (globalY >> CameraRotation);
		localZ = (globalZ >> CameraRotation);
		CameraRotation = OrthoRotation(localX,localY,localZ);
	}
}
*/

/*
State Dead
{
	Function KilledBy(APawn * EventInstigator)
	{
	}
	void NextWeapon()
	{
	}
	void PrevWeapon()
	{
	}
	simulated Function int32 GetTraceDistance()
	{
		return 0;
	}
	void ThrowWeapon()
	{
	}
	Function bool isDead()
	{
		return true;
	}
	Function ServerReStartPlayer()
	{
		if (!Level.Game.PlayerCanRestart(this))
		{
			return;
		}
		if (!Level.Game.IsSpectateFirstPersonOnly())
		{
			ClientSetBehindView(true,true);
		}
		Super::ServerReStartPlayer();
	}
	void Fire(float F)
	{
		if (bFrozen)
		{
			if ((TimerRate <= 0) || (TimerRate > 1))
			{
				bFrozen = false;
			}
			return;
		}
		LoadPlayers();
		if (bMenuBeforeRespawn)
		{
			bMenuBeforeRespawn = false;
			ShowMidGameMenu(false);
		}
		else
		{
			ServerReStartPlayer();
		}
	}
	void AltFire(float F)
	{
		Fire(F);
	}
	void Use()
	{
		if (bFrozen)
		{
			if ((TimerRate <= 0) || (TimerRate > 1))
			{
				bFrozen = false;
			}
			return;
		}
		if (Level.Game != nullptr)
		{
			Level.Game.DeadUse(this);
		}
	}
	Function ServerMove(float TimeStamp, FVector Accel, FVector ClientLoc, bool NewbWalk, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
	{
		Global.TeamInfo(TimeStamp,Accel,ClientLoc,false,false,false,false,DoubleClickMove,ClientRoll,View);
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		if (!bFrozen)
		{
			if (bPressedJump)
			{
				Fire(0);
				bPressedJump = false;
			}
			GetAxes(Rotation,X,Y,Z);
			ViewRotation = Rotation;
			(ViewRotation.Yaw += int(((32 * DeltaTime) * aTurn)));
			(ViewRotation.Pitch += int(((32 * DeltaTime) * aLookUp)));
			if (Pawn != nullptr)
			{
				ViewRotation.Pitch = Pawn.LimitPitch(ViewRotation.Pitch);
			}
			SetActorRotation(ViewRotation);
			if (Role < 4)
			{
				ReplicateMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
			}
		}
		else
		{
			if ((TimerRate <= 0) || (TimerRate > 1))
			{
				bFrozen = false;
			}
		}
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
	}
	simulated Event PlayerCalcView(AActor * &ViewActor, FVector & CameraLocation, FRotator & CameraRotation)
	{
		APawn* PTarget = nullptr;
		PTarget = Cast<APawn>(ViewTarget);
		if ((PTarget != nullptr) && (GetPawn() == nullptr))
		{
			ViewActor = ViewTarget;
			CameraLocation = ViewTarget.Location;
			Pawn = PTarget;
			if (bBehindView)
			{
				CalcBehindView(CameraLocation,CameraRotation,(CameraDist * PTarget.Default.CollisionRadius));
			}
			else
			{
				CalcFirstPersonView(CameraLocation,CameraRotation);
			}
			Pawn = nullptr;
		}
		else
		{
			Global.Emitters(ViewActor,CameraLocation,CameraRotation);
		}
	}
	Function FindGoodView()
	{
		FVector cameraLoc = FVector(0,0,0);
		FRotator cameraRot = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		int32 tries = 0;
		int32 besttry = 0;
		float bestDist = 0;
		float newdist = 0;
		int32 startYaw = 0;
		AActor* ViewActor = nullptr;
		ViewRotation = Rotation;
		ViewRotation.Pitch = 56000;
		tries = 0;
		besttry = 0;
		bestDist = 0;
		startYaw = ViewRotation.Yaw;
		for (tries = 0; tries < 16; tries++)
		{
			cameraLoc = ViewTarget.Location;
			SetActorRotation(ViewRotation);
			PlayerCalcView(ViewActor,cameraLoc,cameraRot);
			newdist = VSize((cameraLoc - ViewTarget.Location));
			if (newdist > bestDist)
			{
				bestDist = newdist;
				besttry = tries;
			}
			ViewRotation.Yaw += 4096;
		}
		ViewRotation.Yaw = (startYaw + (besttry * 4096));
		SetActorRotation(ViewRotation);
	}
	Function BeginState()
	{
		if ((Pawn != nullptr) && ((Pawn.Controller == this) || (Pawn.Controller == nullptr)))
		{
			Pawn.Controller = nullptr;
		}
		EndZoom();
		CameraDist = Default.CameraDist;
		FovAngle = DesiredFOV;
		Pawn = nullptr;
		Enemy = nullptr;
		StopForceFeedback();
		ClientPlayForceFeedback("Damage");
		CleanOutSavedMoves();
	}
	Function EndState()
	{
		StopForceFeedback();
		bBlockCloseCamera = false;
		CleanOutSavedMoves();
		Velocity = FVector(0,0,0);
		Acceleration = FVector(0,0,0);
		if (!PlayerReplicationInfo->bOutOfLives)
		{
			bBehindView = false;
		}
		bPressedJump = false;
		if (myHUD != nullptr)
		{
			myHUD->bShowScoreBoard = false;
		}
		bFrozen = false;
		StopViewShaking();
	}
Begin:
	Sleep(3);
}
*/

FString AAA2_PlayerController::ApplyFilters(FString S)
{
	return "FAKE";   //FAKE   /ELiZ
}

void AAA2_PlayerController::AAA2_PlayerController::ClientNotifyAdminMessage(FString sMsg)
{
}

void AAA2_PlayerController::MaybeDelaySpawn()
{
}

//native final Function SetNetSpeed(int32 NewSpeed);
void AAA2_PlayerController::SetNetSpeed(int32 NewSpeed)
{

}

//native final Function FString GetPlayerIDHash();
FString AAA2_PlayerController::GetPlayerIDHash()
{
	return "FAKE";   //FAKE   /ELiZ
}

//native final Function FString GetPlayerNetworkAddress();
FString AAA2_PlayerController::GetPlayerNetworkAddress()
{
	return "FAKE";   //FAKE   /ELiZ
}

//native final Function FString GetServerNetworkAddress();
FString AAA2_PlayerController::GetServerNetworkAddress()
{
	return "FAKE";   //FAKE   /ELiZ
}

//native Function FString ConsoleCommand(FString Command, bool bWriteToLog);
FString AAA2_PlayerController::ConsoleCommand(FString Command, bool bWriteToLog)
{
	return "FAKE";   //FAKE   /ELiZ
}

//native final Function LevelInfo GetEntryLevel();
ALevelInfo* AAA2_PlayerController::GetEntryLevel()
{
	return nullptr;   //FAKE   /ELiZ
}

//native(544) final Function ResetKeyboard();
void AAA2_PlayerController::ResetKeyboard()
{

}

//native final Function ResetInput();
void AAA2_PlayerController::ResetInput()
{

}

//native final Function SetViewTarget(AActor* NewViewTarget);
void AAA2_PlayerController::SetViewTarget(AActor* NewViewTarget)
{

}

//native final Function SetFocusTarget(AActor* NewFocusTarget);
void AAA2_PlayerController::SetFocusTarget(AActor* NewFocusTarget)
{

}

//native Event ClientTravel(FString URL, Actor.ETravelType TravelType, bool bItems);
void AAA2_PlayerController::ClientTravel(FString URL, ETravelType TravelType, bool bItems)
{

}

//native final Function FString GetURLProtocol();
FString AAA2_PlayerController::GetURLProtocol()
{
	return "FAKE";   //FAKE   /ELiZ
}

//native final Function FString GetDefaultURL(FString Option);
FString AAA2_PlayerController::GetDefaultURL(FString Option)
{
	return "FAKE";   //FAKE   /ELiZ
}

//native Function CopyToClipboard(FString Text);
void AAA2_PlayerController::CopyToClipboard(FString Text)
{

}

//native Function FString PasteFromClipboard();
FString AAA2_PlayerController::PasteFromClipboard()
{
	return "FAKE";   //FAKE   /ELiZ
}

//native Event ClientValidate(FString C);
void AAA2_PlayerController::ClientValidate(FString C)
{

}

//native Event ServerValidationResponse(FString R);
void AAA2_PlayerController::ServerValidationResponse(FString R)
{

}

//native final Function bool CheckSpeedHack(float DeltaTime);
bool AAA2_PlayerController::CheckSpeedHack(float DeltaTime)
{
	return false;   //FAKE   /ELiZ
}

//native(524) final Function int32 FindStairRotation(float DeltaTime);
int32 AAA2_PlayerController::FindStairRotation(float DeltaTime)
{
	return 0;   //FAKE   /ELiZ
}

//native Event ClientHearSound(AActor* Actor, int32 Id, USoundBase* S, FVector SoundLocation, FVector Parameters, bool Attenuate, bool bNo3D);
void AAA2_PlayerController::ClientHearSound(AActor* Actor, int32 Id, USoundBase* S, FVector SoundLocation, FVector Parameters, bool Attenuate, bool bNo3D)
{

}

void AAA2_PlayerController::SetGrammar()
{
}

void AAA2_PlayerController::ServerUpdateSelfHealActionState(bool bState)
{
	if (bState)
	{
		bHealSelfAction = 1;
	}
	else
	{
		bHealSelfAction = 0;
	}
}

void AAA2_PlayerController::SetFromAuthJacket(FAuthJacket Jacket)
{
	int32 ii = 0;
	iCompleted[0] = Jacket.ToursCompleted;
	for (ii = 0; ii < 32; ii++)
	{
		iCompleted[(ii + 1)] = Jacket.MissionsCompleted[ii];
	}
	iRifleRangeRating = Jacket.MarksmanshipScore;
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo->_iTrust = Jacket.Honor;
		PlayerReplicationInfo->_Experience = Jacket.Experience;
		//PlayerReplicationInfo->SetGroup(byte(Jacket.Group));
	}
	iUID = Jacket.UID;
}

FString AAA2_PlayerController::AuthJacketToString(FAuthJacket Jacket)
{
	FString str = "";
	int32 ii = 0;
	/*
	str = "ToursCompleted:" @ FString::FromInt(Jacket.ToursCompleted);
	str @ = "MissionsCompleted: ";
	for (ii = 0; ii < 32; ii++)
	{
		if (ii > 0)
		{
			str += ",";
		}
		str += FString::FromInt(Jacket.MissionsCompleted[ii]);
	}
	str @ = "MarksmanshipScore:" @ FString::FromInt(Jacket.MarksmanshipScore);
	str @ = "Honor:" @ FString::FromInt(Jacket.Honor);
	str @ = "Experience:" @ FString::FromInt(Jacket.Experience);
	str @ = "Group:" @ FString::FromInt(Jacket.Group);
	str @ = "UID:" @ FString::FromInt(Jacket.UID);
	*/
	return str;
}

void AAA2_PlayerController::ServerExperienceUpdateAuthorizeComplete(int32 Code)
{
}

void AAA2_PlayerController::ClientAuthorizeUserAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
}

void AAA2_PlayerController::ServerAuthorizeUserAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
}

void AAA2_PlayerController::ClientNewsAuthorizeComplete(int32 Code, int32 NewsId, FString Line)
{
}

void AAA2_PlayerController::ClientMissionCompleteAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
}

void AAA2_PlayerController::ServerMissionCompleteAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
}

void AAA2_PlayerController::AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
{
}

void AAA2_PlayerController::AddMBSAttributes(TArray<FKeyValuePair>& Attributes)
{
}

//native final Function FString GetPBConnectStatus();
FString AAA2_PlayerController::GetPBConnectStatus()
{
	return "FAKE";    //FAKE  /ELiZ
}

//native final Function int32 IsPBEnabled();
int32 AAA2_PlayerController::IsPBEnabled()
{
	return 0;    //FAKE  /ELiZ
}

void AAA2_PlayerController::NotifyPawnSpawned(APawn* p)
{
}

void AAA2_PlayerController::NotifyPawnDestroyed(APawn* p)
{
}

void AAA2_PlayerController::ServerUploadTrustAndExperience(int32 Logout)
{
}

void AAA2_PlayerController::ServerUploadStats(int32 Kills, int32 Deaths, int32 ShotsFired, int32 ShotsThatHitAGPPawns, float PlayDuration)
{
}

void AAA2_PlayerController::NotifyPromotion(bool bFTL, uint8 yFT)
{
}

void AAA2_PlayerController::NotifyNoScore(FName Reason)
{
}

void AAA2_PlayerController::GrenadeExploded(float Duration, float Intensity)
{
}

void AAA2_PlayerController::ClientStartScreenShake(float ShakeTime)
{
}

void AAA2_PlayerController::ClientFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void AAA2_PlayerController::FlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void AAA2_PlayerController::ClientGrenaded(float Duration, float AudIntensity)
{
}

void AAA2_PlayerController::Grenaded(float Duration, float AudIntensity)
{
}

bool AAA2_PlayerController::QualifiedFor(AActor* Desired)
{
	return false;   //FAKE  /ELiZ
}

void AAA2_PlayerController::QueryServerList()
{
}

void AAA2_PlayerController::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
}

void AAA2_PlayerController::GetServerSection(int32 Index)
{
}

void AAA2_PlayerController::SetServerSection(int32 Index, FString Section)
{
}

FString AAA2_PlayerController::GetServerSetting(int32 Index)
{
	return "FAKE";   //FAKE   /ELiZ
}

void AAA2_PlayerController::SetServerSetting(int32 Index, FString Value)
{
}

void AAA2_PlayerController::SetServerSettingReply(int32 Index, FString Value)
{
}

void AAA2_PlayerController::KickPlayer(FString PlayerName)
{
}

void AAA2_PlayerController::BanPlayer(FString PlayerName)
{
}

int32 AAA2_PlayerController::GetServerSettingsCount()
{
	return 0;   //FAKE   /ELiZ
}

FString AAA2_PlayerController::GetServerKey(int32 Index)
{
	return "FAKE";   //FAKE   /ELiZ
}

void AAA2_PlayerController::SetServerKey(int32 Index, FString Key)
{
}

FString AAA2_PlayerController::GetServerSettingValue(int32 Index)
{
	return "FAKE";   //FAKE   /ELiZ
}

void AAA2_PlayerController::SetServerSettingValue(int32 Index, FString Value)
{
}

FString AAA2_PlayerController::GetServerKeyValue(int32 Index)
{
	return "FAKE";   //FAKE   /ELiZ
}

void AAA2_PlayerController::SetServerKeyValue(int32 Index, FString Value)
{
}

void AAA2_PlayerController::RefreshServerInfo(bool bInitialize)
{
}

void AAA2_PlayerController::UpdateTimers(float DeltaTime)
{
}

FString AAA2_PlayerController::GetAuthUserName()
{
	return "FAKE";   //FAKE   /ELiZ
}

int32 AAA2_PlayerController::GetTraceDistance()
{
	//return int((float(Pawn.GetShortTraceDistance()) * 0.25));
	return 0;   //FAKE   /ELiZ
}

int32 AAA2_PlayerController::getMaxDistance(AActor* Other)
{
	return 1024;
}

void AAA2_PlayerController::ServerUTrace()
{
}

void AAA2_PlayerController::UTrace()
{
}

void AAA2_PlayerController::AddKey(int32 new_key)
{
	//DistributionHistory.Num() = (DistributionHistory.Num() + 1);
	//DistributionHistory[(DistributionHistory.Num() - 1)] = new_key;
}

void AAA2_PlayerController::ClientSetAccessControlKickMessage(FString sMessage)
{
	sKickReason = sMessage;
}

void AAA2_PlayerController::ClientRefreshDistributionHistory()
{
	/*
	DistributionHistory.RemoveAt(0, DistributionHistory.Num());
	FindDistributionKey("Distribution.ini");
	FindDistributionKey("Distribution270.ini");
	if (DistributionHistory.Num() == 0)
	{
		AddKey(0);
	}
	*/
}

void AAA2_PlayerController::FindDistributionKey(FString sFile)
{
	FString full_path = "";
	int32 i_key = 0;
	/*
	full_path = GetBaseDir() + sFile;
	i_key = GetPrivateProfileInt(full_path, "Distribution", "Partner");
	if (i_key != -1)
	{
		AddKey(i_key);
	}
	*/
}

void AAA2_PlayerController::ServerAddDistributionKey(int32 Key)
{
	int32 previous_len = 0;
	/*
	previous_len = DistributionHistory.Num();
	DistributionHistory.Num() = (previous_len + 1);
	DistributionHistory[previous_len] = Key;
	*/
}

void AAA2_PlayerController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	if (Pawn != nullptr)
	{
		Canvas.DrawText("bLockMovement: " + FString::FromInt(GetLockMovement()) + " bLockRotation: " + FString::FromInt(GetLockRotation()));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Pawn.bLockMovement: " + FString::FromInt(Pawn.bLockMovement));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("bTearOff: " + FString::FromInt(Pawn.bTearOff));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("TrackIR Yaw: " + FString::FromInt(fpTrackIRYaw) + "  Pitch: " + FString::FromInt(fpTrackIRPitch) + " BaseX: " + FString::FromInt(aBaseX) + " BaseY: " + FString::FromInt(aBaseY));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Pawn Rotation: " + FString::FromInt(Pawn.Rotation) + "  Controller Rotation: " + FString::FromInt(Rotation) + " Difference: " + FString::FromInt((Rotation.Yaw - Pawn.Rotation.Yaw)));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
	}
	*/
}

void AAA2_PlayerController::CleanUp()
{
	//Super::CleanUp();
	DesiredFOV = DefaultFOV;
	FovAngle = DesiredFOV;
	ResetSoundDampening();
}

void AAA2_PlayerController::CalcSoundDampening()
{
	ResetSoundDampening();
}

void AAA2_PlayerController::ResetSoundDampening()
{
	SoundDampening = 1;
}

void AAA2_PlayerController::Eye(float F)
{
	/*
	Pawn.BaseEyeHeight = F;
	Pawn.Default.BaseEyeHeight = F;
	*/
}

void AAA2_PlayerController::GetWeaponStats()
{
}

void AAA2_PlayerController::ServerGetWeaponStats(AWeapon* W)
{
	/*
	if ((GetPawn() == nullptr) || (Pawn.Weapon == nullptr))
	{
		Log("Weapon stats requested by " + PlayerReplicationInfo->PlayerName + " with pawn " + FString::FromInt(Pawn) + " and no weapon");
		return;
	}
	Log("Weapon stats requested by " + PlayerReplicationInfo->PlayerName + " for " + FString::FromInt(Pawn.Weapon));
	*/
}

void AAA2_PlayerController::PostBeginPlay()
{
	APlayerChatManager* PlayerChatClass = nullptr;
	/*
	Super::PostBeginPlay();
	MaxTimeMargin = Level.MaxTimeMargin;
	MaxResponseTime = (Default.MaxResponseTime * Level.TimeDilation);
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		SpawnDefaultHUD();
	}
	if (Level.LevelEnterText != "")
	{
		ClientMessage(Level.LevelEnterText);
	}
	FixFOV();
	SetViewTarget(this);
	LastActiveTime = GetWorld()->GetTimeSeconds();
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		AddCheats();
	}
	bForcePrecache = (Role < 4);
	ForcePrecacheTime = (GetWorld()->GetTimeSeconds() + 1.2);
	if (Level.Game != nullptr)
	{
		MapHandler = Level.Game.MaplistHandler;
	}
	if ((PlayerChatType != "") && (GetRemoteRole() == ENetRole::ROLE_MAX))
	{
		PlayerChatClass = class<PlayerChatManager>(DynamicLoadObject(PlayerChatType, Class'Class'));
		if (PlayerChatClass != nullptr)
		{
			ChatManager = Spawn(PlayerChatClass, this);
		}
	}
	*/
}

bool AAA2_PlayerController::BeyondViewDistance(FVector OtherLocation, float CullDistance)
{
	float dist = 0;
	if (ViewTarget == nullptr)
	{
		return true;
	}
	/*
	dist = VSize((OtherLocation - ViewTarget.Location));
	if ((CullDistance > 0) && (CullDistance < (dist * FOVBias)))
	{
		return true;
	}
	return (Region.Zone.bDistanceFog && (dist > Region.Zone.DistanceFogEnd));
	*/
	return false;   //FAKE   /ELiZ
}

void AAA2_PlayerController::KickWarning()
{
	//ReceiveLocalizedMessage(AGameMessage::StaticClass(), 15);
}

void AAA2_PlayerController::ResetTimeMargin()
{
	TimeMargin = -0.1;
	//MaxTimeMargin = Level.MaxTimeMargin;
}

void AAA2_PlayerController::ServerShortTimeout()
{
	AActor* A = nullptr;
	bShortConnectTimeOut = true;
	ResetTimeMargin();
	/*
	if (Level.Game.NumPlayers < 8)
	{
		ForEach AllActors(Class'Actor', A)
		{
			if ((A.NetUpdateFrequency < 1) && (!A.bOnlyRelevantToOwner))
			{
				A.NetUpdateTime = FMin(A.NetUpdateTime, (GetWorld()->GetTimeSeconds() + (0.2 * FMath::FRand())));
			}
		}
	}
	else
	{
		ForEach AllActors(Class'Actor', A)
		{
			if ((A.NetUpdateFrequency < 1) && (!A.bOnlyRelevantToOwner))
			{
				A.NetUpdateTime = FMin(A.NetUpdateTime, (GetWorld()->GetTimeSeconds() + (0.5 * FMath::FRand())));
			}
		}
	}
	*/
}

AActor* AAA2_PlayerController::GetPathTo(AActor* Dest)
{
	int32 i = 0;
	AActor* Best = nullptr;
	FVector Dir = FVector(0, 0, 0);
	if (Dest == nullptr)
	{
		return Dest;
	}
	/*
	if ((Pawn.Physics != 2) && ((RouteGoal != Dest) || ((GetWorld()->GetTimeSeconds() - LastRouteFind) > (1 + FMath::FRand()))))
	{
		MoveTarget = FindPathToward(Dest, false);
		if (MoveTarget == nullptr)
		{
			return Dest;
		}
	}
	if (RouteCache[0] == nullptr)
	{
		return Dest;
	}
	if (RouteCache[1] == nullptr)
	{
		return RouteCache[0];
	}
	Best = RouteCache[0];
	Dir = Normal((RouteCache[1].Location - RouteCache[0].Location));
	for (i = 0; i < 5; i++)
	{
		if ((RouteCache[i] == nullptr) || (VSize((Pawn.Location - RouteCache[i].Location)) > float(2000)))
		{
		}
		if (((Normal((RouteCache[i].Location - RouteCache[0].Location)) Dot Dir) > 0.7) && LineOfSightTo(RouteCache[i]))
		{
			Best = RouteCache[i];
		}
	}
	*/
	return Best;
}

void AAA2_PlayerController::StreamFinished(int32 StreamHandle, EStreamFinishReason Reason)
{
	int32 i = 0;
	/*
	if (Player != nullptr)
	{
		for (i = 0; i < Player->LocalInteractions.Num(); i++)
		{
			if (Player->LocalInteractions[i] != nullptr)
			{
				Player->LocalInteractions[i]->StreamFinished(StreamHandle, Reason);
			}
		}
	}
	*/
}

void AAA2_PlayerController::KillAll(AActor* aClass)
{
	AActor* A = nullptr;
	AController* C = nullptr;
	/*
	if (Role != 4)
	{
		return;
	}
	if (CheatManager != nullptr)
	{
		CheatManager.ReportCheat("KillAll");
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			Cast<APlayerController>(C).ClientMessage("Killed all " + FString::FromInt(aClass));
		}
	}
	if (ClassIsChildOf(aClass, Class'AIController'))
	{
		Level.Game.KillBots(Level.Game.NumBots);
		return;
	}
	if (ClassIsChildOf(aClass, Class'Pawn'))
	{
		KillAllPawns(class<Pawn>(aClass));
		return;
	}
	ForEach DynamicActors(Class'Actor', A)
	{
		if (ClassIsChildOf(A.Class, aClass))
		{
			A.Destroy();
		}
	}
	*/
}

void AAA2_PlayerController::KillAllPawns(APawn* aClass)
{
	APawn* p = nullptr;
	/*
	Level.Game.KillBots(Level.Game.NumBots);
	ForEach DynamicActors(Class'Pawn', p)
	{
		if (ClassIsChildOf(p.Class, aClass) && (!p.IsPlayerPawn()))
		{
			if (p.Controller != nullptr)
			{
				p.Controller.Destroy();
			}
			p.Destroy();
		}
	}
	*/
}

void AAA2_PlayerController::ToggleScreenShotMode()
{
	if (myHUD->bCrosshairShow)
	{
		myHUD->bCrosshairShow = false;
		SetWeaponHand("Hidden");
		myHUD->bHideHUD = true;
		TeamBeaconMaxDist = 0;
		bHideVehicleNoEntryIndicator = true;
	}
	else
	{
		myHUD->bCrosshairShow = true;
		SetWeaponHand("Right");
		myHUD->bHideHUD = false;
		TeamBeaconMaxDist = GetDefault<AAA2_PlayerController>()->TeamBeaconMaxDist;
		bHideVehicleNoEntryIndicator = false;
	}
}

void AAA2_PlayerController::SetSpectateSpeed(float F)
{
	SpectateSpeed = F;
	ServerSpectateSpeed(F);
}

void AAA2_PlayerController::ClientSetWeaponViewShake(bool B)
{
	bWeaponViewShake = B;
}

void AAA2_PlayerController::ClientSetClassicView()
{
	//Level.bClassicView = true;
}

void AAA2_PlayerController::ServerSpectateSpeed(float F)
{
	SpectateSpeed = F;
}

void AAA2_PlayerController::ServerGivePawn()
{
	//GivePawn(Pawn);
}

void AAA2_PlayerController::ClientCapBandwidth(int32 Cap)
{
	ClientCap = Cap;
	/*
	if ((Player != nullptr) && (Player.CurrentNetSpeed > Cap))
	{
		SetNetSpeed(Cap);
	}
	*/
}

void AAA2_PlayerController::PendingStasis()
{
	/*
	bStasis = true;
	Pawn = nullptr;
	GotoState("Scripting");
	*/
}

void AAA2_PlayerController::AddCheats()
{
	/*
	if ((CheatManager == nullptr) && (GetWorld()->GetNetMode() == NM_Standalone))
	{
		CheatManager = new (this) classCheatClass;
	}
	*/
}

void AAA2_PlayerController::MakeAdmin()
{
	/*
	if ((((AdminManager == nullptr) && (Level != nullptr)) && (Level.Game != nullptr)) && (Level.Game.AccessControl != nullptr))
	{
		if (Level.Game.AccessControl.AdminClass == nullptr)
		{
			Log("AdminClass is None");
		}
	}
	*/
}

void AAA2_PlayerController::HandlePickup(APickup* pick)
{
	//ReceiveLocalizedMessage(pick.MessageClass, , , , pick.Class);
}

void AAA2_PlayerController::ClientSetViewTarget(AActor* A)
{
	bool bNewViewTarget = false;
	if (A == nullptr)
	{
		if (ViewTarget != this)
		{
			//SetLocation(CalcViewLocation);
		}
		ServerVerifyViewTarget();
	}
	else
	{
		bNewViewTarget = (ViewTarget != A);
		SetViewTarget(A);
		if (bNewViewTarget)
		{
			//A->POVChanged(this, false);
		}
	}
}

void AAA2_PlayerController::ClientSetViewFocus(AActor* A)
{
	bool bNewViewTarget = false;
	//bNewViewTarget = (FocusTarget != A);
	SetFocusTarget(A);
}

void AAA2_PlayerController::KillCheats()
{
	CheatManager = nullptr;
}

void AAA2_PlayerController::ClientSetScoreMode(bool bAllowsLocalScore)
{
	bAllowScoreShown = bAllowsLocalScore;
}

void AAA2_PlayerController::ServerVerifyViewTarget()
{
	if (ViewTarget == this)
	{
		return;
	}
	if (ViewTarget == nullptr)
	{
		return;
	}
	ClientSetViewTarget(ViewTarget);
}

void AAA2_PlayerController::SpawnDefaultHUD()
{
	//myHUD = Spawn(Class'HUD', this);
}

void AAA2_PlayerController::Reset()
{
	AVehicle* DrivenVehicle = nullptr;
	/*
	DrivenVehicle = Cast<AVehicle>(Pawn);
	if (DrivenVehicle != nullptr)
	{
		DrivenVehicle->KDriverLeave(true);
	}
	if (Pawn != nullptr)
	{
		PawnDied(Pawn);
	}
	Super::Reset();
	SetViewTarget(this);
	ClientSetViewTarget(this);
	ClientSetFixedCamera(false);
	bBehindView = false;
	WaitDelay = (GetWorld()->GetTimeSeconds() + 2);
	FixFOV();
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		GotoState("Spectating");
	}
	else
	{
		GotoState("PlayerWaiting");
	}
	*/
}

void AAA2_PlayerController::ClientReset()
{
	bBehindView = false;
	bFixedCamera = false;
	SetViewTarget(this);
	/*
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		GotoState("Spectating");
	}
	else
	{
		GotoState("PlayerWaiting");
	}
	*/
}

void AAA2_PlayerController::CleanOutSavedMoves()
{
	ASavedMove* Next = nullptr;
	if (SavedMoves != nullptr)
	{
		Next = SavedMoves->NextMove;
		SavedMoves->Destroy();
		SavedMoves = Next;
	}
	if (PendingMove != nullptr)
	{
		PendingMove->Destroy();
		PendingMove = nullptr;
	}
}

void AAA2_PlayerController::InitInputSystem()
{
	/*
	PlayerInput = new (this) classInputClass;
	if (_bPendingPlayerLock)
	{
		LockPlayer(_bPendingLockMovement, _bPendingLockRotation);
	}
	Player.Console.bMenuRestricted = bMenuRestricted;
	*/
}

void AAA2_PlayerController::ClientLockPlayer(bool bLockMovement, bool bLockRotation)
{
	if (PlayerInput != nullptr)
	{
		if (_bMenuLock == true)
		{
			_bSavedLockRotation = bLockRotation;
			_bSavedLockMovement = bLockMovement;
		}
		else
		{
			_bPendingPlayerLock = false;
			//PlayerInput->Lock(bLockMovement, bLockRotation);
		}
	}
	else
	{
		_bPendingPlayerLock = true;
		_bPendingLockRotation = bLockRotation;
		_bPendingLockMovement = bLockMovement;
	}
}

void AAA2_PlayerController::LockPlayer(bool bLockMovement, bool bLockRotation)
{
	ClientLockPlayer(bLockMovement, bLockRotation);
	/*
	if ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GetWorld()->GetNetMode() == NM_ListenServer))
	{
		_ServerLockMovement = bLockMovement;
		_ServerLockRotation = bLockRotation;
	}
	*/
}

void AAA2_PlayerController::MenuLock(bool bLock)
{
	if (bLock)
	{
		if (_bMenuLock == false)
		{
			_bSavedLockRotation = GetLockRotation();
			_bSavedLockMovement = GetLockMovement();
			_bMenuLock = true;
			if (PlayerInput != nullptr)
			{
				//PlayerInput->Lock(true, true);
			}
		}
	}
	else
	{
		if (_bMenuLock == true)
		{
			_bMenuLock = false;
			LockPlayer(_bSavedLockMovement, _bSavedLockRotation);
		}
	}
}

bool AAA2_PlayerController::GetLockMovement()
{
	if (PlayerInput != nullptr)
	{
		//return PlayerInput->bLockMovement;
	}
	else
	{
		return false;
	}
	return false;    //FAKE   /ELiZ
}

bool AAA2_PlayerController::GetLockRotation()
{
	if (PlayerInput != nullptr)
	{
		//return PlayerInput->bLockRotation;
	}
	else
	{
		return false;
	}
	return false;    //FAKE   /ELiZ
}

bool AAA2_PlayerController::GetInvertMouse()
{
	if (PlayerInput != nullptr)
	{
		//return PlayerInput->bInvertMouse;
	}
	else
	{
		return false;
	}
	return false;    //FAKE   /ELiZ
}

bool AAA2_PlayerController::CanFire()
{
	return bCanFire;
}

void AAA2_PlayerController::SetCanFire(bool CanFire)
{
	bCanFire = CanFire;
}

void AAA2_PlayerController::ClientGotoState(FName NewState, FName NewLabel)
{
	//GotoState(NewState, NewLabel);
}

void AAA2_PlayerController::AskForPawn()
{
	/*
	if (IsInState("GameEnded"))
	{
		ClientGotoState("GameEnded", "Begin");
	}
	else
	{
		if (IsInState("RoundEnded"))
		{
			ClientGotoState("RoundEnded", "Begin");
		}
		else
		{
			if (Pawn != nullptr)
			{
				GivePawn(Pawn);
			}
			else
			{
				bFrozen = false;
				ServerReStartPlayer();
			}
		}
	}
	*/
}

void AAA2_PlayerController::GivePawn(APawn* NewPawn)
{
	if (NewPawn == nullptr)
	{
		return;
	}
	/*
	if (NewPawn == Pawn)
	{
		return;
	}
	Pawn = NewPawn;
	NewPawn.Controller = this;
	ClientReStart(Pawn);
	*/
}

int32 AAA2_PlayerController::GetFacingDirection()
{
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector Dir = FVector(0, 0, 0);
	/*
	GetAxes(Pawn.Rotation, X, Y, Z);
	Dir = Normal(Pawn.Acceleration);
	if ((Y Dot Dir) > 0)
	{
		return int((float(49152) + (float(16384) * (X Dot Dir))));
	}
	else
	{
		return int((float(16384) - (float(16384) * (X Dot Dir))));
	}
	*/
	return 0;   //FAKE  /ELiZ
}

void AAA2_PlayerController::SimplePossess(APawn* aPawn)
{
	/*
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		return;
	}
	ResetFOV();
	aPawn.PossessedBy(this);
	Pawn = aPawn;
	Pawn.bStasis = false;
	ResetTimeMargin();
	CleanOutSavedMoves();
	if ((Cast<AVehicle>(Pawn) != nullptr) && (Cast<AVehicle>(Pawn).Driver != nullptr))
	{
		PlayerReplicationInfo->bIsFemale = Vehicle(Pawn).Driver.bIsFemale;
	}
	else
	{
		PlayerReplicationInfo->bIsFemale = Pawn.bIsFemale;
	}
	SimpleRestart();
	*/
}

/*
void AAA2_PlayerController::Possess(APawn* aPawn)
{
	if (PlayerReplicationInfo->bOnlySpectator)
	{
		return;
	}
	ResetFOV();
	aPawn.PossessedBy(this);
	Pawn = aPawn;
	Pawn.bStasis = false;
	ResetTimeMargin();
	CleanOutSavedMoves();
	if ((Cast<AVehicle>(Pawn) != nullptr) && (Cast<AVehicle>(Pawn).Driver != nullptr))
	{
		PlayerReplicationInfo->bIsFemale = Vehicle(Pawn).Driver.bIsFemale;
	}
	else
	{
		PlayerReplicationInfo->bIsFemale = Pawn.bIsFemale;
	}
	ServerSetHandedness(Handedness);
	ServerSetAutoTaunt(bAutoTaunt);
	Restart();
}
*/

void AAA2_PlayerController::AcknowledgePossession(APawn* p)
{
	/*
	if (Viewport(Player) != nullptr)
	{
		AcknowledgedPawn = p;
		if (p != nullptr)
		{
			p.SetBaseEyeheight();
		}
		ServerAcknowledgePossession(p, Handedness, bAutoTaunt);
	}
	*/
}

void AAA2_PlayerController::ServerAcknowledgePossession(APawn* p, float NewHand, bool bNewAutoTaunt)
{
	ResetTimeMargin();
	AcknowledgedPawn = p;
	ServerSetHandedness(NewHand);
	ServerSetAutoTaunt(bNewAutoTaunt);
}

/*
void AAA2_PlayerController::UnPossess()
{
	if (Pawn != nullptr)
	{
		SetActorLocation(Pawn.Location);
		Pawn.RemoteRole = ROLE_SimulatedProxy;
		Pawn.UnPossessed();
		CleanOutSavedMoves();
		if (ViewTarget == Pawn)
		{
			SetViewTarget(this);
		}
	}
	Pawn = nullptr;
	GotoState("Spectating");
}
*/

void AAA2_PlayerController::ViewNextBot()
{
	if (CheatManager != nullptr)
	{
		CheatManager->ViewBot();
	}
}

void AAA2_PlayerController::PawnDied(APawn* p)
{
	/*
	if (p != Pawn)
	{
		return;
	}
	EndZoom();
	if (Pawn != nullptr)
	{
		Pawn.RemoteRole = ROLE_SimulatedProxy;
	}
	ClientGotoState("Dead", "None");
	Super::PawnDied(p);
	*/
}

void AAA2_PlayerController::ClientUpdateFlagHolder(AAA2_PlayerState* PRI, int32 i)
{
	/*
	if ((GetRemoteRole() == ENetRole::ROLE_MAX) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	GameReplicationInfo->FlagHolder[i] = PRI;
	*/
}

void AAA2_PlayerController::ClientSetHUD(AAA2_HUD* newHUDClass, AScoreBoard* newScoringClass)
{
	if (myHUD != nullptr)
	{
		myHUD->Destroy();
	}
	if (newHUDClass == nullptr)
	{
		myHUD = nullptr;
	}
	else
	{
		/*
		myHUD = Spawn(newHUDClass, this);
		if (myHUD == nullptr)
		{
			Log("PlayerController::ClientSetHUD(): Could not spawn a HUD of class " + FString::FromInt(newHUDClass), "Error");
		}
		else
		{
			myHUD->SetScoreBoardClass(newScoringClass);
		}
		*/
	}
	if (((Cast<AAA2_WorldSettings>(GetWorldSettings())->Song != "") && (Cast<AAA2_WorldSettings>(GetWorldSettings())->Song != "None")) && (!bPauseMusic))
	{
		ClientSetInitialMusic(Cast<AAA2_WorldSettings>(GetWorldSettings())->Song, EMusicTransition::MTRAN_Fade);
	}
	bPauseMusic = false;
}

void AAA2_PlayerController::ClientPlayForceFeedback(FString EffectName)
{
	/*
	if (bForceFeedbackSupported && (Viewport(Player) != nullptr))
	{
		PlayFeedbackEffect(EffectName);
	}
	*/
}

void AAA2_PlayerController::StopForceFeedback(FString EffectName)
{
	/*
	if (bForceFeedbackSupported && (Viewport(Player) != nullptr))
	{
		StopFeedbackEffect(EffectName);
	}
	*/
}

void AAA2_PlayerController::ClientStopForceFeedback(FString EffectName)
{
	/*
	if (bForceFeedbackSupported && (Viewport(Player) != nullptr))
	{
		StopFeedbackEffect(EffectName);
	}
	*/
}

float AAA2_PlayerController::UpdateFlashComponent(float Current, float Step, float Goal)
{
	/*
	if (Goal > Current)
	{
		return FMin((Current + Step), Goal);
	}
	else
	{
		return FMax((Current - Step), Goal);
	}
	*/
	return 0;    //FAKE  /EliZ
}

void AAA2_PlayerController::ViewFlash(float DeltaTime)
{
	FVector goalFog = FVector(0, 0, 0);
	float goalscale = 0;
	float Delta = 0;
	float Step = 0;
	APhysicsVolume* ViewVolume = nullptr;
	/*
	Delta = FMin(0.1, DeltaTime);
	goalscale = 1;
	goalFog = FVector(0, 0, 0);
	if (Pawn != nullptr)
	{
		if (bBehindView)
		{
			ViewVolume = Cast<AAA2_WorldSettings>(GetWorldSettings())->GetPhysicsVolume(CalcViewLocation);
		}
		else
		{
			ViewVolume = Pawn.HeadVolume;
		}
		(goalscale += ViewVolume.ViewFlash.X);
		(goalFog += ViewVolume.ViewFog);
	}
	Step = ((0.6 * Delta) * ScreenFlashScaling);
	FlashScale.X = UpdateFlashComponent(FlashScale.X, Step, goalscale);
	FlashScale = (FlashScale.X *  FVector(1, 1, 1));
	FlashFog.X = UpdateFlashComponent(FlashFog.X, Step, goalFog.X);
	FlashFog.Y = UpdateFlashComponent(FlashFog.Y, Step, goalFog.Y);
	FlashFog.Z = UpdateFlashComponent(FlashFog.Z, Step, goalFog.Z);
	*/
}

void AAA2_PlayerController::ReceiveLocalizedMessage(AaLocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//Message.ClientReceive(this, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject, ExtraText);
}

void AAA2_PlayerController::ChatRoomMessage(uint8 Result, int32 ChannelIndex, AAA2_PlayerState* RelatedPRI)
{
	AVoiceChatRoom* VCR = nullptr;
	FString str = "";
	/*
	if ((VoiceReplicationInfo != nullptr) && (ChatRoomMessageClass != nullptr))
	{
		VCR = VoiceReplicationInfo->GetChannelAt(ChannelIndex);
		if (VCR != nullptr)
		{
			str = VCR->GetTitle();
		}
		if (((str ~= "Team") || (str ~= "Public")) || (str ~= "Local"))
		{
			return;
		}
		ClientMessage(ChatRoomMessageClass.AssembleMessage(Result, str, RelatedPRI));
	}
	*/
}

void AAA2_PlayerController::ClientMessage(FString S, FName Type)
{
	/*
	if ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	if (Type == "None")
	{
		Type = "Event";
	}
	*/
	TeamMessage(PlayerReplicationInfo, S, Type);
}

bool AAA2_PlayerController::AllowTextToSpeech(AAA2_PlayerState* PRI, FName Type)
{
	if (bNoTextToSpeechVoiceMessages || (PRI == nullptr))
	{
		return false;
	}
	if (Type == "Say")
	{
		/*
		if ((PRI.bAdmin || ((GameReplicationInfo != nullptr) && (!GameReplicationInfo->bTeamGame))) || (PRI == PlayerReplicationInfo))
		{
			return true;
		}
		if (IsInState("GameEnded") || IsInState("RoundEnded"))
		{
			return true;
		}
		*/
		return (!bOnlySpeakTeamText);
	}
	else
	{
		if (((((Type == "TeamSay") || (Type == "AdminSay")) || (Type == "Global")) || (Type == "Radio")) || (Type == "Squad"))
		{
			return true;
		}
	}
	return false;
}

void AAA2_PlayerController::TeamMessage(AAA2_PlayerState* PRI,FString S, FName Type)
{
}

void AAA2_PlayerController::PlayBeepSound()
{
}

void AAA2_PlayerController::PrecacheAnnouncements()
{
	if (RewardAnnouncer != nullptr)
	{
		RewardAnnouncer->PrecacheAnnouncements(true);
	}
	if (StatusAnnouncer != nullptr)
	{
		StatusAnnouncer->PrecacheAnnouncements(false);
	}
}

void AAA2_PlayerController::PlayStatusAnnouncement(FName AName, uint8 AnnouncementLevel, bool bForce)
{
	float Atten = 0;
	USoundBase* ASound = nullptr;
	/*
	if ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	if ((AnnouncementLevel > AnnouncerLevel) || (StatusAnnouncer == nullptr))
	{
		return;
	}
	if ((!bForce) && ((GetWorld()->GetTimeSeconds() - LastPlaySound) < 1))
	{
		return;
	}
	LastPlaySound = GetWorld()->GetTimeSeconds();
	LastPlaySpeech = GetWorld()->GetTimeSeconds();
	Atten = (2 *FMath::Clamp((0.1 + (float(AnnouncerVolume) * 0.225)), 0.2, 1));
	ASound = StatusAnnouncer.GetSound(AName);
	if (ASound != nullptr)
	{
		ClientPlaySound(ASound, true, Atten, 5);
	}
	*/
}

void AAA2_PlayerController::PlayRewardAnnouncement(FName AName, uint8 AnnouncementLevel, bool bForce)
{
	float Atten = 0;
	USoundBase* ASound = nullptr;
	/*
	if ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	if ((AnnouncementLevel > AnnouncerLevel) || (RewardAnnouncer == nullptr))
	{
		return;
	}
	if ((!bForce) && ((GetWorld()->GetTimeSeconds() - LastPlaySound) < 1))
	{
		return;
	}
	LastPlaySound = GetWorld()->GetTimeSeconds();
	LastPlaySpeech = GetWorld()->GetTimeSeconds();
	Atten = (2 *FMath::Clamp((0.1 + (float(AnnouncerVolume) * 0.225)), 0.2, 1));
	ASound = RewardAnnouncer.GetSound(AName);
	if (ASound != nullptr)
	{
		ClientPlaySound(ASound, true, Atten, 5);
	}
	*/
}

void AAA2_PlayerController::PlayAnnouncement(USoundBase* ASound, uint8 AnnouncementLevel, bool bForce)
{
	float Atten = 0;
	if (AnnouncementLevel > AnnouncerLevel)
	{
		return;
	}
	/*
	if ((!bForce) && ((GetWorld()->GetTimeSeconds() - LastPlaySound) < 1))
	{
		return;
	}
	LastPlaySound = GetWorld()->GetTimeSeconds();
	LastPlaySpeech = GetWorld()->GetTimeSeconds();
	Atten = (2 *FMath::Clamp((0.1 + (float(AnnouncerVolume) * 0.225)), 0.2, 1));
	ClientPlaySound(ASound, true, Atten, 5);
	*/
}

USoundBase* AAA2_PlayerController::CustomizeAnnouncer(USoundBase* AnnouncementSound)
{
	return AnnouncementSound;
}

void AAA2_PlayerController::QueueAnnouncement(FName ASoundName, uint8 AnnouncementLevel, EAPriority Priority, uint8 Switch)
{
	/*
	if (((AnnouncementLevel > AnnouncerLevel) || (GetWorld()->GetNetMode() == NM_DedicatedServer)) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	if (AnnouncerQueueManager == nullptr)
	{
		//AnnouncerQueueManager = Spawn(AAnnouncerQueueManager::StaticClass());
		AnnouncerQueueManager->InitFor(this);
	}
	if (AnnouncerQueueManager != nullptr)
	{
		AnnouncerQueueManager->AddItemToQueue(ASoundName, Priority, Switch);
	}
	*/
}

bool AAA2_PlayerController::AllowVoiceMessage(FName messagetype)
{
	/*
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		return true;
	}
	if ((GetWorld()->GetTimeSeconds() - OldMessageTime) < 3)
	{
		if ((messagetype == "TAUNT") || (messagetype == "AutoTaunt"))
		{
			return false;
		}
		if ((GetWorld()->GetTimeSeconds() - OldMessageTime) < 1)
		{
			return false;
		}
	}
	if ((GetWorld()->GetTimeSeconds() - OldMessageTime) < 6)
	{
		OldMessageTime = (GetWorld()->GetTimeSeconds() + 3);
	}
	else
	{
		OldMessageTime = GetWorld()->GetTimeSeconds();
	}
	*/
	return true;
}

void AAA2_PlayerController::ClientPlaySound(USoundBase* ASound, bool bVolumeControl, float inAtten, ESoundSlot Slot)
{
	float Atten = 0;
	Atten = 1;
	if (bVolumeControl)
	{
		//Atten =FMath::Clamp(inAtten, 0, 2);
	}
	if (ViewTarget != nullptr)
	{
		//ViewTarget.PlaySound(ASound, Slot, Atten, , , , false);
	}
}

void AAA2_PlayerController::ClientReliablePlaySound(USoundBase* ASound, bool bVolumeControl)
{
	ClientPlaySound(ASound, bVolumeControl, 0, ESoundSlot::SLOT_None);
}

void AAA2_PlayerController::Destroyed()
{
	ASavedMove* Next = nullptr;
	AVehicle* DrivenVehicle = nullptr;
	APawn* Driver = nullptr;
	if (AdminManager != nullptr)
	{
		AdminManager->DoLogout();
	}
	/*
	StopFeedbackEffect();
	if (Pawn != nullptr)
	{
		DrivenVehicle = Vehicle(Pawn);
		if (DrivenVehicle != nullptr)
		{
			Driver = DrivenVehicle.Driver;
			DrivenVehicle.KDriverLeave(true);
			if (Driver != nullptr)
			{
				Driver.Health = 0;
				Driver.Died(this, ASuicided::StaticClass(), Driver.Location);
			}
		}
		else
		{
			Pawn.Health = 0;
			Pawn.Died(this, ASuicided::StaticClass(), Pawn.Location);
		}
	}
	*/

	if (myHUD != nullptr)
	{
		myHUD->Destroy();
		myHUD = nullptr;
	}
	if (AnnouncerQueueManager != nullptr)
	{
		AnnouncerQueueManager->Destroy();
	}
	if (FreeMoves != nullptr)
	{
		Next = FreeMoves->NextMove;
		FreeMoves->Destroy();
		FreeMoves = Next;
	}
	if (SavedMoves != nullptr)
	{
		Next = SavedMoves->NextMove;
		SavedMoves->Destroy();
		SavedMoves = Next;
	}
	if (PlayerSecurity != nullptr)
	{
		PlayerSecurity->Destroy();
		PlayerSecurity = nullptr;
	}
	if (ChatManager != nullptr)
	{
		ChatManager->Destroy();
	}
	CheatManager = nullptr;
	PlayerInput = nullptr;
	CameraEffects.Empty();
	Super::Destroyed();
}

void AAA2_PlayerController::ClientSetMusic(FString NewSong, EMusicTransition NewTransition)
{
	float FadeIn = 0;
	float FadeOut = 0;
	/*
	switch (NewTransition)
	{
	case 2:
		FadeIn = 7;
		FadeOut = 3;
		break;
	case 3:
		FadeIn = 3;
		FadeOut = 3;
		break;
	case 4:
		FadeIn = 1;
		FadeOut = 1;
		break;
	case 5:
		FadeIn = 5;
		FadeOut = 5;
		break;
	default:
	}
	StopAllMusic(FadeOut);
	if (NewSong != "")
	{
		PlayMusic(NewSong, FadeIn);
	}
	Song = NewSong;
	Transition = NewTransition;
	if ((Player != nullptr) && (Player.Console != nullptr))
	{
		Player.Console.SetMusic(NewSong);
	}
	*/
}

void AAA2_PlayerController::ClientSetInitialMusic(FString NewSong, EMusicTransition NewTransition)
{
	FString SongName = "";
	if (Song != "")
	{
		return;
	}
	SongName = NewSong;
	/*
	if ((Player != nullptr) && (Player.Console != nullptr))
	{
		SongName = Player.Console.SetInitialMusic(NewSong);
	}
	*/
	ClientSetMusic(SongName, NewTransition);
}

void AAA2_PlayerController::ToggleZoomWithMax(float MaxZoomLevel)
{
	if (DefaultFOV != DesiredFOV)
	{
		EndZoom();
	}
	else
	{
		StartZoomWithMax(MaxZoomLevel);
	}
}

void AAA2_PlayerController::StartZoomWithMax(float MaxZoomLevel)
{
	//myHUD->FadeZoom();
}

void AAA2_PlayerController::ToggleZoom()
{
	ToggleZoomWithMax(0.9);
}

void AAA2_PlayerController::StartZoom()
{
	StartZoomWithMax(0.9);
}

void AAA2_PlayerController::StopZoom()
{
	bZooming = false;
}

void AAA2_PlayerController::EndZoom()
{
	if ((DesiredFOV != DefaultFOV) && (myHUD != nullptr))
	{
		//myHUD->FadeZoom();
	}
	bZooming = false;
	DesiredFOV = DefaultFOV;
}

void AAA2_PlayerController::FixFOV()
{
	FovAngle = GetDefault<AAA2_PlayerController>()->DefaultFOV;
	DesiredFOV = GetDefault<AAA2_PlayerController>()->DefaultFOV;
	DefaultFOV = GetDefault<AAA2_PlayerController>()->DefaultFOV;
}

void AAA2_PlayerController::SetFOV(float NewFOV)
{
	DesiredFOV = NewFOV;
	FovAngle = NewFOV;
}

void AAA2_PlayerController::ResetFOV()
{
	DesiredFOV = DefaultFOV;
	FovAngle = DefaultFOV;
}

void AAA2_PlayerController::FOV(float F)
{
}

void AAA2_PlayerController::Mutate(FString MutateString)
{
	ServerMutate(MutateString);
}

void AAA2_PlayerController::ServerMutate(FString MutateString)
{
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	Level.Game.BaseMutator.Mutate(MutateString, this);
	*/
}

void AAA2_PlayerController::SetSensitivity(float F)
{
	//PlayerInput->UpdateSensitivity(F);
}

void AAA2_PlayerController::SetMouseSmoothing(int32 Mode)
{
	//PlayerInput->UpdateSmoothing(Mode);
}

void AAA2_PlayerController::SetMouseAccel(float F)
{
	//PlayerInput->UpdateAccel(F);
}

void AAA2_PlayerController::ForceReload()
{
	/*
	if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
	{
	}
	*/
}

bool AAA2_PlayerController::AllowTextMessage(FString Msg)
{
	int32 i = 0;
	/*
	if ((GetWorld()->GetNetMode() == NM_Standalone) || PlayerReplicationInfo->bAdmin)
	{
		return true;
	}
	if ((Level.Pauser == nullptr) && ((GetWorld()->GetTimeSeconds() - LastBroadcastTime) < 2))
	{
		return false;
	}
	if ((GetWorld()->GetTimeSeconds() - LastBroadcastTime) < 5)
	{
		Msg = Left(Msg, Clamp((Len(Msg) - 4), 8, 64));
		for (i = 0; i < 4; i++)
		{
			if (LastBroadcastString[i] ~= Msg)
			{
				return false;
			}
		}
	}
	for (i = 3; i > 0; i--)
	{
		LastBroadcastString[i] = LastBroadcastString[(i - 1)];
	}
	LastBroadcastTime = GetWorld()->GetTimeSeconds();
	*/
	return true;
}

void AAA2_PlayerController::Say(FString Msg)
{
	/*
	if (PlayerReplicationInfo->bAdmin && (Left(Msg, 1) == "#"))
	{
		Level.Game.AdminSay(Right(Msg, (Len(Msg) - 1)));
		return;
	}
	Level.Game.Broadcast(this, Msg, "Say");
	*/
}

void AAA2_PlayerController::TeamSay(FString Msg)
{
	/*
	Msg = Left(Msg, 128);
	if (AllowTextMessage(Msg))
	{
		ServerTeamSay(Msg);
	}
	*/
}

void AAA2_PlayerController::ServerTeamSay(FString Msg)
{
	/*
	LastActiveTime = GetWorld()->GetTimeSeconds();
	Msg = Level.Game.StripColor(Msg);
	if (!GameReplicationInfo->bTeamGame)
	{
		Say(Msg);
		return;
	}
	Level.Game.BroadcastTeam(this, Level.Game.ParseMessageString(Level.Game.BaseMutator, this, Msg), "TeamSay");
	*/
}

void AAA2_PlayerController::ServerSetAutoTaunt(bool Value)
{
	bAutoTaunt = Value;
}

void AAA2_PlayerController::SetAutoTaunt(bool Value)
{
	//Class'PlayerController'.Default.bAutoTaunt = Value;
	//Class'PlayerController'.StaticSaveConfig();
	bAutoTaunt = Value;
	ServerSetAutoTaunt(Value);
}

void AAA2_PlayerController::ServerSetHandedness(float hand)
{
	Handedness = hand;
	/*
	if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
	{
		Pawn.Weapon.SetHand(Handedness);
	}
	*/
}

void AAA2_PlayerController::SetHand(int32 IntValue)
{
	Handedness = float(IntValue);
	SaveConfig();
	/*
	if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
	{
		Pawn.Weapon.SetHand(Handedness);
	}
	*/
	ServerSetHandedness(Handedness);
}

void AAA2_PlayerController::SetWeaponHand(FString S)
{
	/*
	if (S ~= "Left")
	{
		Handedness = -1;
	}
	else
	{
		if (S ~= "Right")
		{
			Handedness = 1;
		}
		else
		{
			if (S ~= "Center")
			{
				Handedness = 0;
			}
			else
			{
				if (S ~= "Hidden")
				{
					Handedness = 2;
				}
			}
		}
	}
	SetHand(int(Handedness));
	*/
}

bool AAA2_PlayerController::isDead()
{
	return false;
}

void AAA2_PlayerController::ShowGun()
{
	if (Handedness == 2)
	{
		Handedness = 1;
	}
	else
	{
		Handedness = 2;
	}
	SetHand(int(Handedness));
}

void AAA2_PlayerController::PreClientTravel()
{
	//Log("PreClientTravel");
	ClientStopForceFeedback("");
}

void AAA2_PlayerController::ClientSetFixedCamera(bool B)
{
	bFixedCamera = B;
}

void AAA2_PlayerController::ClientSetBehindView(bool B, bool bSetFreeCamera)
{
	bool bWasBehindView = false;
	bWasBehindView = bBehindView;
	bBehindView = B;
	CameraDist = GetDefault<AAA2_PlayerController>()->CameraDist;
	/*
	if (bBehindView != bWasBehindView)
	{
		ViewTarget.POVChanged(this, true);
	}
	if (bSetFreeCamera)
	{
		bFreeCamera = B;
	}
	CameraDist = GetDefault<AAA2_PlayerController>()->CameraDist;
	if (Cast<AVehicle>(Pawn) != nullptr)
	{
		Vehicle(Pawn).bDesiredBehindView = B;
		Pawn.SaveConfig();
	}
	*/
}

void AAA2_PlayerController::ClientVoiceMessage(AAA2_PlayerState* Sender, AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID)
{
	AVoicePack* V = nullptr;
	/*
	if (((Sender == nullptr) || (Sender.VoiceType == nullptr)) || (Player.Console == nullptr))
	{
		return;
	}
	V = Spawn(Sender.VoiceType, this);
	if (V != nullptr)
	{
		V.ClientInitialize(Sender, Recipient, messagetype, MessageID);
	}
	*/
}

void AAA2_PlayerController::ForceDeathUpdate()
{
	//LastUpdateTime = (GetWorld()->GetTimeSeconds() - float(10));
}

void AAA2_PlayerController::RocketServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
{
	ServerMove(TimeStamp, InAccel, ClientLoc, false, NewbDuck, false, false, EDoubleClickDir::DCLICK_None, ClientRoll, View,0,0);
}

void AAA2_PlayerController::DualRocketServerMove(float TimeStamp0, FVector InAccel0, bool NewbDuck0, uint8 ClientRoll0, int32 View0, float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
{
	ServerMove(TimeStamp0, InAccel0, FVector(0, 0, 0), false, NewbDuck0, false, false, EDoubleClickDir::DCLICK_None, ClientRoll0, View0,0,0);
	ServerMove(TimeStamp, InAccel, ClientLoc, false, NewbDuck, false, false, EDoubleClickDir::DCLICK_None, ClientRoll, View,0,0);
}

void AAA2_PlayerController::SpaceFighterServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, int32 ViewPitch, int32 ViewYaw, int32 ViewRoll)
{
	FRotator BackupView = FRotator(0, 0, 0);
	BackupView.Pitch = ViewPitch;
	BackupView.Yaw = ViewYaw;
	BackupView.Roll = ViewRoll;
	/*
	SetActorRotation(BackupView);
	if (Pawn != nullptr)
	{
		Pawn.SetRotation(BackupView);
	}
	Global.TeamInfo(TimeStamp, InAccel, ClientLoc, false, NewbDuck, false, false, 0, 0, 0);
	*/
}

void AAA2_PlayerController::DualSpaceFighterServerMove(float TimeStamp0, FVector InAccel0, bool NewbDuck0, int32 ViewPitch0, int32 ViewYaw0, int32 ViewRoll0, float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbDuck, int32 ViewPitch, int32 ViewYaw, int32 ViewRoll)
{
	FRotator BackupView = FRotator(0, 0, 0);
	BackupView.Pitch = ViewPitch0;
	BackupView.Yaw = ViewYaw0;
	BackupView.Roll = ViewRoll0;
	/*
	SetActorRotation(BackupView);
	if (Pawn != nullptr)
	{
		Pawn.SetRotation(BackupView);
	}
	Global.TeamInfo(TimeStamp0, InAccel0, FVector(0, 0, 0), false, NewbDuck0, false, false, 0, 0, 0);
	BackupView.Pitch = ViewPitch;
	BackupView.Yaw = ViewYaw;
	BackupView.Roll = ViewRoll;
	SetActorRotation(BackupView);
	if (Pawn != nullptr)
	{
		Pawn.SetRotation(BackupView);
	}
	Global.TeamInfo(TimeStamp, InAccel, ClientLoc, false, NewbDuck, false, false, 0, 0, 0);
	*/
}

void AAA2_PlayerController::TurretServerMove(float TimeStamp, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
{
	ServerMove(TimeStamp, FVector(0, 0, 0), ClientLoc, false, NewbDuck, false, false, EDoubleClickDir::DCLICK_None, ClientRoll, View,0,0);
}

void AAA2_PlayerController::DualTurretServerMove(float TimeStamp0, bool NewbDuck0, uint8 ClientRoll0, int32 View0, float TimeStamp, FVector ClientLoc, bool NewbDuck, uint8 ClientRoll, int32 View)
{
	ServerMove(TimeStamp0, FVector(0, 0, 0), FVector(0, 0, 0), false, NewbDuck0, false, false, EDoubleClickDir::DCLICK_None, ClientRoll0, View0,0,0);
	ServerMove(TimeStamp, FVector(0, 0, 0), ClientLoc, false, NewbDuck, false, false, EDoubleClickDir::DCLICK_None, ClientRoll, View0,0,0);
}

void AAA2_PlayerController::ShortServerMove(float TimeStamp, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, uint8 ClientRoll, int32 View)
{
	ServerMove(TimeStamp, FVector(0, 0, 0), ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, EDoubleClickDir::DCLICK_None, ClientRoll, View,0,0);
}

void AAA2_PlayerController::DualServerMove(float TimeStamp0, FVector InAccel0, uint8 PendingCompress, EDoubleClickDir DoubleClickMove0, int32 View0, float TimeStamp, FVector InAccel, FVector ClientLoc, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
{
	bool NewbIsWalking0 = false;
	bool NewbDuck0 = false;
	bool NewbProne0 = false;
	bool NewbJumpStatus0 = false;
	bool NewbIsWalking = false;
	bool NewbDuck = false;
	bool NewbProne = false;
	bool NewbJumpStatus = false;
	NewbIsWalking0 = ((PendingCompress & 1) != 0);
	NewbDuck0 = ((PendingCompress & 2) != 0);
	NewbProne0 = ((PendingCompress & 4) != 0);
	NewbJumpStatus0 = ((PendingCompress & 8) != 0);
	NewbIsWalking = ((PendingCompress & 16) != 0);
	NewbDuck = ((PendingCompress & 32) != 0);
	NewbProne = ((PendingCompress & 64) != 0);
	NewbJumpStatus = ((PendingCompress & 128) != 0);
	ServerMove(TimeStamp0, InAccel0, FVector(0, 0, 0), NewbIsWalking0, NewbDuck0, NewbProne0, NewbJumpStatus0, DoubleClickMove0, ClientRoll, View0,0,0);
	if (ClientLoc == FVector(0, 0, 0))
	{
		ClientLoc = FVector(0.1, 0, 0);
	}
	ServerMove(TimeStamp, InAccel, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, DoubleClickMove, ClientRoll, View, OldTimeDelta, OldAccel);
}

void AAA2_PlayerController::ServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbWalk, bool NewbDuck, bool NewbProne, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
{
	float DeltaTime = 0;
	float clientErr = 0;
	float OldTimeStamp = 0;
	FRotator DeltaRot = FRotator(0, 0, 0);
	FRotator Rot = FRotator(0, 0, 0);
	FRotator ViewRot = FRotator(0, 0, 0);
	FVector Accel = FVector(0, 0, 0);
	FVector LocDiff = FVector(0, 0, 0);
	int32 maxPitch = 0;
	int32 ViewPitch = 0;
	int32 ViewYaw = 0;
	bool NewbPressedJump = false;
	bool OldbWalk = false;
	bool OldbDuck = false;
	bool OldbProne = false;
	EDoubleClickDir OldDoubleClickMove = EDoubleClickDir::DCLICK_None;
	/*
	if (CurrentTimeStamp >= TimeStamp)
	{
		return;
	}
	if (AcknowledgedPawn != Pawn)
	{
		OldTimeDelta = 0;
		InAccel = FVector(0, 0, 0);
		GivePawn(Pawn);
	}
	if (OldTimeDelta != 0)
	{
		OldTimeStamp = ((TimeStamp - (float(OldTimeDelta) / float(500))) - 0.001);
		if (CurrentTimeStamp < (OldTimeStamp - 0.001))
		{
			Accel.X = float((OldAccel >> > 23));
			if (Accel.X > float(127))
			{
				Accel.X = (-1 * (Accel.X - float(128)));
			}
			Accel.Y = float((int(float((OldAccel >> > 15))) & 255));
			if (Accel.Y > float(127))
			{
				Accel.Y = (-1 * (Accel.Y - float(128)));
			}
			Accel.Z = float((int(float((OldAccel >> > 7))) & 255));
			if (Accel.Z > float(127))
			{
				Accel.Z = (-1 * (Accel.Z - float(128)));
			}
			(Accel *= float(20));
			OldbWalk = ((OldAccel & 64) != 0);
			OldbDuck = ((OldAccel & 32) != 0);
			OldbProne = ((OldAccel & 16) != 0);
			NewbPressedJump = ((OldAccel & 8) != 0);
			if (NewbPressedJump)
			{
				bJumpStatus = NewbJumpStatus;
			}
			switch ((OldAccel & 7))
			{
			case 0:
				OldDoubleClickMove = 0;
				break;
			case 3:
				OldDoubleClickMove = 3;
				break;
			case 4:
				OldDoubleClickMove = 4;
				break;
			default:
			}
			OldTimeStamp = FMin(OldTimeStamp, (CurrentTimeStamp + MaxResponseTime));
			MoveAutonomous((OldTimeStamp - CurrentTimeStamp), OldbWalk, OldbDuck, OldbProne, NewbPressedJump, OldDoubleClickMove, Accel, FRotator(0, 0, 0));
			CurrentTimeStamp = OldTimeStamp;
		}
	}
	ViewPitch = (View & 65535);
	ViewYaw = (View >> 16);
	Accel = (InAccel * 0.1);
	NewbPressedJump = (bJumpStatus != NewbJumpStatus);
	bJumpStatus = NewbJumpStatus;
	DeltaTime = FMin(MaxResponseTime, (TimeStamp - CurrentTimeStamp));
	if (GetPawn() == nullptr)
	{
		ResetTimeMargin();
	}
	else
	{
		if (!CheckSpeedHack(DeltaTime))
		{
			bWasSpeedHack = true;
			DeltaTime = 0;
			Pawn.Velocity = FVector(0, 0, 0);
		}
		else
		{
			if (bWasSpeedHack)
			{
				if ((TimeMargin > (0.5 * Cast<AAA2_WorldSettings>(GetWorldSettings())->MaxTimeMargin)) && (Cast<AAA2_WorldSettings>(GetWorldSettings())->MaxTimeMargin > 0))
				{
					(DeltaTime *= 0.8);
				}
			}
		}
	}
	CurrentTimeStamp = TimeStamp;
	ServerTimeStamp = GetWorld()->GetTimeSeconds();
	ViewRot.Pitch = ViewPitch;
	ViewRot.Yaw = ViewYaw;
	ViewRot.Roll = 0;
	if (Pawn != nullptr)
	{
		Pawn.fSprintMod = Pawn.GetSprintModifier(FMath::Abs(float((ViewRot.Yaw - Rotation.Yaw))), DeltaTime, NewbPressedJump);
	}
	if (NewbPressedJump || (InAccel != FVector(0, 0, 0)))
	{
		LastActiveTime = GetWorld()->GetTimeSeconds();
	}
	if ((GetPawn() == nullptr) || Pawn.bServerMoveSetPawnRot)
	{
		SetActorRotation(ViewRot);
	}
	if (AcknowledgedPawn != Pawn)
	{
		return;
	}
	if ((Pawn != nullptr) && Pawn.bServerMoveSetPawnRot)
	{
		Rot.Roll = (256 * ClientRoll);
		Rot.Yaw = ViewYaw;
		if ((Pawn.Physics == 3) || (Pawn.Physics == 4))
		{
			maxPitch = 2;
		}
		else
		{
			maxPitch = 0;
		}
		if ((ViewPitch > (maxPitch * RotationRate.Pitch)) && (ViewPitch < (65536 - (maxPitch * RotationRate.Pitch))))
		{
			if (ViewPitch < 32768)
			{
				Rot.Pitch = (maxPitch * RotationRate.Pitch);
			}
			else
			{
				Rot.Pitch = (65536 - (maxPitch * RotationRate.Pitch));
			}
		}
		else
		{
			Rot.Pitch = ViewPitch;
		}
		DeltaRot = (Rotation - Rot);
		if (!_ServerLockRotation)
		{
			Pawn.SetRotation(Rot);
		}
	}
	if (_ServerLockRotation)
	{
		DeltaRot.Pitch = 0;
		DeltaRot.Yaw = 0;
		DeltaRot.Roll = 0;
	}
	if (_ServerLockMovement)
	{
		Accel = FVector(0, 0, 0);
	}
	if ((Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser == nullptr) && (DeltaTime > 0))
	{
		MoveAutonomous(DeltaTime, NewbWalk, NewbDuck, NewbProne, NewbPressedJump, DoubleClickMove, Accel, DeltaRot);
	}
	if (ClientLoc == FVector(0, 0, 0))
	{
		return;
	}
	else
	{
		if ((GetWorld()->GetTimeSeconds() - LastUpdateTime) > 0.3)
		{
			clientErr = 10000;
		}
		else
		{
			if ((GetWorld()->GetTimeSeconds() - LastUpdateTime) > (180 / float(Player.CurrentNetSpeed)))
			{
				if (GetPawn() == nullptr)
				{
					LocDiff = (Location - ClientLoc);
				}
				else
				{
					LocDiff = (Pawn.Location - ClientLoc);
				}
				clientErr = (LocDiff Dot LocDiff);
			}
		}
	}
	if (clientErr > 3)
	{
		if (GetPawn() == nullptr)
		{
			PendingAdjustment.newPhysics = Physics;
			PendingAdjustment.NewLoc = Location;
			PendingAdjustment.NewVel = Velocity;
		}
		else
		{
			PendingAdjustment.newPhysics = Pawn.Physics;
			PendingAdjustment.NewVel = Pawn.Velocity;
			PendingAdjustment.NewBase = Pawn.Base;
			if ((Cast<AMover>(Pawn.Base) != nullptr) || (Cast<AVehicle>(Pawn.Base) != nullptr))
			{
				PendingAdjustment.NewLoc = (Pawn.Location - Pawn.Base.Location);
			}
			else
			{
				PendingAdjustment.NewLoc = Pawn.Location;
			}
			PendingAdjustment.NewFloor = Pawn.Floor;
		}
		LastUpdateTime = GetWorld()->GetTimeSeconds();
		PendingAdjustment.TimeStamp = TimeStamp;
		PendingAdjustment.NewState = GetStateName();
	}
	*/
}

void AAA2_PlayerController::SendClientAdjustment()
{
	/*
	if (AcknowledgedPawn != Pawn)
	{
		PendingAdjustment.TimeStamp = 0;
		return;
	}
	if ((GetPawn() == nullptr) || (Pawn.Physics != 9))
	{
		if (PendingAdjustment.NewVel == FVector(0, 0, 0))
		{
			ShortClientAdjustPosition(PendingAdjustment.TimeStamp, PendingAdjustment.NewState, PendingAdjustment.newPhysics, PendingAdjustment.NewLoc.X, PendingAdjustment.NewLoc.Y, PendingAdjustment.NewLoc.Z, uint8((Rotation.Pitch / 256)), PendingAdjustment.NewBase);
		}
		else
		{
			ClientAdjustPosition(PendingAdjustment.TimeStamp, PendingAdjustment.NewState, PendingAdjustment.newPhysics, PendingAdjustment.NewLoc.X, PendingAdjustment.NewLoc.Y, PendingAdjustment.NewLoc.Z, uint8((Rotation.Pitch / 256)), PendingAdjustment.NewVel.X, PendingAdjustment.NewVel.Y, PendingAdjustment.NewVel.Z, PendingAdjustment.NewBase);
		}
	}
	else
	{
		LongClientAdjustPosition(PendingAdjustment.TimeStamp, PendingAdjustment.NewState, PendingAdjustment.newPhysics, PendingAdjustment.NewLoc.X, PendingAdjustment.NewLoc.Y, PendingAdjustment.NewLoc.Z, uint8((Rotation.Pitch / 256)), PendingAdjustment.NewVel.X, PendingAdjustment.NewVel.Y, PendingAdjustment.NewVel.Z, PendingAdjustment.NewBase, PendingAdjustment.NewFloor.X, PendingAdjustment.NewFloor.Y, PendingAdjustment.NewFloor.Z);
	}
	*/
	PendingAdjustment.TimeStamp = 0;
}

void AAA2_PlayerController::ServerDrive(float InForward, float InStrafe, float aaUp, bool InJump, int32 View)
{
	FRotator ViewRotation = FRotator(0, 0, 0);
	ViewRotation.Pitch = (View / 32768);
	ViewRotation.Yaw = (2 * (View - (32768 * ViewRotation.Pitch)));
	(ViewRotation.Pitch *= 2);
	ViewRotation.Roll = 0;
	//SetRotation(ViewRotation);
	ProcessDrive(InForward, InStrafe, aaUp, InJump);
}

void AAA2_PlayerController::ProcessDrive(float InForward, float InStrafe, float InUp, bool InJump)
{
	//ClientGotoState(GetStateName(), "Begin");
}

void AAA2_PlayerController::ProcessMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
{
	/*
	if ((Pawn != nullptr) && (Pawn.Acceleration != NewAccel))
	{
		Pawn.Acceleration = NewAccel;
	}
	*/
}

void AAA2_PlayerController::MoveAutonomous(float DeltaTime, bool NewbWalk, bool NewbDuck, bool NewbProne, bool NewbPressedJump, EDoubleClickDir DoubleClickMove, FVector NewAccel, FRotator DeltaRot)
{
	/*
	if ((Pawn != nullptr) && Pawn.bHardAttach)
	{
		return;
	}
	if (Pawn != nullptr)
	{
		Pawn.SetWalking(NewbWalk);
		Pawn.bWantsToCrouch = NewbDuck;
		Pawn.bWantsToProne = NewbProne;
		if (Pawn.bWantsToProne && Pawn.bIsSprinting)
		{
			Pawn.Dive3p(7);
		}
		bPressedJump = NewbPressedJump;
	}
	ProcessMove(DeltaTime, NewAccel, DoubleClickMove, DeltaRot);
	if (Pawn != nullptr)
	{
		Pawn.AutonomousPhysics(DeltaTime);
	}
	else
	{
		AutonomousPhysics(DeltaTime);
	}
	*/
}

void AAA2_PlayerController::VeryShortClientAdjustPosition(float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, AActor* NewBase)
{
	FVector Floor = FVector(0, 0, 0);
	FName MoveState = "";
	/*
	if (Pawn != nullptr)
	{
		if (Pawn.bIsProne)
		{
			MoveState = "PlayerCrawling";
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				MoveState = "PlayerCrouching";
			}
			else
			{
				MoveState = "PlayerWalking";
			}
		}
		Floor = Pawn.Floor;
	}
	else
	{
		MoveState = "PlayerWalking";
	}
	*/
	LongClientAdjustPosition(TimeStamp, MoveState, EPhysics::PHYS_Walking, NewLocX, NewLocY, NewLocZ, AnimPitch, 0, 0, 0, NewBase, Floor.X, Floor.Y, Floor.Z);
}

void AAA2_PlayerController::ShortClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, AActor* NewBase)
{
	FVector Floor = FVector(0, 0, 0);
	/*
	if (Pawn != nullptr)
	{
		Floor = Pawn.Floor;
	}
	*/
	LongClientAdjustPosition(TimeStamp, NewState, newPhysics, NewLocX, NewLocY, NewLocZ, AnimPitch, 0, 0, 0, NewBase, Floor.X, Floor.Y, Floor.Z);
}

void AAA2_PlayerController::ClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, float NewVelX, float NewVelY, float NewVelZ, AActor* NewBase)
{
	FVector Floor = FVector(0, 0, 0);
	/*
	if (Pawn != nullptr)
	{
		Floor = Pawn.Floor;
	}
	*/
	LongClientAdjustPosition(TimeStamp, NewState, newPhysics, NewLocX, NewLocY, NewLocZ, AnimPitch, NewVelX, NewVelY, NewVelZ, NewBase, Floor.X, Floor.Y, Floor.Z);
}

void AAA2_PlayerController::LongClientAdjustPosition(float TimeStamp, FName NewState, EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, float NewVelX, float NewVelY, float NewVelZ, AActor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
{
	FVector NewLocation = FVector(0, 0, 0);
	FVector NewVelocity = FVector(0, 0, 0);
	FVector NewFloor = FVector(0, 0, 0);
	AActor* MoveActor = nullptr;
	ASavedMove* CurrentMove = nullptr;
	FName CurrentState = "";
	/*
	if ((PlayerReplicationInfo != nullptr) && (!bDemoOwner))
	{
		if (ExactPing < 0.006)
		{
			ExactPing = (GetWorld()->GetTimeSeconds() - TimeStamp);
		}
		else
		{
			ExactPing = ((0.99 * ExactPing) + (0.009 * (GetWorld()->GetTimeSeconds() - TimeStamp)));
		}
		PlayerReplicationInfo->Ping = uint8(FClamp((1000 * ExactPing), 0, 9999));
		if ((GetWorld()->GetTimeSeconds() - LastPingUpdate) > 4)
		{
			LastPingUpdate = GetWorld()->GetTimeSeconds();
			ServerUpdatePing(int(FClamp((1000 * ExactPing), 0, 9999)));
		}
	}
	if (Pawn != nullptr)
	{
		if (Pawn.bTearOff)
		{
			Pawn = nullptr;
			if (((!IsInState("GameEnded")) && (!IsInState("RoundEnded"))) && (!IsInState("Dead")))
			{
				GotoState("Dead");
			}
			return;
		}
		MoveActor = Pawn;
		if ((ViewTarget != Pawn) && ((ViewTarget == this) || ((Cast<APawn>(ViewTarget) != nullptr) && (Cast<APawn>(ViewTarget).Health <= 0))))
		{
			bBehindView = false;
			SetViewTarget(Pawn);
		}
	}
	else
	{
		MoveActor = this;
		if (GetStateName() != NewState)
		{
			if ((NewState == "GameEnded") || (NewState == "RoundEnded"))
			{
				GotoState(NewState);
			}
			else
			{
				if (IsInState("Dead"))
				{
					if ((NewState != "PlayerWalking") && (NewState != "PlayerSwimming"))
					{
						GotoState(NewState);
					}
					return;
				}
				else
				{
					if (NewState == "Dead")
					{
						GotoState(NewState);
					}
				}
			}
		}
	}
	if (CurrentTimeStamp >= TimeStamp)
	{
		return;
	}
	CurrentTimeStamp = TimeStamp;
	NewLocation.X = NewLocX;
	NewLocation.Y = NewLocY;
	NewLocation.Z = NewLocZ;
	NewVelocity.X = NewVelX;
	NewVelocity.Y = NewVelY;
	NewVelocity.Z = NewVelZ;
	CurrentMove = SavedMoves;
	if (CurrentMove != nullptr)
	{
		if (CurrentMove.TimeStamp <= CurrentTimeStamp)
		{
			SavedMoves = CurrentMove.NextMove;
			CurrentMove.NextMove = FreeMoves;
			FreeMoves = CurrentMove;
			if (CurrentMove.TimeStamp == CurrentTimeStamp)
			{
				FreeMoves.Clear();
				if (((Cast<AMover>(NewBase) != nullptr) || (Cast<AVehicle>(NewBase) != nullptr)) && (NewBase == CurrentMove.EndBase))
				{
					if (((GetStateName() == NewState) && IsInState("PlayerWalking")) && ((MoveActor.Physics == 1) || (MoveActor.Physics == 2)))
					{
						if (VSize((CurrentMove.SavedRelativeLocation - NewLocation)) < 3)
						{
							CurrentMove = nullptr;
							return;
						}
						else
						{
							if ((((Cast<AVehicle>(NewBase) != nullptr) && (VSize(Velocity) < 3)) && (VSize(NewVelocity) < 3)) && (VSize((CurrentMove.SavedRelativeLocation - NewLocation)) < float(30)))
							{
								CurrentMove = nullptr;
								return;
							}
						}
					}
				}
				else
				{
					if (((((VSize((CurrentMove.SavedLocation - NewLocation)) < 3) && (VSize((CurrentMove.SavedVelocity - NewVelocity)) < 3)) && (GetStateName() == NewState)) && IsInState("PlayerWalking")) && ((MoveActor.Physics == 1) || (MoveActor.Physics == 2)))
					{
						CurrentMove = nullptr;
						return;
					}
				}
				CurrentMove = nullptr;
			}
			else
			{
				FreeMoves.Clear();
				CurrentMove = SavedMoves;
			}
		}
		else
		{
			CurrentMove = nullptr;
		}
	}
	if (MoveActor.bHardAttach)
	{
		if (MoveActor.Base == nullptr)
		{
			if (NewBase != nullptr)
			{
				MoveActor.SetBase(NewBase);
			}
			if (MoveActor.Base == nullptr)
			{
				MoveActor.bHardAttach = false;
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
	NewFloor.X = NewFloorX;
	NewFloor.Y = NewFloorY;
	NewFloor.Z = NewFloorZ;
	if ((Cast<AMover>(NewBase) != nullptr) || (Cast<AVehicle>(NewBase) != nullptr))
	{
		(NewLocation += NewBase.Location);
	}
	if (!bDemoOwner)
	{
		MoveActor.bCanTeleport = false;
		if (((((((!MoveActor.SetLocation(NewLocation)) && (Cast<APawn>(MoveActor) != nullptr)) && (MoveActor.CollisionHeight > Pawn(MoveActor).CrouchHeight)) && (!Pawn(MoveActor).bIsCrouched)) && (newPhysics == 1)) && (MoveActor.Physics != 13)) && (MoveActor.Physics != 14))
		{
			MoveActor.SetLocation(NewLocation);
		}
		MoveActor.bCanTeleport = true;
	}
	if (((((MoveActor.Physics != newPhysics) && (MoveActor.Physics != 13)) && (MoveActor.Physics != 14)) && (newPhysics != 13)) && (newPhysics != 14))
	{
		MoveActor.SetPhysics(newPhysics);
	}
	if (MoveActor != this)
	{
		MoveActor.SetBase(NewBase, NewFloor);
	}
	MoveActor.Velocity = NewVelocity;
	if (MoveActor->IsA(APawn::StaticClass()))
	{
		Cast<APawn>(MoveActor).AnimPitch = AnimPitch;
	}
	CurrentState = GetStateName();
	if (CurrentState != NewState)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugControllerState)
		{
			Log(string(this) @ "PlayerController::LongClientAdjustPosition()	" + FString::FromInt(GetStateName()) + " --> " + FString::FromInt(NewState));
		}
		if (!ClientRejectStateTransition(NewState))
		{
			GotoState(NewState);
		}
	}
	*/
	bUpdatePosition = true;
}

bool AAA2_PlayerController::ClientRejectStateTransition(FName NewState)
{
	return false;
}

void AAA2_PlayerController::ServerUpdatePing(int32 NewPing)
{
	//PlayerReplicationInfo->Ping = uint8(Min(int((0.25 * float(NewPing))), 250));
	//PlayerReplicationInfo->bReceivedPing = true;
}

void AAA2_PlayerController::ClientUpdatePosition()
{
	ASavedMove* CurrentMove = nullptr;
	bool realbWalk = false;
	bool realbDuck = false;
	bool realbProne = false;
	bool realbSprint = false;
	bool bRealJump = false;
	/*
	if ((Pawn != nullptr) && ((Pawn.Physics == 13) || (Pawn.Physics == 14)))
	{
		return;
	}
	if (GetPawn() == nullptr)
	{
		return;
	}
	bUpdatePosition = false;
	realbWalk = Pawn.bIsWalking;
	realbDuck = Pawn.bWantsToCrouch;
	realbProne = Pawn.bWantsToProne;
	realbSprint = Pawn.bWantsToSprint;
	bRealJump = bPressedJump;
	CurrentMove = SavedMoves;
	bUpdating = true;
	if (CurrentMove != nullptr)
	{
		if ((PendingMove == CurrentMove) && (Pawn != nullptr))
		{
			PendingMove.SetInitialPosition(Pawn);
		}
		if (CurrentMove.TimeStamp <= CurrentTimeStamp)
		{
			SavedMoves = CurrentMove.NextMove;
			CurrentMove.NextMove = FreeMoves;
			FreeMoves = CurrentMove;
			FreeMoves.Clear();
			CurrentMove = SavedMoves;
		}
		else
		{
			MoveAutonomous(CurrentMove.Delta, CurrentMove.bIsWalking, CurrentMove.bDuck, CurrentMove.bProne, CurrentMove.bPressedJump, CurrentMove.DoubleClickMove, CurrentMove.Acceleration, FRotator(0, 0, 0));
			if (Pawn != nullptr)
			{
				CurrentMove.SavedLocation = Pawn.Location;
				CurrentMove.SavedVelocity = Pawn.Velocity;
				CurrentMove.EndBase = Pawn.Base;
				if ((CurrentMove.EndBase != nullptr) && (!CurrentMove.EndBase.bWorldGeometry))
				{
					CurrentMove.SavedRelativeLocation = (Pawn.Location - CurrentMove.EndBase.Location);
				}
			}
			CurrentMove = CurrentMove.NextMove;
		}
	}
	bUpdating = false;
	Pawn.bWantsToCrouch = realbDuck;
	Pawn.bIsWalking = realbWalk;
	Pawn.bWantsToProne = realbProne;
	Pawn.bWantsToSprint = realbSprint;
	bPressedJump = bRealJump;
	*/
}

ASavedMove* AAA2_PlayerController::GetFreeMove()
{
	ASavedMove* S = nullptr;
	ASavedMove* first = nullptr;
	int32 i = 0;
	/*
	if (FreeMoves == nullptr)
	{
		for (S = SavedMoves; S != nullptr; S = S.NextMove)
		{
			i++;
			if (i > 100)
			{
				first = SavedMoves;
				SavedMoves = SavedMoves.NextMove;
				first.Clear();
				first.NextMove = nullptr;
				if (SavedMoves != nullptr)
				{
					S = SavedMoves;
					SavedMoves = SavedMoves.NextMove;
					S.Clear();
					S.NextMove = FreeMoves;
					FreeMoves = S;
				}
				return first;
			}
		}
		return Spawn(ASavedMove::StaticClass());
	}
	else
	{
		S = FreeMoves;
		FreeMoves = FreeMoves.NextMove;
		S.NextMove = nullptr;
		return S;
	}
	*/
	return nullptr;   //FAKE   /ELiZ
}

int32 AAA2_PlayerController::CompressAccel(int32 C)
{
	/*
	if (C >= 0)
	{
		C = FMath::Min(C, 127);
	}
	else
	{
		C = (Min(int(FMath::Abs(float(C))), 127) + 128);
	}
	*/
	return C;
}

void AAA2_PlayerController::ReplicateMove(float DeltaTime, FVector NewAccel, EDoubleClickDir DoubleClickMove, FRotator DeltaRot)
{
	ASavedMove* NewMove = nullptr;
	ASavedMove* OldMove = nullptr;
	ASavedMove* AlmostLastMove = nullptr;
	ASavedMove* LastMove = nullptr;
	uint8 ClientRoll = 0;
	float OldTimeDelta = 0;
	float NetMoveDelta = 0;
	int32 OldAccel = 0;
	FVector BuildAccel = FVector(0, 0, 0);
	FVector AccelNorm = FVector(0, 0, 0);
	FVector MoveLoc = FVector(0, 0, 0);
	FVector CompareAccel = FVector(0, 0, 0);
	bool bPendingJumpStatus = false;
	/*
	MaxResponseTime = (Default.MaxResponseTime * Level.TimeDilation);
	DeltaTime = FMin(DeltaTime, MaxResponseTime);
	if (SavedMoves != nullptr)
	{
		LastMove = SavedMoves;
		AlmostLastMove = LastMove;
		AccelNorm = Normal(NewAccel);
		if (LastMove.NextMove != nullptr)
		{
			if (LastMove.IsJumpMove())
			{
				OldMove = LastMove;
			}
			else
			{
				if ((Pawn != nullptr) && ((OldMove == nullptr) || (!OldMove.IsJumpMove())))
				{
					if (OldMove != nullptr)
					{
						CompareAccel = Normal(OldMove.Acceleration);
					}
					else
					{
						CompareAccel = AccelNorm;
					}
					if ((LastMove.Acceleration != CompareAccel) && ((Normal(LastMove.Acceleration) Dot CompareAccel) < 0.95))
					{
						OldMove = LastMove;
					}
				}
			}
			AlmostLastMove = LastMove;
			LastMove = LastMove.NextMove;
		}
		if (LastMove.IsJumpMove())
		{
			OldMove = LastMove;
		}
		else
		{
			if ((Pawn != nullptr) && ((OldMove == nullptr) || (!OldMove.IsJumpMove())))
			{
				if (OldMove != nullptr)
				{
					CompareAccel = Normal(OldMove.Acceleration);
				}
				else
				{
					CompareAccel = AccelNorm;
				}
				if ((LastMove.Acceleration != CompareAccel) && ((Normal(LastMove.Acceleration) Dot CompareAccel) < 0.95))
				{
					OldMove = LastMove;
				}
			}
		}
	}
	NewMove = GetFreeMove();
	if (NewMove == nullptr)
	{
		return;
	}
	NewMove.SetMoveFor(this, DeltaTime, NewAccel, DoubleClickMove);
	ProcessMove(NewMove.Delta, NewMove.Acceleration, NewMove.DoubleClickMove, DeltaRot);
	if (((((((((((((((PendingMove != nullptr) && (Pawn != nullptr)) && (Pawn.Physics == 1)) && ((NewMove.Delta + PendingMove.Delta) < MaxResponseTime)) && (NewAccel != FVector(0, 0, 0))) && (PendingMove.SavedPhysics == 1)) && (!PendingMove.bPressedJump)) && (!NewMove.bPressedJump)) && (PendingMove.bIsWalking == NewMove.bIsWalking)) && (PendingMove.bDuck == NewMove.bDuck)) && (PendingMove.bProne == NewMove.bProne)) && (PendingMove.DoubleClickMove == 0)) && (NewMove.DoubleClickMove == 0)) && ((Normal(PendingMove.Acceleration) Dot Normal(NewAccel)) > 0.99)) && (Level.TimeDilation >= 0.9))
	{
		Pawn.SetLocation(PendingMove.GetStartLocation());
		Pawn.Velocity = PendingMove.StartVelocity;
		if (PendingMove.StartBase != Pawn.Base)
		{
		}
		Pawn.SetBase(PendingMove.StartBase);
		Pawn.Floor = PendingMove.StartFloor;
		(NewMove.Delta += PendingMove.Delta);
		NewMove.SetInitialPosition(Pawn);
		if (LastMove == PendingMove)
		{
			if (SavedMoves == PendingMove)
			{
				SavedMoves.NextMove = FreeMoves;
				FreeMoves = SavedMoves;
				SavedMoves = nullptr;
			}
			else
			{
				PendingMove.NextMove = FreeMoves;
				FreeMoves = PendingMove;
				if (AlmostLastMove != nullptr)
				{
					AlmostLastMove.NextMove = nullptr;
					LastMove = AlmostLastMove;
				}
			}
			FreeMoves.Clear();
		}
		PendingMove = nullptr;
	}
	if (Pawn != nullptr)
	{
		Pawn.AutonomousPhysics(NewMove.Delta);
	}
	else
	{
		AutonomousPhysics(DeltaTime);
	}
	NewMove.PostUpdate(this);
	if (SavedMoves == nullptr)
	{
		SavedMoves = NewMove;
	}
	else
	{
		LastMove.NextMove = NewMove;
	}
	if (PendingMove == nullptr)
	{
		if (((Player.CurrentNetSpeed > 10000) && (GameReplicationInfo != nullptr)) && (GameReplicationInfo->PRIArray.Num() <= 10))
		{
			NetMoveDelta = 0;
		}
		else
		{
			NetMoveDelta = FMax(0.0222, ((2 * Cast<AAA2_WorldSettings>(GetWorldSettings())->MoveRepSize) / float(Player.CurrentNetSpeed)));
		}
		if ((GetWorld()->GetTimeSeconds() - ClientUpdateTime) < NetMoveDelta)
		{
			PendingMove = NewMove;
			return;
		}
	}
	ClientUpdateTime = GetWorld()->GetTimeSeconds();
	if (OldMove != nullptr)
	{
		OldTimeDelta = FMin(255, ((GetWorld()->GetTimeSeconds() - OldMove.TimeStamp) * float(500)));
		BuildAccel = ((0.05 * OldMove.Acceleration) + FVector(0.5, 0.5, 0.5));
		OldAccel = (((CompressAccel(int(BuildAccel.X)) << 23) + (CompressAccel(int(BuildAccel.Y)) << 15)) + (CompressAccel(int(BuildAccel.Z)) << 7));
		if (OldMove.bIsWalking)
		{
			(OldAccel += 64);
		}
		if (OldMove.bDuck)
		{
			(OldAccel += 32);
		}
		if (OldMove.bProne)
		{
			(OldAccel += 16);
		}
		if (OldMove.bPressedJump)
		{
			(OldAccel += 8);
		}
		(OldAccel += OldMove.DoubleClickMove);
	}
	ClientRoll = uint8((byte((Rotation.Roll >> 8)) & 255));
	if (PendingMove != nullptr)
	{
		if (PendingMove.bPressedJump)
		{
			bJumpStatus = (!bJumpStatus);
		}
		bPendingJumpStatus = bJumpStatus;
	}
	if (NewMove.bPressedJump)
	{
		bJumpStatus = (!bJumpStatus);
	}
	if (GetPawn() == nullptr)
	{
		MoveLoc = Location;
	}
	else
	{
		MoveLoc = Pawn.Location;
	}
	CallServerMove(NewMove.TimeStamp, (NewMove.Acceleration * float(10)), MoveLoc, NewMove.bIsWalking, NewMove.bDuck, NewMove.bProne, bPendingJumpStatus, bJumpStatus, NewMove.DoubleClickMove, ClientRoll, (((Rotation.Yaw & 65535) << 16) + (Rotation.Pitch & 65535)), uint8(OldTimeDelta), OldAccel);
	*/
	PendingMove = nullptr;
}

void AAA2_PlayerController::CallServerMove(float TimeStamp, FVector InAccel, FVector ClientLoc, bool NewbIsWalking, bool NewbDuck, bool NewbProne, bool NewbPendingJumpStatus, bool NewbJumpStatus, EDoubleClickDir DoubleClickMove, uint8 ClientRoll, int32 View, uint8 OldTimeDelta, int32 OldAccel)
{
	uint8 PendingCompress = 0;
	bool bCombine = false;
	/*
	if (PendingMove != nullptr)
	{
		if (PendingMove.bIsWalking)
		{
			PendingCompress = 1;
		}
		if (PendingMove.bDuck)
		{
			(PendingCompress += 2);
		}
		if (PendingMove.bProne)
		{
			(PendingCompress += 4);
		}
		if (NewbPendingJumpStatus)
		{
			(PendingCompress += uint8(8));
		}
		if (NewbIsWalking)
		{
			(PendingCompress += uint8(16));
		}
		if (NewbDuck)
		{
			(PendingCompress += uint8(32));
		}
		if (NewbProne)
		{
			(PendingCompress += uint8(64));
		}
		if (NewbJumpStatus)
		{
			(PendingCompress += uint8(128));
		}
		if (((((InAccel == FVector(0, 0, 0)) && (PendingMove.StartVelocity == FVector(0, 0, 0))) && (DoubleClickMove == 0)) && (PendingMove.Acceleration == FVector(0, 0, 0))) && (PendingMove.DoubleClickMove == 0))
		{
			if (GetPawn() == nullptr)
			{
				bCombine = (Velocity == FVector(0, 0, 0));
			}
			else
			{
				bCombine = (Pawn.Velocity == FVector(0, 0, 0));
			}
			if (bCombine)
			{
				if (OldTimeDelta == 0)
				{
					ShortServerMove(TimeStamp, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, ClientRoll, View);
				}
				else
				{
					ServerMove(TimeStamp, InAccel, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, DoubleClickMove, ClientRoll, View, OldTimeDelta, OldAccel);
				}
				return;
			}
		}
		if (OldTimeDelta == 0)
		{
			DualServerMove(PendingMove.TimeStamp, (PendingMove.Acceleration * float(10)), PendingCompress, PendingMove.DoubleClickMove, (((PendingMove.Rotation.Yaw & 65535) << 16) + (PendingMove.Rotation.Pitch & 65535)), TimeStamp, InAccel, ClientLoc, DoubleClickMove, ClientRoll, View);
		}
		else
		{
			DualServerMove(PendingMove.TimeStamp, (PendingMove.Acceleration * float(10)), PendingCompress, PendingMove.DoubleClickMove, (((PendingMove.Rotation.Yaw & 65535) << 16) + (PendingMove.Rotation.Pitch & 65535)), TimeStamp, InAccel, ClientLoc, DoubleClickMove, ClientRoll, View, OldTimeDelta, OldAccel);
		}
	}
	else
	{
		if (OldTimeDelta != 0)
		{
			ServerMove(TimeStamp, InAccel, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, DoubleClickMove, ClientRoll, View, OldTimeDelta, OldAccel);
		}
		else
		{
			if ((InAccel == FVector(0, 0, 0)) && (DoubleClickMove == 0))
			{
				ShortServerMove(TimeStamp, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, ClientRoll, View);
			}
			else
			{
				ServerMove(TimeStamp, InAccel, ClientLoc, NewbIsWalking, NewbDuck, NewbProne, NewbJumpStatus, DoubleClickMove, ClientRoll, View);
			}
		}
	}
	*/
}

void AAA2_PlayerController::HandleWalking()
{
}

void AAA2_PlayerController::ServerRestartGame()
{
}

void AAA2_PlayerController::SetFOVAngle(float NewFOV)
{
	FovAngle = NewFOV;
}

void AAA2_PlayerController::SetFlashScaling(float F)
{
	//ScreenFlashScaling =FMath::Clamp(F, 0, 1);
}

void AAA2_PlayerController::ClientFlash(float Scale, FVector fog)
{
	FlashScale = ((Scale + ((1 - ScreenFlashScaling) * (1 - Scale))) *  FVector(1, 1, 1));
	FlashFog = ((ScreenFlashScaling * 0.001) * fog);
}

void AAA2_PlayerController::ClientAdjustGlow(float Scale, FVector fog)
{
	(ConstantGlowScale += Scale);
	(ConstantGlowFog += (0.001 * fog));
}

void AAA2_PlayerController::DamageShake(int32 Damage)
{
	ClientDamageShake(Damage);
}

void AAA2_PlayerController::ClientDamageShake(int32 Damage)
{
	//ShakeView((float(Damage) * FVector(30, 0, 0)), (float(120000) * FVector(1, 0, 0)), (0.15 + (0.005 * float(Damage))), (float(Damage) * FVector(0, 0, 0.03)),  FVector(1, 1, 1), 0.2);
}

void AAA2_PlayerController::WeaponShakeView(FVector shRotMag, FVector shRotRate, float shRotTime, FVector shOffsetMag, FVector shOffsetRate, float shOffsetTime)
{
	if (bWeaponViewShake)
	{
		ShakeView(shRotMag, shRotRate, shRotTime, shOffsetMag, shOffsetRate, shOffsetTime);
	}
}

void AAA2_PlayerController::ShakeView(FVector shRotMag, FVector shRotRate, float shRotTime, FVector shOffsetMag, FVector shOffsetRate, float shOffsetTime)
{
	/*
	if (VSize(shRotMag) > VSize(ShakeRotMax))
	{
		ShakeRotMax = shRotMag;
		ShakeRotRate = shRotRate;
		ShakeRotTime = (shRotTime *  FVector(1, 1, 1));
	}
	if (VSize(shOffsetMag) > VSize(ShakeOffsetMax))
	{
		ShakeOffsetMax = shOffsetMag;
		ShakeOffsetRate = shOffsetRate;
		ShakeOffsetTime = (shOffsetTime *  FVector(1, 1, 1));
	}
	*/
}

void AAA2_PlayerController::StopViewShaking()
{
	ShakeRotMax = FVector(0, 0, 0);
	ShakeRotRate = FVector(0, 0, 0);
	ShakeRotTime = FVector(0, 0, 0);
	ShakeOffsetMax = FVector(0, 0, 0);
	ShakeOffsetRate = FVector(0, 0, 0);
	ShakeOffsetTime = FVector(0, 0, 0);
}

void AAA2_PlayerController::SetAmbientShake(float FalloffStartTime, float FalloffTime, FVector OffsetMag, float OffsetFreq, FRotator RotMag, float RotFreq)
{
	bEnableAmbientShake = true;
	AmbientShakeFalloffStartTime = FalloffStartTime;
	AmbientShakeFalloffTime = FalloffTime;
	AmbientShakeOffsetMag = OffsetMag;
	AmbientShakeOffsetFreq = OffsetFreq;
	AmbientShakeRotMag = RotMag;
	AmbientShakeRotFreq = RotFreq;
}

void AAA2_PlayerController::ShakeViewEvent(FVector shRotMag, FVector shRotRate, float shRotTime, FVector shOffsetMag, FVector shOffsetRate, float shOffsetTime)
{
	ShakeView(shRotMag, shRotRate, shRotTime, shOffsetMag, shOffsetRate, shOffsetTime);
}

void AAA2_PlayerController::damageAttitudeTo(APawn* Other, float Damage)
{
	/*
	if (((Other != nullptr) && (Other != Pawn)) && (Damage > 0))
	{
		Enemy = Other;
	}
	*/
}

void AAA2_PlayerController::Typing(bool bTyping)
{
	bIsTyping = bTyping;
	/*
	if ((Pawn != nullptr) && (!Pawn.bTearOff))
	{
		Pawn.bIsTyping = bIsTyping;
	}
	*/
}

void AAA2_PlayerController::Jump(float F)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetPauserPlayerState() == PlayerReplicationInfo)
	{
		SetPause(false);
	}
	else
	{
		bPressedJump = true;
	}
}

void AAA2_PlayerController::Speech(FName Type, int32 Index, FString Callsign)
{
}

void AAA2_PlayerController::ServerSpeech(FName Type, int32 Index, FString Callsign)
{
	/*
	if (PlayerReplicationInfo->VoiceType != nullptr)
	{
		PlayerReplicationInfo->VoiceType.PlayerSpeech(Type, Index, Callsign, this);
	}
	*/
}

void AAA2_PlayerController::RestartLevel()
{
	/*
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		ClientTravel("?restart", 2, false);
	}
	*/
}

void AAA2_PlayerController::LocalTravel(FString URL)
{
	/*
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		ClientTravel(URL, 2, true);
	}
	*/
}

void AAA2_PlayerController::QuickSave()
{
}

void AAA2_PlayerController::QuickLoad()
{
}

bool AAA2_PlayerController::SetPause(bool bPause)
{
	bFire = 0;
	bAltFire = 0;
	//return Level.Game.SetPause(bPause, this);
	return false;    //FAKE  /EliZ
}

void AAA2_PlayerController::Pause()
{
	/*
	if (bDemoOwner)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser == nullptr)
		{
			Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser = PlayerReplicationInfo;
		}
		else
		{
			Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser = nullptr;
		}
	}
	else
	{
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			ServerPause();
		}
	}
	*/
}

void AAA2_PlayerController::ServerPause()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetPauserPlayerState() == nullptr)
	{
		SetPause(true);
	}
	else
	{
		SetPause(false);
	}
}

void AAA2_PlayerController::ShowMenu()
{
	bool bCloseHUDScreen = false;
	if (myHUD != nullptr)
	{
		bCloseHUDScreen = (myHUD->bShowScoreBoard || myHUD->bShowLocalStats);
		if (myHUD->bShowScoreBoard)
		{
			myHUD->bShowScoreBoard = false;
		}
		if (myHUD->bShowLocalStats)
		{
			myHUD->bShowLocalStats = false;
		}
		if (bCloseHUDScreen)
		{
			return;
		}
	}
	ShowMidGameMenu(true);
}

void AAA2_PlayerController::ShowMidGameMenu(bool bPause)
{
	StopForceFeedback("");
	/*
	if (bDemoOwner)
	{
		ClientOpenMenu(DemoMenuClass);
	}
	else
	{
		ClientOpenMenu(MidGameMenuClass);
	}
	*/
}

void AAA2_PlayerController::ActivateInventoryItem(UObject* InvItem)
{
}

void AAA2_PlayerController::ThrowWeapon()
{
}

void AAA2_PlayerController::ServerThrowWeapon()
{
}

void AAA2_PlayerController::PrevWeapon()
{
}

void AAA2_PlayerController::NextWeapon()
{
}

void AAA2_PlayerController::GetWeapon(AWeapon* NewWeaponClass)
{
}

void AAA2_PlayerController::PrevItem()
{
}

void AAA2_PlayerController::ActivateItem()
{
}

bool AAA2_PlayerController::CanUseWeapon(int32 DesiredAction)
{
	if ((!ShouldRenderWeapon()) || (GetPawn() == nullptr))
	{
		return false;
	}
	//return Pawn.CanUseWeapon(DesiredAction);
	return false;   //FAKE  /EliZ
}

void AAA2_PlayerController::Fire(float F)
{
	/*
	if ((GetWorld()->GetNetMode() == NM_Standalone) && bViewingMatineeCinematic)
	{
		Level.Game.SceneAbort();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser == PlayerReplicationInfo)
	{
		SetPause(false);
		return;
	}
	if (bDemoOwner || (GetPawn() == nullptr))
	{
		return;
	}
	if (Pawn.bIsSprinting)
	{
		return;
	}
	Pawn.Fire(F);
	*/
}

void AAA2_PlayerController::AltFire(float F)
{
	/*
	if (bAction != 0)
	{
		Log("Player cannot alt-fire while busy");
		ClientMessage("You are busy and cannot do anything else.");
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser == PlayerReplicationInfo)
	{
		SetPause(false);
		return;
	}
	if (bDemoOwner || (GetPawn() == nullptr))
	{
		return;
	}
	Pawn.AltFire(F);
	*/
}

void AAA2_PlayerController::Reload()
{
	if ((CanUseWeapon(3) && (!bNoReload)) && (GetPawn() != nullptr))
	{
		//Pawn.DoReload();
	}
}

void AAA2_PlayerController::FixJam()
{
	if (CanUseWeapon(2))
	{
		//Pawn.FixJam();
	}
}

void AAA2_PlayerController::ChangeFireMode()
{
	if (!CanUseWeapon(4))
	{
		return;
	}
	//Pawn.ChangeFireMode();
}

void AAA2_PlayerController::Use()
{
	ServerUse();
}

void AAA2_PlayerController::ServerUse()
{
	AActor* A = nullptr;
	AVehicle* DrivenVehicle = nullptr;
	AVehicle* EntryVehicle = nullptr;
	AVehicle* V = nullptr;
	/*
	if (Role < 4)
	{
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Pauser == PlayerReplicationInfo)
	{
		SetPause(false);
		return;
	}
	if ((GetPawn() == nullptr) || (!Pawn.bCanUse))
	{
		return;
	}
	DrivenVehicle = Vehicle(Pawn);
	if (DrivenVehicle != nullptr)
	{
		DrivenVehicle.KDriverLeave(false);
		return;
	}
	ForEach Pawn.VisibleCollidingActors(AVehicle::StaticClass(), V, VehicleCheckRadius)
	{
		EntryVehicle = V.FindEntryVehicle(Pawn);
		if ((EntryVehicle != nullptr) && EntryVehicle.TryToDrive(Pawn))
		{
			return;
		}
	}
	ForEach Pawn.TouchingActors(Class'Actor', A)
	{
		A.UsedBy(Pawn);
	}
	if (Pawn.Base != nullptr)
	{
		Pawn.Base.UsedBy(Pawn);
	}
	*/
}

void AAA2_PlayerController::Suicide()
{
	/*
	if ("" + FString::FromInt(Level) ~= "Entry.LevelInfo0")
	{
		return;
	}
	if ((Pawn != nullptr) && ((GetWorld()->GetTimeSeconds() - Pawn.LastStartTime) > 1))
	{
		if ((Cast<AVehicle>(Pawn) != nullptr) && (Cast<AVehicle>(Pawn).Driver != nullptr))
		{
			Pawn.Suicide();
		}
		else
		{
			Pawn.KilledBy(Pawn);
		}
	}
	*/
}

void AAA2_PlayerController::SetSkinPreference(FString S)
{
}

void AAA2_PlayerController::SetVoice(FString S)
{
	/*
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo->SetCharacterVoice(S);
		}
	}
	else
	{
		ChangeVoiceType(S);
	}
	UpdateURL("Voice", S, true);
	*/
}

void AAA2_PlayerController::ChangeVoiceType(FString NewVoiceType)
{
	/*
	if (VoiceChangeLimit > GetWorld()->GetTimeSeconds())
	{
		return;
	}
	VoiceChangeLimit = (GetWorld()->GetTimeSeconds() + 10);
	if ((NewVoiceType != "") && (PlayerReplicationInfo != nullptr))
	{
		PlayerReplicationInfo->SetCharacterVoice(NewVoiceType);
	}
	*/
}

void AAA2_PlayerController::ChangeName(FString S)
{
	/*
	if (Len(S) > 20)
	{
		S = Left(S, 20);
	}
	ReplaceText(S, " ", "_");
	ReplaceText(S, "\"", "");
	Level.Game.ChangeName(this, S, true);
	*/
}

void AAA2_PlayerController::SwitchTeam()
{
	if ((PlayerReplicationInfo->Team == nullptr) || (PlayerReplicationInfo->Team->TeamIndex == 1))
	{
		RequestChangeTeam(0);
	}
	else
	{
		RequestChangeTeam(1);
	}
}

void AAA2_PlayerController::RequestChangeTeam(int32 N)
{
	if (PlayerReplicationInfo->IsOnlyASpectator())
	{
		return;
	}
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		//PlayerReplicationInfo->DesiredTeam = uint8(N);
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && (N == 1))
		{
			N = 0;
		}
		//Level.Game.RequestChangeTeam(this, N);
	}
}

void AAA2_PlayerController::ChangeTeam(int32 N)
{
	ATeamInfo* OldTeam = nullptr;
	if (PlayerReplicationInfo == nullptr)
	{
		return;
	}
	OldTeam = PlayerReplicationInfo->Team;
	/*
	Level.Game.ChangeTeam(this, N, true);
	if (Level.Game.bTeamGame && (PlayerReplicationInfo->Team != OldTeam))
	{
		if (Pawn != nullptr)
		{
			Pawn.KilledBy(Pawn);
		}
		ResetSkinsAndMeshes();
	}
	*/
}

void AAA2_PlayerController::ServerChangeTeam(int32 N)
{
	ATeamInfo* OldTeam = nullptr;
	OldTeam = PlayerReplicationInfo->Team;
	/*
	Level.Game.ChangeTeam(this, N, true);
	if (Level.Game.bTeamGame && (PlayerReplicationInfo->Team != OldTeam))
	{
		if (((OldTeam != nullptr) && (PlayerReplicationInfo->Team != nullptr)) && (PlayerReplicationInfo->Team->Size > OldTeam.Size))
		{
			Adrenaline = 0;
		}
		if (Pawn != nullptr)
		{
			Pawn.PlayerChangedTeam();
		}
	}
	*/
}

void AAA2_PlayerController::ResetSkinsAndMeshes()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	//DebugLog(DEBUG_Skin, "PlayerController::ResetSkinsAndMeshes()");
}

void AAA2_PlayerController::SwitchLevel(FString URL)
{
	/*
	if ((GetWorld()->GetNetMode() == NM_Standalone) || (GetWorld()->GetNetMode() == NM_ListenServer))
	{
		Level.ServerTravel(URL, false);
	}
	*/
}

void AAA2_PlayerController::ProgressCommand(FString Cmd, FString Msg1, FString Msg2)
{
	FString C = "";
	FString V = "";
	/*
	Log(string(Name) + ".ProgressCommand Cmd '" + Cmd + "'  Msg1 '" + Msg1 + "'   Msg2 '" + Msg2 + "'");
	Divide(Cmd, ":", C, V);
	if (C ~= "menu")
	{
		ClientOpenMenu(V, false, Msg1, Msg2);
	}
	*/
}

void AAA2_PlayerController::ClearProgressMessages()
{
	int32 i = 0;
	for (i = 0; i < 4; i++)
	{
		ProgressMessage[i] = "";
		//ProgressColor[i] = Class'Canvas'.MakeColor(255, 255, 255);
	}
}

void AAA2_PlayerController::SetProgressMessage(int32 Index, FString S, FColor C)
{
	if (Index < 4)
	{
		ProgressMessage[Index] = S;
		ProgressColor[Index] = C;
	}
}

void AAA2_PlayerController::SetProgressTime(float t)
{
	//ProgressTimeOut = (t + GetWorld()->GetTimeSeconds());
}

void AAA2_PlayerController::SimpleRestart()
{
	ResetTimeMargin();
	EnterStartState();
	//bBehindView = Pawn.PointOfView();
	//SimpleClientRestart(Pawn);
	//SetViewTarget(Pawn);
}

void AAA2_PlayerController::Restart()
{
	//Super::Restart();
	ServerTimeStamp = 0;
	ResetTimeMargin();
	EnterStartState();
	//bBehindView = Pawn.PointOfView();
	//ClientReStart(Pawn, bDontClearLevel);
	bDontClearLevel = false;
	//SetViewTarget(Pawn);
}

void AAA2_PlayerController::EnterStartState()
{
	FName NewState = "";
	/*
	if (Pawn.HasParachute() && (Pawn.Physics == 17))
	{
		Log(string(this) @ "PlayerController::EnterStartState	Have parachute. Current state = " + FString::FromInt(GetStateName()));
		NewState = "PlayerParachuting";
	}
	else
	{
		if (Pawn.PhysicsVolume.bWaterVolume)
		{
			if (Pawn.HeadVolume.bWaterVolume)
			{
				Pawn.BreathTime = Pawn.UnderWaterTime;
			}
			NewState = Pawn.WaterMovementState;
		}
		else
		{
			NewState = Pawn.LandMovementState;
		}
	}
	if (IsInState(NewState))
	{
		BeginState();
	}
	else
	{
		GotoState(NewState);
	}
	*/
}

void AAA2_PlayerController::SimpleClientRestart(APawn* NewPawn)
{
	bool bNewViewTarget = false;
	/*
	Pawn = NewPawn;
	if ((Pawn != nullptr) && Pawn.bTearOff)
	{
		Pawn.Controller = nullptr;
		Pawn = nullptr;
	}
	AcknowledgePossession(Pawn);
	if (GetPawn() == nullptr)
	{
		GotoState("WaitingForPawn");
		return;
	}
	bNewViewTarget = (ViewTarget != Pawn);
	SetViewTarget(Pawn);
	bBehindView = Pawn.PointOfView();
	BehindView(bBehindView);
	if (bNewViewTarget)
	{
		Pawn.POVChanged(this, false);
	}
	*/
	bFreeCamera = false;
	CleanOutSavedMoves();
	EnterStartState();
}

void AAA2_PlayerController::ClientReStart(APawn* NewPawn, bool bDontClearLevelParam)
{
	bool bNewViewTarget = false;
	/*
	Pawn = NewPawn;
	if ((Pawn != nullptr) && Pawn.bTearOff)
	{
		Pawn.Controller = nullptr;
		Pawn = nullptr;
	}
	AcknowledgePossession(Pawn);
	if (GetPawn() == nullptr)
	{
		GotoState("WaitingForPawn");
		return;
	}
	Pawn.ClientReStart();
	bNewViewTarget = (ViewTarget != Pawn);
	SetViewTarget(Pawn);
	bBehindView = Pawn.PointOfView();
	BehindView(bBehindView);
	if (bNewViewTarget)
	{
		Pawn.POVChanged(this, false);
	}
	*/
	bFreeCamera = false;
	CleanOutSavedMoves();
	EnterStartState();
}

bool AAA2_PlayerController::CanBehindView()
{
	//return (GetWorld()->GetNetMode() == NM_Standalone);
	return false;    //FAKE   /EliZ
}

void AAA2_PlayerController::BehindView(bool B)
{
	if (CanBehindView())
	{
		bBehindView = B;
		ClientSetBehindView(bBehindView,false);
	}
}

void AAA2_PlayerController::ToggleBehindView()
{
}

void AAA2_PlayerController::ServerToggleBehindView()
{
	bool B = false;
	/*
	if ((((((GetWorld()->GetNetMode() == NM_Standalone) || Level.Game.bAllowBehindView) || (Cast<AVehicle>(Pawn) != nullptr)) || PlayerReplicationInfo->bOnlySpectator) || PlayerReplicationInfo->bAdmin) || IsA("Admin"))
	{
		if ((Cast<AVehicle>(Pawn) == nullptr) || Vehicle(Pawn).bAllowViewChange)
		{
			B = (!bBehindView);
			ClientSetBehindView(B);
			bBehindView = B;
		}
	}
	*/
}

void AAA2_PlayerController::ChangedWeapon()
{
	/*
	if ((Pawn != nullptr) && (Pawn.Weapon != nullptr))
	{
		Pawn.Weapon.SetHand(Handedness);
		LastPawnWeapon = Pawn.Weapon.Class;
	}
	*/
}

void AAA2_PlayerController::TravelPostAccept()
{
	/*
	if (Pawn.Health <= 0)
	{
		Pawn.Health = Pawn.Default.Health;
	}
	*/
}

void AAA2_PlayerController::PlayerTick(float DeltaTime)
{
	bool bSelfHealState = false;
	bSelfHealState = (bHealSelfAction == 1);
	if (bLastHealSelfAction != bSelfHealState)
	{
		bLastHealSelfAction = bSelfHealState;
		ServerUpdateSelfHealActionState(bLastHealSelfAction);
	}
	/*
	if (bForcePrecache)
	{
		if (GetWorld()->GetTimeSeconds() > ForcePrecacheTime)
		{
			bForcePrecache = false;
			Level.FillPrecacheMaterialsArray(false);
			Level.FillPrecacheStaticMeshesArray(false);
		}
	}
	else
	{
		if (!bShortConnectTimeOut)
		{
			bShortConnectTimeOut = true;
			ServerShortTimeout();
		}
	}
	if (Pawn != AcknowledgedPawn)
	{
		if (Role < 4)
		{
			if ((AcknowledgedPawn != nullptr) && (AcknowledgedPawn.Controller == this))
			{
				AcknowledgedPawn.Controller = nullptr;
			}
		}
		AcknowledgePossession(Pawn);
	}
	PlayerInput->PlayerInput(DeltaTime);
	if (bUpdatePosition)
	{
		ClientUpdatePosition();
	}
	if ((!IsSpectating()) && (Pawn != nullptr))
	{
		Pawn.RawInput(DeltaTime, aBaseX, aBaseY, aBaseZ, aMouseX, aMouseY, aForward, aTurn, aStrafe, aUp, aLookUp);
	}
	PlayerMove(DeltaTime);
	*/
}

void AAA2_PlayerController::PlayerMove(float DeltaTime)
{
}

FRotator AAA2_PlayerController::AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror)
{
	return FRotator(0, 0, 0);
}

bool AAA2_PlayerController::NotifyLanded(FVector HitNormal)
{
	return bUpdating;
}

void AAA2_PlayerController::AdjustView(float DeltaTime)
{
	/*
	if (FovAngle != DesiredFOV)
	{
		if (FovAngle > DesiredFOV)
		{
			FovAngle = (FovAngle - FMax(7, ((0.9 * DeltaTime) * (FovAngle - DesiredFOV))));
		}
		else
		{
			FovAngle = (FovAngle - FMin(-7, ((0.9 * DeltaTime) * (FovAngle - DesiredFOV))));
		}
		if (FMath::Abs((FovAngle - DesiredFOV)) <= float(10))
		{
			FovAngle = DesiredFOV;
		}
	}
	*/
}

void AAA2_PlayerController::CalcBehindView(FVector& CameraLocation, FRotator& CameraRotation, float dist)
{
	FVector View = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	float ViewDist = 0;
	float RealDist = 0;
	FVector globalX = FVector(0, 0, 0);
	FVector globalY = FVector(0, 0, 0);
	FVector globalZ = FVector(0, 0, 0);
	FVector localX = FVector(0, 0, 0);
	FVector localY = FVector(0, 0, 0);
	FVector localZ = FVector(0, 0, 0);
	/*
	CameraRotation = Rotation;
	CameraRotation.Roll = 0;
	(CameraLocation.Z += float(12));
	(CameraRotation += CameraDeltaRotation);
	View = (FVector(1, 0, 0) >> CameraRotation);
	RealDist = dist;
	(dist += CameraDeltaRad);
	if (Trace(HitLocation, HitNormal, (CameraLocation - (dist * Vector(CameraRotation))), CameraLocation, false, FVector(10, 10, 10)) != nullptr)
	{
		ViewDist = FMin(((CameraLocation - HitLocation) Dot View), dist);
	}
	else
	{
		ViewDist = dist;
	}
	if (((!bBlockCloseCamera) || (!bValidBehindCamera)) || (ViewDist > (float(10) + FMax(ViewTarget.CollisionRadius, ViewTarget.CollisionHeight))))
	{
		bValidBehindCamera = true;
		OldCameraLoc = (CameraLocation - (ViewDist * View));
		OldCameraRot = CameraRotation;
	}
	else
	{
		SetActorRotation(OldCameraRot);
	}
	CameraLocation = OldCameraLoc;
	CameraRotation = OldCameraRot;
	GetAxes(CameraSwivel, globalX, globalY, globalZ);
	localX = (globalX >> CameraRotation);
	localY = (globalY >> CameraRotation);
	localZ = (globalZ >> CameraRotation);
	CameraRotation = OrthoRotation(localX, localY, localZ);
	*/
}

void AAA2_PlayerController::CalcFirstPersonView(FVector& CameraLocation, FRotator& CameraRotation)
{
	/*
	CameraRotation = Pawn.GetViewRotation();
	CameraLocation = (Pawn.EyePosition() + ShakeOffset);
	*/
}

void AAA2_PlayerController::AddCameraEffect(UCameraEffect* NewEffect, bool RemoveExisting)
{
	/*
	if (RemoveExisting)
	{
		RemoveCameraEffect(NewEffect);
	}
	CameraEffects.Num() = (CameraEffects.Num() + 1);
	CameraEffects[(CameraEffects.Num() - 1)] = NewEffect;
	*/
}

void AAA2_PlayerController::RemoveCameraEffect(UCameraEffect* ExEffect)
{
	int32 EffectIndex = 0;
	/*
	for (EffectIndex = 0; EffectIndex < CameraEffects.Num(); EffectIndex++)
	{
		if (CameraEffects[EffectIndex] == ExEffect)
		{
			CameraEffects.RemoveAt(EffectIndex, 1);
			return;
		}
	}
	*/
}

void AAA2_PlayerController::CreateCameraEffect(UCameraEffect* EffectClass)
{
	//AddCameraEffect(new () classEffectClass);
}

FRotator AAA2_PlayerController::GetViewRotation()
{
	if ((bBehindView && (!bFreeCamera)) && (GetPawn() != nullptr))
	{
		return GetPawn()->GetActorRotation();
	}
	//return Rotation;
	return FRotator(0, 0, 0);
}

void AAA2_PlayerController::CacheCalcView(AActor* ViewActor, FVector CameraLocation, FRotator CameraRotation)
{
}

void AAA2_PlayerController::PlayerCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
	APawn* PTarget = nullptr;
	/*
	if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon.ShowProjectileView())
	{
		Pawn.ProjectileCalcView(ViewActor, CameraLocation, CameraRotation);
		return;
	}
	if (((Pawn != nullptr) && Pawn.bSpecialCalcView) && (ViewTarget == Pawn))
	{
		if (Pawn.SpecialCalcView(ViewActor, CameraLocation, CameraRotation))
		{
			CacheCalcView(ViewActor, CameraLocation, CameraRotation);
			return;
		}
	}
	if ((ViewTarget == nullptr) || ViewTarget.bDeleteMe)
	{
		if (bViewBot && (CheatManager != nullptr))
		{
			CheatManager.ViewBot();
		}
		else
		{
			if ((Pawn != nullptr) && (!Pawn.bDeleteMe))
			{
				SetViewTarget(Pawn);
			}
			else
			{
				if (RealViewTarget != nullptr)
				{
					SetViewTarget(RealViewTarget);
				}
				else
				{
					SetViewTarget(this);
				}
			}
		}
	}
	ViewActor = ViewTarget;
	CameraLocation = ViewTarget.Location;
	if (ViewTarget == Pawn)
	{
		if (bBehindView)
		{
			CalcBehindView(CameraLocation, CameraRotation, (CameraDist * Pawn.Default.CollisionRadius));
		}
		else
		{
			CalcFirstPersonView(CameraLocation, CameraRotation);
		}
		CacheCalcView(ViewActor, CameraLocation, CameraRotation);
		return;
	}
	if (ViewTarget == this)
	{
		if (bCameraPositionLocked)
		{
			CameraRotation = CheatManager.LockedRotation;
		}
		else
		{
			CameraRotation = Rotation;
		}
		CacheCalcView(ViewActor, CameraLocation, CameraRotation);
		return;
	}
	if (ViewTarget->IsA(AProjectile::StaticClass()))
	{
		if (Cast<AProjectile>(ViewTarget).bSpecialCalcView && Projectile(ViewTarget).SpecialCalcView(ViewActor, CameraLocation, CameraRotation, bBehindView))
		{
			CacheCalcView(ViewActor, CameraLocation, CameraRotation);
			return;
		}
		if (!bBehindView)
		{
			(CameraLocation += (ViewTarget.CollisionHeight * FVector(0, 0, 1)));
			CameraRotation = Rotation;
			CacheCalcView(ViewActor, CameraLocation, CameraRotation);
			return;
		}
	}
	CameraRotation = ViewTarget.Rotation;
	PTarget = Cast<APawn>(ViewTarget);
	if (PTarget != nullptr)
	{
		if ((GetWorld()->GetNetMode() == NM_Client) || (bDemoOwner && (GetNetMode() != ENetMode::NM_Standalone)))
		{
			PTarget.SetViewRotation(TargetViewRotation);
			CameraRotation = BlendedTargetViewRotation;
			PTarget.EyeHeight = TargetEyeHeight;
			if (!bBehindView)
			{
				CameraRotation = PTarget.GetInterpolatedRotation();
				CameraLocation = PTarget.EyePosition();
			}
		}
		else
		{
			if (PTarget.IsPlayerPawn())
			{
				CameraRotation = PTarget.GetViewRotation();
			}
		}
		if (PTarget.bSpecialCalcView && PTarget.SpectatorSpecialCalcView(this, ViewActor, CameraLocation, CameraRotation))
		{
			CacheCalcView(ViewActor, CameraLocation, CameraRotation);
			return;
		}
	}
	if (bBehindView)
	{
		CameraLocation = (CameraLocation + ((ViewTarget.Default.CollisionHeight - ViewTarget.CollisionHeight) * FVector(0, 0, 1)));
		CalcBehindView(CameraLocation, CameraRotation, (CameraDist * ViewTarget.Default.CollisionRadius));
	}
	CacheCalcView(ViewActor, CameraLocation, CameraRotation);
	*/
}

int32 AAA2_PlayerController::BlendRot(float DeltaTime, int32 BlendC, int32 NewC)
{
	/*
	if (FMath::Abs(float((BlendC - NewC))) > float(32767))
	{
		if (BlendC > NewC)
		{
			(NewC += 65536);
		}
		else
		{
			(BlendC += 65536);
		}
	}
	if (FMath::Abs(float((BlendC - NewC))) > float(4096))
	{
		BlendC = NewC;
	}
	else
	{
		BlendC = int((float(BlendC) + (float((NewC - BlendC)) * FMin(1, (24 * DeltaTime)))));
	}
	*/
	return (BlendC & 65535);
}

void AAA2_PlayerController::CheckShake(float& MaxOffset, float& offset, float& Rate, float& Time, float dt)
{
	/*
	if (FMath::Abs(offset) < Abs(MaxOffset))
	{
		return;
	}
	offset = MaxOffset;
	if (Time > 1)
	{
		if ((Time * Abs((MaxOffset / Rate))) <= 1)
		{
			MaxOffset = (MaxOffset * ((1 / Time) - 1));
		}
		else
		{
			(MaxOffset *= float(-1));
		}
		(Time -= dt);
		(Rate *= float(-1));
	}
	else
	{
		MaxOffset = 0;
		offset = 0;
		Rate = 0;
	}
	*/
}

void AAA2_PlayerController::UpdateShakeRotComponent(float& Max, int32& Current, float& Rate, float& Time, float dt)
{
	float fCurrent = 0;
	/*
	Current = (int((float((Current & 65535)) + (Rate * dt))) & 65535);
	if (Current > 32768)
	{
		(Current -= 65536);
	}
	fCurrent = float(Current);
	CheckShake(Max, fCurrent, Rate, Time, dt);
	Current = int(fCurrent);
	*/
}

void AAA2_PlayerController::ViewShake(float DeltaTime)
{
	/*
	if (ShakeOffsetRate != FVector(0, 0, 0))
	{
		(ShakeOffset.X += (DeltaTime * ShakeOffsetRate.X));
		CheckShake(ShakeOffsetMax.X, ShakeOffset.X, ShakeOffsetRate.X, ShakeOffsetTime.X, DeltaTime);
		(ShakeOffset.Y += (DeltaTime * ShakeOffsetRate.Y));
		CheckShake(ShakeOffsetMax.Y, ShakeOffset.Y, ShakeOffsetRate.Y, ShakeOffsetTime.Y, DeltaTime);
		(ShakeOffset.Z += (DeltaTime * ShakeOffsetRate.Z));
		CheckShake(ShakeOffsetMax.Z, ShakeOffset.Z, ShakeOffsetRate.Z, ShakeOffsetTime.Z, DeltaTime);
	}
	if (ShakeRotRate != FVector(0, 0, 0))
	{
		UpdateShakeRotComponent(ShakeRotMax.X, ShakeRot.Pitch, ShakeRotRate.X, ShakeRotTime.X, DeltaTime);
		UpdateShakeRotComponent(ShakeRotMax.Y, ShakeRot.Yaw, ShakeRotRate.Y, ShakeRotTime.Y, DeltaTime);
		UpdateShakeRotComponent(ShakeRotMax.Z, ShakeRot.Roll, ShakeRotRate.Z, ShakeRotTime.Z, DeltaTime);
	}
	*/
}

bool AAA2_PlayerController::TurnTowardNearestEnemy()
{
	return false;   //FAKE  /ELiZ
}

void AAA2_PlayerController::TurnAround()
{
	/*
	if (!bSetTurnRot)
	{
		TurnRot180 = Rotation;
		(TurnRot180.Yaw += 32768);
		bSetTurnRot = true;
	}
	DesiredRotation = TurnRot180;
	bRotateToDesired = (DesiredRotation.Yaw != Rotation.Yaw);
	*/
}

void AAA2_PlayerController::UpdateRotation(float DeltaTime, float maxPitch)
{
	FRotator NewRotation = FRotator(0, 0, 0);
	FRotator ViewRotation = FRotator(0, 0, 0);
	FRotator limit = FRotator(0, 0, 0);
	AAGP_Viewpoint* vpt = nullptr;
	/*
	if (bInterpolating || ((Pawn != nullptr) && Pawn.bInterpolating))
	{
		ViewShake(DeltaTime);
		return;
	}
	if (bFreeCam == true)
	{
		if (bFreeCamZoom == true)
		{
			(CameraDeltaRad += ((DeltaTime * 0.25) * aLookUp));
		}
		else
		{
			if (bFreeCamSwivel == true)
			{
				(CameraSwivel.Yaw += int(((16 * DeltaTime) * aTurn)));
				(CameraSwivel.Pitch += int(((16 * DeltaTime) * aLookUp)));
			}
			else
			{
				(CameraDeltaRotation.Yaw += int(((32 * DeltaTime) * aTurn)));
				(CameraDeltaRotation.Pitch += int(((32 * DeltaTime) * aLookUp)));
			}
		}
	}
	else
	{
		ViewRotation = Rotation;
		if ((Pawn != nullptr) && (Pawn.Physics != 4))
		{
			if ((Pawn.DesiredRotation.Roll < 65535) && ((ViewRotation.Roll < Pawn.DesiredRotation.Roll) || (ViewRotation.Roll > 0)))
			{
				ViewRotation.Roll = 0;
			}
			else
			{
				if ((Pawn.DesiredRotation.Roll > 0) && ((ViewRotation.Roll > Pawn.DesiredRotation.Roll) || (ViewRotation.Roll < 65535)))
				{
					ViewRotation.Roll = 0;
				}
			}
		}
		DesiredRotation = ViewRotation;
		if (bTurnToNearest != 0)
		{
			TurnTowardNearestEnemy();
		}
		else
		{
			if (bTurn180 != 0)
			{
				TurnAround();
			}
			else
			{
				TurnTarget = nullptr;
				bRotateToDesired = false;
				bSetTurnRot = false;
				bTrackIRViewTrackingEnabled = false;
				if (bTrackIRViewTrackingWasEnabled)
				{
					if ((((Pawn != nullptr) && (!IsInState("PlayerParachuting"))) && (!IsInState("Manning_Turret"))) && (!IsInState("Viewing_RemoteCam")))
					{
						Pawn.bDecoupleCamera = false;
					}
					bTrackIRViewTrackingWasEnabled = false;
				}
				(ViewRotation.Yaw += int(((32 * DeltaTime) * aTurn)));
				(ViewRotation.Pitch += int(((32 * DeltaTime) * aLookUp)));
				if (Pawn != nullptr)
				{
					Pawn.fSprintMod = Pawn.GetSprintModifier(FMath::Abs(float((ViewRotation.Yaw - Rotation.Yaw))), DeltaTime, bPressedJump);
				}
			}
		}
		if (Pawn != nullptr)
		{
			if (Pawn.bLimitRotation)
			{
				if (GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					Pawn.RestrictRotation(ViewRotation, Pawn.rBaseRotation, Pawn.rRotationLimits);
				}
			}
			if (Pawn.LeanParam != 0)
			{
				bZeroRoll = false;
				ViewRotation.Roll = int((Pawn.LeanParam * float(Pawn.LeanRollView)));
			}
			else
			{
				bZeroRoll = GetDefault<AAA2_PlayerController>()->bZeroRoll;
			}
			ViewRotation.Pitch = (ViewRotation.Pitch & 65535);
			if ((Pawn.bIsProne && (!Pawn.bTransitionAnim)) && (!bBehindView))
			{
				NewRotation = Normalize(ViewRotation);
				if (Pawn.bFrontGrounded)
				{
					if ((((Pawn.Weapon != nullptr) && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass())) && (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch + 1425))) && (!Pawn.Weapon.IsZoomed()))
					{
						ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 1425);
					}
					else
					{
						if (((Pawn.Weapon != nullptr) && Pawn.Weapon->IsA(AJavelin_Tube::StaticClass())) && (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch + 208)))
						{
							ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 208);
						}
						else
						{
							if (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch - 3750))
							{
								ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch - 3750);
							}
						}
					}
					if (NewRotation.Pitch > (Pawn.FrontFloorRotation.Pitch + 6553))
					{
						ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 6553);
					}
				}
				else
				{
					if ((((Pawn.Weapon != nullptr) && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass())) && (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch + 1425))) && (!Pawn.Weapon.IsZoomed()))
					{
						ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 1425);
					}
					else
					{
						if (((Pawn.Weapon != nullptr) && Pawn.Weapon->IsA(AJavelin_Tube::StaticClass())) && (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch + 208)))
						{
							ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 208);
						}
						else
						{
							if (NewRotation.Pitch < (Pawn.FrontFloorRotation.Pitch - 6553))
							{
								ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch - 6553);
							}
						}
					}
					if (NewRotation.Pitch > (Pawn.FrontFloorRotation.Pitch + 6553))
					{
						ViewRotation.Pitch = (Pawn.FrontFloorRotation.Pitch + 6553);
					}
				}
			}
		}
		else
		{
			ViewRotation.Pitch = (ViewRotation.Pitch & 65535);
		}
		vpt = Cast<AAGP_Viewpoint>(ViewTarget);
		if ((vpt != nullptr) && vpt.bLimitRotation)
		{
			DebugLog(DEBUG_Spec, "PlayerController::UpdateRotation()	" + FString::FromInt(ViewRotation) @ FString::FromInt(vpt.Rotation) @ FString::FromInt(limit));
			RestrictRotation(ViewRotation, vpt.Rotation, FRotatorD(vpt.LimitPitch, vpt.LimitYaw, 360));
		}
		else
		{
			if ((ViewRotation.Pitch > 16380) && (ViewRotation.Pitch < 49160))
			{
				if (ViewRotation.Pitch < 32770)
				{
					ViewRotation.Pitch = 16380;
				}
				else
				{
					ViewRotation.Pitch = 49160;
				}
			}
		}
		SetActorRotation(ViewRotation);
		ViewShake(DeltaTime);
		ViewFlash(DeltaTime);
		NewRotation = ViewRotation;
		if ((float(NewRotation.Pitch) > (maxPitch * float(RotationRate.Pitch))) && (float(NewRotation.Pitch) < (float(65536) - (maxPitch * float(RotationRate.Pitch)))))
		{
			if (ViewRotation.Pitch < 32768)
			{
				NewRotation.Pitch = int((maxPitch * float(RotationRate.Pitch)));
			}
			else
			{
				NewRotation.Pitch = int((float(65536) - (maxPitch * float(RotationRate.Pitch))));
			}
		}
		if ((((!bRotateToDesired) && (!bFreeCamera)) && (Pawn != nullptr)) && (!Pawn.bDecoupleCamera))
		{
			Pawn.FaceRotation(NewRotation, DeltaTime);
		}
	}
	*/
}

void AAA2_PlayerController::ClearDoubleClick()
{
	if (PlayerInput != nullptr)
	{
		//PlayerInput->DoubleClickTimer = 0;
	}
}

bool AAA2_PlayerController::DodgingIsEnabled()
{
	/*
	if (PlayerInput != nullptr)
	{
		return PlayerInput->bEnableDodging;
	}
	else
	{
		if (InputClass != nullptr)
		{
			return InputClass.Default.bEnableDodging;
		}
		else
		{
			return Class'PlayerInput'.Default.bEnableDodging;
		}
	}
	*/
	return false;   //FAKE  /ELiZ
}

void AAA2_PlayerController::SetDodging(bool Enabled)
{
	/*
	if (PlayerInput != nullptr)
	{
		PlayerInput->bEnableDodging = Enabled;
	}
	InputClass.Default.bEnableDodging = Enabled;
	InputClass.StaticSaveConfig();
	*/
}

FVector AAA2_PlayerController::CalcAcceleration(FVector X, FVector Y, FVector Z, FRotator& ViewRotation)
{
	FVector Accel = FVector(0, 0, 0);
	Accel = ((aForward * X) + (aStrafe * Y));
	Accel.Z = 0;
	return Accel;
}

bool AAA2_PlayerController::IsSpectating()
{
	return false;
}

bool AAA2_PlayerController::IsSpectating_NativeCallable()
{
	return IsSpectating();
}

void AAA2_PlayerController::ServerViewNextPlayer()
{
}

void AAA2_PlayerController::ServerViewSelf()
{
	//SetLocation(ViewTarget.Location);
	//ClientSetLocation(ViewTarget->GetActorLocation(), Rotation);
	bBehindView = false;
	SetViewTarget(this);
	ClientSetViewTarget(this);
	ClientMessage(OwnCamera, "Event");
}

void AAA2_PlayerController::LoadPlayers()
{
	int32 i = 0;
	if (GameReplicationInfo == nullptr)
	{
		return;
	}
	/*
	for (i = 0; i < GameReplicationInfo->PRIArray.Num(); i++)
	{
		GameReplicationInfo->PRIArray[i].UpdatePrecacheMaterials();
	}
	*/
}

void AAA2_PlayerController::FoundWaitingForPawn(APawn* p)
{
}

void AAA2_PlayerController::ServerSpectate()
{
	//GotoState("Spectating");
	bBehindView = true;
	ServerViewNextPlayer();
}

void AAA2_PlayerController::BecomeSpectator()
{
	/*
	if (Role < 4)
	{
		return;
	}
	if (((((PlayerReplicationInfo == nullptr) || (!GameReplicationInfo->bMatchHasBegun)) || (Level.Game.NumSpectators >= Level.Game.MaxSpectators)) || IsInState("GameEnded")) || IsInState("RoundEnded"))
	{
		ReceiveLocalizedMessage(Level.Game.GameMessageClass, 12);
		return;
	}
	PlayerReplicationInfo->bOnlySpectator = true;
	Level.Game.NumSpectators++;
	Level.Game.NumPlayers--;
	if (Pawn != nullptr)
	{
		Pawn.Died(this, Class'DamageType', Pawn.Location);
	}
	if (PlayerReplicationInfo->Team != nullptr)
	{
		PlayerReplicationInfo->Team->RemoveFromTeam(this);
	}
	PlayerReplicationInfo->Team = nullptr;
	PlayerReplicationInfo->Score_Total = 0;
	PlayerReplicationInfo->GoalsScored = 0;
	PlayerReplicationInfo->Kills = 0;
	ServerSpectate();
	BroadcastLocalizedMessage(Level.Game.GameMessageClass, 14, PlayerReplicationInfo);
	ClientBecameSpectator();
	*/
}

void AAA2_PlayerController::ClientBecameSpectator()
{
	//UpdateURL("SpectatorOnly", "1", true);
}

void AAA2_PlayerController::BecomeActivePlayer()
{
	/*
	if (Role < 4)
	{
		return;
	}
	if (((((((PlayerReplicationInfo == nullptr) || (!GameReplicationInfo->bMatchHasBegun)) || Level.Game.bMustJoinBeforeStart) || (Level.Game.NumPlayers >= Level.Game.MaxPlayers)) || (Level.Game.MaxLives > 0)) || IsInState("GameEnded")) || IsInState("RoundEnded"))
	{
		ReceiveLocalizedMessage(Level.Game.GameMessageClass, 13);
		return;
	}
	bBehindView = false;
	FixFOV();
	ServerViewSelf();
	PlayerReplicationInfo->bOnlySpectator = false;
	Level.Game.NumSpectators--;
	Level.Game.NumPlayers++;
	PlayerReplicationInfo->Reset();
	Adrenaline = 0;
	BroadcastLocalizedMessage(Level.Game.GameMessageClass, 1, PlayerReplicationInfo);
	if (Level.Game.bTeamGame)
	{
		Level.Game.ChangeTeam(this, Level.Game.PickTeam(byte(int(GetUrlOption("Team"))), nullptr), false);
	}
	if (!Level.Game.bDelayedStart)
	{
		Level.Game.bRestartLevel = false;
		if (Level.Game.bWaitingToStartMatch)
		{
			Level.Game.StartMatch();
		}
		else
		{
			Level.Game.RestartPlayer(Cast<APlayerController>(Owner));
		}
		Level.Game.bRestartLevel = Level.Game.Default.bRestartLevel;
	}
	else
	{
		GotoState("PlayerWaiting");
	}
	ClientBecameActivePlayer();
	*/
}

void AAA2_PlayerController::ClientBecameActivePlayer()
{
	//UpdateURL("SpectatorOnly", "", true);
}

void AAA2_PlayerController::ChangeStairLook(bool B)
{
	bLookUpStairs = B;
	if (bLookUpStairs)
	{
		bAlwaysMouseLook = false;
	}
}

void AAA2_PlayerController::ChangeAlwaysMouseLook(bool B)
{
	bAlwaysMouseLook = B;
	if (bAlwaysMouseLook)
	{
		bLookUpStairs = false;
	}
}

void AAA2_PlayerController::UnPressButtons()
{
	bFire = 0;
	bAltFire = 0;
	bDuck = 0;
	bVoiceTalk = 0;
	ResetInput();
}

bool AAA2_PlayerController::ClientOpenMenu(FString Menu, bool bDisconnect, FString Msg1, FString Msg2)
{
	/*
	if (bDemoOwner && (Menu != DemoMenuClass))
	{
		return false;
	}
	bAction = 0;
	if (!Player.GUIController.OpenMenu(Menu, Msg1, Msg2))
	{
		UnPressButtons();
		return false;
	}
	if (bDisconnect)
	{
		if (Player.Console != nullptr)
		{
			Player.Console.DelayedConsoleCommand("DISCONNECT");
		}
		else
		{
			ConsoleCommand("Disconnect");
		}
		return true;
	}
	*/
	return true;
}

void AAA2_PlayerController::ClientReplaceMenu(FString Menu, bool bDisconnect, FString Msg1, FString Msg2)
{
	//Player.GUIController.ReplaceMenu(Menu, Msg1, Msg2);
}

void AAA2_PlayerController::ClientCloseMenu(bool bCloseAll, bool bCancel)
{
	/*
	if (bDemoOwner)
	{
		return;
	}
	if (Player != nullptr)
	{
		if (bCloseAll)
		{
			Player.GUIController.CloseAll(bCancel, true);
		}
		else
		{
			Player.GUIController.CloseMenu(bCancel);
		}
	}
	*/
}

void AAA2_PlayerController::ClientNetworkMessage(FString ParamA, FString ParamB)
{
}

bool AAA2_PlayerController::IsMouseInverted()
{
	//return PlayerInput->bInvertMouse;
	return false;     //FAKE   /ELiZ
}

void AAA2_PlayerController::InvertMouse(FString Invert)
{
	//PlayerInput->InvertMouse(Invert);
}

void AAA2_PlayerController::InvertLook()
{
	bool Result = false;
	/*
	Result = PlayerInput->InvertLook();
	if (IsOnConsole())
	{
		Class'XBoxPlayerInput'.Default.bInvertVLook = Result;
		Class'XBoxPlayerInput'.StaticSaveConfig();
	}
	*/
}

void AAA2_PlayerController::Crouching()
{
	/*
	if ((PlayerInput->bLockMovement || (GetPawn() == nullptr)) || IsInState("BaseSpectating"))
	{
		return;
	}
	if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (Pawn.Weapon.IsInState("BusyTempLowering") || Pawn.Weapon.IsInState("BusyLoweringWeapon")))
	{
		return;
	}
	if (Pawn.bIsCrouched)
	{
		Pawn.ShouldCrouch(false);
	}
	else
	{
		Pawn.ShouldCrouch(true);
	}
	*/
}

void AAA2_PlayerController::Crawling()
{
	/*
	if (bFire == 1)
	{
		if (!Pawn.Weapon->IsA(AThrowWeapon::StaticClass()))
		{
			if (Pawn.bIsProne)
			{
				ClientMessage("You are stopping shooting while leaving the prone position.");
			}
			else
			{
				ClientMessage("You are stopping shooting while going to the prone position.");
			}
			bFire = 0;
			bAltFire = 0;
		}
	}
	if ((PlayerInput->bLockMovement || (GetPawn() == nullptr)) || IsInState("BaseSpectating"))
	{
		return;
	}
	if ((!Pawn.bCanProne) && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass()))
	{
		return;
	}
	if (Pawn.bIsProne)
	{
		Pawn.ShouldProne(false);
	}
	else
	{
		Pawn.ShouldProne(true);
	}
	*/
}

void AAA2_PlayerController::Stand()
{
	/*
	if (PlayerInput->bLockMovement)
	{
		return;
	}
	Pawn.ShouldStand();
	*/
}

void AAA2_PlayerController::Crouch()
{
	/*
	if (PlayerInput->bLockMovement)
	{
		return;
	}
	Pawn.ShouldCrouch(true);
	*/
}

void AAA2_PlayerController::Crawl()
{
	/*
	if (PlayerInput->bLockMovement)
	{
		return;
	}
	if ((!Pawn.bCanProne) && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass()))
	{
		return;
	}
	Pawn.ShouldProne(true);
	*/
}

void AAA2_PlayerController::FastMove()
{
	/*
	if (Pawn != nullptr)
	{
		Pawn.SetWalking((!Pawn.bIsWalking));
	}
	*/
}

void AAA2_PlayerController::SpecSpeed(float Speed)
{
	//SpectatorSpeedScalar = (Speed / float(10));
}

void AAA2_PlayerController::CycleZoom()
{
	/*
	if (Pawn.Weapon != nullptr)
	{
		Pawn.Weapon.CycleZoom();
	}
	*/
}

void AAA2_PlayerController::Zoom()
{
	if (CanUseWeapon(6))
	{
		//Pawn.Weapon.ToggleZoom();
	}
}

void AAA2_PlayerController::SupportedFire()
{
	if (CanUseWeapon(5))
	{
		//Pawn.SetSupported((!Pawn.IsSupported()));
	}
}

void AAA2_PlayerController::Suppressor()
{
	if (CanUseWeapon(8))
	{
		//Pawn.Weapon.ToggleSuppressor();
	}
}

void AAA2_PlayerController::LeftRail()
{
	if (CanUseWeapon(9))
	{
		//Pawn.Weapon.ToggleLeftRail();
	}
}

void AAA2_PlayerController::RightRail()
{
	if (CanUseWeapon(10))
	{
		//Pawn.Weapon.ToggleRightRail();
	}
}

void AAA2_PlayerController::ScopeAdjustVertical(bool increase)
{
	/*
	if (Pawn.Weapon != nullptr)
	{
		Pawn.Weapon.ScopeAdjust(true, increase);
	}
	*/
}

void AAA2_PlayerController::ScopeAdjustLateral(bool increase)
{
	/*
	if (Pawn.Weapon != nullptr)
	{
		Pawn.Weapon.ScopeAdjust(false, increase);
	}
	*/
}

void AAA2_PlayerController::ZeroScope()
{
	/*
	if (Pawn.Weapon != nullptr)
	{
		Pawn.Weapon.ZeroScope();
	}
	*/
}

void AAA2_PlayerController::ClientSetTimeRemaining(int32 t)
{
	//GameReplicationInfo->RemainingTime = t;
}

void AAA2_PlayerController::DoFade(bool bfadein, bool Black, float Time, float percentage)
{
	_bFadeBlack = Black;
	_bFadeIn = bfadein;
	_fFadeTime = Time;
	//_fFadeStartTime = GetWorld()->GetTimeSeconds();
	_bFade = true;
	if (percentage == 0)
	{
		_fFadePercentage = 1;
	}
	else
	{
		//_fFadePercentage =FMath::Clamp(percentage, 0, 1);
	}
}

void AAA2_PlayerController::KillPawn()
{
	//Pawn.TakeDamage(100, Pawn, Pawn->GetActorLocation(), FVector(0, 0, 0), ASuicided::StaticClass());
}

void AAA2_PlayerController::ClientOpenMap(FString Map)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	//ConsoleCommand("disconnect");
	//ConsoleCommand("start " + Map);
}

void AAA2_PlayerController::ClientDisconnect(FString Msg)
{
}

bool AAA2_PlayerController::CanRestartPlayer()
{
	return (!PlayerReplicationInfo->IsOnlyASpectator());
}

void AAA2_PlayerController::StartClientDemoRec()
{
	//DemoClientSetHUD(myHUD->Class, myHUD->ScoreBoard.Class);
	bClientDemo = true;
	ServerSetClientDemo();
}

void AAA2_PlayerController::ServerSetClientDemo()
{
	bClientDemo = true;
}

void AAA2_PlayerController::DemoClientSetHUD(AAA2_HUD* newHUDClass, AScoreBoard* newScoringClass)
{
	if (myHUD == nullptr)
	{
		ClientSetHUD(newHUDClass, newScoringClass);
	}
}

FString AAA2_PlayerController::GetCustomStatusAnnouncerClass()
{
	return "";
}

FString AAA2_PlayerController::GetCustomRewardAnnouncerClass()
{
	return "";
}

void AAA2_PlayerController::SetCustomStatusAnnouncerClass(FString NewAnnouncerClass)
{
}

void AAA2_PlayerController::SetCustomRewardAnnouncerClass(FString NewAnnouncerClass)
{
}

bool AAA2_PlayerController::NeedNetNotify()
{
	return false;
}

void AAA2_PlayerController::VoiceCommand(FString RecognizedString, FString RawString)
{
	//Log(RecognizedString);
	TeamMessage(PlayerReplicationInfo, RawString, "TeamSayQuiet");
	if (RecognizedString != "")
	{
		ServerVoiceCommand(RecognizedString);
	}
}

void AAA2_PlayerController::Command(FString RecognizedString)
{
	//Level.Game.ParseVoiceCommand(this, RecognizedString);
}

void AAA2_PlayerController::ServerVoiceCommand(FString RecognizedString)
{
	//Level.Game.ParseVoiceCommand(this, RecognizedString);
}

void AAA2_PlayerController::Join(FString ChanName, FString ChanPwd)
{
	int32 i = 0;
	int32 idx = 0;
	AVoiceChatRoom* VCR = nullptr;
	if ((VoiceReplicationInfo == nullptr) || (!VoiceReplicationInfo->bEnableVoiceChat))
	{
		return;
	}
	i = 0;
	/*
	if (i < StoredChatPasswords.Num())
	{
		if (ChanName ~= StoredChatPasswords[i].ChatRoomName)
		{
			if (ChanPwd == "")
			{
				ChanPwd = StoredChatPasswords[i].ChatRoomPassword;
			}
			else
			{
				StoredChatPasswords[i].ChatRoomPassword = ChanPwd;
				SaveConfig();
			}
		}
		else
		{
			i++;
		}
	}
	if ((i == StoredChatPasswords.Num()) && (ChanPwd != ""))
	{
		StoredChatPasswords.Num() = (i + 1);
		StoredChatPasswords[i].ChatRoomName = ChanName;
		StoredChatPasswords[i].ChatRoomPassword = ChanPwd;
		SaveConfig();
	}
	Log("Join " + ChanName @ "Password:" + ChanPwd @ "PRI:" + PlayerReplicationInfo->PlayerName @ "Team:" + FString::FromInt(PlayerReplicationInfo->Team), "VoiceChat");
	if ((PlayerReplicationInfo != nullptr) && (PlayerReplicationInfo->Team != nullptr))
	{
		idx = PlayerReplicationInfo->Team->TeamIndex;
	}
	VCR = VoiceReplicationInfo->GetChannel(ChanName, idx);
	if (VCR != nullptr)
	{
		if (!VCR->IsMember(PlayerReplicationInfo))
		{
			ServerJoinVoiceChannel(VCR->ChannelIndex, ChanPwd);
		}
	}
	else
	{
		if (ChatRoomMessageClass != nullptr)
		{
			ClientMessage(ChatRoomMessageClass.AssembleMessage(0, ChanName));
		}
	}
	*/
}

void AAA2_PlayerController::Leave(FString ChannelTitle)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 idx = 0;
	if ((VoiceReplicationInfo == nullptr) || (!VoiceReplicationInfo->bEnableVoiceChat))
	{
		return;
	}
	/*
	if ((PlayerReplicationInfo != nullptr) && (PlayerReplicationInfo->Team != nullptr))
	{
		idx = PlayerReplicationInfo->Team->TeamIndex;
	}
	VCR = VoiceReplicationInfo->GetChannel(ChannelTitle, idx);
	if ((VCR == nullptr) && (ChatRoomMessageClass != nullptr))
	{
		ClientMessage(ChatRoomMessageClass.AssembleMessage(0, ChannelTitle));
		return;
	}
	if (VCR == ActiveRoom)
	{
		ActiveRoom = nullptr;
	}
	ServerLeaveVoiceChannel(VCR->ChannelIndex);
	*/
}

void AAA2_PlayerController::Speak(FString ChannelTitle)
{
	int32 idx = 0;
	AVoiceChatRoom* VCR = nullptr;
	FString ChanPwd = "";
	if ((VoiceReplicationInfo == nullptr) || (!VoiceReplicationInfo->bEnableVoiceChat))
	{
		return;
	}
	/*
	if ((PlayerReplicationInfo != nullptr) && (PlayerReplicationInfo->Team != nullptr))
	{
		idx = PlayerReplicationInfo->Team->TeamIndex;
	}
	VCR = VoiceReplicationInfo->GetChannel(ChannelTitle, idx);
	if ((VCR == nullptr) && (ChatRoomMessageClass != nullptr))
	{
		ClientMessage(ChatRoomMessageClass.AssembleMessage(0, ChannelTitle));
		return;
	}
	if (VCR->ChannelIndex >= 0)
	{
		ChanPwd = FindChannelPassword(ChannelTitle);
		ServerSpeak(VCR->ChannelIndex, ChanPwd);
	}
	else
	{
		if (ChatRoomMessageClass != nullptr)
		{
			ClientMessage(ChatRoomMessageClass.AssembleMessage(0, ChannelTitle));
		}
	}
	*/
}

void AAA2_PlayerController::SpeakDefault()
{
	FString str = "";
	str = GetDefaultActiveChannel();
	/*
	if ((str != "") && ((ActiveRoom == nullptr) || (!(ActiveRoom->GetTitle() ~= str))))
	{
		Speak(str);
	}
	*/
}

void AAA2_PlayerController::SpeakLast()
{
	/*
	if ((LastActiveChannel != "") && ((ActiveRoom == nullptr) || (!(ActiveRoom->GetTitle() ~= LastActiveChannel))))
	{
		Speak(LastActiveChannel);
	}
	*/
}

void AAA2_PlayerController::SetChatPassword(FString NewPassword)
{
	if (ChatPassword != NewPassword)
	{
		ChatPassword = NewPassword;
		SaveConfig();
		ServerSetChatPassword(NewPassword);
	}
}

void AAA2_PlayerController::EnableVoiceChat()
{
	bool bCurrent = false;
	//bCurrent = bool(ConsoleCommand("get ini:Engine.Engine.AudioDevice UseVoIP"));
	//ConsoleCommand("set ini:Engine.Engine.AudioDevice UseVoIP" @ FString::FromInt(true));
	if (VoiceReplicationInfo == nullptr)
	{
		return;
	}
	if (!VoiceReplicationInfo->bEnableVoiceChat)
	{
		ChatRoomMessage(15, -1,nullptr);
		return;
	}
	ChangeVoiceChatMode(true);
	InitializeVoiceChat();
	if (bCurrent == false)
	{
		ConsoleCommand("SOUND_REBOOT",false);
	}
}

void AAA2_PlayerController::DisableVoiceChat()
{
	bool bCurrent = false;
	//bCurrent = bool(ConsoleCommand("get ini:Engine.Engine.AudioDevice UseVoIP"));
	//ConsoleCommand("set ini:Engine.Engine.AudioDevice UseVoIP" @ FString::FromInt(false));
	if ((VoiceReplicationInfo == nullptr) || (!VoiceReplicationInfo->bEnableVoiceChat))
	{
		return;
	}
	ChangeVoiceChatMode(false);
	if (bCurrent == true)
	{
		ConsoleCommand("SOUND_REBOOT",false);
	}
}

void AAA2_PlayerController::InitializeVoiceChat()
{
	if (bVoiceChatEnabled)
	{
		InitPrivateChatRoom();
		AutoJoinVoiceChat();
	}
}

void AAA2_PlayerController::InitPrivateChatRoom()
{
	ServerChangeVoiceChatMode(true);
	if (ChatPassword != "")
	{
		ServerSetChatPassword(ChatPassword);
	}
}

FString AAA2_PlayerController::GetDefaultActiveChannel()
{
	FString DefaultChannel = "";
	if (DefaultActiveChannel != "")
	{
		DefaultChannel = DefaultActiveChannel;
	}
	else
	{
		if (VoiceReplicationInfo != nullptr)
		{
			DefaultChannel = VoiceReplicationInfo->GetDefaultChannel();
		}
	}
	return DefaultChannel;
}

void AAA2_PlayerController::AutoJoinVoiceChat()
{
}

void AAA2_PlayerController::ChangeVoiceChatMode(bool bEnable)
{
	if (VoiceReplicationInfo == nullptr)
	{
		return;
	}
	bVoiceChatEnabled = bEnable;
	/*
	if ((GetWorld()->GetNetMode() == NM_Client) || (GetWorld()->GetNetMode() == NM_ListenServer))
	{
		ServerChangeVoiceChatMode(bEnable);
	}
	*/
}

bool AAA2_PlayerController::ChatBan(int32 PlayerID, uint8 Type)
{
	/*
	Log("ChatBan Role:" + FString::FromInt(GetEnum(Enum'Engine.Actor.ENetRole', Role)) @ "ChatManager:" + FString::FromInt(ChatManager) @ "PlayerID:" + FString::FromInt(PlayerID) @ "Type:" + FString::FromInt(Type), "ChatManager");
	if ((GetWorld()->GetNetMode() == NM_Standalone) || (GetWorld()->GetNetMode() == NM_DedicatedServer))
	{
		return false;
	}
	if (ChatManager == nullptr)
	{
		return false;
	}
	if (ChatManager.SetRestrictionID(PlayerID, Type))
	{
		ServerChatRestriction(PlayerID, Type);
		return true;
	}
	Log(string(Name) @ "ChatBan not successful - could not find player with ID:" @ FString::FromInt(PlayerID), "ChatManager");
	*/
	return false;
}

void AAA2_PlayerController::SetChannelPassword(FString ChannelName, FString ChannelPassword)
{
	int32 i = 0;
	/*
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		return;
	}
	for (i = 0; i < StoredChatPasswords.Num(); i++)
	{
		if (StoredChatPasswords[i].ChatRoomName ~= ChannelName)
		{
		}
	}
	if (i == StoredChatPasswords.Num())
	{
		StoredChatPasswords.Num() = (i + 1);
	}
	StoredChatPasswords[i].ChatRoomName = ChannelName;
	StoredChatPasswords[i].ChatRoomPassword = ChannelPassword;
	*/
	SaveConfig();
}

FString AAA2_PlayerController::FindChannelPassword(FString ChannelName)
{
	int32 i = 0;
	/*
	for (i = 0; i < StoredChatPasswords.Num(); i++)
	{
		if (StoredChatPasswords[i].ChatRoomName ~= ChannelName)
		{
			return StoredChatPasswords[i].ChatRoomPassword;
		}
	}
	*/
	return "";
}

EJoinChatResult AAA2_PlayerController::ServerJoinVoiceChannel(int32 ChannelIndex, FString ChannelPassword)
{
	AVoiceChatRoom* VCR = nullptr;
	EJoinChatResult Result = EJoinChatResult::JCR_Invalid;
	VCR = VoiceReplicationInfo->GetChannelAt(ChannelIndex);
	if ((((VoiceReplicationInfo == nullptr) || (PlayerReplicationInfo == nullptr)) || (VCR == nullptr)) || (!VoiceReplicationInfo->bEnableVoiceChat))
	{
		return EJoinChatResult::JCR_Invalid;
	}
	/*
	if (VoiceReplicationInfo != nullptr)
	{
		Result = VoiceReplicationInfo->JoinChannelAt(ChannelIndex, PlayerReplicationInfo, ChannelPassword);
	}
	switch (Result)
	{
		case 2:
			ClientOpenMenu(ChatPasswordMenuClass, false, VCR->GetTitle(), "NEEDPW");
			break;
		case 3:
			ClientOpenMenu(ChatPasswordMenuClass, false, VCR->GetTitle(), "WRONGPW");
			break;
		case 7:
			Level.Game.ChangeVoiceChannel(PlayerReplicationInfo, ChannelIndex, -1);
		default:
			if (ChannelIndex > VoiceReplicationInfo->GetPublicChannelCount(true))
			{
				ChatRoomMessage(Result, ChannelIndex);
			}
	}
	*/
	return Result;
}

void AAA2_PlayerController::ServerLeaveVoiceChannel(int32 ChannelIndex)
{
	AVoiceChatRoom* VCR = nullptr;
	if ((VoiceReplicationInfo == nullptr) || (PlayerReplicationInfo == nullptr))
	{
		return;
	}
	if (!VoiceReplicationInfo->bEnableVoiceChat)
	{
		ChatRoomMessage(15, -1, nullptr);
		return;
	}
	VCR = VoiceReplicationInfo->GetChannelAt(ChannelIndex);
	if ((VCR != nullptr) && VCR->LeaveChannel(PlayerReplicationInfo))
	{
		if (VCR == ActiveRoom)
		{
			ActiveRoom = nullptr;
			if (PlayerReplicationInfo != nullptr)
			{
				PlayerReplicationInfo->ActiveChannel = -1;
			}
		}
		//Level.Game.ChangeVoiceChannel(PlayerReplicationInfo, -1, ChannelIndex);
		if (ChannelIndex > VoiceReplicationInfo->GetPublicChannelCount(true))
		{
			ChatRoomMessage(8, ChannelIndex, nullptr);
		}
	}
}

void AAA2_PlayerController::ServerSpeak(int32 ChannelIndex, FString ChannelPassword)
{
	AVoiceChatRoom* VCR = nullptr;
	int32 Index = 0;
	if (VoiceReplicationInfo == nullptr)
	{
		return;
	}
	VCR = VoiceReplicationInfo->GetChannelAt(ChannelIndex);
	if (VCR == nullptr)
	{
		if (VoiceReplicationInfo->bEnableVoiceChat)
		{
			ChatRoomMessage(0, ChannelIndex, nullptr);
		}
		else
		{
			ChatRoomMessage(15, ChannelIndex, nullptr);
		}
		return;
	}
	if (!VCR->IsMember(PlayerReplicationInfo,false))
	{
		if (ServerJoinVoiceChannel(ChannelIndex, ChannelPassword) != EJoinChatResult::JCR_Success)
		{
			return;
		}
	}
	Index = -1;
	if (ActiveRoom == VCR)
	{
		ChatRoomMessage(10, ChannelIndex,nullptr);
		//Log(PlayerReplicationInfo->PlayerName @ "no longer speaking on " + VCR->GetTitle(), "VoiceChat");
		ActiveRoom = nullptr;
		ClientSetActiveRoom(-1);
	}
	else
	{
		ActiveRoom = VCR;
		//Log(PlayerReplicationInfo->PlayerName @ "speaking on" @ VCR->GetTitle(), "VoiceChat");
		ChatRoomMessage(9, ChannelIndex,nullptr);
		ClientSetActiveRoom(VCR->ChannelIndex);
		Index = VCR->ChannelIndex;
	}
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo->ActiveChannel = Index;
	}
}

void AAA2_PlayerController::ServerSetChatPassword(FString NewPassword)
{
	ChatPassword = NewPassword;
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo->SetChatPassword(NewPassword);
	}
}

void AAA2_PlayerController::ServerChangeVoiceChatMode(bool bEnable)
{
	if (VoiceReplicationInfo == nullptr)
	{
		return;
	}
	bVoiceChatEnabled = bEnable;
	if (bVoiceChatEnabled)
	{
		if (VoiceReplicationInfo->bEnableVoiceChat)
		{
			VoiceReplicationInfo->AddVoiceChatter(PlayerReplicationInfo);
		}
		else
		{
			ChatRoomMessage(15, -1,nullptr);
		}
	}
	else
	{
		VoiceReplicationInfo->RemoveVoiceChatter(PlayerReplicationInfo);
	}
}

void AAA2_PlayerController::ClientSetActiveRoom(int32 ChannelIndex)
{
	if ((VoiceReplicationInfo == nullptr) || (!bVoiceChatEnabled))
	{
		return;
	}
	if (ActiveRoom != nullptr)
	{
		LastActiveChannel = ActiveRoom->GetTitle();
	}
	else
	{
		LastActiveChannel = "";
	}
	ActiveRoom = VoiceReplicationInfo->GetChannelAt(ChannelIndex);
}

void AAA2_PlayerController::ChatDebug()
{
	ChatManager->ChatDebug();
	ServerChatDebug();
}

void AAA2_PlayerController::ServerChatDebug()
{
}

void AAA2_PlayerController::ServerRequestBanInfo(int32 PlayerID)
{
}

void AAA2_PlayerController::ServerChatRestriction(int32 PlayerID, uint8 Type)
{
	AAA2_PlayerState* PRI = nullptr;
	int32 i = 0;
	/*
	Log("ServerChatRestriction PlayerID:" + FString::FromInt(PlayerID) @ "Type:" + FString::FromInt(Type), "ChatManager");
	if ((ChatManager == nullptr) || (GameReplicationInfo == nullptr))
	{
		return;
	}
	i = 0;
	if (i < GameReplicationInfo->PRIArray.Num())
	{
		Log("ServerChatRestriction checking GRI.PRIArray[" + FString::FromInt(i) + "].PlayerID:" + FString::FromInt(GameReplicationInfo->PRIArray[i].PlayerID), "ChatManager");
		if ((GameReplicationInfo->PRIArray[i] != nullptr) && (GameReplicationInfo->PRIArray[i].PlayerID == PlayerID))
		{
			PRI = GameReplicationInfo->PRIArray[i];
		}
		else
		{
			i++;
		}
	}
	Log("ServerChatRestriction PRI:" + FString::FromInt(PRI) @ "PRI.Owner" + FString::FromInt(PRI.Owner), "ChatManager");
	if ((PRI == nullptr) || (Cast<APlayerController>(PRI.Owner) == nullptr))
	{
		return;
	}
	ChatManager.SetRestriction(Cast<APlayerController>(GameReplicationInfo->PRIArray[i].Owner).GetPlayerIDHash(), Type);
	if (((bool((Type & 8)) && (PlayerReplicationInfo != nullptr)) && (PlayerReplicationInfo->PrivateChatRoom != nullptr)) && PlayerReplicationInfo->PrivateChatRoom.IsMember(PRI, true))
	{
		ChatRoomMessage(13, -1, PRI);
		PlayerReplicationInfo->PrivateChatRoom.RemoveMember(PRI);
	}
	*/
}

void AAA2_PlayerController::GainedChild(AActor* Other)
{
	/*
	Super::GainedChild(Other);
	if (Cast<AVotingReplicationInfoBase>(Other) != nullptr)
	{
		VoteReplicationInfo = VotingReplicationInfoBase(Other);
	}
	*/
}

void AAA2_PlayerController::LostChild(AActor* Other)
{
	/*
	Super::LostChild(Other);
	if (Cast<AVotingReplicationInfoBase>(Other) != nullptr)
	{
		VoteReplicationInfo = nullptr;
	}
	*/
}

void AAA2_PlayerController::ShowVoteMenu()
{
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (VoteReplicationInfo != nullptr)) && VoteReplicationInfo.MapVoteEnabled())
	{
		Player.GUIController.OpenMenu(Player.GUIController.GetPropertyText("MapVotingMenu"));
	}
	*/
}

void AAA2_PlayerController::TelnetMessage(AAA2_PlayerState* PRI,FString S, FName Type)
{
	FColor Color = FColor(0, 0, 0, 0);
	Color.R = 255;
	Color.G = 0;
	Color.B = 0;
	Color.A = 255;
	//Player.Console.Message(S, 20, Color);
	if (myHUD != nullptr)
	{
		//myHUD->Message(PRI, S, Type);
	}
}

void AAA2_PlayerController::NotifyPlayerOfMedicStatus()
{
	if ((myHUD != nullptr) && bNotifyMedicAtRoundStart)
	{
		//myHUD->DisplayCenteredMessage(3, "You are the medic this round");
	}
}

UAA2_CheatManager* AAA2_PlayerController::DebugGetCheatManager()
{
	/*
	if ((!Level.bCoOpGame) && (GetNetMode() != ENetMode::NM_Standalone))
	{
		return nullptr;
	}
	if (CheatManager == nullptr)
	{
		CheatManager = new (this) classCheatClass;
	}
	*/
	return CheatManager;
}

void AAA2_PlayerController::OpenDemoControls()
{
	/*
	if (bDemoOwner)
	{
		ClientOpenMenu(DemoMenuClass);
	}
	*/
}
