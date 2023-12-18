package io.philo.codingtest.ch_0__basic

/**
 * C++ 에서만 지원이 안 되는 걸로 안다
 */
class _3__Split

fun main() {
    val strings = "1 2 3".split(" ")

    for (str in strings) {

        println("str = ${str}")
    }
}