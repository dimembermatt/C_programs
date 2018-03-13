#include <stdio.h>
#include <windows.h>

/**
/ Packet Assembler Program #1
/ based off of r/dailyprogrammer's challenge #333
/ C programming language.
/ Matthew Yu
/ 1/10/18
/ This program is given a text file in the format %ddddd %dd %dd %ssssss in which in order is a packet ID, the
/ fragment number, maximum fragments of the message, and the message. The program unscrambles the message and
/ outputs them in order received.
/ TODO: change program to output messages in order completed
/       create 2d array of Packets and when initially scanning information from file check for unique id,
/       and if found, add to next part of Packet array. Else, store in same part of array as the first found congruent id.
/       while getting information, check for whether number of packet fragments in each section of array match max frags
/       and if true, sort and print and exclude from array.
**/
#define PACKET_NAME "Packet2.txt"

typedef struct
{
    int pID, pNum, pMaxNum;
    char msg[100];
}Packet;

int main()
{
    FILE *packetFile;
    char filePath[150], buff[150], msg[100];
    int pID, pNum, pMaxNum, length = 0;
    GetFullPathNameA(PACKET_NAME, sizeof(filePath), filePath, NULL);
    packetFile = fopen(filePath, "r");
    if(packetFile == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", filePath);
        exit(0);
    }
    //show scrambled packets
    printf("Hello, World! Packet below:\n");
    while(fgets(buff, sizeof(buff), packetFile) != NULL)
    {
        //printf("%s", buff);
        length++;
    }
    Packet packet[length];
    Packet packet2[length];
    fclose(packetFile);

    //create structs for each packet
    packetFile = fopen(filePath, "r");
    length = 0;

    printf("\n");
    while(fscanf(packetFile, "%d %d %d %100[^\n]", &pID, &pNum, &pMaxNum, msg) == 4)
    {
        printf("%d %d %d %s\n", pID, pNum, pMaxNum, msg);
        packet[length].pID = pID;
        packet[length].pNum = pNum;
        packet[length].pMaxNum = pMaxNum;
        strcpy(packet[length].msg, msg);
        length++;
    }
    fclose(packetFile);
    //unscramble each packet
    //make int array with list of packet ids
    int i = 0, k = 0, list[length][2], bool;
    for(int j = 0; j < length; j++)
        list[j][1] = -1;
    while(i < length)
    {
        //check current packet id with rest of array to check for unique
        bool = 0;
        for(int j = 0; j<length; j++)
        {
            if(packet[i].pID == list[j][1])
                bool = 1;
        }
        //if no match, add ID to list array
        if(bool == 0)
        {
            list[k][1] = packet[i].pID;
            list[k][2] = packet[i].pMaxNum;
            k++;
        }
        i++;
    }

    int p = 0;
    i = 0;
    //while list identifier is not empty
    while(list[i][1] != -1)
    {
        //find all instance of identifier in packet array, sort by y, and put into packet2 array.
        pMaxNum = list[i][2];
        //run through packet array number of time of number of packets needed to retrieve
        for(int j = 0; j <= pMaxNum; j++)
        {
            //run through all of packet array and check for packet with correct id and packet num
            for(int k = 0; k < length; k++)
            {
                //if id matches list and packet num matches run, add to packet2 array
                if(packet[k].pID == list[i][1] && packet[k].pNum == j)
                {
                    packet2[p] = packet[k];
                    p++;
                }
            }
        }
        i++;
    }

    //display unscrambled packets
    printf("\nUnscrambled, the message is: \n");
    i = 0;
    while(i < length)
    {
        printf("%d %d %d %s\n", packet2[i].pID, packet2[i].pNum, packet2[i].pMaxNum, packet2[i].msg);
        i++;
    }
    return 0;
}


/**
int main()
{
    FILE *packetFile;
    char filePath[150], buff[150], msg[100];
    int pID, pNum, pMaxNum, length = 0;
    GetFullPathNameA(PACKET_NAME, sizeof(filePath), filePath, NULL);
    packetFile = fopen(filePath, "r");
    if(packetFile == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", filePath);
        exit(0);
    }
    //show scrambled packets
    printf("Hello, World! Packet below:\n");
    while(fgets(buff, sizeof(buff), packetFile) != NULL)
    {
        //printf("%s", buff);
        length++;
    }
    fclose(packetFile);


    //unscramble packets
    //make int array with list of packet ids and max num
    packetFile = fopen(filePath, "r");
    int i = 0, k = 0, list[length][2], bool;
    for(int j = 0; j < length; j++)
        list[j][1] = -1;
    while(i < length)
    {
        //check current packet id with rest of array to check for unique
        bool = 0;
        fscanf(packetFile, "%d %d %d %100[^\n]", &pID, &pNum, &pMaxNum, msg);
        for(int j = 0; j<length; j++)
        {
            if(pID == list[j][1])
                bool = 1;
        }
        //if no match, add ID to list array
        if(bool == 0)
        {
            list[k][1] = pID;
            list[k][2] = pMaxNum;
            k++;
        }
        i++;
    }
    fclose(packetFile);
    //generate 2d Packet struct based on 1. number of unique packet ids and 2. max num of packets for each unique id
    i = 0;
    while(list[i] != -1)
    {
        int x = i;
        //Packet packet[ list[i][1] ][ list[i][2] ];
        i++;
    }


    //display unscrambled packets
    printf("\nUnscrambled, the message is: \n");
    i = 0;
    while(i < length)
    {
        printf("%d %d %d %s\n", packet2[i].pID, packet2[i].pNum, packet2[i].pMaxNum, packet2[i].msg);
        i++;
    }
    return 0;
}**/


/**
    //create structs for each packet
    packetFile = fopen(filePath, "r");
    length = 0;

    printf("\n");
    while(fscanf(packetFile, "%d %d %d %100[^\n]", &pID, &pNum, &pMaxNum, msg) == 4)
    {
        printf("%d %d %d %s\n", pID, pNum, pMaxNum, msg);
        packet[length].pID = pID;
        packet[length].pNum = pNum;
        packet[length].pMaxNum = pMaxNum;
        strcpy(packet[length].msg, msg);
        length++;
    }
    fclose(packetFile);
    **/