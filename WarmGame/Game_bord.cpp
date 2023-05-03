#include "Game_bord.h"

auto Print_Set(int def) -> void;
auto MAKE_BORD(int bord_size) -> int*;

Game_bord::Game_bord(int Bord_size)
{
	this->Bord_size = Bord_size;
	bord = MAKE_BORD(this->Bord_size);
}

auto Game_bord::Print_bord() -> void
{
	for (int i = 0; i < Bord_size; i++) {
		for (int j = 0; j < Bord_size; j++) {
			Print_Set(*(bord + i * Bord_size + j));
		}
		printf("\n");
	}
}

auto Game_bord::Set_apple() -> void
{
	std::random_device rd; // 난수 생성기 시드 생성
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, Bord_size* Bord_size -1);

	while (true) {
		int def = dis(gen);
		if (*(bord + def) == space) {
			*(bord + def) = apple;
			break;
		}
	}
}

auto Game_bord::UPDATE_BORD(Worm_body def) -> void
{
	Worm_body wdef = def;
	while (wdef.back != NULL) {
		*(bord + wdef.x + wdef.y * Bord_size) = wdef.now;
		wdef = *wdef.back;
	}
	*(bord + wdef.x + wdef.y * Bord_size) = wdef.now;
}

auto Game_bord::CHACK_HEAD(Worm def) -> int
{
	if (*(bord + def.Get_Worm().x + def.Get_Worm().y * Bord_size + (def.Frontx() + def.Fronty() * Bord_size)) == space)
		return 1;
	else if (*(bord + def.Get_Worm().x + def.Get_Worm().y * Bord_size + (def.Frontx() + def.Fronty() * Bord_size)) == apple)
		return 2;

	return -1;
}

auto MAKE_BORD(int bord_size) -> int*
{
	int* def = (int*)calloc(bord_size*bord_size, sizeof(int));
	
	for (int i = 0; i < bord_size * bord_size; i++) {
		*(def + i) = space;
	}

	for (int i = 0; i < bord_size; i++) {
		*(def + i) = wall;
		*(def + (bord_size * bord_size - 1) - i) = wall;
		*(def + (bord_size * i)) = wall;
		*((def + bord_size - 1) + bord_size * i) = wall;
	}
	
	return def;
}

auto Print_Set(int def) -> void
{
	switch (def)
	{
	case space:
	{
		printf("  ");
		break;
	}
	case apple:
	{
		printf("＠");
		break;
	}
	case head:
	{
		printf("●");
		break;
	}
	case wall:
	{
		printf("□");
		break;
	}
	case body:
	{
		printf("◎");
		break;
	}
	default:
		printf("⊙");
		break;
	}
}