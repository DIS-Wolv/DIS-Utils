
params ["_usine"];

WOLVGARAGE_var_IdcListInv = 1500;
WOLVGARAGE_var_IdcListArsenal = 1501;
WOLVGARAGE_var_IdcChoixVl = 2100;
WOLVGARAGE_var_BarreInv = 1900;

private _isCreate = False;

_isCreate = createDialog "GUIgarage_Inv";

private _var_ListArsenal = _usine getVariable ["WOLVGARAGE_var_ListArsenal", []];
private _var_ListVL = [_usine] call WOLVGARAGE_fnc_garVlProx;

if (_isCreate) then {
	if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInv)) then {
		_display = findDisplay WOLVGARAGE_var_IddDisplayInv;
		_display setVariable ["WOLVGARAGE_var_Usine", _usine];
	};

	{
		lbAdd [WOLVGARAGE_var_IdcChoixVl, format ["%1 - %2", getText (configOf _x >> "displayName"), getPlateNumber _x]];
		lbSetPicture [WOLVGARAGE_var_IdcChoixVl, _forEachindex, getText (configOf _x >> "picture")]
	} forEach _var_ListVL;

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
	} forEach _var_ListArsenal;
};

((findDisplay WOLVGARAGE_var_IddDisplayInv) displayCtrl WOLVGARAGE_var_IdcChoixVl) ctrlAddEventHandler ["LBSelChanged", "[] call WOLVGARAGE_fnc_invUpdate"];
((findDisplay WOLVGARAGE_var_IddDisplayInv) displayCtrl WOLVGARAGE_var_IdcListArsenal) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_invAddItem"];
// Double clic pour créer le véhicule
