#include "includeMaster.hpp"

class CfgFunctions
{
	#include "CfgFunctions.hpp"
};

class CfgPatches
{
	class WOLV_Garage
	{
		units[] = {"WOLV_Lights_Init"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Modules_F"};
	};
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class DIS_Public: NO_CATEGORY
	{
		displayName = "DIS Public Modules";
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
			class AnyStaticObject;
		};
	};

	class WOLV_Garage_Init : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Init garage";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Garage\data\icon.paa";	// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "WolvGarage_fnc_init";	// Name of function triggered once conditions are met
		functionPriority = 1;				// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 1;						// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isTriggerActivated = 1;				// 1 for module waiting until all synced triggers are activated
		isDisposable = 0;					// 1 if modules is to be disabled once it is activated (i.e. repeated trigger activation will not work)
		is3DEN = 0;							// 1 to run init function in Eden Editor as well
		curatorCanAttach = 0;				// 1 to allow Zeus to attach the module to an entity
		// curatorInfoType = "RscDisplayAttributeModuleNuke"; // Menu displayed when the module is placed or double-clicked on by Zeus

		// 3DEN Attributes Menu Options
		canSetArea = 0;						// Allows for setting the area values in the Attributes menu in 3DEN

		// Module attributes (uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific):
		class Attributes : AttributesBase
		{
			// Module-specific arguments:
			class Range : Edit
			{
				property = "WolvGarage_Module_Init_Range";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Range detection";				// Argument label
				tooltip = "Define the range of the garage";		// Tooltip description
				typeName = "NUMBER";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "100";								// Default attribute value. Warning: this is an expression, and its returned value will be used (50 in this case).
			};

			class AvalaibleVehicle : Edit
			{
				property = "WolvGarage_Module_Init_AvalaibleVehicle";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Avalaible vehicle";				// Argument label
				tooltip = "Define the list of Vehicle that the garage can spawn ([""classname1"",""classname2"",...])";		// Tooltip description
				typeName = "STRING";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "[""B_MRAP_01_F"",""B_Truck_01_mover_F""]";
			};

			class DefaultLoad : Edit
			{
				property = "WolvGarage_Module_Init_DefaultLoad";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Default Load";				// Argument label
				tooltip = "Define the list of object who are place in the vehicle when spawn ([[""classname1"",Number],[""classname2"",Number],...])";		// Tooltip description
				typeName = "STRING";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "[[""30Rnd_65x39_caseless_mag"",10], [""SmokeShell"",5],[""Toolkit"", 1]]";
			};

			class InventoryItem : Edit
			{
				property = "WolvGarage_Module_Init_InventoryItem";
				displayName = "Inventory";
				tooltip = "Define the list of object that can be place in the vehicle ([""classname1"",""classname2"",...])";
				typeName = "STRING";
				defaultValue = "[""30Rnd_65x39_caseless_mag"",""SmokeShell"",""Toolkit""]";
			};

			class AceEnable : Checkbox
			{
				property = "WolvGarage_Module_Init_AceEnable";
				displayName = "Enable Ace";
				tooltip = "Define if you are using Ace";
				typeName = "BOOL";
				defaultValue = "isClass(configFile >> ""CfgPatches"" >> ""ace_interaction"")";
			};

			class AceItem : Edit
			{
				property = "WolvGarage_Module_Init_AceItem";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Ace Inventory";				// Argument label
				tooltip = "Define the list of object that can be place in the vehicle ([""classname1"",""classname2"",...])";		// Tooltip description
				typeName = "STRING";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "[""ACE_medicalSupplyCrate_advanced"", ""ACE_Wheel"", ""ACE_Track"", ""Box_NATO_AmmoVeh_F""]";
			};

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Initialisation of the Garage of the DIS, sync to the object";	// Short description, will be formatted as structured text
		};
	};
};
