// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTTN_FindFrightenedPosition.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP2_PacMan/Controllers/AIControllers/AIGhostController.h"


EBTNodeResult::Type UUBTTN_FindFrightenedPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* controller =  OwnerComp.GetAIOwner();
	
	if (AAIGhostController* GhostController = Cast<AAIGhostController>(controller))
	{
		FVector TargetPos = GhostController->CalculateFrightenedTarget(); 
		
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetLocation"), TargetPos);
			
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}