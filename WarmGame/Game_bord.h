#pragma once
#include "main_head.h"

class Game_bord
{
	int Bord_size;
	int* bord;
public:
	Game_bord(int Bord_size);
	auto Print_bord() ->void;
	auto Set_apple()->void;
	auto UPDATE_BORD(Worm_body def) -> void;
	auto CHACK_HEAD(int x, int y, Worm_body def)->int;
};