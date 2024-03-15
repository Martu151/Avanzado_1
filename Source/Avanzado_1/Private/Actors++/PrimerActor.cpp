// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors++/PrimerActor.h"

// Sets default values
APrimerActor::APrimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrimerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APrimerActor::puedeRespawnear(int vidasJugador)
{
	if(vidasJugador > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

