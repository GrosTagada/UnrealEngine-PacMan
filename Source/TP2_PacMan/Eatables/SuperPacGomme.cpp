// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperPacGomme.h"

#include "TP2_PacMan/GameModes/GamePlayGameMode.h"

void ASuperPacGomme::OnEat()
{
	Super::OnEat();
	
	//Changer le mode 
	//Je peux récupéré le gamemode qui a une référence au GhostManager
	
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	
	if (AGamePlayGameMode* GamePlayGameMode = Cast<AGamePlayGameMode>(GameMode))
	{
		GamePlayGameMode->GhostManager->SetGhostMode(EGhostMode::Frightened);
	}
}
