// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_Parachute::AAttch_Parachute()
{

	sParachuteOpenSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachuteopen_Cue.parachuteopen_Cue'"), NULL, LOAD_None, NULL);
	sParachuteFlutterSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachutefluttering_Cue.parachutefluttering_Cue'"), NULL, LOAD_None, NULL);
	sParachuteCollapseSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachuteopen_Cue.parachuteopen_Cue'"), NULL, LOAD_None, NULL);
	bStartScaleDeploy = true;
	PrevAnimState = 255;
	DrawType = EDrawType::DT_None;
	bOrientOnSlope = true;
	//bReplicateInstigator = true;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Objects/Parachute.Parachute'"), NULL, LOAD_None, NULL);
	RelativeRotation = FRotator(-16384, 0, 0);
	DrawScale3D = FVector(0.1, 0.1, 0.1);
	//bCollideActors = true;
	//bCollideWorld = true;
	ParaItems.SetNum(2);
}

/*
State PendingCCSPA
{
	simulated Function Timer()
	{
		if (Cast<APawn>(GetOwner()) != nullptr)
		{
			CreateClientSideParachuteAttachments();
		}
	}
	simulated Function BeginState()
	{
		SetTimer(0.05,true);
	}
	simulated Function EndState()
	{
		SetTimer(0,false);
	}
}
*/


/*
replication
{
	reliable if ((Role == ROLE_Authority))
		bNoInstigator;
}
*/

void AAttch_Parachute::NotifyBaseChange()
{
}

void AAttch_Parachute::SetMesh()
{
}

UStaticMesh* AAttch_Parachute::GetStaticMesh(bool bFriendly)
{
	return nullptr;    //FAKE   /ELiZ
}

void AAttch_Parachute::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		CreateClientSideParachuteAttachments();
	}
}

void AAttch_Parachute::Destroyed()
{
	int32 i = 0;
	for (i = 0; i < 2; i++)
	{
		if (ParaItems[i] != nullptr)
		{
			ParaItems[i]->Destroy();
		}
	}
	Super::Destroyed();
}

void AAttch_Parachute::CreateClientSideParachuteAttachments()
{
	FString PI_Name = "";
	int32 i = 0;
	FRotator R = FRotator(0, 0, 0);
	AItemAttachment* PI_Class = nullptr;
	/*
	Instigator = Cast<APawn>(GetOwner());
	if ((Instigator == nullptr) && (!bNoInstigator))
	{
		GotoState("PendingCCSPA");
		return;
	}
	else
	{
		if (IsInState("PendingCCSPA"))
		{
			SetTimer(0, false);
		}
	}
	R = FRotator(0, 32768, 16384);
	for (i = 0; i < 2; i++)
	{
		if (ParaItems[i] != nullptr)
		{
			ParaItems[i].Destroy();
		}
		switch (i)
		{
		case 0:
			PI_Name = "AGP_Inventory.Attch_ParaRuck";
			break;
		case 1:
			PI_Name = "AGP_Inventory.Attch_ReserveChute";
			break;
		default:
			PI_Name = "";
			break;
		}
		PI_Class = class<ItemAttachment>(DynamicLoadObject(PI_Name, Class'Class'));
		if (PI_Class != nullptr)
		{
			if (bNoInstigator)
			{
				if (i != 0)
				{
					ParaItems[i] = Spawn(PI_Class);
				}
			}
			else
			{
				ParaItems[i] = Spawn(PI_Class, Instigator);
				Instigator.AttachToBone(ParaItems[i], ParaItems[i].Default.AttachBone);
				ParaItems[i].SetRelativeRotation(R);
				ParaItems[i].NotifyBaseChange();
			}
		}
		else
		{
			DebugLog(DEBUG_Warn, "Item_Parachute::CreateClientSideParachuteAttachments()	Unknown name " + PI_Name);
		}
	}
	if (Instigator.FullBodyAnim != 4)
	{
		Log(string(this) @ "Attch_Parachute::CreateClientSideParachuteAttachments Setting Instigator '" + FString::FromInt(Instigator) + "' FullBodyAnim = FBANIM_PARACHUTE_Jump");
		Instigator.FullBodyAnim = 3;
	}
	*/
}

void AAttch_Parachute::HandleClientAttachments()
{
	int32 i = 0;
	for (i = 0; i < 2; i++)
	{
		if (ParaItems[i] != nullptr)
		{
			if (i == 0)
			{
				ParaItems[i]->Destroy();
			}
			else
			{
				if (ParaItems[i]->Base != nullptr)
				{
					//ParaItems[i]->Base->DetachFromBone(ParaItems[i]);
				}
				else
				{
					//DebugLog(DEBUG_Warn, "Attch_Parachute::HandleClientAttachments()	No Base for " @ FString::FromInt(ParaItems[i]));
				}
				//ParaItems[i]->SetPhysics(PHYS_Falling);
			}
		}
	}
}

void AAttch_Parachute::BeginPlay()
{
	Super::BeginPlay();
	//LoopAnim("StillPackRot");
}

