#include "../../cub3D.h"
#include "../Unity/src/unity.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void)
{
	
}

void tearDown(void)
{
	
}
void test_1(void)
{
	char	**argv;
	int		result;
	argv = malloc(sizeof(char *) * 3);
	if (!argv)
		return ;
	argv[0] = "./cub3d";
	argv[1] = "map.cub";
	argv[2] = NULL;
	result = open_map(argv[1]);
	free(argv);
	TEST_ASSERT_EQUAL_INT(TRUE, result);
}
int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_1);

	return (UNITY_END());
}