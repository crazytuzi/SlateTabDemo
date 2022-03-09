// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FSlateTabModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();

	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs);
	
private:

	void RegisterMenus();

private:
	TSharedPtr<FUICommandList> PluginCommands;

private:
	TArray<TPair<FName, TSubclassOf<UUserWidget>>> TabArray;

private:
	TSharedPtr<FTabManager> TabManager;

	TSharedPtr<FTabManager::FLayout> TabManagerLayout;
};
