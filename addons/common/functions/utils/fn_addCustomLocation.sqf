/*
* Auteur : Wolv
* Permet de deplacer un marker sur la position d'un objet
*
* Arguments :
* 0: STRING - Nom du marker
* 1: OBJECT - Objet
* 2: BOOL - Redo (optionnel) - Si True, le marker sera mis a jour toutes les 150 secondes
*
* Valeur renvoyée :
* nil
*
* Exemple:
* ["DIS_mrk_FOB_0"] call DISCommon_fnc_addCustomLocation;
*
*/

params [["_module", objNull], ["_link",[]]];

private _pos = getPos _module;

private _name = _module getVariable ["Name","Name"];
private _type = _module getVariable ["LocType", "NameLocal"];
private _size = _module getVariable ["objectarea", "NameLocal"];

systemChat format["%1", _name];
systemChat format["%1", _type];
systemChat format["%1", _size];

private _customLoc = createLocation [_type, _pos, (_size select 0), (_size select 1)];
_customLoc setText _name;

