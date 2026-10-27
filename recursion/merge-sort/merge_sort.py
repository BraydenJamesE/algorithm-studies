def merge(
    lst1: list[int | float | str],
    lst2: list[int | float | str]
) -> list[int | float | str]:
    i, j = 0, 0
    merged_list = []
    for _ in range(len(lst1) + len(lst2)):
        if j > len(lst2) - 1:
            merged_list.append(lst1[i])
            i += 1
        elif i > len(lst1) - 1:
            merged_list.append(lst2[j])
            j += 1
        elif lst1[i] <= lst2[j]:
            merged_list.append(lst1[i])
            i += 1
        elif lst2[j] < lst1[i]:
            merged_list.append(lst2[j])
            j += 1
    return merged_list

def merge_sort(
    lst: list[int | float | str]
) -> list[int | float | str]:
    if len(lst) > 1:
        n = len(lst) // 2
        lst1 = merge_sort(lst[:n])
        lst2 = merge_sort(lst[n:])
        final_list = merge(lst1, lst2)
        return final_list
    return lst

def main():
    unsorted_list = [10, 2, 30, 4, 5, 6, -1, 40, -2 , 1, 1000, -50, 7]
    sorted_list = merge_sort(unsorted_list)
    
    print(f"Original Unsorted List: {unsorted_list}")
    print(f"Merge Sorted List: {sorted_list}")

if __name__ == "__main__":
    main()