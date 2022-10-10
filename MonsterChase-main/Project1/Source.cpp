
#include <iostream>
#include <conio.h>

const int MAX = 100;
int board[MAX][MAX];
int number;
char p_name[50];
int p_x;
int p_y;

void Copy_string(char* str1, char* str2)

{

    int i = 0;

    while (str1[i] != 0)
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';

}

void copy(char s1[], char s2[]) {

    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        s2[i] = s1[i];
    }

    s2[i] = '\0';

}

class Monster
{
public:
    char name[50];
    int x;
    int y;
    int round_dead;

};





void clear_board() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board[i][j] = 0;
        }
    }
}


int main()
{
    clear_board();

    std::cout << "Welcome to MonsterChase!\n\n";
    std::cout << "How many monsters to start :";
    std::cin >> number;
    std::cout << "\n";

    Monster* monsters = new Monster[number];
    Monster* temp_monsters;



    for (int i = 0; i < number; i++)
    {
        std::cout << "Enter a name for monster " << i << ": ";
        std::cin >> monsters[i].name;



        monsters[i].x = rand() % 100;
        monsters[i].y = rand() % 100;
        monsters[i].round_dead = rand() % 10;
    }

    std::cout << "Enter a name for the player: ";
    std::cin >> p_name;
    p_x = 0;
    p_y = 0;
    int add_M;
    int same_P;
    while (true)
    {
        add_M = 0;
        clear_board();
        if (number > 1)
        {

            for (int z = 0; z < number; z++)
            {
                board[monsters[z].x][monsters[z].y]++;
            }


            for (int i = 0; i < MAX; i++)
            {
                for (int j = 0; j < MAX; j++)
                {
                    if (board[i][j] > 1)
                    {
                        add_M++;
                    }
                }
            }
        }



        if (add_M == 0 && rand() % 10 < 2)
        {

            add_M++;
        }

        temp_monsters = new Monster[number + add_M];

        for (int i = 0; i < number; i++)
        {
            copy(monsters[i].name, temp_monsters[i].name);

            temp_monsters[i].x = monsters[i].x;
            temp_monsters[i].y = monsters[i].y;
            temp_monsters[i].round_dead = monsters[i].round_dead;
        }
        for (int i = number; i < number + add_M; i++) {

            char t_char[7] = "Newbie";
            copy(t_char, temp_monsters[i].name);
            temp_monsters[i].x = rand() % 100;
            temp_monsters[i].y = rand() % 100;
            temp_monsters[i].round_dead = rand() % 10;
        }
        number = number + add_M;
        monsters = temp_monsters;
        for (int i = 0; i < number; i++)
        {

            std::cout << monsters[i].name << "  " << monsters[i].y << "   " << monsters[i].x << "\n";
        }


        for (int i = 0; i < number; i++)
        {
            monsters[i].round_dead++;
            if (monsters[i].round_dead == 10)
            {
                number--;
            }
        }



        char ch = _getch();




    }

    for (int i = 0; i < number; i++)
    {
        std::cout << monsters[i].name << monsters[i].y << monsters[i].x << "\n";
    }
    free(monsters);




    return 0;
}