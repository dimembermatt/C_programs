#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/**
 * HelloTree Program.
 * File access, modularity, Unions, Structs, Pointer practice.
 * Game design practice.
 *
 * HelloTree is a game where you try to grow the tallest tree in the world! Keep your tree standing against the elements and unfortunate events of the world.
 * TODO: current: fill quotes.txt/prompts.txt with scenarios, debugging
 * TODO: post-working V1 = add itemization, currency. Add fertilizer to your tree to make it grow, or ...
 * TODO: future - implement in java - port into android
 *
 * C programming language.
 * Matthew Yu
 * V1.0 3/7/2018
 * V1.1 WORKING 3/14/2018
 *
 * DOCUMENTATION NOTICE: This program requires the files
 * Quotes.txt, and Prompts.txt in the same folder as the .exe. Functions of the
 * program will not work if either of these files are not included.
 *
 */

#define quoteListLength 50
#define promptListLength 36

FILE *quotes, *prompts;
int quotePointersArr[quoteListLength], promptPointersArr[promptListLength];
char fileName[150];

//main Actor of game - stats change based on events and actions
typedef struct Tree{
    int height;         //in unit cm
    int calamity;
    int love;
    int alive;          //0 = dead, 1 = alive
    int day;
}Tree;

//pre-programmed singular effect of some consequence on Tree
union statChange{
    int heightInc;
    int love;
};

//result of choosing a option of some Prompt - both String consequence and effect
typedef struct Result{
    char consequence[150];
    union statChange effect;
    int type;
}Result;

//prompt loaded from file with a String prompt, options available, and some result
typedef struct Prompt{
    char prompt[150];
    int option[4];
    Result result[4];
}Prompt;

void fileInit();
int quoteGenerator(Tree aTree);
int promptGenerator(Tree *aTree);
Result userPrompt(int aPromptIdx);
void readResponse(Result aResult, Tree *aTree);
void readStatus(Tree aTree, int quoteIdx);
void readEnd(Tree aTree);
void wait(double numberOfSeconds);

int main()
{
    //init
    fileInit();
    srand((unsigned int) time(0));
    int quoteIdx, promptIdx;
    char buff[3];
    Result result;
    Tree myTree;
    myTree.height = 1;
    myTree.calamity = 0;
    myTree.love = 0;
    myTree.alive = 1;
    myTree.day = 1;

    printf("Hello, World!\n");
    printf("Hello, Tree!\n");
    //opening graphic animation

    //main game loop
    while(myTree.alive)
    {
        //beginning prompt
        if(myTree.day == 1)
        {
            printf("One day, you planted a seed into the ground.\nIt then full-heartedly sprouted.\n");
            printf("Now, let's raise the largest tree in the world!\n\n");
        }

        //daily prompt
        quoteIdx = quoteGenerator(myTree);
        readStatus(myTree, quoteIdx);
        //generate event
        promptIdx = promptGenerator(&myTree);
        //user response
        result = userPrompt(promptIdx);
        //generate consequence
        readResponse(result, &myTree);
        if(myTree.height <= 0)
            myTree.alive = 0;
        myTree.day++;
        myTree.height++;
        wait(1);
        if(myTree.alive == 1)
        {
            printf("Type 'n' to move to next day. ");
            do{
                fgets(buff, sizeof(buff), stdin);
                if(strcmp(buff, "n\n") != 0)
                    printf("Please type 'n' to move to next day. ");
                else
                    break;
            }while(1);
        }
    }
    readEnd(myTree);
    printf("Type 'e' to exit. ");
    do{
        fgets(buff, sizeof(buff), stdin);
        if(strcmp(buff, "e\n") != 0)
            printf("Please type 'e' to exit. ");
        else
            return 1;
    }while(1);
}

/**
 * fileInit initiates the file. It fills an array with pointers to quotes in a file
 * as well as an array with pointers to prompts and responses in a file.
 */
