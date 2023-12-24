package io.philo.codingtest.ch_2__d_bfs._2__문제._2K_교수


private fun countFiveFactors(inpNum: Int): Int {

    var n = inpNum

    var cnt = 0
    while (n != 1) {
        if (n % 5 == 0) {
            cnt++
            n /= 5
        } else {
            return cnt
        }
    }

    return cnt
}

/**
 * private ok
 *
 * 시간 초과
 */
fun main() {

    val t = readln().toInt()
    repeat(t) {
        var fiveCnt = 0
        for (num in 1..readln().toInt()) {
            if (num % 5 != 0) continue
            fiveCnt += countFiveFactors(num)
        }
        println(fiveCnt)
    }
}

/*
private fun fn(num: Int): Int {
    return round(log(num.toDouble(), 5.0)).toInt()
}
*/
