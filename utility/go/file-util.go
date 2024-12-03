package utility

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func LoadFile(path string) ([][]string) {
	file, err := os.Open(path)
	if err != nil {
		fmt.Println(err)
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	lines := make([][]string, 0)

	for scanner.Scan() {
		lines = append(lines, strings.Fields(scanner.Text()))
	}

	return lines
}