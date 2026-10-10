// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"

#include "Engine/LocalPlayer.h"


void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
					InputSubsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