void fileInit()
{
    GetFullPathNameA("Quotes.txt", sizeof(fileName), fileName, NULL);
    if((quotes = fopen(fileName, "r")) == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", fileName);
        exit(0);
    }
    //read in pointers of each line from Quotes file
    //assume quoteListLength is accurate with txt file
    quotePointersArr[0] = -1;
    int ptrInc = 0;
    quotePointersArr[ptrInc] = ftell(quotes);
    //inc array
    ptrInc++;

    while(ptrInc < quoteListLength)
    {
        fscanf(quotes, "%*[^\n]\n", NULL);
        quotePointersArr[ptrInc] = ftell(quotes);
        ptrInc++;
    }
    fclose(quotes);

    GetFullPathNameA("Prompts.txt", sizeof(fileName), fileName, NULL);
    if((prompts = fopen(fileName, "r")) == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", fileName);
        exit(0);
    }
    //read in pointers from PromptPointers file
    //assume promptListLength is accurate with txt file
    //space pointers to account for options, results
    ptrInc = 0;
    promptPointersArr[ptrInc] = ftell(prompts);
    ptrInc++;
    while(ptrInc < promptListLength)
    {
        for(int i = 0; i < 10; i ++) //10 lines for each prompt allocated
            fscanf(prompts, "%*[^\n]\n", NULL);
        promptPointersArr[ptrInc] = ftell(prompts);
        ptrInc++;
    }
    fclose(prompts);
}

/**
 * quoteGenerator takes in the status of the Tree and randomly generates a prompt
 * @param aTree struct Tree
 * @return index of some quote pointer in quotePointersArr
 * no pass by reference since only accessing data so copy is okay
 */
int quoteGenerator(Tree aTree)
{
    //{[(0-14 sapling) - 29 small tree (25-29 well taken care of)] - 49 medium tree (45-49 well loved)}
    //some set of quote numbers related to a sapling - short, cute, etc -allocate 0-14 from rng
    if(aTree.height < 50)
    {
        return rand()%15;
    }
    if(aTree.height >= 50 && aTree.height < 100)
    {
        //some set of specific quote numbers related to a well taken care of tree //include 23-29 from rng allocation
        //some set of quote numbers related to a small tree
        //allocate (15-29) from rng
        if(aTree.love > 15)
        {
            //allocate 25-29 subset
            return rand()%15 + 15;
        }
        else return rand()%10 + 15;
    }
    if(aTree.height >= 100)
    {
        //some set of quote numbers related to a well loved tree
        //some set of quote numbers related to a growing tree
        //allocate (30-49) from rng
        if(aTree.love > 50)
        {
            //allocate 45-49 subset
            return rand()%20 + 30;
        }
        else return rand()%15 + 30;
    }
    else
    {
        printf("invalid aTree.height. aTree.height is: %i. err.\n", aTree.height);
        exit(0);
    }
}

/**
 * promptGenerator randomly generates a prompt
 * @param aTree reference to Tree to change calamity
 * @return index of some prompt pointer in promptPointersArr
 * pass by reference and use of arrow operator to access and change member of struct
 */
int promptGenerator(Tree *aTree)
{
    int promptIdx;
    if(aTree->day > 10)
    {
        do{
            promptIdx = rand()%36;
            if(promptIdx < 11)
                wait(2);
            if(promptIdx < 24 || promptIdx > 29)
                break;
        }while(1);

    }
    else
    {
        promptIdx = rand()%36;
        if(promptIdx >= 24 && promptIdx <= 29)
            aTree->calamity++;
        if(promptIdx < 11)
            wait(2);
    }
    return promptIdx;
}

/**
 * userPrompt takes in the return from promptGenerator, uses the index to get a pointer
 * to the prompt in file memory and stores prompt and additional input/consequences in a struct
 * @param aPrompt index to prompt pointer in file memory
 * @return filled Result structure with a selected consequence and stat change
 */
