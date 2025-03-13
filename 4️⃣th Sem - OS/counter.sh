echo "Enter a number:"
read n

echo "Counting from 1 to $n:"

count=1
while [ $count -le $n ]; do
  echo -n "$count "
  ((count++))
done