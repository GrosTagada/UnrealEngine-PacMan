// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGhostController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP2_PacMan/AI/AIGhostPawn.h"

AAIGhostController::AAIGhostController(const FObjectInitializer& ObjectInitializer)
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
}

void AAIGhostController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (AAIGhostPawn* GhostPawn = Cast<AAIGhostPawn>(InPawn))
	{
		if (GhostPawn->TreeAsset && GhostPawn->TreeAsset->BlackboardAsset)
		{
			BlackboardComponent->InitializeBlackboard(*GhostPawn->TreeAsset->BlackboardAsset);
			
			BehaviorTreeComponent->StartTree(*GhostPawn->TreeAsset);
		}
	}
}

void AAIGhostController::SetGhostMode(EGhostMode NewMode)
{
	if (BlackboardComponent)
		BlackboardComponent->SetValueAsEnum("GhostMode",static_cast<uint8>(NewMode));
}

FVector AAIGhostController::CalculateSpawnTarget() const
{
	if (AAIGhostPawn* GhostPawn = Cast<AAIGhostPawn>(GetPawn()))
		return GhostPawn->SpawnLocation;
	
	return FVector(0);
}



