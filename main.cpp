#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// Прототипы функций
char* the_longest_word(char** words, int word_count, int str_length);
int strlen(char* str);
pair<char**, int> from_str_to_char_arr(char* str, int str_length);
void str_sort(char** words, int word_count);

int main() {
    // Объявляем приблизительный размер строки
    constexpr int size = 100;
    auto str = static_cast<char*>(malloc(sizeof(char) * size));
    fgets(str, size, stdin);
    // Проверяем если строка пустая то завершаем программу
    if (str[0] + str[1] == '\n') {
        free(str);
        return -1;
    }
    // Убираем 2 последних символа так как функция fgets добавляет в конец \n
    int str_len = strlen(str);
    str[str_len - 1] = '\0';
    pair<char**, int> p = from_str_to_char_arr(str, strlen(str));
    char** words = p.first;
    int word_count = p.second;
    str_sort(words, word_count);
    free(str);
}

// Функция поиска наибольшего слова
char* the_longest_word(char** words, int word_count, int str_length) {
    auto longest_str = static_cast<char*>(malloc(sizeof(char) * str_length));
    for (int i = 0; i < word_count; i++) {
        if (strlen(words[i]) > strlen(longest_str)) {
            longest_str = words[i];
        }
    }
    return longest_str;
}

// Функция сортировки
void str_sort(char** words, int word_count) {
    char** new_words = words;
    for (int i = 0; i < word_count - 1; ++i) {
        for (int j = 0; j < word_count - i - 1; j++) {
            if (strlen(new_words[j]) < strlen(new_words[j + 1])) {
                char* temp = new_words[j];
                new_words[j] = new_words[j + 1];
                new_words[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < word_count; i++) {
        printf("%s ", new_words[i]);
    }
}

// Функция нахождения длинны слова
int strlen(char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

// Функция получения массива слов и количества слов
pair<char**, int>from_str_to_char_arr(char* str, const int str_length) {
    char* new_str = strtok(str, " ");
    char** words = new char*[str_length];
    int word_count = 0;
    while (new_str != nullptr) {
        words[word_count] = new_str;
        word_count++;
        new_str = strtok(nullptr, " ");
    }
    return {words, word_count};
}
