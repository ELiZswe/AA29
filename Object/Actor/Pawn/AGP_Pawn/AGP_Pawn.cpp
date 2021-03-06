// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineGlobals.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/Controller.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/DummyItem/DummyItem.h"
#include "AA29/Object/Actor/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Parachute/Item_Parachute.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M82_Sniper/Weapon_M82_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_MosinNagant_Sniper/Weapon_MosinNagant_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SVD_Sniper/Weapon_SVD_Sniper.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AA29/Object/Actor/EventLab/Eventlab.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsSkel/KarmaParamsSkel.h"
#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphere.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/Actor/Inventory/Powerups/Powerups.h"
#include "AA29/Object/Team_Interface/Team_Interface.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"
#include "Materials/MaterialInstance.h"
#include "AA29/Object/Actor/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Stats/AI_Stats.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/AnimationController/AnimationController.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/DebugIcon/DebugIcon_Action/DebugIcon_Action.h"
#include "AA29/Object/Actor/DebugIcon/DebugIcon_Interrupt/DebugIcon_Interrupt.h"
#include "AA29/Object/Actor/DebugIcon/DebugIcon_MentalState/DebugIcon_MentalState.h"
#include "AA29/Object/Actor/AI_Primitive/InfoSource/InfoSource.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pickup/Ammo/Ammo.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/item_headphones/item_headphones.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_civilian.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/SniperRifle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"

void AAGP_Pawn::LoadMesh()
{
	UMaterialInstance* Mat;
	if (CustomMesh)
	{
		Mesh_3P->SetSkeletalMesh(CustomMesh);
		if (Mesh_3P != nullptr)
		{
			if (Skins.Num() > 0)
			{
				for (int32 i = 0; i < Skins.Num(); i++)
				{
					Mat = Skins[i];
					Mesh_3P->SetMaterial(i, Mat);
				}
			}
			Mesh_3P->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
			PrePivot.Z = PrePivot.Z - 11;
			Mesh_3P->SetRelativeLocation(PrePivot * 2);
			Mesh_3P->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			Mesh_3P->bOnlyOwnerSee = false;
			Mesh_3P->bOwnerNoSee = true;
			Mesh_3P->CastShadow = true;

			// prevent anim frame skipping optimization based on visibility etc
			Mesh_3P->SetIsReplicated(true);
			Mesh_3P->bEnableUpdateRateOptimizations = false;
			Mesh_3P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
			Mesh_3P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
			Mesh_3P->bReceivesDecals = false;
			bNetUseOwnerRelevancy = true;
		}
	}
}

/*
State PlayerClimbing
{
	Function Fire(float F)
	{
		DebugLog(DEBUG_Multi,"Player trying to fire on ladder - not allowed");
	}
}
*/

/*
State Hidden
{
	Function PlayWaiting()
	{
	}
}
*/

/*
simulated State BusyAnimating
{
	simulated Event bool IsBusy()
	{
		return true;
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
	}
	simulated Function AnimEnd(int32 Channel)
	{
		Global.npcpnNodeBeingEdited(Channel);
		if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
		{
			Controller.NotifyComplete();
		}
	}
	simulated Function bool AllowAnimFiring()
	{
		return false;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		if (! CanLeanInAnimationState())
		{
			ResetLean();
		}
	}
	simulated Function EndState()
	{
		bTransitionAnim=false;
		LockMovement(false);
		AnimBlendToAlpha(15,0,0.25);
		AnimBlendToAlpha((15 - 1),0,0.25);
		AnimBlendToAlpha(13,0,0.35);
		EnableChannelNotify(15,0);
		EnableChannelNotify((15 - 1),0);
		EnableChannelNotify(13,0);
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::EndState - in state" @ FString::FromInt(GetStateName()));
		}
	}
}
*/

/*
simulated State BusyPostureChange extends BusyAnimating
{
	Function ShouldStand(bool bForce)
	{
	}
	Function ShouldCrouch(bool Crouch)
	{
	}
	Function ShouldProne(bool Prone)
	{
	}
	simulated Function bool CanJump()
	{
		return false;
	}
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function WeaponAdjust3p(Pawn.EUpperBodyAnim Anim)
	{
		FName Seq = "";
		float frame = 0;
		float Rate = 0;
		GetAnimParams(13,Seq,frame,Rate);
		switch(Seq)
		{
			case "CrhLgFrBlend":
			case "StdLgFrBlend":
			case "Prn2StdCLU":
			case "Std2PrnCLU":
			Global.vTestLocation(Anim);
			break;
			case "Std2PrnNo":
			case "Prn2StdNo":
			case "Crh2PrnNo":
			case "Prn2CrhNo":
			case "Crh2PrnAT4":
			case "Prn2CrhAT4":
			case "Crh2PrnRPG":
			case "Prn2CrhRPG":
			case "Crh2PrnSM":
			case "Prn2CrhSM":
			case "Prn2CrhCLU":
			case "Crh2PrnCLU":
			case "Std2PrnTube":
			case "Prn2StdTube":
			case "Crh2PrnTube":
			case "Prn2CrhTube":
			DebugLog(DEBUG_Anim,"AGP_Pawn::BusyPostureChange::WeaponAdjust3p()	Not playing adjustment animation for prone related transition");
			SkipWeaponAdjustment(Anim);
			break;
			default:
			DebugLog(DEBUG_Warn,"AGP_Pawn::BusyPosturechange::WeaponAdjust3p()	Did not expect to be in " + FString::FromInt(Seq) + " for UBANIM " + FString::FromInt(Anim));
			break;
		}
	}
	simulated Function GuardWeapon3p(Pawn.EUpperBodyAnim Anim)
	{
	}
	simulated Function BeginState()
	{
		ABaseWeaponAttachment* MyAttachment = nullptr;
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		MyAttachment=GetWeaponAttachment();
		if ((MyAttachment != nullptr) && MyAttachment.bHasAttachmentReload)
		{
			if ((UpperBodyAnim == 3) || (LastUpperBodyAnim == 3))
			{
				MyAttachment.PlayAttachmentReload(-1);
			}
		}
		if ((((Role > 2) && (UpperBodyAnim != 9)) && (UpperBodyAnim != 12)) && (UpperBodyAnim != 1))
		{
			UpperBodyAnimComplete();
		}
		else
		{
			PredictUpperBodyAnim();
		}
		ChangeAnimation();
	}
	simulated Function EndState()
	{
		Super::EndState();
		SetWalking(bIsWalking);
	}
}
*/

/*
simulated State BusyProning extends BusyPostureChange
{
	Function Fire(float F)
	{
	}
	simulated Function bool AllowAnimFiring()
	{
		return (bIsProne && bWasProne);
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (CommoState == 0)
		{
			CommoCycleState();
		}
		if (IsHumanControlled())
		{
			Controller.GotoState("PlayerCrawling");
		}
		if (_AnimationMonitor == nullptr)
		{
			if (AnimIsInGroup(0,"CrouchGroup") && IsAnimating(0))
			{
				bTransitionAnim=true;
				LockMovement(true);
				EnableChannelNotify(13,1);
				AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
				switch(UpperBodyAnim)
				{
					case 2:
					PlayAnim("Crh2PrnLg",1.3,0.05,13);
					break;
					case 33:
					PlayAnim("Crh2PrnAT4",1.3,0.05,13);
					break;
					case 25:
					case 29:
					PlayAnim("Crh2PrnRPG",1.3,0.05,13);
					break;
					case 39:
					PlayAnim("Crh2PrnSM",1.3,0.05,13);
					break;
					case 67:
					case 68:
					PlayAnim("Crh2PrnCLU",1.3,0.05,13);
					break;
					case 75:
					PlayAnim("Crh2PrnTube",1.3,0.05,13);
					break;
					default:
					PlayAnim("Crh2PrnNo",1.3,0.05,13);
					break;
				}
				if (GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					PlayOwnedSound(sCrouchToProne,3,0.5,false,1000,1,true);
				}
			}
			else
			{
				if ((AnimIsInGroup(0,"StandGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"StandGroup") && IsAnimating(15)))
				{
					EnableChannelNotify(13,1);
					AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
					bTransitionAnim=true;
					LockMovement(true);
					switch(UpperBodyAnim)
					{
						case 2:
						PlayAnim("Std2PrnLg",1.3,0.05,13);
						break;
						case 33:
						PlayAnim("Std2PrnAT4",1.3,0.05,13);
						break;
						case 25:
						case 29:
						PlayAnim("Std2PrnRPG",1.3,0.05,13);
						break;
						case 39:
						PlayAnim("Std2PrnSM",1.3,0.05,13);
						break;
						case 67:
						case 68:
						PlayAnim("Std2PrnCLU",1.3,0.05,13);
						break;
						case 75:
						PlayAnim("Std2PrnTube",1.3,0.05,13);
						break;
						default:
						PlayAnim("Std2PrnNo",1.3,0.05,13);
						break;
					}
					if (GetNetMode() != ENetMode::NM_DedicatedServer)
					{
						PlayOwnedSound(sStandToProne,3,0.5,false,1000,1,true);
					}
				}
				else
				{
					EndState();
					GotoState("None");
				}
			}
		}
	}
	simulated Function EndState()
	{
		FName IdleAnim = "";
		Super::EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="PrnLg";
				break;
				case 22:
				case 18:
				IdleAnim="PrnBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="PrnBinocsDn";
				break;
				case 68:
				case 70:
				IdleAnim="PrnCLUIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="PrnCLUIdleDwn";
				break;
				case 75:
				IdleAnim="PrnTubeIdle";
				break;
				case 25:
				case 29:
				IdleAnim="PrnRPG";
				break;
				case 33:
				IdleAnim="PrnAT4";
				break;
				case 39:
				IdleAnim="PrnSMIdle";
				break;
				case 12:
				case 9:
				default:
				IdleAnim="PrnNo";
				break;
			}
			LoopAnim(IdleAnim,1,0.05);
		}
	}
}
*/

/*
simulated State BusyDiving extends BusyProning
{
	simulated Function bool CanJump()
	{
		return false;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		if (CommoState == 0)
		{
			CommoCycleState();
		}
		if (IsHumanControlled())
		{
			Controller.GotoState("PlayerCrawling");
		}
		if (_AnimationMonitor == nullptr)
		{
			if ((AnimIsInGroup(0,"StandGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"StandGroup") && IsAnimating(15)))
			{
				EnableChannelNotify(13,1);
				AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
				bTransitionAnim=true;
				GroundSpeed=((fRunSpeed * GetSpeedModifier()) * fSprintMod);
				if (Weapon != nullptr)
				{
					Weapon.TempLowerWeapon();
				}
				CombatEffectivenessEvent(CE_EVENT_DIVE);
				if (UpperBodyAnim == 2)
				{
					PlayAnim("Drop2PrnLg",1.3,0,13);
				}
				else
				{
					PlayAnim("Drop2PrnNo",1.3,0,13);
				}
			}
			else
			{
				EndState();
				GotoState("None");
			}
		}
	}
	simulated Function EndState()
	{
		FullBodyAnimComplete();
		if ((Weapon != nullptr) && Weapon.IsTempBusy())
		{
			Weapon.TempRaiseWeapon();
		}
		Super::EndState();
	}
}
*/

/*
simulated State BusyCrouching extends BusyPostureChange
{
	simulated Function bool AllowAnimFiring()
	{
		FName Seq = "";
		float f1 = 0;
		float f2 = 0;
		GetAnimParams(13,Seq,f1,f2);
		switch(Seq)
		{
			case "Prn2CrhNo":
			case "Prn2CrhLg":
			case "Prn2CrhAT4":
			case "Prn2CrhRPG":
			case "Prn2CrhSM":
			case "Prn2CrhCLU":
			case "Prn2CrhTube":
			return false;
			default:
			return ((! bIsProne) && (! bWasProne));
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (bIsDead || (Weapon == nullptr))
		{
			return false;
		}
		if ((DesiredAction != 0) || (! AllowAnimFiring()))
		{
			if (AnimIsInGroup(0,"TransitionGroup") || AnimIsInGroup(13,"TransitionGroup"))
			{
				return false;
			}
		}
		return Weapon.CanUseWeapon(DesiredAction);
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			if ((AnimIsInGroup(0,"StandGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"StandGroup") && IsAnimating(15)))
			{
				EnableChannelNotify(13,1);
				AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
				TweenAnim("CrhLgFr_Blend",0.05,13);
				if (GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					PlayOwnedSound(sStandToCrouch,3,0.5,false,1000,1,true);
				}
			}
			else
			{
				if ((AnimIsInGroup(0,"ProneGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"ProneGroup") && IsAnimating(15)))
				{
					EnableChannelNotify(13,1);
					bTransitionAnim=true;
					LockMovement(true);
					AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
					switch(UpperBodyAnim)
					{
						case 2:
						PlayAnim("Prn2CrhLg",1.3,0.05,13);
						break;
						case 33:
						PlayAnim("Prn2CrhAT4",1.3,0.05,13);
						break;
						case 25:
						case 29:
						PlayAnim("Prn2CrhRPG",1.3,0.05,13);
						break;
						case 39:
						PlayAnim("Prn2CrhSM",1.3,0.05,13);
						break;
						case 67:
						case 68:
						PlayAnim("Prn2CrhCLU",1.3,0.05,13);
						break;
						case 75:
						PlayAnim("Prn2CrhTube",1.3,0.05,13);
						break;
						default:
						PlayAnim("Prn2CrhNo",1.3,0.05,13);
						break;
					}
					if (GetNetMode() != ENetMode::NM_DedicatedServer)
					{
						PlayOwnedSound(sProneToCrouch,3,0.5,false,1000,1,true);
					}
				}
				else
				{
					EndState();
					GotoState("None");
				}
			}
			if (IsHumanControlled())
			{
				Controller.GotoState("PlayerCrouching");
			}
		}
	}
	simulated Function EndState()
	{
		FName IdleAnim = "";
		Super::EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="CrhLgFr";
				break;
				case 12:
				IdleAnim="CrhGnRdy";
				break;
				case 9:
				IdleAnim="CrhGnFr";
				break;
				case 68:
				case 70:
				IdleAnim="CrhCluIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="CrhCluIdleDwn";
				break;
				case 75:
				IdleAnim="CrhTubeIdle";
				break;
				case 22:
				case 18:
				IdleAnim="CrhBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="CrhBinocsDn";
				break;
				case 25:
				case 29:
				IdleAnim="CrhRPG";
				break;
				case 33:
				IdleAnim="CrhAT4";
				break;
				case 39:
				IdleAnim="CrhSmIdle";
				break;
				default:
				IdleAnim="CrhNo";
				break;
			}
			if (AnimLoopAction != "None")
			{
				LoopAnim(AnimLoopAction,1,0.25);
			}
			else
			{
				LoopAnim(IdleAnim,1,0.25);
			}
		}
		bInProneTransition=false;
	}
}
*/

/*
simulated State BusyStanding extends BusyPostureChange
{
	simulated Function bool AllowAnimFiring()
	{
		FName Seq = "";
		float f1 = 0;
		float f2 = 0;
		GetAnimParams(13,Seq,f1,f2);
		switch(Seq)
		{
			case "Prn2StdNo":
			case "Prn2StdLg":
			case "Prn2StdAT4":
			case "Prn2StdRPG":
			case "Prn2StdSM":
			case "Prn2StdCLU":
			case "Prn2StdTube":
			return false;
			default:
			return ((! bIsProne) && (! bWasProne));
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (bIsDead || (Weapon == nullptr))
		{
			return false;
		}
		if ((DesiredAction != 0) || (! AllowAnimFiring()))
		{
			if (AnimIsInGroup(0,"TransitionGroup") || AnimIsInGroup(13,"TransitionGroup"))
			{
				return false;
			}
		}
		return Weapon.CanUseWeapon(DesiredAction);
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			if ((AnimIsInGroup(0,"CrouchGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"CrouchGroup") && IsAnimating(15)))
			{
				EnableChannelNotify(13,1);
				AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
				TweenAnim("StdLgFr_Blend",0.05,13);
				if (GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					PlayOwnedSound(sCrouchToStand,3,0.5,false,1000,1,true);
				}
			}
			else
			{
				if ((AnimIsInGroup(0,"ProneGroup") && IsAnimating(0)) || (AnimIsInGroup(15,"ProneGroup") && IsAnimating(15)))
				{
					EnableChannelNotify(13,1);
					bTransitionAnim=true;
					LockMovement(true);
					AnimBlendParams(13,1,0,0);
					switch(UpperBodyAnim)
					{
						case 2:
						PlayAnim("Prn2StdLg",1.3,0.05,13);
						break;
						case 33:
						PlayAnim("Prn2StdAT4",1.3,0.05,13);
						break;
						case 25:
						case 29:
						PlayAnim("Prn2StdRPG",1.3,0.05,13);
						break;
						case 39:
						PlayAnim("Prn2StdSM",1.3,0.05,13);
						break;
						case 67:
						case 68:
						PlayAnim("Prn2StdCLU",1.3,0.05,13);
						break;
						case 75:
						PlayAnim("Prn2StdTube",1.3,0.05,13);
						break;
						default:
						PlayAnim("Prn2StdNo",1.3,0.05,13);
						break;
					}
					if (GetNetMode() != ENetMode::NM_DedicatedServer)
					{
						PlayOwnedSound(sProneToStand,3,0.5,false,1000,1,true);
					}
				}
				else
				{
					EndState();
					GotoState("None");
				}
			}
			if (IsHumanControlled() && (Physics != 11))
			{
				if (Cast<AHumanController>(Controller) != nullptr)
				{
					Cast<AHumanController>(Controller).MaybeEnterPlayerWalkingState();
				}
				else
				{
					Controller.GotoState("PlayerWalking");
				}
			}
		}
	}
	simulated Function EndState()
	{
		FName IdleAnim = "";
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::EndState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="StdLgFr";
				break;
				case 12:
				IdleAnim="StdGnRdy";
				break;
				case 9:
				IdleAnim="StdGnFr";
				break;
				case 68:
				case 70:
				IdleAnim="StdCluIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="StdCluIdleDwn";
				break;
				case 75:
				IdleAnim="StdTubeIdle";
				break;
				case 22:
				case 18:
				IdleAnim="StdBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="StdBinocsDn";
				break;
				case 33:
				IdleAnim="StdAT4";
				break;
				case 25:
				case 29:
				IdleAnim="StdRPG";
				break;
				case 39:
				IdleAnim="StdSmIdle";
				break;
				default:
				if (nmNPCIdleAnim != "None")
				{
					IdleAnim=nmNPCIdleAnim;
				}
				else
				{
					IdleAnim="StdNo";
				}
			}
			if (AnimLoopAction != "None")
			{
				LoopAnim(AnimLoopAction,1,0.25);
			}
			else
			{
				LoopAnim(IdleAnim,1,0.25);
			}
		}
		bInProneTransition=false;
	}
}
*/

/*
simulated State BusyRolling extends BusyAnimating
{
	simulated Function bool CanJump()
	{
		return false;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			if (AnimIsInGroup(0,"ProneGroup"))
			{
				PlayRolling(FullBodyAnim);
			}
			else
			{
				EndState();
				GotoState("None");
			}
		}
	}
	simulated Function EndState()
	{
		FName IdleAnim = "";
		if (_AnimationMonitor == nullptr)
		{
			FullBodyAnimComplete();
			if (_AnimationMonitor == nullptr)
			{
				switch(UpperBodyAnim)
				{
					case 2:
					IdleAnim="PrnLg";
					break;
					case 68:
					case 70:
					IdleAnim="PrnCLUIdleUp";
					break;
					case 67:
					case 71:
					IdleAnim="PrnCLUIdleDwn";
					break;
					case 75:
					IdleAnim="PrnTubeIdle";
					break;
					case 22:
					case 18:
					IdleAnim="PrnBinocsUp";
					break;
					case 21:
					case 19:
					IdleAnim="PrnBinocsDn";
					break;
					case 25:
					case 29:
					IdleAnim="PrnRPG";
					break;
					case 33:
					IdleAnim="PrnAT4";
					break;
					case 39:
					IdleAnim="PrnSMIdle";
					break;
					case 12:
					case 9:
					default:
					IdleAnim="PrnNo";
					break;
				}
				LoopAnim(IdleAnim,1,0.05);
			}
			if (IsHumanControlled())
			{
				Controller.GotoState("PlayerCrawling");
			}
		}
		if (Weapon != nullptr)
		{
			Weapon.TempRaiseWeapon();
		}
		Super::EndState();
	}
}
*/

/*
simulated State BusyParachuting extends BusyAnimating
{
	simulated Function bool CanJump()
	{
		return false;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			LoopAnim("ParachuteIdle",1,0.05);
			TimeSinceBusyParachutingStarted=0;
			Enable("Tick");
		}
	}
	simulated Function Tick(float DeltaTime)
	{
		(TimeSinceBusyParachutingStarted += DeltaTime);
		if (TimeSinceBusyParachutingStarted > 0.5)
		{
			TimeSinceBusyParachutingStarted=0;
			if (! IsAnimating())
			{
				LoopAnim("ParachuteIdle",1,0.05);
			}
			else
			{
				Disable("Tick");
			}
		}
	}
	simulated Function EndState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::EndState - in state" @ FString::FromInt(GetStateName()));
		}
		Disable("Tick");
	}
}
*/

/*
simulated State BusyPLF extends BusyAnimating
{
	simulated Function bool CanJump()
	{
		return false;
	}
	simulated Function ChangeAnimation()
	{
	}
	simulated Function bool UseAnimatedEyeRotation()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		PlayPLF();
		bPhysicsAnimUpdate=false;
		if (Controller != nullptr)
		{
			Controller.GotoState("PlayerWalking");
		}
	}
	simulated Function EndState()
	{
		Super::EndState();
		bPhysicsAnimUpdate=true;
		FullBodyAnimComplete();
		if (Controller != nullptr)
		{
			SetViewRotation(GetViewRotation());
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		FName Seq = "";
		float frame = 0;
		float Rate = 0;
		if (Channel == 13)
		{
			GetAnimParams(Channel,Seq,frame,Rate);
			if (((Seq == "PLFGetup") || (Seq == "PLFGetupMilesDead")) || (Seq == "PLFDead"))
			{
				Super::AnimEnd(Channel);
			}
			else
			{
				if (Seq == "PLF")
				{
					EnableChannelNotify(13,1);
					AnimBlendParams(13,1,0,BlendChangeTime);
					if (bIsDead && Level.IsMILES())
					{
						PlayAnim("PLFGetupMilesDead",1,0,13);
					}
					else
					{
						PlayAnim("PLFGetup",1,0,13);
					}
				}
			}
		}
	}
}
*/

/*
simulated State BusySignaling extends BusyAnimating
{
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			EnableChannelNotify(15,1);
			if ((LastUpperBodyAnim == 1) || ((Role > 2) && (Weapon == nullptr)))
			{
				EnableChannelNotify((15 - 1),1);
				AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"Rshoulder");
				AnimBlendParams((15 - 1),1,BlendChangeTime,BlendChangeTime,"Neck");
				PlayAnim(commosignalanim,1,0.05,(15 - 1));
			}
			else
			{
				if (bIsCrouched)
				{
					AnimBlendParams(15,1,0,BlendChangeTime,"Spine02");
				}
				else
				{
					AnimBlendParams(15,1,0,BlendChangeTime,"spine01");
				}
			}
			PlayAnim(commosignalanim,1,0.05,15);
		}
	}
}
*/

/*
simulated State BusyReloading extends BusyAnimating
{
	simulated Function bool CanSprint()
	{
		return false;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		Super::AnimEnd(Channel);
		if (Channel == 15)
		{
			GotoState("None");
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (Weapon == nullptr)
		{
			return false;
		}
		return Weapon.CanUseWeapon(DesiredAction);
	}
	simulated Function BeginState()
	{
		ABaseWeaponAttachment* MyAttachment = nullptr;
		FName PawnReloadName = "";
		Super::BeginState();
		EnableChannelNotify(15,1);
		Reload3p(3);
		if (_AnimationMonitor == nullptr)
		{
			MyAttachment=GetWeaponAttachment();
			if ((MyAttachment != nullptr) && MyAttachment.bHasAttachmentReload)
			{
				MyAttachment.PlayAttachmentReload();
				PawnReloadName=MyAttachment.GetPawnReloadAnimation();
				if (MyAttachment->IsA(AAttachW_Javelin::StaticClass()))
				{
					AnimBlendParams(15,1,0,0,"Spine02");
					PlayAnim(PawnReloadName,1,0,15);
				}
				else
				{
					AnimBlendParams(15,1,0.05,0.05,"Spine02");
					PlayAnim(PawnReloadName,1,0.05,15);
				}
			}
			else
			{
				AnimBlendParams(15,1.4,0.05,0.05,"Spine02");
				if (bIsProne)
				{
					PlayAnim("PrnLgRld",1.4,0.05,15);
				}
				else
				{
					PlayAnim("StdLgRld",1.4,0.05,15);
				}
			}
		}
	}
}
*/

/*
simulated State BusyGuardingWeapon extends BusyAnimating
{
	simulated Function bool IsBusy()
	{
		return false;
	}
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		if (! CanLeanInAnimationState())
		{
			ResetLean();
		}
		if (_AnimationMonitor == nullptr)
		{
			EnableChannelNotify(15,1);
			AnimBlendParams(15,0,0,0,"Spine02");
			switch(UpperBodyAnim)
			{
				case 34:
				if (bIsProne)
				{
					LoopAnim("PrnAT4Rlx",1,0,15);
					break;
				}
				if (bIsCrouched)
				{
					LoopAnim("CrhAT4Rlx",1,0,15);
					break;
				}
				LoopAnim("StdAT4Rlx",1,0,15);
			}
			case 26:
			case 30:
			if (bIsProne)
			{
				LoopAnim("PrnRPGRlx",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					LoopAnim("CrhRPGRlx",1,0,15);
				}
				else
				{
					LoopAnim("StdRPGRlx",1,0,15);
				}
			}
			case 69:
			if (bIsProne)
			{
				LoopAnim("PrnCLURlx",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					LoopAnim("CrhCLURlx",1,0,15);
				}
				else
				{
					LoopAnim("StdCLURlx",1,0,15);
				}
			}
			case 74:
			if (bIsProne)
			{
				LoopAnim("PrnTubeRlx",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					LoopAnim("CrhTubeRlx",1,0,15);
				}
				else
				{
					LoopAnim("StdTubeRlx",1,0,15);
				}
			}
			case 40:
			if (bIsProne)
			{
				LoopAnim("PrnSmRdy",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					LoopAnim("CrhSmRdy",1,0,15);
				}
				else
				{
					LoopAnim("StdSmRdy",1,0,15);
				}
			}
			case 6:
			default:
			if (bIsProne)
			{
				LoopAnim("PrnLgRdy",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					LoopAnim("CrhLgRdy",1,0,15);
				}
				else
				{
					LoopAnim("StdLgRdy",1,0,15);
				}
			}
			AnimBlendToAlpha(15,1,0.25);
			if (Weapon != nullptr)
			{
				Weapon.GuardWeapon();
			}
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Channel == 15)
		{
			switch(UpperBodyAnim)
			{
				case 69:
				case 74:
				case 6:
				case 26:
				case 30:
				case 34:
				case 40:
				break;
				default:
				Super::AnimEnd(Channel);
			}
		}
	}
	simulated Function EndState()
	{
		Super::EndState();
		FreezeAnimAt(0,15);
		if ((Weapon != nullptr) && (! bIsSprinting))
		{
			Weapon.TempRaiseWeapon();
		}
	}
}
*/

/*
simulated State BusyDrawingBack extends BusyAnimating
{
	Function TossWeapon(Vector TossVel)
	{
	}
	Function SwapHands()
	{
	}
	Function SwapHip()
	{
	}
	Function SwapAltShoulder()
	{
	}
	simulated Function bool CanChangePosture(bool bForce, bool bForceUnzoom)
	{
		return false;
	}
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			if ((Weapon != nullptr) && Weapon->IsA(AFixedWeapon::StaticClass()))
			{
				AnimEnd(15);
				return;
			}
			EnableChannelNotify(15,1);
			if (bIsProne)
			{
				AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"spine01");
			}
			else
			{
				AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"Spine02");
			}
			switch(UpperBodyAnim)
			{
				case 11:
				if (bIsProne)
				{
					PlayAnim("PrnSlingGn",1,0.05,15);
					break;
				}
				PlayAnim("StdSlingGn",1,0.05,15);
			}
			case 20:
			if (bIsProne)
			{
				PlayAnim("PrnSlingGn",1,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingGn",1,0.05,15);
			}
			case 24:
			case 28:
			if (bIsProne)
			{
				PlayAnim("PrnSlingRPG",1,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingRPG",1,0.05,15);
			}
			case 66:
			if (bIsProne)
			{
				PlayAnim("PrnSlingCLU",1,0.05,15);
			}
			else
			{
				if (bIsCrouched)
				{
					PlayAnim("CrhSlingCLU",1,0.05,15);
				}
				else
				{
					PlayAnim("StdSlingCLU",1,0.05,15);
				}
			}
			case 73:
			if (bIsProne)
			{
				PlayAnim("PrnSlingTube",1,0.05,15);
			}
			else
			{
				if (bIsCrouched)
				{
					PlayAnim("CrhSlingTube",1,0.05,15);
				}
				else
				{
					PlayAnim("StdSlingTube",1,0.05,15);
				}
			}
			case 32:
			if (bIsProne)
			{
				PlayAnim("PrnSlingAT4",1,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingAT4",1,0.05,15);
			}
			case 36:
			if (bIsProne)
			{
				PlayAnim("PrnSlingBDM",1,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingBDM",1,0.05,15);
			}
			case 38:
			if (bIsProne)
			{
				PlayAnim("PrnSlingSm",1,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingSm",1,0.05,15);
			}
			default:
			if (bIsProne)
			{
				PlayAnim("PrnSlingLg",1.4,0.05,15);
			}
			else
			{
				PlayAnim("StdSlingLg",1.4,0.05,15);
			}
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (! fInitialAnimationComplete)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::BusyDrawingBack::AnimEnd() - signalling initial animation complete");
			fInitialAnimationComplete=true;
		}
		if (Channel == 15)
		{
			if (isDead())
			{
				GotoState("Dying");
			}
			else
			{
				GotoState("None");
			}
		}
	}
	simulated Function EndState()
	{
		AAGP_Weapon* OldWeapon = nullptr;
		Super::EndState();
		OldWeapon=Cast<AAGP_Weapon>(Weapon);
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			GOTO JL00AE;
		}
		if (OldWeapon == nullptr)
		{
			if (NextSwap != nullptr)
			{
				FinishSwapHands();
			}
		}
		else
		{
			FinishSwapHands();
			if (OldWeapon.VirtualWeapon())
			{
				OldWeapon.Destroy();
			}
			else
			{
				if (OldWeapon.ThirdPersonActor != nullptr)
				{
					Cast<AWeaponAttachment>(OldWeapon.ThirdPersonActor).AdjustAttachmentFor(OldWeapon);
JL00AE:
				}
			}
		}
		switch(UpperBodyAnim)
		{
			case 65:
			case 72:
			case 4:
			case 10:
			case 17:
			case 23:
			case 27:
			case 31:
			case 35:
			case 37:
			break;
			default:
			AnimEnd(15);
		}
	}
}
*/

/*
simulated State BusyDrawing extends BusyAnimating
{
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		if (! fInitialAnimationComplete)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::BusyDrawing::BeginState() - signalling initial animation complete");
			fInitialAnimationComplete=true;
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			EnableChannelNotify(15,1);
			if (bIsProne)
			{
				AnimBlendParams(15,1,0,0,"spine01");
			}
			else
			{
				AnimBlendParams(15,1,0,0,"Spine02");
			}
			switch(UpperBodyAnim)
			{
				case 10:
				if (bIsProne)
				{
					PlayAnim("PrnDrawGn",1,0.05,15);
					break;
				}
				PlayAnim("StdDrawGn",1,0.05,15);
			}
			case 17:
			if (bIsProne)
			{
				PlayAnim("PrnDrawGn",1,0.05,15);
			}
			else
			{
				PlayAnim("StdDrawGn",1,0.05,15);
			}
			case 23:
			case 27:
			if (bIsProne)
			{
				PlayAnim("PrnDrawRPG",1,0.05,15);
			}
			else
			{
				PlayAnim("StdDrawRPG",1,0.05,15);
			}
			case 65:
			if (bIsProne)
			{
				PlayAnim("prndrawclu",1,0.05,15);
			}
			else
			{
				if (bIsCrouched)
				{
					PlayAnim("CrhDrawCLU",1,0.05,15);
				}
				else
				{
					PlayAnim("StdDrawCLU",1,0.05,15);
				}
			}
			case 72:
			if (bIsProne)
			{
				PlayAnim("PrnDrawTube",1,0,15);
			}
			else
			{
				if (bIsCrouched)
				{
					PlayAnim("CrhDrawTube",1,0,15);
				}
				else
				{
					PlayAnim("StdDrawTube",1,0,15);
				}
			}
			case 31:
			if (bIsProne)
			{
				PlayAnim("PrnDrawAT4",1,0.05,15);
			}
			else
			{
				PlayAnim("StdDrawAT4",1,0.05,15);
			}
			case 35:
			if (bIsProne)
			{
				PlayAnim("PrnDrawBDM",1,0.05,15);
			}
			else
			{
				PlayAnim("StdDrawBDM",1,0.05,15);
			}
			case 37:
			if (bIsProne)
			{
				PlayAnim("PrnDrawSm",1,0.05,15);
			}
			else
			{
				PlayAnim("StdDrawSm",1,0.05,15);
			}
			default:
			if (bIsProne)
			{
				PlayAnim("PrnDrawLg",1.4,0,15);
			}
			else
			{
				PlayAnim("StdDrawLg",1.4,0,15);
			}
		}
	}
}
*/

/*
simulated State BusyPullingPinGrenade extends BusyAnimating
{
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			EnableChannelNotify(15,1);
			AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"Spine02");
			if (bIsProne)
			{
				PlayAnim("PrnGnPull",1,0.05,15);
			}
			else
			{
				PlayAnim("StdGnPull",1,0.05,15);
			}
		}
	}
}
*/

/*
simulated State BusyThrowingGrenade extends BusyAnimating
{
	simulated Function bool CanLeanInAnimationState()
	{
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			EnableChannelNotify(15,1);
			if (bIsCrouched)
			{
				AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"Spine02");
			}
			else
			{
				AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,"spine01");
			}
			if (bIsProne)
			{
				if (UpperBodyAnim == 8)
				{
					PlayAnim("PrnGnThrwUHEnd",1,0.05,15);
				}
				else
				{
					PlayAnim("PrnGnThrwOHEnd",1,0.05,15);
				}
			}
			else
			{
				if (UpperBodyAnim == 8)
				{
					PlayAnim("StdGnThrwUHEnd",1,0.05,15);
				}
				else
				{
					PlayAnim("StdGnThrwOHEnd",1,0.05,15);
				}
			}
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Channel == 15)
		{
			if (isDead())
			{
				GotoState("Dying");
			}
			else
			{
				GotoState("None");
			}
		}
	}
	simulated Function EndState()
	{
		Super::EndState();
		AnimEnd(15);
	}
}
*/

/*
simulated State BusyDeployingBreacherUS extends BusyAnimating
{
	simulated Function bool CanLeanInAnimationState()
	{
		return false;
	}
	simulated Function BeginState()
	{
		AActor* HitActor = nullptr;
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		float dist = 0;
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		GetAxes(Rotation,X,Y,Z);
		HitActor=Trace(HitLocation,HitNormal,(Location + (X * float(256))),Location,true);
		dist=VSize((HitLocation - Location));
		if (bIsProne)
		{
			PlayAnim("PrnDoorBreacherUSDeploy",1,0.01);
		}
		else
		{
			if (dist < float(65))
			{
				PlayAnim("StdDoorBreacherUSDeployClose",0.78,0.01);
			}
			else
			{
				PlayAnim("StdDoorBreacherUSDeploy",0.78,0.01);
			}
		}
	}
}
*/

