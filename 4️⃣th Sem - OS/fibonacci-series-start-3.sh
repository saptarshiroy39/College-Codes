echo "Enter the number of elements:"
read nun

a=3
b=5
echo "Fibonacci series of $nun elements starts from 3:"
echo "$a"
echo "$b"

for ((i = 2; i < $nun; i++))
do
  c = $((a + b))
  a=$b
  b=$c
  echo "$c"
done