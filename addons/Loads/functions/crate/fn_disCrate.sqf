/*
* Auteur : Wolv
* Ajoute un loads custom dans une caisse
*
* Arguments :
* 0: module
* 1: link
* 
*/
private _crateLoad = [];

params ["_module","_link"];

if (isNil "DISCrate_var_dump") then {
    [] call DISLoad_fnc_VarLoads;
};

private _CrateName = _module getVariable ["CrateName", "dump"];

switch (_CrateName) do {
    case "para" : {_crateLoad = DISCrate_var_Para;};
    case "dump" : {_crateLoad = DISCrate_var_dump;};
    case "medical" : {_crateLoad = DISCrate_var_medical;};
    case "arme" : {_crateLoad = DISCrate_var_Armes;};
    case "lanceurs" : {_crateLoad = DISCrate_var_Lanceurs;};
    case "items" : {_crateLoad = DISCrate_var_Items;};
    case "itemsCe" : {_crateLoad = DISCrate_var_ItemsCe;};
    case "itemsDa" : {_crateLoad = DISCrate_var_ItemsDa;};
    default {false;};
};

if (isNil "DISLoad_var_AllCrate") then {
	DISLoad_var_AllCrate = [];
};

DISLoad_var_AllCrate append _crateLoad;

{
	[_x, _crateLoad] call DISLoad_fnc_SetCrate;
	_x addAction ["Recharger la caisse", {params ["_t", "_c", "_i", "_arguments"]; [_t, (_arguments select 0)] call DISLoad_fnc_SetCrate;}, [_crateLoad], 1.5, True, True, "", "", 5];

} forEach _link;

