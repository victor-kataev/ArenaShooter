// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = "Authority";
		break;
		
	case ENetRole::ROLE_AutonomousProxy:
		Role = "AutonomouseProxy";
		break;

	case ENetRole::ROLE_SimulatedProxy:
		Role = "SimulatedProxy";
		break;

	case ENetRole::ROLE_None:
		Role = "None";
		break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote role: %s"), *Role);
	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
