/*
* Auteur : Wolv
* Permet d'initialiser le HALO Jump
*
* Arguments :
* 0: OBJECT - Module
* 1: ARRAY - object syncronized
*
* Valeur renvoyée :
* nil
*/

params [["_module", objNull], ["_link", [], [[]]]];

[] call DISCommon_fnc_haloJumpinfo;

{
    _x addAction ["Saut",{[player] call DISCommon_fnc_haloJump},[],1.5,True,True,"","",5];
}foreach _link;