/*
simulated State BusyDeployingBreacherOPFOR extends BusyAnimating
{
	simulated Function bool CanLeanInAnimationState()
	{
		return false;
	}
	simulated Function BeginState()
	{
		AActor* HitActor = nullptr;
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		float dist = 0;
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		GetAxes(Rotation,X,Y,Z);
		HitActor=Trace(HitLocation,HitNormal,(Location + (X * float(256))),Location,true);
		dist=VSize((HitLocation - Location));
		if (bIsProne)
		{
			PlayAnim("PrnDoorBreacherOPFORDeploy",1,0.01);
		}
		else
		{
			if (dist < float(65))
			{
				PlayAnim("StdDoorBreacherOPFORDeployClose",0.75,0.01);
			}
			else
			{
				PlayAnim("StdDoorBreacherOPFORDeploy",0.75,0.01);
			}
		}
	}
}
*/

/*
simulated State BusyJumping extends BusyAnimating
{
	Function Fire(float F)
	{
	}
	simulated Function bool AllowAnimFiring()
	{
		return false;
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if ((((Weapon == nullptr) || (DesiredAction == 0)) || bIsSprinting) || bIsDead)
		{
			return false;
		}
		return Weapon.CanUseWeapon(DesiredAction);
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			BaseEyeHeight=(BlendChangeTime * Default.BaseEyeHeight);
			if (FullBodyAnim == 3)
			{
				PlayAnim("ParachuteJump",0.7,0.01);
			}
			else
			{
				switch(UpperBodyAnim)
				{
					case 1:
					case 7:
					case 8:
					case 9:
					case 10:
					case 11:
					case 12:
					case 17:
					case 18:
					case 19:
					case 20:
					case 21:
					case 22:
					if ((Acceleration.X != 0) || (Acceleration.Y != 0))
					{
						PlayAnim("RunFwNoJmp",0.7,0.01);
						break;
					}
					PlayAnim("RunFwNoJmp",0.7,0.01);
				}
				case 23:
				case 24:
				case 25:
				case 27:
				case 28:
				case 29:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwRPGJmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwRPGJmp",0.7,0.01);
				}
				case 66:
				case 65:
				case 70:
				case 71:
				case 67:
				case 68:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwCluJmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwCluJmp",0.7,0.01);
				}
				case 72:
				case 73:
				case 75:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwTubeJmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwTubeJmp",0.7,0.01);
				}
				case 31:
				case 32:
				case 33:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwAT4Jmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwAT4Jmp",0.7,0.01);
				}
				case 35:
				case 36:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwAT4Jmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwAT4Jmp",0.7,0.01);
				}
				case 37:
				case 38:
				case 39:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwSmJump",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwSmJump",0.7,0.01);
				}
				default:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwLgJmp",0.7,0.01);
				}
				else
				{
					PlayAnim("RunFwLgJmp",0.7,0.01);
				}
			}
		}
	}
	Event EndState()
	{
		bMidJump=false;
	}
}
*/

/*
simulated State BusyLanding extends BusyAnimating
{
	simulated Function PlayStanding()
	{
	}
	simulated Function BeginState()
	{
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 1:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				if ((Acceleration.X != 0) || (Acceleration.Y != 0))
				{
					PlayAnim("RunFwNoJmpLand",1.15,0.1);
					break;
				}
				PlayAnim("RunFwNoJmpLand",1.15,0.1);
			}
			case 23:
			case 24:
			case 25:
			case 27:
			case 28:
			case 29:
			case 31:
			case 32:
			case 33:
			case 35:
			case 36:
			if ((Acceleration.X != 0) || (Acceleration.Y != 0))
			{
				PlayAnim("RunFwNoJmpLand",1.15,0.1);
			}
			else
			{
				PlayAnim("RunFwNoJmpLand",1.15,0.1);
			}
			case 66:
			case 65:
			case 70:
			case 71:
			case 67:
			case 68:
			if ((Acceleration.X != 0) || (Acceleration.Y != 0))
			{
				PlayAnim("RunFwCLUJmpLand",1.15,0.1);
			}
			else
			{
				PlayAnim("RunFwCLUJmpLand",1.15,0.1);
			}
			case 72:
			case 73:
			case 75:
			if ((Acceleration.X != 0) || (Acceleration.Y != 0))
			{
				PlayAnim("RunFwTubeJmpLand",1.15,0.1);
			}
			else
			{
				PlayAnim("RunFwTubeJmpLand",1.15,0.1);
			}
			case 37:
			case 38:
			case 39:
			if ((Acceleration.X != 0) || (Acceleration.Y != 0))
			{
				PlayAnim("RunFwSmJumpLand",1.15,0.1);
			}
			else
			{
				PlayAnim("RunFwSmJumpLand",1.15,0.1);
			}
			default:
			if ((Acceleration.X != 0) || (Acceleration.Y != 0))
			{
				PlayAnim("RunFwLgJmpLand",1.15,0.1);
			}
			else
			{
				PlayAnim("RunFwLgJmpLand",1.15,0.1);
			}
		}
	}
	simulated Function EndState()
	{
		if (_AnimationMonitor == nullptr)
		{
			LoopAnim("StdLgFr",1,0.1);
		}
		Super::EndState();
	}
}
*/

/*
simulated State Dying
{
	simulated Function GuardWeapon3p(Pawn.EUpperBodyAnim Anim)
	{
	}
	Function Fire(float F)
	{
	}
	simulated Function bool UseAnimatedEyeRotation()
	{
		return true;
	}
	Function BaseChange()
	{
		Super::BaseChange();
	}
	simulated Function Landed(Vector HitNormal)
	{
		if (Level.debugDeath)
		{
			DebugLog(DEBUG_Anim,"AGP_Pawn:Dying::Landed DeathAnim" @ FString::FromInt(GetDeathAnimName(false)));
		}
		switch(DeathAnim)
		{
			case 23:
			ParachuteLanding(false);
			return;
			default:
			break;
		}
		FreezePawn();
	}
	simulated Function FreezePawn()
	{
		if (Level.debugDeath)
		{
			DebugLog(DEBUG_Anim,"AGP_Pawn:Dying::FreezePawn");
		}
		bSimDeadFalling=false;
		SetPhysics(PHYS_None);
		Velocity=FVector(0,0,0);
		SetCollision(false,false,false);
		if (FrontAuxCyl != nullptr)
		{
			FrontAuxCyl.SetAuxCylinder(false);
		}
		if (BackAuxCyl != nullptr)
		{
			BackAuxCyl.SetAuxCylinder(false);
		}
		if (BoneAuxCyl != nullptr)
		{
			BoneAuxCyl.SetCollision(false,false,false);
		}
	}
	simulated Function bool DoPlayDying()
	{
		if (DeathAnim != OldDeathAnim)
		{
			bPlayedDeathEnd=false;
			return true;
		}
		else
		{
			if (AnimIsInGroup(0,"DyingGroup") || bPlayedDeathEnd)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	simulated Function BeginState()
	{
		int32 i = 0;
		if ((Level.IsMILES() || (OutOfBounds > 0)) || ((AnimManager != nullptr) && AnimManager.CanPlayDeathAnim()))
		{
			if (Level.debugPawnState)
			{
				DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
			}
			if (Level.IsMILES())
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::BeginState() for MILES entered ");
			}
			if (OutOfBounds > 0)
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::BeginState() for out-of-bounds entered");
			}
			bIsDead=true;
			bTransitionAnim=false;
			bInvulnerableBody=true;
			AnimateDead();
			StopAnimating(true);
			if (IsHumanControlled())
			{
				Cast<APlayerController>(Controller).LockPlayer(true,true);
			}
			if (Controller != nullptr)
			{
				Controller.CleanUp();
			}
			for (i=1; i<15; i++)
			{
				AnimBlendToAlpha(i,0,0);
				EnableChannelNotify(i,0);
			}
			if (DoPlayDying())
			{
				AnimBlendToAlpha(15,0,0.25);
				AnimBlendToAlpha((15 - 1),0,0.25);
				AnimBlendToAlpha(13,0,0.35);
				EnableChannelNotify(15,0);
				EnableChannelNotify((15 - 1),0);
				EnableChannelNotify(13,0);
				if (OutOfBounds > 0)
				{
					OutOfBoundsNotifyKillPlayer();
					if (bIsProne)
					{
						PlayAnim("PrnKillMiles",1,0);
					}
					else
					{
						if (bIsCrouched)
						{
							PlayAnim("CrhKillMiles",1,0);
						}
						else
						{
							if (Rand(2) == 0)
							{
								PlayAnim("StdKillMiles",1,0);
							}
							else
							{
								PlayAnim("StdKillMilesB",1,0);
							}
						}
					}
				}
				else
				{
					if ((AnimManager != nullptr) && AnimManager.CanPlayDeathAnim())
					{
						AnimManager.PlayDeathAnim();
					}
					else
					{
						if (bNetAlreadyDead)
						{
							PlayAnim(GetDeathAnimName(true),1,0);
						}
						else
						{
							if (IsDeadFlying())
							{
								LoopAnim(GetDeathAnimName(false),1,0.05);
							}
							else
							{
								PlayAnim(GetDeathAnimName(false),1,0.05);
							}
						}
					}
				}
				OldDeathAnim=DeathAnim;
			}
			if (((((Base == nullptr) || (Cast<APawn>(Base) != nullptr)) || (Cast<AAuxCollisionCylinder>(Base) != nullptr)) || IsDeadFlying()) && (! bNetAlreadyDead))
			{
				if (DeathAnim != 23)
				{
					SetPhysics(PHYS_Falling);
				}
				bSimDeadFalling=true;
				if (Level.debugDeath)
				{
					DebugLog(DEBUG_Anim,"AGP_Pawn:Dying::BeginState SimDeadFalling");
				}
			}
			else
			{
				FreezePawn();
			}
			SetTimer(3,false);
		}
		else
		{
			bIsDead=true;
			bTransitionAnim=false;
			bInvulnerableBody=true;
			if (IsHumanControlled())
			{
				Cast<APlayerController>(Controller).LockPlayer(true,true);
			}
			if ((Controller != nullptr) && (! Controller->IsA(ANPC_BaseController::StaticClass())))
			{
				Controller.CleanUp();
			}
			FreezePawn();
			SetTimer(3,false);
		}
		if ((Controller != nullptr) && Controller->IsA(ANPCBaseController::StaticClass()))
		{
			Controller.PawnDied(this);
		}
	}
	simulated Function Timer()
	{
		if (bDoFreezeKarma)
		{
			SetTimer(0,false);
			if (! Level.IsServer())
			{
				KFreezeRagdoll();
			}
		}
		else
		{
			if ((Level.IsMILES() || (OutOfBounds > 0)) || ((AnimManager != nullptr) && AnimManager.CanPlayDeathAnim()))
			{
				bNetAlreadyDead=true;
				bInvulnerableBody=false;
				if (Controller != nullptr)
				{
					if (Controller.bIsPlayer || Controller->IsA(AaAIController::StaticClass()))
					{
						if (Level.IsMILES())
						{
							Log("MILES level signalling controller pawn died");
						}
						if (OutOfBounds > 0)
						{
							Log("Player is out of bounds, signaling controller pawn died");
						}
						Controller.PawnDied(this);
					}
					else
					{
						Log(string(Tag) + "-" + FString::FromInt(Name) + " Pawn died - destroying controller");
						bCleanUp=true;
						Controller.Destroy();
						Controller=nullptr;
					}
				}
				if (IsHumanControlled())
				{
					DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::Timer() unlocking player controller");
					Cast<APlayerController>(Controller).LockPlayer(false,false);
				}
				SetTimer(0,false);
			}
			else
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::Timer() " + FString::FromInt(this) + " timer entered for non-miles, karma not frozen");
				AnimEnd(0);
				bDoFreezeKarma=true;
				SetTimer(10,false);
			}
		}
	}
	simulated Function bool IsDeadFlying()
	{
		switch(DeathAnim)
		{
			case 23:
			return true;
			default:
			return false;
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (bNetAlreadyDead)
		{
			return;
		}
		if ((Controller != nullptr) && (Controller.PlayerReplicationInfo != nullptr))
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::AnimEnd() entered for " + PlayerController(Controller).PlayerReplicationInfo.PlayerName);
		}
		else
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::AnimEnd() " + FString::FromInt(this) + " entered with no controller or no PRI");
		}
		if (IsDeadFlying())
		{
			return;
		}
		bNetAlreadyDead=true;
		bInvulnerableBody=false;
		DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::AnimEnd() Cleaning up controller for this pawn");
		if (Controller != nullptr)
		{
			if (Controller.bIsPlayer)
			{
				Controller.PawnDied(this);
			}
			else
			{
				bCleanUp=true;
				Controller.Destroy();
				Controller=nullptr;
			}
		}
		if (IsHumanControlled())
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::AnimEnd() " + FString::FromInt(this) + " unlocking player controller");
			Cast<APlayerController>(Controller).LockPlayer(false,false);
		}
		AnimBlendToAlpha(Channel,0,0);
		EnableChannelNotify(Channel,0);
	}
	simulated Function EndState()
	{
		DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::EndState() - entered");
		if (Level.IsMILES() || (OutOfBounds > 0))
		{
			Log("AGP_Pawn::Dying::EndState() - Forcing AnimEnd()");
			AnimEnd(0);
		}
		DebugLog(DEBUG_Multi,"AGP_Pawn::Dying::EndState() - Pawn done dying.");
		if (! bPendingDelete)
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::Dying::EndState()	Pawn is leaving the dying state!? " @ FString::FromInt(this));
		}
	}
}
*/

/*
State TimingOut
{
	Function BreathTimer()
	{
	}
	Function TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	{
	}
	Function BeginState()
	{
		if (Level.debugPawnState)
		{
			Log(string(this) @ "AGP_Pawn::BeginState - in state" @ FString::FromInt(GetStateName()));
		}
		SetPhysics(PHYS_None);
		SetCollision(false,false,false);
		LifeSpan=1;
	}
}
*/

// Sets default values
AAGP_Pawn::AAGP_Pawn()
{
	FixedHitQuadrants.SetNum(4);
	HitQuadrants.SetNum(4);
	Subordinate.SetNum(8);
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bReplicates = true;

	NPC_LikesToProne         = 50;
	NPC_LikesToCrouch        = 50;
	NPC_LikesToStand         = 50;
	NPC_LikesToAmbush        = 50;
	NPC_LikesToAssault       = 50;
	NPC_LikesToTalk          = 50;
	NPC_LikesToAmbient       = 50;
	NPC_LikesToThrowGrenade  = 50;
	NPC_ShootAccuracy       = 5;
	iNPC_FragGrenade        = 3;
	iNPC_StunGrenade        = 1;
	iNPC_SmokeGrenade       = 1;
	RagdollOverride         = "SoldierM";
	RagInvInertia           = 4;
	RagShootStrength        = 10000;
	RagSpinScale            = 13;
	RagProneProjectileScale = 0.35;
	followmouse             = true;
	bEyeTrack               = true;
	bUseAuxCollision        = true;
	sBulletWhip             = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby1.WeaponFX_Passby_Passby1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby2.WeaponFX_Passby_Passby2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby3.WeaponFX_Passby_Passby3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Passby4.WeaponFX_Passby_Passby4"), NULL, LOAD_None, NULL)
	};
	sBulletCrack            = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack1.WeaponFX_Passby_Crack1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack2.WeaponFX_Passby_Crack2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack3.WeaponFX_Passby_Crack3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack4.WeaponFX_Passby_Crack4"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack5.WeaponFX_Passby_Crack5"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Passby/WeaponFX_Passby_Crack6.WeaponFX_Passby_Crack6"), NULL, LOAD_None, NULL)
	};
	sMilesGraze             = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/miles/WeaponFX_MILES_NearMiss.WeaponFX_MILES_NearMiss"), NULL, LOAD_None, NULL)
	};
	sParaLanding            = {
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground1.paratrooperhitsground1"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground2.paratrooperhitsground2"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground3.paratrooperhitsground3"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/paratrooperhitsground4.paratrooperhitsground4"), NULL, LOAD_None, NULL)
	};
	sCrouchToProne          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_CrouchToProne.Human_Movement_CrouchToProne"), NULL, LOAD_None, NULL);
	sProneToCrouch          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_ProneToCrouch.Human_Movement_ProneToCrouch"), NULL, LOAD_None, NULL);
	sProneToStand           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_ProneToStand.Human_Movement_ProneToStand"), NULL, LOAD_None, NULL);
	sStandToProne           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/Human_Movement_StandToProne.Human_Movement_StandToProne"), NULL, LOAD_None, NULL);
	fHealDivisor            = 5;
	fpBleedRate             = 5;
	CurrentZoneTimeToKill   = 9999999;
	bNewAccuracy            = true;
	fSpeedPenalty           = 1;
	bCanSwapWeapons         = true;
	bCanCrouch              = true;
	bCanClimbLadders        = true;
	bCanStrafe              = true;
	bCanWalkOffLedges       = true;
	bCanPickupInventory     = true;
	GroundSpeed             = 90;
	WaterSpeed              = 300;
	AirSpeed                = 1200;
	AccelRate               = 2048;
	JumpZ                   = 400;
	AirControl              = 0.35;
	MaxFallSpeed            = 750;
	bCanProne               = true;
	bCanSprint              = true;
	LeanDirection           = 1;
	LeanSpeed               = 4;
	LeanOffsetRight         = FVector(2, 16, -4);
	LeanOffsetLeft          = FVector(-2, 16 , 4);
	LeanRollView            = 2000;
	BreathInSound           = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Breathe/BreatheIn.BreatheIn"), NULL, LOAD_None, NULL);
	BreathOutSound          = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Breathe/BreathOut.BreathOut"), NULL, LOAD_None, NULL);
	fWalkSpeed              = 120;
	fWalkRearPct            = 0.83;
	fRunSpeed               = 220;
	fRunSidePct             = 0.6;
	fCrouchSpeed            = 60;
	fFastCrouchSpeed        = 100;
	fHCrawlSpeed            = 68;
	fLCrawlSpeed            = 25;
	fRollTime               = 1.5;
	CE_RecoveryPenalty      = 1;
	CE_MeterValue           = 1;
	fMaxGrabHeight          = 64;
	fGrabBufferDist         = 5;
	fMantleSpeed            = 50;
	fFallDamageSpd          = -500;
	PrePivot                = FVector(0, 0, -38);
	SoundRadius             = 240;
	bBulletPenetration      = true;
	//KParams = KarmaParamsSkel'AGP.AGP_Pawn.PawnKParams'
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(25.f, 96.0f);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Create a CameraComponent	
	//FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	//FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	//FirstPersonCameraComponent->SetRelativeLocation(FVector(-5.0f, 0.0f, 25 + BaseEyeHeight));
	//FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a 1P Mesh	
	CustomMesh_1P = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P.M249_1P"), NULL, LOAD_None, NULL);
	//Anim_1P       = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Select.Select'"), NULL, LOAD_None, NULL);
	Anim_1P = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M249_1P/Still.Still'"), NULL, LOAD_None, NULL);

	// Create a 3P Mesh	
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman.SoldierM_Infantry_Arctic_Rifleman'"), NULL, LOAD_None, NULL);

	Anim_3P    = LoadObject<UAnimationAsset>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Infantry_Arctic_Rifleman/StdLgFr.StdLgFr'"), NULL, LOAD_None, NULL);
	
	//Prepare the 1P Mesh
	Mesh_1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	Mesh_1P->SetupAttachment(RootComponent);
	//Mesh_1P->SetupAttachment(FirstPersonCameraComponent);

	//Prepare the 3P Mesh
	Mesh_3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ThirdPersonMesh"));
	Mesh_3P->SetupAttachment(RootComponent);
	
	ProjectileClass = AProjectile::StaticClass();

	/*
	UAnimSequence* LoadedAnimation = LoadObject<UAnimSequence>(NULL, *AnimPath, NULL, LOAD_None, NULL);
	FString AnimPath = GetAnimationPath();
	B2Utility::LogInfo(AnimPath);
	UAnimSequence* LoadedAnimation = LoadObject<UAnimSequence>(NULL, *AnimPath, NULL, LOAD_None, NULL);
	if (LoadedAnimation)
	{
		UAnimationAsset* AnimationAsset = Cast<UAnimationAsset>(LoadedAnimation);
		if (AnimationAsset)
		{
			AvatarMesh->SetAnimation(AnimationAsset);
			AvatarMesh->PlayAnimation(AnimationAsset, true);
		}
	}
	*/
	LoadMesh();

	//From Pawn:
	HealthMax = 100.000000;
	Health = 100;

	AGP_Direction = 50;				//Forward -50 -> 50
	AGP_Speed = 0;				//Sprint Forward 0 -> 100

	/*
	//Specify Animation BluePrint
	Mesh_3P->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> FoundAnimBP(TEXT("/Game/AmericasArmy/Blueprints/Anim/SoldierM_AnimBlueprint.SoldierM_AnimBlueprint"));
	UAnimBlueprintGeneratedClass* PreviewBP = FoundAnimBP.Object->GetAnimBlueprintGeneratedClass();
	Mesh_3P->SetAnimInstanceClass(PreviewBP);
	*/

	UKarmaParamsSkel* PawnKParams = NewObject<UKarmaParamsSkel>(UKarmaParamsSkel::StaticClass());


	FriendlyMaterial.SetNum(5);		//var UMaterialInstance* FriendlyMaterial[5];
	EnemyMaterial.SetNum(5);		//var UMaterialInstance* EnemyMaterial[5];
}


void AAGP_Pawn::BeginPlay()
{
	FString myName;

	//Inventory = AWeapon_M16A2_Rifle::StaticClass();

	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		fInitialAnimationComplete = true;
	}
	Super::BeginPlay();
	
	if (GetNetMode() == ENetMode::NM_Client)
	{
		
		/*
		if (Cast<AAGP_GameInfo>(GetGameMode()).bNoInventory)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::BeginPlay()	Not giving InvContainers!"));
		}
		else
		{
			if (_InvHands == nullptr)
			{
				_InvHands=SpawnContainer("AGP_Inventory.InvHands");
				_InvShoulder=SpawnContainer("AGP_Inventory.InvShoulder");
				_InvUtility=SpawnContainer("AGP_Inventory.InvUtility");
				_InvHolster=SpawnContainer("AGP_Inventory.InvHolster");
				_InvHip=SpawnContainer("AGP_Inventory.InvHip");
				_InvAltShoulder=SpawnContainer("AGP_Inventory.InvAltShoulder");
			}
		}
		*/

		/*
			//Spawn a M24
			UWorld* const World = GetWorld();
			//FVector myLocation = GetActorLocation();
			myLocation = FVector(1900.998901, -282.000000, 262.000671);
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = Instigator;
				AActor* const SpawningObject = World->SpawnActor<AActor>(AWeapon_M24_Sniper::StaticClass(), myLocation, FRotator::ZeroRotator, SpawnParams);
			}
		*/
	}

}


void AAGP_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FastTick(DeltaTime);
}

//These is the new ones:
AAGP_Pawn* AAGP_Pawn::Clone()
{
	return nullptr;      //FAKE   /ELiZ
}
void AAGP_Pawn::AnimateGrenadeMoving()
{
}
void AAGP_Pawn::RemoveParachuteSkins()
{
}
void AAGP_Pawn::MatchStarting()
{
}
void AAGP_Pawn::ConfigureLinkDamage()
{
}
void AAGP_Pawn::ActivateLinkedObjective(APawn* User)
{
}
void AAGP_Pawn::SetWeaponRelativeRotation(FRotator rotNew)
{
}
void AAGP_Pawn::SetAnimAction(FName NewAction)
{
	if (GetNetMode() != ENetMode::NM_Client)
	{
		//EnableChannelNotify(1,1);
		//AnimBlendParams(1,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim(NewAction,1,0.05,1);

	}
	else
	{
		//EnableChannelNotify(1,1);
		//AnimBlendParams(1,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim(NewAction,1,0.05,1);
		//AnimAction=NewAction;
	}
}

void AAGP_Pawn::ClientSetViewRotation(FRotator NewRotation)
{
	//SetViewRotation(NewRotation);
}

void AAGP_Pawn::KNotifySimError()
{
	AHumanController* HC = nullptr;
	/*
	HC=Cast<AHumanController>(Level.GetClientController());
	if (HC.ViewTarget == this)
	{
		HC.NotifyLostViewTarget();
	}
	*/
}

void AAGP_Pawn::SetupBoneAuxCylinder()
{
	if (BoneAuxCyl == nullptr)
	{
		//BoneAuxCyl=Spawn(AAuxCollisionCylinder::StaticClass(),Self,,Location);
	}
	//BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	BoneAuxCyl->SetAuxCylinder(false);
	//BoneAuxCyl->SetBase(this);
	BoneAuxCyl->SetOwner(this);
	//BoneAuxCyl->bProjTarget=true;
	//BoneAuxCyl->bBlockBulletTraces=true;
	//bBlockBulletTraces=false;
}

void AAGP_Pawn::PreBeginPlay()
{
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	//Super::PreBeginPlay();
	if (bUseAuxCollision)
	{
		SetupBoneAuxCylinder();
		//GetAxes(Rotation,X,Y,Z);
		if (FrontAuxCyl == nullptr)
		{
			//FrontAuxCyl=Spawn(AAuxCollisionCylinder::StaticClass(),Self,,Location + X * ProneRadius * 1.5);
		}
		if (BackAuxCyl == nullptr)
		{
			//BackAuxCyl=Spawn(AAuxCollisionCylinder::StaticClass(),Self,,Location - X * ProneRadius * 1.3);
		}
		//FrontAuxCyl->SetBase(this);
		//BackAuxCyl->SetBase(this);
		FrontAuxCyl->SetAuxCylinder(false);
		BackAuxCyl->SetAuxCylinder(false);
		//BoneAuxCyl->SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
		
		bInProneTransition=false;
	}
	//NV_AmbientGlow=Cast<AAA2_WorldSettings>(GetWorldSettings())->Pawn_NV_AmbientGlow;
	fHopTimer=8;
}

void AAGP_Pawn::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PostBeginPlay()	" + Self);
	Super::PostBeginPlay();
	SetActorRotation(FRotator(0,Rotation.Yaw,0));
	if (GetNetMode() != ENetMode::NM_Client)
	{
		SetCustomTimer(1,True,'AlertAIOfPlayerNoiseTimer');
	}
	*/
}

void AAGP_Pawn::AlertAIOfPlayerNoiseTimer()
{
	
	if (bIsProne || bIsCrouched || bIsWalking)
	{
		return;
	}
	//if (VSize(Velocity) > 0)
	//{
	//	MakeNoise(1,Self);
	//}
}

void AAGP_Pawn::PostBeginNetPlay()
{
	/*
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PostBeginNetPlay()	" + Self);
	SetActorRotation(FRotator(0,Rotation.Yaw,0));
	*/
}

bool AAGP_Pawn::AllowAnimFiring()
{
	return true;
}

AInvContainer* AAGP_Pawn::SpawnContainer(FString class_name)
{
	AInvContainer* local_container = nullptr;
	AInvContainer* container_class = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SpawnContainer() - creating " + class_name);
	}
	container_class=class<InvContainer>(DynamicLoadObject(class_name,Class'Class'));
	if (container_class != nullptr)
	{
		local_container=Spawn(container_class,Self);
		if (local_container != nullptr)
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			{
				DebugLog(DEBUG_Inv,"PickupFunction for " + local_container);
			}
			local_container.PickupFunction(this);
			AddContainer(local_container);
			return local_container;
		}
	}
	DebugLog(DEBUG_Warn,"AGP_Pawn::SpawnContainer()	Failed to create InvContainer " + class_name);
	*/
	return nullptr;
}

void AAGP_Pawn::AddContainer(AInvContainer* Add)
{
	AInvContainer* Last;
	if (_InvTop == nullptr)
	{
		_InvTop=Add;
	}
	else
	{
		Last=_InvTop;
		if (Last->nextContainer != nullptr)
		{
			Last=Last->nextContainer;
		}
		Last->nextContainer=Add;
	}
}

void AAGP_Pawn::PossessedBy(AController* C)
{
	Super::PossessedBy(C);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("%s, Possessed by : %s"), *GetHumanReadableName(), *C->GetName()), false);
	}
	/*
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Entered");
	DebugLog(DEBUG_Multi,"Possessing:" @ Self);
	PossessedBy(C);
	if (PlayerReplicationInfo != nullptr)
	{
		DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy PRI != nullptr; Calling ServerSetMyPawn()");
		PlayerReplicationInfo.ServerSetMyPawn(this);
	}
	if (C->IsA(AaAIController::StaticClass()))
	{
		return;
	}
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Calling SpawnTeamClass()");
	
	SpawnTeamClass(Cast<AAGP_Pawn>(C)->TeamClassClass);
	
	if (PlayerReplicationInfo != nullptr)
	{
		PlayerReplicationInfo.requiredClass=C.TeamClassClass;
	}
	DebugLog(DEBUG_Multi,Self @ "AGP_Pawn::PossessedBy Leaving");
	*/
}

void AAGP_Pawn::SpawnTeamClass(AActor* actor_class)
{
	ASoldierClass*  sclass = nullptr;
	AHumanController* HC = nullptr;

	HC = Cast<AHumanController>(Controller);

	if (HC != nullptr && !HC->QualifiedFor(actor_class))
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changing to Rifleman " + this @ actor_class);
	}

	/*
	HC=Cast<AHumanController>(Controller);
	if (HC != nullptr && ! HC.QualifiedFor(actor_class))
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changing to Rifleman " + this @ actor_class);
		if (PlayerReplicationInfo.bGuerrillaPS)
		{
			sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassGuerrillaAK74su",Class'Class'));
		}
		else
		{
			if (PlayerReplicationInfo.bSpecialForcesPS)
			{
				sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassSFRifleman",Class'Class'));
			}
			else
			{
				switch(PlayerReplicationInfo.Team.UseAltClass(0))
				{
					case 1:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRiflemanM4A1AutoIron",Class'Class'));
					break;
					case 2:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRiflemanM4A1Auto",Class'Class'));
					break;
					default:
					sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRifleman",Class'Class'));
				}
				DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Not qualified for class - changed to: " + this + sclass);
			}
		}
	}
	else
	{
		sclass=class<SoldierClass>(actor_class);
	}
	if (sclass == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamClass()	Got a null SoldierClass - defaulting to Recruit");
		sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassRecruit",Class'Class'));
	}
	DebugLog(DEBUG_Inv,"AGP_Pawn::SpawnTeamClass() " + this @ sclass);
	if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.bSpecialForcesPS && ! PlayerReplicationInfo.bQualifiedSF)
	{
		sclass=class<SoldierClass>(DynamicLoadObject("AGP_Characters.ClassGuerrillaAK74su",Class'Class'));
	}
	if (TeamClass != nullptr && sclass != nullptr && TeamClass.Class != sclass)
	{
		DebugLog(DEBUG_Warn,"sclass doesn't match current TeamClass");
	}
	if (TeamClass == nullptr && sclass != nullptr)
	{
		TeamClass=Spawn(sclass,Self);
	}
	TeamClass.adjustAttributes();
	*/
}

void AAGP_Pawn::SpawnTeamRole(AActor* actor_class)
{
	ASoldierRole* srole = nullptr;
	/*
	srole=class<SoldierRole>(actor_class);
	if (srole == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::SetTeamRole()	Got a null SoldierRole - defaulting to FTMember");
		srole=class<SoldierRole>(DynamicLoadObject("AGP_AI.FTMemberRole",Class'Class'));
	}
	TeamRole=Spawn(srole,Self);
	*/
}

AMentalModel* AAGP_Pawn::getMentalModel()
{
	if (_mentalModel == nullptr && Leader != nullptr)
	{
		return Leader->getMentalModel();
	}
	else
	{
		return _mentalModel;
	}
}

AMentalModel* AAGP_Pawn::createMentalModel()
{
	//_mentalModel=Spawn('MentalModel');
	return getMentalModel();
}

AMentalModel* AAGP_Pawn::resetMentalModel()
{
	_mentalModel=nullptr;
	return getMentalModel();
}

void AAGP_Pawn::setMentalModel(AMentalModel* set_mm)
{
	_mentalModel=set_mm;
}

bool AAGP_Pawn::ownsMentalModel()
{
	if (_mentalModel == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

FRotator AAGP_Pawn::GetInterpolatedRotation()
{
	//return FRotator(InterpolatedPitch,InterpolatedYaw,0);
	return FRotator(0, 0, 0);    //FAKE   /ELiZ
}

void AAGP_Pawn::LockMovement(bool bLock)
{
	bLockMovement=bLock;
}
void AAGP_Pawn::LimitRotation(bool bLimit)
{
	bLimitRotation=bLimit;
}

void AAGP_Pawn::SetMovementPhysics()
{
	/*
	if (Physics == 2)
	{
		return;
	}
	else
	{
		if (DrivenVehicle == nullptr)
		{
			SetPhysics(1);
		}
	}
	*/
}
void AAGP_Pawn::SetWalking(bool bNewIsWalking)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"SLOWMODE," + bNewIsWalking);
	}
	if (Physics == 17)
	{
		return;
	}
	if (bNewIsWalking != bIsWalking || bIsScriptedWalking)
	{
		bIsWalking=bNewIsWalking;
		if (bIsScriptedWalking)
		{
			bIsWalking=true;
		}
		if (bIsWalking)
		{
			bWantsToSprint=false;
		}
		if (Weapon != nullptr)
		{
			Weapon.SetFastMove(! bIsWalking);
		}
	}
	UpdateGroundspeeds();
	*/
}
void AAGP_Pawn::UpdateGroundspeeds()
{
	if (bIsProne)
	{
		if (! bIsWalking)
		{
			GroundSpeed=fHCrawlSpeed * fSpeedPenalty;
		}
		else
		{
			GroundSpeed=fLCrawlSpeed * fSpeedPenalty;
		}
		AccelRate=2048;
	}
	else
	{
		if (bIsCrouched)
		{
			if (! bIsWalking)
			{
				GroundSpeed=fFastCrouchSpeed * fSpeedPenalty;
			}
			else
			{
				GroundSpeed=fCrouchSpeed * fSpeedPenalty;
			}
			AccelRate=2048;
		}
		else
		{
			if (! bIsWalking)
			{
				GroundSpeed=fRunSpeed * fSpeedPenalty;
				//AccelRate=Default.AccelRate;
			}
			else
			{
				GroundSpeed=fWalkSpeed * fSpeedPenalty;
				AccelRate=2048;
			}
		}
	}
}

void AAGP_Pawn::EndClimbLadder(ALadderVolume* OldLadder)
{
	/*
	if (Controller != nullptr)
	{
		Controller.EndClimbLadder();
	}
	if (Controller != nullptr && GetNetMode() == ENetMode::NM_Standalone)
	{
		Cast<AStudentController>(Controller)->EndClimbingLadder(OldLadder);
	}
	if (Physics == 11)
	{
		if (Controller->IsA(AaAIController::StaticClass()))
		{
			SetPhysics(2);
		}
		else
		{
			SetPhysics(1);
		}
	}
	if (Weapon != nullptr)
	{
		Weapon.TempRaiseWeapon();
	}
	LimitRotation(false);
*/

}