Result userPrompt(int aPromptIdx)
{
    Prompt prompt;
    //option selection -1 (not available), 0 (activated, but not selecteD), 1 (activated and selected)
    prompt.option[0] = -1;
    prompt.option[1] = -1;
    prompt.option[2] = -1;
    prompt.option[3] = -1;

    int optionSize;
    int statChange = 0;
    char buff[3];
    int validInp = 0;

    //open file
    GetFullPathNameA("Prompts.txt", sizeof(fileName), fileName, NULL);
    if((prompts = fopen(fileName, "r")) == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", fileName);
        exit(0);
    }
    //read Prompt, options, results(consequences, stat changes) and store in prompt struct
    fseek(prompts, promptPointersArr[aPromptIdx], SEEK_SET);
    //get line of prompt size
    fgets(prompt.prompt, sizeof(prompt.prompt), prompts);
    //get number of options
    fscanf(prompts, "%d%*c", &optionSize);
    //process optionSize
    switch(optionSize)
    {
        //turn option on depending on optionSize
        case 4:
            prompt.option[3] = 0;
        case 3:
            prompt.option[2] = 0;
        case 2:
            prompt.option[1] = 0;
        case 1:
        default:
            prompt.option[0] = 0;
    }
    //retrieve rest of information from prompt based on how many options there are
    for(int i = 0; i < optionSize; i++)
    {
        //get consequence flavor text for each option (null or not)
        fgets(prompt.result[i].consequence, sizeof(prompt.result[i].consequence), prompts);
        //get type for each option, get union statChange for each option
        fscanf(prompts, "%d%d%*c", &prompt.result[i].type, &statChange);
        //define what statChange type is based on type
        if(prompt.result[i].type == 0)
            prompt.result[i].effect.heightInc = statChange;
        else if(prompt.result[i].type == 1)
            prompt.result[i].effect.love = statChange;
        else
        {
            printf("conversion error. type not 0/1. type is:%d. statChange is:%i. err.\n", prompt.result[i].type, statChange);
            exit(0);
        }
    }
    fclose(prompts);

    //take user input after printing prompt and options
    //if no options (only 1), arbitrarily select results
    //else choose option and select results
    //store into Result endResult and return endResult
    printf("%s", prompt.prompt);
    switch(optionSize)
    {
        case 1:
        default:
            printf("%s", prompt.result[0].consequence);
            //adjust option to selected mode (1)
            prompt.option[0] = 1;
            break;
        case 2:
            printf("You have two options: please type (a) or (b). ");
            do{
                fgets(buff, sizeof(buff), stdin);
                if(strcmp(buff, "a\n") != 0 && strcmp(buff, "b\n") != 0)
                    printf("Please enter a valid option. Please type (a) or (b). ");
                else
                    validInp = 1;
            }while(validInp != 1);
            if(buff[0] == 'a')
            {
                prompt.option[0] = 1;
                printf("%s", prompt.result[0].consequence);
            } else {
                prompt.option[1] = 1;
                printf("%s", prompt.result[1].consequence);
            }
            break;
        case 3:
            printf("You have three options: please type (a), (b), or (c). ");
            do{
                fgets(buff, sizeof(buff), stdin);
                if(strcmp(buff, "a\n") != 0 && strcmp(buff, "b\n") != 0 && strcmp(buff, "c\n") != 0)
                    printf("Please enter a valid option. Please type (a), (b), or (c). ");
                else
                    validInp = 1;
            }while(validInp != 1);
            if(buff[0] == 'a')
            {
                prompt.option[0] = 1;
                printf("%s", prompt.result[0].consequence);
            } else if(buff[0] == 'b') {
                prompt.option[1] = 1;
                printf("%s", prompt.result[1].consequence);
            } else {
                prompt.option[2] = 1;
                printf("%s", prompt.result[2].consequence);
            }
            break;
        case 4:
            printf("You have four options: please type (a), (b), (c), or (d). ");
            do{
                fgets(buff, sizeof(buff), stdin);
                if(strcmp(buff, "a\n") != 0 && strcmp(buff, "b\n") != 0 && strcmp(buff, "c\n") != 0 && strcmp(buff, "d\n") != 0)
                    printf("Please enter a valid option. Please type (a), (b), (c), or (d). ");
                else
                    validInp = 1;
            }while(validInp != 1);
            if(buff[0] == 'a')
            {
                prompt.option[0] = 1;
                printf("%s", prompt.result[0].consequence);
            } else if(buff[0] == 'b') {
                prompt.option[1] = 1;
                printf("%s", prompt.result[1].consequence);
            } else if(buff[0] == 'c') {
                prompt.option[2] = 1;
                printf("%s", prompt.result[2].consequence);
            } else {
                prompt.option[3] = 1;
                printf("%s", prompt.result[3].consequence);
            }
            break;
    }
    //find option selected and return result associated with option
    for(int i = 0; i < 4; i++)
        if(prompt.option[i] == 1)
            return prompt.result[i];

    //36 scenarios
    //1/3 are normal (e.g. some event with little effect on objective or some small benefit)
    //1/3 are problems (e.g. some decision event that have either negative or positive conseq. based on action
    //1/6 are calamity (e.g. some decision event with mainly all bad outcomes. randomized.)
    //1/6 are lucky event (e.g. some event with a large unconditional positive benefit)
}

