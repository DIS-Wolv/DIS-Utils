class GUIgarage_Garage 
{
	idd = 0310221;
	name = "GUIgarage_Garage";
	author = "Wolv";
	
	class controlsBackground
	{
		class GUI_Garage_Background: WolvGUIgarage_RscText
		{
			idc = 1000;
			x = 0.2 * safezoneW + safezoneX;
			y = 0.12 * safezoneH + safezoneY;
			w = 0.6 * safezoneW;
			h = 0.68 * safezoneH;
			colorBackground[] = {0.16,0.196,0.098,0.9};
		};
		class GUI_Garage_Title: WolvGUIgarage_RscStructuredText
		{
			idc = 1100;
			text = "<t size='3' align='center'>Garage DIS<t/>"; //--- ToDo: Localize;
			x = 0.25 * safezoneW + safezoneX;
			y = 0.14 * safezoneH + safezoneY;
			w = 0.5 * safezoneW;
			h = 0.06 * safezoneH;
		};
	};

	class controls 
	{
		class GUI_Garage_ButtonNavGarage: WolvGUIgarage_RscButton
		{
			idc = 1600;
			text = "Garage"; //--- ToDo: Localize;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.04 * safezoneH;
			//action = "[1] spawn WolvGarage_fnc_switchDisplay;";
			colorBackground[] = {0,0,0,1};
		};
		class GUI_Garage_ButtonNavInv: WolvGUIgarage_RscButton
		{
			idc = 1601;
			text = "Inventaire"; //--- ToDo: Localize;
			x = 0.4125 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.04 * safezoneH;
			action = "[2] spawn WolvGarage_fnc_switchDisplay;";
		};
		class GUI_Garage_ButtonNavInvAce: WolvGUIgarage_RscButton
		{
			idc = 1602;
			text = "Inventaire Ace"; //--- ToDo: Localize;
			x = 0.5875 * safezoneW + safezoneX;
			y = 0.24 * safezoneH + safezoneY;
			w = 0.175 * safezoneW;
			h = 0.04 * safezoneH;
			action = "[3] spawn WolvGarage_fnc_switchDisplay;";
		};

		class GUI_Garage_ListBoxVlProx: WolvGUIgarage_RscListBox
		{
			idc = 1500;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.32 * safezoneH + safezoneY;
			w = 0.1625 * safezoneW;
			h = 0.44 * safezoneH;
		};
		class GUI_Garage_ListBoxUsine: WolvGUIgarage_RscListBox
		{
			idc = 1501;
			x = 0.6 * safezoneW + safezoneX;
			y = 0.32 * safezoneH + safezoneY;
			w = 0.1625 * safezoneW;
			h = 0.44 * safezoneH;
		};

		class GUI_Garage_ButtonSpawn: WolvGUIgarage_RscButton
		{
			idc = 1603;
			text = "Créer"; //--- ToDo: Localize;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.36 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.08 * safezoneH;
			action = "[] spawn WolvGarage_fnc_garSpawnVl";
		};
		class GUI_Garage_ButtonParadrop: WolvGUIgarage_RscButton
		{
			idc = 1604;
			text = "Parrachuter"; //--- ToDo: Localize;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.08 * safezoneH;
			action = "[] spawn WolvGarage_fnc_garParradropVl";
		};
		class GUI_Garage_ButtonDelete: WolvGUIgarage_RscButton
		{
			idc = 1605;
			text = "Supprimer"; //--- ToDo: Localize;
			x = 0.45 * safezoneW + safezoneX;
			y = 0.64 * safezoneH + safezoneY;
			w = 0.1 * safezoneW;
			h = 0.08 * safezoneH;
			action = "[] spawn WolvGarage_fnc_garDeleteVL";
		};
	};
};