void AAGP_Pawn::ClimbLadder(ALadderVolume* L)
{
	/*
	if (isDead())
	{
		return;
	}
	TakeFallingDamage();
	if (Velocity.Z < -1.4 * JumpZ)
	{
		Log("Velocity fast when entering ladder volume: " + Velocity.Z + " Damage is " + GetFallingDamage(Velocity.Z));
		MakeNoise(-0.5 * Velocity.Z / FMax(JumpZ,150));
	}
	if (Controller != nullptr && GetNetMode() == ENetMode::NM_Standalone)
	{
		Cast<AStudentController>(Controller)->StartClimbingLadder(L);
	}
	OnLadder=L;
	SetActorRotation(OnLadder.WallDir);
	SetPhysics(11);
	if (IsHumanControlled())
	{
		Controller.GotoState('PlayerClimbing');
	}
	GotoState("None");
	if (Weapon != nullptr && ! Weapon.IsInState('BusyTempLowering') || Weapon.IsInState('BusyTempDown'))
	{
		Weapon.TempLowerWeapon();
	}
	bWantsToSprint=false;
	ResetLean();
	CombatEffectivenessEvent(9);
	LimitRotation(true);
	rRotationLimits=Default.rRotationLimits;
	rBaseRotation=L.WallDir;
	*/
}

bool AAGP_Pawn::CanGrabLadder()
{
	//return bCanClimbLadders && Physics != 11;
	return false;    //FAKE   /ELiZ
}

float AAGP_Pawn::GetSprintModifier(float DeltaYaw, float DeltaTime, bool bJumped)
{
	float mod = 0;
	/*
	if (bIsSprinting)
	{
		CombatEffectivenessEvent(4,DeltaTime);
		if (DeltaYaw > 32768)
		{
			mod=1;
		}
		else
		{
			if (DeltaYaw != 0)
			{
				mod=FClamp(fSprintMod - Default.fSprintMod - 1 * DeltaYaw / 32768,1,Default.fSprintMod);
			}
			else
			{
				mod=FClamp(fSprintMod + Default.fSprintMod - 1 * DeltaTime * 0.75,1,Default.fSprintMod);
			}
		}
	}
	else
	{
		if (fSprintMod != Default.fSprintMod)
		{
			mod=FClamp(fSprintMod + Default.fSprintMod - 1 * DeltaTime * 0.75,1,Default.fSprintMod);
		}
		else
		{
			mod=fSprintMod;
		}
	}
	if (bJumped)
	{
		mod *= 0.75;
	}
	*/
	return mod;
}

/*
 // ======================================================================================
 // AGP function - GetSpeedModifier
 // Retrieves a scalar [0,1] that limits the total groundspeed of the pawn
 // Takes into account Strength, Inventory Weight, and Damage
 // output:	float [0,1] to scale groundspeed
 // last modified by:  superville 12/20/01
 // ======================================================================================
*/
float AAGP_Pawn::GetSpeedModifier()
{
	float Modifier = 0;
	EHealthCondition HC = EHealthCondition::HC_GREEN;
	/*
	Modifier=1;
	if (fInvWeight > fStrength)
	{
		Modifier *= 1 - fInvWeight - fStrength / fInvWeight / 2;
	}
	if (Level.GamePlayMode == 0)
	{
		HC=GetHealthCondition();
		if (HC == 0)
		{
			Modifier *= 1;
		}
		else
		{
			if (HC == 1)
			{
				Modifier *= 0.8;
			}
			else
			{
				if (HC == 2)
				{
					Modifier *= 0.6;
				}
				else
				{
					Modifier *= 0;
				}
			}
		}
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"GetSpeedModifier:" @ SpeedRatio);
	}
	*/
	return Modifier;
}

/* =================================================================================== *
 * AGP function GetSpeedModifier_Always()
 *	The normal speed modifier only applies to your max possible speed (standing/fast mode)
 *	This modifier gets applied to your current speed, no matter what mode you are in.
 *	Right now, only being zoomed currently affects your speed in all cases.
 *
 * output:	float [0,1] to scale groundspeed
 *
 * last modified by: cmb
 * =================================================================================== */
float AAGP_Pawn::GetSpeedModifier_Always()
{
	float Modifier;
	Modifier=1;
	if (IsZoomed())
	{
		Modifier *= 1;
	}
	return Modifier;
}

void AAGP_Pawn::StartMantle(int32 EndPosture, FVector MantleLoc, FRotator BaseRot)
{
	FVector Move = FVector(0,0,0);
	/*
	iMantleEndPosture=EndPosture;
	vMantlePoint=MantleLoc;
	rBaseRotation=BaseRot;
	rRotationLimits=Default.rRotationLimits;
	LimitRotation(true);
	Move=Location - vMantlePoint;
	Move.Z=0;
	Move=Normal(Move) * CollisionRadius + fGrabBufferDist;
	Move=vMantlePoint + Move;
	Move.Z=Location.Z;
	SetActorLocation(Move);
	if (Controller != nullptr)
	{
		Controller.GotoState('PlayerMantle');
	}
	*/
}

void AAGP_Pawn::EndMantle(int32 EndPosture)
{
	/*
	LimitRotation(false);
	if (EndPosture == 0)
	{
		ShouldStand();
	}
	else
	{
		if (EndPosture == 1)
		{
			ShouldCrouch(true);
		}
		else
		{
			ShouldProne(true);
		}
	}
	SetPhysics(2);
	if (Controller != nullptr)
	{
		Controller.GotoState('PlayerWalking');
	}
	*/
}

FRotator AAGP_Pawn::GetViewRotation() const
{
	/*
	if (UseAnimatedEyeRotation())
	{
		return EyeRotation();
	}
	else
	{
		return Super::GetViewRotation();
	}
	*/
	return Super::GetViewRotation();
}

bool AAGP_Pawn::UseAnimatedEyeRotation()
{
	return false;
}

FVector AAGP_Pawn::EyePosition()
{
	//return EyeHeight * FVector(0, 0, 1) + WalkBob + Location;
	return FVector(0, 0, 0);   //FAKE ELiZ
}

FRotator AAGP_Pawn::EyeRotation()
{
	return GetViewRotation();
}

void AAGP_Pawn::CheckBob(float DeltaTime, FVector Y)
{
	float Speed2D = 0;
	/*
	Speed2D=Sqrt(Velocity.X * Velocity.X + Velocity.Y * Velocity.Y);
	if (Speed2D < 10)
	{
		bobtime += 0.2 * DeltaTime;
	}
	else
	{
		bobtime += DeltaTime * 0.3 + 0.7 * Speed2D / GroundSpeed * 2.5;
	}
	WalkBob=Y * 0.2 * Bob * Speed2D * Sin(8 * bobtime);
	AppliedBob=AppliedBob * 1 - FMin(1,16 * DeltaTime);
	if (Speed2D < 10)
	{
		WalkBob.Z=AppliedBob;
	}
	else
	{
		WalkBob.Z=AppliedBob + 0.1 * Bob * Speed2D * Sin(16 * bobtime);
	}
	*/
}
void AAGP_Pawn::AngleEditorCalculate()
{
	
	FRotator Rotator;
	float multiplier;
	multiplier=182;
	
	if (s1boneangle1R > 180)
	{
		s1boneangle1R=s1boneangle1R - 180 - 180;
	}
	if (s1boneangle1R < -180)
	{
		s1boneangle1R=s1boneangle1R + 180 + 180;
	}
	if (s1boneangle1P > 180)
	{
		s1boneangle1P=s1boneangle1P - 180 - 180;
	}
	if (s1boneangle1P < -180)
	{
		s1boneangle1P=s1boneangle1P + 180 + 180;
	}
	if (s1boneangle1Y > 180)
	{
		s1boneangle1Y=s1boneangle1Y - 180 - 180;
	}
	if (s1boneangle1Y < -180)
	{
		s1boneangle1Y=s1boneangle1Y + 180 + 180;
	}
	if (s1boneangle2R > 180)
	{
		s1boneangle2R=s1boneangle2R - 180 - 180;
	}
	if (s1boneangle2R < -180)
	{
		s1boneangle2R=s1boneangle2R + 180 + 180;
	}
	if (s1boneangle2P > 180)
	{
		s1boneangle2P=s1boneangle2P - 180 - 180;
	}
	if (s1boneangle2P < -180)
	{
		s1boneangle2P=s1boneangle2P + 180 + 180;
	}
	if (s1boneangle2Y > 180)
	{
		s1boneangle2Y=s1boneangle2Y - 180 - 180;
	}
	if (s1boneangle2Y < -180)
	{
		s1boneangle2Y=s1boneangle2Y + 180 + 180;
	}
	if (s1boneangle3R > 180)
	{
		s1boneangle3R=s1boneangle3R - 180 - 180;
	}
	if (s1boneangle3R < -180)
	{
		s1boneangle3R=s1boneangle3R + 180 + 180;
	}
	if (s1boneangle3P > 180)
	{
		s1boneangle3P=s1boneangle3P - 180 - 180;
	}
	if (s1boneangle3P < -180)
	{
		s1boneangle3P=s1boneangle3P + 180 + 180;
	}
	if (s1boneangle3Y > 180)
	{
		s1boneangle3Y=s1boneangle3Y - 180 - 180;
	}
	if (s1boneangle3Y < -180)
	{
		s1boneangle3Y=s1boneangle3Y + 180 + 180;
	}
	if (s2boneangle1R > 180)
	{
		s2boneangle1R=s2boneangle1R - 180 - 180;
	}
	if (s2boneangle1R < -180)
	{
		s2boneangle1R=s2boneangle1R + 180 + 180;
	}
	if (s2boneangle1P > 180)
	{
		s2boneangle1P=s2boneangle1P - 180 - 180;
	}
	if (s2boneangle1P < -180)
	{
		s2boneangle1P=s2boneangle1P + 180 + 180;
	}
	if (s2boneangle1Y > 180)
	{
		s2boneangle1Y=s2boneangle1Y - 180 - 180;
	}
	if (s2boneangle1Y < -180)
	{
		s2boneangle1Y=s2boneangle1Y + 180 + 180;
	}
	if (s2boneangle2R > 180)
	{
		s2boneangle2R=s2boneangle2R - 180 - 180;
	}
	if (s2boneangle2R < -180)
	{
		s2boneangle2R=s2boneangle2R + 180 + 180;
	}
	if (s2boneangle2P > 180)
	{
		s2boneangle2P=s2boneangle2P - 180 - 180;
	}
	if (s2boneangle2P < -180)
	{
		s2boneangle2P=s2boneangle2P + 180 + 180;
	}
	if (s2boneangle2Y > 180)
	{
		s2boneangle2Y=s2boneangle2Y - 180 - 180;
	}
	if (s2boneangle2Y < -180)
	{
		s2boneangle2Y=s2boneangle2Y + 180 + 180;
	}
	if (s2boneangle3R > 180)
	{
		s2boneangle3R=s2boneangle3R - 180 - 180;
	}
	if (s2boneangle3R < -180)
	{
		s2boneangle3R=s2boneangle3R + 180 + 180;
	}
	if (s2boneangle3P > 180)
	{
		s2boneangle3P=s2boneangle3P - 180 - 180;
	}
	if (s2boneangle3P < -180)
	{
		s2boneangle3P=s2boneangle3P + 180 + 180;
	}
	if (s2boneangle3Y > 180)
	{
		s2boneangle3Y=s2boneangle3Y - 180 - 180;
	}
	if (s2boneangle3Y < -180)
	{
		s2boneangle3Y=s2boneangle3Y + 180 + 180;
	}
	if (s3boneangle1R > 180)
	{
		s3boneangle1R=s3boneangle1R - 180 - 180;
	}
	if (s3boneangle1R < -180)
	{
		s3boneangle1R=s3boneangle1R + 180 + 180;
	}
	if (s3boneangle1P > 180)
	{
		s3boneangle1P=s3boneangle1P - 180 - 180;
	}
	if (s3boneangle1P < -180)
	{
		s3boneangle1P=s3boneangle1P + 180 + 180;
	}
	if (s3boneangle1Y > 180)
	{
		s3boneangle1Y=s3boneangle1Y - 180 - 180;
	}
	if (s3boneangle1Y < -180)
	{
		s3boneangle1Y=s3boneangle1Y + 180 + 180;
	}
	if (s3boneangle2R > 180)
	{
		s3boneangle2R=s3boneangle2R - 180 - 180;
	}
	if (s3boneangle2R < -180)
	{
		s3boneangle2R=s3boneangle2R + 180 + 180;
	}
	if (s3boneangle2P > 180)
	{
		s3boneangle2P=s3boneangle2P - 180 - 180;
	}
	if (s3boneangle2P < -180)
	{
		s3boneangle2P=s3boneangle2P + 180 + 180;
	}
	if (s3boneangle2Y > 180)
	{
		s3boneangle2Y=s3boneangle2Y - 180 - 180;
	}
	if (s3boneangle2Y < -180)
	{
		s3boneangle2Y=s3boneangle2Y + 180 + 180;
	}
	if (s3boneangle3R > 180)
	{
		s3boneangle3R=s3boneangle3R - 180 - 180;
	}
	if (s3boneangle3R < -180)
	{
		s3boneangle3R=s3boneangle3R + 180 + 180;
	}
	if (s3boneangle3P > 180)
	{
		s3boneangle3P=s3boneangle3P - 180 - 180;
	}
	if (s3boneangle3P < -180)
	{
		s3boneangle3P=s3boneangle3P + 180 + 180;
	}
	if (s3boneangle3Y > 180)
	{
		s3boneangle3Y=s3boneangle3Y - 180 - 180;
	}
	if (s3boneangle3Y < -180)
	{
		s3boneangle3Y=s3boneangle3Y + 180 + 180;
	}
	Rotator.Roll=s1boneangle1R * multiplier;
	Rotator.Pitch=s1boneangle1P * multiplier;
	Rotator.Yaw=s1boneangle1Y * multiplier;
	//SetBoneRotation('spine01',Rotator,0,1);
	Rotator.Roll=s1boneangle2R * multiplier;
	Rotator.Pitch=s1boneangle2P * multiplier;
	Rotator.Yaw=s1boneangle2Y * multiplier;
	//SetBoneRotation('Spine02',Rotator,0,1);
	Rotator.Roll=s1boneangle3R * multiplier;
	Rotator.Pitch=s1boneangle3P * multiplier;
	Rotator.Yaw=s1boneangle3Y * multiplier;
	//SetBoneRotation('head',Rotator,0,1);
	Rotator.Roll=s2boneangle1R * multiplier;
	Rotator.Pitch=s2boneangle1P * multiplier;
	Rotator.Yaw=s2boneangle1Y * multiplier;
	//SetBoneRotation('RArmUp',Rotator,0,1);
	Rotator.Roll=s2boneangle2R * multiplier;
	Rotator.Pitch=s2boneangle2P * multiplier;
	Rotator.Yaw=s2boneangle2Y * multiplier;
	//SetBoneRotation('RArmLow',Rotator,0,1);
	Rotator.Roll=s2boneangle3R * multiplier;
	Rotator.Pitch=s2boneangle3P * multiplier;
	Rotator.Yaw=s2boneangle3Y * multiplier;
	//SetBoneRotation('RHand',Rotator,0,1);
	Rotator.Roll=s3boneangle1R * multiplier;
	Rotator.Pitch=s3boneangle1P * multiplier;
	Rotator.Yaw=s3boneangle1Y * multiplier;
	//SetBoneRotation('LArmUp',Rotator,0,1);
	Rotator.Roll=s3boneangle2R * multiplier;
	Rotator.Pitch=s3boneangle2P * multiplier;
	Rotator.Yaw=s3boneangle2Y * multiplier;
	//SetBoneRotation('LArmLow',Rotator,0,1);
	Rotator.Roll=s3boneangle3R * multiplier;
	Rotator.Pitch=s3boneangle3P * multiplier;
	Rotator.Yaw=s3boneangle3Y * multiplier;
	//SetBoneRotation('LHand',Rotator,0,1);
}
void AAGP_Pawn::PlayBoneAnim(FName BoneName)
{
	/*
	boneAnimFrame=0;
	boneAnimDirection=true;
	boneAnimComplete=false;
	boneAnimName=BoneName;
	rotTorsoFire.Yaw=0;
	rotTorsoFire.Pitch=0;
	if (Controller != nullptr)
	{
		rotTorsoFire.Roll=Controller.Rotation.Pitch;
	}
	else
	{
		rotTorsoFire.Roll=AnimPitch;
	}
	*/
}
void AAGP_Pawn::UpdateBoneAnim()
{
	/*
	if (boneAnimComplete)
	{
		return;
	}
	if (boneAnimFrame < 5 && boneAnimDirection)
	{
		rotTorsoFire.Pitch=rotTorsoFire.Pitch - 200;
		rotTorsoFire.Roll=rotTorsoFire.Roll + 400;
		boneAnimFrame ++;
	}
	else
	{
		boneAnimFrame --;
		boneAnimDirection=false;
		rotTorsoFire.Pitch=rotTorsoFire.Pitch + 200;
		rotTorsoFire.Roll=rotTorsoFire.Roll - 400;
		if (boneAnimFrame < 1)
		{
			boneAnimComplete=true;
		}
	}
	rotTorsoFire.Yaw=0;
	SetBoneRotation(boneAnimName,rotTorsoFire,0,1);
	*/
}

bool AAGP_Pawn::ShouldDrawCrosshair()
{
	/*
	if (Controller == nullptr || Controller.IsInState('BaseSpectating'))
	{
		return false;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		if (bForceDrawCrosshair || Controller.IsInState('MedicTraining_TakingExam') || Controller.IsInState('MedicTraining_TakingExam2') || Controller.IsInState('SFTraining_TakingExam'))
		{
			return true;
		}
	}
	if (IsBusy() || bIsSprinting || Weapon == nullptr || bIsDead)
	{
		return false;
	}
	return Weapon.ShouldDrawCrosshair() && Controller.ShouldRenderWeapon();
	*/
	return false;    //FAKE  /EliZ
}
/*
void AAGP_Pawn::StopDriving (Vehicle V)
{
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.Destroy();
		BoneAuxCyl=nullptr;
		SetupBoneAuxCylinder();
	}
	StopDriving(V);
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != nullptr && Controller->IsA(APlayerController::StaticClass()))
	{
		Cast<APlayerController>(Controller).LockPlayer(false,false);
	}
}
*/

void AAGP_Pawn::AnimEnd(int32 Channel)
{
	/*
	if (_AnimationMonitor != nullptr)
	{
		_AnimationMonitor.AnimEnd(Channel);
		return;
	}
	if (Channel == 13)
	{
		FullBodyAnimComplete();
	}
	else
	{
		if (Channel == 15)
		{
			if (UpperBodyAnim == 7 || UpperBodyAnim == 8)
			{
				UpperBodyAnim=1;
			}
			else
			{
				if (Role > 2)
				{
					if (UpperBodyAnim != 9 && UpperBodyAnim != 12)
					{
						UpperBodyAnimComplete();
					}
				}
				else
				{
					PredictUpperBodyAnim();
				}
			}
			ChangeAnimation();
		}
	}
	if (Channel == 13 || Channel == 15 && ! IsAnimating(13))
	{
		if (isDead())
		{
			GotoState('Dying');
		}
		else
		{
			GotoState("None");
		}
	}
	*/
}

/*
 // ======================================================================================
 // AGP function - PredictUpperBodyAnim
 // Used for SimulatedProxy pawns to help predict the next animation sequence to blend to
 // This helps prevent animation popping over a lagged network.
 // last modified by:  superville 06/03/01
 // ======================================================================================
*/

void AAGP_Pawn::PredictUpperBodyAnim()
{

	switch (UpperBodyAnim)
	{
		// Predict that the pawn came from a position with or without a gun and will go back to that position
		// since gun swaps aren't allowed during hand signals
		case EUpperBodyAnim::UBANIM_HAND_MoveOut:
		case EUpperBodyAnim::UBANIM_HAND_Hold:
		case EUpperBodyAnim::UBANIM_HAND_TakeCover:
		case EUpperBodyAnim::UBANIM_HAND_PointFwd:
		case EUpperBodyAnim::UBANIM_HAND_Ready:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTime:
		case EUpperBodyAnim::UBANIM_HAND_Affirm:
		case EUpperBodyAnim::UBANIM_HAND_Neg:

		case EUpperBodyAnim::UBANIM_HAND_MoveOutGn:
		case EUpperBodyAnim::UBANIM_HAND_HoldGn:
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverGn:
		case EUpperBodyAnim::UBANIM_HAND_PointFwdGn:
		case EUpperBodyAnim::UBANIM_HAND_ReadyGn:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeGn:
		case EUpperBodyAnim::UBANIM_HAND_AffirmGn:
		case EUpperBodyAnim::UBANIM_HAND_NegGn:

		case EUpperBodyAnim::UBANIM_HAND_MoveOutSm:
		case EUpperBodyAnim::UBANIM_HAND_HoldSm:
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverSm:
		case EUpperBodyAnim::UBANIM_HAND_PointFwdSm:
		case EUpperBodyAnim::UBANIM_HAND_ReadySm:
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeSm:
		case EUpperBodyAnim::UBANIM_HAND_AffirmSm:
		case EUpperBodyAnim::UBANIM_HAND_NegSm:
			UpperBodyAnim = LastUpperBodyAnim;
			return;

			// Predict that if a pawn is raising a weapon it will be a large weapon
		case EUpperBodyAnim::UBANIM_WEAP_RaiseLg:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Large;
			return;

			// Predict that if the player is reloading, they will play the same idle anim they were playing before
		case EUpperBodyAnim::UBANIM_WEAP_Reload:
			UpperBodyAnim = LastUpperBodyAnim;
			return;

			// Predict that if a pawn is lowering a weapon it will have empty hands after
			//agp:aafa [mwd] javelin animation code
		case EUpperBodyAnim::UBANIM_Jav_LowerJav:
		case EUpperBodyAnim::UBANIM_WEAP_LowerLg:
		case EUpperBodyAnim::UBANIM_GREN_LowerGn:
		case EUpperBodyAnim::UBANIM_BINOC_LowerBn:
		case EUpperBodyAnim::UBANIM_RPG_LowerRPG:
		case EUpperBodyAnim::UBANIM_RPG_LowerRPG_NS:
		case EUpperBodyAnim::UBANIM_AT4_LowerAT4:
		case EUpperBodyAnim::UBANIM_BDM_LowerBDM:
		case EUpperBodyAnim::UBANIM_PISTOL_Lower:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Empty;
			return;

		case EUpperBodyAnim::UBANIM_GREN_Throwing_Over:
		case EUpperBodyAnim::UBANIM_GREN_Throwing_Under:
			if (LastUpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large)
				UpperBodyAnim = EUpperBodyAnim::UBANIM_WEAP_RaiseLg;
			else
				UpperBodyAnim = EUpperBodyAnim::UBANIM_NONE_Empty;
			return;

			// Predict that if a pawn is raising a grenade it will be a greande in his hands
		case EUpperBodyAnim::UBANIM_GREN_RaiseGn:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_GREN_Ready;
			return;

			// Predict that if a pawn is raising binoculars or lowering from zoom it will be binocs ready
		case EUpperBodyAnim::UBANIM_BINOC_RaiseBn:
		case EUpperBodyAnim::UBANIM_BINOC_LowerZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_BINOC_Ready;
			return;

			// Predict that if a pawn is raising to zoom it will be binocs zoom
		case EUpperBodyAnim::UBANIM_BINOC_RaiseZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			return;

			//agp:aafa [mwd] javelin animation code
			// Predict that if a pawn is raising the Javelin it will be Ready RPG
		case EUpperBodyAnim::UBANIM_Jav_RaiseJav:
		case EUpperBodyAnim::UBANIM_Jav_LowerZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_Jav_Ready;
			return;

			//agp:aafa [mwd] javelin animation code
			// Predict that if a pawn is raising to zoom it will be binocs zoom
		case EUpperBodyAnim::UBANIM_Jav_RaiseZoom:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_Jav_ReadyZoom;
			return;

			// Predict that if a pawn is raising the RPG it will be Ready RPG
		case EUpperBodyAnim::UBANIM_RPG_RaiseRPG:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_RPG_Ready;
			return;

			// Predict that if a pawn is raising the non swapping RPG it will be Ready RPG non swapping
		case EUpperBodyAnim::UBANIM_RPG_RaiseRPG_NS:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_RPG_Ready_NS;
			return;

			// Predict that if a pawn is raising the AT4 it will be Ready AT4
		case EUpperBodyAnim::UBANIM_AT4_RaiseAT4:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_AT4_Ready;
			return;

			// Predict that if a pawn is raising the BDM it will be Ready BDM but uses the AT4 ready.
		case EUpperBodyAnim::UBANIM_BDM_RaiseBDM:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_AT4_Ready;
			return;

			// Predict that if a pawn is raising a weapon it will be a pistol
		case EUpperBodyAnim::UBANIM_PISTOL_Raise:
			UpperBodyAnim = EUpperBodyAnim::UBANIM_PISTOL_Ready;
			return;
	}

}
void AAGP_Pawn::PlayRolling(EFullBodyAnim Anim)
{
	/*
	EnableChannelNotify(13,1);
	AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
	bTransitionAnim=true;
	if (Weapon != nullptr)
	{
		Weapon->TempLowerWeapon();
	}
	if (FullBodyAnim == 2)
	{
		if (UpperBodyAnim == 2)
		{
			PlayAnim('RollLtLg',1.3,0,13);
		}
		else
		{
			if (UpperBodyAnim == 39)
			{
				PlayAnim('RollLtSm',1.3,0,13);
			}
			else
			{
				PlayAnim('RollLtGn',1.3,0,13);
			}
		}
	}
	else
	{
		if (UpperBodyAnim == 2)
		{
			PlayAnim('RollRtLg',1.3,0,13);
		}
		else
		{
			if (UpperBodyAnim == 39)
			{
				PlayAnim('RollRtSm',1.3,0,13);
			}
			else
			{
				PlayAnim('RollRtGn',1.3,0,13);
			}
		}
	}
	*/
}
void AAGP_Pawn::PlayProningSound()
{
}
void AAGP_Pawn::StartSprint()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"SPRINTMODE,True");
	}
	if (Weapon != nullptr)
	{
		if (Weapon.IsInState('BusyChangingFireMode'))
		{
			if (Cast<AHumanController>(Controller) != nullptr)
			{
				Cast<AHumanController>(Controller).ClientMessage("You are too busy adjusting your weapon to sprint.");
			}
			return;
		}
		Weapon.TempLowerWeapon();
	}
	SetWalking(false);
	bIsSprinting=true;
	ResetLean();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Start Sprint");
	}
	*/
}
void AAGP_Pawn::StopSprint()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"SPRINTMODE,False");
	}
	bIsSprinting=false;
	bWantsToSprint=false;
	SetWalking(bIsWalking);
	if (Weapon != nullptr && Physics != 11 && ! IsInState('BusyProning'))
	{
		Cast<AAGP_Weapon>(Weapon).ForceTempRaiseWeapon();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Stop Sprint");
	}
	*/
}

void AAGP_Pawn::ResetLean()
{
	uint8 LastDir = 0;
	/*
	LastDir=LeanDirection;
	LeanDirection=1;
	if (IsHumanControlled())
	{
		Cast<AHumanController>(Controller).bLeanRight=0;
		Cast<AHumanController>(Controller).bLeanLeft=0;
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
void AAGP_Pawn::LeanLeft(bool bFullLeft)
{
	/*
	int32 LastDir;
	LastDir=LeanDirection;
	if (bFullLeft)
	{
		LeanDirection=0;
	}
	else
	{
		LeanDirection=Max(LeanDirection + -1,0);
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
void AAGP_Pawn::LeanRight(bool bFullRight)
{
	/*
	int32 LastDir;
	LastDir=LeanDirection;
	if (bFullRight)
	{
		LeanDirection=2;
	}
	else
	{
		LeanDirection=Min(LeanDirection + 1,2);
	}
	if (GetNetMode() == ENetMode::NM_Client && LeanDirection != LastDir)
	{
		ServerLean(LeanDirection);
	}
	*/
}
bool AAGP_Pawn::CanLean()
{
	if (bIsDead || bLockMovement || bTransitionAnim || bIsProne || IsSupported() || Weapon != nullptr && !Cast<AWeapon>(Weapon)->CanLean())
	{
		return false;
	}
	return true;
}
bool AAGP_Pawn::CanLeanInAnimationState()
{
	return false;
}
bool AAGP_Pawn::CanHandSignal()
{
	/*
	if (IsBusy() || bIsProne || IsInState('Dying') || bIsDead || Weapon != nullptr && Weapon.IsBusy())
	{
		return false;
	}
	*/
	return true;
}

bool AAGP_Pawn::CanCommo()
{
	/*
	if (IsInState('Dying'))
	{
		return false;
	}
	*/
	return true;
}

bool AAGP_Pawn::CanJump()
{
	/*
	if (IsSupported() && Weapon.IsBusy() || bLockMovement && ! IsSupported() || bUsingObjective || UpperBodyAnim == 11 || UpperBodyAnim == 5 || UpperBodyAnim == 24 || UpperBodyAnim == 28 || UpperBodyAnim == 32 || UpperBodyAnim == 36 || UpperBodyAnim == 38 || UpperBodyAnim == 66 || UpperBodyAnim == 73 || FullBodyAnim != 0)
	{
		return false;
	}
	return Super::CanJump();
	*/
	return false;    //FAKE   /EliZ
}

bool AAGP_Pawn::CanSprint()
{
	/*
	if (! fInitialAnimationComplete && Weapon != nullptr)
	{
		ClientMessage("You cannot sprint while readying your weapon.");
		DebugLog(DEBUG_Inv,"AGP_Pawn::CanSprint() - initial animation not complete");
		return false;
	}
	DebugLog(DEBUG_Inv,"Can Sprint Pawn.IsBusy: " + IsBusy() + ", Weapon CAn Sprint: " + Weapon.CanSprint() + " Weapon state: " + Weapon.GetStateName());
	return fInitialAnimationComplete || Weapon == nullptr && ! IsBusy() && Weapon == nullptr || Weapon.CanSprint();
	*/
	return false;    //FAKE   /EliZ
}

bool AAGP_Pawn::DoJump(bool bUpdating)
{
	float fSlowDown = 0;
	/*
	if (! bIsCrouched && ! bWantsToCrouch && ! bIsProne && ! bWantsToProne && Physics == 1 || Physics == 11 && fHopTimer > 0)
	{
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Level.Game != nullptr && Level.Game.GameDifficulty > 0)
			{
				MakeNoise(0.1 * Level.Game.GameDifficulty);
			}
			if (bCountJumps && Inventory != nullptr)
			{
				Inventory.OwnerEvent('Jumped');
			}
		}
		if (Physics == 11)
		{
			Velocity.Z=0;
		}
		else
		{
			if (bIsWalking)
			{
				Velocity.Z=Default.JumpZ;
			}
			else
			{
				Velocity.Z=JumpZ;
			}
		}
		if (Base != nullptr && ! Base.bWorldGeometry)
		{
			Velocity.Z += Base.Velocity.Z;
		}
		fSlowDown=fHopTimer / 3;
		fSlowDown=FClamp(fSlowDown,0,1);
		fHopTimer -= 2;
		switch(GetHealthCondition())
		{
			case 2:
			fSlowDown *= 0.6;
			break;
			case 1:
			fSlowDown *= 0.8;
			break;
			default:
			fSlowDown *= 1;
			break;
		}
		Velocity.X *= fSlowDown;
		Velocity.Y *= fSlowDown;
		if (fSlowDown < 0.4)
		{
			Velocity.Z *= 0.75;
		}
		SetPhysics(2);
		CombatEffectivenessEvent(5);
		return true;
	}
	*/
	return false;
}

bool AAGP_Pawn::CanChangePosture(bool bForce, bool bForceUnzoom)
{
	/*
	EnableChannelNotify(13,1);
	if (Cast<AHumanController>(Controller) != nullptr && Cast<AHumanController>(Controller)->GameReplicationInfo.iDelayedStartTimeRemaining > 0)
	{
		return false;
	}
	if (! bForce)
	{
		if (Physics == 2 || FullBodyAnim != 0 || bLockMovement && ! IsSupported() || IsSupported() && Weapon.IsBusy())
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
			{
				DebugLog(DEBUG_Anim,"Can't change posture - Physics" @ Physics @ "FullBodyAnim" @ FullBodyAnim @ "Lock/Support" @ bLockMovement @ IsSupported());
			}
			return false;
		}
	}
	*/

	if (Weapon != nullptr)
	{
		if (IsSupported())
		{
			SetSupported(false,true);
		}
		else
		{
			if (bForceUnzoom)
			{
				Weapon->ForceUnzoom(false);
			}
		}
		Weapon->StopCrawling();
	}
	return true;
}
bool AAGP_Pawn::CanCombatRoll(bool bActual)
{
	/*
	if (! bIsProne || Physics == 2 || FullBodyAnim != 0 || bLockMovement || IsSupported() || IsInState('BusyDrawingBack') || ! _InvAltShoulder.isEmpty() || Weapon != nullptr && ! Weapon.CanCombatRoll(bActual))
	{
		return false;
	}
	return true;
	*/
	return true;      //FAKE  /ELiZ
}
void AAGP_Pawn::ShouldStand(bool bForce)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"Stand");
	}
	if (bIsProne)
	{
		if (! CanChangePosture(bForce,True))
		{
			return;
		}
	}
	else
	{
		if (! CanChangePosture(bForce))
		{
			return;
		}
	}
	bWantsToCrouch=false;
	bWantsToProne=false;
	*/
}
void AAGP_Pawn::ShouldCrouch(bool Crouch)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"ShouldCrouch" @ Crouch);
	}
	*/

	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1Y += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2Y += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3Y += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1Y += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2Y += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3Y += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1Y += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2Y += 2.5;
										}
										else
										{
											s3boneangle3Y += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1Y -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2Y -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3Y -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1Y -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2Y -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3Y -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1Y -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2Y -= 2.5;
										}
										else
										{
											s3boneangle3Y -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
	if (bIsProne)
	{
		if (! CanChangePosture(false,true))
		{
			return;
		}
	}
	else
	{
		if (! CanChangePosture(false, false))
		{
			return;
		}
	}
	ShouldCrouch(Crouch);
	if (Crouch)
	{
		bWantsToProne=false;
	}
}
void AAGP_Pawn::EndCrouch(float HeightAdjust)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"CROUCHMODE,False");
	}
	EndCrouch(HeightAdjust);
	OldZ += HeightAdjust;
	bCrawler=Default.bCrawler;
	ShouldStand(true);
	if (FrontAuxCyl != nullptr)
	{
		FrontAuxCyl.SetAuxCylinder(false);
	}
	if (BackAuxCyl != nullptr)
	{
		BackAuxCyl.SetAuxCylinder(false);
	}
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	*/
}
void AAGP_Pawn::StartCrouch(float HeightAdjust)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"CROUCHMODE,True");
	}
	EyeHeight += HeightAdjust;
	OldZ -= HeightAdjust;
	BaseEyeHeight=CrouchEyeHeight;
	bCrawler=Default.bCrawler;
	if (FrontAuxCyl != nullptr)
	{
		FrontAuxCyl.SetAuxCylinder(false);
	}
	if (BackAuxCyl != nullptr)
	{
		BackAuxCyl.SetAuxCylinder(false);
	}
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	if (bIsProne)
	{
		bInProneTransition=true;
	}
	*/
}
void AAGP_Pawn::ShouldProne(bool Prone)
{
	/*
	if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		DebugLog(DEBUG_Anim,"ShouldProne" @ Prone);
	}
	*/

	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1P += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2P += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3P += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1P += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2P += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3P += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1P += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2P += 2.5;
										}
										else
										{
											s3boneangle3P += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1P -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2P -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3P -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1P -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2P -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3P -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1P -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2P -= 2.5;
										}
										else
										{
											s3boneangle3P -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
	if (! CanChangePosture(false,true))
	{
		return;
	}
	bWantsToProne=Prone;
	if (Prone)
	{
		bWantsToCrouch=false;
	}
}

