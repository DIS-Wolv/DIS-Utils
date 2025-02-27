/*
* Auteur : Wolv
* Permet d'initialiser la reco en drone
*
* Arguments :
* 0: OBJECT - Module
* 1: ARRAY - object syncronized
*
* Valeur renvoyée :
* nil
*/

params [["_module", objNull], ["_link", [], [[]]]];

[] call DISCommon_fnc_recoDroneinfo;

// récupération des paramètres par défaut
private _defaultDroneType = _module getVariable ["TypeDrone","B_UAV_01_F"];
private _defaultRange = _module getVariable ["DefaultRange", 2000];
private _defaultAltitude = _module getVariable ["DefaultAltitude", 200];
private _defaultPosBase = getPosATL _module;
private _defaultPos = [(_defaultPosBase select 0), (_defaultPosBase select 1), (_defaultPosBase select 2) + _defaultAltitude];
private _isArmed = _module getVariable ["IsArmed", false];


{
    _x addAction ["Reco Drone",{params ["_t", "_c", "_i", "_arguments"];_arguments call DISCommon_fnc_recoDrone;},[_defaultDroneType, _defaultRange, _defaultAltitude, _defaultPos, _isArmed],1.5,True,True,"","",5];
}forEach _link;