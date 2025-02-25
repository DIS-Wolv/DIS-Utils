/*
* Auteur : Wolv
* Ajoute des loads custom
*
* Arguments :
* 0: module
* 1: link
* 
*/
params ["_module","_link"];

private _load = _module getVariable ["Load", [[["arifle_MXC_F","","","optic_Aco",["30Rnd_65x39_caseless_mag",30],[],""],[],["hgun_Pistol_heavy_01_F","","","optic_MRD",["11Rnd_45ACP_Mag",15],[],""],["U_B_CombatUniform_mcam",[["FirstAidKit",1],["30Rnd_65x39_caseless_mag",2,30],["Chemlight_green",1,1]]],["V_BandollierB_rgr",[["30Rnd_65x39_caseless_mag",1,30],["11Rnd_45ACP_Mag",2,15],["SmokeShell",1,1],["SmokeShellGreen",1,1],["Chemlight_green",1,1]]],[],"H_MilCap_mcamo","",[],["ItemMap","B_UavTerminal","ItemRadio","ItemCompass","ItemWatch",""]],[]]];
if (typeName _load == "STRING") then {
	_load = parseSimpleArray _load;
};
private _addInArsenal = _module getVariable ["AddInArsenal", false];

private _loadName = _module getVariable ["LoadName", "CustomLoad"];

if (isClass(configFile >> "CfgPatches" >> "ace_arsenal") and _addInArsenal) then {
	//ajout du load dans l'arsenal
	[_loadName, _load, true] call ace_arsenal_fnc_addDefaultLoadout;
};
_loadName = _loadName splitString ' ';
_loadName = _loadName joinString '_';
missionNamespace setVariable [("DISLoad_Var_CustomLoad_" + _loadName), _load];

if (_addInArsenal) then {
	if (isNil "DISLoad_var_AllLoad") then {
		DISLoad_var_AllLoad = [];
	};
	DISLoad_var_AllLoad pushBack _load;
};

{
	if (_x isKindOf "Man") then {
		[_load, _x] call DISLoad_fnc_SetLoad;
	} else {
		 _x addAction [format["%1", _loadName],{params ["_t", "_c", "_i", "_arguments"]; [(_arguments select 0), player] call DISLoad_fnc_SetLoad;}, [_load], 1.5,True,True,"","",5];
	};
} forEach _link;

