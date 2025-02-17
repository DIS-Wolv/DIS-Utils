/*
* Auteur : Wolv
* Permet de supprimer le bateaus sur la position
*
* Arguments :
* 0 : ARRAY : position
* 
* Exemple:
* [] call DISCommon_fnc_deleteBoat;
*
*/
params [["_boatSpawn", [0,0,0]], ["_boatType", "B_Boat_Transport_01_F"]];

private _allBoats = nearestObjects [_boatSpawn, [_boatType], 250, True];

{
	deleteVehicle _x
} forEach _allBoats;
