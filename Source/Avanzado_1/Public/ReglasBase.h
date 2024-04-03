// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ReglasBase.generated.h"

/**
 * 
 */
UCLASS()
class AVANZADO_1_API AReglasBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int vidasRespawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int enemigosMatados;

public:
	AReglasBase();
	void Tick(float deltaSeconds) override;
	
};

