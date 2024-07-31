using UnrealBuildTool;

public class SeqLogEditor : ModuleRules
{
	public SeqLogEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.Add("SeqLogEditor/Private");
		PrivateIncludePaths.Add("SeqLog/Private");

    PublicDependencyModuleNames.AddRange
        (
			new string[]
			{
				"Core",
				"InputCore",
        "Slate",
        "SlateCore",
        "ToolMenus",
      }
		);
			
		
		PrivateDependencyModuleNames.AddRange
        (
			new string[]
			{
        "SeqLog",
        "Engine",
				"CoreUObject",
        "UnrealEd"
			}
		);
	}
}
