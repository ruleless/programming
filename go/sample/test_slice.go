// 切片数组测试，包括：
//   1. 从定长数组或切片数组创建而来的切片数组是否与原数组共享内存？
//   2. 扩容后的切片数组与原数组是否还共享内存？

package main

import (
    "fmt"
)

func main() {
    var fixedArr [10]int = [10]int{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    }

    // 打印初始值
    var arr []int = fixedArr[:5]
    fmt.Println("----")
    fmt.Println("fixedArr:", fixedArr)
    fmt.Println("arr:", arr)
    fmt.Println("")

    // 更新切片数组的值
    fmt.Println("----(arr[i] += 10)")
    for i := range arr {
        arr[i] += 10
    }

    fmt.Println("fixedArr:", fixedArr)
    fmt.Println("arr:", arr)
    fmt.Println("")

    // 扩容切片数组，使其超过原始数组大小
    fmt.Println("----(append(arr, ...))")
    arr = append(arr, -1, -2, -3, -4, -5, -6)
    fmt.Println("fixedArr:", fixedArr)
    fmt.Println("arr:", arr)
    fmt.Println("")

    // 更新切片数组的值
    fmt.Println("----(arr[i] += 10)")
    for i := range arr {
        arr[i] += 10
    }

    fmt.Println("fixedArr:", fixedArr)
    fmt.Println("arr:", arr)
    fmt.Println("")

    // append函数测试
    fmt.Println("----(append(fixedArr[:1], 99))")
    arr = append(fixedArr[:2], 99)

    fmt.Println("fixedArr:", fixedArr)
    fmt.Println("arr:", arr)
    fmt.Println("")
}

// 结论：
//   1. 从定长数组或切片数组创建而来的切片数组与原数组**共享内存**
//   2. 扩容后的切片数组与原数组**不共享内存**
