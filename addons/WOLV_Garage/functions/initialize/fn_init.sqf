/*
* Auteur: Wolv
* Function pour crée un garage
* 
* Return Value:
* nil
*
*/

params [["_logic", objNull], ["_link", []]];


if(isNil "_logic") exitWith {systemChat "Erreur de création du garage"};

// private _objName = _logic getVariable ["Name", ""];

{
    // get the info object
    private _obj = _x;
    // if the info object exists
    if (!isNil "_obj") then {

        if (isNil "WOLVGARAGE_var_OBJ") then {
            WOLVGARAGE_var_OBJ = [_obj];
        } else {
            WOLVGARAGE_var_OBJ pushBack _obj;
        };
        publicVariable "WOLVGARAGE_var_OBJ";

        _obj setVariable ["WOLVGARAGE_var_Range", 100, True];

        // publicVariable pour que le serv les connaisse
        WOLVGARAGE_var_IddDisplayGarage = 0310221;
        WOLVGARAGE_var_IddDisplayInv = 0310222;
        WOLVGARAGE_var_IddDisplayInvAce = 0310223;
        publicVariable "WOLVGARAGE_var_IddDisplayGarage";
        publicVariable "WOLVGARAGE_var_IddDisplayInv";
        publicVariable "WOLVGARAGE_var_IddDisplayInvAce";

        //Liste des élements dans l'arsenal
        private _var_ListArsenal = _logic getVariable ["InventoryItem", '["30Rnd_65x39_caseless_mag","SmokeShell","Toolkit"]'];
        if (typeName _var_ListArsenal == "STRING") then {
            _var_ListArsenal = parseSimpleArray (_var_ListArsenal);
        } else { 
            if (typeName _var_ListArsenal != "ARRAY") then {
                _var_ListArsenal = ["30Rnd_65x39_caseless_mag","SmokeShell","Toolkit"];
            };
        };
        _obj setVariable ["WOLVGARAGE_var_ListArsenal", _var_ListArsenal, True];

        // définie les loads
        private _var_VlLoad = _logic getVariable ["DefaultLoad", '[["30Rnd_65x39_caseless_mag",10], ["SmokeShell",5],["Toolkit", 1]]'];
        if (typeName _var_VlLoad == "STRING") then {
            _var_VlLoad = parseSimpleArray (_var_VlLoad);
        } else { 
            if (typeName _var_VlLoad != "ARRAY") then {
                _var_VlLoad = [["30Rnd_65x39_caseless_mag",10], ["SmokeShell",5],["Toolkit", 1]];
            };
        };
        _obj setVariable ["WOLVGARAGE_var_VlLoad", _var_VlLoad, True];

        // définie les Véhicules
        private _var_ListUsine = _logic getVariable ["AvalaibleVehicle", '["B_MRAP_01_F","B_Truck_01_mover_F"]'];
        if (typeName _var_ListUsine == "STRING") then {
            _var_ListUsine = parseSimpleArray (_var_ListUsine);//
        } else { 
            if (typeName _var_ListUsine != "ARRAY") then {
                _var_ListUsine = ["B_MRAP_01_F","B_Truck_01_mover_F"];
            };
        };
        _obj setVariable ["WOLVGARAGE_var_ListUsine", _var_ListUsine, True];

        private _var_AceEnable = _logic getVariable ["AceEnable", False];
        private _var_ItemAce = [];
        _obj setVariable ["WOLVGARAGE_var_AceEnable", _var_AceEnable, True];

        if (_var_AceEnable) then {
            //Liste des élements dans l'arsenal ACE
            _var_ItemAce = _logic getVariable ["AceItem", '["ACE_medicalSupplyCrate_advanced", "ACE_Wheel", "ACE_Track", "Box_NATO_AmmoVeh_F"]'];
            if (typeName _var_ItemAce == "STRING") then {
                _var_ItemAce = parseSimpleArray (_var_ItemAce);
            } else { 
                if (typeName _var_ItemAce != "ARRAY") then {
                    _var_ItemAce = ["ACE_medicalSupplyCrate_advanced", "ACE_Wheel", "ACE_Track", "Box_NATO_AmmoVeh_F"];
                };
            };
        };
        _obj setVariable ["WOLVGARAGE_var_ItemAce", _var_ItemAce, True];

        _obj addAction ["<t color='#5c7038'>Garage</t>", {params ["_target"]; [_target] call WOLVGARAGE_fnc_garCreate},[],1.5,True,True,"", "True",5];

        private _radGar = _obj getVariable ["WOLVGARAGE_var_Range", 100]; // raduis du garrage

        private _garTrigger = createTrigger ["EmptyDetector", _obj];  //crée le trigger
        _garTrigger setTriggerArea [_radGar, _radGar, 0, false];        //definie la taille
        _garTrigger setTriggerActivation ["VEHICLE", "PRESENT", true];  //activation a la présence d'un vl
        _garTrigger setTriggerStatements ["this",
            "[this getVariable 'Usine'] remoteExec ['WOLVGARAGE_fnc_garUpdateVlProx', 0];",
            "[this getVariable 'Usine'] remoteExec ['WOLVGARAGE_fnc_garUpdateVlProx', 0];"];

        _garTrigger setVariable ["Usine", _obj, True];
        _obj setVariable ["_var_updateTrigger", _garTrigger, True];

        // liste des véhicules a proxmité
        _obj setVariable ["WOLVGARAGE_var_ListVL", [], True];
        
        // liste de tous les véhicules
        if (isNil "WOLVGARAGE_var_AllVl") then {
            WOLVGARAGE_var_AllVl = [];
        };
        publicVariable "WOLVGARAGE_var_AllVl";

        // liste des véhicules blacklisté (ignore les VL qui sont autours au moment de l'init)
        if (isNil "WOLVGARAGE_var_BlacklistedVL") then {
            WOLVGARAGE_var_BlacklistedVL = nearestObjects [[(worldSize/2),(worldSize/2)], ["car", "tank", "plane", "ship", "helicopter", "ReammoBox_F", "StaticWeapon"], worldSize];
        } else {
            WOLVGARAGE_var_BlacklistedVL pushBack (nearestObjects [[(worldSize/2),(worldSize/2)], ["car", "tank", "plane", "ship", "helicopter", "ReammoBox_F", "StaticWeapon"], worldSize]);
        };
        publicVariable "WOLVGARAGE_var_BlacklistedVL";
    };

} forEach _link;
