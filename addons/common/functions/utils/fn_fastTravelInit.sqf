/*
* Auteur : Wolv
* Initialise le fast travel
*
* Arguments :
* 0: OBJECT - Module
* 1: ARRAY - object syncronized
*
* Valeur renvoyée :
* nil
*/
params [["_module", objNull], ["_link", []]];

private _pos = getPosATL _module;
private _name = _module getVariable ["Name","Name"];

{
    _x addAction [Format["%1", _name],{params ["_t", "_c", "_i", "_arguments"]; _arguments call DISCommon_fnc_fastTravel;}, [_pos], 1.5,True,True,"","",5];
} foreach _link;
