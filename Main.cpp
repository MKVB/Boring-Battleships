#include <iostream>
#include <time.h>
#include "Game.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Game a;
	a.start();
	system("pause");
	return 0;
}