void AAGP_Pawn::EndProne(float HeightAdjust)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"PRONEMODE,False");
	}
	EyeHeight -= HeightAdjust;
	OldZ += HeightAdjust;
	BaseEyeHeight=Default.BaseEyeHeight;
	bCrawler=Default.bCrawler;
	if (FrontAuxCyl != nullptr)
	{
		FrontAuxCyl.SetAuxCylinder(false);
	}
	if (BackAuxCyl != nullptr)
	{
		BackAuxCyl.SetAuxCylinder(false);
	}
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	ShouldStand(true);
	bInProneTransition=true;
	*/
}

void AAGP_Pawn::HidePawn(bool bNewHidePawn)
{
	/*
	bHidePawn=bNewHidePawn;
	bHidden=bHidePawn;
	OnlyAffectPawns(bHidePawn);
	bBlockZeroExtentTraces=! bNewHidePawn;
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.bProjTarget=! bNewHidePawn;
		BoneAuxCyl.bBlockBulletTraces=! bNewHidePawn;
		BoneAuxCyl.SetCollision(! bNewHidePawn,False,false);
	}
	*/
}

void AAGP_Pawn::StartProne(float HeightAdjust)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"PRONEMODE,True");
	}
	if (bIsSprinting)
	{
		Dive3p(7);
	}
	EyeHeight += HeightAdjust;
	OldZ -= HeightAdjust;
	BaseEyeHeight=ProneEyeHeight;
	bCrawler=true;
	if (FrontAuxCyl != nullptr)
	{
		FrontAuxCyl.SetAuxCylinder(true);
	}
	if (BackAuxCyl != nullptr)
	{
		BackAuxCyl.SetAuxCylinder(true);
	}
	if (BoneAuxCyl != nullptr)
	{
		BoneAuxCyl.SetCollisionSize(ExtendedRadius,CollisionHeight * ExtendedHeightScalar);
	}
	*/
}

bool AAGP_Pawn::IsSupported()
{
	if (Weapon == nullptr)
	{
		return false;
	}
	return Cast<AWeapon>(Weapon)->IsSupported();
}

bool AAGP_Pawn::IsZoomed()
{
	if (Weapon != nullptr)
	{
		bPawnZoomed= Cast<AWeapon>(Weapon)->IsZoomed();
	}
	return bPawnZoomed;
}

void AAGP_Pawn::SetZoomed(bool bNewZoomed)
{
	bPawnZoomed=bNewZoomed;
}

void AAGP_Pawn::NPCSetWeaponZoom(bool bZoomWeapon)
{
	if (Weapon == nullptr)
	{
		return;
	}
	bPawnZoomed=bZoomWeapon;
	Cast<AAGP_Weapon>(Weapon)->DoZoom(bZoomWeapon);
	if (bZoomWeapon)
	{
		if (Weapon->IsA(AItem_Binoculars::StaticClass()))
		{
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			//PlayMoving();
		}
	}
	else
	{
		if (Weapon->IsA(AItem_Binoculars::StaticClass()))
		{
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_Ready;
			//PlayMoving();
		}
	}
}

float AAGP_Pawn::GetZoomMultiplier()
{
	if (Weapon == nullptr || ! IsZoomed())
	{
		return 1.0f;
	}
	return Cast<AWeapon>(Weapon)->GetZoomMultiplier();
}

bool AAGP_Pawn::SetSupported(bool newSupported, bool bForce)
{
	FRotator CurrentRot = FRotator(0,0,0);
	/*
	if (newSupported == IsSupported())
	{
		return newSupported;
	}
	if (newSupported && ! bForce && ! SupportablePosition())
	{
		LimitRotation(false);
		if (Weapon != nullptr)
		{
			Weapon.FailedSupported();
		}
		if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
		{
			DebugLog(DEBUG_Anim,"FAILED SUPPORTED: Not a supportable position");
		}
		return false;
	}
	if (newSupported)
	{
		ResetLean();
		rBaseRotation.Pitch=FloorRotation.Pitch;
		rBaseRotation.Yaw=Rotation.Yaw;
		rBaseRotation.Roll=0;
		rRotationLimits=Weapon.rSupportedLimit;
		CurrentRot=GetViewRotation();
		if (! RestrictRotation(CurrentRot,rBaseRotation,rRotationLimits))
		{
			if (IsHumanControlled() && Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
			{
				DebugLog(DEBUG_Anim,"FAILED SUPPORTED: Rotation Limit");
			}
			return false;
		}
	}
	CombatEffectivenessEvent(8);
	Weapon.SetSupported(newSupported);
	*/
	return true;
}

bool AAGP_Pawn::SupportablePosition()
{
	return bIsProne && !IsBusy() && Weapon != nullptr && !Cast<AWeapon>(Weapon)->IsBusy() && Cast<AWeapon>(Weapon)->bCanSupport;
}

bool AAGP_Pawn::OverRotated(FRotator Desired, FRotator Actual)
{
	return true;
}

void AAGP_Pawn::UpdateParachute(int32 Type)
{
	if (Type == 4)
	{
		bParachuteOutfit=false;
		RemoveParachuteSkins();
		//Log(Self + "." + GetStateName() + ".UpdateParachute() - Weapon now: " + Weapon);
		SwapHands();
	}
	if (Weapon != nullptr && Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		switch(Type)
		{
			case 0:
			case 3:
			case 4:
				break;
			default:
				SetWalking(true);
		}
		Cast<AWeapon>(Weapon)->NotifyNewParachuteState(Type);
	}
	else
	{
		//DebugLog(DEBUG_Warn,Self @ "AGP_Pawn::UpdateParachute()	No parachute! Weapon=" + Weapon);
	}
}

void AAGP_Pawn::FlareParachute()
{
	/*
	if (Cast<AAGP_PlayerStart>(Controller.StartSpot).bNoPLFDamage)
	{
		return;
	}
	UpdateParachute(5);
	*/
}

bool AAGP_Pawn::HasParachute()
{
	return bParachuteOutfit;
}

int32 AAGP_Pawn::CheckParachuteLandingFall()
{
	int32 Damage = 0;
	FVector View2D = FVector(0,0,0);
	FVector Vel2D = FVector(0, 0, 0);
	float ViewDotVel = 0;
	float ViewDotZ = 0;
	float VelSize2D = 0;
	/*
	if (Cast<AAGP_PlayerStart>(Controller.StartSpot).bNoPLFDamage)
	{
		return 0;
	}
	View2D= Vector(Rotation);
	Vel2D=Velocity;
	View2D.Z=0;
	Vel2D.Z=0;
	VelSize2D=VSize(Vel2D);
	View2D=Normal(View2D);
	Vel2D=Normal(Vel2D);
	if (Level.debugParachute)
	{
		ViewDotVel=View2D Dot Vel2D;
		ViewDotZ=View2D Dot FVector(0 0 1);
		if (Damage == 0)
		{
			ScreenPrint("PLF Successful: ViewDotVel = " @ ViewDotVel @ "(must be > 0.90631) - ViewDotZ =" @ ViewDotZ @ "(must be > 0.0)");
		}
		else
		{
			ScreenPrint("PLF Failed:	  ViewDotVel = " @ ViewDotVel @ "(must be > 0.90631) - ViewDotZ =" @ ViewDotZ @ "(must be > 0.0)");
		}
	}
	*/
	return Damage;
}

void AAGP_Pawn::ParachuteLanding(bool bFailed)
{
	//DebugLog(DEBUG_Anim,"AGP_PAWN::ParachuteLanding" @ bFailed);
	UpdateParachute(3);
	if (bFailed)
	{
		PLF3p(EFullBodyAnim::FBANIM_PLF_Fail);
	}
	else
	{
		PLF3p(EFullBodyAnim::FBANIM_PLF_Pass);
	}
}
void AAGP_Pawn::PlayPLF()
{
	/*
	if (_AnimationMonitor == nullptr)
	{
		EnableChannelNotify(13,1);
		AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		if (bIsDead)
		{
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
			{
				SetDeathAnim(24);
				PlayAnim('PLFDead',1,0,13);
			}
			else
			{
				SetDeathAnim(25);
				PlayAnim('PLF',1,0,13);
			}
		}
		else
		{
			if (FullBodyAnim == 6)
			{
				PlayAnim('PLF',1,0,13);
				if (IsHumanControlled() && GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					Cast<APlayerController>(Controller).DoFade(true,False,2);
				}
			}
			else
			{
				PlayAnim('PLF',1,0,13);
			}
		}
		PlaySound(sParaLanding[Rand(sParaLanding.Num())],0,1,,,,false);
		bTransitionAnim=true;
		LockMovement(true);
		Velocity=FVector(0,0,0);
		Acceleration=FVector(0,0,0);
	}
	*/
}

void AAGP_Pawn::ChangeAnimation()
{
	/*
	if (Controller != nullptr && Controller.IsInState('Manning_Turret'))
	{
		return;
	}
	if (isDead())
	{
		if (! IsInState('Dying'))
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::ChangeAnimation() Pawn should have been in state Dying! " @ this @ GetStateName());
			GotoState('Dying');
		}
		return;
	}
	if (Controller != nullptr && Controller.bControlAnimations)
	{
		return;
	}
	if (bClearSplitAnims)
	{
		ClearSplitAnims();
		PlayWaiting();
	}
	else
	{
		if (bWasWalking == bIsWalking)
		{
			PlayWaiting();
		}
	}
	PlayMoving();
	bWasCrouched=bIsCrouched;
	bWasProne=bIsProne;
	bWasWalking=bIsWalking;
	bWasSprinting=bIsSprinting;
	*/
}

void AAGP_Pawn::ClearSplitAnims()
{
	/*
	AnimBlendToAlpha(15,0,0.25);
	AnimBlendToAlpha(15 - 1,0,0.25);
	EnableChannelNotify(15,0);
	EnableChannelNotify(15 - 1,0);
	bClearSplitAnims=false;
	*/
}

void AAGP_Pawn::UpperBodyAnimComplete()
{
	if (Weapon != nullptr)
	{
		UpperBodyAnim = Cast<AAGP_Weapon>(Weapon)->GetUpperBodyReadyAnim();
	}
	else
	{
		UpperBodyAnim= EUpperBodyAnim::UBANIM_NONE_Empty;
	}
	//PlayMoving();
}

void AAGP_Pawn::FullBodyAnimComplete()
{
	FullBodyAnim = EFullBodyAnim::FBANIM_NONE;
	//PlayMoving();
}

void AAGP_Pawn::HandSignalSet(FName h_name)
{
	/*
	switch(h_name)
	{
		case 'SgnlMoveOutLg':
		if (UpperBodyAnim <= 2)
		{
			UpperBodyAnim=41;
			break;
		}
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=57;
			break;
		}
		UpperBodyAnim=49;
	}
	GOTO JL02A5;
	case 'SgnlHoldLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=42;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=58;
		}
		else
		{
			UpperBodyAnim=50;
		}
	}
	GOTO JL02A5;
	case 'SgnlTakeCoverLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=43;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=59;
		}
		else
		{
			UpperBodyAnim=51;
		}
	}
	GOTO JL02A5;
	case 'SgnlPointFwdLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=44;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=60;
		}
		else
		{
			UpperBodyAnim=52;
		}
	}
	GOTO JL02A5;
	case 'SgnlReadyLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=45;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=61;
		}
		else
		{
			UpperBodyAnim=53;
		}
	}
	GOTO JL02A5;
	case 'SgnlDoubleTimeLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=46;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=62;
		}
		else
		{
			UpperBodyAnim=54;
		}
	}
	GOTO JL02A5;
	case 'SgnlAffirmLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=47;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=63;
		}
		else
		{
			UpperBodyAnim=55;
		}
	}
	GOTO JL02A5;
	case 'SgnlNegLg':
	if (UpperBodyAnim <= 2)
	{
		UpperBodyAnim=48;
	}
	else
	{
		if (UpperBodyAnim >= 37)
		{
			UpperBodyAnim=64;
		}
		else
		{
			UpperBodyAnim=56;
		}
	}
	GOTO JL02A5;
	default:
	DebugLog(DEBUG_Warn,"AGP_Pawn::HandSignalSet()	Unknown Name " + h_name);
	if (Role > 2)
	{
		UpperBodyAnimComplete();
	}
	GOTO JL02A5;
JL02A5:

	*/
}

FName AAGP_Pawn::HandSignalGet()
{
	switch(UpperBodyAnim)
	{
		case EUpperBodyAnim::UBANIM_HAND_MoveOut:		return "SgnlMoveOutLg";
		case EUpperBodyAnim::UBANIM_HAND_Hold:			return "SgnlHoldLg";
		case EUpperBodyAnim::UBANIM_HAND_TakeCover:		return "SgnlTakeCoverLg";
		case EUpperBodyAnim::UBANIM_HAND_PointFwd:		return "SgnlPointFwdLg";
		case EUpperBodyAnim::UBANIM_HAND_Ready:			return "SgnlReadyLg";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTime:	return "SgnlDoubleTimeLg";
		case EUpperBodyAnim::UBANIM_HAND_Affirm:		return "SgnlAffirmLg";
		case EUpperBodyAnim::UBANIM_HAND_Neg:			return "SgnlNegLg";

		case EUpperBodyAnim::UBANIM_HAND_MoveOutGn:		return "SgnlMoveOutGn";
		case EUpperBodyAnim::UBANIM_HAND_HoldGn:		return "SgnlHoldGn";
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverGn:	return "SgnlTakeCoverGn";
		case EUpperBodyAnim::UBANIM_HAND_PointFwdGn:	return "SgnlPointFwdGn";
		case EUpperBodyAnim::UBANIM_HAND_ReadyGn:		return "SgnlReadyGn";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeGn:	return "SgnlDoubleTimeGn";
		case EUpperBodyAnim::UBANIM_HAND_AffirmGn:		return "SgnlAffirmGn";
		case EUpperBodyAnim::UBANIM_HAND_NegGn:			return "SgnlNegGn";

		case EUpperBodyAnim::UBANIM_HAND_MoveOutSm:		return "SgnlMoveOutSm";
		case EUpperBodyAnim::UBANIM_HAND_HoldSm:		return "SgnlHoldSm";
		case EUpperBodyAnim::UBANIM_HAND_TakeCoverSm:	return "SgnlTakeCoverSm";
		case EUpperBodyAnim::UBANIM_HAND_PointFwdSm:	return "SgnlPointFwdSm";
		case EUpperBodyAnim::UBANIM_HAND_ReadySm:		return "SgnlReadySm";
		case EUpperBodyAnim::UBANIM_HAND_DoubleTimeSm:	return "SgnlDoubleTimeSm";
		case EUpperBodyAnim::UBANIM_HAND_AffirmSm:		return "SgnlAffirmSm";
		case EUpperBodyAnim::UBANIM_HAND_NegSm:			return "SgnlNegSm";
		default:
			//DebugLog(DEBUG_Warn, "AGP_Pawn::HandSignalGet()	Unknown Index " $UpperBodyAnim);
			return "";
	}
}

void AAGP_Pawn::PlayHandSignalIndex()
{
	//PlayHandSignal(HandSignalGet());
}

void AAGP_Pawn::PlayHandSignal(FName Anim)
{
	/*
	if (! CanHandSignal())
	{
		return;
	}
	commosignalanim=Anim;
	GotoState('BusySignaling');
	*/
}

ABaseWeaponAttachment* AAGP_Pawn::GetWeaponAttachment()
{
	ABaseWeaponAttachment* BWA = nullptr;
	/*
	switch(Level.NetMode)
	{
		case 1:
		case 0:
		if (Weapon != nullptr && Weapon.ThirdPersonActor != nullptr)
		{
			return Cast<ABaseWeaponAttachment>(Weapon.ThirdPersonActor);
			break;
		}
		return nullptr;
		}
		case 3:
		ForEach AllActors('BaseWeaponAttachment',BWA)
		{
			if (BWA.Instigator == this && BWA.bCurrentlySelectedAttachment)
			{
				return BWA;
			}
		}
		default:
	}
	*/
	return nullptr;
}

void AAGP_Pawn::PlayJumping()
{
	if (angleEditor)
	{
		if (boneaxisdirection == 1)
		{
			boneaxisdirection=0;
		}
		else
		{
			boneaxisdirection=1;
		}
		return;
	}
	//GotoState('BusyJumping');
}

void AAGP_Pawn::PlayLanding()
{
	//GotoState('BusyLanding');
}

void AAGP_Pawn::PlayFiring(float Rate, FName FiringMode)
{
}

void AAGP_Pawn::ClientPlayBulletWhip(FVector HitLocation, bool bCrack, AActor* aShooter)
{
	AActor* SoundActor = nullptr;
	USoundBase* SoundPtr = nullptr;
	int32 R = 0;
	/*
	if (IsHumanControlled() && IsLocallyControlled())
	{
		if (Level.GamePlayMode == 1)
		{
			if (FastTrace(HitLocation,EyePosition()))
			{
				R=Rand(sMilesGraze.Num());
				SoundPtr=sMilesGraze[R];
			}
		}
		else
		{
			if (bCrack)
			{
				R=Rand(sBulletCrack.Num());
				SoundPtr=sBulletCrack[R];
			}
			else
			{
				R=Rand(sBulletWhip.Num());
				SoundPtr=sBulletWhip[R];
			}
		}
		if (SoundPtr != nullptr)
		{
			SoundActor=Spawn(AEffectLocation::StaticClass(),,,HitLocation);
			SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
			SoundActor.PlaySound(SoundPtr,0,1,,,,false);
		}
	}
	else
	{
		if (Controller != nullptr && Controller->IsA(AAgentController::StaticClass()))
		{
			bGotBulletBuzzed=true;
		}
		else
		{
			if (Controller != nullptr && Controller->IsA(AaAIController::StaticClass()))
			{
				Cast<AaAIController>(Controller).NotifyBuzzedByBullet(aShooter);
			}
		}
	}
	*/
}

bool AAGP_Pawn::CanUseWeapon(int32 DesiredAction)
{
	/*
	if (IsBusy() || bWantsToSprint || bIsSprinting || Weapon == nullptr || bIsDead || bUsingObjective)
	{
		return false;
	}
	if (bIsProne != bWantsToProne)
	{
		return false;
	}
	if (Controller != nullptr && Controller->IsA(AHumanController::StaticClass()))
	{
		if (Cast<AHumanController>(Controller).bAutoWalkZoom == false)
		{
			if (DesiredAction == 6 && ! FVector::IsZero(Acceleration) && ! bIsWalking)
			{
				return false;
			}
		}
	}
	if (DesiredAction == 3 && bTransitionAnim)
	{
		return false;
	}
	if (Weapon == nullptr)
	{
		return false;
	}
	return Weapon.CanUseWeapon(DesiredAction);
	*/
	return false;     //FAKE   /EliZ
}

bool AAGP_Pawn::IsBusy()
{
	return PressingAction();
}

bool AAGP_Pawn::CanMantle(float Height)
{
	if (Height > fMaxGrabHeight)
	{
		return false;
	}
	return true;
}

bool AAGP_Pawn::PressingAction()
{
	//return Controller != nullptr && Cast<AHumanController>(Controller) != nullptr && Cast<AHumanController>(Controller)->bAction != 0;
	return false;				//Not the real one /ELiZ
}

void AAGP_Pawn::AddDefaultInventory()
{
	
}

AInventory* AAGP_Pawn::CreateInventoryFromName(FString InventoryClassName, bool bIndigenous)
{
	return nullptr;   //FAKE   /ELiZ
}

AInventory* AAGP_Pawn::CreateInventory(AInventory* InventoryClass, bool bRealInventory, bool bIndigenous)
{
	return nullptr;   //FAKE   /ELiZ
}

bool AAGP_Pawn::IsValidInventory(AInventory* InventoryClass, AInventory*& out_AltClass)
{
	return false;   //FAKE   /ELiZ
}

FVector AAGP_Pawn::CalcDrawOffset(AInventory* Inv)
{
	FVector DrawOffset = FVector(0,0,0);
	FRotator Rot = FRotator(0,0,0);
	/*
	if (Controller == nullptr)
	{
		return Inv.PlayerViewOffset >> Rotation + EyePosition();
	}
	if (! Inv.bUseInstigatorRotation)
	{
		Rot=GetViewRotation();
	}
	else
	{
		Rot=Rotation;
	}
	DrawOffset=0.9 / Controller.FovAngle * 100 * ModifiedPlayerViewOffset(Inv) >> Rot;
	if (! IsLocallyControlled() || ! Inv->IsA(AWeapon::StaticClass()))
	{
		DrawOffset += EyePosition();
	}
	else
	{
		DrawOffset += EyePosition();
		DrawOffset += WeaponBob(Inv.BobDamping);
	}
	*/
	return DrawOffset;
}

void AAGP_Pawn::Reload3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim=Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	GotoState('BusyReloading');
	*/
}

void AAGP_Pawn::GuardWeapon3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim=Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	GotoState('BusyGuardingWeapon');
	*/
}

