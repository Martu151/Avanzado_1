// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealerBase.generated.h"

UCLASS()
class AVANZADO_1_API AHealerBase : public AActor
{
	GENERATED_BODY()

public:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	UPROPERTY(EditAnywhere) int healAmount;
	
public:	
	// Sets default values for this actor's properties
	AHealerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
