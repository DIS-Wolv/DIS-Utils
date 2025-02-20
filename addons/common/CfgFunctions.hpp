class DIS_Common {
	tag = "DISCommon";
	class Initialize {
		file = "common\functions";

		class PosFob {};
		class configRadio {};
		class arsenal{};
	};

	class Halo {
		file = "common\functions\halo";
		
		class initHalo {};
		class haloJump {};
		class haloJumpinfo {};
	}

	class RecoDrone {
		file = "common\functions\RecoDrone";

		class initRecoDrone {};
		class recoDrone{};
		class recoDroneInfo{};
	}

	class Boat {
		file = "common\functions\boat";

		class initBoat {};
		class createBoat {};
		class deleteBoats {};
	}

	class utils {
		file = "common\functions\utils";

		class markers {};
		class customLocations {};
		class addCustomLocation {};
		class fastTravel {};
		class fastTravelInit {};
		class CutBushes {};
		class CutBushesInit {};
	}
};