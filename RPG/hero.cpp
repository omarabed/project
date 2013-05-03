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

    m_maxHealth = m_health;
    m_maxMana = m_mana;

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
void Hero::addItemAttributes(Item item)
{
    m_baseDam += item.getDamage();
    m_baseMagicDam += item.getMagicDamage();
    m_baseHealth += item.getHealth();
    m_baseMana += item.getMana();
    m_baseArmor += item.getArmor();
    m_baseDodge += item.getDodge();

    m_maxHealth += item.getHealth();
    m_maxMana += item.getMana();

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
void Hero::removeItemAttributes(Item item)
{
    m_baseDam -= item.getDamage();
    m_baseMagicDam -= item.getMagicDamage();
    m_baseHealth -= item.getHealth();
    m_baseMana -= item.getMana();
    m_baseArmor -= item.getArmor();
    m_baseDodge -= item.getDodge();

    m_maxHealth -= item.getHealth();
    m_maxMana -= item.getMana();
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


//-------------------------------------------------------------------------------------------------
bool Hero::run(int enemyLvl)
{
    int rand = rangeRand(1,100);

    int topOfRange = 50 + (10 * (enemyLvl - m_lvl));

    if(rand <= topOfRange)
    {
        cout << "Failed to run away!" << endl << endl;
        return false;
    }
    else
    {
        cout << "Successfully ran away!" << endl << endl;
        return true;
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
bool Hero::attack(Enemy *enemy)
{
    cout << m_name << " attacks with " << m_attackName << endl;
    enemy->attacked(m_dam);

    if(enemy->getHealth() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
bool Hero::magicAttack(Enemy *enemy)
{

    if(m_mana >= 1)
    {
        cout << m_name << " attacks with " << m_magicAttackName << endl;
        enemy->attacked(m_magicDam);
        m_mana -= 1;

        if(enemy->getHealth() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        cout << "Not enough mana!" << endl << endl;
        return false;
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::useItem()
{
    string input = "";
    int choice;

    //print out all items
    cout << "(-1) Do not use an item." << endl << endl;
    for(int i = 0; i < 10; i++)
    {
        if((m_inventory[i].getType() == 0) || (m_inventory[i].getType() == 1))
        {
            cout << "(" << i << ")" << endl;
            m_inventory[i].view();
        }
    }

    //get input
    while(true)
    {
        getline(cin, input);
        stringstream ss1(input);

        if(!(ss1 >> choice) || (choice >= 10) || (m_class <= -2))
        {
            cout << "Invalid choice, please select -1,0,1,2,3,4,5,6,7,8, or 9" << endl;
        }
        else
            if(choice == -1)
            {
                cout << "Did not use an item. Lose a turn." << endl << endl;
                break;
            }
            else
                if((m_inventory[choice].getType() != 0) && (m_inventory[choice].getType() != 1))
                {
                    cout << "Cannot use that item." << endl << endl;
                }
                else
                {
                    cout << "Used item:" << endl;

                    if(m_inventory[choice].getType() == 0)
                    {
                        cout << "Health Potion" << endl;

                        m_health += (m_maxHealth / 2);
                        if(m_health > m_maxHealth)
                        {
                            m_health = m_maxHealth;
                        }

                        cout << "Health is now " << m_health << "/" << m_maxHealth << endl << endl;
                    }
                    else
                        if(m_inventory[choice].getType() == 1)
                        {
                            cout << "Mana Potion" << endl;

                            m_mana += (m_maxMana / 2);
                            if(m_mana > m_maxMana)
                            {
                                m_mana = m_maxMana;
                            }

                            cout << "Mana is now " << m_mana << "/" << m_maxMana << endl << endl;
                        }

                    Item tempItem(true);
                    m_inventory[choice] = tempItem;
                    break;
                }

    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::pickUpLoot(int lvl)
{
    Item item(lvl);
    int choice;
    string input = "";

    cout << "While looting the corpse you find: " << endl;
    item.view();

    cout << "Do you want to:" << endl
         << " (0) leave the item" << endl
         << " (1) pick up the item" << endl
         << " (2) equip the item" << endl;

        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> choice) || (choice >= 3) || (choice <= -1))
            {
                cout << "Invalid choice, please select 0, 1, 2, or 3." << endl;
            }
            else
            {
                if(((item.getType() == 0) || (item.getType() == 1)) && (choice == 2))//the item is a potion
                {
                    cout << "Cannot equip a potion." << endl;
                }
                else
                    {
                        break;
                    }
            }
        }

        switch(choice)
        {
        case 0:
            cout << "You left the item." << endl << endl;
            break;
        case 1:
            addItem(item);
            break;
        case 2:
            equipItem(item);
            break;
        }

}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::displayEquipped()
{
    for(int i = 0; i < 5; i++)
    {
        if (m_equipped[i].getType() != -1)
        {
            m_equipped[i].view();
        }
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::equipItem(Item item)
{
    bool isTaken = false;
    Item tempItem;

    for(int i = 0; i < 5; i++)
    {
        if(m_equipped[i].getType() == item.getType())
        {
            isTaken = true;
            tempItem = m_equipped[i];
        }
    }

    if(!isTaken)
    {
        for(int i = 0; i < 5; i++)
        {
            if(m_equipped[i].getType() == -1)
            {
                m_equipped[i] = item;
                cout << "Equipped:" << endl;
                item.view();

                addItemAttributes(item);

                break;
            }
        }
    }
    else
    {
        cout << "You must unequip your current item." << endl;

        addItem(tempItem);

        for(int i = 0; i < 5; i++)
        {
            if(m_equipped[i].getType() == item.getType())
            {
                removeItemAttributes(tempItem);
                m_equipped[i] = item;
                cout << "Equipped:" << endl;
                item.view();
            }
        }
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::displayInventory()
{
    for(int i = 0; i < 10; i++)
    {
        if (m_inventory[i].getType() != -1)
        {
            m_inventory[i].view();
        }
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::addItem(Item item)
{
    if(InventoryFull())
    {
        cout << "Inventory full! Drop an item." << endl;

        dropItem();
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if(m_inventory[i].getType() == -1)
            {
                cout << "Added to inventory: " << endl;
                item.view();
                m_inventory[i] = item;
                break;
            }
        }
    }
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
bool Hero::InventoryFull()
{
    for(int i = 0; i < 10; i++)
    {
        if(m_inventory[i].getType() == -1)
        {
            return false;
        }
    }
    return true;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Hero::dropItem()
{
    string input = "";
    int choice;

    //print out all items
    cout << "(-1) Do not drop an item." << endl << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "(" << i << ")" << endl;
        m_inventory[i].view();
    }

    //get input
    while(true)
    {
        getline(cin, input);
        stringstream ss1(input);

        if(!(ss1 >> choice) || (choice >= 10) || (m_class <= -2))
        {
            cout << "Invalid choice, please select -1,0,1,2,3,4,5,6,7,8, or 9" << endl;
        }
        else
        {
            if(choice == -1)
            {
                cout << "Did not drop an item." << endl << endl;
            }
            else
            {
                cout << "dropped item:" << endl;
                m_inventory[choice].view();

                Item tempItem(true);
                m_inventory[choice] = tempItem;
            }
            break;
        }
    }
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
    m_lvl = 1;
    m_exp = 0;
    m_nextLvlExp = 3;

    //initialize inventory
    for(int i = 0; i < 10; i++)
    {
        Item tempItem(true);
        m_inventory[i] = tempItem;
    }

    //set name
    cout << "Enter Name: ";
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
        m_armorMult = 0.4;
        m_dodgeMult = 0.8;
        m_attackName = "Heroic Strike";
        m_magicAttackName = "Heavenly Strike";
        break;
    case 1: //Mage
        cout << "You have chosen 'Mage'." << endl << endl;
        m_damMult = 0.8;
        m_magicDamMult = 1.2;
        m_healthMult = 1.2;
        m_manaMult = 1.2;
        m_armorMult = 0.2;
        m_dodgeMult = 0.8;
        m_attackName = "Magic Missile";
        m_magicAttackName = "Meteor";
        break;
    case 2: //Rogue
        cout << "You have chosen 'Rogue'." << endl << endl;
        m_damMult = 1.2;
        m_magicDamMult = 0.8;
        m_healthMult = 1.2;
        m_manaMult = 0.8;
        m_armorMult = 0.2;
        m_dodgeMult = 1.2;
        m_attackName = "Sinister Strike";
        m_magicAttackName = "Back Stab";
        break;
    }
    assignStats(10);
    //cout << "You are now prepared to enter the Tower " << m_name << "." << endl  << endl;
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
    int damageTaken;
    int select;
    string input;
    bool enemyDead = false;
    bool characterDead = false;
    bool ranAway = false;
    bool enemyRan = false;

    cout << "Encounter!!!" << endl
         << "A " << enemy->getName() << " has appeared!" << endl;

    if(m_health <= 0)
    {
        characterDead = true;
    }
    while(!enemyDead && !characterDead && !ranAway && !enemyRan)
    {
        cout << "Current Health: " << m_health << "/" << m_maxHealth << endl
             << "Current Mana: " << m_mana << "/" << m_maxMana << endl
             << "\t(0) Run" << endl
             << "\t(1) Attack" << endl
             << "\t(2) Magic Attack" << endl
             << "\t(3) Use Item" << endl;

        //get input
        while(true)
        {
            getline(cin, input);
            stringstream ss1(input);

            if(!(ss1 >> select) || (select >= 4) || (select <= -1))
            {
                cout << "Invalid choice, please select 0, 1, 2, or 3." << endl;
            }
            else
            {
                break;
            }
        }


        switch(select)
        {
        case 0: //Run
            ranAway = run(enemy->getLvl());
            break;
        case 1: // Attack
            enemyDead = attack(enemy);
            break;
        case 2: //Magic Attack
            enemyDead = magicAttack(enemy);
            break;
        case 3: //Use Item
            useItem();
            break;
        }

        if(enemy->getHealth() <= 0)
        {
            enemyDead = true;
            break;
        }
        if(ranAway)
        {
            break;
        }


        //enemy's turn
        damageTaken = enemy->attackHero();

        if(damageTaken == 0)
        {
            //enemy healed, do nothing
        }
        else
            if(damageTaken == -1)
            {
                //enemy ran away
                enemyRan = true;
            }
            else
            {
                damageTaken -= m_armor;
                if(damageTaken <= 0.001)
                {
                    cout << m_name << " is hit! It is not very effective" << endl;
                    cout << m_name << " still has " << m_health << " health." << endl << endl;
                }
                else
                {
                    m_health -= damageTaken;

                    if(m_health <= 0)
                    {
                        m_health = 0;
                    }

                    cout << m_name << " is hit and takes " << damageTaken << " damage!" << endl;
                    cout << m_name << " now has " << m_health << " health." << endl << endl;
                }
            }
        if(m_health <= 0)
        {
            characterDead = true;
        }
    }



    if(characterDead)
    {
        cout << "GAME OVER!" << endl << endl;
        return false;
    }
    else
        if(enemyDead)
        {
            cout << "Danana na na nanana!" << endl << endl;

            //drop item
            int rand = rangeRand(1,100);
            if(rand <= 50)
            {
                pickUpLoot(enemy->getLvl());
            }

            //deal with experience
            m_exp += enemy->getExp();
            cout << "Gained " << enemy->getExp() << " experience!" << endl;
            cout <<  "Current Experience: " << m_exp << "/" << m_nextLvlExp << endl << endl;
            if(m_exp >= m_nextLvlExp)
            {
                levelUp();
            }
            return true;
        }

    return true;
}

//-------------------------------------------------------------------------------------------------
int Hero::getHealth()
{
    return m_health;
}
//-------------------------------------------------------------------------------------------------

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
