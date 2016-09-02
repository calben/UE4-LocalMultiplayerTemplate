// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "SharedCameraPawn.h"


// Sets default values
ASharedCameraPawn::ASharedCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASharedCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASharedCameraPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ASharedCameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

