#include<stdio.h>
int main(void)
{
    float distance,fuel,price,mileage;

    printf("Enter the price of the fuel per liter:");
    scanf("%f",&price);

    printf("Enter the distance travelled in km:");
    scanf("%f", &distance);

    printf("Enter the mileage of the vehical :");
    scanf("%f", &mileage);

    fuel = distance/mileage;
    price = fuel*price;
    printf("The total cost of the trip is : %f",price);

    return 0;
}