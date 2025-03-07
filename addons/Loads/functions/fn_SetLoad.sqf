/*
* Auteur : Wolv
* permet d'equipé un preset à un joueur
*
* Arguments :
*
* Exemple:
* [DISLoadMC_var_CDE, player] call DISLoad_fnc_SetLoad;
*
* Variable publique :
*/

params ["_Preset", "_unit"];

removeAllWeapons _unit;
removeAllItems _unit;
removeAllAssignedItems _unit;
removeUniform _unit;
removeVest _unit;
removeBackpack _unit;
removeHeadgear _unit;
removeGoggles _unit;

private _load = _Preset select 0;

// Arme Principale
private _primary = _load select 0;
if (count _primary > 0) then {
	_unit addWeapon (_primary select 0);
	_unit addPrimaryWeaponItem (_primary select 1);
	_unit addPrimaryWeaponItem (_primary select 2);
	_unit addPrimaryWeaponItem (_primary select 3);
	_unit addPrimaryWeaponItem (_primary select 4 select 0);
	_unit addPrimaryWeaponItem (_primary select 5 select 0);
	_unit addPrimaryWeaponItem (_primary select 6);
	if (_primary select 3 == 'rhsusf_acc_g33_xps3') then {
		[_unit] call DISLoad_fnc_StandardScope;
	} else {
		_unit addPrimaryWeaponItem (_primary select 3);
	};
};

// Arme Secondaire
private _secondary = _load select 1;
if (count _secondary > 0) then {
	_unit addWeapon (_secondary select 0);
	_unit addSecondaryWeaponItem (_secondary select 1);
	_unit addSecondaryWeaponItem (_secondary select 2);
	_unit addSecondaryWeaponItem (_secondary select 3);
	_unit addSecondaryWeaponItem (_secondary select 4 select 0);
	_unit addSecondaryWeaponItem (_secondary select 5 select 0);
	_unit addSecondaryWeaponItem (_secondary select 6);
};

// Hand Gun
private _HandGun = _load select 2;
if (count _HandGun > 0) then {
	_unit addWeapon (_HandGun select 0);
	_unit addHandgunItem (_HandGun select 1);
	_unit addHandgunItem (_HandGun select 2);
	_unit addHandgunItem (_HandGun select 3);
	_unit addHandgunItem (_HandGun select 4 select 0);
	_unit addHandgunItem (_HandGun select 5 select 0);
	_unit addHandgunItem (_HandGun select 6);
};

// Uniforme
private _uniform = _load select 3;
_unit forceAddUniform (_uniform select 0);
{
	for "_i" from 1 to (_x select 1) do {
		if (typeName (_x select 0) == "ARRAY") then {
			_unit addItemToUniform (_x select 0 select 0);
		} else {
			_unit addItemToUniform (_x select 0);
		};
	};
} forEach (_uniform select 1);

// Gilet
private _vest = _load select 4;
if (count _vest > 0) then {
	_unit addVest (_vest select 0);
	{
		for "_i" from 1 to (_x select 1) do {
			if (typeName (_x select 0) == "ARRAY") then {
				_unit addItemToVest (_x select 0 select 0);
			} else {
				_unit addItemToVest (_x select 0);
			};
		};
	} forEach (_vest select 1);
};

// Sac à dos
private _backpack = _load select 5;
if (count _backpack > 0) then {
	_unit addBackpack (_backpack select 0);

	{
		private _nb = (_x select 1);
		if (typeName _nb == "SCALAR") then {
			for "_i" from 1 to _nb do {
				if (typeName (_x select 0) == "ARRAY") then {
					_unit addItemToBackpack (_x select 0 select 0);
				} else {
					_unit addItemToBackpack (_x select 0);
				};
			};
		} else {
			_unit addItemToBackpack (_x select 0);
		};
	} forEach (_backpack select 1);
};
// Casque
private _helmet = _load select 6;
_unit addHeadgear _helmet;

// Lunettes
private _goggles = _load select 7;
_unit addGoggles _goggles;

// Jumelles
private _binocular = _load select 8;
if (count _binocular > 0) then {
	_unit addWeapon (_binocular select 0);
	_unit addBinocularItem (_binocular select 1);
	_unit addBinocularItem (_binocular select 2);
	_unit addBinocularItem (_binocular select 3);
	_unit addBinocularItem (_binocular select 4 select 0);
	_unit addBinocularItem (_binocular select 5 select 0);
	_unit addBinocularItem (_binocular select 6);
};
// Items
private _items = _load select 9;
{
	_unit linkItem _x;
} forEach _items;

// set des variables
private _var = _Preset select 1;


{
	_unit setVariable [_x select 0, _x select 1];
} forEach _var;

//_unit setVariable ["ace_hasearplugsin",true];

if(True) exitWith{};
