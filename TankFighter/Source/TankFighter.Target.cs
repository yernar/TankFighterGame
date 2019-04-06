// Copyright Magic Inc., Yernar Aldabergenov© 2019.

using UnrealBuildTool;
using System.Collections.Generic;

public class TankFighterTarget : TargetRules
{
	public TankFighterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "TankFighter" } );
	}
}
