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
	class DIS_Public: NO_CATEGORY
	{
		displayName = "DIS Public Modules";
	};
	class DIS_Preset: NO_CATEGORY
	{
		displayName = "DIS Preset Modules";
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
		category = "DIS_Preset";

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

	class DISLoad_Equip : Module_F
	{
		scope = 2;
		displayName = "Equip";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS_Preset";

		function = "DISLoad_fnc_EquipInit";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase 
		{
			class IsZeus : Edit
			{
				property = "DISLoad_Module_Equip_Zeus";
				displayName = "Zeus";
				tooltip = "Define the class of the unit to equip as Zeus";
				typeName = "STRING";
				defaultValue = "[""god"",""god1""]";
			};

			class IsCdS : Edit
			{
				property = "DISLoad_Module_Equip_CdS";
				displayName = "Chef de Section";
				tooltip = "Define the class of the unit to equip as CdS";
				typeName = "STRING";
				defaultValue = "[""coyCds""]";
			};

			class IsCdG : Edit
			{
				property = "DISLoad_Module_Equip_CdG";
				displayName = "Chef de Groupe";
				tooltip = "Define the class of the unit to equip as CdG";
				typeName = "STRING";
				defaultValue = "[""grCdg"",""trCdg"",""sgCdg""]";
			};
			
			class IsMedic : Edit
			{
				property = "DISLoad_Module_Equip_Medic";
				displayName = "Medic";
				tooltip = "Define the class of the unit to equip as Medic";
				typeName = "STRING";
				defaultValue = "[""coyMed"",""grMed"",""trMed"",""sgMed""]";
			};
			
			class IsCdE : Edit
			{
				property = "DISLoad_Module_Equip_CdE";
				displayName = "Chef d'Equipe";
				tooltip = "Define the class of the unit to equip as CdE";
				typeName = "STRING";
				defaultValue = "[""coyCde"",""sgBlCde"",""sgGrCde"",""trBlCde"",""trGrCde"",""grBlCde"",""grGrCde""]";
			};
			
			class IsGv : Edit
			{
				property = "DISLoad_Module_Equip_Gv";
				displayName = "Gv";
				tooltip = "Define the class of the unit to equip as Gv";
				typeName = "STRING";
				defaultValue = "[""coyGvIng"",""sgGvIng"",""sgBlGv1"",""sgBlGv2"",""sgGrGv1"",""sgGrGv2"",""trGvIng"",""trBlGv1"",""trBlGv2"",""trGrGv1"",""trGrGv2"",""grGvIng"",""grBlGv1"",""grBlGv2"",""grGrGv1"",""grGrGv2""]";
			};
			
			class IsCdBr : Edit
			{
				property = "DISLoad_Module_Equip_CdBr";
				displayName = "Chef de Bord (rouge)";
				tooltip = "Define the class of the unit to equip as CdBr";
				typeName = "STRING";
				defaultValue = "[""sgCdb"",""trCdb"",""grCdb""]";
			};
			
			class IsCdB : Edit
			{
				property = "DISLoad_Module_Equip_CdB";
				displayName = "Chef de Bord";
				tooltip = "Define the class of the unit to equip as CdB";
				typeName = "STRING";
				defaultValue = "[""crCdb"",""trCdb"",""alCdb""]";
			};
			
			class IsEquipier : Edit
			{
				property = "DISLoad_Module_Equip_Equipier";
				displayName = "Equipier";
				tooltip = "Define the class of the unit to equip as Equipier";
				typeName = "STRING";
				defaultValue = "[""sgEq"",""grEq"",""trEq"",""crEq1"",""crEq2"",""alEq1"",""alEq2""]";
			};
			
			class IsPiloteHelo : Edit
			{
				property = "DISLoad_Module_Equip_PiloteHelo";
				displayName = "Pilote Helico";
				tooltip = "Define the class of the unit to equip as PiloteHelo";
				typeName = "STRING";
				defaultValue = "[""haP1"",""haP2"",""haP3"",""haP4""]";
			};
			
			class IsPiloteAvions : Edit
			{
				property = "DISLoad_Module_Equip_PiloteAvions";
				displayName = "Pilote Avions";
				tooltip = "Define the class of the unit to equip as PiloteAvions";
				typeName = "STRING";
				defaultValue = "[""albP1"",""albP2""]";
			};

			class DefaultGV : Checkbox
			{
				property = "DISLoad_Module_Equip_PiloteAvions";
				displayName = "GV pour les autres";
				tooltip = "Define if the Gv is the default load for the other units";
				typeName = "BOOL";
				defaultValue = "TRUE";
			};

			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description = "This module will initialise the load on given units.";
		};
	};

	class DISLoad_CustomLoad : Module_F
	{
		scope = 2;
		displayName = "Custom Loads";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS_Public";

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
		displayName = "Loads";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS_Preset";

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

	class DISLoad_CustomCrate : Module_F
	{
		scope = 2;
		displayName = "Custom Crate";
		icon = "z\DISUtils\addons\Loads\data\box.paa";
		category = "DIS_Public";

		function = "DISLoad_fnc_customCrate";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase
		{

			class CrateName : Edit
			{
				property = "DISLoad_Module_CustomCrate_LoadName";
				displayName = "Crate Name";
				tooltip = "Define the name of the crate";
				typeName = "STRING";
				defaultValue = """Custom Crate""";
			};

			class Load : Edit
			{
				property = "DISLoad_Module_CustomCrate_Load";
				displayName = "Crate";
				tooltip = "Define the load of the crate";
				typeName = "STRING";
				defaultValue = "[[""SmokeShell"",25],[""B_Parachute"",5]]";
			};

			class AddInArsenal : Checkbox
			{
				property = "DISLoad_Module_CustomCrate_AddInArsenal";
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
			description= "This module will initialise the crate on sync object and share the object in the arsenal if available.";
		};
	};

	class DISLoad_DisCrate : Module_F
	{
		scope = 2;
		displayName = "DIS Crates";
		icon = "z\DISUtils\addons\Loads\data\box.paa";
		category = "DIS_Preset";

		function = "DISLoad_fnc_DISCrate";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase
		{
			class CrateName : Combo
			{
				property = "DISLoad_Module_DisCrate_CrateName";
				displayName = "Crate";
				tooltip = "The crate to setup";
				typeName = "STRING";
				defaultValue = """dump""";

				// Listbox items
				class Values
				{
					class 1		{ value = "dump";		name = "Poubelle"; };
					class 2		{ value = "arme";		name = "Armes"; };
					class 3		{ value = "items";		name = "Items"; };
					class 4		{ value = "itemsCe";	name = "Items CE"; };
					class 5		{ value = "itemsDa";	name = "Items DA"; };
					class 6		{ value = "lanceurs";	name = "Lanceurs"; };
					class 7		{ value = "medical";	name = "Médical"; };
					class 8		{ value = "para";		name = "Parachute"; };
				};
			};

			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description= "This module will initialise the crate on sync object and share the object in the arsenal.";
		};
	};

	class DISLoad_DisLoadSign : Module_F
	{
		scope = 2;
		displayName = "DIS Sign";
		icon = "z\DISUtils\addons\Loads\data\Helmet.paa";
		category = "DIS_Preset";

		function = "DISLoad_fnc_SetSign";
		functionPriority = 1;
		isGlobal = 1;
		isTriggerActivated = 0;
		isDisposable = 0;
		is3DEN = 0;
		curatorCanAttach = 0;

		canSetArea = 0;

		class Attributes : AttributesBase
		{
			class SignName : Combo
			{
				property = "DISLoad_Module_DisLoadSign_SignName";
				displayName = "Type of load";
				tooltip = "The type of load to setup";
				typeName = "STRING";
				defaultValue = """Infanterie""";

				// Listbox items
				class Values
				{
					class 1		{ value = "Infanterie";	name = "Infanterie"; };
					class 2		{ value = "Cavalerie";	name = "Cavalerie"; };
					class 3		{ value = "Plongeur";	name = "Plongeur"; };
					class 4		{ value = "Pilote";		name = "Pilote"; };
				};
			};

			// Attributes definition
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		class ModuleDescription: ModuleDescription
		{
			description= "This module will initialise the crate on sync object and share the object in the arsenal.";
		};
	};
};
