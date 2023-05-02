#pragma once
#include "main_head.h"

class Worm
{
	Worm_body FWhead;
	Worm_body* FWbody;

	int movex;
	int movey;

public:
	Worm(int&& x, int&& y);
	auto Makemove_body() -> void;
	auto Move_body() ->void;
	auto Get_Worm() -> Worm_body&;
	auto INPUT() -> void;
	auto Frontx() -> int;
	auto Fronty() -> int;
};

