/*
* Auteur : Wolv
* Ajoute des loads DIS sur un objets
*
* Arguments :
* 0: module
* 1: link
* 
*/
params ["_module","_link"];

private _loadType = _module getVariable ["LoadName", ""];

if (isNull _loadType) exitWith {False;};

{
    switch (_loadType) do {
        case "Infanterie": {
            _x addAction ["GV",{[DISLoadMc_var_GV,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Gv Sac",{[DISLoadMc_var_GvBck,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Grenadier",{[DISLoadMc_var_Grenadier,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Minimi 5.56",{[DISLoadMc_var_Minimi5,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Minimi 7.62",{[DISLoadMc_var_Minimi7,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Chef d'Equipe",{[DISLoadMc_var_CdE,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Chef de Groupe",{[DISLoadMc_var_CdG,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Chef de Section",{[DISLoadMc_var_CdS,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Medecin",{[DISLoadMc_var_Medecin,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["EOD",{[DISLoadMc_var_EOD,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["EOD Light",{[DISLoadMc_var_EOD_Light,_this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
        };
        case "Cavalerie": {
            _x addAction ["Chef de Bord (médecin)",{[DISLoadMc_var_CDB, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Chef de Bord (groupe d'infanterie)",{[DISLoadMc_var_CDBR, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Equipier",{[DISLoadMc_var_Equipier, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
        };
        case "Plongeur": {
            _x addAction ["CdG (Plongeur)",{[DISLoadPL_var_CDG, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
	        _x addAction ["CdE (Plongeur)",{[DISLoadPL_var_CDE, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
	        _x addAction ["GV (Plongeur)",{[DISLoadPL_var_GV, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
	        _x addAction ["Minimi (Plongeur)",{[DISLoadPL_var_Minimi5, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
	        _x addAction ["Médecin (Plongeur)",{[DISLoadPL_var_Medecin, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
        };
        case "Pilote": {
            _x addAction ["Hélicoptère",{[DISLoad_var_piloteHelo, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
            _x addAction ["Chasseur",{[DISLoad_var_piloteAvions, _this select 1] call DISLoad_fnc_SetLoad;},[],1.5,True,True,"","",5];
        };
    };
} forEach _link;

