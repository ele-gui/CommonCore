#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     line_count;

    // Test 1: File normale
    printf("=== TEST 1: File normale ===\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Errore nell'apertura del file test.txt\n");
        return (1);
    }
    line_count = 1;
    while ((line = get_next_line(fd)))
    {
        printf("Linea %d: %s", line_count, line);
        free(line);
        line_count++;
    }
    close(fd);

    // Test 2: File vuoto
    printf("\n=== TEST 2: File vuoto ===\n");
    fd = open("empty.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Errore nell'apertura del file empty.txt\n");
        return (1);
    }
    line = get_next_line(fd);
    if (line == NULL)
        printf("File vuoto - OK\n");
    else
    {
        printf("Errore: dovrebbe essere NULL\n");
        free(line);
    }
    close(fd);

    // Test 3: File senza newline finale
    printf("\n=== TEST 3: File senza newline finale ===\n");
    fd = open("no_newline.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Errore nell'apertura del file no_newline.txt\n");
        return (1);
    }
    line_count = 1;
    while ((line = get_next_line(fd)))
    {
        printf("Linea %d: %s\n", line_count, line);
        free(line);
        line_count++;
    }
    close(fd);

    // Test 4: Lettura da stdin (commenta se vuoi testare solo file)
    /*
    printf("\n=== TEST 4: Lettura da stdin ===\n");
    printf("Scrivi alcune righe (CTRL+D per terminare):\n");
    while ((line = get_next_line(0)))
    {
        printf("Hai scritto: %s", line);
        free(line);
    }
    */

    // Test 5: File descriptor invalido
    printf("\n=== TEST 5: FD invalido ===\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("FD invalido gestito correttamente - OK\n");
    else
    {
        printf("Errore: dovrebbe essere NULL\n");
        free(line);
    }

    // Test 6: Chiamate multiple su file diversi
    printf("\n=== TEST 6: File multipli alternati ===\n");
    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    
    if (fd1 != -1 && fd2 != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            line = get_next_line(fd1);
            if (line)
            {
                printf("File1: %s", line);
                free(line);
            }
            
            line = get_next_line(fd2);
            if (line)
            {
                printf("File2: %s", line);
                free(line);
            }
        }
        close(fd1);
        close(fd2);
    }

    printf("\n=== TUTTI I TEST COMPLETATI ===\n");
    return (0);
}
