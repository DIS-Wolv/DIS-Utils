/*
* Auteur: Wolv
* Function pour récupérer les véhicules a proximité
* 
* Return Value:
* nil
*
*/
params ["_usine"];

private _range = _usine getVariable ["WOLVGARAGE_var_Range", 100];
private _pos = getPos _usine;

private _listVL = nearestObjects [_pos, ["car", "tank", "plane", "ship", "helicopter", "ReammoBox_F", "StaticWeapon"], _range];
_listVL = _listVL - WOLVGARAGE_var_BlacklistedVL;
_usine setVariable ["WOLVGARAGE_var_ListVL", _listVL, True];
_listVL;

