
class CfgFunctions
{
	#include "CfgFunctions.hpp"
};


class CfgPatches
{
	class WOLV_Lights
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

	class WOLV_Lights_Init : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Init lights";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Lights\data\icon.paa";	// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "WolvLights_fnc_init";	// Name of function triggered once conditions are met
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
			class Force : Combo
			{
				property = "WolvLights_Module_Init_force";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Strength of display";				// Argument label
				tooltip = "Define the precision of the display";		// Tooltip description
				typeName = "NUMBER";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "1";								// Default attribute value. Warning: this is an expression, and its returned value will be used (50 in this case).

				// Listbox items
				class Values
				{
					class 1	{ name = "Generator only";	value = 1; };
					class 2	{ name = "Generator and radius"; value = 2; };
					class 3	{ name = "Generator and poles"; value = 3; };
					class 4	{ name = "Generator and line"; value = 4; };
				};
			};

			class Lang : Combo
			{
				property = "WolvLights_Module_Init_Lang";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Language of the instruction";		// Argument label
				tooltip = "Wich language is use in game";			// Tooltip description
				typeName = "NUMBER";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "1";									// Default attribute value. Warning: this is an expression, and its returned value will be used (50 in this case).

				// Listbox items
				class Values
				{
					class 0	{ name = "English"; 	value = 0; };
					class 1	{ name = "Français";	value = 1; };
				};
			};

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Initialisation of the light script, to select display object, sync to the module";	// Short description, will be formatted as structured text

		};
	};
};
