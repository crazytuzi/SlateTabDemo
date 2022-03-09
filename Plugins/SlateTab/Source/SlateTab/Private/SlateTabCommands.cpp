// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateTabCommands.h"

#define LOCTEXT_NAMESPACE "FSlateTabModule"

void FSlateTabCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "SlateTab", "Execute SlateTab action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
