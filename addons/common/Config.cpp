
class CfgFunctions
{
	#include "CfgFunctions.hpp"
};


class CfgPatches
{
	class DISCommon
	{
		units[] = {"DISCommon_InitHalo", "DISCommon_InitRecoDrone", "DISCommon_AttachMarkerToObject", "DISCommon_CustomDISLocation", "DISCommon_CustomLocation"};
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
			// class AnyBrain;
		};
	};

	class DISCommon_InitHalo : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Init HALO Jump";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\halo.paa";	// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCommon_fnc_initHalo";// Name of function triggered once conditions are met
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
			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Initialisation of the Halo Jump script, sync to the objects";	// Short description, will be formatted as structured text

		};
	};

	class DISCommon_InitRecoDrone : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Init reco drone";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\drone.paa";					// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCommon_fnc_initRecoDrone";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;						// Allows for setting the area values in the Attributes menu in 3DEN

		// Module attributes (uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific):
		class Attributes : AttributesBase
		{
			// Attributes definition
			class TypeDrone : Edit
			{
				property = "DISCommon_Module_Init_TypeDrone";
				displayName = "TypeDrone";
				tooltip = "Define the type of drone (""classname1"")";
				typeName = "STRING";
				defaultValue = """B_UAV_02_F""";
			};

			class DefaultRange : Edit
			{
				property = "DISCommon_Module_Init_DefaultRange";
				displayName = "Range";
				tooltip = "Define the default range of the drone";
				typeName = "NUMBER";
				defaultValue = "2000";
			};

			class DefaultAltitude : Edit
			{
				property = "DISCommon_Module_Init_DefaultAltitude";
				displayName = "Altitude";
				tooltip = "Define the default altitude of the drone";
				typeName = "NUMBER";
				defaultValue = "2000";
			};

			class IsArmed : Checkbox
			{
				property = "DISCommon_Module_Init_IsArmed";
				displayName = "Is Armed";
				tooltip = "Define if the drone is armed";
				typeName = "BOOL";
				defaultValue = "FALSE";
			};

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Initialisation of the Halo Jump script, sync to the objects";	// Short description, will be formatted as structured text
			position = 1;	// Position is taken into effect
		};
	};

	class DISCommon_AttachMarkerToObject : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Attach marker to object";		// Name displayed in the menu
		icon = "\A3\ui_f\data\map\markers\handdrawn\objective_CA.paa";					// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCommon_fnc_markers";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;						// Allows for setting the area values in the Attributes menu in 3DEN

		class Attributes : AttributesBase
		{
			// Attributes definition
			class MarkerName : Edit
			{
				property = "DISCommon_Module_Init_MarkerName";
				displayName = "Marker";
				tooltip = "Name of the marker";
				typeName = "STRING";
				defaultValue = """Marker""";
			};

			class Redo : Checkbox
			{
				property = "DISCommon_Module_Init_Redo";
				displayName = "Redo";
				tooltip = "Does the script need to redo the marker placement";
				typeName = "BOOL";
				defaultValue = "TRUE";
			};

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Permet d'attacher un marker a un object, sync to the object";	// Short description, will be formatted as structured text
		};
	};
	
	class DISCommon_CustomDISLocation : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Location DIS";					// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\loc.paa";							// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCommon_fnc_customLocations";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 1;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;

		class Attributes : AttributesBase
		{
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Permet d'initialisé les locations custom de la DIS";	// Short description, will be formatted as structured text
		};
	};

	class DISCommon_AddCustomLocation : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Location custom";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\loc.paa";							// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCOMMON_fnc_addCustomLocation";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 1;
		canSetAreaShape = 0;				// Allows for setting "Rectangle" or "Ellipse" in Attributes menu in 3DEN
		canSetAreaHeight = 0;				// Allows for setting height or Z value in Attributes menu in 3DEN
		class AttributeValues
		{
			// This section allows you to set the default values for the attributes menu in 3DEN
			size3[] = { 100, 100, -1 };		// 3D size (x-axis radius, y-axis radius, z-axis radius)
		};

		class Attributes : AttributesBase
		{
			// Module-specific arguments:
			class Name : Edit
			{
				property = "DISCommon_Module_CustomLocation_Name";
				displayName = "Name";
				tooltip = "Name of the location";
				typeName = "STRING";
				defaultValue = """Nom""";
			};

			class LocType : Combo
			{
				property = "DISCommon_Module_CustomLocation_LocType";		// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Type";				// Argument label
				tooltip = "Type of the location";		// Tooltip description
				typeName = "STRING";								// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = """NameVillage""";								// Default attribute value. Warning: this is an expression, and its returned value will be used (50 in this case).

				// Listbox items
				class Values
				{
					class 1	{ name = "Colline";	value = "Hill"; };
					class 2	{ name = "Lieux-dit"; value = "Name"; };
					class 3	{ name = "Village";	value = "NameVillage"; };
					class 4	{ name = "Ville"; value = "NameCity"; };
					class 5	{ name = "Capitale"; value = "NameCityCapital"; };
				};
			};//['NameCityCapital', 'NameCity', 'NameVillage', 'Name', 'NameLocal', 'Hill']
			
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Permet d'ajouter une locations custom";	// Short description, will be formatted as structured text
			position = 1;	// Position is taken into effect

		};
	};

	class DISCommon_BoatSpawner : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Boat spaw point";				// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\boat.paa";							// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCOMMON_fnc_initboat";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;

		class Attributes : AttributesBase
		{
			// Module-specific arguments:
			class BoatName : Edit
			{
				property = "DISCommon_Module_BoatSpawner_Name";
				displayName = "Name";
				tooltip = "Type of the boat";
				typeName = "STRING";
				defaultValue = """B_Boat_Transport_01_F""";
			};
			
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Add a action to spawn and delete boats near the marker";	// Short description, will be formatted as structured text
			position = 1;	// Position is taken into effect
		};
	};

	class DISCommon_Teleporter : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Teleporter";						// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\teleport.paa";					// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCOMMON_fnc_fastTravelInit";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;

		class Attributes : AttributesBase
		{
			// Module-specific arguments:
			class Name : Edit
			{
				property = "DISCommon_Module_Teleporter_Name";
				displayName = "Destination name";
				tooltip = "Name of the destination";
				typeName = "STRING";
				defaultValue = """Base""";
			};
			
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Add a action to teleport player to the module position";	// Short description, will be formatted as structured text
			position = 1;	// Position is taken into effect
		};
	};

	class DISCommon_CutBushes : Module_F
	{
		// Standard object definitions:
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Cut bushes option";						// Name displayed in the menu
		icon = "z\DISUtils\addons\Common\data\bush.paa";					// Map icon. Delete this entry to use the default icon.
		category = "DIS_Public";
		author = "Wolv";

		function = "DISCOMMON_fnc_CutBushesInit";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		// 3DEN Attributes Menu Options
		canSetArea = 0;

		class Attributes : AttributesBase
		{
			class Timer : Edit
			{
				property = "DISCommon_Module_CutBushes_Timer";
				displayName = "Timer";
				tooltip = "Time needed to cut the bushes";
				typeName = "NUMBER";
				defaultValue = "2";
			};
			// Module-specific arguments:
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Add a action to cut bushes near the player, NEED ACE INTERACTION";	// Short description, will be formatted as structured text
			position = 0;	// Position is taken into effect
		};
	};

};
