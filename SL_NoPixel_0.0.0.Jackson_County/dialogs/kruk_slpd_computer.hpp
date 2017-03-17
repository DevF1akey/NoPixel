class kruk_slpd_computer {
	idd = 666001;
	name = "kruk_slpd_computer";
	movingEnable = 0;
	enableSimulation = 1;
	onLoad = "[player] remoteExec [""server_fnc_slpdComputerLoad"", 2]";
	class controls {
		class edit_search_input: Client_RscEdit
		{
			idc = 1001;
			text = "";
			autocomplete = "";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 2.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.3};
		};
		class edit_vehicle: Client_RscEdit
		{
			idc = 1002;
			text = "";
			autocomplete = "";
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.3};
		};
		class listbox_criminals: client_RscListBox
		{
			idc = 1101;
		    sizeEx = 0.02921;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 7.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.3};
		};
		class listbox_vehicles: client_RscListBox
		{
			idc = 1102;
		    sizeEx = 0.02921;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 8.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.3};
		};
		class listbox_players: client_RscListBox
		{
			idc = 1103;
		    sizeEx = 0.02921;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 7.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.3};
		};
		class button_search_plate: client_RscButtonMenu
		{
			idc = 1201;
			text = "Szukaj rejestracji"; //--- ToDo: Localize;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 15.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_search_name: client_RscButtonMenu
		{
			idc = 1202;
			text = "Szukaj Imię i Nazwisko"; //--- ToDo: Localize;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 17 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_search_uid: client_RscButtonMenu
		{
			idc = 1202;
			text = "Szukaj PESEL"; //--- ToDo: Localize;
			action = "[player, (ctrlText 1001)] remoteExec [""server_fnc_slpdCheckPlayer""];";
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 18.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_close: client_RscButtonMenu
		{
			idc = 1203;
		    sizeEx = 0.02921;
			style = 2;
			text = "Zamknij"; //--- ToDo: Localize;
			x = 31 * GUI_GRID_W + GUI_GRID_X;
			y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_search_case: client_RscButtonMenu
		{
			idc = 1204;
		    sizeEx = 0.02921;
			text = "Szukaj Sprawy"; //--- ToDo: Localize;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 20 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_vehicle_check: client_RscButtonMenu
		{
			idc = 1205;
		    sizeEx = 0.02921;
			text = "Sprawdź"; //--- ToDo: Localize;
			style = 2;
			x = 15.5 * GUI_GRID_W + GUI_GRID_X;
			y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "_data = lbData[1102,lbCurSel (1102)]; _data = call compile format[""%1"", _data]; [_data, ""vehicle""] spawn client_fnc_load_checkCase;";
			colorBackground[] = {0,0,0,0.7};
		};
		class button_check_list: client_RscButtonMenu
		{
			idc = 1206;
		    sizeEx = 0.02921;
			text = "Sprawdź"; //--- ToDo: Localize;
			style = 2;
			x = 35.5 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "_data = lbData[1103,lbCurSel (1103)]; _data = call compile format[""%1"", _data]; [player, (_data select 0)] remoteExec [""server_fnc_slpdCheckPlayer""];";
			colorBackground[] = {0,0,0,0.7};
		};
		class button_criminal_add: client_RscButtonMenu
		{
			idc = 1207;
		    sizeEx = 0.02921;
			text = "Dodaj"; //--- ToDo: Localize;
			style = 2;
			x = 31 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_add_vehicle: client_RscButtonMenu
		{
			idc = 1208;
		    sizeEx = 0.02921;
			text = "Dodaj"; //--- ToDo: Localize;
			style = 2;
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_change: client_RscButtonMenu
		{
			idc = 1209;
		    sizeEx = 0.02921;
			text = "Zmień"; //--- ToDo: Localize;
			style = 2;
			x = 6.5 * GUI_GRID_W + GUI_GRID_X;
			y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 4.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_case_check: client_RscButtonMenu
		{
			idc = 1210;
		    sizeEx = 0.02921;
			text = "Podgląd sprawy"; //--- ToDo: Localize;
			style = 2;
			x = 11 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.0 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "_data = lbData[1101,lbCurSel (1101)]; _data = call compile format[""%1"", _data]; [_data, ""personal""] spawn client_fnc_load_checkCase;";
			colorBackground[] = {0,0,0,0.7};
		};
		class text_title: RscText
		{
			idc = -1;
			text = "SLPD Computer"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 40 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_wanted_criminals: RscText
		{
			idc = -1;
			text = "Wanted Criminals"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_search: RscText
		{
			idc = -1;
			text = "Search"; //--- ToDo: Localize;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_wanted_vehicles: RscText
		{
			idc = -1;
			text = "Wanted Vehicles"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_search_input: RscText
		{
			idc = -1;
			text = "Search Input"; //--- ToDo: Localize;
			x = 21 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 19 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
	};
};
class kruk_slpd_casefile {
	idd = 666002;
	name = "kruk_slpd_casefile";
	movingEnable = 0;
	enableSimulation = 1;
	class controls {
		class edit_level: Client_RscEdit
		{
			idc = 1001;
			text = "";
			autocomplete = "";
			colorBackground[] = {0,0,0,0.3};
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 5.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};	
		class listbox_tickets: client_RscListBox
		{
			idc = 1101;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.3};
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 17 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 6 * GUI_GRID_H;
		};
		class listbox_activeCases: client_RscListBox
		{
			idc = 1102;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.3};
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 4 * GUI_GRID_H;
		};
		class listbox_restCases: client_RscListBox
		{
			idc = 1103;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.3};
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 6 * GUI_GRID_H;
		};
		class listbox_vehicles: client_RscListBox
		{
			idc = 1104;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.3};
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 10 * GUI_GRID_H;
		};
		class button_add: client_RscButtonMenu
		{
			idc = 1201;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.7};
			text = "Dodaj"; //--- ToDo: Localize;
			x = 33.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class button_change: client_RscButtonMenu
		{
			idc = 1202;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.7};
			text = "Zmień"; //--- ToDo: Localize;
			x = 26.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class button_close: client_RscButtonMenu
		{
			idc = 1203;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.7};
			text = "Zamknij"; //--- ToDo: Localize;
			x = 32.5 * GUI_GRID_W + GUI_GRID_X;
			y = 23.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "closeDialog 0;";
		};
		class text_title: RscText
		{
			idc = -1;
			text = "Kartoteka"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 40 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
		class text_info: RscText
		{
			idc = 1301;
			style = 16;
		    sizeEx = 0.035;
			text = "Informacje"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 9 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_tickets: RscText
		{
			idc = -1;
			text = "Mandaty"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
		class text_activeCases: RscText
		{
			idc = -1;
			text = "Aktywne Sprawy"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
		class text_titleInfo: RscText
		{
			idc = -1;
			text = "Informacje"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
		class text_titleLicences: RscText
		{
			idc = -1;
			text = "Pojazdy"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
		class text_restCases: RscText
		{
			idc = -1;
			text = "Przedawnione"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 19.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
		};
	};
};
class kruk_slpd_info{
	idd = 666003;
	name = "kruk_slpd_info";
	movingEnable = 0;
	enableSimulation = 1;
	class controls {
		class text_title: RscText
		{
			idc = 1000;
			text = "Informacje"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_info: RscText
		{
			idc = 1001;
			text = "Informacje"; //--- ToDo: Localize;
			style = 16;
		    sizeEx = 0.035;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 1 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 14.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class button_caseClose: client_RscButtonMenu
		{
			idc = 1201;
			text = "Umorzenie"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 15.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.7};
		};
		class button_close: client_RscButtonMenu
		{
			idc = 1202;
			text = "Zamknij"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 15.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			action = "closeDialog 0;";
		    sizeEx = 0.02921;
			colorBackground[] = {0,0,0,0.7};
		};
	};
};
class kruk_slpd_vehicle_add {
	idd = 666004;
	name = "kruk_slpd_vehicle_add";
	movingEnable = 0;
	enableSimulation = 1;
	class controls {
		class edit_plate: Client_RscEdit
		{
			idc = 1001;
			text = "";
			autocomplete = "";
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class edit_level: Client_RscEdit
		{
			idc = 1002;
			text = "";
			autocomplete = "";
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class edit_description: Client_RscEdit
		{
			idc = 1003;
			text = "";
			autocomplete = "";
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 7 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
		};
		class edit_reason: Client_RscEdit
		{
			idc = 1004;
			text = "";
			autocomplete = "";
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 12.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
		};
		class button_caseClose: client_RscButtonMenu
		{
			idc = 1201;
			text = "Dodaj"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class button_close: client_RscButtonMenu
		{
			idc = 1202;
			text = "Zamknij"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class text_plate: RscText
		{
			idc = -1;
			text = "Numer rejestracyjny"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_description: RscText
		{
			idc = -1;
			text = "Opis pojazdu"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_title: RscText
		{
			idc = -1;
			text = "Dodaj pojazd"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_reason: RscText
		{
			idc = -1;
			text = "PowĂłd"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_level: RscText
		{
			idc = -1;
			text = "Poziom"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
	};
};
class kruk_slpd_criminal_add {
	idd = 666005;
	name = "kruk_slpd_criminal_add";
	movingEnable = 0;
	enableSimulation = 1;
	class controls {
		class edit_reason: Client_RscEdit
		{
			idc = 1001;
			text = "";
			autocomplete = "";
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 7 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
		};
		class edit_level: Client_RscEdit
		{
			idc = 1002;
			text = "";
			autocomplete = "";
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class button_caseClose: client_RscButtonMenu
		{
			idc = 1201;
			text = "Dodaj"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class button_close: client_RscButtonMenu
		{
			idc = 1202;
			text = "Zamknij"; //--- ToDo: Localize;
			x = 20.5 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 9.5 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class text_reason: RscText
		{
			idc = -1;
			text = "PowĂłd"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_level: RscText
		{
			idc = -1;
			text = "Poziom"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_title: RscText
		{
			idc = -1;
			text = "Dodaj poszukiwanego"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class text_info: RscText
		{
			idc = -1;
			text = "ImiÄ™ i Nazwisko:"; //--- ToDo: Localize;
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
	};
};