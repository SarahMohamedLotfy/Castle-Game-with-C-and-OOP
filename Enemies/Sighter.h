#pragma once
#include"Enemy.h"
class Sfighter:public Enemy
{
	 static int c1,c2,c3;
public:
	Sfighter(void);
	static void setconst(int ,int,int);
	static int getconst1();
	static int getconst2();
	static int getconst3();
	virtual void isattacked (double);
	virtual void Move() ;	    //All enemies can move
	virtual void Attack() ;
	virtual bool operator >=(const Enemy& e);
	~Sfighter(void);
};
