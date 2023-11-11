// Copyright Epic Games, Inc. All Rights Reserved.


#include "GemetrySandboxGameModeBase.h"
#include "./Public/SandboxPawn.h"
#include "./Public/SandboxPlayerController.h"

AGemetrySandboxGameModeBase::AGemetrySandboxGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
	PlayerControllerClass = ASandboxPlayerController::StaticClass();
}
