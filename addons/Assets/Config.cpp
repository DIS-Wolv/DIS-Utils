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
			"DISAsset_PDIS",
			"DISAsset_Rules"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Structures_F", "A3_Weapons_F_Ammoboxes", "A3_Supplies_F_Heli_CargoNets", "DISLoad"};
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

class CfgEditorSubCategories
{
	class NO_CATEGORY;
	class DISSign: NO_CATEGORY
	{
		displayName = "Panneaux";
	};
	class DISCrates: NO_CATEGORY
	{
		displayName = "DIS Crates";
	};
};


class CfgVehicles
{
// Drapeaux
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

// Panneaux
	class Land_Billboard_F;
	class DISAsset_BillboardDIS : Land_Billboard_F
	{
		author = "Wolv";
		displayName = "Grand Panneaux DIS";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto.jpg";
		category = "DISAssets";
		editorCategory = "DISAssets";
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

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
		editorSubcategory = "DISSign";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\divers.jpg'];";
		};
	};
	class DISAsset_PDIS : SignAd_Sponsor_F
	{
		author = "Wolv";
		displayName = "Panneaux DIS";
		editorPreview = "z\DISUtils\addons\Assets\data\DISMoto.jpg";
		editorCategory = "DISAssets";
		editorSubcategory = "DISSign";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\DISMoto.jpg'];";
		};
	};

	class Land_MapBoard_01_Wall_F;
	class DISAsset_Rules : Land_MapBoard_01_Wall_F
	{
		author = "Wolv";
		displayName = "Panneaux Regles";
		editorPreview = "z\DISUtils\addons\Assets\data\tip.jpg";
		editorCategory = "DISAssets";
		editorSubcategory = "DISSign";

		class EventHandlers
		{
			init = "(_this select 0) setObjectTextureGlobal [0, 'z\DISUtils\addons\Assets\data\tip.jpg'];";
		};
	};
// Caisses
	class Box_NATO_Equip_F;
	class DISAsset_Box_Para : Box_NATO_Equip_F
	{
		author = "Wolv";
		displayName = "Caisse Parachutiste";
		editorCategory = "DISAssets";
		editorSubcategory = "DISCrates";

		class TransportItems {};
		class EventHandlers
		{
			init = "if (isNil ""DISCrate_var_dump"") then {[] call DISLoad_fnc_VarLoads;}; [(_this select 0), DISCrate_var_Para] call DISLoad_fnc_SetCrate; (_this select 0) addAction [""Recharger la caisse"", {params [""_t"", ""_c"", ""_i"", ""_arguments""]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [DISCrate_var_Para], 1.5, True, True, """", """", 5];";
		};
	};
	class DISAsset_Box_Items : Box_NATO_Equip_F
	{
		author = "Wolv";
		displayName = "Caisse Items";
		editorCategory = "DISAssets";
		editorSubcategory = "DISCrates";

		class TransportItems {};
		class EventHandlers
		{
			init = "if (isNil ""DISCrate_var_dump"") then {[] call DISLoad_fnc_VarLoads;}; [(_this select 0), DISCrate_var_Items] call DISLoad_fnc_SetCrate; (_this select 0) addAction [""Recharger la caisse"", {params [""_t"", ""_c"", ""_i"", ""_arguments""]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [DISCrate_var_Items], 1.5, True, True, """", """", 5];";
		};
	};

	class Box_NATO_Wps_F;
	class DISAsset_Box_Wpn : Box_NATO_Wps_F
	{
		author = "Wolv";
		displayName = "Caisse Armes";
		editorCategory = "DISAssets";
		editorSubcategory = "DISCrates";

		class EventHandlers
		{
			init = "if (isNil ""DISCrate_var_dump"") then {[] call DISLoad_fnc_VarLoads;}; [(_this select 0), DISCrate_var_Armes] call DISLoad_fnc_SetCrate; (_this select 0) addAction [""Recharger la caisse"", {params [""_t"", ""_c"", ""_i"", ""_arguments""]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [DISCrate_var_Armes], 1.5, True, True, """", """", 5];";
		};
	};
	
	class Box_NATO_WpsLaunch_F;
	class DISAsset_Box_Launcher : Box_NATO_WpsLaunch_F
	{
		author = "Wolv";
		displayName = "Caisse Lanceur";
		editorCategory = "DISAssets";
		editorSubcategory = "DISCrates";

		class EventHandlers
		{
			init = "if (isNil ""DISCrate_var_dump"") then {[] call DISLoad_fnc_VarLoads;}; [(_this select 0), DISCrate_var_Lanceurs] call DISLoad_fnc_SetCrate; (_this select 0) addAction [""Recharger la caisse"", {params [""_t"", ""_c"", ""_i"", ""_arguments""]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [DISCrate_var_Lanceurs], 1.5, True, True, """", """", 5];";
		};
	};

	class CargoNet_01_box_F;
	class DISAsset_Box_Dump : CargoNet_01_box_F
	{
		author = "Wolv";
		displayName = "Dump";
		editorCategory = "DISAssets";
		editorSubcategory = "DISCrates";

		class EventHandlers
		{
			init = "if (isNil ""DISCrate_var_dump"") then {[] call DISLoad_fnc_VarLoads;}; [(_this select 0), DISCrate_var_dump] call DISLoad_fnc_SetCrate; (_this select 0) addAction [""Recharger la caisse"", {params [""_t"", ""_c"", ""_i"", ""_arguments""]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [DISCrate_var_dump], 1.5, True, True, """", """", 5];";
		};
	};
};


