

class CfgPatches
{
	class DISAssets
	{
		units[] = {"DISAsset_FlagDISMoto", "DISAsset_FlagDIS","DISAsset_FlagDISMoto_Tan","DISAsset_FlagDIS_Tan","DISAsset_BillboardDIS"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Structures_F"};
	};
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class DISAssets: NO_CATEGORY
	{
		displayName = "DIS Assets";

	};
};

class CfgEditorCategories
{
	class NO_CATEGORY;
	class DISAssets: NO_CATEGORY
	{
		displayName = "DIS Assets";

	};
};


class CfgVehicles
{
	class Flag_NATO_F;
	class DISAsset_FlagDISMoto : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Moto)";
		editorPreview = "Assets\data\DISMoto.paa";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'Assets\data\DISMoto.paa'";
		};
	};
	class DISAsset_FlagDIS : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS)";
		editorPreview = "Assets\data\DIS.paa";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'Assets\data\DIS.paa'";
		};
	};

	class DISAsset_FlagDISMoto_Tan : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Moto Tan)";
		editorPreview = "Assets\data\DISMoto_Tan.paa";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'Assets\data\DISMoto_Tan.paa'";
		};
	};
	class DISAsset_FlagDIS_Tan : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Tan)";
		editorPreview = "Assets\data\DIS_Tan.paa";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'Assets\data\DIS_Tan.paa'";
		};
	};

	class Land_Billboard_F;
	class DISAsset_BillboardDIS : Land_Billboard_F
	{
		author = "Wolv";
		displayName = "Billboard (DIS)";
		editorPreview = "Assets\data\DISMoto.jpg";
		category = "DISAssets";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'Assets\data\DISMoto.jpg']; if (isClass(configFile >> ""CfgPatches"" >> ""ace_medical"")) then {(_this select 0) addAction[""<t color='#0D4C00'>Full heal</t>"",{[player] call ace_medical_treatment_fnc_fullHealLocal;}];};";
		};
	};
};
