// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BalaBase.generated.h"

UCLASS()
class AVANZADO_1_API ABalaBase : public AActor
{
	GENERATED_BODY()

public:
	void TimerDestroy();
	void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere) FTimerHandle timer;
	UPROPERTY(EditAnywhere) float duracionBala;
	UPROPERTY(EditAnywhere) FVector speed;
	UPROPERTY(EditAnywhere) int danioBala;
	
public:	
	// Sets default values for this actor's properties
	ABalaBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
