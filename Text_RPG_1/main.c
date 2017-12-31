#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Text_RPG_1
 * Based off of r/dailyprogrammer's challenge #84 and dungeon.c attributed to
 * Douglas L. Jones from the University of Illinois at Urbana-Champaign.
 *
 * C programming language.
 * Matthew Yu
 * 12/30/17
 * V1
 * This program is a text adventure!
 */
int checkEntry(int option, char entry[]);
int main()
{
    char name[50], entry[50];
    int flag = 1, check, choice, day, area, key, death, deathcount = 0, daycount = 0, timeAchievement = 0, deathAchievement = 0;
    //double luck;

    printf("Hello, World!\nHello young adventurer, what is your name?");
    fgets(name, sizeof(name), stdin);
    while(strcmp(name, "\n") == 0)
    {
        printf("Adventurer! Your name, please! \n");
        fgets(name, sizeof(name), stdin);
    }
    name[strlen(name)-1] = '\0';
    printf("Nice to meetcha, %s!\nGood luck on your journey!\n\n", name);

    while(flag)
    {
        area = 0;
        day = 0;
        check = 0;
        choice = 0;
        death = 0;
        //key = 1; //implementation of different story without key?

        while(area != -1 && death != 1 && daycount < 30 /*&& key*/)
        {
            if(area == 0)
            {
                //chase scene
                printf("\n\nThe wind is howling in your ears.\n");
                printf("Left and right, the lights of torches wander in the fog.\n");
                printf("Behind you, a pack of hunting dogs are growling furiously.\n");
                printf("The shouts of guards echo inside the forest.\n");
                printf("Just what did you do in order to incur their wrath?\n");
                printf("You stare guiltily at the key in your hand.\n");
                printf("The key to the treasure vaults of the kingdom!\n");
                printf("\"Quick!\" The voice of your partner in crime shouts from ahead.\n");
                printf("\"There's a split in the woods ahead!\"\n");
                printf("You reach the fork, and your partner's back disappears through the path on the right.\n");
                printf("You have to make a sudden decision! Do you go left or right? Enter (\"left\") or (\"right\").\n");
                printf("Well, actually you could also stop (\"stop\") and turn yourself in.\n");
                printf("But would you really do that after getting so far? ");

                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(0, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "left\n") == 0)
                            choice = 1;
                        else if(strcmp(entry, "right\n") == 0)
                            choice = 2;
                        else if(strcmp(entry, "stop\n") == 0)
                            choice = 3;
                        else if(strcmp(entry, "death25\n") == 0)
                        {
                            deathcount = 25;
                            area = -1;
                        }
                        else
                        {
                            day = 25;
                            area = -1;
                        }
                    }
                    else
                        printf("Please enter \"left\", \"right\", or \"stop\". ");
                } while (check == 0);

                if(choice == 1)
                    area = 1;
                else if(choice == 2)
                    area = 2;
                else if(choice == 3)
                {
                    printf("The news the next day: \"%s arrested for treason and hanged to death.\"\n", name);
                    printf("YOU DIED ON DAY %i\n", day);
                    death = 1;
                }
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 1)
            {
                //ditch scene
                day ++;
                printf("\n\nDid you seriously just ditch your partner in crime?\n");
                printf("You should better hope he doesn't come back to stab you for that.\n");
                printf("The night passes, and the sounds of barking and muffled feet trickle away.\n");
                printf("You've finally escaped from your pursuants!\n");
                printf("Your eyes droop forward, and you find a nice, sturdy tree to climb.\n");
                printf("There's a nice vantage point to see from, and plenty of leaves to hide yourself with.\n");
                printf("You have a fitful sleep until the sunrise.\n");
                printf("Day %i as a fugitive.\n", day);
                printf("By noon, you're already walking up the mountain through the forest.\n");
                printf("Everything is peaceful, but your mind is not.\n");
                printf("You have the key, but now what?\n");
                printf("The next plan in action is to sneak into the royal vault and open the safe, but you don't have a watchmate!\n");
                printf("Do you go in alone, or search for your mate? Or do you recruit another accomplice?\n");
                printf("Enter (\"alone\") or (\"search\") or (\"recruit\") ");

                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(1, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "alone\n") == 0)
                            choice = 0;
                        else if(strcmp(entry, "search\n") == 0)
                            choice = 1;
                        else if(strcmp(entry, "recruit\n") == 0)
                            choice = 2;
                        else
                            choice = 3;
                    }
                    else
                        printf("Please enter \"alone\", \"search\", or \"recruit\".\n");
                } while (check == 0);

                if(choice == 0)
                    area = 4;
                else if(choice == 1)
                    area = 2;
                else if(choice == 2)
                    area = 3;
                else if(choice == 3)
                {
                    printf("You decided to give up and become a farmer, and threw away the key in the river.\n");
                    printf("In the distant future, a peasant who found the key was awarded several bags of gold.\n");
                    printf("You, however, died to an assassin soon after you raised your first crop. Too bad!\n");
                    printf("YOU DIED ON DAY %i\n", day);
                    death = 1;
                    //key = 0;
                }
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 2)
            {
                //search
                day++;
                printf("\n\nYou catch up with your partner at the end of the right path, panting and out of breath.\n");
                printf("\"You're so slow! What if the guards caught you and had taken away the key?\"\n");
                printf("He's usually this irritable.\n");
                printf("The two of you sneak around the forest and return to the castle by nightfall.\n");
                printf("Your partner unlocks the doors and you sneak into the vault.\n");
                printf("You use the key to open the safe and the treasure is in front of you.\n");
                printf("Suddenly, a light shines in your eyes!\n");
                printf("It's the princess of the castle, and she's already called the guards! What will you do?\n");
                printf("Do you snatch the princess and hold her hostage or take the loot and flee?\n");
                printf("Enter (\"hold princess hostage\") or (\"flee\"); ");

                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(2, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "hold princess hostage\n") == 0)
                            choice = 0;
                        else
                            choice = 1;
                    }
                    else
                        printf("Please enter \"hold princess hostage\" or \"flee\".\n");
                } while (check == 0);

                if(choice == 0)
                    area = 6;
                else if(choice == 1)
                    area = 7;
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 3)
            {
                //recruit scene
                day++;
                printf("\n\nYou're in a tavern, drinking cider with a hood over your head.\n");
                printf("It's only been %i days, but there are already wanted posters of you on the walls.\n", day);
                printf("Perhaps it's best to be discreet about your business.\n");
                printf("However, a thin man with a white scar on his face sits down across from you.\n");
                printf("\"I don't believe we've met, have we?\" he says in a grating voice.\n");
                printf("There's a glare in his eye, bloodshot and murderous.\n");
                printf("\"Let's be frank.\" he utters. \"I know who you are, %s, what you've done.\"\n", name);
                printf("\"Unless you want me bringing the army upon you right now, I have one demand.\"\n");
                printf("\"I want in, capiche?\"\n");
                printf("He doesn't seem to be the type of person you'd want to hang out with.\n");
                printf("Do you accept his demands? Or leave immediately? Enter (\"accept\") or (\"leave\"). ");

                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(3, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "accept\n") == 0)
                            choice = 0;
                        else if(strcmp(entry, "leave\n") == 0)
                            choice = 1;
                        else
                            choice = 2;
                    }
                    else
                        printf("Please enter \"accept\" or \"leave\".\n");
                } while (check == 0);

                if(choice == 0)
                    area = 5;
                else if(choice == 1)
                {
                    printf("You stood up to leave, but the man pulls out knife and stabs you.\n");
                    printf("As you lay bleeding out, he robs you of the key and says, \"See ya, sucker.\"\n");
                    printf("YOU DIED ON DAY %i\n", day);
                    death = 1;
                    //key = 0;
                }
                else if(choice == 2)
                {
                    printf("You get in a fistfight with the man. After you two get beat up, he laughs and tells you ");
                    printf("to give him the key in exchange for a life with money.\n");
                    printf("You accept, and he gives you a bag of gold. You live happily ever after!\n");
                    area = -1;
                    //key = 0;
                }
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 4)
            {
                day++;
                printf("\n\nAlright! You're going in alone!\n");
                printf("After spending a day getting ready, you sneak onto castle grounds.\n");
                printf("You don't have the lockpick skill, though, so you get stuck outside the gates.\n");
                printf("Give up? Or look for your comrade? Or will you find someone else with the skills?\n");
                printf("Enter (\"give up\") or (\"search\") or (\"recruit\"). ");

                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(4, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "give up\n") == 0)
                            choice = 0;
                        else if(strcmp(entry, "search\n") == 0)
                            choice = 1;
                        else if(strcmp(entry, "recruit\n") == 0)
                            choice = 2;
                        else
                            choice = 3;
                    }
                    else
                        printf("Please enter \"give up\" or \"search\" or \"recruit\".\n");
                } while (check == 0);

                if(choice == 0)
                {
                    printf("You gave up. But as you turned around to leave, a guard says, \"Intruder!\"\n");
                    printf("You were then quickly killed.\n");
                    printf("YOU DIED ON DAY %i\n", day);
                    death = 1;
                }
                else if(choice == 1)
                    area = 2;
                else if(choice == 2)
                    area = 3;
                else if(choice == 3)
                    area = 8;
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 5)
            {
                //bad end scene 1
                day++;
                printf("\n\nYou and your new accomplice decide on a plan of action.\n");
                printf("You both return to the castle disguised as pages and sneak into the treasury in the dead of night.\n");
                printf("Your partner picks the locks to the door and finally, you're in the treasure room!\n");
                printf("\"Psst, hurry up, before the guards come!\"\n");
                printf("You insert the key into the lock and twist with all your might until you hear a deep clicking sound.\n");
                printf("You did it! You swing the door outwards until suddenly-\n");
                printf("you find a saber emerging from your chest.\n");
                printf("You turn your head and find yourself looking into the greedy eyes of your former companion!\n");
                printf("\"That's what you get for backstabbing me, %s!\" he laughs, and your new 'companion'", name);
                printf(" bares his teeth evily.\n You finally black out.\n");
                printf("YOU DIED ON DAY %i\n", day);
                death = 1;
            }
            else if(area == 6)
            {
                //hostage
                printf("\n\nGoodness, you held the princess hostage!\n");
                printf("Your partner angrily yells at the cowering king.\n");
                printf("\"Arrgh! Hand over the loot and let us leave peacefully or the girl gets it!\"\n");
                printf("The king acquiesces and you're soon on a carriage out of the country.\n");
                printf("Well, not until you two get murdered at the border by ruffians.\n");
                printf("YOU DIED ON DAY %i\n", day);
                death  = 1;
            }
            else if(area == 7)
            {
                //flee
                day++;
                printf("\n\nYou grabbed the gold and hightailed it out of the castle!\n");
                printf("Thankfully your partner in crime had a map of the underground sewers,\n");
                printf("so you two escaped and went fugitive in another country.\n");
                printf("You lived happily ever after!\n");
                area = -1;
            }
            else if(area == 8)
            {
                //hide
                day++;
                printf("You live a day of hiding away in the forest, scavenging for nuts and hunting for small animals\n");
                if(day > 10)
                    printf("You shiver in your boots as you're pissing somewhere on the mountain.");
                if(day > 20)
                    printf("Hey, %s, how long are you intending to lounge around?\nAre you waiting for the kingdom to fall? ", name);
                printf("Should you wait it out some more?\nOr go find your partner? Or search for another?\n");
                printf("Enter (\"hide\") or (\"search\") or (\"recruit\"). ");
                do{
                    fgets(entry, sizeof(entry), stdin);
                    check = checkEntry(8, entry);
                    if(check == 1)
                    {
                        if(strcmp(entry, "hide\n") == 0)
                            choice = 0;
                        else if(strcmp(entry, "search\n") == 0)
                            choice = 1;
                        else if(strcmp(entry, "recruit\n") == 0)
                            choice = 2;
                        else
                            choice = 3;
                    }
                    else
                        printf("Please enter \"hide\" or \"search\" or \"recruit\".\n");
                } while (check == 0);

                if(choice == 0)
                {
                    if(day > 25)
                        area = 9;
                    else
                        area = 8;
                }
                else if(choice == 1)
                {
                    if(day > 10)
                    {
                        area = 8;
                        printf("It's been so long, don't you think he's already left?\n");
                    }
                    else
                        area = 2;
                }

                else if(choice == 2)
                    area = 3;
                else
                {
                    printf("Adventurer, it's dangerous, you shouldn't be here! Err: badchoice\n");
                }
            }
            else if(area == 9)
            {
                printf("Forces beyond your control bring you back to the castle.\n");
                printf("Astonishingly, the castle was destroyed by a gigantic dragon.\n");
                printf("You rummaged through the rubble for the vault.\n");
                printf("The dragon took all the loot. Good job %s!\n", name);
                printf("You decide to live happily ever after, miserably poor.\n");
                area = -1;
            }
        }
        if(daycount >= 50)
        {
            printf("Are you still playing? The game is over. The dragon destroyed the castle days ago.\n");
            printf("Your princess and loot are in another castle!\n");
            printf("Alternatively, another *iteration* of this world.\n");
            printf("But you aren't bored enough to do that, right?");
        }

        //tallying results
        if(death == 1)
            deathcount++;
        daycount = daycount + day;

        //game over
        printf("\n\nGame over. You have died %i times. You have played for a total of %i day(s).\n\n\n", deathcount, daycount);
        //achievements
        if(timeAchievement == 1)
            printf("Achievement: Abnormally long shelf life.\n");
        if(deathAchievement == 1)
            printf("Achievement: Masochist.\n");
        //hints and eggs
        if(deathcount == 5)
            printf("Did you know? You could just 'give up' once you run away.\n");
        if(deathcount == 10)
            printf("Did you know? You could 'hide' if things go south.\n");
        if(deathcount == 15)
            printf("When you see a shady guy, don't you want to just 'punch him'?\n");
        if(deathcount == 25)
        {
            printf("You died so many times the universe exploded.\n");
            printf("Have a cookie for the next death.\n");
            deathAchievement = 1;
        }
        if(daycount == 25)
        {
            printf("Either you're very persistent at playing this game or you got stuck in an infinite loop.\n");
            printf("Well anyways, here's a cookie on the next run!\n");
            timeAchievement = 1;
        }
        printf("Would you like to play again? Enter 1 for yes, 0 for no. ");
        do{
            fgets(entry, sizeof(entry), stdin);
            check = checkEntry(-1, entry);
            if(check == 1)
            {
                if(strcmp(entry, "1\n") == 0)
                    choice = 1;
                else
                    choice = 0;
            }
            else
            {
                printf("\n Bad input. Enter a 1 or 0. ");
            }
        }while(check == 0);
        if(choice == 0)
        {
            flag = 0;
            printf("Thank you for playing! Text_RPG_1 (2017) by Matthew Yu");
        }
    }
    return 0;
}

