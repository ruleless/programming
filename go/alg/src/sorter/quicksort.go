// 排序算法

package sorter

type Interface interface {
	// Len is the number of elements in the collection.
	Len() int

	// Less reports whether the element with
	// index i should sort before the element with index j.
	Less(i, j int) bool

	// Swap swaps the elements with indexes i and j.
	Swap(i, j int)
}

type IntSlice []int

func (p IntSlice) Len() int           { return len(p) }
func (p IntSlice) Less(i, j int) bool { return p[i] < p[j] }
func (p IntSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

type Float64Slice []float64

func (p Float64Slice) Len() int           { return len(p) }
func (p Float64Slice) Less(i, j int) bool { return p[i] < p[j] || isNaN(p[i]) && !isNaN(p[j]) }
func (p Float64Slice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

// isNaN is a copy of math.IsNaN to avoid a dependency on the math package.
func isNaN(f float64) bool {
	return f != f
}

// StringSlice attaches the methods of Interface to []string, sorting in increasing order.
type StringSlice []string

func (p StringSlice) Len() int           { return len(p) }
func (p StringSlice) Less(i, j int) bool { return p[i] < p[j] }
func (p StringSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }


func doPivot(data Interface, startIndex int, count int) int {
    if count <= 0 {
        return startIndex
    }

    pivotIndex := startIndex
    low, high := startIndex, startIndex + count - 1

    for low < high {
        for low < high && data.Less(pivotIndex, high) {
            high--
        }
        if low < high {
            data.Swap(pivotIndex, high)
            pivotIndex = high
        }

        for low < high && !data.Less(pivotIndex, low) {
            low++
        }
        if low < high {
            data.Swap(pivotIndex, low)
            pivotIndex = low
        }
    }

    return pivotIndex
}

func QuickSort(data Interface, startIndex int, count int) {
    if count <= 0 {
        return
    }

    pivotIndex := doPivot(data, startIndex, count)
    if startIndex < pivotIndex {
        QuickSort(data, startIndex, pivotIndex - startIndex)
    }
    if pivotIndex + 1 < startIndex + count {
        QuickSort(data, pivotIndex + 1, startIndex + count - pivotIndex - 1)
    }
}
