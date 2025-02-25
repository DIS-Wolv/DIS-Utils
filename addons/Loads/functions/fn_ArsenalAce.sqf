/*
* Auteur : Wolv
* permet de set up l'arsenal Ace
*
* Arguments :
* 0: module
* 1: link
*
* Exemple:
* [] call DISLoad_fnc_ArsenalAce;
*
* Variable publique :
*/
params ["_Module", "_Link"];

if (!(isClass(configFile >> "CfgPatches" >> "ace_arsenal"))) exitWith {systemChat "Erreur : Ace Arsenal n'est pas charger"};


private _loadDIS = _Module getVariable ["LoadDIS", false];
if (isNil "DISLoad_var_piloteAvions" and _loadDIS) then {
    [] call DISLoad_fnc_Varloads;

    if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
        //ajout de tout les loads dans l'arsenal
        ["Pilote Helico", DISLoad_var_piloteHelo, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["Pilote Avions", DISLoad_var_piloteAvions, true] call ace_arsenal_fnc_addDefaultLoadout;

        ["MC CDB", DISLoadMc_var_CDBR, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC CDB(inf)", DISLoadMc_var_CDBR, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Equipier", DISLoadMc_var_Equipier, true] call ace_arsenal_fnc_addDefaultLoadout;

        ["MC CdS", DISLoadMc_var_CdS, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC CdG", DISLoadMc_var_CdG, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC CdG Médecin", DISLoadMc_var_CdGM, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Medecin", DISLoadMc_var_Medecin, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC CdE", DISLoadMc_var_CDB, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC EOD", DISLoadMc_var_EOD, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC EOD Light", DISLoadMc_var_EOD_Light, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Grenadier", DISLoadMc_var_Grenadier, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC GvBck", DISLoadMc_var_GvBck, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC GV", DISLoadMc_var_GV, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Minimi5", DISLoadMc_var_Minimi5, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Minimi7", DISLoadMc_var_Minimi7, true] call ace_arsenal_fnc_addDefaultLoadout;

        ["MC TP", DISLoadMc_var_TP, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC TE", DISLoadMC_var_TE, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Spotter", DISLoadMC_var_Spotter, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["MC Zeus", DISLoadMc_var_Zeus, true] call ace_arsenal_fnc_addDefaultLoadout;

        ["PL CDG", DISLoadPL_var_CDG, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["PL CDE", DISLoadPL_var_CDE, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["PL Medecin", DISLoadPL_var_Medecin, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["PL GV", DISLoadPL_var_GV, true] call ace_arsenal_fnc_addDefaultLoadout;
        ["PL Minimi5", DISLoadPL_var_Minimi5, true] call ace_arsenal_fnc_addDefaultLoadout;
    };
};

if (isNil "DISLoad_var_AllLoad") then {
	DISLoad_var_AllLoad = [];
};

if (isNil "DISLoad_var_AllCrate") then {
	DISLoad_var_AllCrate = [];
};

private _customItem = _Module getVariable ["CustomItem", []];
if (typeName _customItem == "STRING") then {
	_customItem = parseSimpleArray _customItem;
};


private _DIScrate = _Module getVariable ["CrateDIS", false];

private _caisseItems = [];
if (_DIScrate) then {
    systemChat "DIScrate";
    // récup tout les items des caisses
    private _caisse = 'B_supplyCrate_F' createVehicle [0,0,0];
    // Caisse Armes
    [_caisse] call DISLoadCrate_fnc_armes;
    sleep 1;
    _caisseItems pushBack ((getItemCargo _caisse) select 0);
    _caisseItems pushBack ((getWeaponCargo _caisse) select 0);
    _caisseItems pushBack ((getMagazineCargo _caisse) select 0);
    _caisseItems pushBack ((getBackPackCargo _caisse) select 0);

    // caisse Tube
    [_caisse] call DISLoadCrate_fnc_lanceurs;
    sleep 1;
    _caisseItems pushBack ((getItemCargo _caisse) select 0);
    _caisseItems pushBack ((getWeaponCargo _caisse) select 0);
    _caisseItems pushBack ((getMagazineCargo _caisse) select 0);
    _caisseItems pushBack ((getBackPackCargo _caisse) select 0);

    // caisse Medical
    [_caisse] call DISLoadCrate_fnc_medical;
    sleep 1;
    _caisseItems pushBack ((getItemCargo _caisse) select 0);
    _caisseItems pushBack ((getWeaponCargo _caisse) select 0);
    _caisseItems pushBack ((getMagazineCargo _caisse) select 0);
    _caisseItems pushBack ((getBackPackCargo _caisse) select 0);

    // caisse Items
    [_caisse] call DISLoadCrate_fnc_items;
    sleep 0.1;
    _caisseItems pushBack ((getItemCargo _caisse) select 0);
    _caisseItems pushBack ((getWeaponCargo _caisse) select 0);
    _caisseItems pushBack ((getMagazineCargo _caisse) select 0);
    _caisseItems pushBack ((getBackPackCargo _caisse) select 0);

    // caisse para
    [_caisse] call DISLoadCrate_fnc_para;
    sleep 0.1;
    _caisseItems pushBack ((getItemCargo _caisse) select 0);
    _caisseItems pushBack ((getWeaponCargo _caisse) select 0);
    _caisseItems pushBack ((getMagazineCargo _caisse) select 0);
    _caisseItems pushBack ((getBackPackCargo _caisse) select 0);

    deleteVehicle _caisse;
};

// récup tout les items des loads
private _allItemArray = [];
{
    _allItemArray pushBack _x;
} forEach DISLoad_var_AllLoad;

// récup tout les items des caisses
{
    _allItemArray pushBack _x;
} forEach DISLoad_var_AllCrate;

// en prend 1 seul de chaque
private _items = flatten (_allItemArray + _customItem + _caisseItems);
_items = (_items arrayIntersect _items) select {_x isEqualType "" && {_x != ""}};


{
    // on ajoute les items dans l'arsenal
    [_x, []] call ace_arsenal_fnc_initBox;
    [_x, _items] remoteExec ["ace_arsenal_fnc_addVirtualItems", 0, True] ;
} forEach _Link;

