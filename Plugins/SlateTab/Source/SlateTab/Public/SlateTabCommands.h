// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SlateTabStyle.h"

class FSlateTabCommands : public TCommands<FSlateTabCommands>
{
public:

	FSlateTabCommands()
		: TCommands<FSlateTabCommands>(TEXT("SlateTab"), NSLOCTEXT("Contexts", "SlateTab", "SlateTab Plugin"), NAME_None, FSlateTabStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
