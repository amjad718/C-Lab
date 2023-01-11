#include<stdio.h>
#define N 100
int n,i,choice,a[N];
void maximum();
void minimum();
void sum();
void mean();
void count();
void main()
{
	printf("How many elements");
	scanf("%d",&n);
	printf("Enter the elements into the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	do
	{
	printf("Enter the choice: \n 1. Maximum \n 2.Minimum \n 3.Sum \n 4.Mean \n 5.Count \n");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: maximum();
			break;
			case 2: minimum();
			break;
			case 3: sum();
            break;
            case 4: mean();
            break;
            case 5: count();
            break;
            default: printf("Invalid Value");
		break;
		}
	}while(choice!=0);
}
void maximum()
{
    int big=a[0];
    for ( i = 0; i < n; i++)
    {
        if(a[i]>big)
        {
            big=a[i];
        }
    }
    printf("The Biggest element is %d",big);    
}
void minimum()
{
    int small=a[0];
    for ( i = 0; i < n; i++)
    {
        if(small>a[i])
        {
            small=a[i];
        }
    }
    printf("The smallest number is %d",small);
}
void sum()
{
    int sum=0;
    for ( i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    printf("The sum is %d",sum);
}
void mean()
{
    int sum=0;
    float mean;
    for ( i = 0; i < n; i++)
    {
      
        for ( i = 0; i < n; i++)
        {
            sum+=a[i];
        }
        mean=sum/n;
        printf("The mean is %f",mean);
    }
    
}
void count()
{
    printf("The no of elements is %d",n);
}
