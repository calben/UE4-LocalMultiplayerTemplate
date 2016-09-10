// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "Player/LMCharacter.h"
#include "Player/SharedCameraPawn.h"
#include "LocalMultiplayerGameMode.h"


ALocalMultiplayerGameMode::ALocalMultiplayerGameMode()
{
	DefaultPawnClass = ALMCharacter::StaticClass();
}

void ALocalMultiplayerGameMode::BeginPlay()
{
	for (auto i = 0; i < RegisteredPlayersNum; ++i)
		UGameplayStatics::CreatePlayer(GetWorld(), i);
	ASharedCameraPawn* SharedCameraPawn = GetWorld()->SpawnActor<ASharedCameraPawn>(FVector(0.f, 0.f, 10000.f), FRotator::ZeroRotator);
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* Controller = Cast<APlayerController>(*Iterator);
		if (Controller)
		{
			if (Controller->IsLocalController())
			{
				UE_LOG(LogTemp, Warning, TEXT("DETECTED LOCAL CONTROLLER %s"), *Controller->GetName());
				if (SharedCameraPawn)
				{
					SharedCameraPawn->RegisterPawn(Controller->GetPawn());
					ALMCharacter* LMCharacter = Cast<ALMCharacter>(Controller->GetPawn());
					if (LMCharacter)
					{
						LMCharacter->SharedCameraPawn = SharedCameraPawn;
					}
				}
			}
		}
	}
	if (SharedCameraPawn)
		GetWorld()->GetFirstPlayerController()->SetViewTarget(SharedCameraPawn);
}
