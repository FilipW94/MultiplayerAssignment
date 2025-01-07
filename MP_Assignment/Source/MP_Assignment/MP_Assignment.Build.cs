// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MP_Assignment : ModuleRules
{
	public MP_Assignment(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
