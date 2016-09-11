// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "SharedCameraPawn.h"
#include "LMCharacter.h"


// Sets default values
ALMCharacter::ALMCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to timprove performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	const ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshObj(TEXT("/Game/Characters/YBot/Y_Bot"));
	const ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimBlueprintObj(TEXT("/Game/Characters/YBot/CharacterRifleAnimBlueprint"));
	if (MeshObj.Object)
		GetMesh()->SetSkeletalMesh(MeshObj.Object);
	if (AnimBlueprintObj.Object)
		GetMesh()->SetAnimInstanceClass(AnimBlueprintObj.Object->GeneratedClass);
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.1f;
	GetCharacterMovement()->GravityScale = 1.4f;

	bUseControllerRotationYaw = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bDoCollisionTest = true;
	SpringArm->RelativeRotation = FRotator(-80.f, 0.f, 0.f);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 800.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation = false;


	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void ALMCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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


float ALMCharacter::GetCharacterMovementSpeed()
{
	return GetVelocity().Size();
}

void ALMCharacter::Kill()
{
	if (SharedCameraPawn)
		SharedCameraPawn->UnregisterPawn(this);
	if (GEngine->GetGamePlayer(GetWorld(), 0)->PlayerController == Cast<APlayerController>(Controller))
		Controller->Possess(SharedCameraPawn);
	this->Destroy();
}

void ALMCharacter::Damage(float Value)
{
	this->Health -= Value;
	if (Health < 0)
	{
		this->Kill();
	}
}
