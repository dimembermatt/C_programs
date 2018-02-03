#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/*
 * Wildfire Science Project Algorithm - Brute Force
 * @author Matthew Yu
 * @version 1.00 (C) 1/28/2018 (V 1.00 (JAVA) 2/9/2017)
 * @version 1.01 (C) 2/03/2018 WORKING -cli interface working, methods working, code from JAVA version cleaned up.
 *
 * WildfireScienceProjectAlgorithm is a program that determines a possible
 * algorithm using input data of PDSI, Avg Temp, and NDVI, as well as Acreage
 * Burned. It will use loops to create a new equation for each iteration and
 * compare the result to the acreage burned in order to determine an average
 * percent error.
 *
 * Steps: getCalculation - creates the variable coefficients by implementing
 * increments for each separate coefficient in an array.
 * computeCalculation - computes the avg percent error by taking out the
 * coefficient values for each array row from getCalculation, multiplies them by
 * respective input data from file, and compares them with the observed acreage
 * burned in 4th column of input data file. (percent error funct, equationColl)
 * It then averages all percent errors from one row of equationColl into an
 * eqnCollCompressed array that contains the avg percent error for each
 * respective iteration found in step 1.
 *
 * Storage of input data is in the format:
 * "PDSI, Avg Temp, NDVI, Acreage Burned \n"
 * Storage of comparison data is in the format:
 * "PDSI, Avg Temp, NDVI, Observed Acreage Burned \n"
 * A WildfireScienceProjectAlgorithm has a File Path and a Delimiter.
 *
 * TODO:
 * create cli input for array size, coefficient increments, check bounds from said increments?
 * fix variable descriptions
 * debug
 */

#define PATH_BUFF 150
#define BUFF 50
#define ARRAY_SIZE (100*100*100)
#define FILE_LENGTH 72  //assume file length is 72, TODO: getLength method in main to determine file length
#define ROWS (ARRAY_SIZE-1)
#define COLS 3

int coeff[ROWS][COLS];
double equationColl[ARRAY_SIZE][FILE_LENGTH] = {0};
double eqnCollCompressed[ARRAY_SIZE];

void getCalculation(int pdsiInt, int pdsiCoeff, int tempInt, int tempCoeff, int ndviInt, int ndviCoeff);
void computeCalculation(FILE * file, char * filePath[]);
int main()
{
    time_t start;
    time_t stop;
    double dif = 0.0;
    FILE * dataFile;
    FILE * writeFile;
    printf("Hello, World!\n");
    char filePath[PATH_BUFF];
    char writeFilePath[PATH_BUFF];
    char * strPointer;
    int buff[BUFF];
    int PDSIInt, PDSICoeff, TempInt, TempCoeff, NDVIInt, NDVICoeff;

    GetFullPathNameA("DataN20082012N0Event.tsv", PATH_BUFF, filePath, NULL);
    dataFile = fopen(filePath, "r+");
    //setup result file path
    strncpy(writeFilePath, filePath, PATH_BUFF);
    strPointer = strstr(writeFilePath, ".tsv");
    strncpy(strPointer, "Result.txt", 10);

    //IO
    printf("Enter PDSI intercept.\n");
    scanf("%d", &PDSIInt); // NOLINT
    printf("Enter PDSI slope.\n");
    scanf("%d", &PDSICoeff); // NOLINT
    printf("Enter Avg Temp intercept.\n");
    scanf("%d", &TempInt); // NOLINT
    printf("Enter Avg Temp slope.\n");
    scanf("%d", &TempCoeff); // NOLINT
    printf("Enter NDVI intercept.\n");
    scanf("%d", &NDVIInt); // NOLINT
    printf("Enter NDVI slope.\n");
    scanf("%d", &NDVICoeff); // NOLINT

    printf("Calculating...");
    time(&start);

    getCalculation(PDSIInt, PDSICoeff, TempInt, TempCoeff, NDVIInt, NDVICoeff);
    printf("Writing Results...");
    //pass addr of coeff array in getCalculation to coeff array copy in main
    //pass copy in main to compute calculation
    computeCalculation(dataFile, filePath);


    //output
    writeFile = fopen(writeFilePath, "w");
    if(writeFile == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", writeFilePath);
        exit(1);
    }
    for(int i = 0; i < ARRAY_SIZE-1; i++)
    {
        //fprintf(writeFile, "arr run %i:  coeffs %d\t%d\t%d\n", i, coeff[i][0], coeff[i][1], coeff[i][2]);
        //for(int j = 0; j < FILE_LENGTH; j++)
        //    fprintf(writeFile, "percent error for line %d:\t %05.3f\n", j, equationColl[i][j]);
        //fprintf(writeFile, "avg percent error: %05.3f\n", eqnCollCompressed[i]);
        //short vers
        if(i%72)
        {
            if(eqnCollCompressed[i] < 3000)
                fprintf(writeFile, "arr run %i:  coeffs %d\t%d\t%d\tavg %% error %05.3f\n", i, coeff[i][0], coeff[i][1], coeff[i][2], eqnCollCompressed[i]);
            else
            {
                if(eqnCollCompressed[i+1] >= 3000);
                else
                    fprintf(writeFile, "arr run %i:  coeffs %d\t%d\t%d\tfail 5000%% err bar\t%05.3f avg %% error\n", i, coeff[i][0], coeff[i][1], coeff[i][2], eqnCollCompressed[i]);
            }
        }


    }
    fclose(writeFile);


    //for(int i = 0; i <10; i++)
    //    printf("list of coefficients:\n%d\t%d\t%d\n", coeff[i][0], coeff[i][1], coeff[i][2]);
    //print coefficients x, y, z; equationColl[RowCount][n] - from 1 to n, each avg result of f(x) using coefficients against each line of data
    //printf("List of percent errors of f(x) against each data line for coefficients %d\t%d\t%d\n", coeff[0][0], coeff[0][1], coeff[0][2]);
    //for(int i = 0; i < 10; i++)
    //    printf("%f\n", equationColl[0][i]);
    //printf("Average of percent errors for coefficients from all percent errors.\n%f\n", eqnCollCompressed[0]);
    time(&stop);
    dif = difftime(stop, start);
    printf("Time: %f minutes and %d seconds.", dif/60, (int)dif%60);
    return 0;
}

