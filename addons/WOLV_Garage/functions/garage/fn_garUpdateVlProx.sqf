/*
* Auteur: Wolv
* Function pour mettre a jour les vls a proximité
* 
* Return Value:
* nil
*
*/
params [["_usine", objNull]];

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayGarage)) then {
	if (isNull _usine) then {
		_usine = (findDisplay WOLVGARAGE_var_IddDisplayGarage) getVariable ["WOLVGARAGE_var_Usine", objNull];
	};

	lbClear WOLVGARAGE_var_IdcListVlProx;

	_var_ListVL = [_usine] call WOLVGARAGE_fnc_garVlProx;

	{
		lbAdd [WOLVGARAGE_var_IdcListVlProx, format["%1 - %2", getText (configOf _x >> "displayName"), getPlateNumber _x]];
		if (getText (configOf _x >> "picture") != "pictureThing") then 
		{
			lbSetPicture [WOLVGARAGE_var_IdcListVlProx, _forEachindex, getText (configOf _x >> "picture")];
		}
	} forEach _var_ListVL;

};

