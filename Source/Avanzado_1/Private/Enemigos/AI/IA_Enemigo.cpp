// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigos/AI/IA_Enemigo.h"
#include "Enemigos/EnemigoBase.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Characters/MyCharacterBase.h"
#include "BehaviorTree/BlackBoardComponent.h"

AIA_Enemigo::AIA_Enemigo()
{
	perception = CreateDefaultSubobject<UAIPerceptionComponent>("Perception");

	UAISenseConfig_Sight* sight = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");
	sight->SightRadius = 1000;
	sight->LoseSightRadius = 1100;
	sight->PeripheralVisionAngleDegrees = 90;
	sight->DetectionByAffiliation.bDetectNeutrals = true;
	sight->SetMaxAge(2);
}

void AIA_Enemigo::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(behaviorTree);
	perception->OnTargetPerceptionUpdated.AddDynamic(this, &AIA_Enemigo::OnStimulus);
}

void AIA_Enemigo::OnStimulus(AActor* actor, FAIStimulus stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("OnStimulus"));
	AMyCharacterBase* detectedPlayer = Cast<AMyCharacterBase>(actor);
	if (detectedPlayer != nullptr)
	{
		if (player == nullptr)
		{
			player = detectedPlayer;
			Blackboard->SetValueAsObject("Player", detectedPlayer);
		}
		else if (player == detectedPlayer)
		{
			player = nullptr;
			Blackboard->ClearValue("Player");
		}
	}
}

/*void AIA_Enemigo::Tick(float deltaSeconds)
{
	if (player != nullptr)
	{
		MoveToLocation(player->GetActorLocation());
	}
	else 
	{
		AEnemigoBase* enemigo = Cast<AEnemigoBase>(GetPawn());
		FVector enemyPos = enemigo->GetActorLocation();
		FVector targetPos = enemigo->wayPoints[currentWayPoint]->GetActorLocation();

		float dist = FVector::Dist(enemyPos, targetPos);

		if (dist < 100)
		{
			currentWayPoint++;
			if (currentWayPoint >= enemigo->wayPoints.Num())
			{
				currentWayPoint = 0;
			}

			targetPos = enemigo->wayPoints[currentWayPoint]->GetActorLocation();
			MoveToLocation(targetPos);
		}
	}
}*/