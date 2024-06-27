package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	in, err := io.ReadAll(os.Stdin)
	if err != nil {
		panic(err)
	}

	lns := strings.Split(string(in), "\n")

	for i := 0; i < len(lns); i++ {
		if !strings.Contains(lns[i], "const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]") {
			continue
		}
		i++

		for i < len(lns) {
			ln := lns[i]
			tln := strings.TrimSpace(ln)

			if strings.Contains(ln, "}") {
				os.Exit(0)
			}

			if strings.HasPrefix(tln, "//") {
				fmt.Println(ln[7:])
			} else if strings.HasPrefix(tln, "[") {
				fmt.Println("Layer " + ln[5:8])
			} else if strings.HasPrefix(tln, ")") {
			} else {
				fmt.Println(strings.ReplaceAll(ln[7:], "XXXXXXX", "       "))
			}

			i++
		}
	}
}
