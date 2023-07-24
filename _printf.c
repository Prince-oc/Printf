/**
 * _printf - function that produces output according to a format
 *
 * Description: function that produces output according to a format
 *
 * @format: String Format
 *
 * Return: number of charracters printed
 */

int _printf(const char *format, ...)
{
	int number_of_characters_printed, format_position, format_length;
	char *string_placeholder;
	va_list all_parameters;

	format_length = strlen(format);
	number_of_characters_printed = 0;

	va_start(all_parameters, format);

	format_position = 0;

	while (format[format_position])
	{
		if ((format_position + 1) <= (format_length - 1))
		{
			if (format[format_position] == '%')
			{
				switch (format[format_position + 1])
				{
					case 'c':
						_putchar(va_arg(all_parameters, int));
						number_of_characters_printed++;
						format_position += 2;
						break;
					case 's':
						string_placeholder = (char *) va_arg(all_parameters, char *);
						number_of_characters_printed += _puts(string_placeholder);
						format_position += 2;
						break;
					case '%':
						_putchar('%');
						number_of_characters_printed++;
						format_position += 2;
						break;
					case 'i':
					case 'd':
						number_of_characters_printed = _puts_integer(va_arg(all_parameters, int));
						format_position += 2;
						break;
					case 'b':
						number_of_characters_printed = _puts_binary(va_arg(all_parameters, int));
						format_position += 2;
						break;
					case 'u':
						number_of_characters_printed = _puts_unsigned_integer(va_arg(all_parameters, unsigned int));
						format_position += 2;
						break;
					case 'o':
						number_of_characters_printed = _puts_octal(va_arg(all_parameters, unsigned int));
						format_position += 2;
						break;
					case 'x':
						number_of_characters_printed = _puts_hex(va_arg(all_parameters, unsigned int), 1);
						format_position += 2;
						break;
					case 'X':
						number_of_characters_printed = _puts_hex(va_arg(all_parameters, unsigned int), 0);
						format_position += 2;
						break;
					case 'p':
						number_of_characters_printed = _puts_pointer(va_arg(all_parameters, void *));
						format_position += 2;
						break;

					default:
						_putchar(format[format_position]);
						number_of_characters_printed++;
						format_position++;
						break;
				}

			}
			else if (format[format_position] == '\\')
			{
				_putchar(format[format_position]);
				number_of_characters_printed++;
				format_position++;

			}
			else
			{
				_putchar(format[format_position]);
				number_of_characters_printed++;
				format_position++;
			}
		}
		else
		{
			_putchar(format[format_position]);
			number_of_characters_printed++;
			format_position++;
		}
	}

	va_end(all_parameters);

	return (number_of_characters_printed);
}
