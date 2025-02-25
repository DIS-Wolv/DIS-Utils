/*
* Auteur : Wolv
* permet de set up une caisse avec un load custom
*
* Arguments :
* 0: caisse
* 1: load
*
* Exemple:
*
* Variable publique :
*/

params [["_crate", objnull], ["_CrateLoad", []]];

clearMagazineCargoGlobal _crate;
clearWeaponCargoGlobal _crate;
clearItemCargoGlobal _crate;
clearBackpackCargoGlobal _crate;

{
	if (isClass (configFile >> "CfgWeapons" >> _x select 0)) then {
		if ((getNumber (configFile >> "CfgWeapons" >> _x select 0 >> "optics")) > 0) then {
			_crate addItemCargoGlobal [_x select 0, _x select 1];
			// systemChat 'scope';
		}
		else {
			_crate addWeaponCargoGlobal [_x select 0, _x select 1];
			// systemChat 'weapon';
		};
	}
	else {
		if (isClass (configFile >> "CfgMagazines" >> _x select 0)) then
		{
			_crate addMagazineCargoGlobal [_x select 0, _x select 1];
			// systemChat 'magazine';
		}
		else {
			if (getNumber (configFile >> "CfgVehicles" >> _x select 0 >> "isBackpack") > 0) then {
				_crate addBackpackCargoGlobal [_x select 0, _x select 1];
				// systemChat 'backpack';
			}
			else {
				_crate addItemCargoGlobal [_x select 0, _x select 1];
				// systemChat 'item';
			}
		};
	};

} forEach _CrateLoad;
