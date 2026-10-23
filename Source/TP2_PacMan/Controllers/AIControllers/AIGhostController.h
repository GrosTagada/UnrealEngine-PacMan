// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TP2_PacMan/AI/Enum/EGhostMode.h"
#include "AIGhostController.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TP2_PACMAN_API AAIGhostController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIGhostController(const FObjectInitializer& ObjectInitializer);
	
	virtual void OnPossess(APawn* InPawn) override;
	
	void SetGhostMode(EGhostMode NewMode);
	
	virtual FVector CalculateChaseTarget() PURE_VIRTUAL(AAIGhostController::CalculateChaseTarget, return FVector(0);) ;
	virtual FVector CalculateScatterTarget() PURE_VIRTUAL(AAIGhostController::CalculateScatterTarget, return FVector(0););
	virtual FVector CalculateFrightenedTarget() PURE_VIRTUAL(AAIGhostController::CalculateScatterTarget, return FVector(0););
	FVector CalculateSpawnTarget() const;
	
	UPROPERTY(Transient)
	class UBehaviorTreeComponent* BehaviorTreeComponent;
	
	UPROPERTY(Transient)
	class UBlackboardComponent* BlackboardComponent;
};
