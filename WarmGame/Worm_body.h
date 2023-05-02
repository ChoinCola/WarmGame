#pragma once
class Worm_body
{
public:
	Worm_body* front = nullptr;
	int x;
	int y;
	int now;
	Worm_body* back = nullptr;
};