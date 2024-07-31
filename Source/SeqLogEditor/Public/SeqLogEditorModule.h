#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class SEQLOGEDITOR_API FSeqLogEditorModule : public IModuleInterface
{

public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;

private:

	void RegisterMenuExtensions();

	TSharedPtr<class FUICommandList> PluginCommands;
};
