// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateTab.h"
#include "SlateTabStyle.h"
#include "SlateTabCommands.h"
#include "SlateTabTestWindow1UserWidget.h"
#include "SlateTabTestWindow2UserWidget.h"
#include "SlateTabTestWindow3UserWidget.h"
#include "ToolMenus.h"
#include "Containers/ArrayBuilder.h"

static const FName SlateTabTabName("SlateTab");

#define LOCTEXT_NAMESPACE "FSlateTabModule"

void FSlateTabModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSlateTabStyle::Initialize();
	FSlateTabStyle::ReloadTextures();

	FSlateTabCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSlateTabCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FSlateTabModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FSlateTabModule::RegisterMenus));

	TabArray =
		TArrayBuilder<TPair<FName, TSubclassOf<UUserWidget>>>()
		.Add(TPair<FName, TSubclassOf<UUserWidget>>(FName("TestTab1"), USlateTabTestWindow1UserWidget::StaticClass()))
		.Add(TPair<FName, TSubclassOf<UUserWidget>>(FName("TestTab2"), USlateTabTestWindow2UserWidget::StaticClass()))
		.Add(TPair<FName, TSubclassOf<UUserWidget>>(FName("TestTab3"), USlateTabTestWindow3UserWidget::StaticClass()));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SlateTabTabName, FOnSpawnTab::CreateRaw(this, &FSlateTabModule::OnSpawnPluginTab))
							.SetMenuType(ETabSpawnerMenuType::Hidden);

	for (const auto& Tab : TabArray)
	{
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(Tab.Key, FOnSpawnTab::CreateLambda(
			                                                  [Tab](const FSpawnTabArgs& SpawnTabArgs)
			                                                  {
				                                                  const auto UserWidget = CreateWidget<UUserWidget>(
					                                                  GWorld->GetWorld(), Tab.Value);

				                                                  return SNew(SDockTab).TabRole(ETabRole::NomadTab)
				                                                  [
					                                                  UserWidget->TakeWidget()
				                                                  ];
			                                                  })).SetMenuType(ETabSpawnerMenuType::Hidden);
	}
}

void FSlateTabModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FSlateTabStyle::Shutdown();

	FSlateTabCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(SlateTabTabName);
}

void FSlateTabModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(SlateTabTabName);
}

TSharedRef<SDockTab> FSlateTabModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	const auto NomadTab = SNew(SDockTab).TabRole(ETabRole::NomadTab);

	if (!TabManager.IsValid())
	{
		TabManager = FGlobalTabmanager::Get()->NewTabManager(NomadTab);
	}

	if (!TabManagerLayout.IsValid())
	{
		const auto NewStack = FTabManager::NewStack();

		for (const auto& Tab : TabArray)
		{
			NewStack->AddTab(Tab.Key, ETabState::OpenedTab);
		}

		TabManagerLayout = FTabManager::NewLayout(SlateTabTabName)->AddArea(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)->Split(
				NewStack));
	}

	const auto TabContent = TabManager->RestoreFrom(TabManagerLayout.ToSharedRef(), TSharedPtr<SWindow>()).
	                                    ToSharedRef();

	NomadTab->SetContent(TabContent);

	return NomadTab;
}

void FSlateTabModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FSlateTabCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FSlateTabCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateTabModule, SlateTab)