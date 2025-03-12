/*
* Auteur : Wolv
* Permet d'update le GUI du code
*
* Arguments :
* 0: OBJECT - Cible
*
* Valeur renvoyée :
* nil
*
*/
params ["_cible"];

private _actual = _cible getVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1]];


private _isOpen = _cible getVariable ["DISGUI_code_var_CodeOuvert", False]; 

private _C1 = ((findDisplay DISGUI_code_var_IDD) displayCtrl DISGUI_code_var_IDCC1);
private _C2 = ((findDisplay DISGUI_code_var_IDD) displayCtrl DISGUI_code_var_IDCC2);
private _C3 = ((findDisplay DISGUI_code_var_IDD) displayCtrl DISGUI_code_var_IDCC3);
private _C4 = ((findDisplay DISGUI_code_var_IDD) displayCtrl DISGUI_code_var_IDCC4);

if (_isOpen) then {
    _C1 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>X</t>"]));
    _C2 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>X</t>"]));
    _C3 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>X</t>"]));
    _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>X</t>"]));
}
else {
    if (_actual select 0 > -1) then {
        _C1 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>%1</t>", _actual select 0]));
        if (_actual select 1 > -1) then {
            _C2 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>%1</t>", _actual select 1]));
            if (_actual select 2 > -1) then {
                _C3 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>%1</t>", _actual select 2]));
                if (_actual select 3 > -1) then {
                    _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>%1</t>", _actual select 3]));
                } else {
                    _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
                };
            } else {
                _C3 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
                _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
            };
        } else {
            _C2 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
            _C3 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
            _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
        };
    } else {
        _C1 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
        _C2 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
        _C3 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
        _C4 ctrlSetStructuredText (parseText (format ["<t valign='middle' align='center' size='2.4'>_</t>"]));
    };
};
