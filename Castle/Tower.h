#pragma once
#include <fstream>
#include "../DS/LinkedList.cpp"
class Tower
{
	double Health;
	double MaxEnemyNum;
	double FirePower;
	double DamageDE;
	int unpaved;
	double TotalDam;
	LinkedList<Enemy> SF;
	LinkedList<Enemy> F;
	LinkedList<Enemy> killed;
	int Scount;
	int Fcount;
	int Kcount;
	int totalkilled;
	

public:
	Tower();
	void SetHealth(double h);
	double GetHealth() const;

	void setmax(double );
	double getmax() const ;
	void decrement();
	void setfire(double);
	double getfire() const;
	void addenemy(Enemy*);
	void addkilled(Enemy*);
	void deletekilled();
	void deletefighter();
	void deletesfighter();
	void MoveEnemy();
	void AttackTower();
	void setUnpaved(int);
	void DecreementHealth(double);
	bool destroyed();
	int getScount();
	int getFcount();
	int getKcount();
	int gettotalkilled();
	double gettotdamaged();
	int getunpave();
	LinkedList<Enemy> & getshieldedf();
	LinkedList<Enemy>& getfighter();
	LinkedList<Enemy>& getkilled();
	void attackenemies(int);
	void checkilled(int);
	void ShiftEnemies(Tower& t);
	void SetNewReg(int);
	void SetNewDis(Tower t);
	void clearTower();
	~Tower();

	//
	// TODO: Add More Member Functions As Needed
	//

};

