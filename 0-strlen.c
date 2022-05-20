/**
 * _strlen - determine the length of a string
 * @s: character string
 * Return: string length
 */

int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
