// All the original content belonged to the US Army

#include "PSProxy.h"
#include "Components/SceneComponent.h"


APSProxy::APSProxy()
{
	bNoAutoConnect = true;
	bForcedOnly = true;
	
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_NavP.S_NavP'"), NULL, LOAD_None, NULL);

	LoadEditorIconPS();
	this->SetActorScale3D (FVector(2, 2, 2));
}



void APSProxy::LoadEditorIconPS()
{
#if WITH_EDITORONLY_DATA
	bool UBillboardComponentExists = false;

	TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* ThisObject : ObjectArray)
	{
		if (ThisObject->GetName() == "Sprite")
		{
			if (Texture != NULL)
			{
				SpriteComponent = Cast<UBillboardComponent>(ThisObject);
				SpriteComponent->Sprite = Texture;
				
				UBillboardComponentExists = true;
			}
		}
	}
	if (!UBillboardComponentExists)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
		SpriteComponent->Sprite = Texture;
		SpriteComponent->SetRelativeScale3D(FVector(1, 1, 1));

		//Class
		SpriteComponentClass = CreateDefaultSubobject<UBillboardComponent>(TEXT("ClassSprite"));
		SpriteComponentClass->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/R.R'"), NULL, LOAD_None, NULL);
		SpriteComponentClass->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
		SpriteComponentClass->SetRelativeLocation(FVector(0, 2, 0));
		SpriteComponentClass->AttachToComponent(SpriteComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

		//What FireTeam
		SpriteComponentFT = CreateDefaultSubobject<UBillboardComponent>(TEXT("FTSprite"));
		SpriteComponentFT->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/FTAlpha.FTAlpha'"), NULL, LOAD_None, NULL);
		//SpriteComponentFT->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/FTBravo.FTBravo'"), NULL, LOAD_None, NULL);
		//SpriteComponentFT->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/FTCharlie.FTCharlie'"), NULL, LOAD_None, NULL);
		//SpriteComponentFT->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/FTDelta.FTDelta'"), NULL, LOAD_None, NULL);
		SpriteComponentFT->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
		SpriteComponentFT->SetRelativeLocation(FVector(-18, 4.0, -18));
		SpriteComponentFT->AttachToComponent(SpriteComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

		//What Team
		SpriteComponentTeam = CreateDefaultSubobject<UBillboardComponent>(TEXT("TeamSprite"));
		SpriteComponentTeam->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/Team0.Team0'"), NULL, LOAD_None, NULL);;
		//SpriteComponentTeam->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/Team0.Team0'"), NULL, LOAD_None, NULL);;
		SpriteComponentTeam->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
		SpriteComponentTeam->SetRelativeLocation(FVector(18, 6.0, 18));
		SpriteComponentTeam->AttachToComponent(SpriteComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

		//Fire Team Leader
		SpriteComponentFTL = CreateDefaultSubobject<UBillboardComponent>(TEXT("FTLSprite"));
		SpriteComponentFTL->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/FTLeader.FTLeader'"), NULL, LOAD_None, NULL);;
		SpriteComponentFTL->SetRelativeScale3D(FVector(0.40, 0.40, 0.40));
		SpriteComponentFTL->SetRelativeLocation(FVector(-20, 8.0, -12));
		SpriteComponentFTL->AttachToComponent(SpriteComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

		//Squad Leader
		SpriteComponentSL = CreateDefaultSubobject<UBillboardComponent>(TEXT("SLSprite"));
		SpriteComponentSL->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/SquadLeader.SquadLeader'"), NULL, LOAD_None, NULL);;
		SpriteComponentSL->SetRelativeScale3D(FVector(0.50, 0.50, 0.50));
		SpriteComponentSL->SetRelativeLocation(FVector(-18, 10.0, 18));
		SpriteComponentSL->AttachToComponent(SpriteComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);




		if (GetWorld())
		{
			SpriteComponentClass->RegisterComponent();
			SpriteComponentTeam->RegisterComponent();
			SpriteComponentFT->RegisterComponent();
			SpriteComponentFTL->RegisterComponent();
			SpriteComponentSL->RegisterComponent();
		}



	}
#endif // WITH_EDITORONLY_DATA
}