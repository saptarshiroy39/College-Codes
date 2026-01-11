echo "Enter a number:"
read num;

if [ $((num%2)) -eq 0 ]; then
  echo "$num is EVEN"
else
  echo "$num is ODD"
fi