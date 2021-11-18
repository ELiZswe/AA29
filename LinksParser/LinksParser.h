// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinksParser.generated.h"

UCLASS()
class AA29_API ALinksParser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALinksParser();

	UPROPERTY()											TArray<FSection> Sections;							//var array<Section> Sections;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	void Init(FString FilePath);
	void GetHeaders(FString FilePath);
	void GetSections(FString FilePath);
	int32 GetHeaderIndex(FString Header);
	int32 GetIDIndex(FString Id);



};
