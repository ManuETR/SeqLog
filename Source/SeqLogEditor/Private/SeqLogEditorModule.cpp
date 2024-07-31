#pragma once

#include "SeqLogEditorModule.h"
#include "SeqLogEditor.h"
#include "ToolMenus.h"

IMPLEMENT_MODULE(FSeqLogEditorModule, FSeqLogEditor)

void FSeqLogEditorModule::StartupModule() {
  UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(
    this, &FSeqLogEditorModule::RegisterMenuExtensions));
}

void FSeqLogEditorModule::ShutdownModule() {
  UToolMenus::UnRegisterStartupCallback(this);
  UToolMenus::UnregisterOwner(this);
}




void FSeqLogEditorModule::RegisterMenuExtensions()
{
  // Use the current object as the owner of the menus
  // This allows us to remove all our custom menus when the 
  // module is unloaded (see ShutdownModule below)
  FToolMenuOwnerScoped OwnerScoped(this);

  // Extend the "File" section of the main toolbar
  UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu(
    "LevelEditor.LevelEditorToolBar.ModesToolBar");
  FToolMenuSection& ToolbarSection = ToolbarMenu->FindOrAddSection("File");
  

  ToolbarSection.AddEntry(FToolMenuEntry::InitToolBarButton(
    TEXT("MyCustomButtonName"),
    FExecuteAction::CreateLambda([]()
      {
        // Simply log for this example
        UE_LOG(LogTemp, Log, TEXT("MyCustomButton triggered!!"));
      }),
    INVTEXT("My custom button"),
    INVTEXT("Tooltip for my custom button"),
    FSlateIcon(FAppStyle::GetAppStyleSetName(), "InputBindingEditor.OutputLog")
  ));
}