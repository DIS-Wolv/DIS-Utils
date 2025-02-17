/*
* Auteur : Wolv
* Permet de créer un bateau sur la position
*
* Arguments :
* 0 : ARRAY : position
* 
* Valeur renvoyée :
* OBJECT : bateau
*
* Exemple:
* [] call DISCommon_fnc_createBoat;
*
*/
params [["_pos", [0,0,0]], ["_boatType", "B_Boat_Transport_01_F"]];

private _nbBoat = count nearestObjects [_pos, [_boatType], 25, True];
private _boat = objNull;

if (_nbBoat > 3) 
then {
	systemChat "Trop de bateaux, eloignez les bateaux !";
	sleep 10;
	hintSilent "";
}
else {
	_boat = createVehicle [_boatType, _pos, [], 5, "CAN_COLLIDE"];
};

_boat;
