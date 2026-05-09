


WOLVGARAGE_var_IdcListInv = 1500;
WOLVGARAGE_var_IdcListArsenal = 1501;
WOLVGARAGE_var_IdcChoixVl = 2100;
WOLVGARAGE_var_BarreInv = 1900;

private _isCreate = False;

_isCreate = createDialog "GUIgarage_Inv";

WOLVGARAGE_var_ListSpawn = call WOLVGARAGE_fnc_garVlProx;

if (_isCreate) then {
	{
		lbAdd [WOLVGARAGE_var_IdcChoixVl, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "displayName")];
		lbSetPicture [WOLVGARAGE_var_IdcChoixVl, _forEachindex, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "picture")]
	} forEach WOLVGARAGE_var_ListVL;

	{
		if (getNumber (configFile >> "CfgVehicles" >> _x >> "isBackpack") > 0) then {
			_index = lbAdd [WOLVGARAGE_var_IdcListArsenal, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
			lbSetData [WOLVGARAGE_var_IdcListArsenal, _index, "backpack"];
		} else {
			if (isClass (configFile >> "CfgWeapons" >> _x)) then {
				lbAdd [WOLVGARAGE_var_IdcListArsenal, getText (configFile >> "CfgWeapons" >> _x >> "displayName")];
			}
			else {
				lbAdd [WOLVGARAGE_var_IdcListArsenal, getText (configFile >> "CfgMagazines" >> _x >> "displayName")];
			};
		};
	} forEach WOLVGARAGE_var_ListArsenal;
};

((findDisplay WOLVGARAGE_var_IddDisplayInv) displayCtrl WOLVGARAGE_var_IdcChoixVl) ctrlAddEventHandler ["LBSelChanged", "call WOLVGARAGE_fnc_invUpdate"];
((findDisplay WOLVGARAGE_var_IddDisplayInv) displayCtrl WOLVGARAGE_var_IdcListArsenal) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_invAddItem"];
// Double clic pour créer le véhicule
