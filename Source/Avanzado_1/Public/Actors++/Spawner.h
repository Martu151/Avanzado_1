// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class AVANZADO_1_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) int spawnAmount;
	UPROPERTY(EditAnywhere) TArray<TSubclassOf<AActor>> enemiesToSpawn;

	UPROPERTY(EditAnywhere) TArray<AActor*> spawnPoints;

public:
	void ActivaSpawn();
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
