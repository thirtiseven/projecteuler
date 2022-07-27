def powMod(a: Long, b: Long, mod: Long): Long = {
	@scala.annotation.tailrec
	def powTail(x: Long, y: Long, ans: Long): Long = y match {
		case 0 => ans
		case y if (y & 1) > 0 => powTail((x * x) % mod, y / 2, (ans * x) % mod)
		case _ => powTail((x * x) % mod, y / 2, ans)
	}
	powTail(a % mod, b, 1)
}

def inv(a: Long, n: Long): Long = {
	powMod(a, n-2, n)
}

def choose(n: Long, m: Long, mod: Long): Long = {
	@scala.annotation.tailrec
	def chooseTail(it: Long, a: Long, b: Long, ans: Long): Long = it match {
		case x if (x > m) => ans
		case _ => {
			chooseTail(it+1, (n - m + it + 1) % mod, (it + 1) % mod, (ans * (a * inv(b, mod) % mod) % mod) % mod)
		}
	}
	chooseTail(1, (n - m + 1) % mod, 1, 1)
}

val maxn: Int = 100000004
val mod: Long = 1000000007

val chooseKI = new Array[Long](maxn)

val chooseNHalfN = new Array[Long](maxn)

val powerOfTwo = new Array[Long](maxn)

val k: Long = 100000000
val t: Long = 100000000

println("KCI")

chooseKI(0) = 1
for (i <- 1 to k.toInt) {
	chooseKI(i) = (((chooseKI(i-1) * (k-i+1L)) % mod) * inv(i, mod)) % mod
}

println("NCN/2")

chooseNHalfN(0) = 1
chooseNHalfN(1) = 2
for (i <- 2 to k.toInt) {
	chooseNHalfN(i) = ((chooseNHalfN(i-1) * (4*i-2+mod) % mod) % mod * inv(i, mod) % mod)
}

println("power of two")

powerOfTwo(0) = 1L
powerOfTwo(1) = powMod(2L, t, mod)
for (i <- 2 to k.toInt) {
	powerOfTwo(i) = powerOfTwo(i-1) * powerOfTwo(1) % mod
}

println("start")

def A(k: Long, t: Long): Long = {
	@scala.annotation.tailrec
	def subTail(i: Long, ans: Long): Long = i match {
		case a if a < 0 => ans
		case _ => {
//			println("=================" + i.toString)
//			val part1x = choose(k, i, mod)
//			val part2x = choose(k-i, (k-i)/2L, mod)
//			val part3x = powMod(2L, i*t, mod)
			val part1 = chooseKI(i.toInt)
			val part2 = chooseNHalfN(((k-i)/2L).toInt)
			val part3 = powerOfTwo(i.toInt)
//			println(part1)
//			println(part1x)
//			println(part2)
//			println(part2x)
//			println(part3)
//			println(part3x)
			val cur1 = (part1 * part2) % mod
			val cur = (cur1 * part3) % mod
			subTail(i-2, (ans + cur) % mod)
		}
	}
	subTail(k, 0)
}


//print(choose(200000000,100000000,1000000007))
print(A(k, t))