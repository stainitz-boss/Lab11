#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

struct Plant {
    char name[50];
    char species[50];
    char date[20];
    float height;
    int watering;
};

typedef struct Plant plant;

int check(plant p, float target_height);
void print(plant p);

int main() {
    setlocale(LC_ALL, "RUS");

    plant p1, p2, p3;
    float target_height;
    int i;
    int found = 0;

    printf("--- ВВОД ДАННЫХ О РАСТЕНИЯХ ---\n");
    
    printf("\nРастение 1:\n");

    printf("Название: ");
    scanf("%s", p1.name);
    printf("Вид: ");
    scanf("%s", p1.species);
    printf("Дата посадки (ДД.ММ.ГГГГ): ");
    scanf("%s", p1.date);
    printf("Высота (см): ");
    scanf("%f", &p1.height);
    printf("Частота полива (раз в 5 дней): ");
    scanf("%d", &p1.watering);

    printf("\nРастение 2:\n");
    printf("Название: ");
    scanf("%s", p2.name);
    printf("Вид: ");
    scanf("%s", p2.species);
    printf("Дата посадки (ДД.ММ.ГГГГ): ");
    scanf("%s", p2.date);
    printf("Высота (см): ");
    scanf("%f", &p2.height);
    printf("Частота полива (раз в 5 дней): ");
    scanf("%d", &p2.watering);

    printf("\nРастение 3:\n");
    printf("Название: ");
    scanf("%s", p3.name);
    printf("Вид: ");
    scanf("%s", p3.species);
    printf("Дата посадки (ДД.ММ.ГГГГ): ");
    scanf("%s", p3.date);
    printf("Высота (см): ");
    scanf("%f", &p3.height);
    printf("Частота полива (раз в 5 дней): ");
    scanf("%d", &p3.watering);

    printf("\nВведите минимальную высоту для поиска: ");
    scanf("%f", &target_height);
    printf("\n");
    printf("Подходящие растения:\n\n");

    
    if (check(p1, target_height)) {
        found = 1;
        print(p1);
    }
    if (check(p2, target_height)) {
        found = 1;
        print(p2);
    }
    if (check(p3, target_height)) {
        found = 1;
        print(p3);
    }

    if (found == 0) printf("Таких растений нет.\n");

    return 0;
}

int check(plant p, float target_height) {
    if (p.watering <= 5 && p.height > target_height) 
        return 1;
    return 0;
}

void print(plant p) {
    printf("Название: %s\n", p.name);
    printf("Вид: %s\n", p.species);
    printf("Дата посадки: %s\n", p.date);
    printf("Высота: %.1f см\n", p.height);
    printf("Частота полива: раз в %d дн.\n", p.watering);
    printf("\n");
}
