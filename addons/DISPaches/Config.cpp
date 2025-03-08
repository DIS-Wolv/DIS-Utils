class CfgPatches
{
	class DISPatches
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"R3F_Uniformes"};
	};
};


class cfgWeapons {
    class UniformItem;
    
	class R3F_uniform_urr_DA;
    class DIS_uniform_urr_DA : R3F_uniform_urr_DA {
		author = "Wolv";
        scope = 2;
        displayName = "Uniforme URR DA";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
        
        class ItemInfo : UniformItem {
            // uniformModel = "-";
            uniformClass = "R3F_URR_BLUFOR_DA"; //would be same as our made soldier class
            containerClass = "Supply80"; //how much it can carry
            mass = 10; //how much it weights
        };
    };

	class SlotInfo;
	class WeaponSlotsInfo;
	class compatibleItems;
	class CowsSlot;
	
	// class WeaponSlotsInfo : WeaponSlotsInfo
	// {
	// 	class CowsSlot : SlotInfo
	// 	{
	// 		class compatibleItems: compatibleItems
	// 		{
	// 			rhsusf_acc_g33_xps3 = 1;
	// 		};
	// 	};
	// };

	// class Rifle;
	// class Rifle_Base_F: Rifle
	// {
	// 	class WeaponSlotsInfo;
	// 	class GunParticles;
	// };

	// class R3F_Famas_F1: Rifle_Base_F {};
	class R3F_FAMAS_G2; //: R3F_Famas_F1 {}
	class DIS_FAMAS_G2 : R3F_FAMAS_G2 {
		author = "Wolv";
		scope = 2;
		displayName = "FAMAS G2 DIS";

		muzzles[]=
		{
			"this",
			"Lance_Grenades",
			"securite"
		};

		magazines[] = {
			"R3F_30Rnd_556x45_FAMAS",
			"R3F_30Rnd_556x45_TRACER_FAMAS",
			"R3F_30Rnd_556x45_HK416",
			"R3F_30Rnd_556x45_tracer_hk416",
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"R3F_MINIMI_200rnd_556x45",
		};
	// 	class WeaponSlotsInfo: WeaponSlotsInfo
	// 	{
	// 		class CowsSlot: CowsSlot
	// 		{
	// 			iconPosition[]={0.47999999,0.18000001};
	// 			iconScale=0.2;
	// 			iconPicture="\A3\Weapons_F\Data\UI\attachment_top.paa";
	// 			iconPinpoint="Center";
	// 			linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
	// 			displayName="$STR_A3_CowsSlot0";
	// 			class compatibleItems : compatibleItems
	// 			{
	// 				rhsusf_acc_g33_xps3 = 1;
	// 			};
	// 		};
	//	 };
	};


};