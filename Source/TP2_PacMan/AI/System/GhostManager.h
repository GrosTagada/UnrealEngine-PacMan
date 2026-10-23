// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP2_PacMan/AI/AIGhostPawn.h"
#include "TP2_PacMan/AI/Enum/EGhostMode.h"
#include "GhostManager.generated.h"

UCLASS()
class TP2_PACMAN_API AGhostManager : public AActor
{
	GENERATED_BODY()
	
	FTimerHandle TimerHandle;
	
	float ChangeTime = 10.0f;
	
	UPROPERTY(EditInstanceOnly, Category = "Ghost Manager")
	TArray<TObjectPtr<AAIGhostPawn>> GhostArray;
	UPROPERTY(VisibleInstanceOnly, Category = "Ghost Manager")
	EGhostMode CurrentMode = EGhostMode::Scatter;
	
public :
	void SetGhostMode(EGhostMode NewMode);
	
	UFUNCTION()
	void test();
public:	
	// Sets default values for this actor's properties
	AGhostManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
