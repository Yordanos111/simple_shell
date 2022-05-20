#include "main.h"

/**
 * check_wait_status - check status code for wait function
 * @wstatus: integer, return value of the wait() function
 */

void check_wait_status(int wstatus)
{
	if (WIFEXITED(wstatus))
	{
		int statusCode;

		statusCode = WEXITSTATUS(wstatus);
		if (statusCode != 0)
			/* printf("Success!\n"); */
			printf("Failure status code %d\n", statusCode);
	}
}
