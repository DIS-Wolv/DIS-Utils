/*
* Auteur: Wolv
* Function pour mettre a jour les vls a proximité
* 
* Return Value:
* nil
*
*/

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayGarage)) then {

lbClear WOLVGARAGE_var_IdcListVlProx;

WOLVGARAGE_var_ListVL = call WOLVGARAGE_fnc_garVlProx;

{
	lbAdd [WOLVGARAGE_var_IdcListVlProx, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "displayName")];
	if (getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "picture") != "pictureThing") then 
	{
		lbSetPicture [WOLVGARAGE_var_IdcListVlProx, _forEachindex, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "picture")];
	}
} forEach WOLVGARAGE_var_ListVL;

};
