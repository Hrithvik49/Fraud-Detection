#include<stdio.h>	//to use the printf function
#include<conio.h>   //to use the getche function
#include<stdlib.h>  //to use the rand function
#include<string.h>

typedef struct key_value
{
	char Time[50];
	char V1[50];
	char V2[50];
	char V3[50];
    char V4[50];
    char V5[50];
    char V6[50];
    char V7[50];
    char V8[50];
    char V9[50];
    char V10[50];
    char V11[50];
    char V12[50];
    char V13[50];
    char V14[50];
    char V15[50];
    char V16[50];
    char V17[50];
    char V18[50];
    char V19[50];
    char V20[50];
    char V21[50];
    char V22[50];
    char V23[50];
    char V24[50];
    char V25[50];
    char V26[50];
    char V27[50];
    char V28[50];
    char Amount[50];
    char Class[50];            // and so on for required no. of columns.
}dict;

/*---------------------------------------------------------------------------------------------------------------------*/



int main()
{

    int num;			// num is the no. of iterations
    int i,j;

    printf("\nWelcome to the Genetic Algorithm coded for Minor 1 \n"); // introduction to the program


    enter: printf("\nPlease enter the no. of iterations:  ");
    scanf("%d",&num);       // enter the no. of iterations in num


    if(num<1)                    // if a -ve number is inserted .. enter num again
    goto enter;

    // Initialize the file pointers
	FILE *fp = fopen("F:\\College Study Material\\Minor\\Dataset\\Dataset V1-V28\\Trying.csv", "r"); //open in read mode
	if (!fp)
	{
		printf("error occured");
		return 0;
	}

    /*For using structure named dict*/
	char buff[1024];      								  // stores the first 1024 lines into buff
	int row_count = 0;
	int field_count = 0;
	dict values[999];                                       //array to structs to store values

	chromosome*chromosome[300];

	while(fgets(buff, 1024, fp))
	{
		field_count = 0;
		row_count++;
		if(row_count == 1)
		{
			continue;
        }
    char *field = strtok(buff, ",");
    while(field)
		{
		    for (i=0; i<=num; i++)
            {
                chromosome = value[i].V1;
            }


	/*Code for fitness*/

    struct Individual obj;
    initialize(&obj);
    calculateFitness(&obj);
    printf("%d",obj.fitness);

    selection(values);



    /*Code for roulette wheel*/

    char popcurrent[50];         // we make 50 chromes of popcurrent
    char popnext[50];            // we make 50 chromes of popnext

    evpop(popcurrent);           //initialise pop current

    for(i=0;i<num;i++)           // loop num times
    {
        printf("\ni = %d\n",i);       // print the iteration number

        for(j=0;j<50;j++)
        {
            popnext[j]=popcurrent[j];            	//copy popcurrent to popnext in order to adjust it
        }

        pickchroms(popnext);                    	//pick best chromes
        crossover(popnext);                      	//cross over to get children chromes
        mutation(popnext);                       	//mutate with a low probability

        for(j=0;j<50;j++)
        {
            popcurrent[j]=popnext[j];             	//copy the chromes of popnext to popcurrent
        }
    }                                           // loop back until no. of iterations is exceeded

    printf("\nPress any key to end ! ");

    flushall();                             		// flush the input buffer
    getche();                                	// wait for a character from the keyboard to end



	//defining the functions that we will use

    void *evpop(char popcurrent[8]);
    int x(char popcurrent);
    int y(int x);
    void *pickchroms(char popcurrent[8]);
    void *crossover(char popnext[8]);
    void *mutation(char popnext[8]);


    return 0;
}                                            	//end of main

/*-------------------------------------------------------------------------------------------------------*/

/* Code for fitness criteria */

struct Individual
{
    int fitness;
    int geneLength;
    int genes[5];
};
void initialize(struct Individual* obj)
{
    obj->fitness = 0;
    obj->geneLength = 5;
    for(int i=0; i<obj->geneLength; i++)
    {
        obj->genes[i]=rand()%2;
    }
}
void calculateFitness(struct Individual* obj)
{
    obj->fitness = 0;
    for (int i = 0; i < obj->geneLength; i++)
    {
        if (obj->genes[i] == 0)
        {
            ++obj->fitness;
        }
    }
}
/*----------------------------------------------------------------------------------------------------------*/


/*Roulett wheel implementation*/

void selection(chromosome * chromosome)
{

    double totalFitness = 0;
    double totalProbability = 0;
    double probability = 0;
    double rndNumber;
    double min,max;

    int i;

    min = 0.0;
    max = 1.0;

    POPOLATION_SIZE = popcurrent[];

    for(i=0; i<POPULATION_SIZE; i++)
    {
        totalFitness += chromosome[i].fitness;
    }

    for(i=0; i<POPULATION_SIZE; i++)
    {
        chromosome[i].probability = (chromosome[i].fitness)/totalFitness;
        printf("Chromosome %d with probability %f\n",i, chromosome[i].probability);
    }

    srand((unsigned)time(NULL));
    for(i=0;i<POPULATION_SIZE;i++)
    {
        rndNumber = ((double)rand()/(double)RAND_MAX);

        if(chromosome[i].probability >= rndNumber)
        {
            printf("Chromosome %d selected \n",i);
        }
    }
}
/*-------------------------------------------------------------------------------------------------------*/

