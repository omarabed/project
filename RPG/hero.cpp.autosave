#include <hero.h>




//PRIVATE##########################################################################################
//-------------------------------------------------------------------------------------------------
void Hero::calculateAttributes()
{
    m_dam = m_baseDam + (m_str * m_damMult);
    m_magicDam = m_baseMagicDam + (m_intel * m_magicDamMult);
    m_health = m_baseHealth + (m_vit * m_healthMult);
    m_mana = m_baseMana + (m_intel * m_manaMult);
    m_armor = (m_def * m_armorMult);
    m_dodge = (m_agil * m_dodgeMult);

    cout << "your attributes are:" << endl
         << "\tDamage: " << m_dam << endl
         << "\tMagic Damage: " << m_magicDam << endl
         << "\tHealth: " << m_health << endl
         << "\tMana: " << m_mana << endl
         << "\tArmor: " << m_armor << endl
         << "\tDodge: " << m_dodge << endl << endl;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::assignStats(int statPoints)
{
    m_statPoints = statPoints;
    string input = "";
    int temp = 0;


    while(m_statPoints > 0)
    {
        cout << "You have been granted " << m_statPoints << " stat points use them wisely:" << endl
             << "\tStrength increases Damage by " << m_damMult << " per point." << endl
             << "\tIntelligence increases Magic Damage by " << m_magicDamMult << " per point." << endl
             << "\tIntelligence increases Mana by " << m_manaMult << " per point." << endl
             << "\tVitality increases Health by " << m_healthMult << " per point." << endl
             << "\tDefense increases Armor by " << m_armorMult << " per point." << endl
             << "\tAgility increases Dodge by " << m_dodgeMult << " per point." << endl;

        cout << "Strength (" << m_str << "): ";
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> temp) || (temp > m_statPoints) || (temp <= -1))
            {
                cout << "Invalid value" << endl;
            }
            else
            {
                m_statPoints -= temp;
                m_str += temp;
                break;
            }
        }

        cout << "Intelligence (" << m_intel << "): ";
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> temp) || (temp > m_statPoints) || (temp <= -1))
            {
                cout << "Invalid value" << endl;
            }
            else
            {
                m_statPoints -= temp;
                m_intel += temp;
                break;
            }
        }

        cout << "Vitality (" << m_vit << "): ";
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> temp) || (temp > m_statPoints) || (temp <= -1))
            {
                cout << "Invalid value" << endl;
            }
            else
            {
                m_statPoints -= temp;
                m_vit += temp;
                break;
            }
        }

        cout << "Defense (" << m_def << "): ";
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> temp) || (temp > m_statPoints) || (temp <= -1))
            {
                cout << "Invalid value" << endl;
            }
            else
            {
                m_statPoints -= temp;
                m_def += temp;
                break;
            }
        }

        cout << "Agility (" << m_agil << "): ";
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> temp) || (temp > m_statPoints) || (temp <= -1))
            {
                cout << "Invalid value" << endl;
            }
            else
            {
                m_statPoints -= temp;
                m_agil += temp;
                break;
            }
        }
    }
    cout << endl;
    calculateAttributes();
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::levelUp()
{
    m_lvl++;
    cout << "DING Level " << m_lvl << "!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    m_nextLvlExp = m_lvl * (10 + m_lvl);
    assignStats(10);
}
//-------------------------------------------------------------------------------------------------

//#################################################################################################


//PUBLIC###########################################################################################
//-------------------------------------------------------------------------------------------------
Hero::Hero()
{
    string input = "";
    m_str = 0;
    m_intel = 0;
    m_vit = 0;
    m_def = 0;
    m_agil = 0;
    m_baseDam = 1;
    m_baseMagicDam = 1.2;
    m_baseHealth = 10;
    m_baseMana = 2;

    //set name
    cout << "What is your name hero?" << endl;
    getline(cin, m_name);
    cout << "You shall hence forth be known as " << m_name << endl << endl;

    cout << "Choose your class hero:" << endl
         << "(0) Warrior:" << endl
         << "\tStrength and Defense based." << endl << endl
         << "(1) Mage:" << endl
         << "\tIntelligence and Vitality based." << endl << endl
         << "(2) Rogue:" << endl
         << "\tStrength and Agility based." << endl << endl;
    //set class
    while(true)
    {
        getline(cin, input);
        stringstream ss1(input);

        if(!(ss1 >> m_class) || (m_class >= 3) || (m_class <= -1))
        {
            cout << "Invalid choice, please select 0, 1, or 2." << endl;
        }
        else
        {
            break;
        }
    }

    //set attribute multipliers for each class
    switch(m_class)
    {
    case 0: //Warrior
        cout << "You have chosen 'Warrior'." << endl << endl;
        m_damMult = 1.2;
        m_magicDamMult = 0.8;
        m_healthMult = 1.2;
        m_manaMult = 0.8;
        m_armorMult = 1.2;
        m_dodgeMult = 0.8;
        break;
    case 1: //Mage
        cout << "You have chosen 'Mage'." << endl << endl;
        m_damMult = 0.8;
        m_magicDamMult = 1.2;
        m_healthMult = 1.2;
        m_manaMult = 1.2;
        m_armorMult = 0.8;
        m_dodgeMult = 0.8;
        break;
    case 2: //Rogue
        cout << "You have chosen 'Rogue'." << endl << endl;
        m_damMult = 1.2;
        m_magicDamMult = 0.8;
        m_healthMult = 1.2;
        m_manaMult = 0.8;
        m_armorMult = 0.8;
        m_dodgeMult = 1.2;
        break;
    }
    assignStats(10);
    cout << "You are now prepared to enter the Tower " << m_name << "." << endl;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
Hero::~Hero()
{

}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
bool Hero::fight(Enemy* enemy)
{
    cout << "Encounter!!!" << endl
         << "A " << enemy->getName() << " has appeared!" << endl;

    bool enemyDead = false;
    bool characterDead = false;

    while(!enemyDead && !characterDead)
    {

    }

    if(characterDead)
    {

    }

    return true;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::save(int towerLvl)
{

}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::load()
{

}
//-------------------------------------------------------------------------------------------------
//#################################################################################################
