// 测试

package main

import (
    "sorter"
    "fmt"
)

func main() {
    a := []int{2, 1, 6, 19, 0, -1}

    fmt.Println("before TestSort: ", a)

    sorter.QuickSort(sorter.IntSlice(a), 0, len(a))
    fmt.Println("after TestSort: ", a)
}
