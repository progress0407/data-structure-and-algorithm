package io.philo.codingtest.ch_1__big_o._2__문제

/**
 * 틀림
 */
fun main() {
    val (A, B, C) = readln().split(" ").map { it.toLong() }

    val result = go(A, B, C) % C

    println(result)
}

private fun go(a: Long, b: Long, c: Long): Long {

    if (b == 1L) {
        return a % c
    }

    val subVal:Long = go(a, b / 2, c)

    return if (b % 2 == 0L) {
        (subVal * subVal) % c
    } else {
        (subVal * subVal * a) % c
    }
}
