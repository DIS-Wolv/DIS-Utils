/*
* Auteur: Wolv
* Script pour mettre à jour la liste de l'inventaire Arma
* 
* Return Value:
* nil
*
*/

if (!isNull(findDisplay WOLVGARAGE_var_IddDisplayInv)) then {

lbClear WOLVGARAGE_var_IdcListInv;								// Nettoie la liste inventaire 
_index = lbCurSel WOLVGARAGE_var_IdcChoixVl;					// Récupère l'index du véhicule
_display = findDisplay WOLVGARAGE_var_IddDisplayInv;			// Récupère le GUI
_ctrlBar = _display displayCtrl WOLVGARAGE_var_BarreInv;		// Récupère la barre de charge du véhicule
_ctrlBar progressSetPosition 0;									// Met la progression de la barre a 0

if ((_index != -1) and (count(WOLVGARAGE_var_ListSpawn) > 0)) then {  // Si un élément est séléctioné
	_vl = WOLVGARAGE_var_ListSpawn select _index; 	// Récupère le véhicule 

	_ListInvWeap = getWeaponCargo _vl;
	{
		lbAdd [WOLVGARAGE_var_IdcListInv, 
			format ["%1 × %2", str ((_ListInvWeap select 1) select _forEachIndex), getText (configFile >> "CfgWeapons" >> _x >> "displayName")
		]];
	} forEach (_ListInvWeap select 0);
	// Récupère les armes dans l'inventaire du véhicule et les met dans la liste

	_ListInvMag = getMagazineCargo _vl;
	{
		lbAdd [WOLVGARAGE_var_IdcListInv, 
			format ["%1 × %2", str ((_ListInvMag select 1) select _forEachIndex), getText (configFile >> "CfgMagazines" >> _x >> "displayName")
		]];
	} forEach (_ListInvMag select 0);
	// Récupère les chargeurs l'inventaire du véhicule et les met dans la liste

	_ListInvItems = getItemCargo _vl;
	{
		lbAdd [WOLVGARAGE_var_IdcListInv, 
			format ["%1 × %2", str ((_ListInvItems select 1) select _forEachIndex), getText (configFile >> "CfgWeapons" >> _x >> "displayName")
		]];
	} forEach (_ListInvItems select 0);
	// Récupère les items l'inventaire du véhicule et les met dans la liste

	_ListInvBackpack = getBackpackCargo _vl;
	{
		lbAdd [WOLVGARAGE_var_IdcListInv, 
			format ["%1 × %2", str ((_ListInvBackpack select 1) select _forEachIndex), getText (configFile >> "CfgVehicles" >> _x >> "displayName")
		]];
	} forEach (_ListInvBackpack select 0);

	_ctrlBar progressSetPosition (load _vl);
	// Défini la progression de la barre de chargement
};


};
