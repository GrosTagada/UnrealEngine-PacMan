// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP2_PacMan/AI/System/GhostManager.h"
#include "GamePlayGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API AGamePlayGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	
public: 
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="GamePlayGameMode")
	TObjectPtr<AGhostManager> GhostManager;
};
