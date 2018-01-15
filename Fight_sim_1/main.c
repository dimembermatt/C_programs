#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
/ Fight Simulator Program #1
/ C
/ @author: Matthew Yu
/ @version: 1.1
/ 1/14/18 - V1.0
/ 1/15/18 - V1.1 - implementation of stamina, multi difficulty opponent, multiple opponents, multiple weapons (sword, shield, spear)
/
/ This program is a simple fighting simulator, in which the Player fights a pre-generated opponent.
/ The Player is given the option to attack, use a special attack (which is dependent on stamina,
/ or defend, and damage is based on an rng. The pre generated opponent has three modes, building
/ up to the full capability as the player.
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
    int rand_num = 0;
    while(1)
    {
        int turn = 0;
        int result = 0;
        srand((unsigned int) time(0));
        printf("Hello, Fight sim World!\n");

        //round 1
        printf("\nGenerating character...\n");
        Actor Player;
        Player.hp = 100;
        Player.stamina = 10;
        Player.weapon = 0;
        strcpy(Player.name, "Player");
        printf("Character: %s\nHP: %d\nStamina: %d\nWeapon: Sword\n", Player.name, Player.hp, Player.stamina);

        printf("\nGenerating enemy...\n");
        Actor Enemy1;
        Enemy1.hp = 50;
        Enemy1.stamina = 10;
        Enemy1.weapon = 0;
        strcpy(Enemy1.name, "Ganon");
        printf("Character: %s\nHP: %d\nStamina: %d\nWeapon: Sword\n", Enemy1.name, Enemy1.hp, Enemy1.stamina);

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
            printf("Death = -1. Error.\n");

        //round 2
        printf("\nRound 2!\n");
        printf("\nGenerating enemy...\n");
        Actor Enemy2;
        Enemy2.hp = 75;
        Enemy2.stamina = 10;
        Enemy2.weapon = 1;
        strcpy(Enemy2.name, "Light Yagami");
        printf("Character: %s\nHP: %d\nStamina: %d\nWeapon: Shield\n", Enemy2.name, Enemy2.hp, Enemy2.stamina);

        printf("\n\nNow fight!\n");
        rand_num = rand();
        if(rand_num%100 >= 50)
            turn = 1;
        else
            turn = 0;
        result = fight(Player, Enemy2, turn);

        if(result == 1)
            printf("%s wins!\n", Player.name);
        else if(result == 0)
            printf("%s wins!\n", Enemy2.name);
        else if(result == 2)
            printf("A double knockout! It's a draw!\n");
        else
            printf("Death = -1. Error.\n");

        //round 3
        printf("\nRound 3!\n");
        printf("\nGenerating enemy...\n");
        Actor Enemy3;
        Enemy3.hp = 100;
        Enemy3.stamina = 10;
        Enemy3.weapon = 2;
        strcpy(Enemy3.name, "Giovanni");
        printf("Character: %s\nHP: %d\nStamina: %d\nWeapon: Spear\n", Enemy3.name, Enemy3.hp, Enemy3.stamina);

        printf("\n\nNow fight!\n");
        rand_num = rand();
        if(rand_num%100 >= 50)
            turn = 1;
        else
            turn = 0;
        result = fight(Player, Enemy3, turn);

        if(result == 1)
            printf("%s wins!\n", Player.name);
        else if(result == 0)
            printf("%s wins!\n", Enemy3.name);
        else if(result == 2)
            printf("A double knockout! It's a draw!\n");
        else
            printf("Death = -1. Error.\n");

        printf("Game over. Thanks for playing! Created 2018, Matthew Yu\n");
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
 * 1 - shield - 50% dmg reduction against sword special attack
 * 2 - spear
 **/


/**
 * fight takes two Actor structs and their properties and plays a turn by turn fight.
 * @param Actor1 player struct
 * @param Actor2 enemy struct
 * @param turn RNG int that decides who goes first
 * @return int result of fight (-1 for error)
 */
int fight(Actor Actor1, Actor Actor2, int turn)
{
    int rand_num = 0;
    int dmg = 0;
    int defend_flag = 0;
    int death = -1;
    char decision[3];

    while(Actor1.hp > 0 && Actor2.hp > 0)
    {
        if(turn == 0)
        {
            printf("\n%s's turn! Type 1 to attack, 2 to special attack, or 3 to defend.\n", Actor1.name);
            do{
                if(fgets(decision, sizeof(decision), stdin) == NULL)
                    printf("NULL error.\n");
                if(strcmp(decision, "1\n") == 0 || (strcmp(decision, "2\n") == 0 && Actor1.stamina >= 5) || strcmp(decision, "3\n") == 0)
                    break;
                if(strcmp(decision, "2\n") == 0 && Actor1.stamina < 5)
                    printf("Not enough stamina!\n");
                else
                    printf("Invalid input. Type 1 to attack, 2 to special attack, or 3 to defend.\n");
            }while(1);

            //attack
            if(strcmp(decision, "1\n") == 0)
            {
                rand_num = rand();
                //damage calculation
                dmg = rand_num%10 + 1;

                //check defend flag
                if(defend_flag == 1)
                {
                    //damage calculation
                    dmg = dmg/2;
                    Actor1.hp = Actor1.hp - dmg;
                    Actor2.hp = Actor2.hp - dmg;
                    defend_flag = 0;

                    //output message based on attack result.
                    printf("%s attacks but %s defended!\n", Actor1.name, Actor2.name);
                    printf("%d reduced damage is dealt and %d damage is rebounded!\n", dmg, dmg);
                    printf("%s has %d hp left. %s has %d hp left.\n", Actor1.name, Actor1.hp, Actor2.name, Actor2.hp);
                }
                else
                {
                    //damage calculation
                    Actor2.hp = Actor2.hp - dmg;

                    //output message based on attack result.
                    printf("%s attacks! %d damage is dealt!\n", Actor1.name, dmg);
                    printf("%s has %d hp left!\n", Actor2.name, Actor2.hp);
                }
            }
            //special attack
            else if(strcmp(decision, "2\n") == 0)
            {
                rand_num = rand();
                //check weapon affinity and damage calculation
                if(Actor2.weapon == 1)
                    dmg = rand_num%5;
                else
                    dmg = rand_num%10 + 10;

                Actor1.stamina = Actor1.stamina - 5;
                Actor2.hp = Actor2.hp - dmg;
                defend_flag = 0;

                //output messages based on attack result.
                if(Actor2.weapon == 1)
                {
                    printf("%s uses a special attack! It was resisted by the enemy's shield...\n", Actor1.name);
                    printf("%d damage is dealt. %s has %d health left.\n", dmg, Actor2.name, Actor2.hp);
                    printf("Stamina fell by 5. Stamina left: %d\n", Actor1.stamina);

                }
                else
                {
                    printf("%s uses a special attack!\n", Actor1.name);
                    printf("%d damage is dealt! %s has %d health left.\n", dmg, Actor2.name, Actor2.hp);
                    printf("Stamina fell by 5. Stamina left: %d\n", Actor1.stamina);
                }
            }
            //defend
            else if(strcmp(decision, "3\n") == 0)
            {
                defend_flag = 1;
                printf("%s prepares to defend!\n", Actor1.name);
            }
            //error checking
            else
            {
                printf("Player option error. Input is out of bounds.\n");
                return -1;
            }

            //end turn actions
            if(Actor1.stamina <= 10)
                Actor1.stamina ++;
            turn = 1;
        }
        else
        {
            printf("\n%s's turn!\n", Actor2.name);

            //check weapon and set rng to options based on it
            if(Actor2.weapon == 0)
                rand_num = rand()%1; //only attack
            else if(Actor2.weapon == 1)
                rand_num = rand()%5; //attack and defend
            else if(Actor2.weapon == 2)
            {
                do{
                    rand_num = rand()%10;
                }while(rand_num >= 7 && Actor2.stamina < 5);
            } //attack, defend, and special attack
            else
            {
                printf("Error. Weapon type not yet supported.\n");
                return -1;
            }
            //100% chance if weapon is sword (0), 60% chance if weapon is shield (0,1,2), 50% chance if weapon is spear (0-4)
            if((Actor2.weapon == 0 && rand_num == 0) || (Actor2.weapon == 1 && rand_num <= 2) || (Actor2.weapon == 2 && rand_num <=4))
            {
                //attack
                rand_num = rand();
                dmg = rand_num%10 + 1;

                //check defend flag
                if(defend_flag == 1)
                {
                    //damage calculation
                    dmg = dmg/2;
                    Actor1.hp = Actor1.hp - dmg;
                    Actor2.hp = Actor2.hp - dmg;
                    defend_flag = 0;

                    //output message based on attack result.
                    printf("%s attacks but %s defended!\n", Actor2.name, Actor1.name);
                    printf("%d reduced damage is dealt and %d damage is rebounded!\n", dmg, dmg);
                    printf("%s has %d hp left. %s has %d hp left.\n", Actor1.name, Actor1.hp, Actor2.name, Actor2.hp);
                }
                else
                {
                    //damage calculation
                    Actor1.hp = Actor1.hp - dmg;

                    //output message based on attack result.
                    printf("%s attacks! %d damage is dealt!\n", Actor2.name, dmg);
                    printf("%s has %d hp left!\n", Actor1.name, Actor1.hp);
                }
            }
            //40% chance if weapon is shield (3,4), 20% chance if weapon is spear (5,6)
            else if((Actor2.weapon == 1 && rand_num >= 3 && rand_num <= 4) || (Actor2.weapon == 2 && rand_num >= 5 && rand_num <= 6))
            {
                //defend
                defend_flag = 1;
                printf("%s prepares to defend!\n", Actor2.name);
            }
            //30% chance if weapon is spear (7,8,9)
            else if(Actor2.weapon == 2 && rand_num >= 7 && rand_num <= 9)
            {
                //special attack
                rand_num = rand();
                //check weapon affinity and damage calculation
                if(Actor1.weapon == 1)
                    dmg = rand_num%5;
                else
                    dmg = rand_num%10 + 10;

                Actor2.stamina = Actor2.stamina - 5;
                Actor1.hp = Actor1.hp - dmg;
                defend_flag = 0;

                //output messages based on attack result.
                if(Actor1.weapon == 1)
                {
                    printf("%s uses a special attack! It was resisted by the enemy's shield...\n", Actor1.name);
                    printf("%d damage is dealt. %s has %d health left.\n", dmg, Actor1.name, Actor1.hp);
                    printf("Stamina fell by 5. Stamina left: %d", Actor2.stamina);

                }
                else
                {
                    printf("%s uses a special attack!\n", Actor2.name);
                    printf("%d damage is dealt! %s has %d health left.\n", dmg, Actor1.name, Actor1.hp);
                    printf("Stamina fell by 5. Stamina left: %d", Actor2.stamina);
                }
            }
            else
            {
                printf("Enemy option error. RNG is out of bounds.\n");
                return -1;
            }

            //end turn actions
            if(Actor2.stamina <= 10)
                Actor2.stamina ++;
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