/**
 * readResponse reads a Result and changes condition of the Tree.
 * @param aResult
 * @param aTree Tree modified by aResult
 */
void readResponse(Result aResult, Tree *aTree)
{
    //read Result consequences and stat changes
    //change condition of the Tree
    if(aResult.type == 0) //if height
        aTree->height += aResult.effect.heightInc;
    else if(aResult.type == 1) //if love
        aTree->love += aResult.effect.love;
    else
    {
        printf("cannot change condition of tree. result type: %i,\naResult.effect.heightInc: %i, aResult.effect.love: %i. err.\n", aResult.type, aResult.effect.heightInc, aResult.effect.love);
        exit(0);
    }
    //output consequence
    //printf("%s\n", aResult.consequence);
}

/**
 * readStatus reads the current status of the Tree and daily generated quote
 * @param aTree the Tree
 * @param quote index to quote pointer to File in array
 */
void readStatus(Tree aTree, int quoteIdx)
{
    //get pointer of Quote in File from array
    //read Quote and store into buffer
    //output buffer

    int quoteSize = 0;
    //open file
    GetFullPathNameA("Quotes.txt", sizeof(fileName), fileName, NULL);
    if((quotes = fopen(fileName, "r")) == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", fileName);
        exit(0);
    }
    //get size of quote in line
    fseek(quotes, quotePointersArr[quoteIdx], SEEK_SET);
    while(fgetc(quotes) != '\n')
        quoteSize++;
    fseek(quotes, quotePointersArr[quoteIdx], SEEK_SET);

    char quote[quoteSize + 1];
    //get line of quote size
    fgets(quote, quoteSize + 1, quotes);
    fclose(quotes);
    //outputs daily quote
    printf("\n\n%s", quote);
    //output stats of tree based on Tree
    printf("\nTree is %i cm tall.\nDo your best as always!\n", aTree.height);
}

/**
 * readEnd reads the end status of the Tree.
 * @param aTree
 */
void readEnd(Tree aTree)
{
    //output final stats of Tree
    //printf("\n\nThe tree is no more...\nHeight Reached:\t%lo\nAge:\t%i\nHow loved:\t%i\n", aTree.height, aTree.day, aTree.love);
    printf("\n\nThe tree is no more...\nHeight Reached:\t%icm\nAge:\t%i\nHow loved:\t%i\nCalamities Survived:\t%i\n", aTree.height, aTree.day, aTree.love, aTree.calamity);
}

/**
 * wait delays the program for a number of seconds.
 * @param double numberOfSeconds
 */
void wait(double numberOfSeconds)
{
    double milliSeconds = 1000 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}
