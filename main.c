#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- 구조체 정보 ---
typedef struct {
    char name[20];
    char color[20];
    int price;
} Fruit;

// 초기 데이터
Fruit fruits[5] = {
    {"Apple", "Red", 20000},
    {"Banana", "Yellow", 15000},
    {"Melon", "Green", 32000},
    {"Grape", "Purple", 22000},
    {"Kiwi", "Brown", 19000},
};

// --- 파일 이름 상수 ---
// 과일 정보를 텍스트 형식으로 저장할 입력 파일
#define INPUT_FILE "frui.txt"      
// 가장 비싼 과일 정보를 저장할 출력 파일
#define OUTPUT_FILE "fruit_info.txt" 

int main() {
    FILE *input_fp, *output_fp;
    int i;
    
    // ===========================================
    // 1. INPUT_FILE (fruits.txt)에 과일 정보 텍스트 형식으로 저장
    // ===========================================
    
    // fruits.txt 파일을 쓰기 모드 ("w")로 엽니다.
    input_fp = fopen(INPUT_FILE, "w");
    if (input_fp == NULL) {
        // 파일 열기 오류 발생 시, 오류 메시지를 출력하고 종료합니다.
        perror("Error opening input file for writing");
        return 1;
    }

    // fscanf()로 읽을 수 있도록 "이름 색상 가격\n" 형태로 텍스트 파일에 씁니다.
    for (i = 0; i < 5; i++) {
        fprintf(input_fp, "%s %s %d\n", 
                fruits[i].name, 
                fruits[i].color, 
                fruits[i].price);
    }
    
    fclose(input_fp);

    // ===========================================
    // 2. INPUT_FILE (fruits.txt) 읽기 및 분석 (fscanf 활용)
    // ===========================================
    
    // fruits.txt 파일을 읽기 모드 ("r")로 엽니다.
    input_fp = fopen(INPUT_FILE, "r");
    if (input_fp == NULL) {
        perror("Error opening input file for reading");
        return 1;
    }

    Fruit current_fruit;
    Fruit most_expensive_fruit = {"", "", 0}; 
    int max_price = -1;
    int max_price_offset = -1;
    int record_index = 0;

    // 파일의 끝까지 순회하며 각 레코드를 읽고 분석합니다.
    // fscanf()를 사용하여 텍스트 데이터("이름 색상 가격")를 읽고,
    // 성공적으로 3개의 항목을 읽었는지 확인합니다.
    while (fscanf(input_fp, "%19s %19s %d", 
                  current_fruit.name, 
                  current_fruit.color, 
                  &current_fruit.price) == 3) {
        
        // 가장 비싼 과일 정보 업데이트
        if (current_fruit.price > max_price) {
            max_price = current_fruit.price;
            most_expensive_fruit = current_fruit; // 구조체 복사
            max_price_offset = record_index;      // 오프셋(인덱스) 저장
        }
        record_index++;
    }
    
    fclose(input_fp);

    // ===========================================
    // 3. 최종 결과 텍스트 파일 저장 (fruit_info.txt)
    // ===========================================
    
    // 최종 보고서 파일(fruit_info.txt)을 쓰기 모드 ("w")로 엽니다.
    output_fp = fopen(OUTPUT_FILE, "w");
    if (output_fp == NULL) {
        perror("Error opening output file for writing");
        return 1;
    }
    
    // 요구된 출력 형식에 맞춰 정보를 텍스트 파일에 씁니다.
    fprintf(output_fp, "offset: %d\n", max_price_offset);
    fprintf(output_fp, "name: %s\n", most_expensive_fruit.name);
    fprintf(output_fp, "color: %s\n", most_expensive_fruit.color);
    fprintf(output_fp, "price: %d\n", most_expensive_fruit.price);

    fclose(output_fp);

    return 0;
}
