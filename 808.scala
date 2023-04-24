import scala.math._

//def PrimeInit():
//	IsPrime = [True] * maxn
//	Prime = []
//	for i in range(2, maxn):
//		if IsPrime[i]:
//			Prime.append(i)
//			for j in range(i * i, maxn, i):
//				IsPrime[j] = False;
//	return Prime

// def primes(n: Int): List

def reverse(a: Long): Long = {
	var res:Long = 0
	var aa:Long = a
	while (aa > 0) {
		res = res * 10 + aa % 10
		aa = aa / 10
	}
	return res
}

def palindrome(a: Long): Boolean = {
	return a == reverse(a)
}

def is_prime(a: Long): Boolean = {
	for (i <- 2 until sqrt(a.toDouble).toInt) {
		if (a % i == 0) {
			return false
		}
	}
	true
}

def is_prime_square(a: Long): Boolean = {
	val x = sqrt(a.toDouble).toLong
	x * x == a && is_prime(x)
}

var ans:Long = 0

var cnt:Long = 0

var cur:Long = 2

while (cnt < 50) {
	if (is_prime(cur)) {
		val x:Long = cur * cur
		if (palindrome(x) == false && is_prime_square(reverse(x))) {
			ans += x
			cnt += 1
			println(cnt, x)
		}
	}
	cur += 1
}

println("ans =")
println(ans)