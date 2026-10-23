// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UBTTaskNode_FindRespawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API UUBTTaskNode_FindRespawnPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
private:
	FVector TargetLocation;
	class UNavigationSystemV1* NavArea;
};
