// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors++/MinaBase.h"
#include "Characters/MyCharacterbase.h"

// Sets default values
AMinaBase::AMinaBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinaBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMinaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Coll
void AMinaBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (damagePlayer > 0)
	{
		AMyCharacterBase* player = Cast<AMyCharacterBase>(OtherActor);
		if (player != nullptr)
		{
			player->DamagePlayer(damagePlayer);

			if (explotionPart != nullptr)
			{
				GetWorld()->SpawnActor<AActor>(explotionPart, GetActorLocation(), GetActorRotation());
			}
			Destroy();
		}
	}
}

