class red_charger_12_p_u_base;
class sl_charger_slicktop_221: red_charger_12_p_u_base
	{
		scope=2;
		displayName="221 SHERIFF OFFICE DODGE CHARGER SLICKTOP 2012";
		crew="C_man_1";
		side=3;
		faction="CIV_F";
		hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\charger_12_pu\sheriff_221.paa"};
		class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_12_p\scripts\init.sqf"";";
		};
        #include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
	};
class sl_283: red_charger_12_p_u_base
{
	scope=2;
	displayName="283 Black Dodge Charger 2012 Unmarked";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0,0,0,1.0,CO)"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_12_p\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_charger_12_uc_black : sl_283
{
    displayName = "Dodge Charger 2012 Unmarked Black";
};

class sl_284: red_charger_12_p_u_base
{
	scope=2;
	displayName="284 Blue Dodge Charger 2012 Unmarked";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.141176,0.0784314,0.396078,1.0,CO)"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_12_p\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};

class sl_charger_12_uc_blue : sl_284
{
    displayName = "Dodge Charger 2012 Unmarked Blue";
};

class sl_charger12_swat: red_charger_12_p_u_base
{
	scope=2;
	displayName = "2012 Dodge Charger SRT8 (SWAT)";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
	hiddenSelectionsTextures[]=
	{
		"\sl_vehicles_red\tex\charger_12_pu\swat.paa"
	};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_charger_12_p\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\lights\red_spotlight_lights.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};