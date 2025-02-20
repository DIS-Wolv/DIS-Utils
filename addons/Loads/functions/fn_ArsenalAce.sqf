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
};

if (isNil "DISLoad_var_AllLoad") then {
	DISLoad_var_AllLoad = [];
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

// en prend 1 seul de chaque
private _items = flatten (_allItemArray + _customItem + _caisseItems);
_items = (_items arrayIntersect _items) select {_x isEqualType "" && {_x != ""}};


{
    // on ajoute les items dans l'arsenal
    [_x, []] call ace_arsenal_fnc_initBox;
    [_x, _items] remoteExec ["ace_arsenal_fnc_addVirtualItems", 0, True] ;
} forEach _Link;

