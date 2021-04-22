#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ----- Намалювати зірочки заданим кольором ----- //
void draw(int color_1){
    setColor(color_1);
    printf("************************************\n");
    setColor(WHITE);
}

// ----- Ввести ціле число ----- //
int inputd(int color){
    int num;
    setColor(color);
    scanf("%d", &num);
    setColor(WHITE);
    return num;
}

// ----- Ввести дійсне число ----- //
float inputf(int color){
    float num;
    setColor(color);
    scanf("%f", &num);
    setColor(WHITE);
    return num;
}

// ----- Дуже сильний рандом ----- //
int random(int min, int max){
    int rand_num, r;
    if(min <= 0){
        max+=1;
        r = abs(min);
        rand_num = (min+r)+rand()%(max+r);
        rand_num -=r;
    }
    else{
        do {
            rand_num = min+rand()%max;
            if(rand_num >= min && rand_num <= max)
                break;
        }
        while (1);
    }
    return rand_num;
}

float randomf(int min, int max){
    return random(min, max) - rand()/(float)RAND_MAX;
}


//max
int maxd(int arr[], int length) {
    int max = arr[0];
    for (int i=0; i<length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

float maxf(float arr[], int length) {
    float max = arr[0];
    for (int i=0; i<length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

////////////////////////////////////////////////////

//min
int mind(int arr[], int length) {
    int min = arr[0];
    for (int i=0; i<length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

float minf(float arr[], int length) {
    float min = arr[0];
    for (int i=0; i<length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

////////////////////////////////////////////////////

//sum
int sumd(int arr[], int length) {
    int sum = 0;
    for (int i=0; i<length; i++) {
        sum += arr[i];
    }
    return sum;
}

float sumf(float arr[], int length) {
    float sum = 0;
    for (int i=0; i<length; i++) {
        sum += arr[i];
    }
    return sum;
}

////////////////////////////////////////////////////

//sort
int sortd(int *arr[], int length) {
    for (int i=1; i<length; i++) {
        int k = i;
        while ((k > 0) && (arr[k-1] > arr[k])) {
            int tmp = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = tmp;
            k -= 1;
        }
    }
}

float sortf(float arr[], int length) {
    for (int i=1; i<length; i++) {
        int k = i;
        while ((k > 0) && (arr[k-1] > arr[k])) {
            float tmp = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = tmp;
            k -= 1;
        }
    }
}
