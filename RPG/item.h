#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <Random_Number_Generator.h>

using namespace std;

class Item
{
private:
    int m_level;
    string m_name;
    short m_type; // -1=NULL, 0=healthpotion, 1=manapotion, 2=armor, 3=helm, 4=gauntlets, 5=leggings, 6=boots
    double m_armor;
    double m_health;
    double m_mana;
    double m_dodge;
    double m_damage;
    double m_magicDamage;

    const static double sm_armorMult = 0.2;
    const static double sm_healthMult = 0.3;
    const static double sm_manaMult = 0.2;
    const static double sm_dodgeMult = 0.2;
    const static double sm_damageMult = 0.4;
    const static double sm_magicDamageMult = 0.5;

    const static string sm_itemSuffix[];
    const static string sm_itemName[];

public:
    //generate a random item with Item level lvl
    Item(int lvl);

    //create your own item
    Item(int level, string name, short type, double armor, double mana, double health, double dodge, double damage, double magicDamage);

    //create a NULL item (a place-holder)
    Item(bool null);

    //default constructor does nothing
    Item();

    //view an item
    void view();

    short getType();

    double getMagicDamage();
    double getDamage();
    double getDodge();
    double getMana();
    double getHealth();
    double getArmor();

};

#endif // ITEM_H
