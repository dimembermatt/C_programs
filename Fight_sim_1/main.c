#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
/ Fight Simulator Program #1
/ C
/ Matthew Yu
/ 1/14/18
/
/ This program is a simple fighting simulator, in which the Player fights a pre-generated opponent.
/ The Player is given the option to attack or defend, and damage is based on an rng.
/ TODO: stamina and weapon type unused, implement later
**/


typedef struct
{
    int hp, stamina, weapon;
    char name[25];
}Actor;
int fight(Actor Actor1, Actor Actor2, int turn);
int main()
{
    char response[2];
    int rand_num;
    while(1)
    {
        int turn, result;
        srand((unsigned int) time(0));
        printf("Hello, Fight sim World!\n");

        printf("\nGenerating character...\n");
        Actor Player;
        Player.hp = 100;
        Player.stamina = 15;
        Player.weapon = 0;
        strcpy(Player.name, "Player");
        printf("Character: %s\nHP: %d\nWeapon: Sword\n", Player.name, Player.hp);

        printf("\nGenerating enemy...\n");
        Actor Enemy1;
        Enemy1.hp = 50;
        Enemy1.stamina = 15;
        Enemy1.weapon = 0;
        strcpy(Enemy1.name, "Ganon");
        printf("Character: %s\nHP: %d\nWeapon: Sword\n", Enemy1.name, Enemy1.hp);

        printf("\n\nNow fight!\n");
        rand_num = rand();
        if(rand_num%100 >= 50)
            turn = 1;
        else
            turn = 0;
        result = fight(Player, Enemy1, turn);

        if(result == 1)
            printf("%s wins!\n", Player.name);
        else if(result == 0)
            printf("%s wins!\n", Enemy1.name);
        else if(result == 2)
            printf("A double knockout! It's a draw!\n");
        else
            printf("Death = -1. Error.");

        printf("Press 1 to exit, any other key to play again.\n");
        fgets(response, sizeof(response), stdin);
        if(strcmp(response, "1") == 0)
            break;
    }

    return 0;
}

/**
 * Weapon description:
 * 0 - sword
 * 1 - staff
 * 2 - spear
 **/


int fight(Actor Actor1, Actor Actor2, int turn)
{
    int rand_num, dmg, defend_flag = 0, death = -1;
    char decision[3];
    while(Actor1.hp > 0 && Actor2.hp > 0)
    {
        if(turn == 0)
        {
            printf("\n%s's turn! Type 1 to attack, or 2 to defend.\n", Actor1.name);
            do{
                if(fgets(decision, sizeof(decision), stdin) == NULL)
                    printf("NULL error.\n");
                if(strcmp(decision, "1\n") == 0 || strcmp(decision, "2\n") == 0)
                    break;
                printf("Invalid input. Type 1 to attack, or 2 to defend.\n");
            }while(1);

            //attack
            if(strcmp(decision, "1\n") == 0)
            {
                rand_num = rand();
                dmg = rand_num%10 + 1;
                Actor2.hp = Actor2.hp - dmg;
                printf("%s attacks! %d damage is dealt!\n%s has %d hp left!\n", Actor1.name, dmg, Actor2.name, Actor2.hp);
            }

            //defend
            else if(strcmp(decision, "2\n") == 0)
            {
                defend_flag = 1;
                printf("%s prepares to defend!\n", Actor1.name);
            }
            //error checking
            else
                printf("You shouldn't be here...\n");
            turn = 1;
        }
        else
        {
            printf("\n%s's turn!\n", Actor2.name);
            //some code
            //attack
            rand_num = rand();
            dmg = rand_num%10 + 1;
            if(defend_flag == 1)
            {
                dmg = dmg/2;
                Actor1.hp = Actor1.hp - dmg;
                Actor2.hp = Actor2.hp - dmg;
                defend_flag = 0;
                printf("%s attacks but %s defended! %d reduced damage is dealt and %d damage is rebounded!\n", Actor2.name, Actor1.name, dmg, dmg);
                printf("%s has %d hp left! %s has %d hp left!\n", Actor1.name, Actor1.hp, Actor2.name, Actor2.hp);
            }
            else
            {
                Actor1.hp = Actor1.hp - dmg;
                printf("%s attacks! %d damage is dealt!\n%s has %d hp left!\n", Actor2.name, dmg, Actor1.name, Actor1.hp);
            }
            turn = 0;
        }


        //check faint and set death flag if true
        if(Actor1.hp <= 0)
        {
            printf("%s faints!\n", Actor1.name);
            death = 0;
        }
        if(Actor2.hp <= 0)
        {
            printf("%s faints!\n", Actor2.name);
            death = 1;
        }
        if(Actor1.hp <= 0 && Actor2.hp <= 0)
        {
            printf("Both fighters have fainted!\n");
            death = 2;
        }
    }
    return death;
}
