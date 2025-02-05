echo "Enter 2 numbers"
read a
read b
echo "1 for +, 2 for -, 3 for *, 4 for /"
read op
case $op in
  1) res=$(($a + $b));;
  2) res=$(($a - $b));;
  3) res=$(($a * $b));;
  4) res=$(($a / $b));;
esac
echo "Result: $res"