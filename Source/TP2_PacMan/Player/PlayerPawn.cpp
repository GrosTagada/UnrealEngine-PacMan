// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "EnhancedInputComponent.h"
#include "Engine/Engine.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	PlayerSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlayerSpriteComponent"));
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	
	RootComponent = BoxComponent;
	PlayerSpriteComponent->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("possess"));
}

FVector2D APlayerPawn::GetDirection()
{
	return PlayerDirection;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddMovementInput(GetActorRightVector(), PlayerDirection.Y);
	AddMovementInput(GetActorForwardVector(), PlayerDirection.X);
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Blue,FString::Printf(TEXT("X : %f , Y: %f"),PlayerDirection.X,PlayerDirection.Y));
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveInputAction)
		{
			EnhancedInputComponent->BindAction(MoveInputAction,ETriggerEvent::Started,this,&APlayerPawn::Move);
		}
	}
}


void APlayerPawn::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	PlayerDirection = MovementVector;
}

