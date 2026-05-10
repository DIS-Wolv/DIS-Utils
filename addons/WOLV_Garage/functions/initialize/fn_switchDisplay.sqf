

params["_dest"];

private _display = 0;

private _usine = objNull;

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayGarage)) then {
	_usine = (findDisplay WOLVGARAGE_var_IddDisplayGarage) getVariable ["WOLVGARAGE_var_Usine", objNull];
	_display = findDisplay WOLVGARAGE_var_IddDisplayGarage;
};
if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInv)) then {
	_usine = (findDisplay WOLVGARAGE_var_IddDisplayInv) getVariable ["WOLVGARAGE_var_Usine", objNull];
	_display = findDisplay WOLVGARAGE_var_IddDisplayInv;
};
if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInvAce)) then {
	_usine = (findDisplay WOLVGARAGE_var_IddDisplayInvAce) getVariable ["WOLVGARAGE_var_Usine", objNull];
	_display = findDisplay WOLVGARAGE_var_IddDisplayInvAce;
};

_display closeDisplay 1;

sleep 0.001;

switch (_dest) do {
	case 3: {
		[_usine] call WOLVGARAGE_fnc_aceInvCreate;
	};
	case 2: {
		[_usine] call WOLVGARAGE_fnc_invCreate;
	};
	case 1;
	default {
		[_usine] call WOLVGARAGE_fnc_garCreate;
	};
};


