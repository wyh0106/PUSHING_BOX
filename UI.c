#include <stdio.h>

int _temp = 0;
// ø | = +
void UI(int UI_type)
{
	char UI__level_select[32][64] = {
		"================================",
		"|  < 1 >  < 2 >  < 3 >  < X >  |",
		"|  < X >  < X >  < X >  < X >  |",
		"|  < ø >  < ø >  < ø >  < ø >  |",
		"================================",
		"Press the number to start your game.",
		"'Q'->quit."
	};
	char UI__WIN[5][64] = {
		"================================",
		"+                              +",
		"+           YOU WIN            +",
		"+                              +",
		"================================"
	};
	char UI__TIPS[128] = "Press 'R' you can reset the checkpoint.\nAnd press the 'B' you can back to the menu.";

	if(0 == UI_type)
	{
		system("cls");
		for(_temp=0;_temp<=6;_temp++)
			puts(UI__level_select[_temp]);
	}
	else if(1 == UI_type)
	{
		system("cls");
		for(_temp=0;_temp<=4;_temp++)
			puts(UI__WIN[_temp]);
	}
	else if(3 == UI_type)
		puts(UI__TIPS);
}