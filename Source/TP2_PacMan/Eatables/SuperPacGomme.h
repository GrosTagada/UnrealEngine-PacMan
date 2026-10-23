// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eatable.h"
#include "SuperPacGomme.generated.h"

/**
 * 
 */
UCLASS()
class TP2_PACMAN_API ASuperPacGomme : public AEatable
{
	GENERATED_BODY()
	
	
protected:
	virtual void OnEat() override;
};
