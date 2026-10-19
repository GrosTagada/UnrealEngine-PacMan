// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGhostController.h"
#include "AIRedGhostController.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API AAIRedGhostController : public AAIGhostController
{
	GENERATED_BODY()
	
	class UNavigationSystemV1* NavArea;
	
	FVector TargetLocation;
	
public:
	
	virtual FVector Chase() override;
};
