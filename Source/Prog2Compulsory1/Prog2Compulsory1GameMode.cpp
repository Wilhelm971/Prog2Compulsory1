// Copyright Epic Games, Inc. All Rights Reserved.

#include "Prog2Compulsory1GameMode.h"
#include "Prog2Compulsory1Character.h"
#include "UObject/ConstructorHelpers.h"

AProg2Compulsory1GameMode::AProg2Compulsory1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
