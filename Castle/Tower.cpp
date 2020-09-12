#include "Tower.h"
#include <fstream>

Tower ::Tower()
{
	Scount=0;
	Fcount=0;
	Kcount=0;
	totalkilled=0;
	unpaved=30;
	TotalDam=0;
}

void Tower::SetHealth(double h)  //function to set the health of the enemy that exist in the region of the tower
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Tower::GetHealth() const//get health of the tower
{
	return Health;
}

void Tower::setfire(double f)//function to set the fire  of the tower 
{
	FirePower=f;
}

double Tower::getfire() const //get fire  of the tower
	
{
	return FirePower;
}

void Tower::setmax(double m)//function to set the maximum the number of enemies that exist in the region of the tower
{
	MaxEnemyNum=m;
}

double Tower::getmax() const//get he maximum the number of enemies of the tower
{
	return MaxEnemyNum;
}

void Tower::addenemy(Enemy*p)// to add an enemy to the region of the tower
{
	if(p->getype()==2)// if type of enemy =2
	{
		SF.append(p);// append enemy to shieldefighter 
		Scount++;//increment the number of shielded fighters 
		SF.MergeSort();
	}
	else 
	{
		F.append(p); // append enemy to fighter 
		Fcount++;  //increment the number of the fighters
	}
}

void Tower::addkilled(Enemy*e) //add the killed enemies by the tower
{
	if((e->getype())==2)
	{
		SF.deleteval(e); // delete the killed enemy
		Scount--; // decrement the number of shielded fighters
	}
	else
	{
		F.deleteval(e); // delete the killed enemy 
		Fcount--;// decrement the number of fighters
	}
	killed.append(e); // append or add the killlled enemy to the killed enemies list
	Kcount++; // increment the number of killed enemies
	totalkilled++;
}

void Tower::decrement()    // decrement the distance between the enemies and their  towers
{
	for (int i = 1; i <= Scount; i++)
	{
		(SF.getvalue(i))->DecrementDist(); // decrement the distance between the shielded enemies  and their tower
	}
	for (int i = 1; i <= Fcount; i++)
	{
		(F.getvalue(i))->DecrementDist();// decrement the distance between the fighter enemies  and their tower
	}
}
void Tower::deletekilled() // delete the all  killed enemies in the reiomn of the tower
{
	Enemy*e;
	for (int i = 1; i <= Kcount; i++)
	{
		e=killed.getvalue(i); 
		
		delete e;
	}
	killed.clearlist();  //clear or empty te list of the killed enemies in the tower
	Kcount=0;
}

void Tower::deletefighter() // delete the all  fighter enemies in the region of the tower

{
	Enemy*e;
	for (int i = 1; i <= Fcount; i++)  //loop on the number of fighter enemies
	{
		e=F.getvalue(i);
		delete e;
	}
	F.clearlist();   //clear or empty te list of the fighter enemies in the tower
	Fcount=0;
	totalkilled=0;
}

void Tower::deletesfighter()// delete the all shielded fighter enemies in the region of the tower
{
	Enemy*e;
	for (int i = 1; i <= Scount; i++)//loop on the number of shielded enemies
	{
		e=SF.getvalue(i);
		
		delete e;
	}
	SF.clearlist(); //clear or empty te list of the fighter enemies in the tower
	Scount=0;
}

void Tower::MoveEnemy()    
{
	SF.beginref();
	for (int i = 1; i <= Scount; i++)
	{
		(SF.getref())->Move();
		SF.advance();
	}
	F.beginref();
	for (int i = 1; i <= Fcount; i++)
	{
		(F.getref())->Move();
		F.advance();
	}
}

void Tower::AttackTower()    
{
	int MinUnpaved=unpaved;
	SF.beginref();
	for (int i = 1; i <= Scount; i++)
	{
		(SF.getref())->Attack();
		DecreementHealth((SF.getref())->getdamage());
		TotalDam=TotalDam+((SF.getref())->getdamage());
		SF.advance();
	}
	F.beginref();
	for (int i = 1; i <= Fcount; i++)
	{
		(F.getref())->Attack();
		DecreementHealth((F.getref())->getdamage());
		TotalDam=TotalDam+((F.getref())->getdamage());
		int unpav=F.getref()->getunpaved();
		if(MinUnpaved>unpav)
		{
			MinUnpaved=unpav;
		}
		F.advance();
	}
	unpaved=MinUnpaved;
	setUnpaved(unpaved);
}

