// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors++/Spawner.h"
#include "GameFramework/Actor.h"
#include "WaveManager.generated.h"

UCLASS()
class AVANZADO_1_API AWaveManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TArray<ASpawner*> spawners;
	UPROPERTY(EditAnywhere) AActor* puertaWin;

public:
	int actualWave;
	UPROPERTY(EditAnywhere) FTimerHandle timerWave;
	int waveDuration;
	int waveDecrement;
	bool activate;
public:
	void NewWave();
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
public:	
	// Sets default values for this actor's properties
	AWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
