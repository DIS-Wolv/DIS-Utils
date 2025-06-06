

_index = lbCurSel WolvGarage_var_IdcListVlUsine;
if (_index != -1) then { 
	_vlType = (WolvGarage_var_ListUsine select _index);
	_pos = WolvGarage_var_pos findEmptyPosition [5, 100, _vlType];

	if ((count _pos) != 0) then {
		// Crée le véhicule
		_vl = _vlType createVehicle _pos;

		// Ajoute le véhicule à la liste des véhicules
		(owner player) publicVariableClient "WolvGarage_var_AllVl";
		WolvGarage_var_AllVl pushBack _vl;
		publicVariableServer "WolvGarage_var_AllVl";

		//vide le véhicule
		clearWeaponCargoGlobal _vl;
		clearMagazineCargoGlobal _vl;
		clearBackpackCargoGlobal _vl;
		clearItemCargoGlobal _vl;

		
		{
			_vl addItemCargoGlobal [(_x select 0), (_x select 1)];
		}forEach WolvGarage_var_VlLoad;

		// Set de la plaque d'immatriculation
		_plate = ["DIS-"];
		for "_i" from 0 to 2 do {
			_plate pushBack (floor random 10);
		};
		_plate pushBack "-";
		_plate pushBack (toUpper ((((groupId (group player)) splitString "") select [0,3]) joinString ''));
		_vl setPlateNumber ( _plate joinString "");
		
		if (WolvGarage_var_AceEnable) then {

			[_vl, 30] call ace_cargo_fnc_setSpace; //force la taille du cargo a 30

			["ACE_medicalSupplyCrate_advanced", _vl, 1] call ace_cargo_fnc_addCargoItem;
			// Ajoute une caisse medicale ACE dans l'inventaire ACE du véhicule

			private _inv = (_vl getVariable "ace_cargo_loaded") select 0;
			// Récupère le premier élément de l'inventaire ACE

			if (!isNil "_inv") then {
				if (_inv != "ACE_medicalSupplyCrate_advanced" ) then {
					[_inv, _vl, 3] call ace_cargo_fnc_addCargoItem;
				};
				// Ajoute 3 roues ou chenilles de rechange
			};
		};
	} 
	else {
		systemChat "Pas de position libre";
	};
};

[] remoteExec ["WolvGarage_fnc_garUpdateVlProx", 0];

