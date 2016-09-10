// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "SharedCameraPawn.h"


// Sets default values
ASharedCameraPawn::ASharedCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bDoCollisionTest = true;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 400.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;

	RootComponent = SpringArm;
	Camera->SetupAttachment(SpringArm);
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

	FVector tmp;
	if (RegisteredPawns.Num() > 0)
	{
		for (APawn* Pawn : RegisteredPawns)
		{
			if (Pawn)
				tmp += Pawn->GetActorLocation();
		}
	}
	else
	{
		tmp = FVector(0.f, 0.f, 1000.f);
	}
	tmp /= RegisteredPawns.Num();
	tmp.Z = PreferredZPosition;
	SetActorLocation(tmp);

}

// Called to bind functionality to input
void ASharedCameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ASharedCameraPawn::RegisterPawn(APawn* Pawn)
{
	RegisteredPawns.Add(Pawn);
}

void ASharedCameraPawn::UnregisterPawn(APawn* Pawn)
{
	RegisteredPawns.Remove(Pawn);
}
