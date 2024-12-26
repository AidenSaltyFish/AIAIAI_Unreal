// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIAIAIGameMode.h"
#include "AIAIAICharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIAIAIGameMode::AAIAIAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
