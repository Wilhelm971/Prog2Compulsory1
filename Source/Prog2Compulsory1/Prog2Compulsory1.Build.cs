// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Prog2Compulsory1 : ModuleRules
{
	public Prog2Compulsory1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
