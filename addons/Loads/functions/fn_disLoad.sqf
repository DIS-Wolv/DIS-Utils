/*
* Auteur : Wolv
* Ajoute des loads DIS
*
* Arguments :
* 0: module
* 1: link
* 
*/
params ["_module","_link"];

private _loadInfo = _module getVariable ["LoadName", ""];
_loadInfo = parseSimpleArray _loadInfo;

private _loadName = _loadInfo select 0;
private _LoadText = _loadInfo select 1;

if (isNil _loadName) then {
    [] call DISLoad_fnc_VarLoads;
};
private _load = missionNamespace getVariable [_loadName, []];


{
    if (_x isKindOf "Man") then {
		[_load, _x] call DISLoad_fnc_SetLoad;
	} else {
		 _x addAction [Format["%1", _LoadText],{params ["_t", "_c", "_i", "_arguments"]; [(_arguments select 0), player] call DISLoad_fnc_SetLoad;}, [_load], 1.5,True,True,"","",5];
	};
} forEach _link;

