params["_player","_items"];
if(isNull _player) exitWith { diag_log "Stat save - player null"; };
_statuses = _player getVariable "statuses";
_uid = getPlayerUID _player;
if(isNil "_statuses") exitwith { };

//_items = getunitloadout _player;

_items = _player getVariable "getunitloadout";

_phoneBackground = _player getVariable "phoneBackground";
_messages = _player getVariable "messages";

_house = _player getVariable "house";
//_shop = _player getVariable "shop";

//_shop setVariable ["shop",nil,false];
//shops pushback _shop;


_houselevel = _player getVariable "houselevel";

/*if (_houseLevel == 1) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 2) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 3) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 4) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 5) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 6) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 7) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 8) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 9) then {
        tier3housing pushback _house;
    };*/



//_housecontent = _player getVariable "housecontent";
//_shopcontent = _player getVariable "shopcontent";


deletemarker format["%1",_uid];

_cash = _player getVariable "wallet";
_bank = _player getVariable "atm";

_position = position _player;

_syncInfo = _player getVariable "sync";
if(isNil "_syncInfo") then { _syncinfo = 1; };
//_exit = false;

if(_syncInfo == 0 || _player in CurrentCop || _player in currentEMS || _player in currentFire) then {
    _updatestr = format ["updatePlayerInfoNoGearNoShopNoHouse:%1:%2:%3:%4:%5:%6:%7:%8", _cash, _bank, _position, _messages, _statuses, _phonebackground, _houselevel, _uid]; 
	_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;

	//_updatestr = format ["updatePlayerInfoNoGear:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10", _cash, _bank, _position, _messages, _statuses, _housecontent, _shopcontent, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerInfoNoGearNoMoneyNoShop:%1:%2:%3:%4:%5:%6", _position, _messages, _statuses, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerHouseShop:%1:%2:%3", _housecontent, _shopcontent, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerMoney:%1:%2:%3", _cash, _bank, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
} else {

    _updatestr = format ["updatePlayerInfoNoShopNoHouse:%1:%2:%3:%4:%5:%6:%7:%8:%9", _items, _cash, _bank, _position, _messages, _statuses, _phonebackground, _houselevel, _uid]; 
	_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;

    //_updatestr = format ["updatePlayerInfo:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11", _items, _cash, _bank, _position, _messages, _statuses, _housecontent, _shopcontent, _phonebackground, _houselevel, _uid]; 
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerInfoNoGearNoMoneyNoShop:%1:%2:%3:%4:%5:%6", _position, _messages, _statuses, _phonebackground, _houselevel, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerHouseShop:%1:%2:%3", _housecontent, _shopcontent, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//_updatestr = format ["updatePlayerMoney:%1:%2:%3", _cash, _bank, _uid];
	//_update = [0, _updatestr] call ExternalS_fnc_ExtDBquery;
	
	//[_player,_items, _uid] spawn server_fnc_invSave;
    //if(!isNil "theMayor") then { if(_player == theMayor) then { TaxRate = 0; publicVariable "TaxRate"; }; };

};

//if (_exit) exitwith { deleteVehicle _player; };

    /*if (_houseLevel == 1) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 2) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 3) then {
        tier1housing pushback _house;
    };
    if (_houseLevel == 4) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 5) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 6) then {
        tier2housing pushback _house;
    };
    if (_houseLevel == 7) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 8) then {
        tier3housing pushback _house;
    };
    if (_houseLevel == 9) then {
        tier3housing pushback _house;
    };*/

/*[] spawn server_fnc_refreshjobs;

_playeroffice = _player getVariable "office";

if(!isNil "_playerOffice") then {
_pia = rentedshops FIND _playeroffice;
rentedshops DELETEAT _pia;
deletemarker format["%1OFFICE",_uid];
};

if(isNil "racecontestents") then { racecontestents = []; };
_pia = racecontestents FIND _player; 
racecontestents DELETEAT _pia;

//deleteVehicle _player;

_pia = MafiaLoan1 FIND _player;

if(_pia != -1) then {
MafiaLoan1 DELETEAT _pia;
MafiaLoan2 DELETEAT _pia;
};



_player setvariable ["getunitloadout",nil,false];
_player setVariable ["sync", nil, false];
_player setVariable ["wallet", nil, false];
_player setVariable ["atm", nil, false];
_player setVariable ["bankAccount", nil, false];
_player setVariable ["cop", nil, false];
_player setVariable ["ems", nil, false];
_player setVariable ["mafia", nil, false];
_player setVariable ["fire", nil, false];
_player setVariable ["legal", nil, false];
_player setVariable ["garage", nil, false];
_player setVariable ["phoneBackground", nil, false];
_player setVariable ["messages", nil, false];
_player setVariable ["statuses", nil, false];
_player setVariable ["houselevel", nil, false];
_player setVariable ["housecontent", nil, false];
_player setVariable ["shopcontent", nil, false];
_player setVariable ["house", nil, false];
_player setVariable ["office", nil, false];
_player setVariable ["shop", nil, false];*/


//[_player, "save", "Zapisano gracza"] call Server_fnc_insertLog;
