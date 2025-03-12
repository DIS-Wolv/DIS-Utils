/*
* Auteur : Wolv
* Permet d'ouvrire le GUI du code
*
* Arguments :
* 0: OBJECT - Cible
* 1: STRING - Titre
*
* Valeur renvoyée :
* nil
*
*/
params ["_cible", ["_titre", "Code"]];

private _isCreate = createDialog "GUICode_Interface";

if (_isCreate) then {
    private _display = findDisplay DISGUI_code_var_IDD;
    (_display displayCtrl DISGUI_code_var_IDCTitle) ctrlSetStructuredText parseText format ["<t valign='middle' align='center' size='2.4'>%1</t>", _titre];

    _display setVariable ["DISGUI_code_var_cible", _cible];
    [_cible] call DISGUICode_fnc_update;
};
