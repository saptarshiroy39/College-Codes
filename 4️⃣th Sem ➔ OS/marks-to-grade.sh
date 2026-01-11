echo "Enter your marks:"
read marks

if [ $marks -ge 90 ]; then
    grade="A"
elif [ $marks -ge 80 ] && [ $marks -lt 90 ]; then
    grade="B"
elif [ $marks -ge 70 ] && [ $marks -lt 80 ]; then
    grade="C"
elif [ $marks -ge 60 ] && [ $marks -lt 70 ]; then
    grade="D"
else
    grade="F"
fi

echo "Your grade is: $grade"


# echo "Enter your marks:"
# read marks

# if [ $marks -ge 90 ]; then
#     grade="A"
# elif [ $marks -ge 80 ]; then
#     grade="B"
# elif [ $marks -ge 70 ]; then
#     grade="C"
# elif [ $marks -ge 60 ]; then
#     grade="D"
# else
#     grade="F"
# fi

# echo "Your grade is: $grade"