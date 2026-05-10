
params ["_usine"];

WOLVGARAGE_var_IdcListInvAce = 1500;
WOLVGARAGE_var_IdcListArsenalAce = 1501;
WOLVGARAGE_var_IdcChoixVl = 2100;
WOLVGARAGE_var_BarreInvAce = 1900;
WOLVGARAGE_var_IdcAceInvSize = 1101;

private _AceEnable = _usine getVariable ["WOLVGARAGE_var_AceEnable", False];
if (!_AceEnable) exitWith {closeDialog 0;};

private _isCreate = False;

_isCreate = createDialog "GUIgarage_InvAce";

private _var_ListArsenalAce = _usine getVariable ["WOLVGARAGE_var_ItemAce", []];
private _var_ListVL = [_usine] call WOLVGARAGE_fnc_garVlProx;

if (_isCreate) then {
	if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInvAce)) then {
		_display = findDisplay WOLVGARAGE_var_IddDisplayInvAce;
		_display setVariable ["WOLVGARAGE_var_Usine", _usine];
	};

	{
		lbAdd [WOLVGARAGE_var_IdcChoixVl, format ["%1 - %2", getText (configOf _x >> "displayName"), getPlateNumber _x]];
		lbSetPicture [WOLVGARAGE_var_IdcChoixVl, _forEachindex, getText (configOf _x >> "picture")]
	} forEach _var_ListVL;

	{
		lbAdd [WOLVGARAGE_var_IdcListArsenalAce, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
	} forEach _var_ListArsenalAce;
};

((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcChoixVl) ctrlAddEventHandler ["LBSelChanged", "[] call WOLVGARAGE_fnc_aceInvUpdate"];
// Double clic pour créer le véhicule

((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcListInvAce) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_aceInvRemoveItem"];
((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcListArsenalAce) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_aceInvAddItem"];

