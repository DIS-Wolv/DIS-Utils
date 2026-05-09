params ["_usine"];

WOLVGARAGE_var_pos = getPos _usine;
WOLVGARAGE_var_IdcListVlProx = 1500;
WOLVGARAGE_var_IdcListVlUsine = 1501;
WOLVGARAGE_var_IdcButtonSpawn = 1603;
WOLVGARAGE_var_IdcButtonParadrop = 1604;
WOLVGARAGE_var_IdcButtonDelete = 1605;

private _isCreate = False;

_isCreate = createDialog "GUIgarage_Garage";

private _var_ListUsine = _usine getVariable ["WOLVGARAGE_var_ListUsine", []];


if (_isCreate) then {
	{
		lbAdd [WOLVGARAGE_var_IdcListVlUsine, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
		if (getText (configFile >> "CfgVehicles" >> _x >> "picture") != "pictureThing") then 
		{
			lbSetPicture [WOLVGARAGE_var_IdcListVlUsine, _forEachindex, getText (configFile >> "CfgVehicles" >> _x >> "picture")];
		}
	} forEach _var_ListUsine;

	call WOLVGARAGE_fnc_garUpdateVlProx;

};


((findDisplay WOLVGARAGE_var_IddDisplayGarage) displayCtrl WOLVGARAGE_var_IdcListVlUsine) ctrlAddEventHandler ["LBDblClick", "call WOLVGARAGE_fnc_garSpawnVl"];
// Double clic pour créer le véhicule


