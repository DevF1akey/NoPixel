class red_explorer_16_p_p_base;
class red_explorer_16_p_statetrooper: red_explorer_16_p_p_base
{
	scope = 2;
	displayName = "2016 Ford Explorer (State Trooper)";
	crew = "C_man_1";
	side = 3;
	faction = "CIV_F";
	hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\StateTrooper.paa"};
	
    #include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_225: red_explorer_16_p_p_base
{
	scope = 2;
	displayName = "225 FPIU SHERIFF OFFICE";
	crew = "C_man_1";
	side = 3;
	faction = "CIV_F";
	hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\sheriff.paa"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_explorer_16_e\scripts\init.sqf"";";
		};
    #include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_222: red_explorer_16_p_p_base
{
	scope=2;
	displayName="222 Sheriff FTO FPIU";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\222.paa"};
	class eventhandlers
		{
			init = "_this call DD_fnc_VehicleInit; _this execVM ""red_explorer_16_e\scripts\init.sqf"";";
		};
	#include "\sl_vehicles_red\handling\physx_fast.hpp"
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_055: red_explorer_16_p_p_base
{
	scope=2;
	displayName="055 Police FTO FPIU";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\055.paa"};
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_fd_explorer16p: red_explorer_16_p_p_base
{
	scope=2;
	displayName="Ford Explorer 2016 F.D.";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\fd.paa"};
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	//#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_rru_113: red_explorer_16_p_p_base
{
	scope=2;
	displayName="RRU Explorer 2015 (113)";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\113_2016_Explorer_RRU.paa"};
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	//#include "\sl_vehicles_red\data\sirenArray.hpp"
};
class sl_rru_114: red_explorer_16_p_p_base
{
	scope=2;
	displayName="RRU Explorer 2015 (114)";
	crew="C_man_1";
	side=3;
	faction="CIV_F";
    hiddenSelectionsTextures[] = {"\sl_vehicles_red\tex\explorer_16_p\114_2016_Explorer RRU.paa"};
	#include "\sl_vehicles_red\data\weapons_sheriff_vehicle.hpp"
	//#include "\sl_vehicles_red\data\sirenArray.hpp"
};