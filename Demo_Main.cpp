#include "Battle.h"
#include "GUI\GUI.h"
#include "Castle\Tower.h"
#include <fstream>

int main()
{
	Battle* pGameBattle = new Battle;
	GUI * pGUI = new GUI;
	actions a;
	pGUI->PrintMessage("choose an action please ;)");
	a=pGUI->getaction();
	while(a != Exit)
	{
		switch (a)
		{
		case addfile:
			pGUI->PrintMessage("you chose add file action :)");
			pGameBattle->read(pGUI);
			pGUI->PrintMessage("File has been added successfully :)");
			Sleep(500);
			pGUI->PrintMessage("choose mode to start the game ;)");
			break;
		case outputfilemode:
			pGUI->PrintMessage("you chose outputfile mode :)");
			break;
		case interactivemode:
			pGUI->PrintMessage("you chose interactive mode have fun :)");
			pGameBattle->simulation(pGUI,interactivemode);
			break;
		case automode:
			pGUI->PrintMessage("you chose auto mode have fun :)");
			pGameBattle->simulation(pGUI,automode);
			break;
		case Empty_area:
			pGUI->PrintMessage("that's an empty area :(");
			break;
		}

		a=pGUI->getaction();
	}
	delete pGUI;
	delete pGameBattle;
	return 0;
}
