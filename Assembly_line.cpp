//  2016054011_±èÁö¿¬_508 

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) ((x < y)? x: y)

typedef struct Line {
    int* assembly_time;
    int* transfer_time;

    int entry_time;
    int exit_time;
} Line;

int main() {
    int N;  //  means # of station
    Line* line;
    int *time[2], *station[2];

    int a00, a01, a10, a11; //  linei to linej
    int final_time, final_station;
    
    int *output;    //  reverse proper station
    int i, j;

    line = (Line*)malloc(sizeof(Line) * 2);

    scanf("%d", &N);
    for (i = 0; i < 2; i++) {
        line[i].assembly_time = (int*)malloc(sizeof(int) * N);
        line[i].transfer_time = (int*)malloc(sizeof(int) * (N - 1));
        
        time[i] = (int*)malloc(sizeof(int) * N);
        station[i] = (int*)malloc(sizeof(int) * (N - 1));

        output = (int*)malloc(sizeof(int) * N);
    }

    for (i = 0; i < 2; i++)
        scanf("%d", &line[i].entry_time);
    for (i = 0; i < 2; i++)
        scanf("%d", &line[i].exit_time);

    //  input assembly_time
    for (i = 0; i < 2; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &line[i].assembly_time[j]);

    //  input transfer_time
    for (i = 0; i < 2; i++)
        for (j = 0; j < N - 1; j++)
            scanf("%d", &line[i].transfer_time[j]);

    time[0][0] = line[0].assembly_time[0] + line[0].entry_time;
    time[1][0] = line[1].assembly_time[0] + line[1].entry_time;

    for (i = 1; i < N; i++) {
        a00 = time[0][(i + 1) % 2] + line[0].assembly_time[i];  //  line1 to line1
        a01 = time[0][(i + 1) % 2] + line[0].transfer_time[i - 1] + line[1].assembly_time[i];   //  line1 to line2
        a10 = time[1][(i + 1) % 2] + line[1].transfer_time[i - 1] + line[0].assembly_time[i];   //  line2 to line1
        a11 = time[1][(i + 1) % 2] + line[1].assembly_time[i];  //  line2 to line2

        //  line(1 to 1) < line(2 to 1)
        if (a00 <= a10) {
            time[0][i % 2] = a00;
            station[0][i-1] = 1;
        }

        //  line(2 to 1) < line(1 to 1)
        else {
            time[0][i % 2] = a10;
            station[0][i-1] = 2;
        }

        //  line(2 to 2) < line(1 to 2)
        if (a11 <= a01) {
            time[1][i % 2] = a11;
            station[1][i-1] = 2;
        }

        //  line(1 to 2) < line(2 to 2)
        else {
            time[1][i % 2] = a01;
            station[1][i-1] = 1;
        }
    }

    a00 = time[0][(i + 1) % 2] + line[0].exit_time;
    a11 = time[1][(i + 1) % 2] + line[1].exit_time;

    if (a00 < a11) {
        final_time = a00;
        final_station = 1;
    }
    else {
        final_time = a11;
        final_station = 2;
    }

    //  saves proper assembly line reversely
    output[N - 1] = final_station;
    for (i = N - 2; i >= 0; i--) {
        output[i] = station[final_station - 1][i];
        final_station = output[i];
    }

    printf("%d\n", final_time);
    for (i = 0; i < N; i++)
        printf("%d %d\n", output[i], i + 1);

    
    for (i = 0; i < 2; i++) {
        free(line[i].assembly_time);
        free(line[i].transfer_time);
        
        free(time[i]);
        free(station[i]);

    }
    free(line);
    free(output);
}
