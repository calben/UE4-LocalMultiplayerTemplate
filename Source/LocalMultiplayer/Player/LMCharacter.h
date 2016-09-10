// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "LMCharacter.generated.h"

UCLASS()
class LOCALMULTIPLAYER_API ALMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		class ASharedCameraPawn* SharedCameraPawn;

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		float Health = 100.f;

	virtual void Kill();

	void MoveForward(float Value);

	void MoveRight(float Value);
	
	float GetCharacterMovementSpeed();

	void Damage(float Value);

};
