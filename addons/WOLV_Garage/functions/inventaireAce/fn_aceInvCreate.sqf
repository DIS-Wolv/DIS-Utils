


WolvGarage_var_IdcListInvAce = 1500;
WolvGarage_var_IdcListArsenalAce = 1501;
WolvGarage_var_IdcChoixVl = 2100;
WolvGarage_var_BarreInvAce = 1900;
WolvGarage_var_AceInvSize = 1101;

if (!WolvGarage_var_AceEnable) exitWith {closeDialog 0;};

private _isCreate = False;

_isCreate = createDialog "GUIgarage_InvAce";

WolvGarage_var_ListSpawn = call WolvGarage_fnc_garVlProx;

if (_isCreate) then {
	{
		lbAdd [WolvGarage_var_IdcChoixVl, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "displayName")];
		lbSetPicture [WolvGarage_var_IdcChoixVl, _forEachindex, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "picture")]
	} forEach WolvGarage_var_ListVL;

	{
		lbAdd [WolvGarage_var_IdcListArsenalAce, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
	} forEach WolvGarage_var_ItemAce;
};

((findDisplay WolvGarage_var_IddDisplayInvAce) displayCtrl WolvGarage_var_IdcChoixVl) ctrlAddEventHandler ["LBSelChanged", "call WolvGarage_fnc_aceInvUpdate"];
// Double clic pour créer le véhicule

((findDisplay WolvGarage_var_IddDisplayInvAce) displayCtrl WolvGarage_var_IdcListInvAce) ctrlAddEventHandler ["LBDblClick", "[1] call WolvGarage_fnc_aceInvRemoveItem"];
((findDisplay WolvGarage_var_IddDisplayInvAce) displayCtrl WolvGarage_var_IdcListArsenalAce) ctrlAddEventHandler ["LBDblClick", "[1] call WolvGarage_fnc_aceInvAddItem"];

