package io.philo.codingtest.ch_2__D_BFS._2__문제._2K_교수

/**
 * 내 풀이 :  틀림
 */
fun main() {

//    val t = readln().toInt()
//    repeat(t) {
//        val n = readln().toInt()
//        var fiveCnt = countFiveFactors(n)
//        println(fiveCnt)
//    }
    var fiveCnt = countFiveFactors(25)
    println(fiveCnt)
}

private fun countFiveFactors(n: Int): Int {
    var fiveCnt = 0
    var i = 5
    while (i <= n) {
        fiveCnt += (i / 5)
        i += 5
    }
    return fiveCnt
}