void AAGP_Pawn::Roll3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyRolling');
}
void AAGP_Pawn::Dive3p(EFullBodyAnim Anim)
{
	FullBodyAnim=Anim;
	//GotoState('BusyDiving');
}
void AAGP_Pawn::Parachute3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyParachuting');
}
void AAGP_Pawn::PLF3p(EFullBodyAnim Anim)
{
	FullBodyAnim = Anim;
	//GotoState('BusyPLF');
}
void AAGP_Pawn::GrenadeThrow3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim = Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	if (UpperBodyAnim == 12)
	{
		GotoState('BusyDrawing');
		if (Weapon != nullptr)
		{
			Weapon.AttachToPawn(this);
		}
		AnimateGrenadeMoving();
	}
	else
	{
		if (UpperBodyAnim == 9)
		{
			GotoState('BusyPullingPinGrenade');
		}
		else
		{
			if (UpperBodyAnim == 13 || UpperBodyAnim == 14)
			{
				GotoState('BusyDeployingBreacherUS');
			}
			else
			{
				if (UpperBodyAnim == 15 || UpperBodyAnim == 16)
				{
					GotoState('BusyDeployingBreacherOPFOR');
				}
				else
				{
					if (Weapon != nullptr)
					{
						if (Weapon->IsA(AThrowWeapon::StaticClass()))
						{
							Weapon.DetachFromPawn(this,true);
						}
					}
					if (UpperBodyAnim == 7 || UpperBodyAnim == 8)
					{
						GotoState('BusyThrowingGrenade');
					}
					else
					{
						GotoState("None");
						ChangeAnimation();
					}
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::WeaponSwap3p(EUpperBodyAnim Anim)
{
	UpperBodyAnim = Anim;
	/*
	if (Role > 2 && UpperBodyAnim == 0)
	{
		DebugLog(DEBUG_Anim,"T");
		UpperBodyAnimComplete();
	}
	followmouse=false;
	switch(UpperBodyAnim)
	{
		case 66:
		case 73:
		case 5:
		case 11:
		case 20:
		case 19:
		case 24:
		case 28:
		case 32:
		case 36:
		case 38:
			GotoState('BusyDrawingBack');
			break;
		case 65:
		case 70:
		case 72:
		case 4:
		case 10:
		case 17:
		case 18:
		case 23:
		case 27:
		case 31:
		case 35:
		case 37:
			GotoState('BusyDrawing');
			break;
		default:
			DebugLog(DEBUG_Anim,"AGP_Pawn::WeaponSwap3P() Don't know what to do with UpperBodyAnim " + UpperBodyAnim);
			break;
	}
	*/
}
void AAGP_Pawn::SkipWeaponAdjustment(EUpperBodyAnim Anim)
{
	switch(Anim)
	{
		case EUpperBodyAnim::UBANIM_BINOC_LowerZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_Ready;
			break;
		case EUpperBodyAnim::UBANIM_BINOC_RaiseZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_BINOC_ReadyZoom;
			break;
		case EUpperBodyAnim::UBANIM_Jav_LowerZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_Jav_Ready;
			break;
		case EUpperBodyAnim::UBANIM_Jav_RaiseZoom:
			UpperBodyAnim= EUpperBodyAnim::UBANIM_Jav_ReadyZoom;
			break;
		default:
			//DebugLog(DEBUG_Warn,"AGP_Pawn::BusyPostureChange::WeaponAdjust3p()	Unexpected Anim " + Anim);
			break;
	}
	ChangeAnimation();
}
void AAGP_Pawn::WeaponAdjust3p(EUpperBodyAnim Anim)
{
	/*
	int32 i = 0;
	for (i=4; i<8; i++)
	{
		if (IsAnimating(i))
		{
			DebugLog(DEBUG_Anim,"AGP_Pawn::WeaponAdjust3p()	Not playing adjustment animation while animating a movement ");
			SkipWeaponAdjustment(Anim);
			return;
		}
	}
	UpperBodyAnim=Anim;
	if (Role > 2 && UpperBodyAnim == 0)
	{
		UpperBodyAnimComplete();
	}
	followmouse=false;
	PlayWeaponAdjustAnim();
	*/
}
void AAGP_Pawn::PlayWeaponAdjustAnim()
{
	/*
	if (_AnimationMonitor == nullptr)
	{
		EnableChannelNotify(15,1);
		if (bIsProne)
		{
			AnimBlendParams(15,1,0,0,'spine01');
		}
		else
		{
			AnimBlendParams(15,1,0,0,'Spine02');
		}
		switch(UpperBodyAnim)
		{
			case 18:
			if (bIsProne)
			{
				PlayAnim('PrnBinocsUp',2.2,0.25,15);
				break;
			}
			if (bIsCrouched)
			{
				PlayAnim('CrhBinocsUp',2.2,0.25,15);
				break;
			}
			PlayAnim('StdBinocsUp',2.2,0.25,15);
		}
		case 19:
		if (bIsProne)
		{
			PlayAnim('PrnBinocsDn',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhBinocsDn',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdBinocsDn',2.2,0.25,15);
			}
		}
		case 70:
		if (bIsProne)
		{
			PlayAnim('PrnCLUUp',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhCluUp',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdCluUp',2.2,0.25,15);
			}
		}
		case 71:
		if (bIsProne)
		{
			PlayAnim('PrnCLUDwn',2.2,0.25,15);
		}
		else
		{
			if (bIsCrouched)
			{
				PlayAnim('CrhCluDwn',2.2,0.25,15);
			}
			else
			{
				PlayAnim('StdCluDwn',2.2,0.25,15);
			}
		}
		default:
		DebugLog(DEBUG_Warn,"AGP_Pawn::BusyAdjustingWeapon::BeginState()	Don't know what to do here!");
		bClearSplitAnims=true;
	}
	*/
}
void AAGP_Pawn::ClientWeaponActionFailed()
{
	/*
	DebugLog(DEBUG_Warn,"AGP_Pawn::ClientWeaponActionFailed() Will interrupt if possible: " + GetStateName() @ Weapon.GetStateName());
	if (IsInState('BusyReloading'))
	{
		if (Weapon != nullptr && Weapon->IsA(AWEAPON_Javelin::StaticClass()))
		{
			if (Weapon.CheckJavelinTube())
			{
				Weapon.SetbTubeAttached(false);
				bCanProne=true;
			}
			else
			{
				Weapon.SetbTubeAttached(true);
				bCanProne=false;
			}
		}
		ChangeAnimation();
	}
	if (Weapon == nullptr)
	{
		return;
	}
	if (Weapon.IsInState('BusyReloading'))
	{
		DebugLog(DEBUG_Anim,"AGP_Pawn::ClientWeaponActionFailed() Sending weapon to Idle state");
		Weapon.GotoState('Idle');
	}
	*/
}
void AAGP_Pawn::DoReload()
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		//GotoState('BusyReloading');
		Cast<AWeapon>(Weapon)->Reload();
		Cast<AWeapon>(Weapon)->ReloadClip(Cast<AWeapon>(Weapon)->GetBestClip());
		//ClientDoReload(Weapon->GetCurrentAmmoType()->AmmoAmount);
		return;
	}
	ServerReload();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		//GotoState('BusyReloading');
		Cast<AWeapon>(Weapon)->Reload();
	}
}
void AAGP_Pawn::ClientDoReload(int32 iAmmoAmount)
{
	/*
	if (IsInState('BusyReloading'))
	{
		Weapon.Reload();
		GotoState('BusyReloading');
	}
	if (Weapon->IsA(AWeapon_M24_Sniper::StaticClass()))
	{
		GOTO JL0056;
	}
	Weapon.GetCurrentAmmoType().AmmoAmount=iAmmoAmount;
JL0056:
	*/
}
void AAGP_Pawn::ServerReload()
{
	/*
	if (Controller == nullptr)
	{
		return;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && ! PlayerController(Controller).CanUseWeapon(3))
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::ServerReload()	Client requested a reload but server was unable to comply");
		ClientWeaponActionFailed();
		return;
	}
	if (Weapon == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::ServerReload() - No Weapon");
		ClientWeaponActionFailed();
		return;
	}
	GotoState('BusyReloading');
	Weapon.Reload();
	Weapon.ReloadClip(Weapon.GetBestClip());
	ClientDoReload(Weapon.GetCurrentAmmoType().AmmoAmount);
	NPCAlertPlayerEvent();
	*/

	if (angleEditor)
	{
		if (boneaxisdirection == 0)
		{
			if (boneaxis == 0)
			{
				s1boneangle1R += 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2R += 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3R += 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1R += 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2R += 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3R += 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1R += 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2R += 2.5;
										}
										else
										{
											s3boneangle3R += 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else
		{
			if (boneaxis == 0)
			{
				s1boneangle1R -= 2.5;
			}
			else
			{
				if (boneaxis == 1)
				{
					s1boneangle2R -= 2.5;
				}
				else
				{
					if (boneaxis == 2)
					{
						s1boneangle3R -= 2.5;
					}
					else
					{
						if (boneaxis == 3)
						{
							s2boneangle1R -= 2.5;
						}
						else
						{
							if (boneaxis == 4)
							{
								s2boneangle2R -= 2.5;
							}
							else
							{
								if (boneaxis == 5)
								{
									s2boneangle3R -= 2.5;
								}
								else
								{
									if (boneaxis == 6)
									{
										s3boneangle1R -= 2.5;
									}
									else
									{
										if (boneaxis == 7)
										{
											s3boneangle2R -= 2.5;
										}
										else
										{
											s3boneangle3R -= 2.5;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return;
	}
}

void AAGP_Pawn::ClientReload()
{
	Cast<AWeapon>(Weapon)->Reload();
	//GotoState('BusyReloading');
}

AAmmunition* AAGP_Pawn::ReloadWithThisClip(AAmmunition* newclip)
{
	AAmmunition* oldclip = nullptr;
	if (newclip != nullptr)
	{
		if (Weapon != nullptr)
		{
			/*
			if (Cast<AAGP_Weapon>(Weapon).IsInState('GunReloading'))
			{
				return nullptr;
			}
			oldclip=Weapon.GetCurrentAmmoType();
			Cast<AAGP_Weapon>(Weapon).Reload();
			Weapon.SetCurrentAmmoType(newclip);
			*/
		}
	}
	return oldclip;
}

void AAGP_Pawn::DropSpecificItem(AInventory* Item)
{
	APickup* Pickup = nullptr;
	if (Item == nullptr)
	{
		return;
	}
	/*
	if (Item->IsA(AWeapon::StaticClass()))
	{
		Item.DropFrom(Self.Location + 72 *  Vector(Rotation) + FVector(0 0 1) * 15);
		return;
	}
	Pickup=Spawn(Item.PickupClass,,"None",Self.Location + 72 *  Vector(Rotation) + FVector(0 0 1) * 15);
	if (Pickup == nullptr)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			ScreenPrint("InvContainer:dropCurrentItem failed fabrication.");
		}
	}
	if (Pickup->IsA(AAmmo::StaticClass()))
	{
		Cast<AAmmo>(Pickup).AmmoAmount=Cast<AAmmunition>(Item).AmmoAmount;
	}
	*/
}

void AAGP_Pawn::DropSpecificItemBehind(AInventory* Item)
{
	APickup* Pickup = nullptr;
	if (Item == nullptr)
	{
		return;
	}
	if (Item->IsA(AWeapon::StaticClass()))
	{
		//Item->DropFrom(Self.Location + 72 *  Vector(Rotation) + FVector(0,0,1) * 15);
		return;
	}
	//Pickup=Spawn(Item.PickupClass,,"None",Self.Location - 72 *  Vector(Rotation) + FVector(0 0 1) * 15);
	if (Pickup == nullptr)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			//ScreenPrint("InvContainer:dropCurrentItem failed fabrication.");
		}
	}
	if (Pickup->IsA(AAmmo::StaticClass()))
	{
		Cast<AAmmo>(Pickup)->AmmoAmount=Cast<AAmmunition>(Item)->AmmoAmount;
	}
}

void AAGP_Pawn::EmptyInventory(bool bDropObjectives)
{
	AInvContainer* invCon;
	int32 i = 0;
	//Controller->CleanUp();
	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		EmptyContainer(invCon, bDropObjectives);
	}
	if (_OpticsDevice != nullptr)
	{
		_OpticsDevice->Destroy();
		_OpticsDevice= nullptr;
	}
	
	for (i=0; i<7; i++)
	{
		_InvGrenades[i]=0;
	}
}

void AAGP_Pawn::EmptyContainer(AInvContainer* container,bool bDropObjectives)
{
	AInventory* Item = nullptr;
	/*
	if (!(container->isEmpty()))
	{
		Item=container->getFirstItem();
		if (bDropObjectives && Item->IsA(AAGP_ObjectiveInventory::StaticClass()))
		{
			DropUtilityInventory();
		}
		else
		{
			if (container.DeleteItem(Item))
			{
				Item.Destroy();
			}
			else
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
				{
					DebugLog(DEBUG_Inv,"ERROR - AGP_Pawn::EmptyContainer " + container.thename + " could not delete " + Item.Name);
				}
			}
		}
		else
		{
		}
	}
	RecalcInvWeight();
	*/
}

void AAGP_Pawn::NextItem()
{
	UE_LOG(LogTemp, Log, TEXT("AGP_Pawn::NextItem called.  No-op."));
}

AInventory* AAGP_Pawn::FindInventoryType(AInventory* DesiredClass)
{
	AInvContainer* invCon = nullptr;
	AInventory* InvItem = nullptr;
	InvItem=nullptr;

	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		//InvItem = invCon->FindInventoryType(DesiredClass);
		if (InvItem != nullptr)
		{
			return InvItem;
		}
	}
	return nullptr;
}

int32 AAGP_Pawn::CountInventoryType(AInventory* DesiredClass)
{
	AInvContainer* invCon = nullptr;
	int32 Count = 0;
	uint8 Index = 0;
	/*
	if (DesiredClass == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType() received null desired class.");
		return -1;
	}
	if (ClassIsChildOf(DesiredClass,'ThrowWeapon'))
	{
		Index=class<ThrowWeapon>(DesiredClass).Default.InvGrenadeIndex;
		if (Index < 7)
		{
			return _InvGrenades[Index];
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType()	Unknown ThrowWeapon " + DesiredClass);
			return -1;
		}
	}
	if (Role != 4)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::CountInventoryType()	No client side functionality!");
		return -1;
	}
	*/
	Count = 0;
	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		//Count += invCon->CountInventoryType(DesiredClass);
	}
	return Count;
}

bool AAGP_Pawn::AddInventory(TSubclassOf<AInventory> NewItem)
{
	TSubclassOf<AInventory> actor = NewItem;
	if (actor != nullptr)
	{
		UWorld* myWorld = GetWorld();
		AActor* myActor = myWorld->SpawnActor(actor);
		//My_Pawn_Inventory.Add(myActor);
		//My_Pawn_Inventory.Add(actor);
	}
	return false;

	//AInventory* Inv;
	TSubclassOf<AInvContainer> holder;

	//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	//{
	//	DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory adding " @ NewItem.GetHumanReadableName());
	//}

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	Class Name:%s"), *NewItem->GetName()), false);

	if (NewItem == nullptr)
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::AddInventory()	Received NULL item");
		return false;
	}

	/*
	//Therse Works:
	if (NewItem->GetName() == FString("Throw_M67_Frag"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(1)  Name=Throw_M67_Frag")), false);
		//return false;
	}
	
	if (NewItem->IsChildOf(AWeapon::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(2) Is a Child of Weapon")), false);
		//return false;
	}
	if (NewItem->IsChildOf(AInventory::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(3) Is a Child of Inventory")), false);
		//return false;
	}
	if (NewItem->IsChildOf(AThrow_M67_Frag::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 25.0f, FColor::Green, FString::Printf(TEXT("AGP_Pawn::AddInventory()	(4) Is a Child of Throw_M67_Frag")), false);
		//return false;
	}
	*/
	
	if (NewItem->IsChildOf(AInvContainer::StaticClass()))
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::AddInventory()	Can't add containers here");
		return false;
	}
	
	if (NewItem->IsChildOf(AItem_Parachute::StaticClass()))
	{
		/*
		Inv=_InvHands->getFirstItem();
		if (Inv == nullptr)
		{
			//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			//{
			//	ScreenPrint("Hands are empty. Adding parachute.");
			//}
			_InvHands->addItem(NewItem);
			NewItem->SetOwner(this);
			NewItem->SetInstigator(this);
			ChangeInventoryWeight(NewItem->fWeight);
			Weapon = Cast<AWeapon>(NewItem);
			if (Controller != nullptr)
			{
			//	Controller.NotifyAddInventory(NewItem);
			}
			NewItem->AttachToPawn(this);
			return true;
		}
		else
		{
			//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
			//{
			//	ScreenPrint("Hands are not empty.  Moving Weapon to shoulder.");
			//}
			if (_InvHands->DeleteItem(Inv))
			{
				if (_InvShoulder->addItem(Inv))
				{
					_InvHands->addItem(NewItem);
					NewItem->SetOwner(this);
					NewItem->SetInstigator(this);
					ChangeInventoryWeight(NewItem->fWeight);
					Weapon = Cast<AWeapon>(NewItem);
					if (Controller != nullptr)
					{
						//Controller.NotifyAddInventory(NewItem);
					}
					NewItem->AttachToPawn(this);
					Inv->AttachToPawn(this);
					//Inv->SetRelativeLocation(GetDefault<AInventory>()->RelativeLocation);
					//Inv->SetRelativeRotation(GetDefault<AInventory>()->RelativeRotation);

					UpperBodyAnimComplete();
					return true;
				}
			}
		}
		*/
		return false;
	}
	/*
	if (NewItem->IsChildOf(ADummyItem::StaticClass()))
	{
		//NewItem->AttachToPawn(this);
		//return true;
	}
	holder=NULL;
	//holder=Cast<AInvContainer>(this->FindInventoryItem(NewItem));
	if (holder != nullptr)
	{
		//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		//{
		//	DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory tried to add item that it already owns.");
		//}
		return false;
	}
	
	holder=FindInventorySpace(NewItem);
	if (holder == nullptr)
	{
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory can't find any space for " @ NewItem.GetHumanReadableName());
		if (! NewItem->IsA(ADummyItem::StaticClass()))
		{
			DropSpecificItemBehind(NewItem);
		}
		return false;
	}
	if (holder->addItem(NewItem))
	{
		ChangeInventoryWeight(NewItem->fWeight);
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory added " @ NewItem.GetHumanReadableName() @ " to " @ holder.thename);
		NewItem->SetOwner(this);
		NewItem->SetInstigator(this);
		if (Controller != nullptr)
		{
			//Controller->NotifyAddInventory(NewItem);
		}
		if (NewItem->IsA(AWeapon::StaticClass()))
		{
			if (NewItem == getHandsInventory())
			{
				PendingWeapon = Cast<AWeapon>(NewItem);
				ChangedWeapon();
			}
			NewItem->AttachToPawn(this);
		}
		if (NewItem->IsA(AItem_Bullseye::StaticClass()))
		{
			NewItem->AttachToPawn(this);
		}
		return true;
	}
	else
	{
		//DebugLog(DEBUG_Inv,"AGP_Pawn::AddInventory() Failed to add item: " + NewItem);
	}
	DropSpecificItemBehind(NewItem);
	*/
	return false;
}

void AAGP_Pawn::DeleteInventory(AInventory* Item)
{
	AInvContainer* holder = nullptr;
	//holder=this->FindInventoryItem(Item);
	//DebugLog(DEBUG_Inv,"AGP_Pawn::DeleteInventory() " + Item @ holder);
	if (holder != nullptr)
	{
		//holder->DeleteItem(Item);
		Item->SetOwner(nullptr);
		ChangeInventoryWeight(-(Item->fWeight));
	}
}

void AAGP_Pawn::ChangedWeapon()
{
	AWeapon* OldWeapon = nullptr;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	/*
	DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() " + Weapon @ PendingWeapon);
	if (Weapon != nullptr && Weapon.Owner == nullptr)
	{
		Weapon.SetOwner(this);
	}
	OldWeapon=Weapon;
	if (PendingWeapon == nullptr && Weapon == nullptr)
	{
		return;
	}
	if (Weapon == PendingWeapon)
	{
		if (Weapon.IsInState('BusyLoweringWeapon'))
		{
			Weapon.GotoState('Idle');
		}
		PendingWeapon=nullptr;
		DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() Place 1 " + OldWeapon @ Weapon);
		ServerChangedWeapon(OldWeapon,Weapon);
		return;
	}
	Weapon=PendingWeapon;
	if (Weapon != nullptr)
	{
		Weapon.Instigator=Self;
		Weapon.BringUp();
	}
	PendingWeapon=nullptr;
	DebugLog(DEBUG_Inv,"AGP_Pawn::ChangedWeapon() Place 2 " + OldWeapon @ Weapon);
	ServerChangedWeapon(OldWeapon,Weapon);
	if (Controller != nullptr)
	{
		Controller.ChangedWeapon();
	}
	*/
}

void AAGP_Pawn::ServerChangedWeapon(AWeapon* OldWeapon, AWeapon* W)
{
	/*
	DebugLog(DEBUG_Inv,"AGP_Pawn::ServerChangedWeapon() " + OldWeapon @ W);
	Weapon=W;
	bSwapWhenLanded=false;
	if (Weapon == nullptr)
	{
		if (Controller != nullptr && Controller->IsA(AHumanController::StaticClass()))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::ServerChangedWeapon()	" + Weapon @ Cast<AHumanController>(Controller)->bAutoSwapFromGrenade @ Physics);
			if (OldWeapon->IsA(AThrowWeapon::StaticClass()) && Cast<AHumanController>(Controller)->bAutoSwapFromGrenade)
			{
				switch(Physics)
				{
					case 1:
					SwapHands();
					break;
					case 2:
					bSwapWhenLanded=true;
					break;
					default:
					DebugLog(DEBUG_Warn,"AGP_Pawn::ServerChangedWeapon()	Unable to auto-swap for Physics state " + Physics);
				}
			}
		}
		return;
	}
	Weapon.AttachToPawn(this);
	Weapon.SetRelativeLocation(Weapon.Default.RelativeLocation);
	Weapon.SetRelativeRotation(Weapon.Default.RelativeRotation);
	if (OldWeapon == Weapon)
	{
		if (Weapon.IsInState('BusyLoweringWeapon'))
		{
			Weapon.BringUp();
		}
		return;
	}
	else
	{
		if (Level.Game != nullptr)
		{
			MakeNoise(0.1 * Level.Game.GameDifficulty);
		}
	}
	W.RecountAmmo();
	PlayWeaponswitch(W);
	Weapon.BringUp();
	if (Cast<AAGP_Weapon>(Weapon).fpWeaponThreatLevel > fpPlayerThreatLevel)
	{
		fpPlayerThreatLevel=Cast<AAGP_Weapon>(Weapon).fpWeaponThreatLevel;
	}
	*/
}

void AAGP_Pawn::WeaponChanged()
{
	if (Weapon != nullptr)
	{
		if (CommoState == ECommoType::COMMOTYPE_Hand && !(CommoCanHandSignal()))
		{
			CommoCycleState();
		}
		Weapon->OwnerRecieved();
	}
}

FName AAGP_Pawn::GetWeaponBoneFor(TSubclassOf<AInventory> i)
{
	return "WeaponBone";
}

AInvContainer* AAGP_Pawn::FindInventoryItem(TSubclassOf<AInventory> p_item)
{
	AInvContainer* invCon;

	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		if (invCon->FindInventoryItem(p_item))
		{
			return invCon;
		}
	}
	return nullptr;
}

AInvContainer* AAGP_Pawn::FindInventorySpace(TSubclassOf<AInventory> p_item)
{
	/*
	AInvContainer* IC;
	if (p_item == nullptr)
	{
		return nullptr;
	}
	if (p_item->IsA(AItem_Bullseye::StaticClass()))
	{
		return _InvUtility;
	}
	if (Cast<AInventory>(p_item)->VirtualWeapon() || Cast<AInventory>(p_item)->isHandsOnly())
	{
		if (_InvHands != nullptr && _InvHands->FindInventorySpace(p_item))
		{
			return _InvHands;
		}
		else
		{
			return nullptr;
		}
	}
	Cast<AInventory>(p_item)->SetInstigator(this);
	if (_InvHands->FindInventorySpace(p_item))
	{
		return _InvHands;
	}
	else
	{
		IC= Cast<AInventory>(p_item)->GetSwapContainer();
		if (IC != nullptr && IC->FindInventorySpace(p_item))
		{
			return IC;
		}
	}
	*/
	return nullptr;
}

TSubclassOf<AInventory> AAGP_Pawn::getShoulderInventory()
{
	if (_InvShoulder != nullptr)
	{
		return _InvShoulder->getCurrentItem();
	}
	return nullptr;
}

TSubclassOf<AInventory> AAGP_Pawn::getHandsInventory()
{
	if (_InvHands != nullptr)
	{
		return _InvHands->getCurrentItem();
	}
	return nullptr;
}

TSubclassOf<AInventory> AAGP_Pawn::getHolsterInventory()
{
	if (_InvHolster != nullptr)
	{
		return _InvHolster->getCurrentItem();
	}
	return nullptr;
}

TSubclassOf<AInventory> AAGP_Pawn::getHipInventory()
{
	if (_InvHip != nullptr)
	{
		return _InvHip->getCurrentItem();
	}
	return nullptr;
}

TSubclassOf<AInventory> AAGP_Pawn::getAltShoulderInventory()
{
	if (_InvAltShoulder != nullptr)
	{
		return _InvAltShoulder->getCurrentItem();
	}
	return nullptr;
}

void AAGP_Pawn::DiscardInventory()
{
	AInvContainer* Prev = nullptr;
	AInvContainer* Next = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::DiscardInventory() - Destroying");
	}
	Prev=_InvTop;
	if (Prev != nullptr)
	{
		Next=Prev.nextContainer;
		Prev.Destroy();
		Prev=Next;
	}
	if (_OpticsDevice != nullptr)
	{
		_OpticsDevice.Destroy();
		_OpticsDevice=nullptr;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::DiscardInventory() - Setting to None");
	}
	*/
	_InvTop=nullptr;
	_InvHands=nullptr;
	_InvShoulder=nullptr;
	_InvHolster=nullptr;
	_InvHip=nullptr;
	_InvAltShoulder=nullptr;
}
void AAGP_Pawn::KnowAll(FString S)
{
	/*
	if (Level.debugThis(18))
	{
		DebugLog(DEBUG_Inv,S + "	NextSwap  -" @ NextSwap);
		DebugLog(DEBUG_Inv,S + "	Weapon    -" @ Weapon);
		DebugLog(DEBUG_Inv,S + "	Hands     -" @ getHandsInventory());
		DebugLog(DEBUG_Inv,S + "	Shoulder  -" @ getShoulderInventory());
		DebugLog(DEBUG_Inv,S + "	Holster   -" @ getHolsterInventory());
	}
	*/
}
bool AAGP_Pawn::CanSwapHands()
{
	if (bAllowSwap)
	{
		bAllowSwap=false;
		return true;
	}
	/*
	if (! bCanSwapWeapons || IsBusy() || IsSupported() || bIsSprinting || Physics == 11 || bIsDead || Weapon != nullptr && Weapon.IsBusy() && ! Weapon.IsTempBusy() || Weapon->IsA(AItem_Parachute::StaticClass()))
	{
		return false;
	}
	*/
	return true;
}

void AAGP_Pawn::SwapHands()
{
	AInventory* handitem = nullptr;
	/*
	StopSprint();
	handitem=getHandsInventory();
	NextSwap=getShoulderInventory();
	KnowAll("AGP_Pawn::SwapHands()	");
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem->IsA(AWeapon::StaticClass()))
		{
			Cast<AWeapon>(handitem).PutDown();
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::SwapHands()	Don't know how to handle non-weapon " + handitem,true);
			NextSwap=nullptr;
		}
	}
	*/
}

void AAGP_Pawn::SwapHip()
{
	AAGP_Weapon* handitem = nullptr;
	/*
	StopSprint();
	KnowAll("AGP_Pawn::SwapHip()");
	handitem=Cast<AAGP_Weapon>(getHandsInventory());
	NextSwap=getHipInventory();
	if (NextSwap == nullptr && ! handitem->IsA(AWEAPON_Javelin::StaticClass()))
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHip()	No CLU to swap");
		return;
	}
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (! CanPutAway(handitem))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	Can't put the hand item away!");
			NextSwap=nullptr;
		}
		else
		{
			handitem.PutDown();
		}
	}
	*/
}

void AAGP_Pawn::SwapAltShoulder()
{
	AInventory* handitem = nullptr;
	/*
	KnowAll("AGP_Pawn::SwapAltShoulder()");
	handitem=getHandsInventory();
	NextSwap=getAltShoulderInventory();
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem->IsA(AWeapon::StaticClass()))
		{
			Cast<AWeapon>(handitem).PutDown();
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Pawn::SwapHands()	Don't know how to handle non-weapon " + handitem,true);
			NextSwap=nullptr;
		}
	}
	*/
}
void AAGP_Pawn::DropAndSwap()
{
	//NextSwap=getShoulderInventory();
	if (getHandsInventory() == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		Cast<AHumanController>(Controller)->ServerThrowWeapon();
	}
}

void AAGP_Pawn::getItemToPutInHands()
{
	AThrowWeapon* Grenade = nullptr;
	AAGP_Weapon* binoculars = nullptr;
	/*
	if (DesiredGrenade != nullptr)
	{
		Grenade=Spawn(DesiredGrenade);
		if (! HaveUnlimitedAmmo())
		{
			_InvGrenades[Grenade.InvGrenadeIndex] --;
		}
		return Grenade;
	}
	else
	{
		if (DesiredBinoculars != nullptr)
		{
			binoculars=Spawn(DesiredBinoculars);
			return binoculars;
		}
		else
		{
			return NextSwap;
		}
	}
	*/
}

AInvContainer* AAGP_Pawn::GetSwapContainer()
{
	return Cast<AInvContainer>(Cast<AAGP_Weapon>(NextSwap)->GetSwapContainer());
}

bool AAGP_Pawn::FinishSwapHands()
{
	AInventory* NextItem = nullptr;
	AInventory* handitem = nullptr;
	bool bSuccess = false;
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		DebugLog(DEBUG_Warn,"How did it get here?");
		return false;
	}
	if (EventLab != nullptr)
	{
		if (Weapon->IsA(Aitem_headphones::StaticClass()))
		{
			return false;
		}
	}
	handitem=getHandsInventory();
	NextItem=getItemToPutInHands();
	if (handitem == nullptr)
	{
		if (NextItem == nullptr)
		{
			bSuccess=true;
		}
		else
		{
			if (CanPutInHands(NextItem))
			{
				NextItem.GetSwapContainer().DeleteItem(NextItem);
				ItemPutInHands(NextItem);
				bSuccess=true;
			}
		}
	}
	else
	{
		if (NextItem == nullptr)
		{
			if (CanPutAway(handitem))
			{
				_InvHands.DeleteItem(handitem);
				ItemPutAway(handitem);
				bSuccess=true;
			}
		}
		else
		{
			_InvHands.DeleteItem(handitem);
			NextItem.GetSwapContainer().DeleteItem(NextItem);
			if (CanPutAway(handitem) && CanPutInHands(NextItem))
			{
				ItemPutAway(handitem);
				ItemPutInHands(NextItem);
				bSuccess=true;
			}
			else
			{
				_InvHands.addItem(handitem);
				NextItem.GetSwapContainer().addItem(NextItem);
			}
		}
	}
	KnowAll("AGP_Pawn::FinishSwapHands()	Before ");
	if (! bSuccess)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::FinishSwapHands() Unable to swap " + handitem @ NextItem);
	}
	else
	{
		PendingWeapon=Weapon(getHandsInventory());
		ChangedWeapon();
	}
	KnowAll("AGP_Pawn::FinishSwapHands()	After ");
	DesiredGrenade=nullptr;
	DesiredBinoculars=nullptr;
	NextSwap=nullptr;
	*/
	return bSuccess;
}

bool AAGP_Pawn::CanPutInHands(TSubclassOf<AInventory> Item)
{
	return _InvHands->FindInventorySpace(Item);
}

bool AAGP_Pawn::CanPutAway(TSubclassOf<AInventory> Item)
{
	AAGP_Weapon* weap;
	weap=Cast<AAGP_Weapon>(Item);
	if (weap == nullptr)
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::CanPutAway()	Don't know what to do with no weapon. item(" @ Item @ ") weap(" @ weap @ ")");
		return false;
	}
	if (weap->VirtualWeapon())
	{
		return true;
	}
	else
	{
		//return Cast<AInventory>(weap->GetSwapContainer())->isEmpty();
		return true;   //FAKE /ELiZ
	}
}
void AAGP_Pawn::ItemPutInHands(TSubclassOf<AInventory> Item)
{
	/*
	if (Item->IsA(AThrowWeapon::StaticClass()) || Item->IsA(AItem_Binoculars::StaticClass()))
	{
		Item.GiveTo(this);
		Item.PickupFunction(this);
	}
	_InvHands.addItem(Item);
	if (Item->IsA(AAGP_Weapon::StaticClass()))
	{
		if (Cast<AAGP_Weapon>(Item).fpWeaponThreatLevel > fpPlayerThreatLevel)
		{
			fpPlayerThreatLevel=Cast<AAGP_Weapon>(Item).fpWeaponThreatLevel;
		}
	}
	NPCAlertPlayerEvent();
	*/
}

void AAGP_Pawn::ItemPutAway(TSubclassOf<AInventory> Item)
{
	/*
	if (Cast<AWeapon>(Item).VirtualWeapon())
	{
		if (Item->IsA(AThrowWeapon::StaticClass()))
		{
			_InvGrenades[ThrowWeapon(Item).InvGrenadeIndex] ++;
		}
		else
		{
			if (Item->IsA(AItem_Binoculars::StaticClass()))
			{
				if (_InvBinoculars != Item_Binoculars(Item).InvBinocularsIndex)
				{
					DebugLog(DEBUG_Warn,"AGP_Pawn::ItemPutAway()	Trying to hold two different binocs! Keeping last!");
					_InvBinoculars=Item_Binoculars(Item).InvBinocularsIndex;
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::ItemPutAway() " @ Item @ Cast<AAGP_Weapon>(Item).GetSwapContainer());
		Cast<AAGP_Weapon>(Item).GetSwapContainer().addItem(Item);
	}
	NPCAlertPlayerEvent();
	*/
}

void AAGP_Pawn::PrintInventory()
{
	AInvContainer* invCon = nullptr;
	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		//ScreenPrint("Container: " @ invCon.thename);
		//ScreenPrint(invCon.toString());
	}
}

void AAGP_Pawn::LogInventory()
{
	AInvContainer* invCon = nullptr;
	for (invCon = _InvTop; invCon != nullptr; invCon = invCon->nextContainer)
	{
		//DebugLog(DEBUG_Inv, "AGP_Pawn::LogInventory() Container: " @ invCon.thename);
		//Log(invCon.toString());
	}
}

AInvContainer* AAGP_Pawn::getInvContainerHands()
{
	return _InvHands;
}

AInvContainer* AAGP_Pawn::getInvContainerShoulder()
{
	return _InvShoulder;
}

AInvContainer* AAGP_Pawn::getInvContainerHolster()
{
	return _InvHolster;
}

AInvContainer* AAGP_Pawn::getInvContainerUtility()
{
	return _InvUtility;
}

AInvContainer* AAGP_Pawn::getInvContainerHip()
{
	return _InvHip;
}

AInvContainer* AAGP_Pawn::getInvContainerAltShoulder()
{
	return _InvAltShoulder;
}

void AAGP_Pawn::GetGrenade(uint8 Index)
{
	AInventory* handitem = nullptr;
	AInventory* AltClass = nullptr;
	/*
	DesiredGrenade=nullptr;
	Index --;
	if (Index >= 7)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GetGrenade()	Invalid index received " + Index);
		return;
	}
	if (_InvGrenades[Index] == 0 && ! HaveUnlimitedAmmo())
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	No more grenades at index " + Index);
		return;
	}
	switch(Index)
	{
		case 0:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M67_Frag",Class'Class'));
		break;
		case 1:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_Smoke",Class'Class'));
		break;
		case 2:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M84_Stun",Class'Class'));
		break;
		case 3:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M14_Incendiary",Class'Class'));
		break;
		case 5:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Demo_DoorBreacher",Class'Class'));
		break;
		case 6:
		DesiredGrenade=class<ThrowWeapon>(DynamicLoadObject("AGP_Inventory.Throw_M83_GreenSmoke",Class'Class'));
		break;
		default:
	}
	if (! IsValidInventory(DesiredGrenade,AltClass))
	{
		DesiredGrenade=class<ThrowWeapon>(AltClass);
	}
	if (DesiredGrenade == nullptr)
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GetGrenade()	This Grenade is not valid!");
		return;
	}
	handitem=getHandsInventory();
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.Class == DesiredGrenade)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	Already holding this grenade");
			DesiredGrenade=nullptr;
		}
		else
		{
			if (! CanPutAway(handitem))
			{
				DebugLog(DEBUG_Inv,"AGP_Pawn::GetGrenade()	Nowhere to put the weapon");
				DesiredGrenade=nullptr;
			}
			else
			{
				Cast<AWeapon>(handitem).PutDown();
			}
		}
	}
	*/
}

void AAGP_Pawn::GetBinoculars()
{
	AInventory* handitem = nullptr;
	/*
	if (_InvBinoculars == 0)
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	You don't have binoculars!");
		return;
	}
	switch(_InvBinoculars)
	{
		case 1:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocM22_A",Class'Class'));
		break;
		case 2:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocM24_B",Class'Class'));
		break;
		case 3:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocTank_A",Class'Class'));
		break;
		case 4:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_BinocNewt_B",Class'Class'));
		break;
		case 5:
		DesiredBinoculars=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Item_VIPER",Class'Class'));
		break;
		default:
		break;
	}
	handitem=getHandsInventory();
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (handitem.Class == DesiredBinoculars)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	Already holding these binoculars");
			Cast<AWeapon>(handitem).PutDown();
			DesiredBinoculars=nullptr;
		}
		else
		{
			if (! CanPutAway(handitem))
			{
				DebugLog(DEBUG_Inv,"AGP_Pawn::GetBinoculars()	Nowhere to put the weapon");
				DesiredBinoculars=nullptr;
			}
			else
			{
				Cast<AWeapon>(handitem).PutDown();
			}
		}
	}
	*/
}
void AAGP_Pawn::PutAwayHandItem()
{
	TSubclassOf<AInventory> handitem;
	handitem=getHandsInventory();
	if (handitem != nullptr)
	{
		Cast<AWeapon>(handitem)->PutDown();
	}
}

void AAGP_Pawn::SwapHolster()
{
	AAGP_Weapon* handitem = nullptr;
	/*
	KnowAll("AGP_Pawn::SwapHolster()");
	handitem=Cast<AAGP_Weapon>(getHandsInventory());
	NextSwap=getHolsterInventory();
	if (NextSwap == nullptr && ! handitem->IsA(APistolWeapon::StaticClass()))
	{
		DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	No pistol to swap");
		return;
	}
	if (handitem == nullptr)
	{
		FinishSwapHands();
	}
	else
	{
		if (! CanPutAway(handitem))
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SwapHolster()	Can't put the hand item away!");
			NextSwap=nullptr;
		}
		else
		{
			handitem.PutDown();
		}
	}
	*/
}
void AAGP_Pawn::RecalcInvWeight()
{
	float accumWeight;
	accumWeight = 0;
	if (_InvHands != nullptr)
	{
		accumWeight += _InvHands->fWeight;
	}
	if (_InvShoulder != nullptr)
	{
		accumWeight += _InvShoulder->fWeight;
	}
	if (_InvHolster != nullptr)
	{
		accumWeight += _InvHolster->fWeight;
	}
	if (_InvHip != nullptr)
	{
		accumWeight += _InvHip->fWeight;
	}
	if (_InvHip != nullptr)
	{
		accumWeight += _InvAltShoulder->fWeight;
	}
	SetInventoryWeight(accumWeight);
}
void AAGP_Pawn::ChangeInventoryWeight(float Weight)
{
	/*
	fInvWeight += Weight;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		ScreenPrint("fInvWeight=" @ fInvWeight @ "SpeedRatio=" @ SpeedRatio);
	}
	*/
}
void AAGP_Pawn::SetInventoryWeight(float Weight)
{
	fInvWeight=Weight;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugPosture)
	{
		ScreenPrint("fInvWeight=" @ fInvWeight @ "SpeedRatio=" @ SpeedRatio);
	}
	*/
}
float AAGP_Pawn::GetInventoryWeight()
{
	return fInvWeight;
}

bool AAGP_Pawn::CanUseAmmo(AInventory* weap, AInventory* Ammo)
{
	//return weap != nullptr && weap->IsA(AWeapon::StaticClass()) && Cast<AAGP_Weapon>(weap).ValidAmmo(Ammo.Class);
	return false;    //FAKE   /ELiZ

}

bool AAGP_Pawn::CanPickupItem(AInventory* Item, bool bVirtual)
{
	/*
	if (Item->IsA(AWEAPON_Javelin::StaticClass()))
	{
		if (getHipInventory() != nullptr)
		{
			if (getHipInventory()->IsA(AWEAPON_Javelin::StaticClass()))
			{
				return false;
			}
		}
		if (getHandsInventory() != nullptr)
		{
			if (getHandsInventory()->IsA(AWEAPON_Javelin::StaticClass()))
			{
				return false;
			}
		}
	}
	if (Item->IsA(AJavelin_Tube::StaticClass()))
	{
		if (getAltShoulderInventory() != nullptr)
		{
			if (getAltShoulderInventory()->IsA(AJavelin_Tube::StaticClass()))
			{
				return false;
			}
		}
		if (getHandsInventory() != nullptr)
		{
			if (getHandsInventory()->IsA(AJavelin_Tube::StaticClass()))
			{
				return false;
			}
		}
	}
	if (bVirtual)
	{
		if (Item->IsA(AAmmunition::StaticClass()))
		{
			return CanUseAmmo(Weapon,Item) || CanUseAmmo(_InvShoulder.getFirstItem(),Item) || CanUseAmmo(_InvHolster.getFirstItem(),Item);
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (FindInventorySpace(Item) == nullptr)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::CanPickupItem()	Pawn " + this + " cannot pick up " + Item);
			return false;
		}
		else
		{
			if (Item->IsA(AWeapon::StaticClass()) && Controller.IsInState('PlayerClimbing'))
			{
				Cast<AHumanController>(Controller).ClientMessage("You cannot pick up weapons while climbing.");
				return false;
			}
			DebugLog(DEBUG_Inv,"AGP_Pawn::CanPickupItem()	Pawn " + this + " can pick up " + Item);
			return true;
		}
	}
	*/
	return false;    //FAKE   /ELiZ
}
bool AAGP_Pawn::AreHandsEmpty()
{
	if (_InvHands != nullptr)
	{
		return _InvHands->isEmpty();
	}
	return true;
}

void AAGP_Pawn::NotifyOpticsStatusChangingTo(bool bActive)
{
	/*
	if (bActive && Weapon != nullptr && Weapon->IsA(AItem_Binoculars::StaticClass()))
	{
		Weapon.ForceUnzoom(true);
	}
	*/
}

void AAGP_Pawn::NotifyBinocularsStatusChangingTo(bool bZoom)
{
	if (bZoom && GetOpticsDevice() != nullptr && GetOpticsDevice()->IsActive())
	{
		DeactivateOptics();
	}
}

void AAGP_Pawn::ToggleOptics()
{
	if (GetOpticsDevice() != nullptr)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Toggle();
	}
}

void AAGP_Pawn::CleanupOptics()
{
	if (GetOpticsDevice() != nullptr)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->CleanUp();
	}
}

void AAGP_Pawn::DeactivateOptics()
{
	if (GetOpticsDevice() != nullptr)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Deactivate();
	}
}

void AAGP_Pawn::ActivateOptics()
{
	if (GetOpticsDevice() != nullptr)
	{
		Cast<ABaseOptics>(GetOpticsDevice())->Activate();
	}
}
ABaseOptics* AAGP_Pawn::GetOpticsDevice()
{
	return _OpticsDevice;
}
void AAGP_Pawn::ChangeFireMode()
{
	//Weapon.ChangeFireMode();
}
void AAGP_Pawn::FixJam()
{
	/*
	if (Weapon != nullptr && Weapon.IsInState('BusySupporting') || Weapon.IsInState('BusyChangingFireMode'))
	{
		Log("User tried to fix jame while busy using supported function or changing modes");
		return;
	}
	if (angleEditor)
	{
		boneaxis += 1;
		if (boneaxis == 9)
		{
			boneaxis=0;
		}
		return;
	}
	NPCAlertPlayerEvent();
	Weapon.FixJam();
	*/
}
void AAGP_Pawn::ClientTossWeapon(FVector TossVel)
{
	
	if (Weapon != nullptr)
	{
		Cast<AWeapon>(Weapon)->UnZoom();
	}
	//SetSupported(false,true);
	//WeaponSwap3p(5);
	
}

void AAGP_Pawn::TossWeapon(FVector TossVel)
{
	FVector loc = FVector(0,0,0);
	/*
	ClientTossWeapon(TossVel);
	Weapon.Velocity=TossVel;
	loc=GetPickupSpawnLocation(Weapon.PickupClass);
	Weapon.DropFrom(loc);
	WeaponSwap3p(5);
	*/
}

FVector AAGP_Pawn::GetPickupSpawnLocation(APickup*  PickupClass)
{
	FVector WeaponLoc = FVector(0,0,0);
	FVector SpawnLoc = FVector(0, 0, 0);
	FVector loc = FVector(0, 0, 0);
	FVector Dir = FVector(0, 0, 0);
	FRange PickupCyl = FRange({0,0});
	FRange PawnCyl = FRange({ 0,0 });
	float PawnRadius = 0;
	/*
	WeaponLoc=GetBoneCoords('WeaponBone').Origin;
	if (bIsProne && FrontAuxCyl != nullptr)
	{
		loc=FrontAuxCyl.Location;
		PawnRadius=FrontAuxCyl.CollisionRadius;
	}
	else
	{
		loc=Location;
		PawnRadius=CollisionRadius;
	}
	Dir=Normal(WeaponLoc - loc);
	Dir *= FMax(0,PawnRadius - PickupClass.Default.CollisionRadius);
	SpawnLoc=loc + Dir;
	SpawnLoc.Z=WeaponLoc.Z;
	PickupCyl.Min=SpawnLoc.Z - PickupClass.Default.CollisionHeight / 2;
	PickupCyl.Max=SpawnLoc.Z + PickupClass.Default.CollisionHeight / 2;
	PawnCyl.Min=Location.Z - CollisionHeight / 2;
	PawnCyl.Max=Location.Z + CollisionHeight / 2;
	if (PickupCyl.Min < PawnCyl.Min)
	{
		SpawnLoc.Z=PawnCyl.Min + PickupClass.Default.CollisionHeight / 2;
	}
	else
	{
		if (PickupCyl.Max > PawnCyl.Max)
		{
			SpawnLoc.Z=PawnCyl.Max - PickupClass.Default.CollisionHeight / 2;
		}
	}
	*/
	return SpawnLoc;
}

bool AAGP_Pawn::HaveUnlimitedAmmo()
{
	//return GetController()->bUnlimitedAmmo;
	return false;    //FAKE   /ELiZ
}

float AAGP_Pawn::WeaponEffectivenessBonus()
{
	float retvalue = 0;
	/*
	if (Cast<AAGP_Weapon>(Weapon) == nullptr)
	{
		return 0;
	}
	retvalue=TeamClass.WeaponEffectivenessBonus(Cast<AAGP_Weapon>(Weapon));
	if (Controller != nullptr && Controller.bNoWeaponPenalty)
	{
		return 1;
	}
	if (Cast<AAGP_Weapon>(Weapon).IsOpFor())
	{
		if (Weapon.bGuerrillaWeapon && bGuerrillaMesh)
		{
			retvalue *= 1;
		}
		else
		{
			if (! bGuerrillaMesh)
			{
				retvalue *= 0.75;
			}
		}
	}
	if (bGuerrillaMesh && ! Weapon.bGuerrillaWeapon)
	{
		retvalue *= 0.75;
	}
	*/
	return retvalue;
}

FRotator AAGP_Pawn::BreatheCycle(float DeltaTime)
{
	float OldZoomCycle = 0;
	FRotator BreatheRot = FRotator(0,0,0);
	float CEMToStopWander = 0;
	CEMToStopWander=0.95;
	/*
	fZoomTime += DeltaTime;
	fDeviateCycle += DeltaTime;
	if (Weapon != nullptr && Weapon.ShouldBreatheCycle())
	{
		OldZoomCycle=fZoomCycle;
		fZoomCycle=Sin(fZoomTime + 1 - CE_MeterValue) ** 3;
		if (IsHumanControlled())
		{
			Cast<APlayerController>(Controller).ResetSoundDampening();
		}
		if (OldZoomCycle > 0 && fZoomCycle < 0)
		{
			PlaySound(BreathOutSound,0,1,,,,false);
		}
		else
		{
			if (OldZoomCycle < 0 && fZoomCycle > 0)
			{
				PlaySound(BreathInSound,0,1,,,,false);
			}
		}
		if (IsHumanControlled())
		{
			Cast<APlayerController>(Controller).CalcSoundDampening();
		}
		if (IsHumanControlled() && PlayerController(Controller).debugAiming)
		{
			if (Abs(fZoomCycle) < 0.2 * CE_MeterValue)
			{
				ScreenPrint("Fire Here " @ fZoomCycle @ "Threshold" @ 0.2 * CE_MeterValue);
			}
		}
		fZoomCycle *= Cast<AAGP_Weapon>(Weapon).GetBreatheMultiplier();
		BreatheRot=FRotator(13 0 0) * fZoomCycle * 1 - CE_MeterValue;
		if (fDeviateCycle > fDeviateTime)
		{
			fDeviateCycle=0;
			fDeviateTime=0.25 * CE_MeterValue + FMath::FRand() * CE_MeterValue;
			rDeviation=Weapon.CalcZoomWander() * 1 - CE_MeterValue;
			if (IsSupported())
			{
				if (CE_MeterValue >= CEMToStopWander)
				{
					rDeviation=FRotator(0 0 0);
				}
				else
				{
					rDeviation *= CEMToStopWander - CE_MeterValue / CEMToStopWander;
				}
			}
		}
		if (Abs(fZoomCycle) < 0.2 * CE_MeterValue)
		{
			BreatheRot += rDeviation * 0.85 * DeltaTime;
		}
		else
		{
			BreatheRot += rDeviation * DeltaTime;
		}
		return BreatheRot;
	}
	*/
	return FRotator(0,0,0);
}

