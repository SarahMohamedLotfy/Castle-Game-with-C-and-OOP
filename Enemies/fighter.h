#pragma once
#include"Enemy.h"
class fighter:public Enemy
{
public:
	fighter(void);
	virtual void Move() ;	    //All enemies can move
	virtual void Attack() ;	//All enemies can attack (attacking is paving or shooting)
	virtual void isattacked (double);
	virtual bool operator >=(const Enemy& e);
	~fighter(void);
};

