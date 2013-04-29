#include "item.h"

const string Item::sm_itemName[] = {"Health Potion", "Mana Potion", "Armor", "Helm", "Gauntlets", "Leggings", "Boots"};

//-------------------------------------------------------------------------------------------------
Item::Item(int lvl)
{
    m_level = lvl;

    int randType = rangeRand(1,100);
    int randSuffix = rangeRand(1,100);

    m_armor = 0;
    m_health = 0;
    m_mana = 0;
    m_dodge = 0;
    m_damage = 0;
    m_magicDamage = 0;

    if(randType <= 25)
    {
        m_name = sm_itemName[0];
        m_type = 0;
    }
    else
        if(randType <= 50)
        {
            m_name = sm_itemName[1];
            m_type = 1;
        }
        else
            if(randType <= 60)
            {
                m_name = sm_itemName[2];
                m_type = 2;
            }
            else
                if(randType <= 70)
                {
                    m_name = sm_itemName[3];
                    m_type = 3;
                }
                else
                    if(randType <= 80)
                    {
                        m_name = sm_itemName[4];
                        m_type = 4;
                    }
                    else
                        if(randType <= 90)
                        {
                            m_name = sm_itemName[5];
                            m_type = 5;
                        }
                        else
                            if(randType <= 100)
                            {
                                m_name = sm_itemName[6];
                                m_type = 6;
                            }
    if(randType > 50)
    {
        if(randSuffix <= 4) //High Heavens
        {
            m_name = m_name + " of the High Heavens";
            m_armor = m_level * sm_armorMult;
            m_health = m_level * sm_healthMult;
            m_mana = m_level * sm_manaMult;
            m_dodge = m_level * sm_dodgeMult;
            m_damage = m_level * sm_damageMult;
            m_magicDamage = m_level * sm_magicDamageMult;
        }
        else
            if(randSuffix <= 16) //Dire Wolf
            {
                m_name = m_name + " of the Dire Wolf";
                m_armor = m_level * sm_armorMult;
                m_health = m_level * sm_healthMult;
                m_damage = m_level * sm_damageMult;
            }
            else
                if(randSuffix <= 28) //Mongoose
                {
                    m_name = m_name + " of the Mongoose";
                    m_health = m_level * sm_healthMult;
                    m_dodge = m_level * sm_dodgeMult;
                    m_damage = m_level * sm_damageMult;
                }
                else
                    if(randSuffix <= 40) //Dragon
                    {
                        m_name = m_name + " of the Dragon";
                        m_armor = m_level * sm_armorMult;
                        m_mana = m_level * sm_manaMult;
                        m_magicDamage = m_level * sm_magicDamageMult;
                    }
                    else
                        if(randSuffix <= 55) //Elephant
                        {
                            m_name = m_name + " of the Elephant";
                            m_armor = m_level * sm_armorMult;
                            m_health = m_level * sm_healthMult;
                        }
                        else
                            if(randSuffix <= 70) //Crow
                            {
                                m_name = m_name + " of the Crow";
                                m_mana = m_level * sm_manaMult;
                                m_dodge = m_level * sm_dodgeMult;
                            }
                            else
                                if(randSuffix <= 85) //Viper
                                {
                                    m_name = m_name + " of the Viper";
                                    m_dodge = m_level * sm_dodgeMult;
                                    m_magicDamage = m_level * sm_magicDamageMult;
                                }
                                else
                                    if(randSuffix <= 100) //Gorilla
                                    {
                                        m_name = m_name + " of the Gorilla";
                                        m_health = m_level * sm_healthMult;
                                        m_damage = m_level * sm_damageMult;;
                                    }

    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
Item::Item(int level, string name, short type, double armor, double mana, double health, double dodge, double damage, double magicDamage)
{
    m_level = level;
    m_name = name;
    m_type = type;
    m_armor = armor;
    m_health = health;
    m_mana = mana;
    m_dodge = dodge;
    m_damage = damage;
    m_magicDamage = magicDamage;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
Item::Item(bool null)
{
    m_type = -1;
    m_level = 0;
    m_name = "NULL";
    m_armor = 0;
    m_health = 0;
    m_mana = 0;
    m_dodge = 0;
    m_damage = 0;
    m_magicDamage = 0;
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
Item::Item()
{
    m_type = -1;
    m_level = 0;
    m_name = "NULL";
    m_armor = 0;
    m_health = 0;
    m_mana = 0;
    m_dodge = 0;
    m_damage = 0;
    m_magicDamage = 0;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Item::view()
{
    if((m_type != -1) && (m_type != 0) && (m_type != 1))
    {
        cout << "\t" << m_name << endl
             << "Armor: " << m_armor << endl
             << "Health: " << m_health << endl
             << "Mana: " << m_mana << endl
             << "Dodge: " << m_dodge << endl
             << "Damage: " << m_damage << endl
             << "Magic Damage: " << m_magicDamage << endl << endl;
    }
    else
        if(m_type != -1)
        {
            cout << "\t" << m_name << endl << endl;
        }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
short Item::getType()
{
    return m_type;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getArmor()
{
    return m_armor;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getHealth()
{
    return m_health;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getMana()
{
    return m_mana;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getDodge()
{
    return m_dodge;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getDamage()
{
    return m_damage;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
double Item::getMagicDamage()
{
    return m_magicDamage;
}
//-------------------------------------------------------------------------------------------------
