/*
* Auteur : Number42 & Wolv
* init la fonction CutBushes
*
* Arguments :
* 0: module
* 1: link
*/
params ["_module", "_link"];

if (isClass(configFile >> "CfgPatches" >> "ace_interaction")) then {
    
    private _timer = _module getVariable ["Timer", 2];

    _nobushAction = [
        "noBush",
        "Cut bushes",
        "\z\ace\addons\logistics_wirecutter\ui\wirecutter_ca.paa",
        {params ["_target", "_player", "_params"]; [player, false, _params] spawn DISCommon_fnc_CutBushes;},
        {True},
        {}, 
        _timer
    ] call ace_interact_menu_fnc_createAction;

    [player, 1, ["ACE_SelfActions", "ACE_Equipment"],_nobushAction] call ace_interact_menu_fnc_addActionToObject;


} else {
    systemChat "CutBushes requires ACE interaction to be loaded";
};

