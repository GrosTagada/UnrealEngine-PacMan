// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "GamePlayerController|Inputs")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
