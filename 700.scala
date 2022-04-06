import scala.collection.View.Unfold

val x: Long = 1504170715041707L
val m: Long = 4503599627370517L

def nextCoin(step: Long, limit: Long, max: Long): Option[Long] = {
  if (limit == 1) {
    None
  } else if (step < limit) {
    Some(step)
  } else {
    val shift = max - max / step * step
    nextCoin(shift, limit, step).map(limit - _)
  }
}

val coins = new Unfold[Long, Long](m)(last => nextCoin(x, last, m).map(x => x -> x)).toList

println(coins)
println(coins.sum)