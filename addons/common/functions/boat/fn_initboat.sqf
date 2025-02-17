/*
* Auteur : Wolv
* Permet d'initialiser le spawn des bateau
*
* Arguments :
* 0: OBJECT - Module
* 1: ARRAY - object syncronized
*
* Valeur renvoyée :
* nil
*/
params [["_module", objNull],["_link",[]]];

private _pos = getPos _module;
private _defaultBoatType = _module getVariable ["BoatName", "B_Boat_Transport_01_F"]; // rhsgref_hidf_rhib

{
    _x addAction ["Spawn Boat",{params ["_t", "_c", "_i", "_arguments"]; _arguments call DISCommon_fnc_createBoat;},[_pos, _defaultBoatType],1.5,True,True,"","",5];
    _x addAction ["Delete Boat",{params ["_t", "_c", "_i", "_arguments"]; _arguments call DISCommon_fnc_deleteBoats;},[_pos, _defaultBoatType],1.5,True,True,"","",5];
} foreach _link;


