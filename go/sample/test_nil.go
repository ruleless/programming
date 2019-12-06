// nil值测试，包括：
//   1. 哪些类型的变量可以被赋值为nil

package main

import (
    "fmt"
)

type FooStruct struct {
    foo int
}

func main() {
    var intVar *int = nil // 指针类型的变量可以赋值为nil
    var intArr []int = nil // 切片数组类型的变量可赋值为nil
    var mapVar map[int] int = nil // map类型的变量可赋值为nil
    var interfaceVar interface{} = nil // 接口类型的变量可赋值为nil
    var chanVar chan int = nil

    // var intArr [5]int = nil // 定长数组的变量不可赋值为nil
    // var foo FooStruct = nil // 结构体类型的变量不可赋值为nil

    // 结论：
    // 1. 使用引用语义的变量可被赋值为nil
    // 2. 而使用值语义的变量不可被赋值为nil

    fmt.Println("*int:", intVar)
    fmt.Println("[]int:", intArr)
    fmt.Println("map[int] int:", mapVar)
    fmt.Println("interface{}:", interfaceVar)
    fmt.Println("char int:", chanVar)
}
