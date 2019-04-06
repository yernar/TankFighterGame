// Copyright Magic Inc., Yernar Aldabergenov© 2019.

using UnrealBuildTool;
using System.Collections.Generic;

public class TankFighterEditorTarget : TargetRules
{
	public TankFighterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "TankFighter" } );
	}
}
