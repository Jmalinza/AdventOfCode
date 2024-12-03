package main

import (
	"fmt"
	"strings"

	"AdventOfCode/utility/go/utility"
)

func mul(symbols string) (int){
	closeIndex := strings.Index(symbols, ")")
	if closeIndex != len(symbols) - 1 {
		return 0
	}

	strValues := strings.Split(strings.Trim(symbols, "()"), ",")
	if len(strValues) < 2 {
		return 0
	}

	values := utility.ToInts(strValues)
	return values[0] * values[1]
}

func main() {
	file := utility.LoadFile("2024/inputs/day3.txt")

	sum := 0
	enableMul := true
	for _, line := range file {
		memory := strings.Join(line, "")
		commandBlock := strings.SplitAfter(memory, ")")
		for _, block := range commandBlock {

			do := strings.SplitAfter(block, "do(")
			if len(do) > 1 {
				enableMul = true
			}

			dont := strings.SplitAfter(block, "don't(")
			if len(dont) > 1{
				enableMul = false
			}

			m := strings.SplitAfter(block, "mul(")
			if len(m) > 1 && enableMul{
				sum += mul(m[len(m) - 1])
			}
		}
	}
	fmt.Printf("Sum of muls: %d\n", sum)
}