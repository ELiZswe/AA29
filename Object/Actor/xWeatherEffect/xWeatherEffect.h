// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "Components/BillboardComponent.h"
#include "xWeatherEffect.generated.h"

UCLASS()
class AA29_API AxWeatherEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AxWeatherEffect();

	UPROPERTY()										TArray<AVolume*> pclBlockers;					//var transient array<Volume> pclBlockers;
	UPROPERTY()										TArray<FWeatherPcl> pcl;						//var transient array<WeatherPcl> pcl;
	UPROPERTY(EditAnywhere)							bool bForceAffected;							//var(Force) bool bForceAffected;
	UPROPERTY(EditAnywhere)							FRange EyeSizeClamp;							//var() Object.Range EyeSizeClamp;
	UPROPERTY(EditAnywhere)							FRange Size;									//var() Object.Range Size;
	UPROPERTY(EditAnywhere)							FRange Life;									//var() Object.Range Life;
	UPROPERTY(EditAnywhere)							FRange Speed;									//var() Object.Range Speed;
	UPROPERTY(EditAnywhere)							FRangeVector Position;							//var() Object.RangeVector Position;
	UPROPERTY(EditAnywhere)							FVector spawnVel;								//var() FVector spawnVel;
	UPROPERTY()										FVector spawnVecV;								//var FVector spawnVecV;
	UPROPERTY()										FVector spawnVecU;								//var FVector spawnVecU;
	UPROPERTY()										bool noReference;								//var transient bool noReference;
	UPROPERTY()										float texV;										//var transient float texV;
	UPROPERTY()										float texU;										//var transient float texU;
	UPROPERTY()										float numFrames;								//var transient float numFrames;
	UPROPERTY(EditAnywhere)							float numRows;									//var() float numRows;
	UPROPERTY(EditAnywhere)							float numCols;									//var() float numCols;
	UPROPERTY(EditAnywhere)							float maxPclEyeDist;							//var() float maxPclEyeDist;
	UPROPERTY(EditAnywhere)							float deviation;								//var() float deviation;
	UPROPERTY()										float eyeVel;									//var transient float eyeVel;
	UPROPERTY()										FVector eyeMoveVec;								//var transient FVector eyeMoveVec;
	UPROPERTY()										FVector spawnOrigin;							//var transient FVector spawnOrigin;
	UPROPERTY()										FVector eyeDir;									//var transient FVector eyeDir;
	UPROPERTY()										FVector eyePos;									//var transient FVector eyePos;
	UPROPERTY()										FBox Box;										//var transient Object.Box Box;
	UPROPERTY()										int32 numActive;								//var transient int numActive;
	UPROPERTY(EditAnywhere)							int32 numParticles;								//var() int numParticles;
	UPROPERTY(EditAnywhere)							EWeatherType WeatherType;						//var() EWeatherType WeatherType;

	UPROPERTY()										UTexture2D* Texture;
	UPROPERTY()										USceneComponent* Root;
	UPROPERTY()										UBillboardComponent* SpriteComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
