private ["_old", "_new"];
params ["_amount"];
_old = player getVariable "sl_atm_silverlake";
_new = _old - _amount;
if (_new < 0) then {
	_return = false;
} else {
	player setVariable ["atm", _new, false];
	[player, "atm", _new] remoteExec ["StanLakesideServer_fnc_setVariable",2];
	[2,_new,_new,getplayeruid player] remoteExec ["StanLakesideServer_fnc_syncmoney",2];
	_return = true;
};