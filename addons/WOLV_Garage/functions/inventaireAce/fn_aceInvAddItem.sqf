/*
* Auteur: Wolv
* Fonction pour ajouter un item à l'inventaire ace
* 
* Return Value:
* nil
*
*/
params [["_nb", 1]];

private _usine = (findDisplay WOLVGARAGE_var_IddDisplayInvAce) getVariable ['WOLVGARAGE_var_Usine', objNull];

private _var_ListSpawn = _usine getVariable ["WOLVGARAGE_var_ListVL", []];
private _var_ItemAce = _usine getVariable ["WOLVGARAGE_var_ItemAce", []];

_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;						// Récupère l'index du véhicule

if ((_index != -1) and (count(_var_ListSpawn) > 0)) then {  	// Si un élément est séléctioné
	_vl = _var_ListSpawn select _index;

	_indexObj = lbCurSel WOLVGARAGE_var_IdcListArsenalAce;	
	// Récupère l'index de l'objet

	if (_indexObj != -1) then {
		_inv = _var_ItemAce select _indexObj;
		[_inv, _vl, _nb] call ace_cargo_fnc_addCargoItem;
	};
};

[] remoteExec ["WOLVGARAGE_fnc_aceInvUpdate", 0];
