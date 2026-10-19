// Fill out your copyright notice in the Description page of Project Settings.


#include "UBTTaskNode_FindPlayerLocation.h"

#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP2_PacMan/Controllers/AIControllers/AIGhostController.h"

EBTNodeResult::Type UUBTTaskNode_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	//Problème de performance
	AAIController* controller =  OwnerComp.GetAIOwner();
	
	if (AAIGhostController* GhostController = Cast<AAIGhostController>(controller))
	{
		FVector TargetPos = GhostController->Chase(); //If there is an error the result will be FVector(0)
		
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetLocation"), TargetPos);
			
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
