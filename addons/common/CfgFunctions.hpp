class DIS_Common {
	tag = "DISCommon";
	class Initialize {
		file = "z\DISUtils\addons\Common\functions";

		class PosFob {};
		class configRadio {};
		class arsenal{};
		class rDate {};
	};

	class Halo {
		file = "z\DISUtils\addons\Common\functions\halo";
		
		class initHalo {};
		class haloJump {};
		class haloJumpinfo {};
	};

	class RecoDrone {
		file = "z\DISUtils\addons\Common\functions\RecoDrone";

		class initRecoDrone {};
		class recoDrone{};
		class recoDroneInfo{};
	};

	class Boat {
		file = "z\DISUtils\addons\Common\functions\boat";

		class initBoat {};
		class createBoat {};
		class deleteBoats {};
	};

	class utils {
		file = "z\DISUtils\addons\Common\functions\utils";

		class markers {};
		class customLocations {};
		class addCustomLocation {};
		class fastTravel {};
		class fastTravelInit {};
		class CutBushes {};
		class CutBushesInit {};
	};
};

class DIS_GUI_Code {
	tag = "DISGUICode";
	class CodeInterface {
		file = "z\DISUtils\addons\common\GUI\Code";

		class initGUI {};
		class openGUI {};
		class update {};
		class PressButton {};
	};
};

