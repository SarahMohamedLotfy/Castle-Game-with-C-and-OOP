#include "fighter.h"


fighter::fighter(void)
{
	Clr=DARKOLIVEGREEN;
}
bool fighter:: operator >=(const Enemy& e)
{
	if(Health==0)
	{
		return(getFD()>=e.getFD());
	}
	else
		return(Time<=e.getime());
}


void fighter:: Move()
{
	if(Distance>UnpavedDist)
	{
		DecrementDist();
	}

}

void fighter::Attack()
{
	if(RemainToShoot==0)
	{

		DamageDT=(1/Distance)*FirePow;
		RemainToShoot=RLD;
	}
	else
	{
		RemainToShoot--;
	}

}
void fighter:: isattacked (double TP)
{
	double DE;
	DE= (TP/Distance);
	sethealth(Health-DE);
}
fighter::~fighter(void)
{
}