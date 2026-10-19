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
	
	virtual FVector Chase() PURE_VIRTUAL(AAIGhostController::Chase, return FVector(0););
	
	UPROPERTY(Transient)
	class UBehaviorTreeComponent* BehaviorTreeComponent;
	
	UPROPERTY(Transient)
	class UBlackboardComponent* BlackboardComponent;
};
