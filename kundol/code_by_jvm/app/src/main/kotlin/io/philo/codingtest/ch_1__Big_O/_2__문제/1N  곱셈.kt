package io.philo.codingtest.ch_1__Big_O._2__문제

/**
 * 시간 초과
 */
fun main() {
    val (A, B, C) = readln().split(" ").map { it.toInt() }

    var result: Long = 1
    repeat(B) {
        result *= A
        if (result >= C) {
            result %= C
        }
    }
    println(result)
}