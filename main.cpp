#include<iostream>
#include<random>
#include<ctime>
#include<string>

using namespace std;

int getRandomNumber()
{
    mt19937 mersenne{static_cast<mt19937::result_type>(time(nullptr))};
    uniform_int_distribution<> die{1,100};
    return die(mersenne);
}

string checkRandom(int main_num, int random_num)
{
    if(main_num>random_num)
    {
        return "Your guess is high\n" ;
    }
    if(main_num<random_num)
    {
        return "Your guess is low\n";
    }
    if(main_num==random_num)
    {
        return "Correct\n";
    }
}

int retry()
{
    cout << "Would you like to retry[y/n]";
    char check;
    cin >> check;
    if(check=='y')
    {
        return true;
    }
    else if (check=='n')
    {
        return false;
    }
    else
    {
        retry();
    }
    {
        return false;
    }
}
int main()
{
    cout << "Lets Play a Game. I'm thinking of a number.\n";
    int main_num{0};
    int counter{0};
    int random_num{getRandomNumber()};
    while(true)
    {
        ++counter;
        cout  << "Guess: #" << counter << '\t';
        cin   >> main_num;
        string result{checkRandom(main_num,random_num)};
        cout << result;
        if(result=="Correct\n")
        {
            if(retry())
            {
                main();
            }
            else
            {
                cout << "Thanks for playing.";
                return 0;
            }
        }
    }
}
