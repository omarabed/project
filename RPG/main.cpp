#include "hero.h"
//#include <hero.h>
#include <fstream>


int main(int argc, char *argv[])
{
    int floor = 1;

    string line;
    ifstream myfile ("story.txt");
    myfile.is_open();

    //myfile.seekg(1, myfile.beg);

    //Read Intro
    getline(myfile, line);
    for(int i=0; i<7; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Hero myHero;

    //Read First Monster
    getline(myfile, line);
    for(int i=0; i<5; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Enemy enemy1(1);
    myHero.fight(&enemy1);


    if(myHero.getHealth() > 0)
    {

        //Read Go Find Stairs
        getline(myfile, line);
        for(int i=0; i<3; i++)
        {
            getline(myfile, line);
            cout << line << endl;
        }
    }

    int rand;
    string input = "";
    int inputInt = 0;

    while(floor < 5 && (myHero.getHealth() > 0))
    {
        cout << "Forward(1)" << endl;
        cout << "Right(2)"   << endl;
        cout << "Left(3)"    << endl;

        while(true)
        {
            getline(cin, input);
            stringstream goIn(input);

            if(!(goIn >> inputInt) || (inputInt < 1) || (inputInt > 3))
            {
                cout << "Choose either 1, 2, or 3" << endl;
            }
            else
            {
                break;
            }
        }

        rand = rangeRand(1,100);

        //There's a 6% chance you find stairs if you move
        if((rand < 6) && (myHero.getHealth() > 0))
        {
            //Read Find Stairs
            getline(myfile, line);
            for(int i=0; i<2; i++)
            {
                getline(myfile, line);
                cout << line << endl;
            }
            floor++;
        }
        //If not stairs, theres an 18% chance you get a battle
        else if((rand > 82) && (myHero.getHealth() > 0))
        {
            Enemy randEnemy(floor);
            myHero.fight(&randEnemy);
        }
    }

    if(myHero.getHealth() <= 0)
    {
        return 0;
    }

    //Read Boss
    getline(myfile, line);
    for(int i=0; i<4; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Enemy boss(5);
    myHero.fight(&boss);

    //Read Win!
    getline(myfile, line);
    for(int i=0; i<4; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    return 0;
}
