// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Eatable.generated.h"

UCLASS()
class TP2_PACMAN_API AEatable : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionBox;
	UPROPERTY(EditAnywhere)
	class UPaperSpriteComponent* SpriteComponent;
	
public:	
	// Sets default values for this actor's properties
	AEatable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void OnEat();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
	void OnOverlap(AActor* MyActor, AActor* OtherActor);

};
