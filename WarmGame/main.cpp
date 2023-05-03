#include "main_head.h"

void START();
void RESET();
bool UPDATE();
void RENDER();

static Game_bord bord(GAME_BORD_SIZE);
static Worm Bug(GAME_BORD_SIZE / 2, GAME_BORD_SIZE / 2);
static bool applec = false;
static int score = 0;

int main()
{
	START();
	RESET();
	while (UPDATE())
	{
		RENDER();
	}
	return 0;
}

void START()
{
}

void RESET()
{
}

bool UPDATE()
{
	Bug.INPUT();
	if (applec == false) { 
		bord.Set_apple(); 
		applec = true; 
	}
	if (bord.CHACK_HEAD(Bug) == 2) {
		Bug.Makemove_body();
		bord.UPDATE_BORD(Bug.Get_Worm());
		applec = false;
		score += 500;
		return true;
	}
	else if (bord.CHACK_HEAD(Bug) < 0)
		return false;
	else
	{
		Bug.Move_body();
		bord.UPDATE_BORD(Bug.Get_Worm());
		return true;
	}
}

void RENDER()
{
	system("cls");
	bord.Print_bord();
	printf("\nÁ¡¼ö : %d", score);
	Sleep(250);
}
