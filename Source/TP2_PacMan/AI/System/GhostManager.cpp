// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostManager.h"

#include "TP2_PacMan/Controllers/AIControllers/AIGhostController.h"


// Sets default values
AGhostManager::AGhostManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGhostManager::BeginPlay()
{
	Super::BeginPlay();
	
	SetGhostMode(EGhostMode::Chase);
	
	//Je lance un timer
	FTimerManager& WorldTimer = GetWorld()->GetTimerManager();
	WorldTimer.SetTimer(TimerHandle,this,&AGhostManager::test,10.0f);
}

// Called every frame
void AGhostManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGhostManager::SetGhostMode(EGhostMode NewMode)
{
	CurrentMode = NewMode;

	for (AAIGhostPawn* Ghost : GhostArray)
	{
		if (!IsValid(Ghost))
		{
			continue;
		}

		if (AAIGhostController* Controller = Cast<AAIGhostController>(Ghost->GetController()))
		{
			Controller->SetGhostMode(NewMode);
		}
	}
}

void AGhostManager::test()
{
	//SetGhostMode(EGhostMode::Frightened);
}
