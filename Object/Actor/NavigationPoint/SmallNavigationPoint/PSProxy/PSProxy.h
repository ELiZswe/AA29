// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"

#include "PSProxy.generated.h"

class APlayerStart;

UCLASS()
class APSProxy : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	APSProxy();
	
	UPROPERTY(EditAnywhere, Category = "Proxy")					FName SetTag;				//var(Proxy) name SetTag;
	UPROPERTY(EditAnywhere, Category = "Proxy")					FName ProxyTag;				//var(Proxy) name ProxyTag;
	UPROPERTY()																		APlayerStart* PS;			//var const PlayerStart PS;

	void FindPlayerStart();
	void BeginPlay();

// Sprite Component
	class UBillboardComponent* SpriteComponent;
	class UBillboardComponent* SpriteComponentClass;
	class UBillboardComponent* SpriteComponentFT;
	class UBillboardComponent* SpriteComponentTeam;
	class UBillboardComponent* SpriteComponentFTL;
	class UBillboardComponent* SpriteComponentSL;

	

	virtual void LoadEditorIconPS();
};
