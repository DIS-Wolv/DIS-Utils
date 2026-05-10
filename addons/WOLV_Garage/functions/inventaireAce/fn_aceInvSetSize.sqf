/*
* Auteur: Wolv
* Script pour mettre à jour la liste de l'inventaire 
* 
* Return Value:
* nil
*
*/
params [["_mod", 10]];

private _usine = (findDisplay WOLVGARAGE_var_IddDisplayInvAce) getVariable ['WOLVGARAGE_var_Usine', objNull];
private _var_ListSpawn = _usine getVariable ["WOLVGARAGE_var_ListVL", []];

_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;						// Récupère l'index du véhicule

if ((_index != -1) and (count(_var_ListSpawn) > 0)) then {  	// Si un élément est séléctioné
	_vl = _var_ListSpawn select _index;
	_maxLoad = [] call WOLVGARAGE_fnc_aceInvSize;


	if (_maxLoad >= 0) then {
		_newMax = round (_maxLoad + _mod);
		_freeSpace = _vl getVariable "ace_cargo_space";
		
		_newMax = _newMax max (_maxLoad - _freeSpace);
		_newMax = _newMax min 100;
		//limite basse
		[_vl, _newMax] call ace_cargo_fnc_setSpace;
	};

};

[] remoteExec ["WOLVGARAGE_fnc_aceInvUpdate", 0];
