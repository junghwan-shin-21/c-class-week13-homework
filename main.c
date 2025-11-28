#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 정보 
typedef struct {
    char name[20];
    char color[20];
    int price;
} Fruit;

// Init Value
Fruit fruits[5] = {
    {"Apple", "Red", 20000},
    {"Banana", "Yellow", 15000},
    {"Melon", "Green", 32000},
    {"Grape", "Purple", 22000},
    {"Kiwi", "Brown", 19000},
};

#define INPUT_FILE "fruits.txt"      
#define OUTPUT_FILE "fruit_info.txt" 

int main() {
    

    return 0;
}
