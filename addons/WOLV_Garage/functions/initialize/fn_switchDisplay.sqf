

params["_dest"];

_display = 0;

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayGarage)) then {
	_display = findDisplay WOLVGARAGE_var_IddDisplayGarage;
};
if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInv)) then {
	_display = findDisplay WOLVGARAGE_var_IddDisplayInv;
};
if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInvAce)) then {
	_display = findDisplay WOLVGARAGE_var_IddDisplayInvAce;
};

_display closeDisplay 1;

sleep 0.001;

switch (_dest) do {
	case 3: {
		call WOLVGARAGE_fnc_aceInvCreate;
	};
	case 2: {
		call WOLVGARAGE_fnc_invCreate;
	};
	case 1;
	default {
		call WOLVGARAGE_fnc_garCreate;
	};
};


