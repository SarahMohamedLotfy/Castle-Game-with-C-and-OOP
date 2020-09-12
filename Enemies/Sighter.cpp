#include "Sighter.h"


Sfighter::Sfighter(void)
{
	Clr=ORANGERED;
}


int Sfighter::c1;
int Sfighter::c2;
int Sfighter::c3;
 void Sfighter::setconst(int i,int j,int k)
{
	c1=i;
	c2=j;
	c3=k;
}
int Sfighter::getconst1()
{
	return c1;
}
int Sfighter::getconst2()
{
	return c2;
}
int Sfighter::getconst3()
{
	return c3;
}
void Sfighter:: isattacked (double TP)
{
	double DE;
	DE= (TP/(2*Distance));
	sethealth(Health-DE);
}
void Sfighter::Move()
{
	if(Distance>UnpavedDist)
		DecrementDist();
}

void Sfighter::Attack()
{
	if(RemainToShoot==0)
	{
		DamageDT=(2.0/float(Distance))*FirePow;
		RemainToShoot=RLD;
	}
	else
		RemainToShoot--;
}
Sfighter::~Sfighter(void)
{
}
bool Sfighter:: operator >=(const Enemy& e)
{
	if(Health==0)
	{
		return(getFD()>=e.getFD());
	}
	else
	{

		double a=((getfire()/GetDistance())*c1)+(c2/(getRLD()+1))+(gethealth()*c3);
		double b=((e.getfire()/e.GetDistance())*c1)+(c2/(e.getRLD()+1))+(e.gethealth()*c3);
		return (a>=b);
	}
}
