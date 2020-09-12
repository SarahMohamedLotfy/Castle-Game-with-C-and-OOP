#pragma once
#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Castle\Tower.h"
#include "Enemies\Sighter.h"
#include "Enemies\Enemy.h"
#include "DS\LinkedList.h"
#include "DS\queue.cpp"
#include "GUI\GUI.h"
// it is the controller of the project

class Battle
{
private:
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	LinkedList<Enemy> killed;
	double TotalFD;
	double TotalKD;
	int totalcount;
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	queue<Enemy> inactive;
	int kcount;
	 
	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	void AddEnemy(Enemy* Ptr);
	void DrawEnemies(GUI * pGUI);
	Castle * GetCastle();
	void simulation(GUI*,actions action);
	void toactive(int i);
	void deletearr();
	void read (GUI*pGUI);
	void print (GUI*pGUI);
	void printkilled(ofstream&outputfile);
	void printall(ofstream&outputfile);
	bool isloss();
	void Clear ();
	//
	// TODO: Add More Member Functions As Needed
	//
};

