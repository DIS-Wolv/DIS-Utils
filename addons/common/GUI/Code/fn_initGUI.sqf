/*
* Auteur : Wolv
* Permet d'initialiser le GUI du code
*
* Arguments :
* 0: OBJECT - Cible
* 1: CODE   - Action [Code Bon, Code Mauvais, Fermeture]
* 1: STRING - Titre
* 2: ARRAY  - Code [1,3,2,4]
* 3: STRING - Référence du code
*
* Valeur renvoyée :
* nil
*
*/
params ["_module", ["_links", []]];

private _cible = _links select 0;
private _titre = _module getVariable ["CodeTitre", "Code"];
private _reference = _module getVariable ["Reference", "-1"];

private _actionGood = _module getVariable ["ActionGood", "systemChat 'Code Bon';"];
private _actionErreur = _module getVariable ["ActionErreur", "systemChat 'Code Mauvais';"];
private _actionClose = _module getVariable ["ActionFermeture", "systemChat 'Fermeture';"];

private _code = [0,0,0,0];
_code set [0, _module getVariable ["CodeD1", 0]];
_code set [1, _module getVariable ["CodeD2", 0]];
_code set [2, _module getVariable ["CodeD3", 0]];
_code set [3, _module getVariable ["CodeD4", 0]];

// "_cible", ["_action", ["", "", ""]], ["_titre", "Code"], ["_code", [0,0,0,0]], ["_reference", "-1"]

// initialisation des variables
DISGUI_code_var_IDD = 1103251;
DISGUI_code_var_IDCTitle = 1000;
DISGUI_code_var_IDCC1 = 2400;
DISGUI_code_var_IDCC2 = 2401;
DISGUI_code_var_IDCC3 = 2402;
DISGUI_code_var_IDCC4 = 2403;
DISGUI_code_var_IDCT0 = 1600;
DISGUI_code_var_IDCT1 = 1601;
DISGUI_code_var_IDCT2 = 1602;
DISGUI_code_var_IDCT3 = 1603;
DISGUI_code_var_IDCT4 = 1604;
DISGUI_code_var_IDCT5 = 1605;
DISGUI_code_var_IDCT6 = 1606;
DISGUI_code_var_IDCT7 = 1607;
DISGUI_code_var_IDCT8 = 1608;
DISGUI_code_var_IDCT9 = 1609;
DISGUI_code_var_IDCTCancel = 1610;
DISGUI_code_var_IDCTConfirm = 1611;

// action pour ouvrir le GUI
_cible addAction ["Ouvrir le Panneaux du Code", {params ["_t", "_c", "_i", "_arguments"]; _arguments call DISGUICode_fnc_openGUI;}, [_cible, _titre], 1.5,True,True,"","",5];

if (_reference == "-1") then {
    _reference = _titre;
};

// variable pour le code
_cible setVariable ["DISGUI_code_var_Code", _code, True];
_cible setVariable ["DISGUI_code_var_CodeTentative", 0, True];
_cible setVariable ["DISGUI_code_var_Title", _titre, True];
_cible setVariable ["DISGUI_code_var_reference", _reference, True];
_cible setVariable ["DISGUI_code_var_CodeOuvert", False, True];
_cible setVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1], True];
_cible setVariable ["DISGUI_code_var_ActionGood", _actionGood, True];
_cible setVariable ["DISGUI_code_var_ActionErr", _actionErreur, True];
_cible setVariable ["DISGUI_code_var_ActionLock", _actionClose, True];




