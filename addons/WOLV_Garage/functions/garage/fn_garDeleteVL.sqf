/*
* Auteur: Wolv
* Script pour supprimer le véhicule selectioné 
* 
* Return Value:
* nil
*
*/

private _usine = (findDisplay WOLVGARAGE_var_IddDisplayGarage) getVariable ['WOLVGARAGE_var_Usine', objNull];

_index = lbCurSel WOLVGARAGE_var_IdcListVlProx;
// Récupère l'index du véhicule

private _var_ListVL = _usine getVariable ["WOLVGARAGE_var_ListVL", []];

if (_index != -1) then {
	// Si un véhicule est selectioné
	_vl = _var_ListVL select _index;
	// Récupère le véhicule sélectioné
	// Supprime le véhicule
	deleteVehicle _vl;

	// Supprime le véhicule de la liste
	(owner player) publicVariableClient "WOLVGARAGE_var_AllVl";
	WOLVGARAGE_var_AllVl = WOLVGARAGE_var_AllVl - [_vl];
	publicVariableServer "WOLVGARAGE_var_AllVl";

	lbDelete [WOLVGARAGE_var_IdcListVlProx, _index];
	// Supprime le véhicule de la liste

	_var_ListVL deleteAt _index;
	_usine setVariable ["WOLVGARAGE_var_ListVL", _var_ListVL, True];
	[_usine] call WOLVGARAGE_fnc_garUpdateVlProx;
	// Supprime le véhicule de la liste des véhicules a proxmité
};
sleep 0.5;

[] remoteExec ["WOLVGARAGE_fnc_garUpdateVlProx", 0];

