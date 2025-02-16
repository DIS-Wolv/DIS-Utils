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

// get the info object
private _obj = _link select 0;
// if the info object exists
if (!isNil "_obj") then {

    WolvGarage_var_OBJ = _obj;
    WolvGarage_var_Range = 100;
    WolvGarage_var_IddDisplayGarage = 0310221;
    WolvGarage_var_IddDisplayInv = 0310222;
    WolvGarage_var_IddDisplayInvAce = 0310223;

    // publicVariable pour que le serv les connaisse
    publicVariable "WolvGarage_var_Range";
    publicVariable "WolvGarage_var_IddDisplayGarage";
    publicVariable "WolvGarage_var_IddDisplayInv";
    publicVariable "WolvGarage_var_IddDisplayInvAce";

    //Liste des élements dans l'arsenal
    WolvGarage_var_ListArsenal = _logic getVariable ["InventoryItem", '["30Rnd_65x39_caseless_mag","SmokeShell","Toolkit"]'];
    if (typeName WolvGarage_var_ListArsenal == "STRING") then {
        WolvGarage_var_ListArsenal = parseSimpleArray (WolvGarage_var_ListArsenal);//
    } else { 
        if (typeName WolvGarage_var_ListArsenal != "ARRAY") then {
            WolvGarage_var_ListArsenal = ["30Rnd_65x39_caseless_mag","SmokeShell","Toolkit"];
        };
    };

    // définie les loads
    WolvGarage_var_VlLoad = _logic getVariable ["DefaultLoad", '[["30Rnd_65x39_caseless_mag",10], ["SmokeShell",5],["Toolkit", 1]]'];
    if (typeName WolvGarage_var_VlLoad == "STRING") then {
        WolvGarage_var_VlLoad = parseSimpleArray (WolvGarage_var_VlLoad);//
    } else { 
        if (typeName WolvGarage_var_VlLoad != "ARRAY") then {
            WolvGarage_var_VlLoad = [["30Rnd_65x39_caseless_mag",10], ["SmokeShell",5],["Toolkit", 1]];
        };
    };

    // définie les Véhicules
    WolvGarage_var_ListUsine = _logic getVariable ["AvalaibleVehicle", '["B_MRAP_01_F","B_Truck_01_mover_F"]'];
    if (typeName WolvGarage_var_ListUsine == "STRING") then {
        WolvGarage_var_ListUsine = parseSimpleArray (WolvGarage_var_ListUsine);//
    } else { 
        if (typeName WolvGarage_var_ListUsine != "ARRAY") then {
            WolvGarage_var_ListUsine = ["B_MRAP_01_F","B_Truck_01_mover_F"];
        };
    };

    WolvGarage_var_AceEnable = _logic getVariable ["AceEnable", False];
    if (WolvGarage_var_AceEnable) then {
        //Liste des élements dans l'arsenal ACE
        WolvGarage_var_ItemAce = _logic getVariable ["AceItem", '["ACE_medicalSupplyCrate_advanced", "ACE_Wheel", "ACE_Track", "Box_NATO_AmmoVeh_F"]'];
        if (typeName WolvGarage_var_ItemAce == "STRING") then {
            WolvGarage_var_ItemAce = parseSimpleArray (WolvGarage_var_ItemAce);//
        } else { 
            if (typeName WolvGarage_var_ItemAce != "ARRAY") then {
                WolvGarage_var_ItemAce = ["ACE_medicalSupplyCrate_advanced", "ACE_Wheel", "ACE_Track", "Box_NATO_AmmoVeh_F"];
            };
        };
    }else {
        WolvGarage_var_ItemAce = [];
    };


    _obj addAction ["<t color='#5c7038'>Garage</t>", {call WolvGarage_fnc_garCreate},[],1.5,True,True,"", "True",5];

    private _radGar = WolvGarage_var_Range; // raduis du garrage

    private _garTrigger = createTrigger ["EmptyDetector", WolvGarage_var_OBJ];  //crée le trigger
    _garTrigger setTriggerArea [_radGar, _radGar, 0, false];        //definie la taille
    _garTrigger setTriggerActivation ["VEHICLE", "PRESENT", true];  //activation a la présence d'un vl
    _garTrigger setTriggerStatements ["this", 
        "[] remoteexec ['WolvGarage_fnc_garUpdateVlProx', 0];",
        "[] remoteexec ['WolvGarage_fnc_garUpdateVlProx', 0];"];

    WolvGarage_var_OBJ setVariable ["_var_updateTrigger", _garTrigger, True];

    WolvGarage_var_AllVl = [];
    WolvGarage_var_ListVL = [];
    WolvGarage_var_BlacklistedVL = nearestObjects [[(worldSize/2),(worldSize/2)], ["car", "tank", "plane", "ship", "helicopter", "ReammoBox_F", "StaticWeapon"], worldSize];
};

