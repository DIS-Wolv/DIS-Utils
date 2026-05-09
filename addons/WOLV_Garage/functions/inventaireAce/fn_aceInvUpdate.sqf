/*
* Auteur: Wolv
* Script pour mettre à jour la liste de l'inventaire 
* 
* Return Value:
* nil
*
*/

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInvAce)) then {

lbClear WOLVGARAGE_var_IdcListInvAce;								// Nettoie la liste inventaire 
_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;						// Récupère l'index du véhicule
_display = findDisplay WOLVGARAGE_var_IddDisplayInvAce;				// Récupère le GUI
_ctrlBar = _display displayCtrl WOLVGARAGE_var_BarreInvAce;			// Récupère la barre de charge du véhicule
_ctrlBar progressSetPosition 0;										// Met la progression de la barre a 0

if ((_index != -1) and (count(WOLVGARAGE_var_ListSpawn) > 0)) then {  	// Si un élément est séléctioné
	_vl = WOLVGARAGE_var_ListSpawn select _index; 						// Récupère le véhicule 

	_inv = _vl getVariable "ace_cargo_loaded";
	{
		if (typeName _x == "STRING") then {
			lbAdd [WOLVGARAGE_var_IdcListInvAce, getText (configFile >> "CfgVehicles" >> _x >> "displayName")];
		}
		else {
			lbAdd [WOLVGARAGE_var_IdcListInvAce, getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "displayName")];
		};
	} forEach _inv;

	_maxLoad = call WOLVGARAGE_fnc_aceInvSize;
	_progress = 1;
	if (_maxLoad > 0) then {
		_freeSpace = _vl getVariable "ace_cargo_space";
		_progress = ((_maxLoad - _freeSpace)/_maxLoad);
	};

	_ctrlBar progressSetPosition _progress;
	// Défini la progression de la barre de chargement
	((findDisplay WOLVGARAGE_var_IddDisplayInvAce) displayCtrl WOLVGARAGE_var_AceInvSize) ctrlSetStructuredText (parseText format["<t size='2' align='center'>Capacité : %1</t>", _maxLoad]);
};

};
