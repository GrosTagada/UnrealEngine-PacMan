// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UBTTN_FindFrightenedPosition.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API UUBTTN_FindFrightenedPosition : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
private:
	FVector TargetLocation;
	class UNavigationSystemV1* NavArea;
};
