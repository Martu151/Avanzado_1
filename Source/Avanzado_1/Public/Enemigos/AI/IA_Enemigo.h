// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "IA_Enemigo.generated.h"

/**
 * 
 */
UCLASS()
class AVANZADO_1_API AIA_Enemigo : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) int radius;
	UPROPERTY(EditAnywhere) UAIPerceptionComponent* perception;
	UPROPERTY(EditAnywhere) UBehaviorTree* behaviorTree;

public:
	class AMyCharacterBase* player;

public:
	AIA_Enemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION() void OnStimulus(AActor* actor, FAIStimulus stimulus);
	
};