/**
 * checkEntry checks for whether the input is valid or not.
 * @param entry char array entered by user.
 * @param option int option of what type of input context is available
 * @return boolean int of whether input is valid or not. 0 is invalid, 1 is valid.
 */
int checkEntry(int option, char entry[])
{
    //check for 1 or 0 input.
    if(option == -1)
    {
        if(strcmp(entry, "1\n") != 0 && strcmp(entry, "0\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 0 check
    else if(option == 0)
    {
        if(strcmp(entry, "left\n") != 0 && strcmp(entry, "right\n") != 0 && strcmp(entry, "stop\n") != 0 && strcmp(entry, "death25\n") != 0 && strcmp(entry, "day25\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 1 check
    else if(option == 1)
    {
        if(strcmp(entry, "alone\n") != 0 && strcmp(entry, "search\n") != 0 && strcmp(entry, "recruit\n") != 0 && strcmp(entry, "give up\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 2 check
    else if(option == 2)
    {
        if(strcmp(entry, "hold princess hostage\n") != 0 && strcmp(entry, "flee\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 3 check
    else if(option == 3)
    {
        if(strcmp(entry, "accept\n") != 0 && strcmp(entry, "leave\n") != 0 && strcmp(entry, "punch him\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 4 check
    else if(option == 4)
    {
        if(strcmp(entry, "give up\n") != 0 && strcmp(entry, "search\n") != 0 && strcmp(entry, "recruit\n") != 0 && strcmp(entry, "hide\n") != 0)
            return 0;
        else
            return 1;
    }
    //area 8 check
    else if(option == 8)
    {
        if(strcmp(entry, "hide\n") != 0 && strcmp(entry, "search\n") != 0 && strcmp(entry, "recruit\n") != 0)
            return 0;
        else
            return 1;
    }
    else
    {
        printf("Adventurer, it's dangerous, you shouldn't be here! Err: badOption\n");
        return 0;
    }

}