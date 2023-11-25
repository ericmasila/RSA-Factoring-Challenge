#include "header.h"

/**
 * @brief Entry point
 *
 * @param av char array
 * @return int Always 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	RSAPrime fact(av[1]);

	fact.run();

	return (0);
}
