class GUICode_Interface
{
	idd = 1103251;
	name = "GUICode_Interface";
	author = "Wolv";
	
	class controlsBackground
	{
		class GUICode_Background: RscText
		{
			idc = 2200;
			x = 0.396875 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.484 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
			// style = ST_PICTURE;
			// text = "z\DISUtils\addons\Common\GUI\data\dis.paa";
		};
		class GUICode_Title: RscStructuredText
		{
			idc = 1000;
			text = "<t valign='middle' align='center' size='1.9'>Title</t>";
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
	};
	class controls 
	{

		class GUICode_C1: RscStructuredText
		{
			idc = 2400;
			text = "<t valign='middle' align='center' size='2.4'>C1</t>"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			colorBackground[] = {0,0,0,0.4};

		};
		class GUICode_C2: RscStructuredText
		{
			idc = 2401;
			text = "<t valign='middle' align='center' size='2.4'>C2</t>"; //--- ToDo: Localize;
			x = 0.463906 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
		class GUICode_C3: RscStructuredText
		{
			idc = 2402;
			text = "<t valign='middle' align='center' size='2.4'>C3</t>"; //--- ToDo: Localize;
			x = 0.505156 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
		class GUICode_C4: RscStructuredText
		{
			idc = 2403;
			text = "<t valign='middle' align='center' size='2.4'>C4</t>"; //--- ToDo: Localize;
			x = 0.546406 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			colorBackground[] = {0,0,0,0.4};
		};
///////////////////////////////////////////////
		class GUICode_Touche0: RscButton
		{
			idc = 1600;
			text = "0"; //--- ToDo: Localize;
			x = 0.484531 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[0] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche1: RscButton
		{
			idc = 1601;
			text = "1"; //--- ToDo: Localize;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[1] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche2: RscButton
		{
			idc = 1602;
			text = "2"; //--- ToDo: Localize;
			x = 0.484531 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[2] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche3: RscButton
		{
			idc = 1603;
			text = "3"; //--- ToDo: Localize;
			x = 0.530937 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[3] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche4: RscButton
		{
			idc = 1604;
			text = "4"; //--- ToDo: Localize;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[4] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche5: RscButton
		{
			idc = 1605;
			text = "5"; //--- ToDo: Localize;
			x = 0.484531 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[5] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche6: RscButton
		{
			idc = 1606;
			text = "6"; //--- ToDo: Localize;
			x = 0.530937 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[6] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche7: RscButton
		{
			idc = 1607;
			text = "7"; //--- ToDo: Localize;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[7] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche8: RscButton
		{
			idc = 1608;
			text = "8"; //--- ToDo: Localize;
			x = 0.484531 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[8] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Touche9: RscButton
		{
			idc = 1609;
			text = "9"; //--- ToDo: Localize;
			x = 0.530937 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[9] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Cancel: RscButton
		{
			idc = 1610;
			text = "X"; //--- ToDo: Localize;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[11] spawn DISGUICode_fnc_PressButton;";
		};
		class GUICode_Confirm: RscButton
		{
			idc = 1611;
			text = "V"; //--- ToDo: Localize;
			x = 0.530937 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.0309375 * safezoneW;
			h = 0.055 * safezoneH;
			action = "[10] spawn DISGUICode_fnc_PressButton;";
		};
	};
};




