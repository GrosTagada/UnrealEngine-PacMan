// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGhostController.h"
#include "AIPinkGhostController.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API AAIPinkGhostController : public AAIGhostController
{
	GENERATED_BODY()
	
	float AnticipationDistance = 3.0f;
	
	class UNavigationSystemV1* NavArea;
	
	FVector TargetLocation;
public:
	
	virtual FVector Chase() override;
};
