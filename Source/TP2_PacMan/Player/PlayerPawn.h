// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class TP2_PACMAN_API APlayerPawn : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="PlayerPawn|Components")
	TObjectPtr<UBoxComponent> BoxComponent;
	UPROPERTY(EditAnywhere, Category="PlayerPawn|Components")
	TObjectPtr<UPaperSpriteComponent> PlayerSpriteComponent; 
	UPROPERTY(EditAnywhere, Category="PlayerPawn|Components")
	TObjectPtr<UFloatingPawnMovement> MovementComponent;
	
	UPROPERTY(EditAnywhere, Category="PlayerPawn|Inputs")
	TObjectPtr<UInputAction> MoveInputAction;
	
	UPROPERTY(VisibleAnywhere, Category="PlayerPawn|Debug")
	FVector2D PlayerDirection;
	
public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
protected:
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void Move(const FInputActionValue& Value);
};
