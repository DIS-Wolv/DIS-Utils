/*
* Auteur : Wolv
* Permet d'effectuer l'action d'un bouton
*
* Arguments :
* 0: INT - Bouton
*
* Valeur renvoyée :
* nil
*
*/
params ["_bouton"];

// récupère la cible
private _cible = (findDisplay DISGUI_code_var_IDD) getVariable ["DISGUI_code_var_cible", objNull];

// récupère le code actuel
private _current = _cible getVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1]];

private _msgToZeus = {
	params ["_msg"];

	private _curator = allCurators;
	{
		[_msg] remoteExec ["systemChat", owner _x];
	} forEach _curator;
};

private _doorRef = _cible getVariable ["DISGUI_code_var_reference", ""];

private _isOpen = _cible getVariable ["DISGUI_code_var_CodeOuvert", False];
if (_isOpen) then {
	if (_bouton == 11) then {
		// ferme le code
		private _action = _cible getVariable ["DISGUI_code_var_ActionLock", "systemChat 'Fermeture';"];
		[_cible] spawn compile _action;
		_cible setVariable ["DISGUI_code_var_CodeOuvert", False, True];
		[format["%1 a fermé %2", name player, _doorRef]] call _msgToZeus;
	};
} else {
	// bouton validé ou effacé
	if (_bouton >= 10) then {
		// valide le code
		if (_bouton == 10) then {
			private _cypher = _cible getVariable ["DISGUI_code_var_Code", [1, 2, 3, 4]];
			
			if (_current isEqualTo _cypher) then {
				// code bon
				_cible setVariable ["DISGUI_code_var_CodeOuvert", True, True];
				_cible setVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1]];
				private _action = _cible getVariable ["DISGUI_code_var_ActionGood", "systemChat 'Ouverture';"];
				[_cible] spawn compile _action;

				[format["%1 a ouvert %2", name player, _doorRef]] call _msgToZeus;
			}
			else {
				// code mauvais
				_cible setVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1]];
				private _action = _cible getVariable ["DISGUI_code_var_ActionErr", "systemChat 'Code Mauvais';"];
				[_cible] spawn compile _action;

				[format["%1 a essayé d'ouvrir %2", name player, _doorRef]] call _msgToZeus;
			};

		} else {
			// efface le code
			_cible setVariable ["DISGUI_code_var_CurrentCode", [-1,-1,-1,-1]];
		};
	}
	else {
		// ajoute la valeur a la fin du code
		if (_current select 0 == -1) then {
			_current set [0, _bouton];
		} else {
			if (_current select 1 == -1) then {
				_current set [1, _bouton];
			} else {
				if (_current select 2 == -1) then {
					_current set [2, _bouton];
				} else {
					if (_current select 3 == -1) then {
						_current set [3, _bouton];
					};
				};
			};
		};
	};
};
// met a jour le code
[_cible] call DISGUICode_fnc_update;


