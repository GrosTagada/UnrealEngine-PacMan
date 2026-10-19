// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPinkGhostController.h"

#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TP2_PacMan/Controllers/AIControllers/AIGhostController.h"

FVector AAIPinkGhostController::Chase()
{
	if (!NavArea)
		NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (NavArea)
	{
		FVector PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

		// Return true if found a random point in the navigation and around your player position
		if (NavArea->K2_GetRandomLocationInNavigableRadius(GetWorld(), PlayerPosition + AnticipationDistance, TargetLocation, 100.0f))
		{
			return TargetLocation;
		}
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Blue,TEXT("Pink Ghost"));
	
	return FVector(0);
}
