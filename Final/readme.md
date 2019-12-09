Create a project folder called final in your repository and save all the relevant files in the folder
Program must generate and use 100K, 500K, 1M random numbers for each run. (5 points)
Note: for each run, program must use the same set of random numbers to compare all the algorithms implemented and record the time for “apple to apple” comparison
NOTE: Some algorithms may take quite some time depending on the CPUs, cores, speed and RAM. It’s advisable that you store these random numbers into a text file so you can read and load them if the system rebooted or needed to be shutdown.
It is advisable that you write time taken for each algorithm to a file as soon as it’s completed so you do not have to repeat that experiment
Program must implement and calculate the running time of at least the following sorting algorithms to sort the random numbers generated in step 1 (9*5 = 45 points):
 Bubble sort
Selection sort
Insertion sort
Shellsort
Quicksort
Mergesort
Heapsort
algorithm.h/sort
algorithm.h/stable_sort 
Run each sort algorithm 10 times to find the average running time taken to sort the same original set of random numbers across all the algorithms. Specifically, for every run, program must generate and use a new list of random numbers as stated in step 1. (15 points)
Program must implement and calculate the running time of at least the following search algorithms (5*3 = 15 points). 
Sequential search
Binary search
Binary search tree
Pick a random number and search for it in the same random list (sorted list for Binary search). Do this for 10 times picking different random numbers each time but using the same list and record the average time for each algorithm. (10 points)
Program will then sort the algorithms based on the average running time in ascending order i.e., from fastest to slowest and print the results in an output text file called timeComplexity.txt with proper descriptions (10 points)
10 Bonus points will be given if you plot charts comparing the growth rates of algorithm for as the input size grows.

Total 90/100 Points 
