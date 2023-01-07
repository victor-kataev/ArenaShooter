// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArenaShooterGameMode.h"
#include "ArenaShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArenaShooterGameMode::AArenaShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}
