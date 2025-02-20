class CfgFunctions
{
	#include "CfgFunctions.hpp"
};

class CfgPatches
{
	class DISLoad
	{
		units[] = {"DISLoad_Module"};
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

	class ArsenalAce : Module_F
	{
		scope = 2;
		displayName = "DIS Ace Arsenal";
		icon = "Loads\data\Box.paa";
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
		displayName = "DIS Loads";
		icon = "Loads\data\Helmet.paa";
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
				property = "DISLoad_Module_Init_LoadName";
				displayName = "Load Name";
				tooltip = "Define the name of the load in arsenal";
				typeName = "STRING";
				defaultValue = "Custom Load";
			};

			class Load : Edit
			{
				property = "DISLoad_Module_Init_Load";
				displayName = "Load";
				tooltip = "Define the load in format of ACE arsenal";
				typeName = "STRING";
				defaultValue = "[[[""arifle_MXC_F"","""","""",""optic_Aco"",[""30Rnd_65x39_caseless_mag"",30],[],""""],[],[""hgun_Pistol_heavy_01_F"","""","""",""optic_MRD"",[""11Rnd_45ACP_Mag"",15],[],""""],[""U_B_CombatUniform_mcam"",[[""FirstAidKit"",1],[""30Rnd_65x39_caseless_mag"",2,30],[""Chemlight_green"",1,1]]],[""V_BandollierB_rgr"",[[""30Rnd_65x39_caseless_mag"",1,30],[""11Rnd_45ACP_Mag"",2,15],[""SmokeShell"",1,1],[""SmokeShellGreen"",1,1],[""Chemlight_green"",1,1]]],[],""H_MilCap_mcamo"","""",[],[""ItemMap"",""B_UavTerminal"",""ItemRadio"",""ItemCompass"",""ItemWatch"",""""]],[]]";
			};

			class AddInArsenal : Checkbox
			{
				property = "DISLoad_Module_Init_AddInArsenal";
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

};
