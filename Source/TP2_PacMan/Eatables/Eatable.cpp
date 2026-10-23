// Fill out your copyright notice in the Description page of Project Settings.


#include "Eatable.h"

#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "TP2_PacMan/Player/PlayerPawn.h"

// Sets default values
AEatable::AEatable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite Component"));
	
	RootComponent = CollisionBox;
	SpriteComponent->SetupAttachment(CollisionBox);
	
	this->OnActorBeginOverlap.AddDynamic(this,&AEatable::OnOverlap);
}

// Called when the game starts or when spawned
void AEatable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEatable::OnEat()
{
}

// Called every frame
void AEatable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEatable::OnOverlap(AActor* MyActor, AActor* OtherActor) 
{
	if (APlayerPawn* PlayerPawn = Cast<APlayerPawn>(OtherActor))
	{
		OnEat();
		
		Destroy();
	}
}

