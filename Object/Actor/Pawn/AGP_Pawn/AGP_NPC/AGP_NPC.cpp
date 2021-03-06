// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAGP_NPC::AAGP_NPC()
{
	AnimRate      = 1;
		//bPhysicsAnimUpdate = true
		//MovementAnims(0) = "WlkFwNo"
		//MovementAnims(1) = "WlkBkNo"
		//MovementAnims(2) = "WlkLtNo"
		//MovementAnims(3) = "WlkRtNo"
	TurnLeftAnim   = "StdRotLtNo";
	TurnRightAnim  = "StdRotRtNo";
		//MovementAnimRate(0) = 1
		//MovementAnimRate(1) = 1
		//MovementAnimRate(2) = 1
		//MovementAnimRate(3) = 1
	fWalkSpeed     = 160;
	//	bCleanUp = false

	DrawScale     = 1.13;
	LoadMesh();
}

void AAGP_NPC::MatchStarting()
{
	/*
	Log("Match starting");
	DoAnimLoop();
	SetDrawType(EDrawType::DT_Mesh);

	if (NPC_Weapon != nullptr)
	{
		Weapon = Spawn(NPC_Weapon);
		if (Weapon != nullptr)
		{
			Weapon.GiveTo(this);
		}
		Log("Weapon in hand: " + Weapon);
	}
	*/
}

void AAGP_NPC::DoAnimLoop()
{
	/*
	if (AnimSequence != "None" && AnimSequence != "None")
	{
		LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
	*/
}

void AAGP_NPC::PostBeginPlay()
{
	//Super::PostBeginPlay();
	SetAttachments();
}

void AAGP_NPC::InitPlayerRefs()
{
	/*
	Controller = Cast<AHumanController>(Level.GetClientController());
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	*/
}

FRotator AAGP_NPC::LookRotation(FVector LookActorLoc, FVector TargetActorLoc)
{
	//return TargetActorLoc - LookActorLoc;
	return FRotator(0, 0, 0);     //FAKE   /EliZ
}

float AAGP_NPC::infront(FVector vec, APawn* me)
{
	FVector LookDir = FVector(0,0,0);
	FVector AimDir = FVector(0, 0, 0);
	/*
	LookDir = FRotator(me->GetActorRotation());
	LookDir = Normal(LookDir);
	AimDir = vec - me.Location;
	AimDir = Normal(AimDir);
	return LookDir Dot AimDir;
	*/
	return 0;    //FAKE   /ELiZ
}

void AAGP_NPC::SetAttachments()
{
	int32 i = 0;
	AActor* Item = nullptr;
	/*
	for (i = 0; i < Attachments.Num(); i++)
	{
		Item = Spawn(Attachments[i].Attachment);
		if (Item != nullptr)
		{
			AttachToBone(Item, Attachments[i].Bone);
		}
		else
		{
			Log("AGP_NPC::SetAttachments(): ERROR: Item is NONE");
			return;
		}
		Item.SetRelativeLocation(Attachments[i].LocationOffset);
		Item.SetRelativeRotation(Attachments[i].RotationOffset);
		if (Attachments[i].bUseParentScale)
		{
			Item.SetDrawScale(Self.DrawScale);
		}
		else
		{
			if (Attachments[i].Scale == 0)
			{
				Item.SetDrawScale(1);
			}
			else
			{
				Item.SetDrawScale(Attachments[i].Scale);
			}
		}
	}
	*/
}

/*
void AAGP_NPC::TakeDamage(int32 Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (Health <= 0)
	{
		Log(Self + " TakeDamage entered on already dead pawn!");
		return;
	}
	if (Controller != nullptr && Controller->IsA(AaAIController::StaticClass()))
	{
		Log(Self + " Damage received for Pawn with AI Controller: " + Damage);
		Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController, ResponsibleActor);
	return;
}
*/
