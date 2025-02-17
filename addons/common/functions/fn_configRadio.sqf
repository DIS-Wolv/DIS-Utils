/*
* Auteur : Wolv
* change la radio
*
* Arguments :
* 0: player
*
* Valeur renvoyée :
* nil
*
* Exemple:
* [player] call DISCommon_fnc_resetRadio
*
* Variable publique :
*/
params ["_unit"];

["fr","Français"] call acre_api_fnc_babelAddLanguageType;

// copy le preset
["ACRE_PRC152", "default", "Preset_DIS"] call acre_api_fnc_copyPreset;
// from 59,3750 to 71,625 step 0,25

// modifie le preset avec les noms
["ACRE_PRC152", "Preset_DIS", 1, "label", "DIS-COYOTTE"] call acre_api_fnc_setPresetChannelField;
["ACRE_PRC152", "Preset_DIS", 2, "label", "DIS-SANGLIER"] call acre_api_fnc_setPresetChannelField;
["ACRE_PRC152", "Preset_DIS", 3, "label", "DIS-Crocodile"] call acre_api_fnc_setPresetChannelField;
["ACRE_PRC152", "Preset_DIS", 4, "label", "DIS-Harfang"] call acre_api_fnc_setPresetChannelField;
["ACRE_PRC152", "Preset_DIS", 5, "label", "DIS-InterGrp"] call acre_api_fnc_setPresetChannelField;

["ACRE_PRC152", "Preset_DIS"] call acre_api_fnc_setPreset;

// le serv s'arrete ici
if (!hasInterface || {player != _unit}) exitWith {false};

waitUntil {([] call acre_api_fnc_isInitialized)};

// liste des langues parlé
["fr"] call acre_api_fnc_babelSetSpokenLanguages;
// langue par défault
["fr"] call acre_api_fnc_babelSetSpeakingLanguage;

// systemChat str(_unit);
switch (str(_unit)) do {
	// Groupe DIS-Coyotte
	case "DIScoyCdg";
	case "DIScoyMed";
	case "DIScoyCde";
	case "DIScoyGvIng": {
		[["ACRE_PRC152"] call acre_api_fnc_getRadioByType, 1] call acre_api_fnc_setRadioChannel;
	};
	// Groupe DIS-Sanglier
	case "DISsgCdg";
	case "DISsgGvIng";
	case "DISsgBlCde";
	case "DISsgBlGv1";
	case "DISsgBlGv2";
	case "DISsgGrCde";
	case "DISsgGrGv1";
	case "DISsgGrGv2";
	case "DISsgMed": {
		[["ACRE_PRC152"] call acre_api_fnc_getRadioByType, 2] call acre_api_fnc_setRadioChannel;
	};
	// Groupe DIS-Crocodile
	case "DIScroCdb";
	case "DIScroEq1";
	case "DIScroEq2": {
		[["ACRE_PRC152"] call acre_api_fnc_getRadioByType, 3] call acre_api_fnc_setRadioChannel;
	};
	// Groupe DIS-Harfang
	case "DISHaP1";
	case "DISHaP2";
	case "DISHaP3";
	case "DISHaP4": {
		[["ACRE_PRC152"] call acre_api_fnc_getRadioByType, 4] call acre_api_fnc_setRadioChannel;
	};
	default {
		[["ACRE_PRC152"] call acre_api_fnc_getRadioByType, 5] call acre_api_fnc_setRadioChannel;
		systemChat "Player non reconnue";
	};
};
