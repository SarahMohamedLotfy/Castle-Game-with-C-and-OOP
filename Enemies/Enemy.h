#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

// Enemy is the base class of each type of enemy
// Enemy is an abstract class.
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	int UnpavedDist;             //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double Type;   //0:paver 1:fighter  2:shielded
	double FirePow;
	double Time;//arrival time
	double FirstShotTime;
	double KilledTime;
	double RemainToShoot;//remaining time to shoot
	double RLD; //reload time
	double DamageDT;
	//double FD;//first shot delay
	//double KD;//kill delay
	//double LT;//life time
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(color r_c, REGION r_region, int d = MaxDistance);
	Enemy();
	void setID(double);
	double getID() const;
	void sethealth(double);
	double gethealth()const;
	void setype(double);
	double getype()const;
	void setfire(double);
	double getfire()const;
	void setfirstshot(double);
	double getfirstshot ();
	void setkilledtime(double);
	void setremainshoot(double);
	double getremainshoot()const;
	double getkilledtime ()const;
	void setunpaved(int );
	int getunpaved() const;
	double getdamage()const;
	double getKD()const;
	double getFD()const;
	double getLT()const;
	double getkilledtime();
	void setime(double);
	double getime()const;
	void setRLD(double);
	double getRLD()const;
	void setRegNum(int);
	int getRegNum()const;
	

	color GetColor() const;
	void setregion(char);
	REGION GetRegion() const;
	
	void DecrementDist();
	void DecrementUnpaved();
	void SetDistance(int d);
	int GetDistance() const;
	// Virtual Functions: ----------------

	virtual void Move() = 0;	    //All enemies can move
	virtual void Attack() = 0;	//All enemies can attack (attacking is paving or shooting)
	virtual void isattacked (double)=0;
	virtual bool operator >=(const Enemy& e);
	//
	// TODO: Add More Member Functions As Needed
	//
	virtual ~Enemy();
};

