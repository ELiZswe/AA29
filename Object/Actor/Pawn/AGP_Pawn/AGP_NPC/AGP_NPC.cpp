// All the original content belonged to the US Army


#include "AGP_NPC.h"

AAGP_NPC::AAGP_NPC()
{
	AnimRate      = 1;
		//bPhysicsAnimUpdate = True
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
	//	bCleanUp = False

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
		Log("Weapon in hand: " $ Weapon);
	}
	*/
}
void AAGP_NPC::DoAnimLoop()
{
	/*
	if (AnimSequence != 'None' && AnimSequence != 'None')
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
	Controller = HumanController(Level.GetClientController());
	Player = AGP_Pawn(Level.GetClientPawn());
	*/
}
FVector AAGP_NPC::LookRotation(FVector LookActorLoc, FVector TargetActorLoc)
{
	return TargetActorLoc - LookActorLoc;
}
void AAGP_NPC::infront(FVector vec, APawn* me)
{
	/*
	FVector LookDir;
	FVector AimDir;

	LookDir = FRotator(me->GetActorRotation());
	LookDir = Normal(LookDir);
	AimDir = vec - me.Location;
	AimDir = Normal(AimDir);
	return LookDir Dot AimDir;
	*/
}
void AAGP_NPC::SetAttachments()
{
	/*
	local int i;
	local Actor Item;
	for (i = 0; i < Attachments.Length; i++)
	{
		Item = Spawn(Attachments[i].Attachment);
		if (Item != None)
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
void TakeDamage(int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (Health <= 0)
	{
		Log(Self $ " TakeDamage entered on already dead pawn!");
		Return;
	}
	if (Controller != None && Controller.IsA('AIController'))
	{
		Log(Self $ " Damage received for Pawn with AI Controller: " $ Damage);
		AIController(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	}
	TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController, ResponsibleActor);
	Return;
}
*/
