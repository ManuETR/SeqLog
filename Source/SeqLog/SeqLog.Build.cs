using UnrealBuildTool;

public class SeqLog : ModuleRules
{
	public SeqLog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.Add("SeqLog/Private");

		PublicDependencyModuleNames.AddRange
        (
			new string[]
			{
				"Core",
        "CoreUObject",
        "Engine",
				"HTTP"
			}
		);

		PrivateDependencyModuleNames.AddRange
        (
			new string[]
			{
				"CoreUObject",
				"Engine",
				"DeveloperSettings",
        "HTTP",
				"Core",
				"Json"
      }
		);
	}
}
