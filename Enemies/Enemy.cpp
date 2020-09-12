#include "Enemy.h"


Enemy::Enemy(color r_c, REGION r_region, int d) // constructor of the enemy
{
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
	RemainToShoot=0;
	UnpavedDist=30;
	DamageDT=0;
}

Enemy::Enemy()
{
	Distance=60;  //Horizontal distance between enemy & the tower of its region to 60
	RemainToShoot=0;  //remaining time to shoot to 0
	FirstShotTime=0;
	UnpavedDist=30;
	DamageDT=0;

}
Enemy::~Enemy()
{
}

bool Enemy:: operator >=(const Enemy& e) //operator overloading
{
	return true;
}

void Enemy:: setID(double i) //set the id of the enemy (sequence number)
{
	ID=i;
}
double Enemy:: getID()const // return the id of enemy
{
	return ID;
}

void Enemy:: sethealth(double i)//set the health ofenemy
{
	if(i<=0)
	{
		Health=0;
	}
	else
	{
		Health=i;
	}
}
double Enemy:: gethealth()const  // return the health of enemy
{
	return Health;
}

void Enemy:: setype(double x)  //set the type  of enemy
{
	Type= x;
}
double Enemy:: getype()const  // return the type  of enemy
{
	return Type;
}

void Enemy:: setfire(double x) //set the FirePower ofenemy
{
	FirePow=x;
}

double Enemy:: getfire()const  // return the FirePower  of enemy
{
	return FirePow;
}
void Enemy :: setime(double x) //set the Time ofenemy
{
	Time=x;
}

double Enemy:: getime()const   // return the Time  of enemy
{
	return Time;
}

void Enemy:: setfirstshot(double x)  //set the FirstShotTime ofenemy
{
	FirstShotTime=x;
}

void Enemy:: setkilledtime(double x)  //set the KilledTime ofenemy
{
	KilledTime=x;
}
double Enemy:: getkilledtime()
{
	return KilledTime;
}
void Enemy:: setremainshoot(double x)  //set the RemainToShoot ofenemy
{
	RemainToShoot=x;
}

double Enemy:: getremainshoot()const   // return the RemainToShoot of enemy
{
	return RemainToShoot;
}
double  Enemy::getkilledtime ()const
{
	return KilledTime;
}
void Enemy::setunpaved(int x)
{
	UnpavedDist=x;
}

int Enemy::getunpaved()const
{
	return UnpavedDist;
}

double Enemy::getdamage()const
{
	return DamageDT;
}

double Enemy:: getKD()const   
{
	return(KilledTime-FirstShotTime);
}

double Enemy:: getFD()const   
{
	return(FirstShotTime-Time);
}

double Enemy:: getLT()const   
{
	return(KilledTime-Time);
}

void Enemy:: setRLD(double x)    // return the reload time  of enemy
{
	RLD=x;
}

double Enemy :: getRLD()const   // return the reload time  of enemy
{
	return RLD;
}

color Enemy::GetColor() const   // return the color  of enemy
{
	return Clr;
}

void Enemy:: setregion(char r) // set the region of the enemy
{
	switch (r)
	{
	case ('A'):Region=A_REG;
		break;
	case ('B'):Region=B_REG;
		break;
	case ('C'):Region=C_REG;
		break;
	case ('D'):Region=D_REG;
		break;
	}
}
REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist() // decrement the distance between the enemy and its tower
{
	if (Distance > MinDistance) 
		Distance--;
	else
	{
		Distance=MinDistance;
	}
}

void Enemy::DecrementUnpaved() 
{
	if (UnpavedDist > MinDistance) 
		UnpavedDist--;
	else
	{
		UnpavedDist=MinDistance;
	}
}
void Enemy::SetDistance(int d) //set the Horizontal distance between enemy & the tower of its region
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}
double Enemy::getfirstshot ()
{
	return FirstShotTime;
}

int Enemy::GetDistance() const //get the Horizontal distance between enemy & the tower of its region
{
	return Distance;
}
void Enemy::setRegNum(int r)
{
	if(r==0)
		Region=A_REG;
	else if(r==1)
		Region=B_REG;
	else if(r==2)
		Region=C_REG;
	else
		Region=D_REG;
}
int Enemy::getRegNum()const
{
	if(Region==A_REG)
		return 0;
	else if(Region==B_REG)
		return 1;
	else if(Region==C_REG)
		return 2;
	else
		return 3;
}