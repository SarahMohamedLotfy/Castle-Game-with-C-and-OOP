#pragma once
#include "..\Enemies\Enemy.h"
#include "..\Enemies\fighter.h"
#include "..\Enemies\paver.h"
#include "..\Enemies\Sighter.h"
#include "..\DS\LinkedList.h"
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
	Tower Towers[NoOfRegions];

	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowersHealth(double h);
	void SetTowersPower(double );
	void SetTowersMaxNum(double );
	void setenemy(Enemy*);
	void killenemy(Enemy*);
	void decrement();
	void deletekilled();
	void deletefighter();
	void deletesfighter();
	void move();
	void attacktower();
	double GetTowershealth(int index);
	double GetTowerspower(int index);
	double GetTowersmaximum(int index);
	bool IsDestroyed(int index);
	int getscountenemy(int index );
	int getfcountenemy(int index );
	int getkcountenemy(int index );
	int gettotkillenemy(int index);
	double GetTowersdamage(int index);
	int getunpaved(int index);
	LinkedList<Enemy>& getSF(int index);
	LinkedList<Enemy>& getF(int index);
	LinkedList<Enemy>& getkilled(int index);
	void attackenemis(int);
	void checkkilled(int);
	void ShiftTowers();
	//
	// TODO: Add More Member Functions As Needed
	//
};
