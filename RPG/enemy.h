#include <iostream>
#include <string>

using namespace std;

class Enemy
{
private:
	int level;

	double health;
	double maxHealth;

	double agil;		// agility
	double dam;		// Damage
	double sDam;		// Special Damage
	double armor;		// Armor
	double exp;		// Experience

	string name;
    string m_attack;
	string sAttack;
public:

int getLvl();

string getName();

Enemy(int elvl);

void setAttack();
string getAttack();

void attack();			// 
void specAtt();			// Special Attack

void restore();			// restores health
};
