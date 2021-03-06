class CfgPatches
{
	class red_suburban_15
	{
		units[] = {"red_suburban_15_p"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Soft_F"};
	};
};

class DefaultEventhandlers;

class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;

class CfgVehicleClasses 
{
	class red_civilian
	{
		displayName = "Redhotsteel's Cars";
	};
};

class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class HitPoints /// we want to use hitpoints predefined for all cars
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};	
		class EventHandlers;
	};

	class red_suburban_15_base: Car_F
	{
		model 	= "\red_suburban_15\red_suburban_15_p";  /// simple path to model
		picture	= "\red_base\textures\icon.paa"; /// icon in map	
		Icon	= "\red_base\textures\icon.paa"; /// icon in map	
		author = "Redhotsteel";
		hiddenSelections[] = {"camo1","license1","license2","license3","license4","license5","license6","license7"}; ///we want to allow changing the color of this selection	
		terrainCoef 	= 1.0; 	/// different surface affects this car more, stick to tarmac
		turnCoef 		= 2.5; 	/// should match the wheel turn radius
		precision 		= 10; 	/// how much freedom has the AI for its internal waypoints - lower number means more precise but slower approach to way
		brakeDistance 	= 3.0; 	/// how many internal waypoints should the AI plan braking in advance
		acceleration 	= 15; 	/// how fast acceleration does the AI think the car has
		fireResistance 	= 5; 	/// lesser protection against fire than tanks
		armor 			= 32; 	/// just some protection against missiles, collisions and explosions
		cost			= 50000; /// how likely is the enemy going to target this vehicle
		destrType = "DestructDefault";
		explosionEffect = "FuelExplosion";
		
		transportMaxBackpacks 	= 4; /// just some backpacks fit the trunk by default
		transportSoldier 		= 6; /// number of cargo except driver
		
		/// some values from parent class to show how to set them up
		wheelDamageRadiusCoef 	= 0.9; 			/// for precision tweaking of damaged wheel size
		wheelDestroyRadiusCoef 	= 0.4;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 0.5;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.25;			/// multiplier of damage to crew of the vehicle => low number means better protection
		driverLeftHandAnimName 	= "drivewheel"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "drivewheel";	/// beware, non-existent bones may cause game crashes (even if the bones are hidden during play)
		driveOnComponent[] = {"wheel_1_1_damper","wheel_1_2_damper","wheel_2_1_damper","wheel_2_2_damper"};
		extCameraPosition[] = {0, 1, -8.25};
		
		class CargoTurret;	// External class reference
		
		class Turrets{};

		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel	{armor=0.125; passThrough=0;}; /// it is easier to destroy wheels than hull of the vehicle
			class HitLF2Wheel: HitLF2Wheel	{armor=0.125; passThrough=0;};

			class HitRFWheel: HitRFWheel	{armor=0.125; passThrough=0;};
			class HitRF2Wheel: HitRF2Wheel 	{armor=0.125; passThrough=0;}; 

			class HitFuel 			{armor=0.50; material=-1; name="fueltank"; visual=""; passThrough=0.2;}; /// correct points for fuel tank, some of the damage is aFRLied to the whole
			class HitEngine 		{armor=0.50; material=-1; name="engine"; visual=""; passThrough=0.2;};
			class HitBody: HitBody 	{name = "body"; visual="camo1"; passThrough=1;}; /// all damage to the hull is aFRLied to total damage

			class HitGlass1: HitGlass1 {armor=0.25;}; /// it is pretty easy to puncture the glass but not so easy to remove it
			class HitGlass2: HitGlass2 {armor=0.25;};
			class HitGlass3: HitGlass3 {armor=0.25;};
			class HitGlass4: HitGlass4 {armor=0.25;};
		};
		driverAction = "driver_offroad01"; 
		cargoAction[] = {"passenger_low01", "passenger_generic01_leanleft", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands", "passenger_generic01_foldhands"};
		getInAction = "GetInLow"; 
		getOutAction = "GetOutLow"; 
		cargoGetInAction[] 	= {"GetInLow"}; 
		cargoGetOutAction[] = {"GetOutLow"};
		
		attenuationEffectType = "CarAttenuation";
		soundGetIn[]={"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_door",db-5,1};
		soundGetOut[]={"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_door",db-5,1, 40};
		soundDammage[]={"", db-5, 1};
		soundEngineOnInt[] = {"red_base\sounds\SUV_V8\exhaust_start_int",0.61622776,1.0};  /// Ignition On Interior
		soundEngineOnExt[] = {"red_base\sounds\SUV_V8\exhaust_start",1.39810717,1.0,200};  /// Ignition On Exterior
		soundEngineOffInt[] = {"red_base\sounds\SUV_V8\exhaust_stop_int",0.61622776,1.0};  /// Ignition Off Interior
		soundEngineOffExt[] = {"red_base\sounds\SUV_V8\exhaust_stop",1.39810717,1.0,200};  /// Ignition Off Exterior
		buildCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_01", db-3, 1,200};
		buildCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_02", db-3, 1,200};
		buildCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_03", db-3, 1,200};
		buildCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_building_04", db-3, 1,200};
		soundBuildingCrash[]={buildCrash0, 0.25, buildCrash1, 0.25, buildCrash2, 0.25, buildCrash3, 0.25};
		WoodCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_01", db-3, 1,200};
		WoodCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_02", db-3, 1,200};
		WoodCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_03", db-3, 1,200};
		WoodCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_04", db-3, 1,200};
		WoodCrash4[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_05", db-3, 1,200};
		WoodCrash5[]={"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_06", db-3, 1,200};
		soundWoodCrash[]={woodCrash0, 0.166, woodCrash1, 0.166, woodCrash2, 0.166, woodCrash3, 0.166,woodCrash4, 0.166,woodCrash5, 0.166};
		ArmorCrash0[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_01", db-3, 1,200};
		ArmorCrash1[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_02", db-3, 1,200};
		ArmorCrash2[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_03", db-3, 1,200};
		ArmorCrash3[]={"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_04", db-3, 1,200};
		soundArmorCrash[]={ArmorCrash0, 0.25, ArmorCrash1, 0.25, ArmorCrash2, 0.25, ArmorCrash3, 0.25};
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_00764",0.2818383,1,200};
				frequency = "0.9	+	((rpm/	6000) factor[(400/	6000),(1100/	6000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(200/	6000),(600/	6000)])	*	((rpm/	6000) factor[(1100/	6000),(800/	6000)]))";
			};
			class Engine
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_01353",0.31622776,1,200};
				frequency = "0.8	+	((rpm/	6000) factor[(810/	6000),(2000/	6000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(820/	6000),(1100/	6000)])	*	((rpm/	6000) factor[(2000/	6000),(1350/	6000)]))";
			};
			class Engine1_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_01839",0.35481337,1,210};
				frequency = "0.8	+	((rpm/	6000) factor[(1300/	6000),(2700/	6000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(1300/	6000),(2000/	6000)])	*	((rpm/	6000) factor[(2700/	6000),(2150/	6000)]))";
			};
			class Engine2_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_02036",0.39810717,1,220};
				frequency = "0.8	+	((rpm/	6000) factor[(2100/	6000),(3500/	6000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(2150/	6000),(2650/	6000)])	*	((rpm/	6000) factor[(3550/	6000),(2900/	6000)]))";
			};
			class Engine3_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_03221",0.4466836,1,230};
				frequency = "0.8	+	((rpm/	6000) factor[(2900/	6000),(4150/	6000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(2900/	6000),(3500/	6000)])	*	((rpm/	6000) factor[(4180/	6000),(3700/	6000)]))";
			};
			class Engine4_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_03761",0.39810717,1,240};
				frequency = "0.8	+	((rpm/	6000) factor[(3700/	6000),(5200/	6000)]) *0.2";
				volume = "engineOn*camPos*(((rpm/	6000) factor[(3700/	6000),(4100/	6000)])	*	((rpm/	6000) factor[(5200/	6000),(4500/	6000)]))";
			};
			class Engine5_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Ext_04181",0.35481337,1,250};
				frequency = "0.95	+	((rpm/	6000) factor[(4500/	6000),(6000/	6000)])*0.2";
				volume = "engineOn*camPos*((rpm/	6000) factor[(4500/	6000),(5600/	6000)])";
			};
			class IdleThrust
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_01",0.39810717,1,280};
				frequency = "0.9	+	((rpm/	6000) factor[(400/	6000),(1100/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(200/	6000),(600/	6000)])	*	((rpm/	6000) factor[(1100/	6000),(800/	6000)]))";
			};
			class EngineThrust
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_02",0.4466836,1,300};
				frequency = "0.9	+	((rpm/	6000) factor[(810/	6000),(2000/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(820/	6000),(1100/	6000)])	*	((rpm/	6000) factor[(2000/	6000),(1350/	6000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_03",0.5011872,1,310};
				frequency = "0.9	+	((rpm/	6000) factor[(1300/	6000),(2700/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(1300/	6000),(2000/	6000)])	*	((rpm/	6000) factor[(2700/	6000),(2150/	6000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_04",0.5011872,1,320};
				frequency = "0.9	+	((rpm/	6000) factor[(2100/	6000),(3500/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(2150/	6000),(2650/	6000)])	*	((rpm/	6000) factor[(3550/	6000),(2900/	6000)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_05",0.5011872,1,330};
				frequency = "0.9	+	((rpm/	6000) factor[(2900/	6000),(4150/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(2900/	6000),(3500/	6000)])	*	((rpm/	6000) factor[(4180/	6000),(3700/	6000)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_06",0.5011872,1,340};
				frequency = "0.9	+	((rpm/	6000) factor[(3700/	6000),(5200/	6000)]) *0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	6000) factor[(3700/	6000),(4100/	6000)])	*	((rpm/	6000) factor[(5200/	6000),(4500/	6000)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_07",0.5011872,1,350};
				frequency = "0.9	+	((rpm/	6000) factor[(4500/	6000),(6000/	6000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	6000) factor[(4500/	6000),(5600/	6000)])";
			};
			class Idle_int
			{
						sound[] = {"red_base\sounds\SUV_V8\Int_00764",0.25118864,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(400/ 6400),(1100/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(200/ 6400),(600/ 6400)]) * ((rpm/ 6400) factor[(1100/ 6400),(800/ 6400)]))";
			};
			class Engine_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_01353",0.2818383,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(810/ 6400),(2000/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(820/ 6400),(1100/ 6400)]) * ((rpm/ 6400) factor[(2000/ 6400),(1350/ 6400)]))";
			};
			class Engine1_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_01839",0.31622776,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(1300/ 6400),(2700/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(1300/ 6400),(2000/ 6400)]) * ((rpm/ 6400) factor[(2700/ 6400),(2150/ 6400)]))";
			};
			class Engine2_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_02036",0.35481337,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(2100/ 6400),(3500/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(2150/ 6400),(2650/ 6400)]) * ((rpm/ 6400) factor[(3550/ 6400),(2900/ 6400)]))";
			};
			class Engine3_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_03221",0.39810717,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(2900/ 6400),(4150/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(2900/ 6400),(3500/ 6400)]) * ((rpm/ 6400) factor[(4180/ 6400),(3700/ 6400)]))";
			};
			class Engine4_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_03761",0.4466836,1};
				frequency = "0.8 + ((rpm/ 6400) factor[(3700/ 6400),(5200/ 6400)]) *0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 6400) factor[(3700/ 6400),(4100/ 6400)]) * ((rpm/ 6400) factor[(5200/ 6400),(4500/ 6400)]))";
			};
			class Engine5_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Int_04181",0.5011872,1};
				frequency = "0.95 + ((rpm/ 6400) factor[(4500/ 6400),(6400/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*((rpm/ 6400) factor[(4500/ 6400),(5600/ 6400)])";
			};
			class IdleThrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_01_int",0.35481337,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(400/ 6400),(1100/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(200/ 6400),(600/ 6400)]) * ((rpm/ 6400) factor[(1100/ 6400),(800/ 6400)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_02_int",0.39810717,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(810/ 6400),(2000/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(820/ 6400),(1100/ 6400)]) * ((rpm/ 6400) factor[(2000/ 6400),(1350/ 6400)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_03_int",0.4466836,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(1300/ 6400),(2700/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(1300/ 6400),(2000/ 6400)]) * ((rpm/ 6400) factor[(2700/ 6400),(2150/ 6400)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_04_int",0.5011872,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(2100/ 6400),(3500/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(2150/ 6400),(2650/ 6400)]) * ((rpm/ 6400) factor[(3550/ 6400),(2900/ 6400)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_05_int",0.5011872,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(2900/ 6400),(4150/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(2900/ 6400),(3500/ 6400)]) * ((rpm/ 6400) factor[(4180/ 6400),(3700/ 6400)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_06_int",0.56234133,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(3700/ 6400),(5200/ 6400)]) *0.3";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 6400) factor[(3700/ 6400),(4100/ 6400)]) * ((rpm/ 6400) factor[(5200/ 6400),(4500/ 6400)]))";
			};
			class Engine5_Thrust_int
			{
				sound[] = {"red_base\sounds\SUV_V8\Thrust_07_int",0.63095737,1};
				frequency = "0.9 + ((rpm/ 6400) factor[(4500/ 6400),(6400/ 6400)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 6400) factor[(4500/ 6400),(5600/ 6400)])";
			};
			class TiresRockOut /// Contact with ground
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",0.56234133,1.0,60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",0.56234133,1.0,60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",0.56234133,1.0,60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",0.56234133,1.0,60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",0.56234133,1.0,60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",0.8912509,1.0,60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",0.31622776,1.0,90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",0.4466836,1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",0.19952624,1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\acceleration_dirt_ext_1",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[1,15])";
			};
			class acceleration_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[15, 1])";
			};
			class turn_left_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[1, 15])";
			};
			class turn_right_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[1, 15])";
			};
			class breaking_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 15])";
			};
			class acceleration_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\acceleration_dirt_int_1",0.39810717,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.3])*(Speed Factor[15, 2])";
			};
			class turn_left_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.3])*(Speed Factor[2, 15])";
			};
			class turn_right_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.39810717,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.3])*(Speed Factor[2, 15])";
			};
		};
		/// memory points where do tracks of the wheel appear
		// front left track, left offset
		memoryPointTrackFLL = "TrackFLL"; 
		// front left track, right offset
		memoryPointTrackFLR = "TrackFLR"; 
		// back left track, left offset
		memoryPointTrackBLL = "TrackBLL"; 
		// back left track, right offset
		memoryPointTrackBLR = "TrackBLR"; 
		// front right track, left offset
		memoryPointTrackFRL = "TrackFRL"; 
		// front right track, right offset
		memoryPointTrackFRR = "TrackFRR"; 
		// back right track, left offset
		memoryPointTrackBRL = "TrackBRL"; 
		// back right track, right offset
		memoryPointTrackBRR = "TrackBRR"; 		

		class Damage /// damage changes material in specific places (visual in hitPoint)
		{
			tex[]={};
			mat[]=
			{
				"A3\data_f\glass_veh_int.rvmat", 		/// material mapped in model
				"A3\data_f\Glass_veh_damage.rvmat", 	/// changes to this one once damage of the part reaches 0.5
				"A3\data_f\Glass_veh_damage.rvmat",		/// changes to this one once damage of the part reaches 1

				"A3\data_f\glass_veh.rvmat",			/// another material
				"A3\data_f\Glass_veh_damage.rvmat",		/// changes into different ones
				"A3\data_f\Glass_veh_damage.rvmat"
			};
		};
		
		thrustDelay = 0.1;
		brakeIdleSpeed = 1.78;
		maxSpeed = 350;	// max speed on level road, km/h
		fuelCapacity = 45;
		wheelCircumference = 2.277;
		antiRollbarForceCoef = 2.0;
		antiRollbarForceLimit = 2.0;
		antiRollbarSpeedMin = 20;
		antiRollbarSpeedMax = 80;
		idleRpm = 900;
		redRpm = 5600;
		
		class complexGearbox {
			GearboxRatios[] = {"R1", -3.231, "N", 0, "D1", 4.462, "D2", 3.57, "D3", 2.571, "D4", 1.97, "D5", 1.601, "D6", 0.9, "D7", 0.65};
			TransmissionRatios[] = {"High", 4.111};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
			transmissionDelay = 0.01;
		};
		
		simulation = "carx";
		dampersBumpCoef = 0.01;
		differentialType = "rear_limited";
		frontRearSplit = 0.3;
		frontBias = 1.5;
		rearBias = 1.5;
		centreBias = 2.5;
		clutchStrength = 55.0;
		maxOmega = 586.43;
		enginePower = 250;
		peakTorque = 560;
		dampingRateFullThrottle = 0.03;
		dampingRateZeroThrottleClutchEngaged = 0.35;
		dampingRateZeroThrottleClutchDisengaged = 0.05;
		torqueCurve[] = {{0.0, 0.0}, {0.2, 0.65}, {0.3, 0.8}, {0.4, 0.95}, {0.6, 1.0}, {0.7, 0.95}, {0.9, 0.9}, {1.0, 0.5}};
		changeGearMinEffectivity[] = {0.95,0.15,0.95,0.95,0.95,0.95,0.95,0.95,0.95};
		switchTime = 0.20;
		latency = 0.8;
		
		class Wheels
		{
			class LF
			{
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				mass = 20;
				MOI = 5.3;
				maxBrakeTorque = 5000;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.15;
				mMaxDroop = 0.20;
				sprungMass = 273; 
				springStrength = 9813; //6813
				springDamperRate = 2500; //1091
				longitudinalStiffnessPerUnitGravity = 4800;
				latStiffX = 25;
				latStiffY = 220;
				frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				steering = 0;
				side = "left";
				latStiffX = 25;
				latStiffY = 22000;
				maxHandBrakeTorque = 7500;
			};
			class RF: LF
			{
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";

				steering = 1;
				side = "right";
				latStiffX = 25;
				latStiffY = 220;
			};
			class RR: RF
			{
				boneName = "wheel_2_2_damper";
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 7500;
				steering = 0;
				side = "right";
				latStiffX = 25;
				latStiffY = 22000;
			};
		};
		
		class RenderTargets /// class for all Picture-in-Picture (PiP)
		{
			class LeftMirror
			{
				renderTarget = "rendertarget0"; /// what texture is going to be used, it should be mapped in model like #(argb,256,512,1)r2t(rendertarget0,1.0)
				class CameraView1
				{
					pointPosition		= "PIP0_pos"; 	/// memory point of PiP origin
					pointDirection		= "PIP0_dir"; 	/// memory point of PiP direction
					renderQuality 		= 2;			/// what quality should the PiP be
					renderVisionMode 	= 0;			/// zero means standard vision
					fov 				= 0.7;			/// what is the angle of the PiP field of view
				}; 			
			};
			class RearCam	/// rendering of PiPs is shared, it is best to have one for all sources, this is just an example
			{
				renderTarget = "rendertarget1";
				class CameraView1
				{
					pointPosition		= "PIP1_pos";
					pointDirection		= "PIP1_dir";
					renderQuality 		= 2;
					renderVisionMode 	= 0;
					fov 				= 0.7;					
				}; 			
			};
			class FrontCam
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition		= "PIP2_pos";
					pointDirection		= "PIP2_dir";
					renderQuality 		= 2;
					renderVisionMode 	= 0;
					fov 				= 0.7;					
				}; 			
			};
		};
	
		class Exhausts /// specific exhaust effects for the car
		{
			class Exhaust1 /// the car has two exhausts - each on one side
			{
				position 	= "exhaust1_pos";  		/// name of initial memory point
				direction 	= "exhaust1_dir";	/// name of memory point for exhaust direction
				effect 		= "ExhaustsEffect";	/// what particle effect is it going to use
			};

			class Exhaust2
			{
				position 	= "exhaust2_pos";
				direction 	= "exhaust2_dir";
				effect 		= "ExhaustsEffect";
			};				
		};

		class Reflectors	/// only front lights are considered to be reflectors to save CPU
		{
			class LightCarHeadL01 	/// lights on each side consist of two bulbs with different flares
			{
				color[] 		= {1550, 1550, 2000};		/// approximate colour of standard lights
				ambient[]		= {5, 5, 5};				/// nearly a white one
				position 		= "LightCarHeadL01";		/// memory point for start of the light and flare
				direction 		= "LightCarHeadL01_end";	/// memory point for the light direction
				hitpoint 		= "Light_L";				/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection 		= "Light_L";				/// selection for artificial glow around the bulb, not much used any more
				size 			= 1;						/// size of the light point seen from distance
				innerAngle 		= 100;						/// angle of full light
				outerAngle 		= 179;						/// angle of some light
				coneFadeCoef 	= 10;						/// attenuation of light between the above angles
				intensity 		= 1;						/// strength of the light
				useFlare 		= true;						/// does the light use flare?
				dayLight 		= false;					/// switching light off during day saves CPU a lot
				flareSize 		= 0.5;						/// how big is the flare

				class Attenuation
				{
					start 			= 1.0;
					constant 		= 0; 
					linear 			= 0; 
					quadratic 		= 0.25; 
					hardLimitStart 	= 30;		/// it is good to have some limit otherwise the light would shine to infinite distance
					hardLimitEnd 	= 60;		/// this allows adding more lights into scene
				};
			};

			class LightCarHeadR01: LightCarHeadL01
			{
				position 	= "LightCarHeadR01";
				direction 	= "LightCarHeadR01_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};
		};
		aggregateReflectors[] = {{"LightCarHeadL01"}, {"LightCarHeadR01"}}; /// aggregating reflectors helps the engine a lot
	};

	class red_suburban_15_black:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Black)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\black.paa","","","","","","",""};
	};
	
	class red_suburban_15_aqua:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Aqua)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\aqua.paa","","","","","","",""};
	};
	
	class red_suburban_15_blue:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Blue)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\blue.paa","","","","","","",""};
	};
	
	class red_suburban_15_darkblue:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Dark Blue)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\darkblue.paa","","","","","","",""};
	};
	
	class red_suburban_15_green:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Green)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\green.paa","","","","","","",""};
	};
	
	class red_suburban_15_red:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Red)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\red.paa","","","","","","",""};
	};
	
	class red_suburban_15_pink:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Pink)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\pink.paa","","","","","","",""};
	};
	
	class red_suburban_15_yellow:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Yellow)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\yellow.paa","","","","","","",""};
	};
	
	class red_suburban_15_orange:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Orange)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\orange.paa","","","","","","",""};
	};
	
	class red_suburban_15_white:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (White)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\white.paa","","","","","","",""};
	};
	
	class red_suburban_15_purple:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Purple)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\purple.paa","","","","","","",""};
	};
	
	class red_suburban_15_darkgreen:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Dark Green)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\darkgreen.paa","","","","","","",""};
	};
	
	class red_suburban_15_darkred:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Dark Red)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_suburban_15\colours\darkred.paa","","","","","","",""};
	};
	
	class red_suburban_15_custom:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Custom 1)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_suburban_15\skins\custom1.paa","","","","","","",""};
	};
	
	class red_suburban_15_custom2:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Custom 2)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_suburban_15\skins\custom2.paa","","","","","","",""};
	};
	
	class red_suburban_15_custom3:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Custom 3)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_suburban_15\skins\custom3.paa","","","","","","",""};
	};
	
	class red_suburban_15_custom4:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Custom 4)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_suburban_15\skins\custom4.paa","","","","","","",""};
	};
	
	class red_suburban_15_custom5:red_suburban_15_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2015 Chevrolet Suburban LTZ (Custom 5)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_suburban_15\skins\custom5.paa","","","","","","",""};
	};
};