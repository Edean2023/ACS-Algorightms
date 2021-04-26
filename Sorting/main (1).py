import time
import argparse
from algorithms import quick_sort, heap_sort
from typing import Callable


# sort a file with a given data set and output it's performance in another file
def time_sort(file: str, algorithm: Callable[[list], None], iterations: int = 1):
    total_time = 0

    for i in range(0, iterations):
        try:
            dataset_file = open("data/" + file + ".dat", "r")
        except FileNotFoundError:
            print("Unable to open file, please check again to see if it is there.")
            return

        # read the elements into the array
        dataset: list
        dataset = dataset_file.readlines()

        # convert the elements into an integer and remove unwanted text
        for j in range(0, len(dataset)):
            dataset[j] = int(dataset[j].replace("\n", ""))

        # print the set if it is less than 100 elements
        if len(dataset) <= 100 and i == 0:
            print("Dataset Loaded: " + file + ".dat")
            print(dataset)
            print("-" * 20)
        elif len(dataset) > 100 and i == 0:
            print("Dataset Loaded: " + file + ".dat")
            print("Set larger than 100 elements, not printing set to console.")
            print("-" * 20 )

        # get start time
        t0 = time.time_ns()

        # sort the list
        algorithm(dataset)

        # get an ending time
        t1 = time.time_ns()

        # get the total runtime in ms
        total = ((t1 - t0) / 1000000)

        # add this iterations runtime to the total time
        total_time += total

    # calculate average runtime
    average_time = total_time / iterations

    # format the time as ms or seconds given its total average time
    if average_time > 1000:
        total = str(average_time / 1000) + "s"
    else:
        total = str(average_time) + "ms"

    return total


if __name__ == "__main__":
    # files to test sorting on
    files = ["num10", "num100", "num1000", "num10000", "num100000", "num1000000"]

    for file in files:
        # sort the file with heap sort and get performance data
        heap_time = time_sort(file, heap_sort, 100)

        # sort the file with quick sort and get performance data
        quick_time = time_sort(file, quick_sort, 100)

        # print results
        print("\n")
        print("Results for sorting file: " + file + ".dat:")
        print("\t- Average Time with Heap Sort: " + str(heap_time))
        print("\t- Average Time with Quick Sort: " + str(quick_time))
        print("\n")
        print("-"*20)
