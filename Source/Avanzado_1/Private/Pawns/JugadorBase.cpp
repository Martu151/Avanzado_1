// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/JugadorBase.h"
#include "Components/InputComponent.h"
#include "ReglasBase.h"
#include "Engine/World.h"

// Sets default values
AJugadorBase::AJugadorBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJugadorBase::BeginPlay()
{
	Super::BeginPlay();
	balasActuales = cartuchoBalas;
}

// Called every frame
void AJugadorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(vidaJugador <= 0)
	{
		//Pierde | Respawnea o Game Over
		AReglasBase* mode = Cast<AReglasBase>(GetWorld()->GetAuthGameMode());
		if (mode != nullptr) {
			if(mode->vidasRespawn >= 0)
			{
				//Respawn
				mode->vidasRespawn--;
			}
			else
			{
				//Game Over
				Destroy();
			}
		}
	}
}

// Called to bind functionality to input
void AJugadorBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Disparo", IE_Pressed, this, &AJugadorBase::Dispara);
}

void AJugadorBase::Dispara()
{
	GetWorld()->SpawnActor<AActor>(balaSpawn.Get(), GetActorLocation(), GetActorRotation());
}

//Coll
void AJugadorBase::NotifyActorBeginOverlap(AActor* OtherActor)
{

}

