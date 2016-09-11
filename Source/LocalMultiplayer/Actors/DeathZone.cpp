// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "Player/LMCharacter.h"
#include "DeathZone.h"


// Sets default values
ADeathZone::ADeathZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->bGenerateOverlapEvents = true;
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::TriggerEnter);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ADeathZone::TriggerExit);
	RootComponent = BoxComponent;

}

// Called when the game starts or when spawned
void ADeathZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeathZone::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADeathZone::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ALMCharacter* LMCharacter = Cast<ALMCharacter>(OtherActor);
	if (LMCharacter)
	{
		LMCharacter->Damage(10.f);
	}
}

void ADeathZone::TriggerExit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

