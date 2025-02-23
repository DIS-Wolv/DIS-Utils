class WOLV_Garage {
	tag = "WolvGarage";

	class Initialize {
		file = "z\DISUtils\addons\Garage\functions\initialize";

		class init {};
		class switchDisplay {};
	};

	class garage {
		file = "z\DISUtils\addons\Garage\functions\garage";

		class garCreate {};
		class garVlProx {};
		class garUpdateVlProx {};
		class garSpawnVl {};
		class garDeleteVL {};
		class garParradropVl {};
	};
	
	class Inventaire {
		file = "z\DISUtils\addons\Garage\functions\inventaire";

		class invCreate {};
		class invUpdate {};
		class invAddItem {};
		class invRemoveItem {};
	};

	class InvetaireAce {
		file = "z\DISUtils\addons\Garage\functions\inventaireAce";

		class aceInvCreate {};
		class aceInvUpdate {};
		class aceInvSetSize {};
		class aceInvSize {};
		class aceInvAddItem {};
		class aceInvRemoveItem {};
	};
};