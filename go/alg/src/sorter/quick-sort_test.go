package sorter_test

import (
    // "fmt"
    . "sorter"
    "testing"
    "math/rand"
    "time"
)

func TestQuickSort(t *testing.T) {
    const N = 1000000

    // 使用洗牌算法产生随机数组
    randArray := make([]int, N)
    for i := 0; i < N; i++ {
        randArray[i] = i
    }

    rand.Seed(time.Now().Unix())
    for i := 0; i < N; i++ {
        randIndex := rand.Intn(N - i)
        randArray[N - i - 1], randArray[randIndex] = randArray[randIndex], randArray[N - i - 1]
    }

    // 测试是否产生了正确的随机数组
    flagArray := make([]bool, N)
    for i := 0; i < N; i++ {
        flagArray[randArray[i]] = true
    }
    for i := 0; i < N; i++ {
        if !flagArray[i] {
            t.Errorf("we lost '%d'", i)
        }
    }

    // 快速排序算法测试
    QuickSort(IntSlice(randArray), 0, len(randArray))
    for i := 0; i < N; i++ {
        if randArray[i] != i {
            t.Fatalf("QuickSort failed, index: %d", i)
        }
    }
}