/*
 // ======================================================================================
 // AGP function - GetHealthCondition
 // Classifies pawn's health level as Green/Yellow/Red/Dead
 // output:	Enum value of health condition
 // last modified by:  superville 12/21/01
 // ======================================================================================
*/
EHealthCondition AAGP_Pawn::GetHealthCondition()
{
	if (Health > 70)
	{
		return EHealthCondition::HC_GREEN;
	}
	else
	{
		if (Health > 40)
		{
			return EHealthCondition::HC_YELLOW;
		}
		else
		{
			if (Health > 0)
			{
				return EHealthCondition::HC_RED;
			}
			else
			{
				return EHealthCondition::HC_DEAD;
			}
		}
	}
}

/* =================================================================================== *
 * AGP function GetWoundSeverity()
 *	Get the severity of the wound. This is the amount of CEM that can be restored by
 *	a medic.
 *
 * output:	EWoundSeverity	- enum representing severity
 * last modified by: cmb
 * =================================================================================== */
EWoundSeverity AAGP_Pawn::GetWoundSeverity()
{
	if (Health == 100)
	{
		return EWoundSeverity::WS_NotWounded;
	}
	else
	{
		if (BleedMax == 0)
		{
			return EWoundSeverity::WS_Treated;
		}
		else
		{
			if (BleedMax <= 10)
			{
				return EWoundSeverity::WS_Minor;
			}
			else
			{
				if (BleedMax <= 25)
				{
					return EWoundSeverity::WS_Moderate;
				}
				else
				{
					return EWoundSeverity::WS_Urgent;
				}
			}
		}
	}
}
FString AAGP_Pawn::GetHealthString()
{
	EHealthCondition HC;
	HC=GetHealthCondition();
	switch(HC)
	{
		case EHealthCondition::HC_GREEN:
			return "Green";
		case EHealthCondition::HC_YELLOW:
			return "Yellow";
		case EHealthCondition::HC_RED:
			return "Red";
		default:
			return "Dead";
	}
	return "";
}

void AAGP_Pawn::Landed(const FHitResult& Hit)
{
	bool bPlayLanding = false;
	/*
	if (Physics == 17)
	{
		bPlayLanding=false;
	}
	else
	{
		bPlayLanding=true;
	}
	TakeFallingDamage();
	if (Health > 0 && bPlayLanding)
	{
		PlayLanded(Velocity.Z);
	}
	if (Velocity.Z < -1.4 * JumpZ)
	{
		MakeNoise(-0.5 * Velocity.Z / FMax(JumpZ,150));
	}
	bJustLanded=true;
	if (bMidJump)
	{
		ServerSpawnSideEffect('SideEffectSlowHop',0);
		bMidJump=false;
	}
	if (bSwapWhenLanded)
	{
		SwapHands();
	}
	bSwapWhenLanded=false;
	*/
}

void AAGP_Pawn::HitWall(FVector HitNormal, AActor* Wall)
{
	/*
	HitWall(HitNormal,Wall);
	if (ForceActor != nullptr)
	{
		ForceVelocity *= -1;
	}
	*/
}
void AAGP_Pawn::ClientSpawnSideEffect(ASideEffect* SideEffectClass, int32 Damage)
{
	ASideEffect* SE = nullptr;
	/*
	if (SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_DedicatedServer && ! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Client && SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Standalone && ! SideEffectClass.Default.bServerEffect && Controller != Level.GetLocalPlayerController())
	{
		return;
	}
	SE=Spawn(SideEffectClass,Controller);
	SE.ScaleByDamage(Damage);
	SE.Start();
	*/
}

void AAGP_Pawn::ServerSpawnSideEffect(ASideEffect* SideEffectClass, int32 Damage)
{
	ASideEffect* SE = nullptr;
	/*
	if (! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_DedicatedServer && ! SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Client && SideEffectClass.Default.bServerEffect || GetNetMode() == ENetMode::NM_Standalone && ! SideEffectClass.Default.bServerEffect && Controller != Level.GetLocalPlayerController())
	{
		return;
	}
	SE=Spawn(SideEffectClass,Controller);
	SE.ScaleByDamage(Damage);
	SE.Start();
	*/
}

/*
void AAGP_Pawn::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType,FBoneInfo Bone,AController KillerController,AActor ResponsibleActor,UTexture2D HitMaterial)
{
	AAA2_PlayerState* KillerPRI = nullptr;
	FVector MomentumDir = FVector(0,0,0);
	float FFMultiplier = 0;
	AAGP_Pawn aPawn = nullptr;
	float BleedDamage = 0;
	EHealthCondition HC;
	int32 InitialHealth = 0;
	int32 ActualROE = 0;
	UaAGP_DamageType* AGPDamType = nullptr;
	TArray<ASideEffect*> SideEffects = {};
	int32 i = 0;
	if (Role < 4 || isDead())
	{
		if (isDead())
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: is already dead ");
		}
		if (bIsDead)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: bIsDead ");
		}
		if (bNetAlreadyDead)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: bNetAlreadyDead ");
		}
		if (Health <= 0)
		{
			DebugLog(DEBUG_Multi,"TakeDamage :: Health <= 0 ");
		}
		return;
	}
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,8,instigatedBy);
	}
	if (InGodMode() || Controller != nullptr && Controller->IsA(APlayerController::StaticClass()) && PlayerController(Controller).GameReplicationInfo.bRoundIsSuspended)
	{
		Damage=0;
	}
	if (instigatedBy == nullptr)
	{
		if (ClassIsChildOf(DamageType,'AGP_FellDamage'))
		{
			instigatedBy=Self;
		}
		else
		{
			if (KillerController != nullptr)
			{
				instigatedBy=KillerController.Pawn;
			}
		}
	}
	else
	{
		KillerPRI=instigatedBy.PlayerReplicationInfo;
	}
	if (instigatedBy != nullptr)
	{
		if (KillerController == nullptr)
		{
			KillerController=instigatedBy.Controller;
		}
		if (KillerController != nullptr)
		{
			KillerPRI=KillerController.PlayerReplicationInfo;
		}
		if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.IsFriend(KillerPRI) && DamageType.Default.FFMultiplier == 0)
		{
			KillerController=Controller;
			KillerPRI=PlayerReplicationInfo;
		}
	}
	if (Physics == 0)
	{
		SetMovementPhysics();
	}
	if (Physics == 1)
	{
		Momentum.Z=FMax(Momentum.Z,0.4 * VSize(Momentum));
	}
	if (KillerController == Controller)
	{
		Momentum *= 0.6;
	}
	Momentum /= Mass;
	if (ClassIsChildOf(DamageType,'MilesDamage') && Damage > 0)
	{
		Damage=30;
	}
	if (FVector::IsZero(HitLocation))
	{
		HitLocation=Location;
	}
	MomentumDir=Normal(Momentum);
	PlayHit(Damage,instigatedBy,HitLocation,DamageType,MomentumDir);
	AddVelocity(Momentum);
	InitialHealth=Health;
	BleedDamage=Damage * DamageType.Default.DamageBleedPercent;
	if (BleedDamage > BleedHealth)
	{
		if (IsBleeding())
		{
			Health -= BleedHealth;
		}
		fHealPercent=0;
		if (Health - Damage > 0)
		{
			VirtualHealth=0;
			if (BleedMax > BleedDamage)
			{
				BleedMax=BleedMax + BleedDamage / 2;
			}
			else
			{
				BleedMax=BleedDamage + BleedMax / 2;
			}
			BleedHealth=BleedDamage;
			Damage -= BleedHealth;
		}
		fpBleedRate=5;
	}
	HC=GetHealthCondition();
	Health=Max(0,Health - Damage);
	BleedHealth=Min(BleedHealth,Health);
	if (! InGodMode() && Controller != nullptr && Controller.bSuperGodMode && ! Cast<AAGP_GameInfo>(GetGameMode()).bDisableTakeDamageViewShift)
	{
		AGPDamType=class<AGP_DamageType>(DamageType);
		if (Damage > 5)
		{
			if (AGPDamType != nullptr)
			{
				SideEffects=AGPDamType.GetSideEffects(Controller,Damage,instigatedBy,HitLocation,Momentum,Bone,KillerController,ResponsibleActor);
				for (i=0; i<SideEffects.Num(); i++)
				{
					if (SideEffects[i] != nullptr)
					{
						ClientSpawnSideEffect(SideEffects[i],Damage);
						ServerSpawnSideEffect(SideEffects[i],Damage);
					}
				}
			}
		}
	}
	if (HC < GetHealthCondition())
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Self,"HEALTHDEGRADE");
		}
	}
	if (Health <= 0)
	{
		if (bPhysicsAnimUpdate)
		{
			TearOffMomentum=Momentum;
		}
		if (KillerController == nullptr && instigatedBy->IsA(AVehiclePosition::StaticClass()))
		{
			if (Cast<APawn>(instigatedBy.Owner).Controller != nullptr)
			{
				KillerController=Pawn(instigatedBy.Owner).Controller;
			}
		}
		Died(KillerController,DamageType,HitLocation,MomentumDir,Bone);
	}
	else
	{
		if (Controller != nullptr)
		{
			Controller.NotifyTakeHit(instigatedBy,HitLocation,Damage,DamageType,Momentum);
		}
	}
	MakeNoise(1);
	if (instigatedBy != nullptr && instigatedBy.Controller != nullptr && instigatedBy.Controller->IsA(AStudentController::StaticClass()))
	{
		aPawn=Cast<AAGP_Pawn>(instigatedBy);
		if (aPawn._FriendlyFireMonitor != nullptr)
		{
			if (idTeam == 1 || idTeam == 2 && this != instigatedBy)
			{
				aPawn._FriendlyFireMonitor.Notify();
			}
			else
			{
				if (Cast<ANPCBaseController>(Controller) != nullptr && NPCBaseController(Controller).bTrainingCadre)
				{
					aPawn._FriendlyFireMonitor.Notify();
				}
			}
		}
	}
	if (Cast<AHumanController>(Controller) != nullptr && Damage > 0 && instigatedBy->IsA(AAGP_Character_NPC::StaticClass()))
	{
		Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByAI(Cast<AHumanController>(Controller).Pawn.Location);
	}
	if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.IsFriend(KillerPRI))
	{
		if (KillerPRI != PlayerReplicationInfo && Cast<AHumanController>(Controller) != nullptr && Damage > 0)
		{
			Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByFriendlyFire(Cast<AHumanController>(Controller).Pawn.Location);
			for (i=0; i<Level.Game.Stats.PlayerStats.Num(); i++)
			{
				if (Level.Game.Stats.PlayerStats[i] != nullptr)
				{
					Level.Game.Stats.PlayerStats[i].StatEvent_ROEFriendlyFireHits();
				}
			}
		}
		if (PlayerReplicationInfo != KillerPRI)
		{
			aPawn=Cast<AAGP_Pawn>(instigatedBy);
			if (aPawn != nullptr && aPawn._FriendlyFireMonitor != nullptr)
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::TakeDamage(): Notifying FriendlyFireMonitor");
				aPawn._FriendlyFireMonitor.Notify();
			}
			else
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::TakeDamage(): FF occurred, but APawn or FriendlyFireMonitor is None");
			}
			FFMultiplier=DamageType.Default.FFMultiplier;
			if (Level.Game.GetTimeElapsed() < 45)
			{
				FFMultiplier *= 2;
			}
			if (ClassIsChildOf(DamageType,'ProjectileDamage') || ClassIsChildOf(DamageType,'MilesDamage'))
			{
				if (instigatedBy != nullptr && VSize(instigatedBy.Location - Location) < GetTraceDistance())
				{
					FFMultiplier *= 2;
				}
			}
			if (Cast<AAGP_GameInfo>(GetGameMode()) != nullptr)
			{
				ActualROE=FFMultiplier * Damage;
				AGP_GameInfo(GetGameMode()).RecordFriendlyFire(KillerPRI,Self,ActualROE);
				if (instigatedBy != nullptr && instigatedBy.Controller != nullptr && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
				{
					Cast<AHumanController>(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You are hitting a friendly.");
				}
			}
		}
	}
	NotifyShotHit(instigatedBy,DamageType);
	CombatEffectivenessEvent(10);
	if (ResponsibleActor != nullptr)
	{
		if (ClassIsChildOf(DamageType,'BleedDamage'))
		{
		}
		if (! ClassIsChildOf(DamageType,'AGP_FellDamage'))
		{
			ClientSetHitQuadrant(ResponsibleActor.Location);
		}
	}
	else
	{
		if (instigatedBy != nullptr)
		{
			if (ClassIsChildOf(DamageType,'BleedDamage'))
			{
			}
			if (! ClassIsChildOf(DamageType,'AGP_FellDamage'))
			{
				ClientSetHitQuadrant(instigatedBy.Location);
			}
		}
	}
}
*/

void AAGP_Pawn::NotifyShotHit(APawn* instigatedBy, UaDamageType* DamageType)
{
	/*
	APlayerController* PC = nullptr;
	if (instigatedBy != nullptr && instigatedBy.Controller != nullptr && instigatedBy.Controller != Controller)
	{
		PC=Cast<APlayerController>(instigatedBy.Controller);
		if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
		{
			switch(DamageType.Default.AmmoType)
			{
				case 3:
				case 4:
				case 15:
				case 2:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitGrenade();
				break;
				case 14:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitRocket();
				break;
				case 18:
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitMachineGun();
				break;
				default:
				if (Cast<AAGP_Weapon>(instigatedBy.Weapon) != nullptr && ! instigatedBy.Weapon->IsA(AThrowWeapon::StaticClass()) && ! instigatedBy.Weapon->IsA(ARocketWeapon::StaticClass()))
				{
					switch(Cast<AAGP_Weapon>(instigatedBy.Weapon).StatWeaponType)
					{
						case 3:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitPistol();
							break;
						case 4:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitSniperRifle();
							break;
						case 5:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitMachineGun();
							break;
						case 6:
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotHitAssaultRifle();
							break;
						default:
					}
				}
			}
		}
	}
	*/
}

void AAGP_Pawn::ClientSetHitQuadrant(FVector HitSource)
{
	FVector NormalizedVectorToSource = FVector(0,0,0);
	float Angle = 0;
	/*
	NormalizedVectorToSource=Normal(HitSource - Location);
	Angle=NormalizedVectorToSource Dot FVector(1 0 0);
	if (Angle <= 1 && Angle > 0.7071)
	{
		FixedHitQuadrants[0]=1;
	}
	else
	{
		if (Angle <= 0.7071 && Angle >= -0.7071)
		{
			if (NormalizedVectorToSource.Y >= 0)
			{
				FixedHitQuadrants[3]=1;
			}
			else
			{
				FixedHitQuadrants[1]=1;
			}
		}
		else
		{
			FixedHitQuadrants[2]=1;
		}
	}
	NormalizedVectorToSource=NormalizedVectorToSource << Rotation;
	Angle=NormalizedVectorToSource Dot FVector(1 0 0);
	if (Angle <= 1 && Angle > 0.7071)
	{
		HitQuadrants[0]=1;
	}
	else
	{
		if (Angle <= 0.7071 && Angle >= -0.7071)
		{
			if (NormalizedVectorToSource.Y >= 0)
			{
				HitQuadrants[3]=1;
			}
			else
			{
				HitQuadrants[1]=1;
			}
		}
		else
		{
			HitQuadrants[2]=1;
		}
	}
	*/
}
float AAGP_Pawn::GetInjuryPenalty(int32 test_health)
{
	return 0.75 + 0.25*(test_health / 100);
}
bool AAGP_Pawn::IsBleeding()
{
	return BleedHealth> 0 && !bHealingInProgress;
}
bool AAGP_Pawn::IsWounded()
{
/*
	if (Cast<ANPCBaseCivilianController>(Controller) != nullptr && Cast<ANPCBaseCivilianController>(Controller)->bNPCCanBeHealed && Health < 100 && ! Cast<ANPCBaseCivilianController>(Controller)->bHealedByPlayer)
	{
		return true;
	}
*/
	return BleedHealth > 0 || BleedMax > 0;
	
}
bool AAGP_Pawn::PressingSelfHealAction()
{
	return Cast<AHumanController>(Controller) != nullptr && Cast<AHumanController>(Controller)->bHealSelfAction != 0;
}
bool AAGP_Pawn::IsHealing()
{
	if (bHealingInterrupted)
	{
		return false;
	}
	else
	{
		if (Healer == this && PressingSelfHealAction() && Velocity.IsZero())
		{
			if (EventLab != nullptr)
			{
				//EventLab.ActorNotify(this,31,Self,"ISHEALING");
			}
			return true;
		}
		if (Healer->PressingAction() && (Healer->Velocity).IsZero() && Velocity.IsZero())
		{
			if (EventLab != nullptr)
			{
				//EventLab.ActorNotify(this,31,Self,"ISHEALING");
			}
			return true;
		}
		return false;
	}
}
bool AAGP_Pawn::FlashBleeding()
{
	float F;
	int32 i = 0;
	F=2 * fBleedTimer;
	i=F;
	return (i%2 == 0);
}
void AAGP_Pawn::BleedTick(float DeltaTime)
{
	/*
	if (IsBleeding())
	{
		fBleedTimer += DeltaTime;
		if (fBleedTimer > GetBleedTime())
		{
			DoBleed();
			fBleedTimer=0;
		}
	}
	else
	{
		if (Healer != nullptr)
		{
			if (Healer == this)
			{
				fBleedTimer += DeltaTime;
				if (fBleedTimer > GetBleedTime())
				{
					DoBleed();
					fBleedTimer=0;
				}
			}
			if (IsHealing())
			{
				fHealPercent += DeltaTime / fHealDivisor;
				if (Healer != Self)
				{
					fBleedTimer=0;
				}
				if (fHealPercent >= 1)
				{
					StopBleeding();
				}
				else
				{
					SendHealingPercentage();
				}
			}
			else
			{
				if (fBleedTimer == 0)
				{
					HealingInterrupted();
				}
				else
				{
					if (fBleedTimer > 2)
					{
						HealingCanceled();
					}
					else
					{
						if (ReTryHeal())
						{
							if (Healer == this)
							{
								MedicHealSelf();
							}
							else
							{
								UsedBy(Healer);
							}
						}
					}
				}
				if (Healer != Self)
				{
					fBleedTimer += DeltaTime;
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::CheckInventoryOverload()
{
	/*
	bCanSprint=true;
	if (getAltShoulderInventory() != nullptr && getShoulderInventory() != nullptr && getHandsInventory() != nullptr)
	{
		if (getHandsInventory()->IsA(APistolWeapon::StaticClass()) || getHandsInventory()->IsA(AItem_Binoculars::StaticClass()) || getHandsInventory()->IsA(AWEAPON_Javelin::StaticClass()) || getHandsInventory()->IsA(AThrowWeapon::StaticClass()))
		{
			return;
		}
		else
		{
			bCanSprint=false;
			SetWalking(true);
		}
	}
	*/
}

bool AAGP_Pawn::ReTryHeal()
{
	/*
	if (Healer == this)
	{
		if (Healer.PressingSelfHealAction() && bHealingInterrupted && Velocity.IsZero())
		{
			return true;
		}
		else
		{
			HealingInterrupted();
			return false;
		}
	}
	if (Healer.PressingAction() && bHealingInterrupted && (Healer.Velocity).IsZero() && Velocity.IsZero() && VSize(Healer.Location - Location) <= Cast<AHumanController>(Healer.Controller).GetTraceDistance())
	{
		return true;
	}
	else
	{
		HealingInterrupted();
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

void AAGP_Pawn::DoBleed(int32 drain)
{
	/*
	if (Role != 4)
	{
		return;
	}
	if (drain <= 0)
	{
		drain=1;
	}
	drain=Min(drain,BleedHealth);
	BleedHealth -= drain;
	TakeDamage(drain,Self,FVector(0,0,0),FVector(0,0,0),'BleedDamage');
	*/
}

float AAGP_Pawn::GetBleedTime()
{
	return fpBleedRate;
}

bool AAGP_Pawn::CanHealMe(APawn* H)
{
	if (Healer != nullptr)
	{
		return Healer == H;
	}
	else
	{
		return Cast<AAGP_Pawn>(H)->_InvMedPacks > 0 && IsFriend(H);
	}
}

bool AAGP_Pawn::IsCarrying()
{
	/*
	if (Carrier.PressingAction() && (Carrier.Velocity).IsZero() && Velocity.IsZero())
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Self,"ISCARRYING");
		}
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AAGP_Pawn::IsPickingUp()
{
	/*
	if (Carrier.PressingAction() && (Carrier.Velocity).IsZero() && Velocity.IsZero())
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Self,"ISPICKINGUP");
		}
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AAGP_Pawn::MustBeCarried()
{
	return bCanBeCarried;
}

bool AAGP_Pawn::CanCarryMe(APawn* C)
{
	if (Carrier != nullptr)
	{
		return Carrier == C;
	}
	return false;
}

bool AAGP_Pawn::UsedBy(APawn* User)
{
	bool bResumedHealing = false;
	ACommoLocalMessage* CommoType = nullptr;
	/*
	DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() " @ this @ " by " @ User @ ")");
	if (Controller != nullptr && Controller->IsA(ANPCBaseController::StaticClass()))
	{
		if (Cast<ANPCBaseController>(Controller).UsedBy(User))
		{
			Log("UsedBy overridden by NPC controller");
			return true;
		}
	}
	if (CanHealMe(User) && User != Self)
	{
		if (bHealingInterrupted)
		{
			bHealingInterrupted=false;
			if (Healer != User)
			{
				HealingCanceled();
				Healer=Cast<AAGP_Pawn>(User);
			}
			else
			{
				bResumedHealing=true;
				Healer.HealLock(true,bResumedHealing);
			}
		}
		else
		{
			if (IsWounded())
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() I am wounded!");
				bHealingInProgress=true;
				Healer=Cast<AAGP_Pawn>(User);
				Healer.HealLock(true,false);
				Healer.NPCAlertPlayerEvent();
				NPCAlertPlayerEvent();
			}
			else
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::UsedBy() I am not wounded!");
			}
		}
		if (Healer == User)
		{
			if (! bResumedHealing || fBleedTimer > 5)
			{
				if (Healer.bIsWalking)
				{
					CommoType='CommoWhisper';
				}
				else
				{
					CommoType='CommoShout';
				}
				if (GetNetMode() != ENetMode::NM_Standalone)
				{
					Cast<AHumanController>(Healer.Controller).CommoSend(CommoType,30);
				}
			}
			return true;
		}
	}
	if (CanGiveMeObjective(User))
	{
		fObjectiveGivePercentage=0;
		ObjectiveGiver=Cast<AAGP_Pawn>(User);
		ObjectiveGiver.HealLock(true,false);
		return true;
	}
	*/
	return false;
}

void AAGP_Pawn::MedicHealSelf()
{
	bool bResumedHealing = false;
	/*
	if (_InvSelfHealMedPacks > 0)
	{
		if (bHealingInterrupted)
		{
			bHealingInterrupted=false;
			if (Healer != Self)
			{
				HealingCanceled();
				Healer=Self;
			}
			else
			{
				bResumedHealing=true;
				HealLock(true,bResumedHealing);
			}
		}
		else
		{
			if (IsWounded())
			{
				bHealingInProgress=true;
				Healer=Self;
				HealLock(true, false);
			}
			else
			{
				DebugLog(DEBUG_Always,"AGP_Pawn::MedicHealSelf() I am not wounded!");
			}
		}
	}
	*/
}
void AAGP_Pawn::HealLock(bool bLock, bool bSuppressWeaponMove)
{
	/*
	Cast<AHumanController>(Controller).LockPlayer(bLock,bLock);
	if (Weapon != nullptr && ! bSuppressWeaponMove)
	{
		if (bLock)
		{
			Weapon.TempLowerWeapon();
		}
		else
		{
			if (Weapon.IsInState('BusyTempDown') || Weapon.IsInState('BusyTempLowering'))
			{
				Weapon.TempRaiseWeapon();
			}
		}
	}
	*/
}
void AAGP_Pawn::HealingInterrupted()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31,Self,"HEALINTERRUPTED");
	}
	Healer->HealLock(false,true);
	bHealingInterrupted=true;
	if (Healer == this)
	{
		iLastPercent=-1;
		return;
	}
	iLastPercent=-1;
}
void AAGP_Pawn::HealingCanceled()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"HEALCANCELED");
	}
	bHealingInterrupted=false;
	bHealingInProgress=false;
	fHealPercent=0;
	SendHealingComplete();
	Healer.HealLock(false);
	if (Healer != this && Healer._InvMedPacks == 0)
	{
		Healer.PlayerReplicationInfo.bIsMedic=false;
	}
	Healer=nullptr;
	*/
}
void AAGP_Pawn::StopBleeding()
{
	/*
	APlayerController* PC = nullptr;
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Self,"HEALSUCCESSFUL");
	}
	if (Healer != Self)
	{
		Healer.PlayerReplicationInfo.PScoreObjective(GetHealScore());
		PC=Cast<APlayerController>(Controller);
		if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_WasHealed();
		}
		PC=Cast<APlayerController>(Healer.Controller);
		if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_HealedTeammate();
		}
	}
	if (Healer == this)
	{
		fpBleedRate=10;
		BleedHealth /= 2;
		ClientMessage("You have reduced your rate of bleeding.");
	}
	else
	{
		VirtualHealth=BleedMax;
		BleedMax=0;
		BleedHealth=0;
		fBleedTimer=0;
	}
	bHealingInProgress=false;
	bHealingInterrupted=false;
	fHealPercent=0;
	iLastPercent=-1;
	PlayerReplicationInfo.bCallForMedic=false;
	CombatEffectivenessEvent(11);
	SendHealingComplete();
	Healer.HealLock(false);
	if (Healer == this)
	{
		if (_InvSelfHealMedPacks > 0)
		{
			_InvSelfHealMedPacks --;
		}
		Healer=nullptr;
		return;
	}
	if (Healer._InvMedPacks > 0)
	{
		Healer._InvMedPacks --;
	}
	if (Healer._InvMedPacks == 0)
	{
		Healer.PlayerReplicationInfo.bIsMedic=false;
	}
	if (Cast<ANPCBaseCivilianController>(Controller) != nullptr)
	{
		NPCBaseCivilianController(Controller).NotifyPlayerHealedNPC(Healer);
	}
	Healer=nullptr;
	*/
}

int32 AAGP_Pawn::GetHealScore()
{
	/*
	switch(GetWoundSeverity())
	{
		case 2:
			return FMath::Max(BleedHealth,5);
		case 3:
			return FMath::Max(BleedHealth,10);
		case 4:
			return FMath::Max(BleedHealth,15);
		case 5:
			return FMath::Max(BleedHealth,20);
		default:
			return BleedHealth;
	}
	*/
	return 0;    //FAKE   /EliZ
}

void AAGP_Pawn::SendHealingPercentage()
{
	int32 iPercent = 0;
	APlayerController* myPC = nullptr;
	APlayerController* hlPC = nullptr;
	/*
	iPercent=fHealPercent * 100;
	if (iLastPercent != iPercent)
	{
		myPC=Cast<APlayerController>(Controller);
		hlPC=Cast<APlayerController>(Healer.Controller);
		if (Healer != Self)
		{
			Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'HealLocalMessage',iPercent,PlayerReplicationInfo,hlPC.PlayerReplicationInfo);
		}
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,hlPC,'HealLocalMessage',iPercent,PlayerReplicationInfo,hlPC.PlayerReplicationInfo);
		iLastPercent=iPercent;
	}
	*/
}
void AAGP_Pawn::SendHealingComplete()
{
	APlayerController* myPC = nullptr;
	APlayerController* hlPC = nullptr;
	/*
	myPC=Cast<APlayerController>(Controller);
	hlPC=Cast<APlayerController>(Healer.Controller);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'HealLocalMessage',-1);
	if (Healer != Self)
	{
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,hlPC,'HealLocalMessage',-1);
	}
	*/
}

AAGP_ObjectiveInventory* AAGP_Pawn::GetFirstObjectiveInventory()
{
	AInventory* Inv = nullptr;
	AAGP_ObjectiveInventory* ObjI = nullptr;
	/*
	if (getInvContainerUtility() == nullptr)
	{
		return nullptr;
	}
	Inv=getInvContainerUtility().getFirstItem();
	if (Inv != nullptr)
	{
		ObjI=AGP_ObjectiveInventory(Inv);
		if (ObjI != nullptr)
		{
			return ObjI;
		}
		Inv=getInvContainerUtility().getNextItem();
	}
	*/
	return nullptr;   //FAKE   /EliZ
}

bool AAGP_Pawn::CanGiveMeObjective(APawn* p)
{
	AAGP_ObjectiveInventory* ObjI = nullptr;
	/*
	if (ObjectiveGiver == nullptr && IsFriend(p) && FVector::IsZero(Velocity) && FVector::IsZero(p.Velocity))
	{
		ObjI=Cast<AAGP_Pawn>(p).GetFirstObjectiveInventory();
		if (ObjI != nullptr && CanPickupItem(ObjI))
		{
			return true;
		}
	}
	*/
	return false;
}

bool AAGP_Pawn::IsGivingObjective()
{
	/*
	if (ObjectiveGiver.PressingAction() && FVector::IsZero(ObjectiveGiver.Velocity) && FVector::IsZero(Velocity))
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}
void AAGP_Pawn::ObjectiveGiveTick(float DeltaTime)
{
	/*
	if (ObjectiveGiver != nullptr)
	{
		if (IsGivingObjective())
		{
			fObjectiveGivePercentage += DeltaTime / 3;
			if (fObjectiveGivePercentage >= 1)
			{
				GiveObjective();
			}
			else
			{
				SendObjectiveGivePercentage();
			}
		}
		else
		{
			ObjectiveGiveCanceled();
		}
	}
	*/
}
void AAGP_Pawn::GiveObjective()
{
	AAGP_ObjectiveInventory* Copy = nullptr;
	AAGP_ObjectiveInventory* ObjI = nullptr;
	/*
	ObjI=ObjectiveGiver.GetFirstObjectiveInventory();
	Copy=Spawn(ObjI.Class,Self,,,FRotator(0 0 0));
	if (CanPickupItem(Copy))
	{
		Copy.InitFor(ObjI);
		Copy.GiveTo(this);
		Copy.PickupFunction(this);
		ObjI.DetachFromPawn(ObjectiveGiver);
		ObjectiveGiver.DeleteInventory(ObjI);
		ObjI.Destroy();
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_Pawn::GiveObjective()	Could not give the objective away!");
		Copy.Destroy();
	}
	ResetObjectiveGive();
	*/
}

void AAGP_Pawn::ObjectiveGiveCanceled()
{
	ResetObjectiveGive();
}
void AAGP_Pawn::ResetObjectiveGive()
{
	fObjectiveGivePercentage=0;
	ObjectiveGiver->HealLock(false, false);
	SendObjectiveGiveComplete();
	ObjectiveGiver=nullptr;
}
void AAGP_Pawn::SendObjectiveGivePercentage()
{
	int32 iPercent = 0;
	APlayerController* myPC = nullptr;
	APlayerController* gvPC = nullptr;
	/*
	iPercent=fObjectiveGivePercentage * 100;
	if (iLastObjectiveGivePercent != iPercent)
	{
		myPC=Cast<APlayerController>(Controller);
		gvPC=Cast<APlayerController>(ObjectiveGiver.Controller);
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'ObjectiveGiveLocalMessage',iPercent,PlayerReplicationInfo,gvPC.PlayerReplicationInfo);
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,gvPC,'ObjectiveGiveLocalMessage',iPercent,PlayerReplicationInfo,gvPC.PlayerReplicationInfo);
		iLastObjectiveGivePercent=iPercent;
	}
	*/
}

void AAGP_Pawn::SendObjectiveGiveComplete()
{
	APlayerController* myPC = nullptr;
	APlayerController* gvPC = nullptr;
	/*
	myPC=Cast<APlayerController>(Controller);
	gvPC=Cast<APlayerController>(ObjectiveGiver.Controller);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,myPC,'ObjectiveGiveLocalMessage',-1);
	Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,gvPC,'ObjectiveGiveLocalMessage',-1);
	*/
}

void AAGP_Pawn::PickupLock(bool bLock)
{
	//Cast<AHumanController>(Controller)->LockPlayer(bLock,bLock);
	if (Weapon != nullptr)
	{
		if (bLock)
		{
			Weapon->TempLowerWeapon(false);
		}
		else
		{
			Weapon->TempRaiseWeapon();
		}
	}
}

void AAGP_Pawn::PickupInterrupted()
{
	
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31, this,"PICKUPINTERRUPTED");
	}
	Carrier->PickupLock(false);
	
}

void AAGP_Pawn::PickupCanceled()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31,this,"PICKUPCANCELED");
	}
	Carrier->PickupLock(false);
	Carrier=nullptr;
}

void AAGP_Pawn::FinishedPickup()
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(this,31,Self,"PICKUPSUCCESSFUL");
	}
	Carrier->PickupLock(false);
	Carrier=nullptr;
}

int32 AAGP_Pawn::GetFallingDamage(float fallspeed)
{
	/*
	if (Physics == 17 && AGP_PlayerStart(Controller.StartSpot).bNoParaFallDamage && Weapon->IsA(AItem_Parachute::StaticClass()) && Weapon.Charge != 6)
	{
		return 0;
	}
	else
	{
		return FMath::Max(0,-100 * fallspeed + MaxFallSpeed / MaxFallSpeed);
	}
	*/
	return 0;    //FAKE   /ELiZ
}

void AAGP_Pawn::SaveFallSpeed(float fallspeed)
{
	SavedFallSpeed=fallspeed;
}

void AAGP_Pawn::TakeFallingDamage()
{
	float Shake = 0;
	int32 Damage = 0;
	int32 Dir = 0;
	/*
	if (Level.debugFalling)
	{
		DebugLog(DEBUG_Multi,"TakeFallingDamage Vel" @ Velocity.Z @ "MaxFallSpd" @ MaxFallSpeed @ "Base" @ Base);
		if (Velocity.Z < -1 * MaxFallSpeed)
		{
			DebugLog(DEBUG_Multi,"TakeFallingDamage Damage" @ -100 * Velocity.Z + MaxFallSpeed / MaxFallSpeed);
		}
	}
	if (Velocity.Z < -0.5 * MaxFallSpeed)
	{
		MakeNoise(FMin(2,-0.5 * Velocity.Z / FMax(JumpZ,150)));
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			SaveFallSpeed(Velocity.Z);
			Damage=GetFallingDamage(Velocity.Z);
			if (Damage > 0)
			{
				if (Damage > 33 || Damage > Health)
				{
					TakeDamage(Damage,None,Location,FVector(0,0,0),'FallDamage');
				}
				else
				{
					TakeDamage(Damage,None,Location,FVector(0,0,0),'MinorFallDamage');
				}
			}
		}
		if (Controller != nullptr)
		{
			Shake=FMin(1,-1 * Velocity.Z / MaxFallSpeed);
			if (FMath::FRand() < 0.5)
			{
				Dir=-1;
			}
			else
			{
				Dir=1;
			}
		}
	}
	if (Physics == 17 || IsInState('BusyParachuting') || FullBodyAnim == 4)
	{
		Damage=CheckParachuteLandingFall();
		if (Damage != 0)
		{
			if (Level.debugFalling)
			{
				Log("TakePLFDamage" @ Damage);
			}
			TakeDamage(Damage,None,Location,FVector(0,0,0),'FallDamage');
		}
		if (! bIsDead)
		{
			ParachuteLanding(Damage != 0);
		}
	}
	*/
}

int32 AAGP_Pawn::AbsorbDamage(int32 Damage, UaDamageType* DamageType, FVector HitLocation)
{
	return Damage;
}

