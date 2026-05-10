/*
* Auteur: Wolv
* Script pour ajouter x items dans l'inventaire
* 
* Argument :
* 0: nombre d'éléments à ajouter
* 
* Return Value:
* nil
*
*/
params [["_Nb", 1]];

private _usine = (findDisplay WOLVGARAGE_var_IddDisplayInv) getVariable ['WOLVGARAGE_var_Usine', objNull];

private _var_ListVL = _usine getVariable ["WOLVGARAGE_var_ListVL", []];
private _var_ListArsenal = _usine getVariable ["WOLVGARAGE_var_ListArsenal", []];

_indexVL = lbCurSel WOLVGARAGE_var_IdcChoixVl;
// Récupère l'index du véhicule

if (_indexVL != -1) then {	
	// Si un véhicule est séléctioné
	_vl = _var_ListVL select _indexVL;	
	// Récupère le véhicule 

	_indexObj = lbCurSel WOLVGARAGE_var_IdcListArsenal;	
	// Récupère l'index de l'objet

	// Si un objet est séléctioné 
	if (_indexObj != -1) then {
		_isBackpack = lbData [WOLVGARAGE_var_IdcListArsenal, _indexObj];

		// Si c'est un sac à dos
		if (_isBackpack != "") then {
			// Ajoute le sac à dos au véhicule
			if((maxLoad _vl - loadAbs _vl) >= (getNumber (configFile >> "CfgVehicles" >>  _var_ListArsenal select _indexObj >> "mass") * _Nb)) then { 
			// Vérifie s'il y a la place
				// Ajoute l'arme au véhicule
				_vl addBackpackCargoGlobal [_var_ListArsenal select _indexObj, _nb];
			};
		} else {
			if (isClass (configFile >> "CfgWeapons" >> _var_ListArsenal select _indexObj)) then {
			// Si c'est une arme
				if((maxLoad _vl - loadAbs _vl) >= (getNumber (configFile >> "CfgWeapons" >>  _var_ListArsenal select _indexObj >> "WeaponSlotsInfo" >> "mass") * _Nb)) then { 
				// Vérifie s'il y a la place
					// Ajoute l'arme au véhicule
					_vl addItemCargoGlobal [ _var_ListArsenal select _indexObj, _nb];	
				};
			} else {
			// Si c'est un chargeur
				if((maxLoad _vl - loadAbs _vl) >= (getNumber (configFile >> "CfgMagazines" >>  _var_ListArsenal select _indexObj >> "mass") * _Nb)) then { 
				// Vérifie s'il y a la place
					_vl addItemCargoGlobal [ _var_ListArsenal select _indexObj, _nb]; 
					// Ajoute le chargeur au véhicule 
				};
			};
		};
	};
};

[] remoteExec ["WOLVGARAGE_fnc_invUpdate", 0];
// Met à jour la liste des inventaires
