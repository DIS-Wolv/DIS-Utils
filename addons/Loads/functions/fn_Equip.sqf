


params ["_unit"];

if (isNil "_unit") exitWith {};
if (isNil "DISLoadMc_var_Zeus") then {[] call DISLoad_fnc_varLoads;};



switch (true) do {
	case (str(_unit) in DISLoad_var_IsZeus): {
		[DISLoadMc_var_Zeus, _unit] call DISLoad_fnc_SetLoad;
	}; //god
	case (str(_unit) in DISLoad_var_IsCdS): {
		[DISLoadMc_var_CdS, _unit] call DISLoad_fnc_SetLoad;
	}; //cds
	case (str(_unit) in DISLoad_var_IsCdG): {
		[DISLoadMc_var_CdG, _unit] call DISLoad_fnc_SetLoad;
	}; //Cdg
	case (str(_unit) in DISLoad_var_IsMedic): {
		[DISLoadMc_var_Medecin, _unit] call DISLoad_fnc_SetLoad;
	}; //Med
	case (str(_unit) in DISLoad_var_IsCdE): {
		[DISLoadMc_var_CdE, _unit] call DISLoad_fnc_SetLoad;
	}; //Cde
	case (str(_unit) in DISLoad_var_IsGv): {
		[DISLoadMc_var_GvBck, _unit] call DISLoad_fnc_SetLoad;
	}; //Gv
	case (str(_unit) in DISLoad_var_IsCdBr): {
		[DISLoadMc_var_CDBR, _unit] call DISLoad_fnc_SetLoad;
	};
	case (str(_unit) in DISLoad_var_IsCdB): {
		[DISLoadMc_var_CDB, _unit] call DISLoad_fnc_SetLoad;
	}; //CdB
	case (str(_unit) in DISLoad_var_IsEquipier): {
		[DISLoadMc_var_Equipier, _unit] call DISLoad_fnc_SetLoad;
	}; //Eq
	case (str(_unit) in DISLoad_var_IsPiloteHelo): {
		[DISLoad_var_piloteHelo, _unit] call DISLoad_fnc_SetLoad;
	}; //Ha
	case (str(_unit) in DISLoad_var_IsPiloteAvion): {
		[DISLoad_var_piloteAvions, _unit] call DISLoad_fnc_SetLoad;
	}; //Alb
	default {
		if (DISLoad_var_EquipDefaultGV) then {
			[DISLoadMc_var_GV, _unit] call DISLoad_fnc_SetLoad;
		};
	};
};

sleep 1;
