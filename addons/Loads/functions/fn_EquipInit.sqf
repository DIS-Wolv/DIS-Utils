/*
* Auteur : Wolv
* Equip des unité avec des loads par défaut
*
* Arguments :
* 0: module
* 1: link
* 
*/
params ["_module","_link"];

private _isZeus = _module getVariable ["IsZeus", "[""""]"];
private _isCdS = _module getVariable ["IsCdS", "[""""]"];
private _isCdG = _module getVariable ["IsCdG", "[""""]"];
private _isMedic = _module getVariable ["IsMedic", "[""""]"];
private _isCdE = _module getVariable ["IsCdE", "[""""]"];
private _isGv = _module getVariable ["IsGv", "[""""]"];
private _isCdBr = _module getVariable ["IsCdBr", "[""""]"];
private _isCdB = _module getVariable ["IsCdB", "[""""]"];
private _isEquipier = _module getVariable ["IsEquipier", "[""""]"];
private _isPiloteHelo = _module getVariable ["IsPiloteHelo", "[""""]"];
private _isPiloteAvion = _module getVariable ["IsPiloteAvion", "[""""]"];

DISLoad_var_EquipDefaultGV = _module getVariable ["DefaultGV", True];

private _allLoad = [_isZeus, _isCdS, _isCdG, _isMedic, _isCdE, _isGv, _isCdBr, _isCdB, _isEquipier, _isPiloteHelo, _isPiloteAvion];

{
    if (typeName _x == "STRING") then {
        _x = parseSimpleArray _x;
    };
} forEach _allLoad;


DISLoad_var_IsZeus = _isZeus;
DISLoad_var_IsCdS = _isCdS;
DISLoad_var_IsCdG = _isCdG;
DISLoad_var_IsMedic = _isMedic;
DISLoad_var_IsCdE = _isCdE;
DISLoad_var_IsGv = _isGv;
DISLoad_var_IsCdBr = _isCdBr;
DISLoad_var_IsCdB = _isCdB;
DISLoad_var_IsEquipier = _isEquipier;
DISLoad_var_IsPiloteHelo = _isPiloteHelo;
DISLoad_var_IsPiloteAvion = _isPiloteAvion;

{
    [_x] call DISLoad_fnc_Equip;
} forEach allPlayers;
