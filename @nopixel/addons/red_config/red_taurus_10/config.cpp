class CfgPatches
{
	class red_taurus_10
	{
		units[] = {"red_taurus_10_p"};
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

	class red_taurus_10_base: Car_F
	{
		model 	= "\red_taurus_10\red_taurus_10_p";  /// simple path to model
		picture	= "\red_base\textures\icon.paa"; /// icon in map	
		Icon	= "\red_base\textures\icon.paa"; /// icon in map		
		author = "Redhotsteel";
		hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection	
		terrainCoef 	= 1.0; 	/// different surface affects this car more, stick to tarmac
		turnCoef 		= 2.5; 	/// should match the wheel turn radius
		precision 		= 10; 	/// how much freedom has the AI for its internal waypoints - lower number means more precise but slower approach to way
		brakeDistance 	= 3.0; 	/// how many internal waypoints should the AI plan braking in advance
		acceleration 	= 15; 	/// how fast acceleration does the AI think the car has
		fireResistance 	= 5; 	/// lesser protection against fire than tanks
		armor 			= 32; 	/// just some protection against missiles, collisions and explosions
		cost			= 50000; /// how likely is the enemy going to target this vehicle
		
		transportMaxBackpacks 	= 3; /// just some backpacks fit the trunk by default
		transportSoldier 		= 3; /// number of cargo except driver
		
		/// some values from parent class to show how to set them up
		wheelDamageRadiusCoef 	= 0.9; 			/// for precision tweaking of damaged wheel size
		wheelDestroyRadiusCoef 	= 0.4;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 0.5;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.25;			/// multiplier of damage to crew of the vehicle => low number means better protection
		driverLeftHandAnimName 	= "drivewheel"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "drivewheel";	/// beware, non-existent bones may cause game crashes (even if the bones are hidden during play)
		driveOnComponent[] = {"wheel_1_1_damper","wheel_1_2_damper","wheel_2_1_damper","wheel_2_2_damper"};
		extCameraPosition[] = {0, 1, -7.5};
		
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
		driverAction 		= driver_offroad01; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		cargoAction[] = {passenger_low01,passenger_generic01_leanleft,passenger_generic01_leanright};
		getInAction 		= GetInLow; 		/// how does driver look while getting in
		getOutAction 		= GetOutLow; 		/// and out
		cargoGetInAction[] 	= {"GetInLow"}; 	/// and the same for the rest, if the array has fewer members than the count of crew, the last one is used for the rest
		cargoGetOutAction[] = {"GetOutLow"}; 	/// that means all use the same in this case
		
		attenuationEffectType = "CarAttenuation"; //utlumovani v interieru (odkaz do Attenuation.hpp ve slozce SOUNDS_F

		soundGetIn[]={"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_door",db-5,1};
		soundGetOut[]={"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_door",db-5,1, 40};
		soundDammage[]={"", db-5, 1};
		soundEngineOnInt[] = {"red_base\sounds\SEDAN_V8\start_int.wss",db7,1.0};
		soundEngineOnExt[] = {"red_base\sounds\SEDAN_V8\start.wss",db14,1.0,200};
		soundEngineOffInt[] = {"red_base\sounds\MUSCLE_V8\v8_int_stop.wss",0.39810717,1.0};
		soundEngineOffExt[] = {"red_base\sounds\MUSCLE_V8\v8_ext_stop.wss",0.4466836,1.0,200};

		/* ---- CRASHES START ---- */
		
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

		/* ---- CRASHES  END ---- */

		class	Sounds
		{
			
			// warp	factor
			#define	FACTOR(val,from,to)	(val factor[from,to])
			// RANGE(val,	begin, band, end,	band)
			#define	RANGE(val,from,band0,to,band1) FACTOR2(val,from,(from+band0),to,(to+band1))
			// FACTOR2(val,	0, 400,	1200,	2000)
			#define	FACTOR2(val,from0,to0,from1,to1) (FACTOR(val,from0,to0)	*	FACTOR(val,to1,from1))

			// redRpm
			#define	MAX_RPM	8000
			// scaled	rpm	to 0 - 1
			#define	RPM(rpm) (rpm/MAX_RPM)

			// specialized FACTOR	for	rpm
			#define	FACTOR_RPM(from,to)	FACTOR(RPM(rpm),RPM(from),RPM(to))
			// specialized peak	for	rpm
			#define	FACTOR2_RPM(from0,to0,from1,to1) (FACTOR_RPM(from0,to0)	*	FACTOR_RPM(to1,from1))
			// specialized peak, different definition, version for rpm
			#define	RANGE_RPM(from,band0,to,band1) FACTOR2_RPM(from,(from+band0),to,(to+band1))
			

			#define HZ_IDLE FACTOR_RPM(400,1150)
			#define HZ_RPM1 FACTOR_RPM(900,2100)
			#define HZ_RPM2	FACTOR_RPM(1300,3100)
			#define HZ_RPM3 FACTOR_RPM(2200,4100)
			#define HZ_RPM4 FACTOR_RPM(3300,4900)
			#define HZ_RPM5 FACTOR_RPM(4200,6200)
			#define HZ_RPM6 FACTOR_RPM(5100,6400)
			#define HZ_RPM7 FACTOR_RPM(6000,7400)
			#define HZ_RPM8 FACTOR_RPM(6900,7900)
			
			#define VOLUME_IDLE FACTOR2_RPM(400,700,900,1100)
			#define VOLUME_RPM1 FACTOR2_RPM(870,1100,1300,2100)
			#define VOLUME_RPM2 FACTOR2_RPM(1250,2050,2300,3100)
			#define VOLUME_RPM3 FACTOR2_RPM(2250,3050,3300,4100)
			#define VOLUME_RPM4 FACTOR2_RPM(3250,4050,4200,4870)
			#define VOLUME_RPM5 FACTOR2_RPM(4150,4800,4150,5150)
			#define VOLUME_RPM6 FACTOR2_RPM(4250,5050,5200,6870)
			#define VOLUME_RPM7 FACTOR2_RPM(5150,5800,6150,7150)
			#define VOLUME_RPM8 FACTOR_RPM(6100,7100)
			
			/*		HATCHBACK EXTERNI ZVUK BEZ PLYNU 	 */

			
			class	Idle_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_01520.wav", db-11,	1, 150};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*camPos*VOLUME_IDLE;
			};
			class	Engine
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_01635.wav",	db-10,1, 200};
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*camPos*VOLUME_RPM1;
			};
			class	Engine1_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_02188.wav",	db-9,1, 240};
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*camPos*VOLUME_RPM2;
			};
			class	Engine2_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_02729.wav",	db-8,1, 280};
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*camPos*VOLUME_RPM3;
			};
			class	Engine3_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_03281.wav",	db-7,1, 320};
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*camPos*VOLUME_RPM4;
			};
			class	Engine4_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_04362.wav",	db-6,1, 360};
				frequency	=	0.8	+	HZ_RPM5*0.2;
				volume = engineOn*camPos*VOLUME_RPM5;
			};
			class	Engine5_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_04915.wav",	db-5,1, 420};
				frequency	=	0.95	+	HZ_RPM6*0.2;
				volume = engineOn*camPos*VOLUME_RPM7;
			};
			class	Engine6_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_05462.wav",	db-5,1, 460};
				frequency	=	0.95	+	HZ_RPM7*0.2;
				volume = engineOn*camPos*VOLUME_RPM7;
			};
			class	Engine7_ext
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Ext_06003.wav",	db-5,1, 500};
				frequency	=	0.95	+	HZ_RPM8*0.15;
				volume = engineOn*camPos*VOLUME_RPM8;
			};
			
				/*   POD PLYNEM EXTERNI  */
				
		  class IdleThrust
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_00691.wav", db-15,1, 200};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_IDLE;
		  };
		  class EngineThrust
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_01056.wav", db-14,1, 250};
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM1;
		  };
		  class Engine1_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_01270.wav", db-13,1, 280};
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM2;
		  };
		  class Engine2_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_01591.wav", db-12,1, 320};
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM3;
		  };
		  class Engine3_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_01804.wav", db-11,1, 360};
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM4;
		  };
		  class Engine4_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_02017.wav", db-10,1, 380};
				frequency	=	0.8	+	HZ_RPM5*0.3;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM5;
		  };
		  class Engine5_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_02327.wav", db-9,1, 400};
				frequency	=	0.8	+	HZ_RPM6*0.3;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM6;
		  };
		  class Engine6_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_02648.wav", db-8,1, 420};
				frequency	=	0.8	+	HZ_RPM7*0.3;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM7;
		  };
		  class Engine7_Thrust_ext
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Thrust_03094.wav", db-7,1, 450};
				frequency	=	0.9	+	HZ_RPM8*0.2;
				volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM8;
		  };  

				/*  konec pod plynem externi */

				/* INTERNI OZVUCENI BEZ PLYNU */

			class	Idle_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_00841.wav", db-15,	1};
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*(1-camPos)*VOLUME_IDLE;
			};
			class	Engine_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_01636.wav",	db-14,1 };
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM1;
			};
			class	Engine1_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_02174.wav",	db-13,1 };
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM2;
			};
			class	Engine2_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_02729.wav",	db-12,1 };
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM3;
			};
			class	Engine3_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_03271.wav",	db-11,1 };
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM4;
			};
			class	Engine4_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_03820.wav",	db-10,1 };
				frequency	=	0.8	+	HZ_RPM5*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM5;
			};
			class	Engine5_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_04366.wav",	db-9,1 };
				frequency	=	0.8	+	HZ_RPM6*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM6;
			};
			class	Engine6_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_04911.wav",	db-8,1 };
				frequency	=	0.8	+	HZ_RPM7*0.2;
				volume = engineOn*(1-camPos)*VOLUME_RPM7;
			};
			class	Engine7_int
			{
				sound[]	=	{"red_base\sounds\SEDAN_V8\Int_05998.wav",	db-8,1 };
				frequency	=	0.95	+	HZ_RPM8*0.15;
				volume = engineOn*(1-camPos)*VOLUME_RPM8;
			};

				/*   POD PLYNEM   */
				
		  class IdleThrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_00691.wav", db-25,1 };
				frequency	=	0.9	+	HZ_IDLE*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_IDLE;
		  };
		  class EngineThrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_01056.wav", db-24,1 };
				frequency	=	0.8	+	HZ_RPM1*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM1;
		  };
		  class Engine1_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_01270.wav", db-23,1 };
				frequency	=	0.8	+	HZ_RPM2*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM2;
		  };
		  class Engine2_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_01591.wav", db-22,1 };
				frequency	=	0.8	+	HZ_RPM3*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM3;
		  };
		  class Engine3_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_01804.wav", db-21,1 };
				frequency	=	0.8	+	HZ_RPM4*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM4;
		  };
		  class Engine4_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_02017.wav", db-20,1 };
				frequency	=	0.8	+	HZ_RPM5*0.3;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM5;
		  };
		  class Engine5_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_02327.wav", db-19,1 };
				frequency	=	0.8	+	HZ_RPM6*0.3;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM6;
		  };
		  class Engine6_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_02648.wav", db-18,1 };
				frequency	=	0.8	+	HZ_RPM7*0.3;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM7;
		  };
		  class Engine7_Thrust_int
		  {
			sound[] = {"red_base\sounds\SEDAN_V8\Int_Thrust_03094.wav", db-19,1 };
				frequency	=	0.9	+	HZ_RPM8*0.2;
				volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*VOLUME_RPM8;
		  };  
			class	Movement
			{
				sound	=	"soundEnviron";
				frequency	=	"1";
				volume = "0";
			};
				/*   KONEC POD PLYNEM   */


			/*----------------------------------*/		
			/*-----------  TIRES EXT ---------*/
			/*----------------------------------*/ 
			
					class TiresRockOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*rock*(speed factor[2, 20])";
					};
					class TiresSandOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*sand*(speed factor[2, 20])";
					};
					class TiresGrassOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*grass*(speed factor[2, 20])";
					};
					class TiresMudOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*mud*(speed factor[2, 20])";
					};
					class TiresGravelOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*gravel*(speed factor[2, 20])";
					};
					class TiresAsphaltOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db-6, 1.0, 60};
						frequency = "1";
						volume = "camPos*asphalt*(speed factor[2, 20])";
					};
					class NoiseOut
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", db-8, 1.0, 90};
						frequency = "1";
						volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
					};
					
			/*----------------------------------*/
			/*-----------  TIRES INT ---------*/
			/*----------------------------------*/

					class TiresRockIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*rock*(speed factor[2, 20])";
					};
					class TiresSandIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*sand*(speed factor[2, 20])";
					};
					class TiresGrassIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*grass*(speed factor[2, 20])";
					};
					class TiresMudIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*mud*(speed factor[2, 20])";
					};
					class TiresGravelIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*gravel*(speed factor[2, 20])";
					};
					class TiresAsphaltIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", db-6, 1.0};
						frequency = "1";
						volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
					};
					class NoiseIn
					{
						sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db-12, 1.0};
						frequency = "1";
						volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)"; //definice INSIDE zvuku
					};
			
			/*------------------------------------------------------------------*/	
			/*-------------- ozvuceni piskani pneumatik EXT -------------*/
			/*------------------------------------------------------------------*/	
				
			/* zvuk na silnici */

				class breaking_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
			
				class acceleration_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};	
				class turn_left_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};	

				class turn_right_ext_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db-3, 1, 80};
				frequency	=	1;
				volume = engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	

				/*-----------------------------------------------------------------*/
				/*ozvuceni piskani pneumatik na ostatnich povrsich EXT */
				/*-----------------------------------------------------------------*/
				
				class breaking_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
			};	
				class acceleration_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration", db-3,	1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1]);
			};	
				class turn_left_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15]);
			};	

				class turn_right_ext_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db-3, 1, 60};
				frequency	=	1;
				volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
			};	

			
			/*---------------------------------------------------------------------------*/	
			/*-------------- ozvuceni piskani pneumatik INT silnice --------------*/
			/*---------------------------------------------------------------------------*/	

				class breaking_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	
			
				class acceleration_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};	
				class turn_left_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};	
				class turn_right_int_road
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
			};	

			/*--------------------------------------------------------------------------------------------*/	
			/*-------------- ozvuceni piskani pneumatik na ostatnich povrsich INT -------------*/
			/*--------------------------------------------------------------------------------------------*/	
				class breaking_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15]);
			};	
				class acceleration_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int", db-10, 1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
			};	
				class turn_left_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db-10,	1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
			};	
				class turn_right_int_dirt
			{
				sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db-10,	1};
				frequency	=	1;
				volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
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
		maxSpeed = 241;	// max speed on level road, km/h
		fuelCapacity = 45;
		wheelCircumference = 2.277;
		antiRollbarForceCoef = 2.0;
		antiRollbarForceLimit = 2.0;
		antiRollbarSpeedMin = 20;
		antiRollbarSpeedMax = 80;
		idleRpm = 900;
		redRpm = 5500;
		
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
		maxOmega = 575.96;
		enginePower = 272;
		peakTorque = 474.53;	
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
				springStrength = 6813; //6813
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
				maxHandBrakeTorque = 2500;
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
				maxHandBrakeTorque = 2500;
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
				color[] 		= {2000, 2000, 1700};		/// approximate colour of standard lights
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
				flareSize 		= 0.5;							/// how big is the flare

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

	class red_taurus_10_black:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Black)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\black.paa"};
	};
	
	class red_taurus_10_aqua:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Aqua)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\aqua.paa"};
	};
	
	class red_taurus_10_darkblue:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Dark Blue)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\darkblue.paa"};
	};
	
	class red_taurus_10_blue:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Blue)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\blue.paa"};
	};
	
		class red_taurus_10_green:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Green)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\green.paa"};
	};
	
	class red_taurus_10_red:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Red)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\red.paa"};
	};
	
	class red_taurus_10_pink:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Pink)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\pink.paa"};
	};
	
		class red_taurus_10_yellow:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Yellow)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\yellow.paa"};
	};
	
	class red_taurus_10_orange:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Orange)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\orange.paa"};
	};
	
	class red_taurus_10_white:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (White)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\white.paa"};
	};
	
		class red_taurus_10_purple:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Purple)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\purple.paa"};
	};
	
		class red_taurus_10_darkgreen:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Dark Green)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\darkgreen.paa"};
	};
	
		class red_taurus_10_darkred:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Dark Red)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_taurus_10\colours\darkred.paa"};
	};
	
		class red_taurus_10_custom:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Custom 1)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_taurus_10\skins\custom1.paa"};
	};
	
		class red_taurus_10_custom2:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Custom 2)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_taurus_10\skins\custom2.paa"};
	};
	
		class red_taurus_10_custom3:red_taurus_10_base
	{	
		scope	= 2; 			/// makes the car visible in editor
		scopeCurator=2;			// scope 2 means it's available in Zeus mode (0 means hidden)
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		displayName = "2010 Ford Taurus SHO (Custom 3)";
		vehicleClass = "red_civilian";
		author = "Redhotsteel";
		hiddenSelectionsTextures[] = {"\red_config\red_taurus_10\skins\custom3.paa"};
	};
};