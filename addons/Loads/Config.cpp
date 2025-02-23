class CfgFunctions
{
	#include "CfgFunctions.hpp"
};

class CfgPatches
{
	class DISLoad
	{
		units[] = {"DISLoad_ArsenalAce", "DISLoad_CustomLoad", "DISLoad_DISLoad"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Modules_F"};
	};
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class DIS: NO_CATEGORY
	{
		displayName = "DIS Modules";
	};
};

class CfgVehicles
{
	class Logic;
	class Module_F : Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};

		// Description base classes (for more information see below):
		class ModuleDescription
		{
			// class AnyBrain;
		};
	};

	class DISLoad_ArsenalAce : Module_F
	{
		scope = 2;
		displayName = "DIS Ace Arsenal";
		icon = "z\DISUtils\addons\Loads\data\Box.paa";
		category = "DIS";

		function = "DISLoad_fnc_ArsenalAce";
		functionPriority = 2;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase 
		{
			class CustomItem : Edit
			{
				property = "DISLoad_Module_Init_Load";
				displayName = "Additionnal Items";
				tooltip = "Define the additionnal items";
				typeName = "STRING";
				defaultValue = "[""SmokeShell"",""SmokeShellGreen""]";
			};
			
			class LoadDIS : Checkbox
			{
				property = "DISLoad_Module_Init_AddInArsenal";
				displayName = "Load DIS";
				tooltip = "Define if add the DIS loads in the ACE Arsenal";
				typeName = "BOOL";
				defaultValue = "TRUE";
			};

			class CrateDIS : Checkbox
			{
				property = "DISLoad_Module_Init_CrateDIS";
				displayName = "Crate DIS";
				tooltip = "Define if add the DIS crate item in the ACE Arsenal";
				typeName = "BOOL";
				defaultValue = "TRUE";
			};
			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description= "This module will initialise the Ace Arsenal. It can share the DIS basic Loads and the DIS basic Crate item in the arsenal.";
		};

	};

	class DISLoad_CustomLoad : Module_F
	{
		scope = 2;
		displayName = "Custom Loads";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS";

		function = "DISLoad_fnc_customLoad";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase
		{

			class LoadName : Edit
			{
				property = "DISLoad_Module_CustomLoad_LoadName";
				displayName = "Load Name";
				tooltip = "Define the name of the load in arsenal";
				typeName = "STRING";
				defaultValue = "Custom Load";
			};

			class Load : Edit
			{
				property = "DISLoad_Module_CustomLoad_Load";
				displayName = "Load";
				tooltip = "Define the load in format of ACE arsenal";
				typeName = "STRING";
				defaultValue = "[[[""arifle_MXC_F"","""","""",""optic_Aco"",[""30Rnd_65x39_caseless_mag"",30],[],""""],[],[""hgun_Pistol_heavy_01_F"","""","""",""optic_MRD"",[""11Rnd_45ACP_Mag"",15],[],""""],[""U_B_CombatUniform_mcam"",[[""FirstAidKit"",1],[""30Rnd_65x39_caseless_mag"",2,30],[""Chemlight_green"",1,1]]],[""V_BandollierB_rgr"",[[""30Rnd_65x39_caseless_mag"",1,30],[""11Rnd_45ACP_Mag"",2,15],[""SmokeShell"",1,1],[""SmokeShellGreen"",1,1],[""Chemlight_green"",1,1]]],[],""H_MilCap_mcamo"","""",[],[""ItemMap"",""B_UavTerminal"",""ItemRadio"",""ItemCompass"",""ItemWatch"",""""]],[]]";
			};

			class AddInArsenal : Checkbox
			{
				property = "DISLoad_Module_CustomLoad_AddInArsenal";
				displayName = "Ace Arsenal";
				tooltip = "Define if the load is available in the ACE Arsenal";
				typeName = "BOOL";
				defaultValue = "isClass(configFile >> ""CfgPatches"" >> ""ace_arsenal"")";
			};

			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description= "This module will initialise set the load on sync units and share it in the arsenal if available.";
		};
	};

	class DISLoad_DISLoad : Module_F
	{
		scope = 2;
		displayName = "DIS Loads";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS";

		function = "DISLoad_fnc_disLoad";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase
		{

			class LoadName : Combo
			{
				property = "DISLoad_Module_DISLoad_LoadName";
				displayName = "Loads";
				tooltip = "The load to set on units";
				typeName = "STRING";
				defaultValue = """['DISLoadMc_var_GV','Gv']""";

				// Listbox items
				class Values
				{
					class 1		{ value = "['DISLoadMc_var_GV','Gv']";							name = "Gv"; };
					class 2		{ value = "['DISLoadMc_var_GvBck','Gv bck']";					name = "Gv bck"; };
					class 3		{ value = "['DISLoadMc_var_Grenadier','Grenadier']";			name = "Grenadier"; };
					class 4		{ value = "['DISLoadMc_var_Minimi5','Minimi 5.56']";			name = "Minimi 5.56"; };
					class 5		{ value = "['DISLoadMc_var_Minimi7','Minimi 7.62']";			name = "Minimi 7.62"; };
					class 6		{ value = "['DISLoadMc_var_Medecin','Médecin']";				name = "Médecin"; };
					class 7		{ value = "['DISLoadMc_var_CdE','CdE']";						name = "CdE"; };
					class 8		{ value = "['DISLoadMc_var_CdG','CdG']";						name = "CdG"; };
					class 9		{ value = "['DISLoadMc_var_CdS','CdS']";						name = "CdS"; };
					class 10	{ value = "['DISLoadMc_var_CdGM','CdG (Médic)']";				name = "CdG (Médic)"; };
					class 11	{ value = "['DISLoadMc_var_EOD','EOD']";						name = "EOD"; };
					class 12	{ value = "['DISLoadMc_var_EOD_Light','EOD (Light)']";			name = "EOD (Light)"; };
					class 13	{ value = "['DISLoadMC_var_TE','TE']";							name = "TE"; };
					class 14	{ value = "['DISLoadMc_var_TP','TP']";							name = "TP"; };
					class 15	{ value = "['DISLoadMC_var_Spotter','Spotter']";				name = "Spotter"; };
					class 16	{ value = "['DISLoadMc_var_Zeus','Zeus']";						name = "Zeus"; };
					class 17	{ value = "['DISLoadMc_var_CDB','CdB']";						name = "CdB"; };
					class 18	{ value = "['DISLoadMc_var_CDBR','CdB (inf)']";					name = "CdB (inf)"; };
					class 19	{ value = "['DISLoadMc_var_Equipier','Equipier']";				name = "Equipier"; };
					class 20	{ value = "['DISLoad_var_piloteHelo','Pilote hélico']";			name = "Pilote hélico"; };
					class 21	{ value = "['DISLoad_var_piloteAvions','Pilote avions']";		name = "Pilote avions"; };
					class 22	{ value = "['DISLoadPL_var_CDG','CdG Plongeur']";				name = "CdG Plongeur"; };
					class 23	{ value = "['DISLoadPL_var_CDE','CdE Plongeur']";				name = "CdE Plongeur"; };
					class 24	{ value = "['DISLoadPL_var_GV','Gv Plongeur']";					name = "Gv Plongeur"; };
					class 25	{ value = "['DISLoadPL_var_Medecin','Médecin Plongeur']";		name = "Médecin Plongeur"; };
					class 26	{ value = "['DISLoadPL_var_Minimi5','Minimi 5.56 Plongeur']";	name = "Minimi 5.56 Plongeur"; };
				};
			};

			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description= "This module will initialise the load and set it on sync units.";
		};
	};

};
