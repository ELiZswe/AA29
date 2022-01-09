// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"
#include "PSSet.generated.h"

UCLASS()
class APSSet : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APSSet();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Proxy")		bool	bUseAsDefault;				//var(Proxy) bool bUseAsDefault;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Proxy")		TArray<FName> RestrictedEnemySets;	//var(Proxy) array<name> RestrictedEnemySets;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Proxy")		FName	RequiredEnemySet;			//var(Proxy) name RequiredEnemySet;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Proxy")		FName	SetTag;						//var(Proxy) name SetTag;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Proxy")		uint8	Team;						//var(Proxy) byte Team;


// Sprite Component
	class UBillboardComponent* SpriteComponent;

	// Icon sprite
	UPROPERTY(EditAnywhere)		UTexture2D* Texture;

	virtual void LoadEditorIcon();
};
