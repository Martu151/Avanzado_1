// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors++/HealerBase.h"
#include "Characters/MyCharacterbase.h"

// Sets default values
AHealerBase::AHealerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	healAmount = 25;
}

// Called when the game starts or when spawned
void AHealerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Coll
void AHealerBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AMyCharacterBase* player = Cast<AMyCharacterBase>(OtherActor);
	if (player != nullptr)
	{
		player->characterLife += healAmount;
		if (player->characterLife > 100)
		{
			player->characterLife = 100;
		}

		UE_LOG(LogTemp, Warning, TEXT("VIDA: %d"), player->characterLife);

		Destroy();
	}
}