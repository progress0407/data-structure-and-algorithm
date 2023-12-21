package io.philo.codingtest.ch_1__big_o._2__문제

import java.util.*

/**
 * 직접 푼것 Fail T.T
 */
fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    val arr = Array(9) { nextInt() }

    val list: List<List<Int>> = combinations(arr, 7)

    for (ints in list) {
        if (ints.sum() == 100) {
            printAnswer(ints)
        }
    }
}

fun printAnswer(ints: List<Int>) {
    ints.sorted().forEach { println(it) }
}

private fun <T> combinations(list: List<T>, size: Int): List<List<T>> {
    if (size == 0) return listOf(emptyList())
    if (list.isEmpty()) return emptyList()

    val head = list.first()
    val rest = list.drop(1)

    val combsWithoutHead = combinations(rest, size)
    val combsWithHead = combinations(rest, size - 1).map { listOf(head) + it }

    return combsWithHead + combsWithoutHead
}

private fun <T> combinations(array: Array<T>, size: Int): List<List<T>> {
    return combinations(array.toList(), size)
}
