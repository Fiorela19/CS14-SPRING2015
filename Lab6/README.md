Monica Moreno
861174030
May 16, 2015

Lab6 Question 2

Part a
My selectionsort function is a stable sort because I made several test that 
check its stability in my main.cc. The tests are located at the bottom of the 
file. When the passed-in container has repeated elements, selectionsort keeps 
the elements in their relative order after the sort. Selectionsort starts with 
the first element in the container and swaps it with the smallest element. It 
then goes to the next element in the container and swaps it with the next 
smallest item. This continues until the entire container is sorted. Within the 
for loop that iterates through the container but after the nested for loop that
finds the smallest element I put an if statement that checks if the elements to 
be swaped are the same (the elements to be swapped being the element at the 
current ith position and the smallest element found). If the elements are the 
same then they are not swapped. Since the for loop iterates through the
container from left to right, when there are repeated elements, they remain in
the same realitve position. 

Part b
I wrote a program that tests my code's stability in my main.cc file. The tests
are located at the bottom of the file. I tested the stability of my program by 
testing selectionsort on different containers which contain repeated elements.