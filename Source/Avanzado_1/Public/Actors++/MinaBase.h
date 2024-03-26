// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinaBase.generated.h"

UCLASS()
class AVANZADO_1_API AMinaBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) int damagePlayer;
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> explotionPart;

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
public:	
	// Sets default values for this actor's properties
	AMinaBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
