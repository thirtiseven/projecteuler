package main

import "fmt"

func main() {
	var i int = 2
	var ans int = 0
	var vis [12345] int
	for i = 2; i <= 10000; i++ {
		vis[i] = 0
	}
	for i = 2; i <= 10000; i++ {
		if vis[i] == 1 {
			continue
		}
		var temp int = 0
		for j := 1; j < i; j++ {
			if i%j==0 {
				temp += j
			}
		}
		var temp2 int = 0
		for j := 1; j < temp; j++ {
			if temp%j==0 {
				temp2 += j
			}
		}
		if temp2 == i && i != temp {
			ans += temp2
			ans += temp
			vis[temp] = 1
			fmt.Printf("%d %d\n", temp, temp2)
		}
	}
	fmt.Println(ans)
}