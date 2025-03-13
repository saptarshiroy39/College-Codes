echo "Enter the array elements: "
read -a arr

sum=0
for i in "${arr[@]}"
do
    sum=$((sum + i))
done

echo "Sum of array elements: $sum"