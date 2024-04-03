// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigos/EnemigoBase.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Characters/MyCharacterbase.h"
#include "ReglasBase.h"

// Sets default values
AEnemigoBase::AEnemigoBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	life = 100;
}

// Called when the game starts or when spawned
void AEnemigoBase::BeginPlay()
{
	if(balaSpawn != nullptr)
		GetWorldTimerManager().SetTimer(timer, this, &AEnemigoBase::TimerDispara, tiempoEntreSpawn, true);

	Super::BeginPlay();
}

// Called every frame
void AEnemigoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//AddActorLocalRotation(rotSpeed, true);

}

void AEnemigoBase::TimerDispara()
{
	GetWorld()->SpawnActor<AActor>(balaSpawn.Get(), GetActorLocation(), GetActorRotation());
}

void AEnemigoBase::TakeDamage(int damage)
{
	UE_LOG(LogTemp, Warning, TEXT("Daña Enemigo"));
	life -= damage;
	if(life <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Destruye Enemigo"));
		AReglasBase*  regla = (AReglasBase*)GetWorld()->GetAuthGameMode();
		regla->enemigosMatados += 1;
		Destroy();
	}
}

//Coll
void AEnemigoBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (damagePlayer > 0)
	{
		AMyCharacterBase* player = Cast<AMyCharacterBase>(OtherActor);
		if (player != nullptr)
		{
			player->DamagePlayer(damagePlayer);

			if (collExplota) 
			{
				if (explotionPart != nullptr)
				{
					GetWorld()->SpawnActor<AActor>(explotionPart, GetActorLocation(), GetActorRotation());
				}
				Destroy();
			}
		}
	}
}

