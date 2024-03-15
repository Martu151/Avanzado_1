// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors++/WaveManager.h"
#include "Characters/MyCharacterbase.h"

// Sets default values
AWaveManager::AWaveManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	waveDuration = 25;
	waveDecrement = 5;
}

// Called when the game starts or when spawned
void AWaveManager::BeginPlay()
{
	Super::BeginPlay();
	actualWave = 0;
}

// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Coll
void AWaveManager::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AMyCharacterBase* player = Cast<AMyCharacterBase>(OtherActor);
	if (player != nullptr && activate != true)
	{
		NewWave();
		activate = true;
	}
}

void AWaveManager::NewWave()
{

	if (actualWave <= spawners.Num()-1 && spawners[actualWave] != nullptr)
	{
		spawners[actualWave]->ActivaSpawn();
		if (waveDuration > 10)
		{
			waveDuration -= waveDecrement;
		}
		GetWorldTimerManager().SetTimer(timerWave, this, &AWaveManager::NewWave, waveDuration, false);
		actualWave++;
	}
	else
	{
		//GANA
		//Abre puerta para continuar
		puertaWin->Destroy();
		Destroy();
	}
}

