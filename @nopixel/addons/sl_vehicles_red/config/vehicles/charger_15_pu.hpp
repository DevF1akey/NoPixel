class red_charger_15_p_u_base;
class sl_285: red_charger_15_p_u_base
{
	scope=2;
	displayName="285 Black Dodge Charger 2015 Unmarked";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0,0,0,1.0,CO)"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_15_p\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};

class sl_charger_15_uc_black : sl_285
{
    displayName = "Dodge Charger 2015 Unmarked Black";
};

class sl_286: red_charger_15_p_u_base
{
	scope=2;
	displayName="286 Blue Dodge Charger 2015 Unmarked";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.141176,0.0784314,0.396078,1.0,CO)"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_15_p\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};

class sl_charger_15_uc_blue : sl_286
{
    displayName = "Dodge Charger 2015 Unmarked Blue";
};