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
    
    Hero myHero;

    return 0;
}
