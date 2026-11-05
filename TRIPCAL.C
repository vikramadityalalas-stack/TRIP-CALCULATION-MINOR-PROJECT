#include <stdio.h>

int main(void)
{
    float distance, mileage, fuelPrice, tolls;
    float hotelRate, foodRate, other;
    int days, people;

    printf("===== TRIPCALC: Plan the Trip. Calculate the Cost. =====\n\n");

    printf("One-way distance (km): ");
    scanf("%f", &distance);
    printf("Vehicle mileage (km per litre): ");
    scanf("%f", &mileage);
    printf("Fuel price per litre: ");
    scanf("%f", &fuelPrice);
    printf("Total tolls/parking (round trip): ");
    scanf("%f", &tolls);
    printf("Number of days: ");
    scanf("%d", &days);
    printf("Number of people: ");
    scanf("%d", &people);
    printf("Hotel cost per room per night: ");
    scanf("%f", &hotelRate);
    printf("Food cost per person per day: ");
    scanf("%f", &foodRate);
    printf("Other expenses (shopping, tickets, etc.): ");
    scanf("%f", &other);

    /* Validation */
    if (mileage <= 0 || days <= 0 || people <= 0 ||
        distance < 0 || fuelPrice < 0 || tolls < 0 ||
        hotelRate < 0 || foodRate < 0 || other < 0) {
        printf("\nInvalid input. Please enter positive values.\n");
        return 1;
    }

    /* Calculations */
    float totalDistance = distance * 2;
    float fuelCost      = (totalDistance / mileage) * fuelPrice;
    int   nights        = days - 1;
    int   rooms         = (people + 1) / 2;
    float hotelCost     = rooms * nights * hotelRate;
    float foodCost      = people * days * foodRate;
    float total         = fuelCost + tolls + hotelCost + foodCost + other;
    float perPerson     = total / people;

    /* Output */
    printf("\n------------- TRIP COST SUMMARY -------------\n");
    printf("Total distance (round trip) : %.2f km\n", totalDistance);
    printf("Fuel cost                   : %.2f\n", fuelCost);
    printf("Tolls/parking               : %.2f\n", tolls);
    printf("Hotel (%d room(s), %d night(s)): %.2f\n", rooms, nights, hotelCost);
    printf("Food                        : %.2f\n", foodCost);
    printf("Other expenses              : %.2f\n", other);
    printf("---------------------------------------------\n");
    printf("TOTAL TRIP COST             : %.2f\n", total);
    printf("COST PER PERSON             : %.2f\n", perPerson);

    return 0;
}