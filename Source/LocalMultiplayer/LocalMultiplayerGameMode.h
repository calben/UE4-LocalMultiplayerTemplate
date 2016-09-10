// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "LocalMultiplayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LOCALMULTIPLAYER_API ALocalMultiplayerGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
		int RegisteredPlayersNum = 3;

	ALocalMultiplayerGameMode();

	virtual void BeginPlay() override;
	
};
