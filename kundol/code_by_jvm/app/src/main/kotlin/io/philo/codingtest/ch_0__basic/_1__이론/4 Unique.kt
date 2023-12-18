package io.philo.codingtest.ch_0__basic._1__이론

/**
 * 중복 없애기
 */
class _4__Unique

fun main() {
    val list = listOf(2, 2, 1, 3, 3, 1)
//    val set = setOf(list)
//    println("set = ${set}")
    val set = HashSet<Int>(list)
    println("set = ${set}")
}