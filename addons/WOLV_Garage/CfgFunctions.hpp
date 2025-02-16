class WOLV_Garage {
	tag = "WolvGarage";

	class Initialize {
		file = "WOLV_Garage\functions\initialize";

		class init {};
		class switchDisplay {};
	};

	class garage {
		file = "WOLV_Garage\functions\garage";

		class garCreate {};
		class garVlProx {};
		class garUpdateVlProx {};
		class garSpawnVl {};
		class garDeleteVL {};
		class garParradropVl {};
	};
	
	class Inventaire {
		file = "WOLV_Garage\functions\inventaire";

		class invCreate {};
		class invUpdate {};
		class invAddItem {};
		class invRemoveItem {};
	};

	class InvetaireAce {
		file = "WOLV_Garage\functions\inventaireAce";

		class aceInvCreate {};
		class aceInvUpdate {};
		class aceInvSetSize {};
		class aceInvSize {};
		class aceInvAddItem {};
		class aceInvRemoveItem {};
	};
};