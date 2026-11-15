#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    char title[100];
    char date[20];
    int hour;
    int minute;
    int duration;
    char genre[50];
    float budget;
} Film;

int writefile(char *fname,Film *film, int size) {
    FILE* out;
    if ((out = fopen(fname, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }

    for (int i = 0;i < size;i++)
        fprintf(out," Имя:%20s ; Жанр:%20s ; Дата:%20s ; Время:%2d:%2d ; Бюджет:%d\n", film[i].title,film[i].genre,film[i].date,film[i].hour,film[i].minute,film[i].budget);
    fclose(out);
    return 1;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    char a[20] = "Films.txt";
    printf("Введите количество фильмов: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Film m;

        printf("Название: ");
        scanf(" %99[^\n]", m.title);

        printf("Дата: ");
        scanf(" %19[^\n]", m.date);

        printf("Час начала: ");
        scanf("%d", &m.hour);

        printf("Минуты начала: ");
        scanf("%d", &m.minute);

        printf("Продолжительность (мин): ");
        scanf("%d", &m.duration);

        printf("Жанр: ");
        scanf(" %49[^\n]", m.genre);

        printf("Бюджет: ");
        scanf("%f", &m.budget);

        writefile(&a, &m, n);

        if ((m.hour > 18 || (m.hour == 18 && m.minute > 0)) && m.duration > 100) {
            printf("\n--- Подходящий фильм ---\n");
            printf("Название: %s\n", m.title);
            printf("Дата и время: %s, %02d:%02d\n", m.date, m.hour, m.minute);
            printf("Продолжительность: %d мин.\n", m.duration);
            printf("Жанр: %s\n", m.genre);
            printf("Бюджет: %.2f\n", m.budget);
        }
        else printf("фильм начинается до 18:00 или длится меньше 1 часа 40 минут.\n");
    }
    return 0;
}