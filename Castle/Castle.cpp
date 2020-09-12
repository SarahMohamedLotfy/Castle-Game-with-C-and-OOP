#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowersHealth(double h)// function to set the health of enemies for each region(tower) of the castle
{
	for (int i = 0; i < NoOfRegions; i++)  //loop on the regions of the castle
	{
		Towers[i].SetHealth(h);
	}
}

double Castle ::GetTowershealth(int index)//function to get that health of the enemy of atower we sent its index to the function 
{	
		return Towers[index].GetHealth();	
}

double Castle ::GetTowersdamage(int index)
{
	return Towers[index].gettotdamaged();
}

int Castle ::getunpaved(int index)
{
	return Towers[index].getunpave();
}



void Castle::SetTowersPower(double p)// function to set the power  each region(tower) of the castle
{
	for (int i = 0; i < NoOfRegions; i++)//loop on the regions of the castle
	{
		Towers[i].setfire(p);
	}
}
double Castle ::GetTowerspower(int index)//function to get the power atower we sent its index to the function 
{
	
		return Towers[index].getfire();
	
}


void Castle::SetTowersMaxNum(double m)  // function to set the maximum number of enemies for each region(tower) of the castle
{
	for (int i = 0; i < NoOfRegions; i++)//loop on the regions of the castle
	{
		Towers[i].setmax(m);
	}
}
double Castle ::GetTowersmaximum(int index)//function to get te maximum number of  enemies of atower we sent its index to the function 
{
	
		return Towers[index].getmax();
	
}
void Castle::setenemy(Enemy*e) // add the enemy to its region 
{
	switch (e->GetRegion())
	{
	case A_REG: // if the enemie's region is A
		Towers[0].addenemy(e);
		break;
	case B_REG:  // if the enemie's region is B
		Towers[1].addenemy(e);
		break;
	case C_REG:    // if the enemie's region is C
		Towers[2].addenemy(e);
		break;
	case D_REG:   // if the enemie's region is D
		Towers[3].addenemy(e);
		break;
	}
}
void Castle::killenemy(Enemy*e) // add the KILLED enemy to its region
{
	switch (e->GetRegion())
	{
	case A_REG:  // if the killed enemie's region is A
		Towers[0].addkilled(e);
		break;
	case B_REG:  // if the killed enemie's region is B
		Towers[1].addkilled(e);
		break;
	case C_REG:   // if the killed enemie's region is C
		Towers[2].addkilled(e);
		break;
	case D_REG :   // if the killed enemie's region is D
		Towers[3].addkilled(e);
		break;
	}
}
void Castle::decrement() //decrement the distance between enemies and their towers
{
	for (int i = 0; i < 4; i++) //loop on the towers of the castle 
	{
		Towers[i].decrement();
	}
}
void Castle::deletekilled()  //delete the killed enemies of the towers in the castle 
{
	for (int i = 0; i < 4; i++)//loop on the towers of the castle 
	{
		Towers[i].deletekilled();
	}
}

void Castle::deletefighter()//delete the fighter enemies of the towers in the castle 
{
	for (int i = 0; i < 4; i++)//loop on the towers of the castle 
	{
		Towers[i].deletefighter();
	}
}

void Castle::deletesfighter() //delete the shielded fighter enemies of the towers in the castle 
{
	for (int i = 0; i < 4; i++)//loop on the towers of the castle 
	{
		Towers[i].deletesfighter();
	}
}
bool Castle::IsDestroyed(int x)
{
	return(Towers[x].destroyed());
}

int Castle::getscountenemy(int index )  // get the count of the shielded fighters in the towers of castle
{
	return (Towers[index].getScount());
}
int Castle::getfcountenemy(int index ) // get the count of the fighters enemies in the towers of castle

{
	return (Towers[index].getFcount());
}
int Castle::getkcountenemy(int index ) // get the count of the killed enemies in the towers of castle

{
	return (Towers[index].getKcount());
}

int Castle::gettotkillenemy(int index)
{
	return(Towers[index].gettotalkilled());
}
 LinkedList<Enemy>& Castle::getSF(int index) // return the shielded linkedlist of the shielded fighter in the towers of the castle 
{
	return (Towers[index].getshieldedf());
}
			
LinkedList<Enemy> &Castle::getF(int index) // return the fighter enemies linkedlist of the fighter in the towero the castle 
{
	return (Towers[index].getfighter());
}
LinkedList<Enemy>& Castle::getkilled(int index) // return the killed linkedlist of the killed in the tower of the castle
{
	return (Towers[index].getkilled());
}

void Castle::move() 
{
	for (int i = 0; i < 4; i++) //loop on the towers of the castle 
	{
		Towers[i].MoveEnemy();
	}
}

void Castle::attacktower() 
{
	for (int i = 0; i < 4; i++) //loop on the towers of the castle 
	{
		Towers[i].AttackTower();
	}
}
void Castle::attackenemis(int timestep)
{
	for (int i = 0; i < 4; i++)
	{
		Towers[i].attackenemies(timestep);
	}
}
void Castle::checkkilled(int timestep)
{
	for (int i = 0; i < 4; i++)
	{
		Towers[i].checkilled(timestep);
	}
}

void Castle::ShiftTowers()
{
	for(int i=0;i<3;i++)
	{
		if(Towers[i].GetHealth()==0&&((Towers[i].getFcount())+(Towers[i].getScount())!=0))
		{
			
			Towers[i].SetNewReg(i+1);
			Towers[i+1].ShiftEnemies(Towers[i]);
			
			
		}
	}
	if(Towers[3].GetHealth()==0&&((Towers[3].getFcount())+(Towers[3].getScount())!=0))
	{
		if(Towers[0].GetHealth()!=0)
		{
			
			Towers[3].SetNewReg(0);
			Towers[0].ShiftEnemies(Towers[3]);
			
			
		}
		else if(Towers[1].GetHealth()!=0)
		{
			
			Towers[3].SetNewReg(1);
			Towers[1].ShiftEnemies(Towers[3]);
			
			
		}
		else
		{
			
			Towers[3].SetNewReg(2);
			Towers[2].ShiftEnemies(Towers[3]);
			
		}

	}
}