/**
 * getCalculation gets an array of all the coefficient values for the equation.
 * @param pdsiInt PDSI intercept
 * @param pdsiCoeff PDSI slope
 * @param tempInt Avg Temperature intercept
 * @param tempCoeff Avg Temperature slope
 * @param ndviInt NDVI intercept
 * @param ndviCoeff NDVI slope
 */
void getCalculation(int pdsiInt, int pdsiCoeff, int tempInt, int tempCoeff, int ndviInt, int ndviCoeff)
{
    int rowCount = 0;
    while(rowCount < ARRAY_SIZE) //arraySize
    {
        for(int i = 0; i < cbrt(ARRAY_SIZE); i++)
        {
            for(int j = 0; j < cbrt(ARRAY_SIZE); j++)
            {
                for(int k = 0; k < cbrt(ARRAY_SIZE); k++)
                {
                    coeff[rowCount][0] = pdsiInt + i * pdsiCoeff; //-10 + i * -10
                    coeff[rowCount][1] = tempInt + j * tempCoeff; //10 + j * 10
                    coeff[rowCount][2] = ndviInt + k * ndviCoeff; //100 + k * 100
                    rowCount++;
                }
            }
        }
    }

}

/**
 * computeCalculation gets an array of the percent errors from each data input into the calculation.
 * @param FILE file, pointer to file used in program.
 * */
void computeCalculation(FILE * file, char * filePath[])
{
    char buff[BUFF];
    int coeff1 = 0, coeff2 = 0, coeff3 = 0;
    int rowCount = 0;
    int loop = 0, n;

    double equationArr[4];
    while(rowCount < ARRAY_SIZE) //rowcount < ARRAY_SIZE
    {
        n = 0;
        coeff1 = coeff[rowCount][0];
        coeff2 = coeff[rowCount][1];
        coeff3 = coeff[rowCount][2];

        file = fopen(filePath, "r+");
        if(file == NULL)
        {
            printf("fopen failed. File pointer NULL err - %s.\n", filePath);
            exit(1);
        }
        //while next line is true
        while (fscanf(file, "%s", buff) == 1)
        {
            //if end of line
            if(loop == 4)
            {
                //computation: avg of coefficient f(x) against n line of data =[acreage burned - (coeff1 * pdsi + coeff2 * temp + coeff3 * ndvi) / acreage burned]
                equationColl[rowCount][n] = fabs((equationArr[3] - (coeff1 * equationArr[0] + coeff2 * equationArr[1] + coeff3 * equationArr[2])) / equationArr[3]) * 100;
                n++;
                loop = 0;
            }
            //read next value
            equationArr[loop] = atof(buff);
            loop++;
        }
        fclose(file);
        rowCount++;
    }

    double avgPercentErr = 0;
    for(int p = 0; p < ARRAY_SIZE; p++) //p<arraySize
    {
        double sum = 0, avgCount = 1.0;
        for(int o = 0; o < FILE_LENGTH; o++)
        {

            //System.out.println(equationColl[rowCount][o]);
            sum += equationColl[p][o];
            avgPercentErr = sum/avgCount;
            avgCount++;
            //System.out.println("[rowCount:n:%err:avgCount]"+p+":"+o+":"+avgPercentErr+":"+avgCount+"==>"+equationColl[p][o]);
        }

        //System.out.println(avgPercentErr);
        eqnCollCompressed[p] = avgPercentErr;
        //printf("%f\n", eqnCollCompressed[p]);
        //rowCount++;
    }
}