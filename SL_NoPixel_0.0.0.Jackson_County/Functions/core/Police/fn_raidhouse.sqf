_player = _this select 0;

if(player distance myhouse < 100) then {

	[player] remoteExec ["server_fnc_retreivehouse",2];

} else {
	[myhouse,"Lokalizacja domu","Job"] remoteexec ["client_fnc_hudHelper",_player];
};