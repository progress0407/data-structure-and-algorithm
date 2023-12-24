package io.philo.codingtest.ch_2__d_bfs._2__문제._2K_교수

/**
 * Success
 */
fun main() {

    val t = readln().toInt()
    repeat(t) {
        val n = readln().toInt()
        var fiveCnt = countFiveFactors(n)
        println(fiveCnt)
    }
//    println(countFiveFactors(25))
}

private fun countFiveFactors(n: Int): Int {
    var fiveCnt = 0
    var i = 5
    while (i <= n) {
        fiveCnt += (n / i)
        i *= 5
    }
    return fiveCnt
}
