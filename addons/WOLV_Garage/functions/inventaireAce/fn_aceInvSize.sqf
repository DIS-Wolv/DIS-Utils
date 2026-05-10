/*
* Auteur: Wolv
* Script pour mettre à jour la liste de l'inventaire 
* 
* Return Value:
* nil
*
*/

private _maxLoad = -1;

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInvAce)) then {

private _usine = (findDisplay WOLVGARAGE_var_IddDisplayInvAce) getVariable ['WOLVGARAGE_var_Usine', objNull];
private _var_ListSpawn = _usine getVariable ["WOLVGARAGE_var_ListVL", []];

_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;						// Récupère l'index du véhicule

_maxLoad = -1;

if ((_index != -1) and (count(_var_ListSpawn) > 0)) then {  	// Si un élément est séléctioné
	_vl = _var_ListSpawn select _index; 						// Récupère le véhicule 

	_inv = _vl getVariable "ace_cargo_loaded";
	_weight = 0;
	{
		if (typeName _x == "STRING") then {
			_weight = _weight + getNumber (configFile >> "CfgVehicles" >> _x >> "ace_cargo_size");
		}
		else {
			_weight = _weight + getNumber (configFile >> "CfgVehicles" >> (typeOf _x) >> "ace_cargo_size");
		};
	} forEach _inv;

	_freeSpace = _vl getVariable "ace_cargo_space";
	_maxLoad = (_weight + _freeSpace);

};
};

_maxLoad;
