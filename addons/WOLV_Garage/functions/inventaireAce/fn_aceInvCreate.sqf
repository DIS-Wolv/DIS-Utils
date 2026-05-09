


WOLVGARAGE_var_IdcListInvAce = 1500;
WOLVGARAGE_var_IdcListArsenalAce = 1501;
WOLVGARAGE_var_IdcChoixVl = 2100;
WOLVGARAGE_var_BarreInvAce = 1900;
WOLVGARAGE_var_AceInvSize = 1101;

if (!WOLVGARAGE_var_AceEnable) exitWith {closeDialog 0;};

private _isCreate = False;

_isCreate = createDialog "GUIgarage_InvAce";

WOLVGARAGE_var_ListSpawn = call WOLVGARAGE_fnc_garVlProx;

if (_isCreate) then {
	{
		lbAdd [WOLVGARAGE_var_IdcChoixVl, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "displayName")];
		lbSetPicture [WOLVGARAGE_var_IdcChoixVl, _forEachindex, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "picture")]
	} forEach WOLVGARAGE_var_ListVL;

	{
		lbAdd [WOLVGARAGE_var_IdcListArsenalAce, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
	} forEach WOLVGARAGE_var_ItemAce;
};

((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcChoixVl) ctrlAddEventHandler ["LBSelChanged", "call WOLVGARAGE_fnc_aceInvUpdate"];
// Double clic pour créer le véhicule

((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcListInvAce) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_aceInvRemoveItem"];
((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_IdcListArsenalAce) ctrlAddEventHandler ["LBDblClick", "[1] call WOLVGARAGE_fnc_aceInvAddItem"];