void AAGP_Pawn::AddVelocity(FVector NewVelocity)
{
	/*
	if (bIgnoreForces)
	{
		return;
	}
	if (Health <= 0)
	{
		GOTO JL00CE;
	}
	if (Physics == 11 || Physics == 9 && NewVelocity.Z > Default.JumpZ)
	{
		SetPhysics(2);
		if (Velocity.Z > 380 && NewVelocity.Z > 0)
		{
			NewVelocity.Z *= 0.5;
		}
		Velocity += NewVelocity;
	}
	else
	{
		Velocity.Y += NewVelocity.Y;
		Velocity.X += NewVelocity.X;
JL00CE:
	}
	*/
}
void AAGP_Pawn::PlayHit(float Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FVector Momentum)
{
	/*
	if (Damage <= 0 && Controller != nullptr && ! Controller.bGodMode)
	{
		return;
	}
	CombatEffectivenessEvent(10);
	PlayHit(Damage,instigatedBy,HitLocation,DamageType,Momentum);
	*/
}
void AAGP_Pawn::PlayTakeHit(FVector HitLoc, int32 Damage, UaDamageType* DamageType)
{
	USoundBase* DesiredSound = nullptr;
	/*
	DesiredSound=DamageType.GetPawnDamageSound();
	if (DesiredSound != nullptr)
	{
		PlaySound(DesiredSound,0,1,,40,,false);
	}
	*/
}

bool AAGP_Pawn::IsEnemy(APawn* Other)
{
	/*
	if (Other == this)
	{
		return false;
	}
	if (PlayerReplicationInfo != nullptr && Other.PlayerReplicationInfo != nullptr)
	{
		return PlayerReplicationInfo.IsEnemy(Other.PlayerReplicationInfo);
	}
	*/
	return false;
}

bool AAGP_Pawn::IsFriend(APawn* Other)
{
	
	if (Other == this)
	{
		return true;
	}
	/*
	if (Controller != nullptr && Controller->IsA(ANPCBaseController::StaticClass()) && Cast<ANPCBaseController*>(Controller)->bNPCCanBeHealed)
	{
		return true;
	}
	if (PlayerReplicationInfo != nullptr && Other->PlayerReplicationInfo != nullptr)
	{
		return PlayerReplicationInfo->IsFriend(Other->PlayerReplicationInfo);
	}
	*/
	return false;
	
}
void AAGP_Pawn::ReportCivilianEvent(APawn* Other, float OthersDistance_sq, AController* hcInstigator)
{
	/*
	int32 EventDistance_sq;
	if (Other == nullptr)
	{
		return;
	}
	Log("AGP_Pawn: ReportCivilianEvent Called with: " @ OthersDistance_sq @ " and " + NPCBaseCivilianController(Other.Controller));
	if (Other.Controller != nullptr)
	{
		if (Cast<ANPCBaseController>(Other.Controller).bReportableCivi)
		{
			EventDistance_sq=NPCBaseController(Other.Controller).iReportEventDistance * NPCBaseController(Other.Controller).iReportEventDistance;
			Log("Calling: ReportCivilianEvent with: " @ OthersDistance_sq @ " and " + NPCBaseController(Other.Controller));
			Log("NPC ReportDistanc is : " @ NPCBaseController(Other.Controller).iReportEventDistance @ " EventDistance_sq = " @ EventDistance_sq);
			if (OthersDistance_sq < EventDistance_sq)
			{
				TriggerEvent(Cast<ANPCBaseController>(Other.Controller).ReportedEvent,None,None);
				NPCBaseController(Other.Controller).bReportableCivi=false;
				Cast<AHumanController>(hcInstigator).bNPCReported=true;
			}
		}
	}
	else
	{
		Log("Controller is NONE in ReportCivillianEvent");
	}
	*/
}

bool AAGP_Pawn::IsReportableCivi(APawn* Other)
{
	/*
	if (Other == this)
	{
		Log("Reporting Me");
		return true;
	}
	if (Other.Controller != nullptr)
	{
		if (Other.Controller->IsA(ANPCBaseCivilianController::StaticClass()))
		{
			if (Cast<ANPCBaseCivilianController>(Other.Controller).bReportableCivi)
			{
				Log("Fine... this is something that should be reportable");
				return true;
			}
		}
	}
	else
	{
		Log("Controller still NONE!!!");
	}
	Log("Guess Not!");
	*/
	return false;
}

int32 AAGP_Pawn::CivilianReportDistance(APawn* Other)
{
	/*
	if (Other.Controller != nullptr)
	{
		Log("Wonder how far we have to be: " @ NPCBaseCivilianController(Other.Controller).iReportEventDistance);
		return NPCBaseCivilianController(Other.Controller).iReportEventDistance;
	}
	*/
	return 0;    //FAKE  /ELiZ
}

FName AAGP_Pawn::CivilianReportEvent(APawn* Other)
{
	/*
	if (Other.Controller != nullptr)
	{
		return NPCBaseCivilianController(Other.Controller).ReportedEvent;
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void AAGP_Pawn::SetDeathMonitor(UScriptObject* mon)
{
	_DeathMonitor=mon;
}

void AAGP_Pawn::DropUtilityInventory()
{
	AInventory* Inv = nullptr;
	AAGP_ObjectiveInventory* ObjI = nullptr;
	FName AttachBone = "";
	/*
	if (getInvContainerUtility() == nullptr)
	{
		return;
	}
	Inv=getInvContainerUtility().getFirstItem();
	if (Inv != nullptr)
	{
		ObjI=AGP_ObjectiveInventory(Inv);
		if (ObjI != nullptr)
		{
			AttachBone=ObjI.ThirdPersonActor.AttachmentBone;
			ObjI.Velocity=Velocity * 0.85;
			ObjI.DropFrom(GetBoneCoords(AttachBone).Origin);
		}
		Inv=getInvContainerUtility().getNextItem();
	}
	*/
}

void AAGP_Pawn::DropWeaponsAfterDeath()
{
	AWeapon* weap = nullptr;
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		weap=Weapon;
		if (weap != nullptr)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('WeaponBone').Origin);
			Weapon=nullptr;
		}
		weap=Weapon(getShoulderInventory());
		if (weap != nullptr)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('RSlungWeapon').Origin);
		}
		DropUtilityInventory();
		weap=Weapon(getAltShoulderInventory());
		if (weap != nullptr)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('RSlungWeapon').Origin);
		}
		weap=Weapon(getHipInventory());
		if (weap != nullptr)
		{
			weap.Velocity=Velocity * 1.15;
			weap.DropFrom(GetBoneCoords('ButtPouch').Origin);
		}
	}
	*/
}
void AAGP_Pawn::ClientStopSideEffects()
{
	ASideEffect* SE = nullptr;
	/*
	ForEach AllActors('SideEffect',SE)
	{
		if (SE.Owner == Controller)
		{
			SE.End();
		}
	}
	*/
}

void AAGP_Pawn::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation,FVector HitDir,FBoneInfo Bone)
{
	AAGP_Objective* Objective = nullptr;
	int32 i = 0;
	/*
	if (VisionDistActor != nullptr)
	{
		VisionDistActor.Destroy();
	}
	if (AudioDistActor != nullptr)
	{
		AudioDistActor.Destroy();
	}
	DestroyDebugIcons();
	if (DrivenVehicle == nullptr)
	{
		DropWeaponsAfterDeath();
	}
	ClientStopSideEffects();
	if (_DeathMonitor != nullptr)
	{
		_DeathMonitor.Notify();
	}
	if (Team != nullptr)
	{
		if (removeAsLeader() == false)
		{
			removeAsSubordinate();
		}
		checkTeamSize();
		Team.printTeam();
	}
	DebugLog(DEBUG_Stats,"Current objective trigger on death: " + GetCurrentTrigger() + " objective: " + AGP_Objective(GetCurrentTrigger()));
	Objective=AGP_Objective(GetCurrentTrigger());
	if (Objective != nullptr)
	{
		Objective.PawnDied(this);
	}
	if (bDeleteMe)
	{
		return;
	}
	if (Healer != nullptr)
	{
		HealingCanceled();
	}
	BleedHealth=0;
	if (DrivenVehicle != nullptr)
	{
		Velocity=DrivenVehicle.Velocity;
		DrivenVehicle.DriverDied();
	}
	Health=Min(0,Health);
	if (DrivenVehicle == nullptr)
	{
		Level.Game.Killed(Killer,Controller,Self,DamageType);
	}
	else
	{
		Level.Game.Killed(Killer,DrivenVehicle.Controller,Self,DamageType);
	}
	if (Killer != nullptr)
	{
		TriggerEvent(Event,Self,Killer.Pawn);
	}
	else
	{
		TriggerEvent(Event,Self,None);
	}
	Velocity.Z *= 1.3;
	if (IsHumanControlled())
	{
		Cast<APlayerController>(Controller).ForceDeathUpdate();
	}
	PlayDying(DamageType,HitLocation,HitDir,Bone);
	if (Level.Game != nullptr && Level.Game.bGameEnded)
	{
		return;
	}
	if (! bPhysicsAnimUpdate && ! IsLocallyControlled())
	{
		ClientDying(DamageType,HitLocation,HitDir,Bone);
	}
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,11,Killer);
	}
	if (Cast<AHumanController>(Controller) != nullptr)
	{
		if (Killer != nullptr)
		{
			if (Killer.Pawn->IsA(AAGP_Character_NPC::StaticClass()))
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByAI();
			}
			else
			{
				if (Killer.PlayerReplicationInfo != nullptr && Controller.PlayerReplicationInfo.IsFriend(Killer.PlayerReplicationInfo))
				{
					Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByFriendlyFire();
					for (i=0; i<Level.Game.Stats.PlayerStats.Num(); i++)
					{
						if (Level.Game.Stats.PlayerStats[i] != nullptr)
						{
							Level.Game.Stats.PlayerStats[i].StatEvent_ROEFriendlyFireDeaths();
						}
					}
				}
			}
		}
		else
		{
			if (bHitByIED)
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_PlayerTotalDeathsByObject();
			}
		}
	}
	if (Self->IsA(ANPC_civilian::StaticClass()))
	{
		if (Cast<AHumanController>(Killer) != nullptr)
		{
			Level.Game.Stats.PlayerStats[HumanController(Killer).PlayerStatsIndex].StatEvent_ROECivilianDeaths();
		}
		else
		{
			if (bHitByIED)
			{
				Level.Game.Stats.PlayerStats[HumanController(Controller).PlayerStatsIndex].StatEvent_ROECivilianDeathsByIED();
			}
		}
	}
	*/
}

void AAGP_Pawn::PlayDying(UaDamageType DamageType, FVector HitLoc,FVector HitDir,FBoneInfo Bone)
{
	/*
	DebugLog(DEBUG_NetClean,"AGP_Pawn::PlayDying() " + Self);
	SetCollision(false,False,false);
	if (FrontAuxCyl != nullptr)
	{
		FrontAuxCyl.Destroy();
	}
	if (BackAuxCyl != nullptr)
	{
		BackAuxCyl.Destroy();
	}
	bUseAuxCollision=false;
	AmbientSound=nullptr;
	bCanTeleport=false;
	bReplicateMovement=false;
	bTearOff=true;
	bPlayedDeath=true;
	HitDamageType=DamageType;
	TakeHitLocation=HitLoc;
	AnimBlendParams(1,0);
	if (RagdollLifeSpan > 0)
	{
		LifeSpan=RagdollLifeSpan;
	}
	DebugLog(DEBUG_Anim,"AGP_Pawn::PlayDying() Pawn(" @ this @ ") Cast<AController>(" @ Controller @ ") Owner(" @ Owner @ ") Cast<AWeapon>(" @ Weapon @ ")");
	GotoState('Dying');
	PlayDyingAnimation(DamageType,HitLoc);
	*/
}

void AAGP_Pawn::CloseEyes()
{
	FVector eyeloc;
	FRotator eyerot;
	eyeloc.Y=0.504;
	eyeloc.X=-0.031;
	eyeloc.Z=-0.067;
	eyerot.Yaw=1474;
	eyerot.Pitch=852;
	eyerot.Roll=0;
	//SetBoneLocation('bn_lblink',eyeloc,1);
	//SetBoneRotation('bn_lblink',eyerot,,1);
	eyerot.Yaw=-973;
	eyerot.Pitch=-534;
	eyerot.Roll=0;
	eyeloc.Y=0.57;
	eyeloc.X=0.027;
	eyeloc.Z=0;
	//SetBoneLocation('bn_rblink',eyeloc,1);
	//SetBoneRotation('bn_rblink',eyerot,,1);
}
void AAGP_Pawn::CloseHands()
{
	FRotator rightthumbrot;
	FRotator rightindexrot;
	FRotator rightpinkyrot;
	FRotator leftthumbrot;
	FRotator leftindexrot;
	FRotator leftpinkyrot;
	rightthumbrot.Roll=-3164;
	rightthumbrot.Pitch=204;
	rightthumbrot.Yaw=2092;
	//SetBoneRotation('rthumb1',rightthumbrot,,1);
	rightthumbrot.Roll=-614;
	rightthumbrot.Pitch=-1091;
	rightthumbrot.Yaw=2473;
	//SetBoneRotation('rthumb2',rightthumbrot,,1);
	rightindexrot.Roll=1071;
	rightindexrot.Pitch=-278;
	rightindexrot.Yaw=7209;
	//SetBoneRotation('rindex1',rightindexrot,,1);
	rightindexrot.Roll=0;
	rightindexrot.Pitch=0;
	rightindexrot.Yaw=4123;
	//SetBoneRotation('rindex2',rightindexrot,,1);
	rightindexrot.Roll=0;
	rightindexrot.Pitch=0;
	rightindexrot.Yaw=1619;
	//SetBoneRotation('rindex3',rightindexrot,,1);
	rightpinkyrot.Roll=851;
	rightpinkyrot.Pitch=1213;
	rightpinkyrot.Yaw=10429;
	//SetBoneRotation('rpinky1',rightpinkyrot,,1);
	rightpinkyrot.Roll=1033;
	rightpinkyrot.Pitch=186;
	rightpinkyrot.Yaw=3979;
	//SetBoneRotation('rpinky2',rightpinkyrot,,1);
	rightpinkyrot.Roll=1918;
	rightpinkyrot.Pitch=141;
	rightpinkyrot.Yaw=3521;
	//SetBoneRotation('rpinky3',rightpinkyrot,,1);
	leftthumbrot.Roll=-4891;
	leftthumbrot.Pitch=442;
	leftthumbrot.Yaw=-381;
	//SetBoneRotation('lthumb1',leftthumbrot,,1);
	leftthumbrot.Roll=-1107;
	leftthumbrot.Pitch=778;
	leftthumbrot.Yaw=-2004;
	//SetBoneRotation('lthumb2',leftthumbrot,,1);
	leftthumbrot.Roll=-203;
	leftthumbrot.Pitch=396;
	leftthumbrot.Yaw=-1051;
	//SetBoneRotation('lthumb3',leftthumbrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-4443;
	//SetBoneRotation('lindex1',leftindexrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-5543;
	//SetBoneRotation('lindex2',leftindexrot,,1);
	leftindexrot.Roll=0;
	leftindexrot.Pitch=0;
	leftindexrot.Yaw=-2051;
	//SetBoneRotation('lindex3',leftindexrot,,1);
	leftpinkyrot.Roll=1261;
	leftpinkyrot.Pitch=-836;
	leftpinkyrot.Yaw=-5660;
	//SetBoneRotation('lpinky1',leftpinkyrot,,1);
	leftpinkyrot.Roll=1253;
	leftpinkyrot.Pitch=-110;
	leftpinkyrot.Yaw=-8522;
	//SetBoneRotation('lpinky2',leftpinkyrot,,1);
	leftpinkyrot.Roll=1257;
	leftpinkyrot.Pitch=-210;
	leftpinkyrot.Yaw=-3665;
	//SetBoneRotation('lpinky3',leftpinkyrot,,1);
}

void AAGP_Pawn::PlayDyingAnimation(UaDamageType* DamageType, FVector HitLoc)
{
	FVector shotDir = FVector(0,0,0);
	FVector hitLocRel = FVector(0, 0, 0);
	FVector deathAngVel = FVector(0, 0, 0);
	FVector shotStrength = FVector(0, 0, 0);
	float maxDim = 0;
	FString RagSkelName = "";
	UKarmaParamsSkel* skelParams = nullptr;
	/*
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (GetNetMode() != ENetMode::NM_DedicatedServer && Level.PhysicsDetailLevel == 0 && GetWorld()->GetTimeSeconds() - LastRenderTime > 3)
		{
			Log("PlayDyingAnimation() - detail too low, destroying pawn");
			Destroy();
			return;
		}
		if (Level.GamePlayMode != 1 && OutOfBounds <= 0 && AnimManager == nullptr || ! AnimManager.CanPlayDeathAnim())
		{
			if (RagdollOverride != "")
			{
				RagSkelName=RagdollOverride;
			}
			else
			{
				DebugLog(DEBUG_Anim,"PlayDying: No RagdollOverride");
			}
			if (RagSkelName != "")
			{
				KMakeRagdollAvailable();
			}
			if (KIsRagdollAvailable() && RagSkelName != "")
			{
				skelParams=KarmaParamsSkel(KParams);
				skelParams.KSkeleton=RagSkelName;
				KParams=skelParams;
				StopAnimating(true);
				CloseEyes();
				CloseHands();
				if (DamageType != nullptr && DamageType.Default.bKUseOwnDeathVel)
				{
					RagDeathVel=DamageType.Default.KDeathVel;
					RagDeathUpKick=DamageType.Default.KDeathUpKick;
					RagShootStrength=DamageType.Default.KDamageImpulse;
					DebugLog(DEBUG_Karma,"PlayDyingAnimation() Player was killed by DamageType= " + DamageType);
					if (ClassIsChildOf(DamageType,'ProjectileDamage') && bIsProne)
					{
						RagDeathUpKick=0;
						RagSpinScale *= RagProneProjectileScale;
						RagInvInertia *= RagProneProjectileScale;
						RagShootStrength *= RagProneProjectileScale;
					}
				}
				shotDir=Normal(TearOffMomentum);
				shotStrength=RagDeathVel * shotDir;
				hitLocRel=TakeHitLocation - Location;
				hitLocRel.X *= RagSpinScale;
				hitLocRel.Y *= RagSpinScale;
				if (VSize(TearOffMomentum) < 0.01)
				{
					DebugLog(DEBUG_Karma,"TearOffMomentum magnitude of Zero");
					deathAngVel=VRand() * 18000;
				}
				else
				{
					deathAngVel=RagInvInertia * hitLocRel Cross shotStrength;
				}
				skelParams.KStartLinVel.X=0.6 * Velocity.X;
				skelParams.KStartLinVel.Y=0.6 * Velocity.Y;
				skelParams.KStartLinVel.Z=1 * Velocity.Z;
				skelParams.KStartLinVel += shotStrength;
				if (Velocity.Z > -10)
				{
					skelParams.KStartLinVel.Z += RagDeathUpKick;
				}
				skelParams.KStartAngVel=deathAngVel;
				maxDim=Max(CollisionRadius,CollisionHeight);
				skelParams.KShotStart=TakeHitLocation - 1 * shotDir;
				skelParams.KShotEnd=TakeHitLocation + 2 * maxDim * shotDir;
				skelParams.KShotStrength=RagShootStrength;
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagShootStrength= " + RagShootStrength);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagSpinScale= " + RagSpinScale);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagInvInertia= " + RagInvInertia);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagDeathVel= " + RagDeathVel);
				DebugLog(DEBUG_Karma,"PlayDyingAnimation() RagDeathUpKick= " + RagDeathUpKick);
				KSetBlockKarma(true);
				SetPhysics(14);
				return;
			}
		}
		else
		{
			if (bPhysicsAnimUpdate)
			{
				bReplicateMovement=false;
			}
			bPlayedDeath=true;
		}
	}
	*/
}
bool AAGP_Pawn::isDead()
{
	return bIsDead || bNetAlreadyDead || Health <= 0;
}
void AAGP_Pawn::ClientAlertOutOfBounds(int32 Seconds)
{
	/*
	if (Cast<APlayerController>(Controller).MyHUD != nullptr)
	{
		if (bOOBIsTrainingVolume)
		{
			Cast<APlayerController>(Controller).MyHUD.DisplayCenteredMessage(1.1,"You have left the training area!","You have" @ Seconds @ "seconds to return...");
		}
		else
		{
			Cast<APlayerController>(Controller).MyHUD.DisplayCenteredMessage(1.1,"You have left the combat zone!","You have" @ Seconds @ "seconds to return...");
		}
	}
	*/
}
void AAGP_Pawn::OutOfBoundsNotifyKillPlayer()
{
	/*
	if (Cast<APlayerController>(Controller).MyHUD != nullptr)
	{
		Cast<APlayerController>(Controller).MyHUD.DisplayCenteredMessage(3,"Failed to return to combat.");
	}
	*/
}
void AAGP_Pawn::ClientAlertReturnedToCombat()
{
	/*
	if (Cast<APlayerController>(Controller).MyHUD != nullptr)
	{
		if (bOOBIsTrainingVolume)
		{
			Cast<APlayerController>(Controller).MyHUD.DisplayCenteredMessage(3,"You have returned to the training area.");
		}
		else
		{
			Cast<APlayerController>(Controller).MyHUD.DisplayCenteredMessage(3,"You have returned to combat.");
		}
	}
	*/
}
void AAGP_Pawn::OutOfBoundsCheck()
{
	/*
	if (OutOfBounds > 0)
	{
		TimeOutOfBounds += 0.5;
		ClientAlertOutOfBounds(Ceil(CurrentZoneTimeToKill - TimeOutOfBounds));
	}
	if (CurrentZoneTimeToKill - TimeOutOfBounds <= 0)
	{
		StopCustomTimer('OutOfBoundsCheck');
		OutOfBounds ++;
		if (bOOBIsTrainingVolume)
		{
			Cast<AHumanController>(Controller).DisplayMissionFailure("","You failed to stay within training areas.","Come back tomorrow and try again.",128,128,6,"None");
		}
		else
		{
			KilledBy(this);
		}
	}
	*/
}
void AAGP_Pawn::AnimateDead()
{
}
void AAGP_Pawn::GetDeathAnimName(bool bEndLoop)
{
}
bool AAGP_Pawn::CanTransitionDeath(EDeathAnim NewAnim)
{
	switch(DeathAnim)
	{
		case EDeathAnim::DEATH_None:
			return true;
		case EDeathAnim::DEATH_ParachuteDead:
			return NewAnim == EDeathAnim::DEATH_PLFDead || NewAnim == EDeathAnim::DEATH_PLFMilesDead;
		default:
			return DeathAnim == NewAnim;
	}
}
void AAGP_Pawn::SetDeathAnim(EDeathAnim NewAnim)
{
	if (CanTransitionDeath(NewAnim))
	{
		DeathAnim=NewAnim;
	}
	else
	{
		//DebugLog(DEBUG_Warn,"AGP_Pawn::SetDeathAnim() Can't change the death anim from(" @ DeathAnim @ ") to (" @ NewAnim @ ")");
	}
}
void AAGP_Pawn::Destroyed()
{

	/*
	if (VisionDistActor != nullptr)
	{
		VisionDistActor.Destroy();
	}
	if (AudioDistActor != nullptr)
	{
		AudioDistActor.Destroy();
	}
	DebugLog(DEBUG_NetClean,"AGP_Pawn::Destroyed() for player " + OwnerName + " " + Self);
	DebugLog(DEBUG_Multi,"Resetting reload time on destruction");
	fTimeSinceLastReload=0;
	if (Role != 4)
	{
		if (Level.GetClientController() != nullptr)
		{
			Level.GetClientController().NotifyPawnDestroyed(this);
		}
		if (PlayerReplicationInfo != nullptr)
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	" + PlayerReplicationInfo @ PlayerReplicationInfo.myPawn);
			PlayerReplicationInfo.myPawn=nullptr;
		}
		if (Controller != nullptr)
		{
			DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	controller: " + Controller);
			if (Controller->IsA(APlayerController::StaticClass()))
			{
				DebugLog(DEBUG_Multi,"AGP_Pawn::Destroyed()	HUD: " + PlayerController(Controller).MyHUD);
			}
			if (Controller->IsA(AHumanController::StaticClass()))
			{
				DebugLog(DEBUG_HUD,"AGP_Pawn::Destroyed() - Praying for AGP_HUD not to crash! PawnOwner was " + Cast<AAGP_HUD>(Cast<AHumanController>(Controller).MyHUD).PawnOwner,true);
				Cast<AAGP_HUD>(Cast<AHumanController>(Controller).MyHUD).bDrawHUD=false;
			}
		}
	}
	*/
	DiscardInventory();
	if (_OpticsDevice != nullptr)
	{
		_OpticsDevice->Destroy();
		_OpticsDevice=nullptr;
	}
	if (TeamRole != nullptr)
	{
		TeamRole->Destroy();
		TeamRole= nullptr;
	}
	if (TeamClass != nullptr)
	{
		//TeamClass->Destroy();
		TeamClass= nullptr;
	}
	Super::Destroyed();
}
bool AAGP_Pawn::removeAsLeader()
{
	AAGP_Pawn* new_leader= nullptr;
	bool new_sub=false;
	int32 i=0;
	int32 j = 0;
	float high_leader;
	int32 high_rank;
	if (nSubordinates == 0)
	{
		return false;
	}
	//DebugLog(DEBUG_Team,"AGP_Pawn::removeAsLeader() Removing as leader " @ Self);
	high_leader=0;
	high_rank=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i]->rank > high_rank)
		{
			high_rank=Subordinate[i]->rank;
			high_leader=Subordinate[i]->fLeadership;
			new_leader=Subordinate[i];
		}
		else
		{
			if (Subordinate[i]->rank == high_rank && Subordinate[i]->fLeadership > high_leader)
			{
				high_leader=Subordinate[i]->fLeadership;
				new_leader=Subordinate[i];
			}
		}
	}
	/*
	if (this->ownsMentalModel())
	{
		new_leader->setMentalModel(this->getMentalModel());
	}
	*/
	if (Leader != nullptr)
	{
		Leader->replaceSubordinate(this,new_leader);
	}
	else
	{
		Team->replaceSubordinate(this,new_leader);
	}
	//DebugLog(DEBUG_Team,"AGP_Pawn::removeAsLeader	Elevating this leader " @ new_leader);
	//new_sub=new_leader->removeAsLeader();
	if (new_sub == true)
	{
		new_leader->nSubordinates=nSubordinates;
	}
	else
	{
		new_leader->nSubordinates=nSubordinates - 1;
	}
	j=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] != new_leader)
		{
			Subordinate[i]->Leader=new_leader;
			new_leader->Subordinate[j]=Subordinate[i];
			j ++;
		}
	}
	new_leader->Leader=Leader;
	new_leader->idUnitNumber=idUnitNumber;
	new_leader->idRole=idRole;
	//new_leader->TeamRole=TeamRole->spawnNewRole();
	new_leader->TeamRole->my_AGP_Pawn=new_leader;
	return true;
}

void AAGP_Pawn::checkTeamSize()
{
	int32 i = 0;
	AAGP_Pawn* squad_leader = nullptr;
	AAGP_Pawn* leader_1 = nullptr;
	AAGP_Pawn* leader_2 = nullptr;
	AAGP_Pawn* swap_pawn = nullptr;
	bool Resize = false;
	/*
	if (TeamRole.squadBasedRole() == false)
	{
		return;
	}
	squad_leader=TeamRole.getUnitLeader();
	Resize=false;
	if (squad_leader == nullptr)
	{
		return;
	}
	if (squad_leader.nSubordinates > 1)
	{
		if (squad_leader.Subordinate[0].TeamRole.getUnitSize() < 3)
		{
			Resize=true;
			leader_1=squad_leader.Subordinate[0];
			leader_2=squad_leader.Subordinate[1];
		}
		else
		{
			if (squad_leader.Subordinate[1].TeamRole.getUnitSize() < 3)
			{
				Resize=true;
				leader_1=squad_leader.Subordinate[1];
				leader_2=squad_leader.Subordinate[0];
			}
		}
	}
	if (Resize == true)
	{
		if (leader_2.TeamRole.getUnitSize() > 3)
		{
			leader_2.nSubordinates --;
			swap_pawn=leader_2.Subordinate[leader_2.nSubordinates];
			swap_pawn.Leader=leader_1;
			leader_1.Subordinate[leader_1.nSubordinates]=swap_pawn;
			leader_1.nSubordinates ++;
		}
		else
		{
			if (leader_2.rank > leader_1.rank || leader_2.rank == leader_1.rank && leader_2.fLeadership > leader_1.fLeadership)
			{
				swap_pawn=leader_1;
				leader_1=leader_2;
				leader_2=swap_pawn;
			}
			for (i=0; i<leader_2.nSubordinates; i++)
			{
				leader_1.addSubordinate(leader_2.Subordinate[i]);
			}
			leader_1.addSubordinate(leader_2);
			leader_2.TeamRole=leader_1.TeamRole.spawnSubordinateRole();
			leader_2.TeamRole.my_AGP_Pawn=leader_2;
			leader_2.nSubordinates=0;
			leader_1.Leader.removeSubordinate(leader_2);
		}
	}
	*/
}
bool AAGP_Pawn::replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub)
{
	int32 i = 0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] == old_sub)
		{
			Subordinate[i]=new_sub;
			return true;
		}
	}
	//DebugLog(DEBUG_Team,"Could not replace" @ old_sub @ new_sub);
	return false;
}
bool AAGP_Pawn::removeAsSubordinate()
{
	if (Leader == nullptr)
	{
		return false;
	}
	else
	{
		return Leader->removeSubordinate(this);
	}
}
bool AAGP_Pawn::removeSubordinate(AAGP_Pawn* Remove)
{
	int32 i = 0;
	int32 j = 0;
	bool Found;
	Found=false;
	j=0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] != Remove)
		{
			Subordinate[j]=Subordinate[i];
			j ++;
		}
		else
		{
			Found=true;
		}
	}
	if (Found)
	{
		nSubordinates --;
	}
	else
	{
		//DebugLog(DEBUG_Team,Remove @ "could not be found in" @ Self);
	}
	return Found;
}

void AAGP_Pawn::addSubordinate(AAGP_Pawn* Add)
{
	/*
	Add.Leader=Self;
	Subordinate[nSubordinates]=Add;
	nSubordinates ++;
	*/
}

void AAGP_Pawn::SetCurrentFFMonitor(UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_FriendlyFireMonitor= nullptr;
		UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::SetCurrentFFMonitor(None)"));
	}
	else
	{
		//DebugLog(DEBUG_Multi,"AGP_Pawn::SetCurrentFFMonitor(" + mon.Name + ")");
		_FriendlyFireMonitor=mon;
	}
}

void AAGP_Pawn::SetCurrentFireMonitor(UScriptObject* mon)
{
	if (mon == nullptr)
	{
		_FireMonitor= nullptr;
		UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn::SetCurrentFireMonitor(None)"));
	}
	else
	{
		//DebugLog(DEBUG_Multi,"AGP_Pawn::SetCurrentFireMonitor(" + mon.Name + ")");
		_FireMonitor=mon;
	}
}

bool AAGP_Pawn::CommoCanHandSignal()
{
	if (bIsProne)
	{
		return false;
	}
	else
	{
		if (Weapon != nullptr && Weapon->IsA(ARocketWeapon::StaticClass()))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

/* ======================================================================================
 * AGP function CommoCycleState
 * Cycles to the next available commo state.  For radio, the function checks
 * if the player has radio access.
 * effects: changes current CommoState
 * last modified by:  capps 1/2/02
 * ======================================================================================
 */
void AAGP_Pawn::CommoCycleState()
{
	switch (CommoState)
	{
	case ECommoType::COMMOTYPE_Hand:		CommoState = ECommoType::COMMOTYPE_Whisper;		break;
	case ECommoType::COMMOTYPE_Whisper: 	CommoState = ECommoType::COMMOTYPE_Shout;			break;
	case ECommoType::COMMOTYPE_Shout:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Radio;
		}
		break;
	case ECommoType::COMMOTYPE_Radio:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else if (PlayerReplicationInfo->IsSquadLeader() && !PlayerReplicationInfo->bGuerrillaPS)
		{
			CommoState = ECommoType::COMMOTYPE_Squad;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Global;
		}
		break;
	case ECommoType::COMMOTYPE_Squad:
		if (ENetMode::NM_Standalone)
		{
			CommoState = ECommoType::COMMOTYPE_Hand;
		}
		else
		{
			CommoState = ECommoType::COMMOTYPE_Global;
		}
		break;
	case ECommoType::COMMOTYPE_Global:
		CommoState = ECommoType::COMMOTYPE_Hand;
		break;
	default:
		//DebugLog(DEBUG_Warn, "AGP_Pawn::CommoCycleState() Unknown CommoState("@CommoState@")");
		CommoState = ECommoType::COMMOTYPE_Global;
		break;
	}
	/*
	if (CommoState == ECommoType::COMMOTYPE_Hand && !CommoCanHandSignal())
	{
		CommoState = ECommoType::COMMOTYPE_Whisper;
	}
	*/
}

void AAGP_Pawn::SetCommoState(ECommoType Type)
{

	switch(Type)
	{
		case ECommoType::COMMOTYPE_Hand:
			/*
			if(!CommoCanHandSignal())	return;
			else						break;
			*/
		case ECommoType::COMMOTYPE_Squad:
			if(!PlayerReplicationInfo->IsSquadLeader())	return;
			else										break;
	}

	CommoState = Type;
}

/* ======================================================================================
 * AGP function SetCurrentVolumeMonitor
 *
 * effects:  sets the volume monitor for the pawn
 * last modified by:  mpr
 * ======================================================================================
 */

void AAGP_Pawn::SetCurrentVolumeMonitor(UScriptObject* vol)
{
	if (vol == nullptr)
	{
		_VolumeMonitor= nullptr;
	}
	else
	{
		_VolumeMonitor=vol;
	}
}

/* ======================================================================================
 * AGP function SetCurrentVolume
 *
 * effects:  sets the volume the pawn is in
 * last modified by:  mpr
 * ======================================================================================
 */

void AAGP_Pawn::SetCurrentVolume(AVolume* vol)
{
	if (vol == nullptr)
	{
		_CurrentVolume = nullptr;
		//		Log("AGP_Pawn::SetCurrentVolume(None)");
	}
	else
	{
		_CurrentVolume = nullptr;
		//		Log("AGP_Pawn::SetCurrentVolume(" + vol.tag + ")");
	}

	if (_VolumeMonitor != nullptr)
	{
		if (vol != nullptr)
		{
			//			Log("AGP_Pawn::SetCurrentVolume(" + vol.tag + ") - calling _VolumeMonitor.Update()");
		}
		_VolumeMonitor->update();
	}
}

AVolume* AAGP_Pawn::GetCurrentVolume()
{
	return _CurrentVolume;
}

void AAGP_Pawn::EnterVolume(AVolume* vol)
{
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != nullptr)
	{
		//Controller->EnterVolume(vol);
	}
	if (vol == nullptr)
	{
		return;
	}
	SetCurrentVolume(vol);
}

void AAGP_Pawn::ExitVolume(AVolume* vol)
{
	if (GetNetMode() == ENetMode::NM_Standalone && Controller != nullptr)
	{
		//Controller.ExitVolume(vol);
	}
	if (vol == nullptr)
	{
		return;
	}
	if (_CurrentVolume == vol)
	{
		SetCurrentVolume(nullptr);
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor(UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor= nullptr;
	}
	else
	{
		_TriggerMonitor=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor2(UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor2= nullptr;
	}
	else
	{
		_TriggerMonitor2=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor3(UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor3= nullptr;
	}
	else
	{
		_TriggerMonitor3=trig;
	}
}

void AAGP_Pawn::SetCurrentTriggerMonitor4(UScriptObject* trig)
{
	if (trig == nullptr)
	{
		_TriggerMonitor4= nullptr;
	}
	else
	{
		_TriggerMonitor4=trig;
	}
}

void AAGP_Pawn::SetCurrentTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		_CurrentTrigger=nullptr;
	}
	else
	{
		_CurrentTrigger=trig;
		//DebugLog(DEBUG_Stats,"AGP_Pawn::SetCurrentTrigger(" + trig.Tag + ")");
	}
	if (_TriggerMonitor != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor->update();
		}
	}
	if (_TriggerMonitor2 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor2->update();
		}
	}
	if (_TriggerMonitor3 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor3->update();
		}
	}
	if (_TriggerMonitor4 != nullptr)
	{
		if (trig != nullptr)
		{
			_TriggerMonitor4->update();
		}
	}
}
AActor* AAGP_Pawn::GetCurrentTrigger()
{
	return _CurrentTrigger;
}
void AAGP_Pawn::EnterTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		return;
	}
	SetCurrentTrigger(trig);
}

