// Copyright Epic Games, Inc. All Rights Reserved.

#include "MP_AssignmentGameMode.h"
#include "MP_AssignmentCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMP_AssignmentGameMode::AMP_AssignmentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
