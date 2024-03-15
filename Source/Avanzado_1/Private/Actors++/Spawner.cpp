// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors++/Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawner::ActivaSpawn()
{
	for (int i = 0; i < enemiesToSpawn.Num(); i++)
	{
		int rndEnemy = rand() % enemiesToSpawn.Num();
		int rndSpawnPoint = rand() % spawnPoints.Num();
		TSubclassOf<AActor> enemyToSpawn = enemiesToSpawn[rndEnemy];
		FVector location = spawnPoints[i]->GetActorLocation();
		int rndRot = rand() % 360;
		GetWorld()->SpawnActor<AActor>(enemyToSpawn, location, spawnPoints[i]->GetActorRotation());

		spawnPoints.RemoveAt(rndSpawnPoint);
	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

