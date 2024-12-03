package utility

import (
	"strconv"
)

func ToInts(str []string) ([]int) {
	result := make([]int, len(str))
	for i, s := range str {
		result[i], _ = strconv.Atoi(s)
	}

	return result
}