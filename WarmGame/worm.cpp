#include "Worm.h"

Worm::Worm(int&& x, int&& y)
{
	movex = 0;
	movey = -1;

	FWhead.x = x;
	FWhead.y = y;
	FWhead.now = head;

	Worm_body* def1 = (Worm_body*)calloc(1,sizeof(Worm_body));

	this->FWbody = def1;
	def1->front = &FWhead;
	FWhead.back = def1;

	def1->back = NULL;
	def1->now = space;
	def1->x = x;
	def1->y = y + 1;
}

auto Worm::Makemove_body() -> void
{
	Worm_body* def = (Worm_body*)malloc(sizeof(Worm_body));
	// 몸 하나 생성.

	def->x = FWhead.x;
	def->y = FWhead.y;
	def->now = body;

	FWhead.x += movex;
	FWhead.y += movey;
	// 이동좌표 갱신

	def->front = &FWhead;
	def->back = FWbody;

	FWhead.back = def;
	FWbody->front = def;
	// 주소좌표 재기입.

	FWbody = def;
	// 최상단 주소 갱신. 후 종료
}

auto Worm::Move_body() -> void
{
	Worm_body* def = &FWhead; // 첫 주소 위치를 기록.

	while (def->back != NULL) { // 배열 전체 순환
		def = def->back;
		// 순환하면서 좌표를 계속 갱신한다.
	}
	while (def->front != NULL) {
		def->x = def->front->x;
		def->y = def->front->y;
		def = def->front;
	}

	FWhead.x += movex;
	FWhead.y += movey;
	// 머리 좌표 이동.
}

auto Worm::Get_Worm() -> Worm_body&
{
	return FWhead;
}

auto Worm::INPUT() -> void
{
	if (GetAsyncKeyState(VK_LEFT)) {
		movex = -1;
		movey = 0;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		movex = 1;
		movey = 0;
	}
	else if (GetAsyncKeyState(VK_UP)) {
		movex = 0;
		movey = -1;
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		movex = 0;
		movey = 1;
	}
}

auto Worm::Frontx() -> int
{
	return movex;
}

auto Worm::Fronty() -> int
{
	return movey;
}

