/*
* Auteur : Wolv
* Permet de deplacer un marker sur la position d'un objet
*
* Arguments :
* 0: STRING - Nom du marker
* 1: OBJECT - Objet
* 2: BOOL - Redo (optionnel) - Si True, le marker sera mis a jour toutes les 150 secondes
*
* Valeur renvoyée :
* nil
*
* Exemple:
* ["DIS_mrk_FOB_0"] call DISCommon_fnc_markers;
*
*/
params ["_logic", "_link"];
// ["_marker", "marker_1"], ["_redo", True]
//params [["_marker", "marker_1"], ["_fob", fob], ["_redo", True]];

if (typeName _logic != "OBJECT") exitWith {};
private _marker = _logic getVariable ["MarkerName", objNull];
private _redo = _logic getVariable ["Redo", objNull];
private _delay = _logic getVariable ["Delay", 60];

if (count _link == 0) exitWith {};
_obj = _link select 0;

_marker setMarkerPos (getPos _obj);
if (_redo) then {
	if(canSuspend) then {
		sleep _delay;
	};
	[_logic, [_obj]] spawn DISCommon_fnc_markers;
};
