#ifndef HERO_H
#define HERO_H

#include <string>
#include <enemy.h>
#include <iostream>
#include <sstream>

using namespace std;

class Hero
{
private:
    string m_name;
    int m_lvl;
    int m_exp;
    int m_nextLvlExp;
    int m_statPoints;
    int m_class; //0 = warrior, 1 = Mage, 2 = rogue

    //hero's stats
    int m_str;
    int m_intel;
    int m_vit;
    int m_def;
    int m_agil;

    //hero's stats multiplier (for balancing)
    double m_damMult;
    double m_magicDamMult;
    double m_healthMult;
    double m_manaMult;
    double m_armorMult;
    double m_dodgeMult;

    //base starting attributes
    double m_baseDam;
    double m_baseMagicDam;
    double m_baseHealth;
    double m_baseMana;

    //hero's attributes based on stat * stat Multiplier
    double m_dam;
    double m_magicDam;
    double m_health;
    double m_mana;
    double m_armor;
    double m_dodge;

    //calculates all the hero's attribues
    void calculateAttributes();

    //assign statPoints
    void assignStats(int statPoints);

    //level up
    void levelUp();

public:
    //constructor
    Hero();

    //destructor
    ~Hero();

    //fight enemy, returns true if you win false if you lose.
    bool fight(Enemy *enemy);

    //save hero/level
    void save(int towerLvl);

    //load hero/level
    void load();

};


#endif // HERO_H