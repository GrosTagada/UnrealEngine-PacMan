// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIGhostPawn.generated.h"

UCLASS()
class TP2_PACMAN_API AAIGhostPawn : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	class UPaperSpriteComponent* SpriteComponent;
	
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere)
	class UFloatingPawnMovement* PawnMovement;
	
public: 
	
	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* TreeAsset;
	
public:
	// Sets default values for this pawn's properties
	AAIGhostPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
