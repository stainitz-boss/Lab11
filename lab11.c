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

int main() {
    setlocale(LC_ALL, "RUS");

    struct Plant p[3];
    float target_height;
    int i;
    int found = 0;

    printf("--- ВВОД ДАННЫХ О РАСТЕНИЯХ ---\n");
    for (i = 0; i < 3; i++) {
        printf("\nРастение %d:\n", i + 1);

        printf("Название (без пробелов): ");
        scanf("%s", p[i].name);

        printf("Вид (без пробелов): ");
        scanf("%s", p[i].species);

        printf("Дата посадки (ДД.ММ.ГГГГ): ");
        scanf("%s", p[i].date);

        printf("Высота (см): ");
        scanf("%f", &p[i].height);

        printf("Частота полива (раз в N дней): ");
        scanf("%d", &p[i].watering);
    }

    printf("\nВведите минимальную высоту для поиска: ");
    scanf("%f", &target_height);

    for (i = 0; i < 3; i++) {
        if (p[i].watering <= 5 && p[i].height > target_height) {
            printf("Название: %s\n", p[i].name);
            printf("Вид: %s\n", p[i].species);
            printf("Дата посадки: %s\n", p[i].date);
            printf("Высота: %.1f см\n", p[i].height);
            printf("Частота полива: раз в %d дн.\n", p[i].watering);
            printf("-----------------------------------\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("Таких растений нет.\n");
    }

    return 0;
}
