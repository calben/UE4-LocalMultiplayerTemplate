// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "SharedCameraPawn.generated.h"

UCLASS()
class LOCALMULTIPLAYER_API ASharedCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASharedCameraPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		TArray<APawn*> RegisteredPawns;

	UPROPERTY(EditAnywhere)
		float PreferredZPosition = 400.f;

	void RegisterPawn(APawn* Pawn);
	
	void UnregisterPawn(APawn* Pawn);

};
