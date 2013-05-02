#include "hero.h"
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

    getline(myfile, line);
    for(int i=0; i<5; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Enemy enemy1(1);
    myHero.fight(&enemy1);

    getline(myfile, line);
    for(int i=0; i<3; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    int rand;

    while(floor < 5)
    {
        cout << "Forward(1)" << endl;
        cout << "Right(2)"   << endl;
        cout << "Left(3)"    << endl;

        getline(cin, input);
        stringstream ss1(input);

        while(ss1 > 3 && ss1 < 1)
        {
            cout << "Choose either 1, 2, or 3" << endl;
        }

        rand = rangeRand(1,100);
        if(rand < 7)
        {
            getline(myfile, line);
            for(int i=0; i<2; i++)
            {
                getline(myfile, line);
                cout << line << endl;
            }
            floor++;
        }
        else
        {
            if(rand < 20)
            {
                //Enemy randEnemy(floor);
                //myHero.fight(&randEnemy);
            }
        }
    }

    getline(myfile, line);
    for(int i=0; i<3; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Enemy boss(5);
    myHero.fight(&boss);

    getline(myfile, line);
    for(int i=0; i<4; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }


    /*
    Enemy enemy2(3);
    myHero.fight(&enemy2);
    Enemy enemy3(2);
    myHero.fight(&enemy3);
    Enemy enemy4(1);
    myHero.fight(&enemy4);
    Enemy enemy5(4);
    myHero.fight(&enemy5);
    */

    return 0;
}
