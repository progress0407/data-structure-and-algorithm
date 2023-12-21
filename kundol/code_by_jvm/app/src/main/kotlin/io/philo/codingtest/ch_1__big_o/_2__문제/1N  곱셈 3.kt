package io.philo.codingtest.ch_1__big_o._2__문제

import java.util.Scanner

typealias ll = Long

private fun go(a: ll, b: ll, c: ll): ll {
    if (b == 1L) return a % c
    var ret = go(a, b / 2, c)
    ret = (ret * ret) % c
    if (b % 2 == 1L) ret = (ret * a) % c
    return ret
}

fun main() {
    val scanner = Scanner(System.`in`)
    val a = scanner.nextLong()
    val b = scanner.nextLong()
    val c = scanner.nextLong()

    println(go(a, b, c))
}

