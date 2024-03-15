// Fill out your copyright notice in the Description page of Project Settings.


#include "Disparos/BalaBase.h"
#include "TimerManager.h"
#include "Characters/MyCharacterbase.h"

// Sets default values
ABalaBase::ABalaBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABalaBase::BeginPlay()
{
	GetWorldTimerManager().SetTimer(timer, this, &ABalaBase::TimerDestroy, duracionBala, false);

	//PrimaryActorTick.bCanEverTick = true;
	Super::BeginPlay();
	
}

// Called every frame
void ABalaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Mueve hacia adelante
	AddActorLocalOffset(speed, true);
}

//Coll
void ABalaBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AMyCharacterBase* player = Cast<AMyCharacterBase>(OtherActor);
	if (player != nullptr)
	{
		player->characterLife -= danioBala;
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("VIDA: " + player->characterLife));
		}*/
		UE_LOG(LogTemp, Warning, TEXT("VIDA: %d"), player->characterLife);

		Destroy();
	}
}

void ABalaBase::TimerDestroy()
{
	//Destruir Bala
	Destroy();
}

