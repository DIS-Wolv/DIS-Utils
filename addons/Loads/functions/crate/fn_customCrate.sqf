/*
* Auteur : Wolv
* Ajoute un loads custom dans une caisse
*
* Arguments :
* 0: module
* 1: link
* 
*/

params ["_module", "_link"];

private _crateLoad = _module getVariable ["Load", "[]"];
if (typeName _crateLoad == "STRING") then {
	_crateLoad = parseSimpleArray _crateLoad;
};

private _addInArsenal = _module getVariable ["AddInArsenal", false];
if (_addInArsenal) then {
	if (isNil "DISLoad_var_AllCrate") then {
		DISLoad_var_AllCrate = [];
	};

	DISLoad_var_AllCrate pushBack _crateLoad;
};

private _CrateName = _module getVariable ["CrateName", "CustomCrate"];
_CrateName = _CrateName splitString ' ';
_CrateName = _CrateName joinString '_';
missionNamespace setVariable [("DISLoad_Var_CustomCrate_" + _CrateName), _crateLoad];

{
	[_x, _crateLoad] call DISLoad_fnc_SetCrate;
	_x addAction ["Recharger la caisse", {params ["_t", "_c", "_i", "_arguments"]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [_crateLoad], 1.5, True, True, "", "", 5];

} forEach _link;



