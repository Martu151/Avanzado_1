// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigos/AI/Tasks/GetNextWaypoint.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Enemigos/EnemigoBase.h"
#include "Enemigos/AI/IA_Enemigo.h"


EBTNodeResult::Type UGetNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIController* controller = Cast<AAIController>(OwnerComp.GetOwner());
	if (controller == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[GetNextWaypoint] Cannot cast owner to AAIController type"));
		return EBTNodeResult::Failed;
	}
	AEnemigoBase* enemy = Cast<AEnemigoBase>(controller->GetPawn());
	if (enemy == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[GetNextWaypoint] Cannot cast owner to AEnemigoBase type"));
		return EBTNodeResult::Failed;
	}
	if (enemy->wayPoints.Num() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[GetNextWaypoint] Enemy dont have any waypoint"));
		return EBTNodeResult::Failed;
	}

	int index = OwnerComp.GetBlackboardComponent()->GetValueAsInt(wayPointIndexKey.SelectedKeyName);
	FVector waypointPosition = enemy->wayPoints[index]->GetActorLocation();
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(wayPointLocationKey.SelectedKeyName, waypointPosition);

	index++;
	if (index >= enemy->wayPoints.Num())
	{
		index = 0;
	}
	OwnerComp.GetBlackboardComponent()->SetValueAsInt(wayPointIndexKey.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;

}
