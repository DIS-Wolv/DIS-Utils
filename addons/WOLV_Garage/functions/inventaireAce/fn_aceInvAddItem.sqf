/*
* Auteur: Wolv
* Fonction pour ajouter un item à l'inventaire ace
* 
* Return Value:
* nil
*
*/
params [["_nb", 1]];

_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;						// Récupère l'index du véhicule

if ((_index != -1) and (count(WOLVGARAGE_var_ListSpawn) > 0)) then {  	// Si un élément est séléctioné
	_vl = WOLVGARAGE_var_ListSpawn select _index;

	_indexObj = lbCurSel WOLVGARAGE_var_IdcListArsenalAce;	
	// Récupère l'index de l'objet

	if (_indexObj != -1) then {
		_inv = WOLVGARAGE_var_ItemAce select _indexObj;
		[_inv, _vl, _nb] call ace_cargo_fnc_addCargoItem;
	};
};

[] remoteExec ["WOLVGARAGE_fnc_aceInvUpdate", 0];
