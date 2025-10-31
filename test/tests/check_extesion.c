/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extesion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:21:09 by abtouait          #+#    #+#             */
/*   Updated: 2025/10/31 15:47:58 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void test_valid_extension(void)
{
    TEST_ASSERT_EQUAL_INT(0, check_extension("map.cub"));
}

void test_invalid_extension_txt(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension("map.txt"));
}

void test_invalid_extension_c(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension("level.c"));
}

void test_no_extension(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension("map"));
}

void test_dot_at_end(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension("map."));
}

void test_multiple_dots_valid(void)
{
    TEST_ASSERT_EQUAL_INT(0, check_extension("test.level.cub"));
}

void test_multiple_dots_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension("test.level.cubx"));
}

void test_empty_string(void)
{
    TEST_ASSERT_EQUAL_INT(1, check_extension(""));
}

void test_null_pointer(void)
{
    // comportement indéfini si NULL, donc on s’attend à un crash ou 1 si géré
    TEST_ASSERT_EQUAL_INT(1, check_extension(NULL));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_valid_extension);
    RUN_TEST(test_invalid_extension_txt);
    RUN_TEST(test_invalid_extension_c);
    RUN_TEST(test_no_extension);
    RUN_TEST(test_dot_at_end);
    RUN_TEST(test_multiple_dots_valid);
    RUN_TEST(test_multiple_dots_invalid);
    RUN_TEST(test_empty_string);
    RUN_TEST(test_null_pointer);
    return UNITY_END();
}