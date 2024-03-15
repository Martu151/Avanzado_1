// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GetNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class AVANZADO_1_API UGetNextWaypoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) FBlackboardKeySelector wayPointIndexKey;
	UPROPERTY(EditAnywhere) FBlackboardKeySelector wayPointLocationKey;

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};