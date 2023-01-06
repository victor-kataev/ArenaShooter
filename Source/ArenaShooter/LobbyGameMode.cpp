// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GameState)
	{
		int32 NumberOfPlayers = GameState->PlayerArray.Num();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,
				999.f,
				FColor::Yellow,
				FString::Printf(TEXT("Number of connected players: %d"), NumberOfPlayers));

			APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(1, 
												10.f,
												FColor::Cyan, 
												FString::Printf(TEXT("%s has joined"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if (GameState)
	{
		int32 NumberOfPlayers = GameState->PlayerArray.Num();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,
				999.f,
				FColor::Yellow,
				FString::Printf(TEXT("Number of connected players: %d"), NumberOfPlayers));

			APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(1,
					10.f,
					FColor::Cyan,
					FString::Printf(TEXT("%s has left"), *PlayerName));
			}
		}
	}
}
