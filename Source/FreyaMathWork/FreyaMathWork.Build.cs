// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FreyaMathWork : ModuleRules
{
	public FreyaMathWork(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FreyaMathWork",
			"FreyaMathWork/Variant_Platforming",
			"FreyaMathWork/Variant_Platforming/Animation",
			"FreyaMathWork/Variant_Combat",
			"FreyaMathWork/Variant_Combat/AI",
			"FreyaMathWork/Variant_Combat/Animation",
			"FreyaMathWork/Variant_Combat/Gameplay",
			"FreyaMathWork/Variant_Combat/Interfaces",
			"FreyaMathWork/Variant_Combat/UI",
			"FreyaMathWork/Variant_SideScrolling",
			"FreyaMathWork/Variant_SideScrolling/AI",
			"FreyaMathWork/Variant_SideScrolling/Gameplay",
			"FreyaMathWork/Variant_SideScrolling/Interfaces",
			"FreyaMathWork/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