void Tower::setUnpaved(int x)
{
	SF.beginref();
	for (int i = 1; i <= Scount; i++)
	{
		(SF.getref())->setunpaved(x);
		SF.advance();
	}
	F.beginref();
	for (int i = 1; i <= Fcount; i++)
	{
		(F.getref())->setunpaved(x);
		F.advance();
	}
}

void Tower::DecreementHealth(double x)
{
	SetHealth(Health-x);
}
bool Tower::destroyed()
{
	return(Health==0);
}
int Tower:: getScount()// get the count of the shielded fighters in the tower
{
	return  Scount;
}
int Tower:: getFcount()// get the count of the  fighters in the tower
{
	return Fcount;
}
int Tower:: getKcount()// get the count of the killed enemies in the tower
{
	return Kcount;
}

double Tower::gettotdamaged()
{
	return TotalDam;
}

int Tower::getunpave()
{
	return unpaved;
}

int Tower::gettotalkilled()
{
	return totalkilled;
}

LinkedList<Enemy>& Tower:: getshieldedf() // return the shielded linkedlist of the shielded fighter in the tower
{
	return SF;
}
LinkedList<Enemy>& Tower::getfighter()// return the shielded linkedlist of the fighters inthe tower
{
	return F;
}

LinkedList<Enemy>& Tower:: getkilled()// return the shielded linkedlist of the killed enemies in the  tower
{
	return killed;
}

void Tower::attackenemies(int timestep)
{
	int k=0;
	int i=0;
	SF.beginref();
	SF.MergeSort();
	while((i < Scount) && (k<=getmax()))
	{
		SF.getref()->isattacked(FirePower);
		if(SF.getref()->getfirstshot()==0)
		{
			SF.getref()->setfirstshot(timestep);
		}
		SF.advance();
		k++;
		i++;
	}
	i=0;
	F.beginref();
	while((i < Fcount) && (k<=getmax()))
	{
		F.getref()->isattacked(FirePower);
		if(F.getref()->getfirstshot()==0)
		{
			F.getref()->setfirstshot(timestep);
		}
		F.advance();
		k++;
		i++;
	}
}

void Tower::checkilled(int timestep)
{
	double h;
	Enemy*e;
	SF.beginref();
	for (int i = 0; i < Scount; i++)
	{
		e=NULL;
		e=SF.getref();
		h=e->gethealth();
		if(h==0)
		{
			e->setkilledtime(timestep);
			addkilled(e);
		}
		SF.advance();
	}
	F.beginref();
	for (int i = 0; i < Fcount; i++)
	{
		e=NULL;
		e=F.getref();
		h=e->gethealth();
		if(h==0)
		{
			e->setkilledtime(timestep);
			addkilled(e);
		}
		F.advance();
	}
}

void Tower::ShiftEnemies(Tower& t)
{
	Enemy* e;
	
	for(int i=1;i<=t.Fcount;i++)
	{
		e=t.F.getvalue(i);
		e->setunpaved(unpaved);
		if(e->GetDistance()<unpaved)
		{
			e->SetDistance(unpaved);
		}
		F.append(e);
		Fcount++;
	}
	for(int i=1;i<=t.Scount;i++)
	{
		e=t.SF.getvalue(i);
		e->setunpaved(unpaved);
		if(e->GetDistance()<unpaved)
			e->SetDistance(unpaved);
		SF.append(e);
		Scount++;
	}
	t.clearTower();
	F.MergeSort();
	SF.MergeSort();
}
void Tower::SetNewDis(Tower t)
{
	int x;
	for(int i=1;i<=Fcount;i++)
	{
		x=F.getvalue(i)->GetDistance();
		if(t.unpaved>x)
		{
			F.getvalue(i)->SetDistance(t.unpaved);
		}
	}
	for(int i=1;i<=Scount;i++)
	{
		x=SF.getvalue(i)->GetDistance();
		if(t.unpaved>x)
		{
			SF.getvalue(i)->SetDistance(t.unpaved);
		}
	}
}
void Tower::SetNewReg(int x)
{
	for(int i=1;i<=Fcount;i++)
	{
		F.getvalue(i)->setRegNum(x);
	}
	for(int i=1;i<=Scount;i++)
	{
		SF.getvalue(i)->setRegNum(x);
	}
}
void Tower::clearTower()
{
	SF.clearlist();
	F.clearlist();
	Scount=0;
	Fcount=0;
}
Tower::~Tower()
{
	
}
