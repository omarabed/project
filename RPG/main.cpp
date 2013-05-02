#include "hero.h"
#include <fstream>




int main(int argc, char *argv[])
{
    // while(line doesn't start with a ':') then output the line
    //Reads out the whole story... not done yet obviously
    string line;
    ifstream myfile ("story.txt");
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line);
            cout << line << endl;
        }
        myfile.close();
    }
    /*
    My plan is to have sections of the story split up by headings.
    So the intro would be denoted by:
    :Intro:
    Once upon a time, ...
    :FirstEnemy:
    Oh! You've encountered a .......
    etc etc
    */


    ///*
    Hero myHero;

    Enemy enemy1(3);
    myHero.fight(&enemy1);

    Enemy enemy2(3);
    myHero.fight(&enemy2);
    Enemy enemy3(2);
    myHero.fight(&enemy3);
    Enemy enemy4(1);
    myHero.fight(&enemy4);
    Enemy enemy5(4);
    myHero.fight(&enemy5);
    //*/

    return 0;
}