void AAGP_Pawn::ExitTrigger(AActor* trig)
{
	if (trig == nullptr)
	{
		return;
	}
	if (_CurrentTrigger == trig)
	{
		SetCurrentTrigger(nullptr);
	}
}

void AAGP_Pawn::SetAnimationMonitor(AAnimationController* AM)
{
	_AnimationMonitor=AM;
}

void AAGP_Pawn::SetAmmoMonitor(UScriptObject* monitor, bool weaponly)
{
	AInventory* Item = nullptr;
	if (Cast<AAGP_Weapon>(Weapon) != nullptr)
	{
		/*
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetAmmoMonitor Tracking ammo in gun");
		}
		*/
		Cast<AAGP_Weapon>(Weapon)->SetAmmoMonitor(monitor);
	}
	if (!weaponly)
	{
		//Item=_InvShoulder->getFirstItem();
		if (Cast<AAGP_Weapon>(Item) != nullptr)
		{
			Cast<AAGP_Weapon>(Item)->SetAmmoMonitor(monitor);
		}
		/*
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetAmmoMonitor tracking shoulder.");
		}
		*/
	}
}

void AAGP_Pawn::SetJammedMonitor(UScriptObject* monitor)
{
	if (Cast<AAGP_Weapon>(Weapon) != nullptr)
	{
		/*
		if (Level.debugScreenplay)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::SetJammedMonitor  Tracking gun jams");
		}
		*/
		Cast<AAGP_Weapon>(Weapon)->SetJammedMonitor(monitor);
	}
}

void AAGP_Pawn::InduceJam()
{
	//AGP_Weapon(Weapon).ClientHandleMisfire();
}

bool AAGP_Pawn::IsOutOfAmmo(bool weaponly)
{
	AInventory* Item = nullptr;
	AWeapon* Gun = nullptr;
	/*
	DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  called with argument weapononly=" + weaponly);
	if (weaponly)
	{
		if (Weapon == nullptr)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, but no weapon.");
			return true;
		}
		if (Weapon.GetCurrentAmmoType() == nullptr)
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, but no magazine in weapon.");
			return true;
		}
		if (Weapon.GetCurrentAmmoType().HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, magazine has ammo.");
			return false;
		}
		else
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Test weaponly, magazine is empty.");
			return true;
		}
	}
	if (Weapon != nullptr)
	{
		if (Weapon.HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; weapon has ammo.");
			return false;
		}
	}
	Item=_InvShoulder.getFirstItem();
	if (Item != nullptr && Item->IsA(AWeapon::StaticClass()))
	{
		Gun=Weapon(Item);
		if (Gun.HasAmmo())
		{
			DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; weapon on shoulder has ammo.");
			return false;
		}
	}
	DebugLog(DEBUG_Inv,"AGP_Pawn::IsOutOfAmmo  Check anywhere; found no ammo in hand or shoulder weapon.");
	*/
	return true;
}

int32 AAGP_Pawn::getBestAmmoFromWeapon(AWeapon* weap, AAmmunition* AmmoName)
{
	//return FMath::Max(weap.AmmoType.AmmoAmount,weap.GetClipCount(weap.GetBestClip()));
	return 0;   //FAKE /EliZ
}

void AAGP_Pawn::CombatEffectivenessEvent(ECombatEffectEvent Event, float DeltaTime)
{
	if(GetNetMode()==ENetMode::NM_Client)
	{
		return;
	}
	switch(Event)
	{
		case ECombatEffectEvent::CE_EVENT_BULLETWHIP:
			CE_RecoveryPenalty *= 0.85;
			CE_PanicValue += 1;
			break;
		case ECombatEffectEvent::CE_EVENT_BULLETCRACK:
			CE_RecoveryPenalty *= 0.75;
			CE_PanicValue += 0.75;
			break;
		case ECombatEffectEvent::CE_EVENT_FLASHBANG:
			CE_RecoveryPenalty *= UKismetMathLibrary::FMax(1 - DeltaTime,0.001);
			CE_PanicValue += 1;
			break;
		case ECombatEffectEvent::CE_EVENT_OBJECTIVE:
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_SUPPORTING:
			break;
		case ECombatEffectEvent::CE_EVENT_CLIMBING:
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_EXPLOSION:
			CE_PanicValue += 0.75;
			break;
		case ECombatEffectEvent::CE_EVENT_SPRINT:
			CE_RecoveryPenalty= UKismetMathLibrary::FMax(CE_RecoveryPenalty * (DeltaTime / (DeltaTime + 0.000008)), 0.001);
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_JUMP:
			CE_RecoveryPenalty *= 0.5;
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_DIVE:
			CE_RecoveryPenalty *= 0.5;
			CE_ActivityValue=0;
			break;
		case ECombatEffectEvent::CE_EVENT_INJURY:
		case ECombatEffectEvent::CE_EVENT_BLEEDING:
			break;
		default:
			break;
	}
}

float AAGP_Pawn::GetPostureComponent()
{
	float Result;
	if (bIsProne)
	{
		Result=0.25;					// Prone
	}
	else
	{
		if (bIsCrouched)
		{
			Result=0.09;			// Crouched
		}
		else
		{
			if (Weapon != nullptr && Cast<AWeapon>(Weapon)->CheckJavelinTube())
			{
				return 0;
			}
			else
			{
				Result=0;
			}
		}
	}
	if (IsZoomed())				// Unzoomed Penalty
	{
		Result += 0.7;
	}
	if (IsSupported())
	{
		Result += 0.45;			// Supported
	}
	if (IsLeaning())
	{
		Result *= 0.9;
	}
	if (Result >= 1)
	{
		Result = 1;
	}
	return Result;
}
float AAGP_Pawn::GetWeapEffectivenessComponent()
{
	float Result = 0;
	/*
	if (Controller != nullptr && Controller.bNoWeaponPenalty)
	{
		return 1;
	}
	if (Cast<AAGP_Weapon>(Weapon) == nullptr)
	{
		return 0;
	}
	if (Cast<AAGP_Weapon>(Weapon).IsOpFor() && ! bGuerrillaMesh)
	{
		Result=0;
	}
	else
	{
		if (! Weapon.bGuerrillaWeapon && bGuerrillaMesh)
		{
			Result=0;
		}
		else
		{
			Result=1;
		}
	}
	*/
	return Result;
}

float AAGP_Pawn::GetFriendlyMorale(float TMBonusRadius)
{
	int32 i = 0;
	/*
	for (i=0; i<32; i++)
	{
		if (PlayerReplicationInfo != nullptr && PlayerReplicationInfo.Team != nullptr)
		{
			if (PlayerReplicationInfo.Team.TeamList[i] != nullptr && PlayerReplicationInfo.Team.TeamList[i] != PlayerReplicationInfo)
			{
				if (VSize(PlayerReplicationInfo.Team.TeamList[i].GetPawnLocation() - Location) <= TMBonusRadius)
				{
					return 0.5;
				}
			}
		}
	}
	*/
	return 0;
}

float AAGP_Pawn::GetMoraleComponent()
{
	AAA2_PlayerState* FTL = nullptr;
	AAA2_PlayerState* SQL = nullptr;
	SQL=PlayerReplicationInfo->GetSquadLeader();
	FTL=PlayerReplicationInfo->GetFTLeader();
	/*
	if (PlayerReplicationInfo != SQL && PlayerReplicationInfo.LinkedToSquadLeader)
	{
		return 1;
	}
	else
	{
		if (PlayerReplicationInfo != SQL && PlayerReplicationInfo != FTL && PlayerReplicationInfo.LinkedToFTLeader)
		{
			return 0.8;
		}
		else
		{
			if (PlayerReplicationInfo.LinkedTo != 0)
			{
				return 0.5;
			}
			else
			{
				return 0;
			}
		}
	}
	*/
	return 0;    //FAKE  /ELiZ
}

float AAGP_Pawn::GetPanicComponent()
{
	float Result = 0;
	/*
	Result=FClamp(CE_PanicValue,0,1);
	Result=1 - Result;
	*/
	return Result;
}

float AAGP_Pawn::GetHealthSubcomponent()
{
	float Result = 0;
	float MaxHealthPenalty = 0;
	MaxHealthPenalty = 0.35;
	/*
	Result=Health / 100 * MaxHealthPenalty;
	Result=FClamp(Result + 1 - MaxHealthPenalty,0,1);
	*/
	return Result;
}

float AAGP_Pawn::GetBleedingSubcomponent()
{
	float Result = 0;
	float MaxBleedPenalty = 0;
	MaxBleedPenalty=0.15;
	/*
	if (IsBleeding() && Level.GamePlayMode != 1)
	{
		Result=- MaxBleedPenalty;
	}
	*/
	return Result;
}

float AAGP_Pawn::GetInjuryFactor()
{
	float Result = 0;
	/*
	Result=GetHealthSubcomponent() + GetBleedingSubcomponent();
	Result=FClamp(Result,0,1);
	*/
	return Result;
}
float AAGP_Pawn::GetMovementFactor()
{
	/*
	
	float Result;
	if (FVector::IsZero(Velocity))
	{
		Result=1;
	}
	else
	{
		if (bIsWalking)
		{
			Result=0.9;
		}
		else
		{
			Result=0.7;
		}
	}
	return Result;
	*/
	return 0;    //FAKE /ELiZ
}

float AAGP_Pawn::GetWeapQualifyFactor()
{
	float Result = 0;
	/*
	if (! PlayerReplicationInfo.bQualifiedSniper && Weapon != nullptr && Weapon->IsA(ASniperRifle::StaticClass()) && GetNetMode() != ENetMode::NM_Standalone)
	{
		Result=0.75;
	}
	else
	{
		Result=1;
	}
	*/
	return Result;
}

float AAGP_Pawn::GetActivityFlag()
{
	float Result;
	Result=CE_ActivityValue;
	return Result;
}
void AAGP_Pawn::RecoveryTick(float DeltaTime)
{
	/*
	CE_RecoveryPenalty=FClamp(CE_RecoveryPenalty,0.18,1);
	CE_PanicValue=FClamp(CE_PanicValue,0,1);
	if (Cast<AHumanController>(Controller) == nullptr || Cast<AHumanController>(Controller)->_FlashSoundTime <= 0 && Cast<AHumanController>(Controller)->_GrenadeShakeTime <= 0)
	{
		CE_PanicValue=FMax(CE_PanicValue - 0.45 * CE_RecoveryPenalty * DeltaTime,0);
	}
	if (! bIsSprinting && ! IsBusy() && ! PressingAction() && Physics == 1)
	{
		if (Weapon == nullptr || ! Weapon.IsBusy() || Weapon.IsTempBusy())
		{
			CE_ActivityValue=FMax(CE_ActivityValue - 0.5 * DeltaTime,0);
			if (CE_MeterValue == CE_DesiredValue)
			{
				CE_RecoveryPenalty=FMin(CE_RecoveryPenalty + 0.075 * DeltaTime,1);
			}
		}
		else
		{
			CE_ActivityValue=FMax(CE_ActivityValue - 0.1 * DeltaTime,0);
			if (CE_MeterValue == CE_DesiredValue)
			{
				CE_RecoveryPenalty=FMin(CE_RecoveryPenalty + 0.025 * DeltaTime,1);
			}
		}
	}
	if (CE_DesiredValue < CE_MeterValue)
	{
		CE_MeterValue=FMax(CE_MeterValue - DeltaTime,CE_DesiredValue);
	}
	else
	{
		CE_MeterValue=FMin(CE_MeterValue + 0.75 * DeltaTime * CE_RecoveryPenalty,CE_DesiredValue);
	}
	*/
}

void AAGP_Pawn::UpdateCombatEffectiveness(float DeltaTime)
{
	float COEFF_Pos = 0;
	float COEFF_Wea = 0;
	float COEFF_Mor = 0;
	float COEFF_Pan = 0;
	float COMP_Posture = 0;
	float COMP_WeapEffectiveness = 0;
	float COMP_Morale = 0;
	float COMP_Panic = 0;
	float FACT_Injury = 0;
	float FACT_Movement = 0;
	float FACT_WeapQualify = 0;
	float FLAG_Activity = 0;
	float OldMeterValue = 0;
	float CEMWhenActive = 0;
	if (GetNetMode() == ENetMode::NM_Client || PlayerReplicationInfo == nullptr)
	{
		return;
	}
	OldMeterValue=CE_MeterValue;
	CEMWhenActive=0.1;
	COEFF_Pos=0.71;
	COEFF_Wea=0.07;
	COEFF_Mor=0.13;
	COEFF_Pan=0.09;
	COMP_Posture=GetPostureComponent();
	COMP_WeapEffectiveness=GetWeapEffectivenessComponent();
	COMP_Morale=GetMoraleComponent();
	COMP_Panic=GetPanicComponent();
	FACT_Injury=GetInjuryFactor();
	FACT_Movement=GetMovementFactor();
	FACT_WeapQualify=GetWeapQualifyFactor();
	FLAG_Activity=GetActivityFlag();
	/*
	if (FLAG_Activity > 0)
	{
		CE_DesiredValue=CEMWhenActive;
	}
	else
	{
		CE_DesiredValue=COEFF_Pos * COMP_Posture + COEFF_Wea * COMP_WeapEffectiveness + COEFF_Mor * COMP_Morale + COEFF_Pan * COMP_Panic;
		CE_DesiredValue *= FACT_Injury * FACT_Movement * FACT_WeapQualify;
	}
	CE_DesiredValue=FClamp(CE_DesiredValue,0,1);
	if (FLAG_Activity > 0)
	{
		CE_MaxMeterValue=CEMWhenActive;
	}
	else
	{
		CE_MaxMeterValue=COEFF_Pos * COMP_Posture + COEFF_Wea * COMP_WeapEffectiveness + COEFF_Mor * COMP_Morale + COEFF_Pan * 1;
		CE_MaxMeterValue *= GetHealthSubcomponent() * FACT_WeapQualify;
	}
	RecoveryTick(DeltaTime);
	*/
}
bool AAGP_Pawn::IsSniperClass(APawn* p)
{
	
	if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_M82_Sniper::StaticClass()))
	{
		return true;
	}
	else
	{
		if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_M24_Sniper::StaticClass()))
		{
			return true;
		}
		else
		{
			if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_MosinNagant_Sniper::StaticClass()))
			{
				return true;
			}
			else
			{
				if (Cast<AAGP_Pawn>(p)->Weapon->IsA(AWeapon_SVD_Sniper::StaticClass()))
				{
					return true;
				}
			}
		}
	}
	return false;
}

float AAGP_Pawn::infront(FVector vec, APawn* Who)
{
	FVector LookDir = FVector(0,0,0);
	FVector AimDir = FVector(0, 0, 0);
	/*
	LookDir= Vector(Who.Rotation);
	LookDir=Normal(LookDir);
	AimDir=vec - Who.Location;
	AimDir=Normal(AimDir);
	return LookDir Dot AimDir;
	*/
	return 0;    //FAKE   /EliZ
}

void AAGP_Pawn::StealthBlend(float DeltaTime)
{
	APawn* p = nullptr;
	int32 TeamNum = 0;
	AAA2_PlayerState* aPRI = nullptr;
	float fSniperVisibilityProbability = 0;
	AHumanController* HC = nullptr;
	/*
	return;
	HC=Cast<AHumanController>(Controller);
	if (HC == nullptr)
	{
		return;
	}
	ForEach DynamicActors(Class'Pawn',p)
	{
		if (p->IsA(AHumanController::StaticClass()) || p->IsA(ANPC_soldier::StaticClass()))
		{
			aPRI=p.Controller.PlayerReplicationInfo;
			TeamNum=aPRI.Team.TeamIndex;
			if (TeamNum == PlayerReplicationInfo.Team.TeamIndex)
			{
				p.Controller.iAlpha=0;
				Cast<AAGP_Pawn>(p).fStealthBlendTime=0;
			}
			else
			{
				if (! IsSniperClass(p))
				{
					p.Controller.iAlpha=0;
					Cast<AAGP_Pawn>(p).fStealthBlendTime=0;
				}
				else
				{
					if (p.bIsSprinting && p.IsBusy() && Cast<AAGP_Pawn>(p).PressingAction() && ! p.FVector::IsZero(Velocity))
					{
						Cast<AAGP_Pawn>(p).fStealthBlendTime=0;
						p.iAlpha=0;
					}
					else
					{
						Cast<AAGP_Pawn>(p).fStealthBlendTime=Cast<AAGP_Pawn>(p).fStealthBlendTime + DeltaTime;
					}
					if (Cast<AAGP_Pawn>(p).fStealthBlendTime == 0)
					{
					}
					else
					{
						if (Cast<AAGP_Pawn>(p).fStealthBlendTime > 60)
						{
							Cast<AAGP_Pawn>(p).fStealthBlendTime=60;
						}
						fSniperVisibilityProbability=1;
						if (bIsSprinting && IsBusy() && PressingAction() && FVector::IsZero(Velocity))
						{
							fSniperVisibilityProbability=fSniperVisibilityProbability * 1.4;
						}
						if (Weapon == nullptr || ! Weapon.IsBusy() || Weapon.IsTempBusy())
						{
							fSniperVisibilityProbability=fSniperVisibilityProbability * 1.8;
						}
						if (fSniperVisibilityProbability > 1)
						{
							fSniperVisibilityProbability=1;
						}
						fSniperVisibilityProbability=fSniperVisibilityProbability * 255;
						fSniperVisibilityProbability=fSniperVisibilityProbability * Cast<AAGP_Pawn>(p).fStealthBlendTime / 60;
						p.iAlpha=255 - fSniperVisibilityProbability;
						if (p.iAlpha > 255)
						{
							p.iAlpha=255;
						}
					}
				}
			}
		}
	}
	*/
}
void AAGP_Pawn::FastTick(float DeltaTime)
{
}

void AAGP_Pawn::Cower(int32 Type)
{
	if (Type == 1)
	{
		//LoopAnim('CivSitPanic',1,0.05);
	}
	else
	{
		//LoopAnim('DocPanic',1,0.05);
	}
}
void AAGP_Pawn::PickIdle(int32 pickOne)
{
	
	if (pickOne == 1)
	{
		//LoopAnim('DocIdleA',1,0.05);
	}
	else
	{
		if (pickOne == 2)
		{
			//LoopAnim('DocIdleB',1,0.05);
		}
		else
		{
			//LoopAnim('DocIdleC',1,0.05);
		}
	}
}
int32 AAGP_Pawn::MoralCheck(float fNPCMoral)
{
	if (fNPCMoral > Health)
	{
		return 0;
	}
	return 1;
}
bool AAGP_Pawn::IsHeDead()
{
	if (Health < 0)
	{
		return true;
	}
	return false;
}
void AAGP_Pawn::SetMoveTarget(AActor* NewTarget)
{
	if (Controller != nullptr)
	{
		//Controller->MoveTarget=NewTarget;
	}
}
void AAGP_Pawn::NPC_Drop2Prone(int32 Type)
{
	if (Type == 1)
	{
		//AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim('Drop2PrnLg',1,0.05,15);
	}
	else
	{
		//AnimBlendParams(13,1,BlendChangeTime,BlendChangeTime);
		//PlayAnim('Drop2PrnNo',1,0.05,15);
	}
}
void AAGP_Pawn::NPC_Reload()
{
	/*
	BeginState();
	EnableChannelNotify(15,1);
	Reload3p(3);
	if (_AnimationMonitor == nullptr)
	{
		AnimBlendParams(15,1,BlendChangeTime,BlendChangeTime,'Spine02');
		if (bIsProne)
		{
			PlayAnim('PrnLgRld',1,0.05,15);
		}
		else
		{
			PlayAnim('StdLgRld',1,0.05,15);
		}
	}
	*/
}
bool AAGP_Pawn::NPC_isGotBuzzed()
{
	if (bGotBulletBuzzed == true)
	{
		bGotBulletBuzzed=false;
		return true;
	}
	return false;
}
int32 AAGP_Pawn::NPC_ActorType()
{
	switch (Actor_t)
	{
		case EATypes::NPC_none:
			return 0;
		case EATypes::NPC_civilian:
			return 1;
		case EATypes::NPC_soldier:
			return 2;
		case EATypes::NPC_doctor:
			return 3;
		case EATypes::NPC_pilot:
			return 4;
		case EATypes::NPC_friendly:
			return 5;
		case EATypes::NPC_squad:
			return 6;
		default:
			return 0;
	}
	return 0;
}
void AAGP_Pawn::NPC_Serpentine(float SerpTime)
{
	//SerpentineTime=SerpTime;
}
FRotator AAGP_Pawn::SwapAxes(FRotator R)
{
	FRotator t;
	t=R;
	R.Pitch=- t.Yaw;
	R.Yaw=t.Roll;
	R.Roll=t.Pitch;
	return R;
}

void AAGP_Pawn::EyeTrack()
{
	ANPCRealHeroController* RHController = nullptr;
	FVector RHAdjustment = FVector(0,0,0);
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	FRotator LEyeRot = FRotator(0, 0, 0);
	FRotator REyeRot = FRotator(0, 0, 0);
	FRotator NeckRot = FRotator(0, 0, 0);
	float Dot = 0;
	FRotator Dir = FRotator(0, 0, 0);
	FRotator RDir = FRotator(0, 0, 0);
	FVector pos = FVector(0, 0, 0);
	float fyaw = 0;
	/*
	HController=Cast<AHumanController>(Level.GetClientController());
	Player=Cast<AAGP_Pawn>(Level.GetClientPawn());
	RHController=NPCRealHeroController(Controller);
	if (RHController != nullptr)
	{
		RHAdjustment.Z=RHController.fpVertCollisionOffsetDown;
	}
	if (HController == nullptr || Player == nullptr || ! bEyeTrack)
	{
		return;
	}
	LookDir= Vector(Rotation);
	LookDir=Normal(LookDir);
	AimDir=Player.Location - Location;
	AimDir=Normal(AimDir);
	Dot=LookDir Dot AimDir;
	if (Dot > 0.6)
	{
		NeckRot=GetBoneRotation('Neck');
		AimDir=Player.Location - RHAdjustment - Location;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw;
		if (Dot > 0.9)
		{
			fyaw=RDir.Yaw;
			flastYaw=fyaw;
		}
		else
		{
			fyaw=flastYaw;
		}
		RDir=SwapAxes(RDir);
		NeckRot=RDir;
		if (Dot > 0.9)
		{
			SetBoneDirection('Neck',NeckRot);
		}
		pos=GetBoneCoords('BN_LEyeBall').Origin;
		pos.Z=Location.Z;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw + fyaw;
		RDir=SwapAxes(RDir);
		LEyeRot=RDir;
		SetBoneDirection('BN_LEyeBall',LEyeRot);
		pos=GetBoneCoords('BN_REyeBall').Origin;
		pos.Z=Location.Z;
		RDir=AimDir;
		Dir=LookDir;
		RDir.Yaw=RDir.Yaw - Dir.Yaw + fyaw;
		RDir=SwapAxes(RDir);
		REyeRot=RDir;
		SetBoneDirection('BN_REyeBall',REyeRot);
	}
	else
	{
		if (Dot < -0.5)
		{
			RDir=Rotation;
			Dir=LookDir;
			flastYaw=0;
			RDir.Yaw=RDir.Yaw - Dir.Yaw;
			fyaw=RDir.Yaw;
			RDir=SwapAxes(RDir);
			NeckRot=RDir;
			SetBoneDirection('Neck',NeckRot);
			REyeRot=RDir;
			SetBoneDirection('BN_REyeBall',REyeRot);
			LEyeRot=RDir;
			SetBoneDirection('BN_LEyeBall',LEyeRot);
		}
	}
	*/
}

void AAGP_Pawn::NotifyFire(AAGP_Weapon* W, FString Parms)
{
	
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(W,17,Self,Parms);
	}
	
}

void AAGP_Pawn::NotifyTrace(AAGP_Weapon* W, AActor* HitActor, FString Parms)
{
	if (EventLab != nullptr)
	{
		//EventLab.ActorNotify(W,18,HitActor,Parms);
	}
}

void AAGP_Pawn::NotifyThrow(AThrowWeapon* W, FString Parms)
{
	if (EventLab != nullptr)
	{
		//EventLab->ActorNotify(W,19,this,Parms);
	}
}

void AAGP_Pawn::MatchEnding()
{
	
	UE_LOG(LogTemp, Warning, TEXT("AGP_Pawn.MatchEnding() - Hiding pawn"));
	//SetDrawType(0);
	
}

void AAGP_Pawn::DestroyDebugIcons()
{
	/*
	if (MyDebug_InterruptIcon != nullptr)
	{
		MyDebug_InterruptIcon->Destroy();
	}
	if (MyDebug_MentalStateIcon != nullptr)
	{
		MyDebug_MentalStateIcon->Destroy();
	}
	if (MyDebug_ActionIcon != nullptr)
	{
		MyDebug_ActionIcon->Destroy();
	}
	*/
}

void AAGP_Pawn::AttachDebugIcons()
{
	FBoneOffset BO;
	/*
	MyDebug_InterruptIcon=Spawn('DebugIcon_Interrupt');
	MyDebug_ActionIcon=Spawn('DebugIcon_Action');
	MyDebug_MentalStateIcon=Spawn('DebugIcon_MentalState');
	if (MyDebug_MentalStateIcon != nullptr)
	{
		MyDebug_MentalStateIcon.bHidden=false;
		MyDebug_MentalStateIcon.SetDrawScale(1);
		BO.VOffset=FVector(-33 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_MentalStateIcon,BO);
	}
	if (MyDebug_ActionIcon != nullptr)
	{
		MyDebug_ActionIcon.bHidden=false;
		MyDebug_ActionIcon.SetDrawScale(1);
		BO.VOffset=FVector(0 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_ActionIcon,BO);
	}
	if (MyDebug_InterruptIcon != nullptr)
	{
		MyDebug_InterruptIcon.bHidden=false;
		MyDebug_InterruptIcon.SetDrawScale(1);
		BO.VOffset=FVector(33 -56 2);
		BO.ROffset.Roll=-16384;
		BO.nBone='Pelvis';
		AttachToBoneOffset(MyDebug_InterruptIcon,BO);
	}
	*/
}
void AAGP_Pawn::CreateVisualHearingDebugSpheres(float fpHearingDistance, float fpVisualDistance)
{
	UE_LOG(LogTemp, Warning, TEXT("CreateVisualHearingDebugSpheres() entered"));
	if (fpVisualDistance > 0)
	{
		//VisionDistActor=CreateDebugSphere(true);
		//VisionDistActor.SetDrawScale(fpVisualDistance * 1 / 128);
	}
	if (fpHearingDistance > 0)
	{
		//AudioDistActor=CreateDebugSphere(false);
		//AudioDistActor.SetDrawScale(fpHearingDistance * 1 / 128);
	}
}

ADebugSphere* AAGP_Pawn::CreateDebugSphere(bool bVisionSphere)
{
	ADebugSphere* D = nullptr;
	/*
	Log("CreateDebugSphere entered - visionsphere:" + bVisionSphere);
	if (bVisionSphere)
	{
		D=Spawn('DebugSphereVisual');
	}
	else
	{
		D=Spawn('DebugSphereAudio');
	}
	if (D != nullptr)
	{
		D.bHidden=false;
		D.SetDrawScale(1);
		AttachToBone(D,'BN_HeadEnd');
	}
	*/
	return D;
}

void AAGP_Pawn::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(Canvas,YL,YPos);
	Canvas.SetDrawColor(0,128,255);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("Pawn threat level: " + fpPlayerThreatLevel + " adjusted: " + GetThreatLevel());
	YPos += YL;
	Canvas.SetPos(4,YPos);
	*/
}

float AAGP_Pawn::GetThreatLevel()
{
	/*
	if (IsInState('BusyReloading'))
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
	}
	if (Weapon == nullptr)
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.45;
	}
	else
	{
		if (Weapon.IsInState('BusyFixingJam'))
		{
			return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.6;
		}
		else
		{
			if (Weapon.IsInState('BusyReloading'))
			{
				return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
			}
			else
			{
				if (Weapon.IsInState('BusyFiring'))
				{
					return fpPlayerThreatLevel + fpPlayerThreatLevel * 0.25;
				}
				else
				{
					if (Weapon.IsInState('BusySupporting'))
					{
						return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
					}
					else
					{
						if (Weapon.IsInState('BusyChangingFireMode'))
						{
							return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.25;
						}
					}
				}
			}
		}
	}
	if (bHealingInProgress || bLockMovement)
	{
		return fpPlayerThreatLevel - fpPlayerThreatLevel * 0.9;
	}
	*/
	return fpPlayerThreatLevel;
}

void AAGP_Pawn::NPCAlertPlayerEvent()
{
	AController* ctrlrIterator = nullptr;
	if (GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if (! IsHumanControlled())
	{
		return;
	}
	/*
	for (ctrlrIterator = Level.ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator.nextController)
	{
		if (!ctrlrIterator->IsA(ANPCBaseController::StaticClass()))
		{
		}
		NPCBaseController(ctrlrIterator).AddHistoryContact(this, true);
	}
	*/
}

void AAGP_Pawn::AltFire(float F)
{
	if (bIsSprinting)
	{
		if (Cast<AHumanController>(Controller) != nullptr)
		{
			Cast<AHumanController>(Controller)->ClientMessage("You are too busy sprinting to adjust your weapon.");
		}
		return;
	}
	if (Weapon != nullptr)
	{
		Weapon->AltFire(F);
	}
}
bool AAGP_Pawn::isKilledByIED()
{
	return bHitByIED;
}

//myOwn

bool AAGP_Pawn::IsLeaning()
{
	return false;
}

void AAGP_Pawn::Client_Set_Weapon_Implementation(TSubclassOf<ASoldierClass> SC)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		if (SC)
		{
			//auto FreshObject = NewObject<TSubclassOf<ASoldierClass>>(this, SC->GetFName(), RF_NoFlags, SC->GetDefaultObject());
			//TeamClass = FreshObject;

			//Spawing 
			/*
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			ASoldierClass* NewSoldierClass = GetWorld()->SpawnActor<ASoldierClass>(SC, SpawnInfo);
			FString T= Cast<ASoldierClass>(NewSoldierClass)->_ShortName;
			TArray<TSubclassOf<AInventory>> DefaultInventory = Cast<ASoldierClass>(NewSoldierClass)->ClassEquipment;
			*/
			
			if (Mesh_1P!=nullptr)
			{
				Mesh_1P->SetRelativeLocation(FVector(-15.0f, 0.0f, -10.0f));
				Mesh_1P->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
				Mesh_1P->bOnlyOwnerSee = true;
				Mesh_1P->bOwnerNoSee = false;
				Mesh_1P->bCastDynamicShadow = false;
				Mesh_1P->CastShadow = false;
				if(CustomMesh_1P != nullptr)
				{
					Mesh_1P->SetSkeletalMesh(CustomMesh_1P);
				}
				if (Anim_1P != nullptr)
				{
					Mesh_1P->PlayAnimation(Anim_1P, true);
					
				}
			}

			/*
			if (Anim_3P != nullptr)
			{
				Mesh_3P->SetAnimation(Anim_3P);
				Mesh_3P->PlayAnimation(Anim_3P, true);
			}
			*/
			if (Mesh_3P->SkeletalMesh)
			{
				USkeleton* MySkeleton = Mesh_3P->SkeletalMesh->GetSkeleton();
				if (MySkeleton != nullptr)
				{
					TArray<UAnimationAsset*> AllAnimations = GetAllAnimationOfSkeleton(MySkeleton);
					if (AllAnimations.Num() > 0)
					{
						Mesh_3P->PlayAnimation(AllAnimations[0], true);
					}
					else
					{
						if (Anim_3P != nullptr)
						{
							Mesh_3P->PlayAnimation(Anim_3P, true);
						}
					}
				}
			}

		}
	}
}

void AAGP_Pawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(GetLocalRole() == ROLE_Authority)
	{
		//Health = GetMaxHealth();
		//SpawnDefaultInventory();
	}

	// set initial mesh visibility (3rd person view)
	//UpdatePawnMeshes();

	// create material instance for setting team colors (3rd person view)
	//for (int32 iMat = 0; iMat < GetMesh()->GetNumMaterials(); iMat++)
	//{
	//	MeshMIDs.Add(GetMesh()->CreateAndSetMaterialInstanceDynamic(iMat));
	//}

	// play respawn effects
	if (GetNetMode() != NM_DedicatedServer)
	{
		//if (RespawnFX)
		//{
		//	UGameplayStatics::SpawnEmitterAtLocation(this, RespawnFX, GetActorLocation(), GetActorRotation());
		//}
		//if (RespawnSound)
		//{
		//	UGameplayStatics::PlaySoundAtLocation(this, RespawnSound, GetActorLocation());
		//}
	}
}

void AAGP_Pawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAGP_Pawn, Weapon);
	
	//first Person Stuff
	DOREPLIFETIME(AAGP_Pawn, CustomMesh_1P);
	DOREPLIFETIME(AAGP_Pawn, Anim_1P);

	//Third Person Stuff
	DOREPLIFETIME(AAGP_Pawn, Mesh_3P);
	DOREPLIFETIME(AAGP_Pawn, Anim_3P);

	DOREPLIFETIME(AAGP_Pawn, Health);
	DOREPLIFETIME(AAGP_Pawn, TeamClass);

	DOREPLIFETIME(AAGP_Pawn, bIsProne);
	DOREPLIFETIME(AAGP_Pawn, bIsSprinting);
	DOREPLIFETIME(AAGP_Pawn, bIsWalking);
	DOREPLIFETIME(AAGP_Pawn, bIsCrouching);
	DOREPLIFETIME(AAGP_Pawn, bIsCrouched2);

	DOREPLIFETIME(AAGP_Pawn, AGP_Speed);
	DOREPLIFETIME(AAGP_Pawn, AGP_Direction);
}

bool AAGP_Pawn::IsPlayerPawn()
{
	return GetController() != nullptr && Cast<AHumanController>(GetController())->bIsPlayer;
}

bool AAGP_Pawn::IsHumanControlled()
{
	return (Cast<APlayerController>(GetController()) != nullptr);
}

/*
const FString AAGP_Pawn::GetAnimationPath() const
{
	FString FileName = FString::Printf(TEXT("A_Character_Idle_%s.A_Character_Idle_%s"), *AvatarCharacterName, *AvatarCharacterName);
	return FString::Printf(TEXT("%s%s%s%s%s"), *ANIMATION_PATH, *AvatarCharacterName, *F_DLIM, *FileName, *R_DLIM);
}
*/

TArray<UAnimationAsset*> AAGP_Pawn::GetAllAnimationOfSkeleton(USkeleton* Skeleton)
{
	TArray<UAnimationAsset*> AnimsArray;

	if (Skeleton == nullptr) { return AnimsArray; }

	for (TObjectIterator<UAnimationAsset> Itr; Itr; ++Itr)
	{
		if (Skeleton == (*Itr)->GetSkeleton())
		{
			AnimsArray.Add(*Itr);
		}
	}
	return AnimsArray;
}


//native final Function StopLIPSincAnim();
void AAGP_Pawn::StopLIPSincAnim()
{

};

//native final Function bool HasLIPSincAnim(FName LIPSincAnimName);
bool AAGP_Pawn::HasLIPSincAnim(FName LIPSincAnimName)
{
	return false;
};

//native final Function bool IsPlayingLIPSincAnim();
bool AAGP_Pawn::IsPlayingLIPSincAnim()
{
	return false;
};
