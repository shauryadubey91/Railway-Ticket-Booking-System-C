#include <stdio.h>
#define TOTAL_SEATS 10

void showSeats(int seats[]);
void bookSeat(int seats[]);
void cancelSeat(int seats[]);

int main() {
    int seats[TOTAL_SEATS];
    int choice;

    for(int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = 0;
    }

    do {
        printf("\n Railway Ticket Booking System:- \n");
        printf("1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. Show Seat Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                bookSeat(seats);
                break;
            case 2:
                cancelSeat(seats);
                break;
            case 3:
                showSeats(seats);
                break;
            case 4:
                printf("Exiting system... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void showSeats(int seats[]) {
    printf("\nSeat Status:\n");
    for(int i = 0; i < TOTAL_SEATS; i++) {
        if(seats[i] == 0)
            printf("Seat %d : Available\n", i + 1);
        else
            printf("Seat %d : Booked\n", i + 1);
    }
}

void bookSeat(int seats[]) {
    int seatNo;
    printf("Enter seat number to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if(seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    }
    else if(seats[seatNo - 1] == 1) {
        printf("Seat already booked!\n");
    }
    else {
        seats[seatNo - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNo);
    }
}

void cancelSeat(int seats[]) {
    int seatNo;
    printf("Enter seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if(seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    }
    else if(seats[seatNo - 1] == 0) {
        printf("Seat is already available!\n");
    }
    else {
        seats[seatNo - 1] = 0;
        printf("Seat %d cancelled successfully!\n", seatNo);
    }
}
