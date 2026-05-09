/*
* Auteur: Wolv
* Script pour supprimer le véhicule selectioné 
* 
* Return Value:
* nil
*
*/
params ["_usine"];

_index = lbCurSel WOLVGARAGE_var_IdcListVlProx; 
// Récupère l'index du véhicule

if (_index != -1) then {	
	// Si un véhicule est selectioné
	_vl = WOLVGARAGE_var_ListVL select _index;	 
	// Récupère le véhicule sélectioné
	// Supprime le véhicule
	deleteVehicle _vl;

	// Supprime le véhicule de la liste
	(owner player) publicVariableClient "WOLVGARAGE_var_AllVl";
	WOLVGARAGE_var_AllVl = WOLVGARAGE_var_AllVl - [_vl];
	publicVariableServer "WOLVGARAGE_var_AllVl";

	lbDelete [WOLVGARAGE_var_IdcListVlProx, _index];	
	// Supprime le véhicule de la liste

	WOLVGARAGE_var_ListVL deleteAt _index;
	// Supprime le véhicule de la liste des véhicules a proxmité
};
sleep 0.5;

[] remoteExec ["WOLVGARAGE_fnc_garUpdateVlProx", 0];

