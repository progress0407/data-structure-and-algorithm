package io.philo.codingtest.ch_1__big_o._2__실습

/**
 * Success
 */
fun main() {
    while (true) {
        val n = readLine()?.toIntOrNull() ?: break

        var cnt = 1
        var ones = 1L
        while (ones % n != 0L) {
            ones = (ones * 10 + 1L) % n
            cnt++
        }
        println(cnt)
    }
}
