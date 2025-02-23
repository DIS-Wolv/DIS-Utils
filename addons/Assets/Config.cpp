

class CfgPatches
{
	class DISAssets
	{
		units[] = {
			"DISAsset_FlagDISMoto", "DISAsset_FlagDIS",
			"DISAsset_FlagDISMoto_Tan","DISAsset_FlagDIS_Tan",
			"DISAsset_FlagDISMoto_Bleu","DISAsset_FlagDIS_Bleu",
			"DISAsset_FlagDISMoto_Vert","DISAsset_FlagDIS_Vert",
			"DISAsset_FlagDISMoto_Rouge","DISAsset_FlagDIS_Rouge",
			"DISAsset_FlagDISMoto_Jaune","DISAsset_FlagDIS_Jaune",
			"DISAsset_BillboardDIS",
			"DISAsset_PInf_CE","DISAsset_PInf_DA",
			"DISAsset_PCav","DISAsset_PPil",
			"DISAsset_PRens","DISAsset_PDiv",
			"DISAsset_Rules"};
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
	// Flag Blanc
	class DISAsset_FlagDISMoto : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Blanc Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto.paa'";
		};
	};
	class DISAsset_FlagDIS : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Blanc)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS.paa'";
		};
	};
	// Flag Tan
	class DISAsset_FlagDISMoto_Tan : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Tan Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto_Tan.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto_Tan.paa'";
		};
	};
	class DISAsset_FlagDIS_Tan : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Tan)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS_Tan.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS_Tan.paa'";
		};
	};
	// Flag Bleu 
	class DISAsset_FlagDISMoto_Bleu : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Bleu Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto_Bleu.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto_Bleu.paa'";
		};
	};
	class DISAsset_FlagDIS_Bleu : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Bleu)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS_Bleu.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS_Bleu.paa'";
		};
	};
	// Flag Vert
	class DISAsset_FlagDISMoto_Vert : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Vert Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto_Vert.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto_Vert.paa'";
		};
	};
	class DISAsset_FlagDIS_Vert : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Vert)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS_Vert.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS_Vert.paa'";
		};
	};
	// Flag Rouge
	class DISAsset_FlagDISMoto_Rouge : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Rouge Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto_Rouge.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto_Rouge.paa'";
		};
	};
	class DISAsset_FlagDIS_Rouge : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Rouge)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS_Rouge.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS_Rouge.paa'";
		};
	};
	// Flag Jaune
	class DISAsset_FlagDISMoto_Jaune : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Jaune Moto)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto_Jaune.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DISMoto_Jaune.paa'";
		};
	};
	class DISAsset_FlagDIS_Jaune : Flag_NATO_F
	{
		author = "Wolv";
		displayName = "Flag (DIS Jaune)";
		editorPreview = "z\DISUtils\addons\Assets\data\DIS_Jaune.paa";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture 'z\DISUtils\addons\Assets\data\DIS_Jaune.paa'";
		};
	};

	class Land_Billboard_F;
	class DISAsset_BillboardDIS : Land_Billboard_F
	{
		author = "Wolv";
		displayName = "Billboard (DIS)";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto.jpg";
		category = "DISAssets";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\DISMoto.jpg']; if (isClass(configFile >> ""CfgPatches"" >> ""ace_medical"")) then {(_this select 0) addAction[""<t color='#0D4C00'>Full heal</t>"",{[player] call ace_medical_treatment_fnc_fullHealLocal;}];};";
		};
	};

	class SignAd_Sponsor_F;
	class DISAsset_PInf_CE : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Infantrie CE";
		editorPreview = "z\DISUtils\addons\Assets\data\ce.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\ce.jpg'];";
		};
	};
	class DISAsset_PInf_DA : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Infantrie DA";
		editorPreview = "z\DISUtils\addons\Assets\data\da.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\da.jpg'];";
		};
	};
	class DISAsset_PCav : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Cavalerie";
		editorPreview = "z\DISUtils\addons\Assets\data\cav.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\cav.jpg'];";
		};
	};
	class DISAsset_PPil : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Pilote";
		editorPreview = "z\DISUtils\addons\Assets\data\pilot.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\pilot.jpg'];";
		};
	};
	class DISAsset_PRens : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Renseignement";
		editorPreview = "z\DISUtils\addons\Assets\data\Rens.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\Rens.jpg'];";
		};
	};
	class DISAsset_PDiv : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux Plongeur";
		editorPreview = "z\DISUtils\addons\Assets\data\divers.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\divers.jpg'];";
		};
	};

	class Land_MapBoard_01_Wall_F;
	class DISAsset_Rules : Land_MapBoard_01_Wall_F
	{
		author = "Wolv";
		displayName = "Panneaux Règles";
		editorPreview = "z\DISUtils\addons\Assets\data\tip.jpg";
		editorCategory = "DISAssets";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\tip.jpg'];";
		};
	};
};
