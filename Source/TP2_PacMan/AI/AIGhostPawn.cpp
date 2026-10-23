// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGhostPawn.h"

#include "PaperSpriteComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AAIGhostPawn::AAIGhostPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite Component"));
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
	
	this->RootComponent = BoxComponent;
	SpriteComponent->SetupAttachment(BoxComponent);
	
	PawnMovement->SetUpdatedComponent(BoxComponent);
}

// Called when the game starts or when spawned
void AAIGhostPawn::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLocation = GetActorLocation();
}

// Called every frame
void AAIGhostPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIGhostPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

