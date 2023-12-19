package io.philo.codingtest.ch_1__big_o._2__실습

/**
 * Runtime Error
 */
fun main() {
    while (true) {
        val n = readLine()?.toIntOrNull() ?: break

        var cnt = 1
        var ones = 1L
        while (ones % n != 0L) {
            ones = (ones.toString() + "1").toLong()
            cnt++
        }
        println(cnt)
    }
}
