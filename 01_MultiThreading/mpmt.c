#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
char *words[WORDS];
char *languages[LANGUAGES] = {
    "French", "Spanish", "German"
};
char *translations[LANGUAGES][WORDS] = {
    {"Bonjour", "Merci", "Au revoir"},
    {"Hola", "Gracias", "Adios"},
    {"Hallo", "Danke", "Auf Wiedersehen"}
};
struct Data {
    int language_index;
    int word_index;
};
void *translate(void *arg)
{
    struct Data *data = (struct Data *)arg;

    printf("%s translation of %s = %s\n",
           languages[data->language_index],
           words[data->word_index],
           translations[data->language_index][data->word_index]);
   return NULL;
}
int main()
{
    pthread_t threads[WORDS];
    struct Data data[WORDS];
    pid_t pid[LANGUAGES];

    printf("Enter 3 English words:\n");
    for (int i = 0; i < WORDS; i++) {
        scanf("%ms", &words[i]);
    }

    for (int lang = 0; lang < LANGUAGES; lang++) {
        pid[lang] = fork();

        if (pid[lang] < 0) {
            perror("fork failed");
            exit(1);
        }

        if (pid[lang] == 0) {
            printf("\nChild process translating into %s\n",
                   languages[lang]);

            for (int i = 0; i < WORDS; i++) {
                data[i].language_index = lang;
                data[i].word_index = i;

                pthread_create(&threads[i], NULL,
                               translate, &data[i]);
            }

            for (int i = 0; i < WORDS; i++) {
                pthread_join(threads[i], NULL);
            }

            exit(0);
        }
    }

    for (int i = 0; i < LANGUAGES; i++) {
        waitpid(pid[i], NULL, 0);
    }

    for (int i = 0; i < WORDS; i++) {
        free(words[i]);
    }

printf("\nAll translations completed.\n");
return 0;}
