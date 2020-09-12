#pragma once
#include"Enemy.h"
class paver:public Enemy
{
public:
	paver(void);
	virtual void Move() ;	    //All enemies can move
	virtual void Attack() ;	//All enemies can attack (attacking is paving or shooting)
	virtual bool operator >=(const Enemy& e);
	virtual void isattacked (double);
	~paver(void);
};

