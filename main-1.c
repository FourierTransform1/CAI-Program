#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct question
{
    int firstDigit;
    int secondDigit;
    char operation;
    int answer;
    int correctAnswer;
};


int printTest(struct question arr[], int n);
int practice(int menu);
int test(int menu);
struct question operation(int choice, int menu);
int evaluation(int answer, int correctAnswer);
int testResult(struct question array[],int size);


struct question arr[15];
char *wrongResponses[]= {"No. Please try again!","Wrong. Try once again!","Don’t give up!","No. Keep trying!"};
char *affirmativeResponses[]= {"Very good!","Excellent!","Nice work!","Well done!","Great!","Keep up the good work!"};


int main()
{

    int loop=0;
    do
    {
        printf("\n\nChoose what you want to do: \n1. Practice \n2. Test\n3. End\n");
        int menu;
        scanf("%d", &menu);

        if(menu==1)
            practice(menu);

        if(menu==2)
            test(menu);

        if(menu==3)
            loop=1;

    }
    while(loop==0);


    return 0;

}

int practice(int menu)
{
    int n=0;

    srand(time(NULL));
    printf("\nPractice!\n");
    printf("\nChoose one of the following practice sets:\n1. Addition\n2. Subtraction\n3. Addition and Subtraction\n");
    int choice;
    scanf("%d", &choice);

    while(n<10)
    {
        operation(choice, menu);
        n++;
    }

}


int test(int menu)
{
    int n=0;

    srand(time(NULL));
    printf("\nTest!\n");
    printf("\nChoose one of the following Test-sets:\n1. Addition\n2. Subtraction\n3. Addition and Subtraction\n");
    int choice;
    scanf("%d", &choice);

    while(n<15)
    {
        arr[n]= operation(choice, menu);
        n++;
    }
    testResult(arr,15);
    printTest(arr, 15);
}


struct question operation(int choice, int menu)
{
    struct question Q;
    int a=0;
    int b=0;
    int c=0;

    while(a==0)
        a = rand()%101;


    if(choice==3)
        c = (rand()%2)+1;


    if(choice==1|| c==1)
    {
        b = rand()%(100-a);
        Q.firstDigit=a;
        Q.secondDigit=b;
        Q.operation = '+';
        Q.correctAnswer = a + b;
        printf("What is %d + %d\n",a,b);
        scanf("%d",&Q.answer);
        if(menu==1)
            evaluation(Q.answer, Q.correctAnswer);
    }

    if(choice==2|| c==2)
    {
        b = rand()%a;
        Q.firstDigit=a;
        Q.secondDigit=b;
        Q.operation = '-';
        Q.correctAnswer = a - b;
        printf("What is %d %c %d\n",a,Q.operation,b);
        scanf("%d",&Q.answer);

        if(menu==1)
            evaluation(Q.answer, Q.correctAnswer);
    }

    if(menu==2)
        return Q;

    //return Q;
}


int evaluation(int answer, int correctAnswer)
{

    int i;

    while(answer!=correctAnswer)
    {
        i = rand()%4;
        printf("%s\n",wrongResponses[i]);
        scanf("%d",&answer);
    }

    if(answer==correctAnswer)
    {
        i = rand()%6;
        printf("%s\n", affirmativeResponses[i]);
    }
}


int printTest(struct question array[],int size)
{
    int n = 0;
    printf("Question\tCorrect answer\t\tYour answer\n");
    while(n<size)
    {
        printf("\n%d%c%d\t\t%d\t\t\t%d\t",array[n].firstDigit,array[n].operation,array[n].secondDigit,array[n].answer,array[n].correctAnswer);

        if(array[n].answer==array[n].correctAnswer)
            printf("correct!");

        n++;
    }
}


int testResult(struct question array[],int size)
{
    int n = 0;
    double i = 0;
    while(n<size)
    {
        if(array[n].answer==array[n].correctAnswer)
            i++;
        n++;
    }
    double result = (i/size)*100;
    printf("\n\n\nyour test result is %.0f (percent)!\n\n",result);
}
