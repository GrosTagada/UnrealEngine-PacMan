// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPinkGhostController.h"

#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "TP2_PacMan/Player/PlayerPawn.h"

FVector AAIPinkGhostController::CalculateChaseTarget() 
{
	if (!NavArea)
		NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		
	if (!PlayerPawn)
		return FVector(0);
		
	FVector PlayerPosition = PlayerPawn->GetActorLocation();
	FVector PlayerDirection3D;
		
	if (APlayerPawn* Player = Cast<APlayerPawn>(PlayerPawn))
	{
		FVector2D PlayerDirection2D = Player->GetDirection();
		PlayerDirection3D = FVector(PlayerDirection2D.X,PlayerDirection2D.Y,0);
	}
	
	for (int32 TryChances = 0; TryChances<3; TryChances++)
	{
		if (NavArea->K2_GetRandomLocationInNavigableRadius(GetWorld(), PlayerPosition + (PlayerDirection3D * AnticipationDistance), TargetLocation, 200.0f * TryChances))
		{
			return TargetLocation;
		}
	}
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Blue,TEXT("Pink Ghost"));
	
	return FVector(0);
}

FVector AAIPinkGhostController::CalculateScatterTarget()
{
	return FVector(0);
}

FVector AAIPinkGhostController::CalculateFrightenedTarget()
{
	if (!NavArea)
		NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	if (NavArea)
	{
		// Get the current player position
		FVector PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		
		// Return true if found a random point in the navigation and around your player position
		if (NavArea->K2_GetRandomLocationInNavigableRadius(GetWorld(), GetPawn()->GetActorLocation(), TargetLocation, 600.0f))
		{
			return TargetLocation;
		}
		
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Blue,TEXT("Red Ghost"));

	return FVector(0);
}
