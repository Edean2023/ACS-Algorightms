# partitions the list
def partition(arr: list, low: int, high: int):
    # smaller element index
    index = (low - 1)

    # pivot point
    pivot = arr[high]

    for j in range(low, high):
        # if current element is smaller than the pivot
        if arr[j] < pivot:
            # increment index of smaller element
            index = index + 1
            arr[index], arr[j] = arr[j], arr[index]

    # swap
    arr[index + 1], arr[high] = arr[high], arr[index + 1]
    return index + 1


# recursive quick sort function
def quick(arr: list, low: int, high: int):
    if low < high:
        # generate a partition index
        partition_index = partition(arr, low, high)

        # sort elements before and after partition
        quick(arr, low, partition_index - 1)
        quick(arr, partition_index + 1, high)


# simple quick sort call
def quick_sort(arr: list):
    quick(arr, 0, len(arr) - 1)


    # create a new heap
def generate_heap(arr: list, n: int, i: int):
    # set the root
    largest = i
    left_node = 2 * i + 1
    right_node = 2 * i + 2

    # check if left child of the root exists and is greater than the root
    if left_node < n and arr[i] < arr[left_node]:
        largest = left_node

    # check if the right child of the root exists and is greater than the root
    if right_node < n and arr[largest] < arr[right_node]:
        largest = right_node

    # change the root if it is needed
    if largest != i:
        # swap the root
        arr[i], arr[largest] = arr[largest], arr[i]

        # create a new heap with the root
        generate_heap(arr, n, largest)


# heap sort implementation
def heap_sort(arr: list):
    # get the size of the array
    size = len(arr)

    # create a max heap
    for i in range(size // 2 - 1, -1, -1):
        generate_heap(arr, size, i)

    # extract the elements one at a time
    for i in range(size - 1, 0, -1):
        # swap elements
        arr[i], arr[0] = arr[0], arr[i]

        # new heap
        generate_heap(arr, i, 0)

