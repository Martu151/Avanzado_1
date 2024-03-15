// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "IDamagable.h"
#include "EnemigoBase.generated.h"

UCLASS()
class AVANZADO_1_API AEnemigoBase : public ACharacter, public IIDamagable
{
	GENERATED_BODY()

public:
	void TakeDamage(int damage) override;
	void TimerDispara();
	UPROPERTY(EditAnywhere) TArray<AActor*> wayPoints;
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> balaSpawn;
	UPROPERTY(EditAnywhere) float tiempoEntreSpawn;
	UPROPERTY(EditAnywhere) FTimerHandle timer;
	UPROPERTY(EditAnywhere) FRotator rotSpeed;

	UPROPERTY(EditAnywhere) int life;
	
public:	
	// Sets default values for this actor's properties
	AEnemigoBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
