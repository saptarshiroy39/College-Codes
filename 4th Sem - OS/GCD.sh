echo "Enter 2 numbers"
read a
read b
while [ $b -ne 0 ];do
  temp=$b
  b=$((a%b))
  a=$temp
done
echo "GCD: $a"