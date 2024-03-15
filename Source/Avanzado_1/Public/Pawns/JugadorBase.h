// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "JugadorBase.generated.h"

UCLASS()
class AVANZADO_1_API AJugadorBase : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) int vidaJugador;
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> balaSpawn;
	UPROPERTY(EditAnywhere) int cartuchoBalas;
	UPROPERTY(EditAnywhere) int balasActuales;

public:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void Dispara();

public:
	// Sets default values for this pawn's properties
	AJugadorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
