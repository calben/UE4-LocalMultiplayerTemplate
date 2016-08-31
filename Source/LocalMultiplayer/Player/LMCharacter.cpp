// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "LMCharacter.h"


// Sets default values
ALMCharacter::ALMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to timprove performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	const ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshObj(TEXT("/Game/Characters/YBot/Y_Bot"));
	if(MeshObj.Object)
		GetMesh()->SetSkeletalMesh(MeshObj.Object);

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.1f;
	GetCharacterMovement()->GravityScale = 1.4f;

}

// Called when the game starts or when spawned
void ALMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALMCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ALMCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &ALMCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ALMCharacter::MoveRight);
}

void ALMCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		FVector Direction = FVector(1.f, 0.f, 0.f);
		AddMovementInput(Direction, Value);
	}
}


void ALMCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		FVector Direction = FVector(0.f, 1.f, 0.f);
		AddMovementInput(Direction, Value);
	}
}

void ALMCharacter::Kill()
{

}