FName AAttch_Parachute::GetAttachBoneFor(AInventory* Inv)
{
	return "RuckSack";
}

void AAttch_Parachute::AttachmentAnimation()
{
	if (GetInstigator() != nullptr)
	{
		//GetInstigator()->UpdateParachute(AnimState);
	}
	NotifyNewParachuteState(AnimState);
}

void AAttch_Parachute::NotifyNewParachuteState(int32 NewState)
{
	EDrawType DrawPara = EDrawType::DT_None;
	if (NewState == PrevAnimState)
	{
		return;
	}
	/*
	AnimState = uint8(NewState);
	PrevAnimState = AnimState;
	DrawPara = EDrawType::DT_Mesh;
	switch (NewState)
	{
		case 0:
			DrawPara = 0;
			DebugLog(DEBUG_Warn, "Attach_Parachute::NotifyNewParachuteState()	Entered here with null state " + FString::FromInt(NewState));
			break;
		case 1:
			bStartScaleDeploy = false;
			SetTimer(1, false);
			fScaleDeploy = FVector(0.1, 0.1, 0.1);
			SetDrawScale3D(fScaleDeploy);
			PlayAnim("DeployRot");
			PlayOwnedSound(sParachuteOpenSound, 0, 4, , , , false);
			break;
		case 2:
			SetDrawScale3D(FVector(1, 1, 1));
			LoopAnim("StillOpenRot");
			break;
		case 3:
			SetDrawScale3D(FVector(1, 1, 1));
			PlayAnim("Collapse");
			if (Base != nullptr)
			{
				SetActorLocation(Base.Location);
				Base.DetachFromBone(this);
			}
			SetPhysics(PHYS_Falling);
			SetActorRotation(FRotator(0, 0, 0));
			HandleClientAttachments();
			PlayOwnedSound(sParachuteCollapseSound, 0, 4, , , , false);
			break;
		case 4:
			SetDrawScale3D(FVector(1, 1, 1));
			LoopAnim("StillCollapsed");
			PrepareCleanup();
			break;
		case 5:
			break;
		case 6:
			SetDrawScale3D(FVector(1, 1, 1));
			LoopAnim("PrematureCollapseRot");
			PlayOwnedSound(sParachuteCollapseSound, 0, 4, , , , false);
			break;
		case 7:
			Log(string(this) @ "Attch_Parachute::NotifyNewParachuteState	Got PARACHUTE_ATTACH_RIG message.");
			break;
		default:
			DebugLog(DEBUG_Warn, "Attch_Parachute::NotifyNewParachuteState()	Unknown state " + FString::FromInt(NewState));
			return;
	}
	SetDrawType(DrawPara);
	*/
}

void AAttch_Parachute::PrepareCleanup()
{
	SetOwner(nullptr);
	//Instigator = nullptr;
	bNoInstigator = true;
	//SetTimer(45, false);
}

void AAttch_Parachute::CleanupParachute()
{
	/*
	if (!PlayerCanSeeMe())
	{
		Destroy();
	}
	else
	{
		SetTimer(10, false);
	}
	*/
}

void AAttch_Parachute::Timer()
{
	switch (AnimState)
	{
		case 1:
			if (bStartScaleDeploy == false)
			{
				bStartScaleDeploy = true;
			}
			break;
		case 4:
			CleanupParachute();
			break;
		default:
			break;
	}
}

void AAttch_Parachute::AnimEnd(int32 Channel)
{
	/*
	Super::AnimEnd(Channel);
	if (Instigator != nullptr)
	{
		if (AnimState == 1)
		{
			Instigator.UpdateParachute(2);
		}
		else
		{
			if (AnimState == 3)
			{
				Instigator.UpdateParachute(4);
			}
		}
	}
	*/
}

void AAttch_Parachute::Tick(float DeltaTime)
{
	/*
	if (((AnimState == 1) && (fScaleDeploy.X < 1)) && bStartScaleDeploy)
	{
		SetDrawScale3D(FVector((fScaleDeploy.X += 0.05), (fScaleDeploy.Y += 0.05), (fScaleDeploy.Z += 0.05)));
	}
	if (AnimState == 2)
	{
		(_ParachuteSoundUpdate -= DeltaTime);
		if (_ParachuteSoundUpdate < 0)
		{
			_ParachuteSoundUpdate = GetSoundDuration(sParachuteFlutterSound);
			PlayOwnedSound(sParachuteFlutterSound, 0, 1, , , , false);
		}
	}
	*/
}

FString AAttch_Parachute::DisplayDebugMessage()
{
	FString str = "";
	switch (AnimState)
	{
		case 0:
			str = "None";
			break;
		case 1:
			str = "Deploy";
			break;
		case 2:
			str = "Idle";
			break;
		case 3:
			str = "Collapse";
			break;
		case 4:
			str = "Ground";
			break;
		case 5:
			str = "Flare";
			break;
		case 6:
			str = "Premature";
			break;
		default:
			str = "Error";
			break;
	}
	return str;
}

void AAttch_Parachute::MatchEnding()
{
	Destroy();
}
