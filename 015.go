package main

import "fmt"

func main() {
	var a [23][23] int64
	for i := 0; i < 22; i++ {
		a[i][0] = 0
		a[0][i] = 0
	}
	a[1][0] = 1
	for i := 1; i < 22; i++ {
		for j := 1; j < 22; j++ {
			a[i][j] = a[i-1][j] + a[i][j-1]
		}
	}
	fmt.Print(a[21][21])
}