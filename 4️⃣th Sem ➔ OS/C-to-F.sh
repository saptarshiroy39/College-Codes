echo "Enter temperature in Celsius:"
read cel

feh=$(((9 * cel + 160) / 5))
echo "Temperature in Fahrenheit: $feh"