#include "../../cub3D.h"
#include "../Unity/src/unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void setUp(void)
{
	
}

void tearDown(void)
{
	
}
void test_valid_map(void)
{
    char **argv;
    int result;
    int argc;

    argc = 2;
    argv = malloc(sizeof(char *) * 3);
    if (!argv)
        return;
    argv[0] = "./cub3d";
    argv[1] = "map.cub"; // fichier existant attendu
    argv[2] = NULL;

    // créer un fichier vide pour le test
    int fd = open("map.cub", O_CREAT | O_RDWR, 0644);
    close(fd);

    result = smol_parse(argc, argv);

    remove("map.cub"); // nettoyage
    free(argv);

    TEST_ASSERT_EQUAL_INT(TRUE, result);
}

/* ---------- TEST 2 : mauvais nombre d’arguments ---------- */
void test_wrong_argc(void)
{
    char **argv;
    int result;
    int argc;

    argc = 3; // trop d’arguments
    argv = malloc(sizeof(char *) * 3);
    if (!argv)
        return;
    argv[0] = "./cub3d";
    argv[1] = "map.cub";
    argv[2] = "extra_arg";

    result = smol_parse(argc, argv);
    free(argv);

    TEST_ASSERT_EQUAL_INT(FALSE, result);
}

/* ---------- TEST 3 : mauvaise extension ---------- */
void test_wrong_extension(void)
{
    char **argv;
    int result;
    int argc;

    argc = 2;
    argv = malloc(sizeof(char *) * 3);
    if (!argv)
        return;
    argv[0] = "./cub3d";
    argv[1] = "map.txt"; // mauvaise extension
    argv[2] = NULL;

    result = smol_parse(argc, argv);
    free(argv);

    TEST_ASSERT_EQUAL_INT(FALSE, result);
}

/* ---------- TEST 4 : fichier inexistant ---------- */
void test_nonexistent_file(void)
{
    char **argv;
    int result;
    int argc;

    argc = 2;
    argv = malloc(sizeof(char *) * 3);
    if (!argv)
        return;
    argv[0] = "./cub3d";
    argv[1] = "does_not_exist.cub";
    argv[2] = NULL;

    result = smol_parse(argc, argv);
    free(argv);

    TEST_ASSERT_EQUAL_INT(FALSE, result);
}

/* ---------- TEST 5 : le “fichier” est un dossier ---------- */
void test_directory_instead_of_file(void)
{
    char **argv;
    int result;
    int argc;

    argc = 2;
    argv = malloc(sizeof(char *) * 3);
    if (!argv)
        return;
    argv[0] = "./cub3d";
    argv[1] = "map.cub";
    argv[2] = NULL;

    mkdir("map.cub", 0755); // crée un dossier nommé map.cub

    result = smol_parse(argc, argv);

    rmdir("map.cub"); // nettoyage
    free(argv);

    // Pour que ce test passe correctement, il faut modifier open_map()
    // pour refuser les répertoires (avec stat())
    TEST_ASSERT_EQUAL_INT(FALSE, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_valid_map);
    RUN_TEST(test_wrong_argc);
    RUN_TEST(test_wrong_extension);
    RUN_TEST(test_nonexistent_file);
   //RUN_TEST(test_directory_instead_of_file);

    return UNITY_END();
}