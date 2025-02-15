echo "Enter year:"
read yr

if [ $((yr % 400)) -eq 0 ] || { [ $((yr % 100)) -ne 0 ] && [ $((yr % 4)) -eq 0 ]; }; then
  echo "$yr is a LEAP YEAR"
else
  echo "$yr is NOT a LEAP YEAR"
fi


# echo "Enter year:"
# read yr

# if [ $((yr % 4)) -eq 0 ]; then
#   if [ $(yr % 100)) -eq 0 ]; then
#     if [ $((yr % 400)) -eq 0 ]; then
#       echo "Leap year"
#     else
#       echo "Not a leap year"
#     fi
#   else
#     echo "Leap year"
#   fi
# else
#   echo "Not a leap year"
# fi