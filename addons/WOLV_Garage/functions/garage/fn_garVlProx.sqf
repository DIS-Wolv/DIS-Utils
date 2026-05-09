/*
* Auteur: Wolv
* Function pour récupérer les véhicules a proximité
* 
* Return Value:
* nil
*
*/

_listVL = nearestObjects [WOLVGARAGE_var_pos, ["car", "tank", "plane", "ship", "helicopter", "ReammoBox_F", "StaticWeapon"], WOLVGARAGE_var_Range];
_listVL = _listVL - WOLVGARAGE_var_BlacklistedVL;
_listVL;

