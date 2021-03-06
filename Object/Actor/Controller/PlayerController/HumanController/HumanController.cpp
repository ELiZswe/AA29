// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Containers/UnrealString.h"
#include "Engine/World.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/CallForSupport/CallForSupport.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"
#include "AA29/AA2_GameState.h"
#include "AA29/AA2_GameMode.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MissionCompleteRequestAdapter/MissionCompleteRequestAdapter.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "GameFramework/PlayerController.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRifleman.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/ScoreBoard/AGP_Scoreboard/AGP_Scoreboard.h"
#include "AA29/Object/Actor/AGP_USMortarTeamFDC/AGP_USMortarTeamFDC.h"
#include "AA29/Object/Actor/Info/AGP_ServerInfo/AGP_ServerInfo.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/FixedWeaponAttachment/FixedWeaponAttachment.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/CameraEffect/CamEffect_FlashBang/CamEffect_FlashBang.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCommoInfo/HUDCommoInfo.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/Object/Actor/AttachmentHandler/AttachmentHandler.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/Keypoint/Marker/CubeMapMaker/CubeMapMaker.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCrosshair/HUDCrosshair.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDPlayerID/HUDPlayerID.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDWeaponTarget/HUDWeaponTarget.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/UpdateTrustAndExperienceRequestAdapter/UpdateTrustAndExperienceRequestA.h"
#include "AA29/Object/Actor/Info/AccessControl/AccessControl.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeServerRequestAdapter/AuthorizeServerRequestAdapter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeUserRequestAdapter/AuthorizeUserRequestAdapter.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoShout/CommoShout.h"
#include "AA29/Object/Actor/DBMBS/DBMBS.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/GetNewsRequestAdapter/GetNewsRequestAdapter.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/CheatManager/Cheater/Cheater.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_CarryObjective/AGP_CarryObjective.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SHelicopter/blackhawk/blackhawk.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/BMP1_APC/BMP1_APC.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/BTR80APC/BTR80APC.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassenger.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_civilian.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_SpecialForces/NPC_SpecialForces.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/T62A/T62A.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_AT4_Rocket/Weapon_AT4_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_BDM_Rocket/Weapon_BDM_Rocket.h"
#include "Particles/Emitter.h"

AHumanController::AHumanController()
{
	afpTimePlayedPercent.SetNum(10);
	afpSkillPerRound.SetNum(10);
	SelectedWeaponSlot.SetNum(2);
	asAuthMissionData.SetNum(26);
	
	bAutoSwapFromGrenade				= true;
	bAutoWalkZoom						= true;
	bUseOverlayScopes					= true;
	_tPainOverlay						= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/fx_overlays_pain.fx_overlays_pain"), NULL, LOAD_None, NULL),
	BoundaryEvent						= "Boundary";
	AutoTraceFrequency					= 3;
	//DesiredTeamClassName				= "AGP_Characters.ClassRifleman"
	DesiredTeamClassName				= "ClassRifleman";
	FlashBangDistortion					= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisoriented.WeaponsUS_Grenades_TTSDisoriented"), NULL, LOAD_None, NULL),
	FlashBangDistortionFade				= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisorientedFade.WeaponsUS_Grenades_TTSDisorientedFade"), NULL, LOAD_None, NULL),
	GrenadeDistortion					= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisoriented.WeaponsUS_Grenades_TTSDisoriented"), NULL, LOAD_None, NULL),
	GrenadeDistortionFade				= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_TTSDisorientedFade.WeaponsUS_Grenades_TTSDisorientedFade"), NULL, LOAD_None, NULL),
	ScopeDetail							= EScopeDetail::SCOPEDETAIL_Low;
	sSavedUserName						= "UserName";
	sSavedUserPassword					= "UserPassword";
	bDontRememberUsernameAndPassword	= true;
	NeedUserPassword					= "You must enter a password for this username";
	WrongUserPassword					= "The password is incorrect for this username";
	NoUserRecord						= "The username you have entered has not been registered.";
	UserIsBanned						= "Sorry, you have been banned from this server";
	ResponseTimeOut						= "Communication Error: Please try again.";
	ServerNotRegistered					= "This server is not registered as an authorized server";
	BetaServer							= "You are not authorized to play on this beta server";
	BadHonorUpdateValue					= "Could not update your honor rating.";
	fMsgDuration						= 10;
	HUDAlpha							= 200;
	HUDColor							= 100;
	bWaitingForPRI						= true;
	bWaitingForVRI						= true;
	RadarZoom							= 2;
	bRadarShowPlayerInfoNames			= true;
	bRadarShowPlayerInfoElevation		= true;
	NoSuicideVelocity					= 50;
	iSpotterPolarRangeSetting			= 600;
	sndESSFoundItemAcknowledgement		= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2AcknowledgeFoundItem.S2AcknowledgeFoundItem"), NULL, LOAD_None, NULL),
	bShowDelayedStartWarningMessage		= true;

	//CheatClass = UCheater::StaticClass()
	//bHumanAim = true;
	//MinHitWall = -0.5;
	//CollisionRadius = 10;
	//CollisionHeight = 10;
	//bNetNotify = true;
	WM_Slot.SetNum(6);
}

/*
State ValidatePB extends BaseSpectating
{
	exec Function Fire(float F)
	{
	}
	exec Function AltFire(float F)
	{
	}
	exec Function Jump(float F)
	{
	}
	exec Function Say(FString Msg)
	{
	}
	exec Function DevSay(FString Msg)
	{
	}
	exec Function TeamSay(FString Msg)
	{
	}
	exec Function SelectTeam(FString Param2)
	{
	}
	exec Function SelectClass(FString Param2)
	{
	}
	exec Function ShowScores(FString Param2)
	{
	}
	exec Function ShowObjectives(FString Param2)
	{
	}
	exec Function votekick(FString Input)
	{
	}
	exec Function ShowMenu()
	{
		ClientCloseMenu(true);
		ClientOpenMenu("AGP_Interface.AAMainMenu");
	}
	exec Function OLD_SelectClass(FString Param2)
	{
	}
	exec Function ShowServerInfo(FString Param2)
	{
	}
	exec Function ShowTournament(FString Param2)
	{
	}
	exec Function ShowSurvey(FString Param2)
	{
	}
	Function ClientTeamSelectMenu(bool bOpen)
	{
	}
	Function BeginState()
	{
		DoFade(true,true,3);
		if ((GetWorld()->GetNetMode() == NM_Client) && (IsPBEnabled() == 1))
		{
			ClientCloseMenu(true);
			DebugLog(DEBUG_Auth,"User \"" + UserName + "\" validating PB");
			iUNC=CalculateUserNameChecksum(UserName);
		}
		DebugLog(DEBUG_Auth,"HumanController::ValidatePB::BeginState() entered for player " + UserName + " PB Status: " + GetPBConnectStatus());
		if ((GetWorld()->GetNetMode() == NM_Client) && ((GetPBConnectStatus() != "") || (IsPBEnabled() == 0)))
		{
			ChangeState("PBNotEnabled");
			return;
		}
		iPBWaitTimer=0;
		iPBWaitMessageIndex=0;
		iPBUpdatePercentage=0;
		Super::BeginState();
		SetStartupStage(1);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (bExploreTheArmyServer)
			{
				UserName=UserName + "|" + sETAUserSelectedSurName + "|" + sETAUserSelectedNickName;
			}
			else
			{
				Log(string(this) + "*** ETA Server, Developer or beta joining: " + UserName);
				ServerSetUserName(UserName);
			}
			ServerSetViewPreference(2);
			if (bExploreTheArmyServer)
			{
				AnnounceNewPlayerJoiningServer("A new player has entered the server and is waiting for PB authorization.");
			}
			else
			{
				AnnounceNewPlayerJoiningServer(UserName + " has entered the server and is waiting for PB authorization.");
			}
			DebugLog(DEBUG_Auth,"Starting Timer on Client");
			SetTimer(1,true);
		}
		else
		{
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				ClientMessage("Waiting for PB to authenticate/update...");
			}
		}
	}
	Function Timer()
	{
		int32 iSeconds = 0;
		int32 iEstimatedTimeLeft = 0;
		FString sElapsedTime = "";
		if (! bPBChecked)
		{
			if (iPBWaitTimer == 0)
			{
				ServerNextViewTarget(ViewPreference,false,true);
			}
			if ((float(iPBWaitTimer) % float(10)) == 0)
			{
				ServerCanPlayerJoin(UserName);
			}
			if (((float(iPBWaitTimer) % float(15)) == 0) && (iPBWaitTimer != 420))
			{
				DebugLog(DEBUG_Multi,"PB Update: WaitTimer: " + FString::FromInt(iPBWaitTimer) + "  Percent complete: " + FString::FromInt(iPBUpdatePercentage));
				if ((iPBUpdatePercentage > 0) && (iPBWaitTimer > 0))
				{
					iEstimatedTimeLeft=int((float(int((float(iPBWaitTimer) / float(iPBUpdatePercentage)))) * (100 - float(iPBUpdatePercentage))));
					sElapsedTime=string((iEstimatedTimeLeft / 60)) + ":";
					if ((float(iEstimatedTimeLeft) % float(60)) < float(10))
					{
						sElapsedTime=sElapsedTime + "0";
					}
					iSeconds=int((float(iEstimatedTimeLeft) % float(60)));
					sElapsedTime="|PB is " + FString::FromInt(iPBUpdatePercentage) + "% Updated, Estimated Time Left: " + sElapsedTime + FString::FromInt(iSeconds);
				}
				if (iPBWaitMessageIndex == 0)
				{
					if (iPBWaitTimer == 0)
					{
						NotifyPBAuthMessage("PunkBuster is working to authenticate and/or update your PunkBuster software.|Updates usually take 2 to 4 minutes.");
					}
					else
					{
						NotifyPBAuthMessage("PunkBuster is still working to authenticate/update your PunkBuster software." + sElapsedTime);
					}
					iPBWaitMessageIndex ++;
				}
				else
				{
					if (iPBWaitMessageIndex == 1)
					{
						ServerNextViewTarget(ViewPreference);
						iPBWaitMessageIndex ++;
					}
					else
					{
						if (iPBWaitMessageIndex == 2)
						{
							if (PlatformIsWindows())
							{
								NotifyPBAuthMessage("You can manually update PB by running 'pbsetup.exe' located in the 'America's Army\\System' folder." + sElapsedTime);
							}
							else
							{
								if (PlatformIsUnix())
								{
									NotifyPBAuthMessage("You can manually update PB by running pbweb.x86 in the game's System/pb' folder." + sElapsedTime);
								}
								else
								{
									NotifyPBAuthMessage("PunkBuster is still working to authenticate/update your PunkBuster software." + sElapsedTime);
								}
							}
							iPBWaitMessageIndex ++;
						}
						else
						{
							if (iPBWaitMessageIndex == 3)
							{
								ServerNextViewTarget(ViewPreference);
								iPBWaitMessageIndex ++;
							}
							else
							{
								if (iPBWaitMessageIndex == 4)
								{
									NotifyPBAuthMessage("You can see the progress of the PunkBuster update in the console text area." + sElapsedTime);
									iPBWaitMessageIndex ++;
								}
								else
								{
									if (iPBWaitMessageIndex == 5)
									{
										ServerNextViewTarget(ViewPreference);
										iPBWaitMessageIndex ++;
									}
									else
									{
										if (iPBWaitMessageIndex == 6)
										{
											NotifyPBAuthMessage("You can pan the view around using your mouse while you wait." + sElapsedTime);
											iPBWaitMessageIndex ++;
										}
										else
										{
											if (iPBWaitMessageIndex == 7)
											{
												ServerNextViewTarget(ViewPreference);
												iPBWaitMessageIndex ++;
											}
											else
											{
												if (iPBWaitMessageIndex == 8)
												{
													NotifyPBAuthMessage("PB updates can take up to seven minutes using dial-up or on busy servers." + sElapsedTime);
													iPBWaitMessageIndex ++;
												}
												else
												{
													if (iPBWaitMessageIndex == 9)
													{
														ServerNextViewTarget(ViewPreference);
														iPBWaitMessageIndex ++;
													}
													else
													{
														if (iPBWaitMessageIndex == 10)
														{
															NotifyPBAuthMessage("You can get additional PB support at www.evenbalance.com." + sElapsedTime);
															iPBWaitMessageIndex ++;
														}
														else
														{
															if (iPBWaitMessageIndex == 11)
															{
																ServerNextViewTarget(ViewPreference);
																iPBWaitMessageIndex ++;
															}
															else
															{
																if (iPBWaitMessageIndex == 12)
																{
																	NotifyPBAuthMessage("You can learn more at www.americasarmy.com." + sElapsedTime);
																	iPBWaitMessageIndex ++;
																}
																else
																{
																	if (iPBWaitMessageIndex == 13)
																	{
																		ServerNextViewTarget(ViewPreference);
																		iPBWaitMessageIndex ++;
																	}
																	else
																	{
																		if (iPBWaitMessageIndex == 14)
																		{
																			if (PlatformIsWindows())
																			{
																				NotifyPBAuthMessage("A complete manual is in the 'America's Army\\Help' folder." + sElapsedTime);
																			}
																			else
																			{
																				NotifyPBAuthMessage("A complete manual is in the 'Help' folder inside the game installation." + sElapsedTime);
																			}
																			iPBWaitMessageIndex ++;
																		}
																		else
																		{
																			if (iPBWaitMessageIndex == 15)
																			{
																				ServerNextViewTarget(ViewPreference);
																				iPBWaitMessageIndex=0;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (iPBWaitTimer == 420)
			{
				if (PlatformIsWindows())
				{
					NotifyPBAuthMessage("The automatic PB update service may not be available.|Try 'PBWeb.exe' instead.");
					ClientMessage("Try running 'PBWeb.exe' located in your 'America's Army\\System\\pb' folder.");
				}
				else
				{
					if (PlatformIsMacOS())
					{
						NotifyPBAuthMessage("The automatic PB update service may not be available.");
					}
					else
					{
						if (PlatformIsUnix())
						{
							NotifyPBAuthMessage("The automatic PB update service may not be available.|Try 'System/pb/pbweb.x86' instead.");
							ClientMessage("Try running 'pbweb.x86' located in the game's 'System/pb' folder.");
						}
						else
						{
							NotifyPBAuthMessage("The automatic PB update service may not be available.");
						}
					}
				}
			}
			iPBWaitTimer ++;
		}
		else
		{
			if ((float(iPBWaitTimer) % float(15)) == 0)
			{
				DebugLog(DEBUG_Auth,"ValidatePB::Timer() - PB Checked and Enabled");
				ClientMessage("PB has authenticated and is up to date, checking your account.");
			}
		}
	}
}
*/

/*
State ServerAuthorizePlayer extends BaseSpectating
{
	exec Function Fire(float F)
	{
	}
	exec Function AltFire(float F)
	{
	}
	exec Function Jump(float F)
	{
	}
	exec Function Say(FString Msg)
	{
	}
	exec Function DevSay(FString Msg)
	{
	}
	exec Function TeamSay(FString Msg)
	{
	}
	exec Function votekick(FString Input)
	{
	}
	exec Function SelectTeam(FString Param2)
	{
	}
	exec Function SelectClass(FString Param2)
	{
	}
	exec Function ShowScores(FString Param2)
	{
	}
	exec Function OLD_SelectClass(FString Param2)
	{
	}
	exec Function ShowServerInfo(FString Param2)
	{
	}
	exec Function ShowTournament(FString Param2)
	{
	}
	exec Function ShowSurvey(FString Param2)
	{
	}
	Function ClientTeamSelectMenu(bool bOpen)
	{
	}
	exec Function ShowObjectives(FString Param2)
	{
	}
	Function BeginState()
	{
		FString EPassword = "";
		DoFade(true,true,3);
		DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState() entered for player " + UserName);
		Super::BeginState();
		SetStartupStage(1);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			ServerSetSystemLanguage(ConsoleCommand("GETSYSTEMLANGUAGE"));
			ServerSetUserName(UserName);
			ServerSetViewPreference(2);
		}
		else
		{
			if (GetWorld()->GetNetMode() == NM_DedicatedServer)
			{
				bInitialAuthComplete=false;
				ServerSetViewPreference(2);
			}
		}
		DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState() started for " + UserName);
		if (Level.debugControllerState)
		{
			DebugLog(DEBUG_Auth,string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState()	" + FString::FromInt(StartupStage));
		if (! Level.IsServer())
		{
			DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState() client-side for user " + UserName);
			EPassword=FLoad(UserPassword);
			if (bExploreTheArmyServer)
			{
				UserName=UserName + "|" + sETAUserSelectedSurName + "|" + sETAUserSelectedNickName;
			}
			ServerRequestAuthorization(UserName,EPassword,LANPlayerName);
			iUNC=CalculateUserNameChecksum(UserName);
		}
		else
		{
			DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState() server-side");
			SetStartupStage(1);
			if (! Level.Game.IsRequireAuthorization())
			{
				DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer::BeginState() not authorized, bypassing auth process");
				ClientMessage("Server is not running in authorized mode.");
				bInitialAuthComplete=true;
				EnableStateChange(true);
				ClientEnableStateChange(true);
				ChangeState("UnauthorizedJoinComplete");
				if (((! PlayerReplicationInfo.bAdmin) || (! PlayerReplicationInfo.bOnlySpectator)) || TournamentIsTournament())
				{
					if (! Level.IsExploreTheArmyServer())
					{
						AnnounceNewPlayerJoiningServer(UserName + " has successfully joined the server.");
					}
				}
				SimulateTrainingComplete();
				ClientSimulateTrainingComplete();
				ReadyForFinishPostLogin();
			}
			else
			{
				SetTimer(0.05,false);
				if (! Level.IsExploreTheArmyServer())
				{
					NotifyAuthWaiting(true);
				}
			}
		}
	}
	Function Timer()
	{
		EnableStateChange(false);
		ClientEnableStateChange(false);
	}
	Function ServerAuthorizeUserAuthorizeComplete(int32 Code, PlayerController.AuthJacket Jacket)
	{
		FString sClientMessage = "";
		int32 HonorCheck = 0;
		DebugLog(DEBUG_Auth,"HumanController:Authorizing:ServerAuthorizerUserAuthorizeComplete for " + UserName + ": " @ FString::FromInt(Code) @ AuthJacketToString(Jacket));
		switch(Code)
		{
			case 1:
			NotifyAuthWaiting(false);
			SetFromAuthJacket(Jacket);
			VerifyJacket();
			SendAuthJacketToClient(Jacket);
			if (! Level.IsExploreTheArmyServer())
			{
				HonorCheck=Level.Game.CheckHonor(this);
			}
			if (iCompleted[1] == 15)
			{
				PlayerReplicationInfo.bQualifiedBCT=true;
				break;
			}
			Log("Player " + UserName + " using instant action rules to join server");
			iCompleted[0]=833;
			iCompleted[1]=15;
			iCompleted[2]=3;
			iCompleted[6]=3;
			iCompleted[8]=3;
			PlayerReplicationInfo.bQualifiedViaInstantAction=true;
			PlayerReplicationInfo.bQualifiedBCT=false;
		}
		if ((Level.IsExploreTheArmyServer() && (! bETATrackingUsed)) && ((PlayerReplicationInfo.GetGroup() != 1) && (PlayerReplicationInfo.GetGroup() != 4)))
		{
			sClientMessage="You must select an Explorer Nickname and Surname to play on this server using the 'Instant Action' option.";
			Code=-22;
		}
		else
		{
			if (! Level.CanPlayerPlayMission(this))
			{
				DebugLog(DEBUG_Auth,"HumanController::BaseSpectating::ServerAuthorizerUserAuthorizeComplete() Not qualified");
				if (PlayerReplicationInfo.bQualifiedViaInstantAction)
				{
					if (Level.iTour == 12)
					{
						sClientMessage="You must complete Basic Combat Training and Special Forces Training to play this mission.";
					}
					else
					{
						sClientMessage="You must complete more Basic Combat Training to play this mission.";
					}
				}
				else
				{
					sClientMessage="Player is not qualified for this mission.";
				}
				Code=-20;
			}
			else
			{
				if (! Level.Game.CheckGroup(this))
				{
					DebugLog(DEBUG_Auth,"HumanController::BaseSpectating::ServerAuthorizerUserAuthorizeComplete()	Group not allowed " + FString::FromInt(PlayerReplicationInfo.GetGroup()));
					sClientMessage="Player's Group (" + FString::FromInt(PlayerReplicationInfo.GetGroup()) + ") is not allowed on this server";
					Code=-22;
				}
				else
				{
					if (HonorCheck != 0)
					{
						DebugLog(DEBUG_Auth,"HumanController::BaseSpectating::ServerAuthorizerUserAuthorizeComplete()	Honor out of range " + FString::FromInt(HonorCheck));
						sClientMessage="Player's Honor (" + FString::FromInt(PlayerReplicationInfo.GetHonor()) + ") is too ";
						if (HonorCheck < 0)
						{
							sClientMessage=sClientMessage + "low";
						}
						else
						{
							sClientMessage=sClientMessage + "high";
						}
						sClientMessage=sClientMessage + " for this server [" + FString::FromInt(Level.Game.GetMinHonor()) + "," + FString::FromInt(Level.Game.GetMaxHonor()) + "]";
						Code=-21;
					}
					else
					{
						DebugLog(DEBUG_Auth,"User has authorized, qualified, and is good to go");
						bInitialAuthComplete=true;
						DebugLog(DEBUG_Auth,"Done with ETA work");
						if (PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
						{
							if (TournamentIsTournament())
							{
								Level.Game.TournamentSendMessage(UserName + " logged in as a server administrator.");
							}
						}
						else
						{
							Level.Game.Broadcast(Level.Game,UserName + " has successfully joined the server.");
							LogFileWrite("DevNet","Join succeeded:" + UserName + ":" + GetPlayerNetworkAddress());
						}
						DebugLog(DEBUG_Auth,"HumanController::ServerAuthorizePlayer - Good authorization");
						ClientMessage("Authorization complete");
						DebugLog(DEBUG_Auth,"Updating Auth PRI");
						UpdateAuthRelatedPRI();
						EnableStateChange(true);
						ClientEnableStateChange(true);
						ChangeState("PlayerAuthorizationComplete");
						ClientGotoState("PlayerAuthorizationComplete","None");
						DebugLog(DEBUG_Auth,"Done with auto");
						ReadyForFinishPostLogin();
						return;
					}
				}
			}
		}
		GOTO JL0AA3;
		case -4:
		if (Level.IsLanOnlyServer())
		{
			Log("Authorization failed due to communication failure with Auth Server.  Allowing player in.");
			ClientMessage("Authorization complete");
			EnableStateChange(true);
			ClientEnableStateChange(true);
			ChangeState("PlayerAuthorizationComplete");
			ClientGotoState("PlayerAuthorizationComplete","None");
			ReadyForFinishPostLogin();
			return;
		}
		else
		{
			Log("HumanController::ServerAuthorizePlayer:ServerAuthorizerUserAuthorizeComplete() - failure - auth down.");
			sClientMessage="Auth Server May Be Down.";
		}
		GOTO JL0AA3;
		case -1:
		sClientMessage=WrongUserPassword;
		GOTO JL0AA3;
		case -2:
		sClientMessage=NoUserRecord;
		GOTO JL0AA3;
		case -3:
		sClientMessage=UserIsBanned;
		GOTO JL0AA3;
		case -5:
		sClientMessage=ServerNotRegistered;
		GOTO JL0AA3;
		case -6:
		sClientMessage=BetaServer;
		GOTO JL0AA3;
		case -7:
		DebugLog(DEBUG_Auth,"Calling ClientSetPMessage(" + FString::FromInt(0) + ")");
		ClientSetPMessage(0);
		GOTO JL0AA3;
		case -8:
		sClientMessage=BadHonorUpdateValue;
		GOTO JL0AA3;
		default:
		sClientMessage="Unknown Problem, please try again.";
		GOTO JL0AA3;
JL0AA3:
		ClientMessage(sClientMessage);
		DebugLog(DEBUG_Auth,"HumanController:Authorizing:ServerAuthorizerUserAuthorizeComplete: " + sClientMessage);
		bShowErrorMessageLonger=false;
		DebugLog(DEBUG_Auth,"HumanController:Authorizing:ServerAuthorizerUserAuthorizeComplete: Dropping Player");
		bInitialAuthComplete=true;
		ClientDisconnect(sClientMessage);
		EnableStateChange(true);
		ClientEnableStateChange(true);
		ChangeState("FailedAuthorization");
		ClientGotoState("FailedAuthorization","None");
	}
	Function ReceivedAuthRequest()
	{
		FString s1 = "";
		DBAuth.AuthorizeUserRequestAdapter* Adapter = nullptr;
		FString sTemp = "";
		FString IPAddress = "";
		int32 iPortPos = 0;
		Adapter=Spawn(AAuthorizeUserRequestAdapter::StaticClass(),Self);
		sTemp=GetPlayerNetworkAddress();
		iPortPos=InStr(sTemp,":");
		IPAddress=Left(sTemp,iPortPos);
		s1="847";
		if (Level.IsExploreTheArmyServer())
		{
			if (Len(Level.IsExploreTheArmyAccount(this,UserName,true)) > 0)
			{
				bETATrackingUsed=true;
				Adapter.Request("ETATracking",s1 + "sdk" + FString::FromInt(1),IPAddress,DistributionHistory);
			}
			else
			{
				Adapter.Request(Level.IsExploreTheArmyAccount(this,UserName,false),FUnload(EncryptedPassword),IPAddress,DistributionHistory);
			}
		}
		else
		{
			if (UserName ~= "ETATracking")
			{
				ServerAuthorizeUserAuthorizeComplete(-2);
				return;
			}
			Adapter.Request(UserName,FUnload(EncryptedPassword),IPAddress,DistributionHistory);
		}
		NotifyAuthWaiting(true);
	}
	Function EndState()
	{
		DebugLog(DEBUG_Auth,"HumanController:Authorizing:ServerAuthorizerUserAuthorizeComplete:EndState() for " + UserName + " Auth complete: " + FString::FromInt(bInitialAuthComplete));
	}
	Function ClientGotoState(FName NewState, FName NewLabel)
	{
		if ((! bInitialAuthComplete) && ((((NewState != "UnauthorizedJoinComplete") && (NewState != "AuthorizePlayerAgain")) && (NewState != "PlayerAuthorizationComplete")) && (NewState != "FailedAuthorization")))
		{
			Log("WARNING **********************************");
			Log("Client State changed blocked on request to: " + FString::FromInt(NewState));
			Log("WARNING **********************************");
			return;
		}
		GotoState(NewState,NewLabel);
	}
	Function AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
	{
		ClientMessage(sMsg);
	}
}
*/

/*
State PBNotEnabled
{
	Function BeginState()
	{
		SetTimer(5,false);
		NotifyAdminMessage("PunkBuster must be enabled to play on this server.");
	}
	Function Timer()
	{
		ConsoleCommand("disconnect");
	}
}
*/

/*
State FailedAuthorization
{
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			DebugLog(DEBUG_Auth,string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		SetTimer(10,false);
	}
	Function Timer()
	{
		KickNow();
	}
	Function KickNow()
	{
		Log("User " + UserName + " was removed from server for failed authorization attempt");
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			DebugLog(DEBUG_Auth,"KickNow()");
			ConsoleCommand("Disconnect");
		}
	}
	Function float GetSleepTime()
	{
		if (bShowErrorMessageLonger == true)
		{
			return 60;
		}
		else
		{
			return 5;
		}
	}
}
*/

/*
State AuthorizingUserLocallyThenGetNews extends BaseSpectating
{
	Function BeginState()
	{
		DBAuth.AuthorizeUserRequestAdapter* Adapter = nullptr;
		FString IPAddress = "";
		int32 i = 0;
		for (i=0; i<33; i++)
		{
			iCompleted[i]=0;
		}
		iRifleRangeRating=0;
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo._iTrust=0;
			PlayerReplicationInfo._Experience=0;
		}
		IPAddress=AInternetLink::StaticClass().GetLocalIPAsString();
		EncryptedPassword=FLoad(UserPassword);
		Adapter=Spawn(AAuthorizeUserRequestAdapter::StaticClass(),Self);
		Adapter.RetryCountMax=0;
		ClientRefreshDistributionHistory();
		Adapter.Request(UserName,UserPassword,IPAddress,DistributionHistory);
		SetLoginStatus(1,"Loading Your Account...","");
	}
	Function ClientAuthorizeUserAuthorizeComplete(int32 Code, PlayerController.AuthJacket Jacket)
	{
		DebugLog(DEBUG_Auth,"HumanController:AuthorizingUserLocallyThenGetNews:ClientAuthorizerUserAuthorizeComplete" @ FString::FromInt(Code) @ AuthJacketToString(Jacket));
		switch(Code)
		{
			case 1:
			SetFromAuthJacket(Jacket);
			VerifyJacket();
			SaveJacket();
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD).RefreshTourMissionDisplays();
			}
			ChangeState("AuthGetNewsArticles");
			return;
			case -1:
			SetLoginStatus(0,"Invalid Password","The password you entered did not match the password for this account.");
			ClientMessage(WrongUserPassword);
			break;
			case -2:
			SetLoginStatus(0,"No User Record","The user name you specified could not be located.  You may have mistyped it.");
			ClientMessage(NoUserRecord);
			break;
			case -3:
			SetLoginStatus(2,"User Is Banned","Your account has been banned.  Please visit www.americasarmy.com for support.");
			ClientMessage(UserIsBanned);
			break;
			case -4:
			SetLoginStatus(0,"Err: Check connection","Your Internet connection may be down or the authorization server may be undergoing maintenance.");
			ClientMessage(ResponseTimeOut);
			break;
			case -5:
			SetLoginStatus(0,"Server is not registered","");
			ClientMessage(ServerNotRegistered);
			break;
			case -6:
			SetLoginStatus(0,"Not authorized","You are not authorized to play on this beta server.");
			ClientMessage(BetaServer);
			break;
			default:
			SetLoginStatus(-1,"Error: Unknown","");
			ClientMessage("Error: Unknown");
			break;
		}
		ChangeState("None");
	}
	Function AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
	{
		DebugLog(DEBUG_Auth,"HumanController:AuthorizingUserLocallyThenGetNews:AuthTransmissionErrorCallback" @ FString::FromInt(iReason) @ sMsg @ sShortMsg);
		SetLoginStatus(1,sShortMsg,sMsg);
	}
}
*/

/*
State AuthGetNewsArticles extends BaseSpectating
{
	Function BeginState()
	{
		DBAuth.GetNewsRequestAdapter* Adapter = nullptr;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			Adapter=Spawn(AGetNewsRequestAdapter::StaticClass(),Self);
			SetLoginStatus(1,"Looking for News...","");
			iNewsID=0;
			Adapter.Request(UserName,UserPassword,iNewsID);
			EncryptedPassword="";
		}
	}
	Function ClientNewsAuthorizeComplete(int32 Code, int32 NewsId, FString Line)
	{
		DebugLog(DEBUG_Auth,"HumanController:AuthGetNewsArticles:ClientNewsAuthorizeComplete" @ FString::FromInt(Code) @ "Id:" @ FString::FromInt(NewsId) @ Line[0] @ Line[1] @ Line[2] @ Line[3]);
		switch(Code)
		{
			case 1:
			DebugLog(DEBUG_Auth,"AuthGetNewsArticles::ClientNewsAuthorizeComplete() - good response for news");
			iNewsID=NewsId;
			sNewsLine1=Line[0];
			sNewsLine2=Line[1];
			sNewsLine3=Line[2];
			sNewsLine4=Line[3];
			SetLoginStatus(2,"Transmission Completed","Click to return to the main menu.");
			iAuthClientTransmissionComplete=1;
			ChangeState("None");
			return;
			case -1:
			SetLoginStatus(0,"Invalid Password","The password you entered did not match the password for this account.");
			ClientMessage(WrongUserPassword);
			break;
			case -2:
			SetLoginStatus(0,"No User Record","The user name you specified could not be located.  You may have mistyped it.");
			ClientMessage(NoUserRecord);
			break;
			case -3:
			SetLoginStatus(2,"User Is Banned","Your account has been banned.  Please visit www.americasarmy.com for support.");
			ClientMessage(UserIsBanned);
			break;
			case -4:
			SetLoginStatus(0,"Err: Check connection","Your Internet connection may be down or the authorization server may be undergoing maintenance.");
			ClientMessage(ResponseTimeOut);
			break;
			case -5:
			SetLoginStatus(0,"Server is not registered","");
			ClientMessage(ServerNotRegistered);
			break;
			case -6:
			SetLoginStatus(0,"Not authorized","You are not authorized to play on this beta server.");
			ClientMessage(BetaServer);
			break;
			default:
			SetLoginStatus(-1,"Error: Unknown","");
			ClientMessage("Error: Unknown");
			break;
		}
	}
	Function AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
	{
		ClientMessage(sMsg);
		SetLoginStatus(1,sShortMsg,"");
	}
}
*/

/*
State ClientMissionComplete
{
	Function BeginState()
	{
		DBAuth.MissionCompleteRequestAdapter* Adapter = nullptr;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			SetLoginStatus(1,"Connecting to Your Profile...","");
			if ((((! bMissionPass) || (iTour != Level.GetLevelTour())) || (iMission != Level.GetLevelMission())) && (iTour != 14))
			{
				if (! ((iTour == 19) && (iMission == 0)))
				{
					ChangeState("None");
					DebugLog(DEBUG_Auth,"Level is corrupted.");
					return;
				}
			}
			DebugLog(DEBUG_Auth,string(this) @ "HumanController::ClientMissionComplete::BeginState Calling SendMissionCompleted(" + UserName + "," + UserPassword + "," + FString::FromInt(iTour) + "," + FString::FromInt(iMission) + "," + FString::FromInt(iRifleRangeRating) + ")");
			if ((iTour == 0) && (iMission == 0))
			{
				ResetAuthExtraMissionData();
				AddAuthExtraMissionData(string(iRifleRangeRating));
			}
			Adapter=Spawn(AMissionCompleteRequestAdapter::StaticClass(),Self);
			CopyAuthExtraMissionDataToAdapter(Adapter);
			Adapter.Request(UserName,UserPassword,iTour,iMission,iRifleRangeRating,true,DistributionHistory,AInternetLink::StaticClass().GetLocalIPAsString());
			EncryptedPassword="";
		}
	}
	Function ClientMissionCompleteAuthorizeComplete(int32 Code, PlayerController.AuthJacket Jacket)
	{
		DebugLog(DEBUG_Auth,"HumanController:ClientMissionComplete:ClientMissionCompleteAuthorizeComplete" @ FString::FromInt(Code) @ AuthJacketToString(Jacket));
		switch(Code)
		{
			case 1:
			DebugLog(DEBUG_Auth,"HumanController:ClientMissionComplete:ClientMissionCompleteAuthorizeComplete Tour: " + FString::FromInt(iTour) + " Mission: " + FString::FromInt(iMission));
			DebugLog(DEBUG_Auth,"ClientMissionComplete::ClientMissionCompleteAuthorizeComplete() - good response for news");
			SetFromAuthJacket(Jacket);
			VerifyJacket();
			SaveJacket();
			SetLoginStatus(2,"Transmission Completed","Click to return to the main menu.");
			iAuthClientTransmissionComplete=1;
			if (bDontLockAfterMisionComplete)
			{
				Log("HumanController - Javelin training hack");
				ChangeState("PlayerWalking");
				break;
			}
			ChangeState("None");
		}
		case -1:
		SetLoginStatus(0,"Invalid Password","The password you entered did not match the password for this account.  Make sure you enter your password using the correct upper and lower case letters.");
		ClientMessage(WrongUserPassword);
		GOTO JL0567;
		case -2:
		SetLoginStatus(0,"No User Record","The user name you specified could not be located.  You may have mistyped it.");
		ClientMessage(NoUserRecord);
		GOTO JL0567;
		case -3:
		SetLoginStatus(0,"User Is Banned","Your account has been banned.  Please visit www.americasarmy.com for support.");
		ClientMessage(UserIsBanned);
		GOTO JL0567;
		case -4:
		SetLoginStatus(0,"Err: Check connection","Your Internet connection may be down or the authorization server may be undergoing maintenance.");
		ClientMessage(ResponseTimeOut);
		GOTO JL0567;
		case -5:
		SetLoginStatus(0,"Server is not registered","");
		ClientMessage(ServerNotRegistered);
		GOTO JL0567;
		case -6:
		SetLoginStatus(0,"Not authorized","You are not authorized to play on this beta server");
		ClientMessage(BetaServer);
		GOTO JL0567;
		default:
		Log("Client mission complete update failed: " @ FString::FromInt(Code) @ AuthJacketToString(Jacket));
		SetLoginStatus(-1,"Error: Unknown","");
		ClientMessage("Error: Unknown");
		GOTO JL0567;
JL0567:
		iAuthClientTransmissionComplete=-1;
		DebugLog(DEBUG_Auth,"HumanController.AuthGetNewsArticles.AuthorizeComplete: Dropping player...");
		ChangeState("None");
	}
	Function AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
	{
		ClientMessage(sMsg);
		SetLoginStatus(-1,sShortMsg,"");
	}
}
*/

/*
State PlayerWalking
{
	Function BeginState()
	{
		Super::BeginState();
		pawnPlayersDeadBody=Pawn;
		if ((GetNetMode() != ENetMode::NM_Standalone) && (bAction == 0))
		{
			LockPlayer(false,false);
		}
		if ((Pawn != nullptr) && (PlayerReplicationInfo != nullptr))
		{
			Pawn.OwnerName=PlayerReplicationInfo.PlayerName;
		}
	}
	Function PlayerTick(float DeltaTime)
	{
		Global.BA(DeltaTime);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (bBehindView && (! CanBehindView()))
			{
				ClientSetBehindView(false);
			}
		}
	}
}
*/

/*
State PlayerRolling extends PlayerWalking
{
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		return false;
	}
	simulated Function bool ClientRejectStateTransition(FName NewState)
	{
		return (NewState == "PlayerCrawling");
	}
	Function Vector CalcAcceleration(Vector X, Vector Y, Vector Z, Rotator& ViewRotation)
	{
		FVector Accel = FVector(0,0,0);
		GetAxes(Pawn.Rotation,X,Y,Z);
		Accel=((float(24000) * Y) * float(Pawn.iRollDirection));
		Accel.Z=0;
		return Accel;
	}
	Function UpdateRotation(float DeltaTime, float maxPitch)
	{
	}
	Function ProcessMove(float DeltaTime, Vector NewAccel, Actor.EDoubleClickDir DoubleClickMove, Rotator DeltaRot)
	{
		(Pawn.fRollTime -= DeltaTime);
		DoubleClickMove=0;
		Super::ProcessMove(DeltaTime,NewAccel,DoubleClickMove,DeltaRot);
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
		if (Pawn.bIsProne)
		{
			GetAxes(Pawn.Rotation,X,Y,Z);
			NewAccel=((float(24000) * Y) * float(Pawn.iRollDirection));
		}
		else
		{
			return;
		}
		ViewRotation=Rotation;
		SetActorRotation(ViewRotation);
		OldRotation=Rotation;
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,DoubleClickMove,(OldRotation - Rotation));
		}
		bPressedJump=bSaveJump;
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		ChangeActionStatus(0);
		Pawn.fRollTime=Pawn.Default.fRollTime;
		Pawn.GroundSpeed=(Pawn.fHCrawlSpeed * 2.5);
		if (Pawn.iRollDirection == Pawn.-1)
		{
			Pawn.Roll3p(2);
		}
		else
		{
			Pawn.Roll3p(1);
		}
	}
}
*/

/*
State PlayerParachuting
{
	Function ServerAction(AActor* Other)
	{
		if (CanTakeAction())
		{
			Pawn.FlareParachute();
		}
	}
	simulated Function int32 GetTraceDistance()
	{
		return int((float(Pawn.GetShortTraceDistance()) * 0.75));
	}
	simulated Function bool CanSwapHands()
	{
		return false;
	}
	Function Vector CalcAcceleration(Vector X, Vector Y, Vector Z, Rotator& ViewRotation)
	{
		FVector Accel = FVector(0,0,0);
		Accel=((aStrafe * Y) + (aForward * X));
		CurrentForward=aForward;
		CurrentStrafe=aStrafe;
		return Accel;
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector NewAccel = FVector(0,0,0);
		FRotator OldRotation = FRotator(0,0,0);
		FRotator ViewRotation = FRotator(0,0,0);
		FRotator update = FRotator(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		ViewRotation=Rotation;
		NewAccel=CalcAcceleration(X,Y,Z,ViewRotation);
		update=(Pawn.rParaStrafeRot * (Normal(NewAccel) Dot Y));
		Pawn.SetRotation((Pawn.Rotation + update));
		SetActorRotation((ViewRotation + update));
		OldRotation=Rotation;
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,NewAccel,0,(OldRotation - Rotation));
		}
		else
		{
			ProcessMove(DeltaTime,NewAccel,0,(OldRotation - Rotation));
		}
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
			Log("(Pawn == " + FString::FromInt(Pawn) + ")");
		}
		if (Pawn != nullptr)
		{
			Pawn.SetPhysics(PHYS_Parachute);
			Pawn.Parachute3p(4);
			Pawn.AccelRate=Pawn.fParaAccelRate;
			Pawn.AirControl=0.15;
			Pawn.AirSpeed=400;
			Pawn.bWantsToSprint=false;
			Pawn.ChangeAnimation();
		}
		DoubleClickDir=0;
		bPressedJump=false;
		GroundPitch=0;
	}
	Function EndState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "HumanController::EndState() - in state" @ FString::FromInt(GetStateName()));
			Log("(Pawn == " + FString::FromInt(Pawn) + ")");
		}
		if (Pawn != nullptr)
		{
			Pawn.SetPhysics(PHYS_Walking);
			Pawn.AirControl=Pawn.Default.AirControl;
			Pawn.AirSpeed=Pawn.Default.AirSpeed;
			switch(Pawn.FullBodyAnim)
			{
				case 4:
				case 3:
				Pawn.FullBodyAnim=0;
				default:
			}
		}
	}
}
*/

/*
State PlayerMantle extends PlayerFlying
{
	exec Function Crouching()
	{
	}
	exec Function Crawling()
	{
	}
	exec Function Stand()
	{
	}
	exec Function Crouch()
	{
	}
	exec Function Crawl()
	{
	}
	Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		AAGP_Pawn* p = nullptr;
		p=Cast<AAGP_Pawn>(Pawn);
		GetAxes(Rotation,X,Y,Z);
		Pawn.Acceleration=(p.fMantleSpeed * FVector(0,0,1));
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
	Function ProcessMove(float DeltaTime, Vector NewAccel, Actor.EDoubleClickDir DoubleClickMove, Rotator DeltaRot)
	{
		float Height = 0;
		float PawnRotDotAccel = 0;
		float UpDotAccel = 0;
		AAGP_Pawn* p = nullptr;
		p=Cast<AAGP_Pawn>(Pawn);
		if (Pawn != nullptr)
		{
			Pawn.Acceleration=NewAccel;
		}
		PawnRotDotAccel=( Vector(Pawn.Rotation) Dot NewAccel);
		UpDotAccel=(FVector(0,0,1) Dot NewAccel);
		Height=(p.vMantlePoint.Z - p.Location.Z);
		if (Level.debugMantle)
		{
			Log("Vel" @ FString::FromInt(Pawn.Velocity) @ "Accel" @ FString::FromInt(NewAccel) @ "Jumped" @ FString::FromInt(bPressedJump) @ "Not Forward" @ FString::FromInt((PawnRotDotAccel <= 0)) @ "Not Up" @ FString::FromInt((UpDotAccel <= 0)));
		}
		if ((bPressedJump || ((PawnRotDotAccel <= 0) && (UpDotAccel <= 0))) || (Height > (p.fMaxGrabHeight - 1)))
		{
			p.EndMantle(0);
			if (Level.debugMantle)
			{
				Log("END MANTLE - CANCELED");
			}
		}
		else
		{
			if (((Height + p.CollisionHeight) + float(12)) < 0)
			{
				p.EndMantle(p.iMantleEndPosture);
				if (Level.debugMantle)
				{
					Log("END MANTLE - COMPLETED");
				}
			}
		}
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		Pawn.AccelRate=2048;
		Pawn.Velocity=FVector(0,0,0);
		Pawn.Acceleration=FVector(0,0,0);
	}
}
*/

/*
State Dead
{
	exec Function AltFire(float F)
	{
	}
	exec Function Jump(float F)
	{
	}
	exec Function Reload()
	{
	}
	exec Function FixJam()
	{
	}
	exec Function SwapHands()
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function binoculars()
	{
	}
	exec Function Zoom()
	{
	}
	Function Action()
	{
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Spec,string(this) @ "HumanController::Dead::BeginState() entered");
		DebugLog(DEBUG_Spec,string(this) @ "HumanController::Dead::BeginState() entered for " + PlayerReplicationInfo.PlayerName);
		DebugLog(DEBUG_Spec,string(this) @ "HumanController::Dead::BeginState() Pawn is " + FString::FromInt(pawnPlayersDeadBody));
		DebugLog(DEBUG_Spec,"HumanController::Dead::BeginState() - last state: " + FString::FromInt(GetLastStateName()));
		if ((GetLastStateName() == "Spectating") || (GetLastStateName() == "Dead"))
		{
			DebugLog(DEBUG_Spec,"Returning to DEAD from spectating - that makes no sense");
			SetStartupStage(9);
			ChangeState("Spectating");
			ServerChangeToSpectatingState();
			return;
		}
		if (Pawn != nullptr)
		{
			Pawn.OwnerName=PlayerReplicationInfo.PlayerName;
		}
		Super::BeginState();
		CleanUp();
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (! Level.IsMILES())
			{
				DoFade(false,true,4);
			}
			if (! Level.IsMILES())
			{
				SetTimer(5,false);
			}
			else
			{
				SetTimer(8,false);
			}
		}
	}
	Function Timer()
	{
		if (TournamentIsTournament())
		{
			ViewTargetActor=nullptr;
			ServerNextViewTarget(1,false,false,true);
			DoFade(true,true,1.5);
			ServerChangeToSpectatingState();
			ChangeState("Spectating");
			return;
		}
		DoFade(true,true,1.5);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (pawnPlayersDeadBody != nullptr)
			{
				DebugLog(DEBUG_Spec,"Setting view to dead pawn");
				ServerSetViewTarget(pawnPlayersDeadBody);
				SetActorRotation(pawnPlayersDeadBody.Rotation);
				bBehindView=true;
			}
			else
			{
				DebugLog(DEBUG_Spec,"No dead pawn found, switching to spectating mode: " + FString::FromInt(pawnPlayersDeadBody));
				ViewTargetActor=nullptr;
				ServerNextViewTarget(1,false,false,true);
				ServerChangeToSpectatingState();
				ChangeState("Spectating");
			}
		}
	}
	simulated Function PlayerMove(float DeltaTime)
	{
		Acceleration=FVector(0,0,0);
		Velocity=FVector(0,0,0);
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
	}
	exec Function Fire(float F)
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			DebugLog(DEBUG_Spec,"HumanController::SpectateDeadBody::Fire() Requesting spectating state change");
			ServerChangeToSpectatingState();
			ChangeState("Spectating");
		}
	}
	Function EndState()
	{
		DoFade(true,true,0);
		DebugLog(DEBUG_Spec,string(this) @ "HumanController::Dead::EndState() entered");
		Super::EndState();
	}
	Event PlayerCalcView(AActor*& ViewActor, Vector& CameraLocation, Rotator& CameraRotation)
	{
		Super::PlayerCalcView(ViewActor,CameraLocation,CameraRotation);
		if (((CameraLocation.X == 0) && (CameraLocation.Y == 0)) && (CameraLocation.Z == 0))
		{
			DebugLog(DEBUG_Spec,"bumping camera up higher");
			ViewActor=Level.ViewpointList;
			CameraLocation=Level.ViewpointList.Location;
			(CameraLocation.Z += float(50));
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
		DebugLog(DEBUG_Spec,"Find good death scene view");
		ViewRotation=Rotation;
		ViewRotation.Pitch=56000;
		tries=0;
		besttry=0;
		bestDist=0;
		startYaw=ViewRotation.Yaw;
		for (tries=0; tries<16; tries++)
		{
			cameraLoc=ViewTarget.Location;
			SetActorRotation(ViewRotation);
			PlayerCalcView(ViewActor,cameraLoc,cameraRot);
			newdist=VSize((cameraLoc - ViewTarget.Location));
			if (newdist > bestDist)
			{
				bestDist=newdist;
				besttry=tries;
			}
			ViewRotation.Yaw += 4096;
			DebugLog(DEBUG_Spec,"Trying view location Yaw for body of " + FString::FromInt(ViewRotation.Yaw));
		}
		ViewRotation.Yaw=(startYaw + (besttry * 4096));
		SetActorRotation(ViewRotation);
	}
}
*/

/*
State Spectating
{
	exec Function Reload()
	{
	}
	exec Function SwapHands()
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function binoculars()
	{
	}
	exec Function CommoCycle()
	{
	}
	Function CommoMode(Pawn.ECommoType Type)
	{
	}
	simulated Function PlayerMove(float DeltaTime)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		GetAxes(Rotation,X,Y,Z);
		Acceleration=FVector(0,0,0);
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
	exec Function FixJam()
	{
		fpLastViewChange=GetWorld()->GetTimeSeconds();
	}
	exec Function NV()
	{
		SetSpecNV((! bSpecNightVision));
	}
	Function ClientSetViewTarget(AActor* Target)
	{
		Global.leader_1(Target);
	}
	simulated Function SetSpecNV(bool bNewSpecNV)
	{
		bSpecNightVision=bNewSpecNV;
		if (bSpecNightVision)
		{
			switch(PlayerReplicationInfo->Team->TeamIndex)
			{
				case 0:
				bSpecNightVision=Level.bTeam0HasNVGs;
				break;
				case 1:
				bSpecNightVision=Level.bTeam1HasNVGs;
				break;
				default:
				bSpecNightVision=(Level.bTeam0HasNVGs && Level.bTeam1HasNVGs);
				break;
			}
		}
		SetNightVision(bSpecNightVision);
	}
	simulated Function RenderOverlays_Stage1(UCanvas* Canvas)
	{
		RenderOverlays(Canvas,true);
	}
	simulated Function RenderOverlays_Stage2(UCanvas* Canvas)
	{
		UTexture* NightVisionTexture = nullptr;
		int32 RemainingTime = 0;
		int32 minutes = 0;
		int32 Seconds = 0;
		float XL = 0;
		float YL = 0;
		bool bFlash = false;
		float fpYScale = 0;
		float fpXScale = 0;
		AAGP_HUD* agpMyHUD = nullptr;
		agpMyHUD=AGP_HUD(MyHUD);
		RenderOverlays(Canvas,false);
		if (bSpecNightVision)
		{
			Canvas.SetPos(0,0);
			Canvas.Style = ERenderStyle.STY_TrueModulated;
			NightVisionTexture=Texture(DynamicLoadObject("T_AA2_FX.Optics.Nightvision1",Class'Texture'));
			Canvas.DrawTile(NightVisionTexture,float(Canvas.SizeX),float(Canvas.SizeY),(FMath::FRand() * float(256)),(FMath::FRand() * float(256)),256,256);
		}
		if (agpMyHUD != nullptr)
		{
			Canvas.DrawColor=agpMyHUD.HUDColor;
		}
		Canvas.DrawColor.A=HUDAlpha;
		Canvas.Style = ERenderStyle.STY_Alpha;
		fpYScale=(float(Canvas.SizeY) / 600);
		fpXScale=(float(Canvas.SizeX) / 800);
		Canvas.Font=agpMyHUD._cHUDFrame._cHUDTaskDisplay.GetStatusFont(Canvas);
		Canvas.TextSize("0000:00",XL,YL);
		Canvas.SetPos(((776 * fpXScale) - (XL / 2)),((50 + 5) * fpYScale));
		RemainingTime=GameReplicationInfo.RemainingTime;
		if (RemainingTime > 0)
		{
			bFlash=(((RemainingTime < 45) || GameReplicationInfo.bRoundIsSuspended) && CheckFlashTime());
			minutes=(GameReplicationInfo.RemainingTime / 60);
			Seconds=int((float(GameReplicationInfo.RemainingTime) % float(60)));
		}
		if (! bFlash)
		{
			Canvas.DrawText(TwoDigitString(minutes) + ":" + TwoDigitString(Seconds));
		}
	}
	Function Timer()
	{
		if (GetNetMode() != ENetMode::NM_Client)
		{
			if (ViewTarget->IsA("AAGP_Pawn::StaticClass()") && (Cast<AAGP_Pawn>(ViewTarget).Health <= 0))
			{
				if (! Level.Game.IsSpectateFirstPersonOnly())
				{
					BehindView(true);
				}
				else
				{
					ServerNextViewTarget(ViewPreference);
				}
			}
		}
	}
	simulated Function bool IsFrozen()
	{
		if (ViewTarget == nullptr)
		{
			return false;
		}
		if (((GetWorld()->GetTimeSeconds() - fpLastViewChange) < 0.5) && (GetWorld()->GetTimeSeconds() > fpLastViewChange))
		{
			ClientMessage("Please try again in a few seconds.");
			return true;
		}
		else
		{
			return false;
		}
	}
	exec Function Jump(float F)
	{
		if (IsFrozen())
		{
			return;
		}
		fpLastViewChange=GetWorld()->GetTimeSeconds();
		ServerCycleViewPreference();
	}
	exec Function Fire(float F)
	{
		LockPlayer(true,false);
		if (IsFrozen())
		{
			return;
		}
		fpLastViewChange=GetWorld()->GetTimeSeconds();
		DebugLog(DEBUG_Spec,"PlayerController::Spectating::Fire()	Requesting ServerNextViewTarget(false)	" + FString::FromInt(this));
		ServerNextViewTarget(ViewPreference);
	}
	exec Function Action()
	{
		BehindView((! bBehindView));
	}
	exec Function AltFire(float F)
	{
		if (IsFrozen())
		{
			return;
		}
		DebugLog(DEBUG_Spec,"PlayerController::Spectating::AltFire()	Requesting ServerNextViewTarget(true)	" + FString::FromInt(this));
		fpLastViewChange=GetWorld()->GetTimeSeconds();
		ServerNextViewTarget(ViewPreference,true);
	}
	exec Function Zoom()
	{
	}
	Function ResetLeanRotation()
	{
		FRotator R = FRotator(0,0,0);
		if (bIgnoreSetTargetRotation)
		{
			return;
		}
		R=Rotation;
		R.Roll=0;
		SetActorRotation(R);
	}
	Function BeginState()
	{
		fpLastViewChange=0;
		DebugLog(DEBUG_Spec,"HumanController::Spectating::BeginState() entered for " + PlayerReplicationInfo.PlayerName);
		ResetLeanRotation();
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (StartupStage == 8))
		{
			DebugLog(DEBUG_Spec,"Forcing player " + PlayerReplicationInfo.PlayerName + " into spectator role");
			SetStartupStage(9);
		}
		bNotIdle=true;
		bIdleWarning=0;
		yFloodCount=0;
		SetSpecNV(false);
		DebugLog(DEBUG_Spec,"HumanController::Spectating::BeginState()	" + FString::FromInt(this));
		Super::BeginState();
		bBehindView=(! IsSpectateFirstPersonOnly());
		LockPlayer(true,false);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			DebugLog(DEBUG_Spec,"HumanController::Spectating::BeginState() - Trying to force view to teammate for " + PlayerReplicationInfo.PlayerName);
		}
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ServerSetViewPreference(1);
		}
	}
	Function EndState()
	{
		fpLastViewChange=0;
		CleanUp();
		DebugLog(DEBUG_Spec,"PlayerController::Spectating::EndState()	" + FString::FromInt(this));
		Super::EndState();
		bBehindView=false;
		ViewTargetActor=nullptr;
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			SetTimer(0,false);
		}
		LockPlayer(false,false);
		PlayerReplicationInfo.SetWaitingPlayer(false);
	}
}
*/

/*
State GameEnded
{
	exec Function Fire(float F)
	{
	}
	exec Function AltFire(float F)
	{
	}
	exec Function Reload()
	{
	}
	exec Function FixJam()
	{
	}
	exec Function SwapHands()
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function binoculars()
	{
	}
	exec Function Zoom()
	{
	}
	Function NotifyLostViewTarget()
	{
	}
	Function NotifyServerLostViewTarget()
	{
	}
	Function DoEndOfMatch()
	{
		ATeamInfo* Team1 = nullptr;
		ATeamInfo* Team2 = nullptr;
		ATeamInfo* Winner = nullptr;
		FString Message = "";
		int32 tierounds = 0;
		if (GameReplicationInfo != nullptr)
		{
			if (TournamentWarmupJustEnded())
			{
				EndRound();
				if ((MyHUD != nullptr) && (Cast<AAGP_HUD>(MyHUD) != nullptr))
				{
					Cast<AAGP_HUD>(MyHUD).DisplayCenteredMessage(4,"The next round of the tournament will be live.");
				}
				return;
			}
			Team1=GameReplicationInfo.Teams[0];
			Team2=GameReplicationInfo.Teams[1];
			if ((Team1 != nullptr) && (Team2 != nullptr))
			{
				if (Team1.teamScore > Team2.teamScore)
				{
					Winner=Team1;
				}
				else
				{
					if (Team1.teamScore < Team2.teamScore)
					{
						Winner=Team2;
					}
				}
				if ((MyHUD != nullptr) && (Cast<AAGP_HUD>(MyHUD) != nullptr))
				{
					if (Winner != nullptr)
					{
						if (TournamentIsTournament())
						{
							Message=GameReplicationInfo.asTournamentTeamName[Winner.TeamIndex] + " Team wins the match! (" + GameReplicationInfo.asTournamentTeamName[0] + ") = " + FString::FromInt(Team1.teamScore) + " (" + GameReplicationInfo.asTournamentTeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
							if (Level.Game.TournamentEndedByMercyRule())
							{
								Message=Message + " (EndEx)";
							}
						}
						else
						{
							Message=Level.TeamName[Winner.TeamIndex] + " Team wins the match! (" + Level.TeamName[0] + ") = " + FString::FromInt(Team1.teamScore) + " (" + Level.TeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
							SelectClass();
						}
						tierounds=(GameReplicationInfo.RoundsPerMatch - (Team1.teamScore + Team2.teamScore));
						if (tierounds > 0)
						{
							Message=Message + " (TIE) = " + FString::FromInt(tierounds);
						}
					}
					else
					{
						if (TournamentIsTournament())
						{
							Message="The match was a tie. (" + GameReplicationInfo.asTournamentTeamName[0] + ") = " + FString::FromInt(Team1.teamScore) @ "(" + GameReplicationInfo.asTournamentTeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
						}
						else
						{
							Message="The match was a tie. (" + Level.TeamName[0] + ") = " + FString::FromInt(Team1.teamScore) @ "(" + Level.TeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
						}
					}
					if (TournamentIsTournament() && GameReplicationInfo.bTournamentInProgress)
					{
					}
					if (GameReplicationInfo.sTournamentState ~= "Setup")
					{
						if ((MyHUD != nullptr) && (Cast<AAGP_HUD>(MyHUD) != nullptr))
						{
							Cast<AAGP_HUD>(MyHUD).DisplayCenteredMessage(8,Message);
						}
					}
				}
				else
				{
					if (GetStateName() == "GameEnded")
					{
						EndRound();
						if (Winner != nullptr)
						{
							if (TournamentIsTournament())
							{
								Message=GameReplicationInfo.asTournamentTeamName[Winner.TeamIndex] + " Team wins the match! (" + GameReplicationInfo.asTournamentTeamName[0] + ") = " + FString::FromInt(Team1.teamScore) + " (" + GameReplicationInfo.asTournamentTeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
								if (Level.Game.TournamentEndedByMercyRule())
								{
									Message=Message + " (EndEx)";
								}
							}
							else
							{
								Message=Level.TeamName[Winner.TeamIndex] + " Team wins the match! (" + Level.TeamName[0] + ") = " + FString::FromInt(Team1.teamScore) + " (" + Level.TeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
							}
							tierounds=(GameReplicationInfo.RoundsPerMatch - (Team1.teamScore + Team2.teamScore));
							if (tierounds > 0)
							{
								Message=Message + " (TIE) = " + FString::FromInt(tierounds);
							}
						}
						else
						{
							if (TournamentIsTournament())
							{
								Message="The match was a tie. (" + GameReplicationInfo.asTournamentTeamName[0] + ") = " + FString::FromInt(Team1.teamScore) @ "(" + GameReplicationInfo.asTournamentTeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
							}
							else
							{
								Message="The match was a tie. (" + Level.TeamName[0] + ") = " + FString::FromInt(Team1.teamScore) @ "(" + Level.TeamName[1] + ") = " + FString::FromInt(Team2.teamScore);
							}
						}
						if (TournamentIsTournament() && GameReplicationInfo.bTournamentInProgress)
						{
						}
						if ((MyHUD != nullptr) && (Cast<AAGP_HUD>(MyHUD) != nullptr))
						{
							Cast<AAGP_HUD>(MyHUD).DisplayCenteredMessage(8,Message);
						}
					}
				}
			}
		}
	}
	Function EndRound()
	{
		if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && Pawn.Weapon->IsA(AFixedWeapon::StaticClass()))
		{
			Pawn.TossWeapon(FVector(0,0,0));
		}
		SetFOVAngle(DefaultFOV);
		LockPlayer(false,false);
		bBehindView=false;
	}
	Function Timer()
	{
		if ((GameReplicationInfo != nullptr) && (GameReplicationInfo.RemainingRounds == 0))
		{
			DoEndOfMatch();
		}
	}
	Function BeginState()
	{
		AAGP_Pawn* BleedPawn = nullptr;
		if (Level.bCoOpGame && (GetWorld()->GetNetMode() == NM_DedicatedServer))
		{
			fpLastRoundLength=(float((Cast<AAGP_GameInfo>(GetGameMode()).TimeLimit * 60)) - float(GameReplicationInfo.RemainingTime));
			if ((Pawn != nullptr) && (Pawn.Health > 0))
			{
				fpTimePlayedLastRound=fpLastRoundLength;
			}
		}
		DebugLog(DEBUG_Multi,string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		if (Pawn != nullptr)
		{
			if (Pawn.BleedMax > 0)
			{
				DebugLog(DEBUG_Multi,"Player was bleeding after round ended. Resetting.");
			}
			Pawn.VirtualHealth=Pawn.BleedMax;
			Pawn.BleedMax=0;
			Pawn.BleedHealth=0;
			BleedPawn=Cast<AAGP_Pawn>(Pawn);
			if (BleedPawn != nullptr)
			{
				BleedPawn.fBleedTimer=0;
				BleedPawn.fHealPercent=0;
				BleedPawn.iLastPercent=-1;
			}
			Pawn.ResetLean();
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD).SetHUDActor();
			HUDPlayerID(Cast<AAGP_HUD>(MyHUD).GetHUDControl(16)).ClearTarget();
			Cast<AAGP_HUD>(MyHUD).FreeHUDActor();
		}
		if ((GameReplicationInfo != nullptr) && (GameReplicationInfo.RemainingRounds == 0))
		{
			DoEndOfMatch();
		}
		Super::BeginState();
	}
	Function FindGoodView()
	{
	}
	Function EndState()
	{
		DebugLog(DEBUG_Multi,string(this) @ "HumanController::EndState() - leaving EndGame()");
		CleanUp();
		Super::EndState();
		bTestedIdleRounds=false;
	}
}
*/

/*
State UnauthorizedJoinComplete
{
	Function BeginState()
	{
		DebugLog(DEBUG_Auth,"HumanController::UnauthorizedJoinComplete::BeginState() entered");
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			UpdateAuthRelatedPRI();
			if (PlayerReplicationInfo != nullptr)
			{
				PlayerReplicationInfo.bQualifiedSniper=true;
				PlayerReplicationInfo.bQualifiedAirborne=true;
				PlayerReplicationInfo.bQualifiedRanger=true;
				PlayerReplicationInfo.bQualifiedMedic=true;
				PlayerReplicationInfo.bQualifiedSF=true;
				PlayerReplicationInfo.bQualifiedJavelin=true;
				PlayerReplicationInfo.bQualifiedDriveHMMWV=true;
				PlayerReplicationInfo.bQualifiedUseCROWS=true;
			}
			if (! Level.IsExploreTheArmyServer())
			{
				ClientTeamSelectMenu(true);
			}
			else
			{
				NotifyAdminMessage("Your user name is \"" + UserName + "\" for this game session.");
				SetTimer(3,false);
				return;
			}
		}
		else
		{
			PostLoginComplete();
			ServerSetViewPreference(2);
			if (PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
			{
				NotifyAdminMessage("You are logged on as an administrator.");
			}
			else
			{
				DebugLog(DEBUG_Auth,string(this) + FString::FromInt(GetStateName()) + "BeginState() entered - ETA mode: " + FString::FromInt(bExploreTheArmyServer));
				if (bExploreTheArmyServer)
				{
					NotifyAdminMessage("Your user name is \"" + UserName + "\" for this game session.");
					SetTimer(3,false);
					return;
				}
				else
				{
					SelectTeam();
				}
			}
		}
		ChangeState("PlayerWaiting");
	}
	Function Timer()
	{
		DebugLog(DEBUG_Auth,string(this) + FString::FromInt(GetStateName()) + "Timer() entered");
		if (Level.IsExploreTheArmyServer())
		{
			SelectTeam();
			ChangeState("PlayerWaiting");
		}
	}
}
*/

/*
State PlayerAuthorizationComplete
{
	Function BeginState()
	{
		ChangeState("PlayerWaiting");
		ClientGotoState("PlayerWaiting","None");
	}
}
*/

/*
State PlayerWaiting
{
	Function BeginState()
	{
		GUIController(Level.GetLocalPlayerController().Player.GUIController).RefreshMenus();
		if (Level.debugControllerState)
		{
			DebugLog(DEBUG_Multi,string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		DebugLog(DEBUG_Spec,"PlayerController::PlayerWaiting::BeginState()	" + FString::FromInt(this));
		Super::BeginState();
		bPlayerIsReadyToPlay=true;
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
			{
				DebugLog(DEBUG_Auth,"HumanController::PlayerWaiting::BeginState() - Admin joined");
				if (GetWorld()->GetNetMode() == NM_Client)
				{
					ClientMessage("You are logged on as an administrator.  Type \"Help\" in the console for admin commands.");
					NotifyAdminMessage("You are logged on as an administrator.");
				}
			}
			else
			{
				DebugLog(DEBUG_Auth,"HumanController::PlayerWaiting::BeginState() - Non-admin joined");
				SelectTeam();
			}
		}
		if (PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
		{
			ChangeState("Spectating");
		}
		if (IsInState("DelayedStart"))
		{
			return;
		}
		if ((Pawn != nullptr) && (! Pawn.isDead()))
		{
			if (bBehindView && (! CanBehindView()))
			{
				DebugLog(DEBUG_Spec,"Trying to force normal view");
				ClientSetBehindView(false);
			}
			ChangeState("PlayerWalking");
		}
		else
		{
			ChangeState("Spectating");
		}
	}
	Function EndState()
	{
		DebugLog(DEBUG_Spec,"PlayerController::PlayerWaiting::EndState()	" + FString::FromInt(this));
		Super::EndState();
	}
}
*/

/*
State Stryker_Seat
{
	exec Function Fire(float F)
	{
	}
	exec Function AltFire(float F)
	{
	}
	exec Function Jump(float F)
	{
	}
	exec Function Reload()
	{
	}
	Function BeginState()
	{
		if (Level.debugControllerState)
		{
			Log(string(this) @ "HumanController::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		AGPHUD(false);
		LockPlayer(true,true);
		Pawn.bHidden=true;
	}
	exec Function Action()
	{
		AGPHUD(true);
		SetViewTarget(Pawn);
		SetFOVAngle(DefaultFOV);
		LockPlayer(false,false);
		Pawn.bHidden=false;
		ChangeState("PlayerWalking");
	}
}
*/

/*
State PlayerDriving
{
	Function BeginState()
	{
		Super::BeginState();
	}
	Function EndState()
	{
		Super::EndState();
		SetFOVAngle(DefaultFOV);
	}
}
*/

/*
State Viewing_RemoteCam
{
	exec Function AltFire(float F)
	{
	}
	exec Function Reload()
	{
	}
	exec Function FixJam()
	{
	}
	exec Function SwapHands()
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function binoculars()
	{
	}
	exec Function Zoom()
	{
	}
	Function BeginState()
	{
		if ((Pawn != nullptr) && Pawn.IsZoomed())
		{
			AbortViewCam();
			return;
		}
		if (Pawn.Physics == 1)
		{
			ViewCam();
		}
		else
		{
			AbortViewCam();
		}
	}
	Function EndState()
	{
		SetFOVAngle(DefaultFOV);
		LockPlayer(false,false);
		SetViewTarget(Pawn);
		ClientSetViewTarget(Pawn);
		bBehindView=false;
		AGPHUD(true);
	}
	simulated Function PlayerMove(float DeltaTime)
	{
	}
	simulated Function RenderOverlays_Stage1(UCanvas* Canvas)
	{
	}
	simulated Function RenderOverlays_Stage2(UCanvas* Canvas)
	{
		if (HUDCamOverlay != nullptr)
		{
			Canvas.SetPos(0,0);
			Canvas.Style = ERenderStyle.STY_Alpha;
			Canvas.DrawTile(HUDCamOverlay,float(Canvas.SizeX),float(Canvas.SizeY),0,0,1024,768);
		}
	}
	Function AbortViewCam()
	{
		ServerAbortViewCam();
		Pawn.SetPhysics(PHYS_Walking);
		ChangeState("PlayerWalking");
	}
	Function ServerAbortViewCam()
	{
		Pawn.SetPhysics(PHYS_Walking);
		ChangeState("PlayerWalking");
	}
	Function ViewCam()
	{
		AGPHUD(false);
		LockPlayer(true,true);
		Pawn.Velocity=FVector(0,0,0);
		Pawn.Acceleration=FVector(0,0,0);
		Pawn.SetPhysics(PHYS_None);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		if (Level.IsServer())
		{
			ClientGotoState(GetStateName(),"None");
		}
		SetViewTarget(RemoteCamera);
		ClientSetViewTarget(RemoteCamera);
	}
	exec Function Action()
	{
		ServerAction();
	}
	Function ServerAction(AActor* Other)
	{
		ChangeState("PlayerWalking");
		if (Level.IsServer())
		{
			ClientGotoState("PlayerWalking","None");
		}
	}
}
*/

/*
State Manning_Turret
{
	exec Function AltFire(float F)
	{
	}
	exec Function Reload()
	{
	}
	exec Function FixJam()
	{
	}
	exec Function SwapHands()
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function binoculars()
	{
	}
	exec Function Zoom()
	{
	}
	simulated Function BeginState()
	{
		FString Reason = "";
		TurretBeginTime=GetWorld()->GetTimeSeconds();
		origFOV=turretFOV;
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			turretFOV=65;
			origFOV=65;
			return;
		}
		if ((GetWorld()->GetTimeSeconds() - TurretEndTime) < 1)
		{
			AbortTurret("");
		}
		else
		{
			if (! Turret.CanManTurret(Cast<AAGP_Pawn>(Pawn),Reason))
			{
				AbortTurret(Reason);
			}
			else
			{
				ManTurret();
			}
		}
	}
	Function AbortTurret(FString Reason)
	{
		SetTurret(nullptr);
		if (Reason != "")
		{
			TeamMessage(nullptr,Reason,"Center");
		}
		ChangeState("PlayerWalking");
	}
	Function ManTurret()
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		if (Level.IsServer())
		{
			ClientGotoState(GetStateName(),"None");
		}
		if ((Cast<AAGP_Pawn>(Pawn) != nullptr) && (Cast<AAGP_Pawn>(Pawn)->getHandsInventory() != nullptr))
		{
			Cast<AAGP_Pawn>(Pawn)->FinishSwapHands();
		}
		Turret.ManTurret(Pawn);
		LockPlayer(true,true);
		ClientSetViewTarget(Turret);
		SetViewTarget(Turret);
		Pawn.Velocity=FVector(0,0,0);
		Pawn.Acceleration=FVector(0,0,0);
		Pawn.SetPhysics(PHYS_None);
		if (Turret.bHidePawnWhenUsed)
		{
			Pawn.HidePawn(true);
		}
	}
	simulated Function PlayerMove(float DeltaTime)
	{
		FRotator NewRotation = FRotator(0,0,0);
		float multiplier = 0;
		Pawn.Velocity=FVector(0,0,0);
		Pawn.Acceleration=FVector(0,0,0);
		if (Turret == nullptr)
		{
			ClientSetTurret(ViewTarget);
		}
		if (Turret != nullptr)
		{
			NewRotation=Turret.GetTurretRotation();
			multiplier=Turret.GetRotationMultiplier();
			(NewRotation.Yaw += int(((aMouseX * DeltaTime) * multiplier)));
			if (GetInvertMouse())
			{
				(NewRotation.Pitch += int(((aMouseY * DeltaTime) * multiplier)));
			}
			else
			{
				(NewRotation.Pitch -= int(((aMouseY * DeltaTime) * multiplier)));
			}
			NewRotation.Pitch=Clamp(NewRotation.Pitch,-10000,3200);
			Turret.UpdateTurretRotation(NewRotation);
		}
	}
	Function IdleCheck()
	{
		LastMovedTime=GetWorld()->GetTimeSeconds();
	}
	exec Function Jump(float F)
	{
		ServerAction();
	}
	exec Function Action()
	{
		ServerAction();
	}
	Function ServerAction(AActor* Other)
	{
		if ((GetWorld()->GetTimeSeconds() - TurretBeginTime) > 2)
		{
			Pawn.TossWeapon(FVector(0,0,0));
			ChangeState("PlayerWalking");
			if (Level.IsServer())
			{
				ClientGotoState("PlayerWalking","None");
			}
		}
	}
	simulated Event PlayerCalcView(AActor*& ViewActor, Vector& CameraLocation, Rotator& CameraRotation)
	{
		ViewActor=ViewTarget;
		if (bBehindView)
		{
			CalcBehindView(CameraLocation,CameraRotation,50);
		}
		else
		{
			CalcFirstPersonView(CameraLocation,CameraRotation);
		}
	}
	simulated Function CalcFirstPersonView(Vector& CameraLocation, Rotator& CameraRotation)
	{
		CameraLocation=ViewTarget.GetBoneCoords("Camera").Origin;
		CameraRotation=ViewTarget.GetBoneRotation("Camera");
	}
	simulated Function CalcBehindView(Vector& CameraLocation, Rotator& CameraRotation, float dist)
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		if (bFreeCamera)
		{
			CameraRotation.Pitch=(- ViewTarget.Rotation.Pitch);
			CameraRotation.Yaw=(ViewTarget.Rotation.Yaw + 32768);
			CameraRotation.Roll=0;
		}
		else
		{
			CameraRotation=ViewTarget.GetBoneRotation("Camera");
		}
		GetAxes(CameraRotation,X,Y,Z);
		CameraLocation=((ViewTarget.Location - (float(100) * X)) + FVector(0,0,50));
	}
	exec Function Fire(float F)
	{
		Pawn.Fire();
	}
	exec Function DecreaseRange()
	{
		if (turretFOV < origFOV)
		{
			(turretFOV += 12);
			SetFOV(float(turretFOV));
		}
	}
	exec Function IncreaseRange()
	{
		if (turretFOV > 12)
		{
			(turretFOV -= 12);
			SetFOV(float(turretFOV));
		}
	}
	exec Function ZeroRange()
	{
		SetFOV(float(origFOV));
		turretFOV=origFOV;
		DebugLog(DEBUG_Multi,"FOV Reset (zero) range from turret now: " + FString::FromInt(turretFOV));
	}
	simulated Function EndState()
	{
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Turret != nullptr)
			{
				TurretEndTime=GetWorld()->GetTimeSeconds();
				if (Turret.bHidePawnWhenUsed)
				{
					Pawn.HidePawn(false);
				}
				SetTurret(nullptr);
			}
			Pawn.SetPhysics(PHYS_Walking);
		}
		SetViewTarget(Pawn);
		SetFOV(float(origFOV));
		LockPlayer(false,false);
		bBehindView=false;
	}
	simulated Function RenderOverlays_Stage1(UCanvas* Canvas)
	{
		RenderOverlays(Canvas,false);
	}
}
*/

/*
State DelayedStart
{
	exec Function Fire(float F)
	{
	}
	exec Function Jump(float F)
	{
	}
	exec Function Reload()
	{
	}
	exec Function FixJam()
	{
	}
	exec Function SupportedFire()
	{
	}
	exec Function IncreaseRange()
	{
	}
	exec Function DecreaseRange()
	{
	}
	exec Function ZeroRange()
	{
	}
	exec Function FastMove()
	{
	}
	exec Function Crouch()
	{
	}
	exec Function Crouching()
	{
	}
	exec Function Crawling()
	{
	}
	exec Function Stand()
	{
	}
	exec Function Crawl()
	{
	}
	exec Function Suicide()
	{
	}
	exec Function Grenade(uint8 Index)
	{
	}
	exec Function GrenadeFrag()
	{
	}
	exec Function GrenadePDM()
	{
	}
	exec Function GrenadeFlash()
	{
	}
	exec Function GrenadeSmoke()
	{
	}
	exec Function GrenadeIncendiary()
	{
	}
	exec Function GrenadeSignal()
	{
	}
	exec Function DemolitionItem()
	{
	}
	exec Function ThrowWeapon()
	{
	}
	exec Function CFFFire()
	{
	}
	exec Function EnemySpotted()
	{
	}
	exec Function ESSObjectSpotted(AAGP_Objective* Objective)
	{
	}
	exec Function Shake(float Time, float Intensity)
	{
	}
	exec Function LeanLeft()
	{
	}
	exec Function LeanRight()
	{
	}
	exec Function LeanCenter()
	{
	}
	exec Function HealSelf()
	{
	}
	Function Action()
	{
	}
	Function MPCheat_PlayerLock(bool B)
	{
	}
	Function MPCheat_Slomo(float t)
	{
	}
	Function MPCheat_Pause(bool bPause)
	{
	}
	Function MPCheat_EnterGhostMode()
	{
	}
	Function MPCheat_Walk()
	{
	}
	Function ServerFire()
	{
	}
	simulated Function MaybeEnterPlayerWalkingState()
	{
	}
	simulated Function PlayerMove(float DeltaTime)
	{
		Acceleration=FVector(0,0,0);
		Velocity=FVector(0,0,0);
		UpdateRotation(DeltaTime,1);
		if (Role < 4)
		{
			ReplicateMove(DeltaTime,FVector(0,0,0),0,FRotator(0,0,0));
		}
		else
		{
			ProcessMove(DeltaTime,Acceleration,0,FRotator(0,0,0));
		}
	}
	Function VeryShortClientAdjustPosition(float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, uint8 AnimPitch, AActor* NewBase)
	{
	}
	Function bool CanFire()
	{
		return false;
	}
	Function TurnAround()
	{
	}
	Function BeginState()
	{
		EnableStateChange(false);
		ClientSetViewTarget(Pawn);
		ServerSetViewTarget(Pawn);
		ClientSetBehindView(false);
		SetCustomTimer(0.25,false,"UpdateRotationTimer");
		SetTimer(2,false);
	}
	simulated Function UpdateRotationTimer()
	{
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ClientSetRotation(StartSpot.Rotation);
			Pawn.SetRotation(StartSpot.Rotation);
			SetActorRotation(StartSpot.Rotation);
		}
	}
	Function Timer()
	{
		if (GameReplicationInfo.iDelayedStartTimeRemaining <= 0)
		{
			EnableStateChange(true);
			ChangeState("PlayerWalking");
			return;
		}
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (bShowDelayedStartWarningMessage)
			{
				if (GameReplicationInfo.iDelayedStartTimeRemaining > 0)
				{
					NotifyAdminMessage("Check your gear.  The mission starts in " + FString::FromInt(GameReplicationInfo.iDelayedStartTimeRemaining) + " seconds.");
					Cast<AAGP_HUD>(MyHUD).LongMessageTimeout=(GetWorld()->GetTimeSeconds() + 1.5);
				}
			}
		}
		SetTimer(1,false);
	}
	Function EndState()
	{
		Pawn.bLockMovement=false;
		SetTimer(0,false);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			if (bShowDelayedStartWarningMessage)
			{
				Cast<AAGP_HUD>(MyHUD).LongMessageTimeout=(GetWorld()->GetTimeSeconds() + 0.1);
				Cast<AAGP_HUD>(MyHUD).LongMessage="Move Out!";
			}
			if ((PlayerReplicationInfo.Team != nullptr) && (PlayerReplicationInfo->Team->SquadLeader == this))
			{
				CommoSend(ACommoShout::StaticClass(),0);
			}
		}
	}
}
*/


void AHumanController::BeginPlay()
{
	Super::BeginPlay();

	bPlayerIsReadyToPlay = true;
	if (DesiredTeamClass == nullptr)
	{
		//	DesiredTeamClass = class<SoldierClass>(DynamicLoadObject(DesiredTeamClassName, Class'Class'));
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			DesiredTeamClass = World->SpawnActor<ASoldierClass>(ASoldierClass::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			DesiredTeamClassName = DesiredTeamClass->GetName();
		}
	}

	//if (PlayerReplicationInfo != nullptr)
	//{
	//	PlayerReplicationInfo.sCurrentWeaponClass = "" + DesiredTeamClass;
	//}
	SetHUDAlpha(HUDAlpha);
	SetHUDColor(HUDColor);
	SetHUDCrosshair(HUDCrosshair);

	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();
		MyGameSettings->SetScreenResolution(FIntPoint(3840, 2160));
		MyGameSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		MyGameSettings->SetVSyncEnabled(true);
		MyGameSettings->ApplySettings(false);
	}

	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetWeaponMods();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Max() > 0)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[0]);
	}

	ClientMessage("Test ClientMessage");

	//SaveConfig();

}

void AHumanController::RequestChangeTeam(int32 N)
{
	if (PlayerReplicationInfo->IsOnlyASpectator())
	{
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		PlayerReplicationInfo->DesiredTeam = N;
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && N == 1)
		{
			N = 0;
		}
		Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->RequestChangeTeam(this, N);
	}
}

void AHumanController::DumpServerStats()
{
}

void AHumanController::DumpServerDynamicActors()
{
}

void AHumanController::CheckOutOfBounds()
{
}

void AHumanController::InduceFailure()
{
}

void AHumanController::ResetRend()
{
}

void AHumanController::PostNetBeginPlay()
{
}

void AHumanController::EntryLevelSimulatedScreenplay()
{
}

void AHumanController::ChangeUserName(FString S)
{
	return;
}

//native Function bool ObfuscatePassword(FString Password);
bool AHumanController::ObfuscatePassword(FString Password)
{
	return false;    //FAKE  /EliZ
}

//native Function bool DeobfuscatePassword(FString& Password);
bool AHumanController::DeobfuscatePassword(FString& Password)
{
	return false;    //FAKE   /EliZ
}

void AHumanController::RestoreSavedUserNameAndPassword()
{
	FString DeobfuscatedPassword;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	/*
	if (DeobfuscatePassword(DeobfuscatedPassword))
	{
		Log(this + ".RestoreSavedUserNameAndPassword() Restoring user name & password from saved file ");
		UserName = 'HumanController'.Default.sSavedUserName;
		'HumanController'.Default.UserName = StripBadCodes('HumanController'.Default.sSavedUserName);
		'HumanController'.Default.sSavedUserName = StripBadCodes('HumanController'.Default.sSavedUserName);
		UserPassword = DeobfuscatedPassword;
		'HumanController'.Default.UserPassword = DeobfuscatedPassword;
	}
	*/
}
void AHumanController::ServerCheckServerAuthAndPBMode()
{
	if (IsPBEnabled() == 0)
	{
		ChangeState("ServerAuthorizePlayer");
	}
	//ClientSetAuthMode(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer(), Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(), IsPBEnabled());
}

void AHumanController::ClientSetAuthMode(bool bAuthorizedServer, bool bRequiresAuthorization, int32 aiPBEnabled)
{
	bIsAuthorizedServer = bAuthorizedServer;
	bServerRequiresAuthorization = bRequiresAuthorization;
	if (aiPBEnabled == 1)
	{
		ChangeState("ValidatePB");
	}
	else
	{
		bPBChecked = true;
		ChangeState("ServerAuthorizePlayer");
	}
}

void AHumanController::ClientSetAccessControlKickMessage(FString sMessage)
{
	sKickReason = sMessage;
	//ClientCloseMenu(true);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(4, sMessage, nullptr);
	}
}
void AHumanController::ClientForceGamePlayMode(EGameplayModes newmode)
{
	if (GetMilesOnly())
	{
		if (newmode != EGameplayModes::GM_MILES)
		{
			//ClientOpenMap("entry");
		}
	}
	Cast<AAA2_WorldSettings>(GetWorldSettings())->GamePlayMode = newmode;
}
void AHumanController::ClientSetServerFlags(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bRequiresAuthorization, bool bPlayersOnly, bool bFirstPerson, bool bBodies, bool bAllowLocalScores, bool bIsExploreTheArmyServer, bool bAllowForceclassing)
{
	bCheatServer = bCheat;
	bDevMode = bDev;
	bBetaServer = bBeta;
	bLeasedServer = bLeased;
	bOfficialServer = bOfficial;
	bUnofficialServer = !bOfficial;
	bNATOServer = bNATO;
	bTournamentServer = bTournament;
	bUltimateArenaServer = bUltimateArena;
	bIsAuthorizedServer = bIsAuthorized;
	bServerRequiresAuthorization = bRequiresAuthorization;
	bSpectatePlayersOnly = bPlayersOnly;
	bSpectateFirstPersonOnly = bFirstPerson;
	bSpectateBodies = bBodies;
	bAllowScoreShown = bAllowLocalScores;
	bExploreTheArmyServer = bIsExploreTheArmyServer;
	SetDevMode(false);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, bAllowForceclassing);
	}
}
void AHumanController::SetDevMode(bool bNewDevMode)
{
}

void AHumanController::DevMode(bool bSet)
{
	/*
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().NotifyCheated();
	}
	*/
	if (GetNetMode() == ENetMode::NM_Standalone || bDevMode)
	{
		SetDevMode(bSet);
	}
}

void AHumanController::HideSmoke(bool bDisableRendering)
{
	USpriteEmitter* seIterator = nullptr;
	/*
	ForEach(USpriteEmitter::StaticClass(), seIterator)
	{
		if (seIterator.bCanJavelinSeeThrough)
		{
			seIterator.bDisableRendering = bDisableRendering;
		}
	}
	*/
}

void AHumanController::ServerRequestAuthorization(FString InUserName, FString InEncryptedPassword, FString sLANPlayerName)
{
	
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization( %s)"), *InUserName);
	InUserName = PlayerReplicationInfo->PlayerName;
	if (bReceivedAuthRequest)
	{
		//ServerSay("Player attempting to re-authorize kicked by the server.", 'AdminSay');
		UE_LOG(LogTemp, Log, TEXT("Invalid user attempt to re-authorize"));
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}
	if (InUserName.Len() == 0 && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		//ServerSay("Player with invalid name kicked by the server.", 'AdminSay');
		UE_LOG(LogTemp, Log, TEXT("Invalid User Name for auth request"));
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}

	//bAuthDisabledForAccount = !Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization();
	
	if (Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		if (!PlayerReplicationInfo->bAdmin || !PlayerReplicationInfo->IsOnlyASpectator() || TournamentIsTournament())
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				if ((Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyAccount(this, InUserName, true)).Len() > 0)
				{
					//AnnounceNewPlayerJoiningServer(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyAccount(this, InUserName, true) + " is awaiting account authorization to play.");
				}
				else
				{
					//AnnounceNewPlayerJoiningServer( TEXT("%s is awaiting account authorization to play."), *InUserName);
				}
			}
			else
			{
				//AnnounceNewPlayerJoiningServer(TEXT("%s is awaiting account authorization to play."), *UserName);
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization - starting auth process for player"));
		EncryptedPassword = InEncryptedPassword;
		ReceivedAuthRequest();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerRequestAuthorization - unauthorized server - setting player as qualified for all"));
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo->bQualifiedSniper = true;
			PlayerReplicationInfo->bQualifiedAirborne = true;
			PlayerReplicationInfo->bQualifiedRanger = true;
			PlayerReplicationInfo->bQualifiedMedic = true;
			PlayerReplicationInfo->bQualifiedSF = true;
			PlayerReplicationInfo->bQualifiedJavelin = true;
			PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
			PlayerReplicationInfo->bQualifiedUseCROWS = true;
			PlayerReplicationInfo->bQualifiedES2 = true;
		}
		if (PlayerReplicationInfo->bAdmin && PlayerReplicationInfo->IsOnlyASpectator())
		{
		}
		//Level.Game.Broadcast(Level.Game, UserName + " is joining the server.");
		//LogFileWrite("DevNet", "Join succeeded for player """ + UserName + """:" + GetPlayerNetworkAddress());
		ReceivedAuthRequest();
		//ClientGotoState('UnauthorizedJoinComplete', "None");
		ChangeState("UnauthorizedJoinComplete");
		return;
	}
	
	//ClientSetViewTarget(ViewTarget);
	
}

void AHumanController::ClientSetETA(bool bEnable)
{
	bExploreTheArmyServer = bEnable;
}

void AHumanController::ReceivedAuthRequest()
{
	bReceivedAuthRequest = true;
}

void AHumanController::PostLoginComplete()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT(this + ".PostLoginComplete() entered"));
	bPostLoginComplete = true;
	if (bReadyForFinishPostLogin)
	{
		AGP_GameInfo(GetGameMode()).FinishPostLogin(this);
	}
	*/
}

void AHumanController::EvaluateStatus()
{
	//AGP_GameInfo(GetGameMode()).EvaluatePlayerStatus(this);
}
void AHumanController::ReadyForFinishPostLogin()
{
	/*
	SetCustomTimer(2, false, 'EvaluateStatus');
	bReadyForFinishPostLogin = true;
	if (bPostLoginComplete)
	{
		AGP_GameInfo(GetGameMode()).FinishPostLogin(this);
	}
	if (GameReplicationInfo.bForceShadowsOff)
	{
		ClientMessage("Player shadows have been disabled by the server administrator");
		NotifyAdminMessage("Player shadows have been disabled by the server administrator");
	}
	*/
}
void AHumanController::NotifyAuthWaiting(bool bWaiting)
{
	if (GetWorld()->IsServer())
	{
		return;
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr && bWaiting)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(6.0f, "Waiting for Authorization","");
	}
	else
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(0.1f, "Authorization Complete","");
	}
}
void AHumanController::ClientChangeName(FString sNewName)
{
	UserName = sNewName;
	iUNC = CalculateUserNameChecksum(sNewName);
}
void AHumanController::ChangeName(FString sNewName)
{
	return;
}
void AHumanController::AnnounceNewPlayerJoiningServer(FString sMsg)
{
	/*
	if (InStr(sMsg, "is awaiting account authorization to play") == -1 && InStr(sMsg, "has entered the server and is waiting for PB authorization.") == -1 && InStr(sMsg, " has successfully joined the server.") == -1)
	{
		return;
	}
	Level.Game.Broadcast(Level.Game, sMsg);
	*/
}

void AHumanController::svp()
{
}

void AHumanController::nvp()
{
}

void AHumanController::ServerSetSystemLanguage(FString Language)
{
	SystemLanguage = Language;
}

void AHumanController::ServerSetUserName(FString sUserName)
{
	return;
	sUserName = StripColorCodes(sUserName);
	
	if (sUserName.Len() > 20)
	{
		sUserName = sUserName.Left(20);
	}
	/*
	ReplaceText(sUserName, " ", "_");
	ReplaceText(sUserName, """", "");
	ReplaceText(sUserName, "¤", "");
	*/

	sUserName = StripBadCodes(sUserName);
	/*
	if (!PlayerReplicationInfo.PlayerName ~= "Recruit")
	{
		UE_LOG(LogTemp, Warning, TEXT("Player name " + sUserName + " set in state " + GetStateName() + ", current PRi player name: " + PlayerReplicationInfo.PlayerName));
		if (!PlayerReplicationInfo.PlayerName ~= sUserName)
		{
			Log("Kicking player for changing name twice from """ + PlayerReplicationInfo.PlayerName + """ to """ + sUserName + """");
			Level.Game.KickByController(this, "CHEATER");
		}
		return;
	}
	*/
	if (PlayerReplicationInfo == nullptr)
	{
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}

	if (GetNetMode() == ENetMode::NM_DedicatedServer && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		UE_LOG(LogTemp, Log, TEXT("User name passed in: "" %s"""), *sUserName);
		if (sUserName.Len() == 0)
		{
			//ServerSay("Player with invalid name kicked by the server.", 'AdminSay');
			UE_LOG(LogTemp, Log, TEXT("Invalid User Name view SetUserName ""%s"", Stage: ""%d"""), *sUserName , StartupStage);
			//Level.Game.KickByController(this, "CHEATER");
			return;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("ServerSetUserName() Setting user name to %s"), *sUserName);
	UserName = sUserName;
	PlayerReplicationInfo->PlayerName = sUserName;
	return;
	
}

void AHumanController::ClientSimulateTrainingComplete()
{
	SimulateTrainingComplete();
}

void AHumanController::SimulateTrainingComplete()
{
	int32 i = 0;
	for (i = 0; i < 33; i++)
	{
		iCompleted[i] = 3;
	}
	iCompleted[5] = 3;
	iCompleted[6] = 3;
	iCompleted[8] = 3;
	iCompleted[10] = 15;
	iCompleted[11] = 3;
	iRifleRangeRating = 40;
	PlayerReplicationInfo->_iTrust = 15;
	UpdateAuthRelatedPRI();
}

void AHumanController::ClientEnableStateChange(bool fEnable)
{
	//EnableStateChange(fEnable);
}

void AHumanController::ChangeMyName(FString sName)
{
	ServerCanPlayerJoin(sName);
	ClientMessage("Name set to " + sName);
}

void AHumanController::ServerCanPlayerJoin(FString sUserName)
{
	bAuthDisabledForAccount = !Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization();
	if (PbCanPlayerJoin())
	{
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerCanPlayerJoin() good PB - server State: %s"), *(GetStateName()));
		bPBChecked = true;
		ChangeState("ServerAuthorizePlayer");
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerCanPlayerJoin() - PB Status: %s"), *GetPBConnectStatus());
		ClientPlayerCanJoin(Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization(), IsPBEnabled());
	}
	
}

void AHumanController::ClientPlayerCanJoin(bool bAuthUsed, int32 iPBEnabledOnServer)
{
	bPBChecked = true;
	if (iPBEnabledOnServer == 1)
	{
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientPlayerCanJoin() - PB is enabled!: " + GetPBConnectStatus()));
		ClientMessage("PB has authenticated and is up to date.");
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientPlayerCanJoin() - starting authorization process!"));
	if (!bAuthUsed)
	{
		SelectTeam("");
	}
	else
	{
		ChangeState("ServerAuthorizePlayer");
	}
}

void AHumanController::ClientDisconnect(FString Msg)
{
	FString StrAppended;
	UE_LOG(LogTemp, Log, TEXT("User disconnected: %s"), *Msg);
	UE_LOG(LogTemp, Warning, TEXT("HumanController::ClientDisconnect( %s )"), *Msg);
	if (Msg != "")
	{
		StrAppended = "Failed Authorization|" + Msg;
	}
	else
	{
		StrAppended = "Failed Authorization";
	}
	NotifyPBAuthMessage(StrAppended);
}

void AHumanController::NotifyAuthServerOfMPMissionComplete()
{
	FString ServerIP = "";
	AMissionCompleteRequestAdapter* Adapter = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("HumanController::NotifyAuthServerOfMPMissionComplete()"));
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this, "CHEATER");
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		return;
	}
	if (!Level.Game.CheatsDisabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::NotifyAuthServerOfMPMissionComplete()	Can't authenticate on a cheat server!"));
		return;
	}
	ServerIP = AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthIP();
	UE_LOG(LogTemp, Warning, TEXT("NotifyAuthServerOfMPMissionComplete" @ UserName @ EncryptedPassword));
	Adapter = Spawn(AMissionCompleteRequestAdapter::StaticClass(), this);
	Adapter.Request(UserName, FUnload(EncryptedPassword), Level.iTour, Level.iMission, iRifleRangeRating, true, DistributionHistory, ServerIP);
	*/
}

void AHumanController::AuthUpdateExperienceCallback(int32 ResultCode, int32 experience_current, int32 experience_needed, int32 honor_current)
{
	PlayerReplicationInfo->_Experience = experience_current;
	if (PlayerReplicationInfo->bQualifiedViaInstantAction && !PlayerReplicationInfo->bQualifiedBCT)
	{
		if (PlayerReplicationInfo->_iTrust > 20)
		{
			UE_LOG(LogTemp, Log, TEXT("Information: Instant action player %s limited to display of honor 20"), *PlayerReplicationInfo->PlayerName);
			PlayerReplicationInfo->_iTrust = 20;
		}
	}
	PlayerReplicationInfo->_iTrust = honor_current;
}

bool AHumanController::LoadUserProfileAndNews()
{
	/*
	if ((!(string(Level) ~= "Entry.LevelInfo0")) && (!(string(Level) ~= "Entry2.LevelInfo0")))
	{
		SetLoginStatus(0, "Cannot load profile now.", "You cannot load your profile while attached to game server.");
		return false;
	}
	if (IsInState("AuthorizingUserLocallyThenGetNews"))
	{
		Log("User already authorizing locally");
		return true;
	}
	*/
	iTour = 0;
	ChangeState("AuthorizingUserLocallyThenGetNews");
	return true;
}

void AHumanController::ClientNotifyAuthServerMessage(FString ErrMsg1, FString ErrMsg2, FString ErrURL1, FString ErrURL2)
{
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s HumanController::ClientNotifyAuthServerMessage Got %s %s %s %s " ), *ObjectName, *ErrMsg1 , *ErrMsg2 , *ErrURL1 , *ErrURL2);
	AuthErrorMessage1 = ErrMsg1;
	AuthErrorMessage2 = ErrMsg2;
	AuthErrorURL1 = ErrURL1;
	AuthErrorURL2 = ErrURL2;
}

void AHumanController::ServerUploadTrustAndExperience(int32 Logout)
{
	FString s1 = "";
	int32 upload_experience = 0;
	FString ServerIP = "";
	AUpdateTrustAndExperienceRequestA* Adapter = nullptr;
	/*
	if (PlayerReplicationInfo == nullptr)
	{
		if (!bReportedLogout)
		{
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerUploadTrustAndExperience()	Got here with no PRI and no logout report"));
		}
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer() && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		s1 = "847";
		ClientMessage("This is an America's Army Explorer Server, while playing here you will not accrue XP/HONOR and will not generate player statistics.");
	}
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() entered, bAuthDisabledForAccount:" + bAuthDisabledForAccount));
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() entered, Auth enabled:" + Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization()));
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() || bAuthDisabledForAccount)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() Auth disabled for this account or server"));
		return;
	}
	if (Level.IsUnofficialServer() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer() && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		if (Level.Game.bSendRoundTimeInfo)
		{
			upload_experience = -1;
		}
		else
		{
			return;
		}
	}
	else
	{
		PlayerReplicationInfo.TotalExperience(true);
		upload_experience = PlayerReplicationInfo.GetExperience();
	}
	if (Logout == 1)
	{
		if (bReportedLogout)
		{
			return;
		}
		bReportedLogout = true;
	}
	ServerIP = AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthIP();
	Adapter = Spawn(Class'UpdateTrustAndExperienceRequestAdapter', this);
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() - processing request " @ "ETATracking" @ "Experience:" @ - 1 @ "Logout:" @ Logout == 1 @ "Rounds:" @ PlayerReplicationInfo.GetCumRounds() @ "PlayTime:" @ PlayerReplicationInfo.GetPlayTime() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "ServerIP:" @ ServerIP));
		Adapter.Request("ETATracking", s1 + "sdk" + 1, -1, Logout == 1, PlayerReplicationInfo.GetCumRounds(), PlayerReplicationInfo.GetPlayTime(), Level.iTour, Level.iMission, ServerIP);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadTrustAndExperience() - processing request " @ UserName @ EncryptedPassword @ "Experience:" @ upload_experience @ "Logout:" @ Logout == 1 @ "Rounds:" @ PlayerReplicationInfo.GetCumRounds() @ "PlayTime:" @ PlayerReplicationInfo.GetPlayTime() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "ServerIP:" @ ServerIP));
		Adapter.Request(UserName, FUnload(EncryptedPassword), upload_experience, Logout == 1, PlayerReplicationInfo.GetCumRounds(), PlayerReplicationInfo.GetPlayTime(), Level.iTour, Level.iMission, ServerIP);
	}
	if (Logout != 0)
	{
		Level.Game.NotifyReportLogoutStarted();
	}
	*/
}
void AHumanController::ServerUploadStats(int32 Kills, int32 Deaths, int32 ShotsFired, int32 ShotsThatHitAGPPawns, float PlayDuration)
{
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, bOnlySpectator: %s"), PlayerReplicationInfo->IsOnlyASpectator() ? TEXT("true") : TEXT("false"));
	if (PlayerReplicationInfo->IsOnlyASpectator())
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, bAuthDisabledForAccount: %s"), bAuthDisabledForAccount ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() entered, Auth enabled: %s"), Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() ? TEXT("true") : TEXT("false"));
	if (!Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() || bAuthDisabledForAccount)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats() Auth disabled for this account or server"));
		return;
	}
	//UE_LOG(LogTemp, Warning, TEXT("HumanController.ServerUploadStats()" @ UserName @ EncryptedPassword @ "Kills:" + Kills @ "Deaths:" + Deaths @ "Shots Fired:" + ShotsFired @ "Shots That Hit AGPPawns:" + ShotsThatHitAGPPawns @ "PlayDuration:" + PlayDuration));
}
void AHumanController::ServerExperienceUpdateAuthorizeComplete(int32 Code)
{
	
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerExperienceUpdateAuthorizeComplete" @ UserName @ Code));
		switch(Code)
		{
			case 1:
				//Level.Game.NotifyReportLogoutFinished();
				return;
			case -1:
				ClientMessage(WrongUserPassword);
				break;
			case -2:
				ClientMessage(NoUserRecord);
				break;
			case -3:
				ClientMessage(UserIsBanned);
				break;
			case -4:
				ClientMessage(ResponseTimeOut);
				break;
			case -5:
				ClientMessage(ServerNotRegistered);
				break;
			case -6:
				ClientMessage(BetaServer);
				break;
			case -7:
				break;
			case -8:
				break;
			default:
				ClientMessage("Error: Unknown");
				break;
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController:ServerExperienceUpdateAuthorizeComplete: Closing Authserver Connection"));
		//Level.Game.NotifyReportLogoutFinished();
	
}
void AHumanController::AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
{
	ClientMessage(sMsg);
}
void AHumanController::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	sAuthClientTransmissionText = sStatus;
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->SetLoginStatus(iStatus, sStatus, sNavMsg);
	}
}
void AHumanController::DisplayVAECompleteMessage()
{
	ClientOpenMenu("AGP_Interface.AAVAEMissionCompletePage", false, "", "");
}
void AHumanController::DisplayMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage", false, Text, text2);
}
void AHumanController::DisplayMissionCompleteOther(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, FString OtherMenu)
{
	ClientOpenMenu(OtherMenu, false, Text, text2);
}
void AHumanController::DisplayMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage",false,Text,text2);
}
void AHumanController::DisplayLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		//Cast<AAGP_HUD>(MyHUD)->OpenLandNavScore(text1, text2, text3, text4, text5, text6, text7, text8, Level.Game.GetScreenplay().bPlayerCheated);
	}
}
void AHumanController::ResetAuthExtraMissionData()
{
	iAuthMissionDataFields = 0;
}
void AHumanController::SetAuthMissionPassFlag(bool bAMissionPass)
{
	bMissionPass = bAMissionPass;
}
bool AHumanController::AddAuthExtraMissionData(FString sMissionData)
{
	UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() entered with %s"), *sMissionData);
	if (iAuthMissionDataFields < 26)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() adding data: %s"), *sMissionData);
		asAuthMissionData[iAuthMissionDataFields]=sMissionData;
		iAuthMissionDataFields ++;
		UE_LOG(LogTemp, Warning, TEXT("HumanController.AddAuthExtraMissionData() added data: %s"), *sMissionData);
		return true;
	}
	return false;
}
void AHumanController::MissionCompleted()
{
	/*
	FString sLevelName;
	if (Level.Game.GetScreenplay().bPlayerCheated)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::MissionCompleted()	Cannot Authenticate if you cheated")=;
		ScreenPrint("That don't make no sense at all.");
	}
	sLevelName = Level.GetLevelName();
	SendMissionComplete(Level.GetLevelTour(), Level.GetLevelMission());
	*/
}
void AHumanController::SendMissionComplete(int32 Tour, int32 Mission)
{
	iTour = Tour;
	iMission = Mission;
	iAuthClientTransmissionComplete = 0;
	//EncryptedPassword = FLoad(UserPassword);
	ChangeState("ClientMissionComplete");
}
void AHumanController::ParseMissionString(FString sMissions, bool bNews)
{
	int32 iMissionField = 0;
	FString sTemp = "";
	TArray<FString> asMissionFields ={};
	/*
	if (bNews)
	{
		sMissions = sMissions + Chr(255);
		Split(sMissions, "" + Chr(255), asMissionFields);
		UE_LOG(LogTemp, Warning, TEXT("News field: " + iNewsID));
		UE_LOG(LogTemp, Warning, TEXT("New News ID: " + asMissionFields[34]));
		iNewsID = asMissionFields[34];
		sNewsLine1 = asMissionFields[35];
		sNewsLine2 = asMissionFields[36];
		sNewsLine3 = asMissionFields[37];
		sNewsLine4 = asMissionFields[38];
		UE_LOG(LogTemp, Warning, TEXT("News: " + sNewsLine1));
		UE_LOG(LogTemp, Warning, TEXT("News: " + sNewsLine2));
		UE_LOG(LogTemp, Warning, TEXT("News: " + sNewsLine3));
		UE_LOG(LogTemp, Warning, TEXT("News: " + sNewsLine4));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Missions data:" + sMissions));
		sMissions = sMissions + ",";
		Split(sMissions, ",", asMissionFields);
		for (iMissionField = 0; iMissionField < 33; iMissionField++)
		{
			sTemp = asMissionFields[iMissionField];
			iCompleted[iMissionField] = sTemp;
			Log("Parsed mission: " + iMissionField + " value: " + iCompleted[iMissionField]);
		}
		if (asMissionFields[33] >= 0 && asMissionFields[33] <= 40)
		{
			iRifleRangeRating = asMissionFields[33];
		}
		if (PlayerReplicationInfo == nullptr && GetNetMode() == ENetMode::NM_Standalone)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawning new PRI for single player training mission"));
			PlayerReplicationInfo = Spawn(APlayerReplicationInfo::StaticClass(), this);
		}
		if (PlayerReplicationInfo != nullptr)
		{
			if (asMissionFields.Num() > 34)
			{
				PlayerReplicationInfo._iTrust = asMissionFields[34];
				PlayerReplicationInfo._bSoldiersCharacter = asMissionFields[35];
				PlayerReplicationInfo._Experience = asMissionFields[36];
				iCDG = asMissionFields[37];
				PlayerReplicationInfo.SetGroup(asMissionFields[37]);
			}
		}
		iUID = asMissionFields[38];
		UpdateAuthRelatedPRI();
	}
	*/
}

void AHumanController::UpdateAuthRelatedPRI()
{
	int32 iMissionIndex;
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (PlayerReplicationInfo != nullptr)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Setting PRI.AuthUserName to '%s'"));
			PlayerReplicationInfo->AuthUserName = UserName;
			for (iMissionIndex = 0; iMissionIndex < 20; iMissionIndex++)
			{
				UE_LOG(LogTemp, Warning, TEXT("iCompleted[ %d ] = %d"),iMission, iCompleted[iMission]);
			}
			if (iCompleted[1] == 15)
			{
				PlayerReplicationInfo->bQualifiedBCT = true;
			}
			if (iCompleted[5] == 3)
			{
				PlayerReplicationInfo->bQualifiedSniper = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedSniper = false;
			}
			if (iRifleRangeRating < 36)
			{
				PlayerReplicationInfo->bQualifiedSniper = false;
			}
			if (iCompleted[6] == 3)
			{
				PlayerReplicationInfo->bQualifiedAirborne = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedAirborne = false;
			}
			if (iCompleted[8] == 3)
			{
				PlayerReplicationInfo->bQualifiedRanger = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedRanger = false;
			}
			if (iCompleted[10] == 15)
			{
				PlayerReplicationInfo->bQualifiedMedic = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedMedic = false;
			}
			if (iCompleted[11] == 3 && PlayerReplicationInfo->GetHonor() >= 15)
			{
				PlayerReplicationInfo->bQualifiedSF = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedSF = false;
			}
			if ((iCompleted[14] & 1) == 1)
			{
				PlayerReplicationInfo->bQualifiedJavelin = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedJavelin = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("Javelin training flag is: %s"), PlayerReplicationInfo->bQualifiedJavelin ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 8) != 0)
			{
				PlayerReplicationInfo->bQualifiedES2 = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedES2 = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("bQualifiedES2 training flag is: %s"), PlayerReplicationInfo->bQualifiedES2 ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 2) != 0)
			{
				PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedDriveHMMWV = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("HMMWV Driver qualified: %s"), PlayerReplicationInfo->bQualifiedDriveHMMWV ? TEXT("true") : TEXT("false"));
			if ((iCompleted[14] & 4) != 0)
			{
				PlayerReplicationInfo->bQualifiedUseCROWS = true;
			}
			else
			{
				PlayerReplicationInfo->bQualifiedUseCROWS = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("HMMWV CROWS qualified: %s"), PlayerReplicationInfo->bQualifiedUseCROWS ? TEXT("true") : TEXT("false"));
			
			/*
			if (Cast<AAGP_GameInfo>(GetGameMode()).bAutoAT && !PlayerReplicationInfo->bQualifiedUseCROWS || !PlayerReplicationInfo->bQualifiedDriveHMMWV || !PlayerReplicationInfo->bQualifiedES2 || !PlayerReplicationInfo->bQualifiedJavelin)
			{
				UE_LOG(LogTemp, Warning, TEXT("AT Enabled for user"));
				PlayerReplicationInfo->bQualifiedUseCROWS = true;
				PlayerReplicationInfo->bQualifiedDriveHMMWV = true;
				PlayerReplicationInfo->bQualifiedJavelin = true;
				PlayerReplicationInfo->bQualifiedES2 = true;
			}
			*/
			if (PlayerReplicationInfo->_iTrust < 20 && !PlayerReplicationInfo->bQualifiedBCT)
			{
				PlayerReplicationInfo->bQualifiedAirborne = true;
				PlayerReplicationInfo->bQualifiedRanger = true;
			}
			if (!TournamentIsTournament())
			{
				//UE_LOG(LogTemp, Warning, TEXT("HumanController::UpdateAuthRelatedPRI()  - Testing " + UserName + " for PlayerAdmin rights"));
				/*
				if (!PlayerReplicationInfo->bAdmin && Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo) && !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() || PlayerReplicationInfo->SuperUser())
				{
					if (Level.Game.NumAdmins < Level.Game.MaxAdmins)
					{
						UE_LOG(LogTemp, Warning, TEXT("Player Admin added"));
						PlayerReplicationInfo->bAdmin = true;
						ClientMessage("You are a player administrator on this server.");
						//Level.Game.NumAdmins++;
					}
					else
					{
						PlayerReplicationInfo->bAdmin = false;
						PlayerReplicationInfo->bPlayerAdmin = false;
						UE_LOG(LogTemp, Warning, TEXT("No space for Player Admin"));
						ClientMessage("The Maximum number of administrators are already logged in. You are logged in as a regular player.");
					}
				}
				else
				{
					if (Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo) && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && !PlayerReplicationInfo.SuperUser())
					{
						ClientMessage("You do not have sufficient rights to be a player administrator on this official server.");
						NotifyAdminMessage("You do not have sufficient rights to be a player administrator on this official server.");
					}
				}
				*/
			}
		}
		PlayerReplicationInfo->PostAuthComplete();
	}
}
FString AHumanController::AddField(FString Mission, FString Field)
{
	return Mission + Field + ",";
}

FString AHumanController::BitsetToString(int32 Bitset)
{
	int32 BitIndex = 0;
	FString S = "";
	for (BitIndex = 0; BitIndex < 32; BitIndex++)
	{
		/*
		if ((int((2 * *float(BitIndex))) & Bitset) != 0)
		{
			S += Eval((Len(S) > 0), ", ", "") + FString::FromInt(BitIndex);
		}
		*/
	}
	return S;
}
FString AHumanController::GenerateMissionString()
{
	int32 iCounter = 0;
	FString sMissions= "";

	if (PlayerReplicationInfo == nullptr)
	{
		return "";
	}
	/*
	for (iCounter = 0; iCounter < 33; iCounter++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tour " + iCounter + " is " + iCompleted[iCounter] @ "(" + BitsetToString(iCompleted[iCounter]) + ")"));
		sMissions = sMissions + iCompleted[iCounter] + ",";
	}
	sMissions = sMissions + iRifleRangeRating + ",";
	sMissions = AddField(sMissions, PlayerReplicationInfo._iTrust);
	sMissions = AddField(sMissions, "0");
	sMissions = AddField(sMissions, PlayerReplicationInfo._Experience);
	UE_LOG(LogTemp, Warning, TEXT("HumanController::GenerateMissionString() - Experience: " + PlayerReplicationInfo.GetExperience()));
	sMissions = AddField(sMissions, PlayerReplicationInfo.GetGroup());
	sMissions = AddField(sMissions, iUID);
	*/
	return sMissions;
}

void AHumanController::Shake(float Time, float Intensity)
{
	ClientGlobalCameraScreenShake(Time, 200);
}
void AHumanController::SetAutoLoggedInRunOnce()
{
}

bool AHumanController::HasAutoLoggedInRunOnce()
{
	return false;    //FAKE   /ELiZ
}

void AHumanController::SetNightVision(bool Set)
{
}
void AHumanController::ClientGlobalCameraScreenShake(float ShakeTime, float ShakeIntensity)
{
}
void AHumanController::TournamentWarmupClientGameEnded()
{
	if (bPBChecked == false)
	{
		return;
	}
	
	if (PlayerReplicationInfo->IsOnlyASpectator())
	{
		return;
	}
	ChangeState("GameEnded");
	if (GetPawn() != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->bWantsToProne = false;
		Cast<AAGP_Pawn>(GetPawn())->bWantsToCrouch = false;
	}
	//CleanOutSavedMoves();
}

bool AHumanController::CanFire()
{
	if (bTurn180 != 0)
	{
		bFire = 0;
		bAltFire = 0;
		UE_LOG(LogTemp, Warning, TEXT("Player cannot shoot while turning around"));
		ClientMessage("You are busy and cannot shoot.");
		return false;
	}
	if (bAction != 0)
	{
		bFire = 0;
		bAltFire = 0;
		UE_LOG(LogTemp, Warning, TEXT("Player cannot shoot while busy"));
		ClientMessage("You are busy and cannot shoot.");
		return false;
	}
	/*
	if (GetPawn()!= nullptr && Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyProning'))
	{
		bFire = 0;
		bAltFire = 0;
		ClientMessage("You cannot fire while going prone.");
		return false;
	}
	*/
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		bFire = 0;
		bAltFire = 0;
		ClientMessage("You cannot fire while sprinting.");
		return false;
	}
	//return Super::CanFire();
	return false;      //FAKE    /ELiZ
}
void AHumanController::TurnAround()
{
	if (bAction != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player cannot turn while busy"));
		return;
	}
	bFire = 0;
	bAltFire = 0;
	TurnAround();
}

void AHumanController::CleanUp()
{
	AAGP_Pawn* p = nullptr;
	AEmitter* E = nullptr;
	int32 i = 0;
	/*
	if (Role != 4)
	{
		ForEach AllActors(Class'Emitter', E)
		{
			E.MatchStarting();
		}
	}
	CleanUp();
	CleanOutSavedMoves();
	p = Cast<AAGP_Pawn>(GetPawn());
	if (p != nullptr)
	{
		if (p.Weapon != nullptr)
		{
			p.Weapon.UnZoom();
		}
		p.ResetLean();
		p.CleanupOptics();
		p.LimitRotation(false);
		p.LockMovement(false);
		Pawn.bWantsToProne = false;
		Pawn.bWantsToCrouch = false;
	}
	bNoThrowWeapon = false;
	SetNightVision(false);
	bAction = 0;
	StopFiring();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		LockPlayer(false, false);
	}
	else
	{
		if (GetNetMode() == ENetMode::NM_Standalone && "" + Level ~= "Entry.LevelInfo0")
		{
			UE_LOG(LogTemp, Warning, TEXT("BeginPlay() for standalone - locking player"));
			LockPlayer(true, true);
		}
	}
	*/
	_GrenadeShakeTime = 0;
	_GrenadeShakeUpdate = 0;
	_GrenadeSoundTime = 0;
	_GrenadeSoundUpdate = 0;
	_GrenadeSoundIntensity = 0;
	_FlashSoundTime = 0;
	_FlashSoundUpdate = 0;
	_FlashSoundIntensity = 0;
	if (_FlashEffect != nullptr)
	{
		_FlashEffect->EndFlash(this);
	}

	/*
	RemoveCameraEffect(_FlashEffect);
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::CleanUp() - Praying for AGP_HUD not to crash! PawnOwner was " + Cast<AAGP_HUD>(MyHUD)->PawnOwner, true));
		Cast<AAGP_HUD>(MyHUD)->bDrawHUD = false;
		if (_cHUDCommoInfo == nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			_cHUDCommoInfo = HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(false);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	abpobjESSLastSeen = nullptr;
	LastReportableNPC = nullptr;
	i = 0;
	if (i < FoundESSObject.Num())
	{
		FoundESSObject.RemoveAt(i, 1);
	}
	*/
}

void AHumanController::CleanupLevel()
{
	AAGP_Pawn* p = nullptr;
	/*
	ForEach DynamicActors('AGP_Pawn', p)
	{
		if (p->IsA(ANPC_Ambient::StaticClass()))
		{
			if (p.bDontPossess)
			{
				p.MatchStarting();
			}
		}
		else
		{
			if (p->IsA(ANPC_doctor::StaticClass) || p->IsA(ANPC_soldier::StaticClass()) || p->IsA(ANPC_civilian::StaticClass()) || p->IsA(ANPC_SpecialForces::StaticClass()))
			{
				if (p.bDontPossess)
				{
					p.MatchStarting();
				}
			}
		}
		if (p->IsA(AAGP_Vehicle::StaticClass()))
		{
			p.Destroy();
		}
		if (GetNetMode() != ENetMode::NM_Standalone && p.bTearOff)
		{
			p.Destroy();
		}
	}
	Level.DecalSession++;
	*/
}

void AHumanController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	/*
	int32 NewLean;
	int32 iUserNameCalculatedChecksum;
	if (Pawn != nullptr && Pawn.bIsSprinting)
	{
		bAction = 0;
		bFire = 0;
		bAltFire = 0;
	}
	if (fCD1 && fCD2 && GetNetMode() == ENetMode::NM_Client && bIsAuthorizedServer)
	{
		if (GetWorld()->GetTimeSeconds() - fpCDTime > fpCADelayTime)
		{
			Log("Internal Error - " + sFailReason);
			UE_LOG(LogTemp, Warning, TEXT("Cheat detection trying method: " + iCDAction));
			switch(iCDAction)
			{
					case 0:
						Pawn.Weapon.Zoom();
						Pawn.LimitRotation(true);
						Pawn.LockMovement(true);
						ClientFlashBanged(100, 1, 1);
						ConsoleCommand("quit");
						break;
					case 1:
						ConsoleCommand("disconnect");
						break;
					case 2:
						ConsoleCommand("reconnect");
						break;
					case 3:
					case 4:
					case 5:
						InduceFailure();
						UE_LOG(LogTemp, Warning, TEXT("Cheat detection trying to force crash"));
						break;
					case 6:
						ConsoleCommand("load " + "leaven" + "worth" + ".aao");
						return;
					default:
						InduceFailure();
						break;
			}
		}
	}
	if (Pawn == nullptr)
	{
		PlayerTick(DeltaTime);
	}
	else
	{
		if (bIsAuthorizedServer && GetNetMode() == ENetMode::NM_Client && GetWorld()->GetTimeSeconds() > fLastNameTest)
		{
			fLastNameTest = GetWorld()->GetTimeSeconds() + 2;
			if (Player.Console.Class != "Engine.Console" && Player.Console.Class != "XInterface.ExtendedConsole")
			{
				UE_LOG(LogTemp, Warning, TEXT("Invalid Console Detected: " + Player.Console.Class));
				fpCADelayTime = Rand(15);
				fpCDTime = GetWorld()->GetTimeSeconds();
				fCD1 = true;
				fCD2 = true;
				sFailReason = "Failure: BC";
				iCDAction = Rand(6);
				return;
			}
			if (!bExploreTheArmyServer && PlayerReplicationInfo != nullptr && iCDG != PlayerReplicationInfo.GetGroup() && iCDG > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Mismatched Group: " + iCDG + " vs. current: " + PlayerReplicationInfo.GetGroup()));
				fpCADelayTime = Rand(30);
				fpCDTime = GetWorld()->GetTimeSeconds();
				fCD1 = true;
				fCD2 = true;
				sFailReason = "Failure: BG";
				iCDAction = Rand(6);
				return;
			}
			if (PlayerReplicationInfo != nullptr)
			{
				if (!bExploreTheArmyServer && Len(PlayerReplicationInfo.PlayerName) != 0 && iUNC != 0)
				{
					iUserNameCalculatedChecksum = CalculateUserNameChecksum(PlayerReplicationInfo.PlayerName);
					if (iUNC != iUserNameCalculatedChecksum)
					{
						UE_LOG(LogTemp, Warning, TEXT("Invalid checksum detected"));
						if (fCD1 == false && fCD2 == false && fpCADelayTime == 0 && fpCDTime == 0)
						{
							fpCADelayTime = Rand(30);
							fpCDTime = GetWorld()->GetTimeSeconds();
							fCD1 = true;
							fCD2 = true;
							sFailReason = "Failure: BN";
							iCDAction = Rand(6);
							return;
						}
						else
						{
							if (fCD1 == false || fCD2 == false || fpCADelayTime == 0 || fpCDTime == 0)
							{
								Log("Internal error: CD1");
								InduceFailure();
							}
						}
					}
				}
			}
		}
		if (bAction != bLastAction)
		{
			bLastAction = bAction;
			ChangeActionStatus(bAction);
		}
		if (!bToggleLean && CanLean() && bLeanRight != bLastLeanRight || bLeanLeft != bLastLeanLeft)
		{
			bLastLeanRight = bLeanRight;
			bLastLeanLeft = bLeanLeft;
			NewLean = 0;
			if (bLeanRight != 0)
			{
				NewLean++;
			}
			if (bLeanLeft != 0)
			{
				NewLean--;
			}
			if (NewLean < 0)
			{
				Pawn.LeanLeft(true);
			}
			else
			{
				if (NewLean == 0)
				{
					Pawn.ResetLean();
				}
				else
				{
					Pawn.LeanRight(true);
				}
			}
		}
		PlayerTick(DeltaTime);
		if (!Level.IsEntry())
		{
			AutoTrace();
		}
	}
	*/
}
float AHumanController::GetSoundDampening()
{
	if (_FlashSoundTime > 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("Flashbang Sound Dampening"));
		}
		if (_FlashSoundUpdate < _FlashSoundTime)
		{
			return (0.15 / _FlashSoundIntensity);
		}
	}
	if (_GrenadeSoundTime > 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("Grenade Sound Dampening"));
		}
		if (_GrenadeSoundUpdate < _GrenadeSoundTime)
		{
			return (0.15 / _GrenadeSoundIntensity);
		}
	}
	return 1;
}

void AHumanController::CalcSoundDampening()
{
	float ContDamp;
	float WeapDamp;
	float PawnDamp;
	ContDamp = 1;
	WeapDamp = 1;
	PawnDamp = 1;
	ContDamp = GetSoundDampening();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("Sound Dampening= %i" ));
	}
	if (GetPawn() != nullptr)
	{
		//PawnDamp = Cast<AAGP_Pawn>(GetPawn())->GetSoundDampening();
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
		{
			WeapDamp = Cast<AAGP_Pawn>(GetPawn())->Weapon->GetSoundDampening();
		}
	}
	//SoundDampening = FMin(ContDamp, FMin(WeapDamp, PawnDamp));
}

void AHumanController::Timer()
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		CheckOutOfBounds();
		if (bBoundaryTrigger)
		{
			//TriggerEvent(BoundaryEvent, this, Pawn);
			//bBoundaryTrigger = false;
		}
	}
	else
	{
		IdleCheck();
	}
}
void AHumanController::IdleCheck()
{
	/*
	if (GetWorld()->GetTimeSeconds() < NextIdleCheck || Level.Game == nullptr || PlayerReplicationInfo == nullptr || !Level.Game.TestForIdlePlayers(PlayerReplicationInfo))
	{
		return;
	}
	if (bNotIdle || IdleLocation != ViewTarget.Location || IdleRotation != ViewTarget.Rotation)
	{
		IdleLocation = ViewTarget.Location;
		IdleRotation = ViewTarget.Rotation;
		LastMovedTime = GetWorld()->GetTimeSeconds();
		NextIdleCheck = GetWorld()->GetTimeSeconds() + 20;
		bNotIdle = false;
		bIdleWarning = 0;
	}
	else
	{
		if (Level.Game.NotifyIdlePlayer(this, LastMovedTime))
		{
			NextIdleCheck = GetWorld()->GetTimeSeconds() + 3;
		}
		else
		{
			NextIdleCheck = GetWorld()->GetTimeSeconds() + 20;
		}
	}
	*/
}

void AHumanController::SetHUDAlpha(uint8 A)
{
	HUDAlpha = A;
}

void AHumanController::SetHUDColor(uint8 H)
{
	HUDColor = H;
}

void AHumanController::SetHUDCrosshair(uint8 C)
{
	HUDCrosshair = C;
}

void AHumanController::NextCrosshair()
{

}

void AHumanController::SetSkin(FString S)
{
	S = S.ToUpper();
	if (S.FString::Contains("DARK", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
	{
		S = "SKINPREF_African";
	}
	else
	{
		if (S.FString::Contains("MEDIUM", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
		{
			S = "SKINPREF_Latino";
		}
		else
		{
			if (S.FString::Contains("LIGHT", ESearchCase::CaseSensitive, ESearchDir::FromEnd))
			{
				S = "SKINPREF_Caucasian";
			}
			else
			{
				S = "SKINPREF_None";
			}
		}
	}
	SetSkinPreference(S);
}

bool AHumanController::TestIdle_Location()
{
	FVector distFromStart = FVector(0, 0, 0);
	/*
	distFromStart = (Pawn.Location - StartSpot.GetStartLocation());
	if (distFromStart.Z < float(200))
	{
		distFromStart.Z = 0;
	}
	return (VSize(distFromStart) < float(100));
	*/
	return false;    //FAKE   /ELiZ
}

bool AHumanController::TestIdle_Rotation()
{
	float DeltaYaw = 0;
	/*
	DeltaYaw = Abs(float((Pawn.Rotation.Yaw - StartSpot.GetStartRotation().Yaw)));
	if (DeltaYaw > float(32768))
	{
		DeltaYaw = Abs((DeltaYaw - float(65536)));
	}
	*/
	return (DeltaYaw < float(1024));
}
bool AHumanController::TestIdle_Weapon()
{
	AWeapon* W;
	AAmmunition* A;
	AAGP_Pawn* P;
	P = Cast<AAGP_Pawn>(GetPawn());
	if (P == nullptr)
	{
		return false;
	}
	W= P->Weapon;
	if (W == nullptr)
	{
		return true;
	}
	if (W->IsA(AThrowWeapon::StaticClass()))
	{
		return false;
	}
	A = Cast<AWeapon>(W)->AmmoType;

	//return A == NULL || A->AmmoAmount == A->Default->AmmoAmount;
	return A == nullptr;   //FAKE ELiZ
}
void AHumanController::IdleCheckPerRound(bool bEndGame)
{
	/*
		if (Level.Game == nullptr)
		{
			return;
		}
		if (Level.Game.GetTimeElapsed() < 20)
		{
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("HumanController::IdleCheckPerRound()	" + this @ Pawn + " Idle rounds: " + nIdleRounds + " bTestedIdleRounds: " + bTestedIdleRounds));
		if (Pawn != nullptr && ! bTestedIdleRounds)
		{
			if (StartSpot != nullptr && TestIdle_Location() && TestIdle_Rotation() && TestIdle_Weapon())
			{
				nIdleRounds ++;
			}
			else
			{
				nIdleRounds=0;
			}
		}
		if (nIdleRounds > 0)
		{
			Level.Game.NotifyIdlePlayerRounds(this,nIdleRounds,bEndGame);
		}
		bTestedIdleRounds=true;
	*/
}
void AHumanController::PawnDied(APawn* p)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		fpTimePlayedLastRound=AGP_GameInfo(GetGameMode()).TimeLimit * 60 - GameReplicationInfo.RemainingTime;
	}
	if (_cHUDCommoInfo != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(false);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	IdleCheckPerRound();
	PawnDied(p);
	*/
}
void AHumanController::NotifyImpendingIdleKick(bool bIdleRounds)
{
	if (Cast<AAGP_HUD>(MyHUD) == NULL)
	{
		return;
	}
	if (bIdleRounds)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(20,"IDLE WARNING!","If you are Idle for 1 more round, you will be auto-kicked");
		bIdleWarning=1;
	}
	else
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,"IDLE WARNING!","Move or rotate your view to avoid being auto-kicked");
		bIdleWarning=2;
	}
}
void AHumanController::RenderOverlays_Stage1(UCanvas* Canvas)
{
	/*
		if (Pawn == nullptr || Vehicle(Pawn) != nullptr)
		{
			return;
		}
		RenderOverlays(Canvas,true);
	*/
}

void AHumanController::RenderOverlays_Stage2(UCanvas* Canvas)
{
	int32 i = 0;
	int32 j = 0;
	int32 Alpha = 0;
	float TimeElapsed = 0;
	float TimeScale = 0;
	AAGP_Pawn* myPawn = nullptr;
	/*
	if (Pawn != nullptr)
	{
		myPawn=Cast<AAGP_Pawn>(GetPawn());
	}
	else
	{
		return;
	}
	RenderOverlays(Canvas,false);
	if (Role == 4 && Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().Draw(Canvas);
	}
	if (myPawn == nullptr && Vehicle(Pawn) != nullptr && Vehicle(Pawn).Driver != nullptr)
	{
		myPawn=Cast<AAGP_Pawn>(Cast<AVehicle>(Pawn).Driver);
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr && ! Cast<AAGP_HUD>(MyHUD)->bShowMainMenu && Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice() != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice().IsActive())
	{
		Cast<AAGP_Pawn>(GetPawn()).GetOpticsDevice().RenderOverlays(Canvas,false);
	}
	if (prevHealth - 10 > myPawn.Health)
	{
		_fDamageTime=GetWorld()->GetTimeSeconds();
	}
	prevHealth=myPawn.Health;
	if (_fDamageTime != 0)
	{
		if (GetWorld()->GetTimeSeconds() - _fDamageTime > 0.1)
		{
			_fDamageTime=0;
		}
		else
		{
			Canvas->Style=5;
			Canvas->SetPos(0,0);
			Canvas->DrawTile(_tPainOverlay,Canvas->SizeX,Canvas->SizeY,0,0,512,512);
		}
	}
	for (i=0; i<LaserDots.Num(); i++)
	{
		TimeElapsed=GetWorld()->GetTimeSeconds() - LaserDots[i].LaserDotTimeStarted;
		if (TimeElapsed > 2)
		{
			if (LaserDots.Num() > 1)
			{
				j=i;
				if (j < LaserDots.Num() - 1)
				{
					LaserDots[j]=LaserDots[j + 1];
					j ++;
				}
				LaserDots.Num()=LaserDots.Num() - 1;
				i -= 1;
			}
			else
			{
				LaserDots.Num()=0;
			}
		}
		else
		{
			TimeScale=1 - TimeElapsed / 2;
			Alpha=TimeScale * LaserDots[i].LaserDotIntensity * 255;
			if (Alpha > 0)
			{
				Canvas->SetDrawColor(255,255,255,TimeScale * LaserDots[i].LaserDotIntensity * 255);
				Canvas->Style=7;
				Canvas->SetPos(0,0);
				Canvas->DrawTile(LaserDotOverlay,Canvas->SizeX,Canvas->SizeY,0,0,512,512);
			}
		}
	}
	Canvas->Style=Canvas->Default.Style;
	*/
}
FString AHumanController::TwoDigitString(int32 Num)
{
	if (Num < 10 && Num >= 0)
	{
		return "0" + FString::FromInt(Num);
	}
	else
	{
		return FString::FromInt(Num);
	}
}
bool AHumanController::CheckFlashTime()
{
	float deltaT;
	float deltaF;
		
	deltaT= (GetWorld()->GetTimeSeconds()) - fLastFlashTime;
	deltaF=1 / 2 * 2;
	if (deltaT > deltaF * 2)
	{
		fLastFlashTime= GetWorld()->GetTimeSeconds();
		return false;
	}
	else
	{
		if (deltaT > deltaF)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void AHumanController::SetStartupStage(EStartupStage Stage)
{
	StartupStage=Stage;
	if (StartupStage == EStartupStage::STAGE_Starting)
	{
		NotifyStartupStage(false);
	}
	else
	{
		if (StartupStage == EStartupStage::STAGE_MatchInProgress)
		{
			NotifyStartupStage(true);
		}
	}
}
void AHumanController::NotifyStartupStage(bool bfadein)
{
	
	if (bfadein == true && bFlushOnRoundRestart == true)
	{
		//ConsoleCommand("flush");
	}
	DoFade(bfadein,true,1.25f, 0.0f);
	
}
void AHumanController::PlayStartupMessage(UCanvas* Canvas)
{
	Canvas->SetDrawColor(255, 0, 0, 255);
	//Canvas->SetPos(50, 50);
	switch(StartupStage)
	{
	case EStartupStage::STAGE_WaitForEnoughPlayers:
		//Canvas->DrawText("Startup: Waiting for other players before starting match");
		break;
	case EStartupStage::STAGE_WaitForReadyPlayers:
		//Canvas->DrawText("Startup: Waiting for all players to be ready");
		break;
	case EStartupStage::STAGE_Starting:
		//Canvas->DrawText("Startup: Match is starting in a few seconds ...");
		break;
	case EStartupStage::STAGE_Dead:
		//Canvas->DrawText("Startup: YOU ARE DEAD! Waiting for next match to start");
		break;
	case EStartupStage::STAGE_CanRespawn:
		//Canvas->DrawText("Startup: YOU ARE DEAD! Press any key to respawn.");
		break;
	case EStartupStage::STAGE_Spectator:
		//Canvas->DrawText("Startup: Spectator");
		break;
	case EStartupStage::STAGE_Autobalance:
		//Canvas->DrawText("Startup: AutoBalancing has moved you to the other team");
		break;
	case EStartupStage::STAGE_MatchOver:
		//Canvas->DrawText("Startup: Match is over! Preparing for new match");
		break;
	case EStartupStage::STAGE_Connecting:
		//Canvas->DrawText("Startup: Connecting to the game...");
		break;
	case EStartupStage::STAGE_WaitingForNextMatch:
		//Canvas->DrawText("Startup: You must wait for the next match to join the game");
		break;
	case EStartupStage::STAGE_LostConnection:
		//Canvas->DrawText("Startup: Lost Connection");
		break;
	case EStartupStage::STAGE_MatchInProgress:
		//Canvas->DrawText("Startup: Match In Progress - IGNORE THIS!");
		break;
	default:
		//UE_LOG(LogTemp, Warning, TEXT("HumanController::PlayStartupMessage()	Unknown StartupStage " + StartupStage));
		break;
	}
}

void AHumanController::FlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
	if (bGodMode)
	{
		return;
	}
	if (_FlashEffect != nullptr && VisIntensity != 0)
	{
		_FlashEffect->StartFlash(Duration,VisIntensity,this);
	}
	if (AudIntensity != 0)
	{
		_FlashSoundTime += Duration * AudIntensity * 1.5;
		_FlashSoundUpdate=0;
		_FlashSoundIntensity=AudIntensity;
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientFlashBanged(Duration,VisIntensity,AudIntensity);
	}
}

void AHumanController::ClientFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
	if (bGodMode)
	{
		return;
	}
	if (_FlashEffect != nullptr && VisIntensity != 0)
	{
		_FlashEffect->StartFlash(Duration,VisIntensity,this);
	}
	if (AudIntensity != 0)
	{
		_FlashSoundTime += Duration * AudIntensity * 1.5;
		_FlashSoundUpdate=0;
		_FlashSoundIntensity=AudIntensity;
	}
}

void AHumanController::GrenadeExploded(float Duration, float Intensity)
{
	/*
		if (Level.GamePlayMode == 1)
		{
			Intensity *= 0.5;
		}
		StartScreenShake(Duration * Intensity);
	*/
}

void AHumanController::Grenaded(float Duration, float AudIntensity)
{
	/*
		if (AudIntensity != 0)
		{
			_GrenadeSoundTime += Duration;
			_GrenadeSoundUpdate=0;
			_GrenadeSoundIntensity=AudIntensity;
		}
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			ClientGrenaded(Duration,AudIntensity);
		}
	*/
}

void AHumanController::ClientGrenaded(float Duration, float AudIntensity)
{
	if (AudIntensity != 0)
	{
		_GrenadeSoundTime += Duration;
		_GrenadeSoundUpdate=0;
		_GrenadeSoundIntensity=AudIntensity;
	}
}

void AHumanController::StartScreenShake(float ShakeTime)
{
	/*
		_GrenadeShakeTime=FMax(_GrenadeShakeTime,ShakeTime);
		_GrenadeShakeUpdate=0;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			ClientStartScreenShake(_GrenadeShakeTime);
		}
	*/
}

void AHumanController::ClientStartScreenShake(float ShakeTime)
{
	_GrenadeShakeTime=ShakeTime;
	_GrenadeShakeUpdate=0;
}

void AHumanController::ClientStartViewShake(int32 NewHitShakeAngle, float NewHitShakeOffset, float NewHitShakeMin, float NewHitShakeMax, float NewHitShakeRate)
{
	FRotator ShakeRotator;
	HitShakeVector = FVector(1,0,0);
	ShakeRotator.Pitch = 0;
	ShakeRotator.Yaw = NewHitShakeAngle;
	ShakeRotator.Roll = 0;
	//Normalize(ShakeRotator);
	HitShakeOffset = NewHitShakeOffset;
	HitShakeMin = NewHitShakeMin;
	HitShakeMax = NewHitShakeMax;
	HitShakeRate = NewHitShakeRate;
	//HitShakeVector = HitShakeVector >> ShakeRotator;
}

void AHumanController::PostRender(UCanvas* Canvas)
{
	float fFadeTime = 0;
	int32 iFadePos = 0;
	FColor OldColor = FColor(0,0,0,0);
	FColor FadeToColor = FColor(0, 0, 0, 0);
	FName Anim = "";
	float frame = 0;
	float Rate = 0;
	/*
	if (_bAutoTraceDebug || _bPermaTraceDebug)
	{
		if (_AnimPawn != nullptr)
		{
			Canvas->SetPos(0,0);
			Canvas->DrawText("bWantsToCrouch: " + _AnimPawn.bWantsToCrouch + " bIsCrouched: " + _AnimPawn.bIsCrouched + " bWantsToProne: " + _AnimPawn.bWantsToProne + " bIsProne: " + _AnimPawn.bIsProne);
			if (_AnimPawn.Attached.Num() > 0)
			{
				Canvas->SetPos(0,50);
				Canvas->DrawText("Attached[0]: " + _AnimPawn.Attached[0]);
			}
			_AnimPawn.GetAnimParams(0,Anim,frame,Rate);
			Canvas->SetPos(0,100);
			Canvas->DrawText("AnimSequence " + Anim + " Frame " + frame + " Rate " + Rate + " Rot:" + _AnimPawn.Rotation);
			if (_AnimPawn.Controller != nullptr)
			{
				Canvas->SetPos(0,120);
				Canvas->DrawText("Controller Rot:" + _AnimPawn.Controller.Rotation);
			}
			Canvas->SetPos(0,140);
			Canvas->DrawText("Location: " + _AnimPawn.Location);
			Canvas->SetPos(0,150);
			Canvas->DrawText("Base: " + _AnimPawn.Base);
			Canvas->SetPos(0,160);
			Canvas->DrawText("OnLadder " + _AnimPawn.OnLadder);
			Canvas->SetPos(0,170);
			Canvas->DrawText("Physics " + _AnimPawn.Physics);
			Canvas->SetPos(0,180);
			Canvas->DrawText("UpperBodyAnim" @ _AnimPawn.UpperBodyAnim @ "FullBodyAnim" @ _AnimPawn.FullBodyAnim);
		}
		Canvas->SetPos(Canvas->SizeX / 2,Canvas->SizeY / 2);
		Canvas->DrawText(_AutoTraceString);
	}
	if (bCheatVerbose)
	{
		PlayStartupMessage(Canvas);
	}
	if (! _bFirstFadeIn)
	{
		if (Level != nullptr && Level.Game != nullptr && Level.Game.GetScreenplay() != nullptr)
		{
			DoFade(true,True,3);
		}
		if (MyHUD != nullptr && MyHUD.PlayerConsole != nullptr)
		{
			MyHUD.PlayerConsole.bNoDrawWorld=false;
		}
		_bFirstFadeIn=true;
	}
	if (_bFade)
	{
		Canvas->bNoSmooth=true;
		fFadeTime=GetWorld()->GetTimeSeconds() - _fFadeStartTime;
		OldColor=Canvas->DrawColor;
		Canvas->SetPos(0,0);
		if (_bFadeBlack)
		{
			FadeToColor.R=0;
			FadeToColor.G=0;
			FadeToColor.B=0;
		}
		else
		{
			FadeToColor.R=255;
			FadeToColor.G=255;
			FadeToColor.B=255;
		}
		fFadeTime=FClamp(fFadeTime / _fFadeTime,0,1);
		if (fFadeTime == 1 && _bFadeIn)
		{
			_bFade=false;
		}
		if (! _bFadeIn)
		{
			iFadePos=255 * fFadeTime;
		}
		else
		{
			iFadePos=255 - 255 * fFadeTime;
		}
		FadeToColor.A=iFadePos * _fFadePercentage;
		Canvas->Style=6;
		Canvas->DrawColor=FadeToColor;
		Canvas->DrawTile(Texture'White',Canvas->SizeX,Canvas->SizeY,0,0,16,16);
		Canvas->DrawColor=OldColor;
		Canvas->bNoSmooth=false;
	}
	Canvas->Style=Canvas->Default.Style;
	*/
}

void AHumanController::SetPlayTips(FString InVal, FString inval2, float ttl)
{
	Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(ttl,InVal,inval2);
}

void AHumanController::CalcFirstPersonView(FVector& CameraLocation, FRotator CameraRotation)
{
	/*
		CalcFirstPersonView(CameraLocation,CameraRotation);
		if (IsInState('PlayerRolling') && Pawn.fRollTime > 0)
		{
			CameraRotation.Roll += 65536 * Pawn.Default.fRollTime - Pawn.fRollTime / Pawn.Default.fRollTime * Pawn.iRollDirection;
		}
	*/
}

void AHumanController::CycleZoom()
{
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->CycleZoom();
	}
}

void AHumanController::TRUnZoomWeapon()
{
}

void AHumanController::TRZoomWeapon()
{
}

void AHumanController::TRCrouchDown()
{
}

void AHumanController::TRUnCrouch()
{
}

void AHumanController::Zoom()
{
	if (CanUseWeapon(6))
	{
		if (bAutoWalkZoom)
		{
			if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
			{
				Cast<AAGP_Pawn>(GetPawn())->SetWalking(bSavedWalkingState);
			}
			else
			{
				bSavedWalkingState= Cast<AAGP_Pawn>(GetPawn())->bIsWalking;
				Cast<AAGP_Pawn>(GetPawn())->SetWalking(true);
			}
		}
		Cast<AAGP_Pawn>(GetPawn())->Weapon->ToggleZoom();
	}
}

void AHumanController::NV()
{
	if (GetPawn() == nullptr || Cast<AAGP_HUD>(MyHUD) != nullptr && Cast<AAGP_HUD>(MyHUD)->bShowMainMenu == true)
	{
		return;
	}
	/*
	if (Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->_Scope->HasNVMode() && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
	{
		Cast<AAGP_Pawn>(GetPawn())->Weapon->NV();
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ToggleOptics();
	}
}
void AHumanController::Shadows(FString parm)
{
	/*
		if (parm ~= "none" || parm ~= "off")
		{
			Level.ShadowDetail=SHADOW_None;
			ClientMessage("Shadows disabled.");
		}
		else
		{
			if (parm ~= "blob")
			{
				Level.ShadowDetail=SHADOW_Blob;
				ClientMessage("Using blob shadows.");
			}
			else
			{
				if (parm ~= "detail")
				{
					Level.ShadowDetail=SHADOW_Detail;
					ClientMessage("Using detailed shadows.");
				}
			}
		}
		Level.SaveConfig();
	*/

}
void AHumanController::SetBloom(bool bNewBloomMode)
{
}
void AHumanController::Bloom(FString parm)
{
	if (parm == "0" || parm == "off")
	{
		SetBloom(false);
	}
	else
	{
		SetBloom(true);
	}
}
bool AHumanController::CanLean()
{
	/*
		if (GetPawn() == nullptr || IsInState('PlayerParachuting'))
		{
			return false;
		}
		if (GetLockMovement() || GetLockRotation())
		{
			return false;
		}
	*/
	return Cast<AAGP_Pawn>(GetPawn())->CanLean();
	
}
void AHumanController::ServerWantsToRoll(bool bRollLeft)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		RequestCombatRoll(bRollLeft);
	}
}
void AHumanController::RequestCombatRoll(bool bRollLeft)
{
	if (GetPawn() != nullptr)
	{
		if (bNoRoll)
		{
			return;
		}
		if (! (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && !Cast<AAGP_Pawn>(GetPawn())->CanCombatRoll(false)))
		{
			return;
		}
		if (GetNetMode() == ENetMode::NM_Client)
		{
			ServerWantsToRoll(bRollLeft);
		}
		if (bRollLeft)
		{
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollLeft=true;
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollRight=false;
		}
		else
		{
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollLeft=false;
			Cast<AAGP_Pawn>(GetPawn())->bWantsToRollRight=true;
		}
	}
}
void AHumanController::LeanLeft()
{
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsProne)
	{
		RequestCombatRoll(true);
		return;
	}
	if (! CanLean() || ! bToggleLean)
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->LeanLeft(false);
}
void AHumanController::LeanRight()
{
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->bIsProne)
	{
		RequestCombatRoll(false);
		return;
	}
	if (! CanLean() || ! bToggleLean)
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->LeanRight(false);
}

void AHumanController::LeanCenter()
{
	if (GetPawn() != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ResetLean();
	}
}

void AHumanController::ViewShake(float DeltaTime)
{
	FRotator ViewRotation = FRotator(0,0,0);
	int32 Delta = 0;
	/*
	ViewShake(DeltaTime);
	if (HitShakeRate != 0)
	{
		ViewRotation=Rotation;
		Delta=DeltaTime * HitShakeRate;
		ViewRotation.Pitch += Delta * HitShakeVector.X;
		ViewRotation.Yaw += Delta * HitShakeVector.Y;
		HitShakeOffset += Delta;
		if (HitShakeRate > 0)
		{
			if (HitShakeOffset >= HitShakeMax)
			{
				HitShakeRate *= -0.5;
			}
		}
		else
		{
			if (HitShakeOffset <= HitShakeMin)
			{
				HitShakeRate=0;
			}
		}
		SetActorRotation(ViewRotation);
	}
	*/
}

void AHumanController::UpdateTimers(float DeltaTime)
{
	if (_GrenadeShakeTime > 0)
	{
		_GrenadeShakeTime -= DeltaTime;
		_GrenadeShakeUpdate -= DeltaTime;
		if (_GrenadeShakeUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_GrenadeShakeUpdate=0.1 + 0.15 * FMath::FRand();
		}
	}
		
	if (_FlashSoundTime > 0)
	{
		_FlashSoundTime -= DeltaTime;
		_FlashSoundUpdate -= DeltaTime;
		if (_FlashSoundUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_FlashSoundUpdate=GetSoundDuration(FlashBangDistortion);
			//ResetSoundDampening();
			if (_FlashSoundUpdate > _FlashSoundTime)
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Flash Sound Intensity= %f"), _FlashSoundIntensity);
				}
				//ViewTarget.PlaySound(FlashBangDistortionFade,0,_FlashSoundIntensity,,,,false);
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Flash Sound Intensity= %f"), _FlashSoundIntensity);
				}
				//ViewTarget.PlaySound(FlashBangDistortion,0,_FlashSoundIntensity,,,,false);
			}
			CalcSoundDampening();
		}
	}
	if (_GrenadeSoundTime > 0)
	{
		_GrenadeSoundTime -= DeltaTime;
		_GrenadeSoundUpdate -= DeltaTime;
		if (_GrenadeSoundUpdate < 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			//_GrenadeSoundUpdate=GetSoundDuration(GrenadeDistortion);
			//ResetSoundDampening();
			if (_GrenadeSoundUpdate > _GrenadeSoundTime)
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Grenade Sound Intensity= %f"), _GrenadeSoundIntensity);
				}
				//ViewTarget.PlaySound(GrenadeDistortionFade,0,_GrenadeSoundIntensity,,,,false);
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
				{
					UE_LOG(LogTemp, Log, TEXT("Grenade Sound Intensity= %f"), _GrenadeSoundIntensity);
				}
				//ViewTarget->PlaySound(GrenadeDistortion,0,_GrenadeSoundIntensity,,,,false);
			}
			CalcSoundDampening();
		}
	}
}

int32 AHumanController::Mantle(FVector& out_Point, FVector& out_Normal)
{
	return 0;    //FAKE   /EliZ
}

void AHumanController::DevBug()
{
	/*
		if (Player.bFullScreen)
		{
			ConsoleCommand("togglefullscreen");
		}
		ConsoleCommand("start http://192.168.0.2/ttweb/intbugreport.html");
	*/
}
bool AHumanController::ClientOpenMenu(FString Menu, bool bDisconnect, FString Msg1, FString Msg2)
{
		//Org:
		bAction=0;
		//bLastAction=0;
		//ChangeActionStatus(bAction);
		//return ClientOpenMenu(Menu,bDisconnect,Msg1,Msg2);

		//Copied from PlayerController:

		//if (bDemoOwner && Menu != DemoMenuClass)
		//{
		//	return false;
		//}
		//bAction = 0;

		//if (!Player.GUIController.OpenMenu(Menu, Msg1, Msg2))
		//{
		//	//UnPressButtons();
		//	return false;
		//}
		if (bDisconnect)
		{
			Player->ConsoleCommand("Disconnect");
			return true;
		}

		return true;

}
void AHumanController::AGPGameMenu()
{
		//ClientCloseMenu(true);
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->ToggleAGPGameMenu();
		}
}
void AHumanController::AGPMainMenu()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAIntroMoviePage",false,"","");
}
void AHumanController::AGPLoginMenu()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAPreLoginPage",false,"","");
}

void AHumanController::AGPSplashScreen()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->CloseAllMenus();
	}
	ClientOpenMenu("AGP_Interface.AAIntroMoviePage",false,"","");
}

void AHumanController::OldMainMenu()
{
	return;
	//ClientCloseMenu(true);
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->ToggleAGPMainMenu();
	}
}

void AHumanController::AGPMissionResults()
{
	ClientOpenMenu("AGP_Interface.AAMissionCompletePage",false,"","");
}

void AHumanController::RadarSetZoom(float Meters)
{
	if (Meters >= 1)
	{
		float test = (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarMapSize / Meters) * 52.200001;
		RadarZoom=FMath::Clamp(test,1.0f,1000.f);
	}
}

float AHumanController::RadarGetZoom()
{
	return FMath::RoundFromZero((Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarMapSize / (RadarZoom * 52.200001)));
}

void AHumanController::SAIZoomIn()
{
	if ((PlayerReplicationInfo != nullptr) && (PlayerReplicationInfo->VehicleReplicationInfo != nullptr))
	{
		return;
	}
	if (RadarZoomLevelIndex < (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Num() - 1))
	{
		RadarZoomLevelIndex++;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Num() > RadarZoomLevelIndex)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[RadarZoomLevelIndex]);
	}
}

void AHumanController::SAIZoomOut()
{
	if ((PlayerReplicationInfo != nullptr) && (PlayerReplicationInfo->VehicleReplicationInfo != nullptr))
	{
		return;
	}
	if (RadarZoomLevelIndex > 0)
	{
		RadarZoomLevelIndex--;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Num() > RadarZoomLevelIndex)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[RadarZoomLevelIndex]);
	}
}

void AHumanController::ToggleSAIPlayerInfo()
{
	 bRadarShowPlayerInfo = !bRadarShowPlayerInfo;
}

void AHumanController::ToggleSAISize()
{
	bFullsizeRadar = !bFullsizeRadar;
}

void AHumanController::EnemySpotted()
{
	bool bOldBlockZeroExtent = false;
	AActor* Other = nullptr;
	FRotator CameraRotation = FRotator(0, 0, 0);
	float MaxTraceLength = 0;
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0,0,0);
	/*
	if (PlayerReplicationInfo.isDead() || GetNetMode() == ENetMode::NM_Standalone || CheckRIFlood() || CheckRIFlood())
	{
		return;
	}
	MaxTraceLength=12000;
	PlayerCalcView(Other,StartTrace,CameraRotation);
	EndTrace=StartTrace + MaxTraceLength *  Vector(CameraRotation);
	bOldBlockZeroExtent=Pawn.bBlockZeroExtentTraces;
	Pawn.bBlockZeroExtentTraces=false;
	Other=Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
	Pawn.bBlockZeroExtentTraces=bOldBlockZeroExtent;
	if (Other != nullptr)
	{
		CommoRadio();
		CommoSendMessage(4);
		ServerEnemySpotted(HitLocation.X,HitLocation.Y,HitLocation.Z);
		ClientEnemySpotted(HitLocation.X,HitLocation.Y,HitLocation.Z);
	}
	*/
}
void AHumanController::ServerEnemySpotted(float SpottedX, float SpottedY, float SpottedZ)
{
	/*
		int32 i = 0;
		Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_CombatEnemyContactTime(GetWorld()->GetTimeSeconds);
		for (i=0; i<PlayerReplicationInfo->Team->NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo->Team->ActualList_Player[i] != nullptr && PlayerReplicationInfo->Team->ActualList_Player[i] != PlayerReplicationInfo)
			{
				Cast<AHumanController>(PlayerReplicationInfo->Team->ActualList_Player[i].Owner).ClientEnemySpotted(SpottedX,SpottedY,SpottedZ);
			}
		}
	*/

}

void AHumanController::ClientEnemySpotted(float SpottedX, float SpottedY, float SpottedZ, float SpotDuration)
{
	int32 i = 0;
	FEnemySpottedData SpottedEnemy;
	bool bFoundEnemy = false;
	/*
	ClearOldEnemiesSpotted();
	Log("ClientEnemySpotted");
	bFoundEnemy=false;
	i=0;
	if (i < EnemiesSpotted.Num())
	{
		if (EnemiesSpotted[i].SpottedLocation.X == SpottedX && EnemiesSpotted[i].SpottedLocation.Y == SpottedY)
		{
			bFoundEnemy=true;
		}
		else
		{
			++ i;
		}
	}
	if (! bFoundEnemy)
	{
		Log("didnt find enemy, adding new one");
		SpottedEnemy.SpottedLocation.X=SpottedX;
		SpottedEnemy.SpottedLocation.Y=SpottedY;
		SpottedEnemy.SpottedLocation.Z=SpottedZ;
		SpottedEnemy.TimeSpottedSeconds=GetWorld()->GetTimeSeconds();
		SpottedEnemy.BlinkStartTime=GetWorld()->GetTimeSeconds();
		SpottedEnemy.BlinkEndTime=SpottedEnemy.BlinkStartTime + 2;
		Log("spot enemy duration=" @ SpotDuration);
		if (SpotDuration == 0)
		{
			SpottedEnemy.LifeSpan=8;
		}
		else
		{
			SpottedEnemy.LifeSpan=SpotDuration;
		}
		EnemiesSpotted[EnemiesSpotted.Num()]=SpottedEnemy;
	}
	*/
}
void AHumanController::ClearOldEnemiesSpotted()
{
	/*
		int32 i = 0;
		i=0;
		if (i < EnemiesSpotted.Num())
		{
			if (GetWorld()->GetTimeSeconds() - EnemiesSpotted[i].TimeSpottedSeconds > EnemiesSpotted[i].LifeSpan)
			{
				EnemiesSpotted->Remove(i,1);
			}
			else
			{
				++ i;
			}
		}
	*/
}
void AHumanController::ESSObjectSpotted(AAGP_Objective* Objective)
{
	if (Objective != nullptr)
	{
		/*
		Log(Objective + " was found and reported as a Non Lethal ES2.");
		ServerESSSpotted(Objective.Location.X,Objective.Location.Y,Objective.Location.Z,Objective.isDangerous());
		ClientESSSpotted(Objective.Location.X,Objective.Location.Y,Objective.Location.Z,Objective.isDangerous());
		*/
	}
}
void AHumanController::ServerESSSpotted(float SpottedX, float SpottedY, float SpottedZ, bool bLetal)
{
	/*
		int32 i = 0;
		for (i=0; i<PlayerReplicationInfo->Team->NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo->Team->ActualList_Player[i] != nullptr && PlayerReplicationInfo->Team->ActualList_Player[i] != PlayerReplicationInfo)
			{
				Cast<AHumanController>(PlayerReplicationInfo->Team->ActualList_Player[i].Owner).ClientESSSpotted(SpottedX,SpottedY,SpottedZ,bLetal);
			}
		}
	*/
}
void AHumanController::ClientESSSpotted(float SpottedX, float SpottedY, float SpottedZ, bool bLethal)
{
	int32 i = 0;
	FESSObjectData SpottedESSObject;
	bool bFoundES2Object;
	ClearOldNonLethalESSSpotted();
	bFoundES2Object=false;
	i=0;
	if (i < FoundESSObject.Max())
	{
		if (FoundESSObject[i].SpottedLocation.X == SpottedX && FoundESSObject[i].SpottedLocation.Y == SpottedY)
		{
			bFoundES2Object=true;
		}
		else
		{
			++ i;
		}
	}
	if (! bFoundES2Object)
	{
		UE_LOG(LogTemp, Log, TEXT("Adding a spotted ES2 object to the array."));
		SpottedESSObject.SpottedLocation.X=SpottedX;
		SpottedESSObject.SpottedLocation.Y=SpottedY;
		SpottedESSObject.SpottedLocation.Z=SpottedZ;
		SpottedESSObject.TimeSpottedSeconds=GetWorld()->GetTimeSeconds();
		SpottedESSObject.BlinkStartTime=GetWorld()->GetTimeSeconds();
		SpottedESSObject.BlinkEndTime=SpottedESSObject.BlinkStartTime + 2;
		SpottedESSObject.LifeSpan=8;
		SpottedESSObject.bLethal=bLethal;
		FoundESSObject[FoundESSObject.Max()]=SpottedESSObject;
	}
}
void AHumanController::ClearOldNonLethalESSSpotted()
{
	/*
		int32 i = 0;
		i=0;
		if (i < FoundESSObject.Num())
		{
			if (GetWorld()->GetTimeSeconds() - FoundESSObject[i].TimeSpottedSeconds > FoundESSObject[i].LifeSpan && ! FoundESSObject[i].bLethal)
			{
				FoundESSObject->Remove(i,1);
			}
			else
			{
				++ i;
			}
		}
	*/
}
void AHumanController::ServerPlaySound(USoundBase* ASound)
{
	/*
		int32 i = 0;
		for (i=0; i<PlayerReplicationInfo->Team->NumRequestSlots; i++)
		{
			if (PlayerReplicationInfo->Team->ActualList_Player[i] != nullptr && PlayerReplicationInfo->Team->ActualList_Player[i] != PlayerReplicationInfo)
			{
				Cast<AHumanController>(PlayerReplicationInfo->Team->ActualList_Player[i].Owner).ClientPlaySound(ASound);
			}
		}
	*/
}
void AHumanController::Jump(float F)
{
	/*
		if (IsInState('PlayerRolling') || GetLockMovement())
		{
			return;
		}
		if (Pawn.Weapon != nullptr)
		{
			Pawn.Weapon.ForceUnzoom();
		}
		if (Pawn != nullptr)
		{
			Pawn.ResetLean();
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand();
				return;
			}
			if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyReloading'))
			{
				return;
			}
			if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyFixingJam'))
			{
				return;
			}
			if (Pawn.LandBob < -0.01)
			{
				return;
			}
			if (Pawn.CanJump())
			{
				Pawn.bMidJump=true;
				Jump(F);
			}
		}
	*/
}

bool AHumanController::HandlePickupQuery(APickup* Item)
{
	return true;
}

void AHumanController::HandlePickup(APickup* pick)
{
}

bool AHumanController::CanSwapHands()
{
	/*
		if (Pawn == nullptr)
		{
			return false;
		}
		if (Pawn.Physics == 2 || Pawn.IsInState('BusyPostureChange'))
		{
			ClientMessage("You cannot swap weapons while you are busy adjusting your position.");
			return false;
		}
		if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusySupporting') || Pawn.Weapon.IsInState('BusyFixingJam') || Pawn.Weapon.IsInState('BusyZooming'))
		{
			return false;
		}
		if (Pawn.bIsSprinting)
		{
			ClientMessage("You cannot swap weapons while sprinting.");
			return false;
		}
		if (bAction != 0)
		{
			ClientMessage("You cannot change weapons while you are busy.");
			return false;
		}
		if (Pawn.Weapon != nullptr && Pawn.Weapon->IsA(AWeapon_AT4_Rocket::StaticClass()) || Pawn.Weapon->IsA(AWeapon_BDM_Rocket::StaticClass()))
		{
			if (! Cast<AAGP_Weapon>(Pawn.Weapon).HasAmmo())
			{
				ClientMessage("Drop the empty weapon and then switch to your primary weapon.");
				return false;
			}
		}
		return Pawn.CanSwapHands();

	*/
	return false;       //FAKE /ELiZ
}

void AHumanController::SwapHands()
{
	AAGP_Weapon* AGPWeap = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		Log("HumanController::SwapHands - CanSwapHands" @ CanSwapHands());
	}
	if (! CanSwapHands())
	{
		return;
	}
	DesiredFOV=DefaultFOV;
	SetFOVAngle(DefaultFOV);
	Cast<AAGP_Pawn>(GetPawn()).StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()).Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn()).Weapon.CheckJavelinTube())
		{
			SwapType=1;
			Reload();
			return;
		}
	}
	AGPWeap=Cast<AAGP_Weapon>(Pawn.Weapon);
	if (Role < 4 && AGPWeap != nullptr)
	{
		AGPWeap.bPendingChangeWeapon=true;
		AGPWeap.PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
	}
	ServerSwapHands();
	*/
}

void AHumanController::SwapAltShoulder()
{
	AAGP_Weapon* AGPWeap = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		Log("HumanController::AltShoulder - CanSwapHands" @ CanSwapHands());
	}
	if (! CanSwapHands())
	{
		return;
	}
	if (! CanSwapAltShoulder())
	{
		return;
	}
	DesiredFOV=DefaultFOV;
	SetFOVAngle(DefaultFOV);
	Cast<AAGP_Pawn>(GetPawn()).StopSprint();
	AGPWeap=Cast<AAGP_Weapon>(Pawn.Weapon);
	if (Role < 4 && AGPWeap != nullptr)
	{
		AGPWeap.bPendingChangeWeapon=true;
		AGPWeap.PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
	}
	ServerSwapAltShoulder();
	*/
}
bool AHumanController::CanSwapAltShoulder()
{
	AWeapon* weap;
	if (Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		ClientMessage("You cannot swap weapons while sprinting.");
		return false;
	}
	if (bAction != 0)
	{
		ClientMessage("You cannot change weapons while you are busy.");
		return false;
	}
	weap=Cast<AAGP_Pawn>(GetPawn())->Weapon;
	if (Cast<AAGP_Pawn>(GetPawn())->_InvAltShoulder->isEmpty())
	{
		return false;
	}
	if (! Cast<AAGP_Pawn>(GetPawn())->_InvShoulder->isEmpty() && Cast<AAGP_Weapon>(weap) != nullptr)
	{
		if (Cast<AAGP_Weapon>(weap)->IsA(APistolWeapon::StaticClass()) || Cast<AAGP_Weapon>(weap)->IsA(AWEAPON_Javelin::StaticClass()) || Cast<AAGP_Weapon>(weap)->IsA(AItem_Binoculars::StaticClass()))
		{
			return true;
		}
		if (Cast<AAGP_Weapon>(weap)->_bLarge)
		{
			return false;
		}
	}
	return true;
}

void AHumanController::ServerSwapHands()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHands();
	}
}

void AHumanController::SwapHip()
{
	AAGP_Weapon* AGPWeap;
	if (! CanSwapHands())
	{
		return;
	}
	DesiredFOV=DefaultFOV;
	//SetFOVAngle(DefaultFOV);
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube())
		{
			SwapType=ESwapType::SType_Hip;
			Reload();
			return;
		}
	}
	AGPWeap=Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon);
	if (GetLocalRole() <  4 && AGPWeap != nullptr)
	{
		AGPWeap->bPendingChangeWeapon=true;
		AGPWeap->PendingChangeWeaponTimeStamp=GetWorld()->GetTimeSeconds() + 1.5;
	}
	ServerSwapHip();
}

void AHumanController::ServerSwapHip()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHip();
	}
}

void AHumanController::ServerForceWeaponUnzoom()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Forcing weapon unzoomed and idle"));
		Cast<AAGP_Pawn>(GetPawn())->Weapon->ForceUnzoom(true);
		//Cast<AAGP_Pawn>(GetPawn())->Weapon->GotoState("None");
	}
}

void AHumanController::ServerSwapAltShoulder()
{
	Cast<AAGP_Pawn>(GetPawn())->StopSprint();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapAltShoulder();
	}
}

void AHumanController::Grenade(uint8 Index)
{
	bool bDelayedGrenade=false;
	if (bFire != 0 || bAltFire != 0)
	{
		ClientMessage("Stop firing to take out a grenade.");
		return;
	}
	if (GetWorld()->GetTimeSeconds() < fpWaitingForDelayedGrenade && fpWaitingForDelayedGrenade - GetWorld()->GetTimeSeconds() < 0.2)
	{
		return;
	}
	
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Index - 1] == 0)
	{
		return;
	}
	
	if (GetPawn() != nullptr && Cast<AAGP_Pawn>(GetPawn())->Health <= 0)
	{
		return;
	}
	/*
	if (IsInState('PlayerClimbing') || Pawn.Physics == 11 || Cast<AAGP_Pawn>(GetPawn()).GetCurrentVolume() != nullptr && Cast<AAGP_Pawn>(GetPawn()).GetCurrentVolume()->IsA(ALadderVolume::StaticClass()))
	{
		ClientMessage("You cannot use grenades while climbing a ladder.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->bIsSprinting)
	{
		ClientMessage("You cannot swap weapons while sprinting.");
		return;
	}
	if (bAction != 0)
	{
		ClientMessage("You cannot change weapons while you are busy.");
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		ClientMessage("You cannot use a grenade until your parachute is fully off.");
		return;
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon.IsInState('BusyReloading'))
	{
		ClientMessage("You are busy reloading and cannot select a grenade yet.");
		return;
	}
	*/
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon.IsInState('BusySupporting') || Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyFixingJam') || Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyZooming'))
	{
		ClientMessage("Your weapon is busy and you cannot select a grenade yet.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()))
	{
		/*
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsInState('BusyLoweringWeapon'))
		{
			ClientMessage("You cannot select a grenade until your binoculars are all the way down.");
			return;
		}
		*/
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyThrowingGrenade') || Cast<AAGP_Pawn>(GetPawn())->IsInState('BusyDrawingBack'))
	{
		ClientMessage("You haven't finished throwing the last grenade.");
		return;
	}
	*/
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->SetSupported(false);
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsZoomed())
		{
			bDelayedGrenade = true;
			Cast<AAGP_Pawn>(GetPawn())->Weapon->ToggleZoom();
			ServerForceWeaponUnzoom();
			DesiredFOV = DefaultFOV;
			//SetFOVAngle(DefaultFOV);
		}
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[Index - 1] != 0)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube())
		{
			switch(Index)
			{
					case 1:
						SwapType = ESwapType::SType_Frag;
						break;
					case 2:
						SwapType = ESwapType::SType_Smoke;
						break;
					case 3:
						SwapType = ESwapType::SType_Flash;
						break;
					case 4:
						SwapType = ESwapType::SType_Incendiary;
						break;
					case 5:
						SwapType = ESwapType::SType_PDM;
						break;
					case 6:
						SwapType = ESwapType::SType_DoorBreacher;
						break;
					case 7:
						SwapType = ESwapType::SType_GreenSmoke;
						break;
					default:
						SwapType = ESwapType::SType_None;
						break;
			}
			Reload();
			return;
		}
		else
		{
			if (bDelayedGrenade)
			{
				switch(Index)
				{
					case 1:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'GrenadeFrag');
							return;
						}
						break;
					case 2:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'GrenadeSmoke');
							return;
						}
						break;
					case 3:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'GrenadeFlash');
							return;
						}
						break;
					case 4:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'GrenadeIncendiary');
							return;
						}
						break;
					case 5:
						return;
					case 6:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'DemolitionItem');
							return;
						}
						break;
					case 7:
						if (bDelayedGrenade)
						{
							fpWaitingForDelayedGrenade = GetWorld()->GetTimeSeconds() + 0.25;
							//SetCustomTimer(0.25, false, 'GrenadeSignal');
							return;
						}
						break;
					default:
						break;
				}
			}
		}
	}
	ServerGrenade(Index);
}

void AHumanController::GrenadeFrag()
{
	Grenade(1);
}

void AHumanController::GrenadeSmoke()
{
	Grenade(2);
}

void AHumanController::GrenadeFlash()
{
	Grenade(3);
}

void AHumanController::GrenadeIncendiary()
{
	Grenade(4);
}

void AHumanController::GrenadePDM()
{
}

void AHumanController::DemolitionItem()
{
	Grenade(6);
}

void AHumanController::SignalEnteredPickupZone()
{
}

void AHumanController::GrenadeSignal()
{
	Grenade(7);
}

void AHumanController::binoculars()
{
	if (! CanSwapHands())
	{
		return;
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AWEAPON_Javelin::StaticClass()) || Cast<AAGP_Pawn>(GetPawn())->getHipInventory()->IsA(AWEAPON_Javelin:StaticClass()))
	{
		SwapHip();
		return;
	}
	*/
	ServerBinoculars();
}

void AHumanController::ServerBinoculars()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && !Cast<AAGP_Pawn>(GetPawn())->bHasCLU)
	{
		Cast<AAGP_Pawn>(GetPawn())->GetBinoculars();
	}
}

void AHumanController::Pistol()
{
	if (! CanSwapHands())
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->CheckJavelinTube() && ! Cast<AAGP_Pawn>(GetPawn())->_InvHolster->isEmpty())
		{
			SwapType= ESwapType::SType_Pistol;
			Reload();
			return;
		}
	}
	ServerSwapHolster();
}

void AHumanController::ServerSwapHolster()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->SwapHolster();
	}
}

void AHumanController::CommoHand()
{
	CommoMode(ECommoType::COMMOTYPE_Hand);
}

void AHumanController::CommoWhisper()
{
	CommoMode(ECommoType::COMMOTYPE_Hand);
}

void AHumanController::CommoShout()
{
	CommoMode(ECommoType::COMMOTYPE_Shout);
}

void AHumanController::CommoRadio()
{
	CommoMode(ECommoType::COMMOTYPE_Radio);
}

void AHumanController::CommoSquad()
{
	CommoMode(ECommoType::COMMOTYPE_Squad);
}

void AHumanController::CommoGlobal()
{
	CommoMode(ECommoType::COMMOTYPE_Global);
}

void AHumanController::ServerGrenade(uint8 Index)
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->GetGrenade(Index);
	}
}

void AHumanController::ThrowWeapon()
{
	if (Cast<AAGP_Pawn>(GetPawn()) == nullptr || Cast<AAGP_Pawn>(GetPawn())->Weapon == nullptr)
	{
		return;
	}
	if (bAutoWalkZoom)
	{
		Cast<AAGP_Pawn>(GetPawn())->SetWalking(bSavedWalkingState);
	}
	ServerThrowWeapon();
}

void AHumanController::IncreaseRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			if (iSpotterPolarRangeSetting < 1500)
			{
				iSpotterPolarRangeSetting += 10;
			}
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->IncreaseElevation();
		}
	}
}

void AHumanController::DecreaseRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			if (iSpotterPolarRangeSetting > 300)
			{
				iSpotterPolarRangeSetting -= 10;
			}
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->DecreaseElevation();
		}
	}
}

void AHumanController::ZeroRange()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()) && bMortarSpotter)
		{
			iSpotterPolarRangeSetting=600;
		}
		else
		{
			Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(GetPawn())->Weapon)->ZeroElevation();
		}
	}
}

void AHumanController::FastMove()
{
	//Super::FastMove();
	if (Cast<AAGP_Pawn>(GetPawn()) != NULL)
	{
		Cast<AAGP_Pawn>(GetPawn())->CheckInventoryOverload();
	}
}

void AHumanController::ServerThrowWeapon()
{
	if (bNoThrowWeapon || ! CanUseWeapon(7))
	{
		return;
	}
	Cast<AAGP_Pawn>(GetPawn())->SetZoomed(false);
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(AItem_Binoculars::StaticClass()))
	{
		if (CanSwapHands())
		{
			ServerBinoculars();
		}
		return;
	}
	else
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon->IsA(APistolWeapon::StaticClass()))
		{
			if (CanSwapHands())
			{
				ServerSwapHolster();
			}
			return;
		}
	}
	//Cast<AAGP_Pawn>(GetPawn())->TossWeapon(Cast<AAGP_Pawn>(GetPawn())->Velocity +  Vector(Rotation) * 200 + FVector(0 0 150));
}
void AHumanController::SetIndex(int32 i)
{
	/*
		FString sFile;
		FString sSection;
		if (i < 0)
		{
			i=0;
		}
		sFile=GetBaseDir() + "WeaponMods.ini";
		sSection=GetPrivateProfileString(sFile,"WeaponMods","CurrentWeapon");
		SetPrivateProfileInt(i,sFile,sSection,"CurrentIndex");
		SavePrivateProfile(sFile);
		SetWeaponMods();
	*/
}
void AHumanController::SetIndexName(int32 i, FString S)
{
	/*
		FString sFile;
		FString sSection;
		if (i < 0)
		{
			i=0;
		}
		if (S == "")
		{
			S="Set " + i + 1;
		}
		sFile=GetBaseDir() + "WeaponMods.ini";
		sSection=GetPrivateProfileString(sFile,"WeaponMods","CurrentWeapon");
		SetPrivateProfileString(S,sFile,sSection,"IndexName(" + i + ")");
		SavePrivateProfile(sFile);
	*/
}
void AHumanController::SetWeapon(FString S)
{
	/*
		FString sFile;
		WM_CurrentWeapon=GetLegalWeapon(S);
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
		sFile=GetBaseDir() + "WeaponMods.ini";
		SetPrivateProfileString(WM_CurrentWeapon,sFile,"WeaponMods","CurrentWeapon");
		SetWeaponMods();
		SaveWeaponMods();
	*/
}

void AHumanController::SetMod(int32 i, FString S)
{
	if (i < 0 || i >= 6)
	{
		return;
	}
	WM_Slot[i]=GetLegalMod(S);
	SaveWeaponMods();
}

void AHumanController::CubePics(uint8 Index)
{
	ACubeMapMaker* C = nullptr;
	/*
	if (Index == 0)
	{
		ForEach AllActors('CubeMapMaker',C)
		{
			C.Begin();
			return;
		}
		C=Spawn('CubeMapMaker',,,Pawn.EyePosition());
		if (C != nullptr)
		{
			Log("HumanController::CubePics(): CubeMapMaker created");
			C.Begin();
			C.DestroyOnFinish(true);
		}
		else
		{
			Log("HumanController::CubePics(): Couldn't spawn CubeMapMaker");
		}
	}
	else
	{
		C=Spawn('CubeMapMaker',,,Pawn.EyePosition());
		if (C != nullptr)
		{
			Log("HumanController::CubePics(): CubeMapMaker created");
			C.Begin(Index);
		}
		else
		{
			Log("HumanController::CubePics(): Couldn't spawn CubeMapMaker");
		}
	}
	*/
}

FString AHumanController::GetIndexName(int32 i)
{
	FString sFile = "";
	FString sIndexName = "";
	if (i < 0)
	{
		i = 0;
	}
	/*
	sFile = GetBaseDir() + "WeaponMods.ini";
	sIndexName = GetPrivateProfileString(sFile, WM_CurrentWeapon, "IndexName(" + FString::FromInt(i) + ")");
	if (sIndexName == "")
	{
		sIndexName = "Set " + FString::FromInt((i + 1));
	}
	*/
	return sIndexName;
}

FString AHumanController::GetCurrentIndexName()
{
	FString sFile = "";
	FString sIndexName = "";
	//sFile = GetBaseDir() + "WeaponMods.ini";
	//sIndexName = GetPrivateProfileString(sFile, WM_CurrentWeapon, "IndexName(" + FString::FromInt(GetCurrentIndex()) + ")");
	if (sIndexName == "")
	{
		//sIndexName = "Set " + FString::FromInt((GetCurrentIndex() + 1));
	}
	return sIndexName;
}

FString AHumanController::GetLegalWeapon(FString S)
{
	AWeapon* classW = nullptr;
	/*
	if (S != "")
	{
		if (S != "AGP_Inventory.Weapon_M4A1_Rifle_Mod")
		{
			S = "AGP_Inventory.Weapon_M4A1_Rifle_Mod";
		}
		classW = class<Weapon>(DynamicLoadObject(S, Class'Class', true));
		if (classW != nullptr)
		{
			return S;
		}
	}
	*/
	return "";
}

FString AHumanController::GetLegalMod(FString S)
{
	ABaseWeaponMod* classWM = nullptr;
	/*
	if (S != "")
	{
		classWM=class<BaseWeaponMod>(DynamicLoadObject(S,Class'Class',True));
		if (classWM != nullptr)
		{
			return S;
		}
	}
	*/
	return "";
}

int32 AHumanController::GetCurrentIndex()
{
	FString sFile = "";
	//sFile = GetBaseDir() + "WeaponMods.ini";
	//return GetPrivateProfileInt(sFile, WM_CurrentWeapon, "CurrentIndex");
	return 0;    //FAKE   /ELiZ
}

FString AHumanController::GetCurrentMod(int32 Index, int32 Slot)
{
	FString sFile = "";
	FString sMod = "";
	/*
	sFile = GetBaseDir() + "WeaponMods.ini";
	sMod = GetPrivateProfileString(sFile, WM_CurrentWeapon, "Slot_" + FString::FromInt(Slot) + "_(" + FString::FromInt(Index) + ")");
	return Mid(sMod, Len("AGP_Inventory.WeaponMod_"), Len(sMod));
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void AHumanController::SetWeaponMods()
{
	FString sFile = "";
	int32 Index = 0;
	FString sKey = "";
	int32 i = 0;
	/*
	sFile = GetBaseDir() + "WeaponMods.ini";
	WM_CurrentWeapon = GetPrivateProfileString(sFile, "WeaponMods", "CurrentWeapon");
	WM_CurrentWeapon = GetLegalWeapon(WM_CurrentWeapon);
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo.sCurrentWeaponClass = WM_CurrentWeapon;
	}
	if (WM_CurrentWeapon == "")
	{
		SetPrivateProfileString("", sFile, "WeaponMods", "CurrentWeapon");
		SavePrivateProfile(sFile);
		for (i = 0; i < 6; i++)
		{
			WM_Slot[i] = "";
		}
	}
	else
	{
		Index = GetPrivateProfileInt(sFile, WM_CurrentWeapon, "CurrentIndex");
		if (Index < 0)
		{
			Index = 0;
			SetIndex(0);
		}
		for (i = 0; i < 6; i++)
		{
			sKey = "Slot_" + FString::FromInt(i) + "_(" + FString::FromInt(Index) + ")";
			WM_Slot[i] = GetPrivateProfileString(sFile, WM_CurrentWeapon, sKey);
			WM_Slot[i] = GetLegalMod(WM_Slot[i]);
		}
	}
	*/
	UploadWeaponMods();
}
void AHumanController::SaveWeaponMods()
{
	/*
		FString sFile;
		int32 Index = 0;
		FString sKey;
		int32 i = 0;
		sFile=GetBaseDir() + "WeaponMods.ini";
		WM_CurrentWeapon=GetLegalWeapon(WM_CurrentWeapon);
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
		if (WM_CurrentWeapon == "")
		{
			SetPrivateProfileString("",sFile,"WeaponMods","CurrentWeapon");
		}
		else
		{
			SetPrivateProfileString(WM_CurrentWeapon,sFile,"WeaponMods","CurrentWeapon");
			Index=GetPrivateProfileInt(sFile,WM_CurrentWeapon,"CurrentIndex");
			if (Index < 0)
			{
				Index=0;
				SetIndex(0);
			}
			for (i=0; i<6; i++)
			{
				sKey="Slot_" + i + "_(" + Index + ")";
				WM_Slot[i]=GetLegalMod(WM_Slot[i]);
				SetPrivateProfileString(WM_Slot[i],sFile,WM_CurrentWeapon,sKey);
			}
		}
		SavePrivateProfile(sFile);
		UploadWeaponMods();
	*/
}
void AHumanController::UploadWeaponMods()
{
	int32 i = 0;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerSetWeaponMods(-1,WM_CurrentWeapon);
		for (i=0; i<6; i++)
		{
			ServerSetWeaponMods(i,WM_Slot[i]);
		}
	}
}
void AHumanController::ServerSetWeaponMods(int32 Slot, FString new_mod)
{
	if (Slot == -1)
	{
		WM_CurrentWeapon=new_mod;
		if (PlayerReplicationInfo != nullptr)
		{
			//PlayerReplicationInfo.sCurrentWeaponClass=WM_CurrentWeapon;
		}
	}
	else
	{
		if (Slot >= 0 && Slot < 6)
		{
			WM_Slot[Slot]=new_mod;
		}
	}
}
void AHumanController::SetSkinPreference(FString S)
{
	if (S == "SKINPREF_African")
	{
		ServerSetSkinPreference(ESkinPreference::SKINPREF_African);
	}
	else
	{
		if (S == "SKINPREF_Caucasian")
		{
			ServerSetSkinPreference(ESkinPreference::SKINPREF_Caucasian);
		}
		else
		{
			if (S == "SKINPREF_Latino")
			{
				ServerSetSkinPreference(ESkinPreference::SKINPREF_Latino);
			}
			else
			{
				ServerSetSkinPreference(ESkinPreference::SKINPREF_None);
			}
		}
	}
}

void AHumanController::ServerSetSkinPreference(ESkinPreference newpref)
{
	SkinPreference = newpref;
}
void AHumanController::setFace(FString S)
{
	ServerSetFace(S, true);
}

void AHumanController::SetOpFace(FString S)
{
	ServerSetFace(S, false);
}

void AHumanController::ServerSetFace(FString newface, bool bFriend)
{
	if (bFriend)
	{
		Face = newface;
	}
	else
	{
		OpFace = newface;
	}
}

void AHumanController::ClientResetSpectator()
{
	CleanupLevel();
}

void AHumanController::ClientSetViewTarget2(AActor* Target)
{
	/*
		if (Target == nullptr)
		{
			ServerReSendViewTarget();
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Locating this player will take a moment.  Please wait...");
			}
			return;
		}
		SetViewTarget(Target);
	*/

}
void AHumanController::ServerReSendViewTarget()
{
	UE_LOG(LogTemp, Warning, TEXT("Resending View Target to client after moving controller to that location"));
	/*
	SetActorLocation(ViewTarget.Location);
	SetCustomTimer(0.75, false, 'WaitForPawnToBecomeRelevant');
	*/
}

void AHumanController::WaitForPawnToBecomeRelevant()
{
	UE_LOG(LogTemp, Warning, TEXT("Telling client to try again with view target"));
		/*
		if (ViewTarget == nullptr)
		{
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Lost player view, locating next player.  Please wait...");
			}
			ServerNextViewTarget();
			return;
		}
		if (ViewTarget->IsA(APawn::StaticClass()) && Pawn(ViewTarget).Health < 0 && ViewPreference != 3)
		{
			if (IsInState('Spectating'))
			{
				NotifyAdminMessage("Last player died, locating next player.  Please wait...");
			}
			ServerNextViewTarget();
			return;
		}
		ClientSetViewTarget2(ViewTarget);
	*/
}

/*
AActor* AHumanController::GetViewTargetActor(AActor* VT)
{
	APawn* p = nullptr;
	p = Cast<APawn>(VT);
	if ((p != nullptr) && (ViewPreference != EViewPreference::VIEW_Bodies))
	{
		return p->Controller;
	}
	else
	{
		return VT;
	}
}
*/

AActor* AHumanController::GetNextViewTargetActor(EViewPreference viewpref, AActor* A)
{
	AController* C = nullptr;
	AAGP_Viewpoint* V = nullptr;
	if (viewpref == EViewPreference::VIEW_Bodies)
	{
		return GetNextViewBody(A);
	}
	if (A == nullptr)
	{
		if (viewpref == EViewPreference::VIEW_ViewpointsOnly)
		{
			//DebugLog(DEBUG_Spec, "HumanController::GetNextViewTargetActor() - Returning viewpoints only list");
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList;
		}
		else
		{
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList;
		}
	}
	if (viewpref != EViewPreference::VIEW_ViewpointsOnly)
	{
		C = Cast<AController>(A);
	}
	if (C != nullptr)
	{
		//C = C->nextController;
		if (C != nullptr)
		{
			return C;
		}
		if (viewpref != EViewPreference::VIEW_PlayersOnly)
		{
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList;
		}
		else
		{
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList;
		}
	}
	if (viewpref != EViewPreference::VIEW_PlayersOnly)
	{
		V = Cast<AAGP_Viewpoint>(A);
	}
	if (V != nullptr)
	{
		return V->NextViewpoint;
	}
	//DebugLog(DEBUG_Spec, "HumanController::GetNextViewTargetActor() - Don't know what to do with " + FString::FromInt(A));
	return nullptr;
}

AActor* AHumanController::GetNextViewBody(AActor* A)
{
	APawn* p = nullptr;
	APawn* Prev = nullptr;
	bool b_use_next = false;
	Prev = Cast<APawn>(A);
	if (Prev == nullptr)
	{
		b_use_next = true;
	}
	/*
	ForEach DynamicActors(Class'Pawn', p)
	{
		if (p.isDead())
		{
			if (b_use_next)
			{
				return p;
			}
			else
			{
				if (p == Prev)
				{
					b_use_next = true;
				}
			}
		}
	}
	*/
	return nullptr;
}

bool AHumanController::IsSpectatePlayersOnly()
{
	if (StartupStage == EStartupStage::STAGE_Authorizing)
	{
		return false;
	}
	/*
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		return false;
	}
	*/
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectatePlayersOnly;
	}
	else
	{
		//return Level.Game.IsSpectatePlayersOnly();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::IsSpectateFirstPersonOnly()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectateFirstPersonOnly;
	}
	else
	{
		//return Level.Game.IsSpectateFirstPersonOnly();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::IsSpectateBodies()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return bSpectateBodies;
	}
	else
	{
		//return Level.Game.IsSpectateBodies();
		return false;		//FAKE    /EliZ
	}
}
bool AHumanController::CanBehindView()
{
	/*
		APawn* p = nullptr;
		if (Super::CanBehindView())
		{
			return true;
		}
		else
		{
			if (! (Level.Game.IsSpectateFirstPersonOnly()))
			{
				if (GetNetMode() == ENetMode::NM_Client && Pawn != nullptr && ! Pawn.isDead() && ! bCheatServer)
				{
					ClientMessage("Behindview is not available on non-cheat servers");
					return false;
				}
				p=Pawn(ViewTarget);
				if (p != nullptr && p.Health > 0)
				{
					return true;
				}
			}
		}
		return false;
	*/
	return false;		//FAKE    /EliZ
}
void AHumanController::ClientSetViewPreference(EViewPreference evpNew)
{
	ViewPreference = evpNew;
}
void AHumanController::ServerSetViewPreference(EViewPreference evpNew)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		/*
		if (GameReplicationInfo.Teams[0].NumAlive() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("no players left alive, using viewpoints"));
			ServerNextViewTarget(2);
			return;
		}
		*/
	}
	else
	{
		/*
		if (GameReplicationInfo.Teams[0].NumAlive() == 0 || GameReplicationInfo.Teams[1].NumAlive() == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("No players left alive, using viewpoints only"));
			ServerNextViewTarget(ViewPreference);
			return;
		}
		*/
	}
		
	ViewPreference=evpNew;
	ClientSetViewPreference(ViewPreference);
	//ServerNextViewTarget(ViewPreference);
}

void AHumanController::ServerCycleViewPreference()
{
	/*
	if (IsSpectatePlayersOnly())
	{
		ViewPreference=0;
	}
	switch(ViewPreference)
	{
		case 0:
		ViewPreference=1;
		ClientSetViewPreference(ViewPreference);
		if (! ViewTarget->IsA(APawn::StaticClass()))
		{
			ServerNextViewTarget(ViewPreference);
		}
		return;
		case 1:
		ViewPreference=2;
		ClientSetViewPreference(ViewPreference);
		if (ViewTarget == nullptr || ! ViewTarget->IsA(AAGP_Viewpoint::StaticClass()))
		{
			ServerNextViewTarget(ViewPreference);
		}
		return;
		case 2:
		if (IsSpectateBodies())
		{
			ViewPreference=3;
			break;
		}
		ViewPreference=0;
	}
	ClientSetViewPreference(ViewPreference);
	ServerNextViewTarget(ViewPreference);
	return;
	case 3:
	ViewPreference=0;
	ClientSetViewPreference(ViewPreference);
	if (! ViewTarget->IsA(APawn::StaticClass()) && Pawn(ViewTarget).Health > 0)
	{
		ServerNextViewTarget(ViewPreference);
	}
	return;
	default:
	*/
}

/* =================================================================================== *
 * AGP function ServerNextViewTarget
 *	Cycle through the list of eligible ViewTargets, filtered by viewpref and try to
 *	set my current viewtarget to the new one.
  * =================================================================================== */
void AHumanController::ServerNextViewTarget(EViewPreference viewpref, bool bprev, bool bForceViewChange, bool fFindFirstPlayerOnlyView)
{
	switch(viewpref)
	{
	case EViewPreference::VIEW_ViewpointsOnly:
		NextViewpointViewTarget(bprev, false);
		break;
	case EViewPreference::VIEW_Bodies:
		NextBodyViewTarget(bprev);
		break;
	case EViewPreference::VIEW_PlayersOnly:
		NextPlayerViewTarget(bprev);
		break;
	case EViewPreference::VIEW_Any:
		/*
		if (ViewTarget == nullptr || ViewTarget->IsA('AGP_Viewpoint'))
		{
			NextViewpointViewTarget(bprev, false);
		}
		else
		{
			NextPlayerViewTarget(bprev);
		}
		*/
		break;
	default:
		break;
	}
	
}

void AHumanController::NextViewpointViewTarget(bool bprev, bool bNoSwitchToPawns)
{
	AAGP_Viewpoint* agpvpIterator = nullptr;
	AAGP_Viewpoint* agpvpLast = nullptr;
	AAGP_Viewpoint* agpvpSelectedView = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() entered bPrev: " + bprev + " NoSwitchToPawns: " + bNoSwitchToPawns));
	if (ViewTarget == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() - no previous viewpoint, using viewpoint list head"));
		agpvpSelectedView=Level.ViewpointList;
	}
	else
	{
		if (! bprev && ViewTarget->IsA(AAGP_Viewpoint::StaticClass()) && Cast<AAGP_Viewpoint>(ViewTarget).NextViewpoint != nullptr)
		{
			agpvpSelectedView=AGP_Viewpoint(ViewTarget).NextViewpoint;
		}
		else
		{
			agpvpIterator=Level.ViewpointList;
			if (agpvpIterator != nullptr)
			{
				if (agpvpIterator == ViewTarget)
				{
					if (bprev)
					{
						if (agpvpIterator != Level.ViewpointList)
						{
							agpvpSelectedView=agpvpLast;
						}
					}
					else
					{
						if (agpvpIterator.NextViewpoint != nullptr)
						{
							agpvpSelectedView=agpvpIterator.NextViewpoint;
						}
					}
					else
					{
					}
					else
					{
						agpvpLast=agpvpIterator;
					}
					agpvpIterator=agpvpIterator.NextViewpoint;
				}
			}
		}
	}
	if (agpvpSelectedView == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("NextviewpointViewTarget() - didn't find a viewpoint")=;
		if (ViewPreference == 0 && ! bNoSwitchToPawns)
		{
			UE_LOG(LogTemp, Warning, TEXT("No previous viewpoint, VIEW ANY used, last viewpoint: " + ViewTarget));
			if (ViewTarget->IsA(AAGP_Viewpoint::StaticClass()))
			{
				NextPlayerViewTarget(bprev);
				return;
			}
		}
		if (bprev)
		{
			agpvpSelectedView=agpvpLast;
		}
		else
		{
			agpvpSelectedView=Level.ViewpointList;
		}
	}
	if (agpvpSelectedView == nullptr)
	{
		if (ViewPreference == 2 || bNoSwitchToPawns)
		{
			if (Level.ViewpointList != nullptr)
			{
				agpvpSelectedView=Level.ViewpointList;
			}
			else
			{
				ForEach AllActors(AAGP_Viewpoint::StaticClass(),agpvpIterator)
				{
					UE_LOG(LogTemp, Warning, TEXT("Iterated through actors and found viewpoint"));
					agpvpSelectedView=agpvpIterator;
				}
			}
			if (agpvpSelectedView == nullptr)
			{
				return;
			}
		}
		else
		{
			NextPlayerViewTarget(false);
			return;
		}
	}
	SetViewTarget(agpvpSelectedView);
	ClientSetViewTarget2(ViewTarget);
	*/
}

void AHumanController::NextPlayerViewTarget(bool bprev)
{
	AController* ctrlIterator = nullptr;
	APawn* pawnLastViewed = nullptr;
	APawn* pawnToView = nullptr;
	APawn* pawnLast = nullptr;
	APawn* pawnFirstFound = nullptr;
	bool bGetNextPawn = false;
	/*
	UE_LOG(LogTemp, Warning, TEXT("NextPlayerViewTarget entered with last view: " + ViewTarget + " bPrev: " + bprev));
	if (! bLostViewTarget && ViewTarget != nullptr && ViewTarget->IsA(APawn::StaticClass()) && Pawn(ViewTarget).Health > 0)
	{
		if (Cast<APawn>(ViewTarget).PlayerReplicationInfo != nullptr && Pawn(ViewTarget).PlayerReplicationInfo.bOnlySpectator || Pawn(ViewTarget).PlayerReplicationInfo.bIsSpectator)
		{
			bGetNextPawn=true;
		}
		else
		{
			pawnLastViewed=Pawn(ViewTarget);
		}
	}
	else
	{
		if (ViewTarget->IsA(APawn::StaticClass()) || ! bprev)
		{
			bGetNextPawn=true;
		}
	}
	bLostViewTarget=false;
	ctrlIterator=Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (ctrlIterator == this)
		{
		}
		if (ctrlIterator.Pawn != nullptr && ctrlIterator.Pawn.Health > 0 && ctrlIterator.Pawn->IsA(AAGP_Pawn::StaticClass()) || ctrlIterator.Pawn->IsA(ACROWS_HMMWV::StaticClass()) || ctrlIterator.Pawn->IsA(AHMMWV_Passenger::StaticClass()) && ctrlIterator->IsA(ANPCBaseController::StaticClass()) || ctrlIterator->IsA(AHumanController::StaticClass()))
		{
			if (ctrlIterator->IsA(AHumanController::StaticClass()))
			{
				if (Cast<AHumanController>(ctrlIterator).IsInState('Spectating'))
				{
				}
				if (Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo == nullptr)
				{
				}
				if (Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo.bIsSpectator || Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo.bOnlySpectator)
				{
				}
				else
				{
					else
					{
					}
					else
					{
						if (Level.Game.CanSpectate(this,True,ctrlIterator.Pawn))
						{
							if (pawnFirstFound == nullptr)
							{
								UE_LOG(LogTemp, Warning, TEXT("First pawn found that can be spectated: " + ctrlIterator.Pawn));
								pawnFirstFound=ctrlIterator.Pawn;
							}
							if (bGetNextPawn)
							{
								UE_LOG(LogTemp, Warning, TEXT("Getting pawn from " + ctrlIterator + " -> " + ctrlIterator.Pawn + "." + ctrlIterator.Pawn.HUDText));
								pawnToView=ctrlIterator.Pawn;
							}
							else
							{
								if (pawnLastViewed == ctrlIterator.Pawn)
								{
									UE_LOG(LogTemp, Warning, TEXT("Found last pawn view target: " + ctrlIterator.Pawn));
									if (bprev)
									{
										UE_LOG(LogTemp, Warning, TEXT("Moving backwards, using last view: " + pawnLast));
										if (pawnLast != nullptr)
										{
											pawnToView=pawnLast;
										}
									}
									else
									{
										bGetNextPawn=true;
										UE_LOG(LogTemp, Warning, TEXT("signalling next pawn is the one "));
									}
								}
								pawnLast=ctrlIterator.Pawn;
							}
						}
					}
				}
			}
			ctrlIterator=ctrlIterator.nextController;
		}
	}
	if (pawnToView == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Didn't find pawn yet"));
		if (ViewPreference == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Didn't find pawn and wants to wrap with ViewAny"));
			if (ViewTarget->IsA(APawn::StaticClass()))
			{
				NextViewpointViewTarget(bprev,true);
				return;
			}
		}
		if (bprev)
		{
			UE_LOG(LogTemp, Warning, TEXT("Wrapping back to last pawn found"));
			pawnToView=pawnLast;
		}
		else
		{
			if (pawnFirstFound != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Wrapping back to first pawn: " + pawnFirstFound));
				if (pawnFirstFound == nullptr)
				{
					NextViewpointViewTarget(false,true);
					return;
				}
				else
				{
					pawnToView=pawnFirstFound;
				}
			}
		}
	}
	if (pawnToView == nullptr || pawnToView == pawnPlayersDeadBody)
	{
		UE_LOG(LogTemp, Warning, TEXT("No pawns found, switching to viewpoints"));
		NextViewpointViewTarget(bprev,true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn found, switching view to it: " + pawnToView + " -> " + pawnToView.HUDText));
		if (! IsSpectateFirstPersonOnly())
		{
			bBehindView=true;
		}
		else
		{
			bBehindView=false;
		}
		if (pawnToView->IsA(AHMMWV_Passenger::StaticClass()))
		{
			bBehindView=true;
			pawnToView=pawnToView.GetVehicleBase();
		}
		SetViewTarget(pawnToView);
		ClientSetViewTarget2(ViewTarget);
		ClientSetBehindView(bBehindView);
	}
	*/
}

void AHumanController::NextBodyViewTarget(bool bprev)
{
	AAGP_Pawn* agpIterator = nullptr;
	APawn* pawnLastViewed = nullptr;
	APawn* pawnToView = nullptr;
	APawn* pawnLast = nullptr;
	APawn* pawnFirstFound = nullptr;
	bool bGetNextPawn = false;
	/*
	UE_LOG(LogTemp, Warning, TEXT("NextBodyViewTarget() entered"));
	if (ViewTarget != nullptr && ViewTarget->IsA(APawn::StaticClass()) && Pawn(ViewTarget).Health <= 0)
	{
		pawnLastViewed=Pawn(ViewTarget);
	}
	else
	{
		bGetNextPawn=true;
	}
	ForEach AllActors('AGP_Pawn',agpIterator)
	{
		if (agpIterator.Health <= 0)
		{
			if (Level.Game.CanSpectate(this,True,agpIterator))
			{
				if (pawnFirstFound == nullptr)
				{
					pawnFirstFound=agpIterator;
				}
				if (bGetNextPawn)
				{
					pawnToView=agpIterator;
				}
				else
				{
					if (pawnLastViewed == nullptr)
					{
						pawnToView=agpIterator;
					}
					else
					{
						if (pawnLastViewed == agpIterator)
						{
							if (bprev)
							{
								if (pawnLast != nullptr)
								{
									pawnToView=pawnLast;
								}
							}
							else
							{
								bGetNextPawn=true;
							}
						}
						pawnLast=agpIterator;
					}
				}
			}
		}
	}
	if (pawnToView == nullptr)
	{
		if (bprev)
		{
			pawnToView=pawnLast;
		}
		else
		{
			if (pawnFirstFound != nullptr)
			{
				pawnToView=pawnFirstFound;
			}
		}
	}
	if (pawnToView == nullptr)
	{
		NextViewpointViewTarget(bprev,false);
	}
	else
	{
		SetViewTarget(pawnToView);
		ClientSetViewTarget2(pawnToView);
		if (! IsSpectateFirstPersonOnly())
		{
			bBehindView=true;
		}
		else
		{
			bBehindView=false;
		}
		ClientSetBehindView(bBehindView);
	}
	*/
}

void AHumanController::NotifyLostViewTarget()
{
	bLostViewTarget=true;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Log, TEXT("Lost view target!"));
		ServerNotifyLostViewTarget();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Lost view target"));
	}
}

void AHumanController::ServerNotifyLostViewTarget()
{
	if (StartupStage != EStartupStage::STAGE_Spectator && StartupStage != EStartupStage::STAGE_Authorizing)
	{
		CleanUp();
		//Level.Game.RestartPlayer(this);
	}
	//ServerNextViewTarget();
}
void AHumanController::NotifyPawnDestroyed(APawn* p)
{
	/*
		NotifyPawnDestroyed(p);
		if (ViewTarget == p && p.Role == 2)
		{
			ServerNextViewTarget();
		}
	*/
}
void AHumanController::DebugFlushStats()
{
	ServerDebugFlushStats();
}
void AHumanController::ServerDebugFlushStats()
{
	/*
		if (Role == 4 && GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			if (Level.Game.Stats != nullptr)
			{
				Level.Game.Stats.Aggregate();
				Level.Game.Stats.Store();
			}
		}
	*/
}
void AHumanController::DebugClientDumpPawns()
{
}
void AHumanController::DebugServerDumpPawns()
{
}
void AHumanController::ServerSetViewTarget(AActor* Target)
{
	/*
		if (Target == nullptr)
		{
			Target=Level.ViewpointList;
		}
		SetViewTarget(Target);
		SetActorRotation(Target.Rotation);
	*/
}
void AHumanController::ServerChangeToSpectatingState()
{
	ChangeState("Spectating");
}
void AHumanController::ServerAdminFreeCam(AActor* OldTarget)
{
	/*
		if (OldTarget == nullptr || ! PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		SetPhysics(0);
		SetCollision(false,false,false);
		bCollideWorld=false;
		SetActorLocation(OldTarget.Location);
		SetActorRotation(OldTarget.Rotation);
		SetViewTarget(this);
		ClientSetViewTarget2(ViewTarget);
		ShortClientAdjustPosition(GetWorld()->GetTimeSeconds,GetStateName(),0,Location.X,Location.Y,Location.Z,Rotation.Pitch / 256,this);
	*/
}
void AHumanController::ServerAdminViewPlayer(AActor* NewTarget)
{
	/*
		if (NewTarget == nullptr || ! PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		SetPhysics(0);
		SetCollision(true,false,false);
		bCollideWorld=true;
		SetViewTarget(NewTarget);
		ClientSetViewTarget2(ViewTarget);
	*/
}
void AHumanController::LogTeam()
{
	PlayerReplicationInfo->Team->LogTeamStructure();
}
void AHumanController::ServerLogTeam()
{
	ServerLogTeamStructure();
}
void AHumanController::ServerLogTeamStructure()
{
	PlayerReplicationInfo->Team->LogTeamStructure();
}
void AHumanController::Query()
{
	if(GetNetMode() == ENetMode::NM_Standalone)
	{
		ServerQuery();
	}
	printInfo();
}
bool AHumanController::CanServerQuery()
{
	/*
	if (Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		return PlayerReplicationInfo->Administrator() || PlayerReplicationInfo->SuperUser();
	}
	else
	{
		return true;
	}
	*/
	return true;
}

void AHumanController::ServerQuery()
{
	if (CanServerQuery())
	{
		printInfo();
	}
}

void AHumanController::printInfo()
{
	ABaseWeaponAttachment* WA = nullptr;
	APickup* p = nullptr;
	AAGP_Weapon* W = nullptr;
	AAGP_Pawn* AP = nullptr;
	APlayerController* PC = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	AAttachmentHandler* AH = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("-------------------- (q) --------------------"));
	UE_LOG(LogTemp, Warning, TEXT("***WEAPONS***"));
	ForEach AllActors('AGP_Weapon',W)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	W:	" + W @ W.GetStateName() @ W.Base @ W.Owner @ W.Instigator @ W.AmmoType));
	}
	ForEach AllActors('BaseWeaponAttachment',WA)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	WA:	" + WA @ WA.GetStateName() @ WA.Owner @ WA.Instigator @ WA.Base @ WA.TurretPitch @ WA.TurretYaw));
	}
	ForEach AllActors(APickup::StaticClass(),p)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	P:	" + p @ p.GetStateName() @ p.Base @ p.AttachmentBone));
	}
	ForEach AllActors('AttachmentHandler',AH)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	AH:	" + AH @ AH.GetStateName() @ AH.AttachProxy @ AH.Base));
	}
	UE_LOG(LogTemp, Warning, TEXT("***PLAYERS***"));
	ForEach AllActors('AGP_Pawn',AP)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	AP:  " + AP @ AP.GetStateName() @ AP.Weapon @ AP.getHandsInventory() @ AP.getShoulderInventory()));
	}
	ForEach AllActors(Class'PlayerController',PC)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	PC:   " + PC @ PC.GetStateName() @ PC.ViewTarget @ PC.RealViewTarget));
	}
	ForEach AllActors(APlayerReplicationInfo::StaticClass(),PRI)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	PRI: " + PRI @ PRI.PlayerName @ PRI.Owner @ PRI.Team @ PRI.Team.TeamIndex @ PRI._Group));
	}
	UE_LOG(LogTemp, Warning, TEXT("***INVENTORIES***"));
	ForEach AllActors('AGP_Pawn',AP)
	{
		UE_LOG(LogTemp, Warning, TEXT("(q)	AP:  " + AP.GetHumanReadableName()));
		AP.LogInventory();
	}
	UE_LOG(LogTemp, Warning, TEXT("***PICKUPS***"));
	Level.LogPickupList("Query");
	UE_LOG(LogTemp, Warning, TEXT("-------------------- (q) --------------------"));
	*/
}

bool AHumanController::useTriggered(AActor* A)
{
	if (A != nullptr)
	{
		if (A->IsA(AMover::StaticClass()))
		{
			return Cast<AMover>(A)->bUseControl;
		}
	}
	return false;
}
void AHumanController::ChangeActionStatus(uint8 Action)
{
	bAction = Action;
}
void AHumanController::HealSelf()
{
	/*
		if (Pawn.Weapon != nullptr && Pawn.Weapon.IsInState('BusyReloading') || Pawn.Weapon.IsInState('BusyFixingJam') || Pawn.Weapon.IsZoomed())
		{
			return;
		}
		if (bAction != 0)
		{
			NotifyAdminMessage("You must release your action key to heal yourself.");
			return;
		}
		ServerHealSelf();
	*/
}
void AHumanController::ServerHealSelf()
{
	/*
		if (Pawn.bLockMovement)
		{
			return;
		}
		if (Cast<AAGP_Pawn>(GetPawn()).bHealingInProgress && Cast<AAGP_Pawn>(GetPawn()).Healer != Pawn)
		{
			NotifyAdminMessage("A medic is already healing you.");
			return;
		}
		if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.bQualifiedMedic)
		{
			if (Cast<AAGP_Pawn>(GetPawn()).IsWounded())
			{
				if (Cast<AAGP_Pawn>(GetPawn())._InvSelfHealMedPacks <= 0)
				{
					return;
				}
				if (Pawn.bIsProne || Pawn.bIsCrouched)
				{
					Cast<AAGP_Pawn>(GetPawn()).MedicHealSelf();
				}
				else
				{
					NotifyAdminMessage("To heal yourself safely crouch or go prone and try again.");
				}
			}
		}
	*/
}

void AHumanController::Action()
{
	AActor* ClientAction = nullptr;
	AActor* HitActor = nullptr;
	FVector StartTrace = FVector(0,0,0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	/*
	if (GetNetMode() == ENetMode::NM_Client && Vehicle(Pawn) != nullptr)
	{
		ServerAction(ClientAction);
		return;
	}
	if (GetNetMode() == ENetMode::NM_Client && ! CanTakeAction())
	{
		return;
	}
	ClientAction=_LastGlowActor;
	if (ClientAction == nullptr)
	{
		ClientAction=TryZoomActionTrace();
	}
	if (ClientAction == nullptr)
	{
		GetAxes(Pawn.GetViewRotation(),X,Y,Z);
		StartTrace.X=Pawn.Location.X;
		StartTrace.Y=Pawn.Location.Y;
		StartTrace.Z=Pawn.Location.Z + Pawn.BaseEyeHeight;
		StartTrace += Pawn.CollisionRadius * X;
		EndTrace=StartTrace + 250 * X;
		HitActor=Pawn.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,false);
		if (HitActor != nullptr && HitActor->IsA(Ablackhawk::StaticClass()))
		{
			ClientAction=HitActor;
		}
	}
	ServerAction(ClientAction);
	*/
}

bool AHumanController::CanTakeAction()
{
	/*
	if ((((Pawn == nullptr) || Pawn->bIsSprinting) || (GetTraceDistance() == 0)) || ((Pawn->Weapon != nullptr) && Pawn->Weapon->IsInState("BusyReloading")))
	{
		return false;
	}
	else
	{
		return true;
	}
	*/
	return false;     //FAKE   /ELiZ
}

int32 AHumanController::getZoomActionDistance()
{
	//return int(((float(Pawn->GetShortTraceDistance()) * Pawn->GetZoomMultiplier()) * float(16)));
	return 0;     //FAKE   /ELiZ
}

int32 AHumanController::getMaxDistance(AActor* Other)
{
	AAGP_Objective* obj = nullptr;
	obj = Cast<AAGP_Objective>(Other);
	if ((obj != nullptr) && obj->bLongRange)
	{
		//return getZoomActionDistance();
	}
	else
	{
		//return Super::getMaxDistance(Other);
	}
	return 0;    //FAKE  /ELiZ
}

bool AHumanController::ValidateClientActionOn(AActor* Other)
{
	float max_dist = 0;
	float Distance = 0;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		//Distance = VSize((Pawn.Location - Other.Location));
		max_dist = float(getMaxDistance(Other));
		if (Distance > max_dist)
		{
			return false;
		}
	}
	return true;
}

AActor* AHumanController::TryZoomActionTrace()
{
	AActor* Other = nullptr;
	AAGP_Objective* obj = nullptr;
	/*
	if (Pawn.IsZoomed())
	{
		Other=ManualTrace(getZoomActionDistance());
		obj=AGP_Objective(Other);
		if (obj != nullptr && obj.bLongRange)
		{
			return obj;
		}
	}
	*/
	return nullptr;
}

AActor* AHumanController::TryWeaponTargetTrace()
{
	AActor* Other = nullptr;
	ADecoMesh* MyDeco = nullptr;
	/*
	Other=ManualTrace(26240);
	MyDeco=DecoMesh(Other);
	if (MyDeco != nullptr)
	{
		return MyDeco;
	}
	*/
	return nullptr;
}

AActor* AHumanController::TryJavelinTargetTrace()
{
	FVector StartTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	ABaseWeaponAttachment* BA = nullptr;
	AActor* HitActor = nullptr;
	AActor* TraceFrom = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	/*
	GetAxes(Pawn.GetViewRotation(), X, Y, Z);
	StartTrace.X = Pawn.Location.X;
	StartTrace.Y = Pawn.Location.Y;
	StartTrace.Z = (Pawn.Location.Z + Pawn.BaseEyeHeight);
	(StartTrace += (Pawn.CollisionRadius * X));
	EndTrace = (StartTrace + (float(130000) * X));
	BA = Cast<ABaseWeaponAttachment>(Pawn.Weapon.ThirdPersonActor);
	TraceFrom = BA.GetSource();
	TraceFrom.bUseCollisionStaticMesh = true;
	HitActor = TraceFrom.BoneTrace(HitLocation, HitNormal, EndTrace, StartTrace, HitMaterial, HitBone, true);
	TraceFrom.bUseCollisionStaticMesh = false;
	*/
	return HitActor;
}
void AHumanController::ServerAction(AActor* Other)
{
	/*
			if (! CanTakeAction())
			{
				return;
			}
			if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn()).bHealingInProgress && Cast<AAGP_Pawn>(GetPawn()).Healer == Pawn)
			{
				return;
			}
			if (Pawn.Using(Other))
			{
				return;
			}
			if (Other == nullptr)
			{
				Other=ManualTrace(GetTraceDistance());
			}
			if (Other != nullptr && Other->IsA(Ablackhawk::StaticClass()))
			{
				Log("Trace distance to blackhawk: " + VSize(Other.Location - Pawn.Location));
				if (VSize(Other.Location - Pawn.Location) < 250)
				{
					Log("BH altitude: " + NPCBaseHelicopterController(Cast<AVehicle>(Other).Controller).GetRealAltitude() + ", event: " + NPCBaseHelicopterController(Cast<AVehicle>(Other).Controller).UsedEvent);
					if (Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(Other).Controller).GetRealAltitude() < 150 && NPCBaseHelicopterController(Cast<AVehicle>(Other).Controller).UsedEvent != "None")
					{
						Pawn.TriggerEvent(Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(Other).Controller).UsedEvent,this,Pawn);
						Log("Trying to activate trigger " + NPCBaseHelicopterController(Cast<AVehicle>(Other).Controller).UsedEvent);
					}
				}
				return;
			}
			if (Other != nullptr && ! ValidateClientActionOn(Other))
			{
				Other=nullptr;
			}
			if (Other == nullptr)
			{
				Other=TryZoomActionTrace();
			}
			if (Other != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Found something to activate: " + Other + " Pawn's base: " + Base));
				if (Pawn.Base != nullptr && Pawn.Base->IsA(AMover::StaticClass()))
				{
					UE_LOG(LogTemp, Warning, TEXT("Mover hit, seeing if we're on it (base: " + Pawn.Base + ")"));
					if (Other->IsA(ADoorTrigger::StaticClass()) || Other->IsA(AMover::StaticClass()))
					{
						ClientMessage("You must step back to open this door");
						return;
					}
				}
				if (Other.UsedBy(Pawn))
				{
					return;
				}
			}
			if (Pawn != nullptr)
			{
				SearchForPickup(Pawn.GetShortTraceDistance());
			}
	*/
}

bool AHumanController::SearchForPickup(int32 Distance)
{
	APickup* p = nullptr;
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector SearchLocation = FVector(0, 0, 0);
	TArray<APickup*> PossiblePickups = {};
	FVector EyeToPickup = FVector(0, 0, 0);;
	float BestAngle = 0;
	float CurrentAngle = 0;
	int32 i = 0;
	/*
	if (! IsZero(Pawn.Velocity) && ! IsInState('PlayerCrawling') && ! IsInState('PlayerCrouching'))
	{
		return false;
	}
	GetAxes(Rotation,X,Y,Z);
	SearchLocation=Pawn.Location + Distance / 2 + Pawn.CollisionRadius * X;
	ForEach RadiusActors(APickup::StaticClass(),p,Distance / 2,SearchLocation)
	{
		if (p == nullptr)
		{
		}
		else
		{
			if (p.ReadyToPickup(0))
			{
				if (p.CanSpawnCopy(Pawn,false))
				{
					PossiblePickups.insert (PossiblePickups.Num(),1);
					PossiblePickups[PossiblePickups.Num() - 1]=p;
				}
			}
		}
	}
	p=nullptr;
	BestAngle=-2;
	for (i=0; i<PossiblePickups.Num(); i++)
	{
		EyeToPickup=Normal(PossiblePickups[i].Location - Pawn.EyePosition());
		CurrentAngle= Vector(Rotation) Dot EyeToPickup;
		if (CurrentAngle > BestAngle)
		{
			p=PossiblePickups[i];
			BestAngle=CurrentAngle;
		}
	}
	if (p != nullptr)
	{
		p.TakeItem(Pawn);
		return true;
	}
	*/
	return false;
}

AActor* AHumanController::ManualTrace(int32 Distance)
{
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FRotator CameraRotation = FRotator(0, 0, 0);
	AActor* Other = nullptr;
	bool bOldBlockZeroExtent = false;
	/*
	PlayerCalcView(Other,StartTrace,CameraRotation);
	EndTrace=StartTrace + Distance *  Vector(CameraRotation);
	bOldBlockZeroExtent=Pawn.bBlockZeroExtentTraces;
	Pawn.bBlockZeroExtentTraces=false;
	Other=ActionTrace(EndTrace,StartTrace);
	Pawn.bBlockZeroExtentTraces=bOldBlockZeroExtent;
	if (bPrintShootDebug)
	{
		return Other;
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

bool AHumanController::DoHighlight(AActor* A)
{
	if (A->IsA(AMover::StaticClass()))
	{
		return Cast<AMover>(A)->bUseHighlight;
	}
	else
	{
		if (A->IsA(APawn::StaticClass()) || A->IsA(AAGP_UseTrigger::StaticClass()))
		{
			return false;
		}
		else
		{
			if (A->IsA(ABodyPanel::StaticClass()))
			{
				return Cast<ABodyPanel>(A)->bDoHighlight;
			}
		}
	}
	return true;
}

bool AHumanController::RememberActor(AActor* A)
{
	if (A->IsA(APickup::StaticClass()))
	{
		return true;
	}
	else
	{
		if (A->IsA(AMover::StaticClass()))
		{
			return Cast<AMover>(A)->bUseControl;
		}
		else
		{
			
			if (A->IsA(APawn::StaticClass()) || A->IsA(AAGP_UseTrigger::StaticClass()))
			{
				return true;
			}
			else
			{
				if (A->IsA(ABodyPanel::StaticClass()))
				{
					return true;
				}
			}
			
		}
	}
	return false;
}

int32 AHumanController::getValidActorDistance(AActor* Other)
{
	/*
	if (Cast<AAGP_Objective>(Other) != nullptr)
	{
		if (Other->IsA(AAGP_CoopESSObjective::StaticClass()))
		{
			return Cast<AAGP_Objective>(Other).getObserveDistance();
		}
		if (Cast<AAGP_Objective>(Other).bLongRange)
		{
			return Pawn.GetZoomTraceDistance();
		}
		else
		{
			return Pawn.GetShortTraceDistance();
		}
	}
	else
	{
		if (Cast<AInventory>(Other) != nullptr || Cast<APickup>(Other) != nullptr)
		{
			return Pawn.GetShortTraceDistance();
		}
		else
		{
			if (Cast<AMover>(Other) != nullptr)
			{
				return Pawn.GetShortTraceDistance();
			}
			else
			{
				if (Cast<APawn>(Other) != nullptr)
				{
					if (Pawn.IsFriend(Cast<APawn>(Other)))
					{
						return Pawn.GetFriendTraceDistance();
					}
					if (Pawn.IsEnemy(Cast<APawn>(Other)))
					{
						return Pawn.GetEnemyTraceDistance();
					}
				}
				else
				{
					return GetTraceDistance();
				}
			}
		}
	}
	*/
	return 0;    //FAKE  /ELiZ
}

bool AHumanController::CanIDActor(AActor* Other, float hit_distance_sq)
{
	float max_dist = 0;
	/*
	max_dist=getValidActorDistance(Other);
	if (hit_distance_sq > max_dist * max_dist)
	{
		return false;
	}
	*/
	return true;
}

int32 AHumanController::getValidActorDistanceWeaponTarget(AActor* Other)
{
	/*
	if (Cast<AAGP_Objective>(Other) != nullptr)
	{
		if (Other->IsA(AAGP_CoopESSObjective::StaticClass()))
		{
			return Cast<AAGP_Objective>(Other).getObserveDistance();
		}
		if (Cast<AAGP_Objective>(Other).bLongRange)
		{
			return Pawn.GetZoomTraceDistance();
		}
		else
		{
			return Pawn.GetShortTraceDistance();
		}
	}
	else
	{
		if (Cast<AInventory>(Other) != nullptr || Cast<APickup>(Other) != nullptr)
		{
			return Pawn.GetShortTraceDistance();
		}
		else
		{
			if (Cast<AMover>(Other) != nullptr)
			{
				return Pawn.GetShortTraceDistance() * 16;
			}
			else
			{
				if (Cast<APawn>(Other) != nullptr)
				{
				}
				return GetTraceDistance();
			}
		}
	}
	*/
	return 0;    //FAKE   /ELiZ
}

bool AHumanController::CanIDWeaponTarget(AActor* Other, float hit_distance_sq)
{
	float max_dist = 0;
	/*
	max_dist=getValidActorDistanceWeaponTarget(Other);
	if (hit_distance_sq > max_dist * max_dist)
	{
		return false;
	}
	*/
	return true;
}

bool AHumanController::OverrideActionTrace(AActor* A)
{
	/*
	if (A == nullptr)
	{
		return false;
	}
	else
	{
		if (A.Physics == 14)
		{
			return false;
		}
		else
		{
			if (A->IsA(APickup::StaticClass()))
			{
				return true;
			}
			else
			{
				if (A->IsA(APawn::StaticClass()))
				{
					return Pawn(A).PlayerReplicationInfo != nullptr;
				}
				else
				{
					return false;
				}
			}
		}
	}
	*/
	return false;    //FAKE   /ELiZ
}

AActor* AHumanController::ActionTrace(FVector EndTrace, FVector StartTrace, FVector& HitLocation)
{
	AActor* Trace1 = nullptr;
	AActor* Trace2 = nullptr;
	FVector HitLocation2 = FVector(0, 0, 0);
	FVector HitNormal = FVector(0,0,0);
	/*
	Trace1=Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
	if (Trace1 != nullptr)
	{
		if (Trace1.Physics == 14)
		{
			StartTrace=HitLocation;
			Trace2=Trace1.Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
			Trace1=Trace2;
		}
		if (Trace1 != nullptr && Trace1->IsA(AAGP_Objective::StaticClass()))
		{
			StartTrace=HitLocation;
			Trace2=Trace1.Trace(HitLocation2,HitNormal,EndTrace,StartTrace,true);
			if (OverrideActionTrace(Trace2))
			{
				HitLocation=HitLocation2;
				return Trace2;
			}
		}
		return Trace1;
	}
	*/
	return nullptr;
}

void AHumanController::AutoTrace()
{
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	AActor* Other = nullptr;
	int32 trace_dist = 0;
	bool bDeepTrace = false;
	float hit_distance_sq = 0;
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	trace_dist=GetTraceDistance();
	if (trace_dist == 0)
	{
		return;
	}
	GetAxes(Pawn.GetViewRotation(),X,Y,Z);
	StartTrace=Pawn.EyePosition();
	if (! Pawn->IsA(ACROWS_HMMWV::StaticClass()))
	{
		StartTrace += Pawn.CollisionRadius * X;
	}
	EndTrace=StartTrace;
	EndTrace += trace_dist * X;
	Other=ActionTrace(EndTrace,StartTrace,HitLocation);
	if (Other != nullptr)
	{
		if (Other != _LastGlowActor)
		{
			if (_LastGlowActor != nullptr)
			{
				_LastGlowActor.AmbientGlow=_SavedAmbientGlow;
			}
			if (RememberActor(Other))
			{
				_SavedAmbientGlow=Other.AmbientGlow;
				if (DoHighlight(Other))
				{
					Other.AmbientGlow=255;
				}
				_LastGlowActor=Other;
			}
			else
			{
				_LastGlowActor=nullptr;
			}
		}
		if (Other->IsA(APawn::StaticClass()))
		{
			_AnimPawn=Pawn(Other);
		}
	}
	else
	{
		if (! _bPermaTraceDebug)
		{
			_AnimPawn=nullptr;
		}
		if (_LastGlowActor != nullptr)
		{
			_LastGlowActor.AmbientGlow=_SavedAmbientGlow;
			_LastGlowActor=nullptr;
		}
	}
	AutoTraceCount=AutoTraceCount + 1 % AutoTraceFrequency;
	if (AutoTraceCount == 0)
	{
		if (Other == nullptr)
		{
			EndTrace=StartTrace + Pawn.GetDeepTraceDistance() * X;
			Other=ActionTrace(EndTrace,StartTrace,HitLocation);
			bDeepTrace=true;
		}
		if (Other == nullptr)
		{
			Other=TryZoomActionTrace();
			if (Other != nullptr)
			{
				HitLocation=Other.Location;
			}
		}
		if (Other == nullptr && Pawn.Weapon != nullptr && Pawn.Weapon.bLongTargetTrace)
		{
			Other=TryWeaponTargetTrace();
		}
		if (Other != nullptr)
		{
			if (! Other->IsA(AAGP_CoopESSObjective::StaticClass()) && bLookingAtZombieObject)
			{
				bLookingAtZombieObject=false;
			}
		}
		if (Cast<AVehicle>(Pawn) != nullptr)
		{
			Other=ManualTrace(trace_dist * 1.5);
		}
		if (MyHUD != nullptr)
		{
			ClearActorID();
			if (Other != nullptr)
			{
				hit_distance_sq=VSizeSquared(HitLocation - StartTrace);
				if (CanIDWeaponTarget(Other,hit_distance_sq))
				{
					TryToIDWeaponTarget(Other);
				}
				if (CanIDActor(Other,hit_distance_sq))
				{
					TryToIDActor(Other);
					TryToIDPawn(Other,bDeepTrace);
				}
			}
		}
	}
	if (Other == nullptr && Pawn.Weapon != nullptr && Pawn.Weapon.IsZoomed() && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass()))
	{
		Other=TryJavelinTargetTrace();
		TryToIDJavelinTarget(Other);
	}
	*/
}
void AHumanController::ClearActorID()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		//HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10))->ActionText="";
		//HUDPlayerID(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(16))->NoTarget();
		//HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10))->SetColorID(0);
		//HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17))->NoTarget();
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->bActiveBreacherTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveDemolitionTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveObjPickupTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bInactiveObjPickupTarget=false;
		Cast<AAGP_Pawn>(GetPawn())->bActiveJavelinTarget=false;
	}
}

void AHumanController::TryToIDWeaponTarget(AActor* A)
{
	ADecoMesh* MyDeco = nullptr;
	UHUDWeaponTarget* WeaponTarget = nullptr;
	UaDamageType* MyDamage = nullptr;
	AWeapon* MyWeapon = nullptr;
	AAGP_ObjectivePickup* ObjPickup = nullptr;
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (A != nullptr)
	{
		MyDeco=DecoMesh(A);
	}
	if (A->IsA(AAGP_CoopESSObjective::StaticClass()) && ! Cast<AAGP_Objective>(A).isReportable())
	{
		if (! bLookingAtZombieObject)
		{
			bLookingAtZombieObject=true;
			fTime=GetWorld()->GetTimeSeconds();
		}
		if (bLookingAtZombieObject)
		{
			if (GetWorld()->GetTimeSeconds() - fTime > 1)
			{
				AGP_Objective(A).MakeES2ObjectiveReportable();
				abpobjESSLastSeen=AGP_Objective(A);
				ServerTrackESSObjectSeen(abpobjESSLastSeen);
			}
		}
		if (! Cast<AAGP_Objective>(A).isReportable())
		{
			return;
		}
	}
	if (A->IsA(ANPCBaseCivilianController::StaticClass()))
	{
		Log("Setting LastReportAbleNPC as: " + LastReportableNPC);
		LastReportableNPC=NPCBaseController(A);
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	if (A != nullptr)
	{
		ObjPickup=AGP_ObjectivePickup(A);
	}
	if (A->IsA(AAGP_Objective::StaticClass()) == true)
	{
		if (! Cast<AAGP_Objective>(A).bDisabled && ! A->IsA(AAGP_CarryObjective::StaticClass()))
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
			if (! A->IsA(AAGP_CoopESSObjective::StaticClass()))
			{
				Cast<AAGP_Pawn>(GetPawn()).TargetObjLetter=AGP_Objective(A).HUDLetter;
				WeaponTarget.SetTarget();
				Cast<AAGP_Pawn>(GetPawn()).bActiveObjectiveTarget=true;
			}
			else
			{
				Cast<AAGP_Pawn>(GetPawn()).stTargetDescription=AGP_Objective(A).HUDText;
				WeaponTarget.SetTarget();
				Cast<AAGP_Pawn>(GetPawn()).bActiveCoopESSTarget=true;
			}
		}
	}
	if (ObjPickup != nullptr && ObjPickup.bDisplayTargetingInfo)
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
		}
		if (ObjPickup.idTeamOwner == PlayerReplicationInfo->Team->TeamIndex || ObjPickup.idTeamOwner == 255)
		{
			WeaponTarget.SetTarget();
			Cast<AAGP_Pawn>(GetPawn()).bActiveObjPickupTarget=true;
		}
		else
		{
			WeaponTarget.SetTarget();
			Cast<AAGP_Pawn>(GetPawn()).bInactiveObjPickupTarget=true;
		}
	}
	if (MyDeco != nullptr && MyDeco.bDisplayTargetingInfo)
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
		}
		if (MyDeco.bBreachable == true)
		{
			WeaponTarget.SetTarget();
			if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
			{
				Cast<AAGP_Pawn>(GetPawn()).bActiveBreacherTarget=true;
			}
		}
		if (Pawn.Weapon != nullptr)
		{
			MyWeapon=Pawn.Weapon;
			if (MyWeapon->IsA(AThrowWeapon::StaticClass()))
			{
				MyDamage=Cast<AThrowWeapon>(MyWeapon).MyDamageType;
			}
			else
			{
				if (MyWeapon.GetCurrentAmmoType().ProjectileClass != nullptr)
				{
					MyDamage=MyWeapon.GetCurrentAmmoType().ProjectileClass.Default.MyDamageType;
				}
				else
				{
					MyDamage=MyWeapon.GetCurrentAmmoType().MyDamageType;
				}
			}
			if (MyDeco.ShouldDisplayDamageType(MyDamage))
			{
				WeaponTarget.SetTarget();
				switch(MyDamage.Default.AmmoType)
				{
					case 14:
					if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
					{
						Cast<AAGP_Pawn>(GetPawn()).bActiveDemolitionTarget=true;
					}
					break;
					default:
				}
			}
		}
	}
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}

void AHumanController::TryToIDJavelinTarget(AActor* A)
{
	UHUDWeaponTarget* WeaponTarget = nullptr;
	/*
	if (Pawn == nullptr || Pawn.Weapon == nullptr)
	{
		return;
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	if (A != nullptr && A.ValidJavelinTarget > 0)
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			WeaponTarget=HUDWeaponTarget(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(17));
		}
		WeaponTarget.SetTarget();
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).bActiveJavelinTarget=true;
		}
	}
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}

bool AHumanController::TryToIDActor(AActor* A)
{
	ABodyPanel* MyBodyPanel = nullptr;
	AVehicle* MyVehicle = nullptr;
	int32 PositionIndex = 0;
	/*
	if (A != nullptr)
	{
		MyBodyPanel=BodyPanel(A);
		if (MyBodyPanel != nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				MyVehicle=Vehicle(Pawn);
				if (MyVehicle == nullptr)
				{
					Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
					HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=MyBodyPanel.ExteriorHintText;
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
				else
				{
					if (MyVehicle.Driver != nullptr && MyVehicle.Driver.Health > 0)
					{
						switch(MyVehicle.Driver.AttachmentBone)
						{
							case 'B_Sitbone_LF':
							if (MyVehicle->IsA(ACROWS_HMMWV::StaticClass()))
							{
								PositionIndex=7;
								break;
							}
							PositionIndex=3;
						}
						case 'B_Sitbone_LB':
						if (MyVehicle->IsA(ACROWS_Gunner::StaticClass()))
						{
							PositionIndex=0;
						}
						else
						{
							PositionIndex=4;
						}
						case 'B_Sitbone_RF':
						if (! MyVehicle->IsA(AHMMWV_RunningBoardPassenger::StaticClass()))
						{
							PositionIndex=1;
						}
						else
						{
							PositionIndex=5;
						}
						case 'B_Sitbone_RB':
						if (! MyVehicle->IsA(AHMMWV_RunningBoardPassenger::StaticClass()))
						{
							PositionIndex=2;
						}
						else
						{
							PositionIndex=6;
						}
						default:
						PositionIndex=-1;
						if (PositionIndex >= 0)
						{
							Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
							HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=MyBodyPanel.PassengerHintText[PositionIndex];
							Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
						}
					}
					else
					{
						HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText="";
					}
				}
				if (AGameInfo::StaticClass().GetKeyBindName("Action",this) != "")
				{
					Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
					HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=Repl(Cast<UHUDCrosshair>(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText,"%UseKey%",AGameInfo::StaticClass().GetKeyBindName("Action",this));
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
			}
		}
		else
		{
			if (GetNetMode() == ENetMode::NM_Client && A.HUDTextTeam.Num() > PlayerReplicationInfo->Team->TeamIndex)
			{
				if (Cast<AAGP_HUD>(MyHUD) != nullptr)
				{
					Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
					HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=A.HUDTextTeam[PlayerReplicationInfo->Team->TeamIndex];
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
			}
			else
			{
				if (A->IsA(AAGP_ESSObjective::StaticClass()))
				{
					if (! Cast<AAGP_Objective>(A).bDisabled)
					{
						if (A->IsA(AAGP_CoopESSObjective::StaticClass()) && ! Cast<AAGP_Objective>(A).isReportable())
						{
							return false;
						}
						abpobjESSLastSeen=AGP_Objective(A);
						ServerTrackESSObjectSeen(abpobjESSLastSeen);
					}
					else
					{
						return false;
					}
				}
				if (A->IsA(ANPCBaseCivilianController::StaticClass()))
				{
					Log("Setting LastReportAbleNPC as: " + LastReportableNPC);
					LastReportableNPC=NPCBaseController(A);
				}
				if (Cast<AAGP_HUD>(MyHUD) != nullptr)
				{
					Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
					if (! A->IsA(AAGP_CoopESSObjective::StaticClass()))
					{
						HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText=A.HUDText;
					}
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
				}
			}
		}
		return true;
	}
	else
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10)).ActionText="";
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		}
		return false;
	}
	*/
	return false;    //FAKE  /ELiZ
}

void AHumanController::ServerTrackESSObjectSeen(AAGP_Objective* agpobjSeen)
{
	/*
		int32 iObj;
		for (iObj=0; iObj<aagpobjSeen.Num; iObj++)
		{
			if (aagpobjSeen[iObj] == agpobjSeen)
			{
				return;
			}
		}
		aagpobjSeen.Insert (agpobjSeen, 0)
		//aagpobjSeen.insert (aagpobjSeen.Num,1);
		//aagpobjSeen[0]=agpobjSeen;
		if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ESSObjectDiscovered(agpobjSeen.Location);
		}
		*/
}

void AHumanController::TryToIDObjective(AActor* A, bool bDeepTrace)
{
	AAGP_Objective* IDObjective = nullptr;
	int32 color_id = 0;
	UHUDCrosshair* CrossHair = nullptr;
	/*
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	if (A->IsA(AAGP_Objective::StaticClass()))
	{
		IDObjective=AGP_Objective(A);
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		CrossHair=HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10));
	}
	if (IDObjective != nullptr)
	{
		if (IDObjective.bDisabled)
		{
			color_id=1;
		}
		else
		{
			color_id=2;
		}
		CrossHair.SetColorID(color_id);
	}
	else
	{
		CrossHair.SetColorID(0);
	}
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}

void AHumanController::TryToIDPawn(AActor* A, bool bDeepTrace)
{
	AAGP_Pawn* IDPawn = nullptr;
	int32 color_id = 0;
	UHUDCrosshair* CrossHair = nullptr;
	UHUDPlayerID* PlayerID = nullptr;
	/*
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	if (A != nullptr)
	{
		if (A->IsA(AAGP_Pawn::StaticClass()))
		{
			IDPawn=Cast<AAGP_Pawn>(A);
		}
		else
		{
			if (A->IsA(AAuxCollisionCylinder::StaticClass()))
			{
				IDPawn=Cast<AAGP_Pawn>(Cast<AAuxCollisionCylinder>(A).Owner);
			}
		}
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		CrossHair=HUDCrosshair(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(10));
		PlayerID=HUDPlayerID(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(16));
	}
	if (IDPawn != nullptr && IDPawn != Pawn)
	{
		if (Pawn.IsFriend(IDPawn))
		{
			color_id=1;
		}
		else
		{
			if (Pawn.IsEnemy(IDPawn))
			{
				if (TournamentIsTournament() || ! bExploreTheArmyServer)
				{
					PlayerID.NoTarget();
					CrossHair.SetColorID(0);
					Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
					return;
				}
				color_id=2;
			}
		}
		PlayerID.SetTarget(IDPawn.PlayerReplicationInfo,color_id,bDeepTrace);
		CrossHair.SetColorID(color_id);
	}
	else
	{
		PlayerID.NoTarget();
		CrossHair.SetColorID(0);
	}
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::NotifyPromotion(bool bFTL, uint8 yFT)
{
	FString Message1;
	FString message2;
	if (TournamentIsTournament())
	{
		return;
	}
	Message1="You have been field promoted to ";
	if (bFTL)
	{
		message2="FireTeam ";
		switch(yFT)
		{
			case 0:
				message2=message2 + "Alpha ";
				break;
			case 1:
				message2=message2 + "Bravo ";
				break;
			case 2:
				message2=message2 + "Charlie ";
				break;
			case 3:
				message2=message2 + "Delta ";
				break;
			default:
				break;
		}
	}
	else
	{
		message2="Squad ";
	}
	message2=message2 + "Leader";
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(3,Message1,message2);
	}
}
void AHumanController::NotifyNoScore(FName Reason)
{
	FString Message1;
	FString message2;
	if (bExploreTheArmyServer)
	{
		return;
	}
	Message1="Scoring for this round will not apply to your Personnel Jacket because ";

	if (Reason == "NoEnemy")
	{
		message2 = "there are no players on the other team";
	}
	else
	{
		if (Reason == "SmallGame")
		{
			message2 = "there were not enough players in the game";
		}
		else
		{
			if (Reason == "ShortGame")
			{
				message2 = "the game did not last long enough";
			}
			else
			{
				if (Reason == "CheatServer")
				{
					message2 = "the game server is running with cheats enabled";
				}
				else
				{
					message2 = "UNKNOWN REASON: " + Reason.ToString();
				}
			}
		}
	}
	if (! TournamentIsTournament())
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(3,Message1,message2);
		}
	}
}
void AHumanController::SetSquadTarget()
{
	/*
		if (! PlayerReplicationInfo.IsSquadLeader())
		{
			return;
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		if (_cHUDCompass == nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				_cHUDCompass=UIHUDCompass(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(5));
			}
		}
		_cHUDCompass.SetTarget(! _cHUDCompass.IsSettingTarget());
		if (_cHUDCompass.IsSettingTarget())
		{
			ClientMessage("Select the objective to set as your squad's target by pressing the appropriate letter.");
		}
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}
void AHumanController::ServerSetSquadTarget(int32 iTeamIndex, uint8 objnum)
{
	/*
		if (Level.Game->IsA(AAGP_GameInfo::StaticClass()))
		{
			AGP_GameInfo(GetGameMode()).SetSquadTarget(iTeamIndex,objnum);
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetSquadTarget called game.setsquadtarget with" @ objnum));
		}
	*/
}

bool AHumanController::CanCommo()
{
	/*
	if (Pawn == nullptr || IsInState('BaseSpectating'))
	{
		return false;
	}
	return Pawn.CanCommo();
	*/
	return false;   //FAKE   /ELiZ
}

void AHumanController::CommoCycle()
{
	bool bShowingMessages = false;
	/*
	if (GetNetMode() == ENetMode::NM_Standalone || Pawn == nullptr || Pawn.Health <= 0 || ! CanCommo())
	{
		return;
	}
	if (_cHUDCommoInfo == nullptr)
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		}
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	bShowingMessages=_cHUDCommoInfo.ShowingMessages();
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	if (bShowingMessages)
	{
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).CommoCycleState();
		}
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	_cHUDCommoInfo.ShowMessages(true);
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/
}

void AHumanController::CommoSendMessage(int32 i)
{
	ACommoLocalMessage* CommoType = nullptr;
	/*
	if (_cHUDCommoInfo == nullptr)
	{
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
			_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
			Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		}
	}
	if (i == 0)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowNextMessageSet();
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
		return;
	}
	if (! CanCommo())
	{
		return;
	}
	CommoType=nullptr;
	switch(Pawn.CommoState)
	{
		case 0:
		CommoType='CommoHandSignal';
		break;
		case 1:
		CommoType='CommoWhisper';
		break;
		case 2:
		CommoType='CommoShout';
		break;
		case 3:
		CommoType='CommoRadio';
		break;
		case 4:
		CommoType='CommoSquad';
		break;
		case 5:
		Player.Console.Talk();
		return;
		break;
		default:
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	_cHUDCommoInfo.ShowMessages(false);
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		CommoPlayAnim(CommoType,_cHUDCommoInfo.IndexToMessage(i) - 1);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	}
	Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
	CommoSend(CommoType,_cHUDCommoInfo.IndexToMessage(i) - 1);
	Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
	*/

}

void AHumanController::CommoMode(ECommoType Type)
{
	/*
		if (GetNetMode() == ENetMode::NM_Standalone || Type == 4 && ! PlayerReplicationInfo.IsSquadLeader() || Type == 4 && PlayerReplicationInfo.bGuerrillaPS || ! CanCommo())
		{
			return;
		}
		if (_cHUDCommoInfo == nullptr)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
				_cHUDCommoInfo=HUDCommoInfo(Cast<AAGP_HUD>(MyHUD)->GetHUDControl(13));
				Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();
			}
		}
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).SetCommoState(Type);
		}
		Cast<AAGP_HUD>(MyHUD)->SetHUDActor();
		_cHUDCommoInfo.ShowMessages(true);
		Cast<AAGP_HUD>(MyHUD)->FreeHUDActor();

	*/
}

void AHumanController::CommoSend(ACommoLocalMessage* CommoType, int32 i)
{
	//BroadcastLocalizedMessage(CommoType, i, PlayerReplicationInfo);
	//CommoPlayAnim(CommoType, i);
}

void AHumanController::CommoPlayAnim(ACommoLocalMessage* CommoType, int32 i)
{
	FName Anim = "";
	Anim = CommoType->GetAnim(i);
	if (Anim != "None")
	{
		//Pawn.HandSignalSet(Anim);
		//Pawn.PlayHandSignalIndex();
	}
}

bool AHumanController::CheckRIFlood()
{
	if (yFloodCount != 255)
	{
		if (GetWorld()->GetTimeSeconds() > tFlood)
		{
			yFloodCount=0;
			tFlood=GetWorld()->GetTimeSeconds() + 5;
		}
		else
		{
			if (yFloodCount > 2)
			{
				tFlood += 0.5;
				if (yFloodCount == 3)
				{
					ClientMessage("Please try again in a few seconds.");
					yFloodCount=4;
				}
				return true;
			}
			else
			{
				yFloodCount ++;
				tFlood += 2;
			}
		}
	}
	return false;
}

void AHumanController::ReportIn()
{
	/*
		if (PlayerReplicationInfo.isDead())
		{
			return;
		}
		if (CheckRIFlood())
		{
			return;
		}
		ServerReportIn();
	*/
}
void AHumanController::ServerReportIn()
{
	/*
		if (PlayerReplicationInfo.isDead())
		{
			return;
		}
		ServerSay(PlayerReplicationInfo.GetLocationName(),'ReportIn');
	*/
}

void AHumanController::ClientESSNotifyAdminMessage(FString sString)
{
	//NotifyAdminMessage(ReplaceCommandString(sString));
}

void AHumanController::ClientESSConsoleMessage(FString sString)
{
	//ClientMessage(ReplaceCommandString(sString));
}

void AHumanController::SetDelayReport(float NextReportInSeconds)
{
	fLevelTime = GetWorld()->GetTimeSeconds();
	NextReportAllowedIn = NextReportInSeconds;
}

void AHumanController::ESSObjectiveReport()
{
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	AActor* Other = nullptr;
	int32 trace_dist = 0;
	float hit_distance_sq = 0;
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo.isDead())
	{
		return;
	}
	Log("ESSObjectiveReport():  Current Level time: " @ GetWorld()->GetTimeSeconds() @ "      fLevelTime: " @ fLevelTime @ "     GetWorld()->GetTimeSeconds() - fLevelTime is : " @ GetWorld()->GetTimeSeconds() - fLevelTime @ "        NextReportAllowedIn :" @ NextReportAllowedIn);
	if (GetWorld()->GetTimeSeconds() - fLevelTime <= NextReportAllowedIn)
	{
		ClientMessage("Wait for radio traffic to clear before trying to report another object");
		return;
	}
	trace_dist=GetTraceDistance();
	GetAxes(Pawn.GetViewRotation(),X,Y,Z);
	StartTrace=Pawn.EyePosition();
	if (! Pawn->IsA(ACROWS_HMMWV::StaticClass()))
	{
		StartTrace += Pawn.CollisionRadius * X;
	}
	EndTrace=StartTrace;
	EndTrace=StartTrace + Pawn.GetDeepTraceDistance() * 2 * X;
	Other=ActionTrace(EndTrace,StartTrace,HitLocation);
	if (Other != nullptr)
	{
		hit_distance_sq=VSizeSquared(HitLocation - StartTrace);
		Pawn.ReportCivilianEvent(Cast<APawn>(Other),hit_distance_sq,this);
	}
	else
	{
		Log("Trace returned None!!!");
	}
	if (abpobjESSLastSeen == nullptr)
	{
		Log("Other is: " + Other);
		if (! Other->IsA(AAGP_Pawn::StaticClass()))
		{
			ClientMessage("You haven't seen anything odd so there's nothing to report.");
		}
		return;
	}
	if (bNPCReported)
	{
		bNPCReported=false;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && CheckRIFlood())
	{
		return;
	}
	ServerESSObjectiveReport(abpobjESSLastSeen);
	*/
}

void AHumanController::ServerESSObjectiveReport(AAGP_Objective* agpobj)
{
	float fpRadioDelay = 0;
	float fInteractRange = 0;
	float fRangeFromObject = 0;
	AFlagMeshActor* smIter = nullptr;
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo.isDead())
	{
		Log("returning we arnt standalone");
		return;
	}
	if (agpobj == nullptr)
	{
		if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
		}
		ClientMessage("You haven't seen anything odd so there's nothing to report.");
		return;
	}
	if (agpobj.bDisabled)
	{
		if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectUnnecessaryUse();
		}
		return;
	}
	Log("agpobj.bPlayerRadioedObectiveInfo" @ agpobj.bPlayerRadioedObectiveInfo);
	Log("agpobj.fpTimeUntilESSInvestigateRadioCompletes" @ agpobj.fpTimeUntilESSInvestigateRadioCompletes);
	if (agpobj.bPlayerRadioedObectiveInfo || agpobj.fpTimeUntilESSInvestigateRadioCompletes > 0)
	{
		if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectUnnecessaryUse();
		}
		return;
	}
	if (agpobj->IsA(AAGP_CoopESSObjective::StaticClass()))
	{
		fInteractRange=agpobj.getReportDistance();
		fRangeFromObject=VSize(Pawn.Location - agpobj.Location);
		if (fRangeFromObject > fInteractRange)
		{
			if (Level.Game.Stats.PlayerStats[PlayerStatsIndex] != nullptr)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
			}
			ClientMessage("You're too far away from the " + agpobj.HUDText + " to report it.");
			return;
		}
		ESSObjectSpotted(agpobj);
		smIter=agpobj.getFlagReference();
		if (smIter != nullptr)
		{
			smIter.bHidden=false;
		}
		else
		{
			ForEach AllActors('FlagMeshActor',smIter)
			{
				if (smIter.Tag == agpobj.getFlagTag())
				{
					Log("Found the Flag");
					if (smIter.bHidden)
					{
						Log("Now make it visible.");
						smIter.bHidden=false;
					}
				}
			}
		}
		if (agpobj.getReportEventName() != "None")
		{
			TriggerEvent(agpobj.getReportEventName(),this,Pawn);
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(agpobj,4,this);
			}
		}
	}
	else
	{
		if (agpobj->IsA(AAGP_ESSObjective::StaticClass()))
		{
			if (VSize(Pawn.Location - agpobj.Location) > 300)
			{
				Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportingErrors();
				ClientMessage("You're too far away from the " + agpobj.HUDText + " to report it.");
				return;
			}
		}
	}
	if (! agpobj.spBeenAccountedFor && EventLab != nullptr)
	{
		if (! agpobj.isDummyTrainingObject())
		{
			EventLab.EL_ES2ObjectFound(agpobj.Score_AssaultPlayer);
		}
		agpobj.spBeenAccountedFor=true;
	}
	if (Cast<AAGP_GameInfo>(GetGameMode()) != nullptr && ! agpobj.isDummyTrainingObject())
	{
		AGP_GameInfo(GetGameMode()).ScoreAGPObjective(PlayerReplicationInfo.Team,agpobj,false,PlayerReplicationInfo);
		ClientMessage("For following proper procedures you gained " + agpobj.Score_AssaultPlayer + " points.");
	}
	if (! agpobj->IsA(AAGP_CoopESSObjective::StaticClass()))
	{
		if (PlayerReplicationInfo.Team != nullptr && PlayerReplicationInfo->Team->TeamIndex == 1)
		{
			agpobj.ObjectiveOnCompass=agpobj.3;
		}
		else
		{
			agpobj.ObjectiveOnCompass=agpobj.2;
		}
	}
	agpobj.bPlayerRadioedObectiveInfo=true;
	agpobj.ctrlrESSReporter=this;
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		ClientMessage(UserName + " Radios: " + agpobj.sDiscoveredRadioMessage);
	}
	else
	{
		Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo->Team->TeamIndex,agpobj.sDiscoveredRadioMessage,'ReportESSObjective');
	}
	if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
	{
		Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ESSObjectDiscoveryRadioed();
		if (agpobj.bDangerous)
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedLethal();
		}
		else
		{
			Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedNonLethal();
		}
	}
	fpRadioDelay=1.5 + FMath::FRand() * 3;
	if (! agpobj->IsA(AAGP_CoopESSObjective::StaticClass()))
	{
		SetCustomTimer(fpRadioDelay,false,'ESSRadioResponse');
	}
	else
	{
		stCoopESSFoundItemText=agpobj.getAcknowledgeText();
		sndCoopESSFoundItemSound=agpobj.getAcknowledgeVO();
		SetCustomTimer(fpRadioDelay,false,'CoopESSRadioResponse');
	}
	if (agpobj->IsA(AAGP_CoopESSObjective::StaticClass()))
	{
		agpobj.fpTimeUntilESSInvestigateRadioCompletes=GetWorld()->GetTimeSeconds() + agpobj.getDialogLength() + fpRadioDelay;
		SetDelayReport(agpobj.getDialogLength() + fpRadioDelay);
		if (agpobj.isUseOnReport())
		{
			agpobj.AccomplishObjective(Pawn);
		}
	}
	else
	{
		agpobj.fpTimeUntilESSInvestigateRadioCompletes=GetWorld()->GetTimeSeconds() + 8 + fpRadioDelay;
	}
	Level.Game.Stats.PlayerStats[PlayerStatsIndex].StatEvent_ObjectReportedNonLethal();
	*/
}

void AHumanController::ESSRadioResponse()
{
	/*
	if (! bDisableES2RadioMessages)
	{
		ClientPlaySound(sndESSFoundItemAcknowledgement);
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		ClientMessage("S2 Radios: This is Sierra Two, roger your unknown object.  Identify the object and report back with your findings.  Exercise extreme caution. Out.");
	}
	else
	{
		Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo->Team->TeamIndex,"S2 Radios: This is Sierra Two, roger your unknown object.  Identify the object and report back with your findings.  Exercise extreme caution. Out.",'ReportESSObjective');
	}
	*/
}
void AHumanController::CoopESSRadioResponse()
{
	if (! bDisableES2RadioMessages)
	{
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			ClientPlaySound(sndCoopESSFoundItemSound);
		}
		else
		{
			ServerPlaySound(sndCoopESSFoundItemSound);
			ClientPlaySound(sndCoopESSFoundItemSound);
		}
	}
	if (stCoopESSFoundItemText != "")
	{
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			//ClientMessage(stCoopESSFoundItemText);
		}
		else
		{
			//Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo->Team->TeamIndex,stCoopESSFoundItemText,'ReportESSObjective');
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No text defined by CoopES2Objective"));
	}
}
void AHumanController::ClientESSRadioInvestigateOrder(USoundBase* sndESSObjectiveRadioAcknowledgement)
{
	/*
	if (!bDisableES2RadioMessages)
	{
		ClientPlaySound(sndESSObjectiveRadioAcknowledgement);
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		ClientMessage("S2 Radios: Roger your intel report.  Use this intel to locate and complete this new object.  Sierra Two, out.");
	}
	else
	{
		Level.Game.BroadcastHandler.BroadcastTeamByIndex(PlayerReplicationInfo->Team->TeamIndex, "S2 Radios: Roger your intel report.  Use this intel to locate and complete this new object.  Sierra Two, out.", 'ReportESSObjective');
	}
	*/
}
void AHumanController::ClientCoopESSRadioInvestigateOrder(USoundBase* sndESSRadioAcknowledgement)
{
	/*
		Log("Playing sndESSRadioAcknowledgement: " + sndESSRadioAcknowledgement);
		if (! bDisableES2RadioMessages)
		{
			if (GetNetMode() == ENetMode::NM_Standalone)
			{
				ClientPlaySound(sndESSRadioAcknowledgement);
			}
			else
			{
				ServerPlaySound(sndESSRadioAcknowledgement);
				ClientPlaySound(sndESSRadioAcknowledgement);
			}
		}
	*/
}
void AHumanController::ClientESSRadioSuccessMessage(USoundBase* sndESSObjectiveCompletionAcknowledgement)
{
	/*
		if (! bDisableES2RadioMessages)
		{
			ClientPlaySound(sndESSObjectiveCompletionAcknowledgement);
		}
	*/
}
void AHumanController::ClientESSPlayIntroduction(USoundBase* sndIntro)
{
	/*
		if (bDisableES2Introduction)
		{
			return;
		}
		if (! bESSIntroPlayed || GameReplicationInfo.RoundsPerMatch == GameReplicationInfo.RemainingRounds)
		{
			bESSIntroPlayed=true;
			ClientPlaySound(sndIntro);
		}
	*/
}

bool AHumanController::StartMantle()
{
	int32 EndPosture = 0;
	FVector Point = FVector(0, 0, 0);
	FVector Normal = FVector(0,0,0);
	AAGP_Pawn* p = nullptr;
	/*
	if (IsInState('PlayerCrawling') || IsInState('PlayerCrouching'))
	{
		return false;
	}
	EndPosture=Mantle(Point,Normal);
	if (EndPosture >= 0)
	{
		p=Cast<AAGP_Pawn>(GetPawn());
		if (p != nullptr)
		{
			if (p.Velocity.Z < p.fFallDamageSpd)
			{
				if (Level.debugMantle)
				{
					ScreenPrint("Damage Taken" @ p.fFallDamageSpd - p.Velocity.Z);
				}
				Pawn.TakeDamage(p.fFallDamageSpd - p.Velocity.Z,Pawn,Pawn->GetActorLocation(),FVector(0,0,0),'FallDamage');
				if (IsInState('Dead'))
				{
					return true;
				}
			}
			p.StartMantle(EndPosture,Point,Rotation);
		}
		return true;
	}
	*/
	return false;
}

bool AHumanController::IsTeammateInjured()
{
	int32 i = 0;
	ATeamInfo* Team = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	Team = PlayerReplicationInfo->Team;
	for (i = 0; i < Team->Size; i++)
	{
		PRI = Team->TeamList[i];
		if ((PRI != PlayerReplicationInfo) && PRI->bCallForMedic)
		{
			return true;
		}
	}
	return false;
}

void AHumanController::CallMedic()
{
	/*
	if (Pawn != nullptr)
	{
		if (Pawn.IsWounded())
		{
			if (GetWorld()->GetTimeSeconds() > tMedicFlood || !PlayerReplicationInfo.bCallForMedic)
			{
				ServerCallMedic();
				CommoSend('CommoShout', 31);
				tMedicFlood = GetWorld()->GetTimeSeconds() + 5;
			}
			else
			{
				tMedicFlood += 0.2;
			}
		}
		else
		{
			if (PlayerReplicationInfo.bIsMedic && IsTeammateInjured())
			{
				if (GetWorld()->GetTimeSeconds() > tMedicFlood)
				{
					CommoSend('CommoShout', 29);
					tMedicFlood = GetWorld()->GetTimeSeconds() + 3;
				}
				else
				{
					tMedicFlood += 0.2;
				}
			}
		}
	}
	*/
}
void AHumanController::ServerCallMedic()
{
	/*
	if (Pawn != nullptr && Pawn.IsWounded())
	{
		PlayerReplicationInfo.bCallForMedic=true;
	}
	*/
}
void AHumanController::Say(FString Msg)
{
	FName CommoType = "";
	if (Msg == "")
	{
		return;
	}
	if (CheckRIFlood())
	{
		return;
	}
	/*
	if (Cast<AAGP_Pawn>(GetPawn()) == nullptr)
	{
		ServerSay(Msg,'Say');
		return;
	}
	switch(Cast<AAGP_Pawn>(GetPawn()).CommoState)
	{
		case 0:
		case 1:
		CommoType='Whisper';
		break;
		case 2:
		CommoType='shout';
		break;
		case 3:
		CommoType='Radio';
		break;
		case 4:
		CommoType='Squad';
		break;
		case 5:
		CommoType='Say';
		break;
		default:
	}
	ServerSay(Msg,CommoType);
	*/
}

void AHumanController::TeamSay(FString Msg)
{
	/*
	if (Msg == "")
	{
		return;
	}
	if (CheckRIFlood())
	{
		return;
	}
	ServerSay(Msg, 'TeamSay');
	*/
}

void AHumanController::DevSay(FString Msg)
{
	/*
		if (Msg == "")
		{
			return;
		}
		if (CheckRIFlood())
		{
			return;
		}
		ServerSay(Msg,'DevSay');
	*/
}

void AHumanController::CSay(FString sMsg)
{
	AController* C = nullptr;
	if (sMsg == "")
	{
		return;
	}
	/*
	if ((!PlayerReplicationInfo.bTournamentTeamCaptain) && (!PlayerReplicationInfo.bAdmin))
	{
		ClientMessage("Only Team Captain or Administrators can use Command Chat");
		return;
	}
	if (CheckRIFlood())
	{
		return;
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AHumanController::StaticClass()) && (Cast<APlayerController>(C).PlayerReplicationInfo.bTournamentTeamCaptain || PlayerController(C).PlayerReplicationInfo.bAdmin))
		{
			if (PlayerReplicationInfo.bAdmin)
			{
				Cast<AHumanController>(C).CSayNotify("[admin]" + PlayerReplicationInfo.PlayerName + " COMMAND MESSAGE: " + sMsg);
			}
			else
			{
				if ((PlayerReplicationInfo->Team->TeamIndex == 0) || (PlayerReplicationInfo->Team->TeamIndex == 1))
				{
					Cast<AHumanController>(C).CSayNotify("[" + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + "] " + PlayerReplicationInfo.PlayerName + " COMMAND MESSAGE: " + sMsg);
				}
			}
		}
	}
	*/
}

void AHumanController::CSayNotify(FString sMsg)
{
	FColor Color = FColor(0,0,0,0);
	Color.R=247;
	Color.G=151;
	Color.B=82;
	Color.A=0;
	//Player.Console.Message(sMsg,20,Color);
}

void AHumanController::PlayerList()
{
	int32 IDLen = 0;
	int32 maxIDLen = 0;
	int32 maxTeamLen = 0;
	FString teamstring = "";
	uint8 i = 0;
	AAGP_Scoreboard* SB = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	FString PlayerMessage = "";
	FColor Color = FColor(0,0,0,0);
	/*
	SB=AGP_Scoreboard(MyHUD.ScoreBoard);
	Color.R=255;
	Color.G=0;
	Color.B=255;
	Color.A=255;
	SB.UpdatePlayerList();
	maxIDLen=1;
	for (i=0; i<SB.PlayerCount; i++)
	{
		IDLen=Len(SB.GetOrdered(i).PlayerID);
		if (IDLen > maxIDLen)
		{
			maxIDLen=IDLen;
		}
	}
	if (bTournamentServer)
	{
		maxTeamLen=Max(Len(GameReplicationInfo.asTournamentTeamName[0]),Len(GameReplicationInfo.asTournamentTeamName[1]));
	}
	else
	{
		maxTeamLen=Max(Len(Level.TeamName[0]),Len(Level.TeamName[1]));
	}
	maxTeamLen=Max(maxTeamLen,Len("SPECTATOR"));
	Player.Console.Message("---------- PlayerList ----------",20,Color);
	for (i=0; i<SB.PlayerCount; i++)
	{
		PRI=SB.GetOrdered(i);
		if (PRI.bAdmin && PRI.SuperUser() || PRI.bAdmin && PRI.bOnlySpectator && ! TournamentIsTournament())
		{
		}
		PlayerMessage="" + PRI.PlayerID + ": ";
		PlayerMessage=AppendSpaces(PlayerMessage,maxIDLen - Len(PRI.PlayerID));
		switch(PRI.Team.TeamIndex)
		{
			case 0:
			if (bTournamentServer)
			{
				teamstring=GameReplicationInfo.asTournamentTeamName[0];
				break;
			}
			teamstring=Level.TeamName[0];
		}
		case 1:
		if (bTournamentServer)
		{
			teamstring=GameReplicationInfo.asTournamentTeamName[1];
		}
		else
		{
			teamstring=Level.TeamName[1];
		}
		case 255:
		teamstring="SPECTATOR";
		default:
		PlayerMessage=PlayerMessage + teamstring;
		PlayerMessage=AppendSpaces(PlayerMessage,maxTeamLen - Len(teamstring) + 1);
		PlayerMessage=PlayerMessage + PRI.GetHumanReadableName();
		Player.Console.Message(PlayerMessage,20,Color);
	}
	Player.Console.Message("--------------------------------------------",20,Color);
	*/
}
void AHumanController::ReasonList()
{
	int32 i = 0;
	FString Reason = "";
	FColor Color = FColor(0,0,0,0);
	Color.R = 255;
	Color.G = 0;
	Color.B = 255;
	Color.A = 255;
	i = 5;
	/*
	Player.Console.Message("----------------------------------------",20,Color);
	if (true)
	{
		Reason=GetReason(i);
		if (Reason == "")
		{
		}
		Player.Console.Message(i -- + " " + Reason,20,Color);
	}
	Player.Console.Message("---------- ReasonList ----------",20,Color);
	*/
}

FString AHumanController::GetReason(int32 i)
{
	/*
	switch(i)
	{
			case 1:
				return "Player is idle";
			case 2:
				return "Player is intentionally violating ROE";
			case 3:
				return "Player has used foul or abusive language";
			case 4:
				return "Player is spamming chat";
			case 5:
				return "Player is camping";
			default:
				return "";
	}
	*/
	return "";
}
FString AHumanController::AppendSpaces(FString append, int32 spaces)
{
	int32 i = 0;
	for (i = 0; i < spaces; i++)
	{
		append = append + " ";
	}
	return append;
}

FString AHumanController::MaybeGetPlayerNameFromID(FString PlayerName)
{
	int32 i = 0;
	int32 voteid = 0;
	AAGP_Scoreboard* SB = nullptr;
	FString newplayername = "";
	AAA2_PlayerState* PRI = nullptr;
	FString TempName = "";
	if (PlayerName == "")
	{
		return PlayerName;
	}
	/*
	voteid = int(PlayerName);
	SB = Cast<AAGP_Scoreboard>(MyHUD->ScoreBoard);
	SB->UpdatePlayerList();
	for (i = 0; i < SB->PlayerCount; i++)
	{
		PRI = SB->GetOrdered(i);
		TempName = PRI->GetHumanReadableName();
		if (PlayerName ~= TempName)
		{
			return PlayerName;
		}
		else
		{
			if (PRI->EquivalentName(PlayerName))
			{
				newplayername = TempName;
			}
		}
	}
	*/
	if (newplayername != "")
	{
		return newplayername;
	}
	else
	{
		return PlayerName;
	}
}

APlayerController* AHumanController::GetPlayerFromID(int32 iPlayerID)
{
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C->nextController)
	{
		PC = Cast<APlayerController>(C);
		if ((PC != nullptr) && (PC->PlayerReplicationInfo->PlayerID == iPlayerID))
		{
			return PC;
		}
	}
	*/
	PC = nullptr;
	return PC;
}
void AHumanController::DevKick(FString PlayerName)
{
	/*
	PlayerName = MaybeGetPlayerNameFromID(PlayerName);
	ServerDevKick(PlayerName);
	*/
}
void AHumanController::ServerDevKick(FString PlayerName)
{
	//Level.Game.CheckDevKick(this,PlayerName);
}
void AHumanController::SUToggle()
{
	//PlayerReplicationInfo.SUToggle();
}
void AHumanController::ParseNameAndReason(FString Input, FString& PlayerName, int32& iReason)
{
	/*
		int32 i = 0;
		FString sReason;
		i=InStr(Input," ");
		if (i == -1)
		{
			PlayerName=Input;
			iReason=0;
		}
		else
		{
			PlayerName=Left(Input,i);
			sReason=Mid(Input,i + 1);
			iReason=sReason;
		}
	*/
}
void AHumanController::votekick(FString Input)
{
	/*
		FString PlayerName;
		int32 iReason;
		ParseNameAndReason(Input,PlayerName,iReason);
		PlayerName=MaybeGetPlayerNameFromID(PlayerName);
		if (PlayerName != "" && GetReason(iReason) == "")
		{
			ClientShowVotekickInstructions();
			ClientMessage("You must give a reason.");
		}
		else
		{
			ServerVoteKick(PlayerName,iReason);
		}
	*/
}
void AHumanController::ClientShowVotekickInstructions()
{
	/*
	ReasonList();
	ClientMessage("Example: to kick Idle player 'Fred': 'votekick Fred 1'");
	ClientMessage("REASON_ID must be a number from the list below.");
	ClientMessage("Use PLAYERLIST to view a list of players and player numbers");
	ClientMessage("Use 'votekick [PLAYERNAME or NUMBER] REASON_ID'");
	*/
}
void AHumanController::ServerVoteKick(FString PlayerName, int32 iReason)
{
	/*
		if (PlayerName == "")
		{
			if (! Level.Game.ActiveVote())
			{
				ClientShowVotekickInstructions();
				return;
			}
			Level.Game.CastVote(PlayerReplicationInfo);
		}
		else
		{
			if (iReason == 5)
			{
				Level.Game.InitiateVoteRequest(PlayerReplicationInfo,PlayerReplicationInfo.PlayerName,"Player is complaining about campers");
			}
			else
			{
				Level.Game.InitiateVoteRequest(PlayerReplicationInfo,PlayerName,GetReason(iReason));
			}
		}
	*/
}
void AHumanController::ServerSay(FString Msg, FName Type)
{
	Msg=StripColorCodes(Msg);
	PlayerReplicationInfo->BlinkCharacterOnRadar(2);
	//Level.Game.Broadcast(this,Msg,Type);
}
FString AHumanController::StripBadCodes(FString InString)
{
	InString = InString.Replace(TEXT("£"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("µ"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("¨"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("`"), TEXT(""), ESearchCase::IgnoreCase);
	InString = InString.Replace(TEXT("§"), TEXT(""), ESearchCase::IgnoreCase);
	return InString;
}
FString AHumanController::StripColorCodes(FString InString)
{
	int32 p;
	InString.FindChar(TCHAR(27), p);
	while (p >= 0)
	{
		InString.RemoveAt(p, 4);
		InString.FindChar(TCHAR(27), p);
	}
	return InString;
}
bool AHumanController::GetLanguageFilter()
{
	return true;
}

FString AHumanController::FilterLanguage(FString S)
{
	return S;
}
FString AHumanController::FilterAlways(FString S)
{
	return S;
}
FString AHumanController::ApplyFilters(FString S)
{
	if (GetLanguageFilter())
	{
		S=FilterLanguage(S);
	}
	S=FilterAlways(S);
	return S;
}

FString AHumanController::SubstituteKeyNames(FString S)
{
	int32 Position = 0;
	int32 StrLen = 0;
	int32 Count = 0;
	FString tmp = "";
	FString tcmd = "";
	FString retval = "";
	FString cmdin = "";
	FString cmdout = "";
	EInputKey cmdkey = EInputKey::IK_None;
	retval = "";
	Position = 0;
	StrLen = S.Len();
	if (Position < StrLen)
	{
		/*
		tmp = Mid(S, Position, 1);
		retval = retval + tmp;
		if (tmp == "<")
		{
			cmdin = "";
			for (Position++; Position < StrLen; Position++)
			{
				tcmd = Mid(S, Position, 1);
				if ((tcmd == ">") || (tcmd == " "))
				{
				}
				else
				{
					cmdin = cmdin + tcmd;
				}
			}
			if ((tcmd == ">") && Player.Console.IsValidCommand(cmdin))
			{
				Count = 0;
				if (Player.Console.GetCommandKey(cmdin, cmdkey, cmdout, Count))
				{
					if (Count > 0)
					{
						retval = retval + " or ";
					}
					retval = retval + Caps(cmdout);
					Count++;
				}
				if (Count == 0)
				{
					retval = retval + "no key bound: " + Caps(cmdin);
				}
				retval = retval + ">";
			}
			else
			{
				retval = retval + cmdin;
				if ((tcmd == ">") || (tcmd == " "))
				{
					retval = retval + tcmd;
				}
			}
		}
		Position++;
		*/
	}
	return retval;
}

void AHumanController::old_SelectTeam()
{
	if (! bPBChecked)
	{
		return;
	}
	if (GetNetMode() == ENetMode::NM_Client)
	{
		if (Cast<AAGP_HUD>(MyHUD) != NULL)
		{
			Cast<AAGP_HUD>(MyHUD)->ToggleTeamSelect();
		}
	}
}
void AHumanController::old_ClientTeamSelectMenu(bool bOpen)
{
	/*
		if (! bPBChecked)
		{
			return;
		}
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			return;
		}
		if (PlayerReplicationInfo.bAdmin)
		{
			return;
		}
		if (bOpen)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->OpenTeamSelect();
			}
		}
		else
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->CloseGameMenu();
			}
		}
	*/
}
void AHumanController::ClientTeamSelectMenu(bool bOpen)
{
	/*
		if (Role == 4 || PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.bOnlySpectator)
		{
			return;
		}
		if (! bPBChecked)
		{
			return;
		}
		if (bOpen)
		{
			SelectTeam("Recreate");
		}
	*/
}
void AHumanController::SelectTeam(FString Param2)
{
	
		if (! bPBChecked)
		{
			return;
		}
		if (bTournamentServer)
		{
			/*
			if (! PlayerReplicationInfo.bAdmin)
			{
				ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
			}
			else
			{
				ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Tournament",Param2);
			}
			*/
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	
}
void AHumanController::OLD_SelectClass()
{
	/*
		if (! bPBChecked)
		{
			return;
		}
		if (GetNetMode() == ENetMode::NM_Client)
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->ToggleClassSelect();
			}
		}
	*/
}
void AHumanController::SelectClass(FString Param2)
{
	
	if (! bPBChecked)
	{
		return;
	}
	if (TournamentIsTournament())
	{
		if (CanShowRoster())
		{
			ClientCloseMenu(false,false);
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Roster",Param2);
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	}
	else
	{
		if (CanShowWeaponClass())
		{
			ClientCloseMenu(false,false);
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Weapon Class",Param2);
		}
		else
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team",Param2);
		}
	}
	
}
bool AHumanController::CanShowRoster()
{
	//return PlayerReplicationInfo.bAdmin || PlayerReplicationInfo.bTournamentTeamCaptain || PlayerReplicationInfo->Team->TeamIndex != 255 || PlayerReplicationInfo.DesiredTeam != 255;
	return true;    //FAKE   /ELiZ
}
bool AHumanController::CanShowWeaponClass()
{
	//return PlayerReplicationInfo != nullptr && PlayerReplicationInfo.Team != nullptr && PlayerReplicationInfo->Team->TeamIndex != 255 || PlayerReplicationInfo.DesiredTeam != 255 && GameReplicationInfo.Teams[PlayerReplicationInfo.DesiredTeam].Size < GameReplicationInfo.Teams[PlayerReplicationInfo.DesiredTeam].MaxSize;
	return true;    //FAKE   /ELiZ
}
void AHumanController::ShowScores(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (Cast<AAA2_GameState>(GetWorld()->GetGameState())->bShouldShowScoreboard || PlayerReplicationInfo->bAdmin || PlayerReplicationInfo->IsOnlyASpectator())
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Score","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
	else
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Team","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
}
void AHumanController::ShowMap(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Map","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
void AHumanController::ShowObjectives(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Map","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
void AHumanController::ShowServerInfo(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (bAllowScoreShown)
	{
		if (bTournamentServer)
		{
			if (ClientOpenMenu("AGP_Interface.AAGameMenu",false,"Tournament","") == false)
			{
				ClientCloseMenu(false,false);
			}
		}
		else
		{
			if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Server Info","") == false)
			{
				ClientCloseMenu(false,false);
			}
		}
	}
}
void AHumanController::ShowTournament(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (bTournamentServer)
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Tournament","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
	else
	{
		if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Server Info","") == false)
		{
			ClientCloseMenu(false,false);
		}
	}
}
void AHumanController::ShowSurvey(FString Param2)
{
	if (! bPBChecked)
	{
		return;
	}
	if (ClientOpenMenu("AGP_Interface.AAGameMenu", false,"Survey","") == false)
	{
		ClientCloseMenu(false,false);
	}
}
bool AHumanController::CanShowScores()
{
	return true;
}

bool AHumanController::CanSelectTeam()
{
	return !PlayerReplicationInfo->bAdmin;
}

bool AHumanController::CanSelectClass()
{
	return ! TournamentIsTournament() || TournamentIsTournament() && ! TournamentIsTeamRosterLocked(PlayerReplicationInfo->Team->TeamIndex) || PlayerReplicationInfo->bAdmin;
}
bool AHumanController::CanShowServerInfo()
{
	return true;
}
void AHumanController::ShowMenu()
{
	ClientCloseMenu(true,false);
	ClientOpenMenu("AGP_Interface.AAMainMenu",false,"","");
}
void AHumanController::RequestMedic(bool bMedic)
{
	if (GetNetMode()  == ENetMode::NM_Client)
	{
		
		if (PlayerReplicationInfo->bQualifiedMedic)
		{
			PlayerReplicationInfo->bWantsMedic=bMedic;
		}
		ServerRequestMedic(bMedic);
	}
}
void AHumanController::ServerRequestMedic(bool bMedic)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (PlayerReplicationInfo->bQualifiedMedic)
		{
			PlayerReplicationInfo->bWantsMedic=bMedic;
		}
		else
		{
			PlayerReplicationInfo->bWantsMedic=false;
		}
		ClientNotifyMedic(PlayerReplicationInfo->bWantsMedic);
		PlayerReplicationInfo->Team->TestMedics();
	}
}

void AHumanController::ClientNotifyMedic(bool bMedic)
{
	PlayerReplicationInfo->bWantsMedic=bMedic;
}

void AHumanController::SetPreferredClass(int32 i, bool bAvoidLeader, bool bMedic, int32 prev_i, bool prev_b)
{
	ATeamInfo* Team = nullptr;
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Team=PlayerReplicationInfo.Team;
		if (i != prev_i)
		{
			Team.NumDesired[i] ++;
			if (prev_i != -1)
			{
				Team.NumDesired[prev_i] --;
			}
		}
		if (bAvoidLeader != prev_b)
		{
			if (bAvoidLeader)
			{
				Team.NumLeadersDesired ++;
			}
			else
			{
				Team.NumLeadersDesired --;
			}
		}
		ServerSetDesiredTeamClass(i,bAvoidLeader,bMedic);
	}
	*/
}

void AHumanController::ClientForceNewClass(FString ClassName)
{
		//ASoldierClass* sclass;
		//FString sclass_name;
		
		if (GetPawn() == NULL)
		{
			return;
		}
		//LockPlayer(false,false);
		
		/*
		switch(ClassName)
		{
			case "":
			ScreenPrint("Type ""Class X"" where classes are R, AR, G, S, RCT, AK, FT, SL, S24, F, AK74SU, M4A1, SVD, GP, RPK");
			return;
			case "M":
			case "M4A1":
			sclass_name="AGP_Characters.ClassRiflemanM4A1AutoIron";
			break;
			case "M4A1Auto":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Auto";
			break;
			case "AK74SU":
			sclass_name="AGP_Characters.ClassRiflemanAK74SU";
			break;
			case "AR":
			case "AutomaticRifleman":
			sclass_name="AGP_Characters.ClassAutomaticRifleman";
			break;
			case "R":
			case "Rifleman":
			sclass_name="AGP_Characters.ClassRifleman";
			break;
			case "RCT":
			case "Recruit":
			sclass_name="AGP_Characters.ClassRecruit";
			break;
			case "AK":
			case "RiflemanAK":
			sclass_name="AGP_Characters.ClassRiflemanAK";
			break;
			case "G":
			case "Grenadier":
			sclass_name="AGP_Characters.ClassGrenadier";
			break;
			case "S":
			case "Sniper":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniper";
			}
			GOTO JL0609;
			case "S24":
			case "Sniper24":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniper24_US";
			}
			GOTO JL0609;
			case "SVD":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniperSVD";
			}
			GOTO JL0609;
			case "GP":
			sclass_name="AGP_Characters.ClassGrenadierGP30_Op";
			GOTO JL0609;
			case "RPK":
			sclass_name="AGP_Characters.ClassAutomaticRiflemanRPK";
			GOTO JL0609;
			case "Mos":
			if (GetNoSniper() || ! PlayerReplicationInfo.bQualifiedSniper)
			{
				sclass_name="AGP_Characters.ClassRifleman";
			}
			else
			{
				sclass_name="AGP_Characters.ClassSniperMos";
			}
			GOTO JL0609;
			case "M4M":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Mod";
			GOTO JL0609;
			case "J":
			if (! PlayerReplicationInfo.bQualifiedJavelin)
			{
				sclass_name="AGP_Characters.ClassJavelinTube";
			}
			else
			{
				sclass_name="AGP_Characters.ClassJavelin";
			}
			default:
			ScreenPrint("Unrecognized class " + ClassName);
			ScreenPrint("Type ""Class X"" where classes are R, AR, G, S, RCT, AK, FT, SL, S24, F, AK74SU, M4A1, SVD, GP, RPK");
			return;
JL0609:
		}
		CleanUp();
		if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
		{
			Cast<AAGP_Pawn>(GetPawn()).bForcedWeaponChange=true;
		}
		sclass=class<SoldierClass>(DynamicLoadObject(sclass_name,Class'Class'));
		newTeamClass(sclass);
	*/
}
bool AHumanController::QualifiedFor(AActor*  Desired)
{
	/*
		ASoldierClass* sclass;
		if (Desired == NULL)
		{
			return true;
		}
		sclass=Cast<ASoldierClass>(Desired);
		if (sclass == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("HumanController::QualifiedFor() Unknown class " + Desired));
			return false;
		}
		if (sclass.Default.nativeWeapon == 4)
		{
			if (bNoSniper)
			{
				return false;
			}
			UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo.bQualifiedSniper:" @ PlayerReplicationInfo.bQualifiedSniper));
			return PlayerReplicationInfo.bQualifiedSniper;
		}
		if (sclass.Default.nativeWeapon == 8)
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerReplicationInfo.bQualifiedJavelin:" @ PlayerReplicationInfo.bQualifiedJavelin));
			return PlayerReplicationInfo.bQualifiedJavelin;
		}
		return true;
	*/
	return true;			//Fake ELiZ
}

ASoldierClass* AHumanController::GetDesiredTeamClass()
{
	if (QualifiedFor(DesiredTeamClass))
	{
		return DesiredTeamClass;
	}
	else
	{
		return nullptr;
	}
}

void AHumanController::ServerSetDesiredTeamClass(int32 i, bool bAvoidLeader, bool bMedic)
{
	ATeamInfo* MyTeam = nullptr;
	/*
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this,"CHEATER");
		return;
	}
	MyTeam=PlayerReplicationInfo.Team;
	if (MyTeam.IsClassAvailable(i))
	{
		PlayerReplicationInfo.bWantsMedic=bMedic;
		PlayerReplicationInfo.bAvoidLeaderRole=bAvoidLeader;
		PlayerReplicationInfo.bWantsSquadLeader=MyTeam.IsSquadLeader(i);
		PlayerReplicationInfo.bWantsFTLeader=MyTeam.IsFTLeader(i);
		DesiredTeamClass=class<SoldierClass>(MyTeam.GetClass(i));
		if (! QualifiedFor(DesiredTeamClass))
		{
			DesiredTeamClass=nullptr;
		}
		MyTeam.CountDesiredPlayerStarts();
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetDesiredTeamClass()	" + DesiredTeamClass));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerSetDesiredTeamClass()	Tried to set unavailable class " + this @ i));
	}
	*/
}

void AHumanController::ServerEnablePlayer()
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		PlayerReplicationInfo.bReadyToPlay=true;
	}
	*/
}

void AHumanController::NotifyPendingTeamChange(uint8 NewTeam, bool bForceNotify)
{
	FString TeamName = "";
	FString TeamChangeText = "";
	FString ExtraText = "";
	/*
	if (PlayerReplicationInfo->Team->TeamIndex == NewTeam)
	{
		TeamChangeText="Remaining on";
		if (NewTeam == 255)
		{
			TeamName="Spectator";
		}
		else
		{
			if (TournamentIsTournament())
			{
				if (GameReplicationInfo.asTournamentTeamName[NewTeam] != "")
				{
					TeamName=GameReplicationInfo.asTournamentTeamName[NewTeam];
				}
				else
				{
					TeamName=Level.TeamName[NewTeam];
				}
			}
			else
			{
				TeamName=Level.TeamName[NewTeam];
			}
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,TeamChangeText @ TeamName @ ExtraText);
		}
	}
	else
	{
		if (NewTeam == 255)
		{
			TeamName="Spectator";
		}
		else
		{
			if (TournamentIsTournament())
			{
				TeamChangeText="Joining";
				if (GameReplicationInfo.asTournamentTeamName[NewTeam] != "")
				{
					TeamName=GameReplicationInfo.asTournamentTeamName[NewTeam];
				}
				else
				{
					TeamName=Level.TeamName[NewTeam];
				}
			}
			else
			{
				TeamChangeText="Changing to";
				ExtraText="next round ";
				TeamName=Level.TeamName[NewTeam];
			}
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(4,TeamChangeText @ TeamName @ ExtraText);
		}
	}
	PlayerReplicationInfo.DesiredTeam=NewTeam;
	*/
}

void AHumanController::NotifyPBAuthMessage(FString Msg)
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(8, Msg, nullptr);
	}
}
void AHumanController::ClientNotifyAdminMessage(FString sMsg)
{
	NotifyAdminMessage(sMsg);
}
void AHumanController::ToggleNotificationMessages()
{
	if(Cast<AAGP_HUD>(MyHUD) !=nullptr)
	{
	Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages=!Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages;
		if (Cast<AAGP_HUD>(MyHUD)->bDisableNotificationMessages)
		{
			ClientMessage("Centered notification messages disabled.");
		}
		else
		{
			ClientMessage("Centered notification messages enabled");
		}
	}
}
void AHumanController::NotifyAdminMessage(FString Msg)
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessageLong(4,Msg,nullptr);
	}
}

void AHumanController::LoadJacket()
{
	FString sFile = "";
	FString sTemp = "";
	FString sMissions = "";
	FString Line = "";
	TArray<FString> asJacketParts = {};
	FString sVersion = "";
	int32 iJacketRifleRangeCheck = 0;
	int32 iJacketHonorCheck = 0;
	int32 iJacketChecksum = 0;
	int32 iJacketSecondaryChecksum = 0;
	int32 iField = 0;
	int32 i = 0;
	int32 iChar = 0;
	int32 iCalculatedChecksum = 0;
	/*
	UE_LOG(LogTemp, Warning, TEXT("Loading Jacket..."));
	sTemp=GetBaseDir();
	sFile=sFile + "save\" + UserName + ".dat";
	UE_LOG(LogTemp, Warning, TEXT("Loading Profile Jacket file: " + sFile));
	for (i=0; i<33; i++)
	{
		iCompleted[i]=0;
	}
	if (! FOpen(sFile))
	{
		Log("Failed opening user profile file: " + sFile);
		return;
	}
	FReadLine(Line);
	FClose();
	Split(Line,",",asJacketParts);
	sVersion=asJacketParts[0];
	if (sVersion != "240")
	{
		Log("Invalid version for user personnel jacket file.");
		return;
	}
	iJacketRifleRangeCheck=asJacketParts[1];
	iJacketHonorCheck=asJacketParts[2];
	iJacketChecksum=asJacketParts[3];
	sMissions="";
	for (iField=4; iField<38; iField++)
	{
		sMissions=sMissions + asJacketParts[iField] + ",";
	}
	sMissions=sMissions + asJacketParts[iField] + ",";
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo._iTrust=asJacketParts[iField ++];
	}
	else
	{
		iField ++;
	}
	sMissions=sMissions + asJacketParts[iField ++] + ",";
	if (PlayerReplicationInfo != nullptr)
	{
		sMissions=sMissions + asJacketParts[iField] + ",";
		PlayerReplicationInfo._Experience=asJacketParts[iField ++];
		sMissions=sMissions + asJacketParts[iField] + ",";
		PlayerReplicationInfo._Group=asJacketParts[iField ++];
	}
	else
	{
		sMissions=sMissions + asJacketParts[iField ++] + ",";
		sMissions=sMissions + asJacketParts[iField ++] + ",";
	}
	sMissions=sMissions + asJacketParts[iField] + ",";
	iUID=asJacketParts[iField ++];
	iJacketSecondaryChecksum=65535 - asJacketParts[iField];
	iCalculatedChecksum=0;
	for (iChar=0; iChar<Len(sMissions); iChar++)
	{
		iCalculatedChecksum += Asc(Mid(sMissions,iChar,1));
	}
	ParseMissionString(sMissions);
	if (iCalculatedChecksum != iJacketChecksum || iJacketSecondaryChecksum != iJacketChecksum || 755555 - iJacketRifleRangeCheck != iRifleRangeRating || PlayerReplicationInfo != nullptr && 755555 - iJacketHonorCheck != PlayerReplicationInfo.GetHonor())
	{
		Log("Invalid personnel jacket file");
		for (i=0; i<33; i++)
		{
			iCompleted[i]=0;
		}
		iRifleRangeRating=0;
		if (PlayerReplicationInfo != nullptr)
		{
			PlayerReplicationInfo._Experience=0;
			PlayerReplicationInfo._iTrust=0;
		}
		return;
	}
	UpdateAuthRelatedPRI();
	*/
}

void AHumanController::SaveJacket()
{
	FString sFile = "";
	FString sTemp = "";
	FString sMissions = "";
	int32 iChecksum = 0;
	int32 iChar = 0;
	/*
	if (PlayerReplicationInfo == nullptr || iRifleRangeRating == 0 && PlayerReplicationInfo._Experience != 0 || PlayerReplicationInfo.GetHonor() != 0)
	{
		Log("Invalid values, cannot save Player Jacket");
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Saving Jacket..."));
	sTemp=GetBaseDir();
	sFile=sFile + "save\" + UserName + ".dat";
	if (! FOpenWrite(sFile))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed opening for write " + sFile));
		return;
	}
	FWrite("240,");
	FWrite("" + 755555 - iRifleRangeRating + ",");
	FWrite("" + 755555 - PlayerReplicationInfo.GetHonor() + ",");
	sMissions=GenerateMissionString();
	for (iChar=0; iChar<Len(sMissions); iChar++)
	{
		iChecksum += Asc(Mid(sMissions,iChar,1));
	}
	FWrite("" + iChecksum + ",");
	FWrite(sMissions);
	FWrite("" + 65535 - iChecksum);
	FClose();
	*/
}

void AHumanController::VerifyJacket()
{
	int32 iCurTour = 0;
	int32 iCurMission = 0;
	int32 iNumTours = 0;
	int32 iNumMissions = 0;
	int32 iDependency = 0;
	bool bTourComplete = false;
	bool bMissionsComplete = false;
	bool bSequential = false;
	bool bClearMissions = false;
	int32 iTempMissions = 0;
	/*
	UE_LOG(LogTemp, Warning, TEXT("Verifying Jacket..."));
	iNumTours=Level.iNumTours;
	for (iCurTour=0; iCurTour<iNumTours; iCurTour++)
	{
		iTempMissions=0;
		iNumMissions=Level.GetTourMissions(iCurTour);
		iDependency=Level.GetTourDependency(iCurTour);
		bSequential=Level.GetTourIsSequential(iCurTour);
		if (2 ** iCurTour & iCompleted[0] > 0)
		{
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("Tour" @ iCurTour @ "is flagged as completed"));
			}
			if (iDependency != -1)
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("we have a dependency:" @ iDependency));
				}
				if (2 ** iDependency & iCompleted[0] == 0)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("dependency not met, clearing"));
					}
					iCompleted[0] -= 2 ** iCurTour;
					iCompleted[iCurTour + 1]=0;
				}
			}
			bMissionsComplete=true;
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("checking missions"));
			}
			for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
			{
				iTempMissions += 2 ** iCurMission;
				if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("missions not complete"));
					}
					bMissionsComplete=false;
				}
			}
			if (! bMissionsComplete)
			{
				if (2 ** iCurTour & iCompleted[0] > 0)
				{
					iCompleted[0] -= 2 ** iCurTour;
				}
			}
			else
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("turning off extra bits iTempMissions is" @ iTempMissions));
				}
				if (iCompleted[iCurTour + 1] != iTempMissions)
				{
					iCompleted[iCurTour + 1]=iTempMissions;
				}
			}
		}
		else
		{
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("Tour" @ iCurTour @ "is NOT flagged as completed"));
			}
			if (iDependency != -1)
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("we have a dependency:" @ iDependency));
				}
				if (2 ** iDependency & iCompleted[0] == 0)
				{
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("dependency not met, clearing"));
					}
					iCompleted[iCurTour + 1]=0;
				}
			}
			bTourComplete=true;
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("checking missions"));
			}
			for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
			{
				if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
				{
					bTourComplete=false;
				}
				else
				{
					iTempMissions += 2 ** iCurMission;
				}
			}
			if (bTourComplete == true)
			{
				if (Level.debugAuth)
				{
					UE_LOG(LogTemp, Warning, TEXT("tour complete"));
				}
				if (2 ** iCurTour & iCompleted[0] == 0)
				{
					iCompleted[0] += 2 ** iCurTour;
				}
			}
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("turning off extra bits iTempMissions is" @ iTempMissions));
			}
			if (iCompleted[iCurTour + 1] != iTempMissions)
			{
				iCompleted[iCurTour + 1]=iTempMissions;
			}
		}
		if (bSequential)
		{
			if (Level.debugAuth)
			{
				UE_LOG(LogTemp, Warning, TEXT("this tour is sequential"));
			}
			bClearMissions=false;
			for (iCurMission=0; iCurMission<iNumMissions; iCurMission++)
			{
				if (bClearMissions)
				{
					if (2 ** iCurMission & iCompleted[iCurTour + 1] > 0)
					{
						if (Level.debugAuth)
						{
							UE_LOG(LogTemp, Warning, TEXT("clearing mission" @ iCurMission));
						}
						iCompleted[iCurTour + 1] -= 2 ** iCurMission;
					}
				}
				if (2 ** iCurMission & iCompleted[iCurTour + 1] == 0)
				{
					bClearMissions=true;
					if (Level.debugAuth)
					{
						UE_LOG(LogTemp, Warning, TEXT("clear out rest of missions - iCurMission is" @ iCurMission));
					}
				}
			}
		}
	}
	if (iRifleRangeRating < 36)
	{
		if (iCompleted[0] & 16 == 1)
		{
			iCompleted[0] -= 16;
			iCompleted[5]=0;
		}
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		Level.UpdateAllMissionsStatus(this);
	}
	*/
}

void AHumanController::LimitPawnRotation(bool bLimit, FRotator rRotator)
{
	if (Cast<AAGP_Pawn>(GetPawn()) != NULL)
	{
		Cast<AAGP_Pawn>(GetPawn())->rBaseRotation = Cast<AAGP_Pawn>(GetPawn())->GetViewRotation();
		Cast<AAGP_Pawn>(GetPawn())->rRotationLimits = rRotator;
		Cast<AAGP_Pawn>(GetPawn())->LimitRotation(bLimit);
	}
}
void AHumanController::bind(FString Command)
{
	//PrivateSet("input " + Command);
}
void AHumanController::QueryServerList()
{
}
void AHumanController::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
}
FString AHumanController::GetServerSection(int32 Index)
{
	return "";
}
void AHumanController::SetServerSetting(int32 Index, FString Value)
{
}
void AHumanController::SetServerSettingReply(int32 Index, FString Value)
{
}
void AHumanController::KickPlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " + PlayerReplicationInfo.PlayerName + " is not an admin!"));
		return;
	}
	//ConsoleCommand("kick" @ PlayerName);
}
void AHumanController::BanPlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " + PlayerReplicationInfo.PlayerName + " is not an admin!"));
		return;
	}
//ConsoleCommand("kickban" @ PlayerName);
}
void AHumanController::MutePlayer(FString PlayerName)
{
	if (PlayerReplicationInfo == nullptr || ! PlayerReplicationInfo->bAdmin)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player " + PlayerReplicationInfo.PlayerName + " is not an admin!"));
		return;
	}
	//ConsoleCommand("mute" @ PlayerName);
}

int32 AHumanController::GetServerSettingsCount()
{
	return 0;
}

FString AHumanController::GetServerKey(int32 Index)
{
	return "";
}
void AHumanController::SetServerKey(int32 Index, FString Key)
{
}
FString AHumanController::GetServerKeyValue(int32 Index)
{
	return "";
}
void AHumanController::SetServerKeyValue(int32 Index, FString Value)
{
}
void AHumanController::RefreshServerInfo(bool bInitialize)
{
}
void AHumanController::LoadPSettings()
{
	/*
		FString sFile;
		FString sTemp;
		FString sString;
		FString sKey;
		FString Line;
		sKey="p";
		sTemp=GetBaseDir();
		sFile=sFile + "pc.dat";
		sKey=sKey + "4";
		if (! FOpen(sFile))
		{
			return;
		}
		sKey=sKey + "r3";
		FReadLine(Line);
		sKey=sKey + "n7";
		sString=Extract(Line,sKey);
		ParsePC(sString);
		FClose();
	*/
}
void AHumanController::SavePSettings()
{
	/*
		FString sFile;
		FString sTemp;
		FString sMissions;
		FString sKey;
		int32 sValue;
		sKey="p";
		sTemp=GetBaseDir();
		sKey=sKey + "4";
		sFile=sFile + "pc.dat";
		sKey=sKey + "r3";
		if (! FOpenWrite(sFile))
		{
			return;
		}
		sValue=GetLanguageFilter() + GetNoBlood() * 2 + GetMilesOnly() * 4 + GetNoSniper() * 8;
		sMissions=sValue + "," + ParentPassword + ",";
		sKey=sKey + "n7";
		sMissions=Compress(sMissions,sKey);
		FWriteLine(sMissions);
		FClose();
	*/
}
void AHumanController::ParsePC(FString sString)
{
		int32 iCounter;
		int32 iPos = 0;
		FString sTemp;
		FString string0;
		FString string1;
		bool bDone = false;
		int32 iValue = 0;
		FString sChar;
		
		sTemp=sString;
		iCounter=0;
		sChar=",";
		//iPos=InStr(sTemp,sChar);
		
		if (iPos == -1)
		{
			bDone=true;
			if (sTemp != "")
			{
				//iValue=sTemp;
			}
		}
		else
		{
			//string0=Left(sTemp,iPos);
			//string1=Right(sTemp,Len(sTemp) - iPos - 1);
			//if (string0 != "")
			//{
			//	iValue=string0;
			//}
		}
		if (iCounter == 0)
		{
			if ((iValue & 1) == 1)
			{
				//SetLanguageFilter(true);
			}
			else
			{
				//SetLanguageFilter(false);
			}
			if ((iValue & 2) == 2)
			{
				//SetNoBlood(true);
			}
			else
			{
				//SetNoBlood(false);
			}
			if ((iValue & 4) == 4)
			{
				//SetMilesOnly(true);
			}
			else
			{
				//SetMilesOnly(false);
			}
			if ((iValue & 8) == 8)
			{
				//SetNoSniper(true);
			}
			else
			{
				//SetNoSniper(false);
			}
		}
		if (iCounter == 1)
		{
			ParentPassword=string0;
		}
		sTemp=string1;
		iCounter ++;
		//if (bDone)
		//{
		//}

}
void AHumanController::ClientSetPMessage(int32 messID)
{
	if (messID > 0)
	{
		//PrivateSet("LevelInfo PMessage " + messID);
		if(Cast<AAGP_HUD>(MyHUD) !=nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->PMessage=messID;
		}
	}
}
void AHumanController::ServerSetPC(bool bNS)
{
	bNoSniper = bNS;
}
void AHumanController::LoadServerCommands(FString Filename)
{
	/*
		FString sFile;
		FString sDir;
		FString sCommands;
		FString Line;
		sDir=GetBaseDir();
		if (Filename ~= "")
		{
			sFile=sFile + "RunServer.bat";
		}
		else
		{
			sFile=sFile + Filename;
		}
		if (! FOpen(sFile))
		{
			return;
		}
		FReadLine(Line);
		sCommands=Line;
		ParseServerCommands(sCommands);
		FClose();
	*/
}
void AHumanController::SaveServerCommands(FString Filename)
{
	/*
		FString ServerExecutable;
		FString ServerType;
		FString MapName;
		FString LogFile;
		FString INIfile;
		FString sFile;
		FString sDir;
		FString sCommands;
		sDir=GetBaseDir();
		if (Filename ~= "")
		{
			sFile=sFile + "RunServer.bat";
		}
		else
		{
			sFile=sFile + Filename;
		}
		if (! FOpenWrite(sFile))
		{
			return;
		}
		sCommands=ServerExecutable @ ServerType @ MapName @ "log=" + LogFile @ "ini=" + INIfile;
		FWriteLine(sCommands);
		FClose();
	*/
}
void AHumanController::ParseServerCommands(FString sString)
{
	FString ServerExecutable = "";
	FString ServerType = "";
	FString MapName = "";
	FString LogFile = "";
	FString INIfile = "";
	int32 iCounter = 0;
	int32 iPos = 0;
	FString sTemp = "";
	FString string0 = "";
	FString string1 = "";
	bool bDone = false;
	int32 iValue = 0;
	FString sChar = "";
	sTemp = sString;
	iCounter = 0;
	sChar = " ";
	/*
	do
	{
		iPos = InStr(sTemp, sChar);
		if (iPos == -1)
		{
			bDone = true;
			if (sTemp != "")
			{
				iValue = int(sTemp);
			}
		}
		else
		{
			string0 = Left(sTemp, iPos);
			string1 = Right(sTemp, ((Len(sTemp) - iPos) - 1));
			if (string0 != "")
			{
				iValue = int(string0);
			}
		}
		if (iCounter == 0)
		{
			ServerExecutable = string1;
		}
		if (iCounter == 1)
		{
			ServerType = string1;
		}
		if (iCounter == 2)
		{
			MapName = string1;
		}
		if (iCounter == 3)
		{
			LogFile = string1;
		}
		if (iCounter == 4)
		{
			INIfile = string1;
		}
		sTemp = string1;
		iCounter++;
	}
	until(bDone);
	*/
}

void AHumanController::ServerSetAutoSwapFromGrenade(bool bstatus)
{
	bAutoSwapFromGrenade = bstatus;
}
void AHumanController::ServerSetAutoWalkZoom(bool bstatus)
{
	bAutoWalkZoom = bstatus;
}
void AHumanController::SetTurret(AActor* A)
{
	Turret = Cast<AFixedWeaponAttachment>(A);
	ClientSetTurret(A);
}
void AHumanController::ClientSetTurret(AActor* A)
{
	Turret = Cast<AFixedWeaponAttachment>(A);
}
void AHumanController::SetCamera(AActor* C, UTexture2D* Overlay)
{
	RemoteCamera=C;
	ClientSetCamera(C,Overlay);
}
void AHumanController::ClientSetCamera(AActor* C, UTexture2D* Overlay)
{
	RemoteCamera=C;
	SetCamOverlay(Overlay);
}
void AHumanController::SetCamOverlay(UTexture2D* Overlay)
{
	HUDCamOverlay = Overlay;
}
void AHumanController::ServerAbortViewCam()
{
}
void AHumanController::DisplayLevelLoading()
{
	UE_LOG(LogTemp, Warning, TEXT("HC::DisplayLevelLoading() called"));
	/*
		ClientOpenMenu("AGP_Interface.AAServerLoading",,"","");
		LockPlayer(true,true);

	*/
}

void AHumanController::ClientTriggerCommandPost()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ShowAdminCommandPost();
	}
}

void AHumanController::AdminForceClassAllPlayers(FString WhichClass)
{
	AController* ctrlIterator = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		ClientMessage("Force-classing players on a coop server disables scoring for the round.");
		GameReplicationInfo.bTempDisableRoundScoring=true;
	}
	if (! GameReplicationInfo.bAllowForceclassing)
	{
		ClientMessage("doing this will reduce honor scoring to 75% of normal.");
		ClientMessage("in order to perform a global force class.  Note that on official ");
		ClientMessage("You must enable global forceclassing using ""admin ToggleForceclass""");
		return;
	}
	ctrlIterator=Level.ControllerList;
	if (ctrlIterator != nullptr)
	{
		if (ctrlIterator->IsA(AHumanController::StaticClass()))
		{
			if (! AdminForceClass(Cast<AHumanController>(ctrlIterator).PlayerReplicationInfo.PlayerName,WhichClass))
			{
			}
		}
		else
		{
			ctrlIterator=ctrlIterator.nextController;
		}
	}
	*/
}

bool AHumanController::AdminForceClass(FString Who, FString WhichClass)
{
	APlayerController* PCToChangeClassOf = nullptr;
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	AHumanController* HC = nullptr;
	FString str = "";
	FString sclass_name = "";
	ASoldierClass* sclass = nullptr;
	/*
	DebugLog(DEBUG_Multi, FString::FromInt(this) @ "HumanController::AdminForceClass Attempting to force the class of " + Who + " to " + WhichClass);
	C = Level.ControllerList;
	if (C != nullptr)
	{
		PC = Cast<APlayerController>(C);
		if ((PC != nullptr) && (PC.PlayerReplicationInfo.PlayerName ~= Who))
		{
			PCToChangeClassOf = PC;
			DebugLog(DEBUG_Multi, FString::FromInt(this) @ "HumanController::AdminForceclass Attempting to change class of " + PC.PlayerReplicationInfo.PlayerName);
		}
		else
		{
			C = C.nextController;
		}
	}
	if (Cast<AHumanController>(PCToChangeClassOf)._FlashSoundTime > 0)
	{
		ClientMessage("Player " + Who + " cannot be forceclassed while flashbanged.");
		return true;
	}
	if ((PCToChangeClassOf != nullptr) && (PCToChangeClassOf.Pawn != nullptr))
	{
		HC = Cast<AHumanController>(PCToChangeClassOf);
		if (HC == nullptr)
		{
			ClientMessage("Error: admin forceclass cannot change the class of a non-human player.");
			DebugLog(DEBUG_Multi, "Admin::Forceclass Error! Attempting to change the class of non-human PlayerController!");
			return false;
		}
		else
		{
			DebugLog(DEBUG_Multi, "Admin::Forceclass Changing class of " + FString::FromInt(HC) + " to '" + WhichClass + "'");
		}
		if (((HC.Pawn != nullptr) && (HC.Pawn.Weapon != nullptr)) && HC.Pawn.Weapon.IsZoomed())
		{
			ClientMessage("Unable to forceclass player with weapon zoomed.");
			HC.ClientMessage("Administrator tried to forceclass you but your weapon is zoomed.");
			return true;
		}
		if (((HC.Pawn != nullptr) && (HC.Pawn.Weapon != nullptr)) && HC.Pawn.Weapon->IsA(AItem_Parachute::StaticClass()))
		{
			ClientMessage("Unable to forceclass player wearing a parachute.");
			HC.ClientMessage("Administrator tried to forceclass you but still have a parachute on.");
			return true;
		}
		str = "Changing class of player '" + HC.PlayerReplicationInfo.PlayerName + "' to '" + WhichClass + "'";
		ClientMessage(str);
		HC.ClientForceNewClass(WhichClass);
		if (HC.Pawn != nullptr)
		{
			HC.LockPlayer(false, false);
			switch (WhichClass)
			{
			case "":
				ScreenPrint("Type \"Class X\" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, RPG9");
				return false;
			case "M":
			case "M4A1":
				sclass_name = "AGP_Characters.ClassRiflemanM4A1AutoIron";
				break;
			case "MA":
			case "M4A1Auto":
				sclass_name = "AGP_Characters.ClassRiflemanM4A1Auto";
				break;
			case "AR":
			case "AutomaticRifleman":
				sclass_name = "AGP_Characters.ClassAutomaticRifleman";
				break;
			case "R":
			case "Rifleman":
				sclass_name = "AGP_Characters.ClassRifleman";
				break;
			case "RCT":
			case "Recruit":
				sclass_name = "AGP_Characters.ClassRecruit";
				break;
			case "AK":
			case "RiflemanAK":
				sclass_name = "AGP_Characters.ClassRiflemanAK";
				break;
			case "AK74SU":
				sclass_name = "AGP_Characters.ClassRiflemanAK74SU";
				break;
			case "AK74suReflex":
				sclass_name = "AGP_Characters.ClassGuerrillaAK74suReflex";
				break;
			case "RPK":
				sclass_name = "AGP_Characters.ClassAutomaticRiflemanRPK";
				break;
			case "M4M":
				sclass_name = "AGP_Characters.ClassRiflemanM4A1Mod";
				break;
			case "G":
			case "Grenadier":
				sclass_name = "AGP_Characters.ClassGrenadier";
				break;
			case "GP":
				sclass_name = "AGP_Characters.ClassGrenadierGP30_Op";
				break;
			case "Mos":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassSniperMos";
				}
			case "S":
			case "S82":
			case "Sniper":
			case "Sniper82":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassSniper";
				}
			case "S24":
			case "Sniper24":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassSniper24_US";
				}
			case "SVD":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassSniperSVD";
				}
			case "RPG":
				sclass_name = "AGP_Characters.ClassRPG";
			case "AT4":
				sclass_name = "AGP_Characters.ClassAT4Rocket";
			case "BDM":
				sclass_name = "AGP_Characters.ClassBDMRocket";
			case "M9":
				sclass_name = "AGP_Characters.ClassPistol";
			case "SF":
				sclass_name = "AGP_Characters.ClassSF";
			case "SFSniper":
			case "SPR":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassSFSniper";
				}
			case "PSO":
			case "GuerrillaPSO":
				sclass_name = "AGP_Characters.ClassGuerrillaPSO";
			case "V":
			case "VSS":
			case "GuerrillaSniper":
				if (GetNoSniper())
				{
					sclass_name = "AGP_Characters.ClassRifleman";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassGuerrillaSniper";
				}
			case "GuerrillaAK47su":
				sclass_name = "AGP_Characters.ClassGuerrillaAK47su";
			case "GuerrillaRPG":
				sclass_name = "AGP_Characters.ClassGuerrillaRPG";
			case "GuerrillaRPK":
				sclass_name = "AGP_Characters.ClassGuerrillaRPK";
			case "D":
				sclass_name = "AGP_Characters.ClassDemolitions";
			case "J":
				if (!PlayerReplicationInfo.bQualifiedJavelin)
				{
					sclass_name = "AGP_Characters.ClassJavelinTube";
				}
				else
				{
					sclass_name = "AGP_Characters.ClassJavelin";
				}
			case "JT":
				sclass_name = "AGP_Characters.ClassJavelinTube";
			case "RPG9":
				sclass_name = "AGP_Characters.ClassGuerrillaRPGNine";
			default:
				ScreenPrint("Unrecognized class " + WhichClass);
				ScreenPrint("Type \"Class X\" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, J, RPG9");
				return false;
			}
			HC.CleanUp();
			Cast<AAGP_Pawn>(HC.Pawn).bForcedWeaponChange = true;
			sclass = class<SoldierClass>(DynamicLoadObject(sclass_name, Class'Class'));
			HC.newTeamClass(sclass);
			if ((Pawn.Weapon != nullptr) && Pawn.Weapon->IsA(AItem_Parachute::StaticClass()))
			{
				Cast<AAGP_Pawn>(Pawn)->UpdateParachute(4);
			}
			if (HC == this)
			{
				Level.Game.Broadcast(Level.Game, HC.UserName + " has forceclassed his own weapon class to " + WhichClass);
			}
		}
		HC.ClientMessage("Due to server rules, scoring is reduced when force classing is enabled.");
		HC.ClientMessage("Your class choice has been overruled by the Administrator.  ");
	}
	*/
	return true;
}

void AHumanController::ServerAdminCommand(FString Cmd, FString Arg0AsPlayerName, FString Arguments)
{
	TArray<FString> Args = { "","","","","","","","" };
	int32 NumArgs = 0;
	int32 iPos = 0;
	FString CommandLine = "";
	FString str = "";
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	AHumanController* HC = nullptr;
	bool bMuteAll = false;
	bool abEnabled = false;
	int32 NumTourneyCaptains = 0;
	NumArgs = 0;
	NumTourneyCaptains = 0;
	CommandLine = Arguments;
	Args = {
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		""
	};
	if (PlayerReplicationInfo == nullptr)
	{
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}
	if (PlayerReplicationInfo->bAdmin)
	{
		/*
		do
		{
			iPos = InStr(CommandLine, " ");
			if (iPos > 0)
			{
				Args[NumArgs] = Left(CommandLine, iPos);
				NumArgs += 1;
				CommandLine = Right(CommandLine, ((Len(CommandLine) - iPos) - 1));
			}
			else
			{
				Args[NumArgs] = CommandLine;
				NumArgs += 1;
				CommandLine = "";
			}
		}
		until(((iPos <= 0) || (NumArgs >= 8)));
		if (Cmd ~= "RestartMap")
		{
			Level.ServerTravel("?restart", false);
		}
		else
		{
			if (Cmd ~= "CommandPost")
			{
				ClientTriggerCommandPost();
			}
			else
			{
				if (Cmd ~= "Kick")
				{
					if ((Args[0] == "") || (Args[0] == "?"))
					{
						ClientMessage("");
						ClientMessage("You can get the player names or number using \"PlayerList\".");
						ClientMessage("Usage: admin Kick <player name or number>");
					}
					else
					{
						if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
						{
							Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Player: \"" + Arg0AsPlayerName + "\"", "AdminKick");
						}
						Level.Game.Kick(Arg0AsPlayerName, "Admin");
						ClientMessage("Player '" + Arg0AsPlayerName + "' has been kicked.");
					}
				}
				else
				{
					if (Cmd ~= "ToggleForceclass")
					{
						GameReplicationInfo.bAllowForceclassing = (!GameReplicationInfo.bAllowForceclassing);
						if (GameReplicationInfo.bAllowForceclassing)
						{
							GameReplicationInfo.bForceClassUsedInRound = true;
						}
						GameReplicationInfo.SaveConfig();
						for (C = Level.ControllerList; C != nullptr; C = C.nextController)
						{
							if (Cast<AHumanController>(C) != nullptr)
							{
								Cast<AHumanController>(C).ClientUpdateForceclassing(GameReplicationInfo.bAllowForceclassing, true);
							}
						}
						if (GameReplicationInfo.bAllowForceclassing)
						{
							ClientMessage("is now enabled (and honor scoring reduced to 75% of standard).");
							ClientMessage("Global force classing (\"admin forceclass * <class>\")");
						}
						else
						{
							ClientMessage("Global force classing is now disabled and honor will be at 100% for the next round.");
						}
					}
					else
					{
						if (Cmd ~= "KickBan")
						{
							if ((Args[0] == "") || (Args[0] == "?"))
							{
								ClientMessage("");
								ClientMessage("Note that admins and player admins cannot be banned.");
								ClientMessage("To unban a player use 'admin unban <banlist index>'");
								ClientMessage("To view banned players use 'admin BanList'");
								ClientMessage("");
								ClientMessage("Which will ban 'SomePlayer' for one day by name and IP address and kick the player from the server.");
								ClientMessage("Example: admin kickban SomePlayer 1d IP");
								ClientMessage("Usage: admin kickban <playername> [<time[w|d|h|m]> [NAME | IP | MAC | PBGUID]]");
							}
							else
							{
								if (Level.Game.KickBan(this, Arg0AsPlayerName, Args[1], Args[2]))
								{
									ClientMessage("Player '" + Arg0AsPlayerName + "' has been kicked & banned.");
								}
								else
								{
									ClientMessage("Unable to kick & ban player '" + Arg0AsPlayerName + "'.");
								}
							}
						}
						else
						{
							if (Cmd ~= "Mute")
							{
								if ((Args[0] == "") || (Args[0] == "?"))
								{
									ClientMessage("Player names can be found using the \"PlayerList\" command.");
									ClientMessage("Usage: admin mute <all | playername>");
									return;
								}
								if (Args[0] ~= "all")
								{
									bMuteAll = true;
								}
								else
								{
									bMuteAll = false;
								}
								if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
								{
									Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Options: \"" + Arguments + "\"", "AdminMute");
								}
								for (C = Level.ControllerList; C != nullptr; C = C.nextController)
								{
									PC = Cast<APlayerController>(C);
									if (PC != nullptr)
									{
										if ((bMuteAll == false) && (PC.PlayerReplicationInfo.PlayerName != Arg0AsPlayerName))
										{
										}
										if (PC.PlayerReplicationInfo.SuperUser() || PC.PlayerReplicationInfo.bAdmin)
										{
										}
										Level.Game.ToggleMutedPlayer(PC.PlayerReplicationInfo.PlayerName);
										str = "Mute toggled for player '" + PC.PlayerReplicationInfo.PlayerName + "'";
										PC.ClientMessage(str);
										ClientMessage(str);
									}
								}
							}
							else
							{
								if (Cmd ~= "Say")
								{
									if (Args[0] == "")
									{
										ClientMessage("");
										ClientMessage("Usage: admin say <text>");
										return;
									}
									ServerSay(Arguments, "AdminSay");
								}
								else
								{
									if (Cmd ~= "CSay")
									{
										if (Args[0] == "")
										{
											ClientMessage("");
											ClientMessage("Usage: admin csay <text>");
											return;
										}
										ServerSay(Arguments, "CommandChat");
									}
									else
									{
										if (Cmd ~= "Message")
										{
											if ((Args[0] == "") || (Args[0] == "?"))
											{
												ClientMessage("");
												ClientMessage("You must enter some text to display in the popup window.");
												ClientMessage("Usage: admin message <text>");
												return;
											}
											if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.1)
											{
												Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, Arguments, "AdminMessage");
											}
											for (C = Level.ControllerList; C != nullptr; C = C.nextController)
											{
												HC = Cast<AHumanController>(C);
												if (HC != nullptr)
												{
													HC.NotifyAdminMessage(Arguments);
												}
											}
										}
										else
										{
											if (((Cmd ~= "Switch") || (Cmd ~= "A_Open")) || (Cmd ~= "A_Map"))
											{
												if ((Args[0] == "") || (Args[0] == "?"))
												{
													ClientMessage("");
													ClientMessage("Do not include the file name extension on the map name.");
													ClientMessage("Usage: admin switch <mapname>");
													return;
												}
												if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
												{
													Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Map: \"" + Args[0] + "\"", "AdminSwitchMap");
												}
												Level.ServerTravel(Args[0], false);
											}
											else
											{
												if (Cmd ~= "AdminSet")
												{
													if (IsServerSetting(Args[0], Args[1], Args[2]))
													{
														DebugLog(DEBUG_Multi, "Admin command: Arg0: " + Args[0] + " Arg1: " + Args[1] + " Arg2: " + Args[2]);
														if ((Args[0] ~= "AccessControl") && (Args[1] ~= "AdminPassword"))
														{
															ClientMessage("That cannot be set using this command.");
															return;
														}
														if (((((Args[0] ~= "AGP_GameMultiPlayer") || (Args[0] ~= "AGP_GameTeamObjective")) && (Args[1] ~= "bRequireAuthorization")) && (Args[2] ~= "False")) && (!Level.IsLanOnlyServer()))
														{
															Log("User tried to disable authorization on non LAN server.");
															ClientMessage("You cannot disable authorization for a global server.");
															NotifyAdminMessage("You cannot disable authorization for a global server.");
															return;
														}
														PrivateSet(Arguments);
													}
													else
													{
														ClientMessage("");
														ClientMessage("Usage: admin adminset <section> <setting> <value>");
														DebugLog(DEBUG_Warn, "HumanController::ServerAdminCommand()	Admin tried illegal or unknown AdminSet(" @ Arguments @ ")");
													}
												}
												else
												{
													if (Cmd ~= "A_SwitchTeam")
													{
														if ((Args[0] == "") || (Args[0] == "?"))
														{
															ClientMessage("");
															ClientMessage("Note that player will switch teams at the start of the next round depending on balance options.");
															ClientMessage("Player names can be found using \"PlayerList\".");
															ClientMessage("Usage: admin A_SwitchTeam <player name>");
															return;
														}
														if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
														{
															Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Player \"" + Arg0AsPlayerName + "\"", "AdminSwitchTeam");
														}
														C = Level.ControllerList;
														if (C != nullptr)
														{
															PC = Cast<APlayerController>(C);
															if ((PC != nullptr) && (PC.PlayerReplicationInfo.PlayerName ~= Arg0AsPlayerName))
															{
																PC.SwitchTeam();
															}
															else
															{
																C = C.nextController;
															}
														}
													}
													else
													{
														if (Cmd ~= "Forceclass")
														{
															if (NumArgs < 2)
															{
																ClientMessage("");
																ClientMessage("Player names can be found using \"PlayerList\".");
																ClientMessage("Usage: admin forceclass <playername> <class>");
															}
															else
															{
																if (Arg0AsPlayerName == "*")
																{
																	if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																	{
																		Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Player: \"All\" Class: \"" + Args[1] + "\"", "AdminForceClassAll");
																	}
																	AdminForceClassAllPlayers(Args[1]);
																}
																else
																{
																	if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																	{
																		Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Player: \"" + Arg0AsPlayerName + "\"  Class: \"" + Args[1] + "\"", "AdminForceClassPlayer");
																	}
																	if (Level.Game.CheatsDisabled())
																	{
																		ClientMessage("You must enable cheats to forceclass a single player");
																	}
																	else
																	{
																		AdminForceClass(Arg0AsPlayerName, Args[1]);
																	}
																}
															}
														}
														else
														{
															if (Cmd ~= "DeathMessages")
															{
																if (((Args[0] ~= "on") || (Args[0] ~= "true")) || (Args[0] ~= "1"))
																{
																	abEnabled = true;
																}
																else
																{
																	abEnabled = false;
																}
																DebugLog(DEBUG_Multi, "Setting DeathMessages to " + FString::FromInt(abEnabled));
																Level.Game.bDeathMessages = abEnabled;
																Level.Game.SaveConfig();
																if (Level.Game.bDeathMessages)
																{
																	ClientMessage("Setting Death Messages to TRUE");
																}
																else
																{
																	ClientMessage("Setting Death Messages to FALSE");
																}
															}
															else
															{
																if (Cmd ~= "Score")
																{
																	abEnabled = Level.Game.SetScoreMode(Args[0]);
																	if (abEnabled)
																	{
																		Level.Game.SaveConfig();
																		switch (Level.Game.ScoreMode)
																		{
																		case 0:
																			ClientMessage("Setting score mode to SSM_On");
																			break;
																		case 1:
																			ClientMessage("Setting score mode to SSM_Off");
																			break;
																		case 2:
																			ClientMessage("Setting score mode to SSM_Round");
																			break;
																		case 3:
																			ClientMessage("Setting score mode to SSM_Match");
																			break;
																		default:
																		}
																	}
																	else
																	{
																		ClientMessage("Usage: admin score (on | off | round | match)");
																	}
																}
																else
																{
																	if (Cmd ~= "MOTD")
																	{
																		if (Args[0] ~= "self")
																		{
																			if (GameReplicationInfo.MOTDLine1 != "")
																			{
																				ClientMessage("Message of the day: " + GameReplicationInfo.MOTDLine1);
																			}
																		}
																		else
																		{
																			if (Args[0] ~= "all")
																			{
																				if (GameReplicationInfo.MOTDLine1 != "")
																				{
																					Level.Game.Broadcast(this, "Message of the day: " + GameReplicationInfo.MOTDLine1);
																				}
																			}
																			else
																			{
																				GameReplicationInfo.MOTDLine1 = ApplyFilters(Arguments);
																				ClientMessage("Changing Message Of The Day To: " + GameReplicationInfo.MOTDLine1);
																				GameReplicationInfo.SaveConfig();
																			}
																		}
																	}
																	else
																	{
																		if (Cmd ~= "ROEKickTimer")
																		{
																			if (((Args[0] ~= "true") || (Args[0] ~= "1")) || (Args[0] ~= "on"))
																			{
																				Level.Game.SetROEKickTimer(true);
																				ClientMessage("ROE Kick-Timer enabled.");
																			}
																			else
																			{
																				if (((Args[0] ~= "false") || (Args[0] ~= "0")) || (Args[0] ~= "off"))
																				{
																					Level.Game.SetROEKickTimer(false);
																					ClientMessage("ROE Kick-Timer disabled.");
																				}
																			}
																		}
																		else
																		{
																			if (Cmd ~= "ROEKick")
																			{
																				if (((Args[0] ~= "true") || (Args[0] ~= "1")) || (Args[0] ~= "on"))
																				{
																					Level.Game.SetROEKick(true);
																					ClientMessage("ROE Kick enabled.");
																				}
																				else
																				{
																					if (((Args[0] ~= "false") || (Args[0] ~= "0")) || (Args[0] ~= "off"))
																					{
																						Level.Game.SetROEKick(false);
																						ClientMessage("ROE Kick disabled.");
																					}
																				}
																			}
																			else
																			{
																				if (Cmd ~= "ROEKickDead")
																				{
																					if (((Args[0] ~= "true") || (Args[0] ~= "1")) || (Args[0] ~= "on"))
																					{
																						Level.Game.SetROEKickDead(true);
																						ClientMessage("ROE violations will be punished with death.");
																					}
																					else
																					{
																						if (((Args[0] ~= "false") || (Args[0] ~= "0")) || (Args[0] ~= "off"))
																						{
																							Level.Game.SetROEKickDead(false);
																							ClientMessage("ROE violations will be punished with kick.");
																						}
																					}
																				}
																				else
																				{
																					if (Cmd ~= "roundsuspend")
																					{
																						if (((Args[0] ~= "true") || (Args[0] ~= "1")) || (Args[0] ~= "on"))
																						{
																							if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																							{
																								Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "", "AdminSuspendRound");
																							}
																							Level.Game.GameReplicationInfo.SuspendRound(true);
																						}
																						else
																						{
																							if (((Args[0] ~= "false") || (Args[0] ~= "0")) || (Args[0] ~= "off"))
																							{
																								if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																								{
																									Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "", "AdminResumeRound");
																								}
																								Level.Game.GameReplicationInfo.SuspendRound(false);
																							}
																						}
																					}
																					else
																					{
																						if (Cmd ~= "roundreset")
																						{
																							DebugLog(DEBUG_Multi, "roundreset entered for admin");
																							ClientMessage("Initating round reset");
																							Level.Game.GameReplicationInfo.bRoundIsSuspended = false;
																							Level.Game.GameReplicationInfo.SecsTillRoundResume = 0;
																							Level.Game.GameReplicationInfo.RemainingMinute = (Level.Game.TimeLimit * 60);
																							Level.Game.GameReplicationInfo.bStopCountDown = true;
																							for (C = Level.ControllerList; C != nullptr; C = C.nextController)
																							{
																								PC = Cast<APlayerController>(C);
																								if (PC != nullptr)
																								{
																									PC.ClientMessage("An admin is resetting the round...please wait...");
																									PC.ClientSetTimeRemaining((Level.Game.TimeLimit * 60));
																								}
																							}
																							Level.Game.EndGame(nullptr, "Admin Round Reset");
																						}
																						else
																						{
																							if (Cmd ~= "ban")
																							{
																								if ((Args[0] == "") || (Args[1] == ""))
																								{
																									ClientMessage("");
																									ClientMessage("To unban a player use 'admin unban <banlist index>'");
																									ClientMessage("To view banned players use 'admin BanList'");
																									ClientMessage("");
																									ClientMessage("Which will ban 'SomePlayer' for one day by name and IP address.");
																									ClientMessage("Example: admin ban SomePlayer 1d IP");
																									ClientMessage("Usage: admin ban  <playername> <time[w|d|h|m]> <[NAME | IP | MAC | PBGUID]>");
																								}
																								else
																								{
																									Level.Game.Ban(this, Arg0AsPlayerName, Args[1], Args[2]);
																								}
																							}
																							else
																							{
																								if (Cmd ~= "banlist")
																								{
																									if (Len(Args[0]) > 0)
																									{
																										Level.Game.AccessControl.DisplayBanList(this, int(Args[0]));
																									}
																									else
																									{
																										Level.Game.AccessControl.DisplayBanList(this, 0);
																									}
																								}
																								else
																								{
																									if (Cmd ~= "unban")
																									{
																										if (Args[0] == "")
																										{
																											ClientMessage("");
																											ClientMessage("Use 'admin banlist' for list of entries to pick from");
																											ClientMessage("Usage: admin unban <ban_index>");
																										}
																										else
																										{
																											Level.Game.AccessControl.Unban(this, int(Args[0]));
																										}
																									}
																									else
																									{
																										if (Cmd ~= "Spectate")
																										{
																											if ((Args[0] == "") || (Args[0] == "?"))
																											{
																												ClientMessage("");
																												ClientMessage("Player names can be found using the \"PlayerList\" command.");
																												ClientMessage("Usage: admin spectate <player name>");
																												return;
																											}
																											AdminSpectate(Arg0AsPlayerName);
																										}
																										else
																										{
																											if (Left(Cmd, 3) ~= "pb_")
																											{
																												if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
																												{
																													Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Command: \"" + Cmd @ Arguments + "\"", "AdminPunkBuster");
																												}
																												ConsoleCommand(Cmd @ Arguments);
																												if (Cmd ~= "pb_sv_disable")
																												{
																													ClientMessage("");
																													ClientMessage("You can turn PunkBuster back on with 'admin pb_sv_enable'.");
																													ClientMessage("You will need to stop and restart the server to disable PunkBuster.");
																												}
																											}
																											else
																											{
																												ClientMessage("Unknown admin command: " + Cmd);
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
}

void AHumanController::AdminSpectate(FString argument)
{
	AController* C = nullptr;
	APawn* p = nullptr;
	bool bFound = false;
	FString PlayerName = "";
	int32 Team = 0;
	AController* first = nullptr;
	AController* Current = nullptr;
	bool bUseNext = false;
	/*
	if (((Pawn != nullptr) && (Pawn.Health > 0)) && (!PlayerReplicationInfo.bOnlySpectator))
	{
		ClientMessage("You cannot spectate other players while you are playing.");
		return;
	}
	Team = -1;
	if (TournamentIsTournament())
	{
		if ((argument == "team0") || (argument == GameReplicationInfo.asTournamentTeamName[0]))
		{
			Team = 0;
		}
		else
		{
			if ((argument == "team1") || (argument == GameReplicationInfo.asTournamentTeamName[1]))
			{
				Team = 1;
			}
			else
			{
				if ((argument == "all") || (argument == ""))
				{
					Team = -1;
				}
				else
				{
					PlayerName = argument;
				}
			}
		}
	}
	else
	{
		if ((argument == "team0") || (argument == Level.TeamName[0]))
		{
			Team = 0;
		}
		else
		{
			if ((argument == "team1") || (argument == Level.TeamName[1]))
			{
				Team = 1;
			}
			else
			{
				if ((argument == "all") || (argument == ""))
				{
					Team = -1;
				}
				else
				{
					PlayerName = argument;
				}
			}
		}
	}
	if (PlayerName != "")
	{
		C = Level.ControllerList;
		if (C != nullptr)
		{
			if (PlayerName ~= C.PlayerReplicationInfo.GetHumanReadableName())
			{
				bFound = true;
				if (C.Pawn == nullptr)
				{
					ClientMessage("Player(" + PlayerName + ") is not currently active");
				}
				else
				{
			else
			{
				if (C.Pawn.Health <= 0)
				{
					ClientMessage("Player(" + PlayerName + ") is not currently alive and cannot be viewed");
					return;
				}
				p = C.Pawn;
			}
				}
				C = C.nextController;
			}
		}
		if (!bFound)
		{
			ClientMessage("Player(" + PlayerName + ") not found!");
		}
	}
	if (p == nullptr)
	{
		Current = Cast<AController>(ViewTargetActor);
		if (Current != nullptr)
		{
			if (Team != Current.PlayerReplicationInfo.Team.TeamIndex)
			{
				Current = nullptr;
			}
		}
		if (Current == nullptr)
		{
			bUseNext = true;
		}
		C = Level.ControllerList;
		if (C != nullptr)
		{
			if ((C.Pawn != nullptr) && ((Team == -1) || (Team == C.PlayerReplicationInfo.Team.TeamIndex)))
			{
				if (bUseNext)
				{
					p = C.Pawn;
				}
				else
				{
					if (first == nullptr)
					{
						first = C;
					}
					if (C == Current)
					{
						bUseNext = true;
					}
				}
				C = C.nextController;
			}
		}
		if ((p == nullptr) && (first != nullptr))
		{
			p = first.Pawn;
		}
	}
	if (p != nullptr)
	{
		SetViewTarget(p);
		ClientSetViewTarget2(p);
	}
	else
	{
		if (Team == -1)
		{
			ClientMessage("No active players to spectate");
		}
		else
		{
			ClientMessage("No active players on team '" @ FString::FromInt(Team) @ "' to spectate");
		}
	}

	*/
}

bool AHumanController::IsServerSetting(FString Section, FString Setting, FString Value)
{
	int32 i = 0;
	int32 Len = 0;
	/*
	if ((Section ~= "") || (Setting ~= ""))
	{
		return false;
	}
	Len = FMath::Min(Level.Game.Section.Num(), Level.Game.Setting.Num());
	for (i = 0; i < Len; i++)
	{
		if ((Section ~= Level.Game.Section[i]) && (Setting ~= Level.Game.Setting[i]))
		{
			return true;
		}
	}
	*/
	return false;
}

void AHumanController::Admin(FString CommandLine)
{
	/*
		FString Cmd;
		FString Arg0;
		int32 iPos;
		iPos=InStr(CommandLine," ");
		if (iPos <= 0)
		{
			Cmd=CommandLine;
			Arg0="";
			CommandLine="";
		}
		else
		{
			Cmd=Left(CommandLine,iPos);
			CommandLine=Right(CommandLine,Len(CommandLine) - iPos - 1);
			iPos=InStr(CommandLine," ");
			if (iPos <= 0)
			{
				Arg0=CommandLine;
			}
			else
			{
				Arg0=Left(CommandLine,iPos);
			}
		}
		if (Cmd ~= "CommandPost")
		{
			Player.Console.ConsoleClose();
		}
		ServerAdminCommand(Cmd,MaybeGetPlayerNameFromID(Arg0),CommandLine);
	*/
}
void AHumanController::GetAuthUserName()
{
	/*
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			return PlayerReplicationInfo.PlayerName;
		}
		Log(this + ".GetAuthUserName() - User Name: """ + UserName + """, saved: """ + sSavedUserName + """");
		if (Len(UserName) == 0 || UserName ~= "UserName")
		{
			UserName=sSavedUserName;
		}
		return UserName;
	*/
}
bool AHumanController::TournamentIsTournament()
{
	bool bResult;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		bResult=bTournamentServer;
	}
	else
	{
		//bResult=Level.Game.TournamentIsTournament();
		bResult = false; // temp set until above row works
	}
	return bResult;
}

FString AHumanController::TournamentGetTeamPasswordFor(int32 iTeamIndex)
{
	/*
	if (iTeamIndex == 0 || iTeamIndex == 1)
	{
		return Level.Game.AccessControl.asTeamPasswords[iTeamIndex];
	}
	*/
	return "";
}

void AHumanController::TournamentJoinTeam(int32 iTeamIndex, FString sPassword)
{
	/*
		if (PlayerReplicationInfo.bOnlySpectator && GameReplicationInfo.sTournamentState != "Setup")
		{
			ClientCloseMenu(true);
			NotifyAdminMessage("After Setup, Spectators can not join a team without reconnecting.");
			return;
		}
		if (GameReplicationInfo.sTournamentState == "Complete")
		{
			ClientCloseMenu(true);
			TournamentCaptainAdminMessage("All players must leave the server to allow it to reset the tournament before you can join a team.");
			return;
		}
		PlayerReplicationInfo.DesiredTeam=iTeamIndex;
		TournamentServerJoinTeam(iTeamIndex,sPassword);
	*/
}

void AHumanController::TournamentServerJoinTeam(int32 iTeamIndex, FString sPassword)
{
	bool bResult = false;
	/*
	if (Level.Game.TournamentGetTeam(iTeamIndex).Size > Level.Game.TournamentGetMaxTeamSize())
	{
		return;
	}
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		PlayerReplicationInfo.bOnlySpectator=false;
		if (Level.Game.NumSpectators > 1)
		{
			Level.Game.NumSpectators --;
		}
	}
	bResult=Level.Game.TournamentJoinTeam(this,iTeamIndex,sPassword);
	TournamentNotifyPlayerJoinedTeam(iTeamIndex,bResult);
	*/
}

void AHumanController::TournamentNotifyPlayerJoinedTeam(int32 iTeamIndex, bool bResult, bool bAdminAssigned)
{
	/*
	if (! bResult)
	{
		ClientMessage("Bad team password");
		ClientOpenMenu("AGP_Interface.AAGenericMessageBox",,"Invalid Password","This team requires a password to join. Please enter a valid password.");
	}
	else
	{
		if (bAdminAssigned)
		{
			TournamentCaptainAdminMessage("The administrator assigned you to team " + GameReplicationInfo.asTournamentTeamName[iTeamIndex]);
		}
		else
		{
			ClientMessage("Joined team " + GameReplicationInfo.asTournamentTeamName[iTeamIndex]);
		}
		SelectClass();
	}
	*/
}

void AHumanController::TournamentJoinSpectatorTeam(int32 iTeamIndex)
{
	//TournamentServerJoinSpectatorTeam(iTeamIndex);
}

void AHumanController::TournamentServerJoinSpectatorTeam(int32 iTeamIndex)
{
	bool bResult = false;
	/*
	if (Level.Game.MaxSpectators == 0)
	{
		TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,false,"Spectators are not allowed.");
		return;
	}
	if (Level.Game.NumSpectators >= Level.Game.MaxSpectators)
	{
		TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,false,"All spectating slots are filled.");
		return;
	}
	Level.Game.NumSpectators ++;
	Level.Game.NumPlayers --;
	PlayerReplicationInfo.bOnlySpectator=true;
	bResult=Level.Game.TournamentJoinSpectatorTeam(this,iTeamIndex);
	TournamentNotifyPlayerJoinedSpectatorTeam(iTeamIndex,bResult,"");
	*/
}

void AHumanController::TournamentNotifyPlayerJoinedSpectatorTeam(int32 iTeamIndex, bool bResult, FString sReason)
{
	/*
	if (! bResult)
	{
		NotifyAdminMessage(sReason);
	}
	else
	{
		PlayerReplicationInfo.bOnlySpectator=true;
		ClientMessage("Joined spectators.");
	}
	*/
}

bool AHumanController::TournamentAssignClass(FString sPlayerName, int32 iUnitID, int32 iSlot)
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	bool bGoodAssignment = false;
	bGoodAssignment = false;
	/*
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if ((PC.PlayerReplicationInfo.PlayerName ~= sPlayerName) || (string(PC.PlayerReplicationInfo.PlayerID) == sPlayerName))
		{
			if (PC.PlayerReplicationInfo->Team->TeamIndex == 255)
			{
				ClientMessage("Spectators cannot be assigned to squad positions.");
				return false;
			}
			PC.PlayerReplicationInfo.SubmitPlayerRequest(iUnitID, iSlot);
			return true;
		}
	}
	*/
	return false;
}

bool AHumanController::TournamentRemoveClass(FString sPlayerName, int32 iUnitID, int32 iSlot)
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	bool bGoodAssignment = false;
	bGoodAssignment = false;
	/*
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if ((PC.PlayerReplicationInfo.PlayerName ~= sPlayerName) || (string(PC.PlayerReplicationInfo.PlayerID) == sPlayerName))
		{
			if (PC.PlayerReplicationInfo->Team->TeamIndex == 255)
			{
				ClientMessage("Spectators are not part of squads.");
				return false;
			}
			PC.PlayerReplicationInfo.RemovePlayerRequest(PC.PlayerReplicationInfo);
			return true;
		}
	}
	*/
	return false;
}

void AHumanController::NotifyTournamentTeamNameUpdated(int32 iTeamIndex, FString sTeamName)
{
	
	if (iTeamIndex > 1 || iTeamIndex < 0)
	{
		return;
	}
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->asTournamentTeamName[iTeamIndex] = sTeamName;
	
}
void AHumanController::TournamentSetTeamName(int32 iTeam, FString sTeamName)
{
	/*
		int32 iOtherTeamIndex;
		if (iTeam > 1 || iTeam < 0)
		{
			return;
		}
		//if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		//{
		//	NotifyAdminMessage("Only Team Captains or Administrators can set team names.");
		//	return;
		//}
		if (Len(sTeamName) == 0)
		{
			NotifyAdminMessage("Your team name must be at least one character long.");
			return;
		}
		if (iTeam == 0)
		{
			iOtherTeamIndex=1;
		}
		else
		{
			iOtherTeamIndex=0;
		}
		if (sTeamName ~= GameReplicationInfo.asTournamentTeamName[iOtherTeamIndex])
		{
			NotifyAdminMessage("That team name has already been chosen.");
			return;
		}
		Level.Game.GameReplicationInfo.SetTournamentTeamName(iTeam,sTeamName);
		Level.Game.TournamentSetTeamName(iTeam,sTeamName);
		Level.Game.SaveConfig();
		TournamentNotifyNewTeamName();
	*/
}
void AHumanController::TournamentServerSetTeamName(int32 iTeam, FString sTeamName)
{
	//Level.Game.TournamentSetTeamName(iTeam, sTeamName);
	//TournamentNotifyNewTeamName();
}
void AHumanController::TournamentNotifyNewTeamName()
{
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewTeamName();
	}
}
void AHumanController::NotifyTeamCaptainRequestStatus(bool bTeamCaptain)
{
}
void AHumanController::TournamentNotifyNewTeamCaptain()
{
	if (MyHUD != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewTeamCaptain();
	}
}
bool AHumanController::TournamentAreAllWeaponClassesAvailable()
{
	return Cast<AAA2_GameState>(GetWorld()->GetGameState())->bTournamentOpenAllWeaponClassSlots;
}
void AHumanController::TournamentCaptainLockWeaponClasses(bool fLock)
{
	AController* ctrlrScan = nullptr;
	FString sResponse = "";
	if (PlayerReplicationInfo->bAdmin)
	{
		/*
		GameReplicationInfo->Teams[0]->bTournamentTeamRosterLocked = fLock;
		GameReplicationInfo->Teams[1]->bTournamentTeamRosterLocked = fLock;
		*/
	}
	else
	{
		/*
		GameReplicationInfo.Teams[PlayerReplicationInfo->Team->TeamIndex].bTournamentTeamRosterLocked = fLock;
		if (GameReplicationInfo.Teams[PlayerReplicationInfo->Team->TeamIndex].bTournamentTeamRosterLocked)
		{
			sResponse = "Roster locked for " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex];
		}
		else
		{
			sResponse = "Roster no longer locked for " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex];
		}
		for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
		{
			if (ctrlrScan->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(ctrlrScan).TeamMessage(nullptr, sResponse, "TMStatus");
				if (ctrlrScan.PlayerReplicationInfo->Team->TeamIndex == PlayerReplicationInfo->Team->TeamIndex)
				{
					if ((Cast<AHumanController>(ctrlrScan).MyHUD != nullptr) && (Cast<AAGP_HUD>(Cast<AHumanController>(ctrlrScan).MyHUD) != nullptr))
					{
						Cast<AAGP_HUD>(Cast<AHumanController>(ctrlrScan).MyHUD).TournamentNotifyNewWeaponClassLockState();
					}
				}
			}
		}
		*/
	}
}
void AHumanController::TournamentNotifyNewWeaponClassLockState()
{
	if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyNewWeaponClassLockState();
	}
}
void AHumanController::TournamentTeamReady(bool bReady)
{
	AController* ctrlrScan = nullptr;
	/*
	if ((!PlayerReplicationInfo.Administrator()) && (!PlayerReplicationInfo.bTournamentTeamCaptain))
	{
		if (PlayerReplicationInfo->Team->bTournamentTeamReady)
		{
			PlayerReplicationInfo->Team->bTournamentTeamReady = false;
		}
		ClientMessage("You are not " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + "'s Team Captain and cannot make your roster ready.");
		return;
	}
	if (PlayerReplicationInfo.Administrator())
	{
		Level.Game.TournamentTeamsReady();
		ServerSay("The administrator has made both rosters ready.", "AdminSay");
		return;
	}
	if (PlayerReplicationInfo->Team->bTournamentTeamReady)
	{
		PlayerReplicationInfo->Team->bTournamentTeamReady = false;
		Say("Team " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + " no longer ready.");
	}
	else
	{
		if ((!PlayerReplicationInfo.Administrator()) && PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			PlayerReplicationInfo->Team->bTournamentTeamReady = true;
			TournamentNotifyMyTeamReady();
			ClientCloseMenu(true);
			Say("Team " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + " ready.");
		}
	}
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		if ((ctrlrScan.PlayerReplicationInfo->Team->TeamIndex != PlayerReplicationInfo->Team->TeamIndex) && ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			if (ctrlrScan.PlayerReplicationInfo->Team->bTournamentTeamReady)
			{
				if (!PlayerReplicationInfo->Team->bTournamentTeamReady)
				{
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is no longer ready.");
				}
				else
				{
					TeamMessage(nullptr, "Both Team Captains have signalled they are ready.", "TMStatus");
					Level.Game.TournamentTeamsReady();
				}
				return;
			}
			else
			{
				if (!PlayerReplicationInfo->Team->bTournamentTeamReady)
				{
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is no longer ready.");
				}
				else
				{
					Cast<AHumanController>(ctrlrScan).TournamentNotifyOtherTeamReady();
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain is ready to continue.");
				}
			}
		}
	}
	if (PlayerReplicationInfo->Team->bTournamentTeamReady)
	{
		ClientMessage("Your team is ready. Waiting for the other Team Captain to become ready.");
	}
	else
	{
		ClientMessage("Your team is no longer ready.");
	}
	*/
}

void AHumanController::TournamentNotifyMyTeamReady()
{
	/*
	if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyMyTeamReady();
	}
	*/
}

void AHumanController::TournamentNotifyOtherTeamReady()
{
	/*
	if (MyHUD != nullptr && Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->TournamentNotifyOtherTeamReady();
	}
	*/
}
void AHumanController::TournamentAdminReady()
{
	if (PlayerReplicationInfo->Administrator())
	{
		//Level.GameTournamentTeamsReady();
		//ServerSay(" The administrator is continuing the tournament.",'Center');
		return;
	}
}

bool AHumanController::TournamentWarmupJustEnded()
{
	return GameReplicationInfo->bTournamentWarmupJustEnded;
}

bool AHumanController::TournamentIsPasswordRequired(int32 iTeamIndex)
{
	return GameReplicationInfo->bTournamentWarmupJustEnded;
}

bool AHumanController::TournamentAreCaptainsAllowed()
{
	return GameReplicationInfo->bTournamentTeamCaptainsAllowed;
}

bool AHumanController::TournamentAreTeamPasswordsRequired()
{
	return GameReplicationInfo->bTournamentTeamPasswordsRequired;
}

bool AHumanController::TournamentIsTeamCaptainSelected(int32 iTeamNum)
{
	if (iTeamNum != 255)
	{
		return GameReplicationInfo->Teams[iTeamNum]->bTournamentTeamCaptainSelected;
	}
	return false;
}

bool AHumanController::TournamentIsTeamRosterLocked(int32 iTeamNum)
{
	if (iTeamNum != 255)
	{
		return GameReplicationInfo->Teams[iTeamNum]->bTournamentTeamRosterLocked;
	}
	return false;
}

bool AHumanController::TournamentIsTeamReady(int32 iTeamNum)
{
	if (iTeamNum != 255)
	{
		return GameReplicationInfo->Teams[iTeamNum]->bTournamentTeamReady;
	}
	return false;
}

bool AHumanController::TournamentIsOtherTeamCaptainSelected()
{
	int32 iOtherTeamIndex = 0;
	iOtherTeamIndex=255;
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		if (PlayerReplicationInfo->Team->TeamIndex == 0)
		{
			iOtherTeamIndex=1;
		}
		else
		{
			iOtherTeamIndex=0;
		}
	}
	if (iOtherTeamIndex != 255)
	{
		return GameReplicationInfo->Teams[iOtherTeamIndex]->bTournamentTeamCaptainSelected;
	}
	return false;
}

bool AHumanController::TournamentIsOtherTeamRosterLocked()
{
	int32 iOtherTeamIndex = 0;
	iOtherTeamIndex=255;
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		if (PlayerReplicationInfo->Team->TeamIndex == 0)
		{
			iOtherTeamIndex=1;
		}
		else
		{
			iOtherTeamIndex=0;
		}
	}
	if (iOtherTeamIndex != 255)
	{
		return GameReplicationInfo->Teams[iOtherTeamIndex]->bTournamentTeamRosterLocked;
	}
	return false;
}

bool AHumanController::TournamentIsOtherTeamReady()
{
	int32 iOtherTeamIndex = 0;
	iOtherTeamIndex=255;
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		if (PlayerReplicationInfo->Team->TeamIndex == 0)
		{
			iOtherTeamIndex=1;
		}
		else
		{
			iOtherTeamIndex=0;
		}
	}
	if (iOtherTeamIndex != 255)
	{
		return GameReplicationInfo->Teams[iOtherTeamIndex]->bTournamentTeamReady;
	}
	return false;
}

bool AHumanController::TournamentIsMyTeamCaptainSelected()
{
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		return PlayerReplicationInfo->Team->bTournamentTeamCaptainSelected;
	}
	return false;
}

bool AHumanController::TournamentIsMyTeamRosterLocked()
{
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		return PlayerReplicationInfo->Team->bTournamentTeamRosterLocked;
	}
	return false;
}

bool AHumanController::TournamentIsMyTeamReady()
{
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		return PlayerReplicationInfo->Team->bTournamentTeamReady;
	}
	return false;
}

FString AHumanController::GetTeamName(int32 iTeamNum)
{
	if (iTeamNum != 255)
	{
		if (TournamentIsTournament())
		{
			return GameReplicationInfo->asTournamentTeamName[iTeamNum];
		}
		else
		{
			return Cast<AAA2_WorldSettings>(GetWorldSettings())->TeamName[iTeamNum];
		}
	}
	return "";
}

FString AHumanController::GetOtherTeamName()
{
	int32 iOtherTeamIndex = 0;
	iOtherTeamIndex = 255;
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		if (PlayerReplicationInfo->Team->TeamIndex == 0)
		{
			iOtherTeamIndex = 1;
		}
		else
		{
			iOtherTeamIndex = 0;
		}
	}
	if (iOtherTeamIndex != 255)
	{
		if (TournamentIsTournament())
		{
			return GameReplicationInfo->asTournamentTeamName[iOtherTeamIndex];
		}
		else
		{
			//return Level.TeamName[iOtherTeamIndex];
		}
	}
	return "";

}

FString AHumanController::GetMyTeamName()
{
	if (PlayerReplicationInfo->Team->TeamIndex != 255)
	{
		if (TournamentIsTournament())
		{
			return GameReplicationInfo->asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex];
		}
		else
		{
			//return Level.TeamName[PlayerReplicationInfo->Team->TeamIndex];
		}
	}
	return "";
}

bool AHumanController::TournamentAreAllWeaponClassSlotsOpen()
{
	return GameReplicationInfo->bTournamentOpenAllWeaponClassSlots;
}

FString AHumanController::TournamentGetTournamentState()
{
	return GameReplicationInfo->sTournamentState;
}

void AHumanController::TournamentRequestSwapSides()
{
	AController* ctrlrScan = nullptr;
	/*
	APlayerController* PC = nullptr;
	int32 iCaptainsRequestingCount;
	if (PlayerReplicationInfo.bAdmin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestSwapSides() entered"));
		if (! Level.Game.TournamentRequestSwapSides())
		{
			NotifyAdminMessage("Swapping is not allowed at this time.");
		}
		return;
	}
	if (PlayerReplicationInfo.bTournamentTeamSwapRequest && GetWorld()->GetTimeSeconds() < NextSwapAllowed)
	{
		ClientMessage("You have already requested to swap sides at the end of the round. If your swap request is not granted you can try again during the next round.");
		return;
	}
	PlayerReplicationInfo.bTournamentTeamSwapRequest=true;
	NextSwapAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
	iCaptainsRequestingCount=1;
	ctrlrScan=Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		PC=Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (PC.PlayerReplicationInfo->Team->TeamIndex != PlayerReplicationInfo->Team->TeamIndex && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			if (PC.PlayerReplicationInfo.bTournamentTeamSwapRequest)
			{
				iCaptainsRequestingCount ++;
			}
			else
			{
				Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested to swap sides at the end of the round.");
			}
		}
		else
		{
			ctrlrScan=ctrlrScan.nextController;
		}
	}
	if (iCaptainsRequestingCount < 2)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestSwapSides() entered"));
	if (! Level.Game.TournamentRequestSwapSides())
	{
		PlayerReplicationInfo.bTournamentTeamSwapRequest=false;
		Level.Game.TournamentSendTeamCaptainOnlyMessage("Swapping sides is not allowed at this time.");
	}
	*/
}

void AHumanController::TournamentRequestStartWarmup()
{
	AController* ctrlrScan = nullptr;
	/*
	APlayerController* PC = nullptr;
	int32 iCaptainsRequestingCount;
	if (PlayerReplicationInfo.bAdmin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Server - TournamentRequestStartWarmup() entered"));
		Level.Game.TournamentRequestWarmup();
		return;
	}
	if (PlayerReplicationInfo.bTournamentWarmupRequest && GetWorld()->GetTimeSeconds() < NextWarmupAllowed)
	{
		ClientMessage("You have already requested the tournament be restarted with a warmup round. If your warmup request is not granted you can try again during the next round.");
		return;
	}
	PlayerReplicationInfo.bTournamentWarmupRequest=true;
	NextWarmupAllowed=GetWorld()->GetTimeSeconds() + GameReplicationInfo.iTournamentRequestDelayTime;
	iCaptainsRequestingCount=1;
	ctrlrScan=Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		PC=Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (PC.PlayerReplicationInfo->Team->TeamIndex != PlayerReplicationInfo->Team->TeamIndex && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			if (PC.PlayerReplicationInfo.bTournamentWarmupRequest)
			{
				iCaptainsRequestingCount ++;
			}
			else
			{
				Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested to restart with a mission planning round.");
			}
		}
		else
		{
			ctrlrScan=ctrlrScan.nextController;
		}
	}
	if (iCaptainsRequestingCount < 2)
	{
		return;
	}
	Level.Game.TournamentRequestWarmup();
	*/
}

void AHumanController::TournamentRequestPauseTournament()
{
	//TournamentRequestPause(PlayerReplicationInfo);
}

void AHumanController::TournamentRequestPause(AAA2_PlayerState* PRI)
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	if (PRI->bAdmin)
	{
		//Level.Game.TournamentRequestPauseTournament();
		ServerSay("The Administrator has paused the tournament after this game completes.", "AdminSay");
		return;
	}

	if (!PRI->bTournamentTeamCaptain)
	{
		ClientMessage("You are not the Team Captain and cannot request pauses.");
		return;
	}
	/*
	if (PRI.bTournamentMatchPauseRequest && (GetWorld()->GetTimeSeconds() < NextPauseAllowed))
	{
		ClientMessage("You have already requested the tournament to be paused. If your pause request is not granted you can try again during the next round.");
		return;
	}
	PRI.bTournamentMatchPauseRequest = true;
	NextPauseAllowed = (GetWorld()->GetTimeSeconds() + float(GameReplicationInfo.iTournamentRequestDelayTime));
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if ((PC.PlayerReplicationInfo->Team->TeamIndex != PRI.Team.TeamIndex) && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			DebugLog(DEBUG_Tournament, "Examining other team captain's pause request status");
			if (PC.PlayerReplicationInfo.bTournamentMatchPauseRequest)
			{
				Level.Game.TournamentRequestPauseTournament();
				TeamMessage(nullptr, "Both team captains have requested the tournament to be paused at the end of this round.", "TMStatus");
				return;
			}
			else
			{
				Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested the tournament be paused at the end of the round.");
			}
		}
	}
	*/
	ClientMessage("You have requested to pause the tournament after this round. Waiting for the other team captain to respond.");
}

void AHumanController::TournamentResume()
{
	Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentResumeFromPause();
}

void AHumanController::TournamentRestartMatch()
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	int32 iCaptainsRequestingCount = 0;
	ClientCloseMenu(true,false);
	/*
	if (PlayerReplicationInfo->bAdmin)
	{
		if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
		{
			Level.Game.TournamentTeamsReady();
		}
		else
		{
			Level.Game.TournamentRequestWarmup();
		}
		return;
	}
	if (PlayerReplicationInfo->bTournamentRestartRequest && (GetWorld()->GetTimeSeconds() < NextRestartAllowed))
	{
		ClientMessage("You have already requested the match be restarted. If your restart request is not granted you can try again during the next round.");
		return;
	}
	PlayerReplicationInfo->bTournamentRestartRequest = true;
	NextRestartAllowed = (GetWorld()->GetTimeSeconds() + float(GameReplicationInfo.iTournamentRequestDelayTime));
	iCaptainsRequestingCount = 0;
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan->nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (!PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
		}
		if (PC.PlayerReplicationInfo.bTournamentRestartRequest)
		{
			iCaptainsRequestingCount++;
		}
		else
		{
			if (PC != Self)
			{
				if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
				{
					Cast<AHumanController>(PC).TournamentCaptainAdminMessage("The other Team Captain has requested the match be started  now.");
				}
				else
				{
					Cast<AHumanController>(PC).TournamentCaptainAdminMessage("The other Team Captain has requested the match be restarted.");
				}
			}
		}
	}
	if (iCaptainsRequestingCount < 2)
	{
		return;
	}
	if (GameReplicationInfo.sTournamentState ~= "Mission Planning")
	{
		TeamMessage(nullptr, "Both team captains have requested the match be started now.", "TMCenter");
	}
	else
	{
		TeamMessage(nullptr, "Both team captains have requested the match be restarted.", "TMCenter");
	}
	Level.Game.TournamentRequestResetTournament();
	*/
}

void AHumanController::TournamentRestartTournament()
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	int32 iCaptainsRequestingCount = 0;
	ClientCloseMenu(true,false);
	/*
	if (PlayerReplicationInfo.bAdmin)
	{
		Level.Game.TournamentRequestResetTournament();
		return;
	}
	if (PlayerReplicationInfo.bTournamentRestartRequest && (GetWorld()->GetTimeSeconds() < NextRestartAllowed))
	{
		ClientMessage("You have already requested the match be restarted. If your restart request is not granted you can try again during the next round.");
		return;
	}
	PlayerReplicationInfo.bTournamentRestartTournamentRequest = true;
	NextRestartAllowed = (GetWorld()->GetTimeSeconds() + float(GameReplicationInfo.iTournamentRequestDelayTime));
	iCaptainsRequestingCount = 0;
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (!PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
		}
		if (PC.PlayerReplicationInfo.bTournamentRestartTournamentRequest)
		{
			iCaptainsRequestingCount++;
		}
		else
		{
			if (PC != Self)
			{
				Cast<AHumanController>(PC).TournamentCaptainAdminMessage("The other team captain has requested the tournament be restarted.");
			}
		}
	}
	if (iCaptainsRequestingCount < 2)
	{
		return;
	}
	TeamMessage(nullptr, "Both team captains have requested the tournament be restarted. All players must rejoin the server.", "TMCenter");
	Level.Game.TournamentRequestResetTournament();
	*/
}

void AHumanController::Suicide()
{
	/*
		if (Level.GetTourIsTraining(Level.iTour))
		{
			ConsoleCommand("Reconnect");
			return;
		}
		if (TournamentIsTournament() && GameReplicationInfo.bTournamentInWarmup)
		{
			TournamentTryToSuicidePlayer();
			return;
		}
		if (Cast<AVehicle>(Pawn) != nullptr && VSize(Pawn.Velocity) > NoSuicideVelocity)
		{
			ClientMessage("You cannot commit suicide while the vehicle is moving.");
		}
		else
		{
			Suicide();
		}
	*/
}
void AHumanController::TournamentClientRunSuicide()
{
	/*
		if (Pawn != nullptr && GetWorld()->GetTimeSeconds() - Pawn.LastStartTime > 1)
		{
			if (Cast<AVehicle>(Pawn) != nullptr && Vehicle(Pawn).Driver != nullptr)
			{
				Vehicle(Pawn).Driver.KilledBy(Cast<AVehicle>(Pawn).Driver);
			}
			else
			{
				Pawn.KilledBy(Pawn);
			}
		}
	*/
}

void AHumanController::TournamentTryToSuicidePlayer()
{
	AController* ctrlrScan = nullptr;
	AHumanController* hcScan = nullptr;
	int32 iLivePlayersOnPlayersTeam = 0;
	if (PlayerReplicationInfo->Team->TeamIndex == 255)
	{
		return;
	}
	iLivePlayersOnPlayersTeam = 0;
	/*
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		hcScan = Cast<AHumanController>(ctrlrScan);
		if ((hcScan == nullptr) || (hcScan.Pawn == nullptr))
		{
		}
		if ((!hcScan.Pawn.isDead()) && (hcScan.PlayerReplicationInfo->Team->TeamIndex == PlayerReplicationInfo->Team->TeamIndex))
		{
			iLivePlayersOnPlayersTeam++;
		}
	}
	if (iLivePlayersOnPlayersTeam > 1)
	{
		DebugLog(DEBUG_Tournament, "Just killing player");
		TournamentClientRunSuicide();
	}
	else
	{
		DebugLog(DEBUG_Tournament, "Ending Mission Planning period.");
		for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
		{
			hcScan = Cast<AHumanController>(ctrlrScan);
			if (hcScan == nullptr)
			{
			}
			if ((hcScan.MyHUD != nullptr) && (Cast<AAGP_HUD>(hcScan.MyHUD) != nullptr))
			{
				Cast<AAGP_HUD>(hcScan.MyHUD).DisplayCenteredMessage(4, "Mission Planning Period ending because all players on one team have killed themselves.");
			}
		}
		Level.Game.TournamentEndCurrentRound();
	}
	*/
}

void AHumanController::TournamentTeamList(int32 iTeam)
{
	AController* ctrlrScan = nullptr;
	APlayerController* PC = nullptr;
	ClientMessage("* indicates Team Captain");
	ClientMessage("");
	/*
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan->nextController)
	{
		PC = Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (PC.PlayerReplicationInfo->Team->TeamIndex == iTeam)
		{
			if (ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				ClientMessage("*" + ctrlrScan.PlayerReplicationInfo.PlayerName);
			}
			else
			{
				ClientMessage(ctrlrScan.PlayerReplicationInfo.PlayerName);
			}
		}
	}
	*/
	ClientMessage("-------------------------------------");
	//ClientMessage(GameReplicationInfo.asTournamentTeamName[iTeam] + " Team Roster");

}
void AHumanController::TournamentOpenResultsFile(FString sBaseFileName, FString Message)
{
	/*
		FString sFileName;
		sFileName=GetBaseDir() + "\..\TournamentResults\";
		CreateDir(sFileName);
		sFileName=sFileName + sBaseFileName;
		if (Message != "")
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(10,"The tournament has ended " + Message + ".","Tournament results saved to """ + sBaseFileName + """.");
				ClientMessage("Tournament has ended " + Message + ". Tournament results saved in your ""TournamentResults"" folder as """ + sBaseFileName + """.");
			}
		}
		else
		{
			if (Cast<AAGP_HUD>(MyHUD) != nullptr)
			{
				Cast<AAGP_HUD>(MyHUD)->DisplayCenteredMessage(10,"The tournament has ended.","Tournament results saved to """ + sBaseFileName + """.");
				ClientMessage("Tournament has ended.  Tournament results saved in the ""TournamentResults"" folder as """ + sBaseFileName + """.");
			}
		}
		FOpenWrite(sFileName);
	*/
}
void AHumanController::TournamentWriteResultsFile(FString sTournamentResults)
{
	/*
		if (Len(sTournamentResults) == 0)
		{
			return;
		}
		FWrite(sTournamentResults);
	*/
}
void AHumanController::TournamentCloseResultsFile()
{
	//FClose();
}
void AHumanController::TMAssignClass(int32 iUnitID, int32 iSlot, FString sPlayerName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can assign classes.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && TournamentIsTeamRosterLocked(PlayerReplicationInfo->Team->TeamIndex))
		{
			ClientMessage("The Roster is currently locked.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.PlayerName != sPlayerName)
		{
			ClientMessage("You can only assign yourself.");
			return;
		}
		if (! TournamentAssignClass(sPlayerName,iUnitID,iSlot))
		{
			ScreenPrint("Proper syntax: TMAssignClass [PlayerName] [UnitID 0=SL, 1 = FT Alpha, 2 = FT Bravo, ...] [Slot: 0 = FTL, 1 = Member]");
		}
	*/
}
void AHumanController::TMRemoveClass(int32 iUnitID, int32 iSlot, FString sPlayerName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can remove classes.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && TournamentIsTeamRosterLocked(PlayerReplicationInfo->Team->TeamIndex))
		{
			ClientMessage("The Roster is currently locked.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin && PlayerReplicationInfo.PlayerName != sPlayerName)
		{
			ClientMessage("You can only remove yourself.");
			return;
		}
		if (! TournamentRemoveClass(sPlayerName,iUnitID,iSlot))
		{
			ScreenPrint("Proper syntax: TMRemoveClass [PlayerName] [UnitID 0=SL, 1 = FT Alpha, 2 = FT Bravo, ...] [Slot: 0 = FTL, 1 = Member]");
		}
	*/
}
void AHumanController::TMSetTeamName(int32 iTeam, FString sTeamName)
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can set team names.");
			return;
		}
		if (iTeam > 1 || iTeam < 0 || Len(sTeamName) == 0)
		{
			ClientMessage("Invalid team index, syntax: TestTournamentSetTeamName [0/1] [TeamName]");
			return;
		}
		TournamentSetTeamName(iTeam,sTeamName);
	*/
}
void AHumanController::TMTeamList(int32 iTeam)
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	TournamentTeamList(iTeam);
}
void AHumanController::TMTeamReady()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains can signal ready.");
			return;
		}
		TournamentTeamReady();
	*/

}
void AHumanController::TMAdminReady()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Admins can signal both teams ready.");
			return;
		}
		TournamentAdminReady();
	*/
}
void AHumanController::TMRequestTeamCaptain()
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	//TournamentRequestTeamCaptain(PlayerReplicationInfo);
}
void AHumanController::TMJoinTeam(int32 iTeam, FString sPassword)
{
	if (! TournamentIsTournament())
	{
		ClientMessage("Not in tournament mode.");
		return;
	}
	TournamentJoinTeam(iTeam,sPassword);
}
void AHumanController::TMPauseTournament()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can pause.");
			return;
		}
		TournamentRequestPause(PlayerReplicationInfo);
	*/
}
void AHumanController::TMResume()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can resume.");
			return;
		}
		TMTeamReady();
	*/
}
void AHumanController::TMSwapSides()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can swap sides.");
			return;
		}
		TournamentRequestSwapSides();
	*/
}
void AHumanController::TMRestartMatch()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart a match.");
			return;
		}
		TournamentRestartMatch();
	*/
}
void AHumanController::TMRestartTournament()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart tournaments.");
			return;
		}
		TournamentRestartTournament();
	*/
}
void AHumanController::TMRestartMatchWithMissionPlanning()
{
	/*
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		if (! PlayerReplicationInfo.bTournamentTeamCaptain && ! PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("Only Team Captains or Administrators can restart with mission planning.");
			return;
		}
		TournamentRequestStartWarmup();
	*/
}
void AHumanController::TMHelp()
{
	
		if (! TournamentIsTournament())
		{
			ClientMessage("Not in tournament mode.");
			return;
		}
		ClientMessage("");
		ClientMessage("TMAssignClass [FireTeam] [Slot] [PlayerName/PlayerId](fireteam 0 = Squad Leader, 1 - 4 fireteams)");
		ClientMessage("TMJoinTeam [Team index] Password (this will join the team if the password is correct)");
		ClientMessage("TMSwapSides (this will request swapping sides at end of current round)");
		ClientMessage("TMPauseTournament (this will pause the tournament at end of current round)");
		ClientMessage("TMRequestTeamCaptain (this will request that you be made team captain)");
		ClientMessage("TMTeamReady true/false (this will signal your team is ready to continue)");
		ClientMessage("TMSetTeamName [Team index] Name  (this will set the specified team's name)");
		ClientMessage("TMTeamList [Team index] (displays team members, captain with asterisk)");
		ClientMessage("TMRestartMatch - Restart tournament match play (scores only reset - requires both team captains to agree)");
		ClientMessage("TMRestartMatchWithMissionPlanning - Restart tournament match play (scores only reset, mission planning round played - requires both team captains to agree)");
		ClientMessage("TMRestartTournament - Restart tournament (rosters and scores reset - requires both team captains to agree)");
		ClientMessage("");
		ClientMessage("------------------------------------------------------");
		ClientMessage("Comments are included in parenthesis after parameters)");
		ClientMessage("Spaces are not allowed in team or player names (replace spaces with underscores)");
		ClientMessage("TeamID fields use 0 for Team 0 and 1 for Team 1");
		ClientMessage("Available Tournament Related Commands:");
		/*
		if (PlayerReplicationInfo.bAdmin)
		{
			ClientMessage("");
			ClientMessage("TMRestartMatch - Admin wants to restart tournament match play (scores only reset)");
			ClientMessage("TMRestartTournament - Admin wants to restart tournament (rosters and scores reset, players rejoin server)");
			ClientMessage("TMAdminReady - Admin is ready to continue tournament");
			ClientMessage("TMResume - Admin is resuming match immediately from pause or swap mode");
			ClientMessage("--------------------");
			ClientMessage("Tournament Admin-Only Commands:");
		}
		*/
	
}
void AHumanController::RunServer(FString ServerExecutable, FString ServerType, FString MapName, FString LogFile, FString INIfile, bool bShutDown)
{
	/*
		FString FullURL;
		if (ServerExecutable == "")
		{
			ServerExecutable="server";
		}
		else
		{
			if (InStr(ServerExecutable,".exe") == -1)
			{
				ServerExecutable=ServerExecutable;
			}
		}
		if (ServerType == "")
		{
			ServerType="lan";
		}
		if (MapName == "")
		{
			MapName="MOUT_McKenna.aao";
		}
		else
		{
			if (InStr(MapName,".aao") == -1)
			{
				MapName=MapName + ".aao";
			}
		}
		if (LogFile == "")
		{
			LogFile="server.log";
		}
		else
		{
			if (InStr(LogFile,".log") == -1)
			{
				LogFile=LogFile + ".log";
			}
		}
		if (INIfile == "")
		{
			INIfile="server.ini";
		}
		else
		{
			if (InStr(INIfile,".ini") == -1)
			{
				INIfile=INIfile + ".ini";
			}
		}
		FullURL=ServerType @ MapName @ "log=" + LogFile @ "ini=" + INIfile;
		ConsoleCommand("launchserver" @ FullURL);
	*/
}
int32 AHumanController::NumSupportStrikesAvailable()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return (S->StrikesAvailable);
	}
	return 0;
}
int32 AHumanController::SupportArrivalTime()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return (S->ArrivalTime);
	}
	return 0;
}
bool AHumanController::IsSupportAvailable()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return S->bAvailable;
	}
	return false;
}
bool AHumanController::IsSupportReady()
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != NULL)
	{
		return S->bReady;
	}
	return false;
}
bool AHumanController::IsSupportFiring()
{
	
		ACallForSupport* S;
		S=GetSupport();
		if (S != NULL)
		{
			return S->bFiring;
		}
		return false;
	
}
ACallForSupport* AHumanController::GetSupport()
{
	/*
		ACallForSupport* S;
		ForEach DynamicActors('CallForSupport',S)
		{
			if (S.TeamNumber == PlayerReplicationInfo->Team->TeamIndex)
			{
				return S;
			}
		}
		*/
		return nullptr;
}

void AHumanController::RequestForSupport()
{
}

void AHumanController::ConfirmReqestForSupport()
{
}

bool AHumanController::CanCallForSupport()
{
		AAGP_Pawn* p;
		AAGP_Weapon* W;
		p = Cast<AAGP_Pawn>(GetPawn());
		if (p != nullptr)
		{
			W=Cast<AAGP_Weapon>(p->Weapon);
		}
		/*
		if (W != nullptr && W->IsA('Item_VIPER') && W->IsInState('LockedOn') && W->IsZoomed())
		{
			return true;
		}
		return false;
		*/
	return false;
}
void AHumanController::CallForSupport(FVector StrikeLocation, FVector StrikeNormal)
{
	ACallForSupport* S;
	if (!CanCallForSupport())
	{
		return;
	}
	S=GetSupport();
	if (S != nullptr)
	{
		if (S->bReady)
		{
		}
		if (S->bAvailable)
		{
			ReportIn();
		}
	}
	ServerCallForSupport(StrikeLocation,StrikeNormal);
}
void AHumanController::ServerCallForSupport(FVector StrikeLocation, FVector StrikeNormal)
{
	ACallForSupport* S;
	S=GetSupport();
	if (S != nullptr)
	{
		S->CheckMark(GetPawn(),StrikeLocation,true);
		S->CallForSupport(this);
	}
}
void AHumanController::SetScopeDetailLevel(FString S)
{
	S = S.ToUpper();
	if (S.FString::Contains("UltraLow", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
	{
		S = "SCOPEDETAIL_VeryLow";
	}
	else
	{
		if (S.FString::Contains("VeryLow", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
		{
			S = "SCOPEDETAIL_VeryLow";
		}
		else
		{
			if (S.FString::Contains("Low", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
			{
				S = "SCOPEDETAIL_Low";
			}
			else
			{
				if (S.FString::Contains("Lower", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
				{
					S = "SCOPEDETAIL_Low";
				}
				else
				{
					if (S.FString::Contains("Normal", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
					{
						S = "SCOPEDETAIL_Normal";
					}
					else
					{
						if (S.FString::Contains("Higher", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
						{
							S = "SCOPEDETAIL_High";
						}
						else
						{	
							if (S.FString::Contains("High", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
							{
								S = "SCOPEDETAIL_High";
							}
							else
							{
								if (S.FString::Contains("VeryHigh", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
								{
									S = "SCOPEDETAIL_High";
								}
								else
								{
									if (S.FString::Contains("UltraHigh", ESearchCase::IgnoreCase, ESearchDir::FromEnd))
									{
										S = "SCOPEDETAIL_High";
									}
									else
									{
										S = "SCOPEDETAIL_High";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	SetScopeDetail(S);
}
FString AHumanController::GetScopeDetailLevel()
{
	if (ScopeDetail == EScopeDetail::SCOPEDETAIL_VeryLow)
	{
		return "VeryLow";
	}
	else
	{
		if (ScopeDetail == EScopeDetail::SCOPEDETAIL_Low)
		{
			return "Low";
		}
		else
		{
			if (ScopeDetail == EScopeDetail::SCOPEDETAIL_Normal)
			{
				return "Normal";
			}
			else
			{
				if (ScopeDetail == EScopeDetail::SCOPEDETAIL_High)
				{
					return "High";
				}
				else
				{
					return "High";
				}
			}
		}
	}
}
void AHumanController::SetScopeDetail(FString S)
{
	if (S == "SCOPEDETAIL_VeryLow")
	{
		ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_VeryLow);
	}
	else
	{
		if (S == "SCOPEDETAIL_Low")
		{
			ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_Low);
		}
		else
		{
			if (S == "SCOPEDETAIL_Normal")
			{
				ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_Normal);
			}
			else
			{
				if (S == "SCOPEDETAIL_High")
				{
					ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_High);
				}
				else
				{
					ServerSetScopeDetail(EScopeDetail::SCOPEDETAIL_High);
				}
			}
		}
	}
}

EScopeDetail AHumanController::GetScopeDetail()
{
	return ScopeDetail;
}

void AHumanController::ServerSetScopeDetail(EScopeDetail newDetail)
{
	ScopeDetail=newDetail;
}

bool AHumanController::NeedNetNotify()
{
	//return Super::NeedNetNotify() || bWaitingForPRI || bVoiceChatEnabled && bWaitingForVRI;
	return bWaitingForPRI || bVoiceChatEnabled && bWaitingForVRI;
}

void AHumanController::RunInputCommand(FString Cmd)
{
}
void AHumanController::LoadSRGrammar(FString Grammar)
{
}

bool AHumanController::LoadSRBinds(FString Filename, FString OutFilename)
{
	return false;    //FAKE   /ELiZ
}

void AHumanController::SaveSRBinds(FString Filename)
{
}

FString AHumanController::GetSRBind(FString Alias)
{
	return "FAKE";   //FAKE   /ELiZ
}

bool AHumanController::SetSRBind(FString Alias, FString BindPhrase)
{
	return false;    //FAKE   /ELiZ
}

void AHumanController::SetGrammar()
{
	/*
	if (! LoadSRBinds("aaspeech"))
	{
		LoadSRBinds("default","aaspeech");
		SaveSRBinds();
	}
	*/
	LoadSRGrammar("aaspeech");
}
void AHumanController::ResetGrammar()
{
	LoadSRBinds("default","aaspeech");
}
void AHumanController::VoiceCommand(FString RecognizedString, FString RawString)
{
	/*
		FString Command;
		FString argument;
		FString ParseString;
		FString BitBucket;
		FString tmp;
		UE_LOG(LogTemp, Warning, TEXT("Speech Rec: Recognized Commands = " + RecognizedString));
		UE_LOG(LogTemp, Warning, TEXT("Speech Rex: Raw = " + RecognizedString));
		if (! Divide(RecognizedString," ",Command,ParseString))
		{
			Command=RecognizedString;
		}
		if (Command != "")
		{
			switch(Command)
			{
				case "TEAMSAY":
				case "SAY":
				tmp=GetSRBind(Command);
				if (tmp != "")
				{
					Divide(RawString,tmp,BitBucket,argument);
					ConsoleCommand(Command + argument);
				}
				break;
				default:
				RunInputCommand(Command);
			}
			if (! Divide(ParseString," ",Command,ParseString))
			{
				Command=ParseString;
			}
		}
	*/
}

void AHumanController::PostNetReceive()
{
	/*
		PostNetReceive();
		if (PlayerReplicationInfo != nullptr && bWaitingForPRI)
		{
			bWaitingForPRI=false;
			if (bAutoDemoRec && GetNetMode() == ENetMode::NM_Client && ! bDemoOwner)
			{
				Player.Console.DelayedConsoleCommand("demorec");
			}
		}
		if (VoiceReplicationInfo != nullptr && bWaitingForVRI)
		{
			if (PlayerReplicationInfo != nullptr && ! PlayerReplicationInfo.NeedNetNotify())
			{
				bWaitingForVRI=VoiceReplicationInfo.GetPublicChannelCount(true) == 0;
				if (! bWaitingForVRI)
				{
					VoiceReplicationInfo.SetOwner(this);
					if (bVoiceChatEnabled)
					{
						InitializeVoiceChat();
					}
					else
					{
						DisableVoiceChat();
					}
				}
			}
		}
		bNetNotify=NeedNetNotify();
	*/
}
void AHumanController::AutoJoinVoiceChat()
{
	/*
		int32 i = 0;
		int32 j = 0;
		int32 cnt;
		FString DefaultChannel;
		if (! bVoiceChatEnabled || GetNetMode() != ENetMode::NM_Client && GetNetMode() != ENetMode::NM_ListenServer)
		{
			return;
		}
		if (VoiceReplicationInfo == nullptr)
		{
			return;
		}
		cnt=VoiceReplicationInfo.GetPublicChannelCount(true);
		for (i=0; i<cnt; i++)
		{
			if (AutoJoinMask & 1 << i)
			{
				Join(VoiceReplicationInfo.PublicChannelNames[i],"");
				for (j=RejoinChannels.Num()-1; j>=0; j--)
				{
					if (RejoinChannels[j] == VoiceReplicationInfo.PublicChannelNames[i])
					{
						RejoinChannels->Remove(j,1);
					}
				}
			}
		}
		for (i=0; i<RejoinChannels.Num(); i++)
		{
			Join(RejoinChannels[i],"");
		}
		if (LastActiveChannel != "")
		{
			Speak(LastActiveChannel);
		}
		else
		{
			if (ActiveRoom == nullptr && bEnableInitialChatRoom)
			{
				DefaultChannel=GetDefaultActiveChannel();
				if (DefaultChannel != "")
				{
					Speak(DefaultChannel);
				}
			}
		}
		if (RejoinChannels.Num() > 0 || LastActiveChannel != "")
		{
			RejoinChannels.Num()=0;
			LastActiveChannel="";
			SaveConfig();
		}
	*/
}
void AHumanController::ServerChatDebug()
{
}
void AHumanController::MatchStarting()
{
	//bLastHealSelfAction=false;
	bHealSelfAction=0;

	//ServerUpdateSelfHealActionState(false);
	ChangeActionStatus(0);
	if (! PlayerReplicationInfo->bAdmin && ! PlayerReplicationInfo->IsOnlyASpectator())
	{
		//ClientSetBehindView(false);
	}
	ClientCloseMenu(false,false);
	
}
void AHumanController::MatchEnding()
{
	//ClientSetBehindView(false);
	IdleCheckPerRound(true);
	//CleanOutSavedMoves();
}
int32 AHumanController::CalculateUserNameChecksum(FString sUserName)
{
	
		int32 i = 0;
		int32 iTempValue = 0;
		int32 iChecksum = 0;
	/*
		ReplaceText(sUserName," ","_");
		sUserName=Locs(sUserName);
		for (i=0; i<Len(sUserName); i++)
		{
			iTempValue=Asc(Mid(sUserName,i,1));
			iChecksum += iTempValue * i + 1;
		}
	*/
	return iChecksum;
}

FString AHumanController::strip(FString str, int32 atleast)
{
	/*
		str=Mid(str,atleast);
		if (Left(str,1) == " ")
		{
			str=strip(str,1);
		}
	*/
	return str;
}

bool AHumanController::IsArgument(FString S, FString argument, FString& Option)
{
	/*
	int32 L;
	L=Len(argument);
	if (Left(S,L) ~= argument)
	{
		Option=strip(S,L);
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;
}

void AHumanController::MPCheat(FString cheat)
{
	/*
		FString Option;
		if (_CheatMonitor != nullptr)
		{
			_CheatMonitor.Notify();
		}
		if (EventLab != nullptr)
		{
			Log("Test");
			EventLab.EventLabNotifyCheat();
		}
		if (Level.Game.CheatsDisabled())
		{
			return;
		}
		if (Level.Game.GetScreenplay() != nullptr)
		{
			Level.Game.GetScreenplay().NotifyCheated();
		}
		cheat=Caps(cheat);
		if (Left(cheat,6) == "SILENT")
		{
			cheat=strip(cheat,6);
		}
		else
		{
			Level.Game.Broadcast(this,"Activated a multiplayer cheat: " + cheat,'cheat');
		}
		if (IsArgument(cheat,"GHOST"))
		{
			MPCheat_EnterGhostMode();
		}
		else
		{
			if (IsArgument(cheat,"WALK"))
			{
				MPCheat_Walk();
			}
			else
			{
				if (IsArgument(cheat,"GOD"))
				{
					MPCheat_God();
				}
				else
				{
					if (IsArgument(cheat,"SUPERGOD"))
					{
						MPCheat_SuperGod();
					}
					else
					{
						if (IsArgument(cheat,"ENDGAME"))
						{
							MPCheat_EndGame();
						}
						else
						{
							if (IsArgument(cheat,"FLOOD"))
							{
								MPCheat_Flood();
							}
							else
							{
								if (IsArgument(cheat,"NVG"))
								{
									MPCheat_NVG();
								}
								else
								{
									if (IsArgument(cheat,"ACTORLIST"))
									{
										MPCheat_ActorList();
									}
									else
									{
										if (IsArgument(cheat,"DACTORLIST"))
										{
											MPCheat_DActorList();
										}
										else
										{
											if (IsArgument(cheat,"BINOC",Option))
											{
												MPCheat_Binoc(Option);
											}
											else
											{
												if (IsArgument(cheat,"MEDIC",Option))
												{
													MPCheat_Medic(Option);
												}
												else
												{
													if (IsArgument(cheat,"PAUSE",Option))
													{
														MPCheat_Pause(Option);
													}
													else
													{
														if (IsArgument(cheat,"SLOMO",Option))
														{
															MPCheat_Slomo(Option);
														}
														else
														{
															if (IsArgument(cheat,"FREECAMERA",Option))
															{
																MPCheat_FreeCamera(Option);
															}
															else
															{
																if (IsArgument(cheat,"BEHINDVIEW",Option))
																{
																	MPCheat_Behindview(Option);
																}
																else
																{
																	if (IsArgument(cheat,"CHANGECLASS",Option))
																	{
																		MPCheat_ChangeClass(Option);
																	}
																	else
																	{
																		if (IsArgument(cheat,"CLASS",Option))
																		{
																			MPCheat_ChangeClass(Option);
																		}
																		else
																		{
																			if (IsArgument(cheat,"PARAMS",Option))
																			{
																				MPCheat_Params(Option);
																			}
																			else
																			{
																				if (IsArgument(cheat,"PLAYERLOCK",Option))
																				{
																					MPCheat_PlayerLock(Option);
																				}
																				else
																				{
																					if (IsArgument(cheat,"SCENEJUMP",Option))
																					{
																						MPCheat_SceneJump(Option);
																					}
																					else
																					{
																						if (IsArgument(cheat,"FOV",Option))
																						{
																							MPCheat_FOV(Option);
																						}
																						else
																						{
																							UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat()	Unknown Cheat " + cheat,true));
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
void AHumanController::MPCheat_FOV(float F)
{
	DesiredFOV = FMath::Clamp(F, 1.0f, 170.0f);
}
void AHumanController::MPCheat_ActorList()
{
}
void AHumanController::MPCheat_DActorList()
{
}
void AHumanController::MPCheat_FreeCamera(bool B)
{
	bFreeCamera = B;
	bBehindView = B;
	//ClientSetBehindView(B, true);
}
void AHumanController::MPCheat_Behindview(bool B)
{
	bBehindView = B;
	//ClientSetBehindView(B, false);
}
void AHumanController::MPCheat_PlayerLock(bool B)
{
	//LockPlayer(B,B);
}
void AHumanController::MPCheat_SceneJump(FString SceneName)
{
	/*
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().SceneJump(SceneName);
	}
	*/
}
void AHumanController::MPCheat_Params(FString Params)
{

	/*
		FString Option;
		if (IsArgument(Params,"DEADGAME",Option))
		{
			AGP_GameInfo(GetGameMode()).bDeadGame=Option;
		}
		else
		{
			if (IsArgument(Params,"NOINV",Option))
			{
				AGP_GameInfo(GetGameMode()).bNoInventory=Option;
			}
			else
			{
				if (IsArgument(Params,"NOFADE",Option))
				{
					bCheatNoFade=Option;
				}
				else
				{
					if (IsArgument(Params,"VERBOSE",Option))
					{
						bCheatVerbose=Option;
					}
					else
					{
						if (IsArgument(Params,"SWAP",Option))
						{
							bDebugSwapPickups=Option;
						}
						else
						{
							if (IsArgument(Params,"AIM",Option))
							{
								bPerfectAccuracy=Option;
							}
							else
							{
								if (IsArgument(Params,"AMMO",Option))
								{
									bUnlimitedAmmo=Option;
								}
								else
								{
									if (IsArgument(Params,"PENALTY",Option))
									{
										bNoWeaponPenalty=Option;
									}
									else
									{
										if (IsArgument(Params,"NATIVE",Option))
										{
											bNativeBonus=Option;
										}
										else
										{
											UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat_Params() Unknown parameters " + Params,True));
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
void AHumanController::MPCheat_Slomo(float t)
{
	/*
		if (t == 0)
		{
			return;
		}
		Level.Game.SetGameSpeed(t);
		Level.Game.SaveConfig();
		Level.Game.GameReplicationInfo.SaveConfig();
	*/
}

void AHumanController::MPCheat_Pause(bool bPause)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Level.Game.PauseGame(bPause,this);
	}
	*/
}

void AHumanController::MPCheat_EndGame()
{
	//Level.Game.EndGame(PlayerReplicationInfo,"CheatEndGame");
}

void AHumanController::MPCheat_Flood()
{
	yFloodCount = 255;
}

void AHumanController::MPCheat_NVG()
{
	AAGP_Pawn* myPawn = nullptr;
	/*
	myPawn = Cast<AAGP_Pawn>(GetPawn());
	if (myPawn != nullptr && myPawn._OpticsDevice == nullptr)
	{
		myPawn._OpticsDevice = Spawn(class<BaseOptics>(DynamicLoadObject("AGP_Inventory.NightOpticsDevice", Class'Class')), myPawn);
		myPawn._OpticsDevice.DoAttachStuffWhichShouldBeDoneInInventory();
	}
	*/
}

void AHumanController::MPCheat_Binoc(uint8 new_binoc)
{
	/*
		if (Pawn != nullptr)
		{
			switch(new_binoc)
			{
				case 0:
				if (Pawn._InvBinoculars == 0)
				{
					Pawn._InvBinoculars=1;
					break;
				}
				Pawn._InvBinoculars=0;
			}
			case 1:
			case 2:
			case 3:
			case 4:
			Pawn._InvBinoculars=new_binoc;
			default:
			ClientMessage("[0=No binocs] [1=M22] [2=M22] [3=Tanker] [4=Newtonian]");
		}
	*/
}
void AHumanController::MPCheat_Medic(int32 new_num_med)
{
	/*
		if (Pawn != nullptr)
		{
			if (new_num_med == 0)
			{
				new_num_med=3;
			}
			Pawn._InvMedPacks=new_num_med;
		}
	*/
}
void AHumanController::MPCheat_SuperGod()
{
		bSuperGodMode=! bSuperGodMode;
		bGodMode=bSuperGodMode;
		if (bSuperGodMode)
		{
			ClientMessage("MultiPlayer SuperGod Mode is on!");
		}
		else
		{
			ClientMessage("MultiPlayer SuperGod Mode is off.");
		}
}
void AHumanController::MPCheat_God()
{
	bGodMode=! bGodMode;
	if (bGodMode)
	{
		ClientMessage("MultiPlayer God Mode is on!");
	}
	else
	{
		bSuperGodMode=false;
		ClientMessage("MultiPlayer God Mode is off.");
	}
}
void AHumanController::MPCheat_EnterGhostMode()
{
	/*
	Pawn.UnderWaterTime = -1;
	ClientMessage("MultiPlayer Ghost Mode!");
	Pawn.SetCollision(false, false, false);
	Pawn.bCollideWorld = false;
	bCheatFlying = true;
	ChangeState("PlayerFlying");
	*/
}
void AHumanController::MPCheat_Walk()
{
	/*
		Pawn.UnderWaterTime=0;
		ClientMessage("Walk Mode Restored");
		Pawn.SetCollision(true,True,true);
		Pawn.bCollideWorld=true;
		bCheatFlying=false;
		ChangeState("PlayerWalking");
	*/
}

void AHumanController::newTeamClass(ASoldierClass*  sclass)
{
	ASoldierClass* LastClass = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("newTeamClass(" + sclass + ")"));
	if (Role < 4)
	{
		return;
	}
	if (sclass == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Received null new team class."));
		return;
	}
	if (Pawn == nullptr)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		LastClass=Cast<AAGP_Pawn>(GetPawn()).TeamClass;
	}
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn()).TeamClass=Spawn(sclass,Cast<AAGP_Pawn>(GetPawn()));
		UE_LOG(LogTemp, Warning, TEXT("AGP:Cheater::newTeamClass() Spawned " + Cast<AAGP_Pawn>(GetPawn()).TeamClass));
		Cast<AAGP_Pawn>(GetPawn()).TeamClass.adjustAttributes(LastClass);
		Cast<AAGP_Pawn>(GetPawn()).EmptyInventory(true);
		Cast<AAGP_Pawn>(GetPawn()).TeamClass.addClassInventory(true);
		Cast<AAGP_Pawn>(GetPawn()).TeamClass.addTeamInventory();
	}
	if (Level.Game != nullptr && Level.Game->IsA(AAGP_GameInfo::StaticClass()))
	{
		if (Cast<AAGP_GameInfo>(GetGameMode()).IsClassLegal(sclass))
		{
			PlayerReplicationInfo.sCurrentWeaponClass="" + sclass;
			DesiredTeamClass=sclass;
		}
	}
	else
	{
		DesiredTeamClass=sclass;
	}
	LastClass.Destroy();
	*/
}

void AHumanController::MPCheat_ChangeClass(FString ClassName)
{
	ASoldierClass* sclass = nullptr;
	FString sclass_name = "";
	/*
	if (Pawn == nullptr)
	{
		return;
	}
	if (Level.sLevelName ~= "entry" || Level.sLevelName ~= "entry2")
	{
		return;
	}
	LockPlayer(false,false);
	switch(ClassName)
	{
		case "":
			ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, RPG9");
			return;
		case "M":
		case "M4A1":
			sclass_name="AGP_Characters.ClassRiflemanM4A1AutoIron";
			break;
		case "MA":
		case "M4A1Auto":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Auto";
			break;
		case "AR":
		case "AutomaticRifleman":
			sclass_name="AGP_Characters.ClassAutomaticRifleman";
			break;
		case "R":
		case "Rifleman":
			sclass_name="AGP_Characters.ClassRifleman";
			break;
		case "RCT":
		case "Recruit":
			sclass_name="AGP_Characters.ClassRecruit";
			break;
		case "AK":
		case "RiflemanAK":
			sclass_name="AGP_Characters.ClassRiflemanAK";
			break;
		case "AK74SU":
			sclass_name="AGP_Characters.ClassRiflemanAK74SU";
			break;
		case "AK74suReflex":
			sclass_name="AGP_Characters.ClassGuerrillaAK74suReflex";
			break;
		case "RPK":
			sclass_name="AGP_Characters.ClassAutomaticRiflemanRPK";
			break;
		case "M4M":
			sclass_name="AGP_Characters.ClassRiflemanM4A1Mod";
			break;
		case "G":
		case "Grenadier":
			sclass_name="AGP_Characters.ClassGrenadier";
			break;
		case "GP":
			sclass_name="AGP_Characters.ClassGrenadierGP30_Op";
			break;
		case "Mos":
			sclass_name="AGP_Characters.ClassSniperMos";
			break;
		case "S":
		case "S82":
		case "Sniper":
		case "Sniper82":
			sclass_name="AGP_Characters.ClassSniper";
			break;
		case "S24":
		case "Sniper24":
			sclass_name="AGP_Characters.ClassSniper24_US";
			break;
		case "SVD":
			sclass_name="AGP_Characters.ClassSniperSVD";
			break;
		case "RPG":
			sclass_name="AGP_Characters.ClassRPG";
			break;
		case "AT4":
			sclass_name="AGP_Characters.ClassAT4Rocket";
			break;
		case "BDM":
			sclass_name="AGP_Characters.ClassBDMRocket";
			break;
		case "M9":
			sclass_name="AGP_Characters.ClassPistol";
			break;
		case "SF":
			sclass_name="AGP_Characters.ClassSF";
			break;
		case "SFSniper":
		case "SPR":
			sclass_name="AGP_Characters.ClassSFSniper";
			break;
		case "PSO":
		case "GuerrillaPSO":
			sclass_name="AGP_Characters.ClassGuerrillaPSO";
			break;
		case "V":
		case "VSS":
		case "GuerrillaSniper":
			sclass_name="AGP_Characters.ClassGuerrillaSniper";
			break;
		case "GuerrillaAK47su":
			sclass_name="AGP_Characters.ClassGuerrillaAK47su";
			break;
		case "GuerrillaRPG":
			sclass_name="AGP_Characters.ClassGuerrillaRPG";
			break;
		case "GuerrillaRPK":
			sclass_name="AGP_Characters.ClassGuerrillaRPK";
			break;
		case "D":
			sclass_name="AGP_Characters.ClassDemolitions";
			break;
		case "J":
			sclass_name="AGP_Characters.ClassJavelin";
			break;
		case "JT":
			sclass_name="AGP_Characters.ClassJavelinTube";
			break;
		case "RPG9":
			sclass_name="AGP_Characters.ClassGuerrillaRPGNine";
			break;
		default:
			ScreenPrint("Unrecognized class " + ClassName);
			ScreenPrint("Type ""Class X"" where classes are M4A1, M4A1Auto, AR, R, RCT, AK, AK74SU, RPK, M4M, G, GP, S, S82, S24, SVD, RPG, AT4, BDM, M9, SF, SPR, PSO, V, D, J, JT, RPG9");
			return;
	}
	CleanUp();
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn()).bForcedWeaponChange=true;
	}
	sclass=class<SoldierClass>(DynamicLoadObject(sclass_name,Class'Class'));
	newTeamClass(sclass);
	UE_LOG(LogTemp, Warning, TEXT("HumanController::MPCheat_ChangeClass() " @ Cast<AAGP_Pawn>(GetPawn()).TeamClass));
	*/
}
void AHumanController::ELCheat(FString cheat)
{
	/*
		if (EventLab != nullptr)
		{
			Log("ELCheat TEST");
			EventLab.ActorNotify(this,30,,cheat);
		}
	*/
}

void AHumanController::addDebug(EDebugTag Debug)
{
}

void AHumanController::removeDebug(EDebugTag Debug)
{
}

void AHumanController::toggleDebug(EDebugTag Debug)
{
}

void AHumanController::SToggleDebug(EDebugTag Debug)
{
}

void AHumanController::ServerToggleDebug(EDebugTag Debug)
{
}

void AHumanController::AIDebug()
{
}

void AHumanController::AimDebug()
{
}

void AHumanController::RecoilDebug()
{
}

void AHumanController::FireModeDebug()
{
}

void AHumanController::PostureDebug()
{
}
void AHumanController::GrenadeDebug()
{
}
void AHumanController::MantleDebug()
{
}
void AHumanController::ZoomDebug()
{
}
void AHumanController::HumanAccuracy()
{
}
void AHumanController::TracerDebug()
{
}
void AHumanController::ParachuteDebug()
{
}
void AHumanController::ScreenplayDebug()
{
}
void AHumanController::FallingDebug()
{
}
void AHumanController::MisfireDebug()
{
}
void AHumanController::WeaponStateDebug()
{
}
void AHumanController::PawnStateDebug()
{
}
void AHumanController::ControllerStateDebug()
{
}
void AHumanController::WeaponAccDebug()
{
}

void AHumanController::InventoryDebug()
{
}

void AHumanController::AGPHUD(bool B)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowHUD=B;
	}
}

void AHumanController::HideObjectives()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowObjectives=!Cast<AAGP_HUD>(MyHUD)->bShowObjectives;
	}
}

void AHumanController::ToggleObjectiveDisplay()
{
	AAGP_HUD* A_HUD = nullptr;
	AGameReplicationInfo* GRI = nullptr;
	/*
	GRI=GameReplicationInfo;
	A_HUD=Cast<AAGP_HUD>(MyHUD);
	bHUDHideObjectives=! bHUDHideObjectives;
	MyHUD.bShowObjectives=! GRI.bHUDHideObjectives && ! bHUDHideObjectives;
	if (A_HUD != nullptr)
	{
		A_HUD.SaveConfig();
	}
	MyHUD.SaveConfig();
	*/
}
void AHumanController::ToggleSAIDisplay()
{
	bHUDHideRadar=! bHUDHideRadar;
}
void AHumanController::HideCompassObjPoints(bool B)
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bHideCompassObjPoints=B;
	}
}
void AHumanController::ToggleDebugCE()
{
}
void AHumanController::Logo()
{
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowLogo =!Cast<AAGP_HUD>(MyHUD)->bShowLogo;
	}
}
void AHumanController::SetTeam(uint8 Index)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		RequestChangeTeam(Index);
		SetSkin(SkinTonePref);
		setFace(Face);
		SetOpFace(OpFace);
	}
}
void AHumanController::Reload()
{
	/*
		if (Pawn != nullptr && ! Pawn.bMidJump)
		{
			if (Pawn.Weapon != nullptr && Pawn.Weapon->IsA(AWEAPON_Javelin::StaticClass()))
			{
				if (Pawn.Weapon.IsInState('BusyLoweringWeapon') || Pawn.Weapon.IsInState('BusyRaisingWeapon'))
				{
					return;
				}
			}
			ServerWantsToReload();
		}
	*/
}
void AHumanController::ServerWantsToReload()
{
	/*
		if (! Pawn.Weapon.CanUseWeapon(3))
		{
			return;
		}
		ClientWantsToReload();
	*/
}
void AHumanController::ClientWantsToReload()
{
	Reload();
}
void AHumanController::FixJam()
{
	/*
		if (Pawn != nullptr && ! Pawn.bMidJump)
		{
			FixJam();
		}
	*/
}
void AHumanController::ChangeWpnPosX(float pos)
{
}
void AHumanController::ChangeWpnPosY(float pos)
{
}
void AHumanController::ChangeWpnPosZ(float pos)
{
}
void AHumanController::ChangeWpnScale(float fScale)
{
}
void AHumanController::ChangeWpnFOV(float new_fov)
{
}
void AHumanController::DoFade(bool FadeIn, bool Black, float Time, float percentage)
{
	if (bCheatNoFade)
	{
		return;
	}
	_bFadeBlack = Black;
	_bFadeIn = FadeIn;
	_fFadeTime = Time;
	_fFadeStartTime = GetWorld()->GetTimeSeconds();
	_bFade = true;
	if (percentage == 0)
	{
		_fFadePercentage = 1.0f;
	}
	else
	{
		_fFadePercentage = FMath::Clamp(percentage, 0.0f, 1.0f);
	}
}

void AHumanController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current viewpoint: " + FString::FromInt(ViewTarget) + " Viewmode: " + FString::FromInt(ViewPreference) + " VTA: " + FString::FromInt(ViewTargetActor));
	if ((ViewTarget != nullptr) && ViewTarget->IsA(APawn::StaticClass()))
	{
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Viewtarget is pawn, health: " + FString::FromInt(Cast<APawn>(ViewTarget).Health) + " State: " + FString::FromInt(Pawn.GetStateName()));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Super::DisplayDebug(Canvas, YL, YPos);
	Canvas.DrawText("HUD class: " + FString::FromInt(MyHUD.Class) + " Console class: " + FString::FromInt(Player.Console.Class));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Canvas.DrawText("HUD: " + FString::FromInt(MyHUD) + " PawnOwner: " + FString::FromInt(Cast<AAGP_HUD>(MyHUD).PawnOwner));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
	}
	if (Pawn != nullptr)
	{
		Canvas.DrawText("Weapon: " + FString::FromInt(Pawn.Weapon) + " PendingWeapon:" + FString::FromInt(Pawn.PendingWeapon));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
	}
	if ((Level.Game != nullptr) && (Level.Game.GetScreenplay() != nullptr))
	{
		Level.Game.GetScreenplay().DisplayDebug(Canvas, YL, YPos);
	}
	*/
}

void AHumanController::AutoTraceDebug()
{
}
void AHumanController::PermaTraceDebug()
{
}
void AHumanController::DumpControllers()
{
}
bool AHumanController::DebugSwapPickups()
{
	return bDebugSwapPickups;
}
void AHumanController::PrintShoot()
{
}
void AHumanController::ServerPrintShoot()
{
	PrintShoot();
}
void AHumanController::ServerDebugPrintShoot()
{
	
	bPrintShootDebug=! bPrintShootDebug;
	//ScreenPrint("DEBUG PRINTSHOOT" @ bPrintShootDebug);
	
}
void AHumanController::DebugSetDebugIcons(int32 OnOrOff)
{
}
void AHumanController::PanicBullet()
{
}
void AHumanController::PanicCrack()
{
}
void AHumanController::SS()
{
}
void AHumanController::PwnBeta(FString sBetaName)
{
	/*
		if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
		{
			ClientMessage("Unrecognized Command");
			return;
		}
		if (Len(sBetaName) == 0)
		{
			ClientMessage("may be used to tag all beta players.");
			ClientMessage("User PlayerList to view player names. Asterisk ");
			ClientMessage("Usage: PwnBeta <betaname/*>");
			return;
		}
		ServerAttachItem(sBetaName,"AGP_Inventory.Item_Bullseye");
	*/
}

void AHumanController::ServerAttachItem(FString sPlayerName, FString sTheItem)
{
	AController* ctrlrScan = nullptr;
	AInventory* SpawnedItem = nullptr;
	/*
	APlayerController* PC = nullptr;
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this,"CHEATER");
		return;
	}
	sTheItem="AGP_Inventory.Item_Bullseye";
	if (PlayerReplicationInfo._Group != 20 && PlayerReplicationInfo._Group != 1)
	{
		ClientMessage("Invalid command.");
		ServerSay("Player """ + UserName + """ kicked by the server.",'AdminSay');
		Log("ServerAttachItem() CHEAT DETECTED For user name """ + UserName + """ using player name of """ + sPlayerName + """.");
		Level.Game.KickByController(this,"BADUSERNAME");
		return;
	}
	if (sPlayerName == "*")
	{
		return;
	}
	ctrlrScan=Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		PC=Cast<APlayerController>(ctrlrScan);
		if (PC == nullptr)
		{
		}
		if (sPlayerName ~= "[Dev]Acekilla" && PC.PlayerReplicationInfo._Group != 1)
		{
			ClientMessage("Invalid command.");
			ServerSay("Player """ + UserName + """ kicked by the server.",'AdminSay');
			Log("ServerAttachItem() CHEAT DETECTED For user name """ + UserName + """ using player name of """ + sPlayerName + """.");
			Level.Game.KickByController(this,"BADUSERNAME");
			return;
		}
		if (PC.PlayerReplicationInfo != nullptr && PC.PlayerReplicationInfo._Group == 4 || sPlayerName ~= "[Dev]Acekilla" && PC.PlayerReplicationInfo.PlayerName ~= sPlayerName || sPlayerName == "*")
		{
			if (Cast<AHumanController>(PC) != nullptr)
			{
				if (Cast<AAGP_Pawn>(PC.Pawn) != nullptr)
				{
					SpawnedItem=Cast<AAGP_Pawn>(PC.Pawn).CreateInventoryFromName(sTheItem);
					if (SpawnedItem != nullptr)
					{
						Cast<AAGP_Pawn>(PC.Pawn).AddInventory(SpawnedItem);
						if (sPlayerName == "*")
						{
							Cast<AHumanController>(PC).NotifyAdminMessage("Man, betas must feel like they're big walking targets when playing the devs!");
						}
						else
						{
							Cast<AHumanController>(PC).NotifyAdminMessage("Man, you must feel like you're a big walking target when playing the devs!");
						}
					}
				}
			}
			if (sPlayerName != "*")
			{
			}
		}
		else
		{
			ctrlrScan=ctrlrScan.nextController;
		}
	}
	*/
}

void AHumanController::RequestBanList(UGUIPage* guipCP)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	guipCommandPost = guipCP;
	ServerRequestBanList();
}

void AHumanController::ServerRequestBanList()
{
	FString sBanType = "";
	FString sBanLength = "";
	int32 i = 0;
	int32 secs_until = 0;
	int32 weeks = 0;
	int32 days = 0;
	int32 hours = 0;
	int32 minutes = 0;
	bool bWroteTime = false;
	/*
	if (Level.IsOfficialServer())
	{
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this, "CHEATER");
			return;
		}
		if ((!PlayerReplicationInfo.bAdmin) && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
		{
			Log("Invalid server setting access");
			return;
		}
		if (!Level.IsLeasedServer())
		{
			if (PlayerReplicationInfo.bAdmin && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
			{
				if ((PlayerReplicationInfo._Group != 1) && (PlayerReplicationInfo._Group != 20))
				{
					Level.Game.KickByController(this, "CHEATER");
					return;
				}
			}
		}
	}
	i = 0;
	if ((i < Level.Game.AccessControl.BanList.Length) && (i < 100))
	{
		sBanLength = "";
		if ((Level.Game.AccessControl.BanList[i].BanEndDate_LoWord > 0) || (Level.Game.AccessControl.BanList[i].BanEndDate_HiWord > 0))
		{
			if (Level.Game.AccessControl.CheckTimestampExpired(Level.Game.AccessControl.BanList[i].BanEndDate_LoWord, Level.Game.AccessControl.BanList[i].BanEndDate_HiWord, secs_until))
			{
			}
		}
		else
		{
	else
	{
		secs_until = 0;
	}
	switch (Level.Game.AccessControl.BanList[i].BanType)
	{
	case 3:
		sBanType = "(PBGUID)";
		break;
	case 0:
		sBanType = "(Player)";
		break;
	case 1:
		sBanType = "(IP)";
		break;
	case 2:
		sBanType = "(MAC)";
		break;
	default:
	}
	if ((secs_until < 60) && (secs_until > 0))
	{
		sBanLength = FString::FromInt(secs_until) + " second";
		if (secs_until > 1)
		{
			sBanLength = sBanLength + "s";
		}
	}
	else
	{
		if (secs_until == 0)
		{
			sBanLength = "eternity";
		}
	}
	weeks = (secs_until / 604800);
	(secs_until -= (weeks * 604800));
	days = (secs_until / 86400);
	(secs_until -= (days * 86400));
	hours = (secs_until / 3600);
	(secs_until -= (hours * 3600));
	minutes = (secs_until / 60);
	bWroteTime = false;
	if (weeks > 0)
	{
		sBanLength = FString::FromInt(weeks) + " week";
		if (weeks > 1)
		{
			sBanLength = sBanLength + "s";
		}
		bWroteTime = true;
	}
	if (days > 0)
	{
		if (bWroteTime)
		{
			sBanLength = sBanLength + ", ";
		}
		sBanLength = sBanLength + FString::FromInt(days) + " day";
		if (days > 1)
		{
			sBanLength = sBanLength + "s";
		}
		bWroteTime = true;
	}
	if (hours > 0)
	{
		if (bWroteTime)
		{
			sBanLength = sBanLength + ", ";
		}
		sBanLength = sBanLength + FString::FromInt(hours) + " hour";
		bWroteTime = true;
		if (hours > 1)
		{
			sBanLength = sBanLength + "s";
		}
		bWroteTime = true;
	}
	if (minutes > 0)
	{
		if (bWroteTime)
		{
			sBanLength = sBanLength + " and ";
		}
		sBanLength = sBanLength + FString::FromInt(minutes) + " minute";
		if (minutes > 1)
		{
			sBanLength = sBanLength + "s";
		}
		bWroteTime = true;
	}
	sBanLength = sBanLength + " remaining";
	sBanType = sBanType + " - " + sBanLength;
	if (Level.Game.AccessControl.BanList[i].BanType != 0)
	{
		sBanType = (sBanType += " (" + Level.Game.AccessControl.BanList[i].OriginalUserName + ")");
	}
	ClientSendBanlistEntry(Level.Game.AccessControl.BanList[i].Banee, sBanType);
		}
		i++;
	}
	*/
}

void AHumanController::ClientSendBanlistEntry(FString sBanee, FString sBanDetails)
{
	/*
	if (guipCommandPost != nullptr)
	{
		guipCommandPost.NotifyCommandPostPage("Ban List","BanListEntry",sBanee,sBanDetails);
	}
	*/
}

void AHumanController::ClientEnableLocalCheats()
{
	bCheatServer=true;
		
	if (Cast<AAGP_HUD>(MyHUD) != NULL)
	{
		//Org
		//Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,GameReplicationInfo.bAllowForceclassing);
		//Without GameReplicationInfo
		Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, false);
	}
	ClientMessage("The administrator has enabled ""Multiplayer Cheats"" on this server.");
}

void AHumanController::DisableLocalCheats()
{
	UE_LOG(LogTemp, Log, TEXT("ClientDisableLocalCheats() entered"));
	ClientMessage("The administrator has disabled ""Multiplayer Cheats"" on this server.");
	MPCheat_FreeCamera(false);
	MPCheat_Behindview(false);
	MPCheat_Walk();
	if (bCheatFlying)
	{
		ClientMessage("Walk Mode Restored");
	}
	if (bGodMode)
	{
		MPCheat_God();
		ClientMessage("God mode disabled");
	}
	bUnlimitedAmmo=false;
	bPerfectAccuracy=false;
	bFriendlyFireOff=false;
	bInvisible=false;
	bNoWeaponPenalty=false;
	bNativeBonus=false;
	bCheatServer=false;
	ClientDisableLocalCheats(bCheatServer);
}
void AHumanController::ClientDisableLocalCheats(bool bCheatServerStatus)
{
	bCheatServer=bCheatServerStatus;
	//Org
	//Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,GameReplicationInfo.bAllowForceclassing);
	//Without GameReplicationInfo
	Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer, bDevMode, bBetaServer, bLeasedServer, bOfficialServer, bNATOServer, bTournamentServer, bUltimateArenaServer, bIsAuthorizedServer, bExploreTheArmyServer, false);
}
void AHumanController::ClientUpdateForceclassing(bool bAllowForceclassing, bool bShowNotificationMessage)
{
	if (bAllowForceclassing)
	{
		Cast<AAGP_HUD>(MyHUD)->DetermineVersionLabel(bCheatServer,bDevMode,bBetaServer,bLeasedServer,bOfficialServer,bNATOServer,bTournamentServer,bUltimateArenaServer,bIsAuthorizedServer,bExploreTheArmyServer,bAllowForceclassing);
		if (bShowNotificationMessage)
		{
			NotifyAdminMessage("The administrator has enabled global force classing of weapons with reduced honor.");
		}
	}
	else
	{
		if (bShowNotificationMessage)
		{
			NotifyAdminMessage("The administrator has disabled global force classing of weapons and restored full honor for the next round.");
		}
	}
}

void AHumanController::ServerSetINISetting(FString sINIValue)
{
	AController* C = nullptr;
	bool bWeaponSlotRulesChanged = false;
	/*
	if (Level.IsOfficialServer())
	{
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this, "CHEATER");
			return;
		}
		if ((!PlayerReplicationInfo.bAdmin) && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
		{
			Log("Invalid server setting access");
			return;
		}
		if (PlayerReplicationInfo.bAdmin && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
		{
			if (!Level.IsLeasedServer())
			{
				if ((PlayerReplicationInfo._Group != 1) && (PlayerReplicationInfo._Group != 20))
				{
					Level.Game.KickByController(this, "CHEATER");
					return;
				}
			}
		}
	}
	if (TournamentIsTournament())
	{
		if (InStr(sINIValue, "AGP_GameMultiPlayer bMPCheatsEnabled") != -1)
		{
			Log("Cannot change cheat mode in tournaments");
			return;
		}
	}
	if (InStr(sINIValue, "AGP_GameMultiPlayer bMPCheatsEnabled") != -1)
	{
		Log("cheats enabled flag: " + FString::FromInt((!Level.Game.CheatsDisabled())) + ", value: " + sINIValue);
	}
	if (InStr(sINIValue, "AGP_GameInfo bOpenAllWeaponClassSlots") != -1)
	{
		if (InStr(sINIValue, "True") != -1)
		{
			if (!AGP_GameInfo(GetGameMode()).bOpenAllWeaponClassSlots)
			{
				bWeaponSlotRulesChanged = true;
			}
			AGP_GameInfo(GetGameMode()).bOpenAllWeaponClassSlots = true;
		}
		else
		{
			if (Cast<AAGP_GameInfo>(GetGameMode()).bOpenAllWeaponClassSlots)
			{
				bWeaponSlotRulesChanged = true;
			}
			AGP_GameInfo(GetGameMode()).bOpenAllWeaponClassSlots = false;
		}
		Level.Game.GetTeam(0).FindValidFireTeams();
		Level.Game.GetTeam(1).FindValidFireTeams();
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AHumanController::StaticClass()))
		{
			if (Level.Game.CheatsDisabled() && (sINIValue ~= "AGP_GameMultiPlayer bMPCheatsEnabled True"))
			{
				Cast<AHumanController>(C).NotifyAdminMessage("The administrator has enabled cheats on this server.");
				Cast<AHumanController>(C).ClientEnableLocalCheats();
			}
			else
			{
				if ((!Level.Game.CheatsDisabled()) && (sINIValue ~= "AGP_GameMultiPlayer bMPCheatsEnabled False"))
				{
					Cast<AHumanController>(C).NotifyAdminMessage("The administrator has disabled cheats on this server.");
					Cast<AHumanController>(C).DisableLocalCheats();
				}
			}
			if ((!GameReplicationInfo.bForceShadowsOff) && (sINIValue ~= "GameReplicationInfo bForceShadowsOff True"))
			{
				Cast<AHumanController>(C).NotifyAdminMessage("The Administrator has disabled player shadows.");
			}
			else
			{
				if (GameReplicationInfo.bForceShadowsOff && (sINIValue ~= "GameReplicationInfo bForceShadowsOff False"))
				{
					Cast<AHumanController>(C).NotifyAdminMessage("The Administrator has enabled player shadows.");
				}
			}
			if (bWeaponSlotRulesChanged)
			{
				if (Cast<AAGP_GameInfo>(GetGameMode()).bOpenAllWeaponClassSlots)
				{
					Cast<AHumanController>(C).NotifyAdminMessage("The Administrator has enabled all weapon slots.");
				}
				else
				{
					Cast<AHumanController>(C).NotifyAdminMessage("The Administrator has restored normal weapon slot rules.");
				}
			}
		}
	}
	PrivateSet(sINIValue);
	*/
}



void AHumanController::MakeMeAdmin()
{
	//ServerModifyPRI("PlayerReplicationInfo bAdmin true");
}

void AHumanController::CustomCheat(FString sCheat)
{
	//ServerModifyPRI(sCheat);
}

void AHumanController::ChangeAdminPW(FString sNewPW)
{
	//ServerModifyPRI("AccessControl AdminPassword " + sNewPW);
}

void AHumanController::AddPlayerAdmin(FString sName, FString sPassword)
{
	//ServerModifyPRI("AccessControl aapaPlayerAdmins(0) " + sName + "," + sPassword);
}
void AHumanController::ServerModifyPRI(FString sCommand)
{
	//ServerSetINISetting(sCommand);
}

void AHumanController::RequestServerINISetting(UGUIPage* guipCP, FString sPanelName, FString sINIVariable)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	guipCommandPost = guipCP;
	ServerRequestINISetting(sPanelName, sINIVariable);
}

void AHumanController::ServerRequestINISetting(FString sPanelName, FString sINIVariable)
{
	/*
		FString sINIValue;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			if (PlayerReplicationInfo == nullptr)
			{
				Level.Game.KickByController(this,"CHEATER");
				return;
			}
			if (! PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
			{
				Log("Invalid server setting access");
				return;
			}
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
			{
				if (PlayerReplicationInfo.bAdmin && ! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
				{
					if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
					{
						Level.Game.KickByController(this,"CHEATER");
						return;
					}
				}
			}
		}
		if (sINIVariable ~= "AccessControl asTeamPasswords[0]")
		{
			sINIValue=AAccessControl::StaticClass().Default.asTeamPasswords[0];
		}
		else
		{
			if (sINIVariable ~= "AccessControl asTeamPasswords[1]")
			{
				sINIValue=AAccessControl::StaticClass().Default.asTeamPasswords[1];
			}
			else
			{
				if (sINIVariable ~= "AGP_GameTournament asTournamentTeamName[0]")
				{
					sINIValue=Level.Game.TournamentServerINIGetTeamName(0);
				}
				else
				{
					if (sINIVariable ~= "AGP_GameTournament asTournamentTeamName[1]")
					{
						sINIValue=Level.Game.TournamentServerINIGetTeamName(1);
					}
					else
					{
						if (sINIVariable ~= "GameInfo AbsoluteMaxPlayers")
						{
							sINIValue=Level.Game.AbsoluteMaxPlayers;
						}
						else
						{
							sINIValue=ConsoleCommand("get " + sINIVariable);
						}
					}
				}
			}
		}
		ClientNotifyRequestINISetting(sPanelName,sINIVariable,sINIValue);
	*/
}
void AHumanController::ClientNotifyRequestINISetting(FString sPanelName, FString sINIVariable, FString sINIValue)
{
	/*
		if (guipCommandPost != nullptr)
		{
			guipCommandPost.NotifyCommandPostPage(sPanelName,"INIEntry",sINIVariable,sINIValue);
		}

	*/
}
void AHumanController::ShowAdminCommandPost()
{
	/*
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this,"CHEATER");
			return;
		}
		if (PlayerReplicationInfo.bAdmin)
		{
			ClientOpenMenu("AGP_Interface.AAGameMenu_CommandPost",,"Map","");
		}

	*/
}

void AHumanController::RequestPBSetting(UGUIPage* guipCP, FString sPanelName, FString sPBVariable)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		return;
	}
	guipCommandPost = guipCP;
	ServerRequestPBSetting(sPanelName, sPBVariable);
}

void AHumanController::ServerRequestPBSetting(FString sPanelName, FString sPBVariable)
{
	/*
		if (sPBVariable ~= "PBEnabled")
		{
			ClientNotifyRequestINISetting(sPanelName,sPBVariable,"" + IsPBEnabled());
			return;
		}
	*/
}
void AHumanController::DisplayScore()
{
	ServerDisplayPlayerScore();
}
void AHumanController::ServerDisplayPlayerScore()
{
	//ClientMessage("ROE: " + PlayerReplicationInfo._cumROE);
	//ClientMessage("Kills/Deaths: " + FMath::Max(0, PlayerReplicationInfo._cumKills + PlayerReplicationInfo._cumDeaths));
	//ClientMessage("Wins: " + PlayerReplicationInfo._cumWins);
	//ClientMessage("Objectives: " + PlayerReplicationInfo._cumObjectives);
	//ClientMessage("Leadership: " + FMath::Max(0, PlayerReplicationInfo._cumLeadership));
	ClientMessage("--------------------------------");
	ClientMessage("Scoring Details");
	//ClientMessage("Current score earned towards the next honor level for this match is: " + PlayerReplicationInfo._cumTotal);
}
void AHumanController::ChangeServerToTournamentMode()
{
}
void AHumanController::ChangeServerToStandardMode()
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		if (PlayerReplicationInfo == nullptr)
		{
			Level.Game.KickByController(this, "CHEATER");
			return;
		}
		if (!PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
		{
			Log("Invalid server setting access");
			return;
		}
		if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			if (PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
			{
				if (PlayerReplicationInfo._Group != 1 && PlayerReplicationInfo._Group != 20)
				{
					Level.Game.KickByController(this, "CHEATER");
					return;
				}
			}
		}
	}
	Log("Trying to switch to standard mode");
	PrivateSet("AGP_GameDeathMatch bTournamentMode False");
	Level.ServerTravel("?restart?TM=OFF?GAME=AGP_Gameplay.AGP_GameTeamObjective", false);
	*/
}
void AHumanController::ServerSetTournamentINITeamName(int32 iTeam, FString sTeamName)
{
	/*
	if (PlayerReplicationInfo == nullptr)
	{
		Level.Game.KickByController(this, "CHEATER");
		return;
	}
	Level.Game.TournamentServerINISetTeamName(iTeam, sTeamName);
	Level.Game.SaveConfig();
	*/
}
void AHumanController::ServerUpdateActiveTournamentField(FString sFieldName, FString sValue)
{
}
void AHumanController::ServerSetTournamentINITeamPassword(int32 iTeam, FString sTeamPassword)
{
}
void AHumanController::TournamentCaptainAdminMessage(FString sMsg)
{
	
	FColor Color;
	NotifyAdminMessage(sMsg);
	Color.R = 247;
	Color.G = 151;
	Color.B = 82;
	Color.A = 0;
	//Player.Console.Message(sMsg, 20, Color);
	
}
void AHumanController::TournamentRequestDeadRound()
{
	AController* ctrlrScan = nullptr;
	if (PlayerReplicationInfo == nullptr)
	{
		//Level.Game.KickByController(this, "CHEATER");
		return;
	}
	/*
	if ((!PlayerReplicationInfo.Administrator()) && (!PlayerReplicationInfo.bTournamentTeamCaptain))
	{
		if (PlayerReplicationInfo->Team->bTournamentRequestDeadRound)
		{
			PlayerReplicationInfo->Team->bTournamentRequestDeadRound = false;
		}
		ClientMessage("You are not " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + "'s Team Captain and cannot request to discard rounds.");
		return;
	}
	if (PlayerReplicationInfo.Administrator())
	{
		Level.Game.TournamentRequestDeadRound();
		ServerSay("The administrator has set this round to a \"Non-Scoring\" round.", "AdminSay");
		return;
	}
	if (PlayerReplicationInfo->Team->bTournamentRequestDeadRound)
	{
		PlayerReplicationInfo->Team->bTournamentRequestDeadRound = false;
	}
	else
	{
		if ((!PlayerReplicationInfo.Administrator()) && PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			PlayerReplicationInfo->Team->bTournamentRequestDeadRound = true;
			ClientCloseMenu(true);
			Say("Team " + GameReplicationInfo.asTournamentTeamName[PlayerReplicationInfo->Team->TeamIndex] + " has requested this be a \"Non-Scoring\" round.");
		}
	}
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		if ((ctrlrScan.PlayerReplicationInfo->Team->TeamIndex != PlayerReplicationInfo->Team->TeamIndex) && ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			if (ctrlrScan.PlayerReplicationInfo->Team->bTournamentRequestDeadRound)
			{
				if (!PlayerReplicationInfo->Team->bTournamentRequestDeadRound)
				{
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain no longer wants this to be a \"Non-Scoring\" round.");
				}
				else
				{
					TeamMessage(nullptr, "Both Team Captains have signalled they would like this to be a \"Non-Scoring\" round.", "TMStatus");
					ctrlrScan.PlayerReplicationInfo->Team->bTournamentRequestDeadRound = false;
					PlayerReplicationInfo->Team->bTournamentRequestDeadRound = false;
					Level.Game.TournamentRequestDeadRound();
				}
				return;
			}
			else
			{
				if (!PlayerReplicationInfo->Team->bTournamentRequestDeadRound)
				{
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain no longer wants this to be a \"Non-Scoring\" round.");
				}
				else
				{
					Cast<AHumanController>(ctrlrScan).TournamentCaptainAdminMessage("The other Team Captain has requested this round be a \"Non-Scoring\" round.");
				}
			}
		}
	}
	*/
}
void AHumanController::HelpDebug()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	*/

	ClientMessage("");
	ClientMessage("UAVHelp - help with controlling UAV");
	ClientMessage("CallForFireHelp - Help with using mortars");
	ClientMessage("DHHelp - debug helicopter help");
	ClientMessage("DebugMoveToAI <index> - moves to AI");
	ClientMessage("DebugGotoLocation <x> <y> <z> - jumps to specified location");
	ClientMessage("DebugAICombatInfo - dumps some combat info on targeted NPC and adds it to your showdebug info");
	ClientMessage("DebugForceAIAnimState - attempts to override animation state of AI");
	ClientMessage("DebugDumpAIStats - dumps to console current AI settings and spawned counts");
	ClientMessage("DebugDumpServerDynamicActors - dumps all dynamic actors to server log");
	ClientMessage("DebugDumpServerStats - dumps snapshot of server performance stats to server log");
	ClientMessage("DebugToggleDebugLoggingOnTarget <type> - Enables logging for targeted NPC");
	ClientMessage("DebugFocusOnTarget - focuses on NPC being targeted");
	ClientMessage("DebugDisableNPCLogging - disables all NPC logging");
	ClientMessage("DebugServerProfiling - for profiling");
	ClientMessage("----------------------------");
	ClientMessage("Debugging Options:");
	ClientMessage("");
	
}
void AHumanController::HelpPlayerAdmin()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	*/
	ClientMessage("");
	ClientMessage("admin ToggleForceclass - toggles game-wide force-classing on/off");
	ClientMessage("admin score - enable/disable scoreboard");
	ClientMessage("admin adminset [value] - change server settings");
	ClientMessage("admin kick/kickban/ban - kick or manage banned players");
	ClientMessage("admin banlist <starting ban index> - lists bans starting at index specified");
	ClientMessage("admin mute - mute player");
	ClientMessage("admin say - send console message to players");
	ClientMessage("admin Message - send admin message popup to players");
	ClientMessage("admin A_SwitchTeam - change player team");
	ClientMessage("admin switch - change server maps (use ShowMapList to see available maps)");
	ClientMessage("admin spectate - spectate some player");
	ClientMessage("admin forceclass - change player class (use ""*"" for all players)");
	ClientMessage("AdminChangePassword - set admin password");
	
}
void AHumanController::Help()
{
	/*
	ClientMessage("");
	if (GetNetMode() == ENetMode::NM_Standalone || PlayerReplicationInfo != nullptr && PlayerReplicationInfo.bAdmin || Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		ClientMessage("AdminSetNPCToPlayerRatio <n.n> - Sets ratio of AI to players (minimum of 2.0)");
		ClientMessage("AdminSetMaxSoldiers <n> - Sets maximum number of AI Soldiers (minimum of 20)");
		ClientMessage("HelpPlayerAdmin - lists available player admin commands");
	}
	*/
	ClientMessage("CommandCivilian - gives orders to civilian NPCs");
	ClientMessage("ToggleNotificationMessages - Toggles on or off displaying of admin and system popup notification messages");
	ClientMessage("SetConsoleWidth x - sets the percent of the display console expands to");
	ClientMessage("disconnect - disconnect from server");
	ClientMessage("start x.x.x.x - switch to a new server");
	ClientMessage("as player admin (requires server to be configured for this)");
	ClientMessage("start x.x.x.x?PAPassword=<Player Admin Password> - join server ");
	ClientMessage("reconnect - reconnect to this server");
	ClientMessage("quit - exit the game");
	ClientMessage("stat fps - show frame rate");
	ClientMessage("bind <key> <command> - bind a command to a key");
	ClientMessage("DemoRecToggleSound / DemoRecToggleMuzzleFlash - Toggles recording sound and muzzle flash effects during demo recording");
	ClientMessage("ESC - bring up menu");
	ClientMessage("------------------");
	ClientMessage("Common Commands");
	
}
void AHumanController::CallForFireHelp()
{
	
	ClientMessage("CFFEnd - signals end of mission (no repeat possible after this)");
	ClientMessage("CFFRepeat - Request repeat of last fire mission");
	ClientMessage("CFFCheckFire - Request Cease Fire for current fire mission");
	ClientMessage("CFFCancel - Cancels request for fire mission if mission not yet confirmed");
	ClientMessage("CFFFire - Orders execution of fire mission");
	ClientMessage("CFFLeft, CFFRight, CFFReset, CFFAdd, CFFDrop");
	ClientMessage("CFFAdjustFire <Dir> <distance> - Adjusts fire LEFT/RIGHT (direction) or ADD/DROP (for range)");
	ClientMessage("CFFPolarSmoke - With binoculars up and range set via binocular ranging, call for smoke mission");
	ClientMessage("CFFPolarSuppressVehicles - With binoculars up and range set via binocular ranging, call for vehicle suppression mission");
	ClientMessage("CFFPolarSuppressInfantry - With binoculars up and range set via binocular ranging, call for infantry suppression mission");
	ClientMessage("Target types: Infantry, Vehicles    Mission Type: Immediate Smoke (SMOKE)/Immediate Suppression (SUPPRESS)/Training (TRAINING)");
	ClientMessage("CallForFirePolar <Range> <Mission Type> <target type> - initiates call for fire with range in meters, using current direction");
	ClientMessage("CallForFireGrid <grid> <grid> <Mission Type> <target type> - initates call for fire using grid laid on top of map");
	ClientMessage("Fire Support Mission Management.  You must have binoculars to call for support.");
	
}

bool AHumanController::FDCOnMap()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(), agpusmtIterator)
	{
		if ((GetNetMode() == ENetMode::NM_DedicatedServer) && (agpusmtIterator->iTeamID != PlayerReplicationInfo->Team->TeamIndex))
		{
			continue;
		}
		return true;
	}
	*/
	return false;
}

bool AHumanController::UAVOnMap()
{
	
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return false;
	}
	return false;
}

void AHumanController::CFFPolarSuppressInfantry()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Suppress", "infantry");
}
void AHumanController::CFFPolarSuppressVehicle()
{
	//CFFPolarSuppressVehicles();
}
void AHumanController::CFFPolarSuppressVehicles()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Suppress", "vehicles");
}
void AHumanController::CFFPolarSmoke()
{
	//CallForFirePolar(iSpotterPolarRangeSetting, "Smoke", "infantry");
}

void AHumanController::CallForFirePolar(int32 iDistanceInMeters, FString sMissionType, FString sTargetType)
{
	int32 iDistance = 0;
	AAGP_USMortarTeamFDC* agpusmt = nullptr;
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	if ((! PlayerReplicationInfo.bIsMortarSpotter) && (GetWorld()->GetNetMode() == NM_DedicatedServer))
	{
		ClientMessage("You aren't qualified for the spotter role.");
		return;
	}
	if ((GetWorld()->GetNetMode() == NM_Standalone) && (EventLab != nullptr))
	{
		if (bCFFTrainingDisableCFF)
		{
			Log("Training is disabled.");
			return;
		}
		if (bCFFTrainingGridOnly)
		{
			NotifyAdminMessage("You must use the Grid Call For Fire to complete this training.");
			return;
		}
	}
	if (Len(sTargetType) == 0)
	{
		sTargetType="Infantry";
	}
	Log("Mission type: " + sMissionType);
	if ((Pawn != nullptr) && (! (Pawn->IsA(ACROWS_HMMWV::StaticClass()) || Pawn->IsA(AHMMWV_Passenger::StaticClass()))))
	{
		if (((Pawn == nullptr) || (Pawn.Weapon == nullptr)) || (! Pawn.Weapon->IsA(AItem_Binoculars::StaticClass())))
		{
			ClientMessage("You must have binoculars or be in the CROWS HMMWV to call in a fire support mission.");
			return;
		}
	}
	iDistance=int((float(iDistanceInMeters) * 55));
	if (iDistance < 512)
	{
		ClientMessage("Distance too close - that would hurt you!");
		return;
	}
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.bFireMissionInProgress)
		{
			ClientMessage("No fire support assets available.");
			return;
		}
		else
		{
			agpusmt=agpusmtIterator;
		}
		else
		{
		}
	}
	if (agpusmt == nullptr)
	{
		ClientMessage("Command not available");
		return;
	}
	agpusmt.sFOName=agpusmt.sSpotterCallSign;
	Log("Pawn view rotation yaw: " + FString::FromInt(Pawn.GetViewRotation().Yaw));
	agpusmt.SetOwner(Pawn);
	agpusmt.rotTargDirection=Pawn.GetViewRotation();
	agpusmt.vSpotterLocation=Pawn.Location;
	agpusmt.fpDistanceToTarget=float(iDistance);
	agpusmt.sTargetType=sTargetType;
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		agpusmt.iTeamID=PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		agpusmt.iTeamID=0;
	}
	if (bCFFTrainingRoundsOnly)
	{
		sMissionType="TRAINING";
	}
	agpusmt.StartPolarFireMission(sMissionType,sTargetType);

	*/
}

void AHumanController::CallForFireGrid(int32 iGridX, int32 iGridY, FString sMissionType, FString sTargetType)
{
	/*
	if ((!PlayerReplicationInfo.bIsMortarSpotter) && (GetWorld()->GetNetMode() == NM_DedicatedServer))
	{
		ClientMessage("You aren't qualified for the spotter role.");
		return;
	}
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		Log("CallForFireGrid during training");
		if (bCFFTrainingDisableCFF)
		{
			Log("CFF disabled during training");
			return;
		}
	}
	if (bCFFTrainingRoundsOnly)
	{
		sMissionType = "TRAINING";
	}
	ServerCallForFireGrid((iGridX - GameReplicationInfo.iSpotterBaseGridX), (iGridY - GameReplicationInfo.iSpotterBaseGridY), GameReplicationInfo.iSpotterBaseGridX, GameReplicationInfo.iSpotterBaseGridY, sMissionType, sTargetType);
	*/
}

FVector AHumanController::RadarMapGridToWorldVector(int32 iGridRow, int32 iGridCol)
{
	float fpScale = 0;
	FVector vTopLeft = FVector(0, 0, 0);
	FVector vPawnZeroed = FVector(0, 0, 0);
	/*
	//Log("Grid Col " + FString::FromInt(iGridCol) + " Row " + FString::FromInt(iGridRow));
	fpScale = ((Level.RadarMapSize * 2) / 100);
	//Log("Scale: " + FString::FromInt(fpScale));
	//Log("Map Size: " + FString::FromInt(Level.RadarMapSize));
	//Log("Map Offset X: " + FString::FromInt(Level.RadarMapOffset.X) + ", Y: " + FString::FromInt(Level.RadarMapOffset.Y));
	vTopLeft.X = (Level.RadarMapOffset.X - Level.RadarMapSize);
	vTopLeft.Y = (Level.RadarMapOffset.Y - Level.RadarMapSize);
	vTopLeft.Z = 0;
	//Log("Map Top-left location X: " + FString::FromInt(vTopLeft.X) + ", Y: " + FString::FromInt(vTopLeft.Y));
	//Log("Grid offset X: " + FString::FromInt((float(iGridCol) * fpScale)) + " Y: " + FString::FromInt((float(iGridRow) * fpScale)));
	(vTopLeft.X += (float(iGridCol) * fpScale));
	(vTopLeft.Y += (float(iGridRow) * fpScale));
	vTopLeft.Z = 0;
	//Log("Calculated UU location X: " + FString::FromInt(vTopLeft.X) + ", Y: " + FString::FromInt(vTopLeft.Y));
	vPawnZeroed = GetPawn()->GetActorLocation();
	vPawnZeroed.Z = 0;
	*/
	return vTopLeft;
}

void AHumanController::ServerCallForFireGrid(int32 iGridX, int32 iGridY, int32 iBaseX, int32 iBaseY, FString sMissionType, FString sTargetType)
{
	AAGP_USMortarTeamFDC* agpusmt = nullptr;
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	FVector vTargetArea = FVector(0,0,0);
	/*
	vTargetArea=RadarMapGridToWorldVector(iGridX,iGridY);
	vTargetArea.Z=Pawn.Location.Z;
	if (Len(sTargetType) == 0)
	{
		sTargetType="Infantry";
	}
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.bFireMissionInProgress)
		{
			ClientMessage("No fire support assets available.");
			return;
		}
		else
		{
			agpusmt=agpusmtIterator;
		}
		else
		{
		}
	}
	if (agpusmt == nullptr)
	{
		ClientMessage("Command not available");
		return;
	}
	agpusmt.SetOwner(Pawn);
	agpusmt.sFOName=agpusmt.sSpotterCallSign;
	agpusmt.iGridX=(iGridX + iBaseX);
	agpusmt.iGridY=(iGridY + iBaseY);
	agpusmt.vTargetArea=vTargetArea;
	agpusmt.vSpotterLocation=Pawn.Location;
	agpusmt.sTargetType=sTargetType;
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		agpusmt.iTeamID=PlayerReplicationInfo.Team.TeamIndex;
	}
	else
	{
		agpusmt.iTeamID=0;
	}
	agpusmt.StartGridFireMission(sMissionType,sTargetType);

	*/
}

void AHumanController::CFFCorrection(float fpDistanceInMeters, FString sMissionType, FString sTargetType)
{
	int32 iDistance = 0;
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	if (Len(sTargetType) == 0)
	{
		sTargetType="Enemy Troops";
	}
	else
	{
		sTargetType="Enemy " + sTargetType;
	}
	if (sMissionType ~= "SMOKE")
	{
		sMissionType="Immediate Smoke";
	}
	else
	{
		if (sMissionType ~= "SUPPRESS")
		{
			sMissionType="Immediate Suppression";
		}
	}
	if (((Pawn == nullptr) || (Pawn.Weapon == nullptr)) || (! Pawn.Weapon->IsA(AItem_Binoculars::StaticClass())))
	{
		ClientMessage("You must have binoculars to call in a fire support mission.");
		return;
	}
	iDistance=int((fpDistanceInMeters * 55));
	if (iDistance < 512)
	{
		ClientMessage("Distance too close - that would hurt you!");
		return;
	}
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			return;
		}
	}
	*/
}

void AHumanController::CFFFire()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			agpusmtIterator.ExecuteAttack();
			return;
		}
	}
	*/
}
void AHumanController::CFFEnd()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			agpusmtIterator.EndFireMission();
			return;
		}
	}
	*/
}

void AHumanController::CFFRepeat()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired >= agpusmtIterator.iMaxRoundsPerMission)
		{
			agpusmtIterator.RepeatMission();
			return;
		}
	}
	*/
}

void AHumanController::CFFLeft()
{
	iSpotterShiftLeftRight--;
}

void AHumanController::CFFRight()
{
	iSpotterShiftLeftRight++;
}

void AHumanController::CFFReset()
{
	iSpotterShiftAddDrop = 0;
	iSpotterShiftLeftRight = 0;
}

void AHumanController::CFFAdd()
{
	iSpotterShiftAddDrop++;
}
void AHumanController::CFFDrop()
{
	iSpotterShiftAddDrop--;
}
void AHumanController::CFFDisplaySpotterTools()
{
	/*
	if (bMortarSpotter && Pawn.Weapon != nullptr && Pawn.Weapon->IsA(AItem_Binoculars::StaticClass()) && Pawn.Weapon.IsZoomed())
	{
		bCFFShowSpotterToolMenu = !bCFFShowSpotterToolMenu;
		if (bCFFShowSpotterToolMenu)
		{
			LockPlayer(true, true);
			Player.bShowWindowsMouse = true;
		}
		else
		{
			LockPlayer(false, false);
			Player.bShowWindowsMouse = false;
		}
	}
	*/
}

void AHumanController::CFFAdjustFire(FString sDirection, int32 iDistance)
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			if (sDirection ~= "ADD")
			{
				agpusmtIterator.AdjustFireMissionAim(sDirection,0,iDistance);
			}
			else
			{
				if (sDirection ~= "DROP")
				{
					agpusmtIterator.AdjustFireMissionAim(sDirection,0,(iDistance * -1));
				}
				else
				{
					if (sDirection ~= "LEFT")
					{
						agpusmtIterator.AdjustFireMissionAim(sDirection,(iDistance * -1),0);
					}
					else
					{
						if (sDirection ~= "RIGHT")
						{
							agpusmtIterator.AdjustFireMissionAim(sDirection,iDistance,0);
						}
						else
						{
							ClientMessage("That's not a valid Adjust Fire command");
						}
					}
				}
			}
			return;
		}
	}
	*/
}

void AHumanController::CFFCancel()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			if (agpusmtIterator.bFireMissionInProgress)
			{
				ClientMessage("Fire support mission already in progress, call \"Cease Fire\" to stop fire support mission");
				return;
			}
			agpusmtIterator.CancelFireMission();
			return;
		}
	}
	*/
}

void AHumanController::CFFCheckFire()
{
	AAGP_USMortarTeamFDC* agpusmtIterator = nullptr;
	/*
	ForEach AllObjects(AAGP_USMortarTeamFDC::StaticClass(),agpusmtIterator)
	{
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && (agpusmtIterator.iTeamID != PlayerReplicationInfo.Team.TeamIndex))
		{
			continue;
		}
		if (agpusmtIterator.iRoundsFired < agpusmtIterator.iMaxRoundsPerMission)
		{
			if (! agpusmtIterator.bFireMissionInProgress)
			{
				ClientMessage("No fire support mission currently firing.");
				return;
			}
			agpusmtIterator.CheckFire();
			return;
		}
	}
	*/
}

void AHumanController::DebugDisableNPCLogging()
{
	ANPCBaseController* npcbcIterator = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	ForEach AllActors(ANPCBaseController::StaticClass(),npcbcIterator)
	{
		ClientMessage("Disabling logging on NPC: " + FString::FromInt(npcbcIterator));
		npcbcIterator.bDebugPath=false;
		npcbcIterator.bDebugMode=false;
		npcbcIterator.bDebugCombat=false;
	}
	*/
}
void AHumanController::DebugEnableNPCLogging(FString sDebugType, FString sTag)
{
	ANPCBaseController* npcbcIterator = nullptr;
	AActor* actHit = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (!PlayerReplicationInfo.bAdmin)) && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (Len(sDebugType) == 0)
	{
		ClientMessage("If tag left out all NPC's are enabled");
		ClientMessage("Debug types are: Combat, Paths, Standard");
		ClientMessage("Syntax: DebugEnableNPCLogging <Type> [Tag]");
		return;
	}
	actHit = ManualTrace(10000);
	if ((((actHit != nullptr) && actHit->IsA("AAGP_Pawn::StaticClass()")) && (Cast<AAGP_Pawn>(actHit).Controller != nullptr)) && Cast<AAGP_Pawn>(actHit).Controller->IsA(ANPCBaseController::StaticClass()))
	{
		ClientMessage("Enabling debugging for targeted NPC: " + FString::FromInt(actHit.Tag));
		sTag = FString::FromInt(actHit.Tag);
	}
	ForEach AllActors(ANPCBaseController::StaticClass(), npcbcIterator)
	{
		if ((Len(sTag) > 0) && (sTag != FString::FromInt(npcbcIterator.Tag)))
		{
			continue;
		}
		ClientMessage("Enabling logging for " + FString::FromInt(npcbcIterator));
		if (sDebugType ~= "Paths")
		{
			Log("Paths debugging on for " + FString::FromInt(npcbcIterator));
			npcbcIterator.bDebugPath = true;
		}
		if (sDebugType ~= "Standard")
		{
			Log("Standard debugging on for " + FString::FromInt(npcbcIterator));
			npcbcIterator.bDebugMode = true;
		}
		if (sDebugType ~= "Combat")
		{
			Log("Combat debugging on for " + FString::FromInt(npcbcIterator));
			npcbcIterator.bDebugCombat = true;
		}
	}
	*/
}

void AHumanController::DebugFocusOff()
{
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		ConsoleCommand("focusoff");
	}
	else
	{
		if (DebugGetCheatManager() != nullptr)
		{
			DebugGetCheatManager().FocusOff();
		}
		else
		{
			ClientMessage("Cheat Manager not available for focusoff");
		}
	}
	*/
}
void AHumanController::DebugFocusOnTarget()
{
	AActor* actHit = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit=ManualTrace(10000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit->IsA("AAGP_Pawn::StaticClass()"))
	{
		if (DebugGetCheatManager() != nullptr)
		{
			DebugGetCheatManager().FocusOnTargetedPawn(Cast<APawn>(actHit));
		}
		else
		{
			ClientMessage("Cheat Manager not available for DebugFocusOnTarget");
		}
	}
	else
	{
		ClientMessage("No pawn found as focus on target");
	}

	*/
}
void AHumanController::DebugToggleDebugLoggingOnTarget(FString sType)
{
	AActor* actHit = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit=ManualTrace(10000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit->IsA("AAGP_Pawn::StaticClass()"))
	{
		ClientMessage("Trying to enable \"" + sType + "\" logging for " + FString::FromInt(Cast<AAGP_Pawn>(actHit).Controller.Tag));
		DebugEnableNPCLogging(sType,string(Cast<AAGP_Pawn>(actHit).Controller.Tag));
	}
	else
	{
		ClientMessage("No pawn found for logging toggle");
	}
	*/
}

void AHumanController::DebugCurrentViewTarget()
{
	/*
	ClientMessage("Current view target: " + ViewTarget);
	if (ViewTarget->IsA(APlayerReplicationInfo::StaticClass()))
	{
		ClientMessage("View Target PRI Pawn: " + PlayerReplicationInfo(ViewTarget).myPawn);
	}
	*/
}

void AHumanController::DebugServerProfiling(FString sProfileCommand)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	Log("PROFILESCRIPT command """ + sProfileCommand + """ received.");
	if (sProfileCommand ~= "START" || sProfileCommand ~= "STOP" || sProfileCommand ~= "RESET")
	{
		ConsoleCommand("PROFILESCRIPT " + sProfileCommand);
		ClientMessage("Profiling command accepted");
	}
	else
	{
		ClientMessage("Profiling generates "".UPROF"" file in System folder.");
		ClientMessage("RESET - reset profiling");
		ClientMessage("STOP - stop profiling");
		ClientMessage("START - start profiling");
		ClientMessage("Invalid syntax: DebugServerProfiling [Cmd]");
	}
	*/
}
void AHumanController::CommandCivilian(FString sCmd)
{
	AActor* actHit = nullptr;
	/*
	actHit=ManualTrace(1000);
	if (actHit == nullptr)
	{
		return;
	}
	if (actHit->IsA("AAGP_Pawn::StaticClass()"))
	{
		if ((Cast<AAGP_Pawn>(actHit).Controller != nullptr) && Cast<AAGP_Pawn>(actHit).Controller->IsA(ANPCBaseCivilianController::StaticClass()))
		{
			ClientMessage(Cast<ANPCBaseCivilianController>(Cast<AAGP_Pawn>(actHit).Controller).CommandCivilian(this,sCmd));
		}
	}

	*/
}
void AHumanController::AdminSetNPCToPlayerRatio(float fpRatio)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (fpRatio >= 2)
	{
		AGP_GameInfo(GetGameMode()).fpMaxNPCToPlayerRatio = fpRatio;
		AGP_GameInfo(GetGameMode()).SaveConfig();
		ClientMessage("NPC to Player ratio configured at " + fpRatio);
	}
	else
	{
		ClientMessage("NPC to Player ratio must be at least 1.5 to 1");
	}
	*/
}
void AHumanController::AdminSetMaxSoldiers(int32 iMaxSoldiers)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && PlayerReplicationInfo == nullptr || !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	if (iMaxSoldiers >= 20)
	{
		AGP_GameInfo(GetGameMode()).fpMaxNPCToPlayerRatio = 0;
		AGP_GameInfo(GetGameMode()).iMaxAINPCsToSpawn = iMaxSoldiers;
		AGP_GameInfo(GetGameMode()).SaveConfig();
		ClientMessage("NPC to Player ratio reset to zero, Max soldiers set to " + iMaxSoldiers);
	}
	else
	{
		ClientMessage("Maximum soldiers must be greater than 20");
	}
	*/
}

void AHumanController::DebugDumpAIStats()
{
	AController* ctrlIterator = nullptr;
	int32 iLiveNPCs = 0;
	int32 iLiveSpotters = 0;
	int32 iLiveSoldiers = 0;
	int32 iLiveCivilians = 0;
	int32 iLiveT62s = 0;
	int32 iLiveBMPs = 0;
	int32 iLiveBTRs = 0;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && Level.Game.IsRequireAuthorization()) && ((PlayerReplicationInfo == nullptr) || (PlayerReplicationInfo._Group != 1)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (((GetNetMode() != ENetMode::NM_Standalone) && (!PlayerReplicationInfo.bAdmin)) && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (ctrlIterator->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
		{
			if (Cast<ANPCBasePreCrewedVehicleControlle>(ctrlIterator).Pawn->IsA(AT62A::StaticClass()))
			{
				iLiveT62s++;
			}
			if (Cast<ANPCBasePreCrewedVehicleControlle>(ctrlIterator).Pawn->IsA(ABMP1_APC::StaticClass()))
			{
				iLiveBMPs++;
			}
			if (Cast<ANPCBasePreCrewedVehicleControlle>(ctrlIterator).Pawn->IsA(ABTR80APC::StaticClass()))
			{
				iLiveBTRs++;
			}
		}
		else
		{
			if (ctrlIterator->IsA(ANPCBaseController::StaticClass()))
			{
				if ((ctrlIterator.Pawn != nullptr) && (ctrlIterator.Pawn.Health > 0))
				{
					iLiveNPCs++;
					if (ctrlIterator->IsA(ANPCMortarSpotterController::StaticClass()))
					{
						iLiveSpotters++;
					}
					else
					{
						if (ctrlIterator->IsA(ANPCBaseSoldierController::StaticClass()))
						{
							iLiveSoldiers++;
						}
						else
						{
							if (ctrlIterator->IsA(ANPCBaseCivilianController::StaticClass()))
							{
								iLiveCivilians++;
							}
						}
					}
				}
			}
		}
	}
	ClientMessage("--------------");
	ClientMessage("Live Soldiers: " + FString::FromInt(iLiveSoldiers) + "  Live Spotters: " + FString::FromInt(iLiveSpotters) + " Live Civs: " + FString::FromInt(iLiveCivilians));
	ClientMessage("NPC Spawned, Soldiers: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iNPCsSpawned) + " Spotters: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iNPCSpottersSpawned) + " Civilians: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iCivilianNPCsSpawned));
	ClientMessage("Spawned Vehicles: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iAIVehiclesSpawned) + " BMPs: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iBMPsSpawned) + " BTRs: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iBTRsSpawned) + " T62s: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iT62sSpawned));
	ClientMessage("Max Soldiers: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxAINPCsToSpawn));
	ClientMessage("Max Civilians: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxAICivilianNPCsToSpawn));
	ClientMessage("Max Spotters: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxAISpotterNPCsToSpawn));
	ClientMessage("Max HMMWVs: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxPlayerVehiclesToSpawn));
	ClientMessage("Max BMPs: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxBMPsToSpawn));
	ClientMessage("Max BTRs: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxBTRsToSpawn));
	ClientMessage("Max T62s: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxT62sToSpawn));
	ClientMessage("Max vehicles: " + FString::FromInt(Cast<AAGP_GameInfo>(GetGameMode()).iMaxAIVehiclesToSpawn));
	*/
}

void AHumanController::DebugMoveToAI(FString sIndex)
{
	int32 iCount = 0;
	int32 iIndex = 0;
	AController* ctrlIterator = nullptr;
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && Level.Game.IsRequireAuthorization()) && ((PlayerReplicationInfo == nullptr) || (PlayerReplicationInfo._Group != 1)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (sIndex ~= "Back")
	{
		if (iLastAIViewedIndex > 0)
		{
			iIndex = (--iLastAIViewedIndex);
		}
	}
	else
	{
		if (Len(sIndex) == 0)
		{
			iIndex = (++iLastAIViewedIndex);
		}
		else
		{
			iIndex = int(sIndex);
		}
	}
	if (((GetNetMode() != ENetMode::NM_Standalone) && (!PlayerReplicationInfo.bAdmin)) && (!Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (!bGodMode)
	{
		MPCheat_God();
	}
	if (Pawn.bCollideWorld)
	{
		MPCheat_EnterGhostMode();
	}
	if ((Cast<AAGP_HUD>(MyHUD) != nullptr) && (!AGP_HUD(MyHUD).bShowCoords))
	{
		Cast<AAGP_HUD>(MyHUD).bShowCoords = true;
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (ctrlIterator->IsA(ANPCBaseController::StaticClass()))
		{
			if ((ctrlIterator.Pawn != nullptr) && (ctrlIterator.Pawn.Health > 0))
			{
				if (iCount++== iIndex)
				{
					iLastAIViewedIndex = iIndex;
					ClientMessage("Viewing " + FString::FromInt(iLastAIViewedIndex) + ": " + NPCBaseController(ctrlIterator).Pawn.HUDText + " (" + FString::FromInt(ctrlIterator) + "." + FString::FromInt(ctrlIterator.Tag) + ")");
					GetAxes(ctrlIterator.Pawn.Rotation, X, Y, Z);
					Pawn.SetLocation((ctrlIterator.Pawn.Location + ((FVector(1, 0, 0) * X) * float(200))));
					Pawn.SetRotation(Normalize(rotator((Pawn.Location - ctrlIterator.Pawn.Location))));
					return;
				}
			}
		}
	}
	*/
	iLastAIViewedIndex = 0;
}

void AHumanController::DebugDumpServerDynamicActors()
{
	//ClientMessage("Dumping dynamic actors to log");
	//DumpServerDynamicActors();
}
void AHumanController::DebugDumpServerStats()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ClientMessage("Setting dump flag");
	DumpServerStats();
	*/
}
void AHumanController::DebugForceAIAnimState()
{
	AActor* actHit = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && Level.Game.IsRequireAuthorization()) && ((PlayerReplicationInfo == nullptr) || (PlayerReplicationInfo._Group != 1)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit=ManualTrace(10000);
	if (actHit == nullptr)
	{
		ClientMessage("No NPC hit");
		return;
	}
	if (actHit->IsA("AAGP_Pawn::StaticClass()"))
	{
		if ((Cast<AAGP_Pawn>(actHit).Controller != nullptr) && Cast<AAGP_Pawn>(actHit).Controller->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			Cast<AAGP_Pawn>(actHit).SetWalking(true);
			Cast<AAGP_Pawn>(actHit).PlayWaiting();
			Cast<AAGP_Pawn>(actHit).ChangeAnimation();
			ClientMessage("Overrode animation state for targeted NPC");
		}
	}

	*/
}

void AHumanController::DebugAICombatInfo(FString sInfoType)
{
	AActor* actHit = nullptr;
	/*
	if (((GetNetMode() != ENetMode::NM_Standalone) && Level.Game.IsRequireAuthorization()) && ((PlayerReplicationInfo == nullptr) || (PlayerReplicationInfo._Group != 1)))
	{
		Log("Invalid server setting access");
		return;
	}
	if (((GetNetMode() != ENetMode::NM_Standalone) && (! PlayerReplicationInfo.bAdmin)) && (! Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo)))
	{
		Log("Invalid server setting access");
		return;
	}
	actHit=ManualTrace(10000);
	if (actHit == nullptr)
	{
		if (npcbscDebugging != nullptr)
		{
			npcbscDebugging=nullptr;
			ClientMessage("Disabled NPC debugging information");
		}
		return;
	}
	if (actHit->IsA("AAGP_Pawn::StaticClass()"))
	{
		if ((Cast<AAGP_Pawn>(actHit).Controller != nullptr) && Cast<AAGP_Pawn>(actHit).Controller->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			npcbscDebugging=NPCBaseSoldierController(Cast<AAGP_Pawn>(actHit).Controller);
			ClientMessage("Target status: " + Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).sTargetingStatus);
			ClientMessage("AICC Last Action: " + Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).sLastCombatAction);
			ClientMessage("AICC Next Action: " + Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).sNextAICCAction);
			ClientMessage("Enemy: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).Enemy));
			ClientMessage("State: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).GetStateName()));
			ClientMessage("Last State: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).GetLastStateName()));
			ClientMessage("Soldier info: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).Tag));
			ClientMessage("Weapon: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).Pawn.Weapon));
			ClientMessage("Order: " + FString::FromInt(Cast<ANPCBaseSoldierController>(Cast<AAGP_Pawn>(actHit).Controller).iNPCCurrentOrders));
			ClientMessage("Movement Anim: " + FString::FromInt(Cast<AAGP_Pawn>(actHit).MovementAnims[0]));
			ClientMessage("AnimAction: " + FString::FromInt(Cast<AAGP_Pawn>(actHit).AnimAction));
			ClientMessage("Weapon State: " + FString::FromInt(Cast<AAGP_Pawn>(actHit).Weapon.GetStateName()));
			SetCustomTimer(2,true,"DebugUpdateNPCDebuggingInfo");
		}
	}
	*/
}
void AHumanController::DebugUpdateNPCDebuggingInfo()
{
	FString sDebugInfo = "";
	/*
	if ((npcbscDebugging != nullptr) && (npcbscDebugging.Pawn != nullptr))
	{
		if (npcbscDebugging->IsA(ANPCMortarSpotterController::StaticClass()))
		{
			sDebugInfo=string(npcbscDebugging) + "." + FString::FromInt(npcbscDebugging.Tag) + " STATE: " + FString::FromInt(npcbscDebugging.GetStateName()) + " Anim: " + FString::FromInt(npcbscDebugging.Pawn.AnimAction) + " MovementAnims: " + FString::FromInt(npcbscDebugging.Pawn.MovementAnims[0]) + " WFM: " + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).bWatchingFireMission) + " TLOC: (" + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).vCurrentFireMissionLocation.X) + "," + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).vCurrentFireMissionLocation.Y) + "," + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).vCurrentFireMissionLocation.Z) + ") " + " PWNSN: " + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).pawnLastConsidered) + " TGTD: " + FString::FromInt(Cast<ANPCMortarSpotterController>(npcbscDebugging).pawnLastTargeted);
		}
		else
		{
			sDebugInfo=string(npcbscDebugging) + "." + FString::FromInt(npcbscDebugging.Tag) + " in state: " + FString::FromInt(npcbscDebugging.GetStateName()) + ", Targeting State: " + npcbscDebugging.sTargetingStatus + ", Enemy: " + FString::FromInt(npcbscDebugging.Enemy) + ", Last AICC: " + npcbscDebugging.sLastCombatAction + ", Next AICC: " + npcbscDebugging.sNextAICCAction;
		}
		DebugClientUpdateNPCDebuggingInfo(sDebugInfo);
	}
	else
	{
		DebugClientUpdateNPCDebuggingInfo("");
		StopCustomTimer("DebugUpdateNPCDebuggingInfo");
	}
	*/
}

void AHumanController::DebugClientUpdateNPCDebuggingInfo(FString sNewNPCDebuggingInfo)
{
	sNPCDebuggingInfo = sNewNPCDebuggingInfo;
}

void AHumanController::DebugGotoLocation(FString sLocX, FString sLocY, FString sLocZ)
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization() && PlayerReplicationInfo == nullptr || PlayerReplicationInfo._Group != 1)
	{
		Log("Invalid server setting access");
		return;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		if (Level.GetTourIsTraining(Level.iTour))
		{
			return;
		}
	}
	if (Len(sLocX) == 0 || Len(sLocY) == 0 || Len(sLocZ) == 0)
	{
		if (!Cast<AAGP_HUD>(MyHUD)->bShowCoords)
		{
			Cast<AAGP_HUD>(MyHUD)->bShowCoords = true;
		}
		ClientMessage("Current location: " + Pawn.Location);
		ClientMessage("Invalid location entered.  Use syntax: DebugGotoLocation x y z");
		return;
	}
	Log("Setting pawn location to " + sLocX + ", " + sLocY + ", " + sLocZ);
	if (Level.Game.CheatsDisabled())
	{
		return;
	}
	if (_CheatMonitor != nullptr)
	{
		_CheatMonitor.Notify();
	}
	if (EventLab != nullptr)
	{
		EventLab.EventLabNotifyCheat();
	}
	if (Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay().NotifyCheated();
	}
	if (!bGodMode)
	{
		MPCheat_God();
	}
	if (!IsInState('Flying'))
	{
		MPCheat_EnterGhostMode();
	}
	if (!Cast<AAGP_HUD>(MyHUD)->bShowCoords)
	{
		Cast<AAGP_HUD>(MyHUD)->bShowCoords = true;
	}
	Pawn.SetLocation(FVector(sLocX, sLocY, sLocZ));
	*/
}
void AHumanController::ServerRequestStat(FString sStatRequested)
{
	/*
	FString sValue;
	sValue = "" + Cast<AAGP_GameInfo>(GetGameMode()).GetStatForPlayer(this, sStatRequested);
	UE_LOG(LogTemp, Warning, TEXT("Retrieved stat " + sStatRequested + " value: " + sValue));
	ClientStatInfo(sStatRequested, sValue);
	*/
}
void AHumanController::ClientStatInfo(FString sStatRequested, FString sStatValue)
{
	/*
	if (guipStats != nullptr)
	{
		guipStats.NotifyStatsPage(sStatRequested, sStatValue);
	}
	*/
}
void AHumanController::DHHelp()
{
	ClientMessage("DHIncreaseRise");
	ClientMessage("DHDecreaseRise");
	ClientMessage("DHResetRise");
	ClientMessage("DHViewHelicopter <tag>");
	ClientMessage("DHViewNormal");
	ClientMessage("DHHover");
	ClientMessage("DHManual");
	ClientMessage("DHForward");
	ClientMessage("DHBackward");
	ClientMessage("DHTestPitch");
	ClientMessage("DHLandHere");
	ClientMessage("DHTakeOff");
	ClientMessage("DHShootDown");
	ClientMessage("DHSetMechanicalFailure <type> <chance> - sets failure of Engine, Rotor, or Cockpit chance (0 - 1.0) in next 2.5 minutes");
	ClientMessage("DHSetFlightSpeed <VeryFast,Fast,Medium,Slow,VerySlow");
	ClientMessage("DHRideHere - attempts to position you in crouched position in helicopter");
	ClientMessage("DHDemoRide - get in and ride blackhawk (if it's landed)");
	ClientMessage("DHVH - view first helicopter");
	ClientMessage("UAVCameraView - puts you in recon camera view of helicopter or UAV");
	ClientMessage("DHNextWaypoint");
}

void AHumanController::DHLandHere()
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).Land(Pawn->GetActorLocation(),Self);
		ClientMessage("Heading for landing zone");
	}

	*/
}

void AHumanController::DHNextWaypoint()
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).NextWaypoint();
		ClientMessage("Heading to waypoint set");
	}
	*/
}
void AHumanController::DHPatrol()
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).Patrol();
		ClientMessage("Patrolling");
	}
	*/
}
void AHumanController::DHSetMechanicalFailure(FString sType, float fpChance)
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		if (sType ~= "Engine")
		{
			Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).fpEngineFailureChance=fpChance;
		}
		else
		{
			if (sType ~= "Rotor")
			{
				Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).fpRotorFailurePossible=fpChance;
			}
			else
			{
				if (sType ~= "Cockpit")
				{
					Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).fpCockpitFailurePossible=fpChance;
				}
				else
				{
					ClientMessage("Invalid failure type.  Allowed types: Engine, Rotor, Cockpit");
					return;
				}
			}
		}
		ClientMessage("Mechanical failure possibility enabled");
	}
	*/
}

void AHumanController::DHHover()
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).Hover();
		ClientMessage("Hover set");
	}
	*/
}
void AHumanController::DHTakeOff()
{
	AActor* actHeli = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if ((ViewTarget != nullptr) && ViewTarget->IsA(AVehicle::StaticClass()))
	{
		actHeli=ViewTarget;
	}
	else
	{
		actHeli=DHFindViewHelicopter("first");
	}
	if (((actHeli != nullptr) && actHeli->IsA(AVehicle::StaticClass())) && Vehicle(actHeli).Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
	{
		Cast<ANPCBaseHelicopterController>(Cast<AVehicle>(actHeli).Controller).TakeOff();
		ClientMessage("Hover set");
	}
	*/
}

void AHumanController::DHVH(bool bThirdPersonView)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	/*
	DHViewHelicopter("first", bThirdPersonView);
	*/
}
void AHumanController::UAVCameraView()
{
}

void AHumanController::ClientUAVCameraView(AVehicle* vhUAVFound)
{
}

void AHumanController::UAVStart(FString sNPCTag)
{
}

void AHumanController::UAVView(FString sNPCTag, bool bThirdPersonView)
{
}

AVehicle* AHumanController::UAVFindViewUAV()
{
	return nullptr;
}
void AHumanController::UAVServerHeadForPlayer()
{
}
void AHumanController::UAVServerCircleHere()
{
}
void AHumanController::UAVServerTurnRight()
{
}
void AHumanController::UAVServerTurnLeft()
{
}
void AHumanController::UAVServerClimb()
{
}
void AHumanController::UAVServerDescend()
{
}
void AHumanController::UAVServerSpeedUp()
{
}
void AHumanController::UAVSpawn()
{
}
void AHumanController::UAVLaunch()
{
}
void AHumanController::UAVServerSlowDown()
{
}
void AHumanController::DHViewHelicopter(FString sNPCTag, bool bThirdPersonView)
{
	AVehicle* vhHelicopter = nullptr;
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	vhHelicopter = DHFindViewHelicopter(sNPCTag);
	if (vhHelicopter != nullptr)
	{
		ClientMessage("Switching view to helicopter " + vhHelicopter.Tag);
		ClientSetViewTarget2(vhHelicopter);
		if (bThirdPersonView)
		{
			bBehindView = false;
		}
		else
		{
			bBehindView = true;
		}
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->ShowDebug();
		}
	}
	else
	{
		ClientMessage("Unable to find helicopter " + sNPCTag);
	}
	*/
}

AVehicle* AHumanController::DHFindViewHelicopter(FString sNPCTag)
{
	AController* cIterator = nullptr;
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return nullptr;
	}
	for (cIterator = Level.ControllerList; cIterator != nullptr; cIterator = cIterator.nextController)
	{
		if (cIterator->IsA(ANPCBaseHelicopterController::StaticClass()))
		{
			if (((cIterator.Pawn != nullptr) && (string(cIterator.Pawn.Tag) == sNPCTag)) || (sNPCTag ~= "first"))
			{
				return Vehicle(cIterator.Pawn);
			}
		}
	}
	*/
	return nullptr;
}

void AHumanController::DHViewNormal()
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	/*
	if (GetNetMode() != ENetMode::NM_Standalone && !PlayerReplicationInfo.bAdmin && !Level.Game.AccessControl.IsPlayerAdmin(PlayerReplicationInfo))
	{
		Log("Invalid server setting access");
		return;
	}
	ClientMessage("Restoring view to player controlled pawn");
	if (Pawn != nullptr)
	{
		ClientSetViewTarget2(Pawn);
	}
	*/
}

FString AHumanController::ReplaceCommandString(FString Text)
{
	int32 pos1 = 0;
	int32 pos2 = 0;
	FString ActionKey = "";
	FString TempStr = "";
	FString FinalStr = "";
	/*
	pos1 = InStr(Text, "<");
	pos2 = InStr(Text, ">");
	if ((pos1 < 0) && (pos2 < 0))
	{
		return Text;
	}
	if ((pos1 >= 0) && (pos2 >= 0))
	{
		TempStr = Left(Text, pos1);
		ActionKey = Left(Text, pos2);
		ActionKey = Right(ActionKey, (Len(ActionKey) - (pos1 + 1)));
		TempStr = TempStr + GetCommandKey(ActionKey);
		Text = Right(Text, (Len(Text) - (pos2 + 1)));
		FinalStr = FinalStr + TempStr;
		pos1 = InStr(Text, "<");
		pos2 = InStr(Text, ">");
	}
	*/
	FinalStr = FinalStr + Text;
	return FinalStr;

}

FString AHumanController::GetCommandKey(FString cmdname)
{
	UConsole* Console = nullptr;
	FString cmdkeyname = "";
	EInputKey cmdkey = EInputKey::IK_None;
	int32 Count = 0;
	FString retval = "";
	retval = "<";
	cmdkeyname = "";
	Count = 0;
	/*
	Console = Player.Console;
	if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
	{
		if (Count > 0)
		{
			retval = retval + " or ";
		}
		retval = retval + Caps(cmdkeyname);
		Count++;
	}
	*/
	if (retval == "")
	{
		return "ERROR!";
	}
	return retval + ">";
}

void AHumanController::MaybeDelaySpawn()
{
	/*
	if (Cast<AAGP_GameInfo>(GetGameMode()).iDelayedRoundStartTimeSeconds > 0 && !Level.bDelayedSpawnNotAllowed)
	{
		ClientGotoState('DelayedStart', "None");
	}
	*/
}

void AHumanController::MaybeEnterPlayerWalkingState()
{
	/*
	if (GameReplicationInfo.iDelayedStartTimeRemaining <= 0 || Level.bDelayedSpawnNotAllowed)
	{
		ChangeState("PlayerWalking', "None");
	}
	*/
}

void AHumanController::ServerSpamLog()
{
}

void AHumanController::DemoRecToggleSound()
{
	AActor* A = nullptr;
	/*
	bDemoRecSounds = !bDemoRecSounds;
	ForEach AllActors(Class'Actor', A)
	{
		A.bDemoRecSounds = bDemoRecSounds;
	}
	if (bDemoRecSounds)
	{
		ClientMessage("DemoRec sounds on!");
	}
	else
	{
		ClientMessage("DemoRec sounds off!");
	}
	*/
}

void AHumanController::DemoRecToggleMuzzleFlash()
{
	AActor* A = nullptr;
	/*
	bDemoRecMuzzleFlash = !bDemoRecMuzzleFlash;
	ForEach AllActors(Class'Actor', A)
	{
		A.bDemoRecMuzzleFlash = bDemoRecMuzzleFlash;
	}
	if (bDemoRecMuzzleFlash)
	{
		ClientMessage("DemoRec muzzle flash on!");
	}
	else
	{
		ClientMessage("DemoRec muzzle flash off!");
	}
	*/
}

void AHumanController::DumpRelevantAI()
{
	ServerDumpRelevantAI();
}

void AHumanController::ServerDumpRelevantAI()
{
	AController* ctrlIterator = nullptr;
	ClientMessage("Dumping net relevant list to server log");
	/*
	for (ctrlIterator = Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator->nextController)
	{
		if (Cast<ANPCBaseController>(ctrlIterator) != nullptr)
		{
			//Log("Controller " + FString::FromInt(ctrlIterator.Tag) + " bNetRelevant: " + FString::FromInt(ctrlIterator.Pawn.bNetRelevant));
		}
	}
	*/
}

void AHumanController::DumpPathList(bool bDumpPaths)
{
	ANavigationPoint* npNavIterator = nullptr;
	int32 iPath = 0;
	int32 iCount = 0;
	for (npNavIterator = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; npNavIterator != nullptr; npNavIterator = npNavIterator->nextNavigationPoint)
	{
		//Log("Nav Point[ " + FString::FromInt(iCount++) + " ] " + FString::FromInt(npNavIterator) + " has these " + FString::FromInt(npNavIterator.PathList.Num()) + " paths: ");
		if (bDumpPaths)
		{
			for (iPath = 0; iPath < npNavIterator->PathList.Num(); iPath++)
			{
				//Log("Path[ " + FString::FromInt(iPath) + " ] => " + FString::FromInt(npNavIterator.PathList[iPath]) + " collision height: " + FString::FromInt(npNavIterator.PathList[iPath].CollisionHeight) + " type: " + FString::FromInt(npNavIterator.PathList[iPath].reachFlags));
			}
		}
	}
}

void AHumanController::TriggerClientEvent(FName EventName)
{
	//TriggerEvent(EventName, None, None);
}

void AHumanController::StatIncMissionAttempts()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsStarted;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundStarted();
	After = MyPlayerStats->RoundsStarted;
	UE_LOG(LogTemp, Log, TEXT("MissionAttempts: %d %d"), Before, After);
}

void AHumanController::StatIncMissionFailures()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsLost;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundLost();
	After = MyPlayerStats->RoundsLost;
	UE_LOG(LogTemp, Log, TEXT("RoundsLost: %d %d"), Before, After);
}

void AHumanController::StatIncMissionSuccesses()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->RoundsWon;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundWon();
	After = MyPlayerStats->RoundsWon;
	UE_LOG(LogTemp, Log, TEXT("RoundsWon: %d %d"), Before, After);
}

void AHumanController::StatIncObjectives()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->CapturedObjective;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CapturedObjective();
	After = MyPlayerStats->CapturedObjective;
	UE_LOG(LogTemp, Log, TEXT("CapturedObjective: %d %d"), Before, After);
}

void AHumanController::StatMissionFailureTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionFailureTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSMissionProgressTime = Time;
	After = MyPlayerStats->iESSMissionFailureTime;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionFailureTime: %d %d"), Before, After);
}

void AHumanController::StatMissionSuccessTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionSuccessTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSMissionSuccessTime = Time;
	After = MyPlayerStats->iESSMissionSuccessTime;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionSuccessTime: %d %d"), Before, After);
}

void AHumanController::StatMissionProgressTime(int32 Time)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->TimePlayed;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->TimePlayed = Time;
	After = MyPlayerStats->TimePlayed;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionProgressTime: %d %d"), Before, After);
}

void AHumanController::StatMissionTotalPlayers(int32 TotalPlayers)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionTotalPlayers;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundTotalPlayers(TotalPlayers);
	After = MyPlayerStats->iESSMissionTotalPlayers;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionTotalPlayers: %d %d"), Before, After);
}

void AHumanController::StatMissionPlayersSurviving(int32 PlayersSurviving)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSMissionSurvivingPlayers;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_RoundPlayersSurviving(PlayersSurviving);
	After = MyPlayerStats->iESSMissionSurvivingPlayers;
	UE_LOG(LogTemp, Log, TEXT("iESSMissionSurvivingPlayers: %d %d"), Before, After);
}

void AHumanController::StatIncObjectReported()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDiscovered;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectDiscovered(Blank);
	After = MyPlayerStats->iESSObjectDiscovered;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDiscovered: %d %d"), Before, After);
}

void AHumanController::StatIncObjectExaminedByOtherPlayer()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectExaminedByOtherPlayer;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectExaminedByOtherPlayer();
	After = MyPlayerStats->iESSObjectExaminedByOtherPlayer;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectExaminedByOtherPlayer: %d %d"), Before, After);
}

void AHumanController::StatIncObjectDiscoveryRadioed()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDiscoveryRadioed;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectDiscoveryRadioed();
	After = MyPlayerStats->iESSObjectDiscoveryRadioed;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDiscoveryRadioed: %d %d"), Before, After);
}

void AHumanController::StatIncNoRadioExaminedObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSNoRadioExaminedObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSNoRadioExaminedObject();
	After = MyPlayerStats->iESSNoRadioExaminedObject;
	UE_LOG(LogTemp, Log, TEXT("iESSNoRadioExaminedObject: %d %d"), Before, After);
}

void AHumanController::StatIncPostRadioExaminedObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPostRadioExaminedObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSPostRadioExaminedObject();
	After = MyPlayerStats->iESSPostRadioExaminedObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPostRadioExaminedObject: %d %d"), Before, After);
}

void AHumanController::StatIncPostRadioLinkedObjectTaken()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPostRadioLinkedObjectTaken;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSPostRadioLinkedObjectTaken();
	After = MyPlayerStats->iESSPostRadioLinkedObjectTaken;
	UE_LOG(LogTemp, Log, TEXT("iESSPostRadioLinkedObjectTaken: %d %d"), Before, After);
}

void AHumanController::StatIncNoRadioLinkedObjectTaken()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSNoRadioLinkedObjectTaken;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSNoRadioLinkedObjectTaken();
	After = MyPlayerStats->iESSNoRadioLinkedObjectTaken;
	UE_LOG(LogTemp, Log, TEXT("iESSNoRadioLinkedObjectTaken: %d %d"), Before, After);
}

void AHumanController::StatIncObjectReportable()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectAvailable;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ESSObjectAvailable();
	After = MyPlayerStats->iESSObjectAvailable;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectAvailable: %d %d"), Before, After);
}

void AHumanController::StatIncLethalObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportedLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportedLethal();
	After = MyPlayerStats->iESSObjectReportedLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportedLethal: %d %d"), Before, After);
}

void AHumanController::StatIncNonLethalObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportedNonLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportedNonLethal();
	After = MyPlayerStats->iESSObjectReportedNonLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportedNonLethal: %d %d"), Before, After);
}

void AHumanController::StatReportableLethalObjects(int32 NumObjects)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportableLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportableLethal(NumObjects);
	After = MyPlayerStats->iESSObjectReportableLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportableLethal: %d %d"), Before, After);
}

void AHumanController::StatReportableNonLethalObjects(int32 NumObjects)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportableNonLethal;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportableNonLethal(NumObjects);
	After = MyPlayerStats->iESSObjectReportableNonLethal;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportableNonLethal: %d %d"), Before, After);
}

void AHumanController::StatListUnreportedLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectUnreportedLocations;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSObjectUnreportedLocations = List;
	After = MyPlayerStats->iESSObjectUnreportedLocations;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectUnreportedLocations: %s %s"), *Before, *After);
}

void AHumanController::StatIncObjectReportingErrors()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectReportingErrors;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectReportingErrors();
	After = MyPlayerStats->iESSObjectReportingErrors;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectReportingErrors: %d %d"), Before, After);
}

void AHumanController::StatIncObjectUnnecessaryUse()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectUnnecessaryUse;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ObjectUnnecessaryUse();
	After = MyPlayerStats->iESSObjectUnnecessaryUse;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectUnnecessaryUse: %d %d"), Before, After);
}

void AHumanController::StatListObjectDistribution(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSObjectDistribution;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSObjectDistribution = List;
	After = MyPlayerStats->iESSObjectDistribution;
	UE_LOG(LogTemp, Log, TEXT("iESSObjectDistribution: %s %s"), *Before, *After);
}
void AHumanController::StatIncShotsFired()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->ShotsFiredAstRifle;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ShotFiredAssaultRifle();
	After = MyPlayerStats->ShotsFiredAstRifle;
	UE_LOG(LogTemp, Log, TEXT("ShotsFiredAstRifle: %d %d"), Before, After);
}
void AHumanController::StatIncShotsHit()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->HitsAstRifle;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ShotHitAssaultRifle();
	After = MyPlayerStats->HitsAstRifle;
	UE_LOG(LogTemp, Log, TEXT("HitsAstRifle: %d %d"), Before, After);
}
void AHumanController::StatIncHeadshots()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatHeadshots;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatHeadshots();
	After = MyPlayerStats->iESSCombatHeadshots;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatHeadshots: %d %d"), Before, After);
}

void AHumanController::StatTotalDamage(int32 NewDamage)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatTotalDamage;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatTotalDamage(NewDamage);
	After = MyPlayerStats->iESSCombatTotalDamage;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatTotalDamage: %d %d"), Before, After);
}

void AHumanController::StatIncDamageInstances()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatDamageCount;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatDamageCount();
	After = MyPlayerStats->iESSCombatDamageCount;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatDamageCount: %d %d"), Before, After);
}

void AHumanController::StatEnemyContactTime(float Seconds)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatEnemyContactTime;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatEnemyContactTime(Seconds);
	After = MyPlayerStats->iESSCombatEnemyContactTime;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatEnemyContactTime: %d %d"), Before, After);
}

void AHumanController::StatSurvivingAI(int32 NumAIs)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSCombatSurvivingAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_CombatSurvivingAI(NumAIs);
	After = MyPlayerStats->iESSCombatSurvivingAI;
	UE_LOG(LogTemp, Log, TEXT("iESSCombatSurvivingAI: %d %d"), Before, After);
}

void AHumanController::StatIncTotalDeaths()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->Deaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_Death(Blank);
	After = MyPlayerStats->Deaths;
	UE_LOG(LogTemp,Log, TEXT("Deaths: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByAI()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByAI();
	After = MyPlayerStats->iESSPlayerTotalDeathsByAI;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByAI: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByFriendlyFire()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByFriendlyFire;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByFriendlyFire();
	After = MyPlayerStats->iESSPlayerTotalDeathsByFriendlyFire;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByFriendlyFire: %d %d"), Before, After);
}

void AHumanController::StatIncDeathByObject()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalDeathsByObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalDeathsByObject();
	After = MyPlayerStats->iESSPlayerTotalDeathsByObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalDeathsByObject: %d %d"), Before, After);
}

void AHumanController::StatListDeathLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerDeathLocation;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSPlayerDeathLocation = List;
	After = MyPlayerStats->iESSPlayerDeathLocation;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerDeathLocation: %s %s"), *Before, *After);
}

void AHumanController::StatLifeDuration(int32 Duration)
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->TimeAlive;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->TimeAlive = Duration;
	After = MyPlayerStats->TimeAlive;
	UE_LOG(LogTemp, Log, TEXT("TimeAlive: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuries()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuries;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuries(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuries;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuries: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByAI()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesByAI;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByAI(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesByAI;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesByAI: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByFriendlyFire()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesFriendlyFire;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByFriendlyFire(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesFriendlyFire;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesFriendlyFire: %d %d"), Before, After);
}

void AHumanController::StatIncTotalInjuriesByObject()
{
	FVector Blank;
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerTotalInjuriesByObject;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_PlayerTotalInjuriesByObject(Blank);
	After = MyPlayerStats->iESSPlayerTotalInjuriesByObject;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerTotalInjuriesByObject: %d %d"), Before, After);
}

void AHumanController::StatListInjuryLocations(FString List)
{
	FString Before;
	FString After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSPlayerInjuryLocation;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->iESSPlayerInjuryLocation = List;
	After = MyPlayerStats->iESSPlayerInjuryLocation;
	UE_LOG(LogTemp, Log, TEXT("iESSPlayerInjuryLocation: %s %s"), *Before, *After);
}

void AHumanController::StatIncFriendlyFire()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROEFriendlyFireHits;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROEFriendlyFireHits();
	After = MyPlayerStats->iESSROEFriendlyFireHits;
	UE_LOG(LogTemp, Log, TEXT("iESSROEFriendlyFireHits: %d %d"), Before, After);
}

void AHumanController::StatIncFriendlyFireDeaths()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROEFriendlyFireDeaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROEFriendlyFireDeaths();
	After = MyPlayerStats->iESSROEFriendlyFireDeaths;
	UE_LOG(LogTemp, Log, TEXT("iESSROEFriendlyFireDeaths: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianHits()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianHits;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianHits();
	After = MyPlayerStats->iESSROECivilianHits;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianHits: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianDeaths()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianDeaths;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianDeaths();
	After = MyPlayerStats->iESSROECivilianDeaths;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianDeaths: %d %d"), Before, After);
}

void AHumanController::StatIncCivilianDeathsByIED()
{
	int32 Before;
	int32 After;
	ASTS2_PlayerStatsInfo* MyPlayerStats;
	MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex]);
	Before = MyPlayerStats->iESSROECivilianDeathsByIED;
	Cast<ASTS2_PlayerStatsInfo>(Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->Stats->PlayerStats[PlayerStatsIndex])->StatEvent_ROECivilianDeathsByIED();
	After = MyPlayerStats->iESSROECivilianDeathsByIED;
	UE_LOG(LogTemp, Log, TEXT("iESSROECivilianDeathsByIED: %d %d"), Before, After);
}

void AHumanController::LogES2Stats()
{
	StatIncMissionAttempts();
	StatIncMissionFailures();
	StatIncMissionSuccesses();
	StatIncObjectives();
	StatMissionFailureTime(5);
	StatMissionSuccessTime(5);
	StatMissionProgressTime(5);
	StatMissionTotalPlayers(5);
	StatMissionPlayersSurviving(5);
	StatIncObjectReported();
	StatIncObjectExaminedByOtherPlayer();
	StatIncObjectDiscoveryRadioed();
	StatIncNoRadioExaminedObject();
	StatIncPostRadioExaminedObject();
	StatIncPostRadioLinkedObjectTaken();
	StatIncNoRadioLinkedObjectTaken();
	StatIncObjectReportable();
	StatIncLethalObject();
	StatIncNonLethalObject();
	StatReportableLethalObjects(5);
	StatReportableNonLethalObjects(5);
	StatListUnreportedLocations("1 2 3");
	StatIncObjectReportingErrors();
	StatIncObjectUnnecessaryUse();
	StatListObjectDistribution("1 2 3");
	StatIncShotsFired();
	StatIncShotsHit();
	StatIncHeadshots();
	StatTotalDamage(5);
	StatIncDamageInstances();
	StatEnemyContactTime(9.9);
	StatSurvivingAI(5);
	StatIncTotalDeaths();
	StatIncDeathByAI();
	StatIncDeathByFriendlyFire();
	StatIncDeathByObject();
	StatListDeathLocations("1 2 3");
	StatLifeDuration(5);
	StatIncTotalInjuries();
	StatIncTotalInjuriesByAI();
	StatIncTotalInjuriesByFriendlyFire();
	StatIncTotalInjuriesByObject();
	StatListInjuryLocations("1 2 3");
	StatIncFriendlyFire();
	StatIncFriendlyFireDeaths();
	StatIncCivilianHits();
	StatIncCivilianDeaths();
	StatIncCivilianDeathsByIED();
}

void AHumanController::ClientCloseMenu(bool bCloseAll, bool bCancel)
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

//From Controller:
int32 AHumanController::GetTeamNum()
{
	if (PlayerReplicationInfo == nullptr || PlayerReplicationInfo->Team == nullptr)
	{
		return 255;
	}
	return PlayerReplicationInfo->Team->TeamIndex;
}

void AHumanController::SwitchToBestWeapon()
{
	//float rating;
	if (Cast<AAGP_Pawn>(GetPawn()) == nullptr || Cast<AAGP_Pawn>(GetPawn())->Inventory == nullptr)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == nullptr || Cast<AaAIController>(this) != nullptr)
	{
		//Cast<AAGP_Pawn>(GetPawn())->PendingWeapon = Cast<AAGP_Pawn>(GetPawn())->Inventory->RecommendWeapon(rating);
		if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == Cast<AAGP_Pawn>(GetPawn())->Weapon)
		{
			Cast<AAGP_Pawn>(GetPawn())->PendingWeapon = nullptr;
		}
		if (Cast<AAGP_Pawn>(GetPawn())->PendingWeapon == nullptr)
		{
			return;
		}
	}
	//StopFiring();
	if (Cast<AAGP_Pawn>(GetPawn())->Weapon == nullptr)
	{
		Cast<AAGP_Pawn>(GetPawn())->ChangedWeapon();
	}
	else
	{
		if (Cast<AAGP_Pawn>(GetPawn())->Weapon != Cast<AAGP_Pawn>(GetPawn())->PendingWeapon)
		{
			Cast<AAGP_Pawn>(GetPawn())->Weapon->PutDown();
		}
	}
}

void AHumanController::ClientSwitchToBestWeapon()
{
	SwitchToBestWeapon();
}

void AHumanController::ClientSetWeapon(AWeapon* WeaponClass)
{
	AInventory* Inv = nullptr;
	int32 Count = 0;
	/*
	Inv = Pawn.Inventory;
	if (Inv != nullptr)
	{
		Count++;
		if (Count > 1000)
		{
			return;
		}
		if (!ClassIsChildOf(Inv.Class, WeaponClass))
		{
		}
		if (Pawn.Weapon == nullptr)
		{
			Pawn.PendingWeapon = Cast<AWeapon>(Inv);
			Pawn.ChangedWeapon();
		}
		else
		{
			if (Pawn.Weapon != Cast<AWeapon>(Inv))
			{
				Pawn.PendingWeapon = Cast<AWeapon>(Inv);
				Pawn.Weapon.PutDown();
			}
		}
		return;
		Inv = Inv.Inventory;
	}
	*/
}

void AHumanController::WaitForMover(AMover* M)
{
}

//From PlayerController
void AHumanController::ClientSetScoreMode(bool bAllowsLocalScore)
{
	bAllowScoreShown = bAllowsLocalScore;
}

bool AHumanController::GetMilesOnly()
{
	return false;
}

void AHumanController::AddMBSAttributes(TArray<FKeyValuePair> &Attributes)
{
	ASTS2_PlayerStatsInfo* MyPlayerStatsInfo = nullptr;
	int32 ShotsTotal = 0;
	int32 HitsTotal = 0;
	/*
	if (Level.Game.Stats != nullptr && PlayerStatsIndex >= 0)
	{
		MyPlayerStatsInfo = STS2_PlayerStatsInfo(Level.Game.Stats.PlayerStats[PlayerStatsIndex]);
		ShotsTotal = MyPlayerStatsInfo.ShotsFiredGrenade + MyPlayerStatsInfo.ShotsFiredAstRifle + MyPlayerStatsInfo.ShotsFiredPistol + MyPlayerStatsInfo.ShotsFiredMG + MyPlayerStatsInfo.ShotsFiredRocket + MyPlayerStatsInfo.ShotsFiredSprRifle;
		HitsTotal = MyPlayerStatsInfo.HitsGrenade + MyPlayerStatsInfo.HitsAstRifle + MyPlayerStatsInfo.HitsPistol + MyPlayerStatsInfo.HitsMG + MyPlayerStatsInfo.HitsRocket + MyPlayerStatsInfo.HitsSprRifle;
	}
	AddMBSAttributes(Attributes);
	ADBMBS::StaticClass().AddAttribute(Attributes, "spectator", ADBMBS::StaticClass().BoolToIntString(PlayerReplicationInfo.bOnlySpectator));
	ADBMBS::StaticClass().AddAttribute(Attributes, "honor", PlayerReplicationInfo.GetHonor());
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr)
	{
		ADBMBS::StaticClass().AddAttribute(Attributes, "class", Cast<AAGP_Pawn>(GetPawn()).TeamClass.GetClassID());
		ADBMBS::StaticClass().AddAttribute(Attributes, "role", Cast<AAGP_Pawn>(GetPawn()).TeamRole);
		if (Pawn.Weapon != nullptr)
		{
			ADBMBS::StaticClass().AddAttribute(Attributes, "currentWeapon", Pawn.Weapon.ItemName);
		}
	}
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreTotal", PlayerReplicationInfo.Score_Total);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreLeadership", PlayerReplicationInfo.Score_Leadership);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreObjectives", PlayerReplicationInfo.Score_Objectives);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreWins", PlayerReplicationInfo.Score_Wins);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreROE", PlayerReplicationInfo.Score_ROE);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreDeaths", PlayerReplicationInfo.Score_Deaths);
	ADBMBS::StaticClass().AddAttribute(Attributes, "scoreKills", PlayerReplicationInfo.Score_Kills);
	ADBMBS::StaticClass().AddAttribute(Attributes, "shotsFired", ShotsTotal);
	ADBMBS::StaticClass().AddAttribute(Attributes, "shotsHit", HitsTotal);
	ADBMBS::StaticClass().AddAttribute(Attributes, "team", PlayerReplicationInfo->Team->GetHumanReadableName());
	ADBMBS::StaticClass().AddAttribute(Attributes, "timePlayed", PlayerReplicationInfo.GetPlayTime());
	ADBMBS::StaticClass().AddAttribute(Attributes, "keyboardLocale", SystemLanguage);
	*/
}

void AHumanController::ServerMissionCompleteAuthorizeComplete(int32 Code, FAuthJacket Jacket)
{
	//UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerMissionCompleteAuthorizeComplete for " + UserName + " = " @ Code @ AuthJacketToString(Jacket)));
	switch(Code)
	{
		case 1:
			//SetFromAuthJacket(Jacket);
			//VerifyJacket();
			//SendAuthJacketToClient(Jacket);
			return;
		case -1:
			ClientMessage(WrongUserPassword);
			break;
		case -2:
			ClientMessage(NoUserRecord);
			break;
		case -3:
			ClientMessage(UserIsBanned);
			break;
		case -4:
			ClientMessage(ResponseTimeOut);
			break;
		case -5:
			ClientMessage(ServerNotRegistered);
			break;
		case -6:
			ClientMessage(BetaServer);
			break;
		case -7:
			//ClientSetPMessage(0);
			break;
		case -8:
			UE_LOG(LogTemp, Warning, TEXT("HumanController::ServerMissionCompleteAuthorizeComplete AuthServer says we tried to set honor to 0!!!"));
			break;
		default:
			ClientMessage("Unable to record your mission completion (Mission is probably not in auth database yet)");
			break;
	}
	UE_LOG(LogTemp, Warning, TEXT("HumanController:ServerMissionCompleteAuthorizeComplete - Done! for %s"), *UserName);
}

void AHumanController::AuthGetJacketCallback(int32 ResultCode, FAuthPersonnelJacket Jacket)
{
	if (ResultCode > 0)
	{
		UserAuthID = Jacket.UserID;
		VerifyJacket();
		SaveJacket();
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->RefreshTourMissionDisplays();
		}
		SetLoginStatus(2, "Transmission Completed", "Click to return to the main menu.");
	}
	else
	{
		//SetLoginStatus(ResultCode, AuthErrorMessage1, AuthErrorMessage2);
	}
}

void AHumanController::CopyAuthExtraMissionDataToAdapter(AMissionCompleteRequestAdapter* Adapter)
{
	int32 ii;
	for (ii = 0; ii < iAuthMissionDataFields; ii++)
	{
		Adapter->AddExtraMissionData(asAuthMissionData[ii]);
	}
}

void AHumanController::TournamentServerCaptainLockWeaponClasses(AAA2_PlayerState* PRI, bool fLock)
{
	//GameReplicationInfo.Teams[PRI.Team.TeamIndex].bTournamentTeamRosterLocked = fLock;
}

void AHumanController::TournamentRequestTeamCaptain(AAA2_PlayerState* PRI)
{
	AController* ctrlrScan = nullptr;
	FString sResponse = "";
	/*
	if (GameReplicationInfo->bTournamentTeamCaptainsAllowed == false)
	{
		ClientMessage("Team Captains are not allowed in this tournament.");
		return;
	}
	if (PRI->Team->TeamIndex == 255)
	{
		ClientMessage("You must join a team first.");
		return;
	}
	if (PRI->bTournamentTeamCaptain)
	{
		PRI.bTournamentTeamCaptain = false;
		GameReplicationInfo->Teams[PRI->Team->TeamIndex]->bTournamentTeamCaptainSelected = false;
		GameReplicationInfo->Teams[PRI->Team->TeamIndex]->bTournamentTeamRosterLocked = false;
		sResponse = PRI->PlayerName + " is no longer " + GameReplicationInfo.asTournamentTeamName[PRI->Team.TeamIndex] + "'s team captain.";
		for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan->nextController)
		{
			if (ctrlrScan->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(ctrlrScan).TeamMessage(nullptr, sResponse, "TMStatus");
				if (ctrlrScan.PlayerReplicationInfo->Team->TeamIndex == PlayerReplicationInfo->Team-<TeamIndex)
				{
					if (Cast<AHumanController>(ctrlrScan).MyHUD != nullptr)
					{
						Cast<AAGP_HUD>(Cast<AHumanController>(ctrlrScan).MyHUD).TournamentNotifyNewTeamCaptain();
					}
				}
			}
		}
		return;
	}
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan.nextController)
	{
		if (ctrlrScan->IsA(AHumanController::StaticClass()))
		{
			if (ctrlrScan.PlayerReplicationInfo->Team->TeamIndex == PRI->Team.TeamIndex)
			{
				if (ctrlrScan.PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					TeamMessage(nullptr, "" + ctrlrScan.PlayerReplicationInfo.PlayerName + " is already team captain.", "TMCenter");
					return;
				}
			}
		}
	}
	PRI->bTournamentTeamCaptain = true;
	GameReplicationInfo.Teams[PRI->Team.TeamIndex].bTournamentTeamCaptainSelected = true;
	sResponse = PRI->PlayerName + " is now ";
	if (GameReplicationInfo.asTournamentTeamName[PRI->Team.TeamIndex] != "")
	{
		sResponse = sResponse + GameReplicationInfo.asTournamentTeamName[PRI->Team.TeamIndex];
	}
	else
	{
		sResponse = sResponse + Level.TeamName[PRI->Team->TeamIndex];
	}
	sResponse = sResponse + "'s team captain.";
	for (ctrlrScan = Level.ControllerList; ctrlrScan != nullptr; ctrlrScan = ctrlrScan->nextController)
	{
		if (ctrlrScan->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(ctrlrScan)->TeamMessage(nullptr, sResponse, "TMStatus");
			if (ctrlrScan->PlayerReplicationInfo->Team.TeamIndex == PlayerReplicationInfo->Team->TeamIndex)
			{
				Cast<AHumanController>(ctrlrScan)->TournamentCaptainAdminMessage(sResponse);
				Cast<AHumanController>(ctrlrScan)->TournamentNotifyNewTeamCaptain();
			}
		}
	}
	*/
}

void AHumanController::TournamentServerRequestTeamCaptain(AAA2_PlayerState* PRI)
{
}

void AHumanController::TournamentServerAssignClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlot)
{
	Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->TournamentAssignClass(PRI, iUnitID, iSlot);
}

void AHumanController::TournamentServerRemoveClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlot)
{
}

void AHumanController::TournamentServerAdminAssignPlayerToTeam(int32 iTeamIndex, AAA2_PlayerState* PRI)
{
	bool bResult = false;
	AController* ctrlrScan = nullptr;
	AHumanController* hcPlayerToAssign = nullptr;
	/*
	if (Level.Game.TournamentGetTeam(iTeamIndex).Size > Level.Game.TournamentGetMaxTeamSize())
	{
		return;
	}
	ctrlrScan = Level.ControllerList;
	if (ctrlrScan != nullptr)
	{
		if (Cast<APlayerController>(ctrlrScan) != nullptr && PlayerController(ctrlrScan).PlayerReplicationInfo == PRI)
		{
			hcPlayerToAssign = Cast<AHumanController>(ctrlrScan);
		}
		else
		{
			ctrlrScan = ctrlrScan.nextController;
		}
	}
	if (hcPlayerToAssign == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TournamentServerAdminAssignPlayerToTeam() Couldn't find player's controller"));
		return;
	}
	bResult = Level.Game.TournamentJoinTeam(hcPlayerToAssign, iTeamIndex, TournamentGetTeamPasswordFor(iTeamIndex));
	hcPlayerToAssign.TournamentNotifyPlayerJoinedTeam(iTeamIndex, bResult, true);
	*/
}

/*
* Already exists in PlayerController with different def
void AHumanController::PreClientTravel()
{
	//UE_LOG(LogTemp, Warning, TEXT("HumanController::PreClientTravel() entered"));
	//Super::PreClientTravel();
}
*/

void AHumanController::ServerSendClientNotifyAdminMessage(AAA2_PlayerState* priPlayer, FString sMsg)
{
	/*
	if (GetPlayerFromID(priPlayer->PlayerID) != nullptr)
	{
		Cast<AHumanController>(GetPlayerFromID(priPlayer->PlayerID))->ClientNotifyAdminMessage(sMsg);
	}
	*/
}

void AHumanController::TeamMessage(AAA2_PlayerState* PRI, FString S, FName Type)
{
	FString ConsoleString = "";
	FColor Color = FColor(0,0,0,0);
	FString sCleanedPlayerName = "";
	/*
	S = SubstituteKeyNames(S);
	S = ApplyFilters(S);
	UE_LOG(LogTemp, Warning, TEXT("TeamMessage received: " + S));
	if (AllowTextToSpeech(PRI, Type))
	{
		TextToSpeech(S, TextToSpeechVoiceVolume);
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		ConsoleString = "";
		UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage() - Teammessage with type " + Type + ": " + S));
		if (PRI != nullptr)
		{
			if (Type != 'Event' || Type == "None")
			{
				UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage() - Teammessage with PRI " + PRI + " playername " + PRI.PlayerName + " string " + S + " type " + Type));
				sCleanedPlayerName = ApplyFilters(PRI.PlayerName);
				if (PRI.PlayerName ~= sCleanedPlayerName)
				{
					ConsoleString = "" + PRI.PlayerName;
				}
				else
				{
					ConsoleString = "[" + sCleanedPlayerName + "]";
				}
				UE_LOG(LogTemp, Warning, TEXT("HumanController::TeamMessage(" + PRI + ", " + S + ", " + Type + ") - " + PRI.bAdmin));
				if (PRI.bAdmin)
				{
					Color.R = 0;
					Color.G = 0;
					Color.B = 180;
					Color.A = 255;
					ConsoleString = "[Admin]" @ ConsoleString;
				}
				else
				{
					if (PlayerReplicationInfo->Team->TeamIndex == PRI.Team.TeamIndex)
					{
						Color.R = 0;
						Color.G = 0;
						Color.B = 180;
						Color.A = 255;
						ConsoleString = "[US Army]" @ ConsoleString;
					}
					else
					{
						Color.R = 180;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = "[Enemy]" @ ConsoleString;
					}
				}
			}
			switch(Type)
			{
					case 'AIKiller':
						Color.R = 0;
						Color.G = 0;
						Color.B = 180;
						Color.A = 255;
						break;
					case 'AIKilled':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						break;
					case 'TMCenter':
					case 'TMStatus':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = "";
						break;
					case 'AdminSay':
						Color.R = 255;
						Color.G = 0;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "ADMIN MESSAGE: ";
						break;
					case 'CommandChat':
						Color.R = 82;
						Color.G = 82;
						Color.B = 159;
						Color.A = 0;
						ConsoleString = ConsoleString @ "COMMAND MESSAGE: ";
						break;
					case 'Say':
					case 'Global':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "messaged: ";
						break;
					case 'TeamSay':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "team messaged: ";
						break;
					case 'Whisper':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "whispered: ";
						break;
					case 'shout':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "shouted: ";
						S = Caps(S);
						break;
					case 'Radio':
					case 'Squad':
						Color.R = 0;
						Color.G = 180;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "radioed: ";
						break;
					case 'ReportIn':
						Color.R = 0;
						Color.G = 200;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "reporting in: ";
						break;
					case 'cheat':
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						ConsoleString = ConsoleString @ "cheated: ";
						break;
					case 'ReportESSObjective':
						Color.R = 0;
						Color.G = 200;
						Color.B = 0;
						Color.A = 255;
						ConsoleString = ConsoleString @ "reporting: ";
						break;
					case 'ES2CoopMessage':
						ConsoleString = "";
						Color.R = 255;
						Color.G = 255;
						Color.B = 0;
						Color.A = 255;
						break;
					default:
						Color.R = 255;
						Color.G = 255;
						Color.B = 255;
						Color.A = 255;
						break;
			}
		}
		else
		{
			if (Type == 'TMStatus' || Type == 'TMCenter' || Type == 'AIKilled')
			{
				Color.R = 255;
				Color.G = 0;
				Color.B = 0;
				Color.A = 255;
			}
			else
			{
				if (Type == 'AIKiller')
				{
					Color.R = 0;
					Color.G = 0;
					Color.B = 180;
					Color.A = 255;
				}
			}
		}
		ConsoleString = ConsoleString @ S;
	}
	if (MyHUD != nullptr)
	{
		if (Type == 'Center' || Type == 'TMCenter')
		{
			MyHUD.DisplayCenteredMessageLong(4.5, ConsoleString);
		}
		Player.Console.Message(ConsoleString, 20, Color);
		MyHUD.Message(PRI, S, Type);
	}
	*/
}

/*
AActor* AHumanController::GetViewTarget(AActor* VTA)
{
	AController* C = nullptr;
	C = Cast<AController>(VTA);
	if (C != nullptr)
	{
		return C->GetPawn();
	}
	else
	{
		return VTA;
	}
}
*/

/*
* Already exists in PlayerController with different def
void AHumanController::ClientSetViewTarget(AActor* Target)
{
	//Global.leader_1(Target);
}
*/

/*
* Already exists in PlayerController with different def
void AHumanController::ClientReStart(APawn* NewPawn, bool bDontClearLevelParam)
{
	if (!bDontClearLevelParam)
	{
		CleanupLevel();
	}
	if (Cast<AAGP_HUD>(MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(MyHUD)->bDrawHUD = true;
		Cast<AAGP_HUD>(MyHUD)->bShowScores = false;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client Restart Failed."));
	}
	bLostViewTarget = false;
	ClientReStart(NewPawn);
	ClientSetBehindView(false);
	abpobjESSLastSeen = nullptr;
	if (aagpobjSeen.Num() > 0)
	{
		aagpobjSeen.RemoveAt(0, aagpobjSeen.Num());
	}
	LastReportableNPC = nullptr;
	fpWaitingForDelayedGrenade = 0;
}
*/

/*
* Already exists in PlayerController with different def
void AHumanController::ClientGameEnded()
{
	int32 i = 0;
	TArray<AVoiceChatRoom*> Channels = {};
	if (bVoiceChatEnabled && PlayerReplicationInfo != nullptr && VoiceReplicationInfo != nullptr)
	{
		Channels = VoiceReplicationInfo.GetChannels();
		for (i = 0; i < Channels.Num(); i++)
		{
			if (Channels[i] != nullptr && Channels[i].IsMember(PlayerReplicationInfo, true))
			{
				RejoinChannels[RejoinChannels.Num()] = Channels[i].GetTitle();
			}
		}
		if (ActiveRoom != nullptr)
		{
			LastActiveChannel = ActiveRoom.GetTitle();
		}
	}
	if (RejoinChannels.Num() > 0 || LastActiveChannel != "")
	{
		SaveConfig();
	}
	if (bPBChecked == false)
	{
		return;
	}
	if (PlayerReplicationInfo.bOnlySpectator)
	{
		return;
	}
	ClientGameEnded();
	if (Pawn != nullptr)
	{
		Pawn.bWantsToProne = false;
		Pawn.bWantsToCrouch = false;
	}
	CleanOutSavedMoves();
}
*/

void AHumanController::SendAuthJacketToClient(FAuthJacket Jacket)
{
	if (GetNetMode()==ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Warning, TEXT("HumanController::SendAuthJacketToClient(%s)"), *AuthJacketToString(Jacket));
		//SetFromAuthJacket(Jacket);
		VerifyJacket();
		SaveJacket();
		if (Cast<AAGP_HUD>(MyHUD) != nullptr)
		{
			Cast<AAGP_HUD>(MyHUD)->RefreshTourMissionDisplays();
		}
	}
}

void AHumanController::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		bPlayerIsReadyToPlay = true;
	}
	if (DesiredTeamClass == nullptr)
	{
		DesiredTeamClass = class<SoldierClass>(DynamicLoadObject(DesiredTeamClassName, Class'Class'));
	}
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo.sCurrentWeaponClass = "" + DesiredTeamClass;
	}
	SetHUDAlpha(HUDAlpha);
	SetHUDColor(HUDColor);
	SetHUDCrosshair(HUDCrosshair);
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetWeaponMods();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels.Num() > 0)
	{
		RadarSetZoom(Cast<AAA2_WorldSettings>(GetWorldSettings())->RadarZoomLevels[0]);
	}
	*/
}
void AHumanController::PreBeginPlay()
{
	/*
	RestoreSavedUserNameAndPassword();
	Super::PreBeginPlay();
	if (_FlashEffect == nullptr)
	{
		_FlashEffect = new (None) UCamEffect_FlashBang::StaticClass();
	}
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		SetDevMode(false);
	}
	if (guipCommandPost != nullptr)
	{
		ClientCloseMenu(true);
		guipCommandPost = nullptr;
	}
	*/
}
void AHumanController::Destroyed()
{
	/*
	int32 iETACtrlIndex;
	if (GetNetMode() != ENetMode::NM_DedicatedServer && Level.Game != nullptr && Level.Game.GetScreenplay() != nullptr)
	{
		Level.Game.GetScreenplay()._HumanController = nullptr;
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		SetLoginStatus(0, "", "");
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
		{
			iETACtrlIndex = 0;
			if (iETACtrlIndex < 26)
			{
				if (Level.actrlETAUsedFirstNamePrefixes[iETACtrlIndex] == this)
				{
					Level.actrlETAUsedFirstNamePrefixes[iETACtrlIndex] = nullptr;
				}
				else
				{
					iETACtrlIndex++;
				}
			}
		}
	}
	if (TournamentIsTournament())
	{
		if (PlayerReplicationInfo.bAdmin)
		{
			if (GameReplicationInfo.Teams[0].bTournamentTeamRosterLocked)
			{
				GameReplicationInfo.Teams[0].bTournamentTeamRosterLocked = false;
			}
			if (GameReplicationInfo.Teams[1].bTournamentTeamRosterLocked)
			{
				GameReplicationInfo.Teams[1].bTournamentTeamRosterLocked = false;
			}
		}
		else
		{
			if (PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				GameReplicationInfo.Teams[PlayerReplicationInfo->Team->TeamIndex].bTournamentTeamCaptainSelected = false;
				GameReplicationInfo.Teams[PlayerReplicationInfo->Team->TeamIndex].bTournamentTeamRosterLocked = false;
			}
		}
	}
	*/

	Super::Destroyed();
	//_cHUDCommoInfo = nullptr;
	//_cHUDCompass = nullptr;
	_LastGlowActor = nullptr;
	_tPainOverlay = nullptr;
	DesiredTeamClass = nullptr;
	ViewTargetActor = nullptr;
	_FlashEffect = nullptr;
	
	if (sKickReason.Len() > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Kicked: %s"),*sKickReason);
	}
}

void AHumanController::SetCheatMonitor(UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_CheatMonitor = nullptr;
	}
	else
	{
		_CheatMonitor = mon;
	}
}

//From Controller
bool AHumanController::ShouldRenderWeapon()
{
	if (Cast<AAGP_Pawn>(GetPawn()) != nullptr && Cast<AAGP_Pawn>(GetPawn())->Weapon != nullptr && !Cast<AAGP_Pawn>(GetPawn())->bIsDead)
	{
		return Cast<AAGP_Pawn>(GetPawn())->Weapon->ShouldRenderWeapon();
	}
	return false;
}

//From PlayerController
bool AHumanController::CanUseWeapon(int32 DesiredAction)
{
	if (!ShouldRenderWeapon() || Cast<AAGP_Pawn>(GetPawn()) == nullptr)
	{
		return false;
	}
	return Cast<AAGP_Pawn>(GetPawn())->CanUseWeapon(DesiredAction);
}

//From PlayerController
void AHumanController::ServerUpdateSelfHealActionState(bool bState)
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

//From PlayerController
void AHumanController::SetFromAuthJacket(FAuthJacket Jacket)
{
	int32 ii=0;
	
	iCompleted[0] = Jacket.ToursCompleted;
	for (ii = 0; ii < 32; ii++)
	{
		//iCompleted[ii + 1] = Jacket.MissionsCompleted[ii];
	}
	iRifleRangeRating = Jacket.MarksmanshipScore;
	if (PlayerReplicationInfo != nullptr)
	{
		//PlayerReplicationInfo._iTrust = Jacket.Honor;
		//PlayerReplicationInfo._Experience = Jacket.Experience;
		//PlayerReplicationInfo.SetGroup(Jacket.Group);
	}
	iUID = Jacket.UID;
	
}

//From PlayerController
FString AHumanController::AuthJacketToString(FAuthJacket Jacket)
{
	FString str="";
	int32 ii=0;
	/*
	str = "ToursCompleted:" @ Jacket.ToursCompleted;
	str @ = "MissionsCompleted: ";
	for (ii = 0; ii < 32; ii++)
	{
		if (ii > 0)
		{
			str += ",";
		}
		str += Jacket.MissionsCompleted[ii];
	}
	str @ = "MarksmanshipScore:" @ Jacket.MarksmanshipScore;
	str @ = "Honor:" @ Jacket.Honor;
	str @ = "Experience:" @ Jacket.Experience;
	str @ = "Group:" @ Jacket.Group;
	str @ = "UID:" @ Jacket.UID;
	*/
	return str;
}

//From Controller
//native final Function PbCanPlayerJoin ();
bool AHumanController::PbCanPlayerJoin()
{
	return true;			//FAKE   /ELiZ
}

//From PlayerController
//native final Function IsPBEnabled ();
bool AHumanController::IsPBEnabled()
{
	return true;	//FAKE   /ELiZ
}
