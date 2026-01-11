echo "Enter the array elements: "
read -a arr

sorted=($(for i in "${arr[@]}"; do
    echo $i; done | sort -nr))
    echo "Result: ${sorted[2]}"