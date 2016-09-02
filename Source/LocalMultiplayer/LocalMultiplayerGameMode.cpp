// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayer.h"
#include "Player/LMCharacter.h"
#include "Player/SharedCameraPawn.h"
#include "LocalMultiplayerGameMode.h"


ALocalMultiplayerGameMode::ALocalMultiplayerGameMode()
{
	DefaultPawnClass = ALMCharacter::StaticClass();
	//ASharedCameraPawn* SharedCameraPawn;
}

