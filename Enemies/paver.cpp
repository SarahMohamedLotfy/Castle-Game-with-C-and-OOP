#include "paver.h"


paver::paver(void)
{
	Clr=DARKBLUE;
}

bool paver:: operator >=(const Enemy& e)
{
	if(Health==0)
	{
		return(getFD()>=e.getFD());
	}
	else
		return(Time<=e.getime());
}
void paver::Move()
{
	if(RemainToShoot!=0 && (Distance>UnpavedDist))
	{
		DecrementDist();	
	}
}

void paver::Attack()
{
	if(RemainToShoot==0)
	{
		for(int i=0;i<FirePow;i++)
		{
			if(Distance<=UnpavedDist)
			{
				DecrementUnpaved();
				DecrementDist();
			}
			else
				DecrementDist();
		}
		RemainToShoot=RLD;
	}
	else
	{
		RemainToShoot--;
	}
	
}

void paver:: isattacked (double TP)
{
	double DE;
	DE= (TP/Distance);
	sethealth(Health-DE);
}
paver::~paver(void)
{
}
