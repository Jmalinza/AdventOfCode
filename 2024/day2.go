package main

import (
	"fmt"

	"AdventOfCode/utility/go/utility"
)

func absoluteDelta(a, b int) (int) {
	if a < b {
		return b - a
	}
	return a - b
}

func isPositiveDelta(a, b int) (bool) {
	return a < b
}

func isDeltaUnsafe(level1, level2 int, deltaSign bool) (bool){
	delta := absoluteDelta(level1, level2)
	return delta < 1 || delta > 3 || deltaSign != isPositiveDelta(level1, level2)
}

func IsReportSafe(report []int) (bool) {
	if len(report) == 0 {
		return false
	}

	isSafe := true
	deltaSign := isPositiveDelta(report[0], report[1])
	for i := range report {
		if i == len(report) - 1 {
			break
		}

		if isDeltaUnsafe(report[i], report[i + 1], deltaSign){
			isSafe = false
			break
		}
	}

	return isSafe
}

func removeLevelFrom(report []int, index int) ([]int){
	newReport := make([]int, len(report))
	copy(newReport, report)
	copy(newReport[index:], newReport[index+1:])
	newReport[len(newReport)-1] = 0 
	newReport = newReport[:len(newReport)-1]
	return newReport
}

func IsDampenedReportSafe(report []int) (bool){
	if IsReportSafe(report){
		return true
	}

	for j := range report {
		newReport := removeLevelFrom(report, j)
		if IsReportSafe(newReport){
			return true
		}
	}
	
	return false
}


func main() {
	file := utility.LoadFile("2024/inputs/day2.txt")

	safeScore := 0
	dampeningScore := 0
	for _, line := range file {
		report := utility.ToInts(line)
		if IsReportSafe(report){
			safeScore++
		}
		if IsDampenedReportSafe(report){
			dampeningScore++
		}
	}

	fmt.Printf("Number of safe reports: %d\n", safeScore)
	fmt.Printf("Number of safe dampened reports: %d\n", dampeningScore)
}