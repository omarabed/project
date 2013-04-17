#include <iostream>
#include <string>
#include <stdio>
#include <stdlib>
#include <time>

#include "enemy.h"
#include "Random_Number_Generator.h"
using namespace std;

Enemy::Enemy(int elvl)
{
	int pre_num;
	int spc = rangeRand(0,20);
	int typ = rangeRand(0,21);

	srand( time(null) );
	lvl = elvl;
	health = 5 + ( lvl * 5 );
	maxHealth = health;

	dam = elvl * 1.1;
	armor = elvl * 0.35;
	exp = elvl;
	agil = elvl * 0.5;

	pre_num = setPreNameNum(elvl);
	setTypeSpec( typ );
	setSpcSpec( spc );
	setAttack( typ );
	
	setName( spc, pre_num, typ );
}

void Enemy::setName( int spc, int pre_num, int typ );
{
	string pre[] = {"small ", "lesser ", "baby ", "", "Adult ", "Large ", "Ancient ", "Massive ", "Greater "};

	string spec[] = {"Berserk ", "Armored ", "Experienced ", "", "", "", "", "",
		"", "", "", "", "", "", "", "", "", "", "", "", ""};

	string type[] = {"Boar", "Boar", "Boar", "Boar", "Tiger", "Tiger", "Tiger",
            "Imp", "Imp", "Imp", "Imp", "Imp", "Bison", "Bison", "Bison", "Bison",
            "Troll", "Troll", "Troll", "Dragon", "Dragon", "Bunny"};	

	name = spec[spc] + pre[pre_num] + type[typ];
}

int Enemy::setPreNameNum( int elvl )
{
	int preName;

	if( elvl < 3 )
	{
		preName = rangeRand(0, 2);
	}
	else if( elvl < 5 )
	{
		preName = rangeRand(3, 5);
	}
	else
	{
		preName = rangeRand(6, 8);
	}

	return preName;
}

void Enemy::setTypeSpec(int typ)
{
	if( typ <= 3 ) 			// boar
	{
		armor *= 1.05;
            	dam *= 1.05;
            	sDam = dam * 1.2;
            	health *= 1.0;
            	agil *= 1.05;
        } 
	else if( typ <= 6) 		// tiger
	{
		dam *= 1.1;
                sDam = dam * 1.2;
                health *= 1.05;
        	agil *= 1.1;
        }
	else if( typ <= 11 )		// imp
	{
		armor *= 0.9;
		dam *= 1.2;
		health *= .9;
		sDam = dam * 1.2;
		agil *= 1.0;
	}
	else if( typ <= 15 )		// bison
	{
		armor *= 1.2;
		dam *= 1.05;
		sDam = dam * 1.2;
		health *= 1.1;
		agil *= 0.8;
	}
	else if( typ <= 18 )		// troll
	{
		armor *= 1.1;
		dam *= 1.1;
		sDam = dam * 1.2;
		health *= 1.0;
		agil *= 1.1;
	}
	else if( typ <= 20 )		// dragon
	{
		armor *= 1.3;
		dam *= 1.3;
		sDam = dam * 1.2;
		health *= 1.3;
		agil *= 1.0;
	}
	else				// bunny
	{
		armor *= 0.5;
		dam *= 2;
		sDam = dam * 1.2;
		health *= 0.8;
		agil *= 1.5;
	}
}

void Enemy::setSpcSpec( int spc )
{
	if( spc == 0 )
        {
		armor *= 0.25;
		dam *= 2;
		sDam *= 0.5;
		health *= .4;
		agil *= .5;
        } 
	else if( spc == 1 )
	{
		armor *= 1.75;
		dam *= 0.5;
		sDam *= 0.5;
		health *= 1.1;
		agil *= .5;
        }
	else if( spc == 2 )
	{
		armor *= 1.25;
		dam *= 1.25;
		sDam *= 1.25;
		health *= 1.25;
		agil *= 1.25;
        }
}

void Enemy::setAttack( int typ )
{
	string attackName[] = {"Charge ", "Charge ", "Charge ", "Charge ", "Claw Strike ", "Claw Strike ", "Claw Strike ",
            "Backstab ", "Backstab ", "Backstab ", "Backstab ", "Backstab ",
            "Headbutt ", "Headbutt ", "Headbutt ", "Headbutt ", "Smash ", "Smash ", "Smash ",
            "Bite", "Bite", "NeckBite"};

        string sAttackName[] = {"Gore ", "Gore ", "Gore ", "Gore ", "Maul ", "Maul ", "Maul ",
            "Fireball ", "Fireball ", "Fireball ", "Fireball ", "Fireball ",
            "Bison Warp ", "Bison Warp ", "Bison Warp ", "Bison Warp ", "Voodoo ", "Voodoo ", "Voodoo ",
            "Firebreath ", "Firebreath ", "DEATH BEAM!!! "};

	attack = attackName[typ];
	sAttack = sAttackName[typ];
}

string Enemy::getAttack()
{
	return attack;
}

string Enemy::getSAttack()
{
	return sAttack;
}

string Enemy::getName()
{
	return name;
}

double Enemy::getHealth()
{
	return health;
}

double Enemy::getAgil()
{
	return agil;
}

double Enemy::getDam()
{
	return dam;
}

double Enemy::getSDam()
{
	return sDam;
}

double Enemy::getArmor()
{
	return armor;
}

double Enemy::getExp()
{
	return exp;
}

void Enemy::restore()
{
	health = maxHealth;
}